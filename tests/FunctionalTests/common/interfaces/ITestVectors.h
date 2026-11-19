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

    // Test std::vector serialization over COM-RPC.
    struct EXTERNAL ITestVectors : virtual public Core::IUnknown {
        enum { ID = ID_TEST_VECTORS };

        struct Entry {
            uint32_t id;
            string name;
        };

        struct Collection {
            std::vector<uint32_t> primitives /* @restrict:0..255 */;
            std::vector<Entry> entries /* @restrict:0..255 */;
            std::vector<std::vector<uint32_t> /* @restrict:0..255 */> nestedVectors /* @restrict:0..255 */;
        };

        // ===== Primitive-element vectors =====

        virtual Core::hresult SumPrimitives(const std::vector<uint32_t>& values /* @in @restrict:0..255 */, uint32_t& sum /* @out */) const = 0;
        virtual Core::hresult GetPrimitives(std::vector<uint32_t>& values /* @out @restrict:0..255 */) const = 0;
        virtual Core::hresult TransformPrimitives(std::vector<uint32_t>& values /* @inout @restrict:0..255 */) const = 0;

        // ===== Struct-element vectors =====

        virtual Core::hresult SummarizeEntries(const std::vector<Entry>& values /* @in @restrict:0..255 */, uint32_t& idSum /* @out */, string& concatenatedNames /* @out */) const = 0;
        virtual Core::hresult GetEntries(std::vector<Entry>& values /* @out @restrict:0..255 */) const = 0;
        virtual Core::hresult TransformEntries(std::vector<Entry>& values /* @inout @restrict:0..255 */) const = 0;

        // ===== Nested vectors =====

        virtual Core::hresult SummarizeNestedVectors(const std::vector<std::vector<uint32_t> /* @restrict:0..255 */>& values /* @in @restrict:0..255 */, uint32_t& valueSum /* @out */, uint32_t& vectorCount /* @out */) const = 0;
        virtual Core::hresult GetNestedVectors(std::vector<std::vector<uint32_t> /* @restrict:0..255 */>& values /* @out @restrict:0..255 */) const = 0;
        virtual Core::hresult TransformNestedVectors(std::vector<std::vector<uint32_t> /* @restrict:0..255 */>& values /* @inout @restrict:0..255 */) const = 0;

        // ===== Vectors of optional elements =====

        virtual Core::hresult SummarizeOptionalElements(const std::vector<Core::OptionalType<uint32_t>>& values /* @in @restrict:0..255 */, uint32_t& valueSum /* @out */, uint32_t& setCount /* @out */) const = 0;
        virtual Core::hresult GetOptionalElements(std::vector<Core::OptionalType<uint32_t>>& values /* @out @restrict:0..255 */) const = 0;
        virtual Core::hresult TransformOptionalElements(std::vector<Core::OptionalType<uint32_t>>& values /* @inout @restrict:0..255 */) const = 0;

        // ===== Optional vectors =====

        virtual Core::hresult SummarizeOptionalVector(const Core::OptionalType<std::vector<uint32_t>>& values /* @in @restrict:0..255 */, bool& isSet /* @out */, uint32_t& valueSum /* @out */) const = 0;
        virtual Core::hresult GetOptionalVector(Core::OptionalType<std::vector<uint32_t>>& values /* @out @restrict:0..255 */) const = 0;
        virtual Core::hresult TransformOptionalVector(Core::OptionalType<std::vector<uint32_t>>& values /* @inout @restrict:0..255 */) const = 0;

        // ===== Vectors as struct members =====

        virtual Core::hresult EchoCollection(const Collection& input /* @in */, Collection& output /* @out */) const = 0;
        virtual Core::hresult GetCollection(Collection& collection /* @out */) const = 0;
        virtual Core::hresult TransformCollection(Collection& collection /* @inout */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
