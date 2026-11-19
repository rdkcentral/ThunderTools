# Delta for Rule Exemptions

## ADDED Requirements

### Requirement: Exemption data is local and ignored

Exemption data MUST be stored in `PluginQualityAdvisor/Exemptions/` in separate local files for the plugin and interface rule sets. Files matching `PluginQualityAdvisor/Exemptions/*.local.yaml` MUST be ignored by Git.

When the folder or applicable file is missing, `exempt_manager.py` MUST create the folder first and then initialize the file with an empty `exemptions:` list, but only at the point it actually needs to write (e.g. `add`) — it MUST NOT pre-create either on a pure read (e.g. `list`). The plugin and interface review prompts MUST NOT create the folder or file at all: if either is missing when a review runs, the review MUST simply treat every rule as not exempted for that run and continue, leaving the filesystem untouched. Local state MUST NOT transfer through a fresh clone.

### Requirement: Exemption entries use a minimal schema

Each entry in the `exemptions:` list MUST contain exactly one selector: `rule_id`, `phase`, or `category`. Each entry MUST also contain `scope`, which is either `global` or a list of named plugins/interfaces.

Entries MUST NOT contain `reason`, `added_by`, `added_date`, `expires`, or other audit metadata. A rule selector matches one rule; a phase or category selector matches its group in the selected rule set; scope controls which review names receive the exemption.

### Requirement: Exemptions use the standalone Python CLI

`PluginQualityAdvisor/exempt_manager.py` MUST be the only authoring interface for local exemption state. It MUST use only the Python standard library and support `list`, `add`, `update`, `remove`, and `clear` with the global `--rule-set plugin|interface` option.

`add` MUST require `--scope` and accept a rule ID, `--phase`, or `--category`. `update` MUST change the scope selected by index. `remove` MUST accept one or more indexes. `clear` MUST support `--all`, `--scope`, or a rule ID. Running the script without arguments MUST retain interactive mode.

Example commands:

```text
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin list
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin add rule_14 --scope Dictionary
python PluginQualityAdvisor/exempt_manager.py --rule-set interface add core_13_1 --scope IDictionary
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin clear --all
```

### Requirement: Exemptions do not change review execution

The plugin and interface review prompts MUST load their applicable local exemptions after loading shared rules and before evaluating rules. Every rule MUST still execute in full and receive semantic contextual JUDGE processing.

Exemption status MUST be checked only after the effective status is finalized:

- PASS and SKIP remain unchanged.
- A non-exempted VIOLATION, WARNING, or SUGGESTION remains a normal finding.
- A matching VIOLATION, WARNING, or SUGGESTION becomes `EXEMPT`.

### Requirement: Exempted findings are concise and separate

An exempted finding MUST be omitted from the blocking Issue Summary and MUST NOT receive an individual Detailed Findings block. It MUST appear in a separate `Exempted Findings` section after Skipped Rules.

The section MUST contain one table with exactly these columns: `Rule`, `Status`, `File`, `Line`, and `Issue`. The `Issue` value MUST be a concise one-line description of the finding. The table MUST NOT contain a `Reason` or `Exemption Reason` column, and MUST NOT contain expanded `What's wrong`, `Code found`, or `Fix` content.

The report header and rule-group totals MUST include an `Exempted` count, and `PASS + FAIL + SKIP + EXEMPT` MUST reconcile to 85 plugin rules or 19 interface rules. Chat summaries MUST report exempted findings separately from blocking issues.

### Requirement: Rule catalog remains read-only

The `thunder-plugin-rule-catalog.prompt.md` and `thunder-interface-rule-catalog.prompt.md` prompts MAY display rule definitions and current exemption status, but MUST NOT modify local exemption files. Exemption management MUST NOT depend on either catalog prompt.

### Requirement: CLI global options precede the subcommand

The `--rule-set` option MUST be supplied before the subcommand name (e.g. `--rule-set plugin add rule_14 --scope Dictionary`), because it is defined on the top-level argument parser rather than on each subcommand's parser. Supplying it after the subcommand (e.g. `add rule_14 --rule-set plugin`) MUST fail with an "unrecognized arguments" error rather than being silently accepted. Every documented example (README, this spec, and the review prompts' exemption hints) MUST use this same ordering.

When `--rule-set` is omitted for a one-shot subcommand, the CLI MUST default to `plugin` without prompting. When it is omitted while launching interactive mode (no subcommand at all), the CLI MUST ask the user to choose `plugin` or `interface` before showing any menu, rather than silently defaulting.

### Requirement: Interactive add flow stages across groups before writing

Interactive mode's Add flow MUST present rule groups one at a time (a "phase cart"): the user picks a group, selects one or more rules from it via a numbered list, and is returned to the group menu — never writing to the exemptions file at that point. This MUST repeat for as many groups as the user chooses, in any order.

Confirming the group menu with no input typed (an empty response) MUST be treated as the deliberate finish action — equivalent to a "Submit" choice — and MUST NOT be treated as an accidental dismissal or trigger silently redisplaying the menu. Only after this finish action does the flow ask for scope once for the whole staged batch and write every staged entry in a single pass.

Each group's displayed rule count MUST include both rules already exempted in the file and rules staged earlier in the same interactive session (deduplicated), recomputed every time the group menu is shown — never a count computed once and cached. Within a group's rule list, an already-exempted or already-staged rule MUST be visibly labeled as such, not left to be inferred from a checkbox or highlight alone.

The flow MUST NOT ask a separate "apply to all selected or answer individually" question, since the exemption schema has no `reason` field for such a question to disambiguate.