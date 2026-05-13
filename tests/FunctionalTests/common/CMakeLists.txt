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

set(PROXYSTUB_GENERATOR "${PROJECT_SOURCE_DIR}/ProxyStubGenerator/StubGenerator.py" CACHE BOOL "" FORCE)
set(JSON_GENERATOR "${PROJECT_SOURCE_DIR}/JsonGenerator/JsonGenerator.py" CACHE BOOL "" FORCE)
set(CONFIG_GENERATOR_PATH "${PROJECT_SOURCE_DIR}/ConfigGenerator/" CACHE BOOL "" FORCE)

set(GENERATOR_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(JSON_RPC_OUTPUT_DIR "${GENERATOR_OUTPUT_DIR}/jsonrpc")
set(COM_RPC_OUTPUT_DIR "${GENERATOR_OUTPUT_DIR}/comrpc")

message(VERBOSE "ProxyStubGenerator: ${PROXYSTUB_GENERATOR}")
message(VERBOSE "JsonGenerator: ${JSON_GENERATOR}")
message(VERBOSE "ConfigGenerator: ${CONFIG_GENERATOR_PATH}")    

message(VERBOSE "JSON_RPC_OUTPUT_DIR: ${JSON_RPC_OUTPUT_DIR}")
message(VERBOSE "COM_RPC_OUTPUT_DIR: ${COM_RPC_OUTPUT_DIR}")    

if(NOT GENERATOR_SEARCH_PATH)
    set(GENERATOR_SEARCH_PATH ${_THUNDER_INCLUDE_PATH})
endif()

message(STATUS "Generator search path: ${GENERATOR_SEARCH_PATH}")

add_library(FunctionalTestCommon STATIC
    Module.cpp
)

target_include_directories(FunctionalTestCommon
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/interfaces
)

target_link_libraries(FunctionalTestCommon
    PUBLIC
        ${NAMESPACE}Core::${NAMESPACE}Core
        ${NAMESPACE}COM::${NAMESPACE}COM
)

add_library(FunctionalTestProxySources OBJECT)
add_library(FunctionalTestJsonSources OBJECT)


target_link_libraries(FunctionalTestProxySources
    PRIVATE
        FunctionalTestCommon
        ${NAMESPACE}Core::${NAMESPACE}Core
)

target_link_libraries(FunctionalTestJsonSources
    PRIVATE
        FunctionalTestCommon
        ${NAMESPACE}Core::${NAMESPACE}Core
)

macro(AddTestInterface TestName)
    cmake_parse_arguments(ARG "COM_RPC;JSON_RPC" "" "" ${ARGN})
    
    message(STATUS "Enabling ${TestName} test")
    
    target_sources(FunctionalTestCommon PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/implementations/Test${TestName}Impl.cpp"
    )

    if(ARG_COM_RPC)
        list(APPEND COM_RPC_INTERFACE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/interfaces/ITest${TestName}.h")
    endif()

    if(ARG_JSON_RPC)
        list(APPEND JSON_INTERFACE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/interfaces/ITest${TestName}.h")


        string(APPEND JSON_RPC_REGISTRATIONS
            "    FunctionalTest::JTest${TestName}::Register(module,\n"
            "        static_cast<FunctionalTest::ITest${TestName}*>(\n"
            "            TestImplementation::Factory::Instance().Create(FunctionalTest::ITest${TestName}::ID)));\n\n"
        )
        string(APPEND JSON_RPC_UNREGISTRATIONS
            "    FunctionalTest::JTest${TestName}::Unregister(module);\n"
        )
    endif()
endmacro()


function(GenerateHeader HeaderFileName Directory Filter)
    file(GLOB_RECURSE INCLUDES_LIST "${Directory}/${Filter}")

    set(HEADER_INCLUDES "")

    message(VERBOSE "Generated header list for ${Directory}:")
    foreach(entry ${INCLUDES_LIST})
        message(VERBOSE "  ${entry}")
        get_filename_component(filename "${entry}" NAME)
        string(APPEND HEADER_INCLUDES "#include \"${filename}\"\n")
    endforeach()

    configure_file("HeaderModel.h.in" "${HeaderFileName}"  @ONLY)

    message(STATUS "Generated header file: ${HeaderFileName}")
endfunction()



if (TEST_PRIMITIVES)
    AddTestInterface("Primitives" COM_RPC JSON_RPC) 
endif()

if (TEST_BUFFERS)
    AddTestInterface("Buffers" COM_RPC)  # COM-RPC only — known generator bug
endif()

if (TEST_OPTIONALS)
    AddTestInterface("Optionals" COM_RPC)  # COM-RPC only — known generator bug
endif()

if(TEST_ENUMS)
    AddTestInterface("Enums" COM_RPC JSON_RPC)
endif()

if (TEST_INTERFACES)
    AddTestInterface("Interfaces" COM_RPC JSON_RPC)
endif()

if (TEST_ITERATORS)
    AddTestInterface("Iterators" COM_RPC)  # COM-RPC only — no JSON mapping
endif()

if (TEST_STRUCTS)
    AddTestInterface("Structs" COM_RPC JSON_RPC)
endif()

if (TEST_RESTRICTIONS)
    AddTestInterface("Restrictions" COM_RPC JSON_RPC)
endif()

if (TEST_EVENTS)
    AddTestInterface("Events" COM_RPC)
endif()

if (TEST_ASYNC)
    AddTestInterface("Async" COM_RPC JSON_RPC)
endif()

list(LENGTH COM_RPC_INTERFACE_HEADERS NUM_COM_TESTS)
list(LENGTH JSON_INTERFACE_HEADERS NUM_JSON_TESTS)

message(STATUS "Total COM-RPC interfaces: ${NUM_COM_TESTS}")
message(STATUS "Total JSON-RPC interfaces: ${NUM_JSON_TESTS}")

if(NUM_COM_TESTS GREATER  0)
    ProxyStubGenerator(
        INPUT "${COM_RPC_INTERFACE_HEADERS}" 
        OUTDIR "${COM_RPC_OUTPUT_DIR}" 
        INCLUDE_PATH ${GENERATOR_SEARCH_PATH}
    )

    file(GLOB PROXYSTUB_SOURCES "${COM_RPC_OUTPUT_DIR}/*.cpp" PARENT_SCOPE)

    message(VERBOSE "Generated COM-RPC ProxyStub sources:")

    foreach(src ${PROXYSTUB_SOURCES})
        message(VERBOSE "  ${src}")

        target_sources(FunctionalTestProxySources PRIVATE
            "${src}"
        )   
    endforeach()

else() 
    message(STATUS "COM-RPC interfaces will be SKIPPED for all enabled tests")
endif()

if(NUM_JSON_TESTS GREATER 0)
    JsonGenerator(
        CODE
        NAMESPACE "Thunder::FunctionalTest"
        INPUT "${JSON_INTERFACE_HEADERS}"
        OUTPUT "${JSON_RPC_OUTPUT_DIR}" 
        INCLUDE_PATH "${GENERATOR_SEARCH_PATH}"
    )

    target_include_directories(FunctionalTestCommon
        INTERFACE
            ${JSON_RPC_OUTPUT_DIR}
    )

    configure_file("JsonRpcRegistrations.cpp.in" "${JSON_RPC_OUTPUT_DIR}/JsonRpcRegistrations.cpp"  @ONLY)

    message(VERBOSE "Generated JSON-RPC registration code: ${JSON_RPC_OUTPUT_DIR}/JsonRpcRegistrations.cpp")

    file(GLOB JSON_SOURCES "${JSON_RPC_OUTPUT_DIR}/*.cpp" PARENT_SCOPE)

    message(VERBOSE "Generated JSON-RPC sources:")
    
    foreach(src ${JSON_SOURCES})
        message(VERBOSE "  ${src}")

        target_sources(FunctionalTestJsonSources PRIVATE
            "${src}"
        )
    endforeach()

    GenerateHeader("${JSON_RPC_OUTPUT_DIR}/JsonGeneratedInterfaces.h" "${JSON_RPC_OUTPUT_DIR}" "json_ITest*.h")
else()
    message(STATUS "JSON-RPC interfaces will be SKIPPED for all enabled tests")
endif()
