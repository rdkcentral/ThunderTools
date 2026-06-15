# Spec: Thunder PluginQA Report Generation

## Purpose

After every `/thunder-plugin-review` or `/thunder-interface-review` run, the system generates a
single CSV report file. The CSV is Excel-compatible and contains one row per issue found,
with all fields needed to understand, prioritise, and track fixes.

---

## Requirements

### REQ-R1 — Plugin review CSV

**Scenario:** `/thunder-plugin-review` completes all 79 rules
- The system MUST generate a CSV file at:
  `ThunderTools/PluginQA/Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv`
- If a file with that name already exists, append `_2`, `_3` etc. (never overwrite)
- The CSV MUST contain one header row followed by one data row per FAIL or WARNING or SUGGESTION
- PASS and SKIP rows are NOT included in the CSV (they appear only in the phase summary in chat)

### REQ-R2 — Interface review CSV

**Scenario:** `/thunder-interface-review` completes all 19 rules
- The system MUST generate a CSV file at:
  `ThunderTools/PluginQA/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.csv`
- Same no-overwrite rule applies
- One row per violated rule only

### REQ-R3 — Plugin CSV columns (exact, in order)

```
No,Plugin,Date,Phase,Rule_ID,Rule_Name,Status,Severity,File,Line,Citation,Issue_Description,Fix_Summary,Reasoning
```

| Column | Description | Example |
|---|---|---|
| No | Row number starting at 1 | `1` |
| Plugin | Plugin name from command argument | `HdmiCecSink` |
| Date | ISO date of review | `2026-06-05` |
| Phase | Full phase label | `Phase 2 — Code Style` |
| Rule_ID | Sequential rule ID | `rule_09` |
| Rule_Name | Rule name | `NULL vs nullptr` |
| Status | Effective status after JUDGE step | `VIOLATION` / `WARNING` / `SUGGESTION` |
| Severity | YAML severity level | `violation` / `warning` / `suggestion` |
| File | Source file where issue was found | `HdmiCecSinkImplementation.cpp` |
| Line | Exact line number | `128` |
| Citation | Short citation string | `[HdmiCecSinkImplementation.cpp:128]` |
| Issue_Description | What was found | `NULL used instead of nullptr` |
| Fix_Summary | One-line fix description | `Replace NULL with nullptr` |
| Reasoning | Populated only when severity was downgraded; empty otherwise | `` |

### REQ-R4 — Interface CSV columns (exact, in order)

```
No,Interface,Date,Rule_ID,Rule_Name,Status,Severity,File,Line,Citation,Issue_Description,Fix_Summary,Reasoning
```

| Column | Description | Example |
|---|---|---|
| No | Row number starting at 1 | `1` |
| Interface | Interface filename without extension | `IHdmiCecSink` |
| Date | ISO date of review | `2026-06-05` |
| Rule_ID | YAML rule id | `core_12_1` |
| Rule_Name | Rule name | `@json tag (CRITICAL)` |
| Status | `VIOLATION` / `WARNING` / `SUGGESTION` | `VIOLATION` |
| Severity | YAML severity | `violation` |
| File | Interface file | `IHdmiCecSink.h` |
| Line | Exact line number | `45` |
| Citation | Short citation string | `[IHdmiCecSink.h:45]` |
| Issue_Description | What was found | `@json tag missing above struct declaration` |
| Fix_Summary | One-line fix | `Add // @json 1.0.0 above struct EXTERNAL` |
| Reasoning | Populated only on severity downgrade; empty otherwise | `` |

### REQ-R5 — CSV formatting rules

- Comma-separated, UTF-8, no BOM
- Fields containing commas MUST be wrapped in double quotes: `"Phase 2 — Code Style"`
- Fields containing double quotes MUST escape them as `""`: `"Use ""nullptr"" not NULL"`
- No trailing commas
- Line ending: CRLF (Windows Excel compatible)
- Empty fields: leave blank (two consecutive commas: `,,`)

### REQ-R6 — Folder creation

- `ThunderTools/PluginQA/Reports/plugin/` and `ThunderTools/PluginQA/Reports/interface/`
  MUST be created if they do not exist before writing the file

### REQ-R7 — Post-generation message

After saving the CSV, the prompt MUST display in chat:

```
📊 Report saved:
   ThunderTools/PluginQA/Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv
   {N} issue(s) logged — {violations} violations, {warnings} warnings, {suggestions} suggestions

To open in Excel (Windows):
   Start-Process "ThunderTools\PluginQA\Reports\plugin\{PluginName}_{YYYY-MM-DD}.csv"
```

### REQ-R8 — Empty report (all PASS)

If no issues were found, still generate the CSV with the header row only and add a comment row:

```csv
No,Plugin,Date,Phase,Rule_ID,Rule_Name,Status,Severity,File,Line,Citation,Issue_Description,Fix_Summary,Reasoning
,,,,,,,,,,,,,"All checkpoints passed — no issues found"
```

---

## Folder structure

```
ThunderTools/PluginQA/
└── Reports/
    ├── plugin/
    │   ├── HdmiCecSink_2026-06-05.csv
    │   ├── Dictionary_2026-06-05.csv
    │   └── NetworkControl_2026-06-05.csv
    └── interface/
        ├── IHdmiCecSink_2026-06-05.csv
        └── IDictionary_2026-06-05.csv
```

---

## Out of Scope

- `.xlsx` format (CSV opens natively in Excel — no library dependency needed)
- Report viewer command (VS Code file explorer is sufficient)
- Diff between two reports (Excel handles this)
- Automatic email or CI upload (future)