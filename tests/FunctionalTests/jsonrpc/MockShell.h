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

namespace Thunder {
namespace JsonRpcServer {
    class MockShell : public PluginHost::IShell {
    public:
        MockShell(const string& callsign)
            : _callsign(callsign)
        {
        }
        ~MockShell() override = default;

        // This object is owned by the JsonRpcServer and is not reference counted, so AddRef/Release do nothing.
        uint32_t AddRef() const override { return Core::ERROR_COMPOSIT_OBJECT; }
        uint32_t Release() const override { return Core::ERROR_COMPOSIT_OBJECT; }

        // Essential IShell methods - Callsign() is used by JSONRPC
        string Callsign() const override { return _callsign; }

        // Stub implementations for other required virtual methods
        void EnableWebServer(const string&, const string&) override { }
        void DisableWebServer() override { }
        string Model() const override { return string(); }
        bool Background() const override { return false; }
        string Accessor() const override { return string(); }
        string WebPrefix() const override { return string(); }
        string Locator() const override { return string(); }
        string ClassName() const override { return string(); }
        string PersistentPath() const override { return string(); }
        string VolatilePath() const override { return string(); }
        string DataPath() const override { return string(); }
        string ProxyStubPath() const override { return string(); }
        string SystemPath() const override { return string(); }
        string PluginPath() const override { return string(); }
        string SystemRootPath() const override { return string(); }
        Core::hresult SystemRootPath(const string&) override { return Core::ERROR_NONE; }
        startmode StartMode() const override { return startmode::DEACTIVATED; }
        Core::hresult StartMode(const startmode) override { return Core::ERROR_NONE; }
        string Substitute(const string&) const override { return string(); }
        bool Resumed() const override { return false; }
        Core::hresult Resumed(const bool) override { return Core::ERROR_NONE; }
        string HashKey() const override { return string(); }
        string ConfigLine() const override { return string(); }
        Core::hresult ConfigLine(const string&) override { return Core::ERROR_NONE; }
        Core::hresult Metadata(string&) const override { return Core::ERROR_NONE; }
        PluginHost::ISubSystem* SubSystems() override { return nullptr; }
        void Notify(const string&, const string&) override { }
        void Register(PluginHost::IPlugin::INotification*, const Core::OptionalType<string>& = { }) override { }
        void Unregister(PluginHost::IPlugin::INotification*, const Core::OptionalType<string>& = { }) override { }
        state State() const override { return state::DEACTIVATED; }
        void* QueryInterfaceByCallsign(const uint32_t, const string&) override { return nullptr; }
        Core::hresult Activate(const reason) override { return Core::ERROR_NONE; }
        Core::hresult Deactivate(const reason) override { return Core::ERROR_NONE; }
        Core::hresult Unavailable(const reason) override { return Core::ERROR_NONE; }
        Core::hresult Hibernate(const uint32_t) override { return Core::ERROR_NONE; }
        reason Reason() const override { return reason::REQUESTED; }
        uint32_t Submit(const uint32_t, const Core::ProxyType<Core::JSON::IElement>&) override { return Core::ERROR_NONE; }
        RPC::IStringIterator* GetLibrarySearchPaths(const string&) const override { return nullptr; }

        void Register(PluginHost::IPlugin::INotification* sink, const uint32_t interface_id) override { }
        void Unregister(PluginHost::IPlugin::INotification* sink, const uint32_t interface_id) override { }

        BEGIN_INTERFACE_MAP(MockShell)
        INTERFACE_ENTRY(PluginHost::IShell)
        END_INTERFACE_MAP

    private:
        string _callsign;
    };
} // namespace JsonRpcServer
} // namespace Thunder
