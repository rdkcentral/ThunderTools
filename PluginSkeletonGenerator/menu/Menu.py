'''
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
'''

import argparse
import os
import re
import sys
from dataclasses import dataclass
from typing import Dict, List, Set, Tuple
from parser.MultiParser import MultiParser
from parser.Parser import Printer, ClassData
from core.GeneratorCoordinator import GeneratorCoordinator


ParsedData = Dict[str, Tuple[ClassData, str]]

CLI_GENERATION_FIELDS = (
    "plugin_name",
    "output_dir",
    "out_of_process",
    "plugin_config",
    "header_files",
    "locations",
    "select_interfaces",
    "preconditions",
    "terminations",
    "controls",
)

@dataclass
class PluginOptions:
    name: str
    out_of_process: bool
    plugin_config: bool
    header_files: List[str]
    raw_locations: Dict[str, str]
    select_map: Dict[str, List[str]]
    preconditions: List[str]
    terminations: List[str]
    controls: List[str]
    output_dir: str


def validatePaths(paths: List[str]) -> None:
    files = [p for p in paths if not os.path.isfile(p)]
    if files:
        print("[ERROR]: Following header paths do not exist: ")
        for missing in files:
            print(f"- {missing}")
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


def _prompt_yes_no(question: str, default: bool = False) -> bool:
    suffix = "[Y/N, Enter defaults to N]" if default is False else "[Y/N, Enter defaults to Y]"
    while True:
        raw = input(f"{question} (Y/N) {suffix}: ").strip().lower()
        if raw == "":
            return default
        if raw in ("y", "yes"):
            return True
        if raw in ("n", "no"):
            return False
        print("[WARN] Invalid input. Please enter Y or N.")


def _validate_plugin_name(name: str) -> str:
    name = name.strip()
    if not name:
        print("[ERROR]: Plugin name cannot be empty")
        sys.exit(1)
    if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", name):
        print("[ERROR]: Invalid plugin name. Use only letters, digits and '_' and do not start with a digit.")
        sys.exit(1)
    return name


def _validate_output_dir(output_dir: str) -> str:
    output_dir = os.path.abspath(output_dir or os.getcwd())
    if not os.path.isdir(output_dir):
        print(f"[ERROR]: Output directory does not exist: {output_dir}")
        sys.exit(1)
    return output_dir


def prompts() -> PluginOptions:
    print("=== Plugin Generator ===")

    plugin_name = _validate_plugin_name(input("What will your plugin be called: "))
    output_dir = _validate_output_dir(
        input("Where should the plugin be generated? [default: current directory]: ").strip()
    )

    out_of_process = _prompt_yes_no("Is your plugin out of process?", default=False)
    plugin_config = _prompt_yes_no("Custom plugin specific configuration needed?", default=False)

    header_files = []
    print("\nAdd FULL path to your interface (C++ IDL header file)...")
    print("Example: /home/Thunder/ThunderInterfaces/interfaces/ITestInterface.h")
    while True:
        path = input("Path to interface (or press Enter to finish): ").strip()
        if not path:
            break
        header_files.append(path)

    _validate_header_requirements(header_files, out_of_process)

    subsystems_enabled = _prompt_yes_no(
        "Does your plugin rely on Thunder subsystems [Preconditions, Terminations, Controls]?",
        default=False,
    )

    return PluginOptions(
        name=plugin_name,
        out_of_process=out_of_process,
        plugin_config=plugin_config,
        header_files=header_files,
        raw_locations={},
        select_map={},
        preconditions=collectList("Preconditions") if subsystems_enabled else [],
        terminations=collectList("Terminations") if subsystems_enabled else [],
        controls=collectList("Controls") if subsystems_enabled else [],
        output_dir=output_dir,
    )


def _validate_header_requirements(header_files: List[str], out_of_process: bool) -> None:
    if not header_files and out_of_process:
        print("Error: At least one header path must be provided")
        sys.exit(1)
    validatePaths(header_files)


def _parse_mapping(values: List[str], option_name: str) -> Dict[str, str]:
    result: Dict[str, str] = {}
    for value in values or []:
        if ":" not in value:
            print(f"[ERROR]: {option_name} values must use HEADER:VALUE format")
            sys.exit(1)

        key, mapped_value = value.split(":", 1)
        key = key.strip()
        mapped_value = mapped_value.strip()
        if not key or not mapped_value:
            print(f"[ERROR]: {option_name} values must include both HEADER and VALUE")
            sys.exit(1)

        result[key] = mapped_value
    return result


def _parse_select_interfaces(values: List[str]) -> Dict[str, List[str]]:
    result: Dict[str, List[str]] = {}
    for value in values or []:
        if ":" not in value:
            print("[ERROR]: --select-interface values must use HEADER:INTERFACE[,INTERFACE] format")
            sys.exit(1)

        header, interfaces = value.split(":", 1)
        header = header.strip()
        selected = [item.strip() for item in interfaces.split(",") if item.strip()]
        if not header or not selected:
            print("[ERROR]: --select-interface values must include a HEADER and at least one INTERFACE")
            sys.exit(1)

        result.setdefault(header, []).extend(selected)
    return result


def _has_cli_arguments(args: argparse.Namespace) -> bool:
    return any(getattr(args, field, None) for field in CLI_GENERATION_FIELDS)


def _values_from_cli(args: argparse.Namespace) -> PluginOptions:
    if not args.plugin_name:
        print("[ERROR]: --plugin-name is required when using command line arguments")
        sys.exit(1)

    header_files = args.header_files or []
    _validate_header_requirements(header_files, args.out_of_process)

    return PluginOptions(
        name=_validate_plugin_name(args.plugin_name),
        out_of_process=args.out_of_process,
        plugin_config=args.plugin_config,
        header_files=header_files,
        raw_locations=_parse_mapping(args.locations, "--location"),
        select_map=_parse_select_interfaces(args.select_interfaces),
        preconditions=args.preconditions or [],
        terminations=args.terminations or [],
        controls=args.controls or [],
        output_dir=_validate_output_dir(args.output_dir),
    )


def parserInterfaces(header_files: List[str]) -> Tuple[ParsedData, Dict[str, str]]:
    parser = MultiParser(header_files)
    parsed_data = parser.parseAll()
    header_lookup = parser.m_header_lookup
    return parsed_data, header_lookup


def displayParsedData(parsed_data: ParsedData) -> None:
    print("=" * 30)
    print(f"[INFO] Parsed {len(parsed_data)} interfaces:")
    for name, (class_data, header) in parsed_data.items():
        print(f"[INFO]: {name} (from {header})")
        Printer.printTree(class_data)
        print("=" * 30)


def _root(full_name: str) -> str:
    return full_name.split("::")[-1]


def _build_argument_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Generate a Thunder plugin skeleton. Run with no arguments for the "
            "interactive questionnaire, or pass CLI arguments to skip the prompts."
        ),
        epilog="""\
CLI mode requirements:
  --plugin-name is required when any generation argument is provided.
  --path is required only when --out-of-process is used.
  All other options are optional and default to the same values as pressing Enter
  through the interactive prompts.

Examples:
  Interactive mode:
    PluginSkeletonGenerator.py

  Minimal CLI mode:
    PluginSkeletonGenerator.py --plugin-name ExamplePlugin

  Out-of-process plugin with one interface:
    PluginSkeletonGenerator.py --plugin-name WifiPlugin --out-of-process \\
      --path /home/Thunder/ThunderInterfaces/interfaces/IWifiControl.h

  Select one interface from a header that contains more than one:
    PluginSkeletonGenerator.py --plugin-name WifiPlugin \\
      --path /home/Thunder/ThunderInterfaces/interfaces/IWifiControl.h \\
      --select-interface IWifiControl.h:IWifiControl

  Override the generated include location when it is not "interfaces":
    PluginSkeletonGenerator.py --plugin-name WifiPlugin \\
      --path /home/vendor/ThunderInterfaces/custom/IWifiControl.h \\
      --location IWifiControl.h:custom

  Add multiple subsystem conditions:
    PluginSkeletonGenerator.py --plugin-name WifiPlugin \\
      --precondition PLATFORM --precondition NETWORK \\
      --termination TERMINATED \\
      --control INTERNET
""",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )

    required_cli = parser.add_argument_group("required in CLI mode")
    required_cli.add_argument(
        "-n",
        "--plugin-name",
        metavar="NAME",
        help=(
            "Plugin class/repository name to generate. Required if you pass any "
            "other generation option. Must be a valid C++ identifier."
        ),
    )

    common = parser.add_argument_group("common options")
    common.add_argument(
        "-o",
        "--output-dir",
        metavar="DIR",
        help="Existing directory where the plugin folder is created. Default: current directory.",
    )
    common.add_argument(
        "--out-of-process",
        dest="out_of_process",
        action="store_true",
        default=False,
        help="Generate an out-of-process plugin. Requires at least one --path.",
    )
    common.add_argument(
        "--plugin-config",
        dest="plugin_config",
        action="store_true",
        default=False,
        help="Generate support for custom plugin-specific configuration. Default: disabled.",
    )
    common.add_argument(
        "-p",
        "--path",
        dest="header_files",
        action="append",
        metavar="HEADER",
        help=(
            "Full path to a C++ IDL interface header to parse. Use once per "
            "header. Required for --out-of-process; optional otherwise."
        ),
    )

    subsystem = parser.add_argument_group("Thunder subsystem options")
    subsystem.add_argument(
        "--precondition",
        dest="preconditions",
        action="append",
        metavar="SUBSYSTEM",
        help="Required subsystem before activation, such as PLATFORM. Repeat this option for multiple preconditions.",
    )
    subsystem.add_argument(
        "--termination",
        dest="terminations",
        action="append",
        metavar="SUBSYSTEM",
        help="Subsystem state that terminates the plugin. Repeat this option for multiple terminations.",
    )
    subsystem.add_argument(
        "--control",
        dest="controls",
        action="append",
        metavar="SUBSYSTEM",
        help="Subsystem controlled by the plugin. Repeat this option for multiple controls.",
    )

    interface = parser.add_argument_group("interface selection and include options")
    interface.add_argument(
        "--select-interface",
        dest="select_interfaces",
        action="append",
        metavar="HEADER:INTERFACE[,INTERFACE]",
        help=(
            "Choose which root interface classes to generate from a parsed "
            "header. This matters when one header defines multiple top-level "
            "interfaces, for example IWifiControl and IWifiDiagnostics. HEADER "
            "may be the full path or just the filename. Interface names are the "
            "class names without namespaces. Omit this option to generate all "
            "root interfaces found in that header."
        ),
    )
    interface.add_argument(
        "--location",
        dest="locations",
        action="append",
        metavar="HEADER:LOCATION",
        help=(
            "Override the include folder used for generated #include lines for "
            "interfaces from HEADER. HEADER may be the full path or filename. "
            "Only needed when the generated include should not start with the "
            "default folder, interfaces."
        ),
    )

    return parser


def _group_by_header(parsed_data: ParsedData) -> Dict[str, List[str]]:
    by_header: Dict[str, List[str]] = {}
    for full_name, (_, header_path) in parsed_data.items():
        by_header.setdefault(header_path, []).append(full_name)
    return by_header


def _select_from_cli(by_header: Dict[str, List[str]], select_map: Dict[str, List[str]]) -> Set[str]:
    selected_full_names: Set[str] = set()
    for header_path, full_names in by_header.items():
        header_file = os.path.basename(header_path)
        wanted = select_map.get(header_file) or select_map.get(header_path)
        if not wanted:
            selected_full_names.update(full_names)
            continue

        wanted_set = set(wanted)
        roots_in_header = {_root(fn) for fn in full_names}
        selected_full_names.update(fn for fn in full_names if _root(fn) in wanted_set)
        missing = wanted_set - roots_in_header
        if missing:
            print(f"[WARN] Interfaces not found in {header_path}: {', '.join(sorted(missing))}")
    return selected_full_names


def _select_interactively(by_header: Dict[str, List[str]]) -> Set[str]:
    selected_full_names: Set[str] = set()
    for header_path, full_names in by_header.items():
        roots = [_root(fn) for fn in full_names]

        if len(full_names) == 1:
            selected_full_names.add(full_names[0])
            continue

        print(f"\n[SELECT] Please pick which interfaces you want to use from {header_path}")
        for i, root_name in enumerate(roots, 1):
            print(f"  {i}) {root_name}")

        raw = input("Pick indices (e.g. 1,3) or Enter for ALL: ").strip()
        if not raw:
            chosen = full_names
        else:
            try:
                indices = [int(x) for x in raw.split(",") if x.strip()]
            except ValueError:
                print("[WARN] Invalid selection, keeping ALL for this header.")
                indices = list(range(1, len(full_names) + 1))

            chosen = [full_names[i - 1] for i in indices if 1 <= i <= len(full_names)]
            if not chosen:
                print("[WARN] Empty/invalid selection, keeping ALL for this header.")
                chosen = full_names

        selected_full_names.update(chosen)
    return selected_full_names


def _select_interfaces(
    by_header: Dict[str, List[str]],
    select_map: Dict[str, List[str]],
    direct_cli: bool,
) -> Set[str]:
    if direct_cli:
        return _select_from_cli(by_header, select_map)
    return _select_interactively(by_header)


def _collect_locations(parsed_data: ParsedData, raw_locations: Dict[str, str]) -> Dict[str, str]:
    locations: Dict[str, str] = {}
    for full_name, (_, header_path) in parsed_data.items():
        iface_name = _root(full_name)
        header_file = os.path.basename(header_path)
        location = raw_locations.get(header_file) or raw_locations.get(header_path)
        if location:
            locations[iface_name] = location
    return locations


def _prompt_include_locations(
    by_header: Dict[str, List[str]],
    selected_full_names: Set[str],
    locations: Dict[str, str],
) -> List[str]:
    print("Specify custom include locations for each interface header (press Enter for default 'interfaces'):")
    asked_headers = set()
    header_filenames = []
    for header_path, full_names in by_header.items():
        header_filename = os.path.basename(header_path)
        if header_filename in asked_headers:
            continue

        asked_headers.add(header_filename)
        header_filenames.append(header_filename)
        roots_in_header = [_root(fn) for fn in full_names if fn in selected_full_names]
        roots_str = ", ".join(roots_in_header) if roots_in_header else "(none)"
        loc = input(f"Location for {header_filename} [{roots_str}]: ").strip()
        if loc:
            for root_name in roots_in_header:
                locations[root_name] = loc
    return header_filenames


def _generate(options: PluginOptions, direct_cli: bool) -> None:
    plugin_root = os.path.join(options.output_dir, options.name)
    if os.path.exists(plugin_root):
        print(f"[ERROR]: Directory '{plugin_root}' already exists")
        sys.exit(1)

    parsed_data, _ = parserInterfaces(options.header_files)
    by_header = _group_by_header(parsed_data)
    selected_full_names = _select_interfaces(by_header, options.select_map, direct_cli)

    parsed_data = {k: v for k, v in parsed_data.items() if k in selected_full_names}

    locations = _collect_locations(parsed_data, options.raw_locations)
    displayParsedData(parsed_data)

    selected_header_filenames = []
    if not direct_cli:
        selected_header_filenames = _prompt_include_locations(by_header, selected_full_names, locations)

    coordinator = GeneratorCoordinator(
        options.name,
        options.out_of_process,
        options.plugin_config,
        parsed_data,
        selected_header_filenames,
        locations,
        options.preconditions,
        options.terminations,
        options.controls,
        output_dir=options.output_dir,
    )
    coordinator.generateAll()


def menu() -> None:
    parser = _build_argument_parser()
    args = parser.parse_args()
    direct_cli = _has_cli_arguments(args)
    options = _values_from_cli(args) if direct_cli else prompts()
    _generate(options, direct_cli)