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
#include "TestHarness.h"
#include <ITestAnnotations.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestAnnotations : public Testing::TestHarness<ITestAnnotations> {};

// ===========================================================================
// @deprecated / @obsolete — Methods still callable via COM-RPC
// ===========================================================================

TEST_F(TestAnnotations, DeprecatedEcho_RoundTrip) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->DeprecatedEcho(123, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 123u);
}

TEST_F(TestAnnotations, ObsoleteEcho_RoundTrip) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->ObsoleteEcho(456, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 456u);
}

// ===========================================================================
// @alt — All names route to same implementation
// ===========================================================================

TEST_F(TestAnnotations, EchoWithAlt_RoundTrip) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->EchoWithAlt(99, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 99u);
}

TEST_F(TestAnnotations, Add_RoundTrip) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->Add(10, 20, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 30u);
}

TEST_F(TestAnnotations, Subtract_RoundTrip) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->Subtract(50, 20, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 30u);
}

// ===========================================================================
// @text on struct members — COM-RPC round-trip (names don't affect COM-RPC)
// ===========================================================================

TEST_F(TestAnnotations, EchoDeviceInfo_RoundTrip) {
    ITestAnnotations::DeviceInfo input{};
    input.Name = "TestDevice";
    input.Version = 42;
    input.Active = true;

    ITestAnnotations::DeviceInfo output{};
    ASSERT_EQ(_proxy->EchoDeviceInfo(input, output), Core::ERROR_NONE);
    EXPECT_EQ(output.Name, "TestDevice");
    EXPECT_EQ(output.Version, 42u);
    EXPECT_EQ(output.Active, true);
}

// ===========================================================================
// @text on enum values + @encode:text — COM-RPC (enum wire value unaffected)
// ===========================================================================

TEST_F(TestAnnotations, ConnectionState_SetGet_AllValues) {
    for (auto s : {ITestAnnotations::DISCONNECTED, 
                   ITestAnnotations::CONN_IN_PROGRESS,
                   ITestAnnotations::CONNECTED, 
                   ITestAnnotations::AUTH_FAILURE}) {
        ASSERT_EQ(_proxy->SetConnectionState(s), Core::ERROR_NONE);
        ITestAnnotations::ConnectionState got{};
        ASSERT_EQ(_proxy->GetConnectionState(got), Core::ERROR_NONE);
        EXPECT_EQ(got, s);
    }
}

// ===========================================================================
// @bitmask + @end — COM-RPC round-trip
// ===========================================================================

TEST_F(TestAnnotations, Features_SingleFlag) {
    ASSERT_EQ(_proxy->SetFeatures(ITestAnnotations::FEAT_WIFI), Core::ERROR_NONE);
    ITestAnnotations::Features got{};
    ASSERT_EQ(_proxy->GetFeatures(got), Core::ERROR_NONE);
    EXPECT_EQ(got, ITestAnnotations::FEAT_WIFI);
}

TEST_F(TestAnnotations, Features_MultipleFlags) {
    auto combined = static_cast<ITestAnnotations::Features>(
        ITestAnnotations::FEAT_WIFI | ITestAnnotations::FEAT_NFC);
    ASSERT_EQ(_proxy->SetFeatures(combined), Core::ERROR_NONE);
    ITestAnnotations::Features got{};
    ASSERT_EQ(_proxy->GetFeatures(got), Core::ERROR_NONE);
    EXPECT_EQ(got, combined);
}

TEST_F(TestAnnotations, Features_None) {
    ASSERT_EQ(_proxy->SetFeatures(ITestAnnotations::FEAT_NONE), Core::ERROR_NONE);
    ITestAnnotations::Features got{};
    ASSERT_EQ(_proxy->GetFeatures(got), Core::ERROR_NONE);
    EXPECT_EQ(got, ITestAnnotations::FEAT_NONE);
}

// ===========================================================================
// @encode:base64 — COM-RPC buffer round-trip
// ===========================================================================

TEST_F(TestAnnotations, Base64_SetGet_RoundTrip) {
    const uint8_t input[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    ASSERT_EQ(_proxy->SetPayloadBase64(input, 5), Core::ERROR_NONE);

    uint8_t output[256]{};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->GetPayloadBase64(output, 256, written), Core::ERROR_NONE);
    ASSERT_EQ(written, 5u);
    EXPECT_EQ(::memcmp(input, output, 5), 0);
}

TEST_F(TestAnnotations, Base64_EmptyPayload_MinRestrict) {
    // @restrict:1..256 means 0-byte is rejected
    const uint8_t input[] = {0x00};
    // Size 0 should fail restriction
    uint32_t result = _proxy->SetPayloadBase64(input, 0);
    EXPECT_NE(result, Core::ERROR_NONE);
}

// ===========================================================================
// @encode:hex — COM-RPC buffer round-trip
// ===========================================================================

TEST_F(TestAnnotations, Hex_SetGet_RoundTrip) {
    const uint8_t input[] = {0xDE, 0xAD, 0xBE, 0xEF};
    ASSERT_EQ(_proxy->SetTokenHex(input, 4), Core::ERROR_NONE);

    uint8_t output[64]{};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->GetTokenHex(output, 64, written), Core::ERROR_NONE);
    ASSERT_EQ(written, 4u);
    EXPECT_EQ(::memcmp(input, output, 4), 0);
}

// ===========================================================================
// @extract on struct arrays — COM-RPC round-trip
// ===========================================================================

TEST_F(TestAnnotations, ExtractPoints_SingleElement) {
    std::vector<ITestAnnotations::Point> input = {{10, 20}};
    std::vector<ITestAnnotations::Point> output;
    ASSERT_EQ(_proxy->EchoPoints(input, output), Core::ERROR_NONE);
    ASSERT_EQ(output.size(), 1u);
    EXPECT_EQ(output[0].x, 10);
    EXPECT_EQ(output[0].y, 20);
}

TEST_F(TestAnnotations, ExtractPoints_MultipleElements) {
    std::vector<ITestAnnotations::Point> input = {{1, 2}, {3, 4}, {5, 6}};
    std::vector<ITestAnnotations::Point> output;
    ASSERT_EQ(_proxy->EchoPoints(input, output), Core::ERROR_NONE);
    ASSERT_EQ(output.size(), 3u);
    EXPECT_EQ(output[2].x, 5);
    EXPECT_EQ(output[2].y, 6);
}

// ===========================================================================
// @optional on bool — COM-RPC
// ===========================================================================

TEST_F(TestAnnotations, OptionalBool_Unset_DefaultBehavior) {
    Core::OptionalType<bool> uppercase{};  // not set
    string result;
    ASSERT_EQ(_proxy->FormatText("hello", uppercase, result), Core::ERROR_NONE);
    EXPECT_EQ(result, "hello");
}

TEST_F(TestAnnotations, OptionalBool_SetTrue) {
    Core::OptionalType<bool> uppercase(true);
    string result;
    ASSERT_EQ(_proxy->FormatText("hello", uppercase, result), Core::ERROR_NONE);
    EXPECT_EQ(result, "HELLO");
}

TEST_F(TestAnnotations, OptionalBool_SetFalse) {
    Core::OptionalType<bool> uppercase(false);
    string result;
    ASSERT_EQ(_proxy->FormatText("Hello", uppercase, result), Core::ERROR_NONE);
    EXPECT_EQ(result, "Hello");
}

// ===========================================================================
// @event + @index + @statuslistener — Event notification tests
// ===========================================================================

class AnnotationNotification : public ITestAnnotations::INotification {
public:
    AnnotationNotification()
        : _notifCount(0)
        , _notifEvent(false, true)
    {
        Reset();
    }

    uint32_t AddRef() const override
    {
        Core::InterlockedIncrement(_refCount);
        return Core::ERROR_NONE;
    }

    uint32_t Release() const override
    {
        uint32_t result = Core::ERROR_NONE;
        if (Core::InterlockedDecrement(_refCount) == 0) {
            delete this;
            result = Core::ERROR_DESTRUCTION_SUCCEEDED;
        }
        return result;
    }

    void Reset()
    {
        _portEvents.clear();
        _featureEvents.clear();
        _notifCount.store(0);
        _notifEvent.ResetEvent();
    }

    bool WaitForCount(uint32_t expected, uint32_t timeoutMs = 2000)
    {
        const uint32_t pollMs = 50;
        uint32_t elapsed = 0;
        while (elapsed < timeoutMs) {
            if (_notifCount.load() >= expected) {
                return true;
            }
            _notifEvent.Lock(pollMs);
            _notifEvent.ResetEvent();
            elapsed += pollMs;
        }
        return _notifCount.load() >= expected;
    }

    // INotification
    void OnPortStateChanged(const uint8_t port, const ITestAnnotations::ConnectionState state) override
    {
        _portEvents.push_back({port, state});
        _notifCount++;
        _notifEvent.SetEvent();
    }

    void OnFeaturesChanged(const ITestAnnotations::Features features) override
    {
        _featureEvents.push_back(features);
        _notifCount++;
        _notifEvent.SetEvent();
    }

    struct PortEvent {
        uint8_t port;
        ITestAnnotations::ConnectionState state;
    };

    std::vector<PortEvent> _portEvents;
    std::vector<ITestAnnotations::Features> _featureEvents;

    BEGIN_INTERFACE_MAP(AnnotationNotification)
    INTERFACE_ENTRY(ITestAnnotations::INotification)
    END_INTERFACE_MAP

private:
    mutable uint32_t _refCount = 0;
    std::atomic<uint32_t> _notifCount;
    Core::Event _notifEvent;
};

TEST_F(TestAnnotations, Event_StatusListener_DeliversCurrentState) {
    // Set features before registering
    ASSERT_EQ(_proxy->SetFeatures(ITestAnnotations::FEAT_BLUETOOTH), Core::ERROR_NONE);

    // Register — statuslistener should immediately deliver current features
    auto* sink = new AnnotationNotification();
    sink->AddRef();
    ASSERT_EQ(_proxy->Register(sink), Core::ERROR_NONE);

    // Should have received at least one feature event immediately
    ASSERT_TRUE(sink->WaitForCount(1))
        << "statuslistener should deliver current state on registration";
    EXPECT_EQ(sink->_featureEvents[0], ITestAnnotations::FEAT_BLUETOOTH);

    _proxy->Unregister(sink);
    sink->Release();
}

TEST_F(TestAnnotations, Event_IndexedPort_Delivery) {
    auto* sink = new AnnotationNotification();
    sink->AddRef();
    ASSERT_EQ(_proxy->Register(sink), Core::ERROR_NONE);

    // Wait for the initial statuslistener event
    sink->WaitForCount(1);
    sink->Reset();

    // Trigger port events on different ports
    ASSERT_EQ(_proxy->TriggerPortEvent(1, ITestAnnotations::CONNECTED), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerPortEvent(2, ITestAnnotations::DISCONNECTED), Core::ERROR_NONE);

    ASSERT_TRUE(sink->WaitForCount(2));
    EXPECT_EQ(sink->_portEvents[0].port, 1u);
    EXPECT_EQ(sink->_portEvents[0].state, ITestAnnotations::CONNECTED);
    EXPECT_EQ(sink->_portEvents[1].port, 2u);
    EXPECT_EQ(sink->_portEvents[1].state, ITestAnnotations::DISCONNECTED);

    _proxy->Unregister(sink);
    sink->Release();
}

TEST_F(TestAnnotations, Event_FeatureChange_AfterRegistration) {
    auto* sink = new AnnotationNotification();
    sink->AddRef();
    ASSERT_EQ(_proxy->Register(sink), Core::ERROR_NONE);

    // Wait for statuslistener initial event
    sink->WaitForCount(1);
    uint32_t initialCount = sink->_featureEvents.size();

    // Trigger a new feature change
    auto newFeatures = static_cast<ITestAnnotations::Features>(
        ITestAnnotations::FEAT_WIFI | ITestAnnotations::FEAT_ETHERNET);
    ASSERT_EQ(_proxy->TriggerFeaturesEvent(newFeatures), Core::ERROR_NONE);

    ASSERT_TRUE(sink->WaitForCount(initialCount + 1));
    EXPECT_EQ(sink->_featureEvents.back(), newFeatures);

    _proxy->Unregister(sink);
    sink->Release();
}
