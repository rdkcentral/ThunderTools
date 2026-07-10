# ThunderPluginQualityAdvisor

AI-driven validation tools for Thunder plugin and COM interface development, powered by VS Code GitHub Copilot Chat.

---

## Prerequisites

1. **VS Code** with GitHub Copilot Chat extension installed
2. **ThunderNanoServices** and **ThunderInterfaces** repositories in your workspace (or specify the path when prompted)
3. Register the prompt file location in VS Code:

   Open your VS Code `settings.json` (`Ctrl+Shift+P` -> `Preferences: Open User Settings (JSON)`) and add:

```json
   {
     "chat.promptFilesLocations": {
       "ThunderTools/PluginQualityAdvisor/Prompts": true
     }
   }
```

The path should point to the `Prompts` folder inside PluginQualityAdvisor. Use the path relative to your workspace root, or an absolute path if ThunderTools is outside the workspace.

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

**Output:** Failures grouped by file with exact `[File:line]` citations, followed by a summary table and next steps.

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

**Output:** Findings grouped into Violations, Warnings, Suggestions, Validated, and Compatibility Notes.

---

## `/thunder-generate-plugin`

Generates a new Thunder plugin skeleton interactively using PluginSkeletonGenerator.

**Usage:**
```
/thunder-generate-plugin
```

Collects parameters via VS Code dropdowns (plugin name, in-process/out-of-process, JSON-RPC support, etc.) and generates the plugin files.

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

## Project Structure

```
ThunderTools/PluginQualityAdvisor/
+-- README.md
+-- setup-prompts.py
+-- Update-Template-Guide/
|   +-- plugin-rule-template-guide.md
|   +-- interface-rule-template-guide.md
+-- Prompts/
|   +-- thunder-plugin-review.prompt.md
|   +-- thunder-interface-review.prompt.md
|   +-- thunder-generate-plugin.prompt.md
|   +-- thunder-plugin-rule-manager.prompt.md
|   +-- thunder-interface-rule-manager.prompt.md
+-- rules/
|   +-- thunder-plugin-rules.yaml
|   +-- thunder-interface-rules.yaml
+-- Reports/
    +-- plugin/
    |   +-- {PluginName}_{YYYY-MM-DD}.csv
    +-- interface/
        +-- {InterfaceName}_{YYYY-MM-DD}.csv
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

After each review, a CSV report is generated under `Reports/plugin/` or `Reports/interface/`. Reports contain one row per finding with exact file, line, citation, description, fix summary, and reasoning (if severity was downgraded).