---
title: "Thunder Plugin Rule Catalog"
description: "Read-only, browsable HTML catalog of all 85 plugin rules, or just the ones currently exempted. Does not manage exemptions itself."
---

## Purpose

This prompt is **read-only reference browsing** — it never writes to the exemptions file and has no
Add/Update/Remove/Clear logic at all. To actually create, change, or clear an exemption, use the
standalone script instead:

```
python PluginQualityAdvisor/exempt_manager.py
```

That script (no AI, no VS Code required) is the primary way to manage exemptions — see its own
`--help` output or `README.md` for usage. This prompt exists purely so a developer can quickly see,
in a browsable page, what all 85 rules are and which ones are currently exempted, without needing to
read raw YAML.

---

## Fast-Path Flags

| Flag | Effect |
|---|---|
| `--catalog` | Generate and open the full HTML rule catalog (all 85 rules) and stop |
| `--exempted-catalog` | Generate and open the HTML catalog filtered to exempted rules only and stop |

Running with no flags: ask (`vscode_askQuestions`) which of the two to generate.

---

## Rule Groups Reference (17 groups)

Loaded from `PluginQualityAdvisor/rules/thunder-plugin-rules.yaml` metadata at runtime. Current counts:

**Phase checkpoints (9 groups, 39 rules):**
| Group | Rules |
|---|---|
| `phase_1` - Module Structure | rule_01–rule_03 (3) |
| `phase_2` - Code Style | rule_04–rule_13 (10) |
| `phase_3` - Class Registration | rule_14–rule_16 (3) |
| `phase_4` - Lifecycle | rule_17–rule_28 (12) |
| `phase_5` - Implementation | rule_29–rule_31 (3) |
| `phase_5C` - Out-of-Process | rule_32–rule_33 (2) |
| `phase_6` - Configuration | rule_34–rule_36 (3) |
| `phase_7` - CMake | rule_37, rule_85 (2) |
| `phase_8` - COM Interface | rule_38 (1) |

**Holistic categories (8 groups, 46 rules):**
| Group | Rules |
|---|---|
| `conventions` - Conventions & Encapsulation | 5 rules |
| `lifecycle_integrity` - Lifecycle & State Integrity | 4 rules |
| `concurrency` - Concurrency & Threading | 13 rules |
| `com_safety` - COM Reference & Memory Safety | 5 rules |
| `resource_management` - Resource Management | 1 rule |
| `jsonrpc_compliance` - JSON-RPC Compliance | 6 rules |
| `inter_plugin_design` - Inter-Plugin & OOP Design | 5 rules |
| `code_quality_security` - Code Quality & Security | 7 rules |

Always re-read the YAML at the start of every invocation — counts may have changed since this prompt
was written.

---

## Browse Full Rule Catalog

Generates a self-contained HTML reference page listing **all 85 rules** (not just exempted ones).

**File path:** `PluginQualityAdvisor/Reports/catalog/plugin-rules_{YYYY-MM-DD}.html`
- Create `PluginQualityAdvisor/Reports/catalog/` if it does not exist.
- Never overwrite an existing file — append `_2`, `_3` etc.

**HTML shell:** identical to the shell used in `thunder-plugin-review.prompt.md`'s Step 6 (same
highlight.js CDN includes, same CSS), with `<title>Thunder Plugin Rule Catalog</title>`.

**Content:**
1. `<h1>Thunder Plugin Rule Catalog</h1>` with a table of contents immediately below it: one link per
   rule group (`<a href="#phase-4">Phase 4: Lifecycle (12)</a>`, etc.) jumping to that section.
2. One `<h2 id="phase-N">` (or `<h2 id="{category}">`) section per group, each containing a table:

   | Rule | Name | Severity | What it checks | Exempted? |
   |------|------|----------|-----------------|-----------|
   | rule_06 | NULL vs nullptr | ⚠️ Warning | e.g. "IPlugin* plugin = NULL;" instead of nullptr | — |
   | rule_14 | Special Members Deleted | ⚠️ Warning | All 4 special members deleted on main class | Dictionary, Legacy |

   "What it checks" is the rule's `violation_pattern`. "Exempted?" reads live from
   `PluginQualityAdvisor/Exemptions/thunder-plugin-exemptions.local.yaml` — `—` if not exempted,
   otherwise the scope (`Global` or the plugin name list).
3. Each section ends with `<p class="back-link"><a href="#top">⬆ Back to top</a></p>`.

**Post-generation:** write via terminal (`[System.IO.File]::WriteAllText`), verify non-empty, open via
`simpleBrowser.show` — same conventions as every other report this tool generates. Never open directly
in the VS Code editor.

---

## List Exempted Rules (HTML)

Same template as **Browse Full Rule Catalog** above — identical HTML shell, identical table shape,
identical anchor/TOC/back-link pattern — but the content is **filtered to only the rules currently
exempted**, instead of all 85.

**File path:** `PluginQualityAdvisor/Reports/catalog/plugin-exempted_{YYYY-MM-DD}.html`
- Same folder-creation and no-overwrite rules as the full catalog.
- `<title>Thunder Plugin Exempted Rules</title>`.

**Content — differences from the full catalog:**
1. The table of contents only lists groups that contain **at least one** exempted rule — a group with
   zero exemptions gets no TOC entry and no section at all.
2. Within each included group's table, list **only the exempted rules** in that group (same columns:
   Rule | Name | Severity | What it checks | Exempted?) — not the group's full rule set.
3. If there are **no exemptions at all**, do not generate a file — tell the user directly in chat:
   `No exemptions recorded yet — nothing to list. Add one with python PluginQualityAdvisor/exempt_manager.py add <rule_id> --scope <name>.`

Same post-generation conventions (write via terminal, verify non-empty, open in browser) as every
other report.

---

## Important Notes

1. This prompt never writes to the exemptions file — it only reads it, to show current status.
   `exempt_manager.py` (standalone, no AI) is the tool for Add/Update/Remove/Clear.
2. Always re-read both `thunder-plugin-rules.yaml` and the exemptions YAML fresh at the start of every
   invocation — either may have changed since this prompt was last run.
3. If a developer asks to exempt something while looking at this catalog, tell them to run
   `python PluginQualityAdvisor/exempt_manager.py add <rule_id> --scope <name>` — do not attempt to
   write the exemption from this prompt.
