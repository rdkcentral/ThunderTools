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
#include <ITestEncodingMac.h>

using namespace Thunder;

class TestEncodingMacJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

TEST_F(TestEncodingMacJsonRpc, SetGetMacAddress) {
    string response;

    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("setMacAddress", R"({"mac":"01:23:45:67:89:ab"})", response));

    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("getMacAddress", "{}", response));
    // verify the stored MAC is returned correctly
    EXPECT_EQ(response, "\"01:23:45:67:89:ab\"") << "Response: " << response;
}

TEST_F(TestEncodingMacJsonRpc, EchoMacAddress) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("echoMacAddress", R"({"input":"de:ad:be:ef:00:01"})", response));
    // verify the echoed MAC matches the input
    EXPECT_EQ(response, "\"de:ad:be:ef:00:01\"") << "Response: " << response;
}

// ===========================================================================
// Variable-length @encode:mac — works with any buffer size, not just 6 bytes
// ===========================================================================

TEST_F(TestEncodingMacJsonRpc, VariableMac_8Bytes_SetGet) {
    // 8-byte buffer: "01:02:03:04:05:06:07:08"
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("setVariableMac", R"({"data":"01:02:03:04:05:06:07:08","size":8})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("getVariableMac", R"({"maxSize":32})", response));
    EXPECT_EQ(response, R"({"data":"01:02:03:04:05:06:07:08","written":8})")
        << "Response: " << response;
}

TEST_F(TestEncodingMacJsonRpc, VariableMac_1Byte_SetGet) {
    // 1-byte buffer: just "ff" (no colons)
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("setVariableMac", R"({"data":"ff","size":1})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("getVariableMac", R"({"maxSize":32})", response));
    EXPECT_EQ(response, R"({"data":"ff","written":1})")
        << "Response: " << response;
}

TEST_F(TestEncodingMacJsonRpc, VariableMac_4Bytes_SetGet) {
    // 4-byte buffer: "de:ad:be:ef"
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("setVariableMac", R"({"data":"de:ad:be:ef","size":4})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("getVariableMac", R"({"maxSize":32})", response));
    EXPECT_EQ(response, R"({"data":"de:ad:be:ef","written":4})")
        << "Response: " << response;
}
