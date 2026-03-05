/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * Notify() enqueues callbacks to a dedicated dispatch thread to avoid a
 * COM-RPC deadlock: the inbound TriggerXxx call occupies the channel thread,
 * so the reverse OnXxx notification must be sent from a different thread.
 *
 * The dispatch thread is self-contained — no Thunder WorkerPool required.
 */

#include "TestRegistry.h"
#include <ITestEvents.h>
#include <algorithm>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace Thunder {
namespace TestImplementations {

    using namespace FunctionalTest;

    class TestEventsImpl : public ITestEvents {
    public:
        TestEventsImpl()
            : _stopDispatch(false)
            , _dispatchThread(&TestEventsImpl::DispatchLoop, this)
        {
        }

        ~TestEventsImpl() override
        {
            // Stop dispatch thread cleanly before releasing listeners
            {
                std::unique_lock<std::mutex> lock(_queueMutex);
                _stopDispatch = true;
                _queueCv.notify_all();
            }
            _dispatchThread.join();

            _lock.Lock();
            for (auto* n : _listeners) {
                n->Release();
            }
            _listeners.clear();
            _lock.Unlock();
        }

        TestEventsImpl(const TestEventsImpl&) = delete;
        TestEventsImpl& operator=(const TestEventsImpl&) = delete;

        Core::hresult Flush()
        {
            std::mutex m;
            std::condition_variable cv;
            bool done = false;
            {
                std::unique_lock<std::mutex> lock(_queueMutex);
                _queue.push([&m, &cv, &done]() {
                    std::unique_lock<std::mutex> l(m);
                    done = true;
                    cv.notify_one();
                });
                _queueCv.notify_one();
            }
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&done] { return done; });
            return Core::ERROR_NONE;
        }

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

            if (_listeners.empty() == true) {
                Flush();
            }
            return Core::ERROR_NONE;
        }

        // ===== Triggers — capture by value; return before dispatch runs =====

        Core::hresult TriggerDataReceived(const string& data) override
        {
            Notify([data](INotification* n) { n->OnDataReceived(data); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerStateChanged(const uint32_t state) override
        {
            Notify([state](INotification* n) { n->OnStateChanged(state); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerProgress(const uint32_t current, const uint32_t total) override
        {
            Notify([current, total](INotification* n) { n->OnProgress(current, total); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerCompleted() override
        {
            Notify([](INotification* n) { n->OnCompleted(); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerColorChanged(const uint8_t color) override
        {
            Notify([color](INotification* n) { n->OnColorChanged(color); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerScanResultAvailable(const ScanResult& result) override
        {
            Notify([result](INotification* n) { n->OnScanResultAvailable(result); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerDisplayModeDetected(const string& displayId, const DisplayMode& mode) override
        {
            Notify([displayId, mode](INotification* n) { n->OnDisplayModeDetected(displayId, mode); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerScanCompleted(const uint16_t resultCount) override
        {
            std::vector<ScanResult> results;
            results.reserve(resultCount);
            for (uint16_t i = 0; i < resultCount; ++i) {
                ScanResult r;
                r.name = "network_" + std::to_string(i);
                r.signalStrength = 50 + i;
                r.channel = static_cast<uint8_t>(i % 14 + 1);
                r.secured = (i % 2 == 0);
                results.push_back(r);
            }
            Notify([results](INotification* n) { n->OnScanCompleted(results); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerDisplayModesAvailable(const string& displayId, const uint16_t modeCount) override
        {
            if (modeCount == 0) {
                Notify([displayId](INotification* n) {
                    Core::OptionalType<std::vector<DisplayMode>> unset;
                    n->OnDisplayModesAvailable(displayId, unset);
                });
            } else {
                std::vector<DisplayMode> modes;
                modes.reserve(modeCount);
                for (uint16_t i = 0; i < modeCount; ++i) {
                    modes.push_back({ static_cast<uint16_t>(1920 / (i + 1)),
                        static_cast<uint16_t>(1080 / (i + 1)),
                        static_cast<uint8_t>(60 / (i + 1) + 1),
                        false });
                }
                Notify([displayId, modes](INotification* n) {
                    Core::OptionalType<std::vector<DisplayMode>> opt(modes);
                    n->OnDisplayModesAvailable(displayId, opt);
                });
            }
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerOptionalDataReceived(const Core::OptionalType<string>& data) override
        {
            Notify([data](INotification* n) { n->OnOptionalDataReceived(data); });
            return Core::ERROR_NONE;
        }

        Core::hresult TriggerOptionalValueChanged(const Core::OptionalType<uint32_t>& value) override
        {
            Notify([value](INotification* n) { n->OnOptionalValueChanged(value); });
            return Core::ERROR_NONE;
        }

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
            std::vector<INotification*> snapshot;
            snapshot.swap(_listeners);
            _lock.Unlock();

            // Post releases to dispatch thread — Release() triggers reverse RPC
            // and cannot be called from the inbound channel thread
            {
                std::unique_lock<std::mutex> lock(_queueMutex);
                _queue.push([snapshot]() mutable {
                    for (auto* n : snapshot) {
                        n->Release();
                    }
                });
                _queueCv.notify_one();
            }

            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestEventsImpl)
        INTERFACE_ENTRY(ITestEvents)
        END_INTERFACE_MAP

    private:
        using Job = std::function<void()>;

        // Enqueue a job that fans out fn to a snapshot of current listeners.
        // Captures by value so callers can return immediately.
        void Notify(std::function<void(INotification*)> fn)
        {
            _lock.Lock();
            std::vector<INotification*> snapshot(_listeners);
            for (auto* n : snapshot) {
                n->AddRef();
            }
            _lock.Unlock();

            if (snapshot.empty()) {
                return;
            }

            std::unique_lock<std::mutex> lock(_queueMutex);
            _queue.push([fn, snapshot]() mutable {
                for (auto* n : snapshot) {
                    fn(n);
                    n->Release();
                }
            });
            _queueCv.notify_one();
        }

        void DispatchLoop()
        {
            while (true) {
                Job job;
                {
                    std::unique_lock<std::mutex> lock(_queueMutex);
                    _queueCv.wait(lock, [this] {
                        return _stopDispatch || !_queue.empty();
                    });

                    if (_stopDispatch && _queue.empty()) {
                        break;
                    }

                    job = std::move(_queue.front());
                    _queue.pop();
                }
                job();
            }
        }

        mutable Core::CriticalSection _lock;
        std::vector<INotification*> _listeners;

        std::mutex _queueMutex;
        std::condition_variable _queueCv;
        std::queue<Job> _queue;
        bool _stopDispatch;
        std::thread _dispatchThread;
    };

    static TestRegistry::ImplementationRegistrar<ITestEvents, TestEventsImpl> g_eventsRegistrar;

} // namespace TestImplementations
} // namespace Thunder