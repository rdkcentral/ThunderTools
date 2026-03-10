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

#include "InProcessConfigPreconditions.h"
#include <interfaces/json/JVolumeControl.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<InProcessConfigPreconditions> metadata(
        // Version
        1, 0, 0,
        // Preconditions
        { subsystem::GRAPHICS , subsystem::NOT_GRAPHICS , subsystem::TIME },
        // Terminations
        {},
        // Controls
        {}
        );
    }

    const string InProcessConfigPreconditions::Initialize(PluginHost::IShell* service) {
        string message;

        ASSERT(service != nullptr);
        PluginConfig config;
        config.FromString(service->ConfigLine());
        TRACE(Trace::Information, (_T("This is just an example: [%s]"), config.Example.Value().c_str()));
        Exchange::JVolumeControl::Register(*this, this);
        return (message);
    }

    void InProcessConfigPreconditions::Deinitialize(VARIABLE_IS_NOT_USED PluginHost::IShell* service) {
        Exchange::JVolumeControl::Unregister(*this);
    }

    string InProcessConfigPreconditions::Information() const {
        return (string());
    }

    void InProcessConfigPreconditions::Register(Exchange::IVolumeControl::INotification* notification) {
        ASSERT(notification != nullptr);

        _adminLock.Lock();
        auto item = std::find(_volumecontrolNotification.begin(), _volumecontrolNotification.end(), notification);
        ASSERT(item == _volumecontrolNotification.end());

        if (item == _volumecontrolNotification.end()) {
            notification->AddRef();
            _volumecontrolNotification.push_back(notification);
        }

        _adminLock.Unlock();
    }
    void InProcessConfigPreconditions::Unregister(const Exchange::IVolumeControl::INotification* notification) {
        ASSERT(notification != nullptr);

        _adminLock.Lock();
        auto item = std::find(_volumecontrolNotification.begin(), _volumecontrolNotification.end(), notification);
        ASSERT(item != _volumecontrolNotification.end());

        if (item != _volumecontrolNotification.end()) {
            _volumecontrolNotification.erase(item);
            notification->Release();
        }
        _adminLock.Unlock();
    }
    uint32_t InProcessConfigPreconditions::Muted(const bool /* muted */) {
        return Core::ERROR_NONE;
    }
    uint32_t InProcessConfigPreconditions::Muted(bool& /* muted */ /* @out */) const {
        return Core::ERROR_NONE;
    }
    uint32_t InProcessConfigPreconditions::Volume(const uint8_t /* volume */) {
        return Core::ERROR_NONE;
    }
    uint32_t InProcessConfigPreconditions::Volume(uint8_t& /* volume */ /* @out */) const {
        return Core::ERROR_NONE;
    }

    void InProcessConfigPreconditions::NotifyVolume(const uint8_t volume) const {
        _adminLock.Lock();
        for (auto* notification : _volumecontrolNotification) {
            notification->Volume(volume);
        }
        _adminLock.Unlock();
    }

    void InProcessConfigPreconditions::NotifyMuted(const bool muted) const {
        _adminLock.Lock();
        for (auto* notification : _volumecontrolNotification) {
            notification->Muted(muted);
        }
        _adminLock.Unlock();
    }
} // Plugin
} // Thunder