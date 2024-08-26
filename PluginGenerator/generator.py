#!/usr/bin/env python3

'''
- thunder version (not in the first version as it will only support Thunder R5.0). But we also need to take into account generated skeleton the code could be slightly different for future Thunder versions.
- plugin name
- COMRPC interface (if any)
- json rpc interface (header names required)
- Does the plugin require the possibility to run OOP
- does the plugin use JSONRPC events ?
- does the plugin specific configuration options (is configuration code needed)?
- other plugin access required (use new PluginSmartInterfaceType type for this)
- compile time implementation differentiation needed (e.g. like DisplayInfo)
- special trace categories required (create new category for this plugin)
- subsystems support needed (dependend en set)
- needs workerpool jobs (scheduled or not), so we can generate an example job

'''
import os

class PluginGenerator:
    
    def __init__(self, plugin_name, comrpc_interfaces, jsonrpc_interfaces, run_oop, json_events) -> None:
        self.plugin_name = plugin_name
        self.comrpc_interfaces = comrpc_interface if comrpc_interface else []
        self.jsonrpc_interfaces = jsonrpc_interface if jsonrpc_interface else []
        self.run_oop = run_oop
        self.json_events = json_events
        self.map_of_keyword = {}

    def load_template(self, template_name):
        with open(template_name, 'r') as template_file:
            return template_file
        
    def generate_header(self, template_path, output_path):
        pass

    def generate_plugin(self):
        '''
        Generate the following:
        - Module .h/.cpp
        - Plugin .h/.cpp
        - OOP implementation .cpp
        - Plugin .conf.in
        - CMake .txt
        - Plugin .json
        '''
        
        os.makedirs("HelloWorld", exist_ok=True)

    def add_includes(self):
        
        includes = []

        for jsonrpc in self.jsonrpc_interface:
            includes.append(f'#include <interfaces/json/{jsonrpc}.h>')
        
        for comrpc in self.comrpc_interface:
            includes.append(f'#include <interfaces/{comrpc}>')

        return '\n'.join(includes)
        
    def add_inherited_classes(self):

        # TODO: Implement differentiation between filetypes 
        # Implement indent multiplier

        inhertance = ''
        if comrpc_interface:
            first_inheritance = f'public {self.comrpc_interfaces[0]}'
            if len(first_inheritance > 1):
                for inherited_class in self.comrpc_interfaces[1:]:
                    next_inheritance = "\n".join(f" public {inherited_class}")
                inhertance = f'{first_inheritance}, {next_inheritance}'
            else:
                inheritance = f": {first_inheritance}"
        return inheritance
        
    def add_inherited_methods(self):
        pass

    def add_thunder_license(self):
        return "ADD_THUNDER_LICENSE"
    
    def add_forward_declarations(self):
        pass

    def add_plugin_methods(self):
        pass

    def add_interface_entry(self):

        pass

    def add_interface_aggregate(self):

        if(run_oop == True):
            
        else:
        pass

    def add_data_members(self):
        pass

    def map_of_keywords(self):
        
        self.map_of_keywords = {
            '{{THUNDER_LICENSE}}' : self.add_thunder_license(),
            '{{PLUGIN_NAME}}' : self.plugin_name,
            '{{INCLUDE}}' : self.add_includes(),
            '{{FORWARD_DECLARATIONS}}' : self.add_forward_declarations(),
            '{{INHERITED_CLASS}}' : self.add_inherited_classes(),
            '{{INHERITED_METHOD}}' : self.add_inherited_methods(),
            '{{PLUGIN_METHOD}}' : self.add_plugin_methods(),
            '{{INTERFACE_ENTRY}}' : self.add_interface_entry(),
            '{{INTERFACE_AGGREGATE}}' : self.add_interface_aggregate(),
            '{{DATA_MEMBERS}}' : self.add_data_members()
        }

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#


plugin_name = "HelloWorld"
comrpc_interface = ["COMRPC1", "COMRPC2"]
jsonrpc_interface = ["JSONRPC1", "JSONRPC2"]
run_oop = True
jsonrpc_events = True


print("hello world")

