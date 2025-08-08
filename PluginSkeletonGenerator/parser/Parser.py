import re
from enum import Enum
import os
from typing import Dict


class ScopeType(Enum):
    CLASS = 1
    NAMESPACE = 2
    OTHER = 3

class MethodData:
    def __init__(self, name, return_type, params):
        self.m_name = name
        self.m_return_type = return_type
        self.m_params = params
        self.m_tags = []


class ClassData:
    def __init__(self, name, namespace=""):
        self.m_name = name
        self.m_namespace = namespace
        self.m_tags = []
        self.m_methods = []
        self.m_children = {}

    def addMethod(self, method):
        self.m_methods.append(method)

    def addChild(self, child):
        self.m_children[child.m_name] = child


class InterfaceTree:
    '''
    Each parsed file is represented as a tree of ClassData objects.
    Root interfaces are stored in m_root_classes, keyed by their fully qualified name.
    Each ClassData may have:
    - m_name: class name
    - m_namespace: namespace(s) it belongs to
    - m_methods: list of MethodData
    - m_children: nested interfaces, as (name: ClassData)
    - m_tags: parsed tags ('json', 'event')

    Example...
        namespace Exchange {
            struct EXTERNAL IWifiControl {
                struct INotification {
                    virtual void NetworkChange();
                };
            };
        }
    Will produce:
        m_root_classes = {
            "Exchange::IWifiControl": ClassData(
                m_name="IWifiControl",
                m_namespace="Exchange",
                m_children={
                    "INotification": ClassData(
                        m_name="INotification",
                        m_namespace="Exchange",
                        ...
                    )
                }
            )
        }
    '''

    def __init__(self):
        self.m_root_classes = {}
        self.m_class_stack = []
        self.m_namespace_stack = []
        self.m_scope_stack = []
        self.m_tags = []

    def pushNamespace(self, namespace):
        self.m_namespace_stack.append(namespace)
        self.m_scope_stack.append(ScopeType.NAMESPACE)

    def popNamespace(self):
        if self.m_namespace_stack:
            self.m_namespace_stack.pop()

    def combineNameSpace(self):
        return "::".join(self.m_namespace_stack)

    def addClass(self, interface_name):
        full_class_name = f"{self.combineNameSpace()}::{interface_name}" if self.m_namespace_stack else interface_name
        new_class = ClassData(interface_name, self.combineNameSpace())
        new_class.m_tags.extend(self.m_tags)
        self.m_tags.clear()

        if self.m_class_stack:
            self.m_class_stack[-1].addChild(new_class)
        else:
            self.m_root_classes[full_class_name] = new_class

        self.m_class_stack.append(new_class)
        self.m_scope_stack.append(ScopeType.CLASS)

    def addMethod(self, method):
        if not self.m_class_stack:
            return

        return_type, method_name, params = Parser.extractMethodData(method)
        if method_name:
            method = MethodData(method_name, return_type, params)
            self.m_class_stack[-1].addMethod(method)

    def closeClassStack(self):
        if self.m_class_stack:
            self.m_class_stack.pop()

    def parsedClasses(self) -> Dict[str, ClassData]:
        return self.m_root_classes


class Parser:
    def __init__(self, path):
        self.m_path = path
        self.m_interface_tree = InterfaceTree()
        self.m_pending_class = False

    def parseFile(self) -> Dict[str, ClassData]:
        with open(self.m_path, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()
                self.processTag(line)
                self.processNamespace(line)
                self.processClass(line)
                self.processMethod(line)
                self.processScope(line)
        return self.m_interface_tree.parsedClasses()

    def processTag(self, line):
        tags = re.findall(r'@(\w+)', line)
        for tag in tags:
            if tag in {'json', 'event'}:
                self.m_interface_tree.m_tags.append(tag)

    def processNamespace(self, line):
        match = re.match(r'namespace\s+(\w+)', line)
        if match:
            namespace = match.group(1)
            self.m_interface_tree.pushNamespace(namespace)

    def processClass(self, line):
        match = re.match(r'struct\s+EXTERNAL\s+(\w+)\s*:\s*virtual\s+public\s+Core::IUnknown', line)
        if match:
            interface = match.group(1)
            self.m_pending_class = interface

    def processMethod(self, line):
        if "virtual" in line and ";" in line:
            self.m_interface_tree.addMethod(line)

    def processScope(self, line):
        open_scope = line.count('{')
        close_scope = line.count('}')

        for _ in range(open_scope):
            if self.m_pending_class:
                self.m_interface_tree.addClass(self.m_pending_class)
                self.m_pending_class = None
            else:
                self.m_interface_tree.m_scope_stack.append(ScopeType.OTHER)

        for _ in range(close_scope):
            if not self.m_interface_tree.m_scope_stack:
                continue
            closing_scope = self.m_interface_tree.m_scope_stack.pop()
            if closing_scope == ScopeType.CLASS:
                self.m_interface_tree.closeClassStack()
            elif closing_scope == ScopeType.NAMESPACE:
                self.m_interface_tree.popNamespace()

    @staticmethod
    def extractMethodData(method):
        match = re.search(r'virtual\s+(?P<return>[\w:<>&*\s]+?)\s+(?P<name>\w+)\s*\((?P<params>[^)]*)\)\s*.*;', method)
        if match:
            return_type = match.group("return").strip()
            method_name = match.group("name")
            params = match.group("params").strip()
            return return_type, method_name, params
        return None, None, None
    

class Printer:
    @staticmethod
    def printTree(class_data: ClassData, indent_level=0):
        indent = "  " * indent_level
        namespace = f"{class_data.m_namespace}::" if class_data.m_namespace else ""
        print(f"{indent}Interface: {namespace}{class_data.m_name}")

        if class_data.m_tags:
            print(f"{indent}  Tags: {', '.join(class_data.m_tags)}")

        for method in class_data.m_methods:
            print(f"{indent}  Method: {method.m_return_type} {method.m_name}({method.m_params})")

        for child in class_data.m_children.values():
            Printer.printTree(child, indent_level + 1)