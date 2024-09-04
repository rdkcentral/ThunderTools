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
        self.indent = "    "
        self.indented_code = []

    def process_indent(self, code):
        self.indented_code.clear()

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
            self.indented_code.append(self.indent * self.indent_size + newline)
        return '\n'.join(self.indented_code)