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

**Mandatory gate:** Before proceeding to Step 2, state: "Rules loaded: [N]. Last rule ID loaded: [rule_id]." If N < 84, re-read the YAML from the truncation point before continuing.

All rules produce the same output format. There is no distinction between "phase checkpoint" and "holistic" in the report.

### Step 2 - Identify Plugin Files

Search the workspace for a folder named `{PluginName}` (e.g. `ThunderNanoServices/{PluginName}/`).
If not found: Ask user for location.

**Canonical reading order** (always read files in this sequence to ensure consistent context loading):
1. `Module.h`
2. `Module.cpp`
3. `{PluginName}.h`
4. `{PluginName}.cpp`
5. `{PluginName}Implementation.h` (if present — not OOP-only; in-process plugins can also have an implementation file)
6. `{PluginName}Implementation.cpp` (if present — not OOP-only; in-process plugins can also have an implementation file)
7. `CMakeLists.txt`
8. `{PluginName}.conf.in` (if present)
9. All remaining `.h` files (alphabetical) — **including subdirectories**
10. All remaining `.cpp` files (alphabetical) — **including subdirectories**

**Read every `.h` and `.cpp` under the plugin folder including all subdirectories** (e.g. `legacy/`, `src/`, `impl/`, helper headers). Issues like hardcoded paths, NULL usage, printf calls, and shared-state races are often only visible in helper files, not the primary plugin files.

**CRITICAL: Read every file from line 1 to the last line — never stop partway through a file.** Partial reads miss issues in later sections (e.g. Deinitialize(), background thread functions, helper methods). If a file is large, continue reading until you reach the end before moving to the next file.

**Mandatory gate:** After reading all files, state: "Files read: [list each filename]. Total: [N] files." Do NOT begin rule execution until this inventory is confirmed.

| File | Phase relevance |
|------|----------------|
| `Module.cpp` | Phase 1 (rule_02) |
| `Module.h` | Phase 1 (rule_01, rule_03) |
| `{PluginName}.h` | Phase 2, 3, 4 (class declarations) |
| `{PluginName}.cpp` | Phase 2, 3, 4, 5 (implementation) |
| `{PluginName}Implementation.h` | Phase 5C (OOP rules) + holistic rules — always read if present, not limited to OOP plugins |
| `{PluginName}Implementation.cpp` | Phase 5C (OOP rules) + holistic rules — always read if present, not limited to OOP plugins |
| `CMakeLists.txt` | Phase 7 |
| `{PluginName}.conf.in` | Phase 6 (optional) |

### Step 3 - Execute Rules (CRITICAL: Understand First, Then Check)

**Thunder Version Detection:**
- `namespace WPEFramework` → **pre-Thunder 5.0** plugin
- `namespace Thunder` → **Thunder 5.0+** plugin

**Completeness sweep — after applying all 84 rules, perform these explicit checks across ALL files:**

> **Semantic reasoning still applies to every sweep match.** The sweep ensures patterns are not *missed* — it does not bypass the JUDGE step. Each match found below must be evaluated in full context before being reported: test files, generated code, comments, string literals, and platform-specific shims may make a pattern acceptable. Apply the same understand-first, reason-in-context logic as for all other rules.

- **rule_06** (NULL vs nullptr): search for `= NULL`, `== NULL`, `!= NULL`, `( NULL)`, `NULL,`, `NULL)` — review each match in context and report only confirmed uses of `NULL` as a pointer literal in code (exclude comments and string literals)
- **rule_17** (IShell AddRef): confirm `_service->AddRef()` is the very next line after `_service = service` in `Initialize()` — check the actual source, do not assume
- **rule_18** (IShell Release): confirm `_service->Release()` and `_service = nullptr` both appear in `Deinitialize()` — check every exit path
- **rule_31** (Hardcoded paths): search every file for `/tmp/`, `/opt/`, `/etc/`, `/usr/`, `/var/` — flag each occurrence not under `/proc/`, `/sys/`, or `/dev/`
- **rule_39** (#pragma once): check every `.h` file — flag any that use `#ifndef`/`#define`/`#endif` guard instead of `#pragma once`
- **rule_41** (Reverse-order cleanup): list acquisition order in `Initialize()`; verify `Deinitialize()` releases in strict reverse; `service->Unregister()` must be FIRST
- **rule_47** (Shared state): list every member variable assigned inside a callback, event handler, or non-main thread; confirm each has a lock guard — do not stop at the first unprotected variable
- **rule_54** (Core::ERROR_* return values): search for `return 0;` and `return 1;` inside every method whose return type is `uint32_t` or `Core::hresult` — flag each raw integer return
- **rule_55** (Event constants): search every file for `Notify(_T("` or `Notify("` — flag every inline string event name that is not a named constant
- **rule_63** (hresult return values checked): scan all calls to `Core::hresult`-returning methods — confirm the return value is stored and tested, not silently discarded
- **rule_70** (No printf): search for `printf(`, `fprintf(`, `sprintf(`, `snprintf(` in every file including helper headers
- **rule_73** (PluginSmartInterfaceType): list all member variables that are raw `I*` pointers to another plugin's interface, or use `RPC::SmartInterfaceType` — each should use `PluginSmartInterfaceType`
- **rule_74** (WorkerPool): list all uses of `std::thread`, `pthread_create`, or similar raw thread spawning — each should use `Core::WorkerPool` instead
- **rule_83** (No heavy work in Initialize): from `Initialize()` and `Configure()`, follow every function call one level deep and check whether any called function contains a loop with `sleep`, `usleep`, `std::this_thread::sleep`, a retry counter, or a blocking I/O call
- **rule_40** (Copyright header): check the first 15 lines of every `.h` and `.cpp` file — flag any file that does not contain an Apache 2.0 copyright header
- **rule_12** (No delete this): search every `.cpp` file for `delete this` — flag every occurrence; plugin lifetime is framework-managed
- **rule_71** (No ILocalDispatcher): search every file for `ILocalDispatcher` — flag every usage; ILocalDispatcher bypasses security token validation
- **rule_76** (No IController::Persist): search every file for `->Persist(` — flag every call; Persist() is disabled in non-debug builds
- **rule_77** (No direct curl): search every file for `curl_`, `#include.*curl`, `CURL*` — flag any direct libcurl usage
- **rule_78** (No process spawning): search every file for `popen(`, `system(`, `fork(`, `exec(`, `execve(`, `execvp(` — flag each occurrence
- **rule_79** (No hardcoded callsigns): search every file for string literals containing `"org.rdk.`, `"org.metrological.`, or any other hardcoded plugin callsign — flag each one; callsigns must come from configuration
- **rule_81** (Core::GetEnvironment): search every file for `getenv(`, `setenv(`, `putenv(` — flag each; use `Core::GetEnvironment()` / `Core::SetEnvironment()` instead
- **rule_82** (No sleep anywhere): search every file for `sleep(`, `usleep(`, `std::this_thread::sleep_for(`, `std::this_thread::sleep_until(` — flag every occurrence, not just inside Initialize()
---

## CRITICAL FILE SCOPING RULES

- **Phase 1** (Module Structure) applies ONLY to `Module.h` and `Module.cpp` - never to the main plugin class files
- **Phase 3** (Class Registration) applies ONLY to the **main plugin class** (the one implementing `PluginHost::IPlugin`) - internal helper classes (Notification, Sink, Config, etc.) are explicitly excluded

---

## Contextual Judgment (JUDGE step)

**CRITICAL: The JUDGE step is ONLY allowed AFTER the verification logic produces a "No" answer. You MUST run the verification steps from the YAML first and get an explicit Yes/No before deciding PASS or FAIL. Never shortcut to PASS based on a quick impression — complete ALL verification logic steps before making any judgment.**

**CRITICAL: Downgrade ≠ Discard.** A downgraded finding MUST still appear in the report at its reduced severity. Never silently drop a finding that genuinely violates a rule — even if the developer's approach is reasonable, report it at the lower level so the developer is aware of the trade-off. Only discard when the rule's concern is entirely absent from the code (true false positive: the code is factually correct and the rule simply does not apply).

**Downgrade evidence requirement:** When downgrading severity, the `reasoning` field MUST cite the specific `[File:line]` that provides the mitigating evidence. Abstract reasoning without a code citation is NOT sufficient grounds for a downgrade — if you cannot point to a specific line, do not downgrade.

Severity is **never escalated** above the YAML-defined level. Downgrade one severity level when the developer's approach is valid in context — but always report the finding at the reduced level; never silently discard it. **The JUDGE step can never produce a PASS result — it can only downgrade severity.** If verification logic says "No", the finding must appear in the report at some severity level. Only omit a finding entirely when the rule's concern is factually absent from the code (the code is genuinely correct and the rule simply does not apply — this is a true skip, not a JUDGE outcome). The `reasoning` field is **required** when severity is downgraded; omit it when no downgrade occurs.

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

- **Targeted:** Bounded questions focus analysis on specific constructs, reducing missed findings
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
**File path:** `PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.md`

- Create `PluginQualityAdvisor/Reports/plugin/` if it does not exist
- Never overwrite an existing file - append `_2`, `_3` etc. if a file with that name already exists

**Git Metadata (run before generating the report):**  
Run the following commands in the plugin's git root to populate the report header fields:
- Repo URL: `git remote get-url origin`
- Branch: `git rev-parse --abbrev-ref HEAD`
- Commit SHA: `git rev-parse --short HEAD`
If git is unavailable, use `unknown`.

### Report Template

```markdown
# Thunder Plugin Review - {PluginName}

**Date:** {YYYY-MM-DD}  
**Plugin:** {PluginName}  
**Repo:** {plugin-repo-url}  
**Branch:** {plugin-branch} | **Commit:** {plugin-sha}  
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
- Each detailed section must end with a back-link to the summary table: `[\u2B06 Back to Issue Summary](#issue-summary)` — this allows readers to click back to the table after reading a finding
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
**Repo:** {plugin-repo-url}  
**Branch:** {plugin-branch} | **Commit:** {plugin-sha}  
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