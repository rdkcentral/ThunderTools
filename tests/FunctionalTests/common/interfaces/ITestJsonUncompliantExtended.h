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
    // @uncompliant:extended
    //
    // NOTE: @uncompliant:extended is deprecated (Thunder docs/interfaces/tags.md) and must not
    // be used in new interfaces. This interface exists solely to pin generator behaviour for
    // existing consumers that already use this mode. Do not copy PingExtended as a usage example.
    struct EXTERNAL ITestJsonUncompliantExtended : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_UNCOMPLIANT_EXT };

        // @brief Interface-level tag target for extended uncompliant mode.
        // @param payload Input payload.
        // @param reply   Receives output payload.
        // @retval ERROR_NONE Operation completed.
        virtual Core::hresult PingExtended(const string& payload /* @in */, string& reply /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
