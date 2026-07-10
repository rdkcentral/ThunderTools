#!/usr/bin/env python3
"""
setup-prompts.py — Registers ThunderTools PluginQualityAdvisor prompts with VS Code.

Adds "ThunderTools/PluginQualityAdvisor/Prompts": true to chat.promptFilesLocations
in VS Code settings.json. Works on Windows, macOS, and Linux.

No external dependencies — stdlib only.
Safe to run multiple times (idempotent). Creates a timestamped backup.
"""

import json
import os
import platform
import shutil
import sys
from datetime import datetime

PROMPTS_KEY = "ThunderTools/PluginQualityAdvisor/Prompts"


def find_settings_path():
    """Detect VS Code settings.json path for the current platform."""
    system = platform.system()

    if system == "Windows":
        appdata = os.environ.get("APPDATA", "")
        candidates = [
            os.path.join(appdata, "Code", "User", "settings.json"),
            os.path.join(appdata, "Code - Insiders", "User", "settings.json"),
        ]
    elif system == "Darwin":
        home = os.path.expanduser("~")
        candidates = [
            os.path.join(home, "Library", "Application Support", "Code", "User", "settings.json"),
            os.path.join(home, "Library", "Application Support", "Code - Insiders", "User", "settings.json"),
        ]
    else:
        # Linux
        home = os.path.expanduser("~")
        candidates = [
            os.path.join(home, ".config", "Code", "User", "settings.json"),
            os.path.join(home, ".config", "Code - Insiders", "User", "settings.json"),
        ]

    # Return the first candidate whose parent directory exists
    for path in candidates:
        parent = os.path.dirname(path)
        if os.path.isdir(parent):
            return path

    # Fall back to first candidate even if parent doesn't exist
    return candidates[0]


def read_settings(settings_path):
    """Read and parse settings.json, returning {} if missing or empty."""
    if not os.path.isfile(settings_path):
        return {}
    with open(settings_path, "r", encoding="utf-8") as f:
        content = f.read().strip()
    if not content:
        return {}
    try:
        return json.loads(content)
    except (json.JSONDecodeError, ValueError):
        print("WARNING: Could not parse settings.json as JSON. Starting with empty settings.")
        return {}


def create_backup(settings_path):
    """Create a timestamped backup of settings.json. Returns backup path."""
    if not os.path.isfile(settings_path):
        return None
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    backup_path = f"{settings_path}.backup.{timestamp}"
    if not os.path.exists(backup_path):
        shutil.copy2(settings_path, backup_path)
        return backup_path
    return backup_path


def main():
    # Allow override via environment variable
    settings_path = os.environ.get("VSCODE_SETTINGS_PATH") or find_settings_path()
    print(f"VS Code settings.json: {settings_path}")

    # Ensure parent directory exists
    settings_dir = os.path.dirname(settings_path)
    os.makedirs(settings_dir, exist_ok=True)

    # Read existing settings
    settings = read_settings(settings_path)

    # Check if already configured (idempotent)
    prompt_locations = settings.get("chat.promptFilesLocations", {})
    if isinstance(prompt_locations, dict) and prompt_locations.get(PROMPTS_KEY) is True:
        print()
        print("Already configured — 'ThunderTools/PluginQualityAdvisor/Prompts' is already in chat.promptFilesLocations.")
        print("No changes needed.")
        print()
        print("Available slash commands:")
        print("  /thunder-plugin-review <PluginName>")
        print("  /thunder-interface-review <InterfaceName>")
        print("  /thunder-generate-plugin")
        print("  /thunder-plugin-rule-manager")
        print("  /thunder-interface-rule-manager")
        sys.exit(0)

    # Create backup before modifying
    backup_path = create_backup(settings_path)
    if backup_path:
        print(f"Backup created: {backup_path}")

    # Merge the new entry
    if not isinstance(prompt_locations, dict):
        prompt_locations = {}
    prompt_locations[PROMPTS_KEY] = True
    settings["chat.promptFilesLocations"] = prompt_locations

    # Write back with indent=4
    with open(settings_path, "w", encoding="utf-8") as f:
        json.dump(settings, f, indent=4)
        f.write("\n")

    # Success output
    print()
    print("SUCCESS: settings.json updated.")
    print()
    if backup_path:
        print(f"Backup location: {backup_path}")
        print()
    print("Next steps:")
    print("  1. In VS Code, press Ctrl+Shift+P (or Cmd+Shift+P on Mac)")
    print("  2. Type 'Developer: Reload Window' and press Enter")
    print()
    print("Available slash commands after reload:")
    print("  /thunder-plugin-review <PluginName>")
    print("  /thunder-interface-review <InterfaceName>")
    print("  /thunder-generate-plugin")
    print("  /thunder-plugin-rule-manager")
    print("  /thunder-interface-rule-manager")
    print()


if __name__ == "__main__":
    main()
