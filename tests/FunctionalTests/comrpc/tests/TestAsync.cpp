/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * TestCallback implements ITestAsync::ICallback locally.  When the server
 * calls Complete() on the proxy, the client's InvokeServer dispatches it
 * to the local TestCallback which fulfils the promise.
 */

#include "TestHarness.h"
#include <ITestAsync.h>
#include <chrono>
#include <future>
#include <gtest/gtest.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

// ===== Local ICallback implementation =====

struct CallbackResult {
    ITestAsync::Result status;
    Core::OptionalType<uint32_t> value;
};

class TestCallback : public ITestAsync::ICallback {
public:
    TestCallback()
        : _refCount(1)
        , _promise(std::make_shared<std::promise<CallbackResult>>())
    {
    }

    std::future<CallbackResult> GetFuture()
    {
        return _promise->get_future();
    }

    void Complete(
        const ITestAsync::Result result,
        const Core::OptionalType<uint32_t>& value) override
    {
        _promise->set_value({ result, value });
    }

    uint32_t AddRef() const
    {
        Core::InterlockedIncrement(_refCount);
        return Core::ERROR_NONE;
    }

    uint32_t Release() const
    {
        uint32_t result = Core::ERROR_NONE;
        if (Core::InterlockedDecrement(_refCount) == 0) {
            delete this;
            result = Core::ERROR_DESTRUCTION_SUCCEEDED;
        }
        return result;
    }

    BEGIN_INTERFACE_MAP(TestCallback)
    INTERFACE_ENTRY(ITestAsync::ICallback)
    END_INTERFACE_MAP

private:
    mutable uint32_t _refCount;
    std::shared_ptr<std::promise<CallbackResult>> _promise;
};

// ===== Fixture =====

class TestAsync : public Testing::TestHarness<ITestAsync> { };

// ===== Calculate + callback =====

TEST_F(TestAsync, Calculate_BasicSuccess)
{
    TestCallback cb;
    auto future = cb.GetFuture();

    uint8_t slot {};
    Core::OptionalType<uint16_t> delay(50);
    ASSERT_EQ(_proxy->Calculate(21, delay, slot, &cb), Core::ERROR_NONE);
    EXPECT_LE(slot, 6u);

    auto status = future.wait_for(std::chrono::seconds(3));
    ASSERT_EQ(status, std::future_status::ready);

    auto r = future.get();
    EXPECT_EQ(r.status, ITestAsync::SUCCESS);
    ASSERT_TRUE(r.value.IsSet());
    EXPECT_EQ(r.value.Value(), 42u); // 21 * 2
}

TEST_F(TestAsync, Calculate_DefaultDelay)
{
    TestCallback cb;
    auto future = cb.GetFuture();

    uint8_t slot {};
    Core::OptionalType<uint16_t> noDelay; // unset → impl uses 100ms default
    ASSERT_EQ(_proxy->Calculate(10, noDelay, slot, &cb), Core::ERROR_NONE);

    auto status = future.wait_for(std::chrono::seconds(3));
    ASSERT_EQ(status, std::future_status::ready);
    auto r = future.get();
    EXPECT_EQ(r.status, ITestAsync::SUCCESS);
    EXPECT_EQ(r.value.Value(), 20u);
}

TEST_F(TestAsync, Calculate_SlotInRange)
{
    TestCallback cb;
    auto future = cb.GetFuture();
    uint8_t slot = 255;
    Core::OptionalType<uint16_t> delay(50);
    ASSERT_EQ(_proxy->Calculate(1, delay, slot, &cb), Core::ERROR_NONE);
    EXPECT_LE(slot, 6u);
    future.wait_for(std::chrono::seconds(3));
}

TEST_F(TestAsync, Calculate_MultipleSlots)
{
    // Fill all 7 slots simultaneously
    std::vector<std::unique_ptr<TestCallback>> cbs;
    std::vector<std::future<CallbackResult>> futures;

    for (int i = 0; i < 7; ++i) {
        cbs.push_back(std::make_unique<TestCallback>());
        futures.push_back(cbs.back()->GetFuture());
    }

    uint8_t slots[7] = {};
    Core::OptionalType<uint16_t> delay(50);
    for (int i = 0; i < 7; ++i) {
        ASSERT_EQ(_proxy->Calculate(static_cast<uint32_t>(i + 1), delay, slots[i], cbs[i].get()), Core::ERROR_NONE);
    }

    // All slots should be distinct
    for (int i = 0; i < 7; ++i) {
        for (int j = i + 1; j < 7; ++j) {
            EXPECT_NE(slots[i], slots[j]);
        }
    }

    // Wait for all callbacks
    for (auto& f : futures) {
        auto status = f.wait_for(std::chrono::seconds(3));
        ASSERT_EQ(status, std::future_status::ready);
        auto r = f.get();
        EXPECT_EQ(r.status, ITestAsync::SUCCESS);
    }
}

TEST_F(TestAsync, Calculate_AllSlotsFull_ReturnsUnavailable)
{
    std::vector<std::unique_ptr<TestCallback>> cbs;
    std::vector<std::future<CallbackResult>> futures;

    // Fill all 7
    for (int i = 0; i < 7; ++i) {
        cbs.push_back(std::make_unique<TestCallback>());
        futures.push_back(cbs.back()->GetFuture());
    }
    Core::OptionalType<uint16_t> longDelay(2000); // keep slots busy
    for (int i = 0; i < 7; ++i) {
        uint8_t slot {};
        _proxy->Calculate(1, longDelay, slot, cbs[i].get());
    }

    // 8th should fail
    TestCallback extra;
    auto extraFuture = extra.GetFuture();
    uint8_t slot {};
    Core::OptionalType<uint16_t> delay(50);
    EXPECT_EQ(_proxy->Calculate(1, delay, slot, &extra), Core::ERROR_UNAVAILABLE);

    // Wait for the 7 running slots to complete so they don't linger
    for (auto& f : futures) {
        f.wait_for(std::chrono::seconds(5));
    }
}

// ===== Abort =====

TEST_F(TestAsync, Abort_RunningSlot)
{
    TestCallback cb;
    auto future = cb.GetFuture();

    uint8_t slot {};
    Core::OptionalType<uint16_t> delay(500); // long delay
    ASSERT_EQ(_proxy->Calculate(99, delay, slot, &cb), Core::ERROR_NONE);

    // Abort while running
    EXPECT_EQ(_proxy->Abort(slot), Core::ERROR_NONE);

    // Callback should still fire with ABORTED
    auto status = future.wait_for(std::chrono::seconds(3));
    ASSERT_EQ(status, std::future_status::ready);
    auto r = future.get();
    EXPECT_EQ(r.status, ITestAsync::ABORTED);
}

TEST_F(TestAsync, Abort_IdleSlot_ReturnsError)
{
    // Slot 0 is idle at startup
    EXPECT_NE(_proxy->Abort(0), Core::ERROR_NONE);
}

// ===== SlotResult =====

TEST_F(TestAsync, SlotResult_AfterCompletion)
{
    TestCallback cb;
    auto future = cb.GetFuture();

    uint8_t slot {};
    Core::OptionalType<uint16_t> delay(50);
    ASSERT_EQ(_proxy->Calculate(5, delay, slot, &cb), Core::ERROR_NONE);

    // Wait for completion
    future.wait_for(std::chrono::seconds(3));

    uint32_t result = 0;
    ASSERT_EQ(_proxy->SlotResult(slot, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 10u); // 5 * 2
}

TEST_F(TestAsync, SlotResult_WhileRunning_ReturnsInProgress)
{
    TestCallback cb;
    auto future = cb.GetFuture();

    uint8_t slot {};
    Core::OptionalType<uint16_t> delay(500);
    ASSERT_EQ(_proxy->Calculate(1, delay, slot, &cb), Core::ERROR_NONE);

    uint32_t result = 0;
    EXPECT_EQ(_proxy->SlotResult(slot, result), Core::ERROR_INPROGRESS);

    future.wait_for(std::chrono::seconds(3));
}

TEST_F(TestAsync, SlotResult_UnusedSlot_ReturnsNotExist)
{
    uint32_t result = 0;
    EXPECT_EQ(_proxy->SlotResult(6, result), Core::ERROR_NOT_EXIST);
}

// ===== InProgress =====

TEST_F(TestAsync, InProgress_WhileRunning)
{
    TestCallback cb;
    auto future = cb.GetFuture();

    uint8_t slot {};
    Core::OptionalType<uint16_t> delay(500);
    ASSERT_EQ(_proxy->Calculate(1, delay, slot, &cb), Core::ERROR_NONE);

    bool inProgress = false;
    ASSERT_EQ(_proxy->InProgress(slot, inProgress), Core::ERROR_NONE);
    EXPECT_TRUE(inProgress);

    future.wait_for(std::chrono::seconds(3));
}

TEST_F(TestAsync, InProgress_IdleSlot)
{
    bool inProgress = true;
    ASSERT_EQ(_proxy->InProgress(3, inProgress), Core::ERROR_NONE);
    EXPECT_FALSE(inProgress);
}
