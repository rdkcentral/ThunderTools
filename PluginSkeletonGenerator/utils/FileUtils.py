import re

class FileUtils:
    @staticmethod
    def replaceKeywords(template, keywords):
        lines = template.split('\n')
        result_lines = []
        
        pattern = re.compile('|'.join(re.escape(k) for k in keywords))
        # {{}} pattern used in templates
        placeholder_only_pattern = re.compile(r'^\s*\{\{[^}]+\}\}\s*$')
        
        for line in lines:
            stripped_line = line.strip()
            
            if placeholder_only_pattern.match(stripped_line):
                replaced_line = pattern.sub(lambda m: keywords[m.group(0)], line)
                if replaced_line.strip():
                    result_lines.append(replaced_line)
            else:
                replaced_line = pattern.sub(lambda m: keywords[m.group(0)], line)
                result_lines.append(replaced_line)
        
        return '\n'.join(result_lines)

    @staticmethod
    def readFile(template_name):
        try:
            with open(template_name, 'r', encoding='utf-8') as f:
                return f.read()
        except FileNotFoundError as e:
            raise RuntimeError(f'Could not load template: {template_name}') from e
        except PermissionError as e:
            raise PermissionError(f'Permission denied: {template_name}') from e
        except OSError as e:
            raise OSError(f'OS error opening {template_name}: {e.strerror}')