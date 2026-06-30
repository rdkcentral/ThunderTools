## Core Principle

This prompt performs **semantic code review** — reading plugin source code as a human developer and reasoning about its meaning.

**Phase checkpoint rules (39):** Each uses a bounded yes/no query on a specific code block.

❌ Open-ended (never do this): "Check this file for issues"
✅ Bounded (always this): "Is AddRef() called on the stored IShell* pointer immediately after assignment in Initialize()?"

**Holistic rules (40):** Each requires holistic analysis — understanding control flow, ownership, lifecycle, and threading across multiple code paths. Cannot be reduced to a single bounded query.

---

## Report Output Philosophy

> **CRITICAL:** Only report issues. PASS and SKIP appear as **summary counts only** in phase tables — never as individual checkpoint details.
> Every citation must use the **ACTUAL plugin name** from the user's command — NEVER use `{PluginName}` as a placeholder in output.
> **Every reported issue requires a `[File:line]` citation** — no exceptions.

---

## Usage

**Mode 1 — Full plugin review:**
```
/thunder-plugin-review <PluginName>
```
Reviews ALL files in the plugin folder against all applicable rules.

Examples:
- `/thunder-plugin-review Dictionary`
- `/thunder-plugin-review HdmiCecSink`

**Mode 2 — Single file review:**
```
/thunder-plugin-review <PluginName> <FileName>
```
Reviews ONLY the specified file against rules applicable to that file type.

Examples:
- `/thunder-plugin-review Dictionary Dictionary.cpp`
- `/thunder-plugin-review HdmiCecSink Module.h`

**File scoping for Mode 2:**
- `Module.h` → Phase 1 (rule_01, rule_03) + holistic rules relevant to headers
- `Module.cpp` → Phase 1 (rule_02) + holistic rules relevant to .cpp
- `{PluginName}.h` → Phase 2, 3, 4 (class declaration rules) + holistic rules for headers
- `{PluginName}.cpp` → Phase 2, 3, 4, 5 (implementation rules) + holistic rules for .cpp
- `CMakeLists.txt` → Phase 7 only + CMake holistic rules
- `{PluginName}.conf.in` → Phase 6 only
- `{PluginName}Implementation.h/cpp` → Phase 5C (only if CMakeLists.txt has PLUGIN_<NAME>_MODE = "Local") + applicable holistic rules
- Any file → applicable holistic rules matching the file type

**5-step workflow:**
1. Accept plugin name (+ optional file argument)
2. Locate the plugin folder
3. Identify target files to review
4. Run applicable rules only (scoped by file if Mode 2)
5. Report failures with exact citations

---

## Methodology

### Step 1 — Load Rules

Load `ThunderTools/PluginQA/rules/thunder-plugin-rules.yaml`. This file contains all 79 rules:
- `phase_1_checkpoints` through `phase_8_checkpoints` — 39 rules with bounded queries
- `general_rules` — 40 holistic rules across 8 sub-phases (rule_40 to rule_79)

All rules produce the same output format. There is no distinction between "phase checkpoint" and "holistic" in the report.

### Step 2 — Identify Plugin Files

Primary search: `ThunderNanoServices/{PluginName}/`
Fallback: Search workspace for a folder named `{PluginName}`
Last resort: Ask user for location

| File | Phase relevance |
|------|----------------|
| `Module.cpp` | Phase 1 (rule_02) |
| `Module.h` | Phase 1 (rule_01, rule_03) |
| `{PluginName}.h` | Phase 2, 3, 4 (class declarations) |
| `{PluginName}.cpp` | Phase 2, 3, 4, 5 (implementation) |
| `CMakeLists.txt` | Phase 7 |
| `{PluginName}.conf.in` | Phase 6 (optional) |
| `{PluginName}Implementation.h` | Phase 5C (only if PLUGIN_<NAME>_MODE = "Local" in CMakeLists.txt) |
| `{PluginName}Implementation.cpp` | Phase 5C (only if PLUGIN_<NAME>_MODE = "Local" in CMakeLists.txt) |

### Step 3 — Execute Rules (CRITICAL: Understand First, Then Check)

**Review philosophy for ALL 79 rules:**

1. **UNDERSTAND FIRST** — Read ALL plugin source files. Build a complete mental model of the plugin's architecture: its lifecycle flow, threading model, ownership patterns, data flow, and how Initialize/Deinitialize relate to each other. Do this ONCE before checking any rule.
2. **FOCUS** — For each rule, look at the specific concern it asks about. But reason about it WITH the full context you already understand — never in isolation.
3. **REASON** — Ask the rule's question. If the specific block looks like a violation when viewed alone, ask yourself: "Does the full plugin context make this approach correct and safe?" If yes → downgrade severity.
4. **CITE** — If genuinely wrong (not just technically different), cite exact `[ActualPluginName.cpp:LINE]`
5. **FIX** — Show corrected code using `fix_template`

**Key:** A rule should FAIL only when the code is genuinely unsafe or incorrect in the context of the whole plugin — not because a single block viewed in isolation doesn't match a pattern.

---

## CRITICAL FILE SCOPING RULES

- **Phase 1** (Module Structure) applies ONLY to `Module.h` and `Module.cpp` — never to the main plugin class files
- **Phase 3** (Class Registration) applies ONLY to the **main plugin class** (the one implementing `PluginHost::IPlugin`) — internal helper classes (Notification, Sink, Config, etc.) are explicitly excluded

---

## Contextual Judgment (JUDGE step)

After applying verification logic, if the answer is "No" (rule technically violated), reason whether the developer's actual approach is **valid and reasonable in context**:

| Scenario | Effective status | `reasoning` field |
|----------|-----------------|-------------------|
| Rule satisfied | `PASS` | Omit |
| Rule violated, no mitigation | `VIOLATION` / `WARNING` / `SUGGESTION` | Omit |
| Rule violated but developer's approach is valid in context | Downgrade one level | **Required** — explain rule, developer's approach, why it is acceptable |
| Violated with residual risk but approach is reasonable | `WARNING` | **Required** |

The `reasoning` field is **required** when severity is downgraded; it is **omitted** when no downgrade occurs.
Severity is **never escalated** above the YAML-defined level.

**Example (severity downgraded):**

```yaml
rule_id: rule_17
status: SUGGESTION          # downgraded from VIOLATION
severity: violation
question: "Is AddRef() called on the stored IShell* pointer immediately after assignment in Initialize()?"
answer: "No"
extracted_code: |
  [Dictionary.cpp:45] _service = service;
  [Dictionary.cpp:46] // AddRef not called here — service pointer is used locally only
violation_line: "[Dictionary.cpp:45]"
citation: "[Dictionary.cpp:45] IShell* assigned without AddRef()"
fix: "_service->AddRef(); // add immediately after _service = service;"
reasoning: "The rule exists to prevent dangling pointers when the IShell* is stored across calls. In this plugin, _service is used only within Initialize() and does not persist — it is not a true member field storing the pointer for later use. The developer's approach is valid in this context with no residual lifetime risk."
```

---

## Rules Reference (79 rules, sequential)

### Phase 1 — Module Structure (rule_01 to rule_03)

**rule_01** (suggestion) — `MODULE_NAME Plugin_ Prefix`
- Target: `Module.h` only
- Query: Does MODULE_NAME value start with `Plugin_` prefix?

**rule_02** (violation) — `MODULE_NAME_DECLARATION`
- Target: `Module.cpp` only
- Query: Does Module.cpp contain `MODULE_NAME_DECLARATION(BUILD_REFERENCE)`?

**rule_03** (warning) — `Module.h Uses #pragma once`
- Target: `Module.h` only
- Query: Does Module.h use `#pragma once` instead of a legacy `#ifndef` guard?

---

### Phase 2 — Code Style (rule_04 to rule_13)

**rule_04** (violation) — `VARIABLE_IS_NOT_USED Accuracy`
- Query: Are all VARIABLE_IS_NOT_USED-annotated parameters genuinely unused?

**rule_05** (violation) — `Error Code Preservation`
- Query: Is the error code preserved on all paths — never unconditionally overwritten?

**rule_06** (warning) — `NULL vs nullptr`
- Query: Is nullptr used exclusively — no NULL as a pointer value?

**rule_07** (violation) — `No delete on COM Interface Pointers`
- Query: Are there zero uses of delete on COM interface pointer types?

**rule_08** (violation) — `nullptr After Release`
- Query: Is nullptr assigned immediately after every ->Release() on a member?

**rule_09** (violation, conditional) — `No QueryInterfaceByCallsign as Member`
- SKIP if no QueryInterfaceByCallsign() calls
- Query: Is the result always used transiently (never stored as member)?

**rule_10** (violation) — `No Smart Pointers on COM Objects`
- Query: Are there zero COM interface pointers wrapped in shared_ptr or unique_ptr?

**rule_11** (violation) — `No SmartLinkType for COMRPC Plugins`
- Query: Is SmartLinkType absent from the plugin?

**rule_12** (violation) — `No delete on Plugin Object`
- Query: Is delete this absent from all plugin code?

**rule_13** (violation) — `No throw Keyword in Plugin Code`
- Query: Is throw absent from all executable plugin code?

---

### Phase 3 — Class Registration (rule_14 to rule_16)

**rule_14** (warning) — `Special Members Deleted (Main Class)`
- MAIN class only — helper classes excluded
- Query: Are all 4 special members deleted in the main plugin class?

**rule_15** (violation) — `Plugin Metadata Registration`
- Query: Does the plugin .cpp contain Plugin::Metadata<PluginName> registration?

**rule_16** (violation, conditional) — `JSONRPC Inheritance When Used`
- SKIP if no JSON-RPC Register() calls
- Query: Does the class inherit PluginHost::JSONRPC when JSON-RPC is used?

---

### Phase 4 — Lifecycle (rule_17 to rule_28)

**rule_17** (violation, conditional) — `IShell AddRef in Initialize`
- SKIP if no stored IShell* member
- Query: Is AddRef() called immediately after assignment?

**rule_18** (violation, conditional) — `IShell Release in Deinitialize`
- SKIP if no stored IShell* member
- Query: Is Release() + nullptr called in Deinitialize()?

**rule_19** (violation) — `Information() Method`
- Query: Does the plugin implement string Information() const?

**rule_20** (violation, conditional) — `Root<T>() Null Check`
- SKIP if no Root<T>() calls
- Query: Is the return value checked for nullptr before use?

**rule_21** (violation, conditional) — `Root<T>() Release in Deinitialize`
- SKIP if no Root<T>() stored
- Query: Is the pointer Released and nulled in Deinitialize()?

**rule_22** (violation, conditional) — `Observer Cleanup in Deinitialize`
- SKIP if no observer registration
- Query: Is every registered observer unregistered in Deinitialize()?

**rule_23** (violation, conditional) — `SubSystems() Release in Deinitialize`
- SKIP if no SubSystems() call
- Query: Is SubSystems() released in Deinitialize()?

**rule_24** (violation) — `Constructor Must Be Empty`
- Query: Is the constructor body empty (no logic)?

**rule_25** (violation, conditional) — `service->Register/Unregister Pairing`
- SKIP if no service->Register() calls
- Query: Is every Register() matched by Unregister() in Deinitialize()?

**rule_26** (violation) — `Initialize Returns Error String on Failure`
- Query: Does Initialize() return non-empty error string on every failure path?

**rule_27** (violation) — `No Manual Deinitialize() in Initialize`
- Query: Is Deinitialize() never called from within Initialize()?

**rule_28** (violation) — `Destructor Must Be Empty`
- Query: Is the destructor body completely empty?

---

### Phase 5 — Implementation (rule_29 to rule_32)

**rule_29** (violation, conditional) — `JSON-RPC Register/Unregister Pairing`
- SKIP if no JSON-RPC handlers
- Query: Is every handler registered in Initialize() unregistered in Deinitialize()?

**rule_30** (violation, conditional) — `SinkType Pattern for Subscribers`
- SKIP if no subscriber classes
- Query: Do notification subscribers follow the SinkType pattern?

**rule_31** (violation, conditional) — `Unavailable() in SinkType Classes`
- SKIP if no SinkType classes
- Query: Does every SinkType class implement Unavailable()?

**rule_32** (violation) — `No Hardcoded Paths`
- Query: Are there zero hardcoded filesystem paths?

---

### Phase 5C — Out-of-Process (rule_33 to rule_34)

**rule_33** (violation, conditional) — `OOP Connection Termination in Deinitialize`
- SKIP if CMakeLists.txt does NOT have PLUGIN_<NAME>_MODE set to "Local"
- Query: Does Deinitialize() terminate the OOP connection?

**rule_34** (violation, conditional) — `connectionId Checked in IRemoteConnection Callbacks`
- SKIP if no IRemoteConnection::INotification implementation
- Query: Is connectionId checked before acting in every callback?

---

### Phase 6 — Configuration (rule_35 to rule_37)

**rule_35** (violation, conditional) — `Startmode Declaration`
- SKIP if no .conf.in file
- Query: Does .conf.in declare an explicit startmode?

**rule_36** (violation, conditional) — `Config Core::JSON::Container`
- SKIP if no Config class
- Query: Does Config inherit Core::JSON::Container?

**rule_37** (violation) — `No Hardcoded Numeric Tuning Parameters`
- Query: Are there zero hardcoded tuning parameters (timeouts, sizes, counts)?

---

### Phase 7 — CMake (rule_38)

**rule_38** (violation, conditional) — `CXX_STANDARD Uses Thunder Variable`
- SKIP if CMakeLists.txt does not set CXX_STANDARD
- Query: Does CXX_STANDARD use `${CXX_STD}`?

---

### Phase 8 — COM Interface (rule_39)

**rule_39** (violation) — `COM Methods Return Core::hresult`
- Query: Do all COM interface methods return Core::hresult?

---

### Holistic Rules (rule_40 to rule_79) — 8 sub-phases

Rules 40–79 require reading broader code context across multiple methods/files.
Full definitions in `thunder-plugin-rules.yaml`.

#### Conventions & Encapsulation (4 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_40 | #pragma once in all headers | suggestion |
| rule_41 | Apache 2.0 Copyright Header | suggestion |
| rule_49 | CMake NAMESPACE Variable | suggestion |
| rule_77 | Observer Classes Private and Nested | suggestion |

#### Lifecycle & State Integrity (6 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_44 | OOP Registration Order | violation |
| rule_45 | Complete State Reset in Deinitialize | violation |
| rule_46 | Reverse-Order Cleanup | suggestion |
| rule_57 | Config Errors Return Non-Empty from Initialize | violation |
| rule_70 | Framework Pointers Not Accessed After Deinitialize | violation |
| rule_79 | All Acquired Pointers Cleared After Deinitialize | violation |

#### Concurrency & Threading (10 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_47 | Observer Locking | violation |
| rule_50 | Handlers Must Not Block | violation |
| rule_51 | No Activate/Deactivate from Handlers | violation |
| rule_52 | Shared State Protected by CriticalSection | violation |
| rule_53 | No Lock Held During Framework Callbacks | violation |
| rule_54 | Worker Jobs Check Deinitialize Guard | violation |
| rule_65 | JSON-RPC Handlers Are Re-entrant Safe | violation |
| rule_66 | IPlugin::INotification Callbacks Must Not Block | violation |
| rule_67 | Lock Scope Minimized | violation |
| rule_68 | Plugin Threads Joined in Deinitialize | violation |

#### COM Reference & Memory Safety (3 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_48 | AddRef/Release Balance | violation |
| rule_63 | COM Reference Counting Correctness | violation |
| rule_71 | hresult Return Values Checked | violation |

#### Resource Management (3 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_55 | File Descriptors / Sockets Wrapped in RAII | violation |
| rule_56 | No Unbounded Memory Growth | violation |
| rule_69 | Memory and Allocation Safety | warning |

#### JSON-RPC Compliance (7 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_58 | interface->Register/Unregister Pairing | violation |
| rule_59 | Handler Registration Order | violation |
| rule_60 | Use Core::ERROR_* for Handler Failure Codes | violation |
| rule_61 | Input Validation in JSON-RPC Handlers | violation |
| rule_62 | Event Constants and Typed JSON Payloads | warning |
| rule_74 | JSON-RPC Input Validation for Bounds and Types | violation |
| rule_78 | No Deprecated JSON-RPC APIs | violation |

#### Inter-Plugin & OOP Design (2 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_64 | No Hard Inter-Plugin Dependencies | warning |
| rule_76 | OOP Error Propagation and Method Naming | warning |

#### Code Quality & Security (5 rules)
| ID | Name | Severity |
|----|------|----------|
| rule_42 | STL Types | warning |
| rule_43 | ASSERT vs Error Handling | warning |
| rule_72 | ASSERT Only for Programmer Invariants | warning |
| rule_73 | Security: Logging, Shell, Path, and Error Exposure | violation |
| rule_75 | Config Completeness and Resource Cleanup | warning |

---

## Output Format

### Issue Report — Grouped by File

Group all issues (from any rule) by source file. For files with failures:

```
### {ActualFileName} — N issue(s)
```

For each failing rule (same format for all 79 rules):

```yaml
rule_id: rule_06
status: WARNING
severity: warning
question: "Is nullptr used exclusively — no NULL as a pointer value in code?"
answer: "No"
extracted_code: |
  [Dictionary.cpp:108] IPlugin* plugin = NULL;
violation_line: "[Dictionary.cpp:108]"
citation: "[Dictionary.cpp:108] NULL used as null pointer — use nullptr"
fix: "IPlugin* plugin = nullptr;"
reasoning:   # omit if no severity downgrade
```

Severity heading prefixes:
- ❌ = VIOLATION
- ⚠️ = WARNING
- 💡 = SUGGESTION

### Summary Table (single unified table for all 79 rules)

| Phase | PASS | FAIL | SKIP |
|-------|------|------|------|
| Phase 1 — Module Structure | N | N | N |
| Phase 2 — Code Style | N | N | N |
| Phase 3 — Class Registration | N | N | N |
| Phase 4 — Lifecycle | N | N | N |
| Phase 5 — Implementation | N | N | N |
| Phase 5C — Out-of-Process | N | N | N |
| Phase 6 — Configuration | N | N | N |
| Phase 7 — CMake | N | N | N |
| Phase 8 — COM Interfaces | N | N | N |
| Holistic Rules (8 sub-phases) | N | N | N |
| **Total (79 rules)** | **N** | **N** | **N** |

Followed by a numbered **Next Steps** list citing `[File:line]` for each action item.

---

## Key Advantages

- **Reproducible:** Same bounded questions → same answers on the same code
- **Fast:** One code block per checkpoint — no whole-file analysis per rule
- **Actionable:** Each failure has an exact line, an explanation, and a fix
- **Contextual:** Severity downgrade logic handles valid alternative approaches

## Important Notes

1. Load `thunder-plugin-rules.yaml` at the start of every review run — rules may have been updated
2. Never embed rule data in this prompt — always load from YAML at runtime
3. If a plugin is not found in `ThunderNanoServices/`, search workspace before asking
4. Total: 79 rules (rule_01 to rule_79), all sequential, all producing unified output
5. Rule IDs in reports use the format `rule_XX` — no phase prefixes

## Command Examples

```
/thunder-plugin-review Dictionary
/thunder-plugin-review NetworkControl
/thunder-plugin-review HdmiCecSink
/thunder-plugin-review Dictionary Dictionary.cpp
/thunder-plugin-review NetworkControl Module.h
```

---

## Step 6 — Generate CSV Report

After reporting all results in chat, generate a CSV file for tracking and Excel analysis.

**File path:** `ThunderTools/PluginQA/Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv`

- Create `ThunderTools/PluginQA/Reports/plugin/` if it does not exist
- Never overwrite an existing file — append `_2`, `_3` etc. if a file with that name already exists

**CSV columns (exact order, 14 columns):**

| Column | Description | Example |
|--------|-------------|---------|
| No | Row number starting at 1 | `1` |
| Plugin | Plugin name from command argument | `HdmiCecSink` |
| Date | ISO date of review | `2026-06-05` |
| Phase | Full phase label | `Phase 2 — Code Style` |
| Rule_ID | Sequential rule ID | `rule_06` |
| Rule_Name | Checkpoint name from YAML | `NULL vs nullptr` |
| Status | Effective status after JUDGE step | `VIOLATION` / `WARNING` / `SUGGESTION` |
| Severity | YAML severity level | `violation` / `warning` / `suggestion` |
| File | Source file where issue was found | `HdmiCecSink.cpp` |
| Line | Exact line number | `128` |
| Citation | Short citation string | `[HdmiCecSink.cpp:128]` |
| Issue_Description | What was found | `NULL used instead of nullptr` |
| Fix_Summary | One-line fix description | `Replace NULL with nullptr` |
| Reasoning | Populated only when severity was downgraded by JUDGE; empty otherwise | `` |

**Header row:**
```
No,Plugin,Date,Phase,Rule_ID,Rule_Name,Status,Severity,File,Line,Citation,Issue_Description,Fix_Summary,Reasoning
```

**Rules:**
- One row per FAIL / WARNING / SUGGESTION only — PASS and SKIP rows are excluded
- `Status` reflects the **effective** severity after the JUDGE step
- `Reasoning` column is populated only when severity was downgraded; empty otherwise
- UTF-8, no BOM, CRLF line endings
- Fields containing commas must be wrapped in double quotes: `"Phase 2 — Code Style"`
- Embedded double quotes escaped as `""`: `"Use ""nullptr"" not NULL"`
- Empty fields: leave blank (two consecutive commas: `,,`)

**If no issues found** (all checkpoints pass), still generate the CSV with header + one comment row:

```csv
No,Plugin,Date,Phase,Rule_ID,Rule_Name,Status,Severity,File,Line,Citation,Issue_Description,Fix_Summary,Reasoning
,,,,,,,,,,,,All checkpoints passed — no issues found,
```

**Post-generation message:**
```
📊 Report saved:
   ThunderTools/PluginQA/Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv
   {N} issue(s) logged — {violations} violations, {warnings} warnings, {suggestions} suggestions

To open in Excel (Windows):
   Start-Process "ThunderTools\PluginQA\Reports\plugin\{PluginName}_{YYYY-MM-DD}.csv"
```