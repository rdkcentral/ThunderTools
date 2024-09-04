#!/usr/bin/env python3

from helper import FileUtils
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

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)

        self.keywords = super().generate_keywords_map()
        self.keywords.update(self.generate_keywords_map())
        self.keywords.update(self.generate_nested_map())
    
    def generate_jsonrpc_includes(self):
        includes = []
        for jsonrpc in self.jsonrpc_interfaces:
            includes.append(f'#include <interfaces/json/{jsonrpc}.h>')

        return '\n'.join(includes)
    
    def generate_comrpc_includes(self):
        includes = []
        for comrpc in self.comrpc_interfaces:
            includes.append(f'#include <interfaces/{comrpc}>')

        return '\n'.join(includes)
    
    def generate_inherited_classes(self):

        inheritance = ["PluginHost::IPlugin"]

        if self.jsonrpc:
            inheritance.append("public PluginHost::JSONRPC")

        if not self.out_of_process:
            for inherited_class in self.comrpc_interfaces:
                inheritance.append(f'public {inherited_class}')

        all_inheritance = ', '.join(inheritance)
        return all_inheritance
    
    def generate_oop_inherited_classes(self):
        if not self.comrpc_interfaces:
            return ''

        inheritance = [self.comrpc_interfaces[0]]

        if self.out_of_process:
            for inherited_class in self.comrpc_interfaces[1:]:
                inheritance.append(f'public {inherited_class}')

        all_inheritance = ', '.join(inheritance)
        return all_inheritance

    def generate_inherited_methods(self):
        methods = []
        if not self.out_of_process:
            for inherited in self.comrpc_interfaces:
                method1 = f'void {inherited}Method1() override;'
                method2 = f'void {inherited}Method2() override;'
                methods.extend([method1,method2])
        return ('\n').join(methods)

    def generate_plugin_methods(self):
        method = f'void {self.plugin_name}Method(1);'
        return method
    
    def generate_interface_entry(self):
        entries = []
        for comrpc in self.comrpc_interfaces:
            entry = f'INTERFACE_ENTRY({comrpc})'
            entries.append(entry)
        return ('\n').join(entries)

    def generate_interface_aggregate(self):
        aggregates = []
        if(self.out_of_process):
            aggregates = []
            for comrpc in self.comrpc_interfaces:
                aggregate = f'INTERFACE_AGGREGATE({comrpc}, _impl)'
                aggregates.append(aggregate)
        return ('\n').join(aggregates)

    def generate_data_members(self):
        return 'DATA_MEMBER'
    
    def generate_module_plugin_name(self):
        return f'Plugin_{self.plugin_name}'
       
    def generate_comrpc_interface(self):
        return "Test_COMRPC"
    
    def generate_keywords_map(self):
        return{
            '{{JSONRPC_INTERFACE_INCLUDES}}' : self.generate_jsonrpc_includes(),
            '{{COMRPC_INTERFACE_INCLUDES}}' : self.generate_comrpc_includes(),
            '{{INHERITED_CLASS}}' : self.generate_inherited_classes(),
            '{{INHERITED_METHOD}}' : self.generate_inherited_methods(),
            '{{PLUGIN_METHOD}}' : self.generate_plugin_methods(),
            '{{INTERFACE_ENTRY}}' : self.generate_interface_entry(),
            '{{INTERFACE_AGGREGATE}}' : self.generate_interface_aggregate(),
            '{{DATA_MEMBERS}}' : self.generate_data_members(),
            '{{MODULE_PLUGIN_NAME}}' : self.generate_module_plugin_name(),
            '{{COMRPC_INTERFACE}}' : self.generate_comrpc_interface(),
            '{{OOP_INHERITED_CLASS}}' : self.generate_oop_inherited_classes()
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
        return  ' '
    
    def generate_config(self):

        if not self.out_of_process:
            template_name = global_variables.CONFIG_CLASS_PATH
            template = FileUtils.read_file(template_name)
            code = FileUtils.replace_keywords(template,self.keywords)
            return code
        return ' '
               
class SourceData(FileData):

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = super().generate_keywords_map()
        self.keywords.update(self.generate_keywords_map())
        self.keywords.update(self.generate_nested_map())

    def generate_include_statements(self):
        return f'#include "{self.plugin_name}.h"'

    def generate_plugin_methods(self):
        return "Plugin method"

    def generate_inherited_methods(self):
        return "Inherited method"
    
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

            template = FileUtils.read_file(template_name)
            code = FileUtils.replace_keywords(template,self.keywords)
            return code
        return ""

    def generate_keywords_map(self):
        return {
            '{{INCLUDE}}' : self.generate_include_statements(),
            '{{INHERITED_METHOD}}' : self.generate_inherited_methods(),
            '{{PLUGIN_METHOD}}' : self.generate_plugin_methods(),
            '{{PRECONDITIONS}}' : "conditions",
            '{{TERMINATIONS}}' : "terminations",
            '{{CONTROLS}}' : "controls"
        }
    
    def generate_nested_map(self):
        return {
            '{{INITIALIZE_IMPLEMENTATION}}' : self.generate_initialize(),
            '{{DEINITIALIZE_IMPLEMENTATION}}' : self.generate_deinitialize()
        }
    
class CMakeData(FileData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = super().generate_keywords_map()
        self.keywords.update(self.generate_keywords_map())

    def generate_keywords_map(self):
        return {
            '{{SOURCE_FILES}}' : self.find_source_files()
        }
    
    def find_source_files(self):
        if(self.out_of_process):
            return f'{self.plugin_name}.cpp \n{self.plugin_name}Implementation.cpp'
        else:
            return f'{self.plugin_name}.cpp'

class JSONData(FileData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = super().generate_keywords_map()
        self.keywords.update(self.generate_keywords_map())

class ConfData(FileData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
        self.keywords = super().generate_keywords_map()
        self.keywords.update(self.generate_keywords_map())

    def generate_keywords_map(self):
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