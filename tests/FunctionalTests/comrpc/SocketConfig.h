/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <cstdlib>

namespace Thunder {
namespace Testing {

    // Returns the Unix socket path for COM-RPC communication.
    // Configurable via COMRPC_SOCKET_PATH env variable to allow parallel CI
    // matrix builds (e.g. 32-bit and 64-bit) to run without socket collisions.
    inline const char* SocketPath()
    {
        const char* path = ::getenv("COMRPC_SOCKET_PATH");
        return path ? path : "/tmp/comrpc_test.socket";
    }

} // namespace Testing
} // namespace Thunder
