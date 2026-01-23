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

#include "OutOfProcess.h"
#include <interfaces/json/JBrowser.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<OutOfProcess>metadata(
        // Version
        1, 0, 0,
        // Preconditions
        {},
        // Terminations
        {},
        // Controls
        {}
        );
    }

    const string OutOfProcess::Initialize(PluginHost::IShell* service) {
        string message;

        ASSERT(_service == nullptr);
        ASSERT(service != nullptr);
        ASSERT(_implBrowser == nullptr);
        ASSERT(_connectionId == 0);

        _service = service;
        _service->AddRef();
        _service->Register(static_cast<RPC::IRemoteConnection::INotification*>(&_notification));
        _service->Register(static_cast<PluginHost::IShell::ICOMLink::INotification*>(&_notification));

        _implBrowser = service->Root<Exchange::IBrowser>(_connectionId, timeout, _T("OutOfProcessImplementation"));
        if (_implBrowser == nullptr) {
            message = _T("Couldn't create instance of _implBrowser");
        } else {
            _implWebBrowser = _implBrowser->QueryInterface<Exchange::IWebBrowser>();
            if (_implWebBrowser == nullptr) {
                message = _T("Failed to acquire IWebBrowser interface.");
            } else {
                _implWebBrowserExt = _implBrowser->QueryInterface<Exchange::IWebBrowserExt>();
                if (_implWebBrowserExt == nullptr) {
                    message = _T("Failed to acquire IWebBrowserExt interface.");
                } else {
                    _implBrowserResources = _implBrowser->QueryInterface<Exchange::IBrowserResources>();
                    if (_implBrowserResources == nullptr) {
                        message = _T("Failed to acquire IBrowserResources interface.");
                    } else {
                        _implBrowserSecurity = _implBrowser->QueryInterface<Exchange::IBrowserSecurity>();
                        if (_implBrowserSecurity == nullptr) {
                            message = _T("Failed to acquire IBrowserSecurity interface.");
                        } else {
                            _implBrowserScripting = _implBrowser->QueryInterface<Exchange::IBrowserScripting>();
                            if (_implBrowserScripting == nullptr) {
                                message = _T("Failed to acquire IBrowserScripting interface.");
                            } else {
                                _implBrowserCookieJar = _implBrowser->QueryInterface<Exchange::IBrowserCookieJar>();
                                if (_implBrowserCookieJar == nullptr) {
                                    message = _T("Failed to acquire IBrowserCookieJar interface.");
                                } else {
                                    Exchange::JWebBrowser::Register(*this, _implWebBrowser);
                                    Exchange::JWebBrowserExt::Register(*this, _implWebBrowserExt);
                                    Exchange::JBrowserResources::Register(*this, _implBrowserResources);
                                    Exchange::JBrowserSecurity::Register(*this, _implBrowserSecurity);
                                    Exchange::JBrowserScripting::Register(*this, _implBrowserScripting);
                                    Exchange::JBrowserCookieJar::Register(*this, _implBrowserCookieJar);
                                }
                            }
                        }
                    }
                }
            }
        }

        return (message);
    }

    void OutOfProcess::Deinitialize(PluginHost::IShell* service) {

        ASSERT(_service == service);

        _service->Unregister(static_cast<RPC::IRemoteConnection::INotification*>(&_notification));
        _service->Unregister(static_cast<PluginHost::IShell::ICOMLink::INotification*>(&_notification));

        if (_implBrowser != nullptr) {

            if (_implWebBrowser != nullptr) {
                Exchange::JWebBrowser::Unregister(*this);
                _implWebBrowser->Release();
                _implWebBrowser = nullptr;
            }

            if (_implWebBrowserExt != nullptr) {
                Exchange::JWebBrowserExt::Unregister(*this);
                _implWebBrowserExt->Release();
                _implWebBrowserExt = nullptr;
            }

            if (_implBrowserResources != nullptr) {
                Exchange::JBrowserResources::Unregister(*this);
                _implBrowserResources->Release();
                _implBrowserResources = nullptr;
            }

            if (_implBrowserSecurity != nullptr) {
                Exchange::JBrowserSecurity::Unregister(*this);
                _implBrowserSecurity->Release();
                _implBrowserSecurity = nullptr;
            }

            if (_implBrowserScripting != nullptr) {
                Exchange::JBrowserScripting::Unregister(*this);
                _implBrowserScripting->Release();
                _implBrowserScripting = nullptr;
            }

            if (_implBrowserCookieJar != nullptr) {
                Exchange::JBrowserCookieJar::Unregister(*this);
                _implBrowserCookieJar->Release();
                _implBrowserCookieJar = nullptr;
            }

            RPC::IRemoteConnection* connection(service->RemoteConnection(_connectionId));
            VARIABLE_IS_NOT_USED uint32_t result = _implBrowser->Release();
            _implBrowser = nullptr;

            ASSERT((result == Core::ERROR_DESTRUCTION_SUCCEEDED) || (result == Core::ERROR_CONNECTION_CLOSED));

            // The process can disappear in the meantime...
            if (connection != nullptr) {
                // But if it did not disappear in the meantime, forcefully terminate it. Shoot to kill
                connection->Terminate();
                connection->Release();
            }
        }

        _service->Release();
        _service = nullptr;
        _connectionId = 0;
    }

    string OutOfProcess::Information() const {
        return (string());
    }

    void OutOfProcess::Deactivated(RPC::IRemoteConnection* connection) {
        if (connection->Id() == _connectionId) {
            ASSERT(_service != nullptr);
            Core::IWorkerPool::Instance().Submit(PluginHost::IShell::Job::Create(_service, PluginHost::IShell::DEACTIVATED, PluginHost::IShell::FAILURE));
            _service->Release();
            _service = nullptr;
            _connectionId = 0;
        }
    }
    void OutOfProcess::Dangling(const Core::IUnknown* remote, const uint32_t interfaceId) {
        ASSERT(remote != nullptr);

        if (interfaceId == Exchange::IBrowser::INotification::ID) {
            auto* revokedInterface = remote->QueryInterface<Exchange::IBrowser::INotification>();
            if (revokedInterface) {
                _implBrowser->Unregister(revokedInterface);
                revokedInterface->Release();
            }
        }
    }

} // Plugin
} // Thunder