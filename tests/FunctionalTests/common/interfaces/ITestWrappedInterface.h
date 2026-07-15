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

    // Tests interface-level wrapped annotation.
    // ALL single-value returns are wrapped in an object using the output
    // parameter name as key, e.g. GetCounter returns {"counter":N},
    // GetName returns {"name":"..."}, Echo returns {"result":N}.
    //
    // @json 1.0.0
    // @wrapped
    struct EXTERNAL ITestWrappedInterface : virtual public Core::IUnknown {
        enum { ID = ID_TEST_WRAPPED_INTERFACE };

        // @brief Get a counter value. Returns {"counter":N} on the wire.
        // @param counter Receives the counter value.
        virtual Core::hresult GetCounter(uint32_t& counter /* @out */) const = 0;

        // @brief Get a name string. Returns {"name":"..."} on the wire.
        // @param name Receives the name.
        virtual Core::hresult GetName(string& name /* @out */) const = 0;

        // @brief Echo a value. Returns {"result":N} on the wire.
        // @param value Input value.
        // @param result Receives echoed value.
        virtual Core::hresult Echo(const uint32_t value /* @in */, uint32_t& result /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
