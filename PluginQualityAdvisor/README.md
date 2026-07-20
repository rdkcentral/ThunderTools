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

**Output:** Issue summary table with detailed findings, saved as a Markdown report with clickable navigation.

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
    |   +-- {PluginName}_{YYYY-MM-DD}.md
    +-- interface/
        +-- {InterfaceName}_{YYYY-MM-DD}.md
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

After each review, a Markdown report is generated under `Reports/plugin/` or `Reports/interface/`. Reports contain an Issue Summary table with clickable links to Detailed Findings sections, each with a plain-English explanation, code found, and fix.