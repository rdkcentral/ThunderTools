/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2024 Metrological
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

#include "Module.h"
#include "Ids.h"

namespace Thunder {
    namespace FunctionalTest {
        // @json 1.0.0
        struct EXTERNAL ITestPrimitives : virtual public Core::IUnknown {

            enum { ID = ID_TEST_PRIMITIVES };

            // --- Signed integers ---

            //  @brief Round-trip marshalling test for int8_t
            virtual Core::hresult EchoInt8(const int8_t input /* @in */, int8_t& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for int16_t
            virtual Core::hresult EchoInt16(const int16_t input /* @in */, int16_t& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for int24_t (24-bit signed)
            virtual Core::hresult EchoInt24(const int24_t input /* @in */, int24_t& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for int32_t
            virtual Core::hresult EchoInt32(const int32_t input /* @in */, int32_t& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for int64_t
            virtual Core::hresult EchoInt64(const int64_t input /* @in */, int64_t& output /* @out */) = 0;

            // --- Unsigned integers ---

            //  @brief Round-trip marshalling test for uint8_t
            virtual Core::hresult EchoUInt8(const uint8_t input /* @in */, uint8_t& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for uint16_t
            virtual Core::hresult EchoUInt16(const uint16_t input /* @in */, uint16_t& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for Core::UInt24 (24-bit unsigned)
            virtual Core::hresult EchoUInt24(const Core::UInt24 input /* @in */, Core::UInt24& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for uint32_t
            virtual Core::hresult EchoUInt32(const uint32_t input /* @in */, uint32_t& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for uint64_t
            virtual Core::hresult EchoUInt64(const uint64_t input /* @in */, uint64_t& output /* @out */) = 0;

            // --- Floating point ---

            //  @brief Round-trip marshalling test for float (single precision)
            virtual Core::hresult EchoFloat(const float input /* @in */, float& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for double (double precision)
            virtual Core::hresult EchoDouble(const double input /* @in */, double& output /* @out */) = 0;

            // --- Boolean ---

            //  @brief Round-trip marshalling test for bool
            virtual Core::hresult EchoBool(const bool input /* @in */, bool& output /* @out */) = 0;

            // --- Strings ---

            // --- Special platform types ---

            //  @brief Round-trip marshalling test for Core::instance_id (32/64-bit hex value in JSON-RPC)
            virtual Core::hresult EchoInstanceId(const Core::instance_id input /* @in */, Core::instance_id& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for Core::Time (ISO 8601 in JSON-RPC, uint64 ticks on wire)
            virtual Core::hresult EchoTime(const Core::Time input /* @in */, Core::Time& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for Core::MACAddress (6-byte buffer on wire, string in JSON-RPC)
            virtual Core::hresult EchoMACAddress(const Core::MACAddress input /* @in */, Core::MACAddress& output /* @out */) = 0;

            // --- Strings ---

            //  @brief Round-trip marshalling test for std::string (reference-counted, JSON-friendly)
            virtual Core::hresult EchoString(const string& input /* @in */, string& output /* @out */) = 0;

            //  @brief Round-trip marshalling test for const char* (raw C-string, distinct marshalling path).
            //         Caller pre-allocates output buffer; maxLength carries the buffer capacity in and
            //         the number of bytes written out.
            // FIXME: this will generate non-compiling code... 
            // @ json:omit  (raw buffer pattern has no clean JSON-RPC mapping)
            // virtual Core::hresult EchoCharPtr(const char* input /* @ in @ length:maxLength @ restrict:255 */, char* output /* @ out @ maxlength:maxLength */, uint8_t& maxLength /* @ inout */) = 0;
        };
    } // namespace FunctionalTest
} // namespace Thunder