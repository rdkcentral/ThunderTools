#!/usr/bin/env python3

from utils import FileUtils, Utils
from enum import Enum
import global_variables

class FileData:
    def __init__(self,plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc, plugin_config, notification_interfaces) -> None:
        self.plugin_name = plugin_name
        self.comrpc_interfaces = comrpc_interfaces if comrpc_interfaces else []
        self.jsonrpc_interfaces = jsonrpc_interfaces if jsonrpc_interfaces else []
        self.out_of_process = out_of_process
        self.jsonrpc = jsonrpc
        self.plugin_config = plugin_config
        self.notification_interfaces = notification_interfaces

        self.keywords = self.generate_keywords_map()

    def generate_keywords_map(self):
        return {
            "{{PLUGIN_NAME}}": self.plugin_name,
            "{{PLUGIN_NAME_CAPS}}": self.plugin_name.upper()
        }

class HeaderData(FileData):
    class HeaderType(Enum):
        HEADER = 1
        HEADER_IMPLEMENTATION = 2

    def __init__(
        self,
        plugin_name,
        comrpc_interfaces,
        jsonrpc_interfaces,
        out_of_process,
        jsonrpc,
        plugin_config,
        notification_interfaces
    ) -> None:
        super().__init__(
            plugin_name,
            comrpc_interfaces,
            jsonrpc_interfaces,
            out_of_process,
            jsonrpc,
            plugin_config,
            notification_interfaces
        )
        self.type = HeaderData.HeaderType.HEADER
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        self.keywords.update(self.generate_nested_map())

    def generate_comrpc_includes(self):
        includes = []
        for comrpc in self.comrpc_interfaces:
            if comrpc == 'IConfiguration' and self.type == HeaderData.HeaderType.HEADER:
                break
            includes.append(f'#include <interfaces/{comrpc}.h>')
        if self.type == HeaderData.HeaderType.HEADER:
            includes.append("#include <Module.h>")
            for interface in self.jsonrpc_interfaces:
                if 'I' + interface[1:] in self.notification_interfaces:
                    includes.append(f'#include <interfaces/json/{Utils.replace_comrpc_to_jsonrpc(interface)}.h>')
        return '\n'.join(includes) if includes else 'rm\*n'

    def generate_inherited_classes(self):
        inheritance = ['PluginHost::IPlugin']
        if self.jsonrpc:
            inheritance.append('public PluginHost::JSONRPC')
        if not self.out_of_process:
            inheritance.extend(f'public Exchange::{cls}' for cls in self.comrpc_interfaces)
        return ', '.join(inheritance)

    def generate_oop_inherited_classes(self):
        if not self.comrpc_interfaces:
            return ""
        inheritance = [f': public Exchange::{self.comrpc_interfaces[0]}']
        if self.out_of_process:
            inheritance.extend(f', public Exchange::{cls}' for cls in self.comrpc_interfaces[1:])
        return "".join(inheritance)
    
    def notification_registers(self, interface):
        text = []
        text.append('\n~INDENT_INCREASE~')
        text.append('\nASSERT(notification != nullptr);')
        text.append('\n_adminLock.Lock();')
        text.append(f'''\nauto item = std::find(_{interface[1:].lower()}Notification.begin(), _{interface[1:].lower()}Notification.end(), notification);
                ASSERT(item == _{interface[1:].lower()}Notification.end());
                if (item == _{interface[1:].lower()}Notification.end()) {{
                ~INDENT_INCREASE~
                notification->AddRef();
                _{interface[1:].lower()}Notification.push_back(notification);
                ~INDENT_DECREASE~
                }}

                _adminLock.Unlock(); ''')
        text.append('\n~INDENT_DECREASE~')
        return ''.join(text)
    
    def notification_unregisters(self,interface):
        text = []
        text.append(f'''\n~INDENT_INCREASE~
                ASSERT(notification != nullptr);

                _adminLock.Lock();
                auto item = std::find(_{interface[1:].lower()}Notification.begin(), _{interface[1:].lower()}Notification.end(), notification);
                ASSERT(item != _{interface[1:].lower()}Notification.end());

                if (item != _{interface[1:].lower()}Notification.end()) {{
                ~INDENT_INCREASE~
                (*item)->Release();
                _{interface[1:].lower()}Notification.erase(item);
                ~INDENT_DECREASE~
                }}
                _adminLock.Unlock();
                ~INDENT_DECREASE~''')
        return ''.join(text)
        
    def generate_inherited_methods(self):
        if (not self.out_of_process and self.type != HeaderData.HeaderType.HEADER) or \
        (self.out_of_process and self.type != HeaderData.HeaderType.HEADER_IMPLEMENTATION):
            return "rm\*n"
        
        if not self.comrpc_interfaces:
            return 'rm\*n'

        methods = []
        for inherited in self.comrpc_interfaces:
            if (inherited == 'IConfiguration'):
                continue
            if self.type == HeaderData.HeaderType.HEADER:
                methods.append(f"// {inherited} methods\n" f"uint32_t {inherited}Method1() override;")
                if inherited in self.notification_interfaces:
                    methods.append(f'void Register(Exchange::{inherited}::INotification* notification) override;')
                    methods.append(f'void Unregister(const Exchange::{inherited}::INotification* notification) override;')
                    if f'J{inherited[1:]}' in self.jsonrpc_interfaces and self.out_of_process:
                        methods.append(f'void {inherited}NotificationExample();')
            else:
                methods.append(f'// {inherited} methods')
                if inherited in self.notification_interfaces:               
                    methods.append(f'''uint32_t {inherited}Method1() override {{\n
                                ~INDENT_INCREASE~
                                // This function could be used to call a notify method
                                Notify{inherited}();
                                return Core::ERROR_NONE;
                                ~INDENT_DECREASE~
                                }}\n''')
                else:
                    methods.append(f'uint32_t {inherited}Method1() override {{\n~INDENT_INCREASE~\nreturn Core::ERROR_NONE;\n~INDENT_DECREASE~\n}}\n')
            if inherited in self.notification_interfaces and self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION:
                methods.append(f'void Register(Exchange::{inherited}::INotification* notification) override {{')
                methods.append(self.notification_registers(inherited))
                methods.append('}\n')
                methods.append(f'void Unregister(const Exchange::{inherited}::INotification* notification) override {{')
                methods.append(self.notification_unregisters(inherited))
                methods.append('}\n')

        if self.comrpc_interfaces:
            if self.comrpc_interfaces[-1] == "IConfiguration":
                template_name = global_variables.CONFIGURE_METHOD
                template = FileUtils.read_file(template_name)
                code = FileUtils.replace_keywords(template, self.keywords)
                methods.append(code)
        return ("\n").join(methods)

    def generate_plugin_methods(self):
        method = []
        if self.type == HeaderData.HeaderType.HEADER:
            method = [f'void {self.plugin_name}Method();']
            if self.out_of_process:
                method.append(f'void Deactivated(RPC::IRemoteConnection* connection);')
        return '\n'.join(method)

    def generate_interface_entry(self):
        entries = []
        if self.type == HeaderData.HeaderType.HEADER:
            entries.append(f"INTERFACE_ENTRY(PluginHost::IPlugin)")
            if self.jsonrpc:
                entries.append(f"INTERFACE_ENTRY(PluginHost::IDispatcher)")

        if (self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION) or \
        (not self.out_of_process) and (self.type == HeaderData.HeaderType.HEADER):
            entries.extend(f'INTERFACE_ENTRY(Exchange::{comrpc})' for comrpc in self.comrpc_interfaces)
        return '\n'.join(entries) if entries else 'rm\*n'

    def generate_interface_aggregate(self):
        aggregates = []
        if self.out_of_process:
            for comrpc in self.comrpc_interfaces:
                if comrpc == "IConfiguration":
                    break
                aggregates.append(f'INTERFACE_AGGREGATE(Exchange::{comrpc}, _impl{comrpc[1:]})')
        return ('\n').join(aggregates) if aggregates else 'rm\*n'

    def generate_module_plugin_name(self):
        return f'Plugin_{self.plugin_name}'

    def generate_base_constructor(self):
        constructor = [f' PluginHost::IPlugin()']
        if self.jsonrpc:
            constructor.append(f'\n, PluginHost::JSONRPC()')
        return ''.join(constructor)

    def generate_interface_constructor(self):
        constructor = []
        if not self.comrpc_interfaces:
            return 'rm\*n'
        
        if self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION:
            constructor = [f": Exchange::{self.comrpc_interfaces[0]}()"] + [f", Exchange::{comrpc}()" for comrpc in self.comrpc_interfaces[1:]]
            constructor.append(', _test(0)')
            if self.notification_interfaces:
                constructor.append(', _adminLock()')
                for interface in self.notification_interfaces:
                    constructor.append(f', _{interface[1:].lower()}Notification()')

        if (not self.out_of_process and self.type == HeaderData.HeaderType.HEADER):
            if self.comrpc_interfaces:
                constructor.append(f", Exchange::{self.comrpc_interfaces[0]}()")
            for comrpc in self.comrpc_interfaces[1:]:
                if comrpc == 'IConfiguration':
                    continue
                constructor.append(f", Exchange::{comrpc}()")
        return "\n".join(constructor) if constructor else "rm\*n"

    def generate_member_impl(self):
        members = []
        if self.out_of_process:
            members.append("PluginHost::IShell* _service;")
            members.append("uint32_t _connectionId;")
        if self.out_of_process:
            for comrpc in self.comrpc_interfaces:
                if comrpc == 'IConfiguration':
                    break
                members.append(f"Exchange::{comrpc}* _impl{comrpc[1:]};")
                members.append(f"Core::SinkType<Notification> _notification;")
        if self.notification_interfaces and not self.out_of_process:
            members.append(f"mutable Core::CriticalSection _adminLock;")
            for comrpc in self.notification_interfaces:
                members.append(f'{comrpc[1:]}NotificationVector _{comrpc[1:].lower()}Notification;')
        return "\n".join(members) if members else 'rm\*n'

    def generate_member_constructor(self):
        members = []
        if self.out_of_process:
            members.append(f", _service(nullptr)")
            members.append(f", _connectionId(0)")
            for comrpc in self.comrpc_interfaces:
                if comrpc == "IConfiguration":
                    break
                members.append(f", _impl{comrpc[1:]}(nullptr)")
                members.append(f", _notification(*this)")
        if self.notification_interfaces and not self.out_of_process:
            members.append(f", _adminLock()")
            for comrpc in self.notification_interfaces:
                members.append(f", _{comrpc[1:].lower()}Notification()")
        return "\n".join(members) if members else 'rm\*n'

    def generate_notification_class(self):

        classes = []
        classes.append(f"public RPC::IRemoteConnection::INotification")
        for interface in self.notification_interfaces:
            classes.append(f", public Exchange::{interface}::INotification")
        return "".join(classes)
    
    def generate_notification_constructor(self):
        members = []
        for notif in self.notification_interfaces:
            members.append(f', Exchange::{notif}::INotification()')
        return '\n'.join(members) if members else 'rm\*n'
    
    def generate_notification_entry(self):
        entries = []
        for entry in self.notification_interfaces:
            entries.append(f'INTERFACE_ENTRY(Exchange::{entry}::INotification)')
        return '\n'.join(entries) if entries else 'rm\*n'
        
    def generate_notification_function(self):
        methods = []
        for inherited in self.notification_interfaces:
            if Utils.replace_comrpc_to_jsonrpc(inherited) in self.jsonrpc_interfaces:
                methods.append(f'''void {inherited}Notification() override {{\n~INDENT_INCREASE~\nExchange::J{inherited[1:]}::Event::{inherited}Notification(_parent);\n~INDENT_DECREASE~\n}}\n''')
            else:
                methods.append(f'void {inherited}Notification() override {{\n\n}}')
        return ("\n").join(methods) if methods else 'rm\*n'
    
    def generate_oop_members(self):
        members = []
        if self.notification_interfaces:
            members.append('mutable Core::CriticalSection _adminLock;')
            for interface in self.notification_interfaces:
                members.append(f'{interface[1:]}NotificationVector _{interface[1:].lower()}Notification;')
        return '\n'.join(members) if members else 'rm\*n'
    
    def generate_notify_method(self):
        methods = []
        if self.out_of_process and self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION or not self.out_of_process and HeaderData.HeaderType.HEADER:
            for interface in self.notification_interfaces:
                methods.append(f'void Notify{interface}() const {{')
                methods.append('\n~INDENT_INCREASE~')
                methods.append('\n_adminLock.Lock();')
                methods.append(f'''\nfor (auto* notification : _{interface[1:].lower()}Notification) {{
                            ~INDENT_INCREASE~
                            notification->{interface}Notification();
                            ~INDENT_DECREASE~
                            }}
                            _adminLock.Unlock();
                            ~INDENT_DECREASE~
                            }}\n''')
            
        return ''.join(methods) if methods else 'rm\*n'
    
    def generate_using_container(self):
        usings = []
        if (self.out_of_process and self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION) or \
            (not self.out_of_process and self.type == HeaderData.HeaderType.HEADER):
            for comrpc in self.notification_interfaces:
                usings.append(f'using {comrpc[1:]}NotificationVector = std::vector<Exchange::{comrpc}::INotification*>;')
        return '\n'.join(usings) if usings else 'rm\*n'

    def generate_keyword_map(self):
        return {
            "{{COMRPC_INTERFACE_INCLUDES}}": self.generate_comrpc_includes(),
            "{{INHERITED_CLASS}}": self.generate_inherited_classes(),
            "{{INHERITED_METHOD}}": self.generate_inherited_methods(),
            "{{PLUGIN_METHOD}}": self.generate_plugin_methods(),
            "{{INTERFACE_ENTRY}}": self.generate_interface_entry(),
            "{{INTERFACE_AGGREGATE}}": self.generate_interface_aggregate(),
            "{{MODULE_PLUGIN_NAME}}": self.generate_module_plugin_name(),
            "{{OOP_INHERITED_CLASS}}": self.generate_oop_inherited_classes(),
            "{{BASE_CONSTRUCTOR}}": self.generate_base_constructor(),
            "{{INTERFACE_CONSTRUCTOR}}": self.generate_interface_constructor(),
            "{{MEMBER_IMPL}}": self.generate_member_impl(),
            "{{MEMBER_CONSTRUCTOR}}": self.generate_member_constructor(),
            "{{NOTIFICATION_CLASS}}": self.generate_notification_class(),
            "{{NOTIFICATION_CONSTRUCTOR}}" : self.generate_notification_constructor(),
            "{{NOTIFICATION_ENTRY}}" : self.generate_notification_entry(),
            "{{NOTIFICATION_FUNCTION}}" : self.generate_notification_function(),
            "{{OOP_MEMBERS}}" : self.generate_oop_members(),
            "{{NOTIFY_METHOD}}" : self.generate_notify_method(),
            "{{USING_CONTAINER}}" : self.generate_using_container()
        }

    def generate_nested_map(self):
        return {
            "{{JSONRPC_EVENT}}": self.generate_jsonrpc_event(),
            "{{CONFIG_CLASS}}": self.generate_config(),
        }

    def generate_jsonrpc_event(self):
        if (self.jsonrpc or self.notification_interfaces) and self.out_of_process:
            template_name = global_variables.RPC_NOTIFICATION_CLASS_PATH
            template = FileUtils.read_file(template_name)
            code = FileUtils.replace_keywords(template, self.keywords)
            return code
 
    def generate_config(self):
        code = []
        if self.plugin_config:
            if self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION:
                code.append('~INDENT_DECREASE~\nprivate:\n~INDENT_INCREASE~\n')
                print("Hello)")
            if (not self.out_of_process) or (self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION):
                template_name = global_variables.CONFIG_CLASS_PATH
                template = FileUtils.read_file(template_name)
                code.append(f'{FileUtils.replace_keywords(template, self.keywords)}')
        return ''.join(code) if code else 'rm\*n'

class SourceData(FileData):
    def __init__(
        self,
        plugin_name,
        comrpc_interfaces,
        jsonrpc_interfaces,
        out_of_process,
        jsonrpc,
        plugin_config,
        notification_interfaces
    ) -> None:
        super().__init__(
            plugin_name,
            comrpc_interfaces,
            jsonrpc_interfaces,
            out_of_process,
            jsonrpc,
            plugin_config,
            notification_interfaces
        )
        self.keywords = self.keywords.copy()
        # self.preconditions = preconditions if preconditions else []
        # self.terminations = terminations if terminations else []
        # self.controls = controls if controls else []

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        self.keywords.update(self.generate_nested_map())

    def generate_include_statements(self):
        return_string = f'#include "{self.plugin_name}.h"'
        if self.plugin_config and self.out_of_process:
            return_string += f'\n#include <interfaces/IConfiguration.h>'
        return return_string

    def generate_initialize(self):
        if self.out_of_process:
            template_name = global_variables.INITIALIZE_OOP_PATH
        else:
            template_name = global_variables.INITIALIZE_IP_PATH

        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template, self.keywords)
        return code

    def generate_deinitialize(self):
        if self.out_of_process:
            template_name = global_variables.DENINITIALIZE_OOP_PATH
        else:
            template_name = global_variables.DENINITIALIZE_IP_PATH

        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template, self.keywords)
        return code

    def generate_variable_used(self):
        if self.out_of_process:
            return ""
        return "VARIABLE_IS_NOT_USED "

    def generate_jsonrpc_register(self):

        if not self.jsonrpc_interfaces:
            return 'rm\*n'

        registers = []
        '''
        _implementation->Register(&_volumeNotification);
          Exchange::JVolumeControl::Register(*this, _implementation);
        '''
        for jsonrpc in self.jsonrpc_interfaces:
            registers.append(f"Exchange::{jsonrpc}::Register(*this, this);")

        registers = ("\n").join(registers)
        return registers if registers else "rm\*n"

    def generate_jsonrpc_unregister(self):
        registers = []
        if not self.out_of_process:
            for jsonrpc in self.jsonrpc_interfaces:
                registers.append(f"Exchange::{jsonrpc}::Unregister(*this);")
        else:
            for jsonrpc in self.jsonrpc_interfaces:
                registers.append(f"Exchange::{jsonrpc}::Unregister(*this);")

        registers = ("\n").join(registers)
        return registers if registers else "rm\*n"

    def generate_jsonrpc_includes(self):
        includes = []
        for jsonrpc in self.jsonrpc_interfaces:
            if 'I' + jsonrpc[1:] in self.notification_interfaces:
                continue
            else:
                includes.append(f"#include <interfaces/json/{jsonrpc}.h>")
        return "\n".join(includes) if includes else 'rm\*n'

    """
    def generate_preconditions(self):
        return ', '.join([f'subsystem::{condition}'for condition in self.preconditions])

    def generate_terminations(self):
        return ', '.join([f'subsystem::{termination}'for termination in self.terminations])

    def generate_controls(self):
        return ', '.join([f'subsystem::{control}'for control in self.controls])
    """

    def generate_plugin_method_impl(self):
        if self.out_of_process and self.notification_interfaces:
            method = [f'''\nvoid {self.plugin_name}::Deactivated(RPC::IRemoteConnection* connection) {{
                    ~INDENT_INCREASE~
                    if (connection->Id() == _connectionId) {{
                    ~INDENT_INCREASE~
                    ASSERT(_service != nullptr);
                    Core::IWorkerPool::Instance().Submit(PluginHost::IShell::Job::Create(_service, PluginHost::IShell::DEACTIVATED, PluginHost::IShell::FAILURE));
                    ~INDENT_DECREASE~
                    }}
                    ~INDENT_DECREASE~
                    }}\n''']
            return "".join(method)
        return "rm\*n"

    def generate_inherited_method_impl(self):
        methods = []
        if not self.out_of_process:
            for inherited in self.comrpc_interfaces:
                methods.append(f'uint32_t {self.plugin_name}::{inherited}Method1() {{')
                methods.append(f'~INDENT_INCREASE~')
                if Utils.replace_comrpc_to_jsonrpc(inherited) in self.jsonrpc_interfaces:
                    methods.append(f'''// Note this an example of a notification method that can call the JSONRPC interface equivalent.
                                Exchange::{Utils.replace_comrpc_to_jsonrpc(inherited)}::Event::{inherited}Notification(*this);''')
                methods.append(f'return Core::ERROR_NONE;')
                methods.append(f'~INDENT_DECREASE~')
                methods.append(f'}}')
                if inherited in self.notification_interfaces:
                    methods.append(f'void {self.plugin_name}::Register(Exchange::{inherited}::INotification* notification) {{')
                    methods.append(HeaderData.notification_registers(None, inherited))
                    methods.append('}\n')
                    methods.append(f'void {self.plugin_name}::Unregister(const Exchange::{inherited}::INotification* notification) {{')
                    methods.append(HeaderData.notification_unregisters(None, inherited))
                    methods.append('}\n')
            return ("\n").join(methods)
        return 'rm\*n'
    
    def generate_nested_query(self):
        nested_query = []
        closing_brackets = len(self.comrpc_interfaces) - 1
        if self.plugin_config:
            closing_brackets -= 1
        iteration = 0

        for comrpc in self.comrpc_interfaces[1:]:
            if comrpc == 'IConfiguration':
                break
            nested_query.append("\nrm\*n \n~INDENT_INCREASE~\n")
            if self.comrpc_interfaces[iteration] in self.notification_interfaces:
                nested_query.append(f"_impl{self.comrpc_interfaces[iteration][1:]}->Register(&notification);\n")
            if any(Utils.replace_comrpc_to_jsonrpc(self.comrpc_interfaces[iteration]) in notif for notif in self.jsonrpc_interfaces):
                nested_query.append(f'Exchange::{Utils.replace_comrpc_to_jsonrpc(self.comrpc_interfaces[iteration])}::Register(*this, _impl{self.comrpc_interfaces[iteration][1:]});\n')
            nested_query.append(f"_impl{comrpc[1:]} = _impl{comrpc[0][1:]}->QueryInterface<Exchange::{comrpc[1:]}>();")
            nested_query.append(f'''\nif (_impl{comrpc[1:]} == nullptr) {{
                                ~INDENT_INCREASE~
                                message = _T("Couldn't create instance of _impl{comrpc}")
                                ~INDENT_DECREASE~
                                }} else {{\n''')
            iteration += 1
            
        nested_query.append(self.generate_nested_initialize(iteration))
            
        for i in range(closing_brackets):
            nested_query.append("\n~INDENT_DECREASE~")
            nested_query.append("\n}")
        
        return ''.join(nested_query)

    def generate_nested_initialize(self, iteration):
      
        text = []
        rootCOMRPC = self.comrpc_interfaces[0][1:] if self.comrpc_interfaces else 'IPlugin'

        if self.comrpc_interfaces:
            text.append("\n~INDENT_INCREASE~\n")
            if self.notification_interfaces:
                text.append(f'_impl{self.comrpc_interfaces[iteration][1:]}->Register(&_notification);\n')
            if self.jsonrpc_interfaces:
                if self.jsonrpc_interfaces[-1] == Utils.replace_comrpc_to_jsonrpc(self.comrpc_interfaces[iteration]):
                        text.append(f'Exchange::{self.jsonrpc_interfaces[-1]}::Register(*this, _impl{self.comrpc_interfaces[iteration][1:]});\n')
        if self.plugin_config:
            #text.append("\n~INDENT_INCREASE~\n")
            text.append(f'''\nExchange::IConfiguration* configuration = _impl{rootCOMRPC}->QueryInterface<Exchange::IConfiguration>();
            ASSERT(configuration != nullptr);
            if (configuration != nullptr) {{
                ~INDENT_INCREASE~
                if (configuration->Configure(service) != Core::ERROR_NONE) {{
                    ~INDENT_INCREASE~
                    message = _T("{self.plugin_name} could not be configured.");
                    ~INDENT_DECREASE~
                }}
            ~INDENT_DECREASE~
            configuration->Release();
            }}''')
            
        return ''.join(text) if text else 'rm\*n'
    
    def generate_configure_implementation(self):
        return 'Config config;\nconfig.FromString(service->ConfigLine());\nTRACE(Trace::Information, (_T("This is just an example: [%s])"), config.Example));' if self.plugin_config else 'rm\*n'
    
    def generate_nested_deinitialize(self):
        text = []
        if not self.comrpc_interfaces:
            return ''
        text.append(f'if (_impl{self.comrpc_interfaces[0][1:]} != nullptr) {{')
        text.append(f'\n~INDENT_INCREASE~')
        if self.notification_interfaces:
            if self.notification_interfaces[0] == self.comrpc_interfaces[0]:
                text.append(f'\n_impl{self.comrpc_interfaces[0][1:]}->Unregister(&_notification);')
        if Utils.replace_comrpc_to_jsonrpc(self.comrpc_interfaces[0]) in self.jsonrpc_interfaces:
                text.append(f'\nExchange::{Utils.replace_comrpc_to_jsonrpc(self.comrpc_interfaces[0])}::Unregister(*this);')

        for comrpc in self.comrpc_interfaces[1:]:
            if comrpc == 'IConfiguration':
                break
            text.append(f'''\nif (_impl{comrpc[1:]} != nullptr) {{
                    \n~INDENT_INCREASE~\n''')
            if Utils.replace_comrpc_to_jsonrpc(comrpc) in self.jsonrpc_interfaces:
                    text.append(f'\nExchange::{Utils.replace_comrpc_to_jsonrpc(comrpc)}::Unregister(*this);')
            if comrpc in self.notification_interfaces:
                    text.append(f'\n_impl{comrpc[1:]}->Unregister(&_notification);')
            text.append(f"\n_impl{comrpc[1:]}->Release();")
            text.append(f'\n_impl{comrpc[1:]} = nullptr;')
            text.append('\n~INDENT_DECREASE~')
            text.append('\n}')

        text.append(f'''\nRPC::IRemoteConnection* connection(service->RemoteConnection(_connectionId));
                \nVARIABLE_IS_NOT_USED uint32_t result = _impl{self.comrpc_interfaces[0][1:]}->Release();
                \n_impl{self.comrpc_interfaces[0][1:]} = nullptr;''')
        return ''.join(text)
    
    def generate_assert_implementation(self):
        asserts = []
        for comrpc in self.comrpc_interfaces:
            if comrpc == 'IConfiguration':
                continue
            asserts.append(f'ASSERT(_impl{comrpc[1:]} == nullptr);')
        return '\n'.join(asserts)
    
    def generate_register_notification(self):
        return "_service->Register(&_notification);"
    
    def generate_unregister_notification(self):
        return "_service->Unregister(&_notification);"
    
    def generate_keyword_map(self):
        return {
            "{{INCLUDE}}": self.generate_include_statements(),
            """
            '{{PRECONDITIONS}}' : self.generate_preconditions(),
            '{{TERMINATIONS}}' : self.generate_terminations(),
            '{{CONTROLS}}' : self.generate_controls(),
            """
            "{{VARIABLE_NOT_USED}}": self.generate_variable_used(),
            "{{REGISTER}}": self.generate_jsonrpc_register(),
            "{{JSONRPC_UNREGISTER}}": self.generate_jsonrpc_unregister(),
            "{{COMRPC}}": f'{self.comrpc_interfaces[0] if self.comrpc_interfaces else "Exchange::IPlugin"}',
            "{{COMRPC[1:]}}" : f'{self.comrpc_interfaces[0][1:] if self.comrpc_interfaces else "Exchange::IPlugin"}',
            "{{JSONRPC_INTERFACE_INCLUDES}}": self.generate_jsonrpc_includes(),
            "{{PLUGIN_METHOD_IMPL}}": self.generate_plugin_method_impl(),
            "{{INHERITED_METHOD_IMPL}}": self.generate_inherited_method_impl(),
            "{{VARIABLE_NOT_USED}}" : self.generate_variable_used(),
            "{{NESTED_QUERY}}" : self.generate_nested_query(),
            "{{CONFIGURE_IP}}" : self.generate_configure_implementation(),
            "{{DEINITIALIZE}}" : self.generate_nested_deinitialize(),
            "{{ASSERT_IMPL}}" : self.generate_assert_implementation(),
            "{{REGISTER_NOTIFICATION}}" : self.generate_register_notification(),
            "{{UNREGISTER_NOTIFICATION}}" : self.generate_unregister_notification()
        }

    def generate_nested_map(self):
        return {
            "{{INITIALIZE_IMPLEMENTATION}}": self.generate_initialize(),
            "{{DEINITIALIZE_IMPLEMENTATION}}": self.generate_deinitialize(),
        }


class CMakeData(FileData):

    def __init__(
        self,
        plugin_name,
        comrpc_interfaces,
        jsonrpc_interfaces,
        out_of_process,
        jsonrpc,
        plugin_config,
        notification_interfaces
    ) -> None:
        super().__init__(
            plugin_name,
            comrpc_interfaces,
            jsonrpc_interfaces,
            out_of_process,
            jsonrpc,
            plugin_config,
            notification_interfaces
        )
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        # self.keywords.update(self.generate_nested_map())

    def generate_set_mode(self):
        s = ''
        if self.out_of_process:
            s = (f'set(PLUGIN_{self.plugin_name.upper()}_MODE "Local" CACHE STRING "Controls if the plugin should run in its own process, in process or remote.")')
        return s if s else 'rm\*n'
    
    def generate_set_config(self):
        s = ''
        if self.plugin_config:
            s = (f'set(PLUGIN_{self.plugin_name.upper()}_EXAMPLE "Example Text" CACHE STRING "Example String")')
        return s if s else 'rm\*n'

    def generate_keyword_map(self):
        return {
                "{{SOURCE_FILES}}": self.find_source_files(),
                '{{SET_MODE}}' : self.generate_set_mode(),
                "{{SET_CONFIG}}" : self.generate_set_config()
            }

    def find_source_files(self):
        if self.out_of_process:
            return f"{self.plugin_name}.cpp \n{self.plugin_name}Implementation.cpp"
        else:
            return f"{self.plugin_name}.cpp"


class JSONData(FileData):

    def __init__(
        self,
        plugin_name,
        comrpc_interfaces,
        jsonrpc_interfaces,
        out_of_process,
        jsonrpc,
        plugin_config,
        notification_interfaces
    ) -> None:
        super().__init__(
            plugin_name,
            comrpc_interfaces,
            jsonrpc_interfaces,
            out_of_process,
            jsonrpc,
            plugin_config,
            notification_interfaces
        )
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        self.keywords.update(self.generate_nested_map())

    def generate_cppref(self):
        cppref = []
        for comrpc in self.comrpc_interfaces:
            if comrpc == 'IConfiguration':
                break
            cppref.append(f'"$cppref": "{{cppinterfacedir}}/{comrpc}.h"')
        return ",\n".join(cppref) if cppref else 'rm\*n'

    def generate_json_info(self):
        template_name = global_variables.JSON_INFO
        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template, self.keywords)
        return code

    def generate_json_configuration(self):
        code = []
        if self.plugin_config:
            template_name = global_variables.JSON_CONFIGURATION
            template = FileUtils.read_file(template_name)
            code = FileUtils.replace_keywords(template, self.keywords)
        return code if code else "rm\*n"

    def generate_json_interface(self):
        template_name = global_variables.JSON_INTERFACE
        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template, self.keywords)
        return code

    def generate_keyword_map(self):
        return {
            "{{cppref}}": self.generate_cppref(),
        }

    def generate_nested_map(self):
        return {
            "{{JSON_INFO}}": self.generate_json_info(),
            "{{JSON_CONFIGURATION}}": self.generate_json_configuration(),
            "{{JSON_INTERFACE}}": self.generate_json_interface(),
        }

class ConfData(FileData):

    def __init__(
        self,
        plugin_name,
        comrpc_interfaces,
        jsonrpc_interfaces,
        out_of_process,
        jsonrpc,
        plugin_config,
        notification_interfaces
    ) -> None:
        super().__init__(
            plugin_name,
            comrpc_interfaces,
            jsonrpc_interfaces,
            out_of_process,
            jsonrpc,
            plugin_config,
            notification_interfaces
        )
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        # self.keywords.update(self.generate_nested_map())

    def generate_config(self):
        configuration = []
        configuration.append("configuration = JSON()")
        if self.plugin_config:
            configuration.append(f'configuration.add("example", "@PLUGIN_{self.plugin_name.upper()}_EXAMPLE@")')
        return '\n'.join(configuration)
    
    def generate_root(self):
        root = []
        if self.out_of_process:
            root.append(f'root = JSON() \n root.add("mode", "@PLUGIN_{self.plugin_name.upper()}_MODE@")')
            root.append(f'configuration.add("root", root)')
        return '\n'.join(root) if root else 'rm\*n'

    def generate_keyword_map(self):
        return {
            "{{PLUGIN_STARTMODE}}": f'"@PLUGIN_{self.plugin_name.upper()}_STARTMODE@"',
            "{{OOP_ROOT}}" : self.generate_root(),
            '{{CONFIG}}' : self.generate_config()
        }


# Not in use currently, may use later on to track rather than hardcode
class PluginData:
    # todo: store data such as class names, filenames etc
    def __init__(self) -> None:
        self.classes = []
        self.file_names = []

    def add_class(self, class_name):
        pass