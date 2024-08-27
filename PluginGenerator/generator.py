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
from blueprint_data import BlueprintData, HeaderData, SourceData


header_template_paths = []

class PluginGenerator:
    
    def __init__(self, blueprint_data) -> None:
        self.blueprint_data = blueprint_data
        self.directory = self.blueprint_data.plugin_name
        os.makedirs(self.blueprint_data.plugin_name, exist_ok=True)

    def load_template(self, template_name):
        try:
            with open(template_name, 'r') as template_file:
                return template_file.read()
        except FileNotFoundError:
            print("no file")
            return None
        
    def generate_file(self, template_path, output_path):

        template = self.load_template(template_path)

        if template:

            code = self.replace_code(template)
            header_path = os.path.join(self.directory, output_path)

            with open(header_path, 'w') as f:
                f.write(code)

    def generate_source(self):

        self.generate_file("templates/plugin_source_template.txt", f'{self.blueprint_data.plugin_name}.cpp')
        self.generate_file("templates/module_cpp_file.txt", "Module.cpp")
        pass

    def generate_headers(self):
        self.generate_file("templates/plugin_header_template.txt", f'{self.blueprint_data.plugin_name}.h')
        self.generate_file("templates/module_header_template.txt", "Module.h")
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
        pass

    def replace_code(self,template):
        code = template
        data = self.blueprint_data.keywords
        for keyword, value in data.items():
            code = code.replace(keyword,value)
        return code


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

plugin_name = "HelloWorld"
comrpc_interface = ["COMRPC1", "COMRPC2"]
jsonrpc_interface = ["JSONRPC1", "JSONRPC2"]
run_oop = False
jsonrpc_events = True

#blueprint_data = BlueprintData(plugin_name, comrpc_interface, jsonrpc_interface, run_oop, jsonrpc_events)
header_data = HeaderData(plugin_name, comrpc_interface, jsonrpc_interface, run_oop, jsonrpc_events)
source_data = SourceData(plugin_name, comrpc_interface, jsonrpc_interface, run_oop, jsonrpc_events)

plugin_generator = PluginGenerator(header_data)
plugin_generator.generate_headers()

plugin_generator.blueprint_data = source_data
plugin_generator.generate_source()

