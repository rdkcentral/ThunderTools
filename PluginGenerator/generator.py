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
from blueprint_data import BlueprintData, HeaderData, SourceData, CMakeData, JSONData, ConfData
from helper import Helper

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
            print(f"Could not load template: {template_name}")
            return None
        
    def generate_file(self, template_path, output_path):

        template = self.load_template(template_path)
        if template:
            code = self.replace_code(template)
            header_path = os.path.join(self.directory, output_path)

            with open(header_path, 'w') as f:
                f.write(code)

    def generate_source(self):

        self.generate_file("templates/plugin_source.txt", f'{self.blueprint_data.plugin_name}.cpp')
        self.generate_file("templates/module/module_source.txt", "Module.cpp")

    def generate_headers(self):

        if(self.blueprint_data.run_oop):
            self.generate_file("templates/plugin_implementation.txt", f'{self.blueprint_data.plugin_name}Implementation.cpp')

        self.generate_file("templates/plugin_header.txt", f'{self.blueprint_data.plugin_name}.h')
        self.generate_file("templates/module/module_header.txt", "Module.h")

    def generate_cmake(self):
        self.generate_file("templates/cmake.txt", "CMakeLists.txt")

    def generate_json(self):
       # self.generate_file("templates/cmake.txt", "CMakeLists.txt")
       pass

    def generate_conf_in(self):
        self.generate_file("templates/plugin_conf_in.txt", f'{self.blueprint_data.plugin_name}.conf.in')
        pass

    def replace_code(self,template):
        code = template
        data = self.blueprint_data.keywords
        for keyword, value in data.items():
            code = code.replace(keyword,value)
        return code
    
def menu():

    plugin_name = input("What will your plugin be called: \n")

    comrpc_interface = []
    jsonrpc_interface = []

    print(f"Enter any COM-RPC interfaces used: (Enter ! to quit) \nNote: IPlugin is already defined for you")
    while True:
        comrpc = input("Enter a COM-RPC interface: ")
        if comrpc == '!':
            break
        comrpc_interface.append(comrpc)

    print(f"Enter any JSON-RPC interfaces used: (Enter ! to quit)")
    while True:
        jsonrpc = input("Enter a JSONRPC-RPC interface: ")
        if jsonrpc == '!':
            break
        jsonrpc_interface.append(jsonrpc)

    out_of_process = False

    while True:
        run_oop = input("Is your plugin expected to work out of process: (Enter Y or N)\n")
        if(run_oop.lower() == 'y'):
            out_of_process = True
            break
        elif(run_oop.lower() == 'n'):
            out_of_process = False
            break
        else:
            print("Unknown character, try again.")

    jsonrpc_events = False

    header_data = HeaderData(plugin_name, comrpc_interface, jsonrpc_interface, out_of_process, jsonrpc_events)
    source_data = SourceData(plugin_name, comrpc_interface, jsonrpc_interface, out_of_process, jsonrpc_events)
    cmake_data = CMakeData(plugin_name, comrpc_interface, jsonrpc_interface, out_of_process, jsonrpc_events)
    conf_data = ConfData(plugin_name, comrpc_interface, jsonrpc_interface, out_of_process, jsonrpc_events)

    plugin_generator = PluginGenerator(header_data)
    plugin_generator.generate_headers()

    plugin_generator.blueprint_data = source_data
    plugin_generator.generate_source()

    plugin_generator.blueprint_data = cmake_data
    plugin_generator.generate_cmake()

    plugin_generator.blueprint_data = conf_data
    plugin_generator.generate_conf_in()


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

menu()
