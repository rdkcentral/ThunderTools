/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * Listeners are called synchronously inside each Trigger* method.
 * This works because the client's InvokeServer has spare worker threads
 * to handle the incoming notification call while the original TriggerXxx
 * call is still in flight on another thread.
 */

#include "TestRegistry.h"
#include <ITestEvents.h>
#include <vector>
#include <algorithm>

namespace Thunder {
namespace TestImplementations {

    using namespace FunctionalTest;

    class TestEventsImpl : public ITestEvents {
    public:
        TestEventsImpl() = default;
        ~TestEventsImpl() override
        {
            // Release all registered listeners (best-effort; tests should ClearListeners first)
            _lock.Lock();
            for (auto* n : _listeners) { n->Release(); }
            _listeners.clear();
            _lock.Unlock();
        }

        TestEventsImpl(const TestEventsImpl&) = delete;
        TestEventsImpl& operator=(const TestEventsImpl&) = delete;

        // ===== Subscription =====

        Core::hresult Register(INotification* notification) override
        {
            ASSERT(notification != nullptr);
            _lock.Lock();
            auto it = std::find(_listeners.begin(), _listeners.end(), notification);
            if (it != _listeners.end()) {
                _lock.Unlock();
                return Core::ERROR_ALREADY_CONNECTED;
            }
            notification->AddRef();
            _listeners.push_back(notification);
            _lock.Unlock();
            return Core::ERROR_NONE;
        }

        Core::hresult Unregister(INotification* notification) override
        {
            ASSERT(notification != nullptr);
            _lock.Lock();
            auto it = std::find(_listeners.begin(), _listeners.end(), notification);
            if (it == _listeners.end()) {
                _lock.Unlock();
                return Core::ERROR_NOT_EXIST;
            }
            (*it)->Release();
            _listeners.erase(it);
            _lock.Unlock();
            return Core::ERROR_NONE;
        }

        // ===== Triggers =====

        Core::hresult TriggerDataReceived(const string& data) override
        { Notify([&](INotification* n){ n->OnDataReceived(data); }); return Core::ERROR_NONE; }

        Core::hresult TriggerStateChanged(const uint32_t state) override
        { Notify([&](INotification* n){ n->OnStateChanged(state); }); return Core::ERROR_NONE; }

        Core::hresult TriggerProgress(const uint32_t current, const uint32_t total) override
        { Notify([&](INotification* n){ n->OnProgress(current, total); }); return Core::ERROR_NONE; }

        Core::hresult TriggerCompleted() override
        { Notify([&](INotification* n){ n->OnCompleted(); }); return Core::ERROR_NONE; }

        Core::hresult TriggerColorChanged(const uint8_t color) override
        { Notify([&](INotification* n){ n->OnColorChanged(color); }); return Core::ERROR_NONE; }

        Core::hresult TriggerScanResultAvailable(const ScanResult& result) override
        { Notify([&](INotification* n){ n->OnScanResultAvailable(result); }); return Core::ERROR_NONE; }

        Core::hresult TriggerDisplayModeDetected(const string& displayId, const DisplayMode& mode) override
        { Notify([&](INotification* n){ n->OnDisplayModeDetected(displayId, mode); }); return Core::ERROR_NONE; }

        Core::hresult TriggerScanCompleted(const uint16_t resultCount) override
        {
            std::vector<ScanResult> results;
            results.reserve(resultCount);
            for (uint16_t i = 0; i < resultCount; ++i) {
                ScanResult r;
                r.name           = "network_" + std::to_string(i);
                r.signalStrength = 50 + i;
                r.channel        = static_cast<uint8_t>(i % 14 + 1);
                r.secured        = (i % 2 == 0);
                results.push_back(r);
            }
            Notify([&](INotification* n){ n->OnScanCompleted(results); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerDisplayModesAvailable(const string& displayId, const uint16_t modeCount) override
        {
            if (modeCount == 0) {
                Core::OptionalType<std::vector<DisplayMode>> unset;
                Notify([&](INotification* n){ n->OnDisplayModesAvailable(displayId, unset); });
            } else {
                std::vector<DisplayMode> modes;
                modes.reserve(modeCount);
                for (uint16_t i = 0; i < modeCount; ++i) {
                    modes.push_back({ static_cast<uint16_t>(1920 / (i + 1)),
                                      static_cast<uint16_t>(1080 / (i + 1)),
                                      static_cast<uint8_t>(60 / (i + 1) + 1),
                                      false });
                }
                Core::OptionalType<std::vector<DisplayMode>> opt(modes);
                Notify([&](INotification* n){ n->OnDisplayModesAvailable(displayId, opt); });
            }
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerOptionalDataReceived(const Core::OptionalType<string>& data) override
        { Notify([&](INotification* n){ n->OnOptionalDataReceived(data); }); return Core::ERROR_NONE; }

        Core::hresult TriggerOptionalValueChanged(const Core::OptionalType<uint32_t>& value) override
        { Notify([&](INotification* n){ n->OnOptionalValueChanged(value); }); return Core::ERROR_NONE; }

        // ===== Query =====

        Core::hresult ListenerCount(uint32_t& count) const override
        {
            _lock.Lock();
            count = static_cast<uint32_t>(_listeners.size());
            _lock.Unlock();
            return Core::ERROR_NONE;
        }

        Core::hresult ClearListeners() override
        {
            _lock.Lock();
            for (auto* n : _listeners) { n->Release(); }
            _listeners.clear();
            _lock.Unlock();
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestEventsImpl)
        INTERFACE_ENTRY(ITestEvents)
        END_INTERFACE_MAP

    private:
        template<typename FUNC>
        void Notify(FUNC&& fn)
        {
            // Copy snapshot under lock to avoid holding lock during cross-process calls
            _lock.Lock();
            std::vector<INotification*> snapshot(_listeners);
            for (auto* n : snapshot) { n->AddRef(); }
            _lock.Unlock();

            for (auto* n : snapshot) {
                fn(n);
                n->Release();
            }
        }

        mutable Core::CriticalSection _lock;
        std::vector<INotification*>   _listeners;
    };

    static TestRegistry::ImplementationRegistrar<ITestEvents, TestEventsImpl> g_eventsRegistrar;

} // namespace TestImplementations
} // namespace Thunder
