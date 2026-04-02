/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "JsonRpcTestHarness.h"

using namespace Thunder;

// =============================================================================
// Handwritten versioned handler setup — mirrors ThunderNanoServices pattern
// (examples/JSONRPC/Plugin/JSONRPCPlugin.cpp, CreateHandler({1}, *this))
//
// Key facts from Thunder runtime (PluginHost::JSONRPC):
//   - Handler selection uses only the major version number from the designator.
//   - Unversioned call  → first handler in the list (NOT necessarily version 1).
//   - Explicit version  → first handler whose HasVersionSupport(v) returns true.
//   - Unknown version   → ERROR_INVALID_SIGNATURE.
//   - CreateHandler({N}, source) clones the source handler then returns the new
//     handler; calling Register() on it overrides only the changed entries.
//   - RegisterVersion() (used by generated code) only feeds the "versions"
//     metadata call — it is NOT related to handler dispatch routing.
// =============================================================================

namespace {

void LogVersionedCall(const uint32_t version, const string& method, const string& parameters)
{
    printf("[versioning-test] invoking TestPlugin.%u.%s params=%s\n", version, method.c_str(), parameters.c_str());
}

void LogUnversionedCall(const string& method, const string& parameters)
{
    printf("[versioning-test] invoking TestPlugin.%s params=%s\n", method.c_str(), parameters.c_str());
}

void LogCallResult(const uint32_t result, const string& response)
{
    printf("[versioning-test] result=%u response=%s\n", result, response.c_str());
}

// Phase-2 registrar: runs after all generated interface registrations so that
// the CreateHandler clone has a fully populated v1 method table.
static JsonRpcServer::JsonRpcVersionedRegistrar g_versionedProbeSetup(
    [](JsonRpcServer::JsonRpcServer& server) {
        // Step 1: Register "versionProbe" on the existing v1 (front) handler.
        Core::JSONRPC::Handler* v1 = server.GetHandler(1);
        if (v1 == nullptr) {
            printf("  [versioning] WARNING: v1 handler not found, skipping versioned setup\n");
            return;
        }

        v1->Register("versionProbe",
            Core::JSONRPC::InvokeFunction(
                [](const Core::JSONRPC::Context&, const string&, const string&, string& response) -> uint32_t {
                    response = R"("v1")";
                    return Core::ERROR_NONE;
                }));

        // Step 2: Clone v1 into a new handler that supports version 2.
        //         The clone copies the full v1 method table (including all
        //         generated interface methods registered in phase 1).
        Core::JSONRPC::Handler& v2 = server.CreateHandler({2}, *v1);

        // Step 3: Override only "versionProbe" on the v2 handler.
        //         All other methods (echoUInt8, toggleColor, etc.) remain
        //         identical to v1 — exactly the ThunderNanoServices pattern.
        v2.Register("versionProbe",
            Core::JSONRPC::InvokeFunction(
                [](const Core::JSONRPC::Context&, const string&, const string&, string& response) -> uint32_t {
                    response = R"("v2")";
                    return Core::ERROR_NONE;
                }));

        printf("  [versioning] v1 and v2 handlers configured\n");
    }
);

} // namespace

class TestVersioningJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// An existing generated method is reachable via Callsign.1.method
TEST_F(TestVersioningJsonRpc, ExistingGeneratedMethodWorksOnVersionOneDesignator)
{
    string response;
    const string parameters = R"({"input":42})";
    LogVersionedCall(1, "echoUInt8", parameters);
    const uint32_t result = CallVersionedMethod(1, "echoUInt8", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("42"), string::npos) << "Response: " << response;
}

// Callsign.1.versionProbe reaches the v1 handler
TEST_F(TestVersioningJsonRpc, VersionOneDesignatorRoutesToVersionOneHandler)
{
    string response;
    const string parameters = R"({})";
    LogVersionedCall(1, "versionProbe", parameters);
    const uint32_t result = CallVersionedMethod(1, "versionProbe", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("v1"), string::npos) << "Response: " << response;
}

// Callsign.2.versionProbe reaches the v2 handler (overridden method)
TEST_F(TestVersioningJsonRpc, VersionTwoDesignatorRoutesToVersionTwoHandler)
{
    string response;
    const string parameters = R"({})";
    LogVersionedCall(2, "versionProbe", parameters);
    const uint32_t result = CallVersionedMethod(2, "versionProbe", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("v2"), string::npos) << "Response: " << response;
}

// A method NOT overridden on v2 should still work (inherited from clone)
TEST_F(TestVersioningJsonRpc, NonOverriddenMethodWorksOnVersionTwoHandler)
{
    string response;
    const string parameters = R"({"input":7})";
    LogVersionedCall(2, "echoUInt8", parameters);
    const uint32_t result = CallVersionedMethod(2, "echoUInt8", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("7"), string::npos) << "Response: " << response;
}

// Unversioned call lands on the first (v1) handler
TEST_F(TestVersioningJsonRpc, UnversionedCallLandsOnFirstHandler)
{
    string response;
    // Note: this is "first handler in list", not guaranteed version 1 by spec.
    // In this test the front handler supports {1}, so this exercises that case.
    const string parameters = R"({})";
    LogUnversionedCall("versionProbe", parameters);
    const uint32_t result = CallMethod("versionProbe", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("v1"), string::npos) << "Response: " << response;
}

// An unknown version is rejected with an error
TEST_F(TestVersioningJsonRpc, UnknownVersionIsRejected)
{
    string response;
    const string parameters = R"({})";
    LogVersionedCall(99, "versionProbe", parameters);
    const uint32_t result = CallVersionedMethod(99, "versionProbe", parameters, response);
    LogCallResult(result, response);
    EXPECT_NE(Core::ERROR_NONE, result);
}