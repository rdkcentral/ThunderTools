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
#include <ITestJsonUncompliantCollapsed.h>

using namespace Thunder;

class TestJsonUncompliantCollapsedJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// --- Method behaviour ---
// In @uncompliant:collapsed mode, a single-param method receives the parameter as a
// bare scalar (no enclosing object). Compare with @compliant which requires
// {"payload":"abc"} and @uncompliant:extended which also requires the wrapped form.
TEST_F(TestJsonUncompliantCollapsedJsonRpc, Method_BareParam) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("pingCollapsed", R"("abc")", response));
    EXPECT_EQ(response, "\"abc\"") << "Response: " << response;
}

// @uncompliant:collapsed does NOT reject wrapped-object params for methods.
// The stub registers Core::JSON::String for the payload parameter. Core::JSON::String
// accepts non-quoted input as a raw string value, so {"payload":"abc"} is stored
// as the literal text and the call succeeds. This pins that the stub has no
// object-vs-scalar discrimination for string parameters.
TEST_F(TestJsonUncompliantCollapsedJsonRpc, Method_WrappedParam_NotRejected) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("pingCollapsed", R"({"payload":"abc"})", response));
}

// --- Property SET behaviour (the essence of @uncompliant:collapsed) ---
// The generator emits the property SET params as a *bare* scalar.
// The GET response is placed in the \"params\" field of the JSON-RPC envelope
// (instead of \"result\"), which is the defining wire-format difference from
// @compliant and @uncompliant:extended.
TEST_F(TestJsonUncompliantCollapsedJsonRpc, Property_Set_BareValue) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("value", "42", response));
}

// --- Property GET behaviour ---
// After a SET the GET must echo the stored value back.
// GET is triggered by passing null params — the stub checks params.IsSet() == false.
TEST_F(TestJsonUncompliantCollapsedJsonRpc, Property_Get_AfterSet) {
    string response;
    ASSERT_EQ(Core::ERROR_NONE, CallMethod("value", "33", response));

    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("value", "null", response));
    EXPECT_EQ(response, "33") << "Response: " << response;
}

// --- Property round-trip with boundary values ---
TEST_F(TestJsonUncompliantCollapsedJsonRpc, Property_RoundTrip_Zero) {
    string response;
    ASSERT_EQ(Core::ERROR_NONE, CallMethod("value", "0", response));
    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("value", "null", response));
    EXPECT_EQ(response, "0") << "Response: " << response;
}

TEST_F(TestJsonUncompliantCollapsedJsonRpc, Property_RoundTrip_MaxUint32) {
    string response;
    ASSERT_EQ(Core::ERROR_NONE, CallMethod("value", "4294967295", response));
    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("value", "null", response));
    EXPECT_EQ(response, "4294967295") << "Response: " << response;
}
