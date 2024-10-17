import json
from os import wait
from file_data import FileData, HeaderData, SourceData, CMakeData, JSONData, ConfData
from PluginSkeletonGenerator import PluginGenerator
from utils import Utils
import time

# Helpers for menu options


def generate_files(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc, plugin_config, notification_interfaces):

    data = FileData(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc, plugin_config, notification_interfaces)
    plugin_generator = PluginGenerator(data)

    file_map = {
        HeaderData: plugin_generator.generate_headers,
        SourceData: plugin_generator.generate_source,
        CMakeData: plugin_generator.generate_cmake,
        ConfData: plugin_generator.generate_conf_in,
        JSONData: plugin_generator.generate_json,
    }

    for file_data, generate in file_map.items():
        instance = file_data(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc, plugin_config, notification_interfaces)
        instance.populate_keywords()
        plugin_generator.blueprint_data = instance
        generate()
    return True


def display_settings(
    plugin_name,
    comrpc_interface,
    jsonrpc_interface,
    out_of_process,
    jsonrpc,
    plugin_config,
    notification_interfaces
):
    print("=======================================")
    print("You have chosen the following settings:")
    print(f"Plugin Name: {plugin_name}")
    print(f"COMRPC Interfaces: {comrpc_interface if comrpc_interface else 'None'}")
    print(f"COMRPC Interfaces with events: {notification_interfaces if notification_interfaces else 'None'}")
    print(f"JSONRPC Functionality: {jsonrpc}")
    print(f"JSONRPC Interfaces: {jsonrpc_interface if jsonrpc else 'N/A'} ")
    print(f"Out Of Process: {out_of_process}")
    """
    print(f"Subsystem Support: {subsystems}")
    print(f"Subsystem Preconditions: {preconditions if subsystems else 'N/A'} ")
    print(f"Subsystem Terminations: {terminations if subsystems else 'N/A'}")
    print(f"Subsystem Controls: {controls if subsystems else 'N/A'}")
    """

# Menu options

def menu():
    print("=======================================")
    comrpc_interfaces = []
    jsonrpc_interfaces = []
    notification_interfaces = []

    plugin_name = str(user_plugin_name())
    out_of_process = user_out_of_process()
    jsonrpc = user_comrpc(out_of_process, comrpc_interfaces, jsonrpc_interfaces, notification_interfaces)
    plugin_config = user_plugin_configuration(comrpc_interfaces, out_of_process)

    display_settings(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc, plugin_config, notification_interfaces)

    generate_files(
        plugin_name,
        comrpc_interfaces,
        jsonrpc_interfaces,
        out_of_process,
        jsonrpc,
        plugin_config,
        notification_interfaces
    )


def get_boolean_input(option):
    while True:
        user_input = input(f"{option}")
        if user_input.lower() == "y":
            user_input = True
            break
        elif user_input.lower() == "n":
            user_input = False
            break
        else:
            print("Unknown character, try again.")
    return user_input


def user_plugin_name():
    name = input("What will your plugin be called: ")
    return name


def user_comrpc(out_of_process, comrpc_interfaces, jsonrpc_interfaces, notification_interfaces):

    myBool = True
    iteration = 0
    jsonrpc = False

    print("\n=======================================")
    print("[INFO]: The following section tracks the number of sucessfully defined interfaces!")
    print("=======================================")
    while myBool:

        print(f"\nNumber of succesfully defined interfaces: {iteration}")
        tempName = input(
            "What C++ IDL interface header file (COMRPC Interface) is your interface in?"
            "\nExample: IHello.h"
            "\n[Note]: Do not define: IPlugin, IConfiguration, JSONRPC. They are automatically configured accordingly!"
            "\nTo quit defining interfaces, press ENTER \n"
            )
        
        if tempName:
            correctInitial = Utils.check_correct_comrpc(tempName)
            correctExtension = Utils.extract_interface(tempName)
            if not correctInitial:
                print("\n=======================================")
                print("[Error]: Interface header file does not begin with 'I'")
                print("=======================================")
            if not correctExtension:
                print("\n=======================================")
                print("[Error]: Interface header file does not have the extension '.h'")
                print("=======================================\n")

            if not correctInitial or not correctExtension:
                time.sleep(2)
                continue
            correctName = correctExtension            
            # CorrectName at this point will always return the correct interface name without the '.h'
            while True:
                comrpc_confirm = input(f"The name of the interface in {tempName} is (enter to confirm or type the correct interface name) {correctName}: ")
                if comrpc_confirm:
                    correctInitial = Utils.check_correct_comrpc(comrpc_confirm)
                    if not correctInitial:
                        print("\n=======================================")
                        print("[Error]: Interface header file does not begin with 'I'")
                        print("=======================================")
                    else:
                        correctName = comrpc_confirm
                        break
                else:
                    break

            comrpc_interfaces.append(correctName)
            notification = get_boolean_input("\nDoes your interface contain a notification: (Enter Y or N)\n")
            if notification:
                    notification_interfaces.append(correctName)

            json_tag = user_jsonrpc(correctName, jsonrpc_interfaces)
            if json_tag:
                jsonrpc = True
            iteration += 1
        else:
            if out_of_process and not comrpc_interfaces:
                print("An out of process plugin requires a COMRPC interface.")
            else:
                myBool = False
    return jsonrpc 


def user_jsonrpc(comrpc_interface, jsonrpc_interfaces):

    json_tag = get_boolean_input("Does your plugin require JSON-RPC functionality (@JSON tag): (Enter Y or N)\n")
    if json_tag:
        jsonrpc_interface = Utils.replace_comrpc_to_jsonrpc(comrpc_interface)
        jsonrpc_interfaces.append(jsonrpc_interface)
        return True
    return False


def user_out_of_process():
    out_of_process = get_boolean_input("\nIs your plugin expected to work out of process: (Enter Y or N)\n")
    return out_of_process

def user_plugin_configuration(comrpc_interfaces, out_of_process):
    plugin_config = get_boolean_input("\nDoes the plugin require plugin specific configuration: (Enter Y or N) \n")
    if plugin_config and out_of_process:
        comrpc_interfaces.append("IConfiguration")
    return plugin_config


# Future Thunder Versions..
"""
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

def user_smart_interface():
    
    smart_interface = get_boolean_input("Does your plugin require smart interface")
    return smart_interface
"""
