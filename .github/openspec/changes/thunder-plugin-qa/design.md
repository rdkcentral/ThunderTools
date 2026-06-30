# Design: Thunder Plugin QA System

## Architecture Overview

Three VS Code Copilot Chat slash commands, each backed by a `.prompt.md` file.
Rules are stored in separate YAML files and loaded at runtime — prompts contain
behaviour logic, YAML files contain the rule data. This separation means rules
can be updated without touching prompt logic.

```
User types /thunder-plugin-review Dictionary
       │
       ▼
thunder-plugin-review.prompt.md
       │
       ▼
rules/thunder-plugin-rules.yaml   ← 79 unified rules (rule_01 to rule_79)
       │
       ▼
Plugin files in ThunderNanoServices/Dictionary/
       │
       ▼
Chat report: FAIL citations only, PASS/SKIP as counts
       │
       ▼
Reports/plugin/Dictionary_2026-06-05.csv   ← one row per issue, Excel-compatible
```

```
User types /thunder-plugin-rule-manager
       │
       ▼
thunder-plugin-rule-manager.prompt.md   ← behaviour: questionnaire + file sync logic
       │ collects via vscode_askQuestions
       ▼
User answers (or pastes filled template)
       │
       ▼
Atomically updates 4 files:
  thunder-plugin-rules.yaml
  thunder-plugin-review.prompt.md
  README.md
  specs/plugin/spec.md
```

## Delivery Mechanism

**File type:** VS Code Copilot Chat prompt files (`.prompt.md`)
**Registration:** `chat.promptFilesLocations` key in VS Code `settings.json`
  set to `ThunderTools/PluginQA/Prompts: true`
**Invocation:** User types `/thunder-plugin-review`, `/thunder-interface-review`,
  `/thunder-generate-plugin`, `/thunder-plugin-rule-manager`, or
  `/thunder-interface-rule-manager` in Copilot Chat

**Prompt file frontmatter (required by VS Code):**

```markdown
---
title: Thunder Plugin Rule Review
description: Semantic code review for Thunder plugins — understand first, then check
---
```

## Unified Review Methodology (ALL 79 rules)

Every rule — whether it targets a specific block (rule_01–39) or a broader concern
(rule_40–79) — uses the same "understand first, then check" approach:

1. **UNDERSTAND** — Read ALL plugin source files first. Build a complete mental model
   of the plugin's architecture: lifecycle flow, threading model, ownership patterns,
   data flow, and how Initialize/Deinitialize relate.
2. **FOCUS** — For the specific rule, examine the relevant code block WITH full context
   already understood. Never examine a block in isolation.
3. **REASON** — Ask the rule's question. If the specific block looks wrong in isolation
   but is correct given the full plugin architecture, it's not a real violation.
4. **JUDGE** — A rule FAILs only when the code is genuinely unsafe or incorrect in the
   context of the whole plugin. If the developer's approach is valid in context →
   downgrade severity and explain in the `reasoning` field.
5. **CITE** — exact [File:line] for any genuine failure
6. **FIX** — show corrected code block, not the whole file

This means: no block-wise pattern matching, no checking one line without understanding
its surrounding lifecycle. The reviewer must reason like a senior developer who has
read the entire plugin before commenting on any single line.

## Contextual Judgment

The JUDGE step implements severity downgrade logic:

| Scenario | Effective status |
|---|---|
| Rule satisfied → PASS | `PASS` |
| Rule violated, no mitigating context → FAIL | `VIOLATION` (or `WARNING`/`SUGGESTION` per YAML) |
| Rule technically violated but developer's approach is valid in context | downgrade one level; add `reasoning` |
| Rule violated with residual risk but approach is reasonable | downgrade to `WARNING`; add `reasoning` |

The `reasoning` field in the output block is **required** when severity is downgraded;
it is omitted when no downgrade occurs. Severity is never escalated above the level
defined in the YAML source.

## YAML Rule Structures

The YAML file contains two sections that produce identical report output:

**Phase checkpoints** (39 rules, under `phase_X_checkpoints` keys):
- Fields: `rule_id`, `name`, `severity`, `phase`, `extraction`, `bounded_query`, `verification_logic`, `conditional`, `skip_condition`, `citation`, `fix_template`

**Holistic Rules (8 sub-phases)** (40 rules, under `general_rules` key):
- Fields: `rule_id`, `name`, `severity`, `category`, `review_question`, `review_method`, `evidence_requirement`

Both types produce the same YAML output block in the report. The structural
difference is an internal implementation detail — users see one unified list
of findings grouped by file.

## YAML Interface Rule Structure

Each rule in `thunder-interface-rules.yaml`:

```yaml
- rule_id: "rule_17"
  name: "IShell AddRef in Initialize"
  severity: "violation"         # violation | warning | suggestion
  phase: "lifecycle"

  extraction:
    target: "IShell* member assignment and AddRef() call in Initialize()"
    method: "Read Initialize() body looking for _service (or similar IShell* member) assignment"
    code_block: "Lines in Initialize() that assign the service pointer"

  bounded_query:
    question: "Is AddRef() called on the stored IShell* pointer immediately after assignment in Initialize()?"
    expected_answer: "Yes"

  verification_logic:
    - "1. Check if the class has an IShell* member variable (e.g. _service, _shell)"
    - "2. If no IShell* member → SKIP this checkpoint"
    - "3. If IShell* member exists: find the assignment in Initialize() (e.g. _service = service;)"
    - "4. Check that AddRef() is called on it immediately after: _service->AddRef();"
    - "5. If AddRef() is missing → VIOLATION"

  conditional: true    # true = SKIP if prerequisite not found
  skip_condition: "Class has no stored IShell* member variable"

  citation:
    line_format: "[PluginName.cpp:LINE] IShell* stored but AddRef() not called after assignment"
    rule: "thunder-plugin-rules.yaml / rule_17"

  fix_template: |
    const string Initialize(PluginHost::IShell* service) {
        ASSERT(service != nullptr);
        _service = service;
        _service->AddRef();   // ADD THIS — must AddRef when storing the pointer
        // ...
    }
```

## YAML Interface Rule Structure

Each rule in `thunder-interface-rules.yaml`:

```yaml
- id: "core_12_1"
  name: "@json Tag (CRITICAL)"
  severity: "violation"
  description: |
    Without the @json tag, ZERO JSON-RPC code is generated for the interface.
    This is the most common critical omission. The tag must appear immediately
    above the struct declaration as: // @json 1.0.0
  extraction_logic: |
    1. Search for '// @json' or '/* @json' comment above the interface struct declaration
    2. Check the line immediately preceding the 'struct EXTERNAL I...' line
  verification_logic: |
    1. Tag must appear as: // @json 1.0.0
    2. Must be immediately above the struct declaration (no blank lines between)
    3. If the interface should generate JSON-RPC code and the tag is missing → VIOLATION
    4. If the interface is intentionally not JSON-RPC (pure COM only) → acceptable to omit
  violation_pattern: "No @json comment found above interface struct — no RPC code will be generated"
  fix_template: |
    // @json 1.0.0            ← ADD THIS
    struct EXTERNAL IMyInterface : virtual public Core::IUnknown {
        enum { ID = RPC::ID_MY_INTERFACE };
        // ...
    };
  citation: |
    ThunderInterfaces/interfaces/IDictionary.h:LINE — @json 1.0.0 above struct
```

NOTE: No `category` field in interface rules — it was removed in v3.2.2 as unused by validation logic.

## Report Design Decisions

**Why show failures only?**
Developers fixing bugs need to see what's broken, not a list of 15 passing
checks before finding the 2 that fail. Phase summaries provide the pass count
for completeness without clutter.

**Why YAML-style per-checkpoint output?**
The structured format (rule_id, question, answer, extracted_code, citation,
fix) makes it easy to scan. Each violation is self-contained: what was checked,
what was found, exactly where, and exactly how to fix it.

**Citation format:** `[{ActualPluginName}.cpp:{LineNumber}]`
Always uses the real plugin name from the user's command. Never uses placeholder
text like `{PluginName}` in output.

**Severity indicators:**
- ❌ = Violation (must fix — causes bugs, crashes, or codegen failures)
- ⚠️ = Warning (should fix — best practice violation)
- 💡 = Suggestion (optional — style/consistency)
- ✅ = Phase passed (summary line only, never individual checkpoint)

## File Scoping Rules (Critical for Correctness)

**Phase 1 (Module Structure):**
- rule_01 applies ONLY to `Module.h` — checks MODULE_NAME starts with Plugin_ prefix
- rule_02 applies ONLY to `Module.cpp` — checks MODULE_NAME_DECLARATION(BUILD_REFERENCE)
- rule_03 applies ONLY to `Module.h` — checks for `#pragma once` instead of legacy `#ifndef` guard

**Phase 3 (Class Registration):**
- rule_14 applies ONLY to the main Plugin class (implements PluginHost::IPlugin)
- Internal helper classes (Notification, Sink, Config, etc.) are excluded

**Conditional checkpoints:**
Checkpoints 4.2, 4.3, 4.5, 4.6, 4.7, 4.8, 4.10, 5.2, 5.4, 5.9, 5C/9.1, 5C/9.2, Phase 6 are conditional.
If the prerequisite is not found (e.g. no stored IShell pointer for 4.2), the
checkpoint SKIPS — it does not fail.

## Plugin Generator Design

**Why `vscode_askQuestions` not chat?**
Parameters collected via VS Code's native dialog appear as a structured form,
not a back-and-forth conversation. This is faster and avoids parsing chat text.

**Why interactive PSG mode (not --config)?**
PSG's interactive mode is stable. The --config path has known bugs. Running PSG
interactively and feeding answers programmatically is more reliable.

**Include path fix:**
PSG has a known bug where generated .h files have incorrect include paths.
After PSG completes, the generator automatically fixes these — no other
modifications are made to generated files.

**Answer mapping:**
- "Yes"/"No" from VS Code dialog → "y"/"n" for PSG prompts
- Empty OutputDirectory → default to ThunderNanoServices
- Multiple interface paths → feed one per PSG prompt, then Enter on empty line
- "Does your plugin rely on Thunder subsystems?" → "y" if ANY of Preconditions,
  Terminations, or Controls is non-empty; "n" otherwise

## Setup Script Design

All three scripts (`.ps1`, `.sh`, `.py`) do the same thing:

1. Detect VS Code settings.json location (platform-specific paths, also checks VS Code Insiders)
2. Create a timestamped backup of existing settings.json
3. Parse the JSON safely (handle missing file, handle existing `chat.promptFilesLocations`)
4. Merge the new entry: `"ThunderTools/PluginQA/Prompts": true`
5. Write back to settings.json
6. Print success message and next steps (Ctrl+Shift+P → Reload Window)

**Idempotent:** Running the script multiple times does not duplicate entries.
**Non-destructive:** All other existing settings are preserved.

## YAML File Versioning

- `thunder-plugin-rules.yaml`: version 3.0.0
  - 39 checkpoints, organisation: Phase1:3, Phase2:10, Phase3:3, Phase4:12, Phase5:4,
    Phase5C:2, Phase6:3, Phase7:1, Phase8:1
  - New checkpoints added over v1.0.0: rule_08 (nullptr after Release), rule_09–10 (COM ownership + no-throw), rule_16
    (INTERFACE_MAP + JSONRPC), rule_21/4_6/4_7/4_9/4_10/4_11/4_12 (full lifecycle
    correctness), rule_31 (Unavailable in SinkType),
    rule_34 (connectionId guard),
    rule_36/6_3 (JSON::Container + no magic numbers)

- `thunder-interface-rules.yaml`: version 3.2.2
  - 15 core rules + 4 advisory = 19 total
  - Core::hresult MANDATORY for Thunder 5.0+ @json interfaces
  - advisory_m5_1 explicitly excludes std::vector (core_17_1 covers that)
  - No `category` field — removed in v3.2.2