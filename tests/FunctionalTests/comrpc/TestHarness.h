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
#include <gtest/gtest.h>

namespace Thunder {
namespace Testing {

    // Base test harness template for all test fixtures
    template <typename INTERFACE>
    class TestHarness : public ::testing::Test {
    protected:
        TestHarness()
            : _proxy(nullptr)
            , _engine()
            , _client()
        {
        }

        ~TestHarness() override = default;

        void SetUp() override
        {
            // Create InvokeServer engine (matching working test pattern)
            // Template parameters: <threads, stack, messaging, profiling, proxy pool, channel ID>
            _engine = Core::ProxyType<RPC::InvokeServerType<4, 0, 1, 1, 1>>::Create();
            ASSERT_TRUE(_engine.IsValid()) << "Failed to create InvokeServer engine";

            // Create client with explicit engine
            Core::NodeId remoteNode("/tmp/comrpc_test.socket");
            _client = Core::ProxyType<RPC::CommunicatorClient>::Create(
                remoteNode,
                Core::ProxyType<Core::IIPCServer>(_engine));
            ASSERT_TRUE(_client.IsValid()) << "Failed to create CommunicatorClient";

            // Create proxy to interface
            // Empty string means default instance of this interface type
            _proxy = _client->Open<INTERFACE>(_T(""));
            ASSERT_NE(_proxy, nullptr) << "Failed to create proxy for interface 0x"
                                       << std::hex << INTERFACE::ID;
        }

        void TearDown() override
        {
            // Release proxy
            if (_proxy != nullptr) {
                _proxy->Release();
                _proxy = nullptr;
            }

            // Close client
            if (_client.IsValid()) {
                _client->Close(1000);
                _client.Release();
            }

            // Release engine
            if (_engine.IsValid()) {
                _engine.Release();
            }
        }

        // Proxy for tests to call RPC methods
        INTERFACE* _proxy;

    private:
        Core::ProxyType<RPC::InvokeServerType<4, 0, 1, 1, 1>> _engine;
        Core::ProxyType<RPC::CommunicatorClient> _client;
    };

} // namespace Testing
} // namespace Thunder