# Delta for Plugin Validation

## ADDED Requirements

---

### Requirement: PluginQualityAdvisor folder created inside ThunderTools
A `PluginQualityAdvisor/` directory MUST be created inside the existing `ThunderTools/` folder,
containing all prompts, rules, setup script, and documentation for the QA system.

#### Scenario: Directory structure created
- GIVEN the ThunderTools repository
- WHEN the PluginQualityAdvisor system is delivered
- THEN the following structure MUST exist inside `ThunderTools/`:

```
ThunderTools/PluginQualityAdvisor/
├── README.md
├── PLUGIN_GENERATOR_GUIDE.md
├── setup-prompts.py               (cross-platform Python 3)
├── Prompts/
│   ├── thunder-plugin-review.prompt.md
│   ├── thunder-interface-review.prompt.md
│   └── thunder-generate-plugin.prompt.md
└── rules/
    ├── thunder-plugin-rules.yaml
    └── thunder-interface-rules.yaml
```

#### Scenario: Rules files are the source of truth
- GIVEN the two YAML files under `ThunderTools/PluginQualityAdvisor/rules/`
- WHEN any prompt runs
- THEN it MUST load rules at runtime from those YAML files
- AND rules MUST NOT be embedded directly inside the prompt files
- AND updating a YAML file updates validation behaviour without touching prompt logic

#### Scenario: Prompt files are registered with VS Code
- GIVEN `ThunderTools/PluginQualityAdvisor/Prompts/` containing the three `.prompt.md` files
- WHEN `setup-prompts.py` is run
- THEN it modifies VS Code `settings.json` to add `ThunderTools/PluginQualityAdvisor/Prompts`
- AND the three slash commands (`/thunder-plugin-review`, `/thunder-interface-review`,
  `/thunder-generate-plugin`) become available in VS Code Copilot Chat
- AND the script is safe to run multiple times (idempotent, creates backup of settings)

---

### Requirement: Setup script modifies VS Code settings.json to register prompt location
The `setup-prompts.py` script MUST modify the user-level VS Code `settings.json` to add `"ThunderTools/PluginQualityAdvisor/Prompts": true` under `chat.promptFilesLocations`.

#### Scenario: Resulting settings.json structure
- GIVEN VS Code `settings.json` before the script runs (may be empty `{}` or have existing entries)
- WHEN `setup-prompts.py` completes successfully
- THEN `settings.json` MUST contain the following merged entry:

```json
{
  "chat.promptFilesLocations": {
    "ThunderTools/PluginQualityAdvisor/Prompts": true
  }
}
```

- AND any pre-existing keys in `settings.json` MUST be preserved unchanged

#### Scenario: Settings.json location per platform
- GIVEN the platform the script is running on
- THEN the script MUST locate `settings.json` at:
  - **Windows**: `%APPDATA%\Code\User\settings.json`
    (also check `%APPDATA%\Code - Insiders\User\settings.json`)
  - **macOS**: `~/Library/Application Support/Code/User/settings.json`
    (also check `~/Library/Application Support/Code - Insiders/User/settings.json`)
  - **Linux**: `~/.config/Code/User/settings.json`
    (also check `~/.config/Code - Insiders/User/settings.json`)
- AND if the file does not exist, the script MUST create it with `{}` as the starting content

#### Scenario: Script creates a timestamped backup before modifying
- GIVEN an existing `settings.json`
- WHEN the setup script runs
- THEN it MUST copy `settings.json` to `settings.json.backup.{timestamp}` before any write
- AND the backup MUST be in the same directory as `settings.json`
- AND if the backup already exists from a previous run, it MUST NOT be overwritten

#### Scenario: Script is idempotent
- GIVEN `chat.promptFilesLocations` already contains `"ThunderTools/PluginQualityAdvisor/Prompts": true`
- WHEN the setup script is run again
- THEN it MUST NOT add a duplicate entry
- AND it MUST print a message indicating the entry is already present

#### Scenario: Script prints next steps after success
- GIVEN the script completes without error
- THEN it MUST print:
  1. Confirmation that `settings.json` was updated
  2. The path to the backup file
  3. Instructions to reload the VS Code window:
     `Press Ctrl+Shift+P → "Developer: Reload Window"` (or equivalent for platform)
  4. The three slash commands now available: `/thunder-plugin-review`,
     `/thunder-interface-review`, `/thunder-generate-plugin`

---

### Requirement: thunder-plugin-rules.yaml (v3.3.0) created under PluginQualityAdvisor/rules/
The file `ThunderTools/PluginQualityAdvisor/rules/thunder-plugin-rules.yaml` MUST exist
with version `3.3.0` and contain all 84 rules numbered sequentially (rule_01 to rule_84).

#### Scenario: Metadata block
- GIVEN the YAML file
- THEN it MUST contain a `metadata` block with:
  `version: "3.3.0"`, `total_rules: 84`, `total_general_rules: 46`,
  `approach: "semantic code review — understand whole plugin first, then check specifics"`,
  and a `validation_approach` block listing the 5-step workflow
  (understand whole plugin → focus on specific concern → reason in context → cite if genuinely wrong → fix)

#### Scenario: All 38 phase checkpoints present with required fields
- GIVEN each phase checkpoint entry in the YAML (under phase sections)
- THEN it MUST contain: `rule_id`, `name` (Title Case), `severity`, `phase`,
  `extraction` block (target / method / code_block),
  `bounded_query` as an object with `question` and `expected_answer` fields (NOT a plain string),
  `verification_logic` as a YAML list of numbered step strings (NOT a multiline block scalar)
  that describe SEMANTIC reasoning ("read the code and understand..."), NEVER regex/pattern,
  `violation_pattern` (single-line string), `fix_template`, and
  `citation` object with `line_format` and `rule` fields
- AND conditional rules MUST include a `conditional: true` flag and
  a `skip_condition` describing when to skip

#### Scenario: All 46 holistic rules (8 sub-phases) present with required fields
- GIVEN each General rule entry in the YAML (under `general_rules` section)
- THEN it MUST contain: `rule_id` (e.g. "rule_39"), `name` (Title Case),
  `severity`, `category: "<sub-phase>" (conventions|lifecycle_integrity|concurrency|com_safety|resource_management|jsonrpc_compliance|inter_plugin_design|code_quality_security)`,
  `review_question` (semantic question about what to verify),
  `review_method` (must state "Read the full relevant code context...
  Do not use pattern-only checks."),
  `evidence_requirement` (must state "Provide exact [File:line] citation")
- AND Holistic Rules (8 sub-phases) MUST NOT have `extraction`, `bounded_query`, or `verification_logic` fields

#### Scenario: Report output is unified — no "automated" vs "manual" split
- GIVEN any review run completing all 84 rules
- THEN the report MUST present ONE unified list of findings grouped by file
- AND there MUST NOT be separate "Part 1" / "Part 2" or "Automated" / "Manual" sections
- AND the summary table MUST include all 84 rules in a single table with rows for each
  phase plus "Holistic Rules (8 sub-phases)" and a "Total (84 rules)" footer row

#### Scenario: Phase breakdown matches spec
- GIVEN the 38 checkpoints distributed across phases
- THEN the counts MUST be:
  Phase 1 (module_structure): 3 — `rule_01`, `rule_02`, `rule_03`
  Phase 2 (code_style): 10 — `rule_04`, `rule_05`, `rule_06`,
                              `rule_07`,
                              `rule_08`, `rule_09`, `rule_10`, `rule_11`, `rule_12`,
                              `rule_13`
  Phase 3 (class_registration): 3 — `rule_14`,
                                     `rule_15`, `rule_16`
  Phase 4 (lifecycle): 12 — `rule_17`, `rule_18`, `rule_19`,
                             `rule_20`, `rule_21`, `rule_22`, `rule_23`,
                             `rule_24`, `rule_25`, `rule_26`, `rule_27`,
                             `rule_28`
  Phase 5 (implementation): 4 — `rule_29`, `rule_30`,
  Phase 5C (oop): 2 — `rule_32`, `rule_33`
  Phase 6 (configuration): 3 — `rule_34`, `rule_35`, `rule_36`
  Phase 7 (cmake): 1 — `rule_37`
  Phase 8 (interfaces): 1 — `rule_38`

---

### Requirement: thunder-interface-rules.yaml (v3.2.2) created under PluginQualityAdvisor/rules/
The file `ThunderTools/PluginQualityAdvisor/rules/thunder-interface-rules.yaml` MUST exist
with version `3.2.2` and contain all 19 interface rule definitions (16 core + 3 advisory).

#### Scenario: File header present
- GIVEN the YAML file
- THEN it MUST contain a YAML front-matter header (not a metadata block) with:
  `version: 3.2.2`, `title`, `description` including the full CHANGELOG
  covering v3.2.2, v3.2.1, v3.2.0, v3.1.0, and v3.0.2

#### Scenario: All 16 core rules present with required fields
- GIVEN the `core_rules` list
- THEN it MUST contain exactly these IDs in order:
  `core_1_1`, `core_2_1`, `core_3_1`, `core_4_1`, `core_5_1`, `core_6_1`,
  `core_9_1`, `core_10_1`, `core_11_1`, `core_12_1`, `core_13_1`,
  `core_14_1`, `core_15_1`, `core_16_1`
- AND each rule MUST contain: `id`, `name`, `severity`,
  `description`, `extraction_logic`, `verification_logic`, `violation_pattern`,
  `fix_template`, `citation` (with real Thunder interface file references)

#### Scenario: All 3 advisory rules present with required fields
- GIVEN the `advisory_rules` list
- THEN it MUST contain exactly these IDs:
  `advisory_m1_1` (SRP — warning), `advisory_m2_1` (enum underlying types — warning),
  `advisory_m3_1` (no exceptions — violation)
- AND each advisory rule MUST contain the same fields as core rules

---


### Requirement: Plugin validation command with unified output
The system MUST provide a `/thunder-plugin-review <PluginName>` slash command
in VS Code Copilot Chat that validates a Thunder plugin against all 84 rules
using semantic code review, producing a single unified report.

#### Scenario: Plugin found and reviewed
- GIVEN the user types `/thunder-plugin-review Dictionary`
- WHEN the prompt runs
- THEN it locates `ThunderNanoServices/Dictionary/` automatically
- AND identifies Dictionary.h, Dictionary.cpp, Module.h, Module.cpp, CMakeLists.txt,
  Dictionary.conf.in, and any OOP implementation files
- AND executes all 84 rules in order (phase checkpoints first, then General)
- AND outputs a single unified report showing ONLY failures with exact line citations

#### Scenario: No plugin name provided
- GIVEN the user types `/thunder-plugin-review` with no argument
- WHEN the prompt runs
- THEN it asks "Which plugin would you like to review?"
- AND proceeds normally once the user supplies a name

#### Scenario: Plugin not in ThunderNanoServices
- GIVEN the user types `/thunder-plugin-review MyPlugin`
- AND `ThunderNanoServices/MyPlugin/` does not exist
- WHEN the prompt runs
- THEN it searches the workspace for a folder named `MyPlugin`
- AND if still not found, asks the user for the location

---

### Requirement: Report shows failures only, phase summaries for passes
The report MUST show violations, warnings, and suggestions in full detail.
PASS and SKIP checkpoints MUST appear only as counts in phase summary lines.

#### Scenario: Phase with all passes
- GIVEN Phase 1 (Module Structure) has 3 passing checkpoints
- WHEN the report is generated
- THEN Phase 1 shows: `Status: 3 PASS, 0 FAIL, 0 SKIP ✅ (No issues)`
- AND no individual checkpoint details are shown for Phase 1

#### Scenario: Phase with failures
- GIVEN Phase 4 (Lifecycle) has checkpoint 4.1 failing
- WHEN the report is generated
- THEN the phase summary shows the PASS/FAIL/SKIP counts
- AND the failing checkpoint shows: citation with exact file and line number,
  extracted code block with line numbers, fix template

---

### Requirement: Output status field reflects effective severity after contextual judgment
The `status` field in every output YAML block MUST reflect the **effective** severity
after contextual judgment — not always the raw YAML severity.

#### Scenario: Status field maps from YAML severity by default
- GIVEN a checkpoint with `severity: violation` fires and the developer's approach is genuinely wrong
- THEN the output block MUST show `status: VIOLATION`
- GIVEN a checkpoint with `severity: warning` fires
- THEN the output block MUST show `status: WARNING` (or lower if context permits)
- GIVEN a checkpoint with `severity: suggestion` fires
- THEN the output block MUST show `status: SUGGESTION`

#### Scenario: Severity downgraded when developer's approach is valid in context
- GIVEN a checkpoint with `severity: violation` fires
- AND the validator reasons that the developer's actual approach is valid, safe, and achieves
  the same safety goal as the rule intends
- THEN the output block MUST show `status: SUGGESTION` (downgraded from VIOLATION)
- AND the output block MUST include a `reasoning` field that:
  1. States why the rule normally exists
  2. Describes what the developer did instead
  3. Explains why their approach is valid in this context
  4. Notes any residual risk, if any
- GIVEN the approach is acceptable but has a residual risk
- THEN the output block MUST show `status: WARNING` (downgraded from VIOLATION)

#### Scenario: Severity MUST NOT be escalated
- GIVEN a checkpoint with `severity: warning`
- THEN the output MUST NOT show `status: VIOLATION`
- GIVEN a checkpoint with `severity: suggestion`
- THEN the output MUST NOT show `status: WARNING` or `status: VIOLATION`

#### Scenario: Section heading emoji matches effective severity
- GIVEN a failing checkpoint of any severity
- THEN the heading for that issue block MUST use the corresponding emoji:
  `❌` for VIOLATION, `⚠️` for WARNING, `💡` for SUGGESTION

---

### Requirement: 84 unified rules organised across phase groups and General concerns
The prompt MUST load rule definitions from
`ThunderTools/PluginQualityAdvisor/rules/thunder-plugin-rules.yaml` at runtime.
Each rule definition includes sufficient information for semantic validation.
All 84 rules produce the same output format.

Phase breakdown: Phase 1: 3, Phase 2: 10, Phase 3: 3, Phase 4: 12, Phase 5: 4,
Phase 5C: 2, Phase 6: 3, Phase 7: 1, Phase 8: 1 = 38 phase rules + 46 holistic rules = 84 total.

---

### Requirement: All checkpoint verification MUST use semantic reasoning — no regex or text search
Every checkpoint verification step MUST be performed by reading the relevant source
code in full as a human code reviewer would and reasoning about its meaning —
NOT by running regular expressions or keyword searches against raw text.

#### Scenario: Correct semantic verification approach
- GIVEN any checkpoint that needs to detect a pattern in plugin source code
- WHEN the validator processes that checkpoint
- THEN it MUST read the complete relevant function bodies, class declarations, or file contents
- AND reason about the semantic meaning of the code (types, lifetimes, control flow, ownership)
- AND apply domain knowledge about Thunder/COM conventions to determine compliance
- AND MUST NOT use regex patterns, text searches, or string matching as the primary detection method

#### Scenario: New checkpoints added in future
- GIVEN a new checkpoint is being authored (added to the YAML or prompt)
- THEN the `extraction.method` field in the YAML MUST describe reading code as a human developer
  (e.g. "Read the full function body as a human developer — understand the context")
- AND the `verification_logic` steps MUST describe semantic reasoning steps
  (e.g. "Reason about whether the pointer is a COM interface type from its name and usage context")
- AND ANY use of "search for", "find pattern", or "match regex" language in a checkpoint's
  `extraction.method` or `verification_logic` is a spec violation and MUST be corrected to
  semantic reasoning language

#### Scenario: Verifier encounters an ambiguous case
- GIVEN a code pattern that is not immediately clear from a surface read
- WHEN the verifier applies semantic reasoning
- THEN it MUST consider: the variable's declared type, the class hierarchy, the call context,
  and the surrounding logic — not just the presence or absence of a keyword
- AND apply reasonable judgment: if the semantic intent is clear and compliant, report PASS;
  if the semantic intent is clearly non-compliant, report VIOLATION/WARNING with a citation

---

#### Scenario: Phase 1 - Module Structure (3 checkpoints)
- GIVEN Module.cpp of a Thunder plugin
- WHEN checkpoint rule_01 runs (suggestion)
- THEN it checks MODULE_NAME in Module.h starts with `Plugin_` prefix
- WHEN checkpoint rule_02 runs (violation)
- THEN it checks Module.cpp contains `MODULE_NAME_DECLARATION(BUILD_REFERENCE)`
- WHEN checkpoint rule_03 runs (warning)
- THEN it checks Module.h uses `#pragma once` instead of a legacy `#ifndef/#define/#endif` guard

#### Scenario: Phase 2 - Code Style (10 checkpoints)
- GIVEN plugin .cpp and .h files
- WHEN checkpoint rule_04 runs (violation)
- THEN it flags any parameter annotated `VARIABLE_IS_NOT_USED` that is actually used in the function body;
  the validator MUST read each function in its entirety (signature + body) and reason semantically
  about whether the parameter is used — NOT by regex or text search, but by understanding the code
  as a human reviewer would; covers all annotation forms (inline in signature, macro call in body, etc.)
- WHEN checkpoint rule_05 runs (violation)
- THEN it flags any function that conditionally sets an error code but then
  unconditionally overwrites it with ERROR_NONE/SUCCESS
- WHEN checkpoint rule_06 runs (warning)
- THEN it flags any use of `NULL` as a null pointer literal (must be `nullptr`);
  the validator MUST read each function body and variable declaration as a human reviewer,
  reasoning about the semantic meaning of each null expression — NOT by regex search;
  NULL inside string literals and comments MUST be excluded by context understanding
- WHEN checkpoint rule_07 runs (violation)
- THEN it flags any `delete` or `delete[]` used on a COM interface pointer type;
  the validator MUST read each function body and reason about the type of the deleted pointer
  from context (declarations, naming, class hierarchy) — NOT by pattern matching
- WHEN checkpoint rule_08 runs (violation)
- THEN it flags every `->Release()` on a member variable not immediately followed by `= nullptr`;
  the validator MUST read each function in full and reason about what follows each Release call,
  and whether the pointer is a member variable with lifetime beyond the current scope
- WHEN checkpoint rule_09 runs (violation, conditional)
- THEN it flags any `QueryInterfaceByCallsign()` result stored as a member variable;
  the validator MUST read function bodies and class declarations and reason about the result's
  lifetime — transient local use (acquired, used, released in same scope) is acceptable
- SKIP if no `QueryInterfaceByCallsign` calls found
- WHEN checkpoint rule_10 runs (violation)
- THEN it flags any COM interface pointer (`I*` type) wrapped in `shared_ptr` or `unique_ptr`;
  the validator MUST read class member declarations and reason about types from context
- WHEN checkpoint rule_11 runs (violation)
- THEN it flags any use of `SmartLinkType`; the validator MUST read class declarations
  and reason about member types — use a direct COMRPC interface instead
- WHEN checkpoint rule_12 runs (violation)
- THEN it flags any `delete this` in plugin code; the validator MUST read function bodies
  and reason about ownership — plugin lifetime is owned by the framework
- WHEN checkpoint rule_13 runs (violation)
- THEN it flags any `throw` statement in executable plugin code; the validator MUST read
  function bodies as a human reviewer and reason about error-handling patterns —
  exclude `throw` inside string literals and comments by context understanding

#### Scenario: Phase 3 - Class Registration (3 checkpoints)
- GIVEN the main plugin class (the one implementing PluginHost::IPlugin)
- WHEN checkpoint rule_14 runs (warning)
- THEN it checks all 4 special members are deleted in the MAIN class only
  (copy ctor, copy assign, move ctor, move assign) — internal helper classes excluded
- WHEN checkpoint rule_15 runs (violation)
- THEN it checks `Plugin::Metadata<PluginName>` exists in main Plugin.cpp
  AND `SERVICE_REGISTRATION(...)` in ImplementationClass.cpp if OOP
- WHEN checkpoint rule_16 runs (violation, conditional)
- IF the plugin registers JSON-RPC handlers (`Register(` calls in Initialize())
- THEN it checks the class inherits `PluginHost::JSONRPC`
- SKIP if no JSON-RPC handler registrations found

#### Scenario: Phase 4 - Lifecycle (12 checkpoints, some conditional)
- GIVEN Initialize() and Deinitialize() method bodies
- WHEN checkpoint rule_17 runs (violation, conditional)
- IF `IShell* _service` member exists: checks AddRef() called after assignment in Initialize
- IF no stored IShell pointer: SKIP
- WHEN checkpoint rule_18 runs (violation, conditional)
- IF `IShell* _service` stored: checks `_service->Release()` and `_service = nullptr`
  in Deinitialize
- WHEN checkpoint rule_19 runs (violation)
- THEN it checks the plugin `.cpp` implements `string Information() const`
- WHEN checkpoint rule_20 runs (violation, conditional)
- IF `service->Root<T>()` called in Initialize: checks return value is tested for nullptr
- SKIP if no Root<T>() calls
- WHEN checkpoint rule_21 runs (violation, conditional)
- IF `service->Root<T>()` result stored as member: checks it is Released and set to nullptr in Deinitialize
- SKIP if no Root<T>() calls
- WHEN checkpoint rule_22 runs (violation, conditional)
- IF observer container (`_observers`, `_sinks`) exists: checks Release loop + `.clear()` in Deinitialize
- IF no container: SKIP
- WHEN checkpoint rule_23 runs (violation, conditional)
- IF `service->SubSystems()` stored as member: checks it is Released in Deinitialize
- SKIP if SubSystems() not stored as member
- WHEN checkpoint rule_24 runs (violation)
- THEN it checks the plugin constructor body is empty (no logic, no calls) —
  all initialisation must be in `Initialize()`
- WHEN checkpoint rule_25 runs (violation, conditional)
- IF `service->Register(observer)` called in Initialize: checks matching `service->Unregister(observer)` in Deinitialize
- SKIP if no service->Register() calls
- WHEN checkpoint rule_26 runs (violation)
- THEN it checks every failure return in Initialize() returns a non-empty diagnostic string
  (the success return MUST be `return string();` or `return EMPTY_STRING;`)
- WHEN checkpoint rule_27 runs (violation)
- THEN it checks Initialize() does NOT manually call `Deinitialize()` on failure paths —
  Thunder calls Deinitialize() automatically when Initialize() returns a non-empty string
- WHEN checkpoint rule_28 runs (violation)
- THEN it checks the main plugin class destructor body is completely empty
  (only `ASSERT` invariant checks are acceptable — no Release calls or cleanup logic)
#### Scenario: Phase 5 - Implementation (4 checkpoints, mostly conditional)
- GIVEN plugin implementation files
- WHEN checkpoint rule_29 runs (violation, conditional)
- IF `Exchange::J*::Register` in Initialize: checks matching `::Unregister` in Deinitialize
- WHEN checkpoint rule_30 runs (violation, conditional)
- SKIP if the plugin is a **publisher** — i.e. it only exposes `Register(INotification* sink)` /
  `Unregister()` methods and stores incoming external `INotification*` pointers in an ObserverMap.
  That pattern means callers register with the plugin, NOT that the plugin subscribes to anything.
- ONLY CHECK if the plugin is a **subscriber** — i.e. it defines its OWN inner class
  (e.g. `class NetworkNotification : public Exchange::INetwork::INotification`) to listen
  to an external service. That inner class member MUST be `Core::SinkType<ClassName>`,
  NOT a raw pointer (`ClassName* _member`)
- IF any `Core::SinkType<>` subscriber class found: checks each class implements `void Unavailable()`;
  the validator MUST read the full class declaration and reason about whether the method exists —
  NOT by searching for the string "Unavailable"
- SKIP if no Core::SinkType<> subscriber classes in plugin
- WHEN checkpoint rule_31 runs (violation)
- THEN it checks for hardcoded absolute paths; the validator MUST read function bodies and
  reason about how paths are constructed from context — NOT by searching for path substrings
#### Scenario: Phase 8 - COM Interface Rules (1 checkpoint)
- GIVEN interface struct definitions in the plugin
- WHEN checkpoint rule_38 runs (violation)
- THEN it checks that action/non-getter virtual methods on COM interfaces return `Core::hresult`
- NOTE: The "no delete on COM interface pointers" rule is enforced in Phase 2
  as checkpoint `rule_07` (applies to all .cpp files, not only interface structs)

#### Scenario: Phase 5C - Out-of-Process (2 checkpoints, conditional)
- GIVEN Deinitialize() and IRemoteConnection::INotification callbacks of an OOP plugin
- IF plugin is in-process: SKIP the entire phase
- WHEN checkpoint rule_32 runs
- THEN it checks `service->RemoteConnection()` and `connection->Terminate()` and
  `connection->Release()` all present in Deinitialize()
- WHEN checkpoint rule_33 runs (violation, conditional)
- THEN it checks that the very first action in every `Activated()` and `Deactivated()` callback is
  a guard checking `connection->Id() == _connectionId`
- SKIP if plugin has no IRemoteConnection::INotification implementation

- WHEN checkpoint rule_34 runs (violation, conditional)
  the validator MUST read the file in full and reason about the startup configuration —
  note that `autostart` is not the same as `startmode`
- WHEN checkpoint rule_35 runs (violation, conditional)
- IF `service->ConfigLine()` is called in Initialize(): checks that a typed
  `Config : public Core::JSON::Container` struct exists and its `FromString()` is called
- SKIP if plugin does not call `service->ConfigLine()`
- WHEN checkpoint rule_36 runs (violation)
- THEN it checks for hardcoded numeric tuning parameters (timeouts, retry counts, buffer sizes)
  as inline literals; the validator MUST read Initialize() in full and reason about the semantic
  meaning of each numeric value in context — NOT by searching for number patterns;
  apply judgment: protocol constants (e.g. port 80) are acceptable, deployment tuning values are not

#### Scenario: Phase 7 - CMake (1 checkpoint)
- GIVEN CMakeLists.txt
- WHEN checkpoint rule_37 runs
- THEN it checks `CXX_STANDARD` is set to `${CXX_STD}` (Thunder variable), not a literal like `11` or `14`;
  the validator MUST read CMakeLists.txt in full and reason about each target's property settings

---

### Requirement: 46 holistic rules (8 sub-phases) loaded from YAML and reported in unified output
After the 38 phase checkpoints, the validator MUST also run the 46 holistic rules (8 sub-phases)
loaded from the `general_rules` section of `thunder-plugin-rules.yaml`.
All rules produce the same output format — there is no separate section for these rules.

#### Scenario: Holistic Rules (8 sub-phases) integrated into unified output
- GIVEN the phase checkpoint evaluation is complete
- WHEN the validator runs the 46 holistic rules (8 sub-phases)
- THEN any failures appear in the same file-grouped findings list as phase checkpoint failures
- AND the summary table includes a "Holistic Rules (8 sub-phases)" row with PASS/FAIL/SKIP counts
- AND there is NO separate "Part 2" or "Manual Review" heading in the output
  `rule_id`, `rule` (name), `status` (PASS/FAIL/SUGGEST), `severity`,
  `extracted_code` (with [File:line] prefix where applicable), `violation_line`,
  `citation`, `fix`, `reasoning`
- AND PASS rules are NOT listed individually — they appear only as counts in the summary table
- Holistic Rules (rule_39–rule_84) cover:
  1. `#pragma once` in every .h file (suggestion)
  2. Apache 2.0 copyright headers in all source files (suggestion)
  3. No STL types where Thunder equivalents exist (warning)
  4. ASSERT used correctly — on prerequisites, not return values (warning)
  5. OOP registration order correct (violation, conditional)
  6. Complete state reset in Deinitialize (violation)
  7. Reverse-order cleanup in Deinitialize (warning)
  8. Observer AddRef before Register, Release after Unregister (violation)
  9. AddRef/Release balance across plugin lifetime (violation)
  10. Config struct used for all configuration (warning)
  11. CMake NAMESPACE variable set to Thunder (violation)
  12. write_config() called LAST in CMakeLists.txt (suggestion)
  13. Handlers must not block — dispatch to WorkerPool (violation)
  14. No Activate/Deactivate calls from notification handlers (violation)
  15. Shared member state protected by Core::CriticalSection (violation)
  16. No framework callbacks (Notify, Submit, Register) called while holding _adminLock (violation)
  17. WorkerPool jobs guard against post-Deinitialize execution (violation)
  18. File descriptors and sockets wrapped in RAII (violation)
  20. Config validation failures return non-empty string from Initialize (violation)
  21. Notify() only called after Initialize() has completed (violation)
  22. interface->Register paired with interface->Unregister in Deinitialize (violation)
  23. Handler registration order in Initialize/Deinitialize: acquire first, unregister before release (violation)
  24. Use Core::ERROR_* named constants for failure codes, not raw integers (violation)
  25. Input validation before use in JSON-RPC handlers (violation)
  26. Event name strings as named constants; JSON payloads use typed JsonData::* classes (warning)
  27. COM reference counting correctness: one AddRef per pointer, one Release per lifetime end (violation)
  28. No hard inter-plugin dependencies; use PluginSmartInterfaceType for held cross-plugin pointers (warning)
  29. JSON-RPC handlers are re-entrant safe: shared state under lock (violation)
  30. IPlugin::INotification callbacks must not block: delegate to WorkerPool (violation)
  31. Lock scope minimized: no I/O or long operations while lock is held (violation)
  32. Plugin threads joined/stopped in Deinitialize before releasing interfaces (violation)
  33. Memory and allocation safety: no large stack buffers, no VLAs, no deep recursion, RAII preferred (warning)
  34. Framework pointers (IShell*, acquired interfaces) not accessed from background threads after Deinitialize (violation)
  35. Core::hresult return values from interface calls checked, not silently ignored (violation)
  36. ASSERT used only for programmer invariants, not runtime conditions (warning)
  37. Security: no sensitive data in logs, no shell commands from external input, paths sanitized (violation)
  38. JSON-RPC input validated for type, bounds, enum range, and string length (violation)
  39. Config completeness: defaults for optional fields, typed members, Get<T>() results released, config read-only after Initialize (warning)
  40. OOP error propagation: hresult from interface calls propagated; method names match API contract (warning)
  41. Observer/notification inner classes declared as private nested members (suggestion)
  42. No deprecated JSON-RPC APIs: no IDispatcher, no Announce-style events (violation)
  43. All acquired interface pointers set to nullptr on all Deinitialize() exit paths (violation)

---

### Requirement: Violation output format grouped by file with exact line numbers
Every failing checkpoint MUST be output as a YAML block grouped under the source file
it belongs to. The report structure is:

~~~~text
### {FileName} — N issue(s)

~~~yaml
rule_id: <id>
status: <VIOLATION|WARNING|SUGGESTION|PASS|SKIP>
severity: violation|warning|suggestion
question: "..."
answer: "..."
extracted_code: |
  // [FileName:line-line]
  <code>
violation_line: <number>
citation: "[FileName:line] <description>"
fix: |
  <fixed code>
reasoning: "..."
~~~
~~~~

#### Scenario: File-wise grouping
- GIVEN a plugin review that finds issues in Dictionary.cpp, Dictionary.h, and CMakeLists.txt
- WHEN the report is generated
- THEN failures appear under three separate file headers in document order:
  `### Dictionary.cpp — 8 issue(s)`, `### Dictionary.h — 1 issue(s)`, `### CMakeLists.txt — 1 issue(s)`
- AND each YAML block includes a `severity` field (violation / warning / suggestion)
- AND files with no failures are NOT listed

#### Scenario: Lifecycle violation output
- GIVEN checkpoint 4.1 (Initialize ASSERT) fails
- WHEN the report is generated
- THEN it appears under `### {PluginName}.cpp — N issue(s)`
- AND the citation reads `[Dictionary.cpp:115] Initialize missing ASSERT(service != nullptr)`
  (using the actual plugin name, not a placeholder)
- AND extracted_code shows the Initialize method body with `// [Dictionary.cpp:113-117]` prefix

---

### Requirement: Checkpoint summary as table and Next Steps as numbered list
The report MUST include a `### Checkpoint Summary` table after all file sections.

#### Scenario: Summary table format
- GIVEN a completed review
- THEN the summary MUST be a markdown table:

  | Phase | PASS | FAIL | SKIP |
  |-------|------|------|------|
  | Phase 1: Module Structure | 3 | 0 | 0 |
  | ... | ... | ... | ... |
  | **Total** | **N** | **N** | **N** |

- AND a `### Next Steps` numbered list follows the table
- AND each item references the exact `[File:line]` location and checkpoint ID