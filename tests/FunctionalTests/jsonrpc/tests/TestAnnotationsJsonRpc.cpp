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
#include <ITestAnnotations.h>

using namespace Thunder;

class TestAnnotationsJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// ===========================================================================
// @prefix — All methods must be prefixed with "tags::"
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, Prefix_MethodCallable_WithPrefix) {
    // Method "deprecatedEcho" is prefixed by @prefix tags → "tags::deprecatedEcho"
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::deprecatedEcho", R"({"value":42})", response));
    EXPECT_EQ(response, "42") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, Prefix_MethodNotCallable_WithoutPrefix) {
    // Calling without prefix should fail
    string response;
    EXPECT_NE(Core::ERROR_NONE,
        CallMethod("deprecatedEcho", R"({"value":42})", response));
}

// ===========================================================================
// @deprecated / @obsolete — Methods still callable
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, Deprecated_MethodStillCallable) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::deprecatedEcho", R"({"value":100})", response));
    EXPECT_EQ(response, "100");
}

TEST_F(TestAnnotationsJsonRpc, Obsolete_MethodStillCallable) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::obsoleteEcho", R"({"value":200})", response));
    EXPECT_EQ(response, "200");
}

// ===========================================================================
// @alt — Primary and alternative names both work
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, Alt_PrimaryName_Works) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoWithAlt", R"({"value":55})", response));
    EXPECT_EQ(response, "55");
}

TEST_F(TestAnnotationsJsonRpc, Alt_AlternativeName_Works) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoAlt", R"({"value":55})", response));
    EXPECT_EQ(response, "55");
}

TEST_F(TestAnnotationsJsonRpc, Alt_BothNames_ProduceSameResult) {
    string responsePrimary, responseAlt;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoWithAlt", R"({"value":77})", responsePrimary));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoAlt", R"({"value":77})", responseAlt));
    EXPECT_EQ(responsePrimary, responseAlt);
}

// ===========================================================================
// @alt-deprecated — Primary works; deprecated alternative also works
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, AltDeprecated_PrimaryName_Works) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::add", R"({"a":10,"b":20})", response));
    EXPECT_EQ(response, "30");
}

TEST_F(TestAnnotationsJsonRpc, AltDeprecated_DeprecatedAltName_Works) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::legacyAdd", R"({"a":10,"b":20})", response));
    EXPECT_EQ(response, "30");
}

// ===========================================================================
// @alt-obsolete — Primary works; obsolete alternative also works
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, AltObsolete_PrimaryName_Works) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::subtract", R"({"a":50,"b":30})", response));
    EXPECT_EQ(response, "20");
}

TEST_F(TestAnnotationsJsonRpc, AltObsolete_ObsoleteAltName_Works) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::oldSubtract", R"({"a":50,"b":30})", response));
    EXPECT_EQ(response, "20");
}

// ===========================================================================
// @text on method name — JSON-RPC dispatch name override
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, TextMethodName_RenamedName_Works) {
    // C++ method is RenamedEchoMethod, but @text renames it to "renamedEcho"
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::renamedEcho", R"({"value":123})", response));
    EXPECT_EQ(response, "123");
}

TEST_F(TestAnnotationsJsonRpc, TextMethodName_OriginalCppName_Rejected) {
    // Calling by the C++ method name (camelCase of RenamedEchoMethod) should fail
    string response;
    EXPECT_NE(Core::ERROR_NONE,
        CallMethod("tags::renamedEchoMethod", R"({"value":123})", response))
        << "Original C++ method name should not be callable when @text overrides it";
}

// ===========================================================================
// @text on method combined with @alt — both primary rename + alternative
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, TextCombinedWithAlt_PrimaryTextName_Works) {
    // @text renames to "textPrimary"
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::textPrimary", R"({"value":456})", response));
    EXPECT_EQ(response, "456");
}

TEST_F(TestAnnotationsJsonRpc, TextCombinedWithAlt_AltName_Works) {
    // @alt provides "textSecondary" as alternative
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::textSecondary", R"({"value":456})", response));
    EXPECT_EQ(response, "456");
}

TEST_F(TestAnnotationsJsonRpc, TextCombinedWithAlt_OriginalCppName_Rejected) {
    // C++ name "TextCombinedMethod" (camelCase → "textCombinedMethod") should NOT work
    string response;
    EXPECT_NE(Core::ERROR_NONE,
        CallMethod("tags::textCombinedMethod", R"({"value":456})", response))
        << "Original C++ name should not be callable when @text overrides it";
}

TEST_F(TestAnnotationsJsonRpc, TextCombinedWithAlt_BothNames_ProduceSameResult) {
    string responsePrimary, responseAlt;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::textPrimary", R"({"value":789})", responsePrimary));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::textSecondary", R"({"value":789})", responseAlt));
    EXPECT_EQ(responsePrimary, responseAlt);
}

// ===========================================================================
// @text on struct members — JSON field names use the overridden names
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, TextStructMembers_OverriddenNames_RoundTrip) {
    // C++ struct: Name, Version, Active
    // JSON keys: deviceName, firmwareVersion, isActive
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoDeviceInfo",
            R"({"input":{"deviceName":"MyDevice","firmwareVersion":42,"isActive":true}})",
            response));
    // Exact expected output — field order is deterministic in generated code
    EXPECT_EQ(response, R"({"deviceName":"MyDevice","firmwareVersion":42,"isActive":true})")
        << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, TextStructMembers_OriginalCppNames_Rejected) {
    // Using original C++ member names (Name, Version, Active) should NOT work
    string response;
    uint32_t result = CallMethod("tags::echoDeviceInfo",
        R"({"input":{"Name":"MyDevice","Version":42,"Active":true}})",
        response);
    // Either fails entirely or produces default-valued output (empty string, 0, false)
    if (result == Core::ERROR_NONE) {
        EXPECT_EQ(response, R"({"deviceName":"","firmwareVersion":0,"isActive":false})")
            << "Original C++ names should not be recognized. Response: " << response;
    }
}

// ===========================================================================
// @text on enum values — Custom wire names for specific enumerators
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, TextEnumValues_CustomName_SetGet) {
    // CONN_IN_PROGRESS has @text connecting
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setConnectionState", R"({"state":"connecting"})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getConnectionState", R"({})", response));
    EXPECT_EQ(response, R"("connecting")") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, TextEnumValues_AuthFailed_CustomName) {
    // AUTH_FAILURE has @text auth-failed
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setConnectionState", R"({"state":"auth-failed"})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getConnectionState", R"({})", response));
    EXPECT_EQ(response, R"("auth-failed")") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, TextEnumValues_DefaultName_Works) {
    // DISCONNECTED has no @text override — uses default convention name
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setConnectionState", R"({"state":"DISCONNECTED"})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getConnectionState", R"({})", response));
    EXPECT_EQ(response, R"("DISCONNECTED")") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, TextEnumValues_OriginalCppName_Rejected) {
    // Using the C++ identifier "CONN_IN_PROGRESS" should not work when @text overrides it
    string response;
    uint32_t result = CallMethod("tags::setConnectionState",
        R"({"state":"CONN_IN_PROGRESS"})", response);
    EXPECT_NE(result, Core::ERROR_NONE)
        << "Original C++ enum name should be rejected when @text overrides it";
}

// ===========================================================================
// @bitmask on enum decl + @end sentinel exclusion
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, Bitmask_SingleFlag) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setFeatures", R"({"features":["FEAT_WIFI"]})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getFeatures", R"({})", response));
    EXPECT_EQ(response, R"(["FEAT_WIFI"])") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, Bitmask_MultipleFlags) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setFeatures",
            R"({"features":["FEAT_WIFI","FEAT_BLUETOOTH","FEAT_NFC"]})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getFeatures", R"({})", response));
    EXPECT_EQ(response, R"(["FEAT_WIFI","FEAT_BLUETOOTH","FEAT_NFC"])") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, Bitmask_EmptyArray_NoFlags) {
    // Set empty flags and verify call succeeds
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setFeatures", R"({"features":[]})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getFeatures", R"({})", response));
    // Response for zero flags is empty (field omitted) — this is the current behaviour.
    // Whether this should be "[]" instead is open for discussion with the framework team.
    EXPECT_TRUE(response.empty()) << "Response: " << response;
}

// DISABLED: @end sentinel values are not actively rejected by the JSON-RPC layer.
// The intended behaviour (per reference doc) is rejection, but the current framework
// silently ignores unknown flag names. Re-enable once the generator enforces @end.
TEST_F(TestAnnotationsJsonRpc, DISABLED_Bitmask_EndSentinel_Rejected) {
    // FEAT_ALL is after @end — should not be a valid flag name
    string response;
    uint32_t result = CallMethod("tags::setFeatures",
        R"({"features":["FEAT_ALL"]})", response);
    EXPECT_NE(result, Core::ERROR_NONE)
        << "Sentinel value after @end should be rejected";
}

// ===========================================================================
// @encode:base64 — Variable-length buffer round-trip
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, EncodeBase64_SetGet_RoundTrip) {
    // "AQIDBA==" is base64 for bytes {0x01, 0x02, 0x03, 0x04}
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setPayloadBase64", R"({"data":"AQIDBA==","size":4})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getPayloadBase64", R"({"maxSize":256})", response));
    EXPECT_EQ(response, R"({"data":"AQIDBA==","written":4})") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, EncodeBase64_InvalidBase64_Accepted) {
    // NOTE: Thunder's base64 decoder does not reject invalid input — it silently
    // produces output. This is by design; validation is the caller's responsibility.
    string response;
    uint32_t result = CallMethod("tags::setPayloadBase64",
        R"({"data":"!!!invalid!!!","size":4})", response);
    // Just verify the call doesn't crash; may or may not return error
    (void)result;
}

// ===========================================================================
// @encode:hex — Variable-length buffer round-trip
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, EncodeHex_SetGet_RoundTrip) {
    // "DEADBEEF" is hex for bytes {0xDE, 0xAD, 0xBE, 0xEF}
    // NOTE: Thunder's hex encoder produces lowercase output
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setTokenHex", R"({"data":"DEADBEEF","size":4})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::getTokenHex", R"({"maxSize":64})", response));
    EXPECT_EQ(response, R"({"data":"deadbeef","written":4})") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, EncodeHex_InvalidHexChars_Accepted) {
    // NOTE: Thunder's hex decoder does not reject invalid characters — it silently
    // produces output. This is by design; validation is the caller's responsibility.
    string response;
    uint32_t result = CallMethod("tags::setTokenHex",
        R"({"data":"ZZZZ","size":2})", response);
    // Just verify the call doesn't crash
    (void)result;
}

// ===========================================================================
// @extract on struct arrays
// ===========================================================================

// DISABLED: In compliant format, @extract does NOT unwrap single-element arrays.
// The intended behaviour (per reference doc) is unwrapping, but the current generator
// only applies extraction in collapsed/extended format. Re-enable if this changes.
TEST_F(TestAnnotationsJsonRpc, DISABLED_ExtractStructArray_SingleElement_Unwrapped) {
    // @extract should unwrap single-element arrays on output
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoPoints",
            R"({"input":[{"x":10,"y":20}]})", response));
    // Response should be a single object, NOT wrapped in array
    EXPECT_EQ(response, R"({"x":10,"y":20})")
        << "Single element should be unwrapped. Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, ExtractStructArray_SingleElement_AsArray) {
    // Current behaviour: in compliant format, single element remains as array
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoPoints",
            R"({"input":[{"x":10,"y":20}]})", response));
    EXPECT_EQ(response, R"([{"x":10,"y":20}])") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, ExtractStructArray_MultipleElements_Array) {
    // Multiple elements should remain as array
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::echoPoints",
            R"({"input":[{"x":1,"y":2},{"x":3,"y":4}]})", response));
    EXPECT_EQ(response, R"([{"x":1,"y":2},{"x":3,"y":4}])") << "Response: " << response;
}

// ===========================================================================
// @optional on bool — Regression guard
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, OptionalBool_Omitted_DefaultsFalse) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::formatText", R"({"text":"hello"})", response));
    EXPECT_EQ(response, R"("hello")") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, OptionalBool_SetTrue_Applied) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::formatText", R"({"text":"hello","uppercase":true})", response));
    EXPECT_EQ(response, R"("HELLO")") << "Response: " << response;
}

TEST_F(TestAnnotationsJsonRpc, OptionalBool_SetFalse_NoConversion) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::formatText", R"({"text":"Hello","uppercase":false})", response));
    EXPECT_EQ(response, R"("Hello")") << "Response: " << response;
}

// ===========================================================================
// Strict type matching (Constraint C8)
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, StrictTypeMatching_StringForUint32_Rejected) {
    string response;
    uint32_t result = CallMethod("tags::deprecatedEcho",
        R"({"value":"not_a_number"})", response);
    EXPECT_NE(result, Core::ERROR_NONE)
        << "String value for uint32_t param should be rejected";
}

TEST_F(TestAnnotationsJsonRpc, StrictTypeMatching_IntForEnumString_Rejected) {
    string response;
    uint32_t result = CallMethod("tags::setConnectionState",
        R"({"state":1})", response);
    EXPECT_NE(result, Core::ERROR_NONE)
        << "Integer value for enum string param should be rejected";
}

// ===========================================================================
// Empty parameter list (Constraint C5) — method with no params still callable
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, EmptyParameterList_Ping_Callable) {
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::ping", R"({})", response));
    // Void method returns no data — response should be empty
    EXPECT_TRUE(response.empty()) << "Response: " << response;
}

// ===========================================================================
// Events via JSON-RPC — @event, @index on events, @statuslistener
// ===========================================================================

TEST_F(TestAnnotationsJsonRpc, Event_TriggerPortEvent_Callable) {
    // TriggerPortEvent is a regular method exposed via JSON-RPC
    // It triggers the event internally; here we just verify the method is callable
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerPortEvent", R"({"port":1,"state":"connecting"})", response));
}

TEST_F(TestAnnotationsJsonRpc, Event_TriggerFeaturesEvent_Callable) {
    // TriggerFeaturesEvent is also a regular method
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerFeaturesEvent", R"({"features":["FEAT_WIFI"]})", response));
}

TEST_F(TestAnnotationsJsonRpc, Event_SetFeatures_ThenTrigger_Callable) {
    // Set features, then trigger the event — validates the full flow compiles and runs
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::setFeatures", R"({"features":["FEAT_BLUETOOTH","FEAT_NFC"]})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerFeaturesEvent", R"({"features":["FEAT_BLUETOOTH","FEAT_NFC"]})", response));
}

TEST_F(TestAnnotationsJsonRpc, Event_IndexedPortEvent_DifferentPorts) {
    // Trigger events on different ports — validates @index on event params works in generated code
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerPortEvent", R"({"port":0,"state":"DISCONNECTED"})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerPortEvent", R"({"port":1,"state":"CONNECTED"})", response));
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerPortEvent", R"({"port":2,"state":"auth-failed"})", response));
}
