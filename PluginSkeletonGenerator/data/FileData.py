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

from abc import ABC
from enum import Enum
from core.PluginBlueprint import PluginBlueprint
from utils.CodeGenUtils import generateSimpleText
from utils.FileUtils import FileUtils
import core.GlobalVariables as GlobalVariables
from typing import Dict, List, Tuple
from datetime import datetime
import re

from utils.CodeGenUtils import convertToBaseName, convertToCOMRPC, convertToJSONRPC

class FileData(ABC):
    def __init__(self, blueprint: PluginBlueprint) -> None:
        self.m_blueprint: PluginBlueprint = blueprint
        self.m_plugin_name: str = blueprint.name
        self.m_out_of_process: bool = blueprint.out_of_process
        self.m_plugin_config: bool = blueprint.configuration
        self.m_parsed: Dict[str, Tuple] = blueprint.parsed_data
        self.m_current_year: str = str(datetime.now().year)
        self.m_keywords: Dict[str, str] = {}
        self.m_jsonrpc: bool = blueprint.isJsonRpcPlugin()
        self.m_comrpc_interfaces: List[str] = blueprint.comrpc_interfaces
        self.m_jsonrpc_interfaces: List[str] = blueprint.jsonrpc_interfaces
        self.m_notification_interfaces: List[str] = blueprint.notification_interfaces
        self.m_notification_entries = blueprint.notification_entries
        self.m_locations: dict = blueprint.locations
        self.m_file_interface_map: dict = blueprint.file_interface_map
        self.m_preconditions = blueprint._PRECONDITIONS
        self.m_terminations = blueprint._TERMINATIONS
        self.m_controls = blueprint._CONTROLS
        self.m_event_notification_entries = getattr(blueprint, "event_notification_entries", [])

    @staticmethod
    def _dedupe_preserve_order(items: List[str]) -> List[str]:
        """Return a new list with duplicates removed while preserving the original order.
        """
        seen = set()
        out: List[str] = []
        for item in items:
            if item not in seen:
                seen.add(item)
                out.append(item)
        return out

    def _extractStrippedNamespace(self, full_name: str) -> str:
        parts = full_name.split("::")
        if parts[0] == "Thunder":
            return "::".join(parts[1:-1])
        return "::".join(parts[:-1])  # for interfaces that might not have Thunder::, I don't know if they exist
    
    def resolveFullName(self, short_name: str):
        """Resolve a short interface name to its parsed fully-qualified name."""
        for full_name in self.m_parsed:
            if full_name.endswith(f"::{short_name}"):
                return full_name
        return None

    @staticmethod
    def commentParamnames(params: str):
        """Avoid unused parameter warnings."""
        if not params or not params.strip():
            return "", []

        parts = [s.strip() for s in params.split(",")]
        out_parts: List[str] = []
        names: List[str] = []

        for chunk in parts:
            no_comments = re.sub(r"/\*.*?\*/", "", chunk)
            no_default = no_comments.split("=")[0].strip()
            # Examples of named params:
            #   `const string& msg`
            #   `bool enabled`
            #   `Exchange::IFoo* foo`
            # Examples of anonymous params:
            #   `const string&`
            #   `uint32_t`
            tokens = no_default.split()
            if len(tokens) < 2:
                out_parts.append(chunk)
                continue

            candidate = tokens[-1]
            candidate_stripped = candidate.lstrip("*&").rstrip("&*")
            if not re.match(r"^[A-Za-z_][A-Za-z0-9_]*$", candidate_stripped):
                out_parts.append(chunk)
                continue

            name = candidate_stripped
            names.append(name)

            last = chunk.rfind(name)
            if last != -1:
                chunk = chunk[:last] + f"/* {name} */" + chunk[last + len(name):]

            out_parts.append(chunk)

        return ", ".join(out_parts), names

    def _collect_known_types_for_notification(self, notification_fq: str, notif_cls_data) -> Tuple[str, set, set]:
        """
        Notification methods often reference nested enums/structs from:
          1) the notification scope itself (e.g. INotification::Source), and
          2) the owning interface scope (e.g. IAudioStream::streamstate).

        return both sets so downstream logic can choose the correct qualification target.
        """
        fq_parts = notification_fq.split("::")
        owner_iface_fq = "::".join(fq_parts[:-1])

        notif_types = set(getattr(notif_cls_data, "m_usings", {}).keys())
        notif_types |= set(getattr(notif_cls_data, "m_children", {}).keys())
        notif_types |= set(getattr(notif_cls_data, "m_types", set()))

        owner_types: set = set()
        owner_iface = fq_parts[-2] if len(fq_parts) >= 2 else None
        if owner_iface:
            owner_full = self.resolveFullName(owner_iface)
            if owner_full and owner_full in self.m_parsed:
                owner_cls, _ = self.m_parsed[owner_full]
                owner_types |= set(getattr(owner_cls, "m_usings", {}).keys())
                owner_types |= set(getattr(owner_cls, "m_children", {}).keys())
                owner_types |= set(getattr(owner_cls, "m_types", set()))

        return owner_iface_fq, notif_types, owner_types

    def _qualify_known_type_token(
        self,
        token: str,
        owner_iface_fq: str,
        notification_fq: str,
        notif_types: set,
        owner_types: set,
        *,
        prefer_unqualified_owner: bool,
    ) -> str:
        """
        - Types declared in the notification scope are not visible from the generated sink class
          unless fully qualified, so we always qualify those.
        - Types declared in the owning interface may be visible via inheritance (implementation
          classes) and can remain unqualified for readability unless the current generation
          context requires explicit qualification.
        """
        if token in notif_types:
            return f"{notification_fq}::{token}"
        if token in owner_types and not prefer_unqualified_owner:
            return f"{owner_iface_fq}::{token}"
        return token

    def _qualify_template_args(self, text: str, owner_iface_fq: str, notification_fq: str, notif_types: set, owner_types: set) -> str:
        """
        This focuses on the common Thunder patterns like:
          Core::OptionalType<audioprofile>
        where the nested type appears as a template argument and unqualified lookup might fail
        depending on the surrounding scope.
        """
        def repl_angle(m):
            inner = m.group(1)
            items = [x.strip() for x in inner.split(",")]
            qualified_items: List[str] = []
            for x in items:
                if "::" in x:
                    qualified_items.append(x)
                    continue
                base = x.strip().strip("*&")
                qualified = self._qualify_known_type_token(
                    base, owner_iface_fq, notification_fq, notif_types, owner_types,
                    prefer_unqualified_owner=False,  # inside templates, qualify owner types for safety
                )
                if qualified != base:
                    qualified_items.append(x.replace(base, qualified, 1))
                else:
                    qualified_items.append(x)
            return "<" + ", ".join(qualified_items) + ">"

        return re.sub(r"<\s*([^>]+?)\s*>", repl_angle, text)

    def _qualify_first_type_token_in_param(
        self,
        param: str,
        owner_iface_fq: str,
        notification_fq: str,
        notif_types: set,
        owner_types: set,
        *,
        prefer_unqualified_owner: bool,
    ) -> str:
        """
        Parameter strings are preserved as much as possible; we only rewrite the leading
        type identifier when it is a known nested type
        """
        if "::" in param:
            return param

        analysis = re.sub(r"/\*.*?\*/", "", param)
        analysis = analysis.split("=")[0].strip()
        tokens = analysis.split()
        qualifiers = {"const", "volatile", "signed", "unsigned", "struct", "class", "enum"}

        type_token = next((t for t in tokens if t not in qualifiers), None)
        if not type_token:
            return param

        stripped = type_token.strip("*&")
        qualified = self._qualify_known_type_token(
            stripped, owner_iface_fq, notification_fq, notif_types, owner_types,
            prefer_unqualified_owner=prefer_unqualified_owner,
        )
        if qualified == stripped:
            return param

        return param.replace(type_token, qualified, 1)

    def _qualifyParamTypes(self, params: str, notification_fq: str, cls_data, *, prefer_unqualified_owner: bool = True) -> str:
        if not params or not params.strip() or not cls_data:
            return params

        owner_iface_fq, notif_types, owner_types = self._collect_known_types_for_notification(notification_fq, cls_data)
        if not notif_types and not owner_types:
            return params

        parts = [p.strip() for p in params.split(",") if p.strip()]
        out_parts: List[str] = []

        for p in parts:
            p2 = self._qualify_template_args(p, owner_iface_fq, notification_fq, notif_types, owner_types)
            p3 = self._qualify_first_type_token_in_param(
                p2, owner_iface_fq, notification_fq, notif_types, owner_types,
                prefer_unqualified_owner=prefer_unqualified_owner,
            )
            out_parts.append(p3)

        return ", ".join(out_parts)

    def dynamic_keys(self) -> Dict[str, str]:
        return {
            "{{PLUGIN_NAME}}": self.m_plugin_name,
            "{{PLUGIN_NAME_CAPS}}": self.m_plugin_name.upper(),
            "{{YEAR_OF_GENERATION}}": self.m_current_year,
        }

    def static_keys(self) -> Dict[str, str]:
        return {}

    def extra_keys(self) -> Dict[str, str]:
        return {}

    def prepare(self) -> None:
        self.m_keywords = {**self.dynamic_keys(), **self.static_keys()}
        self.m_keywords.update(self.extra_keys())

    def _iface_namespace(self, iface_short: str) -> str:
        """Returns the stripped namespace for an interface (without the trailing type name)"""
        full_name = self.resolveFullName(iface_short)
        return self._extractStrippedNamespace(full_name) if full_name else ""

    def notification_registers(self, interface: str) -> str:
        name = interface[1:].lower() if interface.startswith('I') else interface.lower()
        return generateSimpleText([
            "ASSERT(notification != nullptr);",
            "",
            "_adminLock.Lock();",
            f"auto item = std::find(_{name}Notification.begin(), _{name}Notification.end(), notification);",
            f"ASSERT(item == _{name}Notification.end());",
            "",
            f"if (item == _{name}Notification.end()) {{",
            "    notification->AddRef();",
            f"    _{name}Notification.push_back(notification);",
            "}",
            "",
            "_adminLock.Unlock();",
        ], remove_empty=False, sep="\n")

    def notification_unregisters(self, interface: str) -> str:
        name = interface[1:].lower() if interface.startswith('I') else interface.lower()
        return generateSimpleText([
            "ASSERT(notification != nullptr);",
            "",
            "_adminLock.Lock();",
            f"auto item = std::find(_{name}Notification.begin(), _{name}Notification.end(), notification);",
            f"ASSERT(item != _{name}Notification.end());",
            "",
            f"if (item != _{name}Notification.end()) {{",
            f"    _{name}Notification.erase(item);",
            "    notification->Release();",
            "}",
            "_adminLock.Unlock();",
        ], remove_empty=False, sep="\n")

    @staticmethod
    def _defaultReturnStatement(return_type: str) -> List[str]:
        rt = (return_type or "").strip()
        if (rt == "void"):
            return []
        
        if rt == "string" or rt.endswith("::string"):
            return ["    return string();"]
        
        if rt == "bool":
            return ["    return false;"]

        if "*" in rt:
            return ["    return nullptr;"]

        if rt in ("Core::hresult", "uint32_t", "int32_t", "uint8_t", "uint16_t", "uint64_t", "int64_t", "long", "unsigned", "unsigned int"):
            return ["    return Core::ERROR_NONE;"]

        return [f"    return {rt}();"]

class HeaderData(FileData):
    class HeaderType(Enum):
        HEADER = 1
        HEADER_IMPLEMENTATION = 2

    def __init__(self, blueprint: PluginBlueprint, header_type: HeaderType) -> None:
        super().__init__(blueprint)
        self.m_type = header_type

    def static_keys(self):
        return {
            "{{PLUGIN_NAME}}": self.m_plugin_name,
            "{{HEADER_INHERITED_METHOD}}": self._generateHeaderInheritedMethod(),
            "{{HEADER_INTERFACE_ENTRY}}": self._generateHeaderInterfaceEntry(),
            "{{HEADER_INTERFACE_AGGREGATE}}": self._generateHeaderInterfaceAggregate(),
            "{{MODULE_PLUGIN_NAME}}": f'Plugin_{self.m_plugin_name}',
            "{{NOTIFICATION_CLASS}}": self._generateNotifClass(),
            "{{NOTIFICATION_CONSTRUCTOR}}": self._generateNotifConstructor(),
            "{{NOTIFICATION_ENTRY}}": self._generateNotifEntry(),
            "{{NOTIFICATION_FUNCTION}}": self._generateNotifFunction(),
            "{{HEADER_USING_CONTAINER}}": self._generateHeaderUsingContainer(),
            "{{HEADER_USING_EXTERNAL}}": self._generateHeaderUsingExternal(),
            "{{ADD_PRIVATE_FIELD}}": self._generatePrivateField(),
            "{{ADD_PUBLIC_FIELD}}": self._generatePublicField(),
            "{{ADD_PRIVATE_MEMBERS_FIELD}}": self._generatePrivateMembersField(),
            "{{HEADER_DEFINITIONS}}": self._generateHeaderDefinitions(),
            "{{HEADER_STATIC_TIMEOUT}}": self._generateHeaderTimeout(),
            "{{HEADER_INCLUDES}}": self._generateHeaderIncludes(),
            "{{HEADER_INHERITED_CLASS}}": self._generateHeaderInheritedClasses(),
            "{{HEADER_CONSTRUCTOR}}": self._generateHeaderConstructor(),
            "{{HEADER_MEMBERS}}": self._generateHeaderMembers(),
            "{{HEADER_NOTIFY}}": self._generateHeaderNotify(),
            "{{HEADER_DEACTIVATE_METHOD}}": self._generateHeaderDeactivateMethod(),
            "{{HEADER_DANGLING_METHOD}}": self._generateHeaderDanglingMethod(),
            "{{CONFIGURE_OOP}}": self._generateConfigureOOPMethod(),
        }

    def extra_keys(self):
        return {
            "{{CONFIG_CLASS}}": self._generateHeaderConfigClass(),
            "{{JSONRPC_EVENT}}": self._generateHeaderJSONRPCEvent(),
        }
    
    def _generateHeaderDeactivateMethod(self):
        return f'void Deactivated(RPC::IRemoteConnection* connection);' if self.m_out_of_process else ''

    def _generateHeaderDanglingMethod(self):
        return f'void Dangling(const Core::IUnknown* remote, const uint32_t interfaceId);' if self.m_out_of_process and self.m_notification_entries else ''
    
    def _generateNotifClass(self):
        entries = self.m_blueprint.notification_entries
        if not entries:
            return ": public RPC::IRemoteConnection::INotification"
        derived = [f"public {fq_name}" for fq_name, _ in entries]
        return generateSimpleText([": public RPC::IRemoteConnection::INotification, public PluginHost::IShell::ICOMLink::INotification"] + derived, sep=", ")

    def _generateNotifConstructor(self):
        entries = self.m_blueprint.notification_entries
        lines = []
        if entries:
            lines.append(", PluginHost::IShell::ICOMLink::INotification()")
        lines.extend([f", {fq_name}()" for fq_name, _ in entries])
        return generateSimpleText(lines)

    def _generateNotifEntry(self):
        entries = self.m_blueprint.notification_entries
        lines = []
        if entries:
            lines.append('INTERFACE_ENTRY(PluginHost::IShell::ICOMLink::INotification)')
        lines.extend([f"INTERFACE_ENTRY({fq_name})" for fq_name, _ in entries])
        return generateSimpleText(lines)

    def _generateNotifFunction(self):
        all_entries = list(getattr(self.m_blueprint, "notification_entries", []))
        event_entries = {fq: cls for fq, cls in (self.m_event_notification_entries if self.m_jsonrpc else [])}

        result = []

        if all_entries:
            result.append(
                "void Dangling(const Core::IUnknown* remote, const uint32_t interfaceId) override {\n"
                "    _parent.Dangling(remote, interfaceId);\n"
                "}"
            )

        for fq_name, cls_data in all_entries:
            root_iface = fq_name.split("::")[-2]
            jprefix = f"J{root_iface[1:]}" if root_iface.startswith("I") else f"J{root_iface}"

            for m in cls_data.m_methods:
                qualified_params = self._qualifyParamTypes(m.m_params, fq_name, cls_data, prefer_unqualified_owner=False)
                _, param_names = self.commentParamnames(qualified_params)
                param_str = ", ".join(param_names)
                add_const = " const" if getattr(m, "m_is_const", False) else ""

                if fq_name in event_entries:
                    result.extend([
                        f"void {m.m_name}({qualified_params}) override {{",
                        f"    Exchange::{jprefix}::Event::{m.m_name}(_parent{', ' + param_str if param_str else ''}){add_const};",
                        "}",
                        "",
                    ])
                else:
                    result.extend([
                        f"void {m.m_name}({qualified_params}) override {{",
                        "    // Intentionally left blank (non-@event notification).",
                        "}",
                        "",
                    ])

        return generateSimpleText(result, remove_empty=True, sep="\n")

    def _generateHeaderDefinitions(self):
        return '#include <definitions/definitions.h>' if self.m_jsonrpc else ''
    
    def _generateConfigureOOPMethod(self):
        if not self.m_plugin_config:
            return ''
        template = FileUtils.readFile(GlobalVariables.CONFIGURE_METHOD)
        return template if template else ''

    def _generateHeaderNotify(self) -> str:
        if not self.m_notification_interfaces:
            return ''
    
        if self.m_type == self.HeaderType.HEADER and not self.m_out_of_process:
            result = []
            for fq_name, cls_data in self.m_blueprint.notification_entries:
                for m in cls_data.m_methods:
                    qualified_params = self._qualifyParamTypes(m.m_params, fq_name, cls_data, prefer_unqualified_owner=True)
                    paramsNoNames, _ = self.commentParamnames(qualified_params)
                    result.append(f"void Notify{m.m_name}({paramsNoNames}) const;")
            return generateSimpleText(result)
    
        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            result = []
            for fq_name, cls_data in self.m_blueprint.notification_entries:
                iface = fq_name.split("::")[-2]
                no_i = iface[1:] if iface.startswith("I") else iface
                container = f"_{no_i.lower()}Notification"
    
                for m in cls_data.m_methods:
                    qualified_params = self._qualifyParamTypes(m.m_params, fq_name, cls_data, prefer_unqualified_owner=True)
                    _, param_names = self.commentParamnames(qualified_params)
                    param_str = ", ".join(param_names)

                    result.extend([
                        f"void Notify{m.m_name}({qualified_params}) const {{",
                        "    _adminLock.Lock();",
                        f"    for (auto* notification : {container}) {{",
                        f"        notification->{m.m_name}({param_str if param_str else ''});",
                        "    }",
                        "    _adminLock.Unlock();",
                        "}",
                        ""
                    ])
            return generateSimpleText(result, remove_empty=False)
        return ''
 
    def _generateHeaderTimeout(self) -> str:
        if self.m_out_of_process:
            return generateSimpleText([
                "// Timeout (2000ms) may be changed if necessary, however, it must not exceed RPC::CommunicationTimeOut",
                "static constexpr uint32_t timeout = 2000;"])
        return "\n"
    
    def _generateHeaderInterfaceAggregate(self) -> str:
        if not self.m_out_of_process:
            return ""

        lines = []
        for iface in self.m_comrpc_interfaces:
            ns = self._iface_namespace(iface)
            full_iface = f"{ns}::{iface}" if ns else iface
            lines.append(f"INTERFACE_AGGREGATE({full_iface}, _impl{convertToBaseName(iface)})")

        return generateSimpleText(lines)

    def _generateHeaderJSONRPCEvent(self):
        if not self.m_out_of_process:
            return ''
        template = FileUtils.readFile(GlobalVariables.RPC_NOTIFICATION_CLASS_PATH)
        return FileUtils.replaceKeywords(template, self.m_keywords) if template else ''

    def _generatePrivateField(self):
        if not self.m_out_of_process and not self.m_plugin_config:
            return ""
        return "private:"

    def _generatePublicField(self):
        if not self.m_out_of_process and not self.m_plugin_config:
            return ""
        return "public:"
    
    def _generatePrivateMembersField(self):
        if not self.m_out_of_process and not self.m_plugin_config and not self.m_notification_entries:
            return ""
        return "private:"

    def _generateHeaderMembers(self) -> str:
        lines = []

        if self.m_type == HeaderData.HeaderType.HEADER:
            if self.m_out_of_process:
                lines.append("PluginHost::IShell* _service;")
                lines.append("uint32_t _connectionId;")

                for iface in self.m_comrpc_interfaces:
                    ns = self._iface_namespace(iface)
                    lines.append(f"{ns}::{iface}* _impl{convertToBaseName(iface)};")

                lines.append("Core::SinkType<Notification> _notification;")

            if self.m_notification_interfaces and not self.m_out_of_process:
                lines.append("mutable Core::CriticalSection _adminLock;")
                for iface in self.m_notification_interfaces:
                    lines.append(f"{convertToBaseName(iface)}NotificationContainer _{convertToBaseName(iface).lower()}Notification;")

        else:
            if self.m_notification_interfaces:
                lines.append("mutable Core::CriticalSection _adminLock;")
                for iface in self.m_notification_interfaces:
                    lines.append(f"{convertToBaseName(iface)}NotificationContainer _{convertToBaseName(iface).lower()}Notification;")

        return generateSimpleText(lines)


    def _generateHeaderInterfaceEntry(self) -> str:
        entries = []

        if self.m_type == self.HeaderType.HEADER:
            entries.append("INTERFACE_ENTRY(PluginHost::IPlugin)")
            if self.m_jsonrpc:
                entries.append("INTERFACE_ENTRY(PluginHost::IDispatcher)")

        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION and self.m_plugin_config:
            entries.append(f"INTERFACE_ENTRY(Exchange::IConfiguration)")

        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION or (not self.m_out_of_process and self.m_type == self.HeaderType.HEADER):
            for iface in self.m_comrpc_interfaces:
                ns = self._iface_namespace(iface)
                entries.append(f"INTERFACE_ENTRY({ns}::{iface})")

        return generateSimpleText(entries)

    def _generateHeaderConfigClass(self):
        if not self.m_plugin_config:
            return ''
        parts = []
        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            parts.append('private:\n')

        if not self.m_out_of_process or self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            template = FileUtils.readFile(GlobalVariables.CONFIG_CLASS_PATH)
            if template:
                parts.append(FileUtils.replaceKeywords(template, self.m_keywords))

        return "\n".join(parts).strip()

    def _generateHeaderIncludes(self):
        includes: List[str] = ['#include "Module.h"']

        for iface in self.m_comrpc_interfaces:
            for filename, mapped_iface in self.m_file_interface_map.items():
                if mapped_iface == iface:
                    location = self.m_locations.get(iface, "interfaces")
                    includes.append(f'#include <{location}/{filename}>')

        # JSON includes in the *header* are only needed for JSONRPC event dispatch methods
        # that are emitted into Notification (OOP). So only include J-headers for @event notifications.
        if self.m_type == self.HeaderType.HEADER and self.m_out_of_process and self.m_jsonrpc:
            needed_roots: List[str] = []
            seen = set()
            for fq_name, _ in getattr(self.m_blueprint, "event_notification_entries", []):
                root_iface = fq_name.split("::")[-2]
                if root_iface not in seen:
                    seen.add(root_iface)
                    needed_roots.append(root_iface)

            for iface in needed_roots:
                json_header = f"J{iface[1:]}" if iface.startswith('I') else f"J{iface}"
                location = self.m_locations.get(iface, "interfaces")
                includes.append(f'#include <{location}/json/{json_header}.h>')

        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION and self.m_plugin_config:
            includes.append(f"#include <interfaces/IConfiguration.h>")

        return generateSimpleText(self._dedupe_preserve_order(includes))

    def _generateHeaderInheritedClasses(self) -> str:
        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            parts = []

            if self.m_plugin_config:
                parts.append(f"public Exchange::IConfiguration")

            for iface in self.m_comrpc_interfaces:
                ns = self._iface_namespace(iface)
                parts.append(f"public {ns}::{iface}")
        else:
            parts = ["public PluginHost::IPlugin"]
            if self.m_jsonrpc:
                parts.append("public PluginHost::JSONRPC")
            if not self.m_out_of_process:
                for iface in self.m_comrpc_interfaces:
                    ns = self._iface_namespace(iface)
                    parts.append(f"public {ns}::{iface}")
        return ": " + generateSimpleText(parts, sep=", ", remove_empty=True)

    
    def _generateHeaderConstructor(self) -> str:
        members = []

        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            for iface in self.m_comrpc_interfaces:
                ns = self._iface_namespace(iface)
                members.append(f"{ns}::{iface}()")
            if self.m_notification_interfaces:
                members.append("_adminLock()")
                members.extend(f"_{convertToBaseName(iface).lower()}Notification()" for iface in self.m_notification_interfaces)

        else:  # HEADER
            members.append("PluginHost::IPlugin()")
            if self.m_jsonrpc:
                members.append("PluginHost::JSONRPC()")
            if not self.m_out_of_process and self.m_comrpc_interfaces:
                for iface in self.m_comrpc_interfaces:
                    ns = self._iface_namespace(iface)
                    members.append(f"{ns}::{iface}()")
            if self.m_out_of_process:
                members.extend(["_service(nullptr)", "_connectionId(0)"])
                members.extend(f"_impl{convertToBaseName(iface)}(nullptr)" for iface in self.m_comrpc_interfaces)
                members.append("_notification(*this)")
            if self.m_notification_interfaces and not self.m_out_of_process:
                members.append("_adminLock()")
                members.extend(f"_{convertToBaseName(iface).lower()}Notification()" for iface in self.m_notification_interfaces)

        return ": " + generateSimpleText(members, sep="\n, ")
 
    def _generateHeaderInheritedMethod(self) -> str:
        is_header = self.m_type == self.HeaderType.HEADER
        is_impl = self.m_type == self.HeaderType.HEADER_IMPLEMENTATION

        if (not self.m_out_of_process and not is_header) or (self.m_out_of_process and not is_impl):
            return ""

        lines = []

        for full_name, (cls_data, _) in self.m_parsed.items():
            short_name = full_name.split("::")[-1]
            namespace = self._extractStrippedNamespace(full_name)
            lines.append(f"// {short_name} methods")

            for m in cls_data.m_methods:
                add_const = " const" if getattr(m, "m_is_const", False) else ""
                if is_header:
                    paramsNoNames, _ = self.commentParamnames(m.m_params)
                    lines.append(f"{m.m_return_type} {m.m_name}({paramsNoNames}){add_const} override;")
                else:
                    paramsNoNames, _ = self.commentParamnames(m.m_params)

                    if short_name in self.m_notification_interfaces and m.m_name in ("Register", "Unregister"):
                        return_stmt = self._defaultReturnStatement(m.m_return_type)
                        if m.m_name == "Register":
                            lines.append(generateSimpleText([
                                f"{m.m_return_type} Register({namespace}::{short_name}::INotification* notification) override {{",
                                self.notification_registers(short_name),
                                *return_stmt,
                                "}"
                            ], remove_empty=False))
                        else:
                            lines.append(generateSimpleText([
                                f"{m.m_return_type} Unregister(const {namespace}::{short_name}::INotification* notification) override {{",
                                self.notification_unregisters(short_name),
                                *return_stmt,
                                "}"
                            ], remove_empty=False))
                    else:
                        body = [
                            f"{m.m_return_type} {m.m_name}({paramsNoNames}){add_const} override {{",
                            *self._defaultReturnStatement(m.m_return_type),
                            "}"
                        ]
                        lines.append(generateSimpleText(body, remove_empty=False))

        return generateSimpleText(lines, sep="\n\n")

    def _generateHeaderUsingContainer(self) -> str:
        cond = (
            (self.m_out_of_process and self.m_type == self.HeaderType.HEADER_IMPLEMENTATION)
            or (not self.m_out_of_process and self.m_type == self.HeaderType.HEADER)
        )
        if not cond or not self.m_notification_interfaces:
            return ""

        lines = []
        for full_name in self.m_parsed:
            short_name = full_name.split("::")[-1]
            if short_name in self.m_notification_interfaces:
                namespace = self._extractStrippedNamespace(full_name)
                container_typedef = (
                    f"using {convertToBaseName(short_name)}NotificationContainer = "
                    f"std::vector<{namespace}::I{convertToBaseName(short_name)}::INotification*>;"
                )
                lines.append(container_typedef)

        return generateSimpleText(lines)
    
    def _generateHeaderUsingExternal(self) -> str:
        if self.m_type != self.HeaderType.HEADER_IMPLEMENTATION:
            return ""

        usings: Dict[str, str] = {}

        for full_name, (cls_data, _) in self.m_parsed.items():
            for name, value in getattr(cls_data, "m_usings", {}).items():
                if name in usings and usings[name] != value:
                    print(
                        f"[WARN] Conflicting type alias '{name}': '{usings[name]}' vs '{value}'. "
                        "Keeping the first definition."
                    )
                    continue
                usings.setdefault(name, value)

        if not usings:
            return ""

        lines = ["// Type aliases copied from interface headers"]
        for name in sorted(usings.keys()):
            lines.append(f"using {name} = {usings[name]};")

        return generateSimpleText(lines, remove_empty=False)

class SourceData(FileData):
    _KNOWN_SUBSYSTEMS = {
        "PLATFORM",
        "SECURITY",
        "NETWORK",
        "IDENTIFIER",
        "GRAPHICS",
        "INTERNET",
        "LOCATION",
        "TIME",
        "PROVISIONING",
        "DECRYPTION",
        "WEBSOURCE",
        "STREAMING",
        "BLUETOOTH",
        "CRYPTOGRAPHY",
        "INSTALLATION",
        "NOT_PLATFORM",
        "NOT_SECURITY",
        "NOT_NETWORK",
        "NOT_IDENTIFIER",
        "NOT_GRAPHICS",
        "NOT_INTERNET",
        "NOT_LOCATION",
        "NOT_TIME",
        "NOT_PROVISIONING",
        "NOT_DECRYPTION",
        "NOT_WEBSOURCE",
        "NOT_STREAMING",
        "NOT_BLUETOOTH",
        "NOT_CRYPTOGRAPHY",
        "NOT_INSTALLATION",
    }

    def _validateSubsystemEntries(self, entries: List[str], label: str) -> List[str]:
        if not entries:
            return []
        invalid = [e for e in entries if e.upper() not in self._KNOWN_SUBSYSTEMS]
        for e in invalid:
            print(f"[WARN] Unknown subsystem in {label}: '{e}'. It will still be emitted as subsystem::{e.upper()}.")
        return [e.upper() for e in entries if e]

    def static_keys(self) -> Dict[str, str]:
        return {
            "{{PLUGIN_NAME}}": self.m_plugin_name,
            "{{VARIABLE_NOT_USED_DEINITIAL}}": self._generateVariableUnusedDeinitial(),
            "{{VARIABLE_NOT_USED_INITIAL}}": self._generateVariableUnusedInitial(),
            "{{REGISTER_IP}}": self._generateJSONRegisterIP(),
            "{{UNREGISTER_IP}}": self._generateJSONUnregisterIP(),
            "{{FIRST_COMRPC_INTERFACE}}": self._generateFirstCOMRPCInterface(),
            "{{COMRPC[1:]}}": self._generateFirstCOMRPCNoPrefix(),
            "{{NESTED_QUERY}}": self._generateNestedQuery(),
            "{{CONFIGURE_IP}}": self._generateConfigurationIP(),
            "{{ASSERT_IMPL}}": self._generateInitialAssert(),
            "{{REGISTER_NOTIFICATION}}": self._generateRegisterNotification(),
            "{{UNREGISTER_NOTIFICATION}}": self._generateUnregisterNotification(),
            "{{DEINITIALIZE_OOP}}": self._generateDeinitializeOOP(),
            "{{INCLUDE_STATEMENTS}}": self._generateSourceIncludeStatements(),
            "{{SOURCE_METHOD_IMPL}}": self._generateSourcePluginMethods(),
            "{{SOURCE_NOTIFY_IMPL}}": self._generateSourceNotify(),
            "{{PRECONDITIONS}}": self._generatePreconditions(),
            "{{TERMINATIONS}}": self._generateTerminations(),
            "{{CONTROLS}}": self._generateControls(),
        }

    def extra_keys(self) -> Dict[str, str]:
        return {
            "{{INITIALIZE_IMPLEMENTATION}}": self._generateInitializeImplementation(),
            "{{DEINITIALIZE_IMPLEMENTATION}}": self._generateDeinitializeImplementation(),
        }
    
    def _generateRegisterNotification(self):
        if self.m_notification_entries:
            return "_service->Register(static_cast<RPC::IRemoteConnection::INotification*>(&_notification));" \
            "\n_service->Register(static_cast<PluginHost::IShell::ICOMLink::INotification*>(&_notification));"
        return "_service->Register(&_notification);"
    
    def _generateUnregisterNotification(self):
        if self.m_notification_entries:
            return "_service->Unregister(static_cast<RPC::IRemoteConnection::INotification*>(&_notification));" \
            "\n_service->Unregister(static_cast<PluginHost::IShell::ICOMLink::INotification*>(&_notification));"
        return "_service->Unregister(&_notification);"

    def _generatePreconditions(self):
        if not self.m_preconditions:
            return ''
        entries = self._validateSubsystemEntries(self.m_preconditions, "Preconditions")
        lines = [f" subsystem::{entry} " for entry in entries]
        return generateSimpleText(lines, sep=",")

    def _generateTerminations(self):
        if not self.m_terminations:
            return ''
        entries = self._validateSubsystemEntries(self.m_terminations, "Terminations")
        lines = [f" subsystem::{entry} " for entry in entries]
        return generateSimpleText(lines, sep=",")

    def _generateControls(self):
        if not self.m_controls:
            return ''
        entries = self._validateSubsystemEntries(self.m_controls, "Controls")
        lines = [f" subsystem::{entry} " for entry in entries]
        return generateSimpleText(lines, sep=",")

    def _generateSourceIncludeStatements(self):
        """
        The source file is responsible for JSONRPC Register/Unregister calls for @json interfaces,
        so it may need J* headers even when the header does not.
        """
        includes = [f'#include "{self.m_plugin_name}.h"']
        if self.m_plugin_config and self.m_out_of_process:
            includes.append('#include <interfaces/IConfiguration.h>')

        for iface in self.m_comrpc_interfaces:
            full_name = self.resolveFullName(iface)
            if not full_name:
                continue
            cls_data, _ = self.m_parsed.get(full_name, (None, None))
            if not cls_data or "json" not in getattr(cls_data, "m_tags", []):
                continue

            json_header = f"J{iface[1:]}" if iface.startswith('I') else f"J{iface}"
            location = self.m_locations.get(iface, "interfaces")
            includes.append(f'#include <{location}/json/{json_header}.h>')

        return generateSimpleText(self._dedupe_preserve_order(includes))


    def _generateSourcePluginMethods(self) -> str:
        if self.m_out_of_process:
            method = []

            method.append(
                f"void {self.m_plugin_name}::Deactivated(RPC::IRemoteConnection* connection) {{\n"
                "if (connection->Id() == _connectionId) {\n"
                "ASSERT(_service != nullptr);\n"
                "Core::IWorkerPool::Instance().Submit(PluginHost::IShell::Job::Create(_service, PluginHost::IShell::DEACTIVATED, PluginHost::IShell::FAILURE));\n"
                "_service->Release();\n"
                "_service = nullptr;\n"
                "_connectionId = 0;\n"
                "}\n"
                "}\n"
            )
    
            dangling = []
            entries = list(getattr(self.m_blueprint, "notification_entries", []))
            if entries:
                dangling.append(
                    f"void {self.m_plugin_name}::Dangling(const Core::IUnknown* remote, const uint32_t interfaceId) {{\n"
                    "ASSERT(remote != nullptr);\n"
                )

                # root interface -> implementation member (e.g. IBrowser -> _implBrowser)
                impl_map = {iface: f"_impl{convertToBaseName(iface)}" for iface in self.m_comrpc_interfaces}

                for fq_name, _ in entries:
                    # fq_name like Exchange::IBrowser::INotification
                    root_iface = fq_name.split("::")[-2]
                    unregister_impl = impl_map.get(root_iface)
                    if not unregister_impl:
                        # Fallback to first interface if we can't resolve (should not happen for selected roots)
                        unregister_impl = impl_map.get(self.m_comrpc_interfaces[0])

                    dangling.append(
                        f"    if (interfaceId == {fq_name}::ID) {{\n"
                        f"        auto* revokedInterface = remote->QueryInterface<{fq_name}>();\n"
                        f"        if (revokedInterface) {{\n"
                        f"            {unregister_impl}->Unregister(revokedInterface);\n"
                        f"            revokedInterface->Release();\n"
                        f"        }}\n"
                        f"    }}\n"
                    )

                dangling.append("}\n")

            return "\n".join(method) + "\n".join(dangling)

        lines = []

        for full_name, (cls_data, _) in self.m_blueprint.parsed_data.items():
            parts = full_name.split("::")
            iface = parts[-1]
            base_name = convertToBaseName(iface)
            notify_var = f"_{base_name.lower()}Notification"
            namespace = self._extractStrippedNamespace(full_name)

            for method in cls_data.m_methods:
                paramsNoNames, _ = self.commentParamnames(method.m_params)
                add_const = " const" if getattr(method, "m_is_const", False) else ""
                
                # Handle Register and Unregister methods for notification interfaces
                if iface in self.m_notification_interfaces and method.m_name in ("Register", "Unregister"):
                    return_stmt = self._defaultReturnStatement(method.m_return_type)
                    if method.m_name == "Register":
                        lines.extend([
                            f"{method.m_return_type} {self.m_plugin_name}::Register({namespace}::{iface}::INotification* notification) {{",
                            self.notification_registers(iface).strip(),
                            *return_stmt,
                            "}"
                        ])
                    else:
                        lines.extend([
                            f"{method.m_return_type} {self.m_plugin_name}::Unregister(const {namespace}::{iface}::INotification* notification) {{",
                            self.notification_unregisters(iface).strip(),
                            *return_stmt,
                            "}"
                        ])
                else:
                    lines.extend([
                        f"{method.m_return_type} {self.m_plugin_name}::{method.m_name}({paramsNoNames}){add_const} {{",
                        *self._defaultReturnStatement(method.m_return_type),
                        "}"
                    ])

            if "event" in cls_data.m_tags:
                lines.extend([
                    f"void {self.m_plugin_name}::Notify{iface}() const {{",
                    f"    _adminLock.Lock();",
                    f"    for (auto* notification : {notify_var}) {{",
                    f"        notification->{iface}Notification();",
                    f"    }}",
                    f"    _adminLock.Unlock();",
                    f"}}"
                ])

        return "\n".join(lines)

    def _generateSourceNotify(self) -> str:
        """Generate notification method implementations for in-process plugins"""
        if self.m_out_of_process or not self.m_notification_interfaces:
            return ''
            
        all_methods = []
        
        for fq_name, cls_data in self.m_blueprint.notification_entries:
            iface = fq_name.split("::")[-2]
            no_i = iface[1:] if iface.startswith("I") else iface
            container = f"_{no_i.lower()}Notification"
            
            for m in cls_data.m_methods:
                qualified_params = self._qualifyParamTypes(m.m_params, fq_name, cls_data, prefer_unqualified_owner=True)
                _, param_names = self.commentParamnames(qualified_params)
                param_str = ", ".join(param_names)

                method_lines = [
                    f"void {self.m_plugin_name}::Notify{m.m_name}({qualified_params}) const {{",
                    "    _adminLock.Lock();",
                    f"    for (auto* notification : {container}) {{",
                    f"        notification->{m.m_name}({param_str if param_str else ''});",
                    "    }",
                    "    _adminLock.Unlock();",
                    "}"
                ]
                
                all_methods.append('\n'.join(method_lines))
        
        return '\n\n'.join(all_methods)

    def _generateVariableUnusedDeinitial(self):
        return "" if self.m_out_of_process else "VARIABLE_IS_NOT_USED "


    def _generateVariableUnusedInitial(self):
        if (not self.m_out_of_process and self.m_plugin_config) or self.m_out_of_process:
            return ""
        return "VARIABLE_IS_NOT_USED "

    def _generateFirstCOMRPCInterface(self):
        """Return the fully-qualified type name for the first selected COMRPC root interface."""
        if not self.m_comrpc_interfaces:
            return "Exchange::IPlugin"

        short_name = self.m_comrpc_interfaces[0]
        ns = self._iface_namespace(short_name)
        return f"{ns}::{short_name}" if ns else short_name

    def _generateFirstCOMRPCNoPrefix(self):
        name = self.m_comrpc_interfaces[0] if self.m_comrpc_interfaces else ""
        return convertToBaseName(name)

    def _generateInitialAssert(self):
        return f"ASSERT(_impl{self._generateFirstCOMRPCNoPrefix()} == nullptr);"

    def _generateJSONRegisterIP(self) -> str:
        lines = []
        for short_name in self.m_comrpc_interfaces:
            json_iface = convertToJSONRPC(short_name)
            if json_iface in self.m_jsonrpc_interfaces:
                ns = self._iface_namespace(short_name)
                if ns:
                    lines.append(f"{ns}::{json_iface}::Register(*this, this);")
        return generateSimpleText(lines)

    def _generateJSONUnregisterIP(self) -> str:
        lines = []
        for short_name in self.m_comrpc_interfaces:
            json_iface = convertToJSONRPC(short_name)
            if json_iface in self.m_jsonrpc_interfaces:
                ns = self._iface_namespace(short_name)
                if ns:
                    lines.append(f"{ns}::{json_iface}::Unregister(*this);")
        return generateSimpleText(lines)

    def _generateConfigurationIP(self):
        if not self.m_plugin_config:
            return ''
        return (
            "Config config;\n"
            "config.FromString(service->ConfigLine());\n"
            "TRACE(Trace::Information, (_T(\"This is just an example: [%s]\"), config.Example.Value().c_str()));")

    def _generateInitializeImplementation(self):
        path = (GlobalVariables.INITIALIZE_OOP_PATH if self.m_out_of_process else GlobalVariables.INITIALIZE_IP_PATH)
        template = FileUtils.readFile(path)
        return (FileUtils.replaceKeywords(template, self.m_keywords) if template else '')

    def _generateDeinitializeImplementation(self):
        path = (GlobalVariables.DENINITIALIZE_OOP_PATH if self.m_out_of_process else GlobalVariables.DENINITIALIZE_IP_PATH)
        template = FileUtils.readFile(path)
        return (FileUtils.replaceKeywords(template, self.m_keywords)if template else '')

    def _iface_has_notification_register(self, iface: str) -> bool:
        full_name = self.resolveFullName(iface)
        if not full_name:
            return False
        cls_data, _ = self.m_parsed.get(full_name, (None, None))
        if not cls_data:
            return False

        method_names = {m.m_name for m in getattr(cls_data, "m_methods", [])}
        if not ({"Register", "Unregister"} <= method_names):
            return False

        
        return any(fq.split("::")[-2] == iface for fq, _ in getattr(self.m_blueprint, "notification_entries", []))

    def _generateNestedQuery(self) -> str:
        if not self.m_comrpc_interfaces:
            return ""

        interfaces = self.m_comrpc_interfaces
        has_qi = len(interfaces) >= 2

        init_lines = self._nestedquery_init_lines(interfaces)
        if self.m_plugin_config:
            init_lines = self._nestedquery_add_configure(init_lines, interfaces[0])

        if not (has_qi or init_lines):
            return generateSimpleText(["}"])

        lines: List[str] = ["} else {"]

        if has_qi:
            lines.extend(self._nestedquery_qi_lines(interfaces))

        if init_lines:
            lines.extend(init_lines)

        lines.extend(self._nestedquery_closing_braces(len(interfaces), has_qi))
        return generateSimpleText(lines)

    def _nestedquery_init_lines(self, interfaces: List[str]) -> List[str]:
        init: List[str] = []
        for iface in interfaces:
            base = convertToBaseName(iface)

            if self._iface_has_notification_register(iface):
                init.append(f"_impl{base}->Register(&_notification);")

            json_iface = convertToJSONRPC(iface)
            if json_iface in self.m_jsonrpc_interfaces:
                ns = self._iface_namespace(iface)
                init.append(f"{ns}::{json_iface}::Register(*this, _impl{base});")

        return init

    def _nestedquery_add_configure(self, init_lines: List[str], root_iface: str) -> List[str]:
        root_base = convertToBaseName(root_iface)
        out = list(init_lines)
        if out and out[-1] != "":
            out.append("")
        out.extend([
            f"Exchange::IConfiguration* configuration = _impl{root_base}->QueryInterface<Exchange::IConfiguration>();",
            "ASSERT(configuration != nullptr);",
            "if (configuration != nullptr) {",
            "    if (configuration->Configure(service) != Core::ERROR_NONE) {",
            f'        message = _T("{self.m_plugin_name} could not be configured.");',
            "    }",
            "    configuration->Release();",
            "}",
        ])
        return out

    def _nestedquery_qi_lines(self, interfaces: List[str]) -> List[str]:
        root_base = convertToBaseName(interfaces[0])
        lines: List[str] = []

        for iface in interfaces[1:]:
            base = convertToBaseName(iface)
            ns = self._iface_namespace(iface)
            lines.extend([
                f"_impl{base} = _impl{root_base}->QueryInterface<{ns}::{iface}>();",
                f"if (_impl{base} == nullptr) {{",
                f'message = _T("Failed to acquire {iface} interface.");',
                "} else {",
            ])

        return lines

    @staticmethod
    def _nestedquery_closing_braces(interface_count: int, has_qi: bool) -> List[str]:
        close_count = 1 + (interface_count - 1 if has_qi else 0)
        return ["}" for _ in range(close_count)]

    def _generateDeinitializeOOP(self):
        if not self.m_comrpc_interfaces:
            return ""

        lines = []
        first = self.m_comrpc_interfaces[0]
        firstBase = convertToBaseName(first)
        firstJson = convertToJSONRPC(first)

        namespace_first = self._iface_namespace(first)

        lines.append(f"if (_impl{firstBase} != nullptr) {{")

        # Unregister JSONRPC bindings + COMRPC notifications for secondary interfaces first
        for comrpc in self.m_comrpc_interfaces[1:]:
            baseName = convertToBaseName(comrpc)
            jsonName = convertToJSONRPC(comrpc)

            namespace = self._iface_namespace(comrpc)

            lines.append("\n")
            lines.append(f"if (_impl{baseName} != nullptr) {{")

            if jsonName in self.m_jsonrpc_interfaces:
                lines.append(f"{namespace}::{jsonName}::Unregister(*this);")

            if self._iface_has_notification_register(comrpc):
                lines.append(f"_impl{baseName}->Unregister(&_notification);")

            lines.append(f"_impl{baseName}->Release();")
            lines.append(f"_impl{baseName} = nullptr;")
            lines.append("}")

        # Now unregister for the root interface last
        if firstJson in self.m_jsonrpc_interfaces:
            lines.append(f"{namespace_first}::{firstJson}::Unregister(*this);")

        if self._iface_has_notification_register(first):
            lines.append(f"_impl{firstBase}->Unregister(&_notification);")

        lines.extend([
            "\n",
            "\n",
            f"RPC::IRemoteConnection* connection(service->RemoteConnection(_connectionId));",
            f"VARIABLE_IS_NOT_USED uint32_t result = _impl{firstBase}->Release();",
            f"_impl{firstBase} = nullptr;",
        ])
        lines.append("\n")
        lines.append(f"ASSERT((result == Core::ERROR_DESTRUCTION_SUCCEEDED) || (result == Core::ERROR_CONNECTION_CLOSED));")
        lines.append("\n")
        lines.extend([
            "// The process can disappear in the meantime...",
            "if (connection != nullptr) {",
            "// But if it did not disappear in the meantime, forcefully terminate it. Shoot to kill",
            "connection->Terminate();",
            "connection->Release();",
            "}",
            "}",
        ])

        return generateSimpleText(lines, remove_empty=False)

class CMakeData(FileData):
    def static_keys(self) -> dict:
        return {
            "{{SOURCE_FILES}}": self._generateSourceFiles(),
            "{{SET_MODE}}": self._generateSetMode(),
            "{{SET_CONFIG}}": self._generateSetConfig(),
            "{{FIND_DEFINITION}}": self._generateFindDefinition(),
            "{{TARGET_DEFINITION}}": self._generateTargetDefinition()
        }
    
    def _generateSourceFiles(self):
        if self.m_out_of_process:
            return f"{self.m_plugin_name}.cpp\n{self.m_plugin_name}Implementation.cpp"
        return f"{self.m_plugin_name}.cpp"


    def _generateSetMode(self):
        if self.m_out_of_process:
            macro = self.m_plugin_name.upper()
            return (
                f"set(PLUGIN_{macro}_MODE \"Local\" CACHE STRING "
                "\"Controls if the plugin should run in its own process, in process, container or remote.\")"
            )
        return ""


    def _generateSetConfig(self):
        if self.m_plugin_config:
            macro = self.m_plugin_name.upper()
            return (
                f"set(PLUGIN_{macro}_EXAMPLE \"Example Text\" CACHE STRING \"Example String\")"
            )
        return ""


    def _generateFindDefinition(self):
        if self.m_jsonrpc:
            return "find_package(${NAMESPACE}Definitions REQUIRED)"
        return ""


    def _generateTargetDefinition(self):
        if self.m_jsonrpc:
            return "${NAMESPACE}Definitions::${NAMESPACE}Definitions"
        return ""

class JSONData(FileData):
    def static_keys(self) -> dict:
        return {
            "{{cppref}}": self._generateCPPREF()
        }

    def extra_keys(self) -> dict:
        return {
            "{{JSON_INFO}}": self._generateJSONInfo(),
            "{{JSON_CONFIGURATION}}": self._generateJSONConfiguration(),
            "{{JSON_INTERFACE}}": self._generateJSONInterface()
        }
   
    def _generateCPPREF(self):
           # header_lookup: { interface_name: header_path }
        if not self.m_blueprint.header_lookup:
            return ""
    
        lines = []
        for header in self.m_blueprint.header_lookup:
            lines.append(f'"$cppref": "{{cppinterfacedir}}/{header}"')
 
        return generateSimpleText(lines, sep=",\n")


    def _generateJSONInfo(self):
        template = FileUtils.readFile(GlobalVariables.JSON_INFO)
        if not template:
            return ""
        return FileUtils.replaceKeywords(template, self.m_keywords)


    def _generateJSONConfiguration(self):
        if not self.m_plugin_config:
            return ""
        template = FileUtils.readFile(GlobalVariables.JSON_CONFIGURATION)
        if not template:
            return ""
        return FileUtils.replaceKeywords(template, self.m_keywords)


    def _generateJSONInterface(self):
        template = FileUtils.readFile(GlobalVariables.JSON_INTERFACE)
        if not template:
            return ""
        return FileUtils.replaceKeywords(template, self.m_keywords)

class ConfData(FileData):
    def static_keys(self) -> dict:
        return {
            "{{PLUGIN_STARTMODE}}": f"\"@PLUGIN_{self.m_plugin_name.upper()}_STARTMODE@\"",
            "{{OOP_ROOT}}": self._generateRoot(),
            "{{CONFIG}}": self._generateConfig()
        }

    def _generateRoot(self):
        if not self.m_out_of_process:
            return ""
        macro = self.m_plugin_name.upper()
        return generateSimpleText([
            "",
            "root = JSON()",
            f"root.add(\"mode\", \"@PLUGIN_{macro}_MODE@\")",
            "configuration.add(\"root\", root)"
        ])

    def _generateConfig(self):
        lines = []
        macro = self.m_plugin_name.upper()

        if self.m_out_of_process or self.m_plugin_config:
            lines.append("configuration = JSON()")

        if self.m_plugin_config:
            lines.append(f"configuration.add(\"example\", \"@PLUGIN_{macro}_EXAMPLE@\")")
        return generateSimpleText(lines)