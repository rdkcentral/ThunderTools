/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "JsonRpcTestHarness.h"

#include <mutex>
#include <vector>

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

constexpr const char* kVersionEvent = "versionProbeEvent";
constexpr const char* kSubscriberId = "versioning-client";

struct RecordedEvent {
    string event;
    string designator;
    string index;
    string parameters;
};

class TestEventSink : public PluginHost::IDispatcher::ICallback {
public:
    TestEventSink()
        : _refCount(1)
    {
    }

    ~TestEventSink() override = default;

    Core::hresult Event(const string& event, const string& designator, const string& index, const string& parameters) override
    {
        std::lock_guard<std::mutex> lock(_adminLock);
        _events.push_back({ event, designator, index, parameters });
        printf("[versioning-test] event=%s designator=%s index=%s params=%s\n",
            event.c_str(), designator.c_str(), index.c_str(), parameters.c_str());
        return Core::ERROR_NONE;
    }

    uint32_t AddRef() const override
    {
        Core::InterlockedIncrement(_refCount);
        return Core::ERROR_NONE;
    }

    uint32_t Release() const override
    {
        if (Core::InterlockedDecrement(_refCount) == 0) {
            delete this;
        }
        return Core::ERROR_NONE;
    }

    void Clear()
    {
        std::lock_guard<std::mutex> lock(_adminLock);
        _events.clear();
    }

    size_t Count() const
    {
        std::lock_guard<std::mutex> lock(_adminLock);
        return _events.size();
    }

    RecordedEvent Last() const
    {
        std::lock_guard<std::mutex> lock(_adminLock);
        EXPECT_FALSE(_events.empty());
        return _events.back();
    }

    BEGIN_INTERFACE_MAP(TestEventSink)
        INTERFACE_ENTRY(PluginHost::IDispatcher::ICallback)
    END_INTERFACE_MAP

private:
    mutable uint32_t _refCount;
    mutable std::mutex _adminLock;
    std::vector<RecordedEvent> _events;
};

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

        v1->Register("emitVersionedEvent",
            Core::JSONRPC::InvokeFunction(
                [&server](const Core::JSONRPC::Context&, const string&, const string&, string& response) -> uint32_t {
                    Core::JSON::String payload;
                    payload = _T("v1-event");
                    response = R"("event-v1-sent")";
                    server.Notify(kVersionEvent, payload);
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

        v2.Register("emitVersionedEvent",
            Core::JSONRPC::InvokeFunction(
                [&server](const Core::JSONRPC::Context&, const string&, const string&, string& response) -> uint32_t {
                    Core::JSON::String payload;
                    payload = _T("v2-event");
                    response = R"("event-v2-sent")";
                    server.Notify(kVersionEvent, payload);
                    return Core::ERROR_NONE;
                }));

        v2.Register("versionTwoOnly",
            Core::JSONRPC::InvokeFunction(
                [](const Core::JSONRPC::Context&, const string&, const string&, string& response) -> uint32_t {
                    response = R"("v2-only")";
                    return Core::ERROR_NONE;
                }));

        printf("  [versioning] v1 and v2 handlers configured\n");
    }
);

} // namespace

class TestVersioningJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

class TestVersioningEventsJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {
protected:
    void SetUp() override
    {
        JsonRpcTesting::JsonRpcTestHarness::SetUp();
        _sink = new TestEventSink();
        const uint32_t subscribe = SubscribeEvent(_sink, kVersionEvent, kSubscriberId);
        printf("[versioning-test] subscribe event=%s result=%u\n", kVersionEvent, subscribe);
        ASSERT_EQ(Core::ERROR_NONE, subscribe);
    }

    void TearDown() override
    {
        if (_sink != nullptr) {
            _server->Dropped(_sink);
            printf("[versioning-test] dropped callback subscriptions for event=%s\n", kVersionEvent);
            _sink->Release();
            _sink = nullptr;
        }

        JsonRpcTesting::JsonRpcTestHarness::TearDown();
    }

    TestEventSink* _sink { nullptr };
};

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

TEST_F(TestVersioningJsonRpc, ExistingGeneratedMethodIsInheritedByVersionTwoHandler)
{
    string response;
    const string parameters = R"({"input":84})";
    LogVersionedCall(2, "echoUInt8", parameters);
    const uint32_t result = CallVersionedMethod(2, "echoUInt8", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("84"), string::npos) << "Response: " << response;
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

TEST_F(TestVersioningJsonRpc, VersionTwoOnlyMethodRequiresVersionTwo)
{
    string response;
    const string parameters = R"({})";

    LogVersionedCall(2, "versionTwoOnly", parameters);
    uint32_t result = CallVersionedMethod(2, "versionTwoOnly", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("v2-only"), string::npos) << "Response: " << response;

    response.clear();
    LogVersionedCall(1, "versionTwoOnly", parameters);
    result = CallVersionedMethod(1, "versionTwoOnly", parameters, response);
    LogCallResult(result, response);
    EXPECT_NE(Core::ERROR_NONE, result);
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

TEST_F(TestVersioningJsonRpc, UnversionedCallDoesNotReachLaterVersionSpecificMethods)
{
    string response;
    const string parameters = R"({})";
    LogUnversionedCall("versionTwoOnly", parameters);
    const uint32_t result = CallMethod("versionTwoOnly", parameters, response);
    LogCallResult(result, response);
    EXPECT_NE(Core::ERROR_NONE, result);
}

TEST_F(TestVersioningJsonRpc, ExistsWithoutVersionUsesFirstHandler)
{
    string response;
    const string parameters = R"({"method":"versionTwoOnly"})";
    LogUnversionedCall("exists", parameters);
    const uint32_t result = CallMethod("exists", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("false"), string::npos) << "Response: " << response;
}

TEST_F(TestVersioningJsonRpc, ExistsWithExplicitVersionUsesMatchingHandler)
{
    string response;
    const string parameters = R"({"method":"versionTwoOnly"})";
    LogVersionedCall(2, "exists", parameters);
    const uint32_t result = CallVersionedMethod(2, "exists", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("true"), string::npos) << "Response: " << response;
}

TEST_F(TestVersioningJsonRpc, VersionsBuiltInReportsInterfaceMetadataNotHandlerVersions)
{
    string response;
    const string parameters = R"({})";
    LogUnversionedCall("versions", parameters);
    const uint32_t result = CallMethod("versions", parameters, response);
    LogCallResult(result, response);
    EXPECT_EQ(Core::ERROR_NONE, result);
    EXPECT_NE(response.find("JTestPrimitives"), string::npos) << "Response: " << response;
    EXPECT_EQ(response.find("\"major\":2"), string::npos) << "Response: " << response;
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

TEST_F(TestVersioningEventsJsonRpc, VersionOneNotificationUsesVersionOnePayload)
{
    string response;
    const string parameters = R"({})";
    _sink->Clear();
    LogVersionedCall(1, "emitVersionedEvent", parameters);
    const uint32_t result = CallVersionedMethod(1, "emitVersionedEvent", parameters, response);
    LogCallResult(result, response);
    ASSERT_EQ(Core::ERROR_NONE, result);
    ASSERT_EQ(static_cast<size_t>(1), _sink->Count());
    const RecordedEvent event = _sink->Last();
    EXPECT_EQ(string(kVersionEvent), event.event);
    EXPECT_EQ(string(kSubscriberId), event.designator);
    EXPECT_NE(event.parameters.find("v1-event"), string::npos) << "Event payload: " << event.parameters;
}

TEST_F(TestVersioningEventsJsonRpc, VersionTwoNotificationUsesVersionTwoPayload)
{
    string response;
    const string parameters = R"({})";
    _sink->Clear();
    LogVersionedCall(2, "emitVersionedEvent", parameters);
    const uint32_t result = CallVersionedMethod(2, "emitVersionedEvent", parameters, response);
    LogCallResult(result, response);
    ASSERT_EQ(Core::ERROR_NONE, result);
    ASSERT_EQ(static_cast<size_t>(1), _sink->Count());
    const RecordedEvent event = _sink->Last();
    EXPECT_NE(event.parameters.find("v2-event"), string::npos) << "Event payload: " << event.parameters;
}

TEST_F(TestVersioningEventsJsonRpc, UnversionedNotificationUsesFirstHandlerPayload)
{
    string response;
    const string parameters = R"({})";
    _sink->Clear();
    LogUnversionedCall("emitVersionedEvent", parameters);
    const uint32_t result = CallMethod("emitVersionedEvent", parameters, response);
    LogCallResult(result, response);
    ASSERT_EQ(Core::ERROR_NONE, result);
    ASSERT_EQ(static_cast<size_t>(1), _sink->Count());
    const RecordedEvent event = _sink->Last();
    EXPECT_NE(event.parameters.find("v1-event"), string::npos) << "Event payload: " << event.parameters;
}

TEST_F(TestVersioningEventsJsonRpc, UnknownVersionDoesNotDeliverNotification)
{
    string response;
    const string parameters = R"({})";
    _sink->Clear();
    LogVersionedCall(99, "emitVersionedEvent", parameters);
    const uint32_t result = CallVersionedMethod(99, "emitVersionedEvent", parameters, response);
    LogCallResult(result, response);
    EXPECT_NE(Core::ERROR_NONE, result);
    EXPECT_EQ(static_cast<size_t>(0), _sink->Count());
}