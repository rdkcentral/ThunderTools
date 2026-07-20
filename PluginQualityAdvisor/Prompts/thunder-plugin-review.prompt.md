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
- `{PluginName}Implementation.h/cpp` → Phase 5C (only if plugin is OOP: PLUGIN_<NAME>_MODE = "Local" in CMakeLists.txt OR outofprocess = true in .conf.in) + applicable holistic rules
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

Load `PluginQualityAdvisor/rules/thunder-plugin-rules.yaml` **in full** — read the entire file from start to end. This file contains all 84 rules:
- `phase_1_checkpoints` through `phase_8_checkpoints` - 38 rules with bounded queries
- `general_rules` - 46 holistic rules across 8 sub-phases (rule_39 to rule_84)

**CRITICAL:** Confirm you have loaded ALL rules up to rule_84 before starting the review. If the YAML reading was truncated or incomplete, continue reading until you reach the end. Do NOT start reviewing code until all 84 rules are loaded. Every rule must be evaluated — never skip a rule because it seems low-value or unlikely to apply.

All rules produce the same output format. There is no distinction between "phase checkpoint" and "holistic" in the report.

### Step 2 - Identify Plugin Files

Search the workspace for a folder named `{PluginName}` (e.g. `ThunderNanoServices/{PluginName}/`).
If not found: Ask user for location.

**CRITICAL: Read ALL .h and .cpp files in the plugin folder AND all subdirectories** — not just the primary files below. Subdirectories (e.g. `LinchpinService/`, `src/`, `lib/`) often contain implementation code with issues. Helper headers (e.g. `WAVRecorder.h`, `DHCPClient.h`, `*Sink.h`, `HID.h`) often contain code relevant to holistic rules (printf usage, lock patterns, COM reference handling). List all files in the plugin directory tree recursively and read every source file before beginning the review.

| File | Phase relevance |
|------|----------------|
| `Module.cpp` | Phase 1 (rule_02) |
| `Module.h` | Phase 1 (rule_01, rule_03) |
| `{PluginName}.h` | Phase 2, 3, 4 (class declarations) |
| `{PluginName}.cpp` | Phase 2, 3, 4, 5 (implementation) |
| `CMakeLists.txt` | Phase 7 |
| `{PluginName}.conf.in` | Phase 6 (optional) |
| `{PluginName}Implementation.h` | Phase 5C (only if plugin is OOP: PLUGIN_<NAME>_MODE = "Local" in CMakeLists.txt OR outofprocess = true in .conf.in) + holistic rules |
| `{PluginName}Implementation.cpp` | Phase 5C (only if plugin is OOP: PLUGIN_<NAME>_MODE = "Local" in CMakeLists.txt OR outofprocess = true in .conf.in) + holistic rules |

### Step 3 - Execute Rules (CRITICAL: Understand First, Then Check)

**Thunder Version Detection:**
- `namespace WPEFramework` → **pre-Thunder 5.0** plugin
- `namespace Thunder` → **Thunder 5.0+** plugin

This affects which rules apply:
- **rule_38** (COM Methods Return Core::hresult): Only applies to Thunder 5.0+ plugins. Pre-5.0 plugins correctly use `uint32_t` - do NOT flag as a violation.
- **rule_31** (No Hardcoded Paths): Linux kernel virtual filesystems (`/proc/`, `/sys/`, `/dev/`) are fixed OS paths, not deployment-specific - do NOT flag these.

**Review philosophy for ALL 84 rules:**

1. **UNDERSTAND FIRST** - Read ALL plugin source files **in full — from line 1 to end of file for every file. Never stop reading a file partway through.** Build a complete mental model of the plugin's architecture: its lifecycle flow, threading model, ownership patterns, data flow, and how Initialize/Deinitialize relate to each other. Do this ONCE before checking any rule.
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

**CRITICAL: The JUDGE step is ONLY allowed AFTER the verification logic produces a "No" answer. You MUST run the verification steps from the YAML first and get an explicit Yes/No before deciding PASS or FAIL. Never shortcut to PASS based on a quick impression — complete ALL verification logic steps before making any judgment.**

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

---

## Step 4 - Validate Findings (Eliminate False Positives)

**CRITICAL:** This step MUST be completed BEFORE generating any chat output or report file. Do NOT write findings mid-analysis and correct them later — validate silently first, then produce final output.

For every candidate finding:

1. **Re-read the actual code** at the cited line — confirm the issue genuinely exists at that exact location
2. **Re-apply the JUDGE step** — ask again: "In the full context of this plugin's architecture, lifecycle, and threading model, is this actually a bug?" If the answer is no → drop it silently
3. **Verify the line number** — ensure the citation points to the correct line, not an approximation
4. **Check for duplicates** — if two rules flag the same root cause (e.g. rule_48 and rule_60 on the same lock-held callback), keep both but note they share a fix
5. **Verify severity is NOT escalated** — the reported status MUST NOT be higher than the YAML-defined severity. A `suggestion` rule can NEVER become ❌ VIOLATION or ⚠️ WARNING. Only downgrading is allowed.
6. **Discard any finding that is:**
   - A false positive (code is actually correct in context)
   - Based on misreading the code (re-read to confirm)
   - A legitimate design choice that is safe in this plugin's context
   - Flagging code that doesn't exist at the cited line
   - Reported at a severity HIGHER than the YAML defines

**Only issues that survive this second pass are reported to the user. Never show discarded findings, self-corrections, or "Wait — actually this is fine" reasoning in any output.**

---

## Output Format

### Chat Output - Brief Summary

In chat, provide a **concise summary table** of all issues found. Do NOT output full YAML blocks in chat - keep it brief and scannable:

```
## Thunder Plugin Review - {PluginName}

| Issue No. | Status | File | Line | Issue |
|-----------|--------|------|------|-------|
| 1 | ❌ VIOLATION | Dictionary.cpp | 45 | IShell* assigned without AddRef() |
| 2 | ⚠️ WARNING | Dictionary.cpp | 108 | NULL used as null pointer |
| 3 | 💡 SUGGESTION | Module.h | 1 | MODULE_NAME missing Plugin_ prefix |
```

Followed by a note pointing to the full report file.

### Chat Output Example

```
## Thunder Plugin Review - Dictionary

| Issue No. | Status | File | Line | Issue |
|-----------|--------|------|------|-------|
| 1 | ❌ VIOLATION | Dictionary.cpp | 45 | IShell* assigned without AddRef() |
| 2 | ⚠️ WARNING | Dictionary.cpp | 108 | NULL used as null pointer |
| 3 | 💡 SUGGESTION | Module.h | 1 | MODULE_NAME missing Plugin_ prefix |

📄 Full report: `PluginQualityAdvisor/Reports/plugin/Dictionary_2026-07-16.md`
```

### Status Symbols

**CRITICAL: Always use actual Unicode emoji characters, NEVER GitHub emoji shortcodes.**
- ❌ `VIOLATION` - blocking issue, must fix — use the character `❌` NOT `:x:`
- ⚠️ `WARNING` - should fix — use the character `⚠️` NOT `:warning:`
- 💡 `SUGGESTION` - optional improvement — use the character `💡` NOT `:bulb:`

GitHub shortcodes (`:x:`, `:warning:`, `:bulb:`) do NOT render in VS Code Markdown Preview and appear as raw text.

End chat output with:
```
📄 Full report saved: PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.md
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions
```

---

## Key Advantages

- **Reproducible:** Same bounded questions → same answers on the same code
- **Fast:** One code block per checkpoint - no whole-file analysis per rule
- **Actionable:** Each failure has an exact line, an explanation, and a fix
- **Contextual:** Severity downgrade logic handles valid alternative approaches

## Important Notes

1. Load `thunder-plugin-rules.yaml` at the start of every review run - rules may have been updated
2. Never embed rule data in this prompt - always load from YAML at runtime
3. If a plugin is not found, search the entire workspace before asking the user
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

## Step 6 - Generate Markdown Report

After reporting all results in chat, generate a Markdown report file with clickable navigation.
/thunder-plugin-review NetworkControl Module.h
**File path:** `PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.md`

- Create `PluginQualityAdvisor/Reports/plugin/` if it does not exist
- Never overwrite an existing file - append `_2`, `_3` etc. if a file with that name already exists

### Report Template

```markdown
# Thunder Plugin Review - {PluginName}

**Date:** {YYYY-MM-DD}  
**Plugin:** {PluginName}  
**Total Rules:** 84 | **Passed:** N | **Failed:** N | **Skipped:** N

---

## Issue Summary

| Issue No. | Status | Rule | File | Line | Issue |
|-----------|--------|------|------|------|-------|
| 1 | ❌ VIOLATION | [rule_17 - AddRef on IShell*](#issue-1) | Dictionary.cpp | 45 | IShell* assigned without AddRef() |
| 2 | ⚠️ WARNING | [rule_06 - NULL vs nullptr](#issue-2) | Dictionary.cpp | 108 | NULL used as null pointer |
| 3 | 💡 SUGGESTION | [rule_01 - MODULE_NAME Prefix](#issue-3) | Module.h | 1 | MODULE_NAME missing Plugin_ prefix |

---

## Detailed Findings

### Issue 1

**rule_17 - AddRef on IShell***  
**Status:** ❌ VIOLATION | **File:** `Dictionary.cpp` | **Line:** 45

**What's wrong:**  
The `IShell*` pointer is stored as a member variable without calling `AddRef()`. This can lead to a dangling pointer if the framework releases the object while the plugin still holds a reference.

**Code found:**
```

// Dictionary.cpp:45
_service = service;
// AddRef() not called - pointer may become dangling
```

**Fix:**

```cpp
_service = service;
_service->AddRef();  // prevent dangling pointer
```

---

### Issue 2

**rule_06 - NULL vs nullptr**  
**Status:** ⚠️ WARNING | **File:** `Dictionary.cpp` | **Line:** 108

**What's wrong:**  
C++ code should use `nullptr` instead of the C macro `NULL` for null pointer values. `nullptr` is type-safe and avoids ambiguity with integer 0.

**Code found:**

```cpp
// Dictionary.cpp:108
IPlugin* plugin = NULL;
```

**Fix:**

```cpp
IPlugin* plugin = nullptr;
```

---

### Issue 3

**rule_01 - MODULE_NAME Plugin_ Prefix**  
**Status:** 💡 SUGGESTION | **File:** `Module.h` | **Line:** 1

**What's wrong:**  
The `MODULE_NAME` macro should use the `Plugin_` prefix convention for consistency across Thunder plugins.

**Code found:**

```cpp
// Module.h:1
#define MODULE_NAME Dictionary
```

**Fix:**

```cpp
#define MODULE_NAME Plugin_Dictionary
```

```

---

## Skipped Rules

| Rule | Reason |
|------|--------|
| rule_32 - OOP Connection Termination | Plugin is in-process (no PLUGIN_MODE = "Local" in CMakeLists.txt and no outofprocess = true in .conf.in) |
| rule_33 - connectionId Checked | Plugin is in-process |
| rule_34 - Configuration Class | No .conf.in file present |

```

### Report Generation Rules

- Each issue in the summary table links to its detailed section via the Rule column using `[rule_XX - Name](#issue-N)` anchors
- Each detailed section heading uses `### Issue N` (creates the `#issue-n` anchor automatically)
- The rule ID and name appear as bold text on the first line under the heading (e.g. `**rule_17 - AddRef on IShell***`)
- **"What's wrong"** must be a plain-English explanation a junior developer can understand - not just restating the rule name
- **"Code found"** must show the actual code from the plugin with file:line comment
- **"Fix"** must show the corrected code with a brief comment explaining the change
- If severity was downgraded (JUDGE step), add a **"Note:"** paragraph after the fix explaining why
- Issues are ordered by severity: VIOLATIONS first, then WARNINGS, then SUGGESTIONS
- After Detailed Findings, include a **Skipped Rules** table listing rules that were not applicable and why
- UTF-8 encoding, LF line endings

**If no issues found**, generate:

```markdown
# Thunder Plugin Review - {PluginName}

**Date:** {YYYY-MM-DD}  
**Plugin:** {PluginName}  
**Total Rules:** 84 | **Passed:** N | **Failed:** 0 | **Skipped:** N

✅ All rules passed - no issues found.
```

**Post-generation message in chat:**
```
📄 Full report saved:
   PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.md
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions
```

### Post-Generation Action

**CRITICAL: Write report via terminal to avoid VS Code editor buffer conflicts.**

1. **Write the file using terminal** — do NOT use create_file or file editing tools for the report. Use:

```powershell
   [System.IO.File]::WriteAllText("<full-path-to-report>.md", $content, [System.Text.UTF8Encoding]::new($false))
```

This bypasses VS Code's editor buffer which can overwrite content with an empty file.

2. **Verify the file is not empty** — after writing, check the file size:

```powershell
   (Get-Item "<full-path-to-report>.md").Length
```

If the size is 0, the write failed — retry once.

3. **Open in Markdown Preview** — run VS Code command `markdown.showPreview` on the generated report file so anchor links work and the user sees a navigable report with clickable issue links.

4. **Do NOT open the report in the editor** — opening `.md` files in the editor triggers notebook mode which creates an unwanted `codebook-md/` config folder and tries to execute code blocks. Always use preview-only.