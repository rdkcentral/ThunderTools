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

#include "Module.h"
#include <interfaces/IWifiControl.h>
#include <interfaces/IConfiguration.h>

namespace Thunder {
namespace Plugin {

    class OutOfProcessConfigPreconditionsImplementation : public Exchange::IConfiguration, public Exchange::IWifiControl {
    public:
        OutOfProcessConfigPreconditionsImplementation(const OutOfProcessConfigPreconditionsImplementation&) = delete;
        OutOfProcessConfigPreconditionsImplementation& operator=(const OutOfProcessConfigPreconditionsImplementation&) = delete;
        OutOfProcessConfigPreconditionsImplementation(OutOfProcessConfigPreconditionsImplementation&&) = delete;
        OutOfProcessConfigPreconditionsImplementation& operator=(OutOfProcessConfigPreconditionsImplementation&&) = delete;

        OutOfProcessConfigPreconditionsImplementation()
            : Exchange::IWifiControl()
            , _adminLock()
            , _wificontrolNotification()
        {
        }
        ~OutOfProcessConfigPreconditionsImplementation() override = default;

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

        BEGIN_INTERFACE_MAP(OutOfProcessConfigPreconditionsImplementation)
            INTERFACE_ENTRY(Exchange::IConfiguration)
            INTERFACE_ENTRY(Exchange::IWifiControl)
        END_INTERFACE_MAP

        // Type aliases copied from interface headers
        using INetworkInfoIterator = RPC::IIteratorType<NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>;
        using ISecurityIterator = RPC::IIteratorType<SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>;
        using IStringIterator = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

        // IWifiControl methods

        uint32_t Register(Exchange::IWifiControl::INotification* notification) override {
            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_wificontrolNotification.begin(), _wificontrolNotification.end(), notification);
            ASSERT(item == _wificontrolNotification.end());

            if (item == _wificontrolNotification.end()) {
                notification->AddRef();
                _wificontrolNotification.push_back(notification);
            }

            _adminLock.Unlock();
            return Core::ERROR_NONE;
        }

        uint32_t Unregister(Exchange::IWifiControl::INotification* notification) override {
            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_wificontrolNotification.begin(), _wificontrolNotification.end(), notification);
            ASSERT(item != _wificontrolNotification.end());

            if (item != _wificontrolNotification.end()) {
                _wificontrolNotification.erase(item);
                notification->Release();
            }
            _adminLock.Unlock();
            return Core::ERROR_NONE;
        }

        uint32_t Networks(INetworkInfoIterator*& /* networkInfoList */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Securities(const string& /* ssid */ /* @index */, ISecurityIterator*& /* securityMethods */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Configs(IStringIterator*& /* configs */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Config(const string& /* ssid */ /* @index */, ConfigInfo& /* configInfo */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Config(const string& /* ssid */ /* @index */, const ConfigInfo& /* configInfo */) override {
            return Core::ERROR_NONE;
        }

        uint32_t Scan() override {
            return Core::ERROR_NONE;
        }

        uint32_t AbortScan() override {
            return Core::ERROR_NONE;
        }

        uint32_t Connect(const string& /* configSSID */) override {
            return Core::ERROR_NONE;
        }

        uint32_t Disconnect(const string& /* configSSID */) override {
            return Core::ERROR_NONE;
        }

        uint32_t Status(string& /* connectedSsid */ /* @out */, bool& /* isScanning */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Configure(PluginHost::IShell* service) override {
            ASSERT(service != nullptr);
            PluginConfig config;
            config.FromString(service->ConfigLine());
            TRACE(Trace::Information, (_T("This is just an example: [%s]"), config.Example.Value().c_str()));
            return Core::ERROR_NONE;
        }
    private:
        using WifiControlNotificationContainer = std::vector<Exchange::IWifiControl::INotification*>;

        void NotifyNetworkChange() const {
            _adminLock.Lock();
            for (auto* notification : _wificontrolNotification) {
                notification->NetworkChange();
            }
            _adminLock.Unlock();
        }

        void NotifyConnectionChange(const string& ssid) const {
            _adminLock.Lock();
            for (auto* notification : _wificontrolNotification) {
                notification->ConnectionChange(ssid);
            }
            _adminLock.Unlock();
        }

        mutable Core::CriticalSection _adminLock;
        WifiControlNotificationContainer _wificontrolNotification;
    };

    SERVICE_REGISTRATION(OutOfProcessConfigPreconditionsImplementation, 1, 0)
} // Plugin
} // Thunder