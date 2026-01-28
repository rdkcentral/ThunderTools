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
#include <interfaces/IDictionary.h>

namespace Thunder {
namespace Plugin {

    class InProcessConfigPreconditions : public PluginHost::IPlugin, public PluginHost::JSONRPC, public Exchange::IDictionary {
    public:
        InProcessConfigPreconditions(const InProcessConfigPreconditions&) = delete;
        InProcessConfigPreconditions& operator=(const InProcessConfigPreconditions&) = delete;
        InProcessConfigPreconditions(InProcessConfigPreconditions&&) = delete;
        InProcessConfigPreconditions& operator=(InProcessConfigPreconditions&&) = delete;

        InProcessConfigPreconditions()
            : PluginHost::IPlugin()
            , PluginHost::JSONRPC()
            , Exchange::IDictionary()
            , _adminLock()
            , _dictionaryNotification()
        {
        }

        ~InProcessConfigPreconditions() override = default;
        class Config : public Core::JSON::Container {
        public:
            Config(const Config&) = delete;
            Config& operator=(const Config&) = delete;
            Config(Config&&) = delete;
            Config& operator=(Config&&) = delete;

            Config()
                : Core::JSON::Container()
                , Example()
            {
                Add(_T("example"), &Example);
            }
            ~Config() override = default;
        public:
            Core::JSON::String Example;
        };
    public:
        // IPlugin Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;

        // IDictionary methods

        Core::hresult Register(const string& /* path */, IDictionary::INotification* /* sink */) override;

        Core::hresult Unregister(const string& /* path */, const IDictionary::INotification* /* sink */) override;

        Core::hresult Get(const string& /* path */, const string& /* key */, string& /* value */ /* @out */) const override;

        Core::hresult Set(const string& /* path */, const string& /* key */, const string& /* value */) override;

        Core::hresult PathEntries(const string& /* path */, IDictionary::IPathIterator*& /* entries */ /* @out */) const override;

        BEGIN_INTERFACE_MAP(InProcessConfigPreconditions)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            INTERFACE_ENTRY(Exchange::IDictionary)
        END_INTERFACE_MAP

    private:
        using DictionaryNotificationContainer = std::vector<Exchange::IDictionary::INotification*>;

        mutable Core::CriticalSection _adminLock;
        DictionaryNotificationContainer _dictionaryNotification;
    };
} // Plugin
} // Thunder