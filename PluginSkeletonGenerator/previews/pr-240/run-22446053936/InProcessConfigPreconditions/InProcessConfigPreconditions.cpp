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
#include <NOT_GRAPHICS/json/JDictionary.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<InProcessConfigPreconditions> metadata(
        // Version
        1, 0, 0,
        // Preconditions
        {},
        // Terminations
        {},
        // Controls
        { subsystem::GRAPHICS }
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

    Core::hresult InProcessConfigPreconditions::Register(Exchange::IDictionary::INotification* notification) {
        ASSERT(notification != nullptr);

        _adminLock.Lock();
        auto item = std::find(_dictionaryNotification.begin(), _dictionaryNotification.end(), notification);
        ASSERT(item == _dictionaryNotification.end());

        if (item == _dictionaryNotification.end()) {
            notification->AddRef();
            _dictionaryNotification.push_back(notification);
        }

        _adminLock.Unlock();
        return Core::ERROR_NONE;
    }
    Core::hresult InProcessConfigPreconditions::Unregister(const Exchange::IDictionary::INotification* notification) {
        ASSERT(notification != nullptr);

        _adminLock.Lock();
        auto item = std::find(_dictionaryNotification.begin(), _dictionaryNotification.end(), notification);
        ASSERT(item != _dictionaryNotification.end());

        if (item != _dictionaryNotification.end()) {
            _dictionaryNotification.erase(item);
            notification->Release();
        }
        _adminLock.Unlock();
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

    void InProcessConfigPreconditions::NotifyModified(const string& path /* @index */, const string& key, const string& value) const {
        _adminLock.Lock();
        for (auto* notification : _dictionaryNotification) {
            notification->Modified(path, key, value);
        }
        _adminLock.Unlock();
    }
} // Plugin
} // Thunder