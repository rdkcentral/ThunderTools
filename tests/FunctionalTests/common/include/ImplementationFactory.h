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

#include <plugins/plugins.h>
#include <map>

namespace Thunder {
namespace TestImplementation {
    class Factory {
    public:
        using CreateFunction = void* (*)(const uint32_t interfaceId);

        static Factory& Instance()
        {
            static Factory instance;
            return instance;
        }

        void Register(uint32_t interfaceId, CreateFunction creator)
        {
            _creators[interfaceId] = creator;
        }

        void* Create(uint32_t interfaceId)
        {
            auto it = _creators.find(interfaceId);
            if (it != _creators.end()) {
                return it->second(interfaceId);
            }
            return nullptr;
        }

    public:
        template <typename INTERFACE, typename IMPLEMENTATION>
        class Registrar {
        public:
            Registrar()
            {
                Factory::Instance().Register(INTERFACE::ID, &Registrar::Create);
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

    private:
        Factory() = default;
        std::map<uint32_t, CreateFunction> _creators;
    };

} // namespace TestImplementation
} // namespace Thunder
