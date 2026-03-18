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

#include "OutOfProcessPreconditions.h"
#include <interfaces/json/JMessageControl.h>

namespace Thunder {
namespace Plugin {

    namespace {

        static Metadata<OutOfProcessPreconditions>metadata(
        // Version
        1, 0, 0,
        // Preconditions
        { subsystem::GRAPHICS },
        // Terminations
        { subsystem::NOT_GRAPHICS },
        // Controls
        { subsystem::TIME }
        );
    }

    const string OutOfProcessPreconditions::Initialize(PluginHost::IShell* service) {
        string message;

        ASSERT(_service == nullptr);
        ASSERT(service != nullptr);
        ASSERT(_implMessageControl == nullptr);
        ASSERT(_connectionId == 0);

        _service = service;
        _service->AddRef();
        _service->Register(&_notification);

        _implMessageControl = service->Root<Exchange::IMessageControl>(_connectionId, timeout, _T("OutOfProcessPreconditionsImplementation"));
        if (_implMessageControl == nullptr) {
            message = _T("Couldn't create instance of _implMessageControl");
        } else {
            Exchange::JMessageControl::Register(*this, _implMessageControl);
        }

        return (message);
    }

    void OutOfProcessPreconditions::Deinitialize(PluginHost::IShell* service) {

        ASSERT(_service == service);

        _service->Unregister(&_notification);

        if (_implMessageControl != nullptr) {
            Exchange::JMessageControl::Unregister(*this);

            RPC::IRemoteConnection* connection(service->RemoteConnection(_connectionId));
            VARIABLE_IS_NOT_USED uint32_t result = _implMessageControl->Release();
            _implMessageControl = nullptr;

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

    string OutOfProcessPreconditions::Information() const {
        return (string());
    }

    void OutOfProcessPreconditions::Deactivated(RPC::IRemoteConnection* connection) {
        if (connection->Id() == _connectionId) {
            ASSERT(_service != nullptr);
            Core::IWorkerPool::Instance().Submit(PluginHost::IShell::Job::Create(_service, PluginHost::IShell::DEACTIVATED, PluginHost::IShell::FAILURE));
            _service->Release();
            _service = nullptr;
            _connectionId = 0;
        }
    }

} // Plugin
} // Thunder