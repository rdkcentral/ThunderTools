from core.PluginBlueprint import PluginBlueprint
from data.FileData import HeaderData, SourceData, CMakeData, JSONData, ConfData
from generators.PluginRepositoryGenerator import PluginRepositoryGenerator
from dataclasses import dataclass
from typing import Callable, List

@dataclass
class GenerationTask:
    name: str
    generator_method: Callable[[object], None]
    data_object: object

class GeneratorCoordinator:
    def __init__(self, name, out_of_process, configuration, parsed_data, header_lookup, locations,
                 preconditions=None, terminations=None, controls=None):
        self.m_blueprint = PluginBlueprint(
            name=name,
            out_of_process=out_of_process,
            configuration=configuration,
            parsed_data=parsed_data,
            header_lookup=header_lookup,
            locations=locations,
            preconditions=preconditions,
            terminations=terminations,
            controls=controls,
        )

    def generateAll(self):
        gen = PluginRepositoryGenerator(self.m_blueprint)

        tasks: List[GenerationTask] = [
            GenerationTask("Header", gen.generateHeader, HeaderData(self.m_blueprint, HeaderData.HeaderType.HEADER)),
            GenerationTask("ModuleHeader", gen.generateModuleHeader, HeaderData(self.m_blueprint, HeaderData.HeaderType.HEADER)),
            GenerationTask("Source", gen.generatePluginSource, SourceData(self.m_blueprint)),
            GenerationTask("ModuleSource", gen.generateModuleSource, SourceData(self.m_blueprint)),
            GenerationTask("CMake", gen.generateCMake, CMakeData(self.m_blueprint)),
            GenerationTask("Conf", gen.generateConfin, ConfData(self.m_blueprint)),
            GenerationTask("JSON", gen.generateJSON, JSONData(self.m_blueprint))
        ]

        if self.m_blueprint.out_of_process:
            tasks.append(GenerationTask(
                "Implementation",
                gen.generateImplementation,
                HeaderData(self.m_blueprint, HeaderData.HeaderType.HEADER_IMPLEMENTATION)
            ))

        for task in tasks:
            print(f"Generating {task.name}")
            task.data_object.prepare()
            task.generator_method(task.data_object)