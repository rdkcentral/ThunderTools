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
#include <ITestJsonTextKeep.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestJsonTextKeep : public Testing::TestHarness<ITestJsonTextKeep> {};

TEST_F(TestJsonTextKeep, EchoMixedCaseName) {
    uint32_t output = 0;
    ASSERT_EQ(_proxy->EchoMixedCaseName(77, output), Core::ERROR_NONE);
    EXPECT_EQ(output, 77u);
}

TEST_F(TestJsonTextKeep, BuildVersionProperty) {
    uint32_t version = 0;
    ASSERT_EQ(_proxy->BuildVersion(version), Core::ERROR_NONE);
    EXPECT_EQ(version, 42u);
}
