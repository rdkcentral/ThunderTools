---
title: "Thunder Plugin Generator"
description: "Interactive Thunder plugin skeleton generator using PluginSkeletonGenerator.py — collects parameters via VS Code dialogs and runs PSG in interactive mode"
---

## Overview

This prompt generates a Thunder plugin skeleton by:
1. Collecting plugin parameters via `vscode_askQuestions` (NOT chat messages)
2. Locating `PluginSkeletonGenerator.py` (PSG) in the workspace
3. Running PSG interactively and feeding answers to each prompt in order
4. Auto-fixing include path bugs in generated header files (PSG workaround)

### CRITICAL RULES

- **Always use `vscode_askQuestions`** to collect parameters — never ask in chat
- **Only run PSG** — do not create, modify, or delete plugin files manually
- **Auto-fix include paths** in generated .h files after PSG completes (known PSG bug)
- **Do not modify anything else** in generated files
- **NO `--config` flag** — PSG's interactive mode is more reliable than the config path

---

## Required Inputs from User

| Parameter | Format | Options | Default |
|-----------|--------|---------|---------|
| PluginName | PascalCase string | e.g. HelloWorld, NetworkControl | (required) |
| OutputDirectory | Path string | Absolute or relative | ThunderNanoServices |
| OutOfProcess | Boolean | Yes / No | No |
| CustomConfig | Boolean | Yes / No | No |
| InterfacePaths | Semicolon-separated paths | One or more .h files | (empty) |
| Preconditions | Comma-separated strings | e.g. PLATFORM,NETWORK | (empty) |
| Terminations | Comma-separated strings | e.g. PLATFORM | (empty) |
| Controls | Comma-separated strings | e.g. SUBSYSTEM | (empty) |

---

## Step 1 — Collect Parameters via vscode_askQuestions

Collect all parameters in a single `vscode_askQuestions` call:

```json
[
  {
    "header": "PluginName",
    "question": "What is the name of your plugin? (PascalCase, e.g. HelloWorld)",
    "message": "Use PascalCase. This becomes the class name, file names, and CMake target."
  },
  {
    "header": "OutputDirectory",
    "question": "Where should the plugin be generated?",
    "message": "Leave blank for the default: ThunderNanoServices. Or enter an absolute path."
  },
  {
    "header": "OutOfProcess",
    "question": "Should the plugin run out-of-process (OOP)?",
    "options": [
      { "label": "No", "description": "In-process plugin (default)", "recommended": true },
      { "label": "Yes", "description": "Out-of-process plugin — generates Implementation files" }
    ]
  },
  {
    "header": "CustomConfig",
    "question": "Does the plugin have custom configuration?",
    "options": [
      { "label": "No", "description": "No custom config class", "recommended": true },
      { "label": "Yes", "description": "Generates a Config class inheriting Core::JSON::Container" }
    ]
  },
  {
    "header": "InterfacePaths",
    "question": "Interface header files to include? (semicolon-separated paths, or leave blank)",
    "message": "Example: ThunderInterfaces/interfaces/IDictionary.h;ThunderInterfaces/interfaces/INetworkControl.h"
  },
  {
    "header": "Preconditions",
    "question": "Subsystem preconditions? (comma-separated, or leave blank)",
    "message": "Example: PLATFORM,NETWORK — these are Thunder subsystems that must be active before this plugin starts"
  },
  {
    "header": "Terminations",
    "question": "Subsystem terminations? (comma-separated, or leave blank)",
    "message": "Example: PLATFORM — subsystems to signal when this plugin terminates"
  },
  {
    "header": "Controls",
    "question": "Subsystem controls? (comma-separated, or leave blank)",
    "message": "Example: SUBSYSTEM — subsystems this plugin controls"
  }
]
```

### Answer processing rules:

- `Yes` / `No` dropdown answers → convert to `y` / `n` for PSG prompts
- Empty `OutputDirectory` → use `ThunderNanoServices` as the output directory
- Subsystems conditional: if ANY of Preconditions, Terminations, or Controls is non-empty → answer PSG's "Does your plugin rely on Thunder subsystems?" with `y`; otherwise `n`
- Multiple interface paths (semicolon-separated) → feed one per PSG prompt, then `Enter` on empty line

---

## Step 2 — Locate PSG

Search for `PluginSkeletonGenerator.py` in the workspace:
- Primary: `ThunderTools/PluginSkeletonGenerator/PluginSkeletonGenerator.py`
- Fallback: search workspace for `PluginSkeletonGenerator.py`
- If not found: report the error and ask the user for the path

---

## Step 3 — Run PSG Interactively

Change to the output directory, then run:
```
python <path-to-PluginSkeletonGenerator.py>
```

Feed answers to PSG's prompts **in exact order**:

| PSG Prompt | Answer |
|-----------|--------|
| Plugin name | PluginName from Step 1 |
| Out of process? | y or n (from OutOfProcess) |
| Custom config? | y or n (from CustomConfig) |
| Interface paths (one per prompt, blank line to finish) | Each InterfacePaths entry, then Enter on empty |
| Does your plugin rely on Thunder subsystems? | y if any subsystem fields non-empty, n otherwise |
| Preconditions (if subsystems = y) | Preconditions value |
| Terminations (if subsystems = y) | Terminations value |
| Controls (if subsystems = y) | Controls value |

After PSG completes, report the generated files.

---

## Post-Generation — Auto-Fix Include Paths

PSG has a known bug where generated `.h` files have incorrect include paths. After PSG completes:

1. Read each generated `.h` file
2. Fix include paths that reference non-existent relative locations
3. Correct to proper Thunder include paths (e.g. `#include <core/core.h>` → `#include "Module.h"` where appropriate)
4. **Make no other changes** to any generated file

List all fixed include paths in the output.

---

## Error Handling

- **PSG not found:** "PluginSkeletonGenerator.py not found. Please provide the path."
- **Generation failure:** Report the PSG error output and stop — do not attempt manual file creation
- **Invalid PluginName:** If PluginName is not PascalCase or contains invalid characters, warn the user and ask for a corrected name before running PSG
