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

#include "OutOfProcessConfigPreconditions.h"
#include <interfaces/IConfiguration.h>
#include <interfaces/json/JWifiControl.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<OutOfProcessConfigPreconditions> metadata(
        // Version
        1, 0, 0,
        // Preconditions
        { subsystem::GRAPHICS , subsystem::NOT_GRAPHICS , subsystem::TIME },
        // Terminations
        {},
        // Controls
        {}
        );
    }

    const string OutOfProcessConfigPreconditions::Initialize(PluginHost::IShell* service) {
        string message;

        ASSERT(_service == nullptr);
        ASSERT(service != nullptr);
        ASSERT(_implWifiControl == nullptr);
        ASSERT(_connectionId == 0);

        _service = service;
        _service->AddRef();
        _service->Register(static_cast<RPC::IRemoteConnection::INotification*>(&_notification));
        _service->Register(static_cast<PluginHost::IShell::ICOMLink::INotification*>(&_notification));

        _implWifiControl = service->Root<Exchange::IWifiControl>(_connectionId, timeout, _T("OutOfProcessConfigPreconditionsImplementation"));
        if (_implWifiControl == nullptr) {
            message = _T("Couldn't create instance of _implWifiControl");
        } else {
            _implWifiControl->Register(&_notification);
            Exchange::JWifiControl::Register(*this, _implWifiControl);
            Exchange::IConfiguration* configuration = _implWifiControl->QueryInterface<Exchange::IConfiguration>();
            ASSERT(configuration != nullptr);
            if (configuration != nullptr) {
                if (configuration->Configure(service) != Core::ERROR_NONE) {
                    message = _T("OutOfProcessConfigPreconditions could not be configured.");
                }
                configuration->Release();
            }
        }

        return (message);
    }

    void OutOfProcessConfigPreconditions::Deinitialize(PluginHost::IShell* service) {

        ASSERT(_service == service);

        _service->Unregister(static_cast<RPC::IRemoteConnection::INotification*>(&_notification));
        _service->Unregister(static_cast<PluginHost::IShell::ICOMLink::INotification*>(&_notification));

        if (_implWifiControl != nullptr) {
            Exchange::JWifiControl::Unregister(*this);
            _implWifiControl->Unregister(&_notification);

            RPC::IRemoteConnection* connection(service->RemoteConnection(_connectionId));
            VARIABLE_IS_NOT_USED uint32_t result = _implWifiControl->Release();
            _implWifiControl = nullptr;

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

    string OutOfProcessConfigPreconditions::Information() const {
        return (string());
    }

    void OutOfProcessConfigPreconditions::Deactivated(RPC::IRemoteConnection* connection) {
        if (connection->Id() == _connectionId) {
            ASSERT(_service != nullptr);
            Core::IWorkerPool::Instance().Submit(PluginHost::IShell::Job::Create(_service, PluginHost::IShell::DEACTIVATED, PluginHost::IShell::FAILURE));
            _service->Release();
            _service = nullptr;
            _connectionId = 0;
        }
    }
    void OutOfProcessConfigPreconditions::Dangling(const Core::IUnknown* remote, const uint32_t interfaceId) {
        ASSERT(remote != nullptr);

        if (interfaceId == Exchange::IWifiControl::INotification::ID) {
            auto* revokedInterface = remote->QueryInterface<Exchange::IWifiControl::INotification>();
            if (revokedInterface) {
                _implWifiControl->Unregister(const_cast<Exchange::IWifiControl::INotification*>(revokedInterface));
                revokedInterface->Release();
            }
        }

    }

} // Plugin
} // Thunder