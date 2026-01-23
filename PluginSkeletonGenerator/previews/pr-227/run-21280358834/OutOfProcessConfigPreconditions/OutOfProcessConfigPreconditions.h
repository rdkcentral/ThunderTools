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
#include <Y/IBluetooth.h>

namespace Thunder {
namespace Plugin {

    class OutOfProcessConfigPreconditions : public PluginHost::IPlugin {
    public:
        OutOfProcessConfigPreconditions(const OutOfProcessConfigPreconditions&) = delete;
        OutOfProcessConfigPreconditions& operator=(const OutOfProcessConfigPreconditions&) = delete;
        OutOfProcessConfigPreconditions(OutOfProcessConfigPreconditions&&) = delete;
        OutOfProcessConfigPreconditions& operator=(OutOfProcessConfigPreconditions&&) = delete;

        OutOfProcessConfigPreconditions()
            : PluginHost::IPlugin()
            , _service(nullptr)
            , _connectionId(0)
            , _implBluetooth(nullptr)
            , _notification(*this)
        {
        }

        ~OutOfProcessConfigPreconditions() override = default;
        class Notification : public RPC::IRemoteConnection::INotification, public PluginHost::IShell::ICOMLink::INotification, public Exchange::IBluetooth::INotification, public Exchange::IBluetooth::INotification, public Exchange::IBluetooth::INotification {
        public:
            Notification(const Notification&) = delete;
            Notification& operator=(const Notification&) = delete;
            Notification(Notification&&) = delete;
            Notification& operator=(Notification&&) = delete;
            Notification() = delete;

            explicit Notification(OutOfProcessConfigPreconditions& parent)
                : RPC::IRemoteConnection::INotification()
                , PluginHost::IShell::ICOMLink::INotification()
                , Exchange::IBluetooth::INotification()
                , Exchange::IBluetooth::INotification()
                , Exchange::IBluetooth::INotification()
                , _parent(parent)
            {
            }

            ~Notification() override = default;

            void Activated(RPC::IRemoteConnection*) override {

            }

            void Deactivated(RPC::IRemoteConnection* connection) override {
                _parent.Deactivated(connection);
            }

            void Dangling(const Core::IUnknown* remote, const uint32_t interfaceId) override {
                _parent.Dangling(remote, interfaceId);
            }
            void Update(IDevice* device) override {
            }
            void ScanningStateChanged() override {
            }
            void AdvertisingStateChanged() override {
            }
            void ScanningStateChanged() override {
            }
            void InquiryScanningStateChanged() override {
            }
            BEGIN_INTERFACE_MAP(Notification)
                INTERFACE_ENTRY(RPC::IRemoteConnection::INotification)
                INTERFACE_ENTRY(PluginHost::IShell::ICOMLink::INotification)
                INTERFACE_ENTRY(Exchange::IBluetooth::INotification)
                INTERFACE_ENTRY(Exchange::IBluetooth::INotification)
                INTERFACE_ENTRY(Exchange::IBluetooth::INotification)
            END_INTERFACE_MAP
        private:
            OutOfProcessConfigPreconditions& _parent;
        };
    public:
        // IPlugin Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;
        void Deactivated(RPC::IRemoteConnection* connection);
        void Dangling(const Core::IUnknown* remote, const uint32_t interfaceId);

        BEGIN_INTERFACE_MAP(OutOfProcessConfigPreconditions)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_AGGREGATE(Exchange::IBluetooth, _implBluetooth)
        END_INTERFACE_MAP

    private:
        // Timeout (2000ms) may be changed if necessary, however, it must not exceed RPC::CommunicationTimeOut
        static constexpr uint32_t timeout = 2000;

        PluginHost::IShell* _service;
        uint32_t _connectionId;
        Exchange::IBluetooth* _implBluetooth;
        Core::SinkType<Notification> _notification;
    };
} // Plugin
} // Thunder