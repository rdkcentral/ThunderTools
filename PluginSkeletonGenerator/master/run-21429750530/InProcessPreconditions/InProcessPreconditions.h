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
#include <interfaces/ITimeSync.h>

namespace Thunder {
namespace Plugin {

    class InProcessPreconditions : public PluginHost::IPlugin, public PluginHost::JSONRPC, public Exchange::ITimeSync {
    public:
        InProcessPreconditions(const InProcessPreconditions&) = delete;
        InProcessPreconditions& operator=(const InProcessPreconditions&) = delete;
        InProcessPreconditions(InProcessPreconditions&&) = delete;
        InProcessPreconditions& operator=(InProcessPreconditions&&) = delete;

        InProcessPreconditions()
            : PluginHost::IPlugin()
            , PluginHost::JSONRPC()
            , Exchange::ITimeSync()
            , _adminLock()
            , _timesyncNotification()
        {
        }

        ~InProcessPreconditions() override = default;
    private:
    public:
        // IPlugin Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;

        // ITimeSync methods

        Core::hresult Register(INotification* const /* notification */) override;

        Core::hresult Unregister(const INotification* const /* notification */) override;

        Core::hresult Synchronize() override;

        Core::hresult SyncTime(TimeInfo& /* info */ /* @out */) const override;

        Core::hresult Time(Core::Time& /* time */ /* @out */) const override;

        Core::hresult Time(const Core::Time& /* time */) override;

        BEGIN_INTERFACE_MAP(InProcessPreconditions)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            INTERFACE_ENTRY(Exchange::ITimeSync)
        END_INTERFACE_MAP

    private:
        using TimeSyncNotificationContainer = std::vector<Exchange::ITimeSync::INotification*>;

        mutable Core::CriticalSection _adminLock;
        TimeSyncNotificationContainer _timesyncNotification;
    };
} // Plugin
} // Thunder