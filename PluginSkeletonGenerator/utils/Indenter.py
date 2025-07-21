import os
import re
from typing import List

class Indenter:
    def __init__(self):
        self.m_indent_map = {
            '.json': '  ',
            '.py': '    ',
            '.h': '    ',
            '.cpp': '    ',
        }
        self.m_indent_unit = '    '
        self.m_cpp_mode = False
        self.m_skip_indent = False
        self.m_manual_indent = False # Used for CMake...

    def indentType(self, path: str):
        ext = os.path.splitext(path)[1]
        base = os.path.basename(path)
        self.m_indent_unit = self.m_indent_map.get(ext, '    ')

        self.m_skip_indent = ext == base.endswith('.conf.in')
        self.m_cpp_mode = ext in ('.h', '.cpp')
        self.m_manual_indent = base == 'CMakeLists.txt'

    def _collapseBlank(self, lines: List[str]) -> List[str]:
        collapsed = []
        prev_blank = False
        for line in lines:
            if not line.strip():
                if not prev_blank:
                    collapsed.append('')
                    prev_blank = True
            else:
                collapsed.append(line.rstrip())
                prev_blank = False
        return collapsed

    def _indentCPP(self, lines: List[str]) -> List[str]:
        result = []
        indent = 0
        class_stack = []
        namespace_count = 0
        in_initializer = False
        constructor_mode = False

        for i, raw_line in enumerate(lines):
            line = raw_line.strip()
            if not line:
                result.append('')
                continue

            # Indents after second namespace : Thunder::Plugin
            if re.match(r'namespace\s+\w+\s*{', line):
                result.append(self.m_indent_unit * indent + line)
                namespace_count += 1
                if namespace_count == 2:
                    indent += 1
                continue

            if line == 'END_INTERFACE_MAP':
                indent = max(0, indent - 1)
                result.append(self.m_indent_unit * indent + line)
                continue

            if re.match(r'BEGIN_INTERFACE_MAP\(.+\)', line):
                result.append(self.m_indent_unit * indent + line)
                indent += 1
                continue

            # Scenario } else {
            if re.match(r'^}\s+else\s+{$', line):
                indent = max(0, indent - 1)
                result.append(self.m_indent_unit * indent + line)
                indent += 1
                continue

            # Closing Brkacets
            if re.match(r'^}\s*;?\s*$', line):
                indent = max(0, indent - 1)
                if class_stack:
                    class_stack.pop()
                result.append(self.m_indent_unit * indent + line)
                continue

            if re.match(r'(class|struct)\s+\w+', line) and line.endswith('{'):
                result.append(self.m_indent_unit * indent + line)
                indent += 1
                class_stack.append(indent)
                continue

            if re.match(r'(public|protected|private):', line):
                class_indent = class_stack[-1] if class_stack else indent
                result.append(self.m_indent_unit * (class_indent - 1) + line)
                continue

            #  Constructor declaration line
            if line.endswith(')') and i + 1 < len(lines) and lines[i + 1].strip().startswith(':'):
                class_indent = class_stack[-1] if class_stack else indent
                result.append(self.m_indent_unit * class_indent + line)
                constructor_mode = True
                continue

            if constructor_mode and line.startswith(':'):
                class_indent = class_stack[-1] if class_stack else indent
                in_initializer = True
                result.append(self.m_indent_unit * (class_indent + 1) + line)
                continue

            if in_initializer:
                class_indent = class_stack[-1] if class_stack else indent
                if line.endswith('{'):
                    result.append(self.m_indent_unit * class_indent + line)
                    indent = class_indent + 1
                    in_initializer = False
                    constructor_mode = False
                else:
                    result.append(self.m_indent_unit * (class_indent + 1) + line)
                continue

            result.append(self.m_indent_unit * indent + line)

            if line.endswith('{') and not re.match(r'namespace\s+\w+\s*{', line):
                indent += 1

        return result

    def _identJSON(self, lines: List[str]) -> List[str]:
        result = []
        indent = 0
        for line in lines:
            stripped = line.strip()
            if not stripped:
                result.append('')
                continue

            if stripped.startswith('}') or stripped.startswith(']'):
                indent = max(0, indent - 1)

            result.append(self.m_indent_unit * indent + stripped)

            if stripped.endswith('{') or stripped.endswith('['):
                indent += 1

        return result

    def _indentManual(self, lines: List[str]) -> List[str]:
        # Indent based on ~INDENT_INCREASE~ or ~INDENT_DECREASE~ (see template...)
        result = []
        indent = 0
        for line in lines:
            stripped = line.strip()
            if stripped == '~INDENT_INCREASE~':
                indent += 1
                continue
            if stripped == '~INDENT_DECREASE~':
                indent = max(0, indent - 1)
                continue
            result.append(self.m_indent_unit * indent + stripped)
        return result

    def processIndent(self, code: str) -> str:
        lines = code.splitlines()
        if self.m_skip_indent:
            return code
        elif self.m_manual_indent:
            lines = self._indentManual(lines)
        elif self.m_cpp_mode:
            lines = self._indentCPP(lines)
        elif code.strip().startswith('{'):
            lines = self._identJSON(lines)
        else:
            lines = [line.strip() if line.strip() else '' for line in lines]

        return '\n'.join(self._collapseBlank(lines)) + '\n'