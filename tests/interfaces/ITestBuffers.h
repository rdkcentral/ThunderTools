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

    // Test buffer passing with @length and @maxlength annotations
    // FIXME: @json 1.0.0 generates uncompilable code for buffer methods.
    struct EXTERNAL ITestBuffers : virtual public Core::IUnknown {
        enum { ID = ID_TEST_BUFFERS };

        // FIXME: ProxyStubGenerator: Fixed-size array parameters generate invalid proxy signatures
        // // ===== Fixed-size arrays =====

        // // @brief Echo a 4-byte buffer unchanged.
        // // @param input  Source buffer (exactly 4 bytes).
        // // @param output Destination buffer; receives a copy of input.
        // virtual Core::hresult EchoFixed4(
        //     const uint8_t input[4] /* @ in */,
        //     uint8_t output[4] /* @ out */) = 0;

        // // @brief Echo a 4-element uint32_t array unchanged.
        // // @param input  Source array (exactly 4 words).
        // // @param output Destination array; receives a copy of input.
        // virtual Core::hresult EchoFixed4Words(
        //     const uint32_t input[4] /* @ in */,
        //     uint32_t output[4] /* @ out */) = 0;

        // // @brief XOR every byte of an 8-byte buffer in-place with a scalar key.
        // // @param data Buffer to transform (exactly 8 bytes, read then written back).
        // // @param key  Single-byte XOR mask applied to each element.
        // virtual Core::hresult XorFixed8(
        //     uint8_t data[8] /* @ inout */,
        //     const uint8_t key /* @ in */) = 0;

        // // @brief Store a 16-byte key.  The @encode:base64 annotation causes the
        // //        JSON-RPC layer to transmit the raw bytes as a base64 string.
        // // @param key 16-byte key to store.
        // virtual Core::hresult SetKey(const uint8_t key[16] /* @ in @ encode:base64 */) = 0;

        // // @brief Retrieve the previously stored 16-byte key.
        // //        The @encode:base64 annotation causes the JSON-RPC layer to return the
        // //        raw bytes as a base64 string.
        // // @param key Receives the stored key.
        // virtual Core::hresult GetKey(uint8_t key[16] /* @ out @ encode:base64 */) const = 0;

        // // @brief Store an 8-byte token.  The @encode:hex annotation causes the
        // //        JSON-RPC layer to transmit the raw bytes as a hex string.
        // // @param token 8-byte token to store.
        // virtual Core::hresult SetToken(const uint8_t token[8] /* @ in @ encode:hex */) = 0;

        // // @brief Retrieve the previously stored 8-byte token.
        // //        The @encode:hex annotation causes the JSON-RPC layer to return the
        // //        raw bytes as a hex string.
        // // @param token Receives the stored token.
        // virtual Core::hresult GetToken(uint8_t token[8] /* @ out @ encode:hex */) const = 0;

        // ===== Input buffers with length =====

        // @brief Sum all bytes in a variable-length input buffer.
        // @param buffer Input bytes; length determined by size.
        // @param size   Number of bytes in buffer.
        // @param sum    Receives the arithmetic sum of all bytes.
        virtual Core::hresult SumBytes(
            const uint8_t buffer[] /* @in @length:size */,
            const uint16_t size,
            uint32_t& sum /* @out */) = 0;

        // @brief Calculate a simple checksum over a variable-length input buffer.
        // @param data     Input bytes; length determined by length.
        // @param length   Number of bytes in data.
        // @param checksum Receives the computed checksum value.
        virtual Core::hresult Checksum(
            const uint8_t data[] /* @in @length:length */,
            const uint32_t length /* @restrict:4194303 */,
            uint32_t& checksum /* @out */) = 0;

        // ===== Output buffers with maxlength =====

        // @brief Fill an output buffer with sequential byte values starting from start.
        //        Writes min(maxSize, 256) bytes.
        // @param buffer  Caller-allocated output buffer; capacity given by maxSize.
        // @param maxSize Capacity of buffer in bytes (@maxlength guard).
        // @param start   First byte value; subsequent values increment by 1 (wrapping at 255).
        // @param written Receives the number of bytes actually written.
        virtual Core::hresult FillSequence(
            uint8_t buffer[] /* @out @length:written @maxlength:maxSize */,
            const uint16_t maxSize,
            const uint8_t start,
            uint16_t& written /* @out */) = 0;

        // @brief Fill an output buffer with a repeated single-byte pattern.
        // @param buffer   Caller-allocated output buffer; capacity given by capacity.
        // @param capacity Capacity of buffer in bytes (@maxlength guard).
        // @param pattern  Byte value to repeat throughout the buffer.
        // @param written  Receives the number of bytes actually written.
        virtual Core::hresult FillPattern(
            uint8_t buffer[] /* @out @length:written @maxlength:capacity */,
            const uint32_t capacity /* @restrict:4194303 */,
            const uint8_t pattern,
            uint32_t& written /* @out @restrict:4194303 */) = 0;

        // ===== In/Out buffers =====

        // @brief Reverse a variable-length buffer in-place.
        // @param buffer Buffer to reverse; read then written back in reversed order.
        // @param size   Number of bytes in buffer.
        virtual Core::hresult ReverseBuffer(
            uint8_t buffer[] /* @inout @length:size @maxlength:size */,
            const uint16_t size) = 0;

        // @brief XOR a variable-length buffer in-place with a scalar key.
        // @param buffer Buffer to transform; read then written back.
        // @param length Number of bytes in buffer.
        // @param key    Single-byte XOR mask applied to each element.
        virtual Core::hresult XorBuffer(
            uint8_t buffer[] /* @inout @length:length @maxlength:length */,
            const uint32_t length /* @restrict:4194303 */,
            const uint8_t key) = 0;

        // ===== Multi-buffer =====

        // @brief Concatenate two input buffers into a single output buffer.
        //        If the combined size exceeds maxOutput the output is truncated.
        // @param input1    First input buffer.
        // @param size1     Length of input1 in bytes.
        // @param input2    Second input buffer.
        // @param size2     Length of input2 in bytes.
        // @param output    Caller-allocated output buffer; capacity given by maxOutput.
        // @param maxOutput Capacity of output in bytes (@maxlength guard).
        // @param written   Receives the number of bytes written to output.
        virtual Core::hresult MergeBuffers(
            const uint8_t input1[] /* @in @length:size1 */,
            const uint16_t size1,
            const uint8_t input2[] /* @in @length:size2 */,
            const uint16_t size2,
            uint8_t output[] /* @out @length:written @maxlength:maxOutput */,
            const uint16_t maxOutput,
            uint16_t& written /* @out */) = 0;

        // ===== Edge cases =====

        // @brief Process a variable-length buffer and return a scalar result.
        //        Passing size=0 exercises the empty-buffer edge case.
        // @param buffer Input bytes; length determined by size.  May be nullptr when size=0.
        // @param size   Number of bytes in buffer; may be zero.
        // @param result Implementation-defined scalar derived from the buffer contents.
        virtual Core::hresult Process(
            const uint8_t buffer[] /* @in @length:size */,
            const uint32_t size /* @restrict:4194303 */,
            uint32_t& result /* @out */) = 0;

        // FIXME: This crashes the generator — @length:return cannot be used with Core::hresult return.
        // The count would have to move to an @out parameter, but that conflicts with how the
        // generator resolves @length forward references in this particular pattern.
        // virtual Core::hresult ProcessLarge(
        //     const uint8_t buffer[] /* @in @length:size */,
        //     const uint32_t size,
        //     uint32_t& result /* @out */) = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder