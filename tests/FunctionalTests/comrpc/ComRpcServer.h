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

#include "Module.h"
#include "Ids.h"

#include <ImplementationFactory.h>

namespace Thunder {
namespace ComRpcServer {

    // Returns the Unix socket path for COM-RPC communication.
    // Configurable via COMRPC_SOCKET_PATH env variable to allow parallel CI
    // matrix builds (e.g. 32-bit and 64-bit) to run without socket collisions.
    static const char* SocketPath()
    {
        const char* path = ::getenv("COMRPC_SOCKET_PATH");
        return path ? path : "/tmp/comrpc_test.socket";
    }

    // RPC::Communicator-based server using Acquire() pattern
    class ComRpcServer : public RPC::Communicator {
    public:
        ComRpcServer(const ComRpcServer&) = delete;
        ComRpcServer& operator=(const ComRpcServer&) = delete;

        ComRpcServer()
            : RPC::Communicator(
                Core::NodeId(SocketPath()),
                _T(""),           // connector
                _T("ComRpcServer")) // callsign
        {
            // Open the RPC communicator
            const uint32_t result = Open(Core::infinite);
            if (result != Core::ERROR_NONE) {
                printf("Failed to open RPC Communicator: %u\n", result);
            } else {
                printf("ComRpcServer RPC Communicator opened on %s\n", SocketPath());
            }
        }

        ~ComRpcServer()
        {
            // Close the communicator
            Close(Core::infinite);
        }

    private:
        // Override Acquire() to create implementations on-demand
        void* Acquire(VARIABLE_IS_NOT_USED const string& className, const uint32_t interfaceId, VARIABLE_IS_NOT_USED const uint32_t versionId) override
        {
            return TestImplementation::Factory::Instance().Create(interfaceId);
        }
    };

    // Global server instance management
    static ComRpcServer* g_server = nullptr;

    inline void Start()
    {
        if (g_server == nullptr) {
            printf("Starting ComRpcServer...\n");
            g_server = new ComRpcServer();
        }
    }

    inline void Stop()
    {
        if (g_server != nullptr) {
            printf("Stopping ComRpcServer...\n");
            delete g_server;
            g_server = nullptr;
        }
    }

    inline ComRpcServer* Instance()
    {
        return g_server;
    }

} // namespace ComRpcServer
} // namespace Thunder
