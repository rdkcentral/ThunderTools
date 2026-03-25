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
#include "JsonRpcServer.h"
#include <gtest/gtest.h>

namespace Thunder {
namespace JsonRpcTesting {

    // JSON-RPC test harness that invokes JSON-RPC methods directly via PluginHost::JSONRPC
    // Tests the generated JSON stubs by sending JSON strings and validating responses
    // 
    // All test fixtures share the same JsonRpcServer singleton and registered implementations.
    // No per-interface state isolation - tests may affect each other if implementations
    // maintain state between method calls.
    class JsonRpcTestHarness : public ::testing::Test {
    protected:
        JsonRpcTestHarness()
            : _server(nullptr)
        {
        }

        ~JsonRpcTestHarness() override = default;

        void SetUp() override
        {
            _server = JsonRpcServer::Instance();
            ASSERT_NE(_server, nullptr) << "JsonRpcServer not started";
        }

        void TearDown() override
        {
            _server = nullptr;
        }

        // Invoke a JSON-RPC method with JSON strings
        // This tests the generated JSON stubs (marshalling, dispatch, etc.)
        uint32_t CallMethod(
            const string& method, 
            const string& parameters, 
            string& response)
        {
            if (_server == nullptr) {
                ADD_FAILURE() << "JsonRpcServer is nullptr";
                return Core::ERROR_UNAVAILABLE;
            }
            
            // Thunder's JSONRPC expects format: Callsign.method
            string fullMethod = _server->Callsign() + "." + method;
            
            // Invoke through PluginHost::JSONRPC::Invoke()
            // This goes through the full JSON-RPC stack:
            // 1. Method routing
            // 2. JSON parameter unmarshalling
            // 3. C++ method call
            // 4. JSON response marshalling
            uint32_t result = _server->Invoke(
                0,          // channelId
                1,          // id
                _T(""),     // token
                fullMethod, // method name (e.g., "TestPlugin.EchoInt8")
                parameters, // JSON parameters
                response    // JSON response (output)
            );
            
            return result;
        }

        // Helper to build simple JSON parameter objects
        string MakeJsonParams(const std::map<string, string>& params) {
            string result = "{";
            bool first = true;
            for (const auto& kv : params) {
                if (!first) result += ",";
                result += "\"" + kv.first + "\":" + kv.second;
                first = false;
            }
            result += "}";
            return result;
        }

        JsonRpcServer::JsonRpcServer* _server;
    };

} // namespace JsonRpcTesting
} // namespace Thunder
