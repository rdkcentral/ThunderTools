## Context

Thunder plugin development is distributed across the core RDK team and a wider ecosystem of partner companies. The existing PluginSkeletonGenerator (PSG) is a Python CLI in `ThunderTools/` that generates correct boilerplate from an interface header, but it operates only at creation time and cannot be invoked by an AI agent. A rich set of Thunder architecture rules is already encoded in `.github/instructions/` (rules files 00–12), but these are only consulted reactively and manually.

VS Code Copilot Agent mode with MCP tool support is now the approved AI-coding surface across the organisation. The GitHub Models API is already in production use in the PSG CI workflow. The tool must be self-contained in `ThunderTools/` so external RDK partners can adopt it through the same distribution channel they already use for PSG.

## Goals / Non-Goals

**Goals:**
- `review_plugin.py` is the single review mechanism used by both the VS Code Agent (invoked via the agent's terminal tool from a `.prompt.md` slash command) and GitHub Actions (headless subprocess). One tool, two surfaces.
- One GitHub Models API call per plugin file — API cost scales with files reviewed, not rule count.
- YAML rule files define the checklist embedded in that single call. Architects own and update rules without Python knowledge.
- Prompt files provide structured, repeatable workflows for developers in VS Code Agent mode: review a plugin, generate a skeleton and review it, look up a pattern, validate an interface.
- Catch architecture violations at the PR gate via CI, before merge.
- Zero changes to existing PSG source.
- MCP server wrapper is an optional enhancement for agent-driven sessions outside VS Code.

**Non-Goals:**
- Full C++ compiler-level static analysis (clang-tidy integration is out of scope).
- Runtime plugin testing or sandboxed execution.
- Auto-fixing found violations (the tool reports; the developer fixes).
- Supporting non-Thunder C++ codebases.
- VS Code extension (`@thunder` chat participant) — planned for a future phase after MCP adoption is proven.

## Decisions

### D1 — Single Python harness used by both VS Code Agent and CI

**Decision:** `review_plugin.py` is the only review execution artifact. VS Code prompt files invoke it via the agent's built-in terminal tool. GitHub Actions invokes it as a headless subprocess. There is no separate pure-prompt path and no separate CI-only script.

**Rationale:** A developer using Copilot Agent mode already has access to the terminal tool — the `.prompt.md` file instructs the agent to run `python ThunderTools/PluginQA/review_plugin.py <file>`, capture the JSON output, and present it formatted. This is simpler than maintaining two separate review paths (one for agent, one for CI) that must produce consistent findings. A single script means a single test corpus, a single prompt assembly path, and a single place to update when YAML rules change. The marginal cost of one API call in VS Code Agent mode is negligible alongside the agent's own inference cost for the session.

**Alternative considered:** Pure prompt files (no Python) for VS Code, Python script only for CI. Rejected — produces two divergent review paths that must be kept consistent. The agent's prompt-only review would not be deterministic or diffable against CI findings.

---

### D2 — Python `mcp` SDK for the optional MCP wrapper

**Decision:** If/when the MCP server is built, use the official `mcp` Python SDK (`pip install mcp`). The core rule engine requires only `PyYAML` (already a PSG dependency) — zero new dependencies.

**Rationale:** The MCP SDK handles transport negotiation, tool schema serialisation, and capability advertisement automatically. Keeping it out of the core `requirements.txt` means the rule engine and CI workflow are immediately usable without any additional installation. The `mcp` SDK goes in a separate `requirements-mcp.txt`.

**Alternative considered:** Implement the MCP wire protocol directly (JSON-RPC over stdio). Rejected — the protocol has version negotiation complexity not worth hand-rolling.

---

### D3 — Single API call per plugin file; rule checklist embedded in the prompt

**Decision:** `review_plugin.py` makes exactly one GitHub Models API call per plugin file. The call sends the full file content (or key structural sections for very large files) alongside a structured rule checklist built from the YAML registry. The model is instructed to return findings as a JSON array — no commentary, no prose — citing rule ID and line number for each violation found.

**Rationale:** The previous design dispatched one API call per rule (8 calls per file). For a PR touching 10 plugin files that would be 80 API calls with 15–30 seconds of cumulative latency. A single call per file costs the same inference tokens but eliminates 7/8 of the round-trips and latency. The model sees the whole file at once, which *improves* cross-method checks (e.g. it sees `Initialize` and `Deinitialize` together when checking `Register`/`Unregister` symmetry). Structuring the output as a JSON array makes findings machine-parseable without any post-processing heuristics.

**Rationale for dropping offline regex pass:** The trivial token checks (keyword presence, include order, path literals) that previously justified an offline regex pass are equally fast and more reliably understood by the model as part of the single call. Maintaining a parallel regex engine adds implementation surface and a separate test corpus with no meaningful benefit once the single-call architecture is adopted.

**Alternative considered:** Per-rule API calls. Rejected — 80 calls for a 10-file PR; latency and cost scale with rule count, not file count.

**Alternative considered:** Offline regex for trivial checks + single AI call for structural. Rejected — adds implementation surface (interpreter, test corpus) for checks the model handles equally well inside the single call.

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

### D7 — YAML rule files as a structured checklist for the single prompt

**Decision:** Each rule is a YAML file in `ThunderTools/PluginQA/rules/<category>/<rule-id>.yaml`. At CI runtime, `review_plugin.py` loads all YAML files and assembles them into a structured rule checklist that is embedded in the single prompt sent to the model. The YAML files are not an execution engine — they define what to check, not how to check it. There is no `type` dispatch, no regex, no custom handler, no `extract` field.

**Rationale:** Thunder architects who own the `.github/instructions/` files should be able to add or update a rule by editing a single plain YAML file. A new rule is one new file; removing a rule is one deleted file. The Python harness never needs to change when rules change. The checklist structure in the prompt (rule ID, severity, description, instruction file source) also gives the model enough context to explain findings in terms of the actual Thunder guidelines, not generic advice.

YAML rule schema:
```yaml
id: plugin/register-leak
severity: error
source: "10-plugin-development.md#JSON-RPC-Method-Registration"
description: >
  Register() call in Initialize() has no matching Unregister() in
  Deinitialize(). Leaked registrations cause collisions if the plugin
  is re-activated after deactivation.
scope: cpp   # cpp | h | any  — tells harness which files to pass for this rule
```

The assembled prompt instructs the model: “For each rule in this checklist, if a violation is present in the file, return a JSON object `{"ruleId", "severity", "line", "message"}`; if no violation, omit it. Return an empty array if the file is clean.”

**Alternative considered:** `type: ai_query` with per-rule `extract` and `query` fields (previous design). Rejected — requires one API call per rule (8 calls per file); single-call with checklist achieves the same review quality at 1/8 the cost.

**Alternative considered:** Rules hardcoded as Python functions or regex. Rejected — requires Python knowledge to update, couples rule logic to engine implementation.

---

### D6 — New `PluginQA.yml` CI workflow, not extending PSG workflow

**Decision:** A standalone `PluginQA.yml` workflow, mirroring the PSG pattern but independent.

**Rationale:** PSG CI generates and previews skeletons on generator changes; PluginQA CI reviews plugin source on plugin-directory changes. Their triggers, matrix strategies, and output destinations differ. A shared workflow template would couple unrelated concerns. Both reuse the same `GH_TOKEN` / GitHub Models API pattern.

## Risks / Trade-offs

| Risk | Mitigation |
|------|-----------|
| MCP SDK protocol version breaks between VS Code releases | Pin `mcp` SDK version in `requirements.txt`; test against VS Code Insiders in CI matrix |
| AI model returns a false positive (flags non-violation as violation) | CI test corpus includes a known-good snippet per rule; a nightly job runs the harness against the corpus and alerts on regressions |
| AI model returns a false negative (misses a real violation) | CI test corpus includes a known-bad snippet per rule; same nightly job asserts each bad snippet produces the expected finding |
| Single-call prompt becomes too long for very large plugin files | Harness checks token estimate before sending; if file exceeds limit, it splits by scope (`cpp` rules on `.cpp`, `h` rules on `.h`) and makes two calls at most |
| GitHub Models API unavailable (network outage, token expired) | `GH_TOKEN` absence or API failure causes `review_plugin.py` to exit non-zero with a `system/ai-unavailable` meta-finding; workflow step is marked failed but the error message is actionable |
| GitHub Models API rate limits in CI | Retry with exponential back-off (max 3 attempts); if all retries fail, workflow posts a comment noting the AI check was skipped and exits success (not failure) |
| Rule file staleness (instruction files updated, YAML rules not) | Each rule includes a `source` tag; CI includes a rule-freshness lint that warns if a referenced section anchor has been deleted from the instruction file |
| Linux/macOS parity for file path handling in harness | All paths normalised through `pathlib.Path`; primary CI target is Linux (`ubuntu-latest`); `macos-latest` also included in CI matrix |

## Open Questions

1. **Versioning of the MCP server tool schemas** — should tool input/output schemas be versioned independently (e.g. `review_plugin/v1`) or tied to the overall `PluginQA` release tag? Affects how Copilot prompt files reference tools.
2. **Rule suppression mechanism** — should developers be able to suppress individual findings with a comment annotation (e.g. `// TPQA:suppress IShell-no-addref`) in plugin source? Useful for intentional deviations, but adds parsing surface.
3. **ThunderDevTools integration** — should `thunder-plugin-qa` be added as option `2` in the `ThunderDevTools.py` menu alongside PSG option `1`? Low effort but needs a decision before delivery.
