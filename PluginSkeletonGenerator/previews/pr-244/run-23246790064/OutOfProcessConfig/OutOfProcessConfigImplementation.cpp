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
#include <interfaces/INetworkControl.h>

namespace Thunder {
namespace Plugin {

    class OutOfProcessConfigImplementation : public Exchange::INetworkControl {
    public:
        OutOfProcessConfigImplementation(const OutOfProcessConfigImplementation&) = delete;
        OutOfProcessConfigImplementation& operator=(const OutOfProcessConfigImplementation&) = delete;
        OutOfProcessConfigImplementation(OutOfProcessConfigImplementation&&) = delete;
        OutOfProcessConfigImplementation& operator=(OutOfProcessConfigImplementation&&) = delete;

        OutOfProcessConfigImplementation()
            : Exchange::INetworkControl()
            , _adminLock()
            , _networkcontrolNotification()
        {
        }
        ~OutOfProcessConfigImplementation() override = default;

    private:

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

        BEGIN_INTERFACE_MAP(OutOfProcessConfigImplementation)
            INTERFACE_ENTRY(Exchange::INetworkControl)
        END_INTERFACE_MAP

        // INetworkControl methods

        uint32_t Register(Exchange::INetworkControl::INotification* notification) override {

            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_networkcontrolNotification.begin(), _networkcontrolNotification.end(), notification);
            ASSERT(item == _networkcontrolNotification.end());

            if (item == _networkcontrolNotification.end()) {
                notification->AddRef();
                _networkcontrolNotification.push_back(notification);
            }

            _adminLock.Unlock();

        }

        uint32_t Unregister(const Exchange::INetworkControl::INotification* notification) override {

            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_networkcontrolNotification.begin(), _networkcontrolNotification.end(), notification);
            ASSERT(item != _networkcontrolNotification.end());

            if (item != _networkcontrolNotification.end()) {
                _networkcontrolNotification.erase(item);
                notification->Release();
            }
            _adminLock.Unlock();

        }

        uint32_t Interfaces(IStringIterator*& /* interfaces */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Status(const string& /* interface */ /* @index */, StatusType& /* status */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Network(const string& /* interface */ /* @index */, INetworkInfoIterator*& /* networkInfo */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Network(const string& /* interface */ /* @index */, INetworkInfoIterator* const& /* networkInfo */ /* @in */) override {
            return Core::ERROR_NONE;
        }

        uint32_t DNS(IStringIterator*& /* dns */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t DNS(IStringIterator* const& /* dns */ /* @in */) override {
            return Core::ERROR_NONE;
        }

        uint32_t Up(const string& /* interface */ /* @index */, bool& /* up */ /* @out */) const override {
            return Core::ERROR_NONE;
        }

        uint32_t Up(const string& /* interface */ /* @index */, const bool /* up */ /* @in */) override {
            return Core::ERROR_NONE;
        }

        uint32_t Flush(const string& /* interface */) override {
            return Core::ERROR_NONE;
        }
    private:
        using NetworkControlNotificationContainer = std::vector<Exchange::INetworkControl::INotification*>;

        void NotifyUpdate(const string& interfaceName) const {
            _adminLock.Lock();
            for (auto* notification : _networkcontrolNotification) {
                notification->Update(interfaceName);
            }
            _adminLock.Unlock();
        }

        mutable Core::CriticalSection _adminLock;
        NetworkControlNotificationContainer _networkcontrolNotification;
    };

    SERVICE_REGISTRATION(OutOfProcessConfigImplementation, 1, 0)
} // Plugin
} // Thunder