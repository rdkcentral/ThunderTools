import os

from data.FileData import FileData
from utils.FileUtils import FileUtils
from utils.Indenter import Indenter
import core.GlobalVariables as GlobalVariables


class PluginRepositoryGenerator:
    def __init__(self, blueprint) -> None:
        self.m_plugin_name = blueprint.name
        self.m_directory = blueprint.name
        os.makedirs(self.m_directory, exist_ok=False)
        self.m_indenter = Indenter()

    def _loadTemplate(self, template_path: str) -> str:
        return FileUtils.readFile(template_path)

    def _writeFile(self, output_path: str, content: str) -> None:
        output_full = os.path.join(self.m_directory, output_path)
        with open(output_full, "w") as f:
            f.write(content)

    def _generateFile(self, template_path: str, output_filename: str, data: FileData) -> None:
        template = self._loadTemplate(template_path)
        if not template:
            print(f"[WARNING] Template not found: {template_path}")
            return

        print(f"Generating file: {output_filename}")
        code = FileUtils.replaceKeywords(template, data.m_keywords)
        self.m_indenter.indentType(output_filename)
        indented = self.m_indenter.processIndent(code)
        self._writeFile(output_filename, indented)

    def generateHeader(self, header_data: FileData) -> None:
        self._generateFile(GlobalVariables.PLUGIN_HEADER_PATH, f"{self.m_plugin_name}.h", header_data)

    def generateModuleHeader(self, module_data: FileData) -> None:
        self._generateFile(GlobalVariables.MODULE_HEADER_PATH, "Module.h", module_data)

    def generateImplementation(self, impl_data: FileData) -> None:
        self._generateFile(GlobalVariables.PLUGIN_IMPLEMENTATION_PATH, f"{self.m_plugin_name}Implementation.cpp", impl_data)

    def generatePluginSource(self, data: FileData) -> None:
        self._generateFile(GlobalVariables.PLUGIN_SOURCE_PATH, f"{self.m_plugin_name}.cpp", data)

    def generateModuleSource(self, data: FileData) -> None:
        self._generateFile(GlobalVariables.MODULE_SOURCE_PATH, "Module.cpp", data)

    def generateCMake(self, data: FileData) -> None:
        self._generateFile(GlobalVariables.CMAKE_PATH, "CMakeLists.txt", data)

    def generateJSON(self, data: FileData) -> None:
        self._generateFile(GlobalVariables.PLUGIN_JSON, f"{self.m_plugin_name}Plugin.json", data)

    def generateConfin(self, data: FileData) -> None:
        self._generateFile(GlobalVariables.PLUGIN_CONF_PATH, f"{self.m_plugin_name}.conf.in", data)

    def generateAllSources(self, data: FileData) -> None:
        self.generatePluginSource(data)
        self.generateModuleSource(data)