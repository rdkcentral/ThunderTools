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
#include <ITestJsonShape.h>

using namespace Thunder;

class TestJsonShapeJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

TEST_F(TestJsonShapeJsonRpc, GetWrappedCounter) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("getWrappedCounter", "{}", response));
    // impl counter is initialised to 42; @wrapped encloses it in an object envelope
    EXPECT_EQ(response, "{\"counter\":42}") << "Response: " << response;
}

TEST_F(TestJsonShapeJsonRpc, EchoExtractedList) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("echoExtractedList", R"({"input":[7]})", response));
    // verify the echoed list element survives the @extract round-trip
    EXPECT_EQ(response, "[7]") << "Response: " << response;
}

TEST_F(TestJsonShapeJsonRpc, EchoStruct) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("echoStruct", R"({"in":{"width":1920,"height":1080}})", response));
    // verify both struct fields survive the standard (non-extracted) round-trip
    EXPECT_EQ(response, "{\"width\":1920,\"height\":1080}") << "Response: " << response;
}
