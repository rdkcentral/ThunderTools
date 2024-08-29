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

#include <interfaces/json/json1.h>
#include <interfaces/com1>

namespace Thunder {
namespace Plugin {

    class HelloWorld : public PluginHost::IPlugin {
    public:
        HelloWorld(const HelloWorld&) = delete;
        HelloWorld &operator=(const HelloWorld&) = delete;
        HelloWorld() {}
        ~HelloWorld override {}

        {{NESTED_CLASS}}

        // Inherited Methods
        const string Initialize(PluginHost::IShell* service) override;
        void Deinitialize(PluginHost::IShell* service) override;
        string Information() const override;
        
        // Plugin Methods
        void HelloWorldMethod(1);

        BEGIN_INTERFACE_MAP(HelloWorld)
        INTERFACE_ENTRY(com1)
        INTERFACE_AGGREGATE(com1, _impl)
        END_INTERFACE_MAP

        private:
        
        DATA_MEMBER
    };
}
}
