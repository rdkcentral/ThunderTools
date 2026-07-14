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
#include "SocketConfig.h"
#include <gtest/gtest.h>

namespace Thunder {
namespace Testing {

    template <typename INTERFACE>
    class TestHarness : public ::testing::Test {
    protected:
        static void SetUpTestSuite()
        {
            _engine = Core::ProxyType<RPC::InvokeServerType<4, 0, 1, 1, 1>>::Create();
            _client = Core::ProxyType<RPC::CommunicatorClient>::Create(
                Core::NodeId(SocketPath()),
                Core::ProxyType<Core::IIPCServer>(_engine));
            _proxy = _client->Open<INTERFACE>(_T(""));
            ASSERT_NE(_proxy, nullptr) << "Failed to create proxy for interface 0x"
                                       << std::hex << INTERFACE::ID;
        }

        static void TearDownTestSuite()
        {
            if (_proxy != nullptr) {
                _proxy->Release();
                _proxy = nullptr;
            }
            _client->Close(1000);
            _client.Release();
            _engine.Release();
        }

        static INTERFACE* _proxy;

    private:
        static Core::ProxyType<RPC::InvokeServerType<4, 0, 1, 1, 1>> _engine;
        static Core::ProxyType<RPC::CommunicatorClient> _client;
    };

    template <typename INTERFACE>
    INTERFACE* TestHarness<INTERFACE>::_proxy{nullptr};

    template <typename INTERFACE>
    Core::ProxyType<RPC::InvokeServerType<4, 0, 1, 1, 1>> TestHarness<INTERFACE>::_engine;

    template <typename INTERFACE>
    Core::ProxyType<RPC::CommunicatorClient> TestHarness<INTERFACE>::_client;

} // namespace Testing
} // namespace Thunder