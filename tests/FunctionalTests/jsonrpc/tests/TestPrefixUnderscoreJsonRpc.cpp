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
#include "JsonRpcTestHarness.h"
#include <ITestPrefixUnderscore.h>

using namespace Thunder;

class TestPrefixUnderscoreJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// Prefix with trailing underscore — methods become flat_echo, flat_add (no :: separator)

TEST_F(TestPrefixUnderscoreJsonRpc, Echo_WithFlatPrefix) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("flat_echo", R"({"value":123})", response));
    EXPECT_EQ(response, "123") << "Response: " << response;
}

TEST_F(TestPrefixUnderscoreJsonRpc, Add_WithFlatPrefix) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("flat_add", R"({"a":10,"b":20})", response));
    EXPECT_EQ(response, "30") << "Response: " << response;
}

TEST_F(TestPrefixUnderscoreJsonRpc, Echo_WithoutPrefix_Rejected) {
    // Calling without the flat_ prefix should fail
    string response;
    EXPECT_NE(Core::ERROR_NONE,
        CallMethod("echo", R"({"value":123})", response));
}

TEST_F(TestPrefixUnderscoreJsonRpc, Echo_WithColonPrefix_Rejected) {
    // Using :: separator should NOT work for underscore prefix
    string response;
    EXPECT_NE(Core::ERROR_NONE,
        CallMethod("flat::echo", R"({"value":123})", response));
}
