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

    // @json 1.0.0
    // @text:legacy
    struct EXTERNAL ITestJsonTextCase : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_TEXT_CASE };

        // @brief Verifies case-convention transformation in generated JSON names.
        // @param sourceValue Input value for round-trip verification.
        // @param resultValue Receives echoed value.
        // @retval ERROR_NONE Echo completed.
        virtual Core::hresult EchoCaseConvention(const uint16_t sourceValue /* @in */, uint16_t& resultValue /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
