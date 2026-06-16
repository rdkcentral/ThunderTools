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
#include <ITestJsonTextCase.h>

using namespace Thunder;

class TestJsonTextCaseJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

TEST_F(TestJsonTextCaseJsonRpc, EchoCaseConvention) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("echocaseconvention", R"({"sourcevalue":123})", response));
    // @text:legacy lowercases method/param names; verify the echo-back value is correct
    EXPECT_NE(response.find("123"), string::npos);
}
