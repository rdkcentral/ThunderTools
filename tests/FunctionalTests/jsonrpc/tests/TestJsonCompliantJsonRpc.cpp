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
#include <ITestJsonCompliant.h>

using namespace Thunder;

class TestJsonCompliantJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

TEST_F(TestJsonCompliantJsonRpc, Ping) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("ping", R"({"payload":"abc"})", response));
    // impl echoes payload into reply; verify the value survives the compliant envelope
    EXPECT_EQ(response, "\"abc\"") << "Response: " << response;
}
