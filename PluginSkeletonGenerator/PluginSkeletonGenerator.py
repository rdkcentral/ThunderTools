#!/usr/bin/env python3

'''
- thunder version (not in the first version as it will only support Thunder R5.0). But we also need to take into account generated skeleton the code could be slightly different for future Thunder versions.
- plugin name
- COMRPC interface (if any)
- json rpc interface (header names required)
- Does the plugin require the possibility to run OOP
- does the plugin use JSONRPC events ?

TODO:
- does the plugin specific configuration options (is configuration code needed)?
- other plugin access required (use new PluginSmartInterfaceType type for this)
- compile time implementation differentiation needed (e.g. like DisplayInfo)
- special trace categories required (create new category for this plugin)
- subsystems support needed (dependend en set)
- needs workerpool jobs (scheduled or not), so we can generate an example job
'''


import os
from file_data import FileData, HeaderData, SourceData, CMakeData, JSONData, ConfData
from utils import Indenter, FileUtils

import global_variables

class PluginGenerator:
    
    def __init__(self, blueprint_data) -> None:
        self.blueprint_data = blueprint_data
        self.directory = self.blueprint_data.plugin_name
        os.makedirs(self.blueprint_data.plugin_name, exist_ok=True)
        self.indenter = Indenter()

    def load_template(self, template_name):
        return FileUtils.read_file(template_name)
    
    def replace_code(self,template):
        code = FileUtils.replace_keywords(template,self.blueprint_data.keywords)
        return code
        
    def generate_file(self, template_path, output_path):

        template = self.load_template(template_path)
        if template:
            code = self.replace_code(template)

            indented_code = self.indenter.process_indent(code, output_path)
            header_path = os.path.join(self.directory, output_path)
            with open(header_path, 'w') as f:
                    f.write(indented_code)

    def generate_source(self):
        self.generate_file(global_variables.PLUGIN_SOURCE_PATH, f'{self.blueprint_data.plugin_name}.cpp')
        self.generate_file(global_variables.MODULE_SOURCE_PATH, "Module.cpp")

    def generate_headers(self):

        self.generate_file(global_variables.PLUGIN_HEADER_PATH, f'{self.blueprint_data.plugin_name}.h')
        self.generate_file(global_variables.MODULE_HEADER_PATH, "Module.h")

        # Although this is a .cpp file, it's actually most like a .h
        if(self.blueprint_data.out_of_process):
            self.blueprint_data.type = HeaderData.HeaderType.HEADER_IMPLEMENTATION
            self.blueprint_data.populate_keywords()
            self.generate_file(global_variables.PLUGIN_IMPLEMENTATION_PATH, f'{self.blueprint_data.plugin_name}Implementation.cpp')


    def generate_cmake(self):
        self.generate_file(global_variables.CMAKE_PATH, "CMakeLists.txt")

    def generate_json(self):
        self.generate_file(global_variables.PLUGIN_JSON, f'{self.blueprint_data.plugin_name}Plugin.json')

    def generate_conf_in(self):
        self.generate_file(global_variables.PLUGIN_CONF_PATH, f'{self.blueprint_data.plugin_name}.conf.in')

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

def menu():

    plugin_name = input("What will your plugin be called: \n")

    comrpc_interface = []
    jsonrpc_interface = []

    print(f"Enter any COM-RPC interfaces used: (Enter to quit) \nNote: IPlugin is already defined for you")
    while True:
        comrpc = input("Enter a COM-RPC interface: ")
        if not comrpc:
            break
        comrpc_interface.append(comrpc)

    while True:
        jsonrpc = input("Does your plugin require JSONRPC functionality: (Enter Y or N)\n")
        if(jsonrpc.lower() == 'y'):
            jsonrpc= True
            break
        elif(jsonrpc.lower() == 'n'):
            jsonrpc = False
            break
        else:
            print("Unknown character, try again.")

    if jsonrpc:
        print(f"Enter any JSON-RPC interfaces used: (Enter to quit)")
        while True:
            jsonrpc_class = input("Enter a JSON-RPC interface: ")
            if not jsonrpc_class:
                break
            jsonrpc_interface.append(jsonrpc_class)

    while True:
        out_of_process = input("Is your plugin expected to work out of process: (Enter Y or N)\n")
        if(out_of_process.lower() == 'y'):
            out_of_process = True
            break
        elif(out_of_process.lower() == 'n'):
            out_of_process = False
            break
        else:
            print("Unknown character, try again.")

    '''
    TODO: Incomplete
    # subsystems support needed (dependend en set)
    while True:
        sub_systems = input("Is your plugin expected to work out of process: (Enter Y or N)\n")
        if(sub_systems.lower() == 'y'):
            sub_systems = True
            break
        elif(sub_systems.lower() == 'n'):
            sub_systems = False
            break
        else:
            print("Unknown character, try again.")

    if sub_systems:
        preconditions= []
        while True:
            precondition = input("Enter subsystem precondition: ")
            if not precondition:
                break
            preconditions.append(precondition)

    # pluginsmartinterface
    '''

    data = FileData(plugin_name, comrpc_interface, jsonrpc_interface, out_of_process, jsonrpc)
    plugin_generator = PluginGenerator(data)

    file_map = {
        HeaderData: plugin_generator.generate_headers,
        SourceData: plugin_generator.generate_source,
        CMakeData: plugin_generator.generate_cmake,
        ConfData: plugin_generator.generate_conf_in,
        JSONData: plugin_generator.generate_json
    }

    for file_data, generate in file_map.items():
        instance = file_data(plugin_name, comrpc_interface, jsonrpc_interface, out_of_process, jsonrpc)
        instance.populate_keywords()
        plugin_generator.blueprint_data = instance
        generate()

def main():
    menu()
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#

if __name__ == "__main__":
    main()