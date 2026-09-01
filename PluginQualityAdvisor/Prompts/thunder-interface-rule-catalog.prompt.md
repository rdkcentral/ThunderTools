---
title: "Thunder Interface Rule Catalog"
description: "Read-only, browsable HTML catalog of all 19 interface rules, or just the ones currently exempted. Does not manage exemptions itself."
---

## Purpose

This prompt is **read-only reference browsing** — it never writes to the exemptions file and has no
Add/Update/Remove/Clear logic at all. To actually create, change, or clear an exemption, use the
standalone script instead:

```
python PluginQualityAdvisor/exempt_manager.py --rule-set interface
```

That script (no AI, no VS Code required) is the primary way to manage exemptions — see its own
`--help` output or `README.md` for usage. This prompt exists purely so a developer can quickly see,
in a browsable page, what all 19 interface rules are and which ones are currently exempted, without
needing to read raw YAML.

---

## Fast-Path Flags

| Flag | Effect |
|---|---|
| `--catalog` | Generate and open the full HTML rule catalog (all 19 rules) and stop |
| `--exempted-catalog` | Generate and open the HTML catalog filtered to exempted rules only and stop |

Running with no flags: ask (`vscode_askQuestions`) which of the two to generate.

---

## Rule Groups Reference (2 groups, 19 rules)

Loaded from `PluginQualityAdvisor/rules/thunder-interface-rules.yaml` at runtime. Current counts:

| Group | Rules |
|---|---|
| `core` - Core Rules | core_1_1–core_16_1 (16) |
| `advisory` - Advisory Rules | advisory_m1_1–advisory_m3_1 (3) |

Always re-read the YAML at the start of every invocation — counts may have changed since this prompt
was written.

---

## Browse Full Rule Catalog

Generates a self-contained HTML reference page listing **all 19 rules** (not just exempted ones).

**File path:** `PluginQualityAdvisor/Reports/catalog/interface-rules_{YYYY-MM-DD}.html`
- Create `PluginQualityAdvisor/Reports/catalog/` if it does not exist.
- Never overwrite an existing file — append `_2`, `_3` etc.

**HTML shell:** identical to the shell used in `thunder-interface-review.prompt.md`'s Step 6 (same
highlight.js CDN includes, same CSS), with `<title>Thunder Interface Rule Catalog</title>`.

**Content:**
1. `<h1>Thunder Interface Rule Catalog</h1>` with a table of contents immediately below it: one link
   per group (`<a href="#core">Core Rules (16)</a>`, `<a href="#advisory">Advisory Rules (3)</a>`)
   jumping to that section.
2. One `<h2 id="core">` / `<h2 id="advisory">` section per group, each containing a table:

   | Rule | Name | Severity | What it checks | Exempted? |
   |------|------|----------|-----------------|-----------|
   | core_10_1 | @json Tag (CRITICAL) | ⚠️ Warning | Missing @json tag → zero JSON-RPC code generated | — |
   | advisory_m2_1 | Enum Underlying Types | ⚠️ Warning | Named enums used as params need explicit type | Global |

   "What it checks" is the rule's `violation_pattern`. "Exempted?" reads live from
   `PluginQualityAdvisor/Exemptions/thunder-interface-exemptions.local.yaml` — `—` if not exempted,
   otherwise the scope (`Global` or the interface name list).
3. Each section ends with `<p class="back-link"><a href="#top">⬆ Back to top</a></p>`.

**Post-generation:** write via terminal (`[System.IO.File]::WriteAllText`), verify non-empty, open via
`simpleBrowser.show` — same conventions as every other report this tool generates. Never open directly
in the VS Code editor.

---

## List Exempted Rules (HTML)

Same template as **Browse Full Rule Catalog** above — identical HTML shell, identical table shape,
identical anchor/TOC/back-link pattern — but the content is **filtered to only the rules currently
exempted**, instead of all 19.

**File path:** `PluginQualityAdvisor/Reports/catalog/interface-exempted_{YYYY-MM-DD}.html`
- Same folder-creation and no-overwrite rules as the full catalog.
- `<title>Thunder Interface Exempted Rules</title>`.

**Content — differences from the full catalog:**
1. The table of contents only lists groups (Core / Advisory) that contain **at least one** exempted
   rule — a group with zero exemptions gets no TOC entry and no section at all.
2. Within each included group's table, list **only the exempted rules** in that group (same columns:
   Rule | Name | Severity | What it checks | Exempted?) — not the group's full rule set.
3. If there are **no exemptions at all**, do not generate a file — tell the user directly in chat:
   `No exemptions recorded yet — nothing to list. Add one with python PluginQualityAdvisor/exempt_manager.py --rule-set interface add <rule_id> --scope <name>.`

Same post-generation conventions (write via terminal, verify non-empty, open in browser) as every
other report.

---

## Important Notes

1. This prompt never writes to the exemptions file — it only reads it, to show current status.
   `exempt_manager.py` (standalone, no AI) is the tool for Add/Update/Remove/Clear.
2. Always re-read both `thunder-interface-rules.yaml` and the exemptions YAML fresh at the start of
   every invocation — either may have changed since this prompt was last run.
3. If a developer asks to exempt something while looking at this catalog, tell them to run
   `python PluginQualityAdvisor/exempt_manager.py --rule-set interface add <rule_id> --scope <name>` —
   do not attempt to write the exemption from this prompt.
