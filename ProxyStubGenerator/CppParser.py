#!/usr/bin/env python3

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

#
# C++ header parser
#

import re, uuid, sys, copy, hashlib, random, os
from collections import OrderedDict
from enum import IntEnum


sys.path.append(os.path.join(os.path.dirname(os.path.abspath(__file__)), os.pardir + os.sep))
import ProxyStubGenerator.Log as Log

class ParserError(RuntimeError):
    def __init__(self, msg):
        msg = "%s(%s): parse error: %s" % (CurrentFile(), CurrentLine(), msg)
        super(ParserError, self).__init__(msg)

class LoaderError(RuntimeError):
    def __init__(self, file, msg):
        msg = "%s: load error: %s" % (file, msg)
        super(LoaderError, self).__init__(msg)


# Checks if identifier is valid.
def is_valid(token):
    if "operator" in token:
        return re.match(r'^[-\+~<>=!%&^*/\|\[\]]+$', token[8:])
    else:
        validChars = re.match(r'^[a-zA-Z0-9_~]+$', token)
        return token and validChars and not token[0].isdigit()


def ASSERT_ISVALID(token):
    if not is_valid(token):
        raise ParserError("invalid identifier: '" + token + "'")
    elif token in ["alignas", "alignof"]:
        raise ParserError("alignment specifiers are not supported")


def ASSERT_ISEXPECTED(token, list):
    if token not in list:
        raise ParserError("unexpected identifier: '" + str(token) + "', expected one of " + str(list))


# -------------------------------------------------------------------------
# CLASS DEFINITIONS
# -------------------------------------------------------------------------

global_namespace = None


class Ref(IntEnum):
    VALUE = 1
    POINTER = 2
    REFERENCE = 4
    RVALUE_REFERENCE = 8
    CONST = 16,
    VOLATILE = 32,
    POINTER_TO_CONST = 64,
    POINTER_TO_VOLATILE = 128,
    POINTER_TO_POINTER = 256


class Metadata:
    def __init__(self):
        self.sourcelocation = ""
        self.brief = ""
        self.details = ""
        self.pre = ""
        self.post = ""
        self.input = False
        self.output = False
        self.length = None
        self.maxlength = None
        self.interface = None
        self.default = None
        self.alt = None
        self.text = None
        self.range = []
        self.decorators = []
        self.param = OrderedDict()
        self.retval = OrderedDict()
        self.is_property = False
        self.is_deprecated = False
        self.is_obsolete = False
        self.is_index = False
        self.alt_is_deprecated = None
        self.alt_is_obsolete = None

    @property
    def is_input(self):
        return self.input or not self.output

    @property
    def is_output(self):
        return self.output

class BaseType:
    def __init__(self, type):
        self.type = type

    def Proto(self):
        return TypeStr(self.type)

    def __str__(self):
        return self.Proto()


class Undefined(BaseType):
    def __init__(self, type, comment=""):
        BaseType.__init__(self, type)
        self.comment = comment

    def Proto(self):
        if isinstance(self.type, list):
            proto = ""

            for e in self.type:
                proto += " " + (e.strip() if isinstance(e, str) else str(e))

            proto = proto.replace(" < ", "<").replace(" :: ", "::").replace(" >", ">")
            proto = proto.replace(" *", "*").replace(" &", "&").replace(" &&", "&&").replace(" ,",",").strip()
        else:
            proto = str(self.type)

        return ((self.comment + " " if self.comment else "") + proto)

    def __str__(self):
        return self.Proto()

    def __repr__(self):
        return "undefined %s" % self.Proto()


class Fundamental(BaseType):
    def __init__(self, type):
        BaseType.__init__(self, type)

    def __repr__(self):
        return "fundamental %s" % self.type


class Intrinsic(BaseType):
    def __init__(self, type):
        BaseType.__init__(self, type)

    def __repr__(self):
        return "intrinsic %s" % self.type


class BuiltinInteger(Intrinsic):
    def __init__(self, fixed_size=False, name="builtin_integer"):
        Intrinsic.__init__(self, name)
        self.fixed = fixed_size

    def IsFixed(self):
        return self.fixed


class InstanceId(BuiltinInteger):
    def __init__(self):
        BuiltinInteger.__init__(self, fixed_size=True, name="Core::instance_id")

    def IsFixed(self):
        return self.fixed


class String(Intrinsic):
    def __init__(self, std=False, cc=False):
        Intrinsic.__init__(self, "std::string" if std else "ccstring" if cc else "string")
        self.is_cc = cc


class CCString(Intrinsic):
    def __init__(self, std=False):
        Intrinsic.__init__(self, "ccstring")


class Time(Intrinsic):
    def __init__(self):
        Intrinsic.__init__(self, "Core::Time::microsecondsfromepoch")

class MacAddress(Intrinsic):
    def __init__(self):
        Intrinsic.__init__(self, "Core::MACAddress")


class Optional(Intrinsic):
    def __init__(self, subtype):
        Intrinsic.__init__(self, "Core::OptionalType<%s>" % subtype.Proto())
        self.optional = subtype


class Nullptr_t(Fundamental):
    def __init__(self):
        Fundamental.__init__(self, "std::nullptr_t")


class Void(Fundamental):
    def __init__(self):
        Fundamental.__init__(self, "void")


class Bool(Fundamental):
    def __init__(self):
        Fundamental.__init__(self, "bool")


class Integer(Fundamental):
    def __init__(self, string):
        Fundamental.__init__(self, string)
        self.signed = "unsigned" not in self.type and "uint" not in self.type
        self.fixed = False
        self.min = 0
        self.max = 0
        if ("64" in self.type) or ("long long" in self.type):
            self.size = "long long"
            self.min = (-2**63 if self.signed else 0)
            self.max = (2**63-1 if self.signed else 2**64-1)
            self.fixed = True
        elif ("32" in self.type) or ("long" in self.type):
            self.size = "long"
            self.min = (-2**31 if self.signed else 0)
            self.max = (2**31-1 if self.signed else 2**32-1)
            self.fixed = True
        elif ("16" in self.type) or ("short" in self.type):
            self.size = "short"
            self.min = (-2**15 if self.signed else 0)
            self.max = (2**15-1 if self.signed else 2**16-1)
            self.fixed = True
        elif ("8" in self.type):
            self.size = "char"
            self.min = (-2**7 if self.signed else 0)
            self.max = (2**7-1 if self.signed else 2**8-1)
            self.fixed = True
        elif "char" in self.type:
            self.size = "char"
            self.signed = ("unsigned" not in self.type) and ("signed" in self.type)
            self.min = (-2**7 if self.signed else 0)
            self.max = (2**7-1 if self.signed else 2**8-1)
            self.fixed = ("signed" in self.type)
        elif self.type == "wchar_t":
            self.size = "wchar"
            self.signed = False
            self.min = 0
            self.max = 2**16-1
            self.fixed = True
        elif "int" in self.type:
            self.min = (-2**31 if self.signed else 0)
            self.max = (2**31-1 if self.signed else 2**32-1)
            self.size = "int"
        else:
            self.size = " ".join(self.type.split()[1:])

    def IsFixed(self):
        return self.fixed


class Float(Fundamental):
    def __init__(self, string):
        Fundamental.__init__(self, string)


# Holds identifier type
class Identifier():
    def __init__(self, parent_block, parent, string, valid_specifiers, tags_allowed=True):
        self.parent = parent_block
        self.meta = Metadata()
        if parent:
            parent.specifiers = []
        self.name = ""
        type = ["?"] # indexing safety
        type_found = False
        nest1 = 0
        nest2 = 0
        array = False
        array_size = None
        self.array = None
        skip = 0
        self.value = []

        if string.count("*") > 2:
            raise ParserError("multi-dimensional pointers to pointers are not supported: '%s'" % (" ".join(["".join(x) for x in string])))
        if string.count("[") > 1:
            raise ParserError("multi-dimensional arrays are not supported: '%s'" % (" ".join(["".join(x) for x in string])))
        elif "[" in string and "*" in string:
            raise ParserError("arrays of pointers are not supported: '%s'" % (" ".join(["".join(x) for x in string])))
        elif "&&" in string:
            raise ParserError("rvalue references are not supported: '%s'" % (" ".join(["".join(x) for x in string])))

        for i, token in enumerate(string):
            if not token:
                continue

            if isinstance(token, Type):
                # encountered a token that has already been parsed
                type.append(token)
                type_found = True
                continue

            if skip > 0:
                skip -= 1
                continue

            # just keep together anything that comes within <> or () brackets
            # template arguments will be parsed when/if instantiated
            if token == "(":
                type[-1] += " ("
                type_found = False
                nest1 += 1
            elif token == ")":
                type[-1] += " )"
                if nest1 == 0 and not nest2:
                    type_found = True
                nest2 -= 1
            elif token == "<":
                if not nest2:
                    type.append("<")
                    type_found = False
                else:
                    type[-1] += " <"
                nest2 += 1
            elif token == ">":
                type[-1] += " >"
                nest2 -= 1
                if nest2 == 0 and not nest1:
                    type_found = True
            elif nest1 or nest2:
                # keep double collon-separated tokens together
                if token == "::" or type[-1].endswith("::"):
                    type[-1] += token
                else:
                    type[-1] += " " + (" ".join(token) if isinstance(token,list) else token)

            # handle pointer/reference markers
            elif token[0] == "@":
                tag = token[1:]
                if tag == "IN":
                    if tags_allowed:
                        self.meta.input = True
                    else:
                        raise ParserError("in/out tags not allowed here")
                elif tag == "OUT":
                    if tags_allowed:
                        self.meta.output = True
                    else:
                        raise ParserError("in/out tags not allowed here")
                elif tag == "INDEX":
                    if tags_allowed:
                        self.meta.is_index = True
                    else:
                        raise ParserError("@index tag not allowed here")
                elif tag == "LENGTH":
                    self.meta.length = string[i + 1]
                    skip = 1
                elif tag == "MAXLENGTH":
                    if tags_allowed:
                        self.meta.maxlength = string[i + 1]
                    else:
                        raise ParserError("@maxlength tag not allowed here")
                    skip = 1
                elif tag == "RESTRICT":
                    self.meta.range = []
                    for s in "".join(string[i + 1]).split(".."):
                        try:
                            if '.' not in s:
                                v = int(eval(s.lower().replace("k","*1024").replace("m","*1024*1024").replace("g","*1024*1024*1024")))
                            else:
                                v = eval(s)
                            self.meta.range.append(v)
                        except:
                            raise ParserError("failed to evaluate range in @restrict: '%s'" % s)
                    if len(self.meta.range) == 2:
                        if self.meta.range[0] > self.meta.range[1]:
                            raise ParserError("invalid range in @restrict: %s > %s" % (self.meta.range[0], self.meta.range[1]))
                    elif len(self.meta.range) == 1:
                        self.meta.range.append(self.meta.range[0])
                        self.meta.range[0] = 0
                    else:
                        raise ParserError("failed to parse range in @restrict: '%s'" % "".join(string[i + 1]))
                    skip = 1
                elif tag == "INTERFACE":
                    self.meta.interface = string[i + 1]
                    skip = 1
                elif tag == "DEFAULT":
                    self.meta.default = string[i + 1]
                    skip = 1
                elif tag == "OPAQUE":
                    self.meta.decorators.append("opaque")
                elif tag == "ENCODEBASE64":
                    self.meta.decorators.append("encode:base64")
                elif tag == "ENCODEHEX":
                    self.meta.decorators.append("encode:hex")
                elif tag == "ENCODEIP":
                    self.meta.decorators.append("encode:ip")
                elif tag == "ENCODEMAC":
                    self.meta.decorators.append("encode:mac")
                elif tag == "OPTIONAL":
                    self.meta.decorators.append("optional")
                elif tag == "EXTRACT":
                    self.meta.decorators.append("extract")
                elif tag == "END":
                    self.meta.decorators.append("endmarker")
                elif tag == "PROPERTY":
                    self.meta.is_property = True
                elif tag == "ASYNC":
                    self.meta.decorators.append("async")
                elif tag == "BRIEF":
                    self.meta.brief = string[i + 1]
                    skip = 1
                elif tag == "DETAILS":
                    self.meta.details = string[i + 1]
                    skip = 1
                elif tag == "PRE":
                    self.meta.pre = string[i + 1]
                    skip = 1
                elif tag == "POST":
                    self.meta.post = string[i + 1]
                    skip = 1
                elif tag == "PARAM":
                    par = string[i + 1]
                    if par.endswith(":"):
                        par = par[:-1]
                    self.meta.param[par] = string[i + 2]
                    skip = 2
                elif tag == "RETVAL":
                    par = string[i + 1]
                    if par.endswith(":"):
                        par = par[:-1]
                    self.meta.retval[par] = string[i + 2]
                    skip = 2
                elif tag == "STATUSLISTENER":
                    self.meta.decorators.append("statuslistener")
                elif tag == "DEPRECATED":
                    self.meta.is_deprecated = True
                elif tag == "OBSOLETE":
                    self.meta.is_obsolete = True
                elif tag == "BITMASK":
                    self.meta.decorators.append("bitmask")
                elif tag == "TEXT":
                    self.meta.text = "".join(string[i + 1])
                    skip = 1
                elif tag == "ALT":
                    self.meta.alt = "".join(string[i + 1])
                    skip = 1
                elif tag == "ALT:OBSOLETE" or tag == "ALT-OBSOLETE":
                    self.meta.alt = "".join(string[i + 1])
                    self.meta.alt_is_obsolete = True
                    skip = 1
                elif tag == "ALT:DEPRECATED" or tag == "ALT-DEPRECATED":
                    self.meta.alt = "".join(string[i + 1])
                    self.meta.alt_is_deprecated = True
                    skip = 1
                else:
                    raise ParserError("invalid tag: " + token)

            # skip C-style explicit struct
            elif token in ["struct", "class", "union"]:
                continue
            elif token in ["export"]: # skip
                continue
            # keep identifers with scope operator together
            elif token == "::":
                if len(type) > 1:
                    type[-1] += "::"
                type_found = False

            # arrays are equivalent to pointers here, so make it uniform
            # disregard anything that's inside the brackets
            elif token == "[":
                array = True
            elif token == "]":
                array = False
                type.append("*")
                self.array = array_size
                array_size = None

            elif token in ["*", "&"]:
                type.append(token)

            elif token in ["const", "volatile", "constexpr"]:
                if token == "constexpr":
                    if parent:
                        parent.specifiers.append("constexpr")
                    token = "const"

                # put qualifiers in order
                if "*" in type:
                    type.insert(type.index("*") + 1, token)
                elif "&" in type:
                    type.insert(type.index("&") + 1, token)
                else:
                    type.insert(1, token)

            # include valid specifiers
            elif token in valid_specifiers:
                if parent:
                    parent.specifiers.append(token)

            elif not type_found and not array:
                # handle primitive type combinations...
                if isinstance(type[-1], str):
                    if (token in ["int"]) and (type[-1].split()[-1] in ["signed", "unsigned", "short", "long"]):
                        type[-1] += " " + token
                    elif (token in ["char", "short", "long"]) and (type[-1].split()[-1] in ["signed", "unsigned"]):
                        type[-1] += " " + token
                    elif (token in ["long", "double"]) and (type[-1].split()[-1] in ["long"]):
                        type[-1] += " " + token
                    # keep identifers with scope operator together
                    elif type[-1].endswith("::"):
                        type[-1] += token
                    # keep together anything that comes within <> or () brackets
                    elif nest1 == 0 and nest2 == 0:
                        type.append(token)
                    else:
                        type[-1] += token

                if ((i == len(string) - 1) or (string[i + 1] not in ["char", "short", "long", "int", "double"])):
                    type_found = True

            elif type_found:
                if not array:
                    self.name = token
                else:
                    array_size = token

        if array:
            raise ParserError("unmatched bracket '['")

        type = type[1:]
        self.type = type

        # Normalize fundamental types
        if type and isinstance(type[-1], str):
            t = type[-1]
            if t.split()[-1] in ["char", "short", "long", "int", "double", "float", "signed", "unsigned"]:
                if "double" in t:
                    type[-1] = "long double" if "long" in t else "double"
                elif "float" in t:
                    type[-1] = "float"
                elif "long" in t:
                    if t.count("long") == 1:
                        type[-1] = "unsigned long" if "unsigned" in t else "signed long"
                    else:
                        type[-1] = "unsigned long long" if "unsigned" in t else "signed long long"
                elif "short" in t:
                    type[-1] = "unsigned short" if "unsigned" in t else "signed short"
                elif "char" in t:
                    type[-1] = "unsigned char" if "unsigned" in t else "signed char" if "signed" in t else "char"
                elif "int" in t or "signed" in t or "unsigned" in t:
                    type[-1] = "unsigned int" if "unsigned" in t else "signed int"

        # Try to match the type to an already defined class...
        self.ResolveIdentifiers(parent_block)

    def ResolveIdentifiers(self, parent):
        if isinstance(parent, Method):
            parent = parent.parent

        if self.type:

            def __Search(tree, found, T):
                qualifiedT = "::" + T

                # need full qualification if the class is a subclass
                if parent and tree.full_name.startswith(parent.full_name + "::"):
                    if T.count("::") != tree.full_name.replace(parent.full_name, "").count("::"):
                        return

                enum_match = [e for e in tree.enums if e.full_name.endswith(qualifiedT)]
                typedef_match = [td for td in tree.typedefs if td.full_name.endswith(qualifiedT)]
                class_match = [cl for cl in tree.classes if cl.full_name.endswith(qualifiedT)]

                enumval_match = []
                for en in tree.enums:
                    enumval_match += ([e for e in en.items if e.full_name.endswith(qualifiedT)])

                template_match = []
                if isinstance(tree, TemplateClass):
                    template_match = [t for t in tree.parameters if t.full_name.endswith(qualifiedT)]

                found += enum_match + typedef_match + class_match + template_match + enumval_match

                if isinstance(tree, (Namespace, Class)):
                    for c in tree.classes:
                        __Search(c, found, T)

                if isinstance(tree, Namespace):
                    for n in tree.namespaces:
                        __Search(n, found, T)

            # find the type to scan for...
            typeIdx = len(self.type) - 1
            cnt = 0
            ref = 0

            if isinstance(self.type[typeIdx], str):
                if self.type[typeIdx].startswith('['):
                    ref |= Ref.POINTER
                    typeIdx -=1
                    cnt += 1

            while self.type[typeIdx] in ["*", "&", "&&", "const", "volatile"]:
                if self.type[typeIdx] == "*":
                    if ref & Ref.POINTER:
                        ref |= Ref.POINTER_TO_POINTER
                    else:
                        ref |= Ref.POINTER
                elif self.type[typeIdx] == "&":
                    if ref & Ref.POINTER:
                        raise ParserError("pointer to a reference is not valid C++")
                    ref |= Ref.REFERENCE
                elif self.type[typeIdx] == "&&":
                    if ref & Ref.POINTER:
                        raise ParserError("pointer to a reference is not valid C++")
                    ref |= Ref.RVALUE_REFERENCE
                elif self.type[typeIdx] == "const":
                    ref |= Ref.CONST
                elif self.type[typeIdx] == "volatile":
                    ref |= Ref.VOLATILE

                typeIdx -= 1
                cnt += 1


            # Skip template parsing here
            if isinstance(self.type[typeIdx], str):
                if self.type[typeIdx][0] == "<":
                    typeIdx -= 1

            if isinstance(self.type[typeIdx], str):
                i = typeIdx
                type = self.type[i].split()[-1]

                if type in ["float", "double"]:
                    self.type[i] = Type(Float(self.type[i]))
                elif type in ["int", "char", "wchar_t", "char16_t", "char32_t", "short", "long", "signed", "unsigned",
                              "int8_t", "uint8_t", "int16_t", "uint16_t", "int32_t", "uint32_t", "int64_t", "uint64_t"]:
                    self.type[i] = Type(Integer(self.type[i]))
                elif type == "bool":
                    self.type[i] = Type(Bool())
                elif type == "void":
                    self.type[i] = Type(Void())
                elif type == "string":
                    self.type[i] = Type(String())
                elif type == "ccstring":
                    self.type[i] = Type(String(cc=True))
                elif type == "std::string":
                    self.type[i] = Type(String(std=True))
                elif type == "__stubgen_integer":
                    self.type[i] = Type(BuiltinInteger(True))
                elif type == "__stubgen_undetermined_integer":
                    self.type[i] = Type(BuiltinInteger(False))
                elif type == "__stubgen_instance_id":
                    self.type[i] = Type(InstanceId())
                elif type == "__stubgen_time":
                    self.type[i] = Type(Time())
                elif type == "__stubgen_macaddress":
                    self.type[i] = Type(MacAddress())
                else:
                    found = []
                    __Search(global_namespace, found, self.type[i])
                    if found:
                        # take closest match
                        found = found[-1]
                        if isinstance(found, TemplateClass):
                            # if we're pointing to a class template, then let's instantiate it!
                            self.type[i] = Type(found.Instantiate(self.type[i + 1], parent))
                            del self.type[i + 1]
                        else:
                            self.type[i] = found if isinstance(found, TemplateTypeParameter) else Type(found)

                if isinstance(self.type[typeIdx], Type):
                    self.type[typeIdx].ref = ref

            if isinstance(self.type[typeIdx], Type):
                for i in range(len(self.type) - cnt - 1):
                    if self.type[i] == "const":
                        if self.type[typeIdx].ref & Ref.POINTER:
                            self.type[typeIdx].ref |= Ref.POINTER_TO_CONST
                        else:
                            self.type[typeIdx].ref |= Ref.CONST
                    elif self.type[i] == "volatile":
                        if self.type[typeIdx].ref | Ref.POINTER:
                            self.type[typeIdx].ref |= Ref.POINTER_TO_VOLATILE
                        else:
                            self.type[typeIdx].ref |= Ref.VOLATILE

                self.type = self.type[typeIdx]

    def __str__(self):
        return str(self.type) if self.type else ""

    def __repr__(self):
        return str(self)

    def Type(self):
        return self.type

    def Proto(self):
        return TypeStr(self.type)

    def TypeStrong(self):
        if self.array:
            return ("%s[%s]" % (self.type.Proto("nocv|noref|noptr"), self.array))
        else:
            return self.Proto()

    def ProtoFmt(self):
        if self.array:
            return ("%s @[%s]" % (self.type.Proto("nocv|noref|noptr"), self.array))
        else:
            return "%s @" % self.Proto()

    def Signature(self, override=None):
        if self.array:
            return ("%s %s[%s]" % (self.type.Proto("nocv|noref|noptr"), override if override != None else self.name, self.array))
        else:
            return (self.Proto() + " " + (override if override != None else self.name))


def Evaluate(identifiers_):
    # Ensure scoped identifiers are kpt together
    identifiers = ["?"]
    for i, id in enumerate(identifiers_):
        if id == "::" or identifiers[-1].endswith("::"):
            identifiers[-1] += id
        else:
            identifiers.append(id)
    del identifiers[0]

    val = []
    if identifiers:
        for identifier in identifiers:
            try:
                val.append(str(int(identifier, 16 if identifier[:2] == "0x" else 10)))
            except:

                def __Search(tree, found, T):
                    var_match = [v for v in tree.vars if v.full_name.endswith(T)]

                    enumerator_match = []
                    for e in tree.enums:
                        enumerator_match += [item for item in e.items if item.full_name.endswith(T)]

                        # non-scoped enums can also be called with scope
                        if not e.scoped:
                            enumerator_match += [item for item in e.items if item.full_name_scoped.endswith(T)]


                    template_match = []
                    if (isinstance(tree, TemplateClass)):
                        template_match = [t for t in tree.arguments if t.full_name.endswith(T)]

                    found += var_match + enumerator_match + template_match

                    if isinstance(tree, (Namespace, Class)):
                        for c in tree.classes:
                            __Search(c, found, T)

                    if isinstance(tree, Namespace):
                        for n in tree.namespaces:
                            __Search(n, found, T)

                found = []
                __Search(global_namespace, found, "::" + identifier)
                if found:
                    val.append(found[-1])
                else:
                    val.append(str(identifier))

    if not val:
        val = identifiers

    value = None

    # attempt to parse the arithmetics...
    try:
        x = [str(v.value) if (isinstance(v, (Variable, Enumerator)) and v.value != None) else str(v) for v in val]
        value = eval("".join(x))
    except:
        try:
            value = eval("".join(val))
        except:
            try:
                value = " ".join(val)
            except:
                value = val

    return value


# Holds a name
class Name:
    def __init__(self, parent_block, name=""):
        if name:
            ASSERT_ISVALID(name)
        self.parent = parent_block
        # come up with an unique name if none given
        uniqueId = "__anonymous_" + self.__class__.__name__.lower() + "_" + uuid.uuid4().hex[:8]
        parentName = "" if self.parent == None else self.parent.full_name
        self.name = uniqueId if (not name and self.parent != None) else name
        self.full_name = parentName + ("" if not self.name else "::" + self.name)
        self.parser_file = CurrentFile()
        self.parser_line = CurrentLine()
        exists = []
        if isinstance(parent_block, Function):
            exists = exists + [x for x in self.parent.vars if x.name == self.name]
        if isinstance(parent_block, Class) or isinstance(parent_block, Union) or isinstance(parent_block, Namespace):
            exists = exists + [x for x in self.parent.vars if x.name == self.name]
            exists = exists + [x for x in self.parent.unions if x.name == self.name]
            exists = exists + [x for x in self.parent.enums if x.name == self.name]
            exists = exists + [x for x in self.parent.typedefs if x.name == self.name]
            if not isinstance(self, Function):
                exists = exists + [x for x in self.parent.methods if x.name == self.name]
            #exists = exists + [x for x in self.parent.classes if x.name == self.name]
        if isinstance(parent_block, Namespace) and not isinstance(self, Namespace):
            exists = exists + [x for x in self.parent.namespaces if x.name == self.name]
        if exists:
            raise ParserError("duplicate indentifier: %s" % self.name)

    def Name(self):
        return self.full_name

    def ShortName(self):
        return self.name


# Holds compound statements and composite types
class Block(Name):
    def __init__(self, parent_block, name=""):
        Name.__init__(self, parent_block, name)
        self.vars = []
        self.enums = []
        self.typedefs = []
        self.classes = []
        self.unions = []
        self.parser_file = CurrentFile()
        self.parser_line = CurrentLine()


# Holds namespaces
class Namespace(Block):
    def __init__(self, parent_block, name=""):
        Block.__init__(self, parent_block, name)
        self.namespaces = []
        self.methods = []
        self.omit = False
        self.omit_mode = False
        self.stub = -False
        if self.parent != None:                                                                 # case for global namespace
            if isinstance(self.parent, Namespace):
                self.parent.namespaces.append(self)
            else:
                raise ParserError("can't insert namespace '%s' into non-namespace block '%s'" %
                                  (self.name, self.parent.name))

    def Proto(self):
        return self.name

    def __str__(self):
        return "namespace " + self.Proto()

    def __repr__(self):
        return self.__str__() if self.Proto else "global namespace"


# Holds a generic type, wraps fundamental and user-defined types with references and pointers
class Type:
    def __init__(self, basetype):
        self.type = basetype
        self.ref = Ref.VALUE

    def IsVoid(self):
        return (isinstance(self.type, Void) and not self.IsPointer() and not self.IsPointerToPointer())

    def IsConst(self):
        return (self.ref & Ref.CONST) != 0

    def IsVolatile(self):
        return (self.ref & Ref.VOLATILE) != 0

    def IsPointer(self):
        return (self.ref & Ref.POINTER) != 0

    def IsPointerToPointer(self):
        return (self.ref & Ref.POINTER_TO_POINTER) != 0

    def IsConstPointer(self):
        return self.IsPointer() and self.IsConst()

    def IsVolatilePointer(self):
        return self.IsPointer() and self.IsVolatile()

    def IsReference(self):
        return (self.ref & Ref.REFERENCE) != 0

    def IsRvalueReference(self):
        return (self.ref & Ref.RVALUE_REFERENCE) != 0

    def IsPointerToConst(self):
        return (self.ref & Ref.POINTER_TO_CONST) != 0

    def IsPointerToVolatile(self):
        return (self.ref & Ref.POINTER_TO_VOLATILE) != 0

    def IsConstPointerToConst(self):
        return self.IsConst() and self.IsPointerToConst()

    def IsConstReference(self):
        return self.IsConst() and self.IsReference()

    def IsValue(self):
        return not self.IsPointer() and not self.IsReference() and not self.IsRvalueReference()

    def IsNonConstReference(self):
        return self.IsReference() and not self.IsConst()

    def IsNonConstPointer(self):
        return self.IsPointer() and not self.IsConst()

    def IsFundamental(self):
        return isinstance(self.type, Fundamental)

    def IsIntrinsic(self):
        return isinstance(self.type, Intrinsic)

    def IsClass(self):
        return isinstance(self.type, Class)

    def Type(self):
        return self.type

    def TypeName(self):
        return self.type.Proto()

    def TypeNameCV(self):
        return self.type.Proto()

    def Resolve(self, ref = 0):
        if self.IsPointerToPointer() and ref & Ref.POINTER:
            raise ParserError("Too many pointers %s" % self)
        if self.IsPointer() and ref & Ref.POINTER:
            ref |= Ref.POINTER_TO_POINTER
        if isinstance(self.type, Typedef):
            type = self.type.Resolve(self.ref | ref)
            if isinstance(type, Type):
                type = type.Resolve()
        else:
            type = copy.deepcopy(self)
            type.ref |= ref
        return type

    def CVString(self, mask=""):
        _str = "const " if (self.IsConst() and not self.IsPointer() and "nocv" not in mask) or (self.IsPointerToConst() and "nopcv" not in mask) else ""
        _str += "volatile " if (self.IsVolatile() and not self.IsPointer() and "nocv" not in mask) or (self.IsPointerToVolatile() and "nopcv" not in mask) else ""
        return _str.strip()

    def PointerString(self, mask=""):
        _str = "*" if self.IsPointer() else ""
        _str += "*" if self.IsPointerToPointer() else ""
        if "nocv" not in mask:
            _str += " const" if self.IsConstPointer() else ""
            _str += " volatile" if self.IsVolatilePointer() else ""
        return _str

    def ReferenceString(self):
        _str = "&" if self.IsReference() else "&&" if self.IsRvalueReference() else ""
        return _str

    def Proto(self, mask=""):
        _str = self.CVString(mask)
        _str += " " if _str else ""
        _str += self.TypeName()
        if "noptr" not in mask:
            _str += self.PointerString(mask)
        if "noref" not in mask:
            _str += self.ReferenceString()
        return _str

    def __str__(self):
        return self.Proto()

    def __repr__(self):
        return "type " + str(self)


def TypeStr(s):
    return str(Undefined(s, "/* undefined type */")) if isinstance(s, list) else str(s)


def ValueStr(s):
    return str(s) if isinstance(s, int) else (str(Undefined(s, "/* unparsable expression */ ")) if not isinstance(s, str) else s)


# Holds typedef definition
class Typedef(Identifier, Name):
    def __init__(self, parent_block, string):
        Identifier.__init__(self, parent_block, self, string, [])
        Name.__init__(self, parent_block, self.name)
        self.parent = parent_block
        self.parent.typedefs.append(self)
        self.is_event = False
        self.is_iterator = self.parent.is_iterator if isinstance(self.parent, (Class, Typedef)) else False

    def Resolve(self, ref = 0):
        if isinstance(self.type, Typedef):
            type = self.type.Resolve(self.type.ref | ref)
        else:
            if isinstance(self.type, list):
                type = self.type[0]
            else:
                type = copy.deepcopy(self.type)
                type.ref |= ref
        return type

    def Proto(self):
        return self.full_name

    def __str__(self):
        return "typedef %s %s" % (TypeStr(self.type), self.full_name)

    def __repr__(self):
        return "typedef %s [= %s]" % (self.full_name, TypeStr(self.type.type))

# Holds structs and classes
class Class(Identifier, Block):
    def __init__(self, parent_block, name):
        Identifier.__init__(self, parent_block, self, [name], [])
        Block.__init__(self, parent_block, name)
        self.type = self.full_name
        self.specifiers = []
        self.methods = []
        self.classes = []
        self.ancestors = [] # parent classes
        self._current_access = "public"
        self.omit = False
        self.omit_mode = False
        self.stub = False
        self.is_json = False
        self.is_custom_lookup = False
        self.is_auto_lookup = False
        self.json_version = ""
        self.json_prefix = ""
        self.is_event = False
        self.is_extended = False
        self.is_collapsed = False
        self.is_compliant = False
        self.is_iterator = False
        self.sourcelocation = None
        self.type_name = name

        if sum([1 for x in self.parent.classes if x.name == name]) == 0:
            self.parent.classes.append(self)

    def IsPOD(self):
        return (not self.methods and self.vars)

    def IsAbstract(self):
        return any([m.IsPureVirtual() for m in self.methods])

    def IsVirtual(self):
        return any([m.IsVirtual() for m in self.methods])

    def Inherits(self, class_name):
        return any([(class_name == str(base[0])) for base in self.ancestors])

    def Proto(self):
        return self.full_name

    def _Merge(self, vars, methods, do_methods=False, virtual=False):
        for a in self.ancestors:
            if isinstance(a[0].type, Class):
                access = a[1]
                kind = a[0].type
                is_virtual = "virtual" in a[2]

                if access == "public":
                    kind._Merge(vars, methods, do_methods, is_virtual)
                else:
                    raise ParserError("public inheritance of %s is required" % kind.full_name)

        def Populate(array, are_methods=False):
            for v in array:
                if v.access == "public":
                    found = list(filter(lambda x: x.name == v.name, vars))
                    assert len(found)<=1

                    if not found:
                        vars.append(v)
                        v._virtual = virtual
                    elif not found[0]._virtual or not virtual:
                        raise ParserError("ambiguous %s %s (use virtual inhertiance?)" % ("method" if are_methods else "attributes", v.full_name))
                else:
                    raise ParserError("all members are reqired to be public, non-public member %s" % v.full_name)

        Populate(self.vars)

        if do_methods:
            Populate(self.methods, True)

    def Merge(self, do_methods=False):
        new_class = Class(self.parent, self.name)
        self._Merge(new_class.vars, new_class.methods, do_methods)
        return new_class

    def __str__(self):
        return "class " + self.Proto()

    def __repr__(self):
        astr = ""
        if self.ancestors:
            astr = " [<- " + ", ".join(str(a[0]) for a in self.ancestors) + "]"
        return "class %s%s" % (self.full_name, astr)


# Holds unions
class Union(Identifier, Block):
    def __init__(self, parent_block, name):
        Identifier.__init__(self, parent_block, self, [name], [])
        Block.__init__(self, parent_block, name)
        self.methods = []
        self.classes = []
        self._current_access = "public"
        self.omit = False
        self.omit_mode = False
        self.stub = False
        self.parent.unions.append(self)

    def __str__(self):
        return "union " + self.full_name

    def __repr__(self):
        return str(self)


# Holds enumeration blocks, including class enums
class Enum(Identifier, Block):
    def __init__(self, parent_block, name, is_scoped, type="int", bitmask=False):
        Identifier.__init__(self, parent_block, self, [type, name], [])
        Block.__init__(self, parent_block, name)
        self.items = []
        self.scoped = is_scoped
        self.parent.enums.append(self)
        if bitmask:
            self.meta.decorators.append("bitmask")
        self._last_value = 0 # used for auto-incrementation

    def Proto(self):
        return self.full_name

    def __str__(self):
        _str = ("enum " if not self.scoped else "enum class ")
        _str += "%s : %s" % (self.Proto(), TypeStr(self.type.type))
        return _str

    def __repr__(self):
        return str(self)

    def SetValue(self, value):
        self._last_value = value + 1

    def GetValue(self):
        return self._last_value

    def Enumerator(self, name):
        for item in self.items:
            if item.name == name:
                return item
        return None


# Holds functions
class Function(Block, Name):
    def __init__(self, parent_block, name, ret_type, valid_specifiers=["static", "extern", "inline"]):
        self.specifiers = []
        Block.__init__(self, parent_block, name if name else self.name)
        Name.__init__(self, parent_block, self.name)
        self.retval = Identifier(self, self, ret_type, valid_specifiers, False)
        self.omit = False
        self.stub = False
        self.is_excluded = False

    def Append(self):
        self.parent.methods.append(self)

    def Proto(self):
        _str = "static " if self.IsStatic() else ""
        _str += TypeStr(self.retval.type) if self.retval.type else ""
        _str += (" " if str(self.retval) else "") + self.name
        _str += "(%s)" % (", ".join([str(v) for v in self.vars]))
        return _str

    def IsStatic(self):
        return "static" in self.specifiers

    def __str__(self):
        return self.Proto()

    def __repr__(self):
        return "function %s" % (self.name)


# Holds variables and constants
class Temporary(Identifier, Name):
    def __init__(self, parent_block, string, value=[], valid_specifiers=["static", "extern", "register"], meta=None):
        Identifier.__init__(self, parent_block, self, string, valid_specifiers)
        Name.__init__(self, parent_block, self.name)
        self.value = Evaluate(value) if value else None
        if meta:
            self.meta = meta

    def __str__(self):
        return self.Proto()

    def __repr__(self):
        value = ValueStr(self.value) if self.value else None
        return "variable %s %s '%s'%s" % (str(self.specifiers), TypeStr(self.type), str(self.name),
                                          (" = " + value) if value else "")

class DynamicArray(Intrinsic):
    def __init__(self, container, subtype):
        Intrinsic.__init__(self, "%s<%s>" % (container, subtype.Proto()))
        self.element = subtype

class Vector(DynamicArray):
    def __init__(self, subtype):
        DynamicArray.__init__(self, "std::vector", subtype)

class VectorElement(Temporary):
    def __init__(self, parent_block, string, value=[], valid_specifiers=[], meta=None):
        Temporary.__init__(self, parent_block, string, value, valid_specifiers, meta)


class OptionalElement(Temporary):
    def __init__(self, parent_block, string, value=[], valid_specifiers=[], meta=None):
        Temporary.__init__(self, parent_block, string, value, valid_specifiers, meta)


class Variable(Identifier, Name):
    def __init__(self, parent_block, string, value=[], valid_specifiers=["static", "extern", "register"]):
        Identifier.__init__(self, parent_block, self, string, valid_specifiers)
        Name.__init__(self, parent_block, self.name)
        self.value = Evaluate(value) if value else None
        if self.parent:
            self.parent.vars.append(self)

    def __str__(self):
        return self.Proto()

    def __repr__(self):
        value = ValueStr(self.value) if self.value else None
        return "variable %s %s '%s'%s" % (str(self.specifiers), TypeStr(self.type), str(self.name),
                                          (" = " + value) if value else "")


class Parameter(Variable):
    def __init__(self, parent_block, string, value=[], valid_specifiers=[]):
        Variable.__init__(self, parent_block, string, None, valid_specifiers)
        self.def_value = Evaluate(value) if value else None
        if self.name in parent_block.retval.meta.param:
            self.meta.brief = parent_block.retval.meta.param[self.name]

    def __str__(self):
        return "%s %s" % (self.Proto(), self.name)

    def __repr__(self):
        value = ValueStr(self.def_value) if self.def_value else None
        return "param %s '%s'%s" % (TypeStr(self.type), str(self.name), (" = " + value) if value else "")


# Holds member attributes
class Method(Function):
    def __init__(self, parent_block, name, ret_type):
        Function.__init__(self, parent_block, name, ret_type,
                          ["inline", "static", "virtual", "explicit", "constexpr", "friend"])
        self.access = self.parent._current_access
        self.qualifiers = []

    def IsVirtual(self):
        return "virtual" in self.specifiers

    def IsPureVirtual(self):
        return "pure-virtual" in self.specifiers

    def IsDestructor(self):
        return isinstance(self, Destructor)

    def IsConst(self):
        return "const" in self.qualifiers

    def IsVolatile(self):
        return "volatile" in self.qualifiers

    def CVString(self):
        str = "const" if self.IsConst() else ""
        str += " " if self.IsConst() and self.IsVolatile() else ""
        str += "volatile" if self.IsVolatile() else ""
        return str

    def Proto(self):
        _str = "virtual " if self.IsVirtual() else ""
        _str += "static " if self.IsStatic() else ""
        _str += TypeStr(self.retval.type) if self.retval.type else ""
        _str += (" " if str(self.retval) else "") + self.name
        _str += "(%s)" % (", ".join([v.Proto() for v in self.vars]))
        _str += " " + self.CVString() if self.CVString() else ""
        _str += " = 0" if self.IsPureVirtual() else ""
        return _str

    def Signature(self):
        _str = "static " if self.IsStatic() else ""
        _str += TypeStr(self.retval.type) if self.retval.type else ""
        _str += (" " if str(self.retval) else "") + self.name
        _str += "(%s)" % (", ".join([str(v) for v in self.vars]))
        _str += " " + self.CVString() if self.CVString() else ""
        return _str

    def __str__(self):
        return self.Signature()

    def __repr__(self):
        cv = " " + self.CVString() if self.CVString() else ""
        return "method %s %s '%s' (%s)%s %s" % (self.access, TypeStr(self.retval.type), self.name, ", ".join([str(v) for v in self.vars]), cv, str(self.specifiers))


class Destructor(Method):
    def __init__(self, parent_block, name, ret_type):
        Method.__init__(self, parent_block, name, ret_type)

    def __repr__(self):
        return "destructor %s '%s' %s" % (self.access, self.name, str(self.specifiers))


# Holds member attributes and constants
class Attribute(Variable):
    def __init__(self, parent_block, string, value=[]):
        Variable.__init__(self, parent_block, string, value, ["static", "constexpr", "thread_local", "mutable"])
        self.access = self.parent._current_access

    def IsConst(self):
        return "const" in self.qualifiers

    def IsVolatile(self):
        return "volatile" in self.qualifiers

    def IsStatic(self):
        return "static" in self.specifiers

    def CVString(self):
        str = "const" if self.IsConst() else ""
        str += " " if self.IsConst() and self.IsVolatile() else ""
        str += "volatile" if self.IsVolatile() else ""
        return str

    def Proto(self):
        return "%s" % (TypeStr(self.type))

    def __str__(self):
        value = ValueStr(self.value) if self.value else None
        return "%s %s %s" % (self.Proto(), self.name, (" = " + value) if value else "")

    def __repr__(self):
        value = ValueStr(self.value) if self.value else None
        return "attribute %s %s %s '%s'%s" % (self.access, str(self.specifiers), TypeStr(self.type), str(self.name),
                                              (" = " + value) if value else "")


# Holds enumeration items
class Enumerator(Identifier, Name):
    def __init__(self, parent_block, name, value=None, type=["int"]):
        parent_enum = parent_block if parent_block.scoped else parent_block.parent
        Identifier.__init__(self, parent_enum, self, [type] + name, [])
        Name.__init__(self, parent_enum, self.name)
        self.parent = parent_block
        self.value = parent_block.GetValue() if value == None else Evaluate(value)
        self.auto_value = (value == None)
        if isinstance(self.value, (int)):
            self.parent.SetValue(self.value)
        self.parent.items.append(self)
        self.full_name_scoped = parent_block.full_name + "::" + self.name

    def Proto(self):
        return self.full_name

    def __str__(self):
        return "%s = %s" % (self.Proto(), ValueStr(self.value))

    def __repr__(self):
        return "enumerator %s '%s' = %s" % (TypeStr(self.type), str(self.full_name), ValueStr(self.value))


class TemplateNonTypeParameter(Variable):
    def __init__(self, parent_block, string, index, value=[]):
        Variable.__init__(self, parent_block, string, [])
        self.value = Evaluate(value) if value else None
        self.parent.arguments.append(self)
        self.index = index

    def __repr__(self):
        return "non-type parameter %s '%s' [= %s]" % (TypeStr(self.type), self.name, str(self.value))


class TemplateTypeParameter(Name):
    def __init__(self, parent_block, string, index):
        Name.__init__(self, parent_block, string)
        parent_block.parameters.append(self)
        self.index = index

    def Proto(self):
        return self.name

    def __str__(self):
        return "typename %s" % self.Proto()

    def __repr__(self):
        return "type parameter %s" % self.Proto()


class InstantiatedTemplateClass(Class):
    def __init__(self, parent_block, name, params, args):
        hash = "_" + hashlib.sha1("_".join(args).encode('utf-8')).hexdigest()[:16]
        Class.__init__(self, parent_block, name + "Instance" + hash)
        self.baseName = Name(parent_block, name)
        self.params = params
        self.args = args
        self.resolvedArgs = [Identifier(parent_block, self, [x], []) for x in args]
        self.type = self.TypeName()

    def TypeName(self):
        return "%s<%s>" % (self.baseName.full_name, ", ".join([str("".join(p.type) if isinstance(p.type, list) else p.type) for p in self.resolvedArgs]))

    def Proto(self):
        return self.TypeName()

    def __str__(self):
        s = []
        for i, _ in enumerate(self.params):
            rhs = ("".join(self.resolvedArgs[i].type) if isinstance(self.resolvedArgs[i].type, list) else self.resolvedArgs[i].type.Proto())
            s.append(self.params[i].name + " = " + rhs)
        _str = "class %s<%s>" % (self.baseName.full_name, ", ".join([str(p) for p in self.params]))
        _str += " [with %s]" % (", ".join(s))
        return _str

    def __repr__(self):
        s = []
        for i, _ in enumerate(self.params):
            s.append(self.params[i].name + " = " + str(self.args[i]))
        return "%s [instance of %s [with %s]]" % (Class.__repr__(self), self.TypeName(), ", ".join(s))


class TemplateClass(Class):
    def ParseArguments(self, string):
        # This is greatly simplified!!!
        # Templates with multiple arguments that itself are template with multiple arguments will not work!!!
        if string.count('<') != string.count('>') and string.count('<') > 0:
            raise ParserError("unbalanced template angle brackets in <%s>" % string)
        params = [x.strip() for x in string[string.find('<')+1:string.rfind('>')-1].strip().split(',')]
        return params


    def __init__(self, parent_block, name, params):
        Class.__init__(self, parent_block, name)
        self.parameters = []
        self.arguments = []
        self.paramList = []
        paramList = self.ParseArguments(params)
        for p in paramList:
            if "typename" in p or "class" in p:
                param = TemplateTypeParameter(self, p.split()[1], index=paramList.index(p))
            else:
                param = TemplateNonTypeParameter(self, p.split(), index=paramList.index(p))
            self.paramList.append(param)

    def Instantiate(self, arguments, parent):
        def _Substitute(identifier):
            if isinstance(identifier.type, list):
                for i, v in enumerate(identifier.type):
                    if isinstance(v, TemplateTypeParameter):
                        if v.name in paramDict:
                            identifier.type[i] = strArgs[paramDict[v.name].index]
                            identifier.ResolveIdentifiers(instance)
                            break
            if (isinstance(identifier, Enumerator) or isinstance(identifier, Variable)) and identifier.value:
                for i, v in enumerate(identifier.value):
                    if isinstance(v, TemplateNonTypeParameter):
                        identifier.value[i] = strArgs[argDict[v.name].index]
                        identifier.value = Evaluate(identifier.value)
                        break

        strArgs = self.ParseArguments(arguments)
        paramDict = dict(zip([x.name for x in self.parameters], self.parameters))
        argDict = dict(zip([x.name for x in self.arguments], self.arguments))
        instance = InstantiatedTemplateClass(self.parent, self.name, self.paramList, strArgs)
        instance.ancestors = self.ancestors
        instance.specifiers = self.specifiers
        instance.is_json = self.is_json
        instance.is_custom_lookup = self.is_custom_lookup
        instance.is_auto_lookup = self.is_auto_lookup
        instance.json_version = self.json_version
        instance.json_prefix = self.json_prefix
        instance.is_extended = self.is_extended
        instance.is_collapsed = self.is_collapsed
        instance.is_compliant = self.is_compliant
        instance.is_event = self.is_event
        instance.is_iterator = self.is_iterator
        instance.meta = self.meta

        if ((self.parent.name == "Core") and (self.name == "OptionalType")):
            # take over as Optional if this is OptionalType instance
            if len(instance.args) == 1:
                instance = Optional(OptionalElement(parent, instance.args[0].split()))
                instance.meta = self.meta
            else:
                raise ParserError("Invalid template arguments to %s" % instance)

        elif ((self.parent.name == "std") and (self.name == "vector")):
            if len(instance.args) == 1:
                instance = Vector(VectorElement(parent, instance.args[0].split()))
                instance.meta = self.meta
            else:
                raise ParserError("Invalid template arguments to %s" % instance)

        else:

            for t in self.typedefs:
                newTypedef = copy.copy(t)
                newTypedef.parent = instance
                newTypedef.type = copy.copy(t.type)
                _Substitute(newTypedef)
                instance.typedefs.append(newTypedef)

            for v in self.vars:
                newAttr = copy.copy(v)
                newAttr.parent = instance
                newAttr.type = copy.copy(v.type)
                newAttr.value = copy.copy(v.value)
                _Substitute(newAttr)
                instance.vars.append(newAttr)

            for e in self.enums:
                newEnum = copy.copy(e)
                newEnum.items = []
                newEnum.parent = instance
                _Substitute(newEnum)
                for i in e.items:
                    newItem = copy.copy(i)
                    newItem.type = copy.copy(i.type)
                    newItem.value = copy.copy(i.value)
                    _Substitute(newItem)
                    newEnum.items.append(newItem)
                instance.enums.append(newEnum)

            for m in self.methods:
                newMethod = copy.copy(m)
                newMethod.vars = []
                newMethod.parent = instance
                if not isinstance(m, Destructor):
                    newMethod.retval = copy.copy(m.retval)
                    newMethod.retval.type = copy.copy(m.retval.type)
                    _Substitute(newMethod.retval)
                    for p in m.vars:
                        newVar = copy.copy(p)
                        newVar.type = copy.copy(p.type)
                        newVar.value = copy.copy(p.value)
                        _Substitute(newVar)
                        newMethod.vars.append(newVar)
                instance.methods.append(newMethod)

        return instance

    def __str__(self):
        return "template class %s<%s>" % (self.full_name, ", ".join([str(p) for p in self.paramList]))

    def __repr__(self):
        return "template %s<%s>" % (Class.__repr__(self), ", ".join([repr(p) for p in self.paramList]))


# -------------------------------------------------------------------------
# PRIVATE FUNCTIONS
# -------------------------------------------------------------------------


# Source file test into a list of tokens, removing comments and preprocessor directives.
def __Tokenize(contents,log = None):
    global current_file
    global current_line

    defines = []

    tokens = contents.splitlines()
    eoltokens = []
    line = 1
    inComment = 0
    for token in tokens:
        if token.startswith("// @_file:"):
            line = 1
            eoltokens.append(token)
        else:
            if not inComment:
                eoltokens.append("// @_line:" + str(line) + " ")

            if (len(eoltokens) > 1) and eoltokens[-2].endswith("\\"):
                del eoltokens[-1]
                eoltokens[-1] = eoltokens[-1][:-1] + token
            else:
                eoltokens.append(token)

            line += 1

            inComment += eoltokens[-1].count("/*") - eoltokens[-1].count("*/")

    contents = "\n".join(eoltokens)

    formula = (
        r"(#if 0[\S\s]*?#endif)"
        r"|(#.*)"                                                       # preprocessor
        r"|(/\*[\S\s]*?\*/)"                                            # multi-line comments
        r"|(//.*)"                                                      # single line comments
        r"|(\"[^\"]+\")"                                                # double quotes
        r"|(\'[^\']+\')"                                                # quotes
        r"|(::)|(==)|(!=)|(>=)|(<=)|(&&)|(\|\|)"                        # two-char operators
        r"|(\+\+)|(--)|(\+=)|(-=)|(/=)|(\*=)|(%=)|(^=)|(&=)|(\|=)|(~=)"
        r"|([,:;~!?=^/*%-\+&<>\{\}\(\)\[\]])"                           # single-char operators
        r"|([\r\n\t ])"                                                 # whitespace
    )

    rtokens = [s.strip() for s in re.split(formula, contents, flags=(re.MULTILINE)) if s and s.strip()]

    tokens = []

    for i, token in enumerate(rtokens):
        if (i > 1) and (i < len(rtokens) - 1):
            if rtokens[i].startswith("//") and tokens[-1].startswith("//"):
                if "@_line" in token and rtokens[i+1].startswith("//") and "@" not in rtokens[i+1]:
                    # get rid of line tags between comments
                    continue
                elif "@" not in token:
                    # join comments without any @ markers
                    tokens[-1] += " "+ token[2:].strip()
                    continue

        tokens.append(token)

    tagtokens = []

    # check for special metadata within comments
    skipmode = False
    omit_depth = 0
    for token in tokens:
        if token:
            if skipmode:
                if "@_file" in token:
                    skipmode = False
                else:
                    continue

            def __ParseParameterValue(string, tag, mandatory=True, append=True, relay=None):
                formula = (r"(\"[^\"]+\")"
                           r"|(\'[^\']+\')"
                           r"|(\*/)|(::)|(==)|(!=)|(>=)|(<=)|(&&)|(\|\|)"
                           r"|(\+\+)|(--)|(\+=)|(-=)|(/=)|(\*=)|(%=)|(^=)|(&=)|(\|=)|(~=)"
                           r"|([:;~?^/*%-\+&<>\{\}\(\)\[\]])"
                           r"|([\r\n\t ])")

                if append:
                    tagtokens.append(relay.upper() if relay else tag.upper())

                length_str = string[string.index(tag) + len(tag):]
                length_tokens = [s.strip() for s in re.split(formula, length_str, flags=re.MULTILINE) if isinstance(s, str) and len(s.strip())]
                tokens = []

                if len(length_tokens) > 0:
                    if length_tokens[0] == ':':
                        length_tokens = length_tokens[1:]

                    no_close_last = (length_tokens[0] == '(')
                    par_count = 0

                    for t in length_tokens:
                        if t == '(':
                            if tokens:
                                tokens.append(t)
                            par_count += 1
                        elif t == ')':
                            par_count -= 1
                            if par_count == 0:
                                if not no_close_last:
                                    tokens.append(t)
                                break
                            else:
                                tokens.append(t)
                        elif t == '*/' or t == "," or t[0] == '@':
                            break
                        else:
                            tokens.append(t)
                            if par_count == 0:
                                break

                    if par_count != 0:
                        raise ParserError("unmatched parenthesis in %s expression" % tag)

                if mandatory and not tokens:
                    raise ParserError("missing parameter to " + tag)

                return tokens

            if ((token[:2] == "/*") and (token.count("/*") != token.count("*/"))):
                raise ParserError("multi-line comment not closed")

            if ((token[:2] == "/*") or (token[:2] == "//")):

                def _find(word, string):
                    return re.compile(r"[ \r\n/\*]({0})([-: \r\n\*]|$)".format(word)).search(string) != None

                if _find("@stubgen", token):
                    if "@stubgen:skip" in token:
                        skipmode = True
                        log.Warn("@stubgen:skip is deprecated, use @stubgen:omit instead", ("%s(%i)" % (CurrentFile(), CurrentLine())))
                    elif "@stubgen:omit" in token:
                        tagtokens.append("@OMIT")
                    elif "@stubgen:stub" in token:
                        tagtokens.append("@STUB")
                    elif "@stubgen:include" in token:
                        pass                                   # nothing to do here
                    else:
                        raise ParserError("invalid @stubgen tag")
                if _find("@stop", token):
                    skipmode = True
                if _find("@omit", token):
                    tagtokens.append("@OMIT")
                if _find("@_omit_start", token):
                    if omit_depth == 0:
                        tagtokens.append("@OMITSTART")
                    omit_depth += 1
                if _find("@_omit_end", token):
                    assert omit_depth > 0
                    omit_depth -= 1
                    if omit_depth == 0:
                        tagtokens.append("@OMITEND")
                if _find("@stub", token):
                    tagtokens.append("@STUB")
                if _find("@in", token):
                    tagtokens.append("@IN")
                if _find("@out", token):
                    tagtokens.append("@OUT")
                if _find("@inout", token):
                    tagtokens.append("@IN")
                    tagtokens.append("@OUT")
                if _find("@index", token):
                    tagtokens.append("@INDEX")
                if _find("@property", token):
                    tagtokens.append("@PROPERTY")
                if _find("@async", token):
                    tagtokens.append("@ASYNC")
                if _find("@deprecated", token):
                    tagtokens.append("@DEPRECATED")
                if _find("@obsolete", token):
                    tagtokens.append("@OBSOLETE")
                if _find("@json:omit", token):
                    tagtokens.append("@JSON_OMIT")
                elif _find("@json", token):
                    tagtokens.append(__ParseParameterValue(token, "@json", False))
                if _find("@event", token):
                    tagtokens.append("@EVENT")
                if _find("@encode:lookup", token):
                    tagtokens.append("@ENCODE-LOOKUP")
                if _find("@encode:autolookup", token):
                    tagtokens.append("@ENCODE-AUTOLOOKUP")
                elif _find("@encode:text", token):
                    tagtokens.append("@ENCODE-TEXT")
                if _find("@statuslistener", token):
                    tagtokens.append("@STATUSLISTENER")
                if _find("@prefix", token):
                    tagtokens.append(__ParseParameterValue(token, "@prefix", False))
                if _find("@extended", token):
                    tagtokens.append("@EXTENDED")
                    log.Warn("@extended keyword is deprecated, use @uncompliant:extended instead", ("%s(%i)" % (CurrentFile(), CurrentLine())))
                if _find("@uncompliant", token):
                    if "@uncompliant:extended" in token:
                        tagtokens.append("@EXTENDED")
                    elif "@uncompliant:collapsed" in token:
                        tagtokens.append("@COLLAPSED")
                    elif "@uncompliant-extended" in token:
                        tagtokens.append("@EXTENDED")
                    elif "@uncompliant-collapsed" in token:
                        tagtokens.append("@COLLAPSED")
                    else:
                        raise ParserError("Invalid @uncompliant tag")
                if _find("@compliant", token):
                    tagtokens.append("@COMPLIANT")
                if _find("@iterator", token):
                    tagtokens.append("@ITERATOR")
                if _find("@encode:bitmask", token) or _find("@bitmask", token):
                    tagtokens.append("@BITMASK")
                if _find("@end", token):
                    tagtokens.append("@END")
                if _find("@opaque", token):
                    tagtokens.append("@OPAQUE")
                if _find("@optional", token):
                    tagtokens.append("@OPTIONAL")
                if _find("@default", token):
                    tagtokens.append(__ParseParameterValue(token, "@default"))
                if _find("@extract", token):
                    tagtokens.append("@EXTRACT")
                if _find("@sourcelocation", token):
                    tagtokens.append(__ParseParameterValue(token, "@sourcelocation"))
                if _find("@alt:deprecated", token):
                    tagtokens.append(__ParseParameterValue(token, "@alt:deprecated"))
                elif _find("@alt:obsolete", token):
                    tagtokens.append(__ParseParameterValue(token, "@alt:obsolete"))
                elif _find("@alt-deprecated", token):
                    tagtokens.append(__ParseParameterValue(token, "@alt-deprecated"))
                elif _find("@alt-obsolete", token):
                    tagtokens.append(__ParseParameterValue(token, "@alt-obsolete"))
                elif _find("@alt", token):
                    tagtokens.append(__ParseParameterValue(token, "@alt"))

                if _find("@text", token):
                    tagtokens.append(__ParseParameterValue(token, "@text"))

                if _find("@encode:base64", token):
                    tagtokens.append("@ENCODEBASE64")
                elif _find("@encode:hex", token):
                    tagtokens.append("@ENCODEHEX")
                elif _find("@encode:ip", token):
                    tagtokens.append("@ENCODEIP")
                elif _find("@encode:mac", token):
                    tagtokens.append("@ENCODEMAC")

                if _find("@length", token):
                    tagtokens.append(__ParseParameterValue(token, "@length"))
                if _find("@maxlength", token):
                    tagtokens.append(__ParseParameterValue(token, "@maxlength"))
                if _find("@restrict", token):
                    tagtokens.append(__ParseParameterValue(token, "@restrict"))
                if _find("@interface", token):
                    tagtokens.append(__ParseParameterValue(token, "@interface"))
                if _find("@define", token):
                    defines.append(__ParseParameterValue(token, "@define", False, False))

                def FindDoxyString(tag, hasParam, string, tagtokens):
                    def EndOfTag(string, start):
                        end_comment = string.find("*/", start)
                        next_tag = string.find("@", start)
                        end = None
                        if next_tag != -1 and end_comment != -1:
                            if next_tag < end_comment:
                                end = next_tag
                        elif end_comment != -1:
                            end = end_comment
                        return end

                    start = string.find(tag)
                    if (start != -1):
                        start += len(tag) + 1
                        end = EndOfTag(string, start)
                        desc = string[start:end].strip(" *\n")
                        if desc:
                            tagtokens.append(tag.upper())
                            if hasParam:
                                splitted = desc.split(" ", 1)
                                if len(splitted) > 1:
                                    tagtokens.append(splitted[0])
                                    tagtokens.append(splitted[1])
                                else:
                                    raise ParserError("not enough parameters to %s tag" % tag)

                            else:
                                tagtokens.append(desc)
                            if end != None:
                                FindDoxyString(tag, hasParam, string[end:], tagtokens)

                FindDoxyString("@brief", False, token, tagtokens)
                FindDoxyString("@details", False, token, tagtokens)
                FindDoxyString("@pre", False, token, tagtokens)
                FindDoxyString("@post", False, token, tagtokens)
                FindDoxyString("@param", True, token, tagtokens)
                FindDoxyString("@retval", True, token, tagtokens)

                if _find("@_file", token):
                    idx = token.index("@_file:") + 7
                    tagtokens.append("@FILE:" + token[idx:])
                    current_file = token[idx:]
                if _find("@_line", token):
                    idx = token.index("@_line:") + 7
                    if len(tagtokens) and not isinstance(tagtokens[-1],list) and tagtokens[-1].startswith("@LINE:"):
                        del tagtokens[-1]
                    current_line = int(token[idx:].split()[0])
                    tagtokens.append("@LINE:" + token[idx:])

            elif len(token) > 0 and token[0] != '#':
                for d in defines:
                    if d[0] == token:
                        token = " ".join(d[1:]) if len(d) > 1 else ""
                        break
                if token:
                    tagtokens.append(token)

    tagtokens.append(";") # prevent potential out-of-range errors

    return tagtokens


# -------------------------------------------------------------------------
# EXPORTED FUNCTIONS
# -------------------------------------------------------------------------

i = 0
tokens = []
line_numbers = []
files = []
current_line = 0
current_file = "undefined"


def CurrentFile():
    if i > 0 and i < len(files):
        # error during c++ parsing
        return files[i]
    else:
        # error during preprocessing
        return os.path.basename(current_file)


def CurrentLine():
    if i > 0 and i < len(line_numbers):
        # error during c++ parsing
        return line_numbers[i]
    else:
        # error during preprocessing
        return current_line


# Builds a syntax tree (data structures only) of C++ source code
def Parse(contents,log = None):
    # Start in global namespace.
    global global_namespace
    global current_file
    global tokens
    global line_numbers
    global files
    global i

    i = 0
    tokens = []
    line_numbers = []
    files = []
    line_tokens = []
    current_line = 0
    current_file = "undefined"

    # Split into tokens first
    line_tokens = __Tokenize(contents,log)

    for token in line_tokens:
        if isinstance(token, str) and token.startswith("@LINE:"):
            current_line = int(token[6:].split()[0])
        elif isinstance(token, str) and token.startswith("@FILE:"):
            current_file = token[6:]
            tokens.append("@GLOBAL")
            line_numbers.append(current_line)
            files.append(current_file)
        else:
            tokens.append(token)
            line_numbers.append(current_line)
            files.append(current_file)


    global_namespace = Namespace(None)

    current_block = [global_namespace]
    next_block = None
    last_template_def = []
    min_index = 0
    omit_mode = False
    omit_next = False
    stub_next = False
    object_next = False
    autoobject_next = False
    json_next = False
    json_version = ""
    prefix_next = False
    prefix_string = ""
    exclude_next = False
    event_next = False
    extended_next = False
    collapsed_next = False
    compliant_next = False
    iterator_next = False
    sourcelocation_next = False
    text_next = None
    in_typedef = False

    # Main loop.
    while i < len(tokens):
        # Handle special tokens
        if not isinstance(tokens[i], str):
            i += 1
            continue

        if tokens[i] == "@OMIT":
            omit_next = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@OMITSTART":
            omit_mode = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@OMITEND":
            omit_mode = False
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@STUB":
            stub_next = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@JSON":
            json_next = True
            json_version = " ".join(tokens[i+1])
            tokens[i] = ";"
            tokens[i+1] = ";"
            i += 2
        elif tokens[i] == "@ENCODE-LOOKUP":
            object_next = True
            tokens[i] = ';'
            i += 1
        elif tokens[i] == "@ENCODE-AUTOLOOKUP":
            autoobject_next = True
            tokens[i] = ';'
            i += 1
        elif tokens[i] == "@ENCODE-TEXT":
            encode_enum_next = True
            tokens[i] = ';'
            i += 1
        elif tokens[i] == "@PREFIX":
            prefix_next = True
            prefix_string = " ".join(tokens[i+1])
            tokens[i] = ";"
            tokens[i+1] = ";"
            i += 2
        elif tokens[i] == "@JSON_OMIT":
            exclude_next = True
            json_next = False
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@EVENT":
            event_next = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@TEXT":
            text_next = tokens[i + 1][0]
            #tokens[i] = ";"
            #tokens[i+1] = ";"
            i += 2
        elif tokens[i] == "@EXTENDED":
            extended_next = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@COLLAPSED":
            collapsed_next = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@COMPLIANT":
            compliant_next = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@SOURCELOCATION":
            sourcelocation_next = tokens[i + 1][0]
            tokens[i] = ";"
            tokens[i+1] = ";"
            i += 2
        elif tokens[i] == "@ITERATOR":
            iterator_next = True
            tokens[i] = ";"
            i += 1
        elif tokens[i] == "@GLOBAL":
            current_block = [global_namespace]
            next_block = None
            last_template_def = []
            min_index = 0
            omit_mode = False
            omit_next = False
            stub_next = False
            json_next = False
            object_next = False
            autoobject_next = False
            encode_enum_next = False
            json_version = ""
            prefix_next = False
            prefix_string = ""
            event_next = False
            extended_next = False
            collapsed_next = False
            compliant_next = False
            iterator_next = False
            sourcelocation_next = False
            text_next = None
            in_typedef = False
            tokens[i] = ";"
            i += 1

        # Swallow template definitions
        elif tokens[i] == "template" and tokens[i + 1] == '<':
            s = i
            i += 1
            nest = 0
            while True:
                if tokens[i] == ">":
                    if nest == 1:
                        break
                    nest -= 1
                elif tokens[i] == "<":
                    nest += 1
                i += 1
            i += 1
            last_template_def = tokens[s:i]
            min_index = i

        # Parse namespace definition...
        elif tokens[i] == "namespace":
            namespace_name = ""
            if is_valid(tokens[i + 1]): # is there a namespace name?
                namespace_name = tokens[i + 1]
                i += 1
            next_block = Namespace(current_block[-1], namespace_name)
            i += 1

        # Parse type alias...
        elif isinstance(current_block[-1], (Namespace, Class)) and tokens[i] == "typedef":
            if json_next or event_next or omit_next or stub_next or exclude_next:
                raise ParserError("@json, @event and @stubgen tags invalid here")

            j = i + 1
            while tokens[j] != ";":
                j += 1
            typedef = Typedef(current_block[-1], tokens[i + 1:j])
            if event_next:
                typedef.is_event = True
                event_next = False
            if not isinstance(typedef.type, Type) and typedef.type[0] == "enum":
                # To be removed
                log.Warn("support for typedefs to anonymous enums is deprecated, (%s(%i)" % (CurrentFile(), CurrentLine()))
                in_typedef = True
                i += 1
            elif not isinstance(typedef.type, Type) and (not isinstance(typedef.type, list) or typedef.type[0] in ["struct", "class", "union"]):
                raise ParserError("typedef to anonymous struct, class or union is not supported")
            else:
                i = j + 1

        # Parse "using"...
        elif isinstance(current_block[-1], (Namespace, Class)) and tokens[i] == "using":
            if json_next or event_next or omit_next or stub_next or exclude_next:
                raise ParserError("@json, @event and @stubgen tags are invalid here")

            if tokens[i + 1] != "namespace" and tokens[i + 2] == "=":
                i += 2
                j = i + 1
                while tokens[j] != ";":
                    j += 1
                # reuse typedef class but correct name accordingly
                if not current_block[-1].omit or current_block[-1].omit_mode:
                    typedef = Typedef(current_block[-1], tokens[i + 1:j])
                    if event_next:
                        typedef.is_event = True
                        event_next = False
                    typedef_id = Name(current_block[-1], tokens[i - 1])
                    typedef.name = typedef_id.name
                    typedef.full_name = typedef_id.full_name
                i = j + 1
            elif tokens[i + 1] != "namespace" and tokens[i + 2] != "=":
                if not current_block[-1].omit:
                    raise ParserError("using-declarations are not supported")
            elif tokens[i + 1] == "namespace":
                if not current_block[-1].omit:
                    raise ParserError("'using namespace' directives are not supported")

        # Parse class definition...
        elif (tokens[i] == "class") or (tokens[i] == "struct") or (tokens[i] == "union"):
            name = tokens[i + 1]
            if tokens[i] == "union":
                new_class = Union(current_block[-1], name)
            else:
                new_class = None
                # Look up previous classes in case there already was a forward declaration of this class
                for idx, cl in enumerate(current_block[-1].classes):
                    if cl.name == name:
                        if len(cl.methods) == 0:
                            new_class = cl
                            # move the class to to bottom
                            current_block[-1].classes.append(new_class)
                            del current_block[-1].classes[idx]
                        else:
                            raise ParserError("duplicate class name: " + cl.name)
                        break

                if new_class == None:
                    if last_template_def:
                        new_class = TemplateClass(current_block[-1], name, " ".join(last_template_def))
                        last_template_def = []
                    else:
                        new_class = Class(current_block[-1], name)

            new_class._current_access = "private" if tokens[i] == "class" else "public"

            if omit_mode:
                new_class.omit = True
                new_class.omit_mode = True
            if omit_next:
                new_class.omit = True
                omit_next = False
            elif stub_next:
                new_class.stub = True
                stub_next = False
            if event_next or json_next:
                new_class.is_collapsed = collapsed_next
                new_class.is_extended = extended_next
                new_class.is_compliant = compliant_next
            if json_next:
                if object_next:
                    new_class.is_custom_lookup = True
                    object_next = False
                if autoobject_next:
                    new_class.is_auto_lookup = True
                    autoobject_next = False
                new_class.is_json = True
                new_class.json_version = json_version
                if event_next:
                    raise ParserError("@json iterface cannot also be @event")
            if prefix_next:
                new_class.json_prefix = prefix_string
            if event_next:
                new_class.is_event = True
            if iterator_next:
                new_class.is_iterator = True
            if sourcelocation_next:
                new_class.sourcelocation = sourcelocation_next
                sourcelocation_next = None
            if extended_next:
                if not json_next and not event_next:
                    raise ParserError("@uncompliant:extended used without @json")
                if collapsed_next:
                    raise ParserError("@uncompliant:extended and @uncompliant:collapsed used together");
            if collapsed_next and not json_next and not event_next:
                raise ParserError("@uncompliant:collapsed used without @json")
            if compliant_next:
                if not json_next and not event_next:
                    raise ParserError("@compliant used without @json")
                if collapsed_next or extended_next:
                    raise ParserError("@compliant and @uncompliant used together")
            if exclude_next:
                raise ParserError("@json:omit is invalid here (applies to methods only)")
            if text_next:
                new_class.meta.text = text_next
                text_next = None

            json_next = False
            object_next = False
            autoobject_next = False
            encode_enum_next = False
            json_version = ""
            prefix_next = False
            prefix_string = ""
            event_next = False
            iterator_next = False
            extended_next = False
            collapsed_next = False
            compliant_next = False

            if new_class.parent.omit:
                # Inherit omiting...
                new_class.omit = True

            if new_class.parent.omit_mode:
                new_class.omit_mode = True

            if last_template_def:
                new_class.specifiers.append(" ".join(last_template_def))
                last_template_def = []

            i += 1
            if tokens[i + 1] == "final":
                new_class.specifiers.append(tokens[i + 2])
                i += 1

            # parse class ancestors...
            # TODO: refactor!!
            if tokens[i + 1] == ':':
                i += 1
                parent_class = ""
                parent_access = new_class._current_access
                specifiers = []
                while True:
                    if tokens[i + 1] in ['{', ',']:
                        # try to find a reference to an already found type
                        parent_ref = Identifier(current_block[-1], current_block[-1], [parent_class], [])
                        new_class.ancestors.append([parent_ref.type, parent_access, specifiers])
                        parent_class = ""
                        if tokens[i + 1] == '{':
                            break
                    elif tokens[i + 1] in ["public", "private", "protected"]:
                        parent_access = tokens[i + 1]
                    elif tokens[i + 1] == "virtual":
                        specifiers.append(tokens[i + 1])
                    else:
                        parent_class += tokens[i + 1]
                    i += 1

            i += 1
            if tokens[i] == ';':
                i += 1
            else:
                next_block = new_class

        # Parse enum definition...
        elif isinstance(current_block[-1], (Namespace, Class)) and tokens[i] == "enum":
            if json_next or event_next or omit_next or stub_next or exclude_next:
                raise ParserError("@json, @event and @stubgen tags are invalid here")

            enum_name = ""
            enum_type = "int"
            enum_bitmask = False
            is_scoped = False
            i += 1
            if (tokens[i] == "class") or (tokens[i] == "struct"):
                is_scoped = True
                i += 1
            if is_valid(tokens[i]): # enum name given?
                enum_name = tokens[i]
                i += 1
            if tokens[i] == "@BITMASK":
                enum_bitmask = True
                i += 1
            if tokens[i] == ':':
                enum_type = tokens[i + 1]
                i += 2
            if tokens[i] == "@BITMASK":
                enum_bitmask = True
                i += 1

            new_enum = Enum(current_block[-1], enum_name, is_scoped, enum_type, enum_bitmask)
            if tokens[i] != ';':
                next_block = new_enum
            else:
                i += 1

            if encode_enum_next:
                new_enum.meta.decorators.append("encode:text")
                encode_enum_next = False

        # Parse class access specifier...
        elif isinstance(current_block[-1], Class) and tokens[i] == ':':
            current_block[-1]._current_access = tokens[i - 1]
            ASSERT_ISEXPECTED(current_block[-1]._current_access, ["private", "protected", "public"])
            i += 1

        # Parse function/method definition...
        elif isinstance(current_block[-1], (Namespace, Class)) and tokens[i] == "(":
            if event_next:
                raise ParserError("@event tag is invalid here")

            json_next = False
            object_next = False
            autoobject_next = False
            encode_enum_next = False
            text_next = None

            # concatenate tokens to handle operators and destructors
            j = i - 1
            k = i - 1
            if isinstance(current_block[-1], Class) and (tokens[i - 2] == "operator"):
                name = "operator" + tokens[i - 1]
                j -= 1
                k -= 1
            else:
                name = tokens[i - 1]
                if tokens[i - 2] == '~':
                    name = "~" + name #dtor
                    j -= 1
                    k -= 1

            # locate return value
            while j >= min_index and tokens[j] not in ['{', '}', ';', ':']:
                j -= 1
            ret_type = tokens[j + 1:k]

            if isinstance(current_block[-1], Class):
                if name[0] == "~":
                    method = Destructor(current_block[-1], name, ret_type)
                else:
                    method = Method(current_block[-1], name, ret_type)
            else:
                method = Function(current_block[-1], name, ret_type)

            if omit_next:
                method.omit = True
                omit_next = False
            elif stub_next:
                method.stub = True
                stub_next = False

            if isinstance(method.parent,Namespace):
                if method.parent.omit:
                    method.omit = True
                elif method.parent.stub:
                    method.stub = True

            if exclude_next:
                method.is_excluded = True
                exclude_next = False

            if last_template_def:
                method.specifiers.append(" ".join(last_template_def))
                last_template_def = []

            method.Append()

            # try to detect a function/macro call
            function_call = not ret_type and ((name != current_block[-1].name) and (name !=
                                                                                    ("~" + current_block[-1].name)))

            # parse method parameters...
            j = i
            nest = 0
            nest2 = 0
            while tokens[i] != ')':
                while tokens[j]:
                    if tokens[j] == '(':
                        nest += 1
                    elif tokens[j] == ')':
                        nest -= 1
                        if nest == 0 and nest2 == 0:
                            break
                        elif nest < 0:
                            raise ParserError("Closing parenthesis ) before opening (")
                    if tokens[j] == '<':
                        nest2 += 1
                    elif tokens[j] == '>':
                        nest2 -= 1
                        if nest2 < 0:
                            raise ParserError("Closing parenthesis > before opening <")
                    elif tokens[j] == ',' and nest == 1 and nest2 == 0:
                        break

                    j += 1

                param = tokens[i + 1:j]
                if len(param) and not (len(param) == 1 and param[0] == "void"): # remove C-style f(void)
                    value = []
                    if '=' in param:
                        assignment = param.index('=')
                        value = param[assignment + 1:]
                        param = param[0:assignment]
                    if not method.omit:
                        Parameter(method, param, value)
                i = j
                j += 1

            if nest:
                raise ParserError("unmatched parenthesis '('")
            if nest2:
                raise ParserError("unmatched parenthesis '<'")

            # parse post-declaration qualifiers/specifiers...
            if isinstance(current_block[-1], Class):
                while tokens[i] not in [';', '{', ':']:
                    # const, volatile
                    if tokens[i] in ["const", "volatile"]:
                        method.qualifiers.append(tokens[i])
                    # handle pure virtual methods
                    elif (tokens[i] == "="):
                        if tokens[i + 1] == "0" and "virtual" in method.specifiers: # mark the virtual function as pure
                            method.specifiers.append("pure-virtual")
                        elif tokens[i + 1] in ["default", "delete"]:
                            method.specifiers.append(tokens[i + 1])
                        i += 1
                    elif tokens[i] in ["override", "final", "noexcept"]:
                        method.specifiers.append(tokens[i])
                    i += 1

            if function_call: # it was apparently a function call and not declaration, so remove it
                current_block[-1].methods.pop()
            else:
                next_block = method

            if tokens[i] == ';':
                i += 1
            elif tokens[i] == ':': # skip ctor initializers
                while tokens[i] != '{':
                    i += 1

        # Handle opening a compound block or a composite type
        elif tokens[i] == '{':
            current_block.append(next_block)
            i += 1

        # Handle closing a compound block/composite type
        elif tokens[i] == '}':
            if isinstance(current_block[-1], Class):
                if (tokens[i + 1] != ';'):
                    raise ParserError("missing semicolon after a class definition; variable definitions following a class are not supported (%s)" % current_block[-1].full_name)

                if current_block[-1].omit_mode and current_block[-1].IsPOD():
                    # it was POD after all, don't remove it from import
                    current_block[-1].omit = False

            if len(current_block) > 1:
                current_block.pop()
            else:
                raise ParserError("unmatched brace '{'")

            i += 1
            next_block = Block(current_block[-1]) # new anonymous scope

        # Parse variables and member attributes
        elif isinstance(current_block[-1], (Namespace, Class)) and tokens[i] == ';':
            if json_next or event_next or omit_next or stub_next or exclude_next:
                raise ParserError("@json, @event and @stubgen tags are invalid here")

            j = i - 1
            while j >= min_index and tokens[j] not in ['{', '}', ';', ":"]:
                j -= 1

            identifier = tokens[j + 1:i]

            if identifier:
                if isinstance(current_block[-1], Class):
                    Attribute(current_block[-1], identifier)
                else:
                    Variable(current_block[-1], identifier)

            i += 1

        # Parse constants and member constants
        elif isinstance(current_block[-1], (Namespace, Class)) and (tokens[i] == '=') and (tokens[i - 1] != "operator"):
            if json_next or event_next or omit_next or stub_next or exclude_next:
                raise ParserError("@json, @event and @stubgen tags are invalid here")

            j = i - 1
            k = i + 1
            while tokens[j] not in ['{', '}', ';', ":"]:
                j -= 1
            while tokens[k] != ';':
                k += 1
            identifier = tokens[j + 1:i]
            value = tokens[i + 1:k]
            if len(identifier) != 0 and not current_block[-1].omit:
                if isinstance(current_block[-1], Class):
                    Attribute(current_block[-1], identifier, value)
                else:
                    Variable(current_block[-1], identifier, value)
            i = k + 1

        # Parse an enum block...
        elif isinstance(current_block[-1], Enum):
            enum = current_block[-1]
            j = i
            while True:
                if tokens[i] in ['}', ',', ';']:

                    # disentangle @text tag and enumerator value (if any)
                    value = None
                    entry = tokens[j:i]
                    if "@TEXT" in entry:
                        where = entry.index("@TEXT")
                        text = entry[where + 1]
                        del entry[where:where + 2]
                        entry = entry[:1] + ["@TEXT", text] + entry[1:]

                    if '=' in entry:
                        where = entry.index('=')
                        value = entry[where + 1:]
                        del entry[where:]

                    Enumerator(enum, entry, value, enum.type)
                    if tokens[i + 1] == '}':
                        i += 1 # handle ,} situation
                        break
                    elif tokens[i] == '}':
                        break
                    else:
                        j = i + 1
                i += 1

            if in_typedef:
                current_block[-2].typedefs[-1].type = Type(enum)
                in_typedef = False
        else:
            i += 1

    return global_namespace


# -------------------------------------------------------------------------


def ReadFile(source_file, includePaths, quiet=False, initial="", omit=False):
    contents = ""
    global current_file
    abs_source_file = os.path.abspath(source_file)

    if abs_source_file not in initial:
        try:
            with open(source_file) as file:
                file_content = file.read()
                pos = 0
                while True:
                    idx = file_content.find("@stubgen:include", pos)
                    if idx == -1:
                        idx = file_content.find("@insert", pos)

                    if idx != -1:
                        pos = idx + 1
                        line = file_content[idx:].split("\n", 1)[0]
                        match = re.search(r' \"(.+?)\"', line)

                        if match:
                            if match.group(1) != os.path.basename(os.path.realpath(source_file)):
                                tryPath = os.path.join(os.path.dirname(os.path.realpath(source_file)), match.group(1))

                                if os.path.isfile(tryPath):
                                    prev = current_file
                                    current_file = source_file
                                    contents += ReadFile(tryPath, includePaths, False, contents, True)
                                    current_file = prev
                                else:
                                    raise LoaderError(source_file, "can't include '%s', file does not exist" % tryPath)
                            else:
                                raise LoaderError(source_file, "can't recursively include self")
                        else:
                            match = re.search(r' <(.+?)>', line)

                            if match:
                                found = False
                                for ipath in includePaths:
                                    tryPath = os.path.join(ipath, match.group(1))

                                    if os.path.isfile(tryPath):
                                        prev = current_file
                                        current_file = source_file
                                        contents += ReadFile(tryPath, includePaths, True, contents, True)
                                        current_file = prev
                                        found = True
                                if not found:
                                    raise LoaderError(source_file, "can't find '%s' in any of the include paths" % match.group(1))
                            else:
                                raise LoaderError(source_file, "syntax error at '%s'" % source_file)
                    else:
                        break

                contents += "// @_file:%s\n" % abs_source_file

                if omit:
                    contents += "// @_omit_start\n"
                    contents += file_content
                    contents += "// @_omit_end\n"
                else:
                    contents += file_content

                return contents

        except FileNotFoundError:
            if not quiet:
                raise LoaderError(source_file, "failed to open file")

    return ""


def Locate(block_name, tree=None):
    if not tree:
        tree = global_namespace

    if block_name in tree.full_name:
        return tree

    if isinstance(tree, (Namespace, Class)):
        for n in tree.namespaces:
            found = Locate(block_name, n)
            if found:
                return found

        for n in tree.namespaces:
            found = Locate(block_name, n)
            if found:
                return found

    return None


def ParseFile(source_file, includePaths = []):
    contents = ReadFile(source_file, includePaths)
    return Parse(contents)


def ParseFiles(source_files, framework_namespace, includePaths = [], log = None):
    contents = ""
    for source_file in source_files:
        if source_file:
            quiet = (source_file[0] == "@")
            contents += ReadFile((source_file[1:] if quiet else source_file), includePaths, quiet, "")
            contents = contents.replace("__FRAMEWORK_NAMESPACE__", framework_namespace)

    return Parse(contents, log)


# -------------------------------------------------------------------------


def DumpTree(tree, ind=0):
    indent = ind * " "

    if isinstance(tree, (Namespace, Class)):
        print(indent + str(tree))

        for td in tree.typedefs:
            print(indent + 2 * " " + str(td))

        for e in tree.enums:
            print(indent + 2 * " " + str(e))
            for item in e.items:
                print(indent + 4 * " " + str(item))

    for v in tree.vars:
        print(indent + 2 * " " + str(v))

    if isinstance(tree, (Namespace, Class)):
        for m in tree.methods:
            print(indent + 2 * " " + str(m))

    if isinstance(tree, (Namespace, Class)):
        for c in tree.classes:
            DumpTree(c, ind + 2)

    if isinstance(tree, Namespace):
        for n in tree.namespaces:
            DumpTree(n, ind + 2)


# -------------------------------------------------------------------------
# entry point

if __name__ == "__main__":
    tree = ParseFiles([os.path.join(os.path.dirname(__file__), "default.h"), sys.argv[1]], "Thunder", sys.argv[2:], Log.Log("debug", True, True))
    if isinstance(tree, Namespace):
        DumpTree(tree)
    else:
        print(tree)
