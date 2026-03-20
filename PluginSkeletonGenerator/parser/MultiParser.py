'''
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
'''

import os
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