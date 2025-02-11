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
from pprint import pprint

import copy
from collections import OrderedDict

import config
import emitter
import rpc_version
from json_loader import *
from class_emitter import Restrictions
from class_emitter import IsObjectOptional
from class_emitter import IsObjectOptionalOrOpaque

class RPCEmitterError(RuntimeError):
    pass

class DottedDict(dict):
    def __getattr__(self, item):
        try:
            return self[item]
        except KeyError as e:
            return None
    __setattr__ = dict.__setitem__
    __delattr__ = dict.__delitem__

def EmitEvent(emit, root, event, params_type, legacy = False):
    names = DottedDict()
    names['module'] = "_module"
    names['filter'] = "_id"
    names['params'] = "_params"
    names['designator'] = "_designator"
    names['sendif'] = "_sendIfMethod"
    names['index'] = "_designatorId"
    names['jsonrpc_alias'] = "PluginHost::JSONRPC"

    prefix = ("%s." % names.module) if not legacy else ""

    params = event.params

    # Build parameter list for the prototype
    parameters = [ ]

    if "@lookup" in event.schema:
        parameters.append("const %s* const %s" % ("LookupStorage", "_storage"))
        parameters.append("const %s* const %s" % (event.schema["@lookup"]["name"], "_obj"))

    if event.sendif_type:
        parameters.append("const %s& %s" % (event.sendif_type.cpp_native_type, names.filter))

    if not params.is_void:
        if params_type == "native":
            if params.properties and params.do_create:
                for p in params.properties:
                    parameters.append("const %s& %s" % (p.cpp_native_type_opt, p.local_name))
            else:
                parameters.append("const %s& %s" % (params.cpp_native_type_opt, params.local_name))

        elif params_type == "json":
            if params.properties and params.do_create:
                for p in params.properties:
                    parameters.append("const %s& %s" % (p.cpp_type, p.local_name))
            else:
                parameters.append("const %s& %s" % (params.cpp_type, params.local_name))

        elif params_type == "object":
           parameters.append("const %s& %s" % (params.cpp_type, params.local_name))

    if not legacy:
        parameters.insert(0, "const %s& %s" % (names.jsonrpc_alias, names.module))

        if event.sendif_type or event.is_status_listener:
            parameters.append("const std::function<bool(const string&)>& %s = nullptr" % names.sendif)

    # Emit the prototype
    if legacy:
        line = "void %s::%s(%s)" % (root.cpp_name, event.endpoint_name, ", ".join(parameters))
    else:
        line = "static void %s(%s)" % (event.cpp_name, ", ".join(parameters))

    if event.included_from:
        line += " /* %s */" % event.included_from

    emit.Line("// Event: %s" % (event.Headline()))
    emit.Line(line)
    emit.Line("{")
    emit.Indent()

    # Convert the parameters to JSON types
    if params_type != "object" or legacy:
        if not params.is_void:
            emit.Line("%s %s;" % (params.cpp_type, names.params))

            if params.properties and params.do_create:
                for p in params.properties:
                    if p.optional and (params_type == "native") and not p.default_value:
                        emit.Line("if (%s.IsSet() == true) {" % (p.local_name))
                        emit.Indent()

                    emit.Line("%s.%s = %s;" % (names.params, p.cpp_name, p.local_name))
                    if p.schema.get("opaque"):
                        emit.Line("%s.%s.SetQuoted(false);" % (names.params, p.cpp_name))

                    if p.optional and (params_type == "native") and not p.default_value:
                        emit.Unindent()
                        emit.Line("}")
            else:
                if params.optional and (params_type == "native") and not params.default_value:
                    emit.Line("if (%s.IsSet() == true) {" % (params.local_name))
                    emit.Indent()

                emit.Line("%s = %s;" % (names.params, params.local_name))
                if params.schema.get("opaque"):
                    emit.Line("%s.SetQuoted(false);" % names.params)

                if params.optional and (params_type == "native") and not params.default_value:
                    emit.Unindent()
                    emit.Line("}")

            emit.Line()

        parameters = [ ]

        if not legacy:
            parameters.append(names.module)

        if "@lookup" in event.schema:
            parameters.append("_storage")
            parameters.append("_obj")

        if not params.is_void:
            parameters.append(names.params)

        if event.sendif_type:
            parameters.insert(0 if legacy else 1, names.filter)

        # Emit the local call
        if not legacy:
            emit.Line("%s(%s);" % (event.cpp_name, ", ".join(parameters + ([names.sendif] if (event.sendif_type or event.is_status_listener) else []))))

    if params_type == "object" or legacy:
        # Build parameters for the notification call
        parameters = [ ]

        if "@lookup" in event.schema:
            parameters.append("Core::Format(%s, _instanceId)" % (Tstring(event.json_name.replace("#ID", "#%u"))))
        else:
            parameters.append(Tstring(event.json_name))

        if not params.is_void:
            parameters.append(names.params if legacy else params.local_name)

        if "@lookup" in event.schema:
            emit.Line("ASSERT(_storage != nullptr);")
            emit.Line("ASSERT(_obj != nullptr);")
            emit.Line()
            emit.Line("const uint32_t _instanceId = _storage->%s.InstanceId(_obj);" % (event.schema["@lookup"]["prefix"]))
            emit.Line("if (_instanceId != 0) {")
            emit.Indent()

        if event.sendif_type:
            if not legacy:
                # If the event has an id specified (i.e. uses "send-if"), generate code for this too:
                # only call if extracted  designator id matches the index.
                emit.Line("if (%s == nullptr) {" % names.sendif)
                emit.Indent()

            def Emit(parameters):
                # Use stock send-if function
                emit.Line('%sNotify(%s, [%s](const string& %s) -> bool {' % (prefix, ", ".join(parameters), names.filter, names.designator))
                emit.Indent()
                emit.Line("const string %s = %s.substr(0, %s.find('.'));" % (names.index, names.designator, names.designator))

                if isinstance(event.sendif_type, JsonInteger):
                    conv_index_name = (names.index + "Converted_")
                    emit.Line("%s %s{};" % (event.sendif_type.cpp_native_type, conv_index_name))
                    emit.Line("return ((Core::FromString(%s, %s) == true) && (%s == %s));" % (names.designator, names.index, names.filter, conv_index_name))

                elif isinstance(event.sendif_type, JsonEnum):
                    conv_index_name = (names.index + "Converted_")
                    emit.Line("Core::EnumerateType<%s> %s(%s.c_str());" % (event.sendif_type.cpp_native_type, conv_index_name, names.index))
                    emit.Line("return (%s == %s);" % (names.filter, conv_index_name))

                else:
                    emit.Line("return (%s == %s);" % (names.filter, names.index))

                emit.Unindent()
                emit.Line("});")

            Emit(parameters)

            if event.alternative and config.LEGACY_ALT:
                Emit([Tstring(event.alternative)] + parameters[1:])

            if not legacy:
                emit.Unindent()
                emit.Line("} else {")

                def Emit(parameters):
                    emit.Line('%sNotify(%s);' % (prefix, ", ".join(parameters + [names.sendif])))

                # Use supplied custom send-if function
                emit.Indent()
                Emit(parameters)

                if event.alternative and config.LEGACY_ALT:
                    Emit([Tstring(event.alternative)] + parameters[1:])

                emit.Unindent()
                emit.Line("}")
        else:
            # No send-if
            def Emit(parameters):
                emit.Line('%sNotify(%s);' % (prefix, ", ".join(parameters + ([names.sendif] if event.is_status_listener else []))))

            Emit(parameters)

            if config.LEGACY_ALT and event.alternative:
                Emit([Tstring(event.alternative)] + parameters[1:])

        if "@lookup" in event.schema:
            emit.Unindent()
            emit.Line("}")

    emit.Unindent()
    emit.Line("}")
    emit.Line()

def _EmitRpcPrologue(root, emit, header_file, source_file, ns, data_emitted, prototypes = []):
    is_json_source = source_file.endswith(".json")

    emit.Line()
    emit.Line("// Generated automatically from '%s'. DO NOT EDIT." % os.path.basename(source_file))
    emit.Line()
    emit.Line("#pragma once")

    if is_json_source and prototypes:
        emit.Line()
        emit.Line("#if _IMPLEMENTATION_STUB")
        emit.Line("// sample implementation class")
        emit.Line("class JSONRPCImplementation {")
        emit.Line("public:")
        emit.Indent()

        for p in prototypes:
            emit.Line("%s { %s}" % (p[0], "return (%s); " % p[1] if p[1] else ""))

        emit.Unindent()
        emit.Line("}; // class JSONRPCImplementation")
        emit.Line("#endif // _IMPLEMENTATION_STUB")
        emit.Line()

    if not config.NO_INCLUDES:
        emit.Line("#include \"Module.h\"")

        if data_emitted:
            emit.Line("#include \"%s_%s.h\"" % (config.DATA_NAMESPACE, header_file))

        if not is_json_source:
            emit.Line("#include <%s%s>" % (config.CPP_INTERFACE_PATH, source_file))

    emit.Line()

    for i, ns_ in enumerate(ns.split("::")):
        if ns_:
            emit.Line("namespace %s {" % ns_)
            if i >= 2:
                emit.Indent()
            emit.Line()

    namespace = root.json_name

    if "info" in root.schema and "namespace" in root.schema["info"]:
        namespace = root.schema["info"]["namespace"] + "::" + namespace
        emit.Line("namespace %s {" % root.schema["info"]["namespace"])
        emit.Indent()
        emit.Line()

    namespace = config.DATA_NAMESPACE + "::" + namespace
    emit.Line("namespace %s {" % ("J" + root.json_name))
    emit.Indent()
    emit.Line()

def _EmitRpcEpilogue(root, emit, ns):
    emit.Unindent()
    emit.Line("} // namespace %s" % ("J" + root.json_name))
    emit.Line()

    if "info" in root.schema and "namespace" in root.schema["info"]:
        emit.Unindent()
        emit.Line("} // namespace %s" % root.schema["info"]["namespace"])
        emit.Line()

    for i, ns_ in reversed(list(enumerate(ns.split("::")))):
        if ns_:
            if i >= 2:
                emit.Unindent()
            emit.Line("} // namespace %s" % ns_)
            emit.Line()

    emit.Line()

def _EmitVersionCode(emit, version):
    emit.Line("namespace Version {")
    emit.Indent()
    emit.Line()
    emit.Line("constexpr uint8_t Major = %u;" % version[0])
    emit.Line("constexpr uint8_t Minor = %u;" % version[1])
    emit.Line("constexpr uint8_t Patch = %u;" % version[2])
    emit.Line()
    emit.Unindent()
    emit.Line("} // namespace Version")
    emit.Line()

def _EmitRpcCode(root, emit, ns, header_file, source_file, data_emitted):

    def trim(identifier):
        return str(identifier).replace(ns + "::", "").replace("::" + config.FRAMEWORK_NAMESPACE + "::", "")

    def _EmitHandlerInterface(listener_events):
        assert listener_events

        emit.Line("struct IHandler {")
        emit.Indent()
        emit.Line("virtual ~IHandler() = default;")

        for m in listener_events:
            emit.Line("virtual void On%sEventRegistration(const string& client, const %s::Status status) = 0;" % (m.cpp_name, names.jsonrpc_alias))

        emit.Unindent()
        emit.Line("};")
        emit.Line()

    def _EmitStorageClass(interfaces):
        assert interfaces

        emit.Line("class LookupStorage {")
        emit.Line("friend Register();")
        emit.Line()
        emit.Line("public:")
        emit.Indent()
        emit.Line("LookupStorage() = default;")
        emit.Line("~LookupStorage() = default;")
        emit.Line("LookupStorage(const LookupStorage&) = delete;")
        emit.Line("LookupStorage(LookupStorage&&) = delete;")
        emit.Line("LookupStorage& operator=(const LookupStorage&) = delete;")
        emit.Line("LookupStorage& operator=(LookupStorage&&) = delete;")
        emit.Line()
        emit.Unindent()

        emit.Line("public:")
        emit.Indent()

        for face in interfaces:
            emit.Line("void Callback(%s*, const std::function<void(const bool, %s*)>& callback = nullptr) { %s.Callback(callback); }" % (trim(face["name"]), trim(face["name"]), face["prefix"]))
            emit.Line("void Closed(%s*, const uint32_t channelId) { %s.Closed(channelId); }" % (trim(face["name"]), face["prefix"]))
            emit.Line()

        emit.Unindent()
        emit.Line("public:")
        emit.Indent()

        for face in interfaces:
            emit.Line("PluginHost::LookupStorageType<%s, uint32_t> %s;" % (trim(face["name"]), face["prefix"]))

        emit.Unindent()
        emit.Line("};")
        emit.Line()


    def _EmitLinkEvents(interfaces):
        assert interfaces

        emit.Line("namespace Link {")
        emit.Indent()
        emit.Line()

        emit.Line("// Call this when the websocket channel is disconnected. Resources which are tied to that channel will be released.")
        emit.Line("void Closed(LookupStorage* _storage, const uint32& _channelId)")
        emit.Line("{")
        emit.Indent()
        emit.Line("ASSERT(_storage != nullptr);")
        emit.Line("ASSERT(_channelId != 0);")

        for face in interfaces:
            emit.Line()
            emit.Line("_storage->Closed((%s*){}, _channelId);" % trim(face["name"]))

        emit.Unindent()
        emit.Line("}")

        emit.Unindent()
        emit.Line()
        emit.Line("} // namespace Link")
        emit.Line()

    def _EmitLiftimeCallbacks(interfaces):
        assert interfaces

        emit.Line("namespace Lifetime {")
        emit.Indent()
        emit.Line()

        for face in interfaces:
            emit.Line("// This allows to set up a callback signalling that an object has been acquired or released.")
            emit.Line("template<typename T>")
            emit.Line("void Callback(LookupStorage* _storage, const std::function<void(const bool acquired, T* object)>& _callback)")
            emit.Line("{")
            emit.Indent()
            emit.Line("ASSERT(_storage != nullptr);")

            emit.Line()
            emit.Line("_storage->Callback((T*){}, _callback);")

            emit.Unindent()
            emit.Line("}")

        emit.Unindent()
        emit.Line()
        emit.Line("} // namespace Link")
        emit.Line()

    def _GenerateImplName(id):
        stripped = "::" + "::".join(id.split("::")[2:])
        return (stripped.replace("::I","").replace("::","") + "Implementation")

    def _EmitAsyncCallbackImpl(method):
        impl_name = _GenerateImplName(method.original_type)
        face_name = trim(method.original_type)
        emit.Line("class %s : public %s {" % (impl_name, face_name))
        emit.Indent()
        emit.Unindent()
        emit.Line("public:")
        emit.Indent()
        emit.Line("%s() = delete;" % (impl_name))
        emit.Line("%s(const %s&) = delete;" % (impl_name, impl_name))
        emit.Line("%s(%s&&) = delete;" % (impl_name, impl_name))
        emit.Line("%s& operator=(%s&&) = delete;" % (impl_name, impl_name))
        emit.Line("%s& operator=(const %s&) = delete;" % (impl_name, impl_name))
        emit.Line()
        emit.Line("%s(%s& module, const string& id)" % (impl_name, names.jsonrpc_alias))
        emit.Indent()
        emit.Line(": _module(module)")
        emit.Line(", _id(id)")
        emit.Unindent()
        emit.Line("{")
        emit.Line("}")
        emit.Line("~%s() override" % (impl_name))
        emit.Line("{")
        emit.Line("}")
        emit.Line()

        initializer = []
        sorted_vars = _BuildVars(method.params if (method.params and not method.params.is_void) else None, None)

        for vname, [vtype, _, _] in sorted_vars:
            initializer.append(trim(vtype.cpp_native_type_proto.replace('@', vname)))

        emit.Line("void %s(%s) override" % (method.original_name, ", ".join(initializer)))
        emit.Line("{")
        emit.Indent()

        params = [ "_module", "_id" ]
        for vname, _  in sorted_vars:
            params.append(vname)

        emit.Line("Async::%s::%s(%s);" % (method.json_name.capitalize(), method.original_name, ", ".join(params)))
        emit.Unindent()
        emit.Line("}")
        emit.Line()

        emit.Line("BEGIN_INTERFACE_MAP(%s)" % (impl_name))
        emit.Indent()
        emit.Line("INTERFACE_ENTRY(%s)" % (face_name))
        emit.Unindent()
        emit.Line("END_INTERFACE_MAP")
        emit.Line()
        emit.Unindent()
        emit.Line("private:")
        emit.Indent()
        emit.Line("%s& _module;" % names.jsonrpc_alias)
        emit.Line("string _id;")
        emit.Unindent()
        emit.Line("};")
        emit.Line()

    def _EmitNoPushWarnings(prologue = True):
        if prologue:
            if not config.NO_PUSH_WARNING:
                emit.Line("PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)")
                emit.Line("PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)")
                emit.Line("PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)")
                emit.Line()
            else:
                emit.Line("#if defined(__GNUC__) || defined(__clang__)")
                emit.Line('#pragma GCC diagnostic ignored "-Wunused-function"')
                emit.Line('#pragma GCC diagnostic ignored "-Wdeprecated-declarations"')
                emit.Line('#pragma GCC diagnostic ignored "-Wtype-limits"')
                emit.Line("#endif")
                emit.Line()
        else:
            if not config.NO_PUSH_WARNING:
                emit.Line("POP_WARNING()")
                emit.Line("POP_WARNING()")
                emit.Line("POP_WARNING()")
                emit.Line()

    def _EmitEvents(events, namespace = None):
        assert events

        if not namespace:
            namespace = "Event"

        emit.Line("namespace %s {" % namespace)
        emit.Indent()
        emit.Line()

        for event in events:
            EmitEvent(emit, root, event, "object")

            if not event.params.is_void:
                if isinstance(event.params, JsonObject):
                    EmitEvent(emit, root, event, "json")

                if not isinstance(event.params, JsonArray):
                    EmitEvent(emit, root, event, "native")

        emit.Unindent()
        emit.Line("} // namespace %s" % namespace)
        emit.Line()

    def _EmitAlternativeEventsRegistration(alt_events, prologue=True):
        assert alt_events

        if prologue:
            emit.Line("// Register alternative notification names...")

            for event in alt_events:
                emit.Line("%s.RegisterEventAlias(%s, %s);" % (names.module, Tstring(event.alternative), Tstring(event.name)))

            emit.Line()
        else:
            emit.Line()
            emit.Line("// Unegister alternative notification names...")

            for event in alt_events:
                emit.Line("%s.UnregisterEventAlias(%s, %s);" % (names.module, Tstring(event.alternative), Tstring(event.name)))

    def _EmitEventStatusListenerRegistration(listener_events, legacy, prologue=True):
        if prologue:
            emit.Line("// Register event status listeners...")
            emit.Line()

            for event in listener_events:
                emit.Line("%s.RegisterEventStatusListener(_T(\"%s\")," % (names.module, event.json_name))
                emit.Indent()
                emit.Line("[%s%s](const string& client, const %s::Status status) {" % ("&" if legacy else "", names.handler, names.jsonrpc_alias))
                emit.Indent()
                emit.Line("%s%sOn%sEventRegistration(client, status);" % (names.handler, '.' if legacy else '->', event.cpp_name))
                emit.Unindent()
                emit.Line("});")
                emit.Unindent()
                emit.Line()

                prototypes.append(["void On%sEventRegistration(const string& client, const %s::Status status)" % (event.cpp_name, names.jsonrpc_alias), None])
        else:
            emit.Line()
            emit.Line("// Unregister event status listeners...")

            for event in listener_events:
                emit.Line("%s.UnregisterEventStatusListener(%s);" % (names.module, Tstring(event.json_name)))

    def _EmitIndexing(index, index_name):
        index_checked = False
        index_name_converted = None
        index_name_optional = None

        def _IsOptional(v):
            return ((IsObjectOptional(v) and not IsObjectOptionalOrOpaque(v)))

        def _IsLegacyOptional(v):
            return (IsObjectOptionalOrOpaque(v))

        def _EmitRestrictions(index_name, extra=None):
            index_restrictions = Restrictions(json=False)

            if extra:
                index_restrictions.extend(extra)

            index_restrictions.append(index, override=index_name)

            if index_restrictions.count():
                emit.Line("if (%s) {" % ( index_restrictions.join()))
                emit.Indent()
                emit.Line("%s = %s;" % (error_code.temp_name, CoreError("bad_request")))
                emit.Unindent()
                emit.Line("}")

            return index_restrictions.count()

        if _IsOptional(index) or _IsLegacyOptional(index):

            if isinstance(index, JsonString):
                if not _IsLegacyOptional(index) or index.default_value:
                    index_name_optional = index.TempName("opt_")
                    emit.Line("%s %s{};" %(index.cpp_native_type_opt, index_name_optional))
            else:
                index_name_optional = index.TempName("opt_")
                emit.Line("%s %s{%s};" %(index.cpp_native_type_opt, index_name_optional, index.default_value if index.default_value else ""))

        if isinstance(index, JsonString):
            if _IsOptional(index) or _IsLegacyOptional(index):
                if _IsOptional(index) or index.default_value:
                    emit.Line("if (%s.empty() == false) {" % index_name)
                    emit.Indent()

                cnt = _EmitRestrictions(index_name)
                if cnt:
                    emit.Line("else {")
                    emit.Indent()

                if _IsOptional(index) or index.default_value:
                    emit.Line("%s = %s;" % (index_name_optional, index_name))

                if cnt:
                    emit.Unindent()
                    emit.Line("}")

                if index.default_value:
                    emit.Unindent()
                    emit.Line("}")
                    emit.Line("else {")
                    emit.Indent()
                    emit.Line("%s = %s;" %(index_name_optional, index.default_value))

                if _IsOptional(index) or index.default_value:
                    emit.Unindent()
                    emit.Line("}")
            else:
                _EmitRestrictions(index_name, extra=("%s.empty() == true" % index_name))
                index_checked = True # still have to close the bracket...

        elif isinstance(index, (JsonInteger, JsonBoolean, JsonEnum)):
            if _IsOptional(index) or _IsLegacyOptional(index):
                emit.Line("if (%s.empty() == false) {" % index_name)
                emit.Indent()

            index_name_converted = index.TempName("conv_")

            if isinstance(index, JsonEnum):
                emit.Line("Core::EnumerateType<%s> %s(%s.c_str());" % (index.cpp_native_type, index_name_converted, index_name))
                _EmitRestrictions(index_name_converted, extra="%s.IsSet() == false" % (index_name_converted))
                index_name_converted += ".Value()"
            else:
                emit.Line("%s %s{};" % (index.cpp_native_type, index_name_converted))
                _EmitRestrictions(index_name_converted, extra="Core::FromString(%s, %s) == false" % (index_name, index_name_converted))

            if _IsOptional(index) or _IsLegacyOptional(index):
                emit.Line("else {")
                emit.Indent()
                emit.Line("%s = %s;" % (index_name_optional, index_name_converted))
                emit.Unindent()
                emit.Line("}")
                emit.Unindent()
                emit.Line("}")

        emit.Line()

        if index_name_optional:
            index_name = index_name_optional
        elif index_name_converted:
            index_name = index_name_converted

        index_checked = ((index_name_converted != None) or index_checked)

        if index_checked:
            emit.Line("if (%s == %s) {" % (error_code.temp_name, CoreError("none")))
            emit.Indent()

        return index_checked, index_name

    def _BuildVars(params, response):
        # Build param/response dictionaries (dictionaries will ensure they do not repeat)
        vars = OrderedDict()

        if params:
            if isinstance(params, JsonObject) and params.do_create:
                for param in params.properties:
                    vars[param.local_name] = [param, "r", DottedDict()]
                    vars[param.local_name][2].var = vars[param.local_name]
            else:
                vars[params.local_name] = [params, "r", DottedDict()]
                vars[params.local_name][2].var = vars[params.local_name]

        if response:
            if isinstance(response, JsonObject) and response.do_create:
                for resp in response.properties:
                    if resp.local_name not in vars:
                        vars[resp.local_name] = [resp, "w", DottedDict()]
                        vars[resp.local_name][2].var = vars[resp.local_name]
                    else:
                        vars[resp.local_name][1] += "w"
                        vars[resp.local_name][2].var = vars[resp.local_name]
            else:
                if response.local_name not in vars:
                    vars[response.local_name] = [response, "w", DottedDict()]
                    vars[response.local_name][2].var = vars[response.local_name]
                else:
                    vars[response.local_name][1] += "w"
                    vars[response.local_name][2].var = vars[response.local_name]

        sorted_vars = sorted(vars.items(), key=lambda x: x[1][0].schema["@position"])

        for _, [param, param_type, param_meta] in sorted_vars:
            param_meta.access = param_type
            param_meta.flags = DottedDict()
            param_meta.flags.parent = param
            param_meta.flags.prefix = ""

            if "encode" in param.schema:
                param_meta.flags.encode = param.schema["encode"]

            if "@async" in param.schema:
                param_meta.flags.asynchronous = True

            elif "@lookupid" in param.schema:
                if param_type == "w":
                    param_meta.flags.store_lookup = param.schema["@lookupid"]
                elif param_type == "r":
                    param_meta.flags.dispose_lookup = param.schema["@lookupid"]

            elif param.schema.get("@bypointer"):
                param_meta.flags.prefix = "&"

        # Tie buffer with length variables
        for _, [param, _, param_meta] in sorted_vars:
            if isinstance(param, (JsonString, JsonArray)):
                length_value = param.schema.get("@length")
                array_size_value = param.schema.get("@arraysize")

                if length_value:
                    for name, [var, var_type, var_meta] in sorted_vars:
                        if name == length_value:
                            if var_type == "w":
                                raise RPCEmitterError("'%s': parameter pointed to by @length is output only" % param.name)
                            else:
                                var_meta.flags.is_buffer_length = True
                                param_meta.flags.length = [var, var_meta]
                                break

                    if not param_meta.flags.length:
                        param_meta.flags.size = length_value

                elif array_size_value:
                    param_meta.flags.size = array_size_value

        return sorted_vars

    def _Invoke(method, sorted_vars, params, response, parent="", repsonse_parent="", const_cast=False, param_const_cast=False, test_param=True, index=None, context=False):

        index_name = index

        restrictions = Restrictions(test_set=True)
        call_conditions = Restrictions(test_set=False)
        async_event = None

        if params:
            restrictions.append(params, override=params.local_name, test_set=test_param)

            if restrictions.present():
                emit.Line()
                emit.Line("if (%s) {" % restrictions.join())
                emit.Indent()
                emit.Line("%s = %s;" % (error_code.temp_name, CoreError("bad_request")))
                emit.Unindent()
                emit.Line("}")
                emit.Line("else {")
                emit.Indent()

        # Emit temporary variables and deserializing of JSON data

        async_param = None

        for _, [param, param_type, param_meta] in sorted_vars:
            if param_meta.flags.is_buffer_length:
                continue

            is_readable = ("r" in param_type)
            is_writeable = ("w" in param_type)
            cv_qualifier = ("const " if not is_writeable else "") # don't consider volatile

            # Take care of POD aggregation
            cpp_name = ((parent + param.cpp_name) if parent else param.local_name)

            # Encoded JSON strings to C-style buffer
            if isinstance(param, JsonString) and param_meta.flags.asynchronous:
                asyncid_param = param.TempName("_asyncId")
                async_event = method.callback.notification.json_name
                async_param = param.temp_name
                initializer = (("(%s)" if isinstance(param, JsonObject) else "{%s}") % cpp_name) if is_readable and not param.convert else "{}"
                emit.Line("%s%s %s%s;" % (cv_qualifier, param.cpp_native_type, asyncid_param, initializer))
                emit.Line("%s* %s = Core::ServiceType<%s>::Create<%s>(%s, %s);" % (param.original_type, param.temp_name, _GenerateImplName(param.original_type), param.original_type, names.module, asyncid_param))
                emit.Line("const uint32_t _subscribe_result__ = %s.Subscribe(%s.ChannelId(), %s, %s, true /* one-off */);" % (names.module,  names.context, Tstring(async_event), asyncid_param))
                emit.Line("ASSERT(%s != nullptr);" % param.temp_name)
                call_conditions.extend("_subscribe_result__ == Core::ERROR_NONE")

            elif isinstance(param, JsonString) and (param_meta.flags.length or param_meta.flags.size) and param_meta.flags.encode:
                conditions = Restrictions(reverse=True)
                length_param = param_meta.flags.length

                assert not param.optional

                if param_meta.flags.length:
                    size = length_param[0].temp_name
                    length_cpp_name = parent + length_param[0].cpp_name

                    if length_param[0].optional and "r" in length_param[1].access:
                        emit.Line("%s %s{};" % (length_param[0].cpp_native_type_opt, size))
                        emit.Line("if (%s.IsSet() == true) { %s = %s.Value(); }" % (length_cpp_name, size, length_cpp_name))
                    else:
                        initializer = (length_cpp_name + ".Value()") if "r" in length_param[1].access else ""
                        emit.Line("%s %s{%s};" % (length_param[0].cpp_native_type_opt, size, initializer))

                    emit.Line("%s* %s{nullptr};" % (param.original_type, param.temp_name))

                    if length_param[0].optional:
                        size += ".Value()"

                    conditions.check_set(length_param[0])
                    conditions.check_not_null(length_param[0])

                    if length_param[0].size > 16:
                        conditions.extend("(%s <= 0x400000) /* sanity! */" % size)
                else:
                    size = param_meta.flags.size
                    emit.Line("%s %s[%s]{};" % (param.original_type, param.temp_name, size))

                emit.EnterBlock(conditions)

                if length_param:
                    emit.Line("%s = reinterpret_cast<%s*>(ALLOCA(%s));" % (param.temp_name, param.original_type, size))
                    emit.Line("ASSERT(%s != nullptr);" % param.temp_name)

                if is_readable:
                    if param_meta.flags.encode == "base64":
                        if param_meta.flags.size:
                            size_var = param.TempName("Size_")
                            emit.Line("uint16_t %s{%s};" % (size_var, size))
                        else:
                            size_var = size

                        emit.Line("Core::FromString(%s, %s, %s, nullptr);" % (cpp_name, param.temp_name, size_var))
                    else:
                        assert False, "unimplemented encoding: " + param_meta.flags.encode

                emit.ExitBlock(conditions)

            elif isinstance(param, JsonArray):
                # Array to iterator
                if param.iterator:
                    emit.Line("%s %s{};" % (param.cpp_native_type_opt, param.temp_name))

                    if is_readable:
                        elements_name = param.items.TempName("elements")
                        iterator_name = param.items.TempName("iterator")
                        impl_name = param.items.TempName("iteratorImplType")

                        if param.optional:
                            emit.Line("if (%s.IsSet() == true) {" % (cpp_name))
                            emit.Indent()

                        emit.Line("std::list<%s> %s{};" % (param.items.cpp_native_type, elements_name))
                        emit.Line("auto %s = %s.Elements();" % (iterator_name, cpp_name))
                        emit.Line("while (%s.Next() == true) { %s.push_back(%s.Current()); }" % (iterator_name, elements_name, iterator_name))
                        impl = (param.iterator[:param.iterator.index('<')].replace("IIterator", "Iterator") + ("<%s>" % param.iterator))
                        emit.Line("using %s = %s;" % (impl_name, impl))
                        initializer = "Core::ServiceType<%s>::Create<%s>(std::move(%s))" % (impl_name, param.iterator, elements_name)

                        iterator = param.temp_name
                        if param.optional:
                            iterator += ".Value()"

                        emit.Line("%s = %s;" % (param.temp_name, initializer))
                        emit.Line("ASSERT(%s != nullptr); " % iterator)

                        if param_const_cast:
                            param_meta.flags.cast = "static_cast<%s const&>(%s)" % (param.cpp_native_type_opt, param.temp_name)

                        if param.optional:
                            emit.Unindent()
                            emit.Line("}")

                        emit.Line()

                # array to bitmask
                elif param.items.schema.get("@bitmask"):
                    if param.optional and is_readable:
                        emit.Line("%s %s{};" % (param.items.cpp_native_type_opt, param.temp_name))
                        emit.Line("if (%s.IsSet() == true) { %s = %s.Value(); }" % ( param.temp_name, cpp_name))
                    else:
                        initializer = cpp_name if is_readable else ""
                        emit.Line("%s%s %s{%s};" % (cv_qualifier, param.items.cpp_native_type, param.temp_name, initializer))

                # array to fixed array
                elif (param_meta.flags.size or param_meta.flags.length):
                    items = param.items
                    length_param = param_meta.flags.length
                    conditions = Restrictions(reverse=True)

                    assert not param.optional

                    if length_param:
                        size = length_param[0].temp_name

                        if length_param[0].optional and "r" in length_param[1].access:
                            length_cpp_name = parent + length_param[0].cpp_name
                            emit.Line("%s %s{};" % (length_param[0].cpp_native_type_opt, size))
                            emit.Line("if (%s.IsSet() == true) { %s = %s.Value(); }" % (length_cpp_name, size, length_cpp_name))
                        else:
                            initializer = (parent + length_param[0].cpp_name + ".Value()") if "r" in length_param[1].access else ""
                            emit.Line("%s %s{%s};" % (length_param[0].cpp_native_type_opt, size, initializer))

                        emit.Line("%s* %s{};" % (items.cpp_native_type, param.temp_name))

                        conditions.check_set(length_param[0])
                        conditions.check_not_null(length_param[1])

                        if length_param[0].optional:
                            size += ".Value()"
                    else:
                        size = param_meta.flags.size
                        emit.Line("%s %s[%s]{};" % (param.items.cpp_native_type, param.temp_name, size))

                    emit.EnterBlock(conditions)

                    if length_param:
                        emit.Line("%s = static_cast<%s*>(ALLOCA(%s));" % (param.temp_name, items.cpp_native_type, size))
                        emit.Line("ASSERT(%s != nullptr);" % param.temp_name)

                    if is_readable:
                        emit.EnterBlock()
                        emit.Line("uint16_t i = 0;")
                        emit.Line("auto it = %s.Elements();" % (parent + param.cpp_name))
                        emit.Line("while ((it.Next() == true) && (i < %s)) { %s[i++] = it.Current(); }" % (size, param.items.temp_name))
                        emit.ExitBlock()

                    emit.ExitBlock(conditions)

                elif is_json_source:
                    response_cpp_name = (response_parent + param.cpp_name) if response_parent else param.local_name
                    initializer = ("(%s)" if isinstance(param, JsonObject) else "{%s}") % (response_cpp_name if is_writeable else cpp_name)

                    if is_readable and is_writeable:
                        emit.Line("%s = %s;" % (response_cpp_name, cpp_name))

                    emit.Line("%s%s %s%s;" % (cv_qualifier, (param.cpp_type + "&") if is_json_source else param.cpp_native_type, param.temp_name, initializer))
                else:
                    raise RPCEmitterError("arrays must be iterators: %s" % param.json_name)

            # All Other
            else:
                if is_json_source:
                    response_cpp_name = (response_parent + param.cpp_name) if response_parent else param.local_name
                    initializer = ("(%s)" if isinstance(param, JsonObject) else "{%s}") % (response_cpp_name if is_writeable else cpp_name)

                    if is_readable and is_writeable:
                        emit.Line("%s = %s;" % (response_cpp_name, cpp_name))
                else:
                    initializer = (("(%s)" if isinstance(param, JsonObject) else "{%s}") % cpp_name) if is_readable and not param.convert else "{}"

                if param.optional and is_readable and (param.default_value == None or not parent):
                    emit.Line("%s %s{};" % (param.cpp_native_type_opt, param.temp_name))
                    emit.Line("if (%s.IsSet() == true) {" % (cpp_name))
                    emit.Indent()
                    emit.Line("%s = %s;" % (param.temp_name, cpp_name))
                    emit.Unindent()

                    if param.default_value:
                        emit.Line("}")
                        emit.Line("else {")
                        emit.Indent()
                        emit.Line("%s = %s;" % (param.temp_name, param.default_value))
                        emit.Unindent()

                    emit.Line("}")
                    emit.Line()
                else:
                    emit.Line("%s%s %s%s;" % (cv_qualifier, (param.cpp_type + "&") if is_json_source else param.cpp_native_type_opt, param.temp_name, initializer))

                if param.convert and is_readable:
                    emit.Line((param.convert + ";") % (param.temp_name, cpp_name))

                if param_meta.flags.store_lookup or param_meta.flags.dispose_lookup:
                    emit.Line("%s* _real%s{};" % (param.original_type, param.temp_name))
                    param_meta.flags.prefix += "_real"

                if param_meta.flags.dispose_lookup:
                    emit.Line("_real%s = %s->%s.Dispose(%s, %s);" % (param.temp_name, names.storage, param_meta.flags.dispose_lookup, names.context, param.temp_name))
                    call_conditions.extend("_real%s != nullptr" % param.temp_name)


        # Emit call to the implementation
        if not is_json_source: # Full automatic mode

            impl = names.impl
            interface = names.interface

            if lookup:
                impl = ("_%s%s" % (lookup["prefix"], impl)).lower()
                interface = trim(lookup["name"])
                emit.Line("%s%s* const %s = %s->%s.Lookup(%s, %s);" % ("const " if const_cast else "", interface, impl, names.storage, lookup["prefix"], names.context, names.id))
                call_conditions.extend("%s != nullptr" % impl)

            implementation_object = "(static_cast<const %s*>(%s))" % (interface, impl) if const_cast and not lookup else impl
            function_params = []

            if context:
                function_params.append(names.context)

            if index_name:
                function_params.append(index_name)

            for _, [param, _, param_meta] in sorted_vars:
                function_params.append("%s%s" % (param_meta.flags.prefix, (param_meta.flags.cast if param_meta.flags.cast else param.temp_name)))

            emit.Line()

            if call_conditions.count():
                emit.Line("if (%s) {" % call_conditions.join())
                emit.Indent()

            assert error_code.temp_name
            assert method.function_name
            emit.Line("%s = %s->%s(%s);" % (error_code.temp_name, implementation_object, method.function_name, ", ".join(function_params)))

            if lookup:
                emit.Line("%s->Release();" % impl)

            if method.callback:
                emit.Line()
                emit.Line("if (%s != Core::ERROR_NONE) {" % (error_code.temp_name))
                emit.Indent()
                emit.Line("%s.Unsubscribe(%s.ChannelId(), %s, %s);" % (names.module, names.context, Tstring(method.callback.notification.json_name), param.TempName("_asyncId")))
                emit.Unindent()
                emit.Line("}")

            if call_conditions.count():
                emit.Unindent()
                emit.Line("}")
                emit.Line("else {")
                emit.Indent()
                emit.Line("%s = %s;" % (error_code.temp_name, CoreError("unknown_key")))
                emit.Unindent()
                emit.Line("}")

            if async_param:
                emit.Line()
                emit.Line("if (%s != nullptr) {" % async_param)
                emit.Indent()
                emit.Line("%s->Release();" % async_param)
                emit.Unindent()
                emit.Line("}")

        # Semi-automatic mode
        else:
            parameters = []

            if index_name:
                parameters.append(index_name)

            for _, [ param, _, _ ] in sorted_vars:
                parameters.append("%s" % (param.temp_name))

            if const_cast:
                emit.Line("%s = (static_cast<const IMPLEMENTATION&>(%s)).%s(%s);" % (error_code.temp_name, names.impl, m.function_name, ", ".join(parameters)))
            else:
                emit.Line("%s = %s.%s(%s);" % (error_code.temp_name, names.impl, method.function_name, ", ".join(parameters)))

            parameters = []

            if index_name:
                parameters.append("const %s& %s" % (any_index.cpp_native_type, index_name))

            for _, [ param, type, _ ] in sorted_vars:
                parameters.append("%s%s& %s" % ("const " if type == "r" else "", param.cpp_type, param.local_name))

            prototypes.append(["uint32_t %s(%s)%s" % (method.function_name, ", ".join(parameters), (" const" if (const_cast or (isinstance(method, JsonProperty) and method.readonly)) else "")), CoreError("none")])

        emit.Line()

        # Emit result handling and serialization to JSON data

        if response and not is_json_source:
            emit.Line("if (%s == %s) {" % (error_code.temp_name, CoreError("none")))
            emit.Indent()

            for _, [param, param_type, param_meta] in sorted_vars:
                if "w" not in param_type:
                    continue

                rhs = param.temp_name
                cpp_name = (repsonse_parent + param.cpp_name) if repsonse_parent else param.local_name

                # Special case for C-style buffers disguised as base64-encoded strings
                if isinstance(param, JsonString) and (param_meta.flags.length or param_meta.flags.size) and param_meta.flags.encode:
                    length_param = param_meta.flags.length

                    conditions = Restrictions(reverse=True)

                    if length_param:
                        conditions.check_set(length_param[0])
                        conditions.check_not_null(length_param[0])

                        size = length_param[0].temp_name

                        if length_param[0].optional:
                            # the length variable determines optionality of the buffer
                            size += ".Value()"
                    else:
                        size = param_meta.flags.size

                    emit.EnterBlock(conditions)

                    if param_meta.flags.encode == "base64":
                        encoded_name = param.TempName("encoded_")
                        emit.Line("%s %s;" % (param.cpp_native_type, encoded_name))
                        emit.Line("Core::ToString(%s, %s, true, %s);" % (param.temp_name, size, encoded_name))
                        emit.Line("%s = %s;" % (cpp_name, encoded_name))
                    else:
                        assert False, "unimplemented encoding: " + param_meta.flags.encode

                    emit.ExitBlock(conditions)

                elif isinstance(param, JsonArray):
                    if param.iterator:
                        conditions = Restrictions(reverse=True)
                        conditions.check_set(param)
                        conditions.check_not_null(param)

                        if param.optional:
                            rhs += ".Value()"

                        emit.EnterBlock(conditions)

                        item_name = param.items.TempName("item_")
                        emit.Line("%s %s{};" % (param.items.cpp_native_type, item_name))
                        emit.Line("while (%s->Next(%s) == true) { %s.Add() = %s; }" % (rhs, item_name, cpp_name, item_name))

                        if param.schema.get("@extract"):
                            emit.Line("%s.SetExtractOnSingle(true);" % (cpp_name))

                        emit.Line("%s->Release();" % rhs)

                        emit.ExitBlock(conditions)

                    elif param.items.schema.get("@bitmask"):
                        emit.Line("%s = %s;" % (cpp_name, rhs))

                    elif (param_meta.flags.length or param_meta.flags.size):
                        length_param = param_meta.flags.length
                        conditions = Restrictions(reverse=True)

                        if length_param:
                            conditions.check_set(length_param[0])
                            conditions.check_not_null(length_param[0])
                            size = length_param[0].temp_name

                            if length_param[0].optional:
                                size += ".Value()"
                        else:
                            size = param_meta.flags.size

                        if conditions.count():
                            emit.Line("if (%s) {" % conditions.join())
                            emit.Indent()

                        emit.Line("%s.Clear();" % cpp_name)
                        emit.Line("for (uint16_t i = 0; i < %s; i++) { %s.Add() = %s[i]; }" % (size, cpp_name, rhs))

                        if conditions.count():
                            emit.Unindent()
                            emit.Line("}")
                            emit.Line("else {")
                            emit.Indent()
                            emit.Line("%s.Null(true);" % cpp_name)
                            emit.Unindent()
                            emit.Line("}")

                        emit.Line()
                    else:
                        raise RPCEmitterError("unable to serialize a non-iterator array: %s" % param.json_name)

                # All others...
                else:
                    if param_meta.flags.store_lookup:
                        emit.Line("%s = %s->%s.Store(_real%s, %s);" % (param.temp_name, names.storage, param.cpp_name, param.temp_name, names.context))
                        emit.Line("_real%s->Release();" % param.temp_name)

                    # assignment operator takes care of OptionalType
                    emit.Line("%s = %s;" % (cpp_name, rhs + param.convert_rhs))

                    if param.schema.get("opaque") and not repsonse_parent: # if comes from a struct it already has a SetQuoted
                        emit.Line("%s.SetQuoted(false);" % (cpp_name))

            emit.Unindent()
            emit.Line("}")

        if restrictions.present():
            emit.Unindent()
            emit.Line("}")

    is_json_source = source_file.endswith(".json")

    for i, ns_ in enumerate(ns.split("::")):
        if ns_ and i >= 2:
            emit.Indent()

    if "info" in root.schema and "namespace" in root.schema["info"]:
        emit.Indent()

    emit.Indent()

    _EmitVersionCode(emit, rpc_version.GetVersion(root.schema["info"] if "info" in root.schema else dict()))

    methods_and_properties = [x for x in root.properties if not isinstance(x, (JsonNotification))]
    methods = [x for x in methods_and_properties if not isinstance(x, (JsonNotification, JsonProperty))]
    events = [x for x in root.properties if isinstance(x, JsonNotification)]
    async_events = []
    async_methods = []
    listener_events = [x for x in events if x.is_status_listener]
    lookup_events = [x for x in events if "@lookup" in x.schema]
    alt_events = [x for x in events if x.alternative]
    lookup_methods = [x for x in methods_and_properties if x.schema.get("@lookup)")]

    names = DottedDict()

    names['module'] = "_module__"
    names['impl'] = "_implementation__"
    names['storage'] = "_storage__"
    names['handler'] = ("_handler_" if not is_json_source else names.impl)
    names['handler_interface'] = "IHandler"
    names['context'] = "context"
    names['id'] = "id"

    names['namespace'] = ("J" + root.json_name)
    names['interface'] = (root.info["interface"] if "interface" in root.info else ("I" + root.json_name))
    names['jsonrpc_alias'] = ("PluginHost::%s" % ("JSONRPCSupportsEventStatus" if listener_events or lookup_events else "JSONRPC"))
    names['context_alias'] = "Core::JSONRPC::Context"

    impl_required = methods_and_properties or listener_events
    module_required = (impl_required or (alt_events and not config.LEGACY_ALT))
    storage_required = (root.schema.get("@interfaces") != None)

    processed_vars = []

    for m in methods_and_properties:
        is_property = isinstance(m, JsonProperty)
        has_index = is_property and m.index

        if is_property:
            # Normalize property params/repsonse to match methods
            if m.properties[1].is_void and not m.writeonly:
                # Try to detect the uncompliant format
                params = copy.copy(m.properties[0] if not m.readonly else m.properties[1])
                response = copy.copy(m.properties[0] if not m.writeonly else m.properties[1])
            else:
                params = copy.copy(m.properties[0])
                response = copy.copy(m.properties[1])

            params.Rename("Params")
            response.Rename("Result")
        else:
            params = copy.copy(m.properties[0])
            response = copy.copy(m.properties[1])

        normalized_params = params if (params and not params.is_void) else None
        normalized_response = response if (response and not response.is_void) else None

        sorted_vars = _BuildVars(normalized_params, normalized_response)

        has_lookup_params = False
        has_async_params = False

        for _, [param, _, param_meta] in sorted_vars:
            if param_meta.flags.store_lookup or param_meta.flags.dispose_lookup:
                has_lookup_params = True
                break

        if m.callback:
            async_events.append(m.callback.notification)
            async_methods.append(m.callback)

        m.processed_vars = [params, response, normalized_params, normalized_response, sorted_vars, has_lookup_params, (m.callback != None)]

    if listener_events and not is_json_source:
        _EmitHandlerInterface(listener_events)

    if storage_required:
        _EmitStorageClass(root.schema.get("@interfaces"))

    if async_events:
        emit.Line("namespace Async {")
        emit.Indent()
        emit.Line()

        for aev in async_events:
            _EmitEvents([aev], aev.name.capitalize())

        emit.Unindent()
        emit.Line("} // namespace Async")
        emit.Line()

    for m in async_methods:
        _EmitAsyncCallbackImpl(m)

    _EmitNoPushWarnings(prologue=True)

    if is_json_source:
        emit.Line("using JSONRPC = %s;" % names.jsonrpc_alias)
        emit.Line()

    impl_name = ((" " + names.impl) if impl_required else "")

    register_params = [ "%s& %s" % (names.jsonrpc_alias, names.module) ]

    if is_json_source:
        register_params.append("IMPLEMENTATION&%s" % impl_name)
        emit.Line("template<typename IMPLEMENTATION>")

    else:
        register_params.append("%s*%s" % (names.interface, impl_name))

        if listener_events:
            register_params.append("%s* %s" % (names.handler_interface, names.handler))

        if storage_required:
            register_params.append("%s*& %s" % ("LookupStorage", names.storage))

    emit.Line("static void Register(%s)" % (", ".join(register_params)))

    emit.Line("{")
    emit.Indent()

    if not is_json_source:
        if methods_and_properties:
            emit.Line("ASSERT(%s != nullptr);" % names.impl)

        if listener_events:
            emit.Line("ASSERT(%s != nullptr);" % names.handler)

        if storage_required:
            emit.Line("ASSERT(%s == nullptr);" % names.storage)

        if methods_and_properties or listener_events or storage_required:
            emit.Line()

        if storage_required:
            emit.Line("%s = new LookupStorage;" % names.storage)
            emit.Line("ASSERT(%s != nullptr);" % names.storage)
            emit.Line()


        emit.Line("%s.RegisterVersion(%s, Version::Major, Version::Minor, Version::Patch);" % (names.module, Tstring(names.namespace)))

        if lookup_events:
            emit.Line()
            emit.Line("// Install subscription assessor")
            emit.Line()
            emit.Line("%s.SetSubscribeAssessor([%s](const uint32_t channel, const string& event, const string& client) -> bool {" % (names.module, names.storage))
            emit.Indent()
            emit.Indent()
            emit.Line("bool result = true;")
            emit.Line("const uint32_t id = Core::JSONRPC::Message::InstanceId(event);")
            emit.Line()
            emit.Line("if (id != 0) {")
            emit.Indent()
            emit.Line("const string prefix = Core::JSONRPC::Message::Prefix(event);")
            emit.Line("result = false;")
            emit.Line()

            for i,ev in enumerate(lookup_events):
                emit.Line("%sif (prefix == _T(\"%s\")) {" % ("else " if i != 0 else "", ev.schema["@lookup"]["fullprefix"]))
                emit.Indent()
                emit.Line("result = %s->%s.Exists(channel, id);" % (names.storage, ev.schema["@lookup"]["prefix"]))
                emit.Unindent()
                emit.Line("}")

            emit.Unindent()
            emit.Line("}")
            emit.Line()
            emit.Line("return (result);")
            emit.Unindent()
            emit.Line("});")
            emit.Unindent()
            emit.Line()

    if module_required:
        emit.Line()

    if alt_events and not config.LEGACY_ALT:
        _EmitAlternativeEventsRegistration(alt_events, prologue=True)

    if methods_and_properties:
        emit.Line("// Register methods and properties...")
        emit.Line()

    prototypes = []

    for m in methods_and_properties:

        is_property = isinstance(m, JsonProperty)
        has_index = is_property and m.index

        params, response, normalized_params, normalized_response, sorted_vars, has_lookup_params, has_async_params = m.processed_vars

        any_index = (m.index[0] if m.index[0] else m.index[1]) if has_index else None
        indexes_are_different = not m.index[2] if has_index else False
        index_name = any_index.local_name if any_index else None

        has_context = not is_property and m.context
        lookup = m.schema.get("@lookup")

        needs_module = has_async_params
        needs_context = has_context or has_lookup_params or lookup or has_async_params
        needs_storage = has_lookup_params or lookup
        needs_id = (lookup != None)
        needs_index = has_index
        needs_handler = needs_context or needs_id or needs_index

        if is_property:
            emit.Line("// %sProperty: %s%s" % ("Indexed " if has_index else "", m.Headline(), " (r/o)" if m.readonly else (" (w/o)" if m.writeonly else "")))
        else:
            emit.Line("// Method: %s" % m.Headline())

        # Emit method prologue
        template_params = [ params.cpp_type, response.cpp_type ]

        if needs_handler:
            function_params = []

            if needs_context:
                function_params.append("const %s&" % names.context_alias)

            if needs_id:
                function_params.append("const %s" % lookup["type"])

            if needs_index:
                function_params.append("const string&")

            if not params.is_void:
                function_params.append("const %s&" % params.cpp_type)

            if not response.is_void:
                function_params.append("%s&" % response.cpp_type)

            template_params.append("std::function<uint32_t(%s)>" % (", ".join(function_params)))

        emit.Line("%s.Register<%s>(%s, " % (names.module, (", ".join(template_params)), Tstring(m.json_name)))
        emit.Indent()

        lambda_params = []

        if needs_context:
            lambda_params.append("const %s& %s" % (names.context_alias, names.context))

        if needs_id:
            lambda_params.append("const %s %s" % (lookup["type"], names.id))

        if needs_index:
            lambda_params.append("const string& %s" % (index_name))

        if not params.is_void:
            lambda_params.append("const %s& %s" % (params.cpp_type, params.local_name))

        if not response.is_void:
            lambda_params.append("%s& %s" % (response.cpp_type, response.local_name))

        captures = []
        captures.append("%s%s" % ("&" if is_json_source else "", names.impl))

        if needs_module:
            captures.append("&" + names.module)

        if needs_storage:
            captures.append(names.storage)

        emit.Line("[%s](%s) -> uint32_t {" % (", ".join(captures), ", ".join(lambda_params)))
        emit.Indent()

        # Emit the function body

        params_parent = ((params.local_name + '.') if (isinstance(params, JsonObject) and params.do_create) else "")
        response_parent = ((response.local_name + '.') if (isinstance(response, JsonObject) and response.do_create) else "")

        error_code = AuxJsonInteger("errorCode_", 32)
        emit.Line("%s %s = %s;" % (error_code.cpp_native_type, error_code.temp_name, CoreError("none")))
        emit.Line()

        # If indexes for r/w property are the same, then emit index code before the check for set/not-set, otherwise do it afterwards
        index_checks_emitted, index_name = _EmitIndexing(any_index, index_name) if (has_index and not indexes_are_different) else (False, index_name)

        if not is_property:
            _Invoke(m, sorted_vars, normalized_params, normalized_response, params_parent, response_parent, context=has_context)
        else:
            is_read_only = m.readonly
            is_write_only = m.writeonly
            is_read_write = not m.readonly and not m.writeonly

            if is_read_write:
                emit.Line("if (%s.IsSet() == false) {" % (params.local_name))
                emit.Indent()
                emit.Line("// property get")

            elif is_read_only:
                emit.Line("// read-only property get")

            if not is_write_only:
                assert normalized_response

                checks_emitted, index_name = _EmitIndexing(any_index, index_name) if (has_index and not index_checks_emitted) else (False, index_name)

                maybe_index = index_name if has_index else None
                _Invoke(m, _BuildVars(None, normalized_response), None, normalized_response, params_parent, response_parent, const_cast=is_read_write, test_param=not is_read_write, index=maybe_index, context=has_context)

                if checks_emitted:
                    emit.Unindent()
                    emit.Line("}")

                if indexes_are_different:
                    index_name = any_index.local_name

            if not is_read_only:
                assert normalized_params

                if is_read_write:
                    emit.Unindent()
                    emit.Line("}")
                    emit.Line("else {")
                    emit.Indent()
                    emit.Line("// property set")
                else:
                    emit.Line("// write-only property set")

                checks_emitted, index_name = _EmitIndexing(any_index, index_name) if (has_index and not index_checks_emitted) else (False, index_name)

                maybe_index = index_name if has_index else None
                _Invoke(m, _BuildVars(normalized_params, None), normalized_params, None, params_parent, response_parent, param_const_cast=is_read_write, test_param=not is_read_write, index=maybe_index, context=has_context)

                if checks_emitted:
                    emit.Unindent()
                    emit.Line("}")

            if is_read_write:
                emit.Line()
                emit.Line("%s.Null(true);" % (response.local_name)) # FIXME

            if not is_read_only and is_read_write:
                emit.Unindent()
                emit.Line("}")

        if index_checks_emitted:
            emit.Unindent()
            emit.Line("}")

        emit.Line()

        # Emit method epilogue

        emit.Line("return (%s);" % error_code.temp_name)
        emit.Unindent()
        emit.Line("});")
        emit.Unindent()
        emit.Line()

        if not config.LEGACY_ALT and m.alternative:
            emit.Line()
            emit.Line("%s.Register(%s, %s);" % (names.module, Tstring(m.alternative), Tstring(m.name)))
            emit.Line()

    # Emit event status registrations
    if listener_events:
        _EmitEventStatusListenerRegistration(listener_events, is_json_source, prologue=True)

    emit.Unindent()
    emit.Line("}")
    emit.Line()

    # Emit method deregistrations
    unregister_params = [ names.jsonrpc_alias + "&" + ((" " + names.module) if module_required else "") ]

    if storage_required:
        unregister_params.append("LookupStorage*& %s" % names.storage)


    emit.Line("static void Unregister(%s)" % ", ".join(unregister_params))
    emit.Line("{")
    emit.Indent()

    if methods_and_properties:
        emit.Line("// Unregister methods and properties...")

        for m in methods_and_properties:
            if isinstance(m, JsonMethod) and not isinstance(m, JsonNotification):
                emit.Line("%s.Unregister(%s);" % (names.module, Tstring(m.json_name)))

                if not config.LEGACY_ALT and m.alternative:
                    emit.Line("%s.Unregister(%s);" % (names.module, Tstring(m.alternative)))

    # Emit alternative events deregistrations
    if alt_events and not config.LEGACY_ALT:
        _EmitAlternativeEventsRegistration(alt_events, prologue=False)

    # Emit event status listeners deregistrations
    if listener_events:
        _EmitEventStatusListenerRegistration(listener_events, is_json_source, prologue=False)

    if lookup_events:
        emit.Line()
        emit.Line("// Uninstall subscription assessor")
        emit.Line("%s.SetSubscribeAssessor(nullptr);" % names.module)

    if storage_required:
        emit.Line()
        emit.Line("ASSERT(%s != nullptr);" % names.storage)
        emit.Line("delete %s;" % names.storage)
        emit.Line("%s = nullptr;" % names.storage)

    emit.Unindent()
    emit.Line("}")
    emit.Line()

    # Finally emit utility event code
    if events:
        _EmitEvents(events)

    if storage_required:
        _EmitLinkEvents(root.schema.get("@interfaces"))
        _EmitLiftimeCallbacks(root.schema.get("@interfaces"))

    # Restore warnings level
    _EmitNoPushWarnings(prologue=False)

    # Return collected signatures, so the emited file can be prepended with
    return prototypes

def __Namespace(root):
    return (root.schema["namespace"] if "namespace" in root.schema else "::%s::Exchange" % config.FRAMEWORK_NAMESPACE)

def EmitRpcCode(root, emit, header_file, source_file, data_emitted):
    _namespace = __Namespace(root)
    prototypes = _EmitRpcCode(root, emit, _namespace, header_file, source_file, data_emitted)

    with emitter.Emitter(None, config.INDENT_SIZE) as prototypes_emitter:
        _EmitRpcPrologue(root, prototypes_emitter, header_file, source_file, _namespace, data_emitted, prototypes)
        emit.Prepend(prototypes_emitter)

    _EmitRpcEpilogue(root, emit, _namespace)

def EmitRpcVersionCode(root, emit, header_file, source_file, data_emitted):
    _namespace = __Namespace(root)
    _EmitRpcPrologue(root, emit, header_file, source_file, _namespace, data_emitted)
    _EmitVersionCode(emit, rpc_version.GetVersion(root.schema["info"] if "info" in root.schema else dict()))
    _EmitRpcEpilogue(root, emit, _namespace)
