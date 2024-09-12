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
    
    class InProcess : public PluginHost::IPlugin, public PluginHost::JSONRPC, public Exchange::IHello, public Exchange::IWorld {
    public:
        InProcess(const InProcess&) = delete;
        InProcess &operator=(const InProcess&) = delete;
        InProcess(InProcess&&) = delete;
        InProcess &operator=(InProcess&&) = delete;
        
        InProcess()
        : IHello()
        , IWorld()
        , _example(0)
        {
        }
        
        ~InProcess() override = default;
    private:
        class Config : public Core::JSON::Container {
        private:
            Config(const Config&) = delete;
            Config& operator=(const Config&) = delete;
            Config(Config&&) = delete;
            Config& operator=(Config&&) = delete;
        public:
            Config()
                : Core::JSON::Container()
            {
                Add(_T("example"), &Example);
            }
            ~Config() override = default;
        public:
            Core::JSON::String Example;
        }
    public:
        // IPlugin Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;
        
        // IHello methods
        void IHelloMethod1() override;
        void IHelloMethod2() override;
        
        // IWorld methods
        void IWorldMethod1() override;
        void IWorldMethod2() override;
        
        // Plugin Methods
        void InProcessMethod(1);
        
        BEGIN_INTERFACE_MAP(InProcess)
        INTERFACE_ENTRY(PluginHost::IPlugin)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
        INTERFACE_ENTRY(Exchange::IHello)
        INTERFACE_ENTRY(Exchange::IWorld)
        END_INTERFACE_MAP
        
    private:
        // Include the correct member variables for your plugin:
        // Note this is only an example, you are responsible for adding the correct members:
        uint32_t _example;
    };
}
}