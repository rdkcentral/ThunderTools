/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestIterators.h>
#include <thread>
#include <chrono>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestIterators : public Testing::TestHarness<ITestIterators> {};

// ===== Direct client-side iteration =====

TEST_F(TestIterators, GetStrings_ClientIteration) {
    RPC::IStringIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetStrings(5, iter), Core::ERROR_NONE);
    ASSERT_NE(iter, nullptr);

    std::vector<string> elements;
    string element;
    iter->Reset(0);
    while (iter->Next(element)) elements.push_back(element);

    EXPECT_EQ(elements.size(), 5u);
    EXPECT_EQ(elements[0], "item_0");
    EXPECT_EQ(elements[4], "item_4");
    iter->Release();
}

TEST_F(TestIterators, GetValues_ClientIteration) {
    RPC::IValueIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetValues(4, iter), Core::ERROR_NONE);
    ASSERT_NE(iter, nullptr);

    uint32_t count = 0, sum = 0, element{};
    iter->Reset(0);
    while (iter->Next(element)) { sum += element; ++count; }

    EXPECT_EQ(count, 4u);
    EXPECT_EQ(sum, 0u + 1u + 2u + 3u);
    iter->Release();
}

TEST_F(TestIterators, GetEmptyStringIterator) {
    RPC::IStringIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetEmptyStringIterator(iter), Core::ERROR_NONE);
    ASSERT_NE(iter, nullptr);
    string element;
    iter->Reset(0);
    EXPECT_FALSE(iter->Next(element));
    iter->Release();
}

TEST_F(TestIterators, GetEmptyValueIterator) {
    RPC::IValueIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetEmptyValueIterator(iter), Core::ERROR_NONE);
    ASSERT_NE(iter, nullptr);
    uint32_t element{};
    iter->Reset(0);
    EXPECT_FALSE(iter->Next(element));
    iter->Release();
}

TEST_F(TestIterators, GetLargeStringIterator) {
    RPC::IStringIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetLargeStringIterator(200, iter), Core::ERROR_NONE);
    ASSERT_NE(iter, nullptr);
    EXPECT_EQ(iter->Count(), 200u);
    iter->Release();
}

TEST_F(TestIterators, GetLargeValueIterator) {
    RPC::IValueIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetLargeValueIterator(500, iter), Core::ERROR_NONE);
    ASSERT_NE(iter, nullptr);
    EXPECT_EQ(iter->Count(), 500u);
    iter->Release();
}

// ===== Store-and-Query: validates iterator contents server-side =====

TEST_F(TestIterators, RegisterStringIterator_CountCorrect) {
    RPC::IStringIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetStrings(10, iter), Core::ERROR_NONE);

    uint32_t id = 0;
    ASSERT_EQ(_proxy->RegisterStringIterator(iter, id), Core::ERROR_NONE);
    EXPECT_NE(id, 0u);
    iter->Release();

    // Wait for async drain
    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    uint32_t count = 0;
    ASSERT_EQ(_proxy->GetStringIteratorCount(id, count), Core::ERROR_NONE);
    EXPECT_EQ(count, 10u);

    _proxy->UnregisterIterator(id);
}

TEST_F(TestIterators, RegisterStringIterator_FirstElement) {
    RPC::IStringIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetStrings(5, iter), Core::ERROR_NONE);

    uint32_t id = 0;
    ASSERT_EQ(_proxy->RegisterStringIterator(iter, id), Core::ERROR_NONE);
    iter->Release();

    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    string first;
    ASSERT_EQ(_proxy->GetStringIteratorFirst(id, first), Core::ERROR_NONE);
    EXPECT_EQ(first, "item_0");

    _proxy->UnregisterIterator(id);
}

TEST_F(TestIterators, RegisterStringIterator_Empty) {
    RPC::IStringIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetEmptyStringIterator(iter), Core::ERROR_NONE);

    uint32_t id = 0;
    ASSERT_EQ(_proxy->RegisterStringIterator(iter, id), Core::ERROR_NONE);
    iter->Release();

    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    bool empty = false;
    ASSERT_EQ(_proxy->IsStringIteratorEmpty(id, empty), Core::ERROR_NONE);
    EXPECT_TRUE(empty);

    _proxy->UnregisterIterator(id);
}

TEST_F(TestIterators, RegisterValueIterator_SumAndCount) {
    RPC::IValueIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetValues(5, iter), Core::ERROR_NONE);  // values: 0,1,2,3,4

    uint32_t id = 0;
    ASSERT_EQ(_proxy->RegisterValueIterator(iter, id), Core::ERROR_NONE);
    iter->Release();

    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    uint32_t count = 0, sum = 0;
    ASSERT_EQ(_proxy->GetValueIteratorCount(id, count), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->GetValueIteratorSum(id, sum), Core::ERROR_NONE);
    EXPECT_EQ(count, 5u);
    EXPECT_EQ(sum, 10u);  // 0+1+2+3+4

    _proxy->UnregisterIterator(id);
}

TEST_F(TestIterators, RegisterValueIterator_FirstElement) {
    RPC::IValueIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetValues(3, iter), Core::ERROR_NONE);

    uint32_t id = 0;
    ASSERT_EQ(_proxy->RegisterValueIterator(iter, id), Core::ERROR_NONE);
    iter->Release();

    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    uint32_t first = 99;
    ASSERT_EQ(_proxy->GetValueIteratorFirst(id, first), Core::ERROR_NONE);
    EXPECT_EQ(first, 0u);

    _proxy->UnregisterIterator(id);
}

TEST_F(TestIterators, UnregisterIterator_ReturnsNotExist) {
    RPC::IStringIterator* iter = nullptr;
    ASSERT_EQ(_proxy->GetStrings(3, iter), Core::ERROR_NONE);

    uint32_t id = 0;
    ASSERT_EQ(_proxy->RegisterStringIterator(iter, id), Core::ERROR_NONE);
    iter->Release();

    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    ASSERT_EQ(_proxy->UnregisterIterator(id), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->UnregisterIterator(id), Core::ERROR_NOT_EXIST);
}

TEST_F(TestIterators, MultipleIterators_IndependentIds) {
    RPC::IStringIterator* si = nullptr;
    RPC::IValueIterator*  vi = nullptr;
    ASSERT_EQ(_proxy->GetStrings(3, si), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->GetValues(4,  vi), Core::ERROR_NONE);

    uint32_t sid = 0, vid = 0;
    ASSERT_EQ(_proxy->RegisterStringIterator(si, sid), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->RegisterValueIterator(vi,  vid), Core::ERROR_NONE);
    si->Release(); vi->Release();

    EXPECT_NE(sid, vid);

    std::this_thread::sleep_for(std::chrono::milliseconds(150));

    uint32_t scount = 0, vcount = 0;
    ASSERT_EQ(_proxy->GetStringIteratorCount(sid, scount), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->GetValueIteratorCount(vid,  vcount), Core::ERROR_NONE);
    EXPECT_EQ(scount, 3u);
    EXPECT_EQ(vcount, 4u);

    _proxy->UnregisterIterator(sid);
    _proxy->UnregisterIterator(vid);
}
