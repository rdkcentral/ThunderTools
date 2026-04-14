## ADDED Requirements

### Requirement: /thunder-generate prompt guides end-to-end plugin creation
The `thunder-generate.prompt.md` file SHALL instruct Copilot Agent to collect plugin
parameters from the developer via conversational Q&A, construct a PSG-compatible YAML
config, call the `generate_skeleton` MCP tool, and automatically follow by calling
`review_plugin` on the generated output.

#### Scenario: Full generate and auto-review flow
- **WHEN** the developer invokes `/thunder-generate` in Copilot Chat
- **THEN** the agent asks for: plugin name, OOP or in-process, interface header path(s), optional subsystems
- **WHEN** the developer provides all answers
- **THEN** the agent calls `generate_skeleton` with the constructed YAML config
- **THEN** the agent immediately calls `review_plugin` on the generated files
- **THEN** both the generated file list and any review findings are shown in the chat response

#### Scenario: Generate fails with actionable message
- **WHEN** `generate_skeleton` returns `success: false`
- **THEN** the agent shows the PSG error output and suggests corrective actions (e.g. "check that the interface path exists")

---

### Requirement: /thunder-review prompt reviews open or specified plugin files
The `thunder-review.prompt.md` file SHALL instruct Copilot Agent to call `review_plugin`
on the currently open file or on explicitly specified file paths, and render findings
grouped by severity.

#### Scenario: Review the currently open file
- **WHEN** the developer invokes `/thunder-review` with no arguments and a plugin `.cpp` or `.h` file is open in the editor
- **THEN** the agent calls `review_plugin` with the open file's path
- **THEN** findings are displayed grouped into Errors, Warnings, and Suggestions sections

#### Scenario: Review specified files
- **WHEN** the developer invokes `/thunder-review MyPlugin.h MyPlugin.cpp`
- **THEN** the agent calls `review_plugin` with both paths
- **THEN** combined findings are displayed grouped by severity

#### Scenario: No findings produces a positive confirmation
- **WHEN** `review_plugin` returns zero error or warning findings
- **THEN** the agent responds with a confirmation message (e.g. "No architecture violations found ✅")

---

### Requirement: /thunder-pattern prompt returns canonical Thunder pattern
The `thunder-pattern.prompt.md` file SHALL instruct Copilot Agent to call `suggest_pattern`
with the developer's scenario description and render the matched pattern name, explanation,
and code example.

#### Scenario: Pattern found and rendered
- **WHEN** the developer invokes `/thunder-pattern I need to observe another plugin's lifecycle`
- **THEN** the agent calls `suggest_pattern` with the description
- **THEN** the chat response shows the pattern name, a one-paragraph explanation, and a formatted code block

#### Scenario: No matching pattern
- **WHEN** `suggest_pattern` returns no match
- **THEN** the agent tells the developer no built-in pattern was matched and offers to search the Thunder documentation

---

### Requirement: /thunder-interface prompt validates a COM interface header
The `thunder-interface.prompt.md` file SHALL instruct Copilot Agent to call
`validate_interface` on the open or specified header file and summarise compliance
findings.

#### Scenario: Interface validation on open header
- **WHEN** the developer invokes `/thunder-interface` with no arguments and a `.h` file is open
- **THEN** the agent calls `validate_interface` with the open header's path
- **THEN** findings are shown with file:line citations and references to the relevant Thunder interface rule

#### Scenario: Compliant interface
- **WHEN** `validate_interface` returns no error-severity findings
- **THEN** the agent confirms the interface is compliant with Thunder interface design rules

---

### Requirement: Prompt files are installable into any workspace
The four prompt files SHALL be usable by any developer with the `thunder-plugin-qa` MCP
server configured, regardless of whether they are working in the `ThunderTools` repo or an
external plugin repo. The canonical copies SHALL live at
`ThunderTools/PluginQA/prompts/*.prompt.md`. A setup script or README SHALL describe how
to copy them into a workspace's `.github/prompts/` directory.

#### Scenario: Prompt files work in an external plugin repo
- **WHEN** a developer copies the four `.prompt.md` files into their project's `.github/prompts/`
- **WHEN** the `thunder-plugin-qa` MCP server is configured in their `.vscode/mcp.json`
- **THEN** all four `/thunder-*` slash commands appear and function correctly in Copilot Chat Agent mode
