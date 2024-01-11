# If not stated otherwise in this file or this component's license file the
# following copyright and licenses apply:
#
# Copyright 2020 Metrological
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import sys
import os
import json
import copy
import posixpath
from collections import OrderedDict

import config

sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir + os.sep + os.pardir))

import ProxyStubGenerator.CppParser as CppParser
import ProxyStubGenerator.Interface as CppInterface


class CppParseError(RuntimeError):
    def __init__(self, obj, msg):
        if obj:
            try:
                msg = "%s(%s): %s (see '%s')" % (obj.parser_file, obj.parser_line, msg, obj.Proto())
                super(CppParseError, self).__init__(msg)
            except:
                super(CppParseError, self).__init__("unknown parsing failure: %s(%i): %s" % (obj.parser_file, obj.parser_line, msg))
        else:
            super(CppParseError, self).__init__(msg)


def LoadInterfaceInternal(file, tree, ns, log, all = False, includePaths = []):

    def StripFrameworkNamespace(identifier):
        return str(identifier).replace("::" + config.FRAMEWORK_NAMESPACE + "::", "")

    def StripInterfaceNamespace(identifier):
        return str(identifier).replace(ns + "::", "")

    interfaces = [i for i in CppInterface.FindInterfaceClasses(tree, ns, file) if (i.obj.is_json or (all and not i.obj.is_event))]

    def Build(face):
        def _EvaluateRpcFormat(obj):
            rpc_format = config.RPC_FORMAT

            if not config.RPC_FORMAT_FORCED:
                if obj.is_collapsed:
                    rpc_format = config.RpcFormat.COLLAPSED
                elif obj.is_extended:
                    rpc_format = config.RpcFormat.EXTENDED
                elif obj.is_compliant:
                    rpc_format = config.RpcFormat.COMPLIANT

            return rpc_format

        schema = OrderedDict()
        methods = OrderedDict()
        properties = OrderedDict()
        events = OrderedDict()

        schema["$schema"] = "interface.json.schema"
        schema["jsonrpc"] = "2.0"
        schema["@generated"] = True
        schema["namespace"] = ns

        if face.obj.is_json:
            schema["mode"] = "auto"
            rpc_format = _EvaluateRpcFormat(face.obj)
        else:
            rpc_format = config.RpcFormat.COLLAPSED

        verify = face.obj.is_json or face.obj.is_event

        schema["@interfaceonly"] = True
        schema["configuration"] = { "nodefault" : True }

        info = dict()
        info["format"] = rpc_format.value

        if not face.obj.parent.full_name.endswith(ns):
            info["namespace"] = face.obj.parent.name[1:] if (face.obj.parent.name[0] == "I" and face.obj.parent.name[1].isupper()) else face.obj.parent.name

        info["class"] = face.obj.name[1:] if face.obj.name[0] == "I" else face.obj.name
        scoped_face = face.obj.full_name.split("::")[1:]

        info["interface"] = StripInterfaceNamespace("::" + "::".join(scoped_face))
        info["sourcefile"] = os.path.basename(file)

        if face.obj.sourcelocation:
            info["sourcelocation"] = face.obj.sourcelocation

        if face.obj.json_version:
            try:
                info["version"] = [int(x) for x in face.obj.json_version.split(".")]
            except:
                raise CppParseError(face.obj, "Interface version must be provided in major[.minor[.patch]] format")

        info["title"] = info["class"] + " API"
        info["description"] = info["class"] + " JSON-RPC interface"
        schema["info"] = info

        event_interfaces = set()

        for method in face.obj.methods:

            def ResolveTypedef(type):
                return type.Resolve()

            def ConvertType(var):
                if isinstance(var.type, str):
                    raise CppParseError(var, "%s: undefined type" % var.type)
                elif isinstance(var.type, list):
                    raise CppParseError(var, "%s: undefined type" % " ".join(var.type))

                var_type = ResolveTypedef(var.type)
                if isinstance(var_type, str):
                    raise CppParseError(var.type, "%s: undefined type" % var_type)
                elif isinstance(var_type, list):
                    raise CppParseError(var.type, "%s: undefined type" % " ".join(var_type))

                cppType = var_type.Type()
                is_iterator = (isinstance(cppType, CppParser.Class) and cppType.is_iterator)

                # Pointers
                if var_type.IsPointer() and (is_iterator or (var.meta.length and var.meta.length != ["void"])):
                    # Special case for serializing C-style buffers, that will be converted to base64 encoded strings
                    if isinstance(cppType, CppParser.Integer) and cppType.size == "char":
                        props = dict()

                        if var.meta.maxlength:
                            props["length"] = " ".join(var.meta.maxlength)
                        elif var.meta.length:
                            props["length"] = " ".join(var.meta.length)

                        if "length" in props:
                            props["original_type"] = cppType.type

                        props["encode"] = cppType.type != "char"

                        if var.meta.range:
                            props["range"] = var.meta.range

                        return "string", props if props else None

                    # Special case for iterators, that will be converted to JSON arrays
                    elif is_iterator and len(cppType.args) == 2:
                        # Take element type from return value of the Current() method
                        currentMethod = next((x for x in cppType.methods if x.name == "Current"), None)

                        if currentMethod == None:
                            raise CppParseError(var, "%s does not appear to a be an @iterator type" % cppType.type)

                        result = ["array", { "items": ConvertParameter(currentMethod.retval), "iterator": StripInterfaceNamespace(cppType.type) } ]

                        if "extract" in var.meta.decorators:
                            result[1]["extract"] = True

                        if var_type.IsPointerToPointer():
                            result[1]["ptr"] = True

                        if var_type.IsPointerToConst():
                            raise CppParseError(var, "passed iterators must not be constant")

                        return result
                    # All other pointer types are not supported
                    else:
                        raise CppParseError(var, "unable to convert C++ type to JSON type: %s - input pointer allowed only on interator or C-style buffer" % cppType.type)
                # Primitives
                else:
                    result = None

                    # String
                    if isinstance(cppType, CppParser.String):
                        if "opaque" in var.meta.decorators :
                            result = [ "string", { "opaque": True } ]
                        else:
                            result = [ "string", {} ]
                    # Boolean
                    elif isinstance(cppType, CppParser.Bool):
                        result = ["boolean", {} ]
                    # Integer
                    elif isinstance(cppType, CppParser.Integer):
                        size = 8 if cppType.size == "char" else 16 if cppType.size == "short" else \
                            32 if cppType.size == "int" or cppType.size == "long" else 64 if cppType.size == "long long" else 32
                        result = [ "integer", { "size": size, "signed": cppType.signed } ]
                    # Instance ID
                    elif isinstance(cppType, CppParser.InstanceId):
                        result = [ "instanceid", {} ]
                    # Float
                    elif isinstance(cppType, CppParser.Float):
                        result = [ "number", { "float": True, "size": 32 if cppType.type == "float" else 64 if cppType.type == "double" else 128 } ]
                    # Null
                    elif isinstance(cppType, CppParser.Void):
                        result = [ "null", {} ]
                    # Enums
                    elif isinstance(cppType, CppParser.Enum):

                        if len(cppType.items) > 1:
                            autos = [e.auto_value for e in cppType.items].count(True)
                            #if autos != 0 and (autos != len(cppType.items)):
                            #   raise CppParseError(var, "enumerator values in an enum must all be explicit or all be implied")

                        enum_spec = { "enum": [e.meta.text if e.meta.text else e.name.replace("_"," ").title().replace(" ","") for e in cppType.items], "scoped": var_type.Type().scoped  }
                        enum_spec["ids"] = [e.name for e in cppType.items]
                        enum_spec["hint"] = var.type.Type().name

                        for e in cppType.items:
                            if "endmarker" in e.meta.decorators:
                                enum_spec["endmarker"] = e.name
                                break;

                        if not cppType.items[0].auto_value:
                            enum_spec["values"] = [e.value for e in cppType.items]

                        if "bitmask" in var.meta.decorators or "bitmask" in var.type.Type().meta.decorators:
                            enum_spec["bitmask"] = True
                            enum_spec["type"] = "string"
                            enum_spec["original_type"] = StripFrameworkNamespace(var.type.Type().full_name)
                            result = ["array", { "items": enum_spec } ]
                        else:
                            result = ["string", enum_spec]

                        if isinstance(var.type.Type(), CppParser.Typedef):
                            result[1]["@register"] = False

                    # POD objects
                    elif isinstance(cppType, CppParser.Class):
                        def GenerateObject(ctype, was_typdef):
                            properties = dict()

                            kind = ctype.Merge()

                            required = []

                            for p in kind.vars:
                                name = p.name.lower()

                                if isinstance(p.type, list):
                                    raise CppParseError(p, "%s: undefined type" % " ".join(p.type))
                                if isinstance(p.type, str):
                                    raise CppParseError(p, "%s: undefined type" % p.type)
                                elif isinstance(ResolveTypedef(p.type).Type(), CppParser.Class):
                                    _, props = GenerateObject(ResolveTypedef(p.type).Type(), isinstance(p.type.Type(), CppParser.Typedef))
                                    properties[name] = props
                                    properties[name]["type"] = "object"
                                    properties[name]["original_type"] = StripFrameworkNamespace(p.type.Type().full_name)

                                    if p.meta.brief:
                                        properties[name]["description"] = p.meta.brief
                                else:
                                    properties[name] = ConvertParameter(p)

                                properties[name]["@originalname"] = p.name

                                if was_typdef:
                                    properties[name]["@register"] = False

                                if "optional" not in p.meta.decorators:
                                    required.append(name)

                            return "object", { "properties": properties, "required": required }

                        result = GenerateObject(cppType, isinstance(var.type.Type(), CppParser.Typedef))

                    # All other types are not supported
                    else:
                        raise CppParseError(var, "unable to convert C++ type to JSON type: %s" % cppType.type)

                    if var_type.IsPointer():
                        result[1]["ptr"] = True

                    if var_type.IsReference():
                        result[1]["ref"] = True

                    if var_type.IsPointerToConst():
                        result[1]["ptrtoconst"] = True

                    if var.meta.range:
                        result[1]["range"] = var.meta.range

                    return result

            def ExtractExample(var):
                egidx = var.meta.brief.index("(e.g.") if "(e.g." in var.meta.brief else None

                if egidx != None and ")" in var.meta.brief[egidx + 1:]:
                    example = var.meta.brief[egidx + 5:var.meta.brief.rfind(")")].strip()
                    description = var.meta.brief[0:egidx].strip()
                    return [example, description]
                else:
                    return None

            def ConvertParameter(var):
                jsonType, args = ConvertType(var)
                properties = {"type": jsonType}

                if args != None:
                    properties.update(args)
                    try:
                        properties["original_type"] = StripFrameworkNamespace(var.type.Type().full_name)
                    except:
                        pass

                if var.meta.brief:
                    # Also attempt to craft some description
                    pair = ExtractExample(var)
                    if pair:
                        properties["example"] = pair[0]
                        properties["description"] = pair[1]
                    else:
                        properties["description"] = var.meta.brief.strip()

                return properties

            def EventParameters(vars):
                events = []
                for var in vars:
                    def ResolveTypedef(resolved, events, type):
                        if not isinstance(type, list):
                            if isinstance(type.Type(), CppParser.Typedef):
                                if type.Type().is_event:
                                    events.append(type)
                                ResolveTypedef(resolved, events, type.Type())
                            else:
                                if isinstance(type.Type(), CppParser.Class) and type.Type().is_event:
                                    events.append(type)
                        else:
                            raise CppParseError(var, "undefined type: '%s'" % " ".join(type))

                        resolved.append(type)
                        return events

                    resolved = []
                    events = ResolveTypedef(resolved, events, var.type)
                return events

            def BuildParameters(vars, rpc_format, is_property=False, test=False):
                params = {"type": "object"}
                properties = OrderedDict()
                required = []

                for var in vars:
                    if var.meta.input or not var.meta.output:
                        if verify:
                            if not var.type.IsConst() and (var.type.IsPointer() and not var.type.IsPointerToConst()):
                                if not var.meta.input:
                                    if var.type.IsPointer():
                                        raise CppParseError(var, "ambiguous non-const pointer parameter without @in/@out tag (forgot 'const'?)")
                                    else:
                                        log.WarnLine(var, "'%s': non-const parameter assumed to be input (forgot 'const'?)" % var.name)
                                elif not var.meta.output:
                                    log.WarnLine(var, "'%s': non-const parameter marked with @in tag (forgot 'const'?)" % var.name)

                        var_name = "value" if is_property else (var.meta.text if var.meta.text else var.name.lower())

                        if var_name.startswith("__unnamed") and not test:
                            raise CppParseError(var, "unnamed parameter, can't deduce parameter name (*1)")

                        properties[var_name] = ConvertParameter(var)

                        if not is_property and not var.name.startswith("@_") and not var.name.startswith("__unnamed"):
                            properties[var_name]["@originalname"] = var.name

                        properties[var_name]["position"] = vars.index(var)

                        if "optional" not in var.meta.decorators:
                            required.append(var_name)
                        else:
                            properties[var_name]["optional"] = True

                        if properties[var_name]["type"] == "string" and not var.type.IsReference() and not var.type.IsPointer() and not "enum" in properties[var_name]:
                            log.WarnLine(var, "'%s': passing input string by value (forgot &?)" % var.name)

                params["properties"] = properties
                params["required"] = required

                if is_property and ((rpc_format == config.RpcFormat.EXTENDED) or (rpc_format == config.RpcFormat.COLLAPSED)):
                    if len(properties) == 1:
                        return list(properties.values())[0]
                    elif len(properties) > 1:
                        params["required"] = required
                        return params
                    else:
                        return None
                else:
                    if (len(properties) == 0):
                        return None
                    elif (len(properties) == 1) and (rpc_format == config.RpcFormat.COLLAPSED):
                        # collapsed format: if only one parameter present then omit the outer object
                        return list(properties.values())[0]
                    else:
                        return params

            def BuildIndex(var, test=False):
                return BuildParameters([var], rpc_format.COLLAPSED, True, test)

            def BuildResult(vars, is_property=False):
                params = {"type": "object"}
                properties = OrderedDict()
                required = []

                for var in vars:
                    var_type = ResolveTypedef(var.type)

                    if var.meta.output:
                        if var_type.IsValue():
                            raise CppParseError(var, "parameter marked with @out tag must be either a reference or a pointer")

                        if var_type.IsConst():
                            raise CppParseError(var, "parameter marked with @out tag must not be const")

                        var_name = "value" if is_property else (var.meta.text if var.meta.text else var.name.lower())

                        if var_name.startswith("__unnamed"):
                            raise CppParseError(var, "unnamed parameter, can't deduce parameter name (*2)")

                        properties[var_name] = ConvertParameter(var)

                        if not is_property and not var.name.startswith("@_") and not var.name.startswith("__unnamed"):
                           properties[var_name]["@originalname"] = var.name

                        properties[var_name]["position"] = vars.index(var)

                        if "optional" not in var.meta.decorators:
                            required.append(var_name)

                params["properties"] = properties

                if len(properties) == 1:
                    return list(properties.values())[0]
                elif len(properties) > 1:
                    params["required"] = required
                    return params
                else:
                    void = {"type": "null"}
                    void["description"] = "Always null"
                    return void

            event_params = EventParameters(method.vars)

            if method.is_excluded:
                if event_params:
                    log.WarnLine(method, "'%s': @json:omit is redundant for notification registration methods" % method.name)

                continue

            if face.obj.json_prefix:
                prefix = (face.obj.json_prefix + ("::" if not face.obj.json_prefix.endswith("_") else ""))
            elif config.AUTO_PREFIX and (face.obj.parent.full_name != ns):
                prefix = (face.obj.parent.name.lower() + "_")
            else:
                prefix = ""

            method_name = method.name
            method_name_lower = method_name.lower()

            if method.retval.meta.text == method_name_lower:
                log.WarnLine(method, "%s': changed function name is same as original name ('%s')" % (method.name, method.retval.meta.text))

            # Copy over @text tag to the other method of a property
            if method.retval.meta.text and method.retval.meta.is_property:
                for mm in face.obj.methods:
                    if mm != method and mm.name == method.name:
                        mm.retval.meta.text = method.retval.meta.text
                        break

            # Copy over @alt tag to the other method of a property
            if method.retval.meta.alt and method.retval.meta.is_property:
                for mm in face.obj.methods:
                    if mm != method and mm.name == method.name:
                        mm.retval.meta.alt = method.retval.meta.alt
                        break

            method_name = method.retval.meta.text if method.retval.meta.text else method.name
            method_name_lower = method_name.lower()

            if method.parent.is_json:
                if method.retval.meta.alt == method_name_lower:
                    log.WarnLine(method, "%s': alternative name is same as original name ('%s')" % (method.name, method.retval.meta.text))

                for mm in methods:
                    if mm == prefix + method_name_lower:
                        raise CppParseError(method, "JSON-RPC name clash detected ('%s')" % (prefix + method_name_lower))
                    if method.retval.meta.alt and (mm == prefix + method.retval.meta.alt):
                        raise CppParseError(method, "JSON-RPC name clash detected ('%s' alternative)" % (prefix + method_name_lower))

                for mm in properties:
                    if properties[mm]["@originalname"] != method.name:
                        if mm == prefix + method_name_lower:
                            raise CppParseError(method, "JSON-RPC name clash detected ('%s')x" % (prefix + method_name_lower))
                        if method.retval.meta.alt and (mm == prefix + method.retval.meta.alt):
                            raise CppParseError(method, "JSON-RPC name clash detected ('%s' alternative)" % (prefix + method_name_lower))

            for e in event_params:
                exists = any(x.obj.type == e.type.type for x in event_interfaces)

                if not exists:
                    event_interfaces.add(CppInterface.Interface(ResolveTypedef(e).type, 0, file))

            obj = None

            if method.retval.meta.is_property or (prefix + method_name_lower) in properties:
                try:
                    obj = properties[prefix + method_name_lower]
                    property_second_method = True
                except:
                    obj = OrderedDict()
                    properties[prefix + method_name_lower] = obj

                obj["@originalname"] = method.name
                method.retval.meta.is_property = True

                indexed_property = (len(method.vars) == 2 and method.vars[0].meta.is_index)

                if len(method.vars) == 1 or (len(method.vars) == 2 and indexed_property):
                    if indexed_property:
                        if method.vars[0].type.IsPointer():
                            raise CppParseError(method.vars[0], "index to a property must not be pointer")

                        if not method.vars[0].type.IsConst() and method.vars[0].type.IsReference():
                            raise CppParseError(method.vars[0], "index to a property must be an input parameter")

                        if "index" not in obj:
                            obj["index"] = BuildIndex(method.vars[0])

                            if obj["index"]:
                                obj["index"]["name"] = method.vars[0].name

                                if "enum" in obj["index"]:
                                    obj["index"]["example"] = obj["index"]["enum"][0]

                                if "example" not in obj["index"]:
                                    # example not specified, let's invent something...
                                    obj["index"]["example"] = ("0" if obj["index"]["type"] == "integer" else "xyz")

                                if obj["index"]["type"] not in ["integer", "string"]:
                                    raise CppParseError(method.vars[0], "index to a property must be integer, enum or string type")
                            else:
                                raise CppParseError(method.vars[0], "failed to determine type of index")
                        else:
                            test = BuildIndex(method.vars[0], True)

                            if not test:
                                raise CppParseError(method.vars[value], "property index must be an input parameter")

                            if obj["index"]["type"] != test["type"]:
                                raise CppParseError(method.vars[0], "setter and getter of the same property must have same index type")

                        if method.vars[1].meta.is_index:
                            raise CppParseError(method.vars[0], "index must be the first parameter to property method")

                        value = 1
                    else:
                        value = 0 # no index

                    if "const" in method.qualifiers:
                        # getter
                        if method.vars[value].type.IsConst():
                            raise CppParseError(method.vars[value], "property getter method must not use const parameter")
                        else:
                            if rpc_format == config.RpcFormat.COLLAPSED:
                                result_name = "params"
                            else:
                                result_name = "result"

                            if "writeonly" in obj:
                                del obj["writeonly"]
                            else:
                                obj["readonly"] = True

                            if result_name not in obj:
                                obj[result_name] = BuildResult([method.vars[value]], True)
                            else:
                                test = BuildResult([method.vars[value]], True)

                                if not test:
                                    raise CppParseError(method.vars[value], "property getter method must have one output parameter")

                                if obj[result_name]["type"] != test["type"]:
                                    raise CppParseError(method.vars[value], "setter and getter of the same property must have same type (*1)")

                                if "ptr" in test and test["ptr"]:
                                    obj[result_name]["ptr"] = True

                                if "ptrtoconst" in test and test["ptrtoconst"]:
                                    obj[result_name]["ptrtoconst"] = True

                            if obj[result_name] == None:
                                raise CppParseError(method.vars[value], "property getter method must have one output parameter")
                    else:
                        # setter
                        if not method.vars[value].type.IsConst():
                            raise CppParseError(method.vars[value], "property setter method must use a const parameter")
                        else:
                            if "readonly" in obj:
                                del obj["readonly"]
                            else:
                                obj["writeonly"] = True

                            if "params" not in obj:
                                obj["params"] = BuildParameters([method.vars[value]], rpc_format, True)
                            else:
                                test = BuildParameters([method.vars[value]], rpc_format, True, True)

                                if not test:
                                    raise CppParseError(method.vars[value], "property setter method must have one input parameter")

                                if obj["params"]["type"] != test["type"]:
                                    raise CppParseError(method.vars[value], "setter and getter of the same property must have same type (*2)")

                                if "ref" in test and test["ref"]:
                                    obj["params"]["ref"] = True

                            if obj["params"] == None or obj["params"]["type"] == "null":
                                raise CppParseError(method.vars[value], "property setter method must have one input parameter")
                else:
                    raise CppParseError(method, "property method must have one parameter")

            elif method.IsVirtual() and not method.IsDestructor() and not event_params:
                var_type = ResolveTypedef(method.retval.type)

                if var_type and ((isinstance(var_type.Type(), CppParser.Integer) and (var_type.Type().size == "long")) or not verify):
                    obj = OrderedDict()
                    obj["@originalname"] = method.name

                    params = BuildParameters(method.vars, rpc_format)

                    if params:
                        obj["params"] = params

                        if "properties" in params and params["properties"]:
                            if method.name.lower() in [x.lower() for x in params["required"]]:
                                raise CppParseError(method, "parameters must not use the same name as the method")

                    obj["result"] = BuildResult(method.vars)
                    methods[prefix + method_name_lower] = obj

                else:
                    raise CppParseError(method, "method return type must be uint32_t (error code), i.e. pass other return values by a reference")

            if obj:
                if method.retval.meta.is_deprecated:
                    obj["deprecated"] = True
                elif method.retval.meta.is_obsolete:
                    obj["obsolete"] = True

                if method.retval.meta.brief:
                    obj["summary"] = method.retval.meta.brief.strip()

                if method.retval.meta.details:
                    obj["description"] = method.retval.meta.details.strip()

                if method.retval.meta.retval:
                    errors = []

                    for err in method.retval.meta.retval:
                        errEntry = OrderedDict()
                        errEntry["description"] = method.retval.meta.retval[err]
                        errEntry["message"] = err
                        errors.append(errEntry)

                    if errors:
                        obj["errors"] = errors

                if config.LEGACY_ALT:
                    upd = properties if method.retval.meta.is_property else methods

                if method.retval.meta.alt:
                    idx = prefix + method.retval.meta.alt
                    obj["alt"] = idx

                    if method.retval.meta.alt_is_deprecated:
                        obj["altisdeprecated"] = method.retval.meta.alt_is_deprecated

                    if method.retval.meta.alt_is_obsolete:
                        obj["altisobsolete"] = method.retval.meta.alt_is_obsolete

                    if config.LEGACY_ALT:
                        idx = prefix + method.retval.meta.alt
                        upd[idx] = copy.deepcopy(obj)
                        upd[idx]["alt"] = prefix + method_name_lower
                        obj["alt"] = idx

                        if "deprecated" in upd[idx]:
                            del upd[idx]["deprecated"]
                        if "obsolete" in upd[idx]:
                            del upd[idx]["obsolete"]

                        if method.retval.meta.alt_is_deprecated:
                            upd[idx]["deprecated"] = True
                        elif method.retval.meta.alt_is_obsolete:
                            upd[idx]["obsolete"] = True

                elif "alt" in obj:
                    if config.LEGACY_ALT:
                        o = upd[obj["alt"]]
                        if "readonly" in o and "readonly" not in obj:
                            del o["readonly"]
                        if "writeonly" in o and "writeonly" not in obj:
                            del o["writeonly"]


        for f in event_interfaces:
            rpc_format = _EvaluateRpcFormat(f.obj)

            for method in f.obj.methods:
                EventParameters(method.vars) # just to check for undefined types...

                if method.IsVirtual() and not method.IsDestructor() and not method.is_excluded:
                    obj = OrderedDict()
                    obj["@originalname"] = method.name
                    varsidx = 0

                    if len(method.vars) > 0:
                        for v in method.vars[1:]:
                            if v.meta.is_index:
                                log.WarnLine(method,"@index ignored on non-first parameter of %s" % method.name)

                        if method.vars[0].meta.is_index:
                            if method.vars[0].type.IsPointer():
                                raise CppParseError(method.vars[0], "index to a notification must not be pointer")

                            if not method.vars[0].type.IsConst() and method.vars[0].type.IsReference():
                                raise CppParseError(method.vars[0], "index to a notification must be an input parameter")

                            obj["id"] = BuildParameters([method.vars[0]], config.RpcFormat.COLLAPSED, True, False)

                            if obj["id"]:
                                obj["id"]["name"] = method.vars[0].name

                                if "example" not in obj["id"]:
                                    obj["id"]["example"] = "0" if obj["id"]["type"] == "integer" else "abc"

                                if obj["id"]["type"] not in ["integer", "string"]:
                                    raise CppParseError(method.vars[0], "id of a notification must be integer, enum or string type")

                                varsidx = 1
                            else:
                                raise CppParseError(method.vars[0], "failed to determine type of notification id parameter")

                    if method.retval.meta.is_listener:
                        obj["statuslistener"] = True

                    params = BuildParameters(method.vars[varsidx:], rpc_format, False)
                    retvals = BuildResult(method.vars[varsidx:])
                    if retvals and retvals["type"] != "null":
                        raise CppParseError(method, "output parameters are invalid for JSON-RPC events")

                    if method.retval.meta.is_deprecated:
                        obj["deprecated"] = True
                    elif method.retval.meta.is_obsolete:
                        obj["obsolete"] = True

                    if method.retval.meta.brief:
                        obj["summary"] = method.retval.meta.brief.strip()

                    if method.retval.meta.details:
                        obj["description"] = method.retval.meta.details.strip()

                    if params:
                        obj["params"] = params

                    method_name = (method.retval.meta.text if method.retval.meta.text else method.name).lower()

                    for mm in events:
                        if mm == prefix + method_name:
                            raise CppParseError(method, "JSON-RPC name clash detected ('%s')" % (prefix + method_name))
                        if method.retval.meta.alt and (mm == prefix + method.retval.meta.alt):
                            raise CppParseError(method, "JSON-RPC name clash detected ('%s' alternative)" % (prefix + method_name))
                        if events[mm].get("alt") == method_name:
                            raise CppParseError(method, "JSON-RPC name clash detected ('%s' with '%s' alternative)" % ((prefix + method_name), mm))

                    if method.retval.meta.alt:
                        obj["alt"] = method.retval.meta.alt

                        if method.retval.meta.alt_is_deprecated:
                            obj["altisdeprecated"] = method.retval.meta.alt_is_deprecated

                        if method.retval.meta.alt_is_obsolete:
                            obj["altisobsolete"] = method.retval.meta.alt_is_obsolete

                    events[prefix + method_name] = obj

        if methods:
            schema["methods"] = methods

        if properties:
            schema["properties"] = properties

        if events:
            schema["events"] = events

        if config.DUMP_JSON:
            print("\n// JSON interface for {} -----------".format(face.obj.name))
            print(json.dumps(schema, indent=2))
            print("// ----------------\n")

        return schema

    schemas = []

    if interfaces:
        for face in interfaces:
            schema = Build(face)
            if schema:
                schemas.append(schema)

    return schemas, []

def LoadInterface(file, log, all = False, includePaths = []):
    try:
        schemas = []
        includes = []

        tree = CppParser.ParseFiles([os.path.join(os.path.dirname(os.path.realpath(__file__)),
                   posixpath.normpath(config.DEFAULT_DEFINITIONS_FILE)), file], includePaths, log)

        for ns in config.INTERFACE_NAMESPACES:
            s, i = LoadInterfaceInternal(file, tree, ns, log, all, includePaths)
            schemas.extend(s)
            includes.extend(i)

        if not schemas:
            log.Info("No interfaces found")

        return schemas, includes

    except CppParser.ParserError as ex:
        raise CppParseError(None, str(ex))
