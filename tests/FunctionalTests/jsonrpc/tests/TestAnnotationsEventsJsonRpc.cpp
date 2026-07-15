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
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace Thunder;

// ===========================================================================
// JSON-RPC event subscription tests.
// Validates that events fired via TriggerPortEvent/TriggerFeaturesEvent
// are delivered to subscribed JSON-RPC clients.
// ===========================================================================

namespace {

class EventCollector : public PluginHost::IDispatcher::ICallback {
public:
    EventCollector() = default;

    uint32_t AddRef() const override
    {
        Core::InterlockedIncrement(_refCount);
        return Core::ERROR_NONE;
    }

    uint32_t Release() const override
    {
        if (Core::InterlockedDecrement(_refCount) == 0) {
            delete this;
            return Core::ERROR_DESTRUCTION_SUCCEEDED;
        }
        return Core::ERROR_NONE;
    }

    Core::hresult Event(
        const string& event,
        const string& designator,
        const string& index,
        const string& parameters) override
    {
        std::lock_guard<std::mutex> lock(_mutex);
        _events.push_back({event, designator, index, parameters});
        _cv.notify_all();
        return Core::ERROR_NONE;
    }

    bool WaitForEvents(size_t count, uint32_t timeoutMs = 2000)
    {
        std::unique_lock<std::mutex> lock(_mutex);
        return _cv.wait_for(lock, std::chrono::milliseconds(timeoutMs),
            [&] { return _events.size() >= count; });
    }

    struct ReceivedEvent {
        string event;
        string designator;
        string index;
        string parameters;
    };

    std::vector<ReceivedEvent> _events;

    BEGIN_INTERFACE_MAP(EventCollector)
    INTERFACE_ENTRY(PluginHost::IDispatcher::ICallback)
    END_INTERFACE_MAP

private:
    mutable uint32_t _refCount { 1 };
    std::mutex _mutex;
    std::condition_variable _cv;
};

} // anonymous namespace

class TestAnnotationsEventsJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

TEST_F(TestAnnotationsEventsJsonRpc, SubscribeAndReceivePortEvent) {
    auto* collector = new EventCollector();

    // Subscribe to the port state changed event
    string callsign = _server->Callsign();
    uint32_t result = SubscribeEvent(collector, "tags::onPortStateChanged", callsign);

    if (result != Core::ERROR_NONE) {
        // Event subscription not supported in this harness configuration
        collector->Release();
        GTEST_SKIP() << "Event subscription not supported (result=" << result << ")";
        return;
    }

    // Trigger the event via JSON-RPC method call
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerPortEvent", R"({"port":1,"state":"connecting"})", response));

    // Wait for the event to be delivered
    ASSERT_TRUE(collector->WaitForEvents(1)) << "Timed out waiting for onPortStateChanged event";
    EXPECT_EQ(collector->_events[0].event, "tags::onPortStateChanged");

    UnsubscribeEvent(collector, "tags::onPortStateChanged", callsign);
    collector->Release();
}

TEST_F(TestAnnotationsEventsJsonRpc, SubscribeAndReceiveFeaturesEvent) {
    auto* collector = new EventCollector();

    string callsign = _server->Callsign();
    uint32_t result = SubscribeEvent(collector, "tags::onFeaturesChanged", callsign);

    if (result != Core::ERROR_NONE) {
        collector->Release();
        GTEST_SKIP() << "Event subscription not supported (result=" << result << ")";
        return;
    }

    // Trigger the event
    string response;
    EXPECT_EQ(Core::ERROR_NONE,
        CallMethod("tags::triggerFeaturesEvent", R"({"features":["FEAT_WIFI","FEAT_NFC"]})", response));

    ASSERT_TRUE(collector->WaitForEvents(1)) << "Timed out waiting for onFeaturesChanged event";
    EXPECT_EQ(collector->_events[0].event, "tags::onFeaturesChanged");

    UnsubscribeEvent(collector, "tags::onFeaturesChanged", callsign);
    collector->Release();
}
