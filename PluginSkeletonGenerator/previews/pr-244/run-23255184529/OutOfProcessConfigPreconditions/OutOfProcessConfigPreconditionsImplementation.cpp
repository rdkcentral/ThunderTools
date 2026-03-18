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
#include <Y/IBluetooth.h>

namespace Thunder {
namespace Plugin {

    class OutOfProcessConfigPreconditionsImplementation : public Exchange::IBluetooth {
    public:
        OutOfProcessConfigPreconditionsImplementation(const OutOfProcessConfigPreconditionsImplementation&) = delete;
        OutOfProcessConfigPreconditionsImplementation& operator=(const OutOfProcessConfigPreconditionsImplementation&) = delete;
        OutOfProcessConfigPreconditionsImplementation(OutOfProcessConfigPreconditionsImplementation&&) = delete;
        OutOfProcessConfigPreconditionsImplementation& operator=(OutOfProcessConfigPreconditionsImplementation&&) = delete;

        OutOfProcessConfigPreconditionsImplementation()
            : Exchange::IBluetooth()
            , _adminLock()
            , _bluetoothNotification()
        {
        }
        ~OutOfProcessConfigPreconditionsImplementation() override = default;

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

        BEGIN_INTERFACE_MAP(OutOfProcessConfigPreconditionsImplementation)
            INTERFACE_ENTRY(Exchange::IBluetooth)
        END_INTERFACE_MAP

        // IBluetooth methods

        uint32_t Register(Exchange::IBluetooth::INotification* notification) override {

            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_bluetoothNotification.begin(), _bluetoothNotification.end(), notification);
            ASSERT(item == _bluetoothNotification.end());

            if (item == _bluetoothNotification.end()) {
                notification->AddRef();
                _bluetoothNotification.push_back(notification);
            }

            _adminLock.Unlock();

        }

        uint32_t Unregister(const Exchange::IBluetooth::INotification* notification) override {

            ASSERT(notification != nullptr);

            _adminLock.Lock();
            auto item = std::find(_bluetoothNotification.begin(), _bluetoothNotification.end(), notification);
            ASSERT(item != _bluetoothNotification.end());

            if (item != _bluetoothNotification.end()) {
                _bluetoothNotification.erase(item);
                notification->Release();
            }
            _adminLock.Unlock();

        }

        bool IsScanning() const override {
            return Core::ERROR_NONE;
        }

        uint32_t Scan(const bool /* lowEnergy */, const uint16_t /* duration */ /* sec */) override {
            return Core::ERROR_NONE;
        }

        uint32_t StopScanning() override {
            return Core::ERROR_NONE;
        }

        IDevice* Device(const string& /* address */, const IDevice::type /* type */) override {
            return Core::ERROR_NONE;
        }

        IDevice::IIterator* Devices() override {
            return Core::ERROR_NONE;
        }

        uint32_t ForgetDevice(const string& /* address */, const IDevice::type /* type */) override {
            return Core::ERROR_NONE;
        }
    private:
        using BluetoothNotificationContainer = std::vector<Exchange::IBluetooth::INotification*>;

        void NotifyUpdate(IDevice* device) const {
            _adminLock.Lock();
            for (auto* notification : _bluetoothNotification) {
                notification->Update(device);
            }
            _adminLock.Unlock();
        }

        void NotifyScanningStateChanged() const {
            _adminLock.Lock();
            for (auto* notification : _bluetoothNotification) {
                notification->ScanningStateChanged();
            }
            _adminLock.Unlock();
        }

        void NotifyAdvertisingStateChanged() const {
            _adminLock.Lock();
            for (auto* notification : _bluetoothNotification) {
                notification->AdvertisingStateChanged();
            }
            _adminLock.Unlock();
        }

        void NotifyScanningStateChanged() const {
            _adminLock.Lock();
            for (auto* notification : _bluetoothNotification) {
                notification->ScanningStateChanged();
            }
            _adminLock.Unlock();
        }

        void NotifyInquiryScanningStateChanged() const {
            _adminLock.Lock();
            for (auto* notification : _bluetoothNotification) {
                notification->InquiryScanningStateChanged();
            }
            _adminLock.Unlock();
        }

        mutable Core::CriticalSection _adminLock;
        BluetoothNotificationContainer _bluetoothNotification;
    };

    SERVICE_REGISTRATION(OutOfProcessConfigPreconditionsImplementation, 1, 0)
} // Plugin
} // Thunder