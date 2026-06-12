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
    // @text:keep
    struct EXTERNAL ITestJsonTextKeep : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_TEXT_KEEP };

        // @brief Verifies that the original C++ identifier casing is preserved
        //        in generated JSON names when @text:keep is enabled.
        // @param InputValue  Input value used for round-trip verification.
        // @param OutputValue Receives echoed value.
        // @retval ERROR_NONE Echo completed.
        virtual Core::hresult EchoMixedCaseName(const uint32_t InputValue /* @in */, uint32_t& OutputValue /* @out */) const = 0;

        // @property
        // @brief Build version property.
        // @param BuildVersion Receives current build version value.
        // @retval ERROR_NONE Value returned.
        virtual Core::hresult BuildVersion(uint32_t& BuildVersion /* @out */) const = 0;
    };

    // @json 1.0.0
    // @text:camelcase
    struct EXTERNAL ITestJsonTextCase : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_TEXT_CASE };

        // @brief Verifies case-convention transformation in generated JSON names.
        // @param sourceValue Input value for round-trip verification.
        // @param resultValue Receives echoed value.
        // @retval ERROR_NONE Echo completed.
        virtual Core::hresult EchoCaseConvention(const uint16_t sourceValue /* @in */, uint16_t& resultValue /* @out */) const = 0;
    };

    // @json 1.0.0
    // @compliant
    struct EXTERNAL ITestJsonCompliant : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_COMPLIANT };

        // @brief Baseline interface for compliant JSON-RPC format generation.
        // @param payload Input payload.
        // @param reply   Receives output payload.
        // @retval ERROR_NONE Operation completed.
        virtual Core::hresult Ping(const string& payload /* @in */, string& reply /* @out */) const = 0;
    };

    // @json 1.0.0
    // @uncompliant:extended
    struct EXTERNAL ITestJsonUncompliantExtended : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_UNCOMPLIANT_EXT };

        // @brief Interface-level tag target for extended uncompliant mode.
        // @param payload Input payload.
        // @param reply   Receives output payload.
        // @retval ERROR_NONE Operation completed.
        virtual Core::hresult PingExtended(const string& payload /* @in */, string& reply /* @out */) const = 0;
    };

    // @json 1.0.0
    // @uncompliant:collapsed
    struct EXTERNAL ITestJsonUncompliantCollapsed : virtual public Core::IUnknown {
        enum { ID = ID_TEST_JSON_UNCOMPLIANT_COL };

        // @brief Interface-level tag target for collapsed uncompliant mode.
        // @param payload Input payload.
        // @param reply   Receives output payload.
        // @retval ERROR_NONE Operation completed.
        virtual Core::hresult PingCollapsed(const string& payload /* @in */, string& reply /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
