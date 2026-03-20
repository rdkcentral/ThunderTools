/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
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

#include "Module.h"
#include "ComRpcServer.h"

namespace Thunder {
namespace TestRegistry {

    // Template factory registration for implementations
    // This registers a creation function with the ImplementationProvider
    template <typename INTERFACE, typename IMPLEMENTATION>
    class ImplementationRegistrar {
    public:
        ImplementationRegistrar()
        {
            // Register factory function for this interface ID
            ComRpcServer::ImplementationProvider::Instance().Register(INTERFACE::ID, &ImplementationRegistrar::Create);
        }

    private:
        static void* Create(const uint32_t interfaceId)
        {
            ASSERT(interfaceId == INTERFACE::ID);
            
            // Create implementation instance
            INTERFACE* instance = Core::Service<IMPLEMENTATION>::template Create<INTERFACE>();
            return instance;
        }
    };

} // namespace TestRegistry
} // namespace Thunder
