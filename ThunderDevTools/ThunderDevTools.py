#!/usr/bin/env python3

import os
import subprocess
import argparse

CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
THUNDER_TOOLS_DIR = os.path.dirname(CURRENT_DIR)

def python_distribution():
    if os.name == "posix":
        return "python3"
    else:
        return "python"

# add future scripts
scripts = {
"plugin_skeleton" : os.path.join("PluginSkeletonGenerator","PluginSkeletonGeneratror.py")
}

def script_menu():
    print("== Thunder Development Tools ==")
    print("Choose one of the following tools: (To quit, type q) ")
    print("1. Plugin Skeleton Generator")
    while True:
        option = input("You have picked: ")
    
        if option == '1':
            script = "plugin_skeleton"
            break
        elif option == "q":
            return
        else:
            print("Incorrect input, try again...")

    run_script(script)
            
def run_script(script):
    try:
        script_path = scripts[script]
        full_path = os.path.join(THUNDER_TOOLS_DIR, script_path)
        subprocess.run([python_distribution(), full_path], check=True, text=True, stderr=subprocess.PIPE)
        print("Success")
    except subprocess.CalledProcessError as e:
        print(f"Error running the script: {e.stderr}")

def main():
    parser = argparse.ArgumentParser(description="Run any ThunderDevTool script")
    parser.add_argument("--s", help="Choose a script to run: ", choices=scripts.keys())
    arg = parser.parse_args()

    if arg.s:
        run_script(arg.s)
    else:
        script_menu()

if __name__ == "__main__":
    main()