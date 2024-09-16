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

#include <interfaces/IHello>
#include <interfaces/IWorld>

namespace Thunder {
namespace Plugin {
    SERVICE_REGISTRATION(OutOfProcessImplementation, 1, 0)
    
    class OutOfProcessImplementation : public IHello, public IWorld {
    public:
        OutOfProcessImplementation(const OutOfProcessImplementation&) = delete;
        OutOfProcessImplementation& operator=(const OutOfProcessImplementation&) = delete;
        
        OutOfProcessImplementation()
            : IHello()
            , IWorld()
            , _test(0)
        {
        }
        ~OutOfProcessImplementation() override = default;
        
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
        
        BEGIN_INTERFACE_MAP(OutOfProcessImplementation)
        INTERFACE_ENTRY(Exchange::IHello)
        INTERFACE_ENTRY(Exchange::IWorld)
        END_INTERFACE_MAP
        
        // Implement methods from the interface
        // IHello methods
        void IHelloMethod1() override;
        void IHelloMethod2() override;
        
        // IWorld methods
        void IWorldMethod1() override;
        void IWorldMethod2() override;
        
    private:
        // Add data members, for example: (Core::CriticalSection, std::vector<INTERFACE*>..)
        uint32_t _test;
    };
} // Plugin
} // Thunder