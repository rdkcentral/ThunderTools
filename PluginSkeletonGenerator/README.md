# PluginSkeletonGenerator

## Overview

The `PluginSkeletonGenerator` is a Python script designed to assist in the creation of plugins for the Thunder framework by creating a skeletons for a new plugin. This tool simplifies the process of creating new plugins by generating the necessary boilerplate code and directory structure.

## Usage

To use the `PluginSkeletonGenerator`, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/your-repo/ThunderTools.git
    ```
2. Run the interactive script, in the location where you want to create a plugin:
    ```sh
    python PluginSkeletonGenerator/PluginSkeletonGenerator.py
    ```
    ```sh
    ./PluginSkeletonGenerator.py
    ```
    Alternatively, you may pass in a config file through the command line. See Guide for more.
    ```sh
    ./PluginSkeletonGenerator.py --config path/to/config.yaml
    ```
## Guide

There are two ways of inputting data to the generator:

### Interactive

You'll be asked to provide the following:
1. Plugin Name
2. If the plugin needs to be able to run OOP
3. Paths to your interface (an example is: /home/Thunder/ThunderInterfaces/interfaces/ITest.h)
4. Whether your plugin requires any Thunder subsystems (Preconditions, Terminations, Controls)
5. Which subfolder of the include path the interfaces your plugin will implement are located (default is interfaces)

### Config File

The command line option allows you to input a .yaml file.

See the example Config.yaml file [here](Config.yaml)

### Full manual
For more extensive documentation and manual see [here](https://rdkcentral.github.io/Thunder/plugin/devtools/pluginskeletongenerator/)

## Requirements

- Python 3.x