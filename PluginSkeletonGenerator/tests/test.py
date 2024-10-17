#!/usr/bin/env python3

import unittest
import sys
import os

sys.path.insert(1, os.path.join(sys.path[0], '..'))
from menu import generate_files

def test_plugin_name():
    return 'TestPluginName'

def test_comrpc_interfaces():
    return ['IHello', 'IWorld']

def test_no_comrpc_interfaces():
    return []

def test_jsonrpc_functionality():
    return True

def test_no_jsonrpc_functionality():
    return False

def test_jsonrpc_interfaces():
    return ['JHello', 'JWorld']

def test_no_jsonrpc_interfaces():
    return []

def test_out_of_process():
    return True

def test_no_out_of_process():
    return False

def test_subsystems():
    return True

def test_no_subsystems():
    return False

def test_preconditions():
    return ["PRE1", "PRE2"]

def test_no_preconditions():
    return []

def test_terminations():
    return ["PRE1", "PRE2"]

def test_no_terminations():
    return []

def test_controls():
    return ["PRE1", "PRE2"]

def test_no_controls():
    return []


test_cases = {
    'InProcessComrpcJsonrpc': {
        'test_plugin_name' : 'InProcessComrpcJsonrpc',
        'test_comrpc_interfaces' : test_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_jsonrpc_interfaces(),
        'test_out_of_process' : test_no_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
    'InProcessComrpc': {
        'test_plugin_name' : 'InProcessComrpc',
        'test_comrpc_interfaces' : test_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_no_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_no_jsonrpc_interfaces(),
        'test_out_of_process' : test_no_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
    'InProcessJsonrpc': {
        'test_plugin_name' : 'InProcessJsonrpc',
        'test_comrpc_interfaces' : test_no_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_jsonrpc_interfaces(),
        'test_out_of_process' : test_no_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
    'InProcess': {
        'test_plugin_name' : 'InProcess',
        'test_comrpc_interfaces' : test_no_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_no_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_no_jsonrpc_interfaces(),
        'test_out_of_process' : test_no_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
    'OutProcessComrpcJsonrpc': {
        'test_plugin_name' : 'OutProcessComrpcJsonrpc',
        'test_comrpc_interfaces' : test_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_jsonrpc_interfaces(),
        'test_out_of_process' : test_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
    'OutProcessComrpc': {
        'test_plugin_name' : 'OutProcessComrpc',
        'test_comrpc_interfaces' : test_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_no_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_no_jsonrpc_interfaces(),
        'test_out_of_process' : test_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
    'OutProcessJsonrpc': {
        'test_plugin_name' : 'OutProcessJsonrpc',
        'test_comrpc_interfaces' : test_no_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_jsonrpc_interfaces(),
        'test_out_of_process' : test_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
    'OutProcess': {
        'test_plugin_name' : 'OutProcess',
        'test_comrpc_interfaces' : test_no_comrpc_interfaces(),
        'test_jsonrpc_functionality' : test_no_jsonrpc_functionality(),
        'test_jsonrpc_interfaces' : test_no_jsonrpc_interfaces(),
        'test_out_of_process' : test_out_of_process(),
        'test_subsystems' : test_no_subsystems(),
        'test_preconditions' : test_no_preconditions(),
        'test_terminations' : test_no_terminations(),
        'test_controls' : test_no_controls()
    },
}
#generate_files(plugin_name, comrpc_interfaces, jsonrpc_interfaces, out_of_process, jsonrpc, plugin_config, notification_interfaces):
class TestSkeletonGenerator(unittest.TestCase):
    def test(self):
        for key,value in test_cases.items():
            result = generate_files(
                value['test_plugin_name'],
                value['test_comrpc_interfaces'],
                value['test_jsonrpc_interfaces'],
                value['test_out_of_process'],
                value['test_jsonrpc_functionality'],
                True,
                value['test_comrpc_interfaces']
            )
            self.assertEqual(result, True)
            print(f'Success for case: {value["test_plugin_name"]}')

if __name__ == "__main__":
    unittest.main()