# Proposal: Thunder PluginQualityAdvisor System

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
- 85 unified rules numbered sequentially (rule_01 to rule_85)
- Each rule: read code semantically -> decide pass/fail -> cite exact line on failure
- Phases: Module Structure, Code Style, Class Registration, Lifecycle, Implementation,
  COM Interface Rules, Out-of-Process, Configuration, CMake, General
- Single unified report with a separate Exempted Findings table when applicable
- Report shows failures only; PASS/SKIP appear as counts in summary tables

**COM interface validator (`/thunder-interface-review`)**
- 19 rules: 16 core + 3 advisory
- Validates Thunder COM interfaces in ThunderInterfaces/interfaces/
- Covers: file structure, @json tag, @restrict on vectors, return types, ID registration,
  event interfaces, no std::map, explicit integer widths

**Plugin skeleton generator (`/thunder-generate-plugin`)**
- Interactive: collects parameters via VS Code `vscode_askQuestions` (NOT chat)
- Parameters: PluginName, OutputDirectory, OutOfProcess, CustomConfig, InterfacePaths,
  SelectInterfaces, IncludeLocations, Preconditions, Terminations, Controls
- Runs ThunderTools PluginSkeletonGenerator.py in interactive mode
- Handles multi-interface headers (interface selection) and custom include locations
- Auto-fixes include paths in generated .h files (known PSG bug workaround)

**Setup script** (Python cross-platform)
- `setup-prompts.py` registers prompt files with VS Code via `chat.promptFilesLocations` in settings.json
- Works on Windows, macOS, and Linux (stdlib only, no dependencies)
- Safe: creates timestamped backup, preserves existing settings, idempotent

**YAML rule definitions** (loaded by prompts at runtime, not embedded)
- `thunder-plugin-rules.yaml` — 85 unified rules (v3.3.0)
- `thunder-interface-rules.yaml` — 19 interface rules (v3.2.2)

**Review reports** (HTML, generated after each review run)
- Single `.html` file per review with Issue Summary table and Detailed Findings for non-exempt findings
- Plugin report: `Reports/plugin/{PluginName}_{YYYY-MM-DD}.html`
- Interface report: `Reports/interface/{InterfaceName}_{YYYY-MM-DD}.html`
- Issue Summary table with clickable `[rule_id - Name](#issue-N)` links navigating to non-exempt detailed sections
- Each non-exempt finding has: What's wrong (plain English), Code found, Fix
- Exempted findings use a separate table with Rule, Status, File, Line, and a concise Issue description; no reason field
- PASS and SKIP rules excluded from individual findings — only totals are shown
- Written via terminal to avoid VS Code editor buffer conflicts; opened in a browser or Simple Browser

## Out of Scope

- CI/CD pipeline integration (future)
- Non-Copilot AI tools (future)
- Auto-fix application (validation only, fixes are shown but not applied)

## Approach

Use VS Code `.prompt.md` files as slash commands. Each prompt loads its YAML
rule definitions at runtime so rules can be updated without touching prompt
logic. Plugin validation uses semantic code review: read code as a human
developer and reason about meaning. All 85 rules produce the same unified
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
ThunderTools/PluginQualityAdvisor/
├── README.md
├── setup-prompts.py           (cross-platform, Python 3)
├── exempt_manager.py          (standalone local exemption CLI)
├── Exemptions/                (runtime-created, git-ignored local state)
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
    │   └── {PluginName}_{YYYY-MM-DD}.html
    └── interface/
        └── {InterfaceName}_{YYYY-MM-DD}.html
```

## Rule Exemptions

Rule exemptions are part of the PluginQualityAdvisor review system and are documented in this change rather than a separate OpenSpec change. They preserve visibility of accepted deviations without skipping validation.

- Store plugin and interface exemptions in local, git-ignored YAML files under `PluginQualityAdvisor/Exemptions/`.
- Use the standalone standard-library `PluginQualityAdvisor/exempt_manager.py` for `list`, `add`, `update`, `remove`, and `clear`; no exemption slash command or review-reply shortcut is required.
- Every rule still executes and receives contextual JUDGE processing. Only a matching failure is reclassified as `EXEMPT` after JUDGE.
- Exempted findings remain visible in a separate table with `Rule`, `Status`, `File`, `Line`, and a concise one-line `Issue` description.
- Exempted findings do not receive expanded detail blocks and the exemption schema has no reason or audit-metadata field.

The existing rule catalog remains read-only. It may display exemption status but does not author or modify exemption state.