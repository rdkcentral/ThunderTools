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

#pragma once
#include <interfaces/json/JHello.h>
#include <interfaces/json/JWorld.h>
#include <interfaces/IHello>
#include <interfaces/IWorld>

namespace Thunder {
namespace Plugin {
    
    class OutOfProcess : public PluginHost::IPlugin, public PluginHost::JSONRPC {
    public:
        OutOfProcess(const OutOfProcess&) = delete;
        OutOfProcess &operator=(const OutOfProcess&) = delete;
        OutOfProcess(OutOfProcess&&) = delete;
        OutOfProcess &operator=(OutOfProcess&&) = delete;
        
        OutOfProcess()
            : _example(0)
        {
        }
        
        ~OutOfProcess() override = default;
    private:
        class ConnectionNotification : public RPC::IRemoteConnection::INotification {
        public:
            explicit ConnectionNotification(OutOfProcess* parent)
                : _parent(*parent)
            {
                ASSERT(parent != nullptr);
            }
            
            ~ConnectionNotification() override = default;
            ConnectionNotification() = delete;
            ConnectionNotification(const ConnectionNotification&) = delete;
            ConnectionNotification& operator=(const ConnectionNotification&) = delete;
            ConnectionNotification(ConnectionNotification&&) = delete;
            ConnectionNotification& operator=(ConnectionNotification&&) = delete;
            
            void Activated(RPC::IRemoteConnection*) override
            {
            }
            
            void Deactivated(RPC::IRemoteConnection* connection) override
            {
                _parent.Deactivated(connection);
            }
            
            BEGIN_INTERFACE_MAP(ConnectionNotification)
            INTERFACE_ENTRY(RPC::IRemoteConnection::INotification)
            END_INTERFACE_MAP
        private:
            OutOfProcess& _parent;
        }
    public:
        // IPlugin Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;
        
        
        // Plugin Methods
        void OutOfProcessMethod();
        
        BEGIN_INTERFACE_MAP(OutOfProcess)
        INTERFACE_ENTRY(PluginHost::IPlugin)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
        INTERFACE_AGGREGATE(Exchange::IHello, _implIHello)
        INTERFACE_AGGREGATE(Exchange::IWorld, _implIWorld)
        END_INTERFACE_MAP
        
    private:
        // Include the correct member variables for your plugin:
        // Note this is only an example, you are responsible for adding the correct members:
        uint32_t _example;
    };
} // Plugin
} // Thunder