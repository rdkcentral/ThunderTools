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

#include "InProcessPreconditions.h"
#include <interfaces/json/JTimeSync.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<InProcessPreconditions>metadata(
        // Version
        1, 0, 0,
        // Preconditions
        { subsystem::GRAPHICS },
        // Terminations
        { subsystem::NOT_GRAPHICS },
        // Controls
        { subsystem::TIME }
        );
    }

    const string InProcessPreconditions::Initialize(VARIABLE_IS_NOT_USED PluginHost::IShell* service) {
        string message;

        ASSERT(service != nullptr);
        Exchange::JTimeSync::Register(*this, this);
        return (message);
    }

    void InProcessPreconditions::Deinitialize(VARIABLE_IS_NOT_USED PluginHost::IShell* service) {
        Exchange::JTimeSync::Unregister(*this);
    }

    string InProcessPreconditions::Information() const {
        return (string());
    }

    Core::hresult InProcessPreconditions::Register(INotification* const /* notification */) {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessPreconditions::Unregister(const INotification* const /* notification */) {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessPreconditions::Synchronize() {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessPreconditions::SyncTime(TimeInfo& /* info */ /* @out */) const {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessPreconditions::Time(Core::Time& /* time */ /* @out */) const {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessPreconditions::Time(const Core::Time& /* time */) {
        return Core::ERROR_NONE;
    }
} // Plugin
} // Thunder