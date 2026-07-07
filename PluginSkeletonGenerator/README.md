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
    Alternatively, you can skip the prompts and provide the same values directly as command line arguments:
    ```sh
    ./PluginSkeletonGenerator.py \
      --plugin-name ExamplePlugin \
      --out-of-process \
      --plugin-config \
      --path /home/Thunder/ThunderInterfaces/interfaces/ITest.h \
      --precondition PLATFORM \
      --termination TERMINATED \
      --control TESTING \
      --select-interface ITest.h:ITest \
      --location ITest.h:interfaces \
      --output-dir /tmp
    ```
## Guide

There are two ways of inputting data to the generator:

### Interactive

You'll be asked to provide the following:
1. Plugin Name
2. If the plugin needs to be able to run OOP
3. Paths to your interface (an example is: /home/Thunder/ThunderInterfaces/interfaces/ITest.h)
4. Whether your plugin requires any Thunder subsystems (Preconditions, Terminations, Controls)
5. If your header file contains more than one root level interface, you are able to choose which intefaces to use.
6. Which subfolder of the include path the interfaces your plugin will implement are located (default is interfaces)

### Direct Command Line

The direct command line mode accepts the same data as the interactive prompts:

- `--plugin-name` / `-n`: plugin name.
- `--output-dir` / `-o`: directory where the plugin folder should be created. Defaults to the current directory.
- `--out-of-process`: generate an out-of-process plugin.
- `--plugin-config`: generate custom plugin configuration support.
- `--path` / `-p`: full path to an interface header. Use once per header.
- `--precondition`, `--termination`, `--control`: Thunder subsystems. Use once per value.
- `--select-interface`: select interfaces from a header with `HEADER:INTERFACE[,INTERFACE]`.
- `--location`: set the include location for a header with `HEADER:LOCATION`.

`HEADER` can be either the full header path or the header filename.

### Full manual
For more extensive documentation and manual see [here](https://rdkcentral.github.io/Thunder/plugin/devtools/pluginskeletongenerator/)

## Requirements

- Python 3.x
