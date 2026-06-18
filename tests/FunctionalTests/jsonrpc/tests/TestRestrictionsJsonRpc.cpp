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
#include <ITestRestrictions.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestRestrictionsJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

TEST_F(TestRestrictionsJsonRpc, SetFixedValue_Correct) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("setFixedValue", R"({"value":42})", response));
}

TEST_F(TestRestrictionsJsonRpc, SetFixedValue_Wrong) {
    string response;
    uint32_t result = CallMethod("setFixedValue", R"({"value":100})", response);
    EXPECT_NE(Core::ERROR_NONE, result) << "Should reject wrong value";
}

TEST_F(TestRestrictionsJsonRpc, SetByte_Valid) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("setByte", R"({"value":42})", response));
}

TEST_F(TestRestrictionsJsonRpc, SetNegative_ValidRange) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("setNegative", R"({"value":-100})", response));
}

TEST_F(TestRestrictionsJsonRpc, SetNegative_ZeroRejected) {
    string response;
    uint32_t result = CallMethod("setNegative", R"({"value":0})", response);
    EXPECT_NE(Core::ERROR_NONE, result) << "Should reject zero";
}

TEST_F(TestRestrictionsJsonRpc, SetRatio_OutOfRange) {
    string response;
    uint32_t result = CallMethod("setRatio", R"({"ratio":1.5})", response);
    EXPECT_NE(Core::ERROR_NONE, result) << "Should reject value > 1.0";
}

TEST_F(TestRestrictionsJsonRpc, SetName_EmptyRejected) {
    string response;
    uint32_t result = CallMethod("setName", R"({"name":""})", response);
    EXPECT_NE(Core::ERROR_NONE, result) << "Should reject empty string";
}

TEST_F(TestRestrictionsJsonRpc, SetName_TooLongRejected) {
    string response;
    string longName(100, 'x');
    string json = "{\"name\":\"" + longName + "\"}";
    uint32_t result = CallMethod("setName", json, response);
    EXPECT_NE(Core::ERROR_NONE, result) << "Should reject too long string";
}

TEST_F(TestRestrictionsJsonRpc, ClampedAdd_ValidInputs) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("clampedAdd", R"({"a":10,"b":20})", response));
    EXPECT_EQ(response, "30") << "Response: " << response;
}

TEST_F(TestRestrictionsJsonRpc, IsValidPercentage) {
    string response;
    
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("isValidPercentage", R"({"value":50})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
    
    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("isValidPercentage", R"({"value":150})", response));
    EXPECT_EQ(response, "false") << "Response: " << response;
}

TEST_F(TestRestrictionsJsonRpc, IsValidRatio) {
    string response;
    
    // Parameter name is "ratio" not "value"
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("isValidRatio", R"({"ratio":0.5})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

