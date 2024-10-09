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

#include "InProcess.h"

namespace Thunder {
namespace Plugin {
    namespace {
        static Metadata<InProcess>metadata(
            // Version
            1, 0, 0,
            // Preconditions
            {subsystem::PRE1, subsystem::PRE2},
            // Terminations
            {},
            // Controls
            {}
        )
    }
    
    // Implement all methods from InProcess.h
    
    const string InProcess::Initialize(PluginHost::IShell* service) {
        string message;
        
        ASSERT(service != nullptr);
        
        Config config;
        config.FromString(service->ConfigLine());
        
        Exchange::JHello::Register(*this, this);
        Exchange::JWorld::Register(*this, this);
        return (message);
    }
    
    void InProcess::Deinitialize(PluginHost::IShell* service VARIABLE_IS_NOT_USED) {
        Exchange::JHello::Unregister(*this);
        Exchange::JWorld::Unregister(*this);
    }
    
    string InProcess::Information() {
        return string()
    }
} // Plugin
} // Thunder