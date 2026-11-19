#!/usr/bin/env python3
"""
exempt_manager.py - Standalone CLI for managing Thunder plugin/interface rule exemptions.

No AI or VS Code required. Reads and writes the local
PluginQualityAdvisor/Exemptions/*.local.yaml files consumed by the plugin and interface review prompts,
so whatever you do here shows up in the next /thunder-plugin-review or /thunder-interface-review run.

No external dependencies - stdlib only (re, argparse, pathlib).

One-shot usage:
    python exempt_manager.py --rule-set plugin list
    python exempt_manager.py --rule-set plugin add rule_14 --scope Dictionary
    python exempt_manager.py --rule-set plugin add --phase phase_6 --scope global
    python exempt_manager.py --rule-set plugin add --category concurrency --scope global
    python exempt_manager.py --rule-set plugin update 2 --scope Legacy,Dictionary
    python exempt_manager.py --rule-set plugin remove 1 3
    python exempt_manager.py --rule-set plugin clear --all
    python exempt_manager.py --rule-set plugin clear --scope Dictionary
    python exempt_manager.py --rule-set plugin clear rule_14

Interactive usage (no arguments at all):
    python exempt_manager.py
"""

import argparse
import re
import sys
from pathlib import Path

_SCRIPT_DIR = Path(__file__).resolve().parent
_EXEMPTIONS_DIR = _SCRIPT_DIR / "Exemptions"
_RULES_DIR = _SCRIPT_DIR / "rules"

RULE_SETS = {
    "plugin": {
        "exemptions_file": _EXEMPTIONS_DIR / "thunder-plugin-exemptions.local.yaml",
        "rules_file": _RULES_DIR / "thunder-plugin-rules.yaml",
        "entry_re": re.compile(r'^\s*-\s*rule_id:\s*"(rule_\d+)"\s*$'),
    },
    "interface": {
        "exemptions_file": _EXEMPTIONS_DIR / "thunder-interface-exemptions.local.yaml",
        "rules_file": _RULES_DIR / "thunder-interface-rules.yaml",
        "entry_re": re.compile(r'^\s*-\s*id:\s*"([A-Za-z0-9_]+)"\s*$'),
    },
}

# Small, near-permanent lookup for human-readable group headings only.
# Rule -> group MEMBERSHIP is never hardcoded here; it's read live from the
# rules YAML every run (see load_rule_index below), so adding rule_86 tomorrow
# needs zero changes to this script.
GROUP_LABELS = {
    "phase_1_checkpoints": "Phase 1 - Module Structure",
    "phase_2_checkpoints": "Phase 2 - Code Style",
    "phase_3_checkpoints": "Phase 3 - Class Registration",
    "phase_4_checkpoints": "Phase 4 - Lifecycle",
    "phase_5_checkpoints": "Phase 5 - Implementation",
    "phase_5C_checkpoints": "Phase 5C - Out-of-Process",
    "phase_6_checkpoints": "Phase 6 - Configuration",
    "phase_7_checkpoints": "Phase 7 - CMake",
    "phase_8_checkpoints": "Phase 8 - COM Interface",
    "conventions": "Conventions & Encapsulation",
    "lifecycle_integrity": "Lifecycle & State Integrity",
    "concurrency": "Concurrency & Threading",
    "com_safety": "COM Reference & Memory Safety",
    "resource_management": "Resource Management",
    "jsonrpc_compliance": "JSON-RPC Compliance",
    "inter_plugin_design": "Inter-Plugin & OOP Design",
    "code_quality_security": "Code Quality & Security",
    "core_rules": "Core Rules",
    "advisory_rules": "Advisory Rules",
}


# ===========================================================================
# Rule index - a targeted regex line-scanner, NOT a general YAML parser.
# Only ever reads the handful of simple "key: value" fields it needs
# (rule_id/id, name, severity, category) and ignores everything else in the
# file, including multi-line fix_template/verification_logic blocks.
# ===========================================================================

_SECTION_RE = re.compile(r'^([A-Za-z0-9_]+):\s*$')
_NAME_RE = re.compile(r'^\s*name:\s*"(.*)"\s*$')
_SEVERITY_RE = re.compile(r'^\s*severity:\s*"(.*)"\s*$')
_CATEGORY_RE = re.compile(r'^\s*category:\s*"(.*)"\s*$')


def load_rule_index(rule_set):
    """Return {id: {"group": ..., "name": ..., "severity": ...}} read live from the rules YAML."""
    cfg = RULE_SETS[rule_set]
    path = cfg["rules_file"]
    if not path.exists():
        return {}

    index = {}
    section = None
    current_id = None
    entry_re = cfg["entry_re"]

    with path.open("r", encoding="utf-8") as f:
        for raw in f:
            line = raw.rstrip("\n")

            if line and not line[0].isspace():
                m = _SECTION_RE.match(line)
                if m:
                    section = m.group(1)
                    current_id = None
                    continue

            m = entry_re.match(line)
            if m:
                current_id = m.group(1)
                index[current_id] = {"group": section}
                continue

            if current_id is None:
                continue

            m = _NAME_RE.match(line)
            if m:
                index[current_id]["name"] = m.group(1)
                continue
            m = _SEVERITY_RE.match(line)
            if m:
                index[current_id]["severity"] = m.group(1)
                continue
            m = _CATEGORY_RE.match(line)
            if m:
                # Only general_rules entries have a category field; this
                # refines their group beyond the flat "general_rules" section.
                index[current_id]["group"] = m.group(1)
                continue

    return index


# ===========================================================================
# Exemptions file I/O - hand-rolled reader/writer for the simple, flat
# exemptions schema. No PyYAML needed.
# ===========================================================================

_ENTRY_ID_RE = re.compile(r'^\s*-\s*(rule_id|id|phase|category):\s*"([^"]*)"\s*$')
_SCOPE_LIST_RE = re.compile(r'^\s*scope:\s*\[(.*)\]\s*$')
_SCOPE_STR_RE = re.compile(r'^\s*scope:\s*"([^"]*)"\s*$')


def load_exemptions(path):
    """Return a list of {"key": ..., "value": ..., "scope": ...} dicts."""
    if not path.exists():
        return []

    entries = []
    current = None

    with path.open("r", encoding="utf-8") as f:
        for raw in f:
            line = raw.rstrip("\n")
            stripped = line.strip()
            if not stripped or stripped.startswith("#"):
                continue

            m = _ENTRY_ID_RE.match(line)
            if m:
                if current is not None:
                    entries.append(current)
                current = {"key": m.group(1), "value": m.group(2), "scope": "global"}
                continue

            if current is None:
                continue

            m = _SCOPE_LIST_RE.match(line)
            if m:
                items = [item.strip().strip('"').strip("'") for item in m.group(1).split(",") if item.strip()]
                current["scope"] = items
                continue
            m = _SCOPE_STR_RE.match(line)
            if m:
                current["scope"] = m.group(1)
                continue

    if current is not None:
        entries.append(current)

    return entries


def format_scope(scope):
    if isinstance(scope, str):
        return f'"{scope}"'
    return "[" + ", ".join(f'"{s}"' for s in scope) + "]"


def scope_display(scope):
    return scope if isinstance(scope, str) else ", ".join(scope)


def save_exemptions(path, entries):
    path.parent.mkdir(parents=True, exist_ok=True)
    lines = []
    if not entries:
        lines.append("exemptions: []")
    else:
        lines.append("exemptions:")
        for e in entries:
            lines.append(f'  - {e["key"]}: "{e["value"]}"')
            lines.append(f'    scope: {format_scope(e["scope"])}')
    content = "\n".join(lines) + "\n"
    with path.open("w", encoding="utf-8", newline="\n") as f:
        f.write(content)


def parse_scope(raw):
    raw = raw.strip()
    if not raw:
        raise ValueError("scope cannot be empty")
    if raw.lower() == "global":
        return "global"
    names = [n.strip() for n in raw.split(",") if n.strip()]
    if not names:
        raise ValueError("scope cannot be empty")
    return names


def print_current_state(entries):
    if not entries:
        print("No exemptions recorded yet.")
        return
    print(f"{'#':<4}{'Identifier':<16}{'Scope'}")
    print("-" * 50)
    for i, e in enumerate(entries, start=1):
        print(f"{i:<4}{e['value']:<16}{scope_display(e['scope'])}")


# ===========================================================================
# Core operations - shared by both the one-shot subcommands and the
# interactive menu, so behavior can never drift between the two.
# ===========================================================================

def op_add(path, key, value, scope):
    entries = load_exemptions(path)
    entries.append({"key": key, "value": value, "scope": scope})
    save_exemptions(path, entries)
    return len(entries)


def op_update(path, index, scope):
    entries = load_exemptions(path)
    if not (1 <= index <= len(entries)):
        raise IndexError(f"no exemption #{index} (there are {len(entries)})")
    entries[index - 1]["scope"] = scope
    save_exemptions(path, entries)
    return entries[index - 1]


def op_remove(path, indices):
    entries = load_exemptions(path)
    removed = []
    for i in sorted(set(indices), reverse=True):
        if 1 <= i <= len(entries):
            removed.append(entries.pop(i - 1))
    save_exemptions(path, entries)
    return list(reversed(removed)), len(entries)


def op_clear_all(path):
    entries = load_exemptions(path)
    save_exemptions(path, [])
    return len(entries)


def op_clear_by_scope(path, name):
    entries = load_exemptions(path)
    kept, removed = [], 0
    for e in entries:
        names = [e["scope"]] if isinstance(e["scope"], str) else e["scope"]
        if name in names:
            removed += 1
        else:
            kept.append(e)
    save_exemptions(path, kept)
    return removed, len(kept)


def op_clear_by_rule(path, rule_id):
    entries = load_exemptions(path)
    kept = [e for e in entries if e["value"] != rule_id]
    removed = len(entries) - len(kept)
    save_exemptions(path, kept)
    return removed, len(kept)


# ===========================================================================
# One-shot subcommands
# ===========================================================================

def cmd_list(args, path):
    print_current_state(load_exemptions(path))


def cmd_add(args, path):
    provided = [x for x in [args.identifier, args.phase, args.category] if x]
    if len(provided) != 1:
        print("Error: provide exactly one of: rule_id (positional), --phase, or --category", file=sys.stderr)
        sys.exit(1)

    index = load_rule_index(args.rule_set)
    known_ids = set(index.keys())
    known_groups = set()
    for info in index.values():
        g = info.get("group")
        if not g:
            continue
        known_groups.add(g)
        # The exemptions schema uses the short form ("phase_6"), while the
        # rule index's group value for phase checkpoints is the raw YAML
        # section name ("phase_6_checkpoints") -- accept both.
        if g.endswith("_checkpoints"):
            known_groups.add(g[: -len("_checkpoints")])

    if args.identifier:
        if args.identifier not in known_ids:
            print(f"Warning: '{args.identifier}' was not found in the current rule definitions - adding anyway.", file=sys.stderr)
        key, value = "rule_id", args.identifier
    elif args.phase:
        if args.phase not in known_groups:
            print(f"Warning: phase '{args.phase}' was not found in the current rule definitions - adding anyway.", file=sys.stderr)
        key, value = "phase", args.phase
    else:
        if args.category not in known_groups:
            print(f"Warning: category '{args.category}' was not found in the current rule definitions - adding anyway.", file=sys.stderr)
        key, value = "category", args.category

    try:
        scope = parse_scope(args.scope)
    except ValueError as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

    total = op_add(path, key, value, scope)
    print(f"Added exemption: {value} (scope: {scope_display(scope)})")
    print(f"Total exemptions: {total}")


def cmd_update(args, path):
    try:
        scope = parse_scope(args.scope)
    except ValueError as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)
    try:
        entry = op_update(path, args.index, scope)
    except IndexError as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)
    print(f"Updated exemption #{args.index}: {entry['value']} scope changed to {scope_display(scope)}")


def cmd_remove(args, path):
    removed, remaining = op_remove(path, args.indices)
    if not removed:
        print("Nothing removed - no matching exemption numbers.", file=sys.stderr)
        sys.exit(1)
    for e in removed:
        print(f"Removed: {e['value']} ({scope_display(e['scope'])})")
    print(f"Total exemptions: {remaining}")


def cmd_clear(args, path):
    if args.all:
        entries = load_exemptions(path)
        if not entries:
            print("No exemptions to clear.")
            return
        answer = input(f"This will remove all {len(entries)} exemptions. Continue? [y/N]: ").strip().lower()
        if answer != "y":
            print("Cancelled.")
            return
        count = op_clear_all(path)
        print(f"Cleared all {count} exemptions.")
    elif args.scope:
        removed, remaining = op_clear_by_scope(path, args.scope)
        print(f'Removed {removed} exemption(s) scoped to "{args.scope}". {remaining} remain.')
    elif args.rule_id:
        removed, remaining = op_clear_by_rule(path, args.rule_id)
        print(f"Removed {removed} exemption entry(ies) for {args.rule_id}. {remaining} remain.")
    else:
        print("Error: specify --all, --scope NAME, or a rule_id.", file=sys.stderr)
        sys.exit(1)


# ===========================================================================
# Interactive menu - no AI, no VS Code, plain terminal input().
# ===========================================================================

def ask_scope():
    choice = input("Apply to: [1] Global  [2] Specific name(s)\n> ").strip()
    if choice == "1":
        return "global"
    names = input("Name(s), comma-separated: ").strip()
    return parse_scope(names)


def interactive_add(rule_set, path):
    """Phase-cart flow: pick a group, select rules, land back on the group
    menu, repeat across as many groups as desired. Submitting the group menu
    with nothing typed (just pressing Enter) is the finish action -- there is
    no separate "Submit" list entry, matching the AI-prompt design this
    mirrors. Nothing is written until that single, consolidated finish."""
    index = load_rule_index(rule_set)
    groups = {}
    for rid, info in index.items():
        g = info.get("group") or "ungrouped"
        groups.setdefault(g, []).append(rid)
    group_keys = sorted(groups.keys())

    already = {e["value"] for e in load_exemptions(path) if e["key"] == "rule_id"}
    staged = []  # accumulates across groups; nothing written until finish

    while True:
        staged_set = set(staged)
        print()
        if staged:
            print(f"Staged so far: {len(staged)} rule(s) -> {', '.join(staged)}")
        print("Pick a group (or type a rule ID directly, e.g. rule_14).")
        print("Press Enter with nothing typed to finish and write what's staged:")
        for i, g in enumerate(group_keys, start=1):
            exempt_count = sum(1 for rid in groups[g] if rid in already or rid in staged_set)
            suffix = f", {exempt_count} exempted" if exempt_count else ""
            print(f"  [{i}] {GROUP_LABELS.get(g, g)} ({len(groups[g])} rules{suffix})")
        choice = input("> ").strip()

        if not choice:
            break  # empty input at the group menu IS the finish action

        if choice.isdigit() and 1 <= int(choice) <= len(group_keys):
            g = group_keys[int(choice) - 1]
            rule_ids = sorted(groups[g])
            print()
            print(f"{GROUP_LABELS.get(g, g)}:")
            for i, rid in enumerate(rule_ids, start=1):
                info = index[rid]
                mark = ""
                if rid in already:
                    mark = "  (already exempted)"
                elif rid in staged_set:
                    mark = "  (staged this session)"
                print(f"  [{i}] {rid} - {info.get('name', '(no name)')} ({info.get('severity', '?')}){mark}")
            picks = input("Pick one or more (comma-separated), or 'b' to go back without selecting: ").strip()
            if picks.lower() == "b" or not picks:
                continue  # back to the group menu, nothing staged from here
            for p in picks.split(","):
                p = p.strip()
                if p.isdigit() and 1 <= int(p) <= len(rule_ids):
                    rid = rule_ids[int(p) - 1]
                    if rid not in staged:
                        staged.append(rid)
            continue  # always return to the group menu, never write here

        # Anything else is treated as a direct rule ID typed by hand.
        if choice not in index:
            print(f"Warning: '{choice}' was not found in the current rule definitions - staging anyway.")
        if choice not in staged:
            staged.append(choice)
        continue

    if not staged:
        print("Nothing staged -- nothing written.")
        return

    print()
    print("Staged: " + ", ".join(staged))
    try:
        scope = ask_scope()
    except ValueError as e:
        print(f"Error: {e}")
        return

    print()
    print("About to add:")
    for rid in staged:
        print(f"  {rid} -> scope: {scope_display(scope)}")
    if input("Confirm? [y/N]: ").strip().lower() != "y":
        print("Cancelled.")
        return

    entries = load_exemptions(path)
    for rid in staged:
        entries.append({"key": "rule_id", "value": rid, "scope": scope})
    save_exemptions(path, entries)
    print(f"Added {len(staged)} exemption(s). Total: {len(entries)}")


def interactive_update(path):
    entries = load_exemptions(path)
    if not entries:
        print("No exemptions to update.")
        return
    print_current_state(entries)
    raw = input("Which # to update? ").strip()
    if not raw.isdigit():
        print("Invalid selection.")
        return
    try:
        scope = ask_scope()
    except ValueError as e:
        print(f"Error: {e}")
        return
    try:
        entry = op_update(path, int(raw), scope)
    except IndexError as e:
        print(f"Error: {e}")
        return
    print(f"Updated #{raw}: {entry['value']} scope changed to {scope_display(scope)}")


def interactive_remove(path):
    entries = load_exemptions(path)
    if not entries:
        print("No exemptions to remove.")
        return
    print_current_state(entries)
    raw = input("Which #(s) to remove (comma-separated)? ").strip()
    indices = [int(p.strip()) for p in raw.split(",") if p.strip().isdigit()]
    if not indices:
        print("Nothing selected.")
        return
    removed, remaining = op_remove(path, indices)
    for e in removed:
        print(f"Removed: {e['value']} ({scope_display(e['scope'])})")
    print(f"Total exemptions: {remaining}")


def interactive_clear(path):
    entries = load_exemptions(path)
    if not entries:
        print("No exemptions to clear.")
        return
    print("Clear which exemptions?")
    print("  [1] Everything")
    print("  [2] By name/scope")
    print("  [3] By rule ID")
    choice = input("> ").strip()
    if choice == "1":
        if input(f"This will remove all {len(entries)} exemptions. Continue? [y/N]: ").strip().lower() == "y":
            count = op_clear_all(path)
            print(f"Cleared all {count} exemptions.")
        else:
            print("Cancelled.")
    elif choice == "2":
        name = input("Name/scope to clear: ").strip()
        removed, remaining = op_clear_by_scope(path, name)
        print(f'Removed {removed} exemption(s) scoped to "{name}". {remaining} remain.')
    elif choice == "3":
        rid = input("Rule ID to clear: ").strip()
        removed, remaining = op_clear_by_rule(path, rid)
        print(f"Removed {removed} exemption entry(ies) for {rid}. {remaining} remain.")
    else:
        print("Not a valid choice.")


def interactive_menu(rule_set):
    cfg = RULE_SETS[rule_set]
    path = cfg["exemptions_file"]

    while True:
        entries = load_exemptions(path)
        print()
        print(f"=== Current {rule_set.title()} Exemptions ===")
        print_current_state(entries)
        print()
        print("What do you want to do?")
        print("  [1] List exemptions")
        print("  [2] Add an exemption")
        print("  [3] Update an exemption")
        print("  [4] Remove exemption(s)")
        print("  [5] Clear exemptions")
        print("  [0] Quit")
        choice = input("> ").strip().lower()

        if choice in ("0", "q", "quit"):
            break
        elif choice == "1":
            continue
        elif choice == "2":
            interactive_add(rule_set, path)
        elif choice == "3":
            interactive_update(path)
        elif choice == "4":
            interactive_remove(path)
        elif choice == "5":
            interactive_clear(path)
        else:
            print("Not a valid choice.")


# ===========================================================================
# Argument parsing
# ===========================================================================

def build_parser():
    parser = argparse.ArgumentParser(
        prog="exempt_manager.py",
        description="Standalone CLI for Thunder rule exemptions - no AI or VS Code required.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__,
    )
    parser.add_argument("--rule-set", choices=["plugin", "interface"], default=None,
                         help="Which exemptions file to operate on. If omitted: asked up front "
                              "in interactive mode, defaults to plugin for one-shot commands.")

    sub = parser.add_subparsers(dest="command")

    sub.add_parser("list", help="Show current exemptions")

    p_add = sub.add_parser("add", help="Add an exemption")
    p_add.add_argument("identifier", nargs="?", help="rule_id, e.g. rule_14")
    p_add.add_argument("--phase", help="Exempt an entire phase group instead of one rule")
    p_add.add_argument("--category", help="Exempt an entire holistic category instead of one rule")
    p_add.add_argument("--scope", required=True, help='"global" or comma-separated names')

    p_update = sub.add_parser("update", help="Update an exemption's scope")
    p_update.add_argument("index", type=int, help="# from `list`")
    p_update.add_argument("--scope", required=True, help='"global" or comma-separated names')

    p_remove = sub.add_parser("remove", help="Remove one or more exemptions")
    p_remove.add_argument("indices", type=int, nargs="+", help="One or more # from `list`")

    p_clear = sub.add_parser("clear", help="Clear exemptions")
    p_clear.add_argument("rule_id", nargs="?", help="Clear only entries for this rule ID")
    p_clear.add_argument("--all", action="store_true", help="Clear everything (asks to confirm)")
    p_clear.add_argument("--scope", help="Clear only entries scoped to this name")

    return parser


def ask_rule_set():
    print("Which rule set?")
    print("  [1] Plugin rules (85 rules)")
    print("  [2] Interface rules (19 rules)")
    choice = input("> ").strip()
    return "interface" if choice == "2" else "plugin"


def main():
    parser = build_parser()
    args = parser.parse_args()

    if args.command is None:
        # Interactive mode: ask up front if --rule-set wasn't given explicitly.
        rule_set = args.rule_set or ask_rule_set()
        interactive_menu(rule_set)
        return

    # One-shot subcommands: keep defaulting to plugin when not specified,
    # since --rule-set is already available right there on the command line.
    args.rule_set = args.rule_set or "plugin"
    cfg = RULE_SETS[args.rule_set]
    path = cfg["exemptions_file"]

    if args.command == "list":
        cmd_list(args, path)
    elif args.command == "add":
        cmd_add(args, path)
    elif args.command == "update":
        cmd_update(args, path)
    elif args.command == "remove":
        cmd_remove(args, path)
    elif args.command == "clear":
        cmd_clear(args, path)


if __name__ == "__main__":
    main()
