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
#include <ITestExtendedFormat.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestExtendedFormat : public Testing::TestHarness<ITestExtendedFormat> {};

// ===========================================================================
// Methods — round-trip via COM-RPC
// ===========================================================================

TEST_F(TestExtendedFormat, EchoMethod_RoundTrip) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->EchoMethod(42, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 42u);
}

TEST_F(TestExtendedFormat, AddMethod_RoundTrip) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->AddMethod(10, 20, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 30u);
}

// ===========================================================================
// Properties — round-trip via COM-RPC
// ===========================================================================

TEST_F(TestExtendedFormat, Volume_SetGet) {
    ASSERT_EQ(_proxy->Volume(75), Core::ERROR_NONE);
    uint32_t vol = 0;
    ASSERT_EQ(static_cast<const ITestExtendedFormat*>(_proxy)->Volume(vol), Core::ERROR_NONE);
    EXPECT_EQ(vol, 75u);
}

TEST_F(TestExtendedFormat, Name_ReadOnly) {
    string name;
    ASSERT_EQ(_proxy->Name(name), Core::ERROR_NONE);
    EXPECT_EQ(name, "DefaultDevice");
}
