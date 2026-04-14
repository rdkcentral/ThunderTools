## ADDED Requirements

### Requirement: MCP server starts and advertises tools
The MCP server SHALL start as a local stdio-transport MCP process, advertise all five
tools (`review_plugin`, `generate_skeleton`, `validate_interface`, `suggest_pattern`,
`explain_rule`) with valid JSON Schema descriptions, and respond to the MCP initialisation
handshake without error.

#### Scenario: Successful MCP initialisation
- **WHEN** an MCP client connects to the server's stdio transport
- **THEN** the server responds with a valid `initialize` response listing all five tools
- **THEN** each tool entry contains a non-empty `description` and a valid `inputSchema`

#### Scenario: Server reports version in initialisation response
- **WHEN** the MCP client sends an `initialize` request
- **THEN** the server's response includes a `serverInfo` block with `name: "thunder-plugin-qa"` and a semver `version` field

---

### Requirement: review_plugin tool accepts file paths and returns findings
The `review_plugin` tool SHALL accept one or more C++ file paths, run the offline rule
engine against each, and return a structured list of findings. Each finding SHALL include:
file path, line number, rule ID, severity (`error` | `warning` | `suggestion`), and a
human-readable message.

#### Scenario: Plugin file with IShell stored without AddRef
- **WHEN** `review_plugin` is called with a `.cpp` file where `_service = service` appears in `Initialize()` but no `_service->AddRef()` call follows
- **THEN** the response contains at least one finding with `ruleId: "mem/ishell-no-addref"` and `severity: "error"` citing the file and line

#### Scenario: Clean plugin file produces no error-severity findings
- **WHEN** `review_plugin` is called with a PSG-generated skeleton plugin that has not been modified
- **THEN** the response contains zero findings with `severity: "error"`

#### Scenario: Multiple files processed in one call
- **WHEN** `review_plugin` is called with paths to both a plugin `.h` and `.cpp`
- **THEN** findings from both files are included in the single response, each citing the correct source file

#### Scenario: Non-existent file path returns structured error
- **WHEN** `review_plugin` is called with a path that does not exist
- **THEN** the response contains a finding with `ruleId: "io/file-not-found"` and `severity: "error"` for that path
- **THEN** processing of any valid file paths in the same call is not aborted

---

### Requirement: generate_skeleton tool invokes PSG and returns generated file tree
The `generate_skeleton` tool SHALL accept a YAML config string (conforming to the PSG
`Config.yaml` schema), write it to a temporary file, invoke `PluginSkeletonGenerator.py`
as a subprocess, and return the list of generated file paths relative to the output
directory.

#### Scenario: Valid config generates expected skeleton files
- **WHEN** `generate_skeleton` is called with a valid YAML config specifying plugin name and at least one interface path
- **THEN** PSG runs to completion (exit code 0)
- **THEN** the response includes at least `<PluginName>.h`, `<PluginName>.cpp`, `Module.h`, `Module.cpp`, `CMakeLists.txt`

#### Scenario: PSG failure surfaces a structured error
- **WHEN** PSG exits with a non-zero exit code
- **THEN** the response contains `success: false`, the PSG stderr output, and no partial file list

#### Scenario: PSG binary not found returns actionable error
- **WHEN** the `THUNDER_TOOLS_PATH` environment variable points to a directory without `PluginSkeletonGenerator.py`
- **THEN** the response contains an error with a message that includes the expected path and how to set `THUNDER_TOOLS_PATH`

---

### Requirement: validate_interface tool checks COM interface header compliance
The `validate_interface` tool SHALL accept a path to a C++ header file, parse it for COM
interface declarations, and return a list of compliance findings against the Thunder
interface rules.

#### Scenario: Interface missing EXTERNAL keyword
- **WHEN** `validate_interface` is called on a header where a `struct` inherits `Core::IUnknown` but is not decorated with `EXTERNAL`
- **THEN** the response contains a finding with `ruleId: "iface/missing-external"` and `severity: "error"`

#### Scenario: Interface method not returning Core::hresult
- **WHEN** `validate_interface` is called on a header where an interface method returns `void` or `bool`
- **THEN** the response contains a finding with `ruleId: "iface/non-hresult-method"` and `severity: "error"` for each such method

#### Scenario: Compliant interface produces no error findings
- **WHEN** `validate_interface` is called on a well-formed interface from `ThunderInterfaces/interfaces/`
- **THEN** the response contains zero findings with `severity: "error"`

---

### Requirement: suggest_pattern tool returns canonical Thunder code pattern
The `suggest_pattern` tool SHALL accept a natural-language description of a development
scenario and return the matching canonical Thunder pattern name, a concise explanation,
and a code example drawn from the Thunder instruction files.

#### Scenario: Sink pattern query
- **WHEN** `suggest_pattern` is called with a description matching the observer/notification use case (e.g. "I need to receive plugin lifecycle events")
- **THEN** the response identifies pattern `"sink-notification"` and includes a code example using `Core::SinkType<T>` and `BEGIN_INTERFACE_MAP`

#### Scenario: No matching pattern
- **WHEN** `suggest_pattern` is called with a description that does not match any known Thunder pattern
- **THEN** the response indicates no pattern was matched and suggests consulting the Thunder documentation

---

### Requirement: explain_rule tool returns full rule explanation
The `explain_rule` tool SHALL accept a rule ID or keyword and return the full explanation
text from the corresponding Thunder instruction file section.

#### Scenario: Valid rule ID returns explanation
- **WHEN** `explain_rule` is called with a known rule ID (e.g. `"mem/ishell-no-addref"`)
- **THEN** the response includes the rule description, the correct code pattern, and the anti-pattern to avoid

#### Scenario: Keyword search returns matching rules
- **WHEN** `explain_rule` is called with a keyword (e.g. `"EXTERNAL"`)
- **THEN** the response includes all rules whose description contains that keyword

---

### Requirement: mcp.json sample enables one-time VS Code setup
A sample `mcp.json` configuration file SHALL be provided so a developer can connect VS
Code Copilot Agent mode to the `thunder-plugin-qa` server by setting one environment
variable (`THUNDER_TOOLS_PATH`) and adding the config to their VS Code settings.

#### Scenario: Developer connects VS Code to the server
- **WHEN** a developer copies `ThunderTools/PluginQA/mcp.json` content into their `.vscode/mcp.json`
- **WHEN** they set `THUNDER_TOOLS_PATH` to the root of their ThunderTools checkout
- **THEN** VS Code Copilot Agent mode lists `thunder-plugin-qa` as an available MCP server with all five tools visible
