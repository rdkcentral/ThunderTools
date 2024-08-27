#!/usr/bin/env python3

class BlueprintData:
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        self.plugin_name = plugin_name
        self.comrpc_interfaces = comrpc_interfaces if comrpc_interfaces else []
        self.jsonrpc_interfaces = jsonrpc_interfaces if jsonrpc_interfaces else []
        self.run_oop = run_oop
        self.json_events = json_events

        self.keywords = {}

   
    def generate_thunder_license(self):
        return "ADD_THUNDER_LICENSE"
    
    def generate_inherited_methods(self):
        raise NotImplementedError("Method: generate_inherited_methods not implemented for class")
    
    def generate_plugin_methods(self):
        raise NotImplementedError("Method: generate_plugin_methods not implemented for class")


class HeaderData(BlueprintData):

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events)
        self.keywords = self.generate_keywords_map()

    def generate_include_statements(self):
        includes = []

        for jsonrpc in self.jsonrpc_interfaces:
            includes.append(f'#include <interfaces/json/{jsonrpc}.h>')
        
        for comrpc in self.comrpc_interfaces:
            includes.append(f'#include <interfaces/{comrpc}>')

        return '\n'.join(includes)
    
    def generate_inherited_classes(self):

        # TODO: Implement differentiation between filetypes 
        # Implement indent multiplier

        if not self.comrpc_interfaces:
            return ''

        inheritance = [f'{self.comrpc_interfaces[0]}']

        for inherited_class in self.comrpc_interfaces[1:]:
            inheritance.append(f'public {inherited_class}')

        all_inheritance = ','.join(inheritance)
        return all_inheritance

    def generate_inherited_methods(self):
        methods = []
        for inherited in self.comrpc_interfaces:
            method1 = f'void {inherited}Method1() override;'
            method2 = f'void {inherited}Method2() override;'
            methods.extend([method1,method2])
        return '\n'.join(methods)

    def generate_plugin_methods(self):
        method = f'void {self.plugin_name}Method(1);'
        return method
    
    def generate_interface_entry(self):

        entries = []
        for comrpc in self.comrpc_interfaces:
            entry = f'INTERFACE_ENTRY({comrpc})'
            entries.append(entry)
        return '\n'.join(entries)

    def generate_interface_aggregate(self):

        return " "

    def generate_data_members(self):
        return 'DATA_MEMBER'
    
    def generate_module_plugin_name(self):
        return f'Plugin_{self.plugin_name}'
    
    def generate_forward_declarations(self):
        return " "
        
    def generate_keywords_map(self):
        return {
            '{{THUNDER_LICENSE}}' : self.generate_thunder_license(),
            '{{PLUGIN_NAME}}' : self.plugin_name,
            '{{INCLUDE}}' : self.generate_include_statements(),
            '{{FORWARD_DECLARATIONS}}' : self.generate_forward_declarations(),
            '{{INHERITED_CLASS}}' : self.generate_inherited_classes(),
            '{{INHERITED_METHOD}}' : self.generate_inherited_methods(),
            '{{PLUGIN_METHOD}}' : self.generate_plugin_methods(),
            '{{INTERFACE_ENTRY}}' : self.generate_interface_entry(),
            '{{INTERFACE_AGGREGATE}}' : self.generate_interface_aggregate(),
            '{{DATA_MEMBERS}}' : self.generate_data_members(),
            '{{MODULE_PLUGIN_NAME}}' : self.generate_module_plugin_name()
        }

class SourceData(BlueprintData):

    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        super().__init__(plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events)
        self.keywords = self.generate_keywords_map()

    def generate_include_statements(self):
        return f'#include "{self.plugin_name}".h'

    def generate_plugin_methods(self):
        return "test method"

    def generate_inherited_methods(self):
        return "test inherited method"

    def generate_keywords_map(self):
        return {
            '{{THUNDER_LICENSE}}' : self.generate_thunder_license(),
            '{{INCLUDE}}' : self.generate_include_statements(),
            '{{INHERITED_METHOD}}' : self.generate_inherited_methods(),
            '{{PLUGIN_METHOD}}' : self.generate_plugin_methods(),
            '{{PRECONDITIONS}}' : "conditions",
            '{{TERMINATIONS}}' : "terminations",
            '{{CONTROLS}}' : "controls"

        }