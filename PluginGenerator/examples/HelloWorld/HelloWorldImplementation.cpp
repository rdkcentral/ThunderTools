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

#include <interfaces/com1>

namespace Thunder {
namespace Plugin {

    SERVICE_REGISTRATION(HelloWorldImplementation, 1, 0)

    class HelloWorldImplementation : public com1 {
    public:

        HelloWorldImplementation(const HelloWorldImplementation&) = delete;
        HelloWorldImplementation& operator=(const HelloWorldImplementation&) = delete;

        HelloWorldImplementation();
        ~HelloWorldImplementation() override = default;

        BEGIN_INTERFACE_MAP(HelloWorldImplementation)
        INTERFACE_ENTRY(com1)
        END_INTERFACE_MAP
    
        // Implement methods from the interface
        

    private:
        // Add data members, for example: (Core::CriticalSection, std::vector<INTERFACE*>..)
};
} // Plugin
} // Thunder