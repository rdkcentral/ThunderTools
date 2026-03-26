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

    // Test @restrict annotation for value and size range validation.
    // @json 1.0.0
    struct EXTERNAL ITestRestrictions : virtual public Core::IUnknown {
        enum { ID = ID_TEST_RESTRICTIONS };

        // ===== Unsigned integer restrictions =====

        // @brief Accept exactly the value 42.
        //        The @ restrict:42 annotation restricts the parameter to a single fixed value.
        // @param value Must equal 42.
        // @retval ERROR_INVALID_INPUT value != 42.
        virtual Core::hresult SetFixedValue(const uint8_t value /* @in @restrict:42 */) = 0;

        // @brief Set a percentage value in the range [0, 100].
        // @param percent Value to store; must be in [0, 100].
        // @retval ERROR_INVALID_INPUT percent > 100.
        virtual Core::hresult SetPercentage(const uint8_t percent /* @in @restrict:0..100 */) = 0;

        // FIXME: open-ended restrict ranges (min-only or max-only) are not yet confirmed
        // to generate correct code in all cases. Left commented pending generator validation.
        // virtual Core::hresult SetPositive(const uint32_t value /* @ in @ restrict:1.. */) = 0;
        // virtual Core::hresult SetSmall(const uint16_t value /* @ in @ restrict:..1000 */) = 0;
        // virtual Core::hresult SetBufferSize(const uint32_t size /* @ in @ restrict:1K..16M */) = 0;

        // @brief Store a byte value and echo it back.
        //        The full uint8_t range [0, 255] is valid.
        // FIXME: parse error: in/out tags not allowed here
        // @param value  Byte value to store; @ restrict:0..255 covers the full uint8_t range.
        // @param result Receives a copy of value.
        virtual Core::hresult SetByte(const uint8_t value /* @in @restrict:0..255 */, uint8_t& result /* @out */) = 0;

        // ===== Signed integer restrictions =====

        // @brief Store a temperature in degrees Celsius, restricted to [-40, 125].
        //        This range covers the typical automotive/industrial operating range.
        // @param temp Temperature in °C; must be in [-40, 125].
        // @retval ERROR_INVALID_INPUT temp is outside the allowed range.
        virtual Core::hresult SetTemperature(const int8_t temp /* @in @restrict:-40..125 */) = 0;

        // @brief Store a negative int16_t value in the range [-1000, -1].
        // @param value Must be in [-1000, -1] (strictly negative).
        // @retval ERROR_INVALID_INPUT value >= 0 or value < -1000.
        virtual Core::hresult SetNegative(const int16_t value /* @in @restrict:-1000..-1 */) = 0;

        // @brief Store a positive (non-zero) int32_t value in the range [1, 1000].
        // @param value Must be in [1, 1000] (strictly positive).
        // @retval ERROR_INVALID_INPUT value <= 0 or value > 1000.
        virtual Core::hresult SetPositiveSigned(const int16_t value /* @in @restrict:1..1000 */) = 0;

        // @brief Store a signed byte-range offset using an int16_t parameter.
        //        Tests that @ restrict can narrow the valid range of a wider type.
        // @param offset Signed offset; must be in [-127, 127] even though the parameter type is int16_t.
        // @retval ERROR_INVALID_INPUT offset is outside [-127, 127].
        virtual Core::hresult SetOffset(const int16_t offset /* @in @restrict:-127..127 */) = 0;

        // ===== Floating point restrictions =====

        // @brief Store a normalised ratio in [0.0, 1.0].
        // @param ratio Must be in [0.0, 1.0].
        // @retval ERROR_INVALID_INPUT ratio < 0.0 or ratio > 1.0.
        virtual Core::hresult SetRatio(const float ratio /* @in @restrict:0.0..1.0 */) = 0;

        // @brief Store a mains voltage in [0.0, 240.0] volts.
        // @param volts Must be in [0.0, 240.0].
        // @retval ERROR_INVALID_INPUT volts < 0.0 or volts > 240.0.
        virtual Core::hresult SetVoltage(const double volts /* @in @restrict:0.0..240.0 */) = 0;

        // @brief Store an attenuation value in decibels in [-100.0, 0.0].
        //        Negative dB values represent attenuation; 0.0 represents unity gain.
        // @param db Must be in [-100.0, 0.0].
        // @retval ERROR_INVALID_INPUT db < -100.0 or db > 0.0.
        virtual Core::hresult SetDecibels(const float db /* @in @restrict:-100.0..0.0 */) = 0;

        // @brief Store an audio frequency in [20.0, 20000.0] Hz (typical audible range).
        // @param hz Must be in [20.0, 20000.0].
        // @retval ERROR_INVALID_INPUT hz < 20.0 or hz > 20000.0.
        virtual Core::hresult SetFrequency(const double hz /* @in @restrict:20.0..20000.0 */) = 0;

        // ===== String restrictions =====

        // @brief Store a display name that is 1 to 64 characters long.
        //        The @ restrict:1..64 annotation applies to the string length in bytes.
        // @param name Non-empty string of at most 64 bytes.
        // @retval ERROR_INVALID_INPUT name is empty or longer than 64 bytes.
        virtual Core::hresult SetName(const string& name /* @in @restrict:1..64 */) = 0;

        // @brief Store a username that must be non-empty.
        //        The @ restrict:nonempty annotation is a shorthand for a lower bound of 1.
        // @param username Non-empty string; no upper bound is enforced.
        // @retval ERROR_INVALID_INPUT username is empty.
        virtual Core::hresult SetUsername(const string& username /* @in @restrict:nonempty */) = 0;

        // FIXME: open-ended string restrict ranges — see integer FIXME above.
        // virtual Core::hresult SetPassword(const string& password /* @ in @ restrict:8.. */) = 0;
        // virtual Core::hresult SetShortCode(const string& code /* @ in @ restrict:..8 */) = 0;

        // ===== Buffer restrictions =====

        // FIXME: buffer restrict combinations below are left commented pending generator validation.
        // virtual Core::hresult ProcessData(
        //     const uint8_t data[] /* @ in @ length:size @ restrict:1..64K */,
        //     const uint32_t size) = 0;

        // virtual Core::hresult ProcessNonEmpty(
        //     const uint8_t data[] /* @ in @ length:size @ restrict:nonempty */,
        //     const uint32_t size) = 0;

        // virtual Core::hresult ProcessMinimum(
        //     const uint8_t data[] /* @ in @ length:size @ restrict:16.. */,
        //     const uint32_t size) = 0;

        // virtual Core::hresult FillBuffer(
        //     uint8_t buffer[] /* @ out @ length:written @ maxlength:capacity @ restrict:..1K */,
        //     const uint16_t capacity,
        //     uint16_t& written /* @ out */) = 0;

        // ===== Multiple parameters with restrictions =====

        // @brief Add two clamped integers, each restricted to [-100, 100].
        //        Tests that @ restrict applies independently to each parameter.
        // @param a      First addend; must be in [-100, 100].
        // @param b      Second addend; must be in [-100, 100].
        // @param result Receives a + b (may exceed the parameter range).
        // @retval ERROR_INVALID_INPUT a or b is outside [-100, 100].
        virtual Core::hresult ClampedAdd(
            const int8_t a /* @in @restrict:-100..100 */,
            const int8_t b /* @in @restrict:-100..100 */,
            int16_t& result /* @out */) const
            = 0;

        // @brief Configure a subsystem with mode, timeout, and gain.
        //        Tests multiple heterogeneous restrict ranges in one call.
        // @param mode    Operating mode; must be in [0, 3].
        // @param timeout Response timeout in milliseconds; must be in [100, 30000].
        // @param gain    Signal gain multiplier; must be in [0.0, 10.0].
        // @retval ERROR_INVALID_INPUT any parameter is outside its allowed range.
        virtual Core::hresult Configure(
            const uint8_t mode /* @in @restrict:0..3 */,
            const uint16_t timeout /* @in @restrict:100..30000 */,
            const float gain /* @in @restrict:0.0..10.0 */)
            = 0;

        // ===== Reference parameters with restrictions =====

        // @brief Return the minimum and maximum of the current percentage range.
        //        Both outputs are guaranteed to be in [0, 100].
        // @param min Receives the lower bound of the current range.
        // @param max Receives the upper bound of the current range.
        virtual Core::hresult GetRange(
            uint8_t& min /* @out @restrict:0..100 */,
            uint8_t& max /* @out @restrict:0..100 */) const
            = 0;

        // @brief Clamp an inout value to [-1000, 1000] in place.
        //        On entry value may be outside the range; on return it is clamped.
        // @param value In: unclamped integer.  Out: value clamped to [-1000, 1000].
        virtual Core::hresult ClampValue(
            int16_t& value /* @inout @restrict:-1000..1000 */)
            = 0;

        // ===== Output parameters with restrictions =====

        // @brief Return the current percentage setting.
        //        The @ restrict:0..100 on the output parameter documents the guaranteed range.
        // @param value Receives the current percentage in [0, 100].
        virtual Core::hresult GetPercentage(uint8_t& value /* @out @restrict:0..100 */) const = 0;

        // @brief Return the current normalised ratio.
        //        The @ restrict:0.0..1.0 on the output parameter documents the guaranteed range.
        // @param value Receives the current ratio in [0.0, 1.0].
        virtual Core::hresult GetRatio(float& value /* @out @restrict:0.0..1.0 */) const = 0;

        // ===== Edge cases and combinations =====

        // FIXME: max-only string restrict — see string FIXME above.
        // virtual Core::hresult SetOptionalName(const string& name /* @ in @ restrict:..256 */) = 0;

        // FIXME: G-suffix restrict — pending generator validation.
        // virtual Core::hresult SetHugeSize(const uint32_t size /* @ in @ restrict:..1G */) = 0;

        // @brief Accept exactly the value 4096 (4K).
        //        Tests the K-suffix shorthand in @ restrict, which the generator expands to 4096.
        // @param size Must equal 4096.
        // @retval ERROR_INVALID_INPUT size != 4096.
        virtual Core::hresult SetPageSize(const uint16_t size /* @in @restrict:4K */) = 0;

        // @brief Optionally set a TCP port number in [1, 65535].
        //        Tests combination of Core::OptionalType with a restrict range.
        //        When port is not set no change is made to the stored port.
        // @param port Optional port number; must be in [1, 65535] when set.
        // @retval ERROR_INVALID_INPUT port is set and outside [1, 65535].
        virtual Core::hresult SetPort(const Core::OptionalType<uint16_t>& port /* @in @restrict:1..65535 */) = 0;

        // ===== Validation helpers =====

        // @brief Test whether a value is a valid percentage (in [0, 100]) without storing it.
        // @param value Value to test.
        // @param valid Receives true if value is in [0, 100].
        virtual Core::hresult IsValidPercentage(const uint8_t value /* @in */, bool& valid /* @out */) const = 0;

        // @brief Test whether a value is a valid temperature (in [-40, 125]) without storing it.
        // @param temp  Value to test.
        // @param valid Receives true if temp is in [-40, 125].
        virtual Core::hresult IsValidTemperature(const int32_t temp /* @in */, bool& valid /* @out */) const = 0;

        // @brief Test whether a value is a valid normalised ratio (in [0.0, 1.0]) without storing it.
        // @param ratio Value to test.
        // @param valid Receives true if ratio is in [0.0, 1.0].
        virtual Core::hresult IsValidRatio(const float ratio /* @in */, bool& valid /* @out */) const = 0;

        // @brief Return the effective [min, max] bounds used by SetPercentage.
        // @param min Receives the lower bound (always 0).
        // @param max Receives the upper bound (always 100).
        virtual Core::hresult GetPercentageRange(uint8_t& min /* @out */, uint8_t& max /* @out */) const = 0;

        // @brief Return the effective [min, max] bounds used by SetTemperature.
        // @param min Receives the lower bound (always -40).
        // @param max Receives the upper bound (always 125).
        virtual Core::hresult GetTemperatureRange(int32_t& min /* @out */, int32_t& max /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder