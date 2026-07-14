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
#include <ITestWrappedInterface.h>

using namespace Thunder;

class TestWrappedInterfaceJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// Interface-level wrapped — ALL single-value returns wrapped in {"value":...}

TEST_F(TestWrappedInterfaceJsonRpc, GetCounter_WrappedInValueObject) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("getCounter", R"({})", response));
    // Should be {"value":42} not just 42
    EXPECT_EQ(response, R"({"value":42})") << "Response: " << response;
}

TEST_F(TestWrappedInterfaceJsonRpc, GetName_WrappedInValueObject) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("getName", R"({})", response));
    // Should be {"value":"WrappedDevice"} not just "WrappedDevice"
    EXPECT_EQ(response, R"({"value":"WrappedDevice"})") << "Response: " << response;
}

TEST_F(TestWrappedInterfaceJsonRpc, Echo_WrappedInValueObject) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("echo", R"({"value":99})", response));
    // Should be {"value":99} not just 99
    EXPECT_EQ(response, R"({"value":99})") << "Response: " << response;
}
