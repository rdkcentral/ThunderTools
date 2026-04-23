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

#include <JsonRpcRegistrations.h>
#include "MockShell.h"
#include "Module.h"

namespace Thunder {
namespace JsonRpcServer {
    class JsonRpcServer : public Test::JsonRPCRegister {
    public:
        JsonRpcServer();
        JsonRpcServer(const JsonRpcServer&) = delete;
        JsonRpcServer& operator=(const JsonRpcServer&) = delete;

        ~JsonRpcServer();

    private:
        MockShell _mockShell;
    };

    extern JsonRpcServer* g_server;

    inline void Start()
    {
        if (g_server == nullptr) {
            printf("Starting JsonRpcServer...\n");
            g_server = new JsonRpcServer();
        }
    }

    inline void Stop()
    {
        if (g_server != nullptr) {
            printf("Stopping JsonRpcServer...\n");
            delete g_server;
            g_server = nullptr;
        }
    }

    inline JsonRpcServer* Instance()
    {
        return g_server;
    }
} // namespace JsonRpcServer
} // namespace Thunder