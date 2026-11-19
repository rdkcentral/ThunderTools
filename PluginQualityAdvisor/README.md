# ThunderPluginQualityAdvisor

AI-driven validation tools for Thunder plugin and COM interface development, powered by VS Code GitHub Copilot Chat.

---

## Prerequisites

1. **VS Code** with GitHub Copilot Chat extension installed
2. **Plugin and interface source files** must be in the same VS Code workspace (any folder structure — the tool searches the workspace automatically)
3. Register the prompt file location in VS Code:

   **Option A — Manual (recommended):**
   Open your VS Code `settings.json` (`Ctrl+Shift+P` -> `Preferences: Open User Settings (JSON)`) and add the absolute path to the Prompts folder:

```json
   {
     "chat.promptFilesLocations": {
       "/full/path/to/ThunderTools/PluginQualityAdvisor/Prompts": true
     }
   }
```

The path must be the **absolute path** to the `Prompts` folder.

> **Tip:** If you have multiple workspaces with PluginQualityAdvisor, set only one path to `true` at a time and the rest to `false`. This avoids slash command collisions. To switch, change `true`/`false` and reload VS Code.

   **Option B — Automated (Python script):**

```shellscript
   python3 PluginQualityAdvisor/setup-prompts.py
```

This detects the absolute path to the `Prompts` folder and writes it to your VS Code `settings.json` automatically.

> **Multiple workspaces:** If you have PluginQualityAdvisor in multiple locations (e.g. different Thunder versions), the script automatically disables any previously registered paths and enables only the current one. This prevents slash command collisions where two paths provide the same prompt file. To switch back to a previous workspace, run `setup-prompts.py` from that workspace — it will disable the current path and enable the previous one.

4. **Reload VS Code** — press `Ctrl+Shift+P` -> `Developer: Reload Window`

After reload, the `/thunder-*` slash commands appear in Copilot Chat.

---

## Commands

| Command | What it does |
|---------|--------------|
| `/thunder-plugin-review` | Validate a Thunder plugin against all rules |
| `/thunder-interface-review` | Validate a Thunder COM interface header |
| `/thunder-generate-plugin` | Generate a new Thunder plugin skeleton |
| `/thunder-plugin-rule-manager` | Add, update, or remove plugin rules |
| `/thunder-interface-rule-manager` | Add, update, or remove interface rules |
| `/thunder-plugin-rule-catalog` | Browse the full 85-rule catalog (or just exempted ones) as HTML — read-only |
| `/thunder-interface-rule-catalog` | Browse the full 19-rule catalog (or just exempted ones) as HTML — read-only |

---

## `/thunder-plugin-review`

Validates a Thunder plugin against all rules defined in `thunder-plugin-rules.yaml` using semantic code review.

**Usage:**
```
/thunder-plugin-review <PluginName>
/thunder-plugin-review <PluginName> <FileName>
```

**Examples:**
```
/thunder-plugin-review Dictionary
/thunder-plugin-review Dictionary Dictionary.cpp
```

- **Full plugin mode** — reviews all files in the plugin folder
- **Single file mode** — reviews only the specified file against applicable rules

**Output:** Failures grouped by file with exact `[File:line]` citations, with a single header line giving `Total Rules | Passed | Failed | Skipped | Exempted` totals — there is no separate per-phase breakdown table. Any rule exempted for this plugin (see **Exemption Management** below) still runs and is still reported — just in a separate **Exempted Findings** section instead of the blocking Issue Summary. The report includes the Python command needed to record an exemption.

---

## `/thunder-interface-review`

Validates a Thunder COM interface header against core and advisory rules defined in `thunder-interface-rules.yaml`.

**Usage:**
```
/thunder-interface-review <InterfaceFile>
```

**Examples:**
```
/thunder-interface-review IDictionary.h
/thunder-interface-review INetworkControl.h
```

**Output:** Issue summary table with detailed findings, saved as an HTML report with clickable navigation and syntax-highlighted code blocks. Any rule exempted for this interface (see **Exemption Management** below) still runs and is still reported — just in a separate **Exempted Findings** section instead of the blocking Issue Summary. The report includes the Python command needed to record an exemption.

---

## `/thunder-generate-plugin`

Generates a new Thunder plugin skeleton interactively using PluginSkeletonGenerator.

**Usage:**
```
/thunder-generate-plugin
```

Collects parameters via VS Code dropdowns and runs PSG interactively:

| Parameter | Description | Default |
|-----------|-------------|---------|
| PluginName | Valid C++ identifier | (required) |
| OutputDirectory | Where to generate | current directory |
| OutOfProcess | Out-of-process plugin | No |
| CustomConfig | Custom configuration class | No |
| InterfacePaths | C++ IDL header files to parse | (empty) |
| SelectInterfaces | Which interfaces from multi-interface headers | ALL |
| IncludeLocations | Custom #include paths per header | interfaces |
| Preconditions | Thunder subsystem preconditions | (empty) |
| Terminations | Thunder subsystem terminations | (empty) |
| Controls | Thunder subsystem controls | (empty) |

After generation, auto-fixes known PSG include path bugs in generated `.h` files.

---

## `/thunder-plugin-rule-manager`

Add, update, or remove plugin validation rules.

**Usage:**
```
/thunder-plugin-rule-manager
```

**Two ways to provide input:**
- **Interactive** — answers questions via VS Code dropdowns
- **Document template** — paste a filled template from `Update-Template-Guide/plugin-rule-template-guide.md`

Updates `thunder-plugin-rules.yaml` and `thunder-plugin-review.prompt.md` atomically.

---

## `/thunder-interface-rule-manager`

Add, update, or remove interface validation rules.

**Usage:**
```
/thunder-interface-rule-manager
```

**Two ways to provide input:**
- **Interactive** — answers questions via VS Code dropdowns
- **Document template** — paste a filled template from `Update-Template-Guide/interface-rule-template-guide.md`

Updates `thunder-interface-rules.yaml` and `thunder-interface-review.prompt.md` atomically.

---

## `/thunder-plugin-rule-catalog` and `/thunder-interface-rule-catalog`

Read-only, browsable HTML catalogs of every rule — for quickly seeing what a rule checks and whether
it's currently exempted, without opening the raw YAML. Neither prompt writes to the exemptions file;
use `exempt_manager.py` (below) for that.

**Usage:**
```
/thunder-plugin-rule-catalog --catalog              # all 85 plugin rules
/thunder-plugin-rule-catalog --exempted-catalog      # only the currently exempted plugin rules
/thunder-interface-rule-catalog --catalog            # all 19 interface rules
/thunder-interface-rule-catalog --exempted-catalog   # only the currently exempted interface rules
```
Running either with no flags asks which of the two to generate.

**Output:** a self-contained HTML page at `PluginQualityAdvisor/Reports/catalog/{plugin|interface}-rules_{YYYY-MM-DD}.html`
(or `-exempted_` for the filtered version), grouped by phase/category with a clickable table of
contents, each rule's severity and one-line description, and its live exemption status. `--exempted-catalog`
generates nothing and tells you directly in chat if there's nothing currently exempted.

---

## Exemption Management (Python CLI)

Manage local exemptions with `PluginQualityAdvisor/exempt_manager.py`. The CLI is standalone and does not
require VS Code or an AI prompt. Plugin and interface review prompts read the same local YAML files, so an
exemption recorded by the CLI is applied on the next review.

Exemption files are personal, local-only state stored in `PluginQualityAdvisor/Exemptions/` and excluded by
`.gitignore`. Exempting a rule does not change what a review checks; a failing exempted rule is still reported
in the report's **Exempted Findings** section instead of the blocking Issue Summary.

**Usage:**
```text
python PluginQualityAdvisor/exempt_manager.py
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin list
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin add rule_14 --scope Dictionary
python PluginQualityAdvisor/exempt_manager.py --rule-set interface add core_13_1 --scope IDictionary
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin update 1 --scope Legacy,Dictionary
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin remove 1
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin clear --scope Dictionary
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin clear rule_14
python PluginQualityAdvisor/exempt_manager.py --rule-set plugin clear --all
```

Supported operations are `list`, `add`, `update`, `remove`, and `clear`. The `add` command also accepts a
`--phase` or `--category` selector where that group exists in the selected rule set instead of a rule ID. Run
`python PluginQualityAdvisor/exempt_manager.py --help` for the complete command syntax. The CLI does not store
reason fields or manage exemptions through review replies.

For read-only rule browsing, use `/thunder-plugin-rule-catalog` or `/thunder-interface-rule-catalog`
(see above) — neither modifies exemptions.

---

## Project Structure

```
ThunderTools/PluginQualityAdvisor/
+-- README.md
+-- setup-prompts.py
+-- exempt_manager.py
+-- Update-Template-Guide/
|   +-- plugin-rule-template-guide.md
|   +-- interface-rule-template-guide.md
+-- Prompts/
|   +-- thunder-plugin-review.prompt.md
|   +-- thunder-interface-review.prompt.md
|   +-- thunder-generate-plugin.prompt.md
|   +-- thunder-plugin-rule-manager.prompt.md
|   +-- thunder-interface-rule-manager.prompt.md
|   +-- thunder-plugin-rule-catalog.prompt.md
|   +-- thunder-interface-rule-catalog.prompt.md
+-- rules/
|   +-- thunder-plugin-rules.yaml
|   +-- thunder-interface-rules.yaml
+-- Exemptions/                              (git-ignored - local-only, never committed)
|   +-- thunder-plugin-exemptions.local.yaml
|   +-- thunder-interface-exemptions.local.yaml
+-- Reports/
    +-- plugin/
    |   +-- {PluginName}_{YYYY-MM-DD}.html
    +-- interface/
    |   +-- {InterfaceName}_{YYYY-MM-DD}.html
    +-- catalog/
        +-- plugin-rules_{YYYY-MM-DD}.html
        +-- interface-rules_{YYYY-MM-DD}.html
```

---

## Severity Levels

| Level | Meaning |
|---|---|
| `violation` | Blocking |
| `warning` | Should fix |
| `suggestion` | Optional |

---

## Reports

After each review, a self-contained **HTML report** is generated under `Reports/plugin/` or `Reports/interface/`. Reports include an Issue Summary table with clickable anchor links to Detailed Findings sections (plain-English explanation, code found, and fix), with syntax-highlighted code blocks powered by highlight.js. Open the `.html` file in a browser or VS Code Simple Browser.

If any rule that failed is locally exempted for the plugin/interface being reviewed, it is never counted as a blocking failure or silently dropped — it appears in a separate **Exempted Findings** table at the end of the report instead. Exemptions have no reason field.

`Reports/catalog/` holds the browsable, searchable HTML rule catalogs generated by
`/thunder-plugin-rule-catalog` and `/thunder-interface-rule-catalog` — a reference listing of every
plugin or interface rule with its current exemption status.

---

## Rule Exemptions

Both review commands support **local-only exemptions** — rules a developer has personally decided to accept, globally or for specific plugins/interfaces, without touching the shared rule definitions. Manage them with `PluginQualityAdvisor/exempt_manager.py` as described above.

Key properties:
- **Exemption ≠ Skip.** An exempted rule always still runs and is always still reported — exemption only decides whether a failure lands in the blocking Issue Summary or the Exempted Findings section.
- **Local-only, never committed.** Exemptions live in `PluginQualityAdvisor/Exemptions/*.local.yaml`, which is git-ignored. They are personal working state, not team policy, and do not transfer between machines.
- **Global or scoped.** An exemption applies either everywhere (`scope: "global"`) or only to specific named plugins/interfaces.