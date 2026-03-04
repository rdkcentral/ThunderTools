# If not stated otherwise in this file or this component's license file the
# following copyright and licenses apply:
#
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
# limitations under the License

set(THUNDER_VERSION "master" CACHE STRING "Thunder git tag/branch/commit to use")

include(FetchContent)

FetchContent_Declare(Thunder
    GIT_REPOSITORY https://github.com/rdkcentral/Thunder.git
    GIT_TAG ${THUNDER_VERSION}
)

# Thunder as static libs
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

# Build configuration
set(COM ON CACHE BOOL "" FORCE)
set(CORE ON CACHE BOOL "" FORCE)
set(MESSAGING ON CACHE BOOL "" FORCE)
set(EXECUTABLE OFF CACHE BOOL "" FORCE)
set(PROCESS OFF CACHE BOOL "" FORCE)
set(SECURE_SOCKET OFF CACHE BOOL "" FORCE)

if (INCLUDE_JSON_RPC_INTERFACES)
    set(CRYPTALGO ON CACHE BOOL "" FORCE)
    set(PLUGINS ON CACHE BOOL "" FORCE)
    set(WEBSOCKET ON CACHE BOOL "" FORCE)
else()
    set(CRYPTALGO OFF CACHE BOOL "" FORCE)
    set(PLUGINS OFF CACHE BOOL "" FORCE)
    set(WEBSOCKET OFF CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(Thunder)

set(_THUNDER_INCLUDE_PATH "${thunder_SOURCE_DIR}/Source" PARENT_SCOPE)