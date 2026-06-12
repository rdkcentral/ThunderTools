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
#include <ITestJsonShape.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestJsonShape : public Testing::TestHarness<ITestJsonShape> {};

TEST_F(TestJsonShape, GetWrappedCounter) {
    uint32_t counter = 0;
    ASSERT_EQ(_proxy->GetWrappedCounter(counter), Core::ERROR_NONE);
}

TEST_F(TestJsonShape, EchoExtractedList) {
    const std::vector<uint32_t> input { 7 };
    std::vector<uint32_t> output;

    ASSERT_EQ(_proxy->EchoExtractedList(input, output), Core::ERROR_NONE);
    ASSERT_EQ(output.size(), input.size());
    EXPECT_EQ(output[0], input[0]);
}

TEST_F(TestJsonShape, EchoExtractedStruct) {
    const ITestJsonShape::Dimensions input { 1920, 1080 };
    ITestJsonShape::Dimensions output { 0, 0 };

    ASSERT_EQ(_proxy->EchoExtractedStruct(input, output), Core::ERROR_NONE);
    EXPECT_EQ(output.width, input.width);
    EXPECT_EQ(output.height, input.height);
}
