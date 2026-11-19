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

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestVectors.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestVectors : public Testing::TestHarness<ITestVectors> {};

// Get-method outputs are seeded to verify that decoding replaces existing contents.

// ===== Primitive-element vectors =====

TEST_F(TestVectors, SumPrimitives) {
    uint32_t sum = 0;
    ASSERT_EQ(_proxy->SumPrimitives({ 1, 2, 3, 4 }, sum), Core::ERROR_NONE);
    EXPECT_EQ(sum, 10u);
}

TEST_F(TestVectors, GetPrimitives) {
    std::vector<uint32_t> values { 99 };
    ASSERT_EQ(_proxy->GetPrimitives(values), Core::ERROR_NONE);
    EXPECT_EQ(values, (std::vector<uint32_t> { 1, 2, 3, 5, 8 }));
}

TEST_F(TestVectors, TransformPrimitives) {
    std::vector<uint32_t> values { 1, 2, 3 };
    ASSERT_EQ(_proxy->TransformPrimitives(values), Core::ERROR_NONE);
    EXPECT_EQ(values, (std::vector<uint32_t> { 4, 3, 2 }));
}

// ===== Struct-element vectors =====

TEST_F(TestVectors, SummarizeEntries) {
    uint32_t idSum = 0;
    string concatenatedNames;
    ASSERT_EQ(_proxy->SummarizeEntries({ { 3, "three" }, { 5, "five" } }, idSum, concatenatedNames), Core::ERROR_NONE);
    EXPECT_EQ(idSum, 8u);
    EXPECT_EQ(concatenatedNames, "threefive");
}

TEST_F(TestVectors, GetEntries) {
    std::vector<ITestVectors::Entry> values { { 99, "stale" } };
    ASSERT_EQ(_proxy->GetEntries(values), Core::ERROR_NONE);
    ASSERT_EQ(values.size(), 2u);
    EXPECT_EQ(values[0].id, 7u);
    EXPECT_EQ(values[0].name, "seven");
    EXPECT_EQ(values[1].id, 11u);
    EXPECT_EQ(values[1].name, "eleven");
}

TEST_F(TestVectors, TransformEntries) {
    std::vector<ITestVectors::Entry> values { { 1, "one" }, { 2, "two" } };
    ASSERT_EQ(_proxy->TransformEntries(values), Core::ERROR_NONE);
    ASSERT_EQ(values.size(), 2u);
    EXPECT_EQ(values[0].id, 101u);
    EXPECT_EQ(values[0].name, "one!");
    EXPECT_EQ(values[1].id, 102u);
    EXPECT_EQ(values[1].name, "two!");
}

// ===== Nested vectors =====

TEST_F(TestVectors, SummarizeNestedVectors) {
    uint32_t valueSum = 0;
    uint32_t vectorCount = 0;
    ASSERT_EQ(_proxy->SummarizeNestedVectors({ { 1, 2 }, {}, { 3, 4, 5 } }, valueSum, vectorCount), Core::ERROR_NONE);
    EXPECT_EQ(valueSum, 15u);
    EXPECT_EQ(vectorCount, 3u);
}

TEST_F(TestVectors, GetNestedVectors) {
    std::vector<std::vector<uint32_t>> values { { 99 } };
    ASSERT_EQ(_proxy->GetNestedVectors(values), Core::ERROR_NONE);
    EXPECT_EQ(values, (std::vector<std::vector<uint32_t>> { { 1, 2 }, {}, { 3, 4, 5 } }));
}

TEST_F(TestVectors, TransformNestedVectors) {
    std::vector<std::vector<uint32_t>> values { { 1, 2 }, {}, { 3, 4, 5 } };
    ASSERT_EQ(_proxy->TransformNestedVectors(values), Core::ERROR_NONE);
    EXPECT_EQ(values, (std::vector<std::vector<uint32_t>> { { 5, 4, 3 }, {}, { 2, 1 } }));
}

// ===== Vectors of optional elements =====

TEST_F(TestVectors, SummarizeOptionalElements) {
    const std::vector<Core::OptionalType<uint32_t>> values {
        Core::OptionalType<uint32_t>(3),
        Core::OptionalType<uint32_t>(),
        Core::OptionalType<uint32_t>(5)
    };
    uint32_t valueSum = 0;
    uint32_t setCount = 0;

    ASSERT_EQ(_proxy->SummarizeOptionalElements(values, valueSum, setCount), Core::ERROR_NONE);
    EXPECT_EQ(valueSum, 8u);
    EXPECT_EQ(setCount, 2u);
}

TEST_F(TestVectors, GetOptionalElements) {
    std::vector<Core::OptionalType<uint32_t>> values { Core::OptionalType<uint32_t>(99) };
    ASSERT_EQ(_proxy->GetOptionalElements(values), Core::ERROR_NONE);

    ASSERT_EQ(values.size(), 3u);
    ASSERT_TRUE(values[0].IsSet());
    EXPECT_EQ(values[0].Value(), 2u);
    EXPECT_FALSE(values[1].IsSet());
    ASSERT_TRUE(values[2].IsSet());
    EXPECT_EQ(values[2].Value(), 6u);
}

TEST_F(TestVectors, TransformOptionalElements) {
    std::vector<Core::OptionalType<uint32_t>> values {
        Core::OptionalType<uint32_t>(1),
        Core::OptionalType<uint32_t>(),
        Core::OptionalType<uint32_t>(3)
    };
    ASSERT_EQ(_proxy->TransformOptionalElements(values), Core::ERROR_NONE);

    ASSERT_EQ(values.size(), 3u);
    ASSERT_TRUE(values[0].IsSet());
    EXPECT_EQ(values[0].Value(), 2u);
    EXPECT_FALSE(values[1].IsSet());
    ASSERT_TRUE(values[2].IsSet());
    EXPECT_EQ(values[2].Value(), 4u);
}

// ===== Optional vectors =====

TEST_F(TestVectors, SummarizeOptionalVector_Set) {
    Core::OptionalType<std::vector<uint32_t>> values;
    values = std::vector<uint32_t> { 1, 2, 3 };
    bool isSet = false;
    uint32_t valueSum = 0;

    ASSERT_EQ(_proxy->SummarizeOptionalVector(values, isSet, valueSum), Core::ERROR_NONE);
    EXPECT_TRUE(isSet);
    EXPECT_EQ(valueSum, 6u);
}

TEST_F(TestVectors, SummarizeOptionalVector_Empty) {
    Core::OptionalType<std::vector<uint32_t>> values;
    values = std::vector<uint32_t> {};
    bool isSet = false;
    uint32_t valueSum = 99;

    ASSERT_EQ(_proxy->SummarizeOptionalVector(values, isSet, valueSum), Core::ERROR_NONE);
    EXPECT_TRUE(isSet);
    EXPECT_EQ(valueSum, 0u);
}

TEST_F(TestVectors, SummarizeOptionalVector_Unset) {
    Core::OptionalType<std::vector<uint32_t>> values;
    bool isSet = true;
    uint32_t valueSum = 99;

    ASSERT_EQ(_proxy->SummarizeOptionalVector(values, isSet, valueSum), Core::ERROR_NONE);
    EXPECT_FALSE(isSet);
    EXPECT_EQ(valueSum, 0u);
}

TEST_F(TestVectors, GetOptionalVector) {
    Core::OptionalType<std::vector<uint32_t>> values;
    values = std::vector<uint32_t> { 99 };
    ASSERT_EQ(_proxy->GetOptionalVector(values), Core::ERROR_NONE);
    ASSERT_TRUE(values.IsSet());
    EXPECT_EQ(values.Value(), (std::vector<uint32_t> { 2, 4, 6 }));
}

TEST_F(TestVectors, TransformOptionalVector_Set) {
    Core::OptionalType<std::vector<uint32_t>> values;
    values = std::vector<uint32_t> { 1, 2, 3 };
    ASSERT_EQ(_proxy->TransformOptionalVector(values), Core::ERROR_NONE);
    ASSERT_TRUE(values.IsSet());
    EXPECT_EQ(values.Value(), (std::vector<uint32_t> { 4, 3, 2 }));
}

TEST_F(TestVectors, TransformOptionalVector_Unset) {
    Core::OptionalType<std::vector<uint32_t>> values;
    ASSERT_EQ(_proxy->TransformOptionalVector(values), Core::ERROR_NONE);
    EXPECT_FALSE(values.IsSet());
}

// ===== Vectors as struct members =====

TEST_F(TestVectors, EchoCollection) {
    ITestVectors::Collection input;
    input.primitives = { 1, 2 };
    input.entries = { { 3, "three" } };
    input.nestedVectors = { { 4 }, { 5, 6 } };

    ITestVectors::Collection output;
    ASSERT_EQ(_proxy->EchoCollection(input, output), Core::ERROR_NONE);
    EXPECT_EQ(output.primitives, (std::vector<uint32_t> { 1, 2 }));
    ASSERT_EQ(output.entries.size(), 1u);
    EXPECT_EQ(output.entries[0].id, 3u);
    EXPECT_EQ(output.entries[0].name, "three");
    EXPECT_EQ(output.nestedVectors, (std::vector<std::vector<uint32_t>> { { 4 }, { 5, 6 } }));
}

TEST_F(TestVectors, GetCollection) {
    ITestVectors::Collection collection;
    collection.primitives = { 99 };
    collection.entries = { { 99, "stale" } };
    collection.nestedVectors = { { 99 } };

    ASSERT_EQ(_proxy->GetCollection(collection), Core::ERROR_NONE);
    EXPECT_EQ(collection.primitives, (std::vector<uint32_t> { 2, 4 }));
    ASSERT_EQ(collection.entries.size(), 1u);
    EXPECT_EQ(collection.entries[0].id, 6u);
    EXPECT_EQ(collection.entries[0].name, "six");
    EXPECT_EQ(collection.nestedVectors, (std::vector<std::vector<uint32_t>> { { 8, 10 }, { 12 } }));
}

TEST_F(TestVectors, TransformCollection) {
    ITestVectors::Collection collection;
    collection.primitives = { 1, 2 };
    collection.entries = { { 3, "three" } };
    collection.nestedVectors = { { 4 }, { 5, 6 } };

    ASSERT_EQ(_proxy->TransformCollection(collection), Core::ERROR_NONE);
    EXPECT_EQ(collection.primitives, (std::vector<uint32_t> { 2, 3 }));
    ASSERT_EQ(collection.entries.size(), 1u);
    EXPECT_EQ(collection.entries[0].id, 103u);
    EXPECT_EQ(collection.entries[0].name, "three!");
    EXPECT_EQ(collection.nestedVectors, (std::vector<std::vector<uint32_t>> { { 4 }, { 6, 5 } }));
}