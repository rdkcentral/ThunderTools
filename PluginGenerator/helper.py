THUNDER_LICENSE = """ /*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 Metrological
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
 */ """

# Currently, indent_size remains as 2 due to how the templates are formatted already
# Possibly in the future, this may change depending on complexity, hence why there are helper functions

class Helper():
    def __init__(self) -> None:
        self.indent = '    '
        self.indent_size = 2

    def increase_indent(self):
        self.indent_size = self.indent_size + 1

    def decrease_indent(self):
        self.indent_size = self.indent_size - 1
        if(self.indent_size < 0):
            self.indent_size = 0

    def apply_indent(self):
        return self.indent_size * self.indent