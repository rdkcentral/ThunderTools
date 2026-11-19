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
#include <ITestJsonUncompliantExtended.h>

using namespace Thunder;

class TestJsonUncompliantExtendedJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// --- Method behaviour ---
// In @uncompliant:extended mode, single-param methods still use a wrapped object
// (same as @compliant). This contrasts with @uncompliant:collapsed where methods
// also accept a bare value.
TEST_F(TestJsonUncompliantExtendedJsonRpc, Method_WrappedParams) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("pingExtended", R"({"payload":"abc"})", response));
    EXPECT_EQ(response, "\"abc\"") << "Response: " << response;
}

// --- Property SET behaviour (the essence of @uncompliant:extended) ---
// The generator emits the property SET params as a *bare* scalar, not wrapped in
// {"value":42}. Sending the bare integer must succeed.
TEST_F(TestJsonUncompliantExtendedJsonRpc, Property_Set_BareValue) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("value", "42", response));
}

// --- Property GET behaviour ---
// After a SET with a bare value the GET must return the stored value.
// The GET response is placed in "result" (same field as @compliant).
// GET is triggered by passing an empty params string — this leaves the
// Core::JSON::DecUInt32 param uninitialized (IsSet()==false), which the
// stub uses to dispatch to the getter branch. JSON null must NOT be used:
// Thunder's parser sets the SET flag after consuming all 4 chars of "null",
// so null would take the setter path and store 0.
TEST_F(TestJsonUncompliantExtendedJsonRpc, Property_Get_AfterSet) {
    string response;
    ASSERT_EQ(Core::ERROR_NONE, CallMethod("value", "55", response));

    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("value", "", response));
    EXPECT_EQ(response, "55") << "Response: " << response;
}

// --- Property round-trip with boundary values ---
TEST_F(TestJsonUncompliantExtendedJsonRpc, Property_RoundTrip_Zero) {
    string response;
    ASSERT_EQ(Core::ERROR_NONE, CallMethod("value", "0", response));
    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("value", "", response));
    EXPECT_EQ(response, "0") << "Response: " << response;
}

TEST_F(TestJsonUncompliantExtendedJsonRpc, Property_RoundTrip_MaxUint32) {
    string response;
    ASSERT_EQ(Core::ERROR_NONE, CallMethod("value", "4294967295", response));
    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, CallMethod("value", "", response));
    EXPECT_EQ(response, "4294967295") << "Response: " << response;
}
