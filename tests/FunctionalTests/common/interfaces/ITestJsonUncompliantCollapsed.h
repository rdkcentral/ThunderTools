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
    // @uncompliant:collapsed
    //
    // NOTE: @uncompliant:collapsed is deprecated (Thunder docs/plugin/interfaces/tags.md) and must not
    // be used in new interfaces. This interface exists solely to pin generator behaviour for
    // existing consumers that already use this mode. Do not copy this interface as a usage example.
    struct EXTERNAL ITestJsonUncompliantCollapsed : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_UNCOMPLIANT_COL };

        // @brief Echo method — single-param method.
        //        In @uncompliant:collapsed mode, a single method parameter is sent as a bare
        //        scalar (e.g. "abc", not {"payload":"abc"}).
        // @param payload Input payload.
        // @param reply   Receives output payload.
        // @retval ERROR_NONE Operation completed.
        virtual Core::hresult PingCollapsed(const string& payload /* @in */, string& reply /* @out */) const = 0;

        // @property
        // @brief Stored counter value — read/write.
        //        Captures the essential property behaviour of uncompliant:collapsed mode:
        //        the SET request sends the value as a bare scalar (e.g. 42),
        //        not wrapped in an object as compliant mode would.
        //        The GET response is placed in the "params" field of the JSON-RPC envelope
        //        (not "result" as in compliant and uncompliant:extended modes).
        // @param counter Counter value to store or retrieve.
        virtual Core::hresult Value(uint32_t& counter /* @out */) const = 0;
        virtual Core::hresult Value(const uint32_t counter /* @in */) = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
