#!/usr/bin/env python3

from utils import FileUtils
from enum import Enum
import global_variables

class FileData:
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc) -> None:
        self.plugin_name = plugin_name
        self.comrpc_interfaces = comrpc_interfaces if comrpc_interfaces else []
        self.jsonrpc_interfaces = jsonrpc_interfaces if jsonrpc_interfaces else []
        self.out_of_process = out_of_process
        self.jsonrpc = jsonrpc

        self.keywords = self.generate_keywords_map()

    def generate_keywords_map(self):
        return {
            '{{PLUGIN_NAME}}' : self.plugin_name,
            '{{PLUGIN_NAME_CAPS}}' : self.plugin_name.upper()
        }
    
class HeaderData(FileData):

    class HeaderType(Enum):
        HEADER = 1
        HEADER_IMPLEMENTATION = 2

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                preconditions, terminations, controls, type=None) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)

        self.type = type if type else HeaderData.HeaderType.HEADER
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        self.keywords.update(self.generate_nested_map())
    
    def generate_jsonrpc_includes(self):
        return '\n'.join([f'#include <interfaces/json/{jsonrpc}.h>' for jsonrpc in self.jsonrpc_interfaces])

    def generate_comrpc_includes(self):
        return '\n'.join([f'#include <interfaces/{comrpc}>' for comrpc in self.comrpc_interfaces])
    
    def generate_inherited_classes(self):
        inheritance = ["PluginHost::IPlugin"]
        if self.jsonrpc:
            inheritance.append("public PluginHost::JSONRPC")
        if not self.out_of_process:
            inheritance.extend(f'public Exchange::{cls}' for cls in self.comrpc_interfaces)
        return ', '.join(inheritance)
    
    def generate_oop_inherited_classes(self):
        if not self.comrpc_interfaces:
            return ''
        inheritance = [self.comrpc_interfaces[0]]
        if self.out_of_process:
            inheritance.extend(f'public {cls}' for cls in self.comrpc_interfaces[1:])
        return ', '.join(inheritance)

    def generate_inherited_methods(self):
        if (not self.out_of_process and self.type != HeaderData.HeaderType.HEADER) or \
            (self.out_of_process and self.type != HeaderData.HeaderType.HEADER_IMPLEMENTATION):
            return ''
        
        methods = [
            f'// {inherited} methods\n'
            f'void {inherited}Method1() override;\n'
            f'void {inherited}Method2() override;\n'
            for inherited in self.comrpc_interfaces]
        return ('\n').join(methods)

    def generate_plugin_methods(self):
        method = f'void {self.plugin_name}Method();'
        return method
    
    def generate_interface_entry(self):
        entries = []
        if self.type == HeaderData.HeaderType.HEADER:
            entries.append(f'INTERFACE_ENTRY(PluginHost::IPlugin)')
            if self.jsonrpc:
                entries.append(f'INTERFACE_ENTRY(PluginHost::IDispatcher)')

        if (self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION) or \
            ((not self.out_of_process) and (self.type == HeaderData.HeaderType.HEADER)):
            entries.extend(f'INTERFACE_ENTRY(Exchange::{comrpc})' for comrpc in self.comrpc_interfaces)
        return '\n'.join(entries) if entries else 'rm\*n'
    
    def generate_interface_aggregate(self):
        if(self.out_of_process):
            aggregates = [f'INTERFACE_AGGREGATE(Exchange::{comrpc}, _impl{comrpc})' for comrpc in self.comrpc_interfaces]
            return ('\n').join(aggregates)
        return 'rm\*n'
    
    def generate_module_plugin_name(self):
        return f'Plugin_{self.plugin_name}'
    
    def generate_interface_constructor(self):
        if not self.comrpc_interfaces:
            return ''
        
        if (self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION) or \
            ((not self.out_of_process) and (self.type == HeaderData.HeaderType.HEADER)):
            constructor = [f' {self.comrpc_interfaces[0]}()\n,'] + \
            [f' {comrpc}()\n,' for comrpc in self.comrpc_interfaces[1:]]
            return ''.join(constructor)
        return ''

    def generate_keyword_map(self):
        return{
            '{{JSONRPC_INTERFACE_INCLUDES}}' : self.generate_jsonrpc_includes(),
            '{{COMRPC_INTERFACE_INCLUDES}}' : self.generate_comrpc_includes(),
            '{{INHERITED_CLASS}}' : self.generate_inherited_classes(),
            '{{INHERITED_METHOD}}' : self.generate_inherited_methods(),
            '{{PLUGIN_METHOD}}' : self.generate_plugin_methods(),
            '{{INTERFACE_ENTRY}}' : self.generate_interface_entry(),
            '{{INTERFACE_AGGREGATE}}' : self.generate_interface_aggregate(),
            '{{MODULE_PLUGIN_NAME}}' : self.generate_module_plugin_name(),
            '{{OOP_INHERITED_CLASS}}' : self.generate_oop_inherited_classes(),
            '{{INTERFACE_CONSTRUCTOR}}' : self.generate_interface_constructor()
        }
    
    def generate_nested_map(self):
        return{
            '{{JSONRPC_EVENT}}' : self.generate_jsonrpc_event(),
            '{{CONFIG_CLASS}}' : self.generate_config()
        }

    def generate_jsonrpc_event(self):
        if self.out_of_process:
            template_name = global_variables.RPC_NOTIFICATION_CLASS_PATH
            template = FileUtils.read_file(template_name)
            code = FileUtils.replace_keywords(template,self.keywords)
            return code
        return  'rm\*n'
    
    def generate_config(self):

        if (not self.out_of_process) or (self.type == HeaderData.HeaderType.HEADER_IMPLEMENTATION):
            template_name = global_variables.CONFIG_CLASS_PATH
            template = FileUtils.read_file(template_name)
            code = FileUtils.replace_keywords(template,self.keywords)
            return code
        return 'rm\*n'
               
class SourceData(FileData):

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                preconditions, terminations, controls) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = self.keywords.copy()
        self.preconditions = preconditions if preconditions else []
        self.terminations = terminations if terminations else []
        self.controls = controls if controls else []

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        self.keywords.update(self.generate_nested_map())

    def generate_include_statements(self):
        return f'#include "{self.plugin_name}.h"'

    def generate_initialize(self):

        if self.out_of_process:
            template_name = global_variables.INITIALIZE_OOP_PATH
        else:
            template_name = global_variables.INITIALIZE_IP_PATH

        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template,self.keywords)
        return code

    def generate_deinitialize(self):

        if self.out_of_process:
            template_name = global_variables.DENINITIALIZE_OOP_PATH
        else:
            template_name = global_variables.DENINITIALIZE_IP_PATH

        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template,self.keywords)
        return code
    
    def generate_variable_used(self):
        
        if self.out_of_process:
            return ''
        return " VARIABLE_IS_NOT_USED"
    
    def generate_jsonrpc_register(self):

        registers = []
        if not self.out_of_process:
            for jsonrpc in self.jsonrpc_interfaces:
                registers.append(f'Exchange::{jsonrpc}::Register(*this, this);')
        else:
            for jsonrpc in self.jsonrpc_interfaces:
                registers.append(f'Exchange::{jsonrpc}::Register(*this, impl{jsonrpc});')

        registers = ('\n').join(registers)
        return registers if registers else 'rm\*n'
    
    def generate_jsonrpc_unregister(self):

        registers = []
        if not self.out_of_process:
            for jsonrpc in self.jsonrpc_interfaces:
                registers.append(f'Exchange::{jsonrpc}::Unregister(*this);')
        else:
            for jsonrpc in self.jsonrpc_interfaces:
                registers.append(f'Exchange::{jsonrpc}::Unregister(*this);')

        registers = ('\n').join(registers)
        return registers if registers else 'rm\*n'
    
    def generate_preconditions(self):
        return ', '.join([f'subsystem::{condition}'for condition in self.preconditions])

    def generate_terminations(self):
        return ', '.join([f'subsystem::{termination}'for termination in self.terminations])

    def generate_controls(self):
        return ', '.join([f'subsystem::{control}'for control in self.controls])

    def generate_keyword_map(self):
        return {
            '{{INCLUDE}}' : self.generate_include_statements(),
            '{{PRECONDITIONS}}' : self.generate_preconditions(),
            '{{TERMINATIONS}}' : self.generate_terminations(),
            '{{CONTROLS}}' : self.generate_controls(),
            '{{VARIABLE_NOT_USED}}' : self.generate_variable_used(),
            '{{JSONRPC_REGISTER}}' : self.generate_jsonrpc_register(),
            '{{JSONRPC_UNREGISTER}}' : self.generate_jsonrpc_unregister(),
            '{{COMRPC}}' : f'{self.comrpc_interfaces[0] if self.comrpc_interfaces else "INTERFACE_NEEDED"}'
        }
    
    def generate_nested_map(self):
        return {
            '{{INITIALIZE_IMPLEMENTATION}}' : self.generate_initialize(),
            '{{DEINITIALIZE_IMPLEMENTATION}}' : self.generate_deinitialize()
        }
    
class CMakeData(FileData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                preconditions=None, terminations=None, controls=None) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        #self.keywords.update(self.generate_nested_map())

    def generate_keyword_map(self):
        return {
            '{{SOURCE_FILES}}' : self.find_source_files()
        }
    
    def find_source_files(self):
        if(self.out_of_process):
            return f'{self.plugin_name}.cpp \n{self.plugin_name}Implementation.cpp'
        else:
            return f'{self.plugin_name}.cpp'

class JSONData(FileData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                preconditions=None, terminations=None, controls=None) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        self.keywords.update(self.generate_nested_map())

    def generate_cppref(self):        
        return ",\n".join(f'"$cppref": "{{cppinterfacedir}}/{comrpc}.h"' for comrpc in self.comrpc_interfaces) \
            if self.comrpc_interfaces else 'rm\*n'

    def generate_json_info(self):
        template_name = global_variables.JSON_INFO
        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template,self.keywords)
        return code
    
    def generate_json_configuration(self):
        template_name = global_variables.JSON_CONFIGURATION
        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template,self.keywords)
        return code
    
    def generate_json_interface(self):
        template_name = global_variables.JSON_INTERFACE
        template = FileUtils.read_file(template_name)
        code = FileUtils.replace_keywords(template,self.keywords)
        return code

    def generate_keyword_map(self):
        return {
            '{{cppref}}' : self.generate_cppref(),
        }
    
    def generate_nested_map(self):
        return {
            '{{JSON_INFO}}' : self.generate_json_info(),
            '{{JSON_CONFIGURATION}}' : self.generate_json_configuration(),
            '{{JSON_INTERFACE}}' : self.generate_json_interface()
        }

class ConfData(FileData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                preconditions=None, terminations=None, controls=None) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = self.keywords.copy()

    def populate_keywords(self):
        self.keywords.update(self.generate_keyword_map())
        #self.keywords.update(self.generate_nested_map())

    def generate_keyword_map(self):
        return {
            '{{PLUGIN_STARTMODE}}' : f'"@PLUGIN_{self.plugin_name.upper()}_STARTMODE@"'
        }

# Not in use currently, may use later on to track rather than hardcode
class PluginData():
    # todo: store data such as class names, filenames etc
    def __init__(self) -> None:
        self.classes = []
        self.file_names = []

    def add_class(self, class_name):
        pass