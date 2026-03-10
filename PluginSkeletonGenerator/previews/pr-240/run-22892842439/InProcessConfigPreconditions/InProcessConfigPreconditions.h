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
#include <interfaces/IVolumeControl.h>

namespace Thunder {
namespace Plugin {

    class InProcessConfigPreconditions : public PluginHost::IPlugin, public PluginHost::JSONRPC, public Exchange::IVolumeControl {
    public:
        InProcessConfigPreconditions(const InProcessConfigPreconditions&) = delete;
        InProcessConfigPreconditions& operator=(const InProcessConfigPreconditions&) = delete;
        InProcessConfigPreconditions(InProcessConfigPreconditions&&) = delete;
        InProcessConfigPreconditions& operator=(InProcessConfigPreconditions&&) = delete;

        InProcessConfigPreconditions()
            : PluginHost::IPlugin()
            , PluginHost::JSONRPC()
            , Exchange::IVolumeControl()
            , _adminLock()
            , _volumecontrolNotification()
        {
        }

        ~InProcessConfigPreconditions() override = default;
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

        // IVolumeControl methods

        void Register(Exchange::IVolumeControl::INotification* const /* sink */) override;

        void Unregister(const Exchange::IVolumeControl::INotification* const /* sink */) override;

        uint32_t Muted(const bool /* muted */) override;

        uint32_t Muted(bool& /* muted */ /* @out */) const override;

        uint32_t Volume(const uint8_t /* volume */) override;

        uint32_t Volume(uint8_t& /* volume */ /* @out */) const override;

        BEGIN_INTERFACE_MAP(InProcessConfigPreconditions)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            INTERFACE_ENTRY(Exchange::IVolumeControl)
        END_INTERFACE_MAP

    private:
        using VolumeControlNotificationContainer = std::vector<Exchange::IVolumeControl::INotification*>;

        void NotifyVolume(const uint8_t /* volume */) const;
        void NotifyMuted(const bool /* muted */) const;

        mutable Core::CriticalSection _adminLock;
        VolumeControlNotificationContainer _volumecontrolNotification;
    };
} // Plugin
} // Thunder