# Delta for Interface Validation and Plugin Generation

## ADDED Requirements

---

### Requirement: COM interface validator command
The system MUST provide a `/thunder-interface-review` slash command that validates
a Thunder COM interface header against 19 rules (15 core + 4 advisory).

#### Scenario: Interface with critical violations
- GIVEN a Thunder interface file with a missing `@json` tag
- WHEN `/thunder-interface-review` runs
- THEN it reports under `🔴 Violations (Must Fix)`:
  `[IMyInterface.h:LINE] Missing @json tag — ZERO RPC code will be generated`
- AND reports under `✅ Validated` all passing rules

#### Scenario: Interface with vector without @restrict
- GIVEN an interface method with a `std::vector` parameter lacking `@restrict`
- WHEN validation runs checkpoint core_17_1
- THEN it reports VIOLATION: `std::vector without @restrict (MANDATORY)`
- AND shows the fix: add `/* @restrict:... */` annotation

#### Scenario: All 19 rules applied in order
- GIVEN any Thunder interface file
- WHEN the validator runs
- THEN it applies all 19 rules loaded from `thunder-interface-rules.yaml` in order:
  core_1_1 through core_17_1 (15 core), then advisory_m1_1 through advisory_m5_1 (4 advisory)
- AND groups output into: 🔴 Violations, 🟡 Warnings, 🟢 Suggestions, ✅ Validated, Compatibility Notes

---

### Requirement: 19 interface rules stored in YAML (v3.2.2)
The YAML file MUST contain all 19 rules, each with:
id, name, severity, description, extraction_logic,
verification_logic, violation_pattern, fix_template, and real code examples.

All rule verification MUST use semantic reasoning — the validator MUST read the
interface header in full and reason about the code as a human reviewer would.
Regex or text search MUST NOT be used as the primary detection mechanism.
Each rule's `extraction_logic` and `verification_logic` fields MUST describe
reading and understanding the code, not searching for patterns.

The validator MUST apply contextual judgment (JUDGE step): if a developer's approach
technically violates a rule but is valid and reasonable in their specific context,
the severity MUST be downgraded (violation→warning or violation→suggestion) and a
`Reasoning` field MUST be populated explaining the rule, the developer's approach,
and why it is acceptable. Severity is NEVER escalated above the YAML-defined level.

The `Status` field in output MUST reflect the **effective** severity after contextual
judgment: `violation`→`VIOLATION`, `warning`→`WARNING`, `suggestion`→`SUGGESTION`.
After a downgrade the downgraded level is used. Emoji prefix must match: 🔴 VIOLATION,
🟡 WARNING, 🟢 SUGGESTION.

#### Scenario: Core rules covered
- 15 core rules at violation level: file/namespace structure, interface declaration shape,
  interface ID registration (nested INotification + ICallback), pure virtual methods,
  return type conventions (Core::hresult mandatory for @json interfaces in Thunder 5.0+),
  const correctness, Thunder type conventions (string not std::string),
  Register/Unregister patterns, nested event interfaces (@event tag required),
  @json tag (CRITICAL — without it zero RPC code is generated), binary compatibility,
  no AddRef/Release redeclaration, no std::map, explicit integer widths (uint32_t not int),
  @restrict mandatory with all std::vector parameters

#### Scenario: Advisory rules covered
- advisory_m1_1: Single responsibility principle (violation)
- advisory_m2_1: Enum underlying types — exclude anonymous ID enum (warning)
- advisory_m3_1: No C++ exceptions (violation)
- advisory_m5_1: @restrict for non-vector parameter constraints — explicitly excludes
  std::vector (that is covered by core_17_1) (warning)

---

### Requirement: Plugin skeleton generator command
The system MUST provide a `/thunder-generate-plugin` slash command that
collects parameters via VS Code `vscode_askQuestions` and runs
PluginSkeletonGenerator.py in interactive mode.

#### Scenario: Simple in-process plugin
- GIVEN the user invokes `/thunder-generate-plugin`
- WHEN the generator collects: PluginName=HelloWorld, OutOfProcess=No,
  CustomConfig=No, all others empty
- THEN it changes to the output directory (default: ThunderNanoServices)
- AND runs `python ThunderTools/PluginSkeletonGenerator/PluginSkeletonGenerator.py`
  interactively, feeding user answers to PSG's prompts
- AND auto-fixes include paths in the generated .h file (PSG bug workaround)
- AND reports the generated files: CMakeLists.txt, Module.h, Module.cpp,
  HelloWorld.h, HelloWorld.cpp

#### Scenario: Out-of-process plugin with interface
- GIVEN PluginName=MediaPlayer, OutOfProcess=Yes, CustomConfig=Yes,
  InterfacePaths=/path/to/IMediaPlayer.h, Preconditions=PLATFORM,NETWORK
- WHEN the generator runs
- THEN PSG is fed "y" for OOP, "y" for config, the interface path, subsystem answers
- AND generates OOP plugin files including MediaPlayerImplementation.h/cpp
- AND generated .conf.in includes preconditions

#### Scenario: vscode_askQuestions dialog
- GIVEN the user invokes `/thunder-generate-plugin`
- WHEN the prompt starts
- THEN it MUST call `vscode_askQuestions` with questions for:
  PluginName, OutputDirectory, OutOfProcess (Yes/No dropdown), CustomConfig (Yes/No dropdown),
  InterfacePaths, Preconditions, Terminations, Controls
- AND MUST NOT ask these questions in chat messages

---

### Requirement: Setup script registers prompts with VS Code
The `setup-prompts.py` script MUST modify VS Code settings.json to add
`chat.promptFilesLocations` pointing to `ThunderTools/PluginQA/Prompts`.

#### Scenario: Python cross-platform setup
- GIVEN any OS with Python 3
- WHEN `python setup-prompts.py` is run
- THEN it performs the same safe settings merge
- AND works identically on Windows, Mac, and Linux
#### Scenario: Script is safe to run multiple times
- GIVEN the script has already been run once
- WHEN it is run again
- THEN it does not duplicate the settings entry
- AND the backup is not overwritten

---

### Requirement: README documents all three commands
The README.md MUST document: quick start (setup scripts, reload VS Code, use the commands),
directory structure, all rules for each of the three commands,
the understand-first review methodology with example, setup script details, FAQ, and example output
for each command (interface validation output, plugin checkpoint output).

---

### Requirement: Rules can be updated without touching prompt files
Because rules are loaded at runtime from YAML, updating existing rule definitions (rewording, logic, or severity) requires only editing the relevant YAML file.
Adding/removing rules may require updating prompt documentation (e.g., the Quick Reference table).

#### Scenario: Updating an existing interface rule
- GIVEN a developer needs to strengthen `core_5_1` (return type convention)
- WHEN they open `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml`
- THEN they edit the relevant fields directly in the rule entry:

```yaml
  - id: core_5_1
    name: Return type conventions (method types)
    severity: violation        # change severity here
    description: |             # update description here
      ...
    verification_logic: |      # update logic here
      ...
    fix_template: |            # update fix here
      ...
```

- AND bump the file-level `version:` field (e.g. `3.2.1` → `3.2.2`)
- AND add a CHANGELOG entry in the `description:` block at the top of the file
- AND save — the next time `/thunder-interface-review` runs it picks up the change automatically

#### Scenario: Adding a new interface rule
- GIVEN a developer needs to add a new rule (e.g. `core_18_1`)
- WHEN they open `thunder-interface-rules.yaml`
- THEN they append a new entry to the `core_rules` list:

```yaml
  - id: core_18_1
    name: "<Short Rule Name in Title Case>"
    severity: violation        # or: warning / suggestion
    description: |
      <what the rule checks and why>
    extraction_logic: |
      1. <how to find the relevant code>
    verification_logic: |
      1. <what constitutes a pass vs fail>
      2. <additional verification steps>
    violation_pattern: "<single-line description of wrong pattern>"
    fix_template: |
      // WRONG:
      <wrong code>

      // Correct:
      <correct code>
    citation: |
      ThunderInterfaces/interfaces/SourceFile.h — real example
```

- AND bump `version:` and add a CHANGELOG entry
- NOTE: No `category` field — it was removed in v3.2.2
- AND also add a row for `core_18_1` to the Quick Reference table inside
  `thunder-interface-review.prompt.md` (the only prompt edit required when adding a rule)

#### Scenario: Adding a new rule
- GIVEN a developer needs to add a new rule (e.g. `rule_80`)
- WHEN they open `thunder-plugin-rules.yaml`
- THEN they append a new entry to the appropriate phase block:

```yaml
  - rule_id: "rule_80"
    name: "Short Name in Title Case"
    severity: "violation"      # or: warning / suggestion
    phase: "code_style"
    conditional: false         # set true if check can be skipped
    skip_condition: null       # or description of skip condition

    extraction:
      target: "<what file or block to read>"
      method: "<how to extract it — describe semantic reading, not regex>"
      code_block: "<description of the extracted snippet>"

    bounded_query:
      question: "<single yes/no question>?"
      expected_answer: "Yes"

    verification_logic:
      - "1. <step 1 — describe reading as a human developer>"
      - "2. <step 2>"
      - "3. If condition → VIOLATION"

    violation_pattern: "<single-line description of violation>"

    fix_template: |
      // WRONG:
      <wrong code>

      // Correct:
      <corrected code>

    citation:
      line_format: "[PluginName.cpp:LINE] <message>"
      rule: "thunder-plugin-rules.yaml / rule_80"
```

- AND increment `total_checkpoints` in the `metadata` block
- AND update the `organization:` string to reflect the new phase count
- AND bump `version:` (e.g. `3.0.0` → `3.1.0`)

#### Scenario: Changing a rule severity
- GIVEN a rule currently at `severity: warning` that should become `severity: violation`
- WHEN the developer updates the YAML field and saves
- THEN the next prompt run reports that finding under `🔴 Violations` instead of `🟡 Warnings`
- AND no prompt file change is needed

#### Scenario: Removing a rule
- GIVEN a rule that is no longer applicable (e.g. a Thunder API was deprecated)
- WHEN the developer deletes the rule entry from the YAML and saves
- THEN the next prompt run no longer checks that rule
- AND `total_checkpoints` (for checkpoint YAML) MUST be decremented accordingly
- AND a CHANGELOG entry MUST document the removal and the reason