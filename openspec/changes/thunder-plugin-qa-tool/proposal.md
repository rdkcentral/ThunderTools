## Why

Thunder plugin developers — both inside the RDK team and across the wider RDK ecosystem — routinely introduce architectural violations (missing `EXTERNAL` macro, wrong `AddRef`/`Release` discipline, JSONRPC registration leaks, STL containers across COM boundaries) that are only caught late in review or at runtime. The existing PluginSkeletonGenerator (PSG) reduces boilerplate errors at creation time but provides no ongoing quality guidance as plugins evolve, and it cannot be invoked by an AI agent. With GitHub Copilot now approved across the organisation and VS Code Agent mode widely adopted, the right moment exists to close this gap with a purpose-built AI quality assurance tool.

## What Changes

- **New (Phase 1)**: VS Code prompt files (`/thunder-generate`, `/thunder-review`, `/thunder-pattern`, `/thunder-interface`) — pure `.prompt.md` slash commands for Copilot Chat Agent mode. No Python tool required. The agent reads the open plugin file, consults the Thunder instruction files already in the workspace, and reasons about all violations directly. Review findings surface inside the VS Code Agent without any GitHub integration, network cost, or subprocess.
- **New (Phase 2)**: Thin Python CI harness (`ThunderTools/PluginQA/review_plugin.py`) that makes a **single** GitHub Models API call per plugin file, sending the full file content alongside a structured rule checklist, and returns line-delimited JSON findings. Only needed for headless GitHub Actions execution.
- **New (Phase 2)**: YAML rule registry (`rules/<category>/<rule-id>.yaml`) — one file per Thunder architecture rule, each describing the rule ID, severity, instruction file source, and description. The registry is loaded at CI runtime to build the single structured prompt sent to the model. Architects can add or modify rules without Python knowledge.
- **New (Phase 2)**: GitHub Actions workflow (`PluginQA.yml`) that triggers on plugin PRs, runs `review_plugin.py` (one API call per changed plugin file), and posts structured findings as a PR comment.
- **New (optional)**: Python MCP server (`mcp_server.py`) wrapping the CI harness for fully agent-driven sessions; requires separate `requirements-mcp.txt`. Not a prerequisite for any other capability.
- The existing PSG is **unchanged** — no PSG source is modified.

## Capabilities

### New Capabilities

- `mcp-server`: Optional Python MCP server wrapping `review_plugin.py` for fully agent-driven sessions (Copilot Agent mode, Claude Desktop). Not required for CI, terminal, or prompt-file use cases.
- `plugin-review-engine` *(Phase 2)*: Thin Python CI harness (`review_plugin.py`) that makes one GitHub Models API call per plugin file. The call sends the full file content alongside a structured checklist built from the YAML rule registry. The model returns findings in a structured format; the harness serialises them as line-delimited JSON, exits `1` on any `error` finding. No offline regex engine. No per-rule API calls.
- `prompt-files` *(Phase 1)*: Four `.prompt.md` slash commands for VS Code Copilot Chat Agent mode. Each prompt instructs the agent to read the relevant files and reason about violations using the Thunder instruction files already in the workspace — no subprocess, no API cost beyond the agent's own inference.
- `ci-pr-review` *(Phase 2)*: GitHub Actions workflow that triggers on plugin PRs, runs `review_plugin.py` (one API call per changed plugin), and posts a structured quality report as a PR comment. Delivered after Phase 1 prompt files are validated in the developer workflow.

### Modified Capabilities

## Impact

- **ThunderTools repo**: New `PluginQA/` subdirectory added alongside `PluginSkeletonGenerator/`. PSG source untouched.
- **`.github/prompts/`**: Four new `.prompt.md` files added to the workspace (Phase 1).
- **`.github/workflows/PluginQA.yml`**: New CI workflow (Phase 2), mirrors `PluginSkeletonGenerator.yml` pattern.
- **Dependencies (Phase 1)**: None — prompt files are plain Markdown. No Python, no packages.
- **Dependencies (Phase 2)**: `PyYAML` (already a PSG dep) + `openai` Python SDK for the GitHub Models API call. `mcp` SDK in a separate optional `requirements-mcp.txt`.
- **Platforms**: Linux (primary dev environment). macOS also supported and covered by CI matrix. No Windows requirement.
- **External partners**: Tool is self-contained in `ThunderTools/` — external RDK partners clone ThunderTools and adopt prompt files the same way they use PSG today.
