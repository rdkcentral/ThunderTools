# Tasks: Thunder Plugin QA System

## Phase 1: YAML rule definitions

- [x] 1.1 Create `ThunderTools/PluginQA/rules/thunder-plugin-rules.yaml` (v3.3.0)
      - metadata block: version, description, approach,
        total_rules: 79, total_general_rules: 40,
        organization: "Phase1:3, Phase2:10, Phase3:3, Phase4:12, Phase5:4, Phase5C:2, Phase6:3, Phase7:1, Phase8:1"
      - validation_approach block: principles list + 5-step workflow (including
        Step 3b JUDGE: contextual judgment — if developer's approach technically
        violates a rule but is valid and reasonable in context, downgrade severity
        (violation→suggestion or →warning) and populate reasoning field)
      - CRITICAL: ALL rules (both automated and manual) use SEMANTIC code review.
        Never pattern-match. Always read the full relevant code context (control flow,
        ownership, lifecycle, threading) before deciding PASS/FAIL.

      YAML STRUCTURE — PHASE RULES (39 rules, rule_01 to rule_39):
        - rule_id, name (Title Case), severity, phase
        - extraction: { target, method, code_block }
        - bounded_query: { question: "...", expected_answer: "Yes" }  ← MUST be object, NOT plain string
        - verification_logic: YAML list of strings (- "1. ...", - "2. ..."), NOT multiline block
          MUST describe semantic reasoning ("read the code and understand..."), NEVER regex/pattern
        - violation_pattern: single-line string
        - fix_template: multiline block showing WRONG + Correct pattern
        - conditional: true/false
        - skip_condition: string or null
        - citation: { line_format: "[PluginName.cpp:LINE] ...", rule: "thunder-plugin-rules.yaml / {id}" }

      YAML STRUCTURE — MANUAL RULES (semantic review, 40 rules):
        - rule_id (e.g. "rule_40"), name (Title Case), severity, category: "<sub-phase>" (conventions|lifecycle_integrity|concurrency|com_safety|resource_management|jsonrpc_compliance|inter_plugin_design|code_quality_security)
        - review_question: semantic question describing what to verify
        - review_method: "Read the full relevant code context (control flow, ownership,
          lifecycle, and threading where applicable) before deciding PASS/FAIL/SUGGEST.
          Do not use pattern-only checks."
        - evidence_requirement: "Provide exact [File:line] citation for any failure."
        NOTE: Manual rules require holistic code understanding — they cannot be reduced
        to a single block check. They require understanding the full plugin architecture — concurrency,
        security, and General concerns that span multiple code paths.

      - phase_1_checkpoints (3):
        rule_01 (suggestion): "MODULE_NAME Plugin_ Prefix" — checks #define MODULE_NAME in Module.h starts with Plugin_
        rule_02 (violation): "MODULE_NAME_DECLARATION" — MODULE_NAME_DECLARATION(BUILD_REFERENCE) present in Module.cpp
        rule_03 (warning): "Module.h Uses #pragma once" — not legacy #ifndef guard
      - phase_2_checkpoints (10):
        rule_04 (violation): "VARIABLE_IS_NOT_USED Accuracy" — wraps only genuinely unused params
        rule_05 (violation): "Error Code Preservation" — conditional error not unconditionally overwritten
        rule_06 (warning): "NULL vs nullptr" — nullptr used not NULL
        rule_07 (violation): "No delete on COM Interface Pointers" — use Release()
        rule_08 (violation): "nullptr After Release" — nullptr assigned immediately after Release()
        rule_09 (violation conditional): "No QueryInterfaceByCallsign as Member" — transient use only
        rule_10 (violation): "No Smart Pointers on COM Objects" — no shared_ptr/unique_ptr on COM
        rule_11 (violation): "No SmartLinkType for COMRPC Plugins" — deprecated mechanism
        rule_12 (violation): "No delete on Plugin Object" — no delete this
        rule_13 (violation): "No throw Keyword in Plugin Code" — no exceptions across COM
      - phase_3_checkpoints (3):
        rule_14 (warning): "Special Members Deleted (Main Class)" — all 4 deleted, main class only
        rule_15 (violation): "Plugin Metadata Registration" — Plugin::Metadata<PluginName> in .cpp
        rule_16 (violation conditional): "JSONRPC Inheritance When Used" — when JSON-RPC handlers registered
      - phase_4_checkpoints (12):
        rule_17 (violation conditional): "IShell AddRef in Initialize"
        rule_18 (violation conditional): "IShell Release in Deinitialize"
        rule_19 (violation): "Information() Method" — string Information() const implemented
        rule_20 (violation conditional): "Root<T>() Null Check"
        rule_21 (violation conditional): "Root<T>() Release in Deinitialize"
        rule_22 (violation conditional): "Observer Cleanup in Deinitialize"
        rule_23 (violation conditional): "SubSystems() Release in Deinitialize"
        rule_24 (violation): "Constructor Must Be Empty"
        rule_25 (violation conditional): "service->Register/Unregister Pairing"
        rule_26 (violation): "Initialize Returns Error String on Failure"
        rule_27 (violation): "No Manual Deinitialize() in Initialize"
        rule_28 (violation): "Destructor Must Be Empty"
      - phase_5_checkpoints (4):
        rule_29 (violation conditional): "JSON-RPC Register/Unregister Pairing"
        rule_30 (violation conditional): "SinkType Pattern for Subscribers"
        rule_31 (violation conditional): "Unavailable() in SinkType Classes"
        rule_32 (violation): "No Hardcoded Paths"
      - phase_5C_checkpoints (2):
        rule_33 (violation conditional): OOP connection termination in Deinitialize
        rule_34 (violation conditional): connectionId checked first in IRemoteConnection callbacks
      - phase_6_checkpoints (3):
        rule_35 (violation conditional): startmode declaration
        rule_36 (violation conditional): Config Core::JSON::Container
        rule_37 (violation): no hardcoded numeric tuning params
      - phase_7_checkpoints (1): rule_38 (violation conditional): CXX_STANDARD uses ${CXX_STD}
      - phase_8_checkpoints (1): rule_39 (violation): "COM Methods Return Core::hresult"

      Holistic Rules (8 sub-phases) (40, all in general_rules section):
        rule_40 (suggestion): "#pragma once"
        rule_41 (suggestion): "Apache 2.0 Copyright Header"
        rule_42 (warning): "STL Types"
        rule_43 (warning): "ASSERT vs Error Handling"
        rule_44 (violation): "OOP Registration Order"
        rule_45 (violation): "Complete State Reset in Deinitialize"
        rule_46 (suggestion): "Reverse-Order Cleanup"
        rule_47 (violation): "Observer Locking"
        rule_48 (violation): "AddRef/Release Balance"
        rule_49 (suggestion): "CMake NAMESPACE Variable"
        rule_50 (violation): "Handlers Must Not Block"
        rule_51 (violation): "No Activate/Deactivate from Handlers"
        rule_52 (violation): "Shared State Protected by CriticalSection"
        rule_53 (violation): "No Lock Held During Framework Callbacks"
        rule_54 (violation): "Worker Jobs Check Deinitialize Guard"
        rule_55 (violation): "File Descriptors / Sockets Wrapped in RAII"
        rule_56 (violation): "No Unbounded Memory Growth"
        rule_57 (violation): "Config Errors Return Non-Empty from Initialize"
        rule_58 (violation): "interface->Register/Unregister Pairing"
        rule_59 (violation): "Handler Registration Order in Initialize/Deinitialize"
        rule_60 (violation): "Use Core::ERROR_* for Handler Failure Codes"
        rule_61 (violation): "Input Validation in JSON-RPC Handlers"
        rule_62 (warning): "Event Constants and Typed JSON Payloads"
        rule_63 (violation): "COM Reference Counting Correctness"
        rule_64 (warning): "No Hard Inter-Plugin Dependencies"
        rule_65 (violation): "JSON-RPC Handlers Are Re-entrant Safe"
        rule_66 (violation): "IPlugin::INotification Callbacks Must Not Block"
        rule_67 (violation): "Lock Scope Minimized"
        rule_68 (violation): "Plugin Threads Joined in Deinitialize"
        rule_69 (warning): "Memory and Allocation Safety"
        rule_70 (violation): "Framework Pointers Not Accessed After Deinitialize"
        rule_71 (violation): "hresult Return Values Checked"
        rule_72 (warning): "ASSERT Only for Programmer Invariants"
        rule_73 (violation): "Security: Logging, Shell, Path, and Error Exposure"
        rule_74 (violation): "JSON-RPC Input Validation for Bounds and Types"
        rule_75 (warning): "Config Completeness and Resource Cleanup"
        rule_76 (warning): "OOP Error Propagation and Method Naming"
        rule_77 (suggestion): "Observer Classes Private and Nested"
        rule_78 (violation): "No Deprecated JSON-RPC APIs"
        rule_79 (violation): "All Acquired Pointers Cleared After Deinitialize"

- [x] 1.2 Create `ThunderTools/PluginQA/rules/thunder-interface-rules.yaml` (v3.2.2)
      - File header: version (unquoted number: 3.2.2, NOT quoted string "3.2.2"), title, description
        with full CHANGELOG using format: `v3.2.2 (current):` (NOT dates like `v3.2.2 (2026-06-08):`)
      - Section headers use `# ===...===` style (NOT `# ───...───`)
      - Rule names use Title Case (e.g. "File and Namespace Structure" not "File and namespace structure")
      - core_rules list (15 rules, all severity: violation):
        core_1_1 ("File and Namespace Structure"), core_2_1 ("Interface Declaration Shape"),
        core_3_1 ("Interface ID Registration"), core_4_1 ("Pure Virtual Methods Only"),
        core_5_1 ("Return Type Conventions" — Core::hresult mandatory for @json in Thunder 5.0+),
        core_6_1 ("Const Correctness"), core_9_1 ("Thunder Type Conventions" — string not std::string),
        core_10_1 ("Register/Unregister Patterns" — INotification 1:many + ICallback 1:1),
        core_11_1 ("Nested Event Interfaces" — @event tag, EXTERNAL, ID required),
        core_12_1 ("@json Tag (CRITICAL)"), core_13_1 ("Binary Compatibility"),
        core_14_1 ("No AddRef/Release Redeclaration"), core_15_1 ("No std::map in Interfaces"),
        core_16_1 ("Explicit Integer Widths"), core_17_1 ("@restrict Mandatory with std::vector")
      - advisory_rules list (4 rules):
        advisory_m1_1 ("Single Responsibility Principle" — violation),
        advisory_m2_1 ("Enum Underlying Types" — warning, exclude anonymous ID enum),
        advisory_m3_1 ("No Exceptions" — violation),
        advisory_m5_1 ("@restrict for Non-vector Params" — warning,
                       explicitly states: does NOT apply to std::vector, that is covered by core_17_1)
      - Each rule structure: id, name, severity, description (multiline), extraction_logic (numbered steps),
        verification_logic (numbered steps), violation_pattern (single-line string NOT bullet list),
        fix_template (shows // WRONG: + // Correct: pattern), citation (reference to real Thunder file)
      - NO category field (removed in v3.2.2)

## Phase 2: Prompt files

- [x] 2.1 Create `ThunderTools/PluginQA/Prompts/thunder-plugin-review.prompt.md`
      Frontmatter: title: "Thunder Plugin Rule Review", description (mention 79 unified rules, semantic review)
      Sections (in order):
      - Core Principle: semantic code review for all 79 rules. NEVER pattern-match.
        ❌ open-ended vs ✅ bounded examples. All rules produce the same output format.
      - Report Output Philosophy: CRITICAL note — only report issues; PASS/SKIP as summary counts only;
        line numbers always required; always use ACTUAL plugin name in citations, NEVER {PluginName}
      - Usage: command syntax supporting TWO modes:
        Mode 1 (full plugin): `/thunder-plugin-review <PluginName>`
          — reviews ALL files in the plugin folder against all applicable rules
          Examples: `/thunder-plugin-review Dictionary`, `/thunder-plugin-review HdmiCecSink`
        Mode 2 (single file): `/thunder-plugin-review <PluginName> <FileName>`
          — reviews ONLY the specified file against rules applicable to that file
          — skips phases/rules that target other files
          Examples: `/thunder-plugin-review Dictionary Dictionary.cpp`,
                    `/thunder-plugin-review HdmiCecSink Module.h`
        File scoping logic for Mode 2:
          - If file is Module.h → run Phase 1 rules (rule_01, rule_03) + Holistic Rules (8 sub-phases) relevant to headers
          - If file is Module.cpp → run Phase 1 rules (rule_02) + Holistic Rules (8 sub-phases) for .cpp
          - If file is {PluginName}.h → run Phase 2, 3, 4 (class declaration), Holistic Rules (8 sub-phases) for headers
          - If file is {PluginName}.cpp → run Phase 2, 3, 4, 5 (implementation), Holistic Rules (8 sub-phases) for .cpp
          - If file is CMakeLists.txt → run Phase 7 only + CMake Holistic Rules (8 sub-phases)
          - If file is {PluginName}.conf.in → run Phase 6 only
          - If file is {PluginName}Implementation.h/cpp → run Phase 5C (OOP) + applicable Holistic Rules (8 sub-phases)
          - For any file: run applicable Holistic Rules (8 sub-phases) that match the file type
        5-step workflow (accept name + optional file → locate folder → identify target files
        → run applicable rules only → report)
      - Methodology: Step 1 (load YAML from ThunderTools/PluginQA/rules/thunder-plugin-rules.yaml —
        contains all 79 rules in phase_X_checkpoints and general_rules sections),
        Step 2 (identify plugin files — primary: ThunderNanoServices/{PluginName}/, fallback: workspace search,
        last resort: ask user; files table: Module.cpp, Module.h, {PluginName}.h, {PluginName}.cpp,
        CMakeLists.txt, {PluginName}.conf.in (optional), {PluginName}Implementation.h/cpp (optional)),
        Step 3 (execute all rules: read → reason → cite → fix)
      - CRITICAL FILE SCOPING RULES: Phase 1 applies ONLY to Module.h/Module.cpp;
        Class Registration (Phase 3) applies ONLY to main plugin class — internal helpers excluded
      - Contextual Judgment section: severity downgrade table with concrete example showing
        reasoning field (required on downgrade, omitted otherwise), no escalation rule
      - All rules defined inline in the prompt for reference
        (exact severity, extraction target, question, verification logic,
        citation format, conditional skip rules).
        Phase counts:
        Phase 1 Module Structure (3):
          rule_01 (suggestion): "MODULE_NAME Plugin_ Prefix"
          rule_02 (violation): "MODULE_NAME_DECLARATION"
          rule_03 (warning): "Module.h Uses #pragma once"
        Phase 2 Code Style (10):
          rule_04 (violation): "VARIABLE_IS_NOT_USED Accuracy"
          rule_05 (violation): "Error Code Preservation"
          rule_06 (warning): "NULL vs nullptr"
          rule_07 (violation): "No delete on COM Interface Pointers"
          rule_08 (violation): "nullptr After Release"
          rule_09 (violation conditional): "No QueryInterfaceByCallsign as Member"
          rule_10 (violation): "No Smart Pointers on COM Objects"
          rule_11 (violation): "No SmartLinkType for COMRPC Plugins"
          rule_12 (violation): "No delete on Plugin Object"
          rule_13 (violation): "No throw Keyword in Plugin Code"
        Phase 3 Class Registration (3):
          rule_14 (warning): "Special Members Deleted (Main Class)"
          rule_15 (violation): "Plugin Metadata Registration"
          rule_16 (violation conditional): "JSONRPC Inheritance When Used"
        Phase 4 Lifecycle (12):
          rule_17 (violation conditional): "IShell AddRef in Initialize"
          rule_18 (violation conditional): "IShell Release in Deinitialize"
          rule_19 (violation): "Information() Method"
          rule_20 (violation conditional): "Root<T>() Null Check"
          rule_21 (violation conditional): "Root<T>() Release in Deinitialize"
          rule_22 (violation conditional): "Observer Cleanup in Deinitialize"
          rule_23 (violation conditional): "SubSystems() Release in Deinitialize"
          rule_24 (violation): "Constructor Must Be Empty"
          rule_25 (violation conditional): "service->Register/Unregister Pairing"
          rule_26 (violation): "Initialize Returns Error String on Failure"
          rule_27 (violation): "No Manual Deinitialize() in Initialize"
          rule_28 (violation): "Destructor Must Be Empty"
        Phase 5 Implementation (4):
          rule_29 (violation conditional): "JSON-RPC Register/Unregister Pairing"
          rule_30 (violation conditional): "SinkType Pattern for Subscribers"
          rule_31 (violation conditional): "Unavailable() in SinkType Classes"
          rule_32 (violation): "No Hardcoded Paths"
        Phase 5C Out-of-Process (2 conditional):
          rule_33: "OOP Connection Termination in Deinitialize"
          rule_34: "connectionId Checked in IRemoteConnection Callbacks"
        Phase 6 Configuration (3):
          rule_35 (violation conditional): startmode declaration
          rule_36 (violation conditional): Config Core::JSON::Container
          rule_37 (violation): no hardcoded numeric tuning params
        Phase 7 CMake (1):
          rule_38 (violation conditional): "CXX_STANDARD Uses Thunder Variable"
        Phase 8 COM Interface Rules (1):
          rule_39 (violation): "COM Methods Return Core::hresult"
      - Output Format: UNIFIED FILE-WISE grouping — all issues from all 79 rules grouped by
        source file with a header "### {FileName} — N issue(s)" for each file that has failures;
        within each file group, each failing rule is a YAML block with fields:
        rule_id, status (FAIL/PASS/SKIP), severity (violation/warning/suggestion),
        question, answer, extracted_code with [File:line] prefix, violation_line,
        citation using ACTUAL plugin filename, fix, reasoning.
        NO separate "Part 1" / "Part 2" sections — all findings in one list.
      - Summary Format: Single unified Summary TABLE with columns Phase | PASS | FAIL | SKIP
        (one row per phase + one row for "Holistic Rules (8 sub-phases)" + a Total row showing all 79),
        followed by a numbered Next Steps list referencing [File:line] for each action item
      - Key Advantages section, Important Notes section
      - Command Examples at end

- [x] 2.2 Create `ThunderTools/PluginQA/Prompts/thunder-interface-review.prompt.md`
      Frontmatter: title: "Thunder Interface Validator", description (mention 19 rules, 15 core + 4 advisory)
      Sections (in order):
      - Context: Thunder uses COM-style interfaces, rules in thunder-interface-rules.yaml (v3.2.2)
      - Quick Reference table: all 19 rules (15 core + 4 advisory) as a markdown table
        with ID, Rule name (Title Case matching YAML), Key Point
      - CRITICAL note: load ThunderTools/PluginQA/rules/thunder-interface-rules.yaml for full
        rule definitions, extraction logic, verification logic, and fix templates before validating
      - Your Task: 5 steps (identify file → load YAML → validate all 19 rules →
        report with 🔴/🟡/🟢/✅/Compatibility Notes sections → provide specific fixes)
      - Step 6 — Generate CSV Report: file path format, CSV columns table, formatting rules,
        post-generation message with file count summary + Start-Process command
      - Example Output structure showing grouped sections
      - Contextual Judgment: JUDGE step table with Status field mapping
      - Common Critical Issues: 5 bullet points (missing @json, vector without @restrict,
        std::map, missing nested IDs, ambiguous int types)
      - Important Notes: Thunder docs link, validation priorities numbered list
        (@json first through type conventions last)

- [x] 2.4 Create `ThunderTools/PluginQA/Prompts/thunder-plugin-rule-manager.prompt.md`
      Frontmatter: title: "Thunder Plugin Rule Manager",
        description: "Add, update, or remove plugin rules (automated or manual) via guided questionnaire — keeps YAML, prompt, README, and spec in sync"
      Sections (in order):
      - Purpose: files kept in sync (YAML + prompt + README + spec)
      - Step 0: document template fast path — user pastes filled .md template with sections:
        "What This Rule Checks", "Extraction Target", "Yes/No Question", "Verification Steps",
        "Violation Pattern", "Fix", "Conditional"; also runs Manual vs Automated Classification
        to verify Type is correct
      - Step 1: collect action via vscode_askQuestions using TEXTUAL descriptions (not JSON blocks):
        Question 1 (header: "action"): "What do you want to do?" with options Add/Update/Remove
        Question 2 (header: "rule_kind"): "Is this an automated rule or a manual rule?" with
          options: "Automated rule (bounded yes/no query, one code block)" |
                   "Manual rule (semantic review, requires holistic code understanding)"
          message explaining the difference:
          - Automated: can be reduced to ONE yes/no question on ONE specific code block
          - Manual: requires architectural judgment, threading analysis, security reasoning,
            or reading multiple code paths that cannot be bounded to a single question
        Question 3 (header: "phase"): (only if automated) "Which phase does this rule belong to?"
          with options for all 9 phase groups
      - Step 2 branching:
        - REMOVE: ask for rule_id (rule_id or manual_XX) → Step 4
        - UPDATE: (2a) ask for rule_id; (2b) display current rule annotated with numbered
          field labels; (2c) multi-select which fields to change; (2d) ask only new values
        - ADD (phase rule): ask all structured fields (extraction, question, verification
          logic, fix, conditional) with detailed messages including ✅/❌ guidance
        - ADD (manual): ask only: name, severity, review_question, review_method,
          evidence_requirement — simpler flow since holistic rules don't need extraction/bounded_query
      - Step 3 (ADD/UPDATE): apply to YAML (phase checkpoints go under phase_N section,
        Holistic Rules (8 sub-phases) go under general_rules section) + prompt + README + spec;
        increment/decrement counts in metadata
      - Step 4 (REMOVE): remove from YAML + prompt + README + spec; decrement counts
      - Step 5: confirmation report listing all files updated with new counts
      - Phase vs General Classification table at end: 5 phase checkpoint criteria vs 6
        General criteria; ambiguous cases prompt user before proceeding

- [x] 2.5 Create `ThunderTools/PluginQA/Prompts/thunder-interface-rule-manager.prompt.md`
      Frontmatter: title: "Thunder Interface Rule Manager",
        description: "Add, update, or remove COM interface validation rules via guided questionnaire — keeps YAML, prompt, and spec in sync"
      Sections (in order):
      - Purpose: files kept in sync (YAML + prompt + spec)
      - Step 0: document template fast path — user pastes filled .md template with sections:
        "Description", "How to Find It (Extraction Logic)", "How to Verify It",
        "Violation Pattern", "Fix", "Example"; also runs Core vs Advisory Classification
      - Step 1: collect action via vscode_askQuestions using TEXTUAL descriptions (not JSON):
        Question 1 (header: "action"): "What do you want to do?" with options Add/Update/Remove
        Question 2 (header: "rule_list"): "Is this a core rule or an advisory rule?" with
        detailed message explaining difference between core (codegen/ABI/crash) and advisory
        (best practice/style)
      - Step 2 branching:
        - REMOVE: ask for rule_id only → Step 4
        - UPDATE: (2a) ask for rule_id; (2b) display current rule annotated with numbered
          field labels [1]–[9]; (2c) multi-select which fields to change; (2d) ask only new
          values for selected fields
        - ADD: ask all fields (id, name, severity, description, extraction_logic,
          verification_logic, violation_pattern, fix_template, example) with detailed messages
      - Step 3 (ADD/UPDATE): update YAML (bump patch version + CHANGELOG entry), update
        Quick Reference table row + rule detail block in prompt, update spec.md requirement line;
        update rule count comments
      - Step 4 (REMOVE): remove from all 3 files; bump version; add CHANGELOG removal entry
      - Step 5: confirmation report listing all 3 files updated with new version and counts
      - Core vs Advisory Classification table at end: core = codegen/ABI/crash failures;
        advisory = best practice; wrong list auto-corrected with explanation

- [x] 2.3 Create `ThunderTools/PluginQA/Prompts/thunder-generate-plugin.prompt.md`
      Frontmatter: title: "Thunder Plugin Generator",
        description: "Interactive Thunder plugin skeleton generator using PluginSkeletonGenerator.py"
      Sections:
      - Overview: what the generator does; CRITICAL RULES (use vscode_askQuestions, NOT chat;
        only run PSG; auto-fix include paths; do not modify anything else; NO --config flag)
      - Required Inputs from User: table with columns Parameter | Format | Options | Default
        (all 8 parameters: PluginName, OutputDirectory, OutOfProcess, CustomConfig,
        InterfacePaths, Preconditions, Terminations, Controls)
      - Step 1: Collect Parameters via vscode_askQuestions — JSON block with SIMPLER question text
        (e.g. "What is the name of your plugin? (PascalCase, e.g. HelloWorld)" not elaborate
        markdown formatting in the question text); options for Yes/No with descriptions;
        message fields for additional context
      - Answer processing rules: Yes/No → y/n, empty OutputDirectory → ThunderNanoServices,
        subsystems conditional (if any non-empty → PSG subsystems answer is y)
      - Workflow — Step 2 (locate PSG), Step 3 (run PSG interactively; feed answers to each
        PSG prompt in exact order; handle subsystems conditional)
      - Post-generation: auto-fix include paths bug workaround; list generated files
      - Error handling for PSG not found or generation failure

## Phase 3: Setup script

- [x] 3.1 Create `ThunderTools/PluginQA/setup-prompts.py` (cross-platform Python 3)
      - No external dependencies (stdlib only: json, os, sys, shutil, platform, datetime)
      - Detect platform (Windows/Mac/Linux) and find settings.json accordingly
      - Also detect VS Code Insiders variant
      - Backup: copy settings.json to settings.json.backup.{timestamp}
      - Parse JSON (handle missing or empty file: default to {})
      - Merge: add "ThunderTools/PluginQA/Prompts": true under chat.promptFilesLocations
      - Write back with indent=4
      - Idempotent: skip if key already present
      - Print clear next steps
      NOTE: Only a single Python script is provided. No .ps1 or .sh variants.

## Phase 4: Documentation

- [x] 4.1 Create `ThunderTools/PluginQA/README.md`
      Sections (in order, matching final PluginQA README exactly):
      - Title: Thunder PluginQA
      - Overview: automated validation tools, bullet list: Thunder COM Interfaces (19 rules),
        Thunder Plugins (39 checkpoints, 8 phases)
      - Quick Start: Setup (3 platform options with code blocks), Reload VS Code (2 steps + note),
        Use the Prompts (/thunder-interface-review, /thunder-plugin-review, /thunder-generate-plugin)
        each with description
      - Directory Structure: tree diagram of ThunderTools/PluginQA/
      - Interface Validation section: intro, Core Rules table (15 rows: ID, Rule, Critical Issues),
        Advisory Rules list (4 bullets), link to YAML
      - Plugin Validation section: intro, Validation Phases table by phase name with checkpoint count,
        all 8 phases listed with their checkpoints as sub-bullets
      - Plugin Generation section: How It Works (4 steps), Parameters table (8 rows),
        Example Usage (simple + with interface), Generated Files tree
      - Next Steps After Generation (5 numbered steps)
      - Integration with Validation (1 code block)
      - Methodology section: Understand-First methodology explanation, example block
      - Setup Script Details: what settings.json entry looks like, What the scripts do (5 bullets),
        Manual Setup fallback instructions
      - FAQ: 5 Q&A pairs
      - Validation Examples: Interface Validation Output code block, Plugin Checkpoint Output code block
      - Version History: v3.2.2 (current), v3.2.1, v3.3.0, v3.0.0
      - Contributing: 5-step process
      - Support: 3 bullet points including Thunder docs URL
      - Footer: Made with ⚡ for Thunder developers

- [x] 4.2 Create `ThunderTools/PluginQA/PLUGIN_GENERATOR_GUIDE.md`
      Sections:
      - Title, Overview paragraph
      - Quick Start: 5 numbered steps
      - Input Parameters: Required (3 params) and Optional (5 params) with descriptions
      - Example Scenarios: 3 scenarios (simple hello world, with config, OOP with interface)
        each showing exact inputs and what gets generated
      - Generated Files: tree for each scenario type
      - Troubleshooting: common issues (PSG not found, include path errors)
      - Integration with validation commands

- [x] 4.3 Create `ThunderTools/PluginQA/Prompts/README-interface-rules-manager.md`
      - Documentation for the interface rules manager (optional supplemental prompt)
      - Covers: how to add new rules to thunder-interface-rules.yaml,
        rule structure reference, testing new rules against example interfaces

## Phase 5: Report generation

- [x] 5.1 Add Step 6 (CSV report) to `ThunderTools/PluginQA/Prompts/thunder-plugin-review.prompt.md`
      - Appended after Command Examples section
      - File path: `ThunderTools/PluginQA/Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv`
      - Create folder if absent; never overwrite (append _2, _3 suffix)
      - Columns (14, exact order): No, Plugin, Date, Phase, rule_id, Rule_Name, Status,
        Severity, File, Line, Citation, Issue_Description, Fix_Summary, Reasoning
      - One row per FAIL/WARNING/SUGGESTION only — PASS and SKIP excluded
      - Status = effective status after JUDGE step (VIOLATION/WARNING/SUGGESTION)
      - Reasoning column populated only when JUDGE downgraded severity; empty otherwise
      - Formatting: UTF-8, CRLF, fields with commas/dashes quoted, embedded quotes escaped as ""
      - Empty report (all pass): header row + one comment row
      - Post-generation chat message: file path, issue counts, Start-Process command for Excel

- [x] 5.2 Add Step 6 (CSV report) to `ThunderTools/PluginQA/Prompts/thunder-interface-review.prompt.md`
      - Appended after Important Notes section
      - File path: `ThunderTools/PluginQA/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.csv`
      - Same no-overwrite rule, same formatting rules
      - Columns (13, exact order): No, Interface, Date, Rule_ID, Rule_Name, Status,
        Severity, File, Line, Citation, Issue_Description, Fix_Summary, Reasoning
      - One row per violated rule only
      - Same post-generation chat message format

- [x] 5.3 Create spec `ThunderTools/openspec/changes/thunder-plugin-qa/specs/reports/spec.md`
      - REQ-R1: plugin CSV path + no-overwrite rule
      - REQ-R2: interface CSV path + no-overwrite rule
      - REQ-R3: plugin CSV columns table (14 columns with descriptions + examples)
      - REQ-R4: interface CSV columns table (13 columns — Category removed)
      - REQ-R5: CSV formatting rules (UTF-8, CRLF, quoting, escaping, empty fields)
      - REQ-R6: folder creation requirement
      - REQ-R7: post-generation chat message format
      - REQ-R8: empty report format (all pass case)
      - Folder structure diagram
      - Out of scope: .xlsx, report viewer, diff, CI upload