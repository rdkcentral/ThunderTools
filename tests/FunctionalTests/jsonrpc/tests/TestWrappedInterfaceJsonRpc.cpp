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

// Interface-level wrapped — ALL single-value returns wrapped using parameter name as key

TEST_F(TestWrappedInterfaceJsonRpc, GetCounter_WrappedInObject) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("getCounter", R"({})", response));
    // Interface-level wrapped: single return value wrapped in object using parameter name as key
    EXPECT_EQ(response, R"({"counter":42})") << "Response: " << response;
}

TEST_F(TestWrappedInterfaceJsonRpc, GetName_WrappedInObject) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("getName", R"({})", response));
    EXPECT_EQ(response, R"({"name":"WrappedDevice"})") << "Response: " << response;
}

TEST_F(TestWrappedInterfaceJsonRpc, Echo_WrappedInObject) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("echo", R"({"value":99})", response));
    EXPECT_EQ(response, R"({"result":99})") << "Response: " << response;
}
