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

// Tests the JSON-RPC handler dispatch versioning mechanism (CreateHandler /
// GetHandler pattern) used in Thunder v4.x and retained for backwards
// compatibility in Thunder v5.
//
// These tests exist specifically to catch regressions like the one observed in
// Thunder 4.4.6, where versioned handler dispatch broke silently.
//
// No generated interface headers are needed.  All handler wiring is handwritten
// and mirrors the patterns described in JSONRPC_VERSIONING.md.
//
// Scenarios covered (see JSONRPC_VERSIONING.md §13-14):
//
//   TestVersioningMain   — Scenario C/D (base={2,3,4}, v1=clone+override):
//     - Explicit versioned dispatch (.1. and .2.)
//     - Unversioned dispatch routes to the FIRST (base) handler, not v1
//     - Inherited method on cloned v1 handler
//     - Method exists only on v2 (.1. rejected, .2. works, unversioned works)
//     - Unknown version rejected with ERROR_INVALID_SIGNATURE
//     - exists built-in with versioned and unversioned access
//     - versions built-in returns metadata, not handler dispatch info
//
//   TestVersioningScenarioA — Single base handler with {1}:
//     - Unversioned and .1. succeed; .2. rejected
//
//   TestVersioningScenarioB — Single handler supporting {1, 2}:
//     - Both .1. and .2. route to the same handler and return identical results
//     - .3. is rejected
//
//   TestVersioningWithValidation — TokenCheckFunction (custom validation handler):
//     Models the ThunderNanoServices JSONRPCPlugin pattern: base={2,3,4} +
//     TokenCheckFunction + v1 clone via CreateHandler.
//     - classification::VALID  → method executes normally (all versions)
//     - classification::INVALID → ERROR_PRIVILIGED_REQUEST (method-level block)
//     - classification::DEFERRED → ERROR_PRIVILIGED_DEFERRED (token-level block)
//     - Validation fires BEFORE handler dispatch (version prefix irrelevant)
//     - Versioned calls (.1., .2.) are subject to the same TokenCheckFunction
//     - DEFERRED takes priority over version-not-found

#include <gtest/gtest.h>
#include "Module.h"

using namespace Thunder;

// =========================================================================
// Helpers
// =========================================================================

// Invoke a method on a plugin without a callsign prefix.
// Passing no callsign (e.g. "echo", "1.echo") is safe when the plugin was
// not attached to an IShell: Split() produces an empty callsign string, which
// satisfies the ASSERT inside InvokeHandler.
static uint32_t PluginCall(PluginHost::IDispatcher& plugin,
    const string& method, const string& params, string& response)
{
    return plugin.Invoke(0, 1, _T(""), method, params, response);
}

// =========================================================================
// VersioningPlugin — used by TestVersioningMain (Scenarios C / D / E)
//
// Handler layout:
//   _handlers[0] (front) — versions {2, 3, 4}
//       echo   -> "v2response"
//       shared -> "shared"
//       v2only -> "v2only"   (registered AFTER clone so v1 never gets it)
//   _handlers[1]          — version  {1}  (clone of front at construction time)
//       echo   -> "v1response"  (overridden)
//       shared -> "shared"      (inherited from clone)
//       v2only -> ABSENT        (registered after clone)
//
// This mirrors the ThunderNanoServices JSONRPCPlugin example exactly.
// =========================================================================

class VersioningPlugin : public PluginHost::JSONRPCSupportsEventStatus {
public:
    VersioningPlugin()
        : PluginHost::JSONRPCSupportsEventStatus({ 2, 3, 4 })
    {
        // Step 1: register shared methods on the base handler (v2/v3/v4).
        Register<Core::JSON::String, Core::JSON::String>(
            _T("echo"), &VersioningPlugin::EchoV2, this);
        Register<Core::JSON::String, Core::JSON::String>(
            _T("shared"), &VersioningPlugin::Shared, this);

        // Step 2: clone the base handler into a new v1 handler.
        //         At this point v1 inherits both echo and shared.
        Core::JSONRPC::Handler& v1 = JSONRPC::CreateHandler({ 1 }, *this);

        // Step 3: override echo on v1 so its response differs from v2.
        v1.Register<Core::JSON::String, Core::JSON::String>(
            _T("echo"), &VersioningPlugin::EchoV1, this);

        // Step 4: register v2only AFTER the clone.
        //         v1 was already cloned so it does NOT inherit this method.
        Register<Core::JSON::String, Core::JSON::String>(
            _T("v2only"), &VersioningPlugin::V2Only, this);

        // Interface version metadata — separate from handler dispatch versions.
        RegisterVersion(_T("TestVersioning"), 2, 0, 0);
    }

    ~VersioningPlugin() override
    {
        Core::JSONRPC::Handler* v1 = JSONRPC::GetHandler(1);
        if (v1 != nullptr) {
            v1->Unregister(_T("echo"));
        }
        Unregister(_T("v2only"));
        Unregister(_T("shared"));
        Unregister(_T("echo"));
    }

    uint32_t EchoV2(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("v2response");
        return Core::ERROR_NONE;
    }

    uint32_t EchoV1(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("v1response");
        return Core::ERROR_NONE;
    }

    uint32_t Shared(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("shared");
        return Core::ERROR_NONE;
    }

    uint32_t V2Only(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("v2only");
        return Core::ERROR_NONE;
    }

    BEGIN_INTERFACE_MAP(VersioningPlugin)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
    END_INTERFACE_MAP

    uint32_t AddRef() const override { return Core::ERROR_COMPOSIT_OBJECT; }
    uint32_t Release() const override { return Core::ERROR_COMPOSIT_OBJECT; }
};

// =========================================================================
// Fixture: TestVersioningMain
// Covers: Scenarios C, D, E, unknown version, exists, versions built-ins
// =========================================================================

class TestVersioningMain : public ::testing::Test {
protected:
    void SetUp() override    { _plugin = new VersioningPlugin(); }
    void TearDown() override { delete _plugin; _plugin = nullptr; }

    uint32_t Call(const string& method, const string& params, string& response)
    {
        return PluginCall(*_plugin, method, params, response);
    }

    VersioningPlugin* _plugin{ nullptr };
};

// -------------------------------------------------------------------------
// Explicit versioned dispatch
// -------------------------------------------------------------------------

TEST_F(TestVersioningMain, ExplicitV2_RoutesToV2Handler)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("2.echo", "{}", response));
    EXPECT_EQ(response, "\"v2response\"") << "Response: " << response;
}

TEST_F(TestVersioningMain, ExplicitV3_RoutesToSameHandlerAsV2)
{
    // The {2,3,4} handler serves v3 and v4 as well — behaviour must be identical.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("3.echo", "{}", response));
    EXPECT_EQ(response, "\"v2response\"") << "Response: " << response;
}

TEST_F(TestVersioningMain, ExplicitV4_RoutesToSameHandlerAsV2)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("4.echo", "{}", response));
    EXPECT_EQ(response, "\"v2response\"") << "Response: " << response;
}

TEST_F(TestVersioningMain, ExplicitV1_RoutesToV1Handler)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.echo", "{}", response));
    EXPECT_EQ(response, "\"v1response\"") << "Response: " << response;
}

// -------------------------------------------------------------------------
// Unversioned dispatch — must use the FIRST handler (the base), NOT v1
// This is the most common regression target: callers incorrectly assume
// that an unversioned call always hits version 1.
// -------------------------------------------------------------------------

TEST_F(TestVersioningMain, Unversioned_UsesFirstHandler_IsV2_NotV1)
{
    // The base handler ({2,3,4}) is front of the list.
    // An unversioned call must return "v2response", not "v1response".
    // Returning "v1response" here would indicate a broken dispatch order.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("echo", "{}", response));
    EXPECT_EQ(response, "\"v2response\"")
        << "Unversioned call must route to the first (base) handler. "
        << "If this returns 'v1response' the handler list ordering is broken. "
        << "Response: " << response;
}

// -------------------------------------------------------------------------
// Inherited method: v1 clone should carry 'shared' from the base handler
// -------------------------------------------------------------------------

TEST_F(TestVersioningMain, V1_InheritedShared_Works)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.shared", "{}", response));
    EXPECT_EQ(response, "\"shared\"") << "Response: " << response;
}

TEST_F(TestVersioningMain, V2_Shared_Works)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("2.shared", "{}", response));
    EXPECT_EQ(response, "\"shared\"") << "Response: " << response;
}

TEST_F(TestVersioningMain, Unversioned_Shared_Works)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("shared", "{}", response));
    EXPECT_EQ(response, "\"shared\"") << "Response: " << response;
}

// -------------------------------------------------------------------------
// Scenario E: method registered only on v2 (after the v1 clone was taken)
// -------------------------------------------------------------------------

TEST_F(TestVersioningMain, V2Only_ExplicitV2_Works)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("2.v2only", "{}", response));
    EXPECT_EQ(response, "\"v2only\"") << "Response: " << response;
}

TEST_F(TestVersioningMain, V2Only_ExplicitV1_Rejected)
{
    // v1 was cloned before v2only was registered so it must not have it.
    string response;
    EXPECT_EQ(Core::ERROR_INVALID_SIGNATURE, Call("1.v2only", "{}", response));
}

TEST_F(TestVersioningMain, V2Only_Unversioned_Works_Via_FirstHandler)
{
    // The first handler ({2,3,4}) has v2only; unversioned routes there.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("v2only", "{}", response));
    EXPECT_EQ(response, "\"v2only\"") << "Response: " << response;
}

// -------------------------------------------------------------------------
// Unknown version rejection
// -------------------------------------------------------------------------

TEST_F(TestVersioningMain, UnknownVersion_99_Rejected)
{
    string response;
    EXPECT_EQ(Core::ERROR_INVALID_SIGNATURE, Call("99.echo", "{}", response));
}

TEST_F(TestVersioningMain, UnknownVersion_5_Rejected)
{
    // Neither {1} nor {2,3,4} covers version 5.
    string response;
    EXPECT_EQ(Core::ERROR_INVALID_SIGNATURE, Call("5.echo", "{}", response));
}

TEST_F(TestVersioningMain, UnknownVersion_0_Rejected)
{
    // Version 0 is never registered.
    string response;
    EXPECT_EQ(Core::ERROR_INVALID_SIGNATURE, Call("0.echo", "{}", response));
}

// -------------------------------------------------------------------------
// exists built-in — validates per-handler method visibility
// -------------------------------------------------------------------------

TEST_F(TestVersioningMain, Exists_V2_Echo_ReturnsTrue)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("2.exists", R"({"method":"echo"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

TEST_F(TestVersioningMain, Exists_V1_Echo_ReturnsTrue)
{
    // v1 has echo (overridden at construction time).
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.exists", R"({"method":"echo"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

TEST_F(TestVersioningMain, Exists_V2_Shared_ReturnsTrue)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("2.exists", R"({"method":"shared"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

TEST_F(TestVersioningMain, Exists_V1_Shared_ReturnsTrue)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.exists", R"({"method":"shared"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

TEST_F(TestVersioningMain, Exists_V1_V2Only_ReturnsFalse)
{
    // v2only was registered after the v1 clone was taken — must be absent on v1.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.exists", R"({"method":"v2only"})", response));
    EXPECT_EQ(response, "false")
        << "v2only must not be visible on the v1 handler. Response: " << response;
}

TEST_F(TestVersioningMain, Exists_V2_V2Only_ReturnsTrue)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("2.exists", R"({"method":"v2only"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

TEST_F(TestVersioningMain, Exists_Unversioned_UsesFirstHandler)
{
    // Unversioned exists resolves against the base ({2,3,4}) handler.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("exists", R"({"method":"v2only"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

TEST_F(TestVersioningMain, Exists_BuiltinMethod_AlwaysTrue)
{
    // Built-in methods (versions, exists, register, unregister) must always
    // report as existing regardless of which handler is selected.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.exists", R"({"method":"versions"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;

    response.clear();
    EXPECT_EQ(Core::ERROR_NONE, Call("2.exists", R"({"method":"register"})", response));
    EXPECT_EQ(response, "true") << "Response: " << response;
}

// -------------------------------------------------------------------------
// versions built-in — reports RegisterVersion() metadata, NOT handler list
// -------------------------------------------------------------------------

TEST_F(TestVersioningMain, Versions_ContainsRegisteredInterfaceName)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("versions", "{}", response));
    EXPECT_NE(response.find("TestVersioning"), string::npos)
        << "versions must contain the registered interface name. Response: " << response;
}

TEST_F(TestVersioningMain, Versions_ContainsCorrectMajorVersion)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("versions", "{}", response));
    EXPECT_NE(response.find("\"major\":2"), string::npos)
        << "versions must contain major:2 from RegisterVersion. Response: " << response;
}

TEST_F(TestVersioningMain, Versions_DoesNotReportHandlerDispatchVersions)
{
    // The versions built-in reports RegisterVersion() metadata only.
    // The handler dispatch versions ({1,2,3,4}) must NOT appear as major values.
    // If this fails it means the two subsystems have been incorrectly merged.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("versions", "{}", response));
    EXPECT_EQ(response.find("\"major\":1"), string::npos)
        << "versions must not expose handler dispatch version 1 as interface metadata. "
        << "Response: " << response;
}

TEST_F(TestVersioningMain, Versions_AccessibleWithExplicitVersion)
{
    // versions is a built-in and must be reachable on any valid handler version.
    string v1Response, v2Response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.versions", "{}", v1Response));
    EXPECT_EQ(Core::ERROR_NONE, Call("2.versions", "{}", v2Response));
    EXPECT_EQ(v1Response, v2Response)
        << "versions must return the same metadata regardless of which handler "
        << "version the call targets.";
}

// =========================================================================
// Scenario A: Single base handler supporting only version {1}
//
// Unversioned -> v1 handler
// .1.         -> v1 handler
// .2.         -> ERROR_INVALID_SIGNATURE (no handler for 2)
// =========================================================================

class ScenarioAPlugin : public PluginHost::JSONRPCSupportsEventStatus {
public:
    // Default constructor: PluginHost::JSONRPC() creates the base handler
    // with support for version {1}.
    ScenarioAPlugin()
        : PluginHost::JSONRPCSupportsEventStatus()
    {
        Register<Core::JSON::String, Core::JSON::String>(
            _T("echo"), &ScenarioAPlugin::Echo, this);
    }

    ~ScenarioAPlugin() override { Unregister(_T("echo")); }

    uint32_t Echo(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("v1only");
        return Core::ERROR_NONE;
    }

    BEGIN_INTERFACE_MAP(ScenarioAPlugin)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
    END_INTERFACE_MAP

    uint32_t AddRef() const override { return Core::ERROR_COMPOSIT_OBJECT; }
    uint32_t Release() const override { return Core::ERROR_COMPOSIT_OBJECT; }
};

class TestVersioningScenarioA : public ::testing::Test {
protected:
    void SetUp() override    { _plugin = new ScenarioAPlugin(); }
    void TearDown() override { delete _plugin; _plugin = nullptr; }

    uint32_t Call(const string& method, const string& params, string& response)
    {
        return PluginCall(*_plugin, method, params, response);
    }

    ScenarioAPlugin* _plugin{ nullptr };
};

TEST_F(TestVersioningScenarioA, Unversioned_RoutesToV1)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("echo", "{}", response));
    EXPECT_EQ(response, "\"v1only\"") << "Response: " << response;
}

TEST_F(TestVersioningScenarioA, ExplicitV1_Works)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.echo", "{}", response));
    EXPECT_EQ(response, "\"v1only\"") << "Response: " << response;
}

TEST_F(TestVersioningScenarioA, ExplicitV2_Rejected)
{
    // No handler for version 2 exists.
    string response;
    EXPECT_EQ(Core::ERROR_INVALID_SIGNATURE, Call("2.echo", "{}", response));
}

TEST_F(TestVersioningScenarioA, ExplicitV99_Rejected)
{
    string response;
    EXPECT_EQ(Core::ERROR_INVALID_SIGNATURE, Call("99.echo", "{}", response));
}

// =========================================================================
// Scenario B: Single handler registered for multiple versions {1, 2}
//
// Both .1.method and .2.method route to the same handler object.
// Behaviour must be identical; only the method selector differs.
// =========================================================================

class ScenarioBPlugin : public PluginHost::JSONRPCSupportsEventStatus {
public:
    ScenarioBPlugin()
        : PluginHost::JSONRPCSupportsEventStatus({ 1, 2 })
    {
        Register<Core::JSON::String, Core::JSON::String>(
            _T("echo"), &ScenarioBPlugin::Echo, this);
    }

    ~ScenarioBPlugin() override { Unregister(_T("echo")); }

    uint32_t Echo(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("same");
        return Core::ERROR_NONE;
    }

    BEGIN_INTERFACE_MAP(ScenarioBPlugin)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
    END_INTERFACE_MAP

    uint32_t AddRef() const override { return Core::ERROR_COMPOSIT_OBJECT; }
    uint32_t Release() const override { return Core::ERROR_COMPOSIT_OBJECT; }
};

class TestVersioningScenarioB : public ::testing::Test {
protected:
    void SetUp() override    { _plugin = new ScenarioBPlugin(); }
    void TearDown() override { delete _plugin; _plugin = nullptr; }

    uint32_t Call(const string& method, const string& params, string& response)
    {
        return PluginCall(*_plugin, method, params, response);
    }

    ScenarioBPlugin* _plugin{ nullptr };
};

TEST_F(TestVersioningScenarioB, ExplicitV1_Works)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.echo", "{}", response));
    EXPECT_EQ(response, "\"same\"") << "Response: " << response;
}

TEST_F(TestVersioningScenarioB, ExplicitV2_Works)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("2.echo", "{}", response));
    EXPECT_EQ(response, "\"same\"") << "Response: " << response;
}

TEST_F(TestVersioningScenarioB, V1AndV2_ReturnIdenticalResult)
{
    // Same handler object serves both versions — results must be equal.
    string v1Response, v2Response;
    EXPECT_EQ(Core::ERROR_NONE, Call("1.echo", "{}", v1Response));
    EXPECT_EQ(Core::ERROR_NONE, Call("2.echo", "{}", v2Response));
    EXPECT_EQ(v1Response, v2Response)
        << "Both versions must return identical results when backed by the same handler.";
}

TEST_F(TestVersioningScenarioB, Unversioned_UsesFirstHandler)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("echo", "{}", response));
    EXPECT_EQ(response, "\"same\"") << "Response: " << response;
}

TEST_F(TestVersioningScenarioB, ExplicitV3_Rejected)
{
    // The {1,2} handler does not cover version 3.
    string response;
    EXPECT_EQ(Core::ERROR_INVALID_SIGNATURE, Call("3.echo", "{}", response));
}

// =========================================================================
// VersionedValidationPlugin — used by TestVersioningWithValidation
//
// Models the ThunderNanoServices JSONRPCPlugin pattern exactly:
//   - Base handler {2, 3, 4} with a TokenCheckFunction
//   - v1 clone via CreateHandler({1}, *this) with an overridden method
//
// Validation rules (mirroring the NanoServices checkvalidation pattern):
//   token == "deferred"  -> classification::DEFERRED   (token-level, checked first)
//   method == "restricted" -> classification::INVALID   (method-level block)
//   otherwise              -> classification::VALID
//
// Methods:
//   "open"       — freely callable on all versions
//   "restricted" — registered but always rejected by the TokenCheckFunction
// =========================================================================

class VersionedValidationPlugin : public PluginHost::JSONRPCSupportsEventStatus {
public:
    VersionedValidationPlugin()
        : PluginHost::JSONRPCSupportsEventStatus(
            { 2, 3, 4 },
            [](const string& token, const string& method, const string& /*params*/)
                -> PluginHost::JSONRPC::classification {
                // Token-level deferral takes priority over method-level checks.
                if (token == _T("deferred")) {
                    return PluginHost::JSONRPC::classification::DEFERRED;
                }
                // Method-level restriction (mirrors the checkvalidation pattern).
                if (method == _T("restricted")) {
                    return PluginHost::JSONRPC::classification::INVALID;
                }
                return PluginHost::JSONRPC::classification::VALID;
            })
    {
        Register<Core::JSON::String, Core::JSON::String>(
            _T("open"), &VersionedValidationPlugin::Open, this);
        Register<Core::JSON::String, Core::JSON::String>(
            _T("restricted"), &VersionedValidationPlugin::Restricted, this);

        // Clone to v1.  The TokenCheckFunction lives on the JSONRPC instance,
        // not on any individual handler, so it fires for v1 calls as well.
        Core::JSONRPC::Handler& v1 = JSONRPC::CreateHandler({ 1 }, *this);

        // Override "open" on v1 so we can confirm the correct handler was hit.
        v1.Register<Core::JSON::String, Core::JSON::String>(
            _T("open"), &VersionedValidationPlugin::OpenV1, this);
    }

    ~VersionedValidationPlugin() override
    {
        Core::JSONRPC::Handler* v1 = JSONRPC::GetHandler(1);
        if (v1 != nullptr) {
            v1->Unregister(_T("open"));
        }
        Unregister(_T("restricted"));
        Unregister(_T("open"));
    }

    uint32_t Open(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("open_v2");
        return Core::ERROR_NONE;
    }

    uint32_t OpenV1(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("open_v1");
        return Core::ERROR_NONE;
    }

    uint32_t Restricted(const Core::JSON::String& /*in*/, Core::JSON::String& out)
    {
        out = _T("should_never_reach_here");
        return Core::ERROR_NONE;
    }

    BEGIN_INTERFACE_MAP(VersionedValidationPlugin)
        INTERFACE_ENTRY(PluginHost::IDispatcher)
    END_INTERFACE_MAP

    uint32_t AddRef() const override { return Core::ERROR_COMPOSIT_OBJECT; }
    uint32_t Release() const override { return Core::ERROR_COMPOSIT_OBJECT; }
};

class TestVersioningWithValidation : public ::testing::Test {
protected:
    void SetUp() override    { _plugin = new VersionedValidationPlugin(); }
    void TearDown() override { delete _plugin; _plugin = nullptr; }

    uint32_t Call(const string& token, const string& method,
                  const string& params, string& response)
    {
        return _plugin->Invoke(0, 1, token, method, params, response);
    }

    VersionedValidationPlugin* _plugin{ nullptr };
};

// -------------------------------------------------------------------------
// classification::VALID — permitted calls execute normally
// -------------------------------------------------------------------------

TEST_F(TestVersioningWithValidation, ValidToken_Open_Succeeds)
{
    // Default handler ({2,3,4}) is used for an unversioned call.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("valid_token", "open", "{}", response));
    EXPECT_EQ(response, "\"open_v2\"") << "Response: " << response;
}

TEST_F(TestVersioningWithValidation, ValidToken_VersionedOpen_Succeeds)
{
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("valid_token", "2.open", "{}", response));
    EXPECT_EQ(response, "\"open_v2\"") << "Response: " << response;
}

TEST_F(TestVersioningWithValidation, ValidToken_V1Open_Succeeds)
{
    // Validation passes (VALID); v1 handler serves the overridden response.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("valid_token", "1.open", "{}", response));
    EXPECT_EQ(response, "\"open_v1\"") << "Response: " << response;
}

TEST_F(TestVersioningWithValidation, EmptyToken_Open_Succeeds)
{
    // Empty token is not special — neither INVALID nor DEFERRED — so it passes.
    string response;
    EXPECT_EQ(Core::ERROR_NONE, Call("", "open", "{}", response));
    EXPECT_EQ(response, "\"open_v2\"") << "Response: " << response;
}

// -------------------------------------------------------------------------
// classification::INVALID — blocked method returns ERROR_PRIVILIGED_REQUEST
// -------------------------------------------------------------------------

TEST_F(TestVersioningWithValidation, ValidToken_RestrictedMethod_Blocked)
{
    // "restricted" is always rejected by the TokenCheckFunction.
    // The method IS registered on the handler — validation fires before dispatch.
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_REQUEST, Call("valid_token", "restricted", "{}", response));
}

TEST_F(TestVersioningWithValidation, ValidToken_VersionedRestrictedMethod_Blocked)
{
    // A version prefix does not bypass validation: realMethod == "restricted".
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_REQUEST, Call("valid_token", "2.restricted", "{}", response));
}

TEST_F(TestVersioningWithValidation, ValidToken_V1RestrictedMethod_Blocked)
{
    // The TokenCheckFunction is on the JSONRPC instance, not on any handler.
    // It fires for v1 calls just as for v2 calls.
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_REQUEST, Call("valid_token", "1.restricted", "{}", response));
}

TEST_F(TestVersioningWithValidation, Validation_FiresBeforeHandlerDispatch)
{
    // Call "99.restricted" — version 99 has no handler, but validation fires
    // first and returns INVALID.  The result must be ERROR_PRIVILIGED_REQUEST,
    // not ERROR_INVALID_SIGNATURE, which confirms dispatch order.
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_REQUEST, Call("valid_token", "99.restricted", "{}", response));
}

// -------------------------------------------------------------------------
// classification::DEFERRED — specific token causes ERROR_PRIVILIGED_DEFERRED
// -------------------------------------------------------------------------

TEST_F(TestVersioningWithValidation, DeferredToken_OpenMethod_Deferred)
{
    // Token == "deferred" triggers DEFERRED regardless of the method.
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_DEFERRED, Call("deferred", "open", "{}", response));
}

TEST_F(TestVersioningWithValidation, DeferredToken_VersionedCall_Deferred)
{
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_DEFERRED, Call("deferred", "2.open", "{}", response));
}

TEST_F(TestVersioningWithValidation, DeferredToken_V1Call_Deferred)
{
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_DEFERRED, Call("deferred", "1.open", "{}", response));
}

TEST_F(TestVersioningWithValidation, DeferredToken_FiresBeforeVersionCheck)
{
    // Version 99 has no handler, but DEFERRED fires before handler lookup.
    // Result must be ERROR_PRIVILIGED_DEFERRED, not ERROR_INVALID_SIGNATURE.
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_DEFERRED, Call("deferred", "99.open", "{}", response));
}

TEST_F(TestVersioningWithValidation, DeferredToken_TakesPriorityOverMethodBlock)
{
    // "restricted" would normally be INVALID, but DEFERRED is checked first
    // in our lambda.  The result must be DEFERRED, not PRIVILIGED_REQUEST.
    string response;
    EXPECT_EQ(Core::ERROR_PRIVILIGED_DEFERRED, Call("deferred", "restricted", "{}", response));
}
