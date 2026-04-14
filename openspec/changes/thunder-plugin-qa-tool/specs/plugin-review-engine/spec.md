## ADDED Requirements

### Requirement: Rule engine is invocable as a standalone CLI script
The rule engine SHALL be runnable directly from the terminal as
`python review_plugin.py <file> [<file> ...]` without any server process, AI model, or
network connectivity. It SHALL print findings as line-delimited JSON to stdout and exit
with code `1` if any `error`-severity findings are present, `0` otherwise.

#### Scenario: Terminal invocation on a single file
- **WHEN** a developer runs `python review_plugin.py MyPlugin.cpp` from the terminal
- **THEN** findings are printed as JSON objects, one per line, each with `ruleId`, `severity`, `file`, `line`, `message`
- **THEN** the process exits with code `1` if any finding has `severity: "error"`, else `0`

#### Scenario: Zero-finding run exits cleanly
- **WHEN** `review_plugin.py` is run on a PSG-generated unmodified skeleton
- **THEN** no output is produced and the process exits with code `0`

---

### Requirement: Each rule is defined as a YAML file in `rules/<category>/`
The rule engine SHALL load rule definitions from YAML files at
`ThunderTools/PluginQA/rules/<category>/<rule-id>.yaml` at startup. Adding a new rule
SHALL require only creating a new YAML file — no Python code changes for pattern-type
rules. Removing a rule SHALL require only deleting its YAML file.

The mandatory fields in every rule YAML file are:
- `id`: stable dot-free slash-separated identifier (e.g. `mem/ishell-no-addref`)
- `severity`: one of `error`, `warning`, `suggestion`
- `source`: reference to the instruction file section (e.g. `05-object-lifecycle-and-memory.md#IShell-Lifetime-Rules`)
- `description`: one-line human-readable description
- `type`: one of `pattern` (regex per line), `context_pair` (regex requiring paired presence/absence across method bodies), or `custom` (delegates to a named Python handler)
- `scope`: one of `cpp`, `h`, or `any`

For `type: pattern` rules, a `pattern` field (Python regex string) is also required.
For `type: custom` rules, a `handler` field naming the Python module in `rule_engine/custom/` is required.

#### Scenario: New rule added via YAML without Python changes
- **WHEN** a new `rules/plugin/my-new-rule.yaml` file is created with `type: pattern`
- **THEN** the rule engine loads and applies it on the next run without any Python modification
- **THEN** a finding with the new rule's `id` appears when the pattern matches

#### Scenario: Rule removed by deleting its YAML file
- **WHEN** a rule's YAML file is deleted from `rules/`
- **THEN** the rule engine no longer produces findings for that rule ID

#### Scenario: YAML file with missing required field is rejected at startup
- **WHEN** a rule YAML file is missing a required field (e.g. `severity`)
- **THEN** the engine fails at startup with an actionable error message naming the file and missing field

---

### Requirement: Structural rules use named Python custom handlers
Rules that require structural analysis across method bodies (e.g. paired
`Register`/`Unregister` calls across `Initialize` and `Deinitialize`) SHALL use
`type: custom` in their YAML file and delegate to a Python module in
`rule_engine/custom/`. Custom handlers SHALL receive parsed structural context (extracted
method bodies, class declarations, include order) from the engine's shared parser — they
SHALL NOT re-parse raw file text.

#### Scenario: Custom handler receives pre-parsed context
- **WHEN** the engine runs a `type: custom` rule
- **THEN** the handler is called with a `ParsedFile` object containing extracted method bodies and class structure
- **THEN** the handler does not open or read the source file directly

---

### Requirement: Rule engine covers all mandatory Thunder cross-cutting rules
The rule engine SHALL implement a check for each of the following rule categories. Each
check SHALL be deterministic, offline, and produce a finding with a stable `ruleId`.

| Rule ID | Category | Severity |
|---------|----------|----------|
| `mem/ishell-no-addref` | `IShell*` stored without `AddRef()` | error |
| `mem/ishell-no-release` | `IShell*` not released in `Deinitialize()` | error |
| `mem/qi-no-release` | `QueryInterface`/`QueryInterfaceByCallsign` result not released | error |
| `mem/direct-delete-com` | `delete` used directly on a COM interface pointer | error |
| `iface/missing-external` | COM class or struct missing `EXTERNAL` | error |
| `iface/non-hresult-method` | Interface method not returning `Core::hresult` | error |
| `iface/non-virtual-iunknown` | Interface lacks `virtual public Core::IUnknown` | error |
| `iface/stl-across-boundary` | STL container in interface method signature | error |
| `plugin/throw-present` | `throw`, `try`, or `catch` found in plugin source | error |
| `plugin/init-logic-in-ctor` | Non-trivial logic in constructor or destructor | warning |
| `plugin/register-leak` | `Register()` call without matching `Unregister()` | error |
| `plugin/missing-unavailable` | `IPlugin::INotification` subclass missing `Unavailable()` | error |
| `plugin/hardcoded-path` | Hardcoded absolute path (not a `%token%`) | warning |
| `plugin/module-h-not-first` | `Module.h` not the first include in a `.cpp` file | warning |
| `imap/incomplete` | `BEGIN_INTERFACE_MAP` missing an inherited interface entry | warning |
| `config/raw-json-parse` | Config parsed by hand rather than via `Core::JSON::Container` | warning |
| `oop/missing-terminate` | OOP plugin `Deinitialize()` missing `connection->Terminate()` | warning |

#### Scenario: Each rule produces a finding for a known-bad snippet
- **WHEN** the rule engine is run against the test corpus file for rule `<ruleId>`
- **THEN** a finding with that `ruleId` is present in the output
- **THEN** the finding cites the correct line number from the test corpus

#### Scenario: Each rule does not fire on a known-good snippet
- **WHEN** the rule engine is run against the clean reference snippet for rule `<ruleId>`
- **THEN** no finding with that `ruleId` is present in the output

---

### Requirement: Findings include stable rule IDs, severity, and source location
Every finding produced by the rule engine SHALL include a `ruleId` (stable string
identifier), `severity` (`error` | `warning` | `suggestion`), `file` (absolute path),
`line` (1-based integer), and `message` (human-readable explanation referencing the
relevant Thunder instruction file section).

#### Scenario: Finding includes instruction file reference
- **WHEN** the rule engine produces a finding
- **THEN** the `message` field ends with a reference of the form `(see <instruction-file>#<section>)`

---

### Requirement: Rule engine test corpus ships alongside the engine
A test corpus SHALL be maintained at `ThunderTools/PluginQA/tests/corpus/`. Each rule
SHALL have at least one `<ruleId>-bad.cpp` and one `<ruleId>-good.cpp` snippet file.
The corpus SHALL be runnable via `pytest` as part of CI.

#### Scenario: pytest passes on the corpus
- **WHEN** `pytest ThunderTools/PluginQA/tests/` is run in CI
- **THEN** all corpus tests pass (each bad snippet triggers its rule, each good snippet does not)

---

### Requirement: LLM-enhanced pass is invoked only when GH_TOKEN is present
When the environment variable `GH_TOKEN` is set, the rule engine SHALL perform a second
LLM-backed pass using the GitHub Models API after the offline pass. The LLM findings
SHALL be merged into the same output structure with `source: "llm"` on each finding.
When `GH_TOKEN` is absent, only the offline pass runs.

#### Scenario: Offline-only mode when no token
- **WHEN** `GH_TOKEN` is not set in the environment
- **THEN** `review_plugin` returns findings with `source: "offline"` only
- **THEN** no network call is made

#### Scenario: LLM findings appended when token present
- **WHEN** `GH_TOKEN` is set and the GitHub Models API returns a valid response
- **THEN** `review_plugin` returns findings from both passes, each tagged with `source: "offline"` or `source: "llm"`

#### Scenario: LLM API failure does not abort offline results
- **WHEN** the GitHub Models API returns a non-200 response or times out
- **THEN** `review_plugin` still returns the offline findings
- **THEN** a `warning`-severity meta-finding with `ruleId: "system/llm-unavailable"` is appended to indicate the LLM pass was skipped
