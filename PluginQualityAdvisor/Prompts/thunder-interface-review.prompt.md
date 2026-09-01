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
2. **Load** — load `PluginQualityAdvisor/rules/thunder-interface-rules.yaml`, resolved relative to the `PluginQualityAdvisor` folder this prompt file itself lives in (the folder registered via `chat.promptFilesLocations`) — **not** via a workspace-wide file search. The interface source repo open in the current workspace does not contain the `PluginQualityAdvisor` tool folder; searching for it there will always return no matches even though the file exists. Actually check for the file at that resolved location rather than assuming; if, after genuinely checking there, it is not there, do not fabricate or recall rule content from memory — stop and report to the user that `thunder-interface-rules.yaml` could not be found, rather than proceeding with assumed rules.
2b. **Load Exemptions** — do not assume this file is missing; actually check. Read `PluginQualityAdvisor/Exemptions/thunder-interface-exemptions.local.yaml`, resolved relative to the same `PluginQualityAdvisor` folder as the rules YAML above — **not** via a workspace-wide file search, since the interface source repo open in the current workspace does not contain that folder. Perform a real file check at that resolved location and, if it exists, actually open and read its full contents — do not skip this step or default to "not found" because the file is commonly absent on a fresh clone. If the `Exemptions/` folder or the file genuinely does not exist at that location, do **not** create it — simply treat all rules as not exempted and continue.
    Resolve which rules are exempted for `{InterfaceName}`: an entry applies if its `rule_id` (or every rule in its `category`) matches, AND its `scope` is `"global"` or includes `{InterfaceName}` by name. This is a lookup only — it does not remove any rule from validation in the next step.
3. **Validate** the interface against All 19 Rules in order (core_1_1 → core_16_1, then advisory_m1_1 → advisory_m3_1) — every rule runs in full regardless of exemption status (see "## Step 3 - Execute Rules" below)
4. **Report** using the Issue Summary table format below
5. **Provide** specific fix examples using the `fix_template` from the YAML

For each rule, apply contextual judgment (JUDGE step): if the developer's approach technically violates a rule but is valid and reasonable in their specific context, downgrade the severity and populate the `Reasoning` field.

**Exemption check runs after JUDGE, never before:** once a rule's effective status is finalized, check the Step 2b exemption lookup. PASS/SKIP are unaffected. A VIOLATION/WARNING/SUGGESTION for a rule exempted for `{InterfaceName}` is reclassified `EXEMPT` and routed to the Exempted Findings section instead of the Issue Summary — never dropped, never left out of the report, and never used to shortcut running the rule in the first place.

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

📄 Full report: `PluginQualityAdvisor/Reports/interface/IHdmiCecSink_2026-07-16.html`
```

### Status Symbols

**CRITICAL: Always use actual Unicode emoji characters, NEVER GitHub emoji shortcodes.**
- ❌ `VIOLATION` - blocking issue, must fix — use the character `❌` NOT `:x:`
- ⚠️ `WARNING` - should fix — use the character `⚠️` NOT `:warning:`
- 💡 `SUGGESTION` - optional improvement — use the character `💡` NOT `:bulb:`
- 🔕 `EXEMPT` - reclassified from a real failure via a local exemption (see Contextual Judgment /
  Exemption Check below). Never shown in the main Issue Summary table, only in Exempted Findings.

End chat output with, **if there are no exempted findings**:
```
📄 Full report saved: PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.html
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions
```

**If one or more findings were exempted**, add the exempted count:
```
📄 Full report saved: PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.html
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions (+{E} exempted findings — see report)
```

**Always** end with, regardless of whether anything was exempted this run:
```
💬 To exempt an interface finding, run: python PluginQualityAdvisor/exempt_manager.py --rule-set interface add {rule_id} --scope {InterfaceName}
```

---

## Step 6 - Generate HTML Report

After reporting results in chat, generate an HTML report file with clickable navigation and syntax-highlighted code blocks.

**File path:** `PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.html`

- Create `PluginQualityAdvisor/Reports/interface/` if it does not exist
- Never overwrite an existing file - append `_2`, `_3` etc. if needed

**Git Metadata (run before generating the report):**  
Run the following command in the interface file's git root to get the repo URL:
- Repo URL: `git remote get-url origin`
If git is unavailable, use `unknown`.

**HTML shell (wrap the entire report content in this):**

```html
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Thunder Interface Review - {InterfaceName}</title>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/styles/github.min.css">
<script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/highlight.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/languages/cmake.min.js"></script>
<script>hljs.highlightAll();</script>
<style>
  body { font-family: sans-serif; max-width: 1100px; margin: 40px auto; padding: 0 20px; color: #24292f; line-height: 1.6; }
  h1 { border-bottom: 2px solid #d0d7de; padding-bottom: 10px; }
  h2 { border-bottom: 1px solid #d0d7de; padding-bottom: 6px; margin-top: 40px; }
  h3 { margin-top: 30px; }
  table { border-collapse: collapse; width: 100%; margin: 16px 0; }
  th, td { border: 1px solid #d0d7de; padding: 8px 12px; text-align: left; }
  th { background: #f6f8fa; font-weight: 600; }
  tr:nth-child(even) { background: #f6f8fa; }
  pre { background: #f6f8fa; border: 1px solid #d0d7de; border-radius: 6px; padding: 16px; overflow-x: auto; }
  code { font-family: monospace; font-size: 13px; }
  .back-link { font-size: 13px; color: #0969da; }
</style>
</head>
<body>
<!-- report content here -->
</body>
</html>
```

### Report Template

```markdown
# Thunder Interface Review - {InterfaceName}

**Date:** {YYYY-MM-DD}  
**Interface:** {InterfaceName}  
**Repo:** {repo-url}  
**Total Rules:** 19 | **Passed:** N | **Failed:** N | **Skipped:** N | **Exempted:** N

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

---

## Exempted Findings

*Only present if one or more rules failed AND are exempted for {InterfaceName} in
`Exemptions/thunder-interface-exemptions.local.yaml`. Omit this entire section if there are none — do
not render an empty table.*

**Table only — no per-finding detail blocks, no "What's wrong"/"Code found"/"Fix" expansion, and no
Exemption Reason column** — exemptions have no reason field at all. Keep each row to one short line:

| Rule | Status | File | Line | Issue |
|------|--------|------|------|-------|
| advisory_m2_1 - Enum Underlying Types | 🔕 EXEMPT (would be ⚠️ WARNING) | IHdmiCecSink.h | 30 | Named enum used as a parameter has no explicit underlying type |
| core_13_1 - Explicit Integer Widths | 🔕 EXEMPT (would be ⚠️ WARNING) | IHdmiCecSink.h | 72 | int parameter instead of uint32_t |

The **Issue** column is a short, single-line plain-English description of what's wrong — the same
level of brevity as the main Issue Summary table's Issue column, not a restatement of the rule name.
```

```markdown
# Thunder Interface Review - {InterfaceName}

**Date:** {YYYY-MM-DD}  
**Interface:** {InterfaceName}  
**Repo:** {repo-url}  
**Total Rules:** 19 | **Passed:** N | **Failed:** 0 | **Skipped:** N | **Exempted:** 0

✅ All rules passed - no issues found.
```

**If there are no blocking issues but one or more exempted findings exist**, keep the Exempted Findings
section — a run is never "all clear" purely because nothing is currently blocking.

**Post-generation message in chat:**
```
📄 Full report saved:
   PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.html
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions
```
Append `(+{E} exempted findings — see report)` after the counts if `E > 0`. Always follow with:
```
💬 To exempt an interface finding, run: python PluginQualityAdvisor/exempt_manager.py --rule-set interface add {rule_id} --scope {InterfaceName}
```

### Post-Generation Action

**CRITICAL: Write report via terminal to avoid VS Code editor buffer conflicts.**

1. **Write the file using terminal** — do NOT use create_file or file editing tools for the report. Use:

```powershell
   [System.IO.File]::WriteAllText("<full-path-to-report>.html", $content, [System.Text.UTF8Encoding]::new($false))
```

2. **Verify the file is not empty** — after writing, check the file size:

```powershell
   (Get-Item "<full-path-to-report>.html").Length
```

If the size is 0, the write failed — retry once.

3. **Open in browser** — run VS Code command `simpleBrowser.show` with the file URI, or open the `.html` file in a browser. highlight.js renders syntax highlighting and anchor links work natively.

4. **Do NOT open the report in the VS Code editor** — the editor shows raw HTML. Always open in browser or Simple Browser preview.

---

## Contextual Judgment (JUDGE step)

**CRITICAL: The JUDGE step is ONLY allowed AFTER the verification logic produces a "No" answer. You MUST run the verification steps from the YAML first and get an explicit Yes/No before deciding PASS or FAIL. Never shortcut to PASS based on a quick impression — complete ALL verification logic steps before making any judgment.**

| Scenario | Status field | Reasoning field |
|----------|-------------|-----------------|
| Rule satisfied | `PASS` | Omit |
| Rule violated, no mitigation | `VIOLATION` / `WARNING` / `SUGGESTION` | Omit |
| Rule technically violated but developer's approach is valid | Downgrade one level | **Required** |

Severity is **never escalated** above the YAML-defined level.

**Exemption Check (runs after this table, on every rule, never before):** once a rule's effective
status is finalized above, check the Step 2b exemption lookup built during "Load Exemptions." PASS and
SKIP are unaffected. A `VIOLATION`/`WARNING`/`SUGGESTION` for a rule exempted for `{InterfaceName}` is
reclassified `EXEMPT` and routed to the Exempted Findings section instead of the Issue Summary, as a
single short table row (rule, status, file, line, one-line issue description) — no expanded detail
block. Exemptions have no reason field at all. This can only move a finding to a different section of
the report, never delete it — an exempted violation still appears in the output, just not in the
blocking Issue Summary table.

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