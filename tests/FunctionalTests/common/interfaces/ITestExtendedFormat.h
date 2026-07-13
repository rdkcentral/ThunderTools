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

    // =========================================================================
    // ITestExtendedFormat
    //
    // Validates the extended format semantics:
    //   - Methods use compliant-style named object params
    //   - Properties use collapsed format (value sent directly, no wrapping)
    //
    // @json 1.0.0
    // @uncompliant:extended
    // =========================================================================
    struct EXTERNAL ITestExtendedFormat : virtual public Core::IUnknown {
        enum { ID = ID_TEST_EXTENDED_FORMAT };

        // @brief A method that takes a single parameter.
        //        With extended format, methods still wrap params in a named object.
        // @param value Input value.
        // @param result Receives the echoed value.
        virtual Core::hresult EchoMethod(const uint32_t value /* @in */, uint32_t& result /* @out */) const = 0;

        // @brief A method with multiple parameters.
        //        With extended format, methods always use named object wrapping.
        // @param a First operand.
        // @param b Second operand.
        // @param result Receives a + b.
        virtual Core::hresult AddMethod(const uint32_t a /* @in */, const uint32_t b /* @in */, uint32_t& result /* @out */) const = 0;

        // @property
        // @brief A read-write property.
        //        With extended format, property GET returns the value directly (collapsed).
        //        Property SET accepts the value directly (collapsed).
        virtual Core::hresult Volume(uint32_t& volume /* @out */) const = 0;
        virtual Core::hresult Volume(const uint32_t volume /* @in */) = 0;

        // @property
        // @brief A read-only string property.
        //        With extended format, GET returns the string directly without wrapping.
        virtual Core::hresult Name(string& name /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
