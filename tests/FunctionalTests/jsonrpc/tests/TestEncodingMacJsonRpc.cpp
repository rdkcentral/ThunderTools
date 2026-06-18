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
