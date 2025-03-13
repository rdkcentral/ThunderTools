from enum import Enum
import os
import re

class FileUtils():
    def __init__(self) -> None:
        pass

    @staticmethod
    def replace_keywords(template, keywords):
        pattern = re.compile('|'.join(re.escape(k) for k in keywords.keys()))
        return pattern.sub(lambda m: keywords[m.group(0)], template)

    @staticmethod
    def read_file(template_name):
        try:
            with open(template_name, 'r') as template_file:
                return template_file.read()
        except FileNotFoundError as e:
            raise (f'Could not load template: {template_name}') from e
        except PermissionError as e:
            raise (f'Permissions denied: {template_name}') from e
        except OSError as e:
            raise OSError(
                f'OS error occurred trying to open: {template_name}, Error details: {e.strerror}')


class Indenter():
    def __init__(self) -> None:
        self.indent_size = 0
        self.indent = ""
        self.indented_code = []
        self.indent_map = self.create_indent_map()

        self.INDENT_RESET = '~INDENT_RESET~'
        self.INDENT_INCREASE = '~INDENT_INCREASE~'
        self.INDENT_DECREASE = '~INDENT_DECREASE~'
        self.REMOVE_LINE = 'rm\*n'

    def create_indent_map(self):
        return {
            '.json': ' ' * 2,
            '.py': ' ' * 4,
            '.h': ' ' * 4,
            '.cpp': ' ' * 4
        }

    def indent_type(self, path):
        extension = os.path.splitext(path)[1]
        self.indent = self.indent_map.get(extension, ' ' * 4)  # Default case: 4 spaces

    def process_indent(self, code, path):
        if not code:
            return ''

        self.indented_code.clear()
        self.indent_type(path)
        lines = code.splitlines()
        self.indent_size = 0

        actions = {
            self.INDENT_RESET: lambda: setattr(self, 'indent_size', 0),
            self.INDENT_INCREASE: lambda: setattr(self, 'indent_size', self.indent_size + 1),
            self.INDENT_DECREASE: lambda: setattr(self, 'indent_size', self.indent_size - 1),
            self.REMOVE_LINE: lambda: None
        }

        for line in lines:
            newline = line.strip()

            action = actions.get(newline, None)
            if action:
                action()
                continue

            indented_line = self.indent * self.indent_size + newline
            self.indented_code.append(indented_line)
        return '\n'.join(self.indented_code)


class Utils():
    def __init__(self) -> None:
        pass

    class Error(Enum):
        EXTENSION = 1
        INITIAL = 2

    # Replaces COMRPC interface to JSONRPC interface
    # IHello -> JHello
    # Under the assumption, an interface is correctly named as I
    @staticmethod
    def replace_comrpc_to_jsonrpc(comrpc_interface):
        return f'J{comrpc_interface[1:]}'

    @staticmethod
    def extract_interface(interface):
        if interface:
            extension = interface[-2:]
            if extension != ".h":
                return False
            return interface[:-2]
        return False
    
    # Currently check to see if interface name begins with I
    @staticmethod
    def check_correct_comrpc(interface):
        if interface:
            return True if interface[0] == "I" else False