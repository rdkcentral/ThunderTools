/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * Each Calculate call occupies one of 7 slots (0..6).
 * A detached thread sleeps delayMs, computes value*2, stores the result,
 * then calls cb->Complete() on the ICallback proxy (which sends a message
 * back to the client). The client's InvokeServer handles that incoming call
 * on a spare worker thread.
 */

#include "TestRegistry.h"
#include <ITestAsync.h>
#include <array>
#include <thread>
#include <chrono>

namespace Thunder {
namespace TestImplementations {

    using namespace FunctionalTest;

    class TestAsyncImpl : public ITestAsync {
    public:
        TestAsyncImpl()
        {
            for (auto& s : _slots) { s.state = SlotState::EMPTY; s.result = 0; }
        }

        ~TestAsyncImpl() override
        {
            // In a production impl we'd join threads; for tests, slots are short-lived
        }

        TestAsyncImpl(const TestAsyncImpl&) = delete;
        TestAsyncImpl& operator=(const TestAsyncImpl&) = delete;

        Core::hresult Calculate(
            const uint32_t value,
            const Core::OptionalType<uint16_t>& delayMs,
            uint8_t& slot,
            ITestAsync::ICallback* const cb) override
        {
            uint16_t delay = delayMs.IsSet() ? delayMs.Value() : 100;

            _lock.Lock();
            int8_t freeSlot = -1;
            for (int8_t i = 0; i < 7; ++i) {
                if (_slots[i].state == SlotState::EMPTY) {
                    freeSlot = i;
                    break;
                }
            }
            if (freeSlot < 0) {
                _lock.Unlock();
                return Core::ERROR_UNAVAILABLE;
            }
            _slots[freeSlot].state = SlotState::RUNNING;
            slot = static_cast<uint8_t>(freeSlot);
            _lock.Unlock();

            // AddRef the callback so it stays alive in the background thread
            if (cb != nullptr) { cb->AddRef(); }

            const uint8_t slotIdx = slot;
            std::thread([this, slotIdx, value, delay, cb]() {
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));

                const uint32_t computed = value * 2;

                _lock.Lock();
                if (_slots[slotIdx].state == SlotState::RUNNING) {
                    _slots[slotIdx].state  = SlotState::COMPLETE;
                    _slots[slotIdx].result = computed;
                }
                const bool wasAborted = (_slots[slotIdx].state == SlotState::ABORTED);
                _lock.Unlock();

                if (cb != nullptr) {
                    if (wasAborted) {
                        cb->Complete(ITestAsync::ABORTED, Core::OptionalType<uint32_t>{});
                    } else {
                        cb->Complete(ITestAsync::SUCCESS, Core::OptionalType<uint32_t>(computed));
                    }
                    cb->Release();
                }
            }).detach();

            return Core::ERROR_NONE;
        }

        Core::hresult Abort(const uint8_t slot) override
        {
            if (slot > 6) return Core::ERROR_INVALID_INPUT_LENGTH;
            _lock.Lock();
            if (_slots[slot].state != SlotState::RUNNING) {
                _lock.Unlock();
                return Core::ERROR_ILLEGAL_STATE;
            }
            _slots[slot].state = SlotState::ABORTED;
            _lock.Unlock();
            return Core::ERROR_NONE;
        }

        Core::hresult SlotResult(const uint8_t slot, uint32_t& result) const override
        {
            if (slot > 6) return Core::ERROR_INVALID_INPUT_LENGTH;
            _lock.Lock();
            SlotState state = _slots[slot].state;
            uint32_t  val   = _slots[slot].result;
            _lock.Unlock();

            switch (state) {
                case SlotState::COMPLETE:
                    result = val;
                    const_cast<TestAsyncImpl*>(this)->FreeSlot(slot); // consume on read
                    return Core::ERROR_NONE;
                case SlotState::RUNNING:
                    return Core::ERROR_INPROGRESS;
                default:
                    return Core::ERROR_NOT_EXIST;
            }
        }

        Core::hresult InProgress(const uint8_t slot, bool& inProgress) const override
        {
            if (slot > 6) return Core::ERROR_INVALID_INPUT_LENGTH;
            _lock.Lock();
            inProgress = (_slots[slot].state == SlotState::RUNNING);
            _lock.Unlock();
            return Core::ERROR_NONE;
        }

        BEGIN_INTERFACE_MAP(TestAsyncImpl)
        INTERFACE_ENTRY(ITestAsync)
        END_INTERFACE_MAP

    private:
        enum class SlotState : uint8_t { EMPTY, RUNNING, COMPLETE, ABORTED };

        struct Slot {
            SlotState state;
            uint32_t  result;
        };

        void FreeSlot(uint8_t slot)
        {
            _lock.Lock();
            _slots[slot].state  = SlotState::EMPTY;
            _slots[slot].result = 0;
            _lock.Unlock();
        }

        mutable Core::CriticalSection _lock;
        std::array<Slot, 7>           _slots;
    };

    static TestRegistry::ImplementationRegistrar<ITestAsync, TestAsyncImpl> g_asyncRegistrar;

} // namespace TestImplementations
} // namespace Thunder
