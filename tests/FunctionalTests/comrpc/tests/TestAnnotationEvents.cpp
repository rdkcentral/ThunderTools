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

/*
 * COM-RPC event tests for @index on events and @statuslistener.
 *
 * WHY SEPARATE FROM ITestAnnotations:
 * Event notification subscription over COM-RPC requires the interface to be
 * registered as COM-RPC only. When an interface is registered for both
 * COM-RPC and JSON-RPC (HAS_EVENTS), the reverse notification channel uses
 * a different code path that causes timeouts during Register() from test code.
 * This matches the pattern used by the existing ITestEvents interface.
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestAnnotationEvents.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

// ===== Notification Sink =====

class AnnotationEventSink : public ITestAnnotationEvents::INotification {
public:
    AnnotationEventSink()
        : _notifEvent(false, true)
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
        _capsEvents.clear();
        _statusMessages.clear();
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
    void OnPortStateChanged(const uint8_t port, const ITestAnnotationEvents::State state) override
    {
        _portEvents.push_back({port, state});
        _notifCount++;
        _notifEvent.SetEvent();
    }

    void OnCapsChanged(const ITestAnnotationEvents::Caps caps) override
    {
        _capsEvents.push_back(caps);
        _notifCount++;
        _notifEvent.SetEvent();
    }

    void OnStatusUpdate(const string& message) override
    {
        _statusMessages.push_back(message);
        _notifCount++;
        _notifEvent.SetEvent();
    }

    void OnLegacyChannelEvent(const uint8_t channel, const uint32_t level) override
    {
        _legacyEvents.push_back({channel, level});
        _notifCount++;
        _notifEvent.SetEvent();
    }

    struct PortEvent {
        uint8_t port;
        ITestAnnotationEvents::State state;
    };

    struct LegacyEvent {
        uint8_t channel;
        uint32_t level;
    };

    std::vector<PortEvent> _portEvents;
    std::vector<ITestAnnotationEvents::Caps> _capsEvents;
    std::vector<string> _statusMessages;
    std::vector<LegacyEvent> _legacyEvents;

    BEGIN_INTERFACE_MAP(AnnotationEventSink)
    INTERFACE_ENTRY(ITestAnnotationEvents::INotification)
    END_INTERFACE_MAP

private:
    mutable uint32_t _refCount { 1 };
    std::atomic<uint32_t> _notifCount { 0 };
    Core::Event _notifEvent;
};

// ===== Test Fixture =====

class TestAnnotationEvents : public Testing::TestHarness<ITestAnnotationEvents> {
protected:
    void SetUp() override
    {
        Testing::TestHarness<ITestAnnotationEvents>::SetUp();
        _sink = new AnnotationEventSink();
        ASSERT_EQ(_proxy->Register(_sink), Core::ERROR_NONE);
    }

    void TearDown() override
    {
        if (_sink != nullptr) {
            _proxy->Unregister(_sink);
            delete _sink;
            _sink = nullptr;
        }
        Testing::TestHarness<ITestAnnotationEvents>::TearDown();
    }

    AnnotationEventSink* _sink { nullptr };
};

// ===========================================================================
// @statuslistener — immediate state delivery on registration
// ===========================================================================

TEST_F(TestAnnotationEvents, StatusListener_DeliversCurrentState_OnRegister) {
    // The fixture's SetUp already called Register().
    // @statuslistener should have delivered the initial caps (CAP_NONE) immediately.
    ASSERT_TRUE(_sink->WaitForCount(1))
        << "@statuslistener should deliver current state on registration";
    EXPECT_EQ(_sink->_capsEvents[0], ITestAnnotationEvents::CAP_NONE);
}

TEST_F(TestAnnotationEvents, StatusListener_DeliversUpdatedState_ToNewSubscriber) {
    // Set caps to a non-default value
    ASSERT_EQ(_proxy->SetCaps(ITestAnnotationEvents::CAP_AUDIO), Core::ERROR_NONE);

    // Unregister current sink and re-register — should get updated state
    _proxy->Unregister(_sink);
    _sink->Reset();
    ASSERT_EQ(_proxy->Register(_sink), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(1));
    EXPECT_EQ(_sink->_capsEvents[0], ITestAnnotationEvents::CAP_AUDIO);
}

// ===========================================================================
// @index on event — per-port event delivery
// ===========================================================================

TEST_F(TestAnnotationEvents, IndexedEvent_PortState_SinglePort) {
    // Wait for initial statuslistener event
    _sink->WaitForCount(1);
    _sink->Reset();

    ASSERT_EQ(_proxy->TriggerPortState(1, ITestAnnotationEvents::CONNECTED), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(1));
    ASSERT_EQ(_sink->_portEvents.size(), 1u);
    EXPECT_EQ(_sink->_portEvents[0].port, 1u);
    EXPECT_EQ(_sink->_portEvents[0].state, ITestAnnotationEvents::CONNECTED);
}

TEST_F(TestAnnotationEvents, IndexedEvent_PortState_MultiplePorts) {
    _sink->WaitForCount(1);
    _sink->Reset();

    ASSERT_EQ(_proxy->TriggerPortState(0, ITestAnnotationEvents::DISCONNECTED), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerPortState(1, ITestAnnotationEvents::CONNECTING), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerPortState(2, ITestAnnotationEvents::CONNECTED), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(3));
    EXPECT_EQ(_sink->_portEvents[0].port, 0u);
    EXPECT_EQ(_sink->_portEvents[0].state, ITestAnnotationEvents::DISCONNECTED);
    EXPECT_EQ(_sink->_portEvents[1].port, 1u);
    EXPECT_EQ(_sink->_portEvents[1].state, ITestAnnotationEvents::CONNECTING);
    EXPECT_EQ(_sink->_portEvents[2].port, 2u);
    EXPECT_EQ(_sink->_portEvents[2].state, ITestAnnotationEvents::CONNECTED);
}

// ===========================================================================
// Feature change event — fires after SetCaps
// ===========================================================================

TEST_F(TestAnnotationEvents, CapsChanged_FiresOnSet) {
    _sink->WaitForCount(1);
    uint32_t initialCount = _sink->_capsEvents.size();

    auto newCaps = static_cast<ITestAnnotationEvents::Caps>(
        ITestAnnotationEvents::CAP_AUDIO | ITestAnnotationEvents::CAP_VIDEO);
    ASSERT_EQ(_proxy->SetCaps(newCaps), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(initialCount + 1));
    EXPECT_EQ(_sink->_capsEvents.back(), newCaps);
}

TEST_F(TestAnnotationEvents, CapsChanged_None_ClearsAll) {
    _sink->WaitForCount(1);
    _sink->Reset();

    ASSERT_EQ(_proxy->SetCaps(ITestAnnotationEvents::CAP_NET), Core::ERROR_NONE);
    ASSERT_TRUE(_sink->WaitForCount(1));

    _sink->Reset();
    ASSERT_EQ(_proxy->SetCaps(ITestAnnotationEvents::CAP_NONE), Core::ERROR_NONE);
    ASSERT_TRUE(_sink->WaitForCount(1));
    EXPECT_EQ(_sink->_capsEvents[0], ITestAnnotationEvents::CAP_NONE);
}

// ===========================================================================
// Broadcast event (no @index) — all subscribers receive
// ===========================================================================

TEST_F(TestAnnotationEvents, StatusUpdate_Broadcast) {
    _sink->WaitForCount(1);
    _sink->Reset();

    ASSERT_EQ(_proxy->TriggerStatus("system ready"), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(1));
    ASSERT_EQ(_sink->_statusMessages.size(), 1u);
    EXPECT_EQ(_sink->_statusMessages[0], "system ready");
}

TEST_F(TestAnnotationEvents, StatusUpdate_MultipleMessages) {
    _sink->WaitForCount(1);
    _sink->Reset();

    ASSERT_EQ(_proxy->TriggerStatus("msg1"), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerStatus("msg2"), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerStatus("msg3"), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(3));
    EXPECT_EQ(_sink->_statusMessages[0], "msg1");
    EXPECT_EQ(_sink->_statusMessages[1], "msg2");
    EXPECT_EQ(_sink->_statusMessages[2], "msg3");
}

// ===========================================================================
// Duplicate registration
// ===========================================================================

TEST_F(TestAnnotationEvents, Register_Duplicate_ReturnsError) {
    EXPECT_EQ(_proxy->Register(_sink), Core::ERROR_ALREADY_CONNECTED);
}

// ===========================================================================
// Mixed events — port + caps + status interleaved
// ===========================================================================

TEST_F(TestAnnotationEvents, MixedEvents_AllDelivered) {
    _sink->WaitForCount(1);
    _sink->Reset();

    ASSERT_EQ(_proxy->TriggerPortState(5, ITestAnnotationEvents::ERROR), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->SetCaps(ITestAnnotationEvents::CAP_VIDEO), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerStatus("hello"), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(3));
    EXPECT_EQ(_sink->_portEvents.size(), 1u);
    EXPECT_EQ(_sink->_capsEvents.size(), 1u);
    EXPECT_EQ(_sink->_statusMessages.size(), 1u);
}

// ===========================================================================
// @index:deprecated — broadcast-to-all semantics
// The event has @index:deprecated on the channel parameter.
// Despite having an index value, the event should be delivered to ALL
// registered clients regardless of which channel they subscribed to.
// ===========================================================================

TEST_F(TestAnnotationEvents, IndexDeprecated_DeliveredRegardlessOfChannel) {
    _sink->WaitForCount(1);
    _sink->Reset();

    // Trigger legacy channel event with different channel values
    ASSERT_EQ(_proxy->TriggerLegacyChannel(1, 100), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerLegacyChannel(5, 200), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->TriggerLegacyChannel(99, 300), Core::ERROR_NONE);

    // All events should be delivered to our single subscriber
    // regardless of channel value (deprecated index = broadcast)
    ASSERT_TRUE(_sink->WaitForCount(3));
    ASSERT_EQ(_sink->_legacyEvents.size(), 3u);
    EXPECT_EQ(_sink->_legacyEvents[0].channel, 1u);
    EXPECT_EQ(_sink->_legacyEvents[0].level, 100u);
    EXPECT_EQ(_sink->_legacyEvents[1].channel, 5u);
    EXPECT_EQ(_sink->_legacyEvents[1].level, 200u);
    EXPECT_EQ(_sink->_legacyEvents[2].channel, 99u);
    EXPECT_EQ(_sink->_legacyEvents[2].level, 300u);
}

TEST_F(TestAnnotationEvents, IndexDeprecated_PayloadIncludesChannel) {
    _sink->WaitForCount(1);
    _sink->Reset();

    ASSERT_EQ(_proxy->TriggerLegacyChannel(42, 999), Core::ERROR_NONE);

    ASSERT_TRUE(_sink->WaitForCount(1));
    // The channel value is still passed in the event payload
    EXPECT_EQ(_sink->_legacyEvents[0].channel, 42u);
    EXPECT_EQ(_sink->_legacyEvents[0].level, 999u);
}
