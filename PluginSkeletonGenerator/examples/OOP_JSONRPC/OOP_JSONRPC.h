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
#include <interfaces/json/JSON1.h>
#include <interfaces/COM1>

namespace Thunder {
namespace Plugin {
    
    class OOP_JSONRPC : public PluginHost::IPlugin, public PluginHost::JSONRPC {
    public:
        OOP_JSONRPC(const OOP_JSONRPC&) = delete;
        OOP_JSONRPC &operator=(const OOP_JSONRPC&) = delete;
        OOP_JSONRPC() {}
        ~OOP_JSONRPC override {}
    
    private:
        
        
        class ConnectionNotification : public RPC::IRemoteConnection::INotification {
        public:
            explicit ConnectionNotification(OOP_JSONRPC* parent)
                : _parent(*parent)
            {
                ASSERT(parent != nullptr);
            }
            
            ~ConnectionNotification() override = default;
            ConnectionNotification() = delete;
            ConnectionNotification(const ConnectionNotification&) = delete;
            ConnectionNotification& operator=(const ConnectionNotification&) = delete;
            
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
            OOP_JSONRPC& _parent;
        }
    public:
        
        // Inherited Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;
        
        // Plugin Methods
        void OOP_JSONRPCMethod(1);
        
        BEGIN_INTERFACE_MAP(OOP_JSONRPC)
        INTERFACE_ENTRY(COM1)
        INTERFACE_AGGREGATE(COM1, _impl)
        END_INTERFACE_MAP
    private:
        // Include the correct member variables for your plugin:
        // Note this is only an example, you are responsible for adding the correct members:
        uint32_t _connectionId;
    };
}
}