import os
import sys
import yaml
import argparse
from typing import Dict, Tuple, List
from parser.Parser import Printer, ClassData
from parser.MultiParser import MultiParser
from core.GeneratorCoordinator import GeneratorCoordinator
 
 
def loadYAML(file_path: str) -> Dict:
    if not os.path.isfile(file_path):
        print(f"[ERROR]: Config file '{file_path}' does not exist")
        sys.exit(1)
    try:
        with open(file_path, "r") as f:
            return yaml.safe_load(f)
    except yaml.YAMLError as e:
        print(f"[ERROR]: Failed to parse: {e}")

def validatePaths(paths: List[str]) -> None:
    files = [p for p in paths if not os.path.isfile(p)]
    if files:
        print(f"[ERROR]: Following header paths do not exist: ")
        for missing in files:
            print(f"-{missing}")
        sys.exit(1)

def collectList(label: str) -> List[str]:
        print(f"\nEnter {label} (press Enter on empty line to finish):")
        entries = []
        while True:
            entry = input(f"{label[:-1]}: ").strip()
            if not entry:
                break
            entries.append(entry)
        return entries
 
def prompts() -> Tuple[str, bool, bool, List[str], Dict[str, str], List[str], List[str], List[str]]:
    print("=== Plugin Generator ===")
 
    plugin_name = input("What will your plugin be called: ").strip()
    out_of_process = input("Is your plugin out of process? (Y/N): ").strip().lower() == "y"
    plugin_config = input("Custom plugin specific configuration needed? (Y/N): ").strip().lower() == "y"
 
    header_files = []
    print("\nAdd FULL path to your interface (C++ IDL header file)...")
    print("Example: /home/Thunder/ThunderInterfaces/interfaces/ITestInterface.h")
    while True:
        path = input("Path to interface (or press Enter to finish): ").strip()
        if not path:
            break
        header_files.append(path)
 
    if not header_files:
        print("Error: At least one header path must be provided")
        sys.exit(1)

    validatePaths(header_files)
 
    subsystems_enabled = input("\nDoes your plugin rely on Thunder subsystems [Preconditions, Terminations, Controls]? (Y/N): ").strip().lower() == "y"
 
 
    preconditions = collectList("Preconditions") if subsystems_enabled else []
    terminations = collectList("Terminations") if subsystems_enabled else []
    controls = collectList("Controls") if subsystems_enabled else []
 
    return plugin_name, out_of_process, plugin_config, header_files, {}, preconditions, terminations, controls
 
 
def parserInterfaces(header_files: List[str]) -> Tuple[Dict[str, Tuple[ClassData, str]], Dict[str, str]]:
    parser = MultiParser(header_files)
    parsed_data = parser.parseAll()
    header_lookup = parser.m_header_lookup
    return parsed_data, header_lookup
 
 
def displayParsedData(parsed_data: Dict[str, Tuple[ClassData, str]]) -> None:
    print("=" * 30)
    print(f"[INFO] Parsed {len(parsed_data)} interfaces:")
    for name, (class_data, header) in parsed_data.items():
        print(f"[INFO]: {name} (from {header})")
        Printer.printTree(class_data)
        print("=" * 30)
 
 
def _root(full_name: str) -> str:
    return full_name.split("::")[-1]
 
 
def menu() -> None:
    parser = argparse.ArgumentParser(description="Plugin Skeleton Generator")
    parser.add_argument("--config", help="Path to .yaml file")
    args = parser.parse_args()
 
    if args.config:
        config = loadYAML(args.config)
 
        plugin_name = config.get("PluginName")
        out_of_process = config.get("OutOfProcess", False)
        plugin_config = config.get("PluginConfig", False)
        header_files = config.get("Paths", [])
        raw_locations = config.get("Locations", {})
 
        preconditions = config.get("Preconditions", [])
        terminations = config.get("Terminations", [])
        controls = config.get("Controls", [])
 
        select_map = config.get("SelectInterfaces", {})
 
        if not plugin_name:
            print("[ERROR]: PluginName must be specified in the config file")
            sys.exit(1)
        if not header_files:
            print("[ERROR]: Paths must be specified in the config file")
            sys.exit(1)
    else:
        plugin_name, out_of_process, plugin_config, header_files, raw_locations, preconditions, terminations, controls = prompts()
        select_map = {}
 
    if os.path.exists(plugin_name):
        print(f"[ERROR]: Directory '{plugin_name}' already exists")
        sys.exit(1)
 
    parsed_data, header_lookup = parserInterfaces(header_files)
 
    # Grouping root level by headeer for root interface selection
    by_header: Dict[str, List[str]] = {}
    for full_name, (_, header_path) in parsed_data.items():
        by_header.setdefault(header_path, []).append(full_name)
 
    selected_full_names: set = set()
 
    if args.config:
        for header_path, full_names in by_header.items():
            header_file = os.path.basename(header_path)
            wanted = select_map.get(header_file)  # list or none
            if not wanted:
                selected_full_names.update(full_names)
            else:
                wanted_set = set(wanted)
                selected_full_names.update(fn for fn in full_names if _root(fn) in wanted_set)
    else:
        for header_path, full_names in by_header.items():
            roots = [_root(fn) for fn in full_names]
 
            if len(full_names) == 1:
                selected_full_names.add(full_names[0])
                continue
 
            print(f"\n[SELECT] Please pick which interfaces you want to use from {header_path}")
            for i, r in enumerate(roots, 1):
                print(f"  {i}) {r}")
            raw = input("Pick indices (e.g. 1,3) or Enter for ALL: ").strip()
            if not raw:
                chosen = full_names
            else:
                try:
                    idx = [int(x) for x in raw.split(",") if x.strip()]
                except ValueError:
                    print("[WARN] Invalid selection, keeping ALL for this header.")
                    idx = list(range(1, len(full_names) + 1))
                chosen = [full_names[i - 1] for i in idx if 1 <= i <= len(full_names)]
                if not chosen:
                    print("[WARN] Empty/invalid selection, keeping ALL for this header.")
                    chosen = full_names
            selected_full_names.update(chosen)
 
    parsed_data = {k: v for k, v in parsed_data.items() if k in selected_full_names}
    chosen_roots = {_root(k) for k in parsed_data.keys()}
    header_lookup = {k: v for k, v in header_lookup.items() if k in chosen_roots}
 
    locations: Dict[str, str] = {}
    for full_name, (_, header_path) in parsed_data.items():
        iface_name = _root(full_name)
        header_file = os.path.basename(header_path)
        if header_file in raw_locations:
            locations[iface_name] = raw_locations[header_file]
 
    displayParsedData(parsed_data)
 
    if not args.config:
        print("Specify custom include locations for each interface header (press Enter for default 'interfaces'):")
        asked_headers = set()
        for full_name, (_, header_path) in parsed_data.items():
            header_filename = os.path.basename(header_path)
            if header_filename in asked_headers:
                continue
            asked_headers.add(header_filename)
            roots_in_header = [_root(fn) for fn in by_header.get(header_path, []) if fn in selected_full_names]
            roots_str = ", ".join(roots_in_header) if roots_in_header else "(none)"
            loc = input(f"Location for {header_filename} [{roots_str}]: ").strip()
            if loc:
                for r in roots_in_header:
                    locations[r] = loc
 
    coordinator = GeneratorCoordinator(
        plugin_name,
        out_of_process,
        plugin_config,
        parsed_data,
        header_lookup,
        locations,
        preconditions,
        terminations,
        controls,
    )
    coordinator.generateAll()
 