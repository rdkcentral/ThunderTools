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

#include <ImplementationFactory.h>
#include <ITestVectors.h>

#include <algorithm>

namespace Thunder {
namespace TestImplementation {

    using namespace FunctionalTest;

    class TestVectorsImpl : public ITestVectors {
    public:
        TestVectorsImpl() = default;
        ~TestVectorsImpl() override = default;

        TestVectorsImpl(const TestVectorsImpl&) = delete;
        TestVectorsImpl& operator=(const TestVectorsImpl&) = delete;

        Core::hresult SumPrimitives(const std::vector<uint32_t>& values, uint32_t& sum) const override
        {
            sum = 0;
            for (const auto value : values) {
                sum += value;
            }
            return Core::ERROR_NONE;
        }

        Core::hresult GetPrimitives(std::vector<uint32_t>& values) const override
        {
            values = { 1, 2, 3, 5, 8 };
            return Core::ERROR_NONE;
        }

        Core::hresult TransformPrimitives(std::vector<uint32_t>& values) const override
        {
            std::reverse(values.begin(), values.end());
            for (auto& value : values) {
                ++value;
            }
            return Core::ERROR_NONE;
        }

        Core::hresult SummarizeEntries(const std::vector<Entry>& values, uint32_t& idSum, string& concatenatedNames) const override
        {
            idSum = 0;
            concatenatedNames.clear();
            for (const auto& entry : values) {
                idSum += entry.id;
                concatenatedNames += entry.name;
            }
            return Core::ERROR_NONE;
        }

        Core::hresult GetEntries(std::vector<Entry>& values) const override
        {
            values = { { 7, "seven" }, { 11, "eleven" } };
            return Core::ERROR_NONE;
        }

        Core::hresult TransformEntries(std::vector<Entry>& values) const override
        {
            for (auto& entry : values) {
                entry.id += 100;
                entry.name += "!";
            }
            return Core::ERROR_NONE;
        }

        Core::hresult SummarizeNestedVectors(const std::vector<std::vector<uint32_t>>& values, uint32_t& valueSum, uint32_t& vectorCount) const override
        {
            valueSum = 0;
            vectorCount = static_cast<uint32_t>(values.size());
            for (const auto& innerValues : values) {
                for (const auto value : innerValues) {
                    valueSum += value;
                }
            }
            return Core::ERROR_NONE;
        }

        Core::hresult GetNestedVectors(std::vector<std::vector<uint32_t>>& values) const override
        {
            values = { { 1, 2 }, {}, { 3, 4, 5 } };
            return Core::ERROR_NONE;
        }

        Core::hresult TransformNestedVectors(std::vector<std::vector<uint32_t>>& values) const override
        {
            for (auto& innerValues : values) {
                std::reverse(innerValues.begin(), innerValues.end());
            }
            std::reverse(values.begin(), values.end());
            return Core::ERROR_NONE;
        }

        Core::hresult SummarizeOptionalElements(const std::vector<Core::OptionalType<uint32_t>>& values, uint32_t& valueSum, uint32_t& setCount) const override
        {
            valueSum = 0;
            setCount = 0;
            for (const auto& value : values) {
                if (value.IsSet()) {
                    valueSum += value.Value();
                    ++setCount;
                }
            }
            return Core::ERROR_NONE;
        }

        Core::hresult GetOptionalElements(std::vector<Core::OptionalType<uint32_t>>& values) const override
        {
            values = {
                Core::OptionalType<uint32_t>(2),
                Core::OptionalType<uint32_t>(),
                Core::OptionalType<uint32_t>(6)
            };
            return Core::ERROR_NONE;
        }

        Core::hresult TransformOptionalElements(std::vector<Core::OptionalType<uint32_t>>& values) const override
        {
            for (auto& value : values) {
                if (value.IsSet()) {
                    value = value.Value() + 1;
                }
            }
            return Core::ERROR_NONE;
        }

        Core::hresult SummarizeOptionalVector(const Core::OptionalType<std::vector<uint32_t>>& values, bool& isSet, uint32_t& valueSum) const override
        {
            isSet = values.IsSet();
            valueSum = 0;
            if (isSet) {
                for (const auto value : values.Value()) {
                    valueSum += value;
                }
            }
            return Core::ERROR_NONE;
        }

        Core::hresult GetOptionalVector(Core::OptionalType<std::vector<uint32_t>>& values) const override
        {
            values = std::vector<uint32_t> { 2, 4, 6 };
            return Core::ERROR_NONE;
        }

        Core::hresult TransformOptionalVector(Core::OptionalType<std::vector<uint32_t>>& values) const override
        {
            if (values.IsSet()) {
                std::reverse(values.Value().begin(), values.Value().end());
                for (auto& value : values.Value()) {
                    ++value;
                }
            }
            return Core::ERROR_NONE;
        }

        Core::hresult EchoCollection(const Collection& input, Collection& output) const override
        {
            output = input;
            return Core::ERROR_NONE;
        }

        Core::hresult GetCollection(Collection& collection) const override
        {
            collection.primitives = { 2, 4 };
            collection.entries = { { 6, "six" } };
            collection.nestedVectors = { { 8, 10 }, { 12 } };
            return Core::ERROR_NONE;
        }

        Core::hresult TransformCollection(Collection& collection) const override
        {
            for (auto& value : collection.primitives) {
                ++value;
            }
            for (auto& entry : collection.entries) {
                entry.id += 100;
                entry.name += "!";
            }
            for (auto& values : collection.nestedVectors) {
                std::reverse(values.begin(), values.end());
            }
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestVectorsImpl)
        INTERFACE_ENTRY(ITestVectors)
        END_INTERFACE_MAP
    };

    static Factory::Registrar<ITestVectors, TestVectorsImpl> g_vectorsRegistrar;

} // namespace TestImplementation
} // namespace Thunder