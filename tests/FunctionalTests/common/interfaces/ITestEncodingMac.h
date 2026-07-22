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

    // Exercises @encode:mac behavior for fixed-size MAC address buffers.
    // @json 1.0.0
    struct EXTERNAL ITestEncodingMac : virtual public Core::IUnknown {
        enum { ID = ID_TEST_ENCODING_MAC };

        // @brief Stores a 6-byte MAC address.
        //        In JSON-RPC, @encode:mac should map the byte array to a string
        //        representation (for example, "01:23:45:67:89:ab").
        // @param mac Input 6-byte MAC address.
        // @retval ERROR_NONE Address stored.
        virtual Core::hresult SetMacAddress(
            const uint8_t mac[] /* @in @length:6 @encode:mac */) = 0;

        // @brief Retrieves the previously stored 6-byte MAC address.
        // @param mac Receives stored 6-byte MAC address.
        // @retval ERROR_NONE Address returned.
        virtual Core::hresult GetMacAddress(
            uint8_t mac[] /* @out @length:6 @maxlength:6 @encode:mac */) const = 0;

        // @brief Echoes a MAC address to verify round-trip conversion.
        // @param input  Input 6-byte MAC address.
        // @param output Receives echoed 6-byte MAC address.
        // @retval ERROR_NONE Echo completed.
        virtual Core::hresult EchoMacAddress(
            const uint8_t input[] /* @in @length:6 @encode:mac */,
            uint8_t output[] /* @out @length:6 @maxlength:6 @encode:mac */) const = 0;

        // =================================================================
        // Variable-length encode:mac — works with any buffer size
        // =================================================================

        // @brief Store a variable-length buffer using colon-hex (mac) encoding.
        //        Verifies encode:mac works with buffers of any size, not just 6 bytes.
        // @param data Input bytes.
        // @param size Number of bytes in data.
        virtual Core::hresult SetVariableMac(
            const uint8_t data[] /* @in @length:size @encode:mac */,
            const uint16_t size /* @restrict:1..32 */) = 0;

        // @brief Retrieve the stored variable-length mac-encoded buffer.
        // @param data Output buffer.
        // @param maxSize Capacity of the output buffer.
        // @param written Receives actual bytes written.
        virtual Core::hresult GetVariableMac(
            uint8_t data[] /* @out @length:written @maxlength:maxSize @encode:mac */,
            const uint16_t maxSize,
            uint16_t& written /* @out */) = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
