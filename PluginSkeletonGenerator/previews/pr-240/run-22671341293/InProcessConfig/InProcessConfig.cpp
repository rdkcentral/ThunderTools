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

#include "InProcessConfig.h"
#include <interfaces/json/JPower.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<InProcessConfig> metadata(
        // Version
        1, 0, 0,
        // Preconditions
        {},
        // Terminations
        {},
        // Controls
        {}
        );
    }

    const string InProcessConfig::Initialize(PluginHost::IShell* service) {
        string message;

        ASSERT(service != nullptr);
        Config config;
        config.FromString(service->ConfigLine());
        TRACE(Trace::Information, (_T("This is just an example: [%s]"), config.Example.Value().c_str()));
        Exchange::JPower::Register(*this, this);
        return (message);
    }

    void InProcessConfig::Deinitialize(VARIABLE_IS_NOT_USED PluginHost::IShell* service) {
        Exchange::JPower::Unregister(*this);
    }

    string InProcessConfig::Information() const {
        return (string());
    }

    Core::hresult InProcessConfig::Register(Exchange::IPower::INotification* notification) {
        ASSERT(notification != nullptr);

        _adminLock.Lock();
        auto item = std::find(_powerNotification.begin(), _powerNotification.end(), notification);
        ASSERT(item == _powerNotification.end());

        if (item == _powerNotification.end()) {
            notification->AddRef();
            _powerNotification.push_back(notification);
        }

        _adminLock.Unlock();
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfig::Unregister(const Exchange::IPower::INotification* notification) {
        ASSERT(notification != nullptr);

        _adminLock.Lock();
        auto item = std::find(_powerNotification.begin(), _powerNotification.end(), notification);
        ASSERT(item != _powerNotification.end());

        if (item != _powerNotification.end()) {
            _powerNotification.erase(item);
            notification->Release();
        }
        _adminLock.Unlock();
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfig::GetState(PCState& /* state */ /* @out */) const {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfig::SetState(const PCState& /* state */, const uint32_t /* waitTime */) {
        return Core::ERROR_NONE;
    }
    void InProcessConfig::PowerKey() {
    }

    void InProcessConfig::NotifyStateChange(const PCState origin, const PCState destination, const PCPhase phase) const {
        _adminLock.Lock();
        for (auto* notification : _powerNotification) {
            notification->StateChange(origin, destination, phase);
        }
        _adminLock.Unlock();
    }
} // Plugin
} // Thunder