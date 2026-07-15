# If not stated otherwise in this file or this component's license file the
# following copyright and licenses apply:
#
# Copyright 2020 Metrological
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import posixpath
import argparse
from enum import Enum

# Constants
DATA_NAMESPACE = "JsonData"
PLUGIN_NAMESPACE = "Plugin"
TYPE_PREFIX = "Core::JSON"
OBJECT_SUFFIX = "Data"
COMMON_OBJECT_SUFFIX = "Info"
ENUM_SUFFIX = "Type"

# Configurables
CLASSNAME_FROM_REF = True
DEFAULT_INT_SIZE = 32
DEFAULT_DEFINITIONS_FILE = "../../ProxyStubGenerator/default.h"
FRAMEWORK_NAMESPACE = "Thunder"
INTERFACE_NAMESPACES = ["::%s::Exchange::JSONRPC" % FRAMEWORK_NAMESPACE, "::%s::Exchange" % FRAMEWORK_NAMESPACE]
INTERFACES_SECTION = True
INTERFACE_SOURCE_LOCATION = None
INTERFACE_SOURCE_REVISION = None
NO_INCLUDES = False
NO_VERSIONING = False
NO_PUSH_WARNING = False
DUPLICATE_OBJ_WARNINGS = True
DEFAULT_INTERFACE_SOURCE_REVISION = "main"
GLOBAL_DEFINITIONS = ".." + os.sep + "global.json"
INDENT_SIZE = 4
ALWAYS_EMIT_COPY_CTOR = False
KEEP_EMPTY = False
CPP_INTERFACE_PATH = "interfaces" + os.sep
JSON_INTERFACE_PATH = CPP_INTERFACE_PATH + "json"  + os.sep
DUMP_JSON = False
FORCE = False
GENERATED_JSON = False
LEGACY_ALT = False
AUTO_PREFIX = False
STATS_FOR_NERDS = False
STRICT_VALIDATION = True
EMIT_RESTRICT_CHECKS = True
EMIT_OPTIONAL_CHECKS = True

class RpcFormat(Enum):
    COMPLIANT = "compliant"
    EXTENDED = "uncompliant-extended"
    COLLAPSED = "uncompliant-collapsed"

class CaseConvention(Enum):
    STANDARD = "standard"
    LEGACY = "legacy"
    KEEP = "keep"
    CUSTOM = "custom"

DEFAULT_CASE_CONVENTION = CaseConvention.STANDARD
IGNORE_SOURCE_CASE_CONVENTION = False

RPC_FORMAT = RpcFormat.COMPLIANT
RPC_FORMAT_FORCED = False


def Parse(cmdline):
    global FRAMEWORK_NAMESPACE
    global DEFAULT_DEFINITIONS_FILE
    global INTERFACE_NAMESPACES
    global JSON_INTERFACE_PATH
    global CPP_INTERFACE_PATH
    global NO_INCLUDES
    global NO_VERSIONING
    global NO_PUSH_WARNING
    global DEFAULT_INT_SIZE
    global INDENT_SIZE
    global INTERFACE_SOURCE_LOCATION
    global INTERFACE_SOURCE_REVISION
    global INTERFACES_SECTION
    global FORCE
    global DUMP_JSON
    global RPC_FORMAT_FORCED
    global RPC_FORMAT
    global DUPLICATE_OBJ_WARNINGS
    global ALWAYS_EMIT_COPY_CTOR
    global KEEP_EMPTY
    global CLASSNAME_FROM_REF
    global LEGACY_ALT
    global AUTO_PREFIX
    global DEFAULT_CASE_CONVENTION
    global IGNORE_SOURCE_CASE_CONVENTION
    global STATS_FOR_NERDS
    global STRICT_VALIDATION
    global EMIT_OPTIONAL_CHECKS
    global EMIT_RESTRICT_CHECKS

    argparser = argparse.ArgumentParser(
        description='Generate JSON C++ classes, JSON-RPC glue code and API documentation from JSON definition files and C++ header files',
        epilog="For information about custom tags supprted in C++ code please see StubGenerator help (--help-tags).",
        formatter_class=argparse.RawTextHelpFormatter)

    argparser.add_argument('path',
            nargs="*",
            help="JSON file(s) and/or C++ header files, wildcards are allowed")
    argparser.add_argument("-d",
            "--docs",
            dest="docs",
            action="store_true",
            default=False,
            help="generate documentation")
    argparser.add_argument("-c",
            "--code",
            dest="code",
            action="store_true",
            default=False,
            help="generate C++ code building JSON classes and complete JSON-RPC functionality (the latter only if applicable)")
    argparser.add_argument("-o",
            "--output",
            dest="output_dir",
            metavar="PATH",
            action="store",
            default=None,
            help="output directory, absolute path or directory relative to output file (default: output in the same directory as the source file)")
    argparser.add_argument(
            "--cpp-output",
            dest="cpp_output_dir",
            metavar="PATH",
            action="store",
            default=None,
            help="output directory for cpp files, absolute path or directory relative to output file")
    argparser.add_argument(
            "--force",
            dest="force",
            action="store_true",
            default=FORCE,
            help= "force code generation even if destination appears up-to-date (default: force disabled)")
    argparser.add_argument(
            "--warnings",
            dest="warnings",
            action=argparse.BooleanOptionalAction,
            default=True,
            help= "report warnings")

    json_group = argparser.add_argument_group("JSON parser arguments (optional)")
    json_group.add_argument("-i",
            dest="if_dirs",
            metavar="PATH",
            action="append",
            type=str,
            default=[],
            help="a directory with JSON API interfaces that will substitute the {interfacedir} tag (can be used multiple times)")
    json_group.add_argument("--ref-names",
            dest="ref_names",
            action=argparse.BooleanOptionalAction,
            default=CLASSNAME_FROM_REF,
            help="derive class names from $refs")
    json_group.add_argument("--duplicate-obj-warnings",
            dest="duplicate_obj_warnings",
            action=argparse.BooleanOptionalAction,
            default=DUPLICATE_OBJ_WARNINGS,
            help="enable duplicate object warnings")

    cpp_group = argparser.add_argument_group("C++ parser arguments (optional)")
    cpp_group.add_argument("-j",
            dest="cpp_if_dirs",
            metavar="PATH",
            action="append",
            type=str,
            default=[],
            help="a directory with C++ API interfaces that will substitute the {cppinterfacedir} tag (can be used multiple times)")
    cpp_group.add_argument('-I',
            dest="include_paths",
            metavar="PATH",
            action='append',
            default=[],
            type=str,
            help='add an include path (can be used multiple times)')
    cpp_group.add_argument("--include",
            dest="extra_include",
            metavar="FILE",
            action="store",
            default=DEFAULT_DEFINITIONS_FILE,
            help="include a C++ header file with common types (default: include '%s')" % DEFAULT_DEFINITIONS_FILE)
    cpp_group.add_argument("--namespace",
            dest="if_namespaces",
            metavar="NS",
            action="append",
            default=[],
            help="add namespace to look for interfaces in (default: %s)" % INTERFACE_NAMESPACES[0])
    cpp_group.add_argument("--format",
            dest="format",
            type=str,
            action="store",
            default="default-compliant",
            choices=["default-compliant", "force-compliant", "default-uncompliant-extended", "force-uncompliant-extended", "default-uncompliant-collapsed", "force-uncompliant-collapsed"],
            help="select JSON-RPC data format (default: default-compliant)")
    cpp_group.add_argument("--case-convention",
            dest="case_convention",
            type=str,
            metavar="CONVENTION",
            action="store",
            default=DEFAULT_CASE_CONVENTION.value,
            help="select JSON-RPC case convention (default: %s)" % DEFAULT_CASE_CONVENTION.value)
    cpp_group.add_argument("--ignore-source-case-convention",
            dest="ignore_source_case_convention",
            action="store_true",
            default=IGNORE_SOURCE_CASE_CONVENTION,
            help="ignore case convention specified by source header file (default: don't ignore)")

    data_group = argparser.add_argument_group("C++ output arguments (optional)")
    data_group.add_argument(
            "--emit-cpp-interface-path",
            dest="cpp_if_path",
            metavar="PATH",
            action="store",
            type=str,
            default=CPP_INTERFACE_PATH,
            help="override emitted path when #include'ing C++ interface header file (default: 'interfaces', . for no path)")
    data_group.add_argument(
            "--emit-json-interface-path",
            dest="if_path",
            metavar="PATH",
            action="store",
            type=str,
            default=JSON_INTERFACE_PATH,
            help="override emitted path when #include'ing JsonData header file (default: 'interfaces/json', . for no path)")
    data_group.add_argument(
            "--no-includes",
            dest="no_includes",
            action="store_true",
            default=NO_INCLUDES,
            help="do not emit #includes (default: include data and interface headers)")
    data_group.add_argument(
            "--no-versioning",
            dest="no_versioning",
            action="store_true",
            default=NO_VERSIONING,
            help= "do not emit versioning information for non-auto JSON interfaces (default: emit versioning header)")
    data_group.add_argument(
            "--auto-prefix",
            dest="auto_prefix",
            action="store_true",
            default=AUTO_PREFIX,
            help= "prefix JSON-RPC endpoints with C++ namespace (default: no prefix)")
    data_group.add_argument("--legacy-alt",
            dest="legacy_alt",
            action="store_true",
            default=LEGACY_ALT,
            help="do not use framework's alt support (default: use framework alt support)")
    data_group.add_argument(
            "--no-push-warning",
            dest="no_push_warning",
            action="store_true",
            default=NO_PUSH_WARNING,
            help= "do not use PUSH/POP_WARNING macros in generated code (default: use macros)")
    data_group.add_argument(
            "--strict-validation",
            dest="strict_validation",
            action=argparse.BooleanOptionalAction,
            default=STRICT_VALIDATION,
            help= "enable strict input parameter validation")
    data_group.add_argument(
            "--restrict-checks",
            dest="restrict_checks",
            action=argparse.BooleanOptionalAction,
            default=EMIT_RESTRICT_CHECKS,
            help="emit restrict checks")
    data_group.add_argument(
            "--optional-checks",
            dest="optional_checks",
            action=argparse.BooleanOptionalAction,
            default=EMIT_OPTIONAL_CHECKS,
            help="emit optional checks")
    data_group.add_argument(
            "--stats",
            dest="stats",
            action=argparse.BooleanOptionalAction,
            default=STATS_FOR_NERDS,
            help="register version with additional method count statistics")
    data_group.add_argument("--copy-ctor",
            dest="copy_ctor",
            action="store_true",
            default=ALWAYS_EMIT_COPY_CTOR,
            help="always emit a copy constructor and assignment operator (default: emit only when needed)")
    data_group.add_argument("--def-int-size",
            dest="def_int_size",
            metavar="SIZE",
            type=int,
            action="store",
            default=DEFAULT_INT_SIZE,
            help="default integer size in bits (default: %i)" % DEFAULT_INT_SIZE)
    data_group.add_argument("--indent",
            dest="indent_size",
            metavar="SIZE",
            type=int,
            action="store",
            default=INDENT_SIZE,
            help="code indentation in spaces (default: %i)" % INDENT_SIZE)
    data_group.add_argument("--framework-namespace",
            dest="framework_namespace",
            metavar="NS",
            type=str,
            action="store",
            default=FRAMEWORK_NAMESPACE,
            help="set framework namespace")


    doc_group = argparser.add_argument_group("Documentation output arguments (optional)")
    doc_group.add_argument("--style-warnings",
            dest="style_warnings",
            action=argparse.BooleanOptionalAction,
            default=True,
            help="report documentation issues")
    doc_group.add_argument("--interfaces-section",
            dest="interfaces_section",
            action=argparse.BooleanOptionalAction,
            default=INTERFACES_SECTION,
            help="include 'Interfaces' section")
    doc_group.add_argument("--source-location",
            dest="source_location",
            metavar="LN",
            type=str,
            action="store",
            default=INTERFACE_SOURCE_LOCATION,
            help="override interface source file location to the link specified")
    doc_group.add_argument("--source-revision",
            dest="source_revision",
            metavar="ID",
            type=str,
            action="store",
            default=None,
            help="override interface source file revision to the commit id specified")

    ts_group = argparser.add_argument_group("Troubleshooting arguments (optional)")
    ts_group.add_argument("--verbose",
            dest="verbose",
            action="store_true",
            default=False,
            help="enable verbose logging")
    ts_group.add_argument("--keep-empty",
            dest="keep_empty",
            action="store_true",
            default=KEEP_EMPTY,
            help="keep generated files that have no code")
    ts_group.add_argument("--dump-json",
            dest="dump_json",
            action="store_true",
            default=DUMP_JSON,
            help="dump the intermediate JSON file created while parsing a C++ header")


    args = argparser.parse_args(cmdline[1:])

    DUPLICATE_OBJ_WARNINGS = args.duplicate_obj_warnings
    INDENT_SIZE = args.indent_size
    ALWAYS_EMIT_COPY_CTOR = args.copy_ctor
    KEEP_EMPTY = args.keep_empty
    CLASSNAME_FROM_REF = args.ref_names
    DEFAULT_INT_SIZE = args.def_int_size
    DUMP_JSON = args.dump_json
    FORCE = args.force
    LEGACY_ALT = args.legacy_alt
    DEFAULT_DEFINITIONS_FILE = args.extra_include
    INTERFACES_SECTION = args.interfaces_section
    INTERFACE_SOURCE_LOCATION = args.source_location
    INTERFACE_SOURCE_REVISION = args.source_revision
    AUTO_PREFIX = args.auto_prefix
    IGNORE_SOURCE_CASE_CONVENTION = args.ignore_source_case_convention
    EMIT_RESTRICT_CHECKS = args.restrict_checks
    EMIT_OPTIONAL_CHECKS = args.optional_checks
    STRICT_VALIDATION = args.strict_validation

    if args.case_convention == "standard":
        DEFAULT_CASE_CONVENTION = CaseConvention.STANDARD
    elif args.case_convention == "legacy" or args.case_convention == "legacy_lowercase":
        DEFAULT_CASE_CONVENTION = CaseConvention.LEGACY
    elif args.case_convention == "keep":
        DEFAULT_CASE_CONVENTION = CaseConvention.KEEP
    else:
        print("Invalid case convention")
        exit(1)

    if args.framework_namespace:
        FRAMEWORK_NAMESPACE = args.framework_namespace
        INTERFACE_NAMESPACES = ["::%s::Exchange::JSONRPC" % FRAMEWORK_NAMESPACE, "::%s::Exchange" % FRAMEWORK_NAMESPACE]

    if args.if_namespaces:
        INTERFACE_NAMESPACES = args.if_namespaces

    for i, ns in enumerate(INTERFACE_NAMESPACES):
        if not ns.startswith("::"):
            INTERFACE_NAMESPACES[i] = "::" + ns

    if RpcFormat.EXTENDED.value in args.format:
        RPC_FORMAT = RpcFormat.EXTENDED
    elif RpcFormat.COLLAPSED.value in args.format:
        RPC_FORMAT = RpcFormat.COLLAPSED
    else:
        RPC_FORMAT = RpcFormat.COMPLIANT

    if "force" in args.format:
        RPC_FORMAT_FORCED = True

    STATS_FOR_NERDS = args.stats

    NO_INCLUDES = args.no_includes
    NO_VERSIONING = args.no_versioning
    NO_PUSH_WARNING = args.no_push_warning

    JSON_INTERFACE_PATH = "" if args.if_path == "." else (posixpath.normpath(args.if_path) + os.sep)
    CPP_INTERFACE_PATH = "" if args.cpp_if_path == "." else (posixpath.normpath(args.cpp_if_path) + os.sep)

    if args.if_dirs:
        args.if_dirs = [os.path.abspath(os.path.normpath(dir)) for dir in args.if_dirs]
    if args.cpp_if_dirs:
        args.cpp_if_dirs = [os.path.abspath(os.path.normpath(dir)) for dir in args.cpp_if_dirs]

    return argparser, args
