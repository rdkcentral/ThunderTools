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

    // Test optional parameter handling with Core::OptionalType<T>
    // Core::OptionalType<T> supersedes the @optional tag from Thunder R4+.
    // @json 1.0.0
    struct EXTERNAL ITestOptionals : virtual public Core::IUnknown {
        enum { ID = ID_TEST_OPTIONALS };

        // ===== Optional input parameters =====

        // @brief Add two numbers. When b is not set it defaults to 0.
        // @param a      First operand.
        // @param b      Optional second operand; treated as 0 when not set. @default:0
        // @param result Receives a + b (or a + 0 when b is not set).
        virtual Core::hresult Add(
            const uint32_t a /* @in */,
            const Core::OptionalType<uint32_t>& b /* @in @default:0 */,
            uint32_t& result /* @out */) = 0;

        // @brief Multiply a value by an optional multiplier. When multiplier is not set
        //        the input value is returned unchanged (effective multiplier is 1).
        // @param value      Value to scale.
        // @param multiplier Optional scale factor; treated as 1 when not set. @default:1
        // @param result     Receives value * multiplier.
        virtual Core::hresult Multiply(
            const int32_t value /* @in */,
            const Core::OptionalType<int32_t>& multiplier /* @in @default:1 */,
            int32_t& result /* @out */) = 0;

        // @brief Concatenate two strings. When second is not set it defaults to an empty string.
        // @param first  First string.
        // @param second Optional second string; treated as "" when not set. @default:""
        // @param result Receives first + second.
        virtual Core::hresult Concatenate(
            const string& first /* @in */,
            const Core::OptionalType<string>& second /* @in @default:"" */,
            string& result /* @out */) = 0;

        // ===== Optional output parameters =====

        // @brief Perform integer division and optionally return the remainder.
        //        Pass an unset remainder to indicate the caller does not need it.
        // @param dividend  Numerator.
        // @param divisor   Denominator; must not be zero.
        // @param quotient  Receives dividend / divisor.
        // @param remainder Optional out; when set on return it receives dividend % divisor.
        // @retval ERROR_BAD_REQUEST divisor is zero.
        virtual Core::hresult Divide(
            const uint32_t dividend /* @in */,
            const uint32_t divisor /* @in */,
            uint32_t& quotient /* @out */,
            Core::OptionalType<uint32_t>& remainder /* @out */) = 0;

        // @brief Parse a decimal integer string.
        //        Pass an unset success to ignore the parse-success flag.
        // @param text    String to parse (e.g. "-42").
        // @param value   Receives the parsed integer; undefined when parsing fails.
        // @param success Optional out; when set on return it receives true if parsing succeeded.
        virtual Core::hresult ParseInt(
            const string& text /* @in */,
            int32_t& value /* @out */,
            Core::OptionalType<bool>& success /* @out */) = 0;

        // ===== Multiple optional parameters =====

        // @brief Wrap a string with optional prefix and suffix.
        //        Unset prefix or suffix are treated as empty strings.
        // @param text   Core string to format.
        // @param prefix Optional string prepended to text. @default:""
        // @param suffix Optional string appended to text.  @default:""
        // @param result Receives prefix + text + suffix.
        virtual Core::hresult Format(
            const string& text /* @in */,
            const Core::OptionalType<string>& prefix /* @in @default:"" */,
            const Core::OptionalType<string>& suffix /* @in @default:"" */,
            string& result /* @out */) = 0;

        // @brief Clamp value to an optional [min, max] range.
        //        When min is not set no lower bound is applied.
        //        When max is not set no upper bound is applied.
        // @param value  Input value to clamp.
        // @param min    Optional lower bound.
        // @param max    Optional upper bound.
        // @param result Receives the clamped value.
        virtual Core::hresult Calculate(
            const int32_t value /* @in */,
            const Core::OptionalType<int32_t>& min /* @in */,
            const Core::OptionalType<int32_t>& max /* @in */,
            int32_t& result /* @out */) = 0;

        // ===== Optional buffers =====

        // @brief Process an input buffer into an output buffer.
        //        Raw C arrays cannot use Core::OptionalType directly.  Pass maxOutputSize=0
        //        to indicate that no output is required; in that case written will be 0 on return.
        // @param input         Input bytes; length determined by inputSize.
        // @param inputSize     Number of bytes in input.
        // @param output        Caller-allocated output buffer; capacity given by maxOutputSize.
        // @param maxOutputSize Capacity of output in bytes; pass 0 to skip output generation.
        // @param written       Receives the number of bytes written to output.
        virtual Core::hresult ProcessOptionalBuffer(
            const uint8_t input[] /* @in @length:inputSize */,
            const uint16_t inputSize,
            uint8_t output[] /* @out @length:written @maxlength:maxOutputSize */,
            const uint16_t maxOutputSize,
            uint16_t& written /* @out */) = 0;

        // ===== Edge cases =====

        // @brief Compute a result from up to three optional unsigned integers.
        //        Unset operands contribute 0 to the sum.
        // @param a      First optional operand.
        // @param b      Second optional operand.
        // @param c      Third optional operand.
        // @param result Receives the sum of all set operands (0 when all are unset).
        virtual Core::hresult AllOptional(
            const Core::OptionalType<uint32_t>& a /* @in */,
            const Core::OptionalType<uint32_t>& b /* @in */,
            const Core::OptionalType<uint32_t>& c /* @in */,
            uint32_t& result /* @out */) = 0;

        // @brief Return a string, optionally converted to uppercase.
        //        When uppercase is not set it defaults to false (no conversion).
        // @param value     Input string.
        // @param uppercase Optional flag; when true the result is uppercased. @default:false
        // @param result    Receives the (possibly transformed) string.
        virtual Core::hresult WithDefault(
            const string& value /* @in */,
            const Core::OptionalType<bool>& uppercase /* @in @default:false*/,
            string& result /* @out */) = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder