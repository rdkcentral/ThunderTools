#!/usr/bin/env python3

import helper

class BlueprintData:
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        self.plugin_name = plugin_name
        self.comrpc_interfaces = comrpc_interfaces if comrpc_interfaces else []
        self.jsonrpc_interfaces = jsonrpc_interfaces if jsonrpc_interfaces else []
        self.run_oop = run_oop
        self.json_events = json_events

        self.indenter = helper.Helper()

        self.keywords = self.generate_keywords_map()

    def generate_thunder_license(self):
        return helper.THUNDER_LICENSE
    
    def generate_inherited_methods(self):
        pass
    
    def generate_plugin_methods(self):
        pass
    
    def generate_keywords_map(self):
        return {
            '{{THUNDER_LICENSE}}' : self.generate_thunder_license(),
            '{{PLUGIN_NAME}}' : self.plugin_name,
            '{{PLUGIN_NAME_CAPS}}' : self.plugin_name.upper(),
        }

class HeaderData(BlueprintData):

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events)
        self.keywords = self.generate_keywords_map()
    
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

        # TODO: Implement differentiation between filetypes 
        # Implement indent multiplier

        if not self.comrpc_interfaces:
            return ''

        inheritance = ["PluginHost::IPlugin"]

        if not self.run_oop:
            for inherited_class in self.comrpc_interfaces:
                inheritance.append(f'public {inherited_class}')

        all_inheritance = ', '.join(inheritance)
        return all_inheritance
    
    def generate_oop_inherited_classes(self):
        if not self.comrpc_interfaces:
            return ''

        inheritance = [self.comrpc_interfaces[0]]

        if self.run_oop:
            for inherited_class in self.comrpc_interfaces[1:]:
                inheritance.append(f'public {inherited_class}')

        all_inheritance = ', '.join(inheritance)
        return all_inheritance

    def generate_inherited_methods(self):
        methods = []
        self.indent_size = 2
        if not self.run_oop:
            for inherited in self.comrpc_interfaces:
                method1 = f'void {inherited}Method1() override;'
                method2 = f'void {inherited}Method2() override;'
                methods.extend([method1,method2])
        return ('\n'+ self.indenter.apply_indent()).join(methods)

    def generate_plugin_methods(self):
        method = f'void {self.plugin_name}Method(1);'
        return method
    
    def generate_interface_entry(self):
        entries = []
        for comrpc in self.comrpc_interfaces:
            entry = f'INTERFACE_ENTRY({comrpc})'
            entries.append(entry)
        return ('\n'+ self.indenter.apply_indent()).join(entries)

    def generate_interface_aggregate(self):
        aggregates = []
        if(self.run_oop):
            aggregates = []
            for comrpc in self.comrpc_interfaces:
                aggregate = f'INTERFACE_AGGREGATE({comrpc}, _impl)'
                aggregates.append(aggregate)
        return ('\n'+ self.indenter.apply_indent()).join(aggregates)

    def generate_data_members(self):
        return 'DATA_MEMBER'
    
    def generate_module_plugin_name(self):
        return f'Plugin_{self.plugin_name}'
    
    def generate_forward_declarations(self):
        return " "
    
    def generate_comrpc_interface(self):
        return "Test_COMRPC"
           
    def generate_keywords_map(self):
        return {
            '{{JSONRPC_INTERFACE_INCLUDES}}' : self.generate_jsonrpc_includes(),
            '{{COMRPC_INTERFACE_INCLUDES}}' : self.generate_comrpc_includes(),
            '{{PLUGIN_NAME}}' : self.plugin_name,
            '{{FORWARD_DECLARATIONS}}' : self.generate_forward_declarations(),
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

class SourceData(BlueprintData):

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events)
        self.keywords = self.generate_keywords_map()

    def generate_include_statements(self):
        return f'#include "{self.plugin_name}.h"'

    def generate_plugin_methods(self):
        return "test method"

    def generate_inherited_methods(self):
        return "test inherited method"

    def generate_keywords_map(self):
        return {
            '{{INCLUDE}}' : self.generate_include_statements(),
            '{{PLUGIN_NAME}}' : self.plugin_name,
            '{{INHERITED_METHOD}}' : self.generate_inherited_methods(),
            '{{PLUGIN_METHOD}}' : self.generate_plugin_methods(),
            '{{PRECONDITIONS}}' : "conditions",
            '{{TERMINATIONS}}' : "terminations",
            '{{CONTROLS}}' : "controls"

        }
    
class CMakeData(BlueprintData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events)

    def generate_keywords_map(self):
        return {
            '{{SOURCE_FILES}}' : self.find_source_files()
        }
    
    def find_source_files(self):
        if(self.run_oop):
            return f'{self.plugin_name}.cpp \n{self.plugin_name}Implementation.cpp'
        else:
            return f'{self.plugin_name}.cpp'

class JSONData(BlueprintData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events)

class ConfData(BlueprintData):
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events)

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

