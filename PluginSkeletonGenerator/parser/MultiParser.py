from typing import List, Dict, Tuple
from parser.Parser import Parser, ClassData

class MultiParser:
    def __init__(self, paths: List[str]) -> None:
        self.m_paths: List[str] = paths
        self.m_parsed_data: Dict[str, Tuple[ClassData, str]] = {}
        self.m_header_lookup: Dict[str, str] = {}

    def parseAll(self) -> Dict[str, Tuple[ClassData, str]]:
        for path in self.m_paths:
            parser = Parser(path)
            parsed: Dict[str, ClassData] = parser.parseFile()
            for name, cls_data in parsed.items():
                self.m_parsed_data[name] = (cls_data, path)
                self.m_header_lookup[name] = path
        return self.m_parsed_data