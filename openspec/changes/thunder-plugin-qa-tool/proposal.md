## Why

Thunder plugin developers — both inside the RDK team and across the wider RDK ecosystem — routinely introduce architectural violations (missing `EXTERNAL` macro, wrong `AddRef`/`Release` discipline, JSONRPC registration leaks, STL containers across COM boundaries) that are only caught late in review or at runtime. The existing PluginSkeletonGenerator (PSG) reduces boilerplate errors at creation time but provides no ongoing quality guidance as plugins evolve, and it cannot be invoked by an AI agent. With GitHub Copilot now approved across the organisation and VS Code Agent mode widely adopted, the right moment exists to close this gap with a purpose-built AI quality assurance tool.

## What Changes

- **New**: Review engine (`ThunderTools/PluginQA/review_plugin.py`) combining two mechanisms: focused AI model queries via GitHub Models API for structural checks (ref-counting discipline, call symmetry, interface map completeness), and offline regex pattern rules for trivially reliable token-level checks (keyword presence, include order, path literals).
- **New**: YAML rule registry (`rules/<category>/<rule-id>.yaml`) linking each rule ID to its instruction file source and defining either the regex pattern or the AI query and code block to extract. Architects can add or modify rules without Python knowledge.
- **New (Phase 1)**: VS Code prompt files (`/thunder-generate`, `/thunder-review`, `/thunder-pattern`, `/thunder-interface`) providing guided conversational entry points in Copilot Chat — review findings surface directly inside the VS Code Agent without any GitHub integration required.
- **New (Phase 2)**: GitHub Actions workflow (`PluginQA.yml`) that triggers on plugin PRs and posts structured findings as a PR comment. Delivered after Phase 1 is validated in the developer workflow.
- **New (optional)**: Python MCP server (`mcp_server.py`) wrapping the review engine for fully agent-driven sessions; requires separate `requirements-mcp.txt`. Not a prerequisite for any other capability.
- The existing PSG is **unchanged** — no PSG source is modified.

## Capabilities

### New Capabilities

- `mcp-server`: Optional Python MCP server wrapping the review engine for fully agent-driven sessions (Copilot Agent mode, Claude Desktop). Not required for CI, terminal, or prompt-file use cases. Exposes `review_plugin`, `generate_skeleton`, `validate_interface`, `suggest_pattern`, and `explain_rule` as MCP tools.
- `plugin-review-engine`: Hybrid analysis engine that is AI-primary for structural checks and offline-secondary for trivial token checks. Structural checks (ref-counting discipline, JSONRPC registration symmetry, interface map completeness, etc.) are evaluated by sending focused, extracted code blocks with yes/no questions to the GitHub Models API — not whole files, not open-ended prompts. Offline checks handle trivially reliable token patterns (keyword presence, include order, path literals). Every finding is tagged `source: "ai"`, `source: "offline"`, or `source: "skipped"` (when `GH_TOKEN` is absent).
- `prompt-files`: Four `.prompt.md` slash commands for VS Code Copilot Chat that orchestrate the MCP tools in natural developer workflows: generate a skeleton, review a plugin, look up a pattern, validate an interface.
- `ci-pr-review` *(Phase 2)*: GitHub Actions workflow that triggers on plugin PRs, runs the review engine, and posts a structured quality report as a PR comment. Delivered after the Phase 1 agent-surfaced results (prompt files + standalone CLI) are validated in the developer workflow.

### Modified Capabilities

## Impact

- **ThunderTools repo**: New `PluginQA/` subdirectory added alongside `PluginSkeletonGenerator/`. PSG source untouched.
- **`.github/prompts/`**: Four new `.prompt.md` files added to the workspace.
- **`.vscode/mcp.json`**: New sample config file for local MCP server connection.
- **`.github/workflows/PluginQA.yml`**: New CI workflow, mirrors `PluginSkeletonGenerator.yml` pattern.
- **Dependencies**: `PyYAML` (already a PSG dep), Python stdlib only for the rule engine core. `mcp` SDK in a separate optional `requirements-mcp.txt`.
- **Platforms**: Linux (primary dev environment). macOS also supported and covered by CI matrix. No Windows requirement.
- **External partners**: Tool is self-contained in `ThunderTools/` — external RDK partners clone ThunderTools and run the MCP server the same way they run PSG today.
