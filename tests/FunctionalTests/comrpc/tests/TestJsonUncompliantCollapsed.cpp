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
#include <ITestJsonUncompliantCollapsed.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestJsonUncompliantCollapsed : public Testing::TestHarness<ITestJsonUncompliantCollapsed> {};

TEST_F(TestJsonUncompliantCollapsed, PingCollapsed) {
    string reply;
    ASSERT_EQ(_proxy->PingCollapsed("payload", reply), Core::ERROR_NONE);
    EXPECT_EQ(reply, "payload");
}

TEST_F(TestJsonUncompliantCollapsed, Value_SetGet_RoundTrip) {
    ASSERT_EQ(_proxy->Value(77u), Core::ERROR_NONE);
    uint32_t got = 0;
    ASSERT_EQ(static_cast<const ITestJsonUncompliantCollapsed*>(_proxy)->Value(got), Core::ERROR_NONE);
    EXPECT_EQ(got, 77u);
}

TEST_F(TestJsonUncompliantCollapsed, Value_GetterSucceeds) {
    uint32_t got = ~0u;
    EXPECT_EQ(static_cast<const ITestJsonUncompliantCollapsed*>(_proxy)->Value(got), Core::ERROR_NONE);
}

TEST_F(TestJsonUncompliantCollapsed, Value_MultipleWrites) {
    const uint32_t values[] = {0u, 1u, 0xFFFFFFFFu, 42u};
    for (uint32_t v : values) {
        ASSERT_EQ(_proxy->Value(v), Core::ERROR_NONE);
        uint32_t got = ~v;
        ASSERT_EQ(static_cast<const ITestJsonUncompliantCollapsed*>(_proxy)->Value(got), Core::ERROR_NONE);
        EXPECT_EQ(got, v);
    }
}
