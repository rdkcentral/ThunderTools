---
title: "Thunder Plugin Review"
description: "Semantic review of Thunder plugins against the Thunder plugin rule set."
---

## Core Principle

This prompt performs **semantic code review** - reading plugin source code as a human developer and reasoning about its meaning.

**Phase checkpoint rules (38):** Each uses a bounded yes/no query on a specific code block.

❌ Open-ended (never do this): "Check this file for issues"
✅ Bounded (always this): "Is AddRef() called on the stored IShell* pointer immediately after assignment in Initialize()?"

**Holistic rules (46):** Each requires holistic analysis - understanding control flow, ownership, lifecycle, and threading across multiple code paths. Cannot be reduced to a single bounded query.

---

## Report Output Philosophy

> **CRITICAL:** Only report issues. PASS and SKIP appear as **summary counts only** in phase tables - never as individual checkpoint details.
> Every citation must use the **ACTUAL plugin name** from the user's command - NEVER use `{PluginName}` as a placeholder in output.
> **Every reported issue requires a `[File:line]` citation** - no exceptions.

---

## Usage

**Mode 1 - Full plugin review:**
```
/thunder-plugin-review <PluginName>
```
Reviews ALL files in the plugin folder against all applicable rules.

**Mode 2 - Single file review:**
```
/thunder-plugin-review <PluginName> <FileName>
```
Reviews ONLY the specified file against rules applicable to that file type.

Examples:
- `/thunder-plugin-review Dictionary`
- `/thunder-plugin-review HdmiCecSink`
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

### Step 1 - Load Rules

Load `PluginQualityAdvisor/rules/thunder-plugin-rules.yaml`. This file contains all 84 rules:
- `phase_1_checkpoints` through `phase_8_checkpoints` - 38 rules with bounded queries
- `general_rules` - 46 holistic rules across 8 sub-phases (rule_39 to rule_84)

All rules produce the same output format. There is no distinction between "phase checkpoint" and "holistic" in the report.

### Step 2 - Identify Plugin Files

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

### Step 3 - Execute Rules (CRITICAL: Understand First, Then Check)

**Thunder Version Detection:**
- `namespace WPEFramework` → **pre-Thunder 5.0** plugin
- `namespace Thunder` → **Thunder 5.0+** plugin

This affects which rules apply:
- **rule_38** (COM Methods Return Core::hresult): Only applies to Thunder 5.0+ plugins. Pre-5.0 plugins correctly use `uint32_t` - do NOT flag as a violation.
- **rule_31** (No Hardcoded Paths): Linux kernel virtual filesystems (`/proc/`, `/sys/`, `/dev/`) are fixed OS paths, not deployment-specific - do NOT flag these.

**Review philosophy for ALL 84 rules:**

1. **UNDERSTAND FIRST** - Read ALL plugin source files. Build a complete mental model of the plugin's architecture: its lifecycle flow, threading model, ownership patterns, data flow, and how Initialize/Deinitialize relate to each other. Do this ONCE before checking any rule.
2. **FOCUS** - For each rule, look at the specific concern it asks about. But reason about it WITH the full context you already understand - never in isolation.
3. **REASON** - Ask the rule's question. If the specific block looks like a violation when viewed alone, ask yourself: "Does the full plugin context make this approach correct and safe?" If yes → downgrade severity.
4. **CITE** - If genuinely wrong (not just technically different), cite exact `[ActualPluginName.cpp:LINE]`
5. **FIX** - Show corrected code using `fix_template`

**Key:** A rule should FAIL only when the code is genuinely unsafe or incorrect in the context of the whole plugin - not because a single block viewed in isolation doesn't match a pattern.

---

## CRITICAL FILE SCOPING RULES

- **Phase 1** (Module Structure) applies ONLY to `Module.h` and `Module.cpp` - never to the main plugin class files
- **Phase 3** (Class Registration) applies ONLY to the **main plugin class** (the one implementing `PluginHost::IPlugin`) - internal helper classes (Notification, Sink, Config, etc.) are explicitly excluded

---

## Contextual Judgment (JUDGE step)

After applying verification logic, if the answer is "No" (rule technically violated), reason whether the developer's actual approach is **valid and reasonable in context**:

| Scenario | Effective status | `reasoning` field |
|----------|-----------------|-------------------|
| Rule satisfied | `PASS` | Omit |
| Rule violated, no mitigation | `VIOLATION` / `WARNING` / `SUGGESTION` | Omit |
| Rule violated but developer's approach is valid in context | Downgrade one level | **Required** - explain rule, developer's approach, why it is acceptable |
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
  [Dictionary.cpp:46] // AddRef not called here - service pointer is used locally only
violation_line: "[Dictionary.cpp:45]"
citation: "[Dictionary.cpp:45] IShell* assigned without AddRef()"
fix: "_service->AddRef(); // add immediately after _service = service;"
reasoning: "The rule exists to prevent dangling pointers when the IShell* is stored across calls. In this plugin, _service is used only within Initialize() and does not persist - it is not a true member field storing the pointer for later use. The developer's approach is valid in this context with no residual lifetime risk."
```

```yaml
rule_id: rule_06
status: WARNING
severity: warning
question: "Is nullptr used exclusively - no NULL as a pointer value in code?"
answer: "No"
extracted_code: |
  [Dictionary.cpp:108] IPlugin* plugin = NULL;
violation_line: "[Dictionary.cpp:108]"
citation: "[Dictionary.cpp:108] NULL used as null pointer - NULL vs nullptr"
fix: "IPlugin* plugin = nullptr;"
reasoning:   # omit if no severity downgrade
```

## Output Format

### Issue Report - Grouped by File

Group all issues (from any rule) by source file. For files with failures:

```
### {ActualFileName} - N issue(s)
```

Under each file heading, list every failing rule as a YAML block (same format for all 84 rules):

```yaml
rule_id: rule_XX
status: ❌ VIOLATION              # or ⚠️ WARNING or 💡 SUGGESTION
severity: violation               # original YAML severity (never changes)
question: "The rule's yes/no question"
answer: "No"
extracted_code: |
  [ActualFile.cpp:LINE] relevant code snippet
violation_line: "[ActualFile.cpp:LINE]"
citation: "[ActualFile.cpp:LINE] Short issue description"
fix: "corrected code or one-line instruction"
reasoning:                        # ONLY if severity was downgraded; omit otherwise
```

Status symbols (prefix the `status:` field value with these):
- ❌ `VIOLATION` - blocking issue, must fix
- ⚠️ `WARNING` - should fix
- 💡 `SUGGESTION` - optional improvement

**Format:** `status: ❌ VIOLATION` or `status: ⚠️ WARNING` or `status: 💡 SUGGESTION`

When severity is downgraded (e.g. violation → suggestion), the symbol matches the **effective** (downgraded) status, not the original YAML severity.
### Summary Table (single unified table for all 84 rules)

| Phase | PASS | FAIL | SKIP |
|-------|------|------|------|
| Phase 1 - Module Structure | N | N | N |
| Phase 2 - Code Style | N | N | N |
| Phase 3 - Class Registration | N | N | N |
| Phase 4 - Lifecycle | N | N | N |
| Phase 5 - Implementation | N | N | N |
| Phase 5C - Out-of-Process | N | N | N |
| Phase 6 - Configuration | N | N | N |
| Phase 7 - CMake | N | N | N |
| Phase 8 - COM Interfaces | N | N | N |
| Holistic Rules (8 sub-phases) | N | N | N |
| **Total (84 rules)** | **N** | **N** | **N** |

Followed by a numbered **Next Steps** list citing `[File:line]` for each action item.

---

## Key Advantages

- **Reproducible:** Same bounded questions → same answers on the same code
- **Fast:** One code block per checkpoint - no whole-file analysis per rule
- **Actionable:** Each failure has an exact line, an explanation, and a fix
- **Contextual:** Severity downgrade logic handles valid alternative approaches

## Important Notes

1. Load `thunder-plugin-rules.yaml` at the start of every review run - rules may have been updated
2. Never embed rule data in this prompt - always load from YAML at runtime
3. If a plugin is not found in `ThunderNanoServices/`, search workspace before asking
4. Total: 84 rules (rule_01 to rule_84), all sequential, all producing unified output
5. Rule IDs in reports use the format `rule_XX` - no phase prefixes

## Command Examples

```
/thunder-plugin-review Dictionary
/thunder-plugin-review NetworkControl
/thunder-plugin-review HdmiCecSink
/thunder-plugin-review Dictionary Dictionary.cpp
/thunder-plugin-review NetworkControl Module.h
```

---

## Step 6 - Generate CSV Report

After reporting all results in chat, generate a CSV file for tracking and Excel analysis.

**File path:** `PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv`

- Create `PluginQualityAdvisor/Reports/plugin/` if it does not exist
- Never overwrite an existing file - append `_2`, `_3` etc. if a file with that name already exists

**CSV columns (exact order, 14 columns):**

| Column | Description | Example |
|--------|-------------|---------|
| No | Row number starting at 1 | `1` |
| Plugin | Plugin name from command argument | `HdmiCecSink` |
| Date | ISO date of review | `2026-06-05` |
| Phase | Full phase label | `Phase 2 - Code Style` |
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
- One row per FAIL / WARNING / SUGGESTION only - PASS and SKIP rows are excluded
- `Status` reflects the **effective** severity after the JUDGE step
- `Reasoning` column is populated only when severity was downgraded; empty otherwise
- UTF-8, no BOM, CRLF line endings
- Fields containing commas must be wrapped in double quotes: `"Phase 2 - Code Style"`
- Embedded double quotes escaped as `""`: `"Use ""nullptr"" not NULL"`
- Empty fields: leave blank (two consecutive commas: `,,`)

**If no issues found** (all checkpoints pass), still generate the CSV with header + one comment row:

```csv
No,Plugin,Date,Phase,Rule_ID,Rule_Name,Status,Severity,File,Line,Citation,Issue_Description,Fix_Summary,Reasoning
,,,,,,,,,,,,All checkpoints passed - no issues found,
```

**Post-generation message:**
```
📊 Report saved:
   PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv
   {N} issue(s) logged - {violations} violations, {warnings} warnings, {suggestions} suggestions

To open in Excel (Windows):
   Start-Process "PluginQualityAdvisor\Reports\plugin\{PluginName}_{YYYY-MM-DD}.csv"
```