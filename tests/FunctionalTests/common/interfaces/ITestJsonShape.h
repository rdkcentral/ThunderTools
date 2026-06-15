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

    // Exercises JSON payload shape tags that are not covered by existing
    // interfaces. Intended primarily for JsonGenerator functional tests.
    // @json 1.0.0
    struct EXTERNAL ITestJsonShape : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_SHAPE };

        // @brief Returns a single scalar result using an object envelope even when
        //        one return value would otherwise be emitted without wrapping.
        // @param counter Receives the current counter value.
        // @retval ERROR_NONE Counter value returned.
        // @wrapped
        virtual Core::hresult GetWrappedCounter(uint32_t& counter /* @out */) const = 0;

        // @brief Echoes a list and requests single-element extraction in JSON.
        //        When the list has exactly one element, JSON may collapse it from
        //        [x] to x depending on the generator behavior.
        // @param input  Input list to echo.
        // @param output Receives echoed list.
        // @retval ERROR_NONE Echo completed.
        virtual Core::hresult EchoExtractedList(
            const std::vector<uint32_t>& input /* @in @extract @restrict:1..64 */,
            std::vector<uint32_t>& output /* @out @extract @restrict:1..64 */) const = 0;

        // @brief Echoes a struct and requests collapsed representation in JSON.
        struct Dimensions {
            uint16_t width;
            uint16_t height;
        };

        // @brief Echoes a struct and requests collapsed representation in JSON.
        // @param in  Input Dimensions value.
        // @param out Receives echoed Dimensions value.
        // @retval ERROR_NONE Echo completed.
        virtual Core::hresult EchoExtractedStruct(
            const Dimensions& in /* @in */,
            Dimensions& out /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
