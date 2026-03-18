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
#include <interfaces/json/JDictionary.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<InProcessConfigPreconditions>metadata(
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

    const string InProcessConfigPreconditions::Initialize(PluginHost::IShell* service) {
        string message;

        ASSERT(service != nullptr);
        Config config;
        config.FromString(service->ConfigLine());
        TRACE(Trace::Information, (_T("This is just an example: [%s]"), config.Example.Value().c_str()));
        Exchange::JDictionary::Register(*this, this);
        return (message);
    }

    void InProcessConfigPreconditions::Deinitialize(VARIABLE_IS_NOT_USED PluginHost::IShell* service) {
        Exchange::JDictionary::Unregister(*this);
    }

    string InProcessConfigPreconditions::Information() const {
        return (string());
    }

    Core::hresult InProcessConfigPreconditions::Register(const string& /* path */, IDictionary::INotification* /* sink */) {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfigPreconditions::Unregister(const string& /* path */, const IDictionary::INotification* /* sink */) {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfigPreconditions::Get(const string& /* path */, const string& /* key */, string& /* value */ /* @out */) const {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfigPreconditions::Set(const string& /* path */, const string& /* key */, const string& /* value */) {
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfigPreconditions::PathEntries(const string& /* path */, IDictionary::IPathIterator*& /* entries */ /* @out */) const {
        return Core::ERROR_NONE;
    }
} // Plugin
} // Thunder