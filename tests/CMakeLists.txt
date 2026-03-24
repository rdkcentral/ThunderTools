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

cmake_minimum_required(VERSION 3.15)

# ============================================================================
# Test Suite Options 
# ============================================================================

option(INCLUDE_JSON_RPC_INTERFACES "Enable JSON-RPC coverage in the test" OFF)
option(BUILD_JSON_RPC_TESTS "Build separate JSON-RPC functional tests executable" OFF)

# If building JSON-RPC tests, automatically enable JSON-RPC interface generation
if(BUILD_JSON_RPC_TESTS)
    set(INCLUDE_JSON_RPC_INTERFACES ON)
    message(STATUS "BUILD_JSON_RPC_TESTS enabled - automatically enabling INCLUDE_JSON_RPC_INTERFACES")
endif()

option(TEST_PRIMITIVES   "Enable primitive types tests"         ON)
option(TEST_BUFFERS      "Enable buffer annotations tests"      ON)
option(TEST_OPTIONALS    "Enable optional parameters tests"     ON)
option(TEST_RESTRICTIONS "Enable restrict annotation tests"     ON) 
option(TEST_INTERFACES   "Enable interface passing tests"       OFF)
option(TEST_ENUMS        "Enable enum types tests"              ON)
option(TEST_STRUCTS      "Enable POD struct tests"              ON)
option(TEST_ITERATORS    "Enable iterator pattern tests"        ON) 
option(TEST_EVENTS       "Enable event callbacks tests"         ON)
option(TEST_ASYNC        "Enable async pattern tests"           OFF) 

# ============================================================================

# Global C++ standard settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}" CACHE BOOL "" FORCE)

set(PROXYSTUB_GENERATOR "${PROJECT_SOURCE_DIR}/ProxyStubGenerator/StubGenerator.py" CACHE BOOL "" FORCE)
set(JSON_GENERATOR "${PROJECT_SOURCE_DIR}/JsonGenerator/JsonGenerator.py" CACHE BOOL "" FORCE)
set(CONFIG_GENERATOR_PATH "${PROJECT_SOURCE_DIR}/ConfigGenerator/" CACHE BOOL "" FORCE)

message(VERBOSE "PROXYSTUB_GENERATOR ${PROXYSTUB_GENERATOR}")

add_subdirectory(external/googletest)
add_subdirectory(external/thunder)

set(INTERFACE_HEADERS "")
set(IMPLEMENTATION_SOURCES "")
set(TEST_SOURCES "")
set(COM_RPC_PROXY_STUB_SOURCES "")
set(JSON_RPC_ENUM_SOURCES "")

set(GENERATOR_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(JSON_RPC_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/jsonrpc")
set(COM_RPC_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/comrpc")

if(NOT GENERATOR_SEARCH_PATH)
    set(GENERATOR_SEARCH_PATH ${_THUNDER_INCLUDE_PATH})
endif()

# ============================================================================
# Helper macro to add a test interface
# ============================================================================

macro(AddTestInterface TestName)
    list(APPEND IMPLEMENTATION_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/implementations/Test${TestName}Impl.cpp
    )

    list(APPEND TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/tests/Test${TestName}.cpp
    )

    list(APPEND COM_RPC_INTERFACE_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/interfaces/ITest${TestName}.h
    )

    list(APPEND COM_RPC_PROXY_STUB_SOURCES 
        ${COM_RPC_OUTPUT_DIR}/ProxyStubs_Test${TestName}.cpp
    )

    # Note: JSON-RPC generation is handled separately for each interface
    # because some interfaces (like Buffers) have known generator issues
endmacro()

# Helper macro to also add interface to JSON-RPC generation
macro(AddTestInterfaceWithJsonRpc TestName)
    AddTestInterface(${TestName})

    if (INCLUDE_JSON_RPC_INTERFACES)
        list(APPEND JSON_INTERFACE_HEADERS
            ${CMAKE_CURRENT_SOURCE_DIR}/interfaces/ITest${TestName}.h
        )
        
        if(EXISTS "${JSON_RPC_OUTPUT_DIR}/json_ITest${TestName}.h")
        list(APPEND JSON_RPC_INTERFACES_GENERATED
            "${JSON_RPC_OUTPUT_DIR}/json_ITest${TestName}.h"
        )
        endif()
    endif()
endmacro()

# Helper macro for interfaces that have enums (generates JsonEnum_*.cpp)
macro(AddTestInterfaceWithJsonRpcAndEnums TestName)
    AddTestInterfaceWithJsonRpc(${TestName})

    if (INCLUDE_JSON_RPC_INTERFACES)
        # This interface has enums, so JsonGenerator will create JsonEnum file
        list(APPEND JSON_RPC_ENUM_SOURCES
            ${JSON_RPC_OUTPUT_DIR}/JsonEnum_Test${TestName}.cpp
        )
    endif()
endmacro()

# ============================================================================
# Add test interfaces based on enabled options
# ============================================================================

if (TEST_PRIMITIVES)
    message(STATUS "Enabling Primitives tests")
    AddTestInterfaceWithJsonRpc("Primitives")
endif()

if (TEST_BUFFERS)
    message(STATUS "Enabling Buffers tests")
    AddTestInterface("Buffers")  # Excluded from JSON-RPC due to known generator bug
    if (INCLUDE_JSON_RPC_INTERFACES)
        message(STATUS "  NOTE: Buffers excluded from JSON-RPC generation (known generator issue)")
    endif()
endif()

if (TEST_OPTIONALS)
    message(STATUS "Enabling Optionals tests")
    AddTestInterface("Optionals")  # Excluded from JSON-RPC due to known generator bug
    if (INCLUDE_JSON_RPC_INTERFACES)
        message(STATUS "  NOTE: Optionals excluded from JSON-RPC generation (known generator issue)")
    endif()
endif()

if(TEST_ENUMS)
    message(STATUS "Enabling Enums tests")
    AddTestInterfaceWithJsonRpcAndEnums("Enums")
endif()

if (TEST_INTERFACES)
    message(STATUS "Enabling Interfaces tests")
    AddTestInterfaceWithJsonRpc("Interfaces")
endif()

if (TEST_ITERATORS)
    message(STATUS "Enabling Iterators tests")
    AddTestInterface("Iterators")  # COM-RPC only - no JSON-RPC mapping
endif()

if (TEST_STRUCTS)
    message(STATUS "Enabling Structs tests")
    AddTestInterfaceWithJsonRpc("Structs")
endif()

if (TEST_RESTRICTIONS)
    message(STATUS "Enabling Restrictions tests")
    AddTestInterfaceWithJsonRpc("Restrictions")
endif()

if (TEST_EVENTS)
    message(STATUS "Enabling Events tests")
    AddTestInterfaceWithJsonRpc("Events")
endif()

if (TEST_ASYNC)
    message(STATUS "Enabling Async tests")
    AddTestInterfaceWithJsonRpc("Async")
endif()

# Verify at least one test is enabled
list(LENGTH COM_RPC_INTERFACE_HEADERS NUM_COM_TESTS)
list(LENGTH JSON_INTERFACE_HEADERS NUM_JSON_TESTS)

if(NUM_COM_TESTS EQUAL 0 AND NUM_JSON_TESTS EQUAL 0)
    message(FATAL_ERROR "No tests enabled! Enable at least one TEST_* option")
endif()

message(STATUS "Total test interfaces enabled: ${NUM_COM_TESTS} COM RPC, ${NUM_JSON_TESTS} JSON RPC")

find_package(ProxyStubGenerator)

# ============================================================================
# Generate ProxyStubs from interfaces
# ============================================================================
ProxyStubGenerator(
    INPUT "${COM_RPC_INTERFACE_HEADERS}" 
    OUTDIR "${COM_RPC_OUTPUT_DIR}" 
    INCLUDE_PATH ${GENERATOR_SEARCH_PATH}
)

# ============================================================================
# Generate JSON-RPC from interfaces
# ============================================================================

if(INCLUDE_JSON_RPC_INTERFACES)
    JsonGenerator(
        CODE
        NAMESPACE "Thunder::FunctionalTest"
        INPUT "${JSON_INTERFACE_HEADERS}"
        OUTPUT "${JSON_RPC_OUTPUT_DIR}" 
        INCLUDE_PATH "${GENERATOR_SEARCH_PATH}"
    )
else()
    message(STATUS "JSON-RPC interfaces will be SKIPPED for all enabled tests")
endif()

# ============================================================================
# Test executable 
# ============================================================================

add_executable(ProxyStubFunctionalTests
    src/Module.cpp
    src/Main.cpp
    ${IMPLEMENTATION_SOURCES}
    ${TEST_SOURCES}  
    ${COM_RPC_PROXY_STUB_SOURCES}
)

target_include_directories(ProxyStubFunctionalTests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}              # For interfaces/ prefix (generated code)
        ${CMAKE_CURRENT_SOURCE_DIR}/interfaces   # For direct includes
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_BINARY_DIR}/comrpc
)

target_link_libraries(ProxyStubFunctionalTests
    PRIVATE
        ${NAMESPACE}Core::${NAMESPACE}Core
        ${NAMESPACE}COM::${NAMESPACE}COM
        GTest::GTest
        CompileSettingsDebug::CompileSettingsDebug
)

if (INCLUDE_JSON_RPC_INTERFACES)
    message(STATUS "JSON-RPC interfaces will be generated for all enabled tests")

    foreach(entry ${JSON_RPC_INTERFACES_GENERATED})
        get_filename_component(filename "${entry}" NAME)
        string(APPEND JSON_FILE_INCLUDES "#include \"${filename}\"\n")
    endforeach()

    configure_file("src/JsonRpcInterfaces.h.in" "${CMAKE_CURRENT_BINARY_DIR}/jsonrpc/JsonRpcInterfaces.h"  @ONLY)

    target_sources(ProxyStubFunctionalTests
        PRIVATE
            ${JSON_RPC_ENUM_SOURCES}
    )

    target_compile_definitions(ProxyStubFunctionalTests
        PRIVATE
            INCLUDE_JSON_RPC_INTERFACES
    )

    target_include_directories(ProxyStubFunctionalTests
        PRIVATE
            ${CMAKE_CURRENT_BINARY_DIR}/jsonrpc
    )

    target_link_libraries(ProxyStubFunctionalTests
        PRIVATE
            ${NAMESPACE}WebSocket::${NAMESPACE}WebSocket
            ${NAMESPACE}Cryptalgo::${NAMESPACE}Cryptalgo
            ${NAMESPACE}Plugins::${NAMESPACE}Plugins
    )
endif()

install(
    TARGETS ProxyStubFunctionalTests
    DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT ${NAMESPACE}_Test)

# ============================================================================
# JSON-RPC Test executable (separate executable for JSON-RPC testing)
# ============================================================================

if(BUILD_JSON_RPC_TESTS)
    message(STATUS "Building separate JSON-RPC functional tests executable")

    # Define JSON-RPC test sources
    set(JSON_RPC_TEST_SOURCES "")

    if (TEST_PRIMITIVES)
        list(APPEND JSON_RPC_TEST_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/src/tests/TestPrimitivesJsonRpc.cpp
        )
    endif()

    if (TEST_ENUMS)
        list(APPEND JSON_RPC_TEST_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/src/tests/TestEnumsJsonRpc.cpp
        )
    endif()

    if (TEST_STRUCTS)
        list(APPEND JSON_RPC_TEST_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/src/tests/TestStructsJsonRpc.cpp
        )
    endif()

    if (TEST_RESTRICTIONS)
        list(APPEND JSON_RPC_TEST_SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/src/tests/TestRestrictionsJsonRpc.cpp
        )
    endif()

    # Note: Events, Async, and Interfaces tests not implemented (require IHandler/async patterns)
    # Note: Iterators excluded - no clean JSON-RPC mapping for RPC::IStringIterator/IValueIterator

    # Note: Buffers and Optionals intentionally excluded due to known JsonGenerator bugs

    # Create JSON-RPC test executable
    add_executable(JsonRpcFunctionalTests
        src/Module.cpp
        src/Main.cpp
        ${IMPLEMENTATION_SOURCES}        # Reuse implementations
        ${JSON_RPC_TEST_SOURCES}         # JSON-RPC specific tests
        ${JSON_RPC_ENUM_SOURCES}         # Generated enum converters (from AddTestInterfaceWithJsonRpc)
    )

    target_include_directories(JsonRpcFunctionalTests
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}              # For interfaces/ prefix (generated code)
            ${CMAKE_CURRENT_SOURCE_DIR}/interfaces   # For direct includes
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            ${CMAKE_CURRENT_BINARY_DIR}/jsonrpc
    )

    target_link_libraries(JsonRpcFunctionalTests
        PRIVATE
            ${NAMESPACE}Core::${NAMESPACE}Core
            ${NAMESPACE}WebSocket::${NAMESPACE}WebSocket
            ${NAMESPACE}Cryptalgo::${NAMESPACE}Cryptalgo
            ${NAMESPACE}Plugins::${NAMESPACE}Plugins
            GTest::GTest
            CompileSettingsDebug::CompileSettingsDebug
    )

    target_compile_definitions(JsonRpcFunctionalTests
        PRIVATE
            BUILD_JSON_RPC_TESTS
            INCLUDE_JSON_RPC_INTERFACES
    )

    install(
        TARGETS JsonRpcFunctionalTests
        DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT ${NAMESPACE}_Test)

    add_test(NAME JsonRpcFunctionalTests COMMAND JsonRpcFunctionalTests)

    message(STATUS "JsonRpcFunctionalTests executable configured")
endif()

# ============================================================================
# Enable testing
# ============================================================================

enable_testing()
add_test(NAME ProxyStubFunctionalTests COMMAND ProxyStubFunctionalTests)
