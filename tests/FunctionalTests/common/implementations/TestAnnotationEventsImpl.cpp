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

#include <ImplementationFactory.h>
#include <ITestAnnotationEvents.h>
#include <mutex>
#include <thread>

namespace Thunder {
namespace TestImplementation {

    class TestAnnotationEventsImpl : public FunctionalTest::ITestAnnotationEvents {
    public:
        TestAnnotationEventsImpl()
            : _caps(FunctionalTest::ITestAnnotationEvents::CAP_NONE)
            , _notification(nullptr)
        {
        }

        ~TestAnnotationEventsImpl() override = default;

        TestAnnotationEventsImpl(const TestAnnotationEventsImpl&) = delete;
        TestAnnotationEventsImpl& operator=(const TestAnnotationEventsImpl&) = delete;

        Core::hresult Register(INotification* notification) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification != nullptr) {
                return Core::ERROR_ALREADY_CONNECTED;
            }
            _notification = notification;
            _notification->AddRef();
            // @statuslistener: deliver current caps on a background thread to avoid
            // COM-RPC channel deadlock (cannot make a reverse call on the same channel
            // that is still processing the Register request).
            Caps currentCaps = _caps;
            INotification* sink = _notification;
            sink->AddRef();
            std::thread([sink, currentCaps]() {
                sink->OnCapsChanged(currentCaps);
                sink->Release();
            }).detach();
            return Core::ERROR_NONE;
        }

        Core::hresult Unregister(INotification* notification) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification == notification) {
                _notification->Release();
                _notification = nullptr;
                return Core::ERROR_NONE;
            }
            return Core::ERROR_NOT_EXIST;
        }

        // All notification callbacks are dispatched on background threads to avoid
        // COM-RPC channel deadlock. The server's worker thread cannot make a reverse-proxy
        // call on the same channel it's currently serving a request on.

        Core::hresult SetCaps(const Caps caps) override
        {
            _caps = caps;
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification) {
                INotification* sink = _notification;
                sink->AddRef();
                Caps c = _caps;
                std::thread([sink, c]() { sink->OnCapsChanged(c); sink->Release(); }).detach();
            }
            return Core::ERROR_NONE;
        }

        Core::hresult GetCaps(Caps& caps) const override
        {
            caps = _caps;
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerPortState(const uint8_t port, const State state) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification) {
                INotification* sink = _notification;
                sink->AddRef();
                std::thread([sink, port, state]() { sink->OnPortStateChanged(port, state); sink->Release(); }).detach();
            }
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerStatus(const string& message) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification) {
                INotification* sink = _notification;
                sink->AddRef();
                string msg = message;
                std::thread([sink, msg]() { sink->OnStatusUpdate(msg); sink->Release(); }).detach();
            }
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerLegacyChannel(const uint8_t channel, const uint32_t level) override
        {
            std::lock_guard<std::mutex> lock(_mutex);
            if (_notification) {
                INotification* sink = _notification;
                sink->AddRef();
                std::thread([sink, channel, level]() { sink->OnLegacyChannelEvent(channel, level); sink->Release(); }).detach();
            }
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestAnnotationEventsImpl)
        INTERFACE_ENTRY(FunctionalTest::ITestAnnotationEvents)
        END_INTERFACE_MAP

    private:
        Caps _caps;
        INotification* _notification;
        mutable std::mutex _mutex;
    };

    static Factory::Registrar<FunctionalTest::ITestAnnotationEvents, TestAnnotationEventsImpl> g_annotationEventsRegistrar;

} // namespace TestImplementation
} // namespace Thunder
