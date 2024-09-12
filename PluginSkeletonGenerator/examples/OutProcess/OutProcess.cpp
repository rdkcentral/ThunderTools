/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2024 Metrological
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

#include "OutProcess.h"

namespace Thunder{
namespace Plugin{
    namespace {
        static Metadata<OutProcess>metadata(
            // Version
            1, 0, 0,
            // Preconditions
            {},
            // Terminations
            {},
            // Controls
            {}
        )
    }
    
    // Implement all methods from OutProcess.h
    
    const string OutProcess::Initialize(PluginHost::IShell* service) {
        string message;
        
        ASSERT (_service == nullptr);
        ASSERT (service != nullptr);
        ASSERT (_implementation == nullptr);
        ASSERT (_connectionId == 0);
        
        _service = service;
        _service->AddRef();
        _service->Register(&_connectionNotification);
        
        // Example
        _implementation = service->Root<Exchange::IHello>(_connectionId, 2000, _T("OutProcessImplementation"));
        if (_implementation == nullptr) {
            message = _T("Couldn't create instance");
        } else {
            // Add registration e.g:
            //_implementation->Register(&_volumeNotification);
            Exchange::JHello::Register(*this, implJHello);
            Exchange::JWorld::Register(*this, implJWorld);
        }
        
        return (message);
    }
    
    void OutProcess::Deinitialize(PluginHost::IShell* service) {
        if (_service != nullptr) {
            ASSERT(_service == service);
            
            service->Unregister(&_connectionNotification);
            
            if (_implementation != nullptr) {
                // Example if your interface has inotification implemented
                Exchange::JHello::Unregister(*this);
                Exchange::JWorld::Unregister(*this);
                //_implementation->Unregister(&_volumeNotification);
                
                RPC::IRemoteConnection* connection(_service->RemoteConnection(_connectionId));
                VARIABLE_IS_NOT_USED uint32_t result = _implementation->Release();
                _implementation = nullptr;
                // It should have been the last reference we are releasing,
                // so it should endup in a DESTRUCTION_SUCCEEDED, if not we
                // are leaking...
                ASSERT(result == Core::ERROR_DESTRUCTION_SUCCEEDED);
                // The process can disappear in the meantime...
                if (connection != nullptr) {
                    // But if it did not dissapear in the meantime, forcefully terminate it. Shoot to kill
                    connection->Terminate();
                    connection->Release();
                }
            }
            _service->Release();
            _service = nullptr;
            _connectionId = 0;
        }
    }
    
    string OutProcess::Information() {
        return string()
    }
} // Plugin
} // Thunder