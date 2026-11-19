/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2026 [PLEASE ADD COPYRIGHT NAME!]
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
#include <interfaces/IPower.h>

namespace Thunder {
namespace Plugin {

    class InProcessConfig : public PluginHost::IPlugin, public PluginHost::JSONRPC, public Exchange::IPower {
    public:
        InProcessConfig(const InProcessConfig&) = delete;
        InProcessConfig& operator=(const InProcessConfig&) = delete;
        InProcessConfig(InProcessConfig&&) = delete;
        InProcessConfig& operator=(InProcessConfig&&) = delete;

        InProcessConfig()
            : PluginHost::IPlugin()
            , PluginHost::JSONRPC()
            , Exchange::IPower()
            , _adminLock()
            , _powerNotification()
        {
        }

        ~InProcessConfig() override = default;
    private:
        class PluginConfig : public Core::JSON::Container {
        public:
            PluginConfig(const PluginConfig&) = delete;
            PluginConfig& operator=(const PluginConfig&) = delete;
            PluginConfig(PluginConfig&&) = delete;
            PluginConfig& operator=(PluginConfig&&) = delete;

            PluginConfig()
                : Core::JSON::Container()
                , Example()
            {
                Add(_T("example"), &Example);
            }
            ~PluginConfig() override = default;
        public:
            Core::JSON::String Example;
        };
    public:
        // IPlugin Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;

        // IPower methods

        Core::hresult Register(Exchange::IPower::INotification* const /* sink */) override;

        Core::hresult Unregister(const Exchange::IPower::INotification* const /* sink */) override;

        Core::hresult GetState(PCState& /* state */ /* @out */) const override;

        Core::hresult SetState(const PCState& /* state */, const uint32_t /* waitTime */) override;

        void PowerKey() override;

        BEGIN_INTERFACE_MAP(InProcessConfig)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            INTERFACE_ENTRY(Exchange::IPower)
        END_INTERFACE_MAP

    private:
        using PowerNotificationContainer = std::vector<Exchange::IPower::INotification*>;

        void NotifyStateChange(const PCState /* origin */, const PCState /* destination */, const PCPhase /* phase */) const;

        mutable Core::CriticalSection _adminLock;
        PowerNotificationContainer _powerNotification;
    };
} // Plugin
} // Thunder