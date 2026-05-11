## ADDED Requirements

### Requirement: Rule engine is invocable as a standalone CLI script
The rule engine (`review_plugin.py`) SHALL be runnable directly from the terminal as
`python review_plugin.py <file> [<file> ...]`. It SHALL make one GitHub Models API call
per file, using the `GH_TOKEN` environment variable for authentication. It SHALL print
findings as line-delimited JSON to stdout and exit with code `1` if any `error`-severity
findings are present, `0` otherwise.

#### Scenario: Terminal invocation on a single file
- **WHEN** a developer runs `GH_TOKEN=... python review_plugin.py MyPlugin.cpp`
- **THEN** findings are printed as JSON objects, one per line, each with `ruleId`, `severity`, `file`, `line`, `message`
- **THEN** the process exits with code `1` if any finding has `severity: "error"`, else `0`

#### Scenario: Zero-finding run exits cleanly
- **WHEN** `review_plugin.py` is run on a PSG-generated unmodified skeleton
- **THEN** no output is produced and the process exits with code `0`

#### Scenario: Missing GH_TOKEN exits with actionable error
- **WHEN** `GH_TOKEN` is not set
- **THEN** the script exits with a non-zero code and prints a message explaining that `GH_TOKEN` is required

---

### Requirement: Each rule is defined as a YAML file in `rules/<category>/`
The rule engine SHALL load rule definitions from YAML files at
`ThunderTools/PluginQA/rules/<category>/<rule-id>.yaml` at startup. Adding a new rule
SHALL require only creating a new YAML file — no Python code changes. Removing a rule
SHALL require only deleting its YAML file.

The mandatory fields in every rule YAML file are:
- `id`: stable dot-free slash-separated identifier (e.g. `mem/ishell-no-addref`)
- `severity`: one of `error`, `warning`, `suggestion`
- `source`: reference to the instruction file section (e.g. `05-object-lifecycle-and-memory.md#IShell-Lifetime-Rules`)
- `description`: one-line human-readable description used in the AI prompt checklist
- `scope`: one of `cpp`, `h`, or `any` — which file type this rule applies to

#### Scenario: New rule added via YAML without Python changes
- **WHEN** a new `rules/plugin/my-new-rule.yaml` file is created
- **THEN** the rule is included in the checklist on the next run without any Python modification

#### Scenario: Rule removed by deleting its YAML file
- **WHEN** a rule's YAML file is deleted from `rules/`
- **THEN** the rule engine no longer produces findings for that rule ID

#### Scenario: YAML file with missing required field is rejected at startup
- **WHEN** a rule YAML file is missing a required field (e.g. `severity`)
- **THEN** the engine fails at startup with an actionable error message naming the file and missing field

---

### Requirement: Rule engine makes a single API call per plugin file
For each plugin file passed to `review_plugin.py`, the engine SHALL make exactly one
GitHub Models API call. The call SHALL include the full file content and a structured
rule checklist assembled from all loaded YAML files whose `scope` matches the file type.
The model SHALL be instructed to return a JSON array of findings — each with `ruleId`,
`severity`, `line`, and `message` — and an empty array if the file is clean.

#### Scenario: Single call per file produces all findings
- **WHEN** `review_plugin.py` is run on a plugin `.cpp` file
- **THEN** exactly one API call is made to the GitHub Models API
- **THEN** the response is a JSON array covering all applicable rules
- **THEN** each finding in the array includes `ruleId`, `severity`, `line`, `message`

#### Scenario: File exceeds token limit — split by scope
- **WHEN** a plugin file is large enough that file + checklist exceeds the model context limit
- **THEN** the engine makes at most two calls: one for `cpp`-scoped rules and one for `h`-scoped rules if applicable
- **THEN** findings from both calls are merged into a single output

#### Scenario: Empty array response means clean file
- **WHEN** the model returns `[]`
- **THEN** no findings are emitted and the process exits with code `0`

---

### Requirement: Rule engine covers all 17 Thunder architecture rules
The YAML rule registry SHALL define a rule file for each of the following. All rules are
evaluated by the model in the single-call checklist.

| Rule ID | Category | Severity |
|---------|----------|----------|
| `mem/ishell-no-addref` | `IShell*` stored without `AddRef()` | error |
| `mem/ishell-no-release` | `IShell*` not released in `Deinitialize()` | error |
| `mem/qi-no-release` | `QueryInterface` result not released | error |
| `mem/direct-delete-com` | `delete` used directly on a COM interface pointer | error |
| `iface/missing-external` | COM class or struct missing `EXTERNAL` | error |
| `iface/non-hresult-method` | Interface method not returning `Core::hresult` | error |
| `iface/non-virtual-iunknown` | Interface lacks `virtual public Core::IUnknown` | error |
| `iface/stl-across-boundary` | STL container in interface method signature | error |
| `plugin/throw-present` | `throw`, `try`, or `catch` found in plugin source | error |
| `plugin/register-leak` | `Register()` without matching `Unregister()` | error |
| `plugin/missing-unavailable` | `IPlugin::INotification` subclass missing `Unavailable()` | error |
| `plugin/hardcoded-path` | Hardcoded absolute path (not a `%token%`) | warning |
| `plugin/module-h-not-first` | `Module.h` not the first include in a `.cpp` file | warning |
| `plugin/init-logic-in-ctor` | Non-trivial logic in constructor or destructor | warning |
| `imap/incomplete` | `BEGIN_INTERFACE_MAP` missing an inherited interface entry | warning |
| `config/raw-json-parse` | Config parsed by hand rather than via `Core::JSON::Container` | warning |
| `oop/missing-terminate` | OOP `Deinitialize()` missing `connection->Terminate()` | warning |

#### Scenario: Model finds a violation in the checklist
- **WHEN** `review_plugin.py` is run against a file containing a known violation
- **THEN** a finding with the expected `ruleId` and a non-null `line` appears in the output

#### Scenario: Model finds no violations
- **WHEN** `review_plugin.py` is run against a PSG-generated clean skeleton
- **THEN** the output is empty and the process exits `0`

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

### Requirement: GH_TOKEN is required; absence fails fast with an actionable message
`review_plugin.py` SHALL fail immediately with a non-zero exit code and a clear error
message when `GH_TOKEN` is not set. There is no offline fallback — the tool requires
the API. CI workflows SHALL set `GH_TOKEN` explicitly; the workflow step failing on a
missing token is intentional and correct.

#### Scenario: GH_TOKEN present — API call proceeds
- **WHEN** `GH_TOKEN` is set and the GitHub Models API returns a valid response
- **THEN** `review_plugin` returns the findings JSON array

#### Scenario: GH_TOKEN absent — fail fast
- **WHEN** `GH_TOKEN` is not set
- **THEN** the script exits with a non-zero code and prints `"GH_TOKEN is required"`
- **THEN** no API call is attempted

#### Scenario: API failure after retries — fail with meta-finding
- **WHEN** the GitHub Models API returns a non-200 response or times out on all retry attempts
- **THEN** `review_plugin` exits non-zero
- **THEN** a `warning`-severity meta-finding with `ruleId: "system/ai-unavailable"` is printed explaining the failure
