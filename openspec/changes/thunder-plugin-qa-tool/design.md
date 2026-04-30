## Context

Thunder plugin development is distributed across the core RDK team and a wider ecosystem of partner companies. The existing PluginSkeletonGenerator (PSG) is a Python CLI in `ThunderTools/` that generates correct boilerplate from an interface header, but it operates only at creation time and cannot be invoked by an AI agent. A rich set of Thunder architecture rules is already encoded in `.github/instructions/` (rules files 00–12), but these are only consulted reactively and manually.

VS Code Copilot Agent mode with MCP tool support is now the approved AI-coding surface across the organisation. The GitHub Models API is already in production use in the PSG CI workflow. The tool must be self-contained in `ThunderTools/` so external RDK partners can adopt it through the same distribution channel they already use for PSG.

## Goals / Non-Goals

**Goals:**
- Use the AI model as the primary mechanism for structural checks (ref-counting discipline, call symmetry, interface map completeness) — the checks where C++ idioms vary too widely for reliable offline matching.
- Use offline regex patterns only for trivially reliable token-level checks where false-positive/false-negative risk is negligible (keyword presence, include order, absolute path literals).
- Rule definitions are plain YAML files, editable without Python knowledge, so Thunder architects can own and update rules and AI queries directly.
- Surface quality guidance in VS Code Agent mode via prompt-file slash commands backed by the standalone review engine.
- Catch architecture violations at the PR gate via CI, before merge.
- Zero changes to existing PSG source.
- MCP server wrapper (enabling fully agent-driven generation) is an optional enhancement on top of the standalone engine.

**Non-Goals:**
- Full C++ compiler-level static analysis (clang-tidy integration is out of scope).
- Runtime plugin testing or sandboxed execution.
- Auto-fixing found violations (the tool reports; the developer fixes).
- Supporting non-Thunder C++ codebases.
- VS Code extension (`@thunder` chat participant) — planned for a future phase after MCP adoption is proven.

## Decisions

### D1 — Standalone script as the core; MCP server as an optional enhancement

**Decision:** The rule engine is a standalone Python CLI script (`review_plugin.py`) that runs entirely without an AI model. The MCP server is a thin optional wrapper around it that enables AI agents to call it programmatically.

**Rationale:** A developer already has PSG and ThunderTools locally. The rule engine provides immediate value as a terminal command (`python review_plugin.py MyPlugin.cpp`), in CI (direct subprocess call, no server process), and via Copilot prompt files (Agent mode reads the open file, calls the script). The MCP wrapper adds value specifically for fully automated agent sessions (AI calls PSG, then immediately reviews the output) — but this is an enhancement, not a prerequisite. This ordering means the tool is useful on day one without any MCP setup.

**Alternative considered:** MCP server as the foundational layer with prompt files on top. Rejected — it couples every use-case (CI, terminal, Copilot review) to a running server process that provides no benefit for those scenarios.

---

### D2 — Python `mcp` SDK for the optional MCP wrapper

**Decision:** If/when the MCP server is built, use the official `mcp` Python SDK (`pip install mcp`). The core rule engine requires only `PyYAML` (already a PSG dependency) — zero new dependencies.

**Rationale:** The MCP SDK handles transport negotiation, tool schema serialisation, and capability advertisement automatically. Keeping it out of the core `requirements.txt` means the rule engine and CI workflow are immediately usable without any additional installation. The `mcp` SDK goes in a separate `requirements-mcp.txt`.

**Alternative considered:** Implement the MCP wire protocol directly (JSON-RPC over stdio). Rejected — the protocol has version negotiation complexity not worth hand-rolling.

---

### D3 — AI model is primary for structural checks; offline patterns for trivial token checks only

**Decision:** The review engine uses two mechanisms: (1) focused AI model queries via the GitHub Models API for all structural checks; (2) offline regex pattern matching for trivially reliable token-level checks only. The AI pass is the primary value delivery mechanism, not an optional enhancement.

**Rationale:** Real RDK plugin codebases (`DeviceInfo`, `UserSettings`, `SystemServices`) show wildly different C++ idioms for the same architectural intent — `IShell*` storage, `Register`/`Unregister` pairing, interface map completeness. Writing regex or Python custom handlers that are reliable across this diversity is not tractable. An AI model already understands all these idioms.

The AI queries are tightly bounded — each query sends a single extracted code block (e.g. `Deinitialize()` body only) with a specific yes/no question (e.g. “Does this call `Release()` on the stored `IShell*`?”). Bounded queries force the model to cite the relevant line when it finds a violation, making findings verifiable. This is distinct from open-ended whole-file review, which produces verbose and hard-to-action output.

Offline regex handles only the trivial checks where the pattern is unambiguous: `throw`/`try`/`catch` keyword presence, `Module.h` include order, hardcoded absolute path literals. False-positive and false-negative risk for these patterns is negligible.

**Alternative considered:** Offline-first + optional LLM. Rejected — testing on real plugin code showed offline structural checks produced too many false positives/negatives to be reliable as the primary mechanism. The LLM is better at this class of check and should be the primary, not the fallback.

**Alternative considered:** LLM-only (whole-file open-ended review). Rejected — produces non-deterministic, hard-to-cite findings that are difficult to track and hard to suppress per rule.

---

### D4 — Delivery in `ThunderTools/PluginQA/`

**Decision:** The entire tool lives at `ThunderTools/PluginQA/`, not in the `Thunder/` repo.

**Rationale:** `ThunderTools` is the established developer-tooling distribution channel. External RDK partners already clone it for PSG. Placing `PluginQA/` alongside `PluginSkeletonGenerator/` means partners get the new tool automatically on `git pull`. The Thunder architecture rule content (instruction files) is referenced via Git submodule path resolution at runtime — the server reads the files from wherever `Thunder/` is checked out.

Rule-file path is configurable in `mcp.json` via `THUNDER_REPO_PATH` environment variable; defaults to `../Thunder` relative to `ThunderTools/`.

---

### D5 — Prompt files in workspace `.github/prompts/`, not bundled in ThunderTools

**Decision:** The four `.prompt.md` slash commands are installed into the consuming project's `.github/prompts/` directory (or `ThunderTools/.github/prompts/` for the canonical copy), not committed alongside the MCP server.

**Rationale:** VS Code resolves `.prompt.md` files relative to the open workspace root. The MCP server is a background process; prompt files are workspace-local UX. Keeping them separate means teams can customise prompt behaviour without touching the server.

---

### D7 — YAML rule files as registry and AI prompt context, not pattern execution engine

**Decision:** Each rule is a YAML file in `ThunderTools/PluginQA/rules/<category>/<rule-id>.yaml`. YAML files serve two roles: (1) a rule registry linking rule IDs to instruction file sections (for traceability and staleness detection); (2) the source of truth for what code block to extract and what question to ask the AI. There is no `type: custom` Python handler dispatch — structural analysis is delegated to the AI model, not to custom Python code.

**Rationale:** Thunder architects who own the `.github/instructions/` files should be able to add, modify, or update the AI query for a rule without Python knowledge. Adding a new structural check means adding a new `type: ai_query` YAML file specifying the extraction target and the bounded question. The Python engine is written once and handles the API call mechanics. External RDK partners can extend the rule set by adding YAML files.

YAML rule schema — `type: pattern` (offline):
```yaml
id: plugin/throw-present
severity: error
source: "09-error-handling-and-logging.md#No-Exceptions"
description: throw/try/catch found in plugin source
type: pattern
pattern: '\b(throw|try|catch)\b'
scope: any
```

YAML rule schema — `type: ai_query` (structural, AI-evaluated):
```yaml
id: plugin/register-leak
severity: error
source: "10-plugin-development.md#JSON-RPC-Method-Registration"
description: Register() call without matching Unregister() in Deinitialize()
type: ai_query
extract:
  - initialize_body
  - deinitialize_body
query: >
  Does Initialize() call Register() or Subscribe() without a matching
  Unregister() or Unsubscribe() call in Deinitialize()?
  If yes, cite the Register/Subscribe call line. If no, say "no issue".
scope: cpp
```

The `extract` field names one or more structural regions the parser extracts from the file. The `query` field is the bounded yes/no question sent to the AI with those extracted blocks as context.

**Alternative considered:** `type: custom` Python handlers for structural rules. Rejected — custom handlers suffer the same C++ idiom diversity problem as regex. An AI model is better at this class of check and does not require a Python handler per rule.

---

### D6 — New `PluginQA.yml` CI workflow, not extending PSG workflow

**Decision:** A standalone `PluginQA.yml` workflow, mirroring the PSG pattern but independent.

**Rationale:** PSG CI generates and previews skeletons on generator changes; PluginQA CI reviews plugin source on plugin-directory changes. Their triggers, matrix strategies, and output destinations differ. A shared workflow template would couple unrelated concerns. Both reuse the same `GH_TOKEN` / GitHub Models API pattern.

## Risks / Trade-offs

| Risk | Mitigation |
|------|-----------|
| MCP SDK protocol version breaks between VS Code releases | Pin `mcp` SDK version in `requirements.txt`; test against VS Code Insiders in CI matrix |
| AI model returns a false positive (flags non-violation as violation) | Each `ai_query` rule ships with a known-good test snippet; CI asserts no false positive on that snippet with the live model |
| AI model returns a false negative (misses a real violation) | Each `ai_query` rule ships with a known-bad test snippet; CI asserts finding is present |
| GitHub Models API unavailable (network outage, token expired) | AI pass is gated on `GH_TOKEN`; when absent or on API failure, offline findings are returned and a `system/ai-unavailable` meta-finding is appended |
| PSG subprocess path fragility (Python version, working directory) | MCP server resolves PSG path from `THUNDER_TOOLS_PATH` env var; documents invocation contract clearly; fails fast with actionable error |
| GitHub Models API rate limits in CI | Add retry with exponential back-off (max 3 attempts per query); per-rule failure is isolated — remaining rules still run; CI still posts offline findings when rate-limited |
| Rule file staleness (instruction files updated, rule engine not) | Each rule includes a `source` tag referencing the instruction file section; CI includes a rule-freshness lint that fails if a referenced section has been deleted |
| Linux/macOS parity for file path handling in rule engine | All paths normalised through `pathlib.Path`; primary dev and CI target is Linux (`ubuntu-latest`); `macos-latest` also included in CI matrix to verify macOS support |

## Open Questions

1. **Versioning of the MCP server tool schemas** — should tool input/output schemas be versioned independently (e.g. `review_plugin/v1`) or tied to the overall `PluginQA` release tag? Affects how Copilot prompt files reference tools.
2. **Rule suppression mechanism** — should developers be able to suppress individual findings with a comment annotation (e.g. `// TPQA:suppress IShell-no-addref`) in plugin source? Useful for intentional deviations, but adds parsing surface.
3. **ThunderDevTools integration** — should `thunder-plugin-qa` be added as option `2` in the `ThunderDevTools.py` menu alongside PSG option `1`? Low effort but needs a decision before delivery.
