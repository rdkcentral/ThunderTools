## Why

Thunder plugin developers — both inside the RDK team and across the wider RDK ecosystem — routinely introduce architectural violations (missing `EXTERNAL` macro, wrong `AddRef`/`Release` discipline, JSONRPC registration leaks, STL containers across COM boundaries) that are only caught late in review or at runtime. The existing PluginSkeletonGenerator (PSG) reduces boilerplate errors at creation time but provides no ongoing quality guidance as plugins evolve, and it cannot be invoked by an AI agent. With GitHub Copilot now approved across the organisation and VS Code Agent mode widely adopted, the right moment exists to close this gap with a purpose-built AI quality assurance tool.

## What Changes

- **New**: Python MCP server (`ThunderTools/PluginQA/mcp_server.py`) exposing Thunder-aware tools that any MCP-compatible AI agent (Copilot Agent mode, Claude Desktop) can invoke programmatically.
- **New**: VS Code prompt files (`/thunder-generate`, `/thunder-review`, `/thunder-pattern`, `/thunder-interface`) providing guided conversational entry points that orchestrate the MCP tools.
- **New**: Static analysis rule engine embedded in the MCP server — offline, regex/AST-lite checks covering all cross-cutting Thunder architecture rules.
- **New**: GitHub Actions workflow (`PluginQA.yml`) that runs the rule engine on PRs and posts structured review comments using the GitHub Models API.
- **New**: `mcp.json` sample configuration so developers can connect VS Code Copilot Agent mode to the server with one-time setup.
- The existing PSG is **unchanged** — `generate_skeleton` calls it as a subprocess; no PSG source is modified.

## Capabilities

### New Capabilities

- `mcp-server`: Python MCP server process hosting all Thunder QA tools; acts as the engine for all other layers. Exposes `review_plugin`, `generate_skeleton`, `validate_interface`, `suggest_pattern`, and `explain_rule` as MCP tools.
- `plugin-review-engine`: Rule-based analysis engine inside the MCP server that parses Thunder C++ plugin files and checks them against the full set of Thunder architecture rules (IPlugin contract, COM ref-counting, interface map completeness, JSONRPC symmetry, config class pattern, OOP constraints, etc.). Produces structured, file:line-cited findings with severity levels.
- `prompt-files`: Four `.prompt.md` slash commands for VS Code Copilot Chat that orchestrate the MCP tools in natural developer workflows: generate a skeleton, review a plugin, look up a pattern, validate an interface.
- `ci-pr-review`: GitHub Actions workflow that triggers on plugin PRs, runs the review engine, and posts a structured quality report as a PR comment using the GitHub Models API.

### Modified Capabilities

## Impact

- **ThunderTools repo**: New `PluginQA/` subdirectory added alongside `PluginSkeletonGenerator/`. PSG source untouched.
- **`.github/prompts/`**: Four new `.prompt.md` files added to the workspace.
- **`.vscode/mcp.json`**: New sample config file for local MCP server connection.
- **`.github/workflows/PluginQA.yml`**: New CI workflow, mirrors `PluginSkeletonGenerator.yml` pattern.
- **Dependencies**: `mcp` Python SDK (new), `PyYAML` (already a PSG dep), Python stdlib only for the rule engine parser.
- **Platforms**: macOS (primary dev), Linux (CI). No Windows requirement.
- **External partners**: Tool is self-contained in `ThunderTools/` — external RDK partners clone ThunderTools and run the MCP server the same way they run PSG today.
