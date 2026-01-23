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
#include <interfaces/IBrowser.h>
#include <interfaces/json/JBrowser.h>

namespace Thunder {
namespace Plugin {

    class OutOfProcess : public PluginHost::IPlugin, public PluginHost::JSONRPC {
    public:
        OutOfProcess(const OutOfProcess&) = delete;
        OutOfProcess& operator=(const OutOfProcess&) = delete;
        OutOfProcess(OutOfProcess&&) = delete;
        OutOfProcess& operator=(OutOfProcess&&) = delete;

        OutOfProcess()
            : PluginHost::IPlugin()
            , PluginHost::JSONRPC()
            , _service(nullptr)
            , _connectionId(0)
            , _implBrowser(nullptr)
            , _implWebBrowser(nullptr)
            , _implWebBrowserExt(nullptr)
            , _implBrowserResources(nullptr)
            , _implBrowserSecurity(nullptr)
            , _implBrowserScripting(nullptr)
            , _implBrowserCookieJar(nullptr)
            , _notification(*this)
        {
        }

        ~OutOfProcess() override = default;
        class Notification : public RPC::IRemoteConnection::INotification, public PluginHost::IShell::ICOMLink::INotification, public Exchange::IBrowser::INotification {
        public:
            Notification(const Notification&) = delete;
            Notification& operator=(const Notification&) = delete;
            Notification(Notification&&) = delete;
            Notification& operator=(Notification&&) = delete;
            Notification() = delete;

            explicit Notification(OutOfProcess& parent)
                : RPC::IRemoteConnection::INotification()
                , PluginHost::IShell::ICOMLink::INotification()
                , Exchange::IBrowser::INotification()
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
            void LoadFinished(const string& URL) override {
                Exchange::JBrowser::Event::LoadFinished(_parent, URL);
            }
            void URLChanged(const string& URL) override {
                Exchange::JBrowser::Event::URLChanged(_parent, URL);
            }
            void Hidden(const bool hidden) override {
                Exchange::JBrowser::Event::Hidden(_parent, hidden);
            }
            void Closure() override {
                Exchange::JBrowser::Event::Closure(_parent);
            }
            BEGIN_INTERFACE_MAP(Notification)
                INTERFACE_ENTRY(RPC::IRemoteConnection::INotification)
                INTERFACE_ENTRY(PluginHost::IShell::ICOMLink::INotification)
                INTERFACE_ENTRY(Exchange::IBrowser::INotification)
            END_INTERFACE_MAP
        private:
            OutOfProcess& _parent;
        };
    public:
        // IPlugin Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;
        void Deactivated(RPC::IRemoteConnection* connection);
        void Dangling(const Core::IUnknown* remote, const uint32_t interfaceId);

        BEGIN_INTERFACE_MAP(OutOfProcess)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
            INTERFACE_AGGREGATE(Exchange::IBrowser, _implBrowser)
            INTERFACE_AGGREGATE(Exchange::IWebBrowser, _implWebBrowser)
            INTERFACE_AGGREGATE(Exchange::IWebBrowserExt, _implWebBrowserExt)
            INTERFACE_AGGREGATE(Exchange::IBrowserResources, _implBrowserResources)
            INTERFACE_AGGREGATE(Exchange::IBrowserSecurity, _implBrowserSecurity)
            INTERFACE_AGGREGATE(Exchange::IBrowserScripting, _implBrowserScripting)
            INTERFACE_AGGREGATE(Exchange::IBrowserCookieJar, _implBrowserCookieJar)
        END_INTERFACE_MAP

    private:
        // Timeout (2000ms) may be changed if necessary, however, it must not exceed RPC::CommunicationTimeOut
        static constexpr uint32_t timeout = 2000;

        PluginHost::IShell* _service;
        uint32_t _connectionId;
        Exchange::IBrowser* _implBrowser;
        Exchange::IWebBrowser* _implWebBrowser;
        Exchange::IWebBrowserExt* _implWebBrowserExt;
        Exchange::IBrowserResources* _implBrowserResources;
        Exchange::IBrowserSecurity* _implBrowserSecurity;
        Exchange::IBrowserScripting* _implBrowserScripting;
        Exchange::IBrowserCookieJar* _implBrowserCookieJar;
        Core::SinkType<Notification> _notification;
    };
} // Plugin
} // Thunder