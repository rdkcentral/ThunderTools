# Spec: Thunder PluginQualityAdvisor Report Generation

## Purpose

After every `/thunder-plugin-review` or `/thunder-interface-review` run, the system generates a self-contained HTML report file with an Issue Summary table and Detailed Findings sections with clickable navigation and syntax-highlighted code blocks.

---

## Requirements

### REQ-R1 — Plugin review HTML report

**Scenario:** `/thunder-plugin-review` completes all 84 rules
- The system MUST generate an HTML file at:
  `ThunderTools/PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.html`
- If a file with that name already exists, append `_2`, `_3` etc. (never overwrite)
- The report MUST contain: header with totals, Issue Summary table, and Detailed Findings sections
- PASS and SKIP rules are NOT included — only VIOLATION, WARNING, and SUGGESTION

### REQ-R2 — Interface review HTML report

**Scenario:** `/thunder-interface-review` completes all 19 rules
- The system MUST generate an HTML file at:
  `ThunderTools/PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.html`
- Same no-overwrite rule applies
- Same structure: header, Issue Summary table, Detailed Findings

### REQ-R3 — Report header

The report MUST start with:

```html
<!-- Thunder Plugin Review - {PluginName} -->

**Date:** {YYYY-MM-DD}  
**Plugin:** {PluginName}  
**Total Rules:** 84 | **Passed:** N | **Failed:** N | **Skipped:** N
```

### REQ-R4 — Issue Summary table

The report MUST contain an Issue Summary table with clickable navigation:

| Column | Description |
|--------|-------------|
| Issue No. | Sequential number |
| Status | ❌ VIOLATION / ⚠️ WARNING / 💡 SUGGESTION (Unicode emoji, never GitHub shortcodes) |
| Rule | Clickable link: `<a href="#issue-N">rule_id - Name</a>` navigating to detailed section |
| File | Source file name |
| Line | Exact line number |
| Issue | Short description |

### REQ-R5 — Detailed Findings sections

Each issue MUST have a detailed section with:

- Heading: `<h3 id="issue-N">Issue N</h3>` (creates `#issue-n` anchor for navigation)
- Rule ID and name as bold text: `**rule_XX - Rule Name**`
- Status line: `**Status:** ❌ VIOLATION | **File:** filename | **Line:** N`
- **What's wrong:** Plain-English explanation a junior developer can understand
- **Code found:** Actual code from the file with file:line comment in a `<pre><code class="language-cpp">` block (highlight.js syntax-highlighted)
- **Fix:** Corrected code in a `<pre><code class="language-cpp">` block
- If severity was downgraded: **Note:** paragraph explaining why

Issues MUST be ordered by severity: VIOLATIONS first, then WARNINGS, then SUGGESTIONS.

### REQ-R6 — Folder creation

- `ThunderTools/PluginQualityAdvisor/Reports/plugin/` and `ThunderTools/PluginQualityAdvisor/Reports/interface/`
  MUST be created if they do not exist before writing the file

### REQ-R7 — File writing and post-generation

- The report MUST be written via terminal (`[System.IO.File]::WriteAllText`) to avoid VS Code editor buffer conflicts
- After writing, the file size MUST be verified (non-zero)
- The report MUST be opened in a browser or VS Code Simple Browser (`simpleBrowser.show`), NOT in the editor
- The editor MUST NOT open the file directly (shows raw HTML)

Post-generation chat message:
```
📄 Full report saved:
   PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.html
   {N} issue(s) - {violations} violations, {warnings} warnings, {suggestions} suggestions
```

### REQ-R8 — Empty report (all PASS)

If no issues were found, generate:

```html
<!-- Thunder Plugin Review - {PluginName} -->

**Date:** {YYYY-MM-DD}  
**Plugin:** {PluginName}  
**Total Rules:** 84 | **Passed:** N | **Failed:** 0 | **Skipped:** N

✅ All rules passed - no issues found.
```

---

## Folder structure

```
ThunderTools/PluginQualityAdvisor/
└── Reports/
    ├── plugin/
    │   ├── Dictionary_2026-07-16.html
    │   └── NetworkControl_2026-07-16.html
    └── interface/
        ├── INetworkControl_2026-07-16.html
        └── IDictionary_2026-07-16.html
```

---

## Out of Scope

- CSV or Excel format
- Report viewer command (Markdown Preview is sufficient)
- Diff between two reports (future)
- Automatic email or CI upload (future)
