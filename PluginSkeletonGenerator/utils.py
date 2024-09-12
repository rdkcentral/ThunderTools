import os
class FileUtils():
    def __init__(self) -> None:
        pass

    @staticmethod
    def replace_keywords(template, keywords):
        code = template
        data = keywords
        for keyword, value in data.items():
            code = code.replace(keyword,value)
        return code
    
    @staticmethod
    def read_file(template_name):
        try:
            with open(template_name, 'r') as template_file:
                template = template_file.read()
        except FileNotFoundError:
            print(f"Could not load template: {template_name}")
            return None
        return template

class Indenter():
    def __init__(self) -> None:
        self.indent_size = 0
        self.indent = ""
        self.indented_code = []

    def indent_type(self, path):

        extension = os.path.splitext(path)[1]
        if extension == '.json':
            self.indent = ' ' * 2
        else:
            self.indent = ' ' * 4

    def process_indent(self, code, path):
        self.indented_code.clear()
        self.indent_type(path)
        lines = code.splitlines()
        self.indent_size = 0
        for line in lines:
            newline = line.strip()

            if('~INDENT_RESET~' in newline):
                self.indent_size = 0
                continue
            elif('~INDENT_INCREASE~' in newline):
                self.indent_size +=1
                continue
            elif('~INDENT_DECREASE~' in newline):
                self.indent_size -=1
                continue
            # rm\*n refers to remove line, therefore return this to delete line
            elif('rm\*n' in newline):
                continue
            indented_line = self.indent * self.indent_size + newline
            self.indented_code.append(indented_line)
        return '\n'.join(self.indented_code)