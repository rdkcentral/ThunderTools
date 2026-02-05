# If not stated otherwise in this file or this component's LICENSE file the 
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

cmake_minimum_required(VERSION 3.15)

project(Generators)

include(GNUInstallDirs)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../src/bridge")
    set(NAMESPACE bridge)
else()
    set(NAMESPACE Thunder)
endif()

set(GENERATOR_INSTALL_PATH "${CMAKE_INSTALL_INCLUDEDIR}/${NAMESPACE}" CACHE PATH "Location to install the generators.")
set(GENERATOR_MODULE_INSTALL_PATH "${GENERATOR_INSTALL_PATH}/Modules" CACHE INTERNAL "Location where to install the generator cmake modules")

option(JSON_GENERATOR_ENABLE_STATS "Globally enable JSON-RPC stats" OFF)
option(PROXYSTUB_GENERATOR_ENABLE_SECURITY "Globally enable security checks in proxystubs" OFF)
option(PROXYSTUB_GENERATOR_ENABLE_COHERENCY "Globally enable frame coherency checks in proxystubs" OFF)

message(VERBOSE  "GENERATOR_MODULE_INSTALL_PATH: ${GENERATOR_MODULE_INSTALL_PATH}")
message(VERBOSE  "GENERATOR_INSTALL_PATH: ${GENERATOR_INSTALL_PATH}")

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindProxyStubGenerator.cmake.in"
                "${CMAKE_CURRENT_BINARY_DIR}/FindProxyStubGenerator.cmake"
                @ONLY
)

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindJsonGenerator.cmake.in"
                "${CMAKE_CURRENT_BINARY_DIR}/FindJsonGenerator.cmake"
                @ONLY
)

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindConfigGenerator.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/FindConfigGenerator.cmake"
                @ONLY
)

install(FILES 
        "${CMAKE_CURRENT_BINARY_DIR}/FindProxyStubGenerator.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/FindJsonGenerator.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/FindConfigGenerator.cmake"
    DESTINATION ${GENERATOR_MODULE_INSTALL_PATH}
    COMPONENT ${NAMESPACE}_Development
)

install(DIRECTORY 
        "${CMAKE_CURRENT_SOURCE_DIR}/ProxyStubGenerator"
        "${CMAKE_CURRENT_SOURCE_DIR}/JsonGenerator"
        "${CMAKE_CURRENT_SOURCE_DIR}/ConfigGenerator"
    DESTINATION ${GENERATOR_INSTALL_PATH}
    FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    COMPONENT ${NAMESPACE}_Runtime
)
