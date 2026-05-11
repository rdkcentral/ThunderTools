## Why

Thunder plugin developers — both inside the RDK team and across the wider RDK ecosystem — routinely introduce architectural violations (missing `EXTERNAL` macro, wrong `AddRef`/`Release` discipline, JSONRPC registration leaks, STL containers across COM boundaries) that are only caught late in review or at runtime. The existing PluginSkeletonGenerator (PSG) reduces boilerplate errors at creation time but provides no ongoing quality guidance as plugins evolve, and it cannot be invoked by an AI agent. With GitHub Copilot now approved across the organisation and VS Code Agent mode widely adopted, the right moment exists to close this gap with a purpose-built AI quality assurance tool.

## What Changes

- **New**: Python review harness (`ThunderTools/PluginQA/review_plugin.py`) — makes a single GitHub Models API call per plugin file, sending the full file content alongside a structured rule checklist, and returns line-delimited JSON findings. Used both by VS Code Agent (via the agent's terminal tool) and by GitHub Actions (headless subprocess).
- **New**: YAML rule registry (`rules/<category>/<rule-id>.yaml`) — one file per Thunder architecture rule, each describing the rule ID, severity, instruction file source, and description. Loaded at runtime to build the single structured prompt. Architects can add or modify rules without Python knowledge.
- **New**: VS Code prompt files (`/thunder-generate`, `/thunder-review`, `/thunder-pattern`, `/thunder-interface`) — `.prompt.md` slash commands for Copilot Chat Agent mode. Each prompt instructs the agent to invoke `review_plugin.py` via its terminal tool and present the findings grouped by severity.
- **New**: GitHub Actions workflow (`PluginQA.yml`) that triggers on plugin PRs, runs `review_plugin.py` on each changed plugin file, and posts structured findings as a PR comment.
- **New (optional)**: Python MCP server (`mcp_server.py`) wrapping `review_plugin.py` for fully agent-driven sessions; requires separate `requirements-mcp.txt`. Not a prerequisite for any other capability.
- The existing PSG is **unchanged** — no PSG source is modified.

## Capabilities

### New Capabilities

- `mcp-server`: Optional Python MCP server wrapping `review_plugin.py` for fully agent-driven sessions (Copilot Agent mode, Claude Desktop). Not required for CI, terminal, or prompt-file use cases.
- `plugin-review-engine`: Python harness (`review_plugin.py`) that makes one GitHub Models API call per plugin file. The call sends the full file content alongside a structured checklist built from the YAML rule registry. The model returns findings as a JSON array; the harness serialises them as line-delimited JSON, exits `1` on any `error` finding. Used by both VS Code Agent (via terminal tool) and CI (headless subprocess).
- `prompt-files`: Four `.prompt.md` slash commands for VS Code Copilot Chat Agent mode. Each prompt instructs the agent to invoke `review_plugin.py` via its terminal tool and present the findings grouped by severity and rule ID.
- `ci-pr-review`: GitHub Actions workflow that triggers on plugin PRs, runs `review_plugin.py` (one API call per changed plugin), and posts a structured quality report as a PR comment.

### Modified Capabilities

## Impact

- **ThunderTools repo**: New `PluginQA/` subdirectory added alongside `PluginSkeletonGenerator/`. PSG source untouched.
- **`.github/prompts/`**: Four new `.prompt.md` files added to the workspace.
- **`.github/workflows/PluginQA.yml`**: New CI workflow, mirrors `PluginSkeletonGenerator.yml` pattern.
- **Dependencies**: `PyYAML` (already a PSG dep) + `openai` Python SDK for the GitHub Models API call. `mcp` SDK in a separate optional `requirements-mcp.txt`.
- **Platforms**: Linux (primary dev environment). macOS also supported and covered by CI matrix. No Windows requirement.
- **External partners**: Tool is self-contained in `ThunderTools/` — external RDK partners clone ThunderTools and run `review_plugin.py` the same way they run PSG today.
