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

#include <gtest/gtest.h>
#include "ComRpcServer.h"

#ifdef BUILD_JSON_RPC_TESTS
#include "JsonRpcServer.h"

// Define global variables for JSON-RPC server
namespace Thunder {
namespace JsonRpcServer {
    JsonRpcServer* g_server = nullptr;
    Core::ProxyType<MockShell> g_shell;
    std::vector<Core::IUnknown*> g_implementations;
} // namespace JsonRpcServer
} // namespace Thunder
#endif

#if defined(INCLUDE_JSON_RPC_INTERFACES) && !defined(BUILD_JSON_RPC_TESTS)
// Include generated headers for JSON-RPC interfaces (only for COM-RPC tests)
#include <JsonRpcInterfaces.h>
#endif

using namespace Thunder;

class TestEnvironment : public ::testing::Environment {
public:
    void SetUp() override {
        // Start the RPC server
        // Implementation factories are already registered via static initialization
        ComRpcServer::Start();
        
        // Give the server a moment to fully initialize
        SleepMs(100);
    }

    void TearDown() override {
        // Stop the RPC server
        ComRpcServer::Stop();
    }
};

#ifdef BUILD_JSON_RPC_TESTS
// JSON-RPC test environment (separate executable)
class JsonRpcTestEnvironment : public ::testing::Environment {
public:
    void SetUp() override {
        // Start JSON-RPC server
        // Interfaces registered automatically via static JsonRpcRegistrar instances
        JsonRpcServer::Start();

        // Give server time to initialize
        SleepMs(100);
    }

    void TearDown() override {
        // Stop JSON-RPC server
        JsonRpcServer::Stop();
    }
};
#endif // BUILD_JSON_RPC_TESTS

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

#ifdef BUILD_JSON_RPC_TESTS
    ::testing::AddGlobalTestEnvironment(new JsonRpcTestEnvironment());
#else
    ::testing::AddGlobalTestEnvironment(new TestEnvironment());
#endif
    return RUN_ALL_TESTS();
}
