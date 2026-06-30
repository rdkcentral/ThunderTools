# Proposal: Thunder PluginQA System

## Intent

Thunder plugin development lacks automated validation. Developers ship plugins
with common, repeatable bugs — missing ASSERT in Initialize(), wrong NULL vs
nullptr, hardcoded paths, missing observer cleanup, wrong CMake ordering — that
reviewers catch manually in code review. This costs review time and introduces
production defects.

We need a structured, AI-driven validation layer that runs inside VS Code via
GitHub Copilot Chat, checking plugins against proven Thunder best practices
automatically.

## Scope

**Rule managers** (`/thunder-plugin-rule-manager`, `/thunder-interface-rule-manager`)
- Guided questionnaire to add, update, or remove rules via `vscode_askQuestions`
- Document template fast path: user can paste a filled `.md` template instead of answering all questions
- Automatic classification: determines whether a new rule belongs as an automated checkpoint vs manual review rule (plugin manager), or core vs advisory (interface manager)
- UPDATE flow: displays the current rule annotated with field numbers, asks only which fields to change
- Keeps all affected files in sync atomically: YAML + prompt + README + spec

**Plugin checkpoint validation (`/thunder-plugin-review`)**
- 79 unified rules numbered sequentially (rule_01 to rule_79)
- Each rule: read code semantically -> decide pass/fail -> cite exact line on failure
- Phases: Module Structure, Code Style, Class Registration, Lifecycle, Implementation,
  COM Interface Rules, Out-of-Process, Configuration, CMake, General
- Single unified report - no separate sections
- Report shows ONLY failures - PASS/SKIP appear as counts in summary table only

**COM interface validator (`/thunder-interface-review`)**
- 19 rules: 15 core (VIOLATION level) + 4 advisory
- Validates Thunder COM interfaces in ThunderInterfaces/interfaces/
- Covers: file structure, @json tag, @restrict on vectors, return types, ID registration,
  nested event interfaces, binary compatibility, no std::map, explicit integer widths

**Plugin skeleton generator (`/thunder-generate-plugin`)**
- Interactive: collects parameters via VS Code `vscode_askQuestions` (NOT chat)
- Runs ThunderTools PluginSkeletonGenerator.py in interactive mode
- Auto-fixes include paths in generated .h files (known PSG bug workaround)

**Setup script** (Python cross-platform)
- `setup-prompts.py` registers prompt files with VS Code via `chat.promptFilesLocations` in settings.json
- Works on Windows, macOS, and Linux (stdlib only, no dependencies)
- Safe: creates timestamped backup, preserves existing settings, idempotent

**YAML rule definitions** (loaded by prompts at runtime, not embedded)
- `thunder-plugin-rules.yaml` — 79 unified rules (v3.3.0)
- `thunder-interface-rules.yaml` — 19 interface rules (v3.2.2)

**Review reports** (CSV, generated after each review run)
- Single CSV file per review, Excel-compatible, UTF-8, CRLF
- Plugin report: `Reports/plugin/{PluginName}_{YYYY-MM-DD}.csv` — one row per issue
- Interface report: `Reports/interface/{InterfaceName}_{YYYY-MM-DD}.csv` — one row per violated rule
- Columns: No, Plugin/Interface, Date, Phase/Category, Checkpoint/Rule ID, Rule Name, Status, Severity, File, Line, Citation, Issue Description, Fix Summary, Reasoning
- PASS and SKIP rows excluded — only failures logged
- Post-generation: chat message with count summary + `Start-Process` command to open in Excel

## Out of Scope

- CI/CD pipeline integration (future)
- Non-Copilot AI tools (future)
- Auto-fix application (validation only, fixes are shown but not applied)

## Approach

Use VS Code `.prompt.md` files as slash commands. Each prompt loads its YAML
rule definitions at runtime so rules can be updated without touching prompt
logic. Plugin validation uses semantic code review: read code as a human
developer and reason about meaning. All 79 rules produce the same unified
output format — no distinction between "automated" and "manual" in the report.

All checkpoint verification uses semantic reasoning — the validator reads code
as a human developer and reasons about meaning. No regex or text search is used
as the primary detection method.

Severity output reflects contextual judgment: if a developer's approach
technically violates a rule but is valid and reasonable in context, the
effective severity is downgraded (violation→suggestion or violation→warning)
and a `reasoning` field explains the rule, the developer's approach, and why
it is acceptable. Severity is never escalated above what the YAML defines.

## Delivery Structure

```
ThunderTools/PluginQA/
├── README.md
├── setup-prompts.py           (cross-platform, Python 3)
├── Prompts/
│   ├── thunder-plugin-review.prompt.md
│   ├── thunder-interface-review.prompt.md
│   ├── thunder-generate-plugin.prompt.md
│   ├── thunder-plugin-rule-manager.prompt.md
│   └── thunder-interface-rule-manager.prompt.md
├── rules/
│   ├── thunder-plugin-rules.yaml
│   └── thunder-interface-rules.yaml
└── Reports/
    ├── plugin/
    │   └── {PluginName}_{YYYY-MM-DD}.csv
    └── interface/
        └── {InterfaceName}_{YYYY-MM-DD}.csv
```