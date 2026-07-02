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

message(STATUS "Configuring COM-RPC functional tests")

add_executable(ComRpcFunctionalTests
    Module.cpp
    Main.cpp
    )

if(TEST_ASYNC)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestAsync.cpp)
endif()

if(TEST_BUFFERS)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestBuffers.cpp)
endif()

if(TEST_ENUMS)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestEnums.cpp)
endif()

if(TEST_EVENTS)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestEvents.cpp)
endif()

if(TEST_INTERFACES)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestInterfaces.cpp)
endif()

if(TEST_ITERATORS)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestIterators.cpp)
endif()

if(TEST_OPTIONALS)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestOptionals.cpp)
endif()

if(TEST_PRIMITIVES)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestPrimitives.cpp)
endif()

if(TEST_RESTRICTIONS)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestRestrictions.cpp)
endif() 

if(TEST_STRUCTS)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestStructs.cpp)
endif()

if(TEST_ENCODING_MAC)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestEncodingMac.cpp)
endif()

if(TEST_LENGTH_MODES)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestLengthModes.cpp)
endif()

if(TEST_JSON_SHAPE)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestJsonShape.cpp)
endif()

if(TEST_JSON_TEXT_KEEP)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestJsonTextKeep.cpp)
endif()

if(TEST_JSON_TEXT_CASE)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestJsonTextCase.cpp)
endif()

if(TEST_JSON_COMPLIANT)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestJsonCompliant.cpp)
endif()

if(TEST_JSON_UNCOMPLIANT_EXT)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestJsonUncompliantExtended.cpp)
endif()

if(TEST_JSON_UNCOMPLIANT_COL)
    target_sources(ComRpcFunctionalTests PRIVATE tests/TestJsonUncompliantCollapsed.cpp)
endif()

target_include_directories(ComRpcFunctionalTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}              # For interfaces/ prefix (generated code)
        ${CMAKE_CURRENT_SOURCE_DIR}/interfaces   # For direct includes
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_BINARY_DIR}/comrpc
)

target_link_libraries(ComRpcFunctionalTests
    PRIVATE
        ${NAMESPACE}Core::${NAMESPACE}Core
        ${NAMESPACE}COM::${NAMESPACE}COM
        GTest::GTest
        CompileSettingsDebug::CompileSettingsDebug
        -Wl,--whole-archive FunctionalTestCommon -Wl,--no-whole-archive
        FunctionalTestProxySources
)

add_test(NAME ComRpcFunctionalTests COMMAND ComRpcFunctionalTests)
