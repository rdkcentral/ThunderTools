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
    with open(file_path, "r") as f:
        return yaml.safe_load(f)

def prompts() -> Tuple[str, bool, bool, List[str], Dict[str, str], List[str], List[str], List[str]]:
    print("=== Plugin Generator ===")
    plugin_name = input("What will your plugin be called: ").strip()
    out_of_process = input("Is your plugin out of process? (Y/N): ").strip().lower() == "y"
    plugin_config = input("Custom plugin specific configuration needed? (Y/N): ").strip().lower() == "y"

    header_files = []
    while True:
        path = input("Add interface path (C++ IDL header file) (or press Enter to finish): ").strip()
        if not path:
            break
        header_files.append(path)

    if not header_files:
        print("Error: At least one header path must be provided")
        sys.exit(1)

    print("\nYou can now enter optional metadata.")
    print("Leave empty and press Enter to skip each list.")

    def collect_list(label: str) -> List[str]:
        print(f"\nEnter {label} (press Enter on empty line to finish):")
        entries = []
        while True:
            entry = input(f"{label[:-1]}: ").strip()
            if not entry:
                break
            entries.append(entry)
        return entries

    preconditions = collect_list("Preconditions")
    terminations = collect_list("Terminations")
    controls = collect_list("Controls")

    return plugin_name, out_of_process, plugin_config, header_files, {}, preconditions, terminations, controls


def parserInterfaces(header_files: List[str]) -> Tuple[Dict[str, Tuple[ClassData, str]], Dict[str, str]]:
    parser = MultiParser(header_files)
    parsed_data = parser.parse_all()
    header_lookup = parser.m_header_lookup
    return parsed_data, header_lookup

def displayParsedData(parsed_data: Dict[str, Tuple[ClassData, str]]) -> None:
    print("=" * 30)
    print(f"[INFO] Parsed {len(parsed_data)} interfaces:")
    for name, (class_data, header) in parsed_data.items():
        print(f"[INFO]: {name} (from {header})")
        Printer.print_tree(class_data)
        print("=" * 30)

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

        if not plugin_name:
            print("[ERROR]: PluginName must be specified in the config file")
            sys.exit(1)
        if not header_files:
            print("[ERROR]: Paths must be specified in the config file")
            sys.exit(1)
    else:
        plugin_name, out_of_process, plugin_config, header_files, raw_locations, preconditions, terminations, controls = prompts()

    if os.path.exists(plugin_name):
        print(f"[ERROR]: Directory '{plugin_name}' already exists")
        sys.exit(1)

    parsed_data, header_lookup = parserInterfaces(header_files)

    locations = {}
    for full_name, (_, header_path) in parsed_data.items():
        iface_name = full_name.split("::")[-1]
        header_file = os.path.basename(header_path)
        if header_file in raw_locations:
            locations[iface_name] = raw_locations[header_file]

    displayParsedData(parsed_data)

    if not args.config:
        print("Specify custom include locations for each interface header (press Enter for default 'interfaces'):")
        for full_name, (_, header_path) in parsed_data.items():
            header_filename = os.path.basename(header_path)
            iface_name = full_name.split("::")[-1]
            loc = input(f"Location for {header_filename} ({iface_name}): ").strip()
            if loc:
                locations[iface_name] = loc

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
    coordinator.generate_all()