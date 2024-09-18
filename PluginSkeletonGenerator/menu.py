from file_data import FileData, HeaderData, SourceData, CMakeData, JSONData, ConfData
from PluginSkeletonGenerator import PluginGenerator

# Helpers for menu options

def generate_files(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                    subsystems, preconditions, terminations, controls):
    
    data = FileData(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc)
    plugin_generator = PluginGenerator(data)

    file_map = {
        HeaderData: plugin_generator.generate_headers,
        SourceData: plugin_generator.generate_source,
        CMakeData: plugin_generator.generate_cmake,
        ConfData: plugin_generator.generate_conf_in,
        JSONData: plugin_generator.generate_json
    }

    for file_data, generate in file_map.items():
        instance = file_data(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                              preconditions, terminations, controls)
        instance.populate_keywords()
        plugin_generator.blueprint_data = instance
        generate()
    return True
  
def display_settings(plugin_name, comrpc_interface, jsonrpc_interface, out_of_process, jsonrpc,
                    subsystems, preconditions, terminations, controls):
    print("=======================================")
    print("You have chosen the following settings:")
    print(f"Plugin Name: {plugin_name}")
    print(f"COMRPC Interfaces: {comrpc_interface if comrpc_interface else 'None'}")
    print(f"JSONRPC Functionality: {jsonrpc}")
    print(f"JSONRPC Interfaces: {jsonrpc_interface if jsonrpc else 'N/A'} ")
    print(f"Out Of Process: {out_of_process}")
    print(f"Subsystem Support: {subsystems}")
    print(f"Subsystem Preconditions: {preconditions if subsystems else 'N/A'} ")
    print(f"Subsystem Terminations: {terminations if subsystems else 'N/A'}")
    print(f"Subsystem Controls: {controls if subsystems else 'N/A'}")

# Menu options

def menu():
    comrpc_interfaces = []
    jsonrpc_interfaces = []
    preconditions = []
    terminations = []
    controls = []

    plugin_name = str(user_plugin_name())
    print(plugin_name)
    user_comrpc(comrpc_interfaces)
    jsonrpc = user_jsonrpc(jsonrpc_interfaces)
    out_of_process = user_out_of_process()
    subsystems = user_subsystems(preconditions, terminations, controls)

    display_settings(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                    subsystems, preconditions, terminations, controls)
    
    generate_files(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc,
                    subsystems, preconditions, terminations, controls)
    
def get_boolean_input(option):
    while True:
        user_input = input(f"{option}")
        if(user_input.lower() == 'y'):
            user_input = True
            break
        elif(user_input.lower() == 'n'):
            user_input = False
            break
        else:
            print("Unknown character, try again.")
    return user_input

def user_plugin_name():
    name = input("What will your plugin be called: ")
    return name

def user_comrpc(comrpc_interfaces):
    print(f"Enter any COM-RPC interfaces used: (Enter to quit) \nNote: IPlugin is already defined for you")
    while True:
        comrpc = input("Enter a COM-RPC interface: ")
        if not comrpc:
            break
        comrpc_interfaces.append(comrpc)

def user_jsonrpc(jsonrpc_interfaces):
    jsonrpc = get_boolean_input("Does your plugin require JSON-RPC functionality: (Enter Y or N)\n")
    if jsonrpc:
        print(f"Enter any JSON-RPC interfaces used: (Enter to quit)")
        while True:
            jsonrpc_class = input("Enter a JSON-RPC interface: ")
            if not jsonrpc_class:
                break
            jsonrpc_interfaces.append(jsonrpc_class)
    return jsonrpc

def user_out_of_process():
    out_of_process = get_boolean_input("Is your plugin expected to work out of process: (Enter Y or N)\n")
    return out_of_process

def user_subsystems(preconditions, terminations, controls):
    sub_systems = get_boolean_input("Does your plugin need subsystem support: (Enter Y or N)\n")
       
    if sub_systems:
        while True:
            precondition = input("Enter subsystem precondition: (Enter to quit) ")
            if not precondition:
                break
            preconditions.append(precondition)

        while True:
            termination = input("Enter subsystem termination: (Enter to quit) ")
            if not termination:
                break
            terminations.append(termination)

        while True:
            control = input("Enter subsystem control: (Enter to quit) ")
            if not control:
                break
            controls.append(control)
    return sub_systems