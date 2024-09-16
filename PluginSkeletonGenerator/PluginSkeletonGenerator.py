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
import menu

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
def main():
    menu.menu()
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
if __name__ == "__main__":
    main()