import re

class FileUtils:
    @staticmethod
    def replaceKeywords(template, keywords):
        pattern = re.compile('|'.join(re.escape(k) for k in keywords))
        return pattern.sub(lambda m: keywords[m.group(0)], template)

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