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

#include <cstdint>

namespace Thunder {
    namespace FunctionalTest {

    constexpr uint32_t ID_INTERFACE_OFFSET = 0xA000; // Base offset for test interface IDs
    
    enum IDs : uint32_t {
        ID_TEST_PRIMITIVES              = ID_INTERFACE_OFFSET + 0x001,
        ID_TEST_BUFFERS                 = ID_INTERFACE_OFFSET + 0x002,
        ID_TEST_OPTIONALS               = ID_INTERFACE_OFFSET + 0x003,
        ID_TEST_ENUMS                   = ID_INTERFACE_OFFSET + 0x004,
        ID_TEST_STRUCTS                 = ID_INTERFACE_OFFSET + 0x005,
        ID_TEST_INTERFACE_POINTERS      = ID_INTERFACE_OFFSET + 0x006,
        ID_TEST_ITERATORS               = ID_INTERFACE_OFFSET + 0x007,
        ID_TEST_EVENTS                  = ID_INTERFACE_OFFSET + 0x008,
        ID_TEST_EVENTS_NOTIFICATION     = ID_INTERFACE_OFFSET + 0x009,
        ID_TEST_RESTRICTIONS            = ID_INTERFACE_OFFSET + 0x00A,
        ID_TEST_ASYNC                   = ID_INTERFACE_OFFSET + 0x00B,
        ID_TEST_ASYNC_CALLBACK          = ID_INTERFACE_OFFSET + 0x00C,
    };

} // namespace FunctionalTest
} // namespace Thunder
