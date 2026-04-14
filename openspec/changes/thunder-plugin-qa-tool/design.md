## Context

Thunder plugin development is distributed across the core RDK team and a wider ecosystem of partner companies. The existing PluginSkeletonGenerator (PSG) is a Python CLI in `ThunderTools/` that generates correct boilerplate from an interface header, but it operates only at creation time and cannot be invoked by an AI agent. A rich set of Thunder architecture rules is already encoded in `.github/instructions/` (rules files 00–12), but these are only consulted reactively and manually.

VS Code Copilot Agent mode with MCP tool support is now the approved AI-coding surface across the organisation. The GitHub Models API is already in production use in the PSG CI workflow. The tool must be self-contained in `ThunderTools/` so external RDK partners can adopt it through the same distribution channel they already use for PSG.

## Goals / Non-Goals

**Goals:**
- Provide offline, deterministic rule-checking of plugin C++ files covering all Thunder architecture rules — no AI model required at review time.
- Rule definitions are plain YAML files, editable without Python knowledge, so Thunder architects can own and update rules directly.
- Surface quality guidance in VS Code Agent mode via prompt-file slash commands backed by the standalone rule engine.
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

### D3 — Hybrid review: deterministic offline pass + optional LLM pass

**Decision:** The rule engine runs a deterministic offline pass first (always, no model, no network), then an optional LLM pass (GitHub Models API) if a `GH_TOKEN` is available.

**Rationale:** The offline pass is the primary value — it runs everywhere (developer laptop without internet, CI without secrets, air-gapped partner environments) and produces the same result every time. The LLM pass adds semantic depth (spotting logic errors in Initialize/Deinitialize ordering that pattern matching cannot) but is explicitly additive. No AI model is needed for the core review.

**Alternative considered:** LLM-only. Rejected — adds network latency, requires a token, and produces non-deterministic results that make it hard to track improvements.

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

### D7 — Rules defined as YAML files, not hardcoded Python (Option B)

**Decision:** Each rule is a YAML file in `ThunderTools/PluginQA/rules/<category>/<rule-id>.yaml`. A Python interpreter in the engine reads and executes these rules. Structural rules that cannot be expressed as patterns use a `type: custom` tag pointing to a named Python handler in `rule_engine/custom/`.

**Rationale:** Thunder architects who own the `.github/instructions/` files should be able to add, modify, or remove rules without Python knowledge. A YAML rule file for a simple pattern check is ~10 lines; adding a new rule means dropping a new file in `rules/`, not editing engine code. The engine is written once. External RDK partners can extend the rule set for their own conventions by adding YAML files alongside the default set.

YAML rule schema:
```yaml
id: plugin/throw-present          # stable rule ID
severity: error                   # error | warning | suggestion
source: "09-error-handling-and-logging.md#No-Exceptions"
description: throw/try/catch found in plugin source
type: pattern                     # pattern | context_pair | custom
pattern: '\b(throw|try|catch)\b'  # regex applied per line
scope: cpp                        # cpp | h | any
```

Complex structural rules (e.g. `plugin/register-leak` requiring paired call analysis across `Initialize`/`Deinitialize`) use `type: custom` with a `handler: register_symmetry` field, mapping to `rule_engine/custom/register_symmetry.py`.

**Alternative considered (Option A):** Rules hardcoded as Python functions. Rejected — requires Python knowledge to update, couples rule logic to engine implementation, and makes it hard for architects to own rules independently.

---

### D6 — New `PluginQA.yml` CI workflow, not extending PSG workflow

**Decision:** A standalone `PluginQA.yml` workflow, mirroring the PSG pattern but independent.

**Rationale:** PSG CI generates and previews skeletons on generator changes; PluginQA CI reviews plugin source on plugin-directory changes. Their triggers, matrix strategies, and output destinations differ. A shared workflow template would couple unrelated concerns. Both reuse the same `GH_TOKEN` / GitHub Models API pattern.

## Risks / Trade-offs

| Risk | Mitigation |
|------|-----------|
| MCP SDK protocol version breaks between VS Code releases | Pin `mcp` SDK version in `requirements.txt`; test against VS Code Insiders in CI matrix |
| Regex rule engine produces false positives / false negatives | Each rule ships with a test corpus of pass/fail C++ snippets; coverage tracked by rule ID |
| PSG subprocess path fragility (Python version, working directory) | MCP server resolves PSG path from `THUNDER_TOOLS_PATH` env var; documents invocation contract clearly; fails fast with actionable error |
| GitHub Models API rate limits in CI | Add retry with exponential back-off; LLM pass is optional — CI still posts offline findings when rate-limited |
| Rule file staleness (instruction files updated, rule engine not) | Each rule includes a `source` tag referencing the instruction file section; CI includes a rule-freshness lint that fails if a referenced section has been deleted |
| macOS vs. Linux parity for file path handling in rule engine | All paths normalised through `pathlib.Path`; CI matrix covers both ubuntu-latest and macos-latest |

## Open Questions

1. **Versioning of the MCP server tool schemas** — should tool input/output schemas be versioned independently (e.g. `review_plugin/v1`) or tied to the overall `PluginQA` release tag? Affects how Copilot prompt files reference tools.
2. **Rule suppression mechanism** — should developers be able to suppress individual findings with a comment annotation (e.g. `// TPQA:suppress IShell-no-addref`) in plugin source? Useful for intentional deviations, but adds parsing surface.
3. **ThunderDevTools integration** — should `thunder-plugin-qa` be added as option `2` in the `ThunderDevTools.py` menu alongside PSG option `1`? Low effort but needs a decision before delivery.
