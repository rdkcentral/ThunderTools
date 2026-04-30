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

### Requirement: Structural rules are evaluated via focused AI queries on extracted code blocks
Rules that require structural analysis (paired `Register`/`Unregister` calls, `IShell*`
lifetime discipline, interface map completeness) SHALL use `type: ai_query` in their YAML
file. The engine SHALL extract the named structural regions (e.g. `initialize_body`,
`deinitialize_body`) from the file and send them with the YAML `query` field as the
question to the GitHub Models API. The AI response SHALL be evaluated as yes/no; a "yes"
produces a finding; a "no" produces nothing; a "cannot determine" produces a
`suggestion`-severity finding.

#### Scenario: AI query returns a violation citation
- **WHEN** the engine runs a `type: ai_query` rule and the model responds with "yes" and a cited line
- **THEN** a finding is produced with `source: "ai"`, the rule's `severity`, and the cited line in `message`

#### Scenario: AI query returns no violation
- **WHEN** the model responds with "no issue"
- **THEN** no finding is produced for that rule

#### Scenario: AI query cannot determine
- **WHEN** the model responds with "cannot determine" or equivalent uncertainty
- **THEN** a `suggestion`-severity finding is produced with `ruleId` prefixed `suggestion/` and a message prompting manual review

#### Scenario: GH_TOKEN absent — AI pass skipped
- **WHEN** `GH_TOKEN` is not set
- **THEN** all `type: ai_query` rules are skipped
- **THEN** a single `system/ai-skipped` meta-finding is produced with `severity: "suggestion"` explaining that AI checks require `GH_TOKEN`

---

### Requirement: Rule engine implements 9 offline pattern rules covering trivially reliable token checks
The offline pass SHALL implement checks for the following rules using `type: pattern`
YAML files. Each check SHALL be deterministic, require no network or AI model, and
produce a finding with a stable `ruleId`.

| Rule ID | Category | Severity |
|---------|----------|----------|
| `mem/direct-delete-com` | `delete` used directly on a COM interface pointer | error |
| `iface/missing-external` | COM class or struct missing `EXTERNAL` | error |
| `iface/non-hresult-method` | Interface method not returning `Core::hresult` | error |
| `iface/non-virtual-iunknown` | Interface lacks `virtual public Core::IUnknown` | error |
| `iface/stl-across-boundary` | STL container in interface method signature | error |
| `plugin/throw-present` | `throw`, `try`, or `catch` found in plugin source | error |
| `plugin/hardcoded-path` | Hardcoded absolute path (not a `%token%`) | warning |
| `plugin/module-h-not-first` | `Module.h` not the first include in a `.cpp` file | warning |
| `config/raw-json-parse` | Config parsed by hand rather than via `Core::JSON::Container` | warning |

#### Scenario: Each offline rule produces a finding for a known-bad snippet
- **WHEN** the rule engine is run against the test corpus file for rule `<ruleId>`
- **THEN** a finding with that `ruleId` is present in the output
- **THEN** the finding cites the correct line number from the test corpus

#### Scenario: Each offline rule does not fire on a known-good snippet
- **WHEN** the rule engine is run against the clean reference snippet for rule `<ruleId>`
- **THEN** no finding with that `ruleId` is present in the output

---

### Requirement: Rule engine implements 8 AI query rules covering structural checks
The AI query pass SHALL implement checks for the following rules using `type: ai_query`
YAML files. Each check sends focused extracted code blocks with a bounded question to the
GitHub Models API. The `extract` field specifies which structural regions to extract.

| Rule ID | Category | Severity | extract |
|---------|----------|----------|---------|
| `mem/ishell-no-addref` | `IShell*` stored without `AddRef()` | error | `initialize_body` |
| `mem/ishell-no-release` | `IShell*` not released in `Deinitialize()` | error | `deinitialize_body` |
| `mem/qi-no-release` | `QueryInterface` result not released | error | `method_bodies` |
| `plugin/register-leak` | `Register()` without matching `Unregister()` | error | `initialize_body, deinitialize_body` |
| `plugin/missing-unavailable` | `IPlugin::INotification` subclass missing `Unavailable()` | error | `class_declarations` |
| `plugin/init-logic-in-ctor` | Non-trivial logic in constructor or destructor | warning | `ctor_body, dtor_body` |
| `imap/incomplete` | `BEGIN_INTERFACE_MAP` missing an inherited interface entry | warning | `interface_map, class_declarations` |
| `oop/missing-terminate` | OOP `Deinitialize()` missing `connection->Terminate()` | warning | `deinitialize_body` |

#### Scenario: Each AI query rule produces a finding for a known-bad snippet
- **WHEN** the AI query rule is run against a known-bad snippet with the live model
- **THEN** a finding with that `ruleId` and `source: "ai"` is present in the output

#### Scenario: Each AI query rule does not fire on a known-good snippet
- **WHEN** the AI query rule is run against a known-good snippet
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

### Requirement: AI query pass is gated on GH_TOKEN; absence is made explicit
The AI query pass SHALL only run when `GH_TOKEN` is set in the environment. When absent,
all `type: ai_query` rules SHALL be skipped and a single meta-finding SHALL be appended
to inform the developer. Every finding in the output SHALL carry a `source` tag
(`"ai"`, `"offline"`, or `"skipped"`) so callers can distinguish mechanism.

#### Scenario: Offline-only mode when no token
- **WHEN** `GH_TOKEN` is not set in the environment
- **THEN** `review_plugin` returns findings with `source: "offline"` only
- **THEN** a `suggestion`-severity meta-finding with `ruleId: "system/ai-skipped"` is appended
- **THEN** no network call is made

#### Scenario: AI findings returned when token present
- **WHEN** `GH_TOKEN` is set and the GitHub Models API returns a valid response
- **THEN** `review_plugin` returns findings from both passes, each tagged with `source: "offline"` or `source: "ai"`

#### Scenario: AI API failure does not abort offline results
- **WHEN** the GitHub Models API returns a non-200 response or times out
- **THEN** `review_plugin` still returns the offline findings
- **THEN** a `warning`-severity meta-finding with `ruleId: "system/ai-unavailable"` is appended to indicate the AI pass was skipped
