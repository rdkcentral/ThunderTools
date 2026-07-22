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

#include "Ids.h"
#include "Module.h"

namespace Thunder {
namespace FunctionalTest {

    // Tests the underscore prefix separator variant.
    // When prefix ends with '_', no '::' separator is added.
    // Method 'Echo' becomes 'flat_echo' on the wire (not 'flat::echo').
    //
    // @json 1.0.0
    // @prefix flat_
    struct EXTERNAL ITestPrefixUnderscore : virtual public Core::IUnknown {
        enum { ID = ID_TEST_PREFIX_UNDERSCORE };

        // @brief Echo a value using flat prefix naming.
        // @param value Input value.
        // @param result Receives echoed value.
        virtual Core::hresult Echo(const uint32_t value /* @in */, uint32_t& result /* @out */) const = 0;

        // @brief Add two values.
        // @param a First operand.
        // @param b Second operand.
        // @param result Receives a + b.
        virtual Core::hresult Add(const uint32_t a /* @in */, const uint32_t b /* @in */, uint32_t& result /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
