import os

def findRepoRoot(filename="PluginSkeletonGenerator.py"):
    curr = os.path.abspath(__file__)
    while True:
        parent = os.path.dirname(curr)
        if os.path.isfile(os.path.join(parent, filename)):
            return parent
        if parent == curr:
            raise RuntimeError(f"Repository root (containing {filename}) not found")
        curr = parent

REPO_ROOT = findRepoRoot()

# === Template directories ===
TEMPLATE_DIR = os.path.join(REPO_ROOT, 'templates')
IPLUGIN_DIR = os.path.join(TEMPLATE_DIR, 'iplugin_methods')
MODULE_DIR = os.path.join(TEMPLATE_DIR, 'module')
NESTED_CLASS_DIR = os.path.join(TEMPLATE_DIR, 'nested_class')
NESTED_METHOD_DIR = os.path.join(TEMPLATE_DIR, 'nested_methods')
JSON_DIR = os.path.join(TEMPLATE_DIR, 'json')

# === Template file paths ===
CMAKE_PATH = os.path.join(TEMPLATE_DIR, '.cmake.txt')
PLUGIN_CONF_PATH = os.path.join(TEMPLATE_DIR, '.plugin_conf_in.txt')
PLUGIN_HEADER_PATH = os.path.join(TEMPLATE_DIR, '.plugin_header.txt')
PLUGIN_IMPLEMENTATION_PATH = os.path.join(TEMPLATE_DIR, '.plugin_implementation.txt')
PLUGIN_SOURCE_PATH = os.path.join(TEMPLATE_DIR, '.plugin_source.txt')

# /templates/iplugin_methods
DENINITIALIZE_OOP_PATH = os.path.join(IPLUGIN_DIR, '.deinitialize_oop.txt')
DENINITIALIZE_IP_PATH = os.path.join(IPLUGIN_DIR, '.deinitialize_ip.txt')
INITIALIZE_OOP_PATH = os.path.join(IPLUGIN_DIR, '.initialize_oop.txt')
INITIALIZE_IP_PATH = os.path.join(IPLUGIN_DIR, '.initialize_ip.txt')
NESTED_OOP_PATH = os.path.join(IPLUGIN_DIR, '.nested_initialize_oop.txt')

# /templates/module
MODULE_HEADER_PATH = os.path.join(MODULE_DIR, '.module_header.txt')
MODULE_SOURCE_PATH = os.path.join(MODULE_DIR, '.module_source.txt')

# /templates/nested_class
CONFIG_CLASS_PATH = os.path.join(NESTED_CLASS_DIR, '.config_class.txt')
RPC_NOTIFICATION_CLASS_PATH = os.path.join(NESTED_CLASS_DIR, '.rpc_inotification.txt')

# /templates/nested_methods
CONFIGURE_METHOD = os.path.join(NESTED_METHOD_DIR, '.configure.txt')

# /templates/json
PLUGIN_JSON = os.path.join(JSON_DIR, '.plugin_json.txt')
JSON_INFO = os.path.join(JSON_DIR, '.json_info.txt')
JSON_CONFIGURATION = os.path.join(JSON_DIR, '.json_configuration.txt')
JSON_INTERFACE = os.path.join(JSON_DIR, '.json_interface.txt')