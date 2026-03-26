/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestBuffers.h>
#include <cstring>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestBuffers : public Testing::TestHarness<ITestBuffers> {};

// ===== Fixed-size arrays =====

// FIXME: ProxyStubGenerator: Fixed-size array parameters generate invalid proxy signatures

// TEST_F(TestBuffers, EchoFixed4_RoundTrip) {
//     const uint8_t in[4]  = {0xAA, 0xBB, 0xCC, 0xDD};
//     uint8_t       out[4] = {};
//     ASSERT_EQ(_proxy->EchoFixed4(in, out), Core::ERROR_NONE);
//     EXPECT_EQ(std::memcmp(in, out, 4), 0);
// }

// TEST_F(TestBuffers, EchoFixed4Words_RoundTrip) {
//     const uint32_t in[4]  = {0x11223344, 0xAABBCCDD, 0u, UINT32_MAX};
//     uint32_t       out[4] = {};
//     ASSERT_EQ(_proxy->EchoFixed4Words(in, out), Core::ERROR_NONE);
//     EXPECT_EQ(std::memcmp(in, out, 4 * sizeof(uint32_t)), 0);
// }

// TEST_F(TestBuffers, XorFixed8_InPlace) {
//     uint8_t data[8] = {0x00, 0xFF, 0xAA, 0x55, 0x0F, 0xF0, 0x12, 0x34};
//     const uint8_t expected[8] = {0xFF, 0x00, 0x55, 0xAA, 0xF0, 0x0F, 0xED, 0xCB};
//     ASSERT_EQ(_proxy->XorFixed8(data, 0xFF), Core::ERROR_NONE);
//     EXPECT_EQ(std::memcmp(data, expected, 8), 0);
// }

// TEST_F(TestBuffers, SetGetKey_RoundTrip) {
//     const uint8_t key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
//     uint8_t       got[16] = {};
//     ASSERT_EQ(_proxy->SetKey(key), Core::ERROR_NONE);
//     ASSERT_EQ(_proxy->GetKey(got), Core::ERROR_NONE);
//     EXPECT_EQ(std::memcmp(key, got, 16), 0);
// }

// TEST_F(TestBuffers, SetGetToken_RoundTrip) {
//     const uint8_t token[8] = {0xDE, 0xAD, 0xBE, 0xEF, 0xCA, 0xFE, 0xBA, 0xBE};
//     uint8_t       got[8]   = {};
//     ASSERT_EQ(_proxy->SetToken(token), Core::ERROR_NONE);
//     ASSERT_EQ(_proxy->GetToken(got), Core::ERROR_NONE);
//     EXPECT_EQ(std::memcmp(token, got, 8), 0);
// }

// ===== Input buffers (@length) =====

TEST_F(TestBuffers, SumBytes_Empty) {
    uint8_t dummy[1] = {0};
    uint32_t sum = 99;
    ASSERT_EQ(_proxy->SumBytes(dummy, 0, sum), Core::ERROR_NONE);
    EXPECT_EQ(sum, 0u);
}

TEST_F(TestBuffers, SumBytes_Values) {
    uint8_t buf[] = {1, 2, 3, 4, 5};
    uint32_t sum = 0;
    ASSERT_EQ(_proxy->SumBytes(buf, 5, sum), Core::ERROR_NONE);
    EXPECT_EQ(sum, 15u);
}

TEST_F(TestBuffers, SumBytes_MaxValues) {
    uint8_t buf[4] = {255, 255, 255, 255};
    uint32_t sum = 0;
    ASSERT_EQ(_proxy->SumBytes(buf, 4, sum), Core::ERROR_NONE);
    EXPECT_EQ(sum, 1020u);
}

TEST_F(TestBuffers, Checksum_Deterministic) {
    uint8_t buf[] = {10, 20, 30, 40, 50};
    uint32_t cs1 = 0, cs2 = 0;
    ASSERT_EQ(_proxy->Checksum(buf, 5, cs1), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->Checksum(buf, 5, cs2), Core::ERROR_NONE);
    EXPECT_EQ(cs1, cs2);
}

TEST_F(TestBuffers, Checksum_OrderSensitive) {
    uint8_t buf1[] = {1, 2, 3};
    uint8_t buf2[] = {3, 2, 1};
    uint32_t cs1 = 0, cs2 = 0;
    ASSERT_EQ(_proxy->Checksum(buf1, 3, cs1), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->Checksum(buf2, 3, cs2), Core::ERROR_NONE);
    EXPECT_NE(cs1, cs2);
}

// ===== Output buffers (@maxlength) =====

TEST_F(TestBuffers, FillSequence_FromZero) {
    uint8_t buf[10] = {};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->FillSequence(buf, 10, 0, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 10u);
    for (int i = 0; i < 10; ++i) EXPECT_EQ(buf[i], static_cast<uint8_t>(i));
}

TEST_F(TestBuffers, FillSequence_WithOffset) {
    uint8_t buf[5] = {};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->FillSequence(buf, 5, 100, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 5u);
    EXPECT_EQ(buf[0], 100u);
    EXPECT_EQ(buf[4], 104u);
}

TEST_F(TestBuffers, FillPattern_AllSame) {
    uint8_t buf[64] = {};
    uint32_t written = 0;
    ASSERT_EQ(_proxy->FillPattern(buf, 64, 0xAB, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 64u);
    for (int i = 0; i < 64; ++i) EXPECT_EQ(buf[i], 0xABu);
}

// ===== In/Out buffers =====

TEST_F(TestBuffers, ReverseBuffer_Even) {
    uint8_t buf[] = {1, 2, 3, 4};
    ASSERT_EQ(_proxy->ReverseBuffer(buf, 4), Core::ERROR_NONE);
    EXPECT_EQ(buf[0], 4u); EXPECT_EQ(buf[1], 3u);
    EXPECT_EQ(buf[2], 2u); EXPECT_EQ(buf[3], 1u);
}

TEST_F(TestBuffers, ReverseBuffer_Odd) {
    uint8_t buf[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(_proxy->ReverseBuffer(buf, 5), Core::ERROR_NONE);
    EXPECT_EQ(buf[0], 5u); EXPECT_EQ(buf[2], 3u); EXPECT_EQ(buf[4], 1u);
}

TEST_F(TestBuffers, XorBuffer_DoubleXorRestores) {
    uint8_t buf[]    = {0x11, 0x22, 0x33, 0x44};
    uint8_t original[4];
    std::memcpy(original, buf, 4);
    ASSERT_EQ(_proxy->XorBuffer(buf, 4, 0xAA), Core::ERROR_NONE);
    ASSERT_EQ(_proxy->XorBuffer(buf, 4, 0xAA), Core::ERROR_NONE);
    EXPECT_EQ(std::memcmp(buf, original, 4), 0);
}

// ===== Multi-buffer =====

TEST_F(TestBuffers, MergeBuffers_Interleave) {
    uint8_t in1[] = {1, 2, 3};
    uint8_t in2[] = {4, 5, 6};
    uint8_t out[10] = {};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->MergeBuffers(in1, 3, in2, 3, out, 10, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 6u);
    EXPECT_EQ(out[0], 1u); EXPECT_EQ(out[1], 4u);
    EXPECT_EQ(out[2], 2u); EXPECT_EQ(out[3], 5u);
}

TEST_F(TestBuffers, MergeBuffers_TruncatedByOutput) {
    uint8_t in1[] = {1, 2, 3, 4, 5};
    uint8_t in2[] = {6, 7, 8, 9, 10};
    uint8_t out[4] = {};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->MergeBuffers(in1, 5, in2, 5, out, 4, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 4u);
}

TEST_F(TestBuffers, MergeBuffers_FirstOnly) {
    uint8_t in1[] = {10, 20, 30};
    uint8_t in2[1] = {};
    uint8_t out[10] = {};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->MergeBuffers(in1, 3, in2, 0, out, 10, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 3u);
    EXPECT_EQ(out[0], 10u); EXPECT_EQ(out[1], 20u); EXPECT_EQ(out[2], 30u);
}

// ===== Edge cases =====

TEST_F(TestBuffers, Process_ZeroSize) {
    uint8_t dummy[1] = {};
    uint32_t result = 99;
    ASSERT_EQ(_proxy->Process(dummy, 0, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 0u);
}

TEST_F(TestBuffers, Process_LargeSize) {
    std::vector<uint8_t> buf(4096, 0xFF);
    uint32_t result = 0;
    ASSERT_EQ(_proxy->Process(buf.data(), 4096, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 4096u);
}
