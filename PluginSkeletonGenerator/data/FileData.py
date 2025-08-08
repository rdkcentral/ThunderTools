from abc import ABC
from enum import Enum
from core.PluginBlueprint import PluginBlueprint
from utils.CodeGenUtils import generateSimpleText
from utils.FileUtils import FileUtils
import core.GlobalVariables as GlobalVariables
from typing import Dict, List, Tuple
from datetime import datetime

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

    def _extractStrippedNamespace(self, full_name: str) -> str:
        parts = full_name.split("::")
        if parts[0] == "Thunder":
            return "::".join(parts[1:-1])
        return "::".join(parts[:-1])  # for interfaces that might not have Thunder::, I don't know if they exist
    
    def resolveFullName(self, short_name: str):
        # Basically a look up, needed for getting full name for namespaces...
        for full_name in self.m_parsed:
            if full_name.endswith(f"::{short_name}"):
                return full_name
        return None

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
            "{{ADD_PRIVATE_FIELD}}": self._generatePrivateField(),
            "{{ADD_PUBLIC_FIELD}}": self._generatePublicField(),
            "{{HEADER_DEFINITIONS}}": self._generateHeaderDefinitions(),
            "{{HEADER_STATIC_TIMEOUT}}": self._generateHeaderTimeout(),
            "{{HEADER_INCLUDES}}": self._generateHeaderIncludes(),
            "{{HEADER_INHERITED_CLASS}}": self._generateHeaderInheritedClasses(),
            "{{HEADER_CONSTRUCTOR}}": self._generateHeaderConstructor(),
            "{{HEADER_MEMBERS}}": self._generateHeaderMembers(),
            "{{HEADER_NOTIFY}}": self._generateHeaderNotify(),
            "{{HEADER_DEACTIVATE_METHOD}}": self._generateHeaderDeactivateMethod()
        }

    def extra_keys(self):
        return {
            "{{CONFIG_CLASS}}": self._generateHeaderConfigClass(),
            "{{JSONRPC_EVENT}}": self._generateHeaderJSONRPCEvent(),
        }
    
    def _generateHeaderDeactivateMethod(self):
        return f'void Deactivated(RPC::IRemoteConnection* connection);' if self.m_out_of_process else ''
    
    def _generateNotifClass(self):
        entries = self.m_blueprint.notification_entries
        if not entries:
            return ": public RPC::IRemoteConnection::INotification"
        derived = [f"public {fq_name}" for fq_name, _ in entries]
        return generateSimpleText([": public RPC::IRemoteConnection::INotification "] + derived, sep=", ")

    def _generateNotifConstructor(self):
        entries = self.m_blueprint.notification_entries
        lines = [f", {fq_name}()" for fq_name, _ in entries]
        return generateSimpleText(lines)

    def _generateNotifEntry(self):
        entries = self.m_blueprint.notification_entries
        lines = [f"INTERFACE_ENTRY({fq_name})" for fq_name, _ in entries]
        return generateSimpleText(lines)

    def _generateNotifFunction(self):
        entries = self.m_blueprint.notification_entries
        result = []

        for fq_name, cls_data in entries:
            namespace = fq_name.split("::")[2]
            jprefix = f"J{namespace[1:]}" if namespace.startswith("I") else f"J{namespace}"

            for m in cls_data.m_methods:
                param_names = []
                if m.m_params.strip():
                    for p in m.m_params.split(","):
                        param_names.append(p.strip().split()[-1])
                param_str = ", ".join(param_names)

                result.extend([
                    f"void {m.m_name}({m.m_params}) override {{",
                    f"{jprefix}::Event::{m.m_name}(_parent{', ' + param_str if param_str else ''});",
                    "}"
                ])
                result.append("")  # for spacing between functions

        return generateSimpleText(result, remove_empty=True, sep="\n")

    def _generateHeaderDefinitions(self):
        return '#include <definitions/definitions.h>' if self.m_jsonrpc else ''

    def _generateHeaderNotify(self) -> str:
        if not self.m_notification_interfaces:
            return ''

        ''' ??
        if self.m_type == self.HeaderType.HEADER:
            lines = [f"void Notify{iface}() const;" for iface in self.m_notification_interfaces]
            return generateSimpleText(lines)
        '''
        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            result = []
            for iface in self.m_notification_interfaces:
                no_i = iface[1:]
                result.extend([
                    f"void Notify{iface}() const {{",
                    "_adminLock.Lock();",
                    f"for (auto* notification : _{no_i.lower()}Notification) {{",
                    f"notification->{iface}Notification();",
                    "}",
                    "_adminLock.Unlock();",
                    "}"
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
            full_name = self.resolveFullName(iface)
            if full_name:
                namespace = self._extractStrippedNamespace(full_name)
                full_iface = f"{namespace}::{iface}" if namespace else iface
                lines.append(f"INTERFACE_AGGREGATE({full_iface}, _impl{convertToBaseName(iface)})")

        return generateSimpleText(lines)

    def _generateHeaderJSONRPCEvent(self):
        if not self.m_out_of_process:
            return ''
        template = FileUtils.readFile(GlobalVariables.RPC_NOTIFICATION_CLASS_PATH)
        return FileUtils.replaceKeywords(template, self.m_keywords) if template else ''

    def _generatePrivateField(self):
        if not self.m_out_of_process and not self.m_plugin_config:
            return "private:"

    def _generatePublicField(self):
        return "public:"

    def _generateHeaderMembers(self) -> str:
        lines = []

        if self.m_type == HeaderData.HeaderType.HEADER:
            if self.m_out_of_process:
                lines.append("PluginHost::IShell* _service;")
                lines.append("uint32_t _connectionId;")

                for iface in self.m_comrpc_interfaces:
                    full_name = self.resolveFullName(iface)
                    namespace = self._extractStrippedNamespace(full_name)
                    lines.append(f"{namespace}::{iface}* _impl{convertToBaseName(iface)};")

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

        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION or (not self.m_out_of_process and self.m_type == self.HeaderType.HEADER):
            for iface in self.m_comrpc_interfaces:
                full_name = self.resolveFullName(iface)
                namespace = self._extractStrippedNamespace(full_name)
                entries.append(f"INTERFACE_ENTRY({namespace}::{iface})")

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
        includes = []
        includes.append('#include "Module.h"')

        # Includes for all IDL Header files
        for iface in self.m_comrpc_interfaces:
            for filename, mapped_iface in self.m_file_interface_map.items():
                if mapped_iface == iface:
                    location = self.m_locations.get(iface, "interfaces")
                    includes.append(f'#include <{location}/{filename}>')

        # Includes JSON variant of IDL Header files if applicable
        if self.m_type == self.HeaderType.HEADER and self.m_out_of_process:
            for json_iface in self.m_jsonrpc_interfaces:
                comrpc_iface = convertToCOMRPC(json_iface)

                if comrpc_iface in self.m_comrpc_interfaces:
                    # Find corresponding filename
                    filename = next(
                        (fname for fname, iface in self.m_file_interface_map.items()
                        if iface == comrpc_iface),
                        None
                    )
                    if filename:
                        location = self.m_locations.get(comrpc_iface, "interfaces")
                        includes.append(f'#include <{location}/json/{filename}>')

        return generateSimpleText(includes)

    def _generateHeaderInheritedClasses(self) -> str:
        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            parts = []
            for iface in self.m_comrpc_interfaces:
                full_name = self.resolveFullName(iface)
                namespace = self._extractStrippedNamespace(full_name)
                parts.append(f"public {namespace}::{iface}")
        else:
            parts = ["public PluginHost::IPlugin"]
            if self.m_jsonrpc:
                parts.append("public PluginHost::JSONRPC")
            if not self.m_out_of_process:
                for iface in self.m_comrpc_interfaces:
                    full_name = self.resolveFullName(iface)
                    namespace = self._extractStrippedNamespace(full_name)
                    parts.append(f"public {namespace}::{iface}")
        return ": " + generateSimpleText(parts, sep=", ", remove_empty=True)

    
    def _generateHeaderConstructor(self) -> str:
        members = []

        if self.m_type == self.HeaderType.HEADER_IMPLEMENTATION:
            for i, iface in enumerate(self.m_comrpc_interfaces):
                full_name = self.resolveFullName(iface)
                namespace = self._extractStrippedNamespace(full_name)
                members.append(f"{namespace}::{iface}()")
            if self.m_notification_interfaces:
                members.append("_adminLock()")
                members.extend(f"_{convertToBaseName(iface).lower()}Notification()" for iface in self.m_notification_interfaces)

        else:  # HEADER
            members.append("PluginHost::IPlugin()")
            if self.m_jsonrpc:
                members.append("PluginHost::JSONRPC()")
            if not self.m_out_of_process and self.m_comrpc_interfaces:
                for i, iface in enumerate(self.m_comrpc_interfaces):
                    full_name = self.resolveFullName(iface)
                    namespace = self._extractStrippedNamespace(full_name)
                    members.append(f"{namespace}::{iface}()")
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
                if is_header:
                    lines.append(f"{m.m_return_type} {m.m_name}({m.m_params}) override;")
                else:
                    if short_name in self.m_notification_interfaces and m.m_name in ("Register", "Unregister"):
                        if m.m_name == "Register":
                            lines.append(generateSimpleText([
                                f"{m.m_return_type} {self.m_plugin_name}::Register({namespace}::{short_name}::INotification* notification) {{",
                                self.notification_registers(short_name),
                                "return Core::ERROR_NONE;",
                                "}"
                            ]))
                        else:
                            lines.append(generateSimpleText([
                                f"{m.m_return_type} {self.m_plugin_name}::Unregister(const {namespace}::{short_name}::INotification* notification) {{",
                                self.notification_unregisters(short_name),
                                "return Core::ERROR_NONE;",
                                "}"
                            ]))
                    else:
                        lines.append(generateSimpleText([
                            f"{m.m_return_type} {self.m_plugin_name}::{m.m_name}({m.m_params}) {{",
                            "    return Core::ERROR_NONE;",
                            "}"
                        ]))

        return generateSimpleText(lines, sep="\n\n")

    
    def notification_registers(self, interface):
        text = []
        text.append('\nASSERT(notification != nullptr);\n')
        text.append('\n_adminLock.Lock();')
        text.append(f'''\nauto item = std::find(_{interface[1:].lower()}Notification.begin(), _{interface[1:].lower()}Notification.end(), notification);
                ASSERT(item == _{interface[1:].lower()}Notification.end());

                if (item == _{interface[1:].lower()}Notification.end()) {{
                notification->AddRef();
                _{interface[1:].lower()}Notification.push_back(notification);
                }}

                _adminLock.Unlock(); ''')
        text.append('\n')
        return ''.join(text)
    
    def notification_unregisters(self,interface):
        text = []
        text.append(f'''\n
                ASSERT(notification != nullptr);

                _adminLock.Lock();
                auto item = std::find(_{interface[1:].lower()}Notification.begin(), _{interface[1:].lower()}Notification.end(), notification);
                ASSERT(item != _{interface[1:].lower()}Notification.end());

                if (item != _{interface[1:].lower()}Notification.end()) {{
                _{interface[1:].lower()}Notification.erase(item);
                notification->Release();
                }}
                _adminLock.Unlock();
                ''')
        return ''.join(text)

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
                    f"std::vector<{namespace}::{convertToBaseName(short_name)}::INotification*>;"
                )
                lines.append(container_typedef)

        return generateSimpleText(lines)

class SourceData(FileData):
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
            "{{REGISTER_NOTIFICATION}}": "_service->Register(&_notification);",
            "{{UNREGISTER_NOTIFICATION}}": "_service->Unregister(&_notification);",
            "{{DEINITIALIZE_OOP}}": self._generateDeinitializeOOP(),
            "{{INCLUDE_STATEMENTS}}": self._generateSourceIncludeStatements(),
            "{{SOURCE_METHOD_IMPL}}": self._generateSourcePluginMethods(),
            "{{PRECONDITIONS}}": self._generatePreconditions(),
            "{{TERMINATIONS}}": self._generateTerminations(),
            "{{CONTROLS}}": self._generateControls(),
        }

    def extra_keys(self) -> Dict[str, str]:
        return {
            "{{INITIALIZE_IMPLEMENTATION}}": self._generateInitializeImplementation(),
            "{{DEINITIALIZE_IMPLEMENTATION}}": self._generateDeinitializeImplementation(),
        }
    
    def _generatePreconditions(self):
        if not self.m_preconditions:
            return ''
        lines = [f" subsystem::{entry} " for entry in self.m_preconditions]
        return generateSimpleText(lines, sep=",")

    def _generateTerminations(self):
        if not self.m_terminations:
            return ''
        lines = [f" subsystem::{entry} " for entry in self.m_terminations]
        return generateSimpleText(lines, sep=",")

    def _generateControls(self):
        if not self.m_controls:
            return ''
        lines = [f" subsystem::{entry} " for entry in self.m_controls]
        return generateSimpleText(lines, sep=",")

    def _generateSourceIncludeStatements(self):
        includes = [f'#include "{self.m_plugin_name}.h"']
        if self.m_plugin_config and self.m_out_of_process:
            includes.append('#include <interfaces/IConfiguration.h>')

        for json_iface in self.m_jsonrpc_interfaces:
            base_name = convertToCOMRPC(json_iface)

            header_filename = next(
                (fname for fname, iface in self.m_file_interface_map.items()
                if iface == base_name),
                None
            )
            if header_filename:
                location = self.m_locations.get(base_name, "interfaces/json")
                includes.append(f'#include <{location}/json/{header_filename}>')

        return generateSimpleText(includes)


    def _generateSourcePluginMethods(self) -> str:
        if self.m_out_of_process:
            return f"""void {self.m_plugin_name}::Deactivated(RPC::IRemoteConnection* connection) {{
                if (connection->Id() == _connectionId) {{
                    ASSERT(_service != nullptr);
                    Core::IWorkerPool::Instance().Submit(PluginHost::IShell::Job::Create(_service, PluginHost::IShell::DEACTIVATED, PluginHost::IShell::FAILURE));
                    }}
                    }}
                    """
        lines = []

        for full_name, (cls_data, _) in self.m_blueprint.parsed_data.items():
            parts = full_name.split("::")
            iface = parts[-1]
            base_name = convertToBaseName(iface)
            notify_var = f"_{base_name.lower()}Notification"

            for method in cls_data.m_methods:
                lines.extend([
                    f"{method.m_return_type} {self.m_plugin_name}::{method.m_name}({method.m_params}) {{",
                    f"    return Core::ERROR_NONE;",
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

    def _generateVariableUnusedDeinitial(self):
        return "" if self.m_out_of_process else "VARIABLE_IS_NOT_USED "


    def _generateVariableUnusedInitial(self):
        if (not self.m_out_of_process and self.m_plugin_config) or self.m_out_of_process:
            return ""
        return "VARIABLE_IS_NOT_USED "

    def _generateFirstCOMRPCInterface(self):
        if not self.m_comrpc_interfaces:
            return "Exchange::IPlugin"

        short_name = self.m_comrpc_interfaces[0]
        full_name = next((k for k in self.m_parsed if k.endswith(f"::{short_name}")), None)

        if full_name:
            namespace = self._extractStrippedNamespace(full_name)
            return f"{namespace}::{short_name}" if namespace else short_name
        else:
            return short_name

    def _generateFirstCOMRPCNoPrefix(self):
        name = self._generateFirstCOMRPCInterface()
        return convertToBaseName(name)


    def _generateInitialAssert(self):
        return f"ASSERT(_impl{self._generateFirstCOMRPCNoPrefix()} == nullptr);"

    def _generateJSONRegisterIP(self) -> str:
        lines = []
        for full_name in self.m_parsed:
            short_name = full_name.split("::")[-1]
            if short_name in self.m_jsonrpc_interfaces:
                namespace = self._extractStrippedNamespace(full_name)
                lines.append(f"{namespace}::{short_name}::Register(*this, this);")
        return generateSimpleText(lines)

    def _generateJSONUnregisterIP(self) -> str:
        lines = []
        for full_name in self.m_parsed:
            short_name = full_name.split("::")[-1]
            if short_name in self.m_jsonrpc_interfaces:
                namespace = self._extractStrippedNamespace(full_name)
                lines.append(f"{namespace}::{short_name}::Unregister(*this);")
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

    def _generateNestedQuery(self) -> str:
        if not self.m_comrpc_interfaces:
            return ""

        lines = []
        interfaces = self.m_comrpc_interfaces

        if len(interfaces) > 1:
            for idx, short_name in enumerate(interfaces[1:], start=1):
                prev = interfaces[idx - 1]
                prevName = convertToBaseName(prev)
                name = convertToBaseName(short_name)

                # Determine full name from parsed to resolve correct namespace
                full_name = next((k for k in self.m_parsed if k.endswith(f"::{short_name}")), None)
                namespace = self._extractStrippedNamespace(full_name)
                qualified = f"{namespace}::{short_name}"

                lines.extend([
                    f"_impl{name} = _impl{prevName}->QueryInterface<{qualified}>();",
                    f"if (_impl{name} == nullptr) {{",
                    f'    message = _T("Couldn\'t create instance of _impl{short_name}");',
                    "} else {"
                ])

        lines.append(self._generateNestedInitialize())
        lines.extend("}" for _ in range(len(interfaces) - 1))

        return generateSimpleText(lines)

    def _generateNestedInitialize(self) -> str:
        if not self.m_comrpc_interfaces:
            return ""

        interfaces = self.m_comrpc_interfaces
        rootName = convertToBaseName(interfaces[0])
        lines = []

        for short_name in interfaces:
            name = convertToBaseName(short_name)
            json_iface = convertToJSONRPC(short_name)

            full_name = next((k for k in self.m_parsed if k.endswith(f"::{short_name}")), None)
            namespace = self._extractStrippedNamespace(full_name)
            qualified = f"{namespace}::{json_iface}"

            if json_iface in self.m_jsonrpc_interfaces:
                lines.extend([
                    f"_impl{name}->Register(&_notification);",
                    f"{qualified}::Register(*this, _impl{name});"
                ])

        if self.m_plugin_config:
            lines.extend([
                "\n",
                f"Exchange::IConfiguration* configuration = _impl{rootName}->QueryInterface<Exchange::IConfiguration>();",
                "ASSERT(configuration != nullptr);",
                "if (configuration != nullptr) {",
                "    if (configuration->Configure(service) != Core::ERROR_NONE) {",
                f'        message = _T("{self.m_plugin_name} could not be configured.");',
                "    }",
                "    configuration->Release();",
                "}"
            ])

        return generateSimpleText(lines)

    def _generateDeinitializeOOP(self):
        if not self.m_comrpc_interfaces:
            return ""

        lines = []
        first = self.m_comrpc_interfaces[0]
        firstBase = convertToBaseName(first)
        firstJson = convertToJSONRPC(first)

        full_name_first = next((k for k in self.m_parsed if k.endswith(f"::{first}")), None)
        namespace_first = self._extractStrippedNamespace(full_name_first)

        lines.append(f"if (_impl{firstBase} != nullptr) {{")

        if firstJson in self.m_jsonrpc_interfaces:
            lines.append(f"_impl{firstBase}->Unregister(&_notification);")
            lines.append(f"{namespace_first}::{firstJson}::Unregister(*this);")

        for comrpc in self.m_comrpc_interfaces[1:]:
            baseName = convertToBaseName(comrpc)
            jsonName = convertToJSONRPC(comrpc)

            full_name = next((k for k in self.m_parsed if k.endswith(f"::{comrpc}")), None)
            namespace = self._extractStrippedNamespace(full_name)

            lines.append("")
            lines.append(f"if (_impl{baseName} != nullptr) {{")

            if jsonName in self.m_jsonrpc_interfaces:
                lines.append(f"{namespace}::{jsonName}::Unregister(*this);")
                lines.append(f"_impl{baseName}->Unregister(&_notification);")

            lines.append(f"_impl{baseName}->Release();")
            lines.append(f"_impl{baseName} = nullptr;")
            lines.append("}")

        lines.extend([
            "",
            f"RPC::IRemoteConnection* connection(service->RemoteConnection(_connectionId));",
            f"VARIABLE_IS_NOT_USED uint32_t result = _impl{firstBase}->Release();",
            f"_impl{firstBase} = nullptr;",
            "}"])

        return generateSimpleText(lines)

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
        headers = {header for iface, header in self.m_blueprint.header_lookup.items()}
        if not headers:
            return ""

        lines = [
            f'"$cppref": "{{cppinterfacedir}}/{name}"'
            for name in sorted(headers)]
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