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

message(STATUS "Configuring JSON-RPC functional tests")

add_executable(JsonRpcFunctionalTests
    Module.cpp
    JsonRpcServer.cpp
    Main.cpp
)

target_include_directories(JsonRpcFunctionalTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

if(TEST_ENUMS)
    target_sources(JsonRpcFunctionalTests PRIVATE tests/TestEnumsJsonRpc.cpp)
endif() 

if(TEST_PRIMITIVES)
    target_sources(JsonRpcFunctionalTests PRIVATE tests/TestPrimitivesJsonRpc.cpp)
endif()

if(TEST_STRUCTS)
    target_sources(JsonRpcFunctionalTests PRIVATE tests/TestStructsJsonRpc.cpp)
endif()

if(TEST_RESTRICTIONS)
    target_sources(JsonRpcFunctionalTests PRIVATE tests/TestRestrictionsJsonRpc.cpp)
endif()

if(TEST_ENCODING_MAC)
    target_sources(JsonRpcFunctionalTests PRIVATE tests/TestEncodingMacJsonRpc.cpp)
endif()

if(TEST_JSON_SHAPE)
    target_sources(JsonRpcFunctionalTests PRIVATE tests/TestJsonShapeJsonRpc.cpp)
endif()

if(TEST_JSON_FORMATTING)
    target_sources(JsonRpcFunctionalTests PRIVATE tests/TestJsonFormattingJsonRpc.cpp)
endif()

# TEST_LENGTH_MODES is COM-RPC only — @length:return uses uint16_t return type which JsonGenerator does not support

target_link_libraries(JsonRpcFunctionalTests
    PRIVATE
        thunder_test_support
        ${NAMESPACE}Core::${NAMESPACE}Core
        ${NAMESPACE}COM::${NAMESPACE}COM
        ${NAMESPACE}WebSocket::${NAMESPACE}WebSocket
        ${NAMESPACE}Cryptalgo::${NAMESPACE}Cryptalgo
        ${NAMESPACE}Plugins::${NAMESPACE}Plugins
        GTest::GTest
        CompileSettingsDebug::CompileSettingsDebug
        -Wl,--whole-archive FunctionalTestCommon -Wl,--no-whole-archive
        FunctionalTestJsonSources
)

add_test(NAME JsonRpcFunctionalTests COMMAND JsonRpcFunctionalTests)
