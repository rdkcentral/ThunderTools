## Context

Thunder uses COM-style interfaces defined in interface header files (commonly in `ThunderInterfaces/interfaces/` or similar paths). These interfaces are binary contracts used across process boundaries. All validation uses semantic reasoning - the validator reads the interface header in full as a human reviewer would, never using regex or text search as the primary detection method.

Rules are loaded at runtime from: `PluginQualityAdvisor/rules/thunder-interface-rules.yaml`

---

## Quick Reference - All 19 Rules

| ID | Rule | Key Point |
|----|------|-----------|
| core_1_1 | File Structure | File name matches interface name; no implementation code (suggestion) |
| core_2_1 | Interface Declaration Shape | struct EXTERNAL, virtual Core::IUnknown, ID enum, all pure virtual (warning) |
| core_3_1 | Interface ID Registration | ID must be RPC::ID_* constant registered in ids.h |
| core_4_1 | Pure Virtual Methods Only | All methods = 0, no inline code, no static methods (warning) |
| core_5_1 | Return Type Conventions | Core::hresult mandatory for @json interfaces in Thunder 5.0+; notification methods MUST return void |
| core_6_1 | Const Correctness | @out params must be non-const refs; notification methods must NEVER be const |
| core_7_1 | Thunder Type Conventions | string not std::string; explicit integer widths |
| core_8_1 | Register/Unregister Patterns | INotification: Register+Unregister; ICallback: Callback(nullptr clears) |
| core_9_1 | Event Interfaces | @event tag required; EXTERNAL; own ID; inherits Core::IUnknown |
| core_10_1 | @json Tag (CRITICAL) | Without @json, ZERO RPC code generated (warning; check for @alias/@text hints) |
| core_11_1 | No IUnknown/IReferenceCounted Methods in Interfaces | Inherited from Core::IUnknown - never redeclare |
| core_12_1 | No std::map in Interfaces | Not serialisable across process boundaries |
| core_13_1 | Explicit Integer Widths | uint32_t not int; no platform-dependent types |
| core_14_1 | @restrict Mandatory with std::vector | Every std::vector parameter must have @restrict:N |
| core_15_1 | No Method Overloads in @json Interfaces | JSON-RPC dispatches by name only; check @text for collisions |
| core_16_1 | No Reserved JSON-RPC Method Names | version/versions/exists are reserved by framework |
| advisory_m1_1 | Single Responsibility Principle | One coherent purpose per interface |
| advisory_m2_1 | Enum Underlying Types | Named enums used as params need explicit type; anonymous ID enum excluded |
| advisory_m3_1 | No Exceptions | No throw; use Core::hresult for errors |

---

> **CRITICAL:** Load `PluginQualityAdvisor/rules/thunder-interface-rules.yaml` before validating. The YAML contains the full rule definitions, extraction logic, verification logic, and fix templates. This quick reference is a navigation aid only.

---

## Your Task

1. **Identify** the interface file to validate (from user's command or ask if not provided)
2. **Load** `PluginQualityAdvisor/rules/thunder-interface-rules.yaml` for full rule definitions
3. **Validate** the interface against All 19 Rules in order (core_1_1 → core_16_1, then advisory_m1_1 → advisory_m3_1)
4. **Report** using the Issue Summary table format below
5. **Provide** specific fix examples using the `fix_template` from the YAML

For each rule, apply contextual judgment (JUDGE step): if the developer's approach technically violates a rule but is valid and reasonable in their specific context, downgrade the severity and populate the `Reasoning` field.

---

## Step 3 - Execute Rules (CRITICAL: Understand First, Then Check)

**Thunder Version Detection:**
- `namespace WPEFramework` → **pre-Thunder 5.0** interface
- `namespace Thunder` → **Thunder 5.0+** interface

This affects which rules apply:
- **core_5_1** (Return Type Conventions - Core::hresult mandatory): Only applies to Thunder 5.0+ interfaces. Pre-5.0 interfaces correctly use `uint32_t` - do NOT flag as a violation.

**Review philosophy for ALL 19 rules:**

1. **UNDERSTAND FIRST** - Read the ENTIRE interface header file. Build a complete mental model of the interface's purpose, method contracts, notification patterns, type usage, and how Register/Unregister relate to each other. Do this ONCE before checking any rule.
2. **FOCUS** - For each rule, look at the specific concern it asks about. But reason about it WITH the full context you already understand - never in isolation.
3. **REASON** - Ask the rule's question. If the specific block looks like a violation when viewed alone, ask yourself: "Does the full interface context make this approach correct and safe?" If yes → downgrade severity.
4. **CITE** - If genuinely wrong (not just technically different), cite exact `[InterfaceName.h:LINE]`
5. **FIX** - Show corrected code using `fix_template`

**Key:** A rule should FAIL only when the code is genuinely unsafe or incorrect in the context of the whole interface - not because a single block viewed in isolation doesn't match a pattern.

**CRITICAL:** Never use regex or pattern matching as the primary detection method - always use semantic understanding. Read the interface as a human reviewer would, reasoning about the meaning and intent of each declaration.

---

## Step 4 - Validate Findings (Eliminate False Positives)

**CRITICAL:** This step MUST be completed BEFORE generating any chat output or report file. Do NOT write findings mid-analysis and correct them later — validate silently first, then produce final output.

For every candidate finding:

1. **Re-read the actual code** at the cited line — confirm the issue genuinely exists at that exact location
2. **Re-apply the JUDGE step** — ask again: "In the full context of this interface's design and purpose, is this actually a problem?" If the answer is no → drop it silently
3. **Verify the line number** — ensure the citation points to the correct line, not an approximation
4. **Verify severity is NOT escalated** — the reported status MUST NOT be higher than the YAML-defined severity. A `suggestion` rule can NEVER become ❌ VIOLATION or ⚠️ WARNING. Only downgrading is allowed.
5. **Discard any finding that is:**
   - A false positive (code is actually correct in context)
   - Based on misreading the code (re-read to confirm before deciding)
   - A legitimate design choice that is valid for this interface
   - Flagging code that doesn't exist at the cited line
   - Reported at a severity HIGHER than the YAML defines

**Only issues that survive this second pass are reported to the user. Never show discarded findings, self-corrections, or "Wait — actually this is fine" reasoning in any output.**

---

## Output Format

### Chat Output - Brief Summary

In chat, provide a **concise summary table** of all issues found. Do NOT output the old grouped format — keep it brief and scannable:

```
## Thunder Interface Review - {InterfaceName}

| Issue No. | Status | Rule | File | Line | Issue |
|-----------|--------|------|------|------|-------|
| 1 | ❌ VIOLATION | core_10_1 - @json Tag | IHdmiCecSink.h | 45 | @json tag missing — ZERO JSON-RPC code generated |
| 2 | ⚠️ WARNING | core_13_1 - Explicit Integer Widths | IHdmiCecSink.h | 72 | int parameter — use uint32_t |

📄 Full report: `PluginQualityAdvisor/Reports/interface/IHdmiCecSink_2026-07-16.md`
```

### Status Symbols

**CRITICAL: Always use actual Unicode emoji characters, NEVER GitHub emoji shortcodes.**
- ❌ `VIOLATION` - blocking issue, must fix — use the character `❌` NOT `:x:`
- ⚠️ `WARNING` - should fix — use the character `⚠️` NOT `:warning:`
- 💡 `SUGGESTION` - optional improvement — use the character `💡` NOT `:bulb:`

End chat output with:
```
📄 Full report saved: PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.md
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions
```

---

## Step 6 - Generate Markdown Report

After reporting results in chat, generate a Markdown report file with clickable navigation.

**File path:** `PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.md`

- Create `PluginQualityAdvisor/Reports/interface/` if it does not exist
- Never overwrite an existing file - append `_2`, `_3` etc. if needed

**Git Metadata (run before generating the report):**  
Run the following command in the interface file's git root to get the repo URL:
- Repo URL: `git remote get-url origin`
If git is unavailable, use `unknown`.

### Report Template

```markdown
# Thunder Interface Review - {InterfaceName}

**Date:** {YYYY-MM-DD}  
**Interface:** {InterfaceName}  
**Repo:** {repo-url}  
**Total Rules:** 19 | **Passed:** N | **Failed:** N | **Skipped:** N

---

## Issue Summary

| Issue No. | Status | Rule | File | Line | Issue |
|-----------|--------|------|------|------|-------|
| 1 | ❌ VIOLATION | [core_10_1 - @json Tag](#issue-1) | IHdmiCecSink.h | 45 | @json tag missing — ZERO JSON-RPC code generated |
| 2 | ⚠️ WARNING | [core_13_1 - Explicit Integer Widths](#issue-2) | IHdmiCecSink.h | 72 | int parameter — use uint32_t |

---

## Detailed Findings

### Issue 1

**core_10_1 - @json Tag (CRITICAL)**  
**Status:** ❌ VIOLATION | **File:** `IHdmiCecSink.h` | **Line:** 45

**What's wrong:**  
Without the `@json 1.0.0` tag above the struct declaration, the Thunder JSON-RPC code generator produces ZERO output for this interface. No JSON-RPC methods, properties, or events will be available — the interface is invisible to JSON-RPC clients.

**Code found:**
```

// IHdmiCecSink.h:45
struct EXTERNAL IHdmiCecSink : virtual public Core::IUnknown {
```

**Fix:**

```cpp
// @json 1.0.0
struct EXTERNAL IHdmiCecSink : virtual public Core::IUnknown {
```

---

### Issue 2

**core_13_1 - Explicit Integer Widths**  
**Status:** ⚠️ WARNING | **File:** `IHdmiCecSink.h` | **Line:** 72

**What's wrong:**  
The `int` type is platform-dependent — it may be 16, 32, or 64 bits depending on the target architecture. COM interfaces cross process boundaries and must use explicit-width types for binary compatibility.

**Code found:**

```cpp
// IHdmiCecSink.h:72
virtual Core::hresult SetVolume(const int volume) = 0;
```

**Fix:**

```cpp
virtual Core::hresult SetVolume(const uint32_t volume) = 0;
```

```

### Report Generation Rules

- Each issue in the summary table links to its detailed section via the Rule column using `[rule_id - Name](#issue-N)` anchors
- Each detailed section heading uses `### Issue N` (creates the `#issue-n` anchor automatically)
- Each detailed section must end with a back-link to the summary table: `[\u2B06 Back to Issue Summary](#issue-summary)` — this allows readers to click back to the table after reading a finding
- The rule ID and name appear as bold text on the first line under the heading
- **"What's wrong"** must be a plain-English explanation a junior developer can understand
- **"Code found"** must show the actual code from the interface with file:line comment
- **"Fix"** must show the corrected code
- If severity was downgraded (JUDGE step), add a **"Note:"** paragraph after the fix explaining why
- Issues are ordered by severity: VIOLATIONS first, then WARNINGS, then SUGGESTIONS
- After Detailed Findings, include a **Skipped Rules** table if any rules were skipped (explaining why each was not applicable)
- UTF-8 encoding, LF line endings

**If no issues found**, generate:

```markdown
# Thunder Interface Review - {InterfaceName}

**Date:** {YYYY-MM-DD}  
**Interface:** {InterfaceName}  
**Repo:** {repo-url}  
**Total Rules:** 19 | **Passed:** N | **Failed:** 0 | **Skipped:** N

✅ All rules passed - no issues found.
```

**Post-generation message in chat:**
```
📄 Full report saved:
   PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.md
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions
```

### Post-Generation Action

**CRITICAL: Write report via terminal to avoid VS Code editor buffer conflicts.**

1. **Write the file using terminal** — do NOT use create_file or file editing tools for the report. Use:

```powershell
   [System.IO.File]::WriteAllText("<full-path-to-report>.md", $content, [System.Text.UTF8Encoding]::new($false))
```

2. **Verify the file is not empty** — after writing, check the file size:

```powershell
   (Get-Item "<full-path-to-report>.md").Length
```

If the size is 0, the write failed — retry once.

3. **Open in Markdown Preview** — run VS Code command `markdown.showPreview` on the generated report file so anchor links work.

4. **Do NOT open the report in the editor** — opening `.md` files in the editor triggers notebook mode which creates an unwanted `codebook-md/` folder. Always use preview-only.

---

## Contextual Judgment (JUDGE step)

**CRITICAL: The JUDGE step is ONLY allowed AFTER the verification logic produces a "No" answer. You MUST run the verification steps from the YAML first and get an explicit Yes/No before deciding PASS or FAIL. Never shortcut to PASS based on a quick impression — complete ALL verification logic steps before making any judgment.**

| Scenario | Status field | Reasoning field |
|----------|-------------|-----------------|
| Rule satisfied | `PASS` | Omit |
| Rule violated, no mitigation | `VIOLATION` / `WARNING` / `SUGGESTION` | Omit |
| Rule technically violated but developer's approach is valid | Downgrade one level | **Required** |

Severity is **never escalated** above the YAML-defined level.

---

## Common Critical Issues

- **Missing @json tag** - the #1 cause of "why is there no JSON-RPC for my interface?" - results in zero generated code
- **std::vector without @restrict** - required; missing @restrict produces unsafe unbounded deserialization
- **std::map in interface** - not serialisable across process boundaries; use iterators instead
- **Missing nested IDs** - INotification/ICallback without their own RPC::ID_* values
- **Ambiguous integer types** - `int` and `long` change size on different platforms; always use uint32_t etc.

---

## Important Notes

- Thunder documentation: https://rdkcentral.github.io/Thunder/
- Validation priorities: @json tag first → Core::hresult returns → @restrict on vectors → type conventions → binary compatibility → advisory rules
- Load the YAML before every validation run - rules may have been updated since this prompt was created
- Interface headers may be anywhere in the workspace — search for the filename if not found in the common `interfaces/` folder