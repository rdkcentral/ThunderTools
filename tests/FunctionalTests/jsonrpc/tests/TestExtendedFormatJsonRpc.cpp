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
#include <ITestExtendedFormat.h>

using namespace Thunder;

class TestExtendedFormatJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// ===========================================================================
// @extended — Methods use compliant-style named object params
// ===========================================================================

TEST_F(TestExtendedFormatJsonRpc, Method_SingleParam_UsesNamedObject) {
    // @extended methods still require named object params (like @compliant)
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("echoMethod", R"({"value":42})", response));
    EXPECT_EQ(response, "42") << "Response: " << response;
}

TEST_F(TestExtendedFormatJsonRpc, Method_MultipleParams_UsesNamedObject) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("addMethod", R"({"a":10,"b":20})", response));
    EXPECT_EQ(response, "30") << "Response: " << response;
}

TEST_F(TestExtendedFormatJsonRpc, Method_BareValue_NotAccepted) {
    // Unlike @collapsed, @extended methods do NOT accept bare values
    string response;
    uint32_t result = CallMethod("echoMethod", R"(42)", response);
    // Should fail because method expects named object format
    EXPECT_NE(result, Core::ERROR_NONE)
        << "@extended methods should not accept collapsed params";
}

// ===========================================================================
// @extended — Properties use collapsed format (value sent directly)
// ===========================================================================

TEST_F(TestExtendedFormatJsonRpc, Property_Set_AcceptsDirectValue) {
    // @extended properties accept the value directly (collapsed)
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("volume", R"(75)", response));
}

TEST_F(TestExtendedFormatJsonRpc, Property_Get_ReturnsDirectValue) {
    // First set a value
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("volume", R"(88)", response));
    // In @extended format, property GET uses empty params (not "{}")
    // because the collapsed format interprets "{}" as a value to parse
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("volume", "", response));
    EXPECT_EQ(response, "88") << "Response: " << response;
}

TEST_F(TestExtendedFormatJsonRpc, Property_ReadOnly_Get_ReturnsDirectString) {
    // Read-only string property — returns the string directly
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("name", "", response));
    EXPECT_EQ(response, R"("DefaultDevice")") << "Response: " << response;
}

// ===========================================================================
// Contrast with @compliant: @extended properties are collapsed, not wrapped
// ===========================================================================

TEST_F(TestExtendedFormatJsonRpc, Property_Get_NotWrappedInValueObject) {
    // Set volume first
    string response;
    CallMethod("volume", R"(42)", response);
    // In @extended format, property GET uses empty params
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("volume", "", response));
    EXPECT_EQ(response, "42") << "Response: " << response;
}
