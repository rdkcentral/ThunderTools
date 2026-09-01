# Delta for Report Generation

## ADDED Requirements

### Requirement: Plugin review generates an HTML report

After `/thunder-plugin-review` completes, the system MUST generate a self-contained HTML report at `ThunderTools/PluginQualityAdvisor/Reports/plugin/{PluginName}_{YYYY-MM-DD}.html`. If that path already exists, the system MUST append `_2`, `_3`, or another suffix and MUST NOT overwrite the existing report.

#### Scenario: Plugin review completes all rules

- GIVEN a plugin review completes all 85 rules
- WHEN the report is written
- THEN it MUST contain the header totals, an Issue Summary table for non-exempt findings, Detailed Findings sections for those findings, and an Exempted Findings table when applicable
- AND PASS and SKIP rules MUST NOT appear as individual issue details
- AND exempted findings MUST NOT receive individual Detailed Findings sections

### Requirement: Interface review generates an HTML report

After `/thunder-interface-review` completes, the system MUST generate a self-contained HTML report at `ThunderTools/PluginQualityAdvisor/Reports/interface/{InterfaceName}_{YYYY-MM-DD}.html`. If that path already exists, the system MUST append a suffix and MUST NOT overwrite the existing report.

#### Scenario: Interface review completes all rules

- GIVEN an interface review completes all 19 rules
- WHEN the report is written
- THEN it MUST contain the header totals, an Issue Summary table for non-exempt findings, Detailed Findings sections for those findings, and an Exempted Findings table when applicable
- AND PASS and SKIP rules MUST NOT appear as individual issue details
- AND exempted findings MUST NOT receive individual Detailed Findings sections

### Requirement: Report header contains complete totals

The report header MUST include the actual date, plugin or interface name, repository metadata when available, the total rule count, and counts for Passed, Failed, Skipped, and Exempted findings. Totals MUST reconcile to 85 plugin rules or 19 interface rules.

#### Scenario: Exempted findings are counted separately

- GIVEN a review has blocking failures and exempted failures
- WHEN the report header is generated
- THEN exempted findings MUST be counted under `Exempted`
- AND they MUST NOT be counted under `Failed`
- AND `Passed + Failed + Skipped + Exempted` MUST equal the complete rule count

### Requirement: Issue Summary contains only non-exempt findings

The report MUST contain an Issue Summary table with these columns: Issue No., Status, Rule, File, Line, and Issue. The Rule cell for each non-exempt finding MUST link to its detailed section using a stable `#issue-N` anchor. The Issue value MUST be a concise description.

#### Scenario: Exempted finding is excluded from blocking summary

- GIVEN a failed rule is reclassified as `EXEMPT`
- WHEN the Issue Summary is generated
- THEN that finding MUST NOT appear in the Issue Summary table
- AND its exempted status MUST remain visible in the separate Exempted Findings section

### Requirement: Detailed Findings describe non-exempt failures

Each non-exempt finding MUST have one detailed section containing the rule ID and name, effective status, file and line citation, a plain-English explanation, actual code found, a corrected code example, and a contextual-judgment note when applicable. Findings MUST be ordered by VIOLATION, WARNING, then SUGGESTION.

`thunder-plugin-review.prompt.md` enforces this ordering with an explicit rule in its Report Generation Rules section. `thunder-interface-review.prompt.md` has no equivalent explicit instruction and relies on default report generation to produce this order.

#### Scenario: Non-exempt failure has a detailed section

- GIVEN a rule failure has no matching exemption
- WHEN the report is generated
- THEN the finding MUST appear in the Issue Summary and Detailed Findings
- AND its detailed section MUST include the exact source citation and actionable fix

### Requirement: Exempted Findings are table-only

When one or more failures are reclassified as `EXEMPT`, the report MUST place them after Skipped Rules in a separate Exempted Findings section. The section MUST contain exactly one table with `Rule`, `Status`, `File`, `Line`, and `Issue` columns. Each Issue value MUST be a concise one-line description.

#### Scenario: Exempted finding has no expanded detail or reason

- GIVEN one or more failures were reclassified as `EXEMPT`
- WHEN the HTML report is generated
- THEN exempted findings MUST NOT appear in the blocking Issue Summary
- AND exempted findings MUST NOT receive `What's wrong`, `Code found`, or `Fix` blocks
- AND the Exempted Findings table MUST NOT contain a `Reason` or `Exemption Reason` column because the exemption schema has no reason field

### Requirement: Report is written and opened safely

The report directory MUST be created when missing. The report MUST be written through the terminal, verified as non-empty, and opened in a browser or VS Code Simple Browser rather than the editor.

#### Scenario: Report generation completes

- GIVEN the report directory does not exist
- WHEN report generation completes
- THEN the required directory MUST be created
- AND the generated file size MUST be verified as non-zero
- AND the report MUST be opened in a browser or Simple Browser

### Requirement: Empty reviews produce a valid report

When every rule passes and no rule is skipped or exempted, the report MUST still contain the report header and a clear all-rules-passed message without an empty Detailed Findings section.