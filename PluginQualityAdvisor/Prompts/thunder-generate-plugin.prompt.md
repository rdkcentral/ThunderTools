## Overview

This prompt generates a Thunder plugin skeleton by:
1. Collecting plugin parameters via `vscode_askQuestions` (NOT chat messages)
2. Locating `PluginSkeletonGenerator.py` (PSG) in the workspace
3. Running PSG interactively and feeding answers to each prompt in order
4. Auto-fixing include path bugs in generated header files (PSG workaround)

### CRITICAL RULES

- **Always use `vscode_askQuestions`** to collect parameters - never ask in chat
- **Only run PSG** - do not create, modify, or delete plugin files manually
- **Auto-fix include paths** in generated .h files after PSG completes (known PSG bug)
- **Do not modify anything else** in generated files
- **NO `--config` flag** - PSG's interactive mode is more reliable than the config path

---

## Required Inputs from User

| Parameter | Format | Options | Default |
|-----------|--------|---------|---------|
| PluginName | Valid C++ identifier | e.g. HelloWorld, NetworkControl | (required) |
| OutputDirectory | Path string | Absolute or relative | current directory |
| OutOfProcess | Boolean | Yes / No | No |
| CustomConfig | Boolean | Yes / No | No |
| InterfacePaths | Semicolon-separated paths | One or more .h files | (empty) |
| SelectInterfaces | Semicolon-separated | e.g. IWifiControl;IWifiDiagnostics | ALL (empty = all) |
| IncludeLocations | Semicolon-separated HEADER:PATH | e.g. IWifiControl.h:custom_vendor | interfaces (default) |
| Preconditions | Comma-separated strings | e.g. PLATFORM,NETWORK | (empty) |
| Terminations | Comma-separated strings | e.g. PLATFORM | (empty) |
| Controls | Comma-separated strings | e.g. SUBSYSTEM | (empty) |

---

## Step 1 - Collect Parameters via vscode_askQuestions

**MANDATORY:** Always ask ALL 10 questions below in a single `vscode_askQuestions` call. Never skip or omit any question — even if some appear conditional, they must all be presented to the user every time:

```json
[
  {
    "header": "PluginName",
    "question": "What is the name of your plugin? (e.g. HelloWorld, NetworkControl)",
    "message": "Must be a valid C++ identifier (letters, digits, underscore; cannot start with a digit). This becomes the class name, file names, and CMake target."
  },
  {
    "header": "OutputDirectory",
    "question": "Where should the plugin be generated?",
    "message": "Leave blank for the default: current working directory. Or enter an absolute path."
  },
  {
    "header": "OutOfProcess",
    "question": "Should the plugin run out-of-process (OOP)?",
    "options": [
      { "label": "No", "description": "In-process plugin (default)", "recommended": true },
      { "label": "Yes", "description": "Out-of-process plugin - generates Implementation files" }
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
    "header": "SelectInterfaces",
    "question": "Which interfaces to generate from multi-interface headers? (semicolon-separated, or leave blank for ALL)",
    "message": "Only needed when a header contains multiple root interfaces. Example: IWifiControl;IWifiDiagnostics. Leave blank to generate code for ALL interfaces found in each header."
  },
  {
    "header": "IncludeLocations",
    "question": "Custom include locations for interface headers? (HEADER:PATH pairs semicolon-separated, or leave blank for default)",
    "message": "Controls the #include path in generated code. Default is 'interfaces' (generates #include <interfaces/IFoo.h>). Example: IWifiControl.h:custom_vendor generates #include <custom_vendor/IWifiControl.h>. Leave blank to use default for all."
  },
  {
    "header": "Preconditions",
    "question": "Subsystem preconditions? (comma-separated, or leave blank)",
    "message": "Example: PLATFORM,NETWORK - these are Thunder subsystems that must be active before this plugin starts"
  },
  {
    "header": "Terminations",
    "question": "Subsystem terminations? (comma-separated, or leave blank)",
    "message": "Example: PLATFORM - subsystems to signal when this plugin terminates"
  },
  {
    "header": "Controls",
    "question": "Subsystem controls? (comma-separated, or leave blank)",
    "message": "Example: SUBSYSTEM - subsystems this plugin controls"
  }
]
```

### Answer processing rules:

- `Yes` / `No` dropdown answers → convert to `y` / `n` for PSG prompts
- Empty `OutputDirectory` → use current working directory (PSG's default)
- Multiple interface paths (semicolon-separated) → feed one per PSG prompt, then `Enter` on empty line
- **SelectInterfaces:** If empty → send Enter (accept ALL) at PSG's `[SELECT]` prompt. If populated → parse semicolon-separated names and send the corresponding index numbers (e.g. `1,3`) when PSG asks `Pick indices`
- **IncludeLocations:** If empty → send Enter (accept default `interfaces`) for each header's location prompt. If populated → parse `HEADER:PATH` pairs and send the PATH value when PSG asks `Location for HEADER`
- Subsystems conditional: if ANY of Preconditions, Terminations, or Controls is non-empty → answer PSG's "Does your plugin rely on Thunder subsystems?" with `y`; otherwise `n`
- Subsystem entries: PSG expects **one entry per line** (not comma-separated). Split the comma-separated input and send each entry individually, followed by an empty Enter to finish the list
- **Validation:** If OutOfProcess = Yes AND InterfacePaths is empty → report error "Out-of-process plugins require at least one interface header" and stop before running PSG

---

## Step 2 - Locate PSG

Search for `PluginSkeletonGenerator.py` in the workspace:
- Primary: `ThunderTools/PluginSkeletonGenerator/PluginSkeletonGenerator.py`
- Fallback: search workspace for `PluginSkeletonGenerator.py`
- If not found: report the error and ask the user for the path

---

## Step 3 - Run PSG Interactively

Change to the output directory, then run:
```
python <path-to-PluginSkeletonGenerator.py>
```

Feed answers to PSG's prompts **in exact order**:

| # | PSG Prompt (watch for this text) | Answer to send |
|---|-----------|--------|
| 1 | `What will your plugin be called:` | PluginName from Step 1 |
| 2 | `Where should the plugin be generated?` | OutputDirectory (or Enter for current dir) |
| 3 | `Is your plugin out of process? (Y/N)` | y or n (from OutOfProcess) |
| 4 | `Custom plugin specific configuration needed? (Y/N)` | y or n (from CustomConfig) |
| 5 | `Path to interface (or press Enter to finish):` | Each InterfacePaths entry one at a time, then Enter on empty line |
| 6 | `Does your plugin rely on Thunder subsystems` | y if any subsystem fields non-empty, n otherwise |
| 7 | `Precondition:` (one per line, if subsystems = y) | Each precondition value individually, then Enter on empty line |
| 8 | `Termination:` (one per line, if subsystems = y) | Each termination value individually, then Enter on empty line |
| 9 | `Control:` (one per line, if subsystems = y) | Each control value individually, then Enter on empty line |
| 10 | **`[SELECT] Please pick which interfaces...`** | If SelectInterfaces is empty: send Enter (= ALL). Otherwise: send comma-separated indices matching the desired interface names |
| 11 | **`Location for <HEADER> [<interfaces>]:`** | If IncludeLocations has a matching HEADER:PATH entry: send PATH. Otherwise: send Enter (= default `interfaces`). This prompt fires ONCE per header file. |

**CRITICAL:** Steps 10 and 11 only appear when interface headers are provided (Step 5 was non-empty).
- Step 10 only shows the selection prompt if a header contains **multiple** root interfaces. If each header has exactly one interface, PSG skips this prompt.
- Step 11 **always** appears once per header file (even for single-interface headers).

After PSG completes, report the generated files.

---

## Post-Generation - Auto-Fix Include Paths

PSG has a known bug where generated `.h` files have incorrect include paths. After PSG completes:

1. Read each generated `.h` file
2. Fix include paths that reference non-existent relative locations
3. Correct to proper Thunder include paths (e.g. `#include <core/core.h>` → `#include "Module.h"` where appropriate)
4. **Make no other changes** to any generated file

List all fixed include paths in the output.

---

## Error Handling

- **PSG not found:** "PluginSkeletonGenerator.py not found. Please provide the path."
- **Generation failure:** Report the PSG error output and stop - do not attempt manual file creation
- **Invalid PluginName:** If PluginName is not a valid C++ identifier (letters, digits, underscore; cannot start with a digit), warn the user and ask for a corrected name before running PSG
- **OOP without headers:** If OutOfProcess = Yes and no InterfacePaths provided → error before running PSG: "Out-of-process plugins require at least one interface header path."
- **Directory already exists:** If `<OutputDirectory>/<PluginName>/` already exists, PSG will exit with error. Report this and ask the user to choose a different name or remove the existing directory.
- **Header file not found:** If any InterfacePaths entry does not exist on disk, PSG will exit. Validate paths before running if possible.