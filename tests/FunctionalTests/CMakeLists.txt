# Copyright 2026 Metrological
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

option(ENABLE_COM_RPC_TESTS "Enable COM-RPC functional tests" ON)
option(ENABLE_JSON_RPC_TESTS "Enable JSON-RPC functional tests" ON)

option(TEST_ASYNC        "Enable async pattern tests"           OFF) 
option(TEST_BUFFERS      "Enable buffer annotations tests"      ON)
option(TEST_ENUMS        "Enable enum types tests"              ON)
option(TEST_EVENTS       "Enable event callbacks tests"         ON)
option(TEST_INTERFACES   "Enable interface passing tests"       OFF)
option(TEST_ITERATORS    "Enable iterator pattern tests"        ON) 
option(TEST_OPTIONALS    "Enable optional parameters tests"     ON)
option(TEST_PRIMITIVES   "Enable primitive types tests"         ON)
option(TEST_RESTRICTIONS "Enable restrict annotation tests"     ON) 
option(TEST_STRUCTS      "Enable POD struct tests"              ON)
option(TEST_ENCODING_MAC         "Enable @encode:mac annotation tests"           ON)
option(TEST_LENGTH_MODES         "Enable @length:void/@length:return tests"      ON)
option(TEST_JSON_SHAPE           "Enable @wrapped/@extract shape tests"          ON)
option(TEST_JSON_TEXT_KEEP       "Enable @text:keep naming tests"                ON)
option(TEST_JSON_TEXT_CASE       "Enable @text:legacy case convention tests"     ON)
option(TEST_JSON_COMPLIANT       "Enable @compliant format tests"                ON)
option(TEST_JSON_UNCOMPLIANT_EXT "Enable @uncompliant:extended format tests"     ON)
option(TEST_JSON_UNCOMPLIANT_COL "Enable @uncompliant:collapsed format tests"    ON)
option(TEST_ANNOTATIONS           "Enable comprehensive annotation coverage tests" ON)
option(TEST_EXTENDED_FORMAT      "Enable @extended format semantics tests"        ON)

set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}" CACHE BOOL "" FORCE)

enable_testing()

add_subdirectory(external/googletest)
add_subdirectory(external/thunder)

add_subdirectory(common)

if(ENABLE_COM_RPC_TESTS)
    add_subdirectory(comrpc )
endif()

if(ENABLE_JSON_RPC_TESTS)
    add_subdirectory(jsonrpc)
endif()
