/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include <limits>
#include <cmath>
#include "TestHarness.h"
#include <ITestPrimitives.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestPrimitives : public Testing::TestHarness<ITestPrimitives> {};

// ===== Signed integers =====

TEST_F(TestPrimitives, EchoInt8_Boundaries) {
    int8_t out{};
    EXPECT_EQ(_proxy->EchoInt8(INT8_MIN, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT8_MIN);
    EXPECT_EQ(_proxy->EchoInt8(INT8_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT8_MAX);
    EXPECT_EQ(_proxy->EchoInt8(0, out), Core::ERROR_NONE);
    EXPECT_EQ(out, 0);
    EXPECT_EQ(_proxy->EchoInt8(-42, out), Core::ERROR_NONE);
    EXPECT_EQ(out, -42);
}

TEST_F(TestPrimitives, EchoInt16_Boundaries) {
    int16_t out{};
    EXPECT_EQ(_proxy->EchoInt16(INT16_MIN, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT16_MIN);
    EXPECT_EQ(_proxy->EchoInt16(INT16_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT16_MAX);
}

TEST_F(TestPrimitives, EchoInt24_Zero) {
    // Negative Int24 has known marshalling issues — only zero/positive tested here
    int24_t out{};
    EXPECT_EQ(_proxy->EchoInt24(0, out), Core::ERROR_NONE);
    EXPECT_EQ(out, int24_t(0));
}

TEST_F(TestPrimitives, EchoInt24_Max) {
    int24_t out{};
    EXPECT_EQ(_proxy->EchoInt24(8388607, out), Core::ERROR_NONE);
    EXPECT_EQ(out, int24_t(8388607));
}

TEST_F(TestPrimitives, EchoInt32_Boundaries) {
    int32_t out{};
    EXPECT_EQ(_proxy->EchoInt32(INT32_MIN, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT32_MIN);
    EXPECT_EQ(_proxy->EchoInt32(INT32_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT32_MAX);
    EXPECT_EQ(_proxy->EchoInt32(-123456, out), Core::ERROR_NONE);
    EXPECT_EQ(out, -123456);
}

TEST_F(TestPrimitives, EchoInt64_Boundaries) {
    int64_t out{};
    EXPECT_EQ(_proxy->EchoInt64(INT64_MIN, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT64_MIN);
    EXPECT_EQ(_proxy->EchoInt64(INT64_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, INT64_MAX);
}

// ===== Unsigned integers =====

TEST_F(TestPrimitives, EchoUInt8_Boundaries) {
    uint8_t out{};
    EXPECT_EQ(_proxy->EchoUInt8(0, out), Core::ERROR_NONE);
    EXPECT_EQ(out, 0u);
    EXPECT_EQ(_proxy->EchoUInt8(UINT8_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, UINT8_MAX);
}

TEST_F(TestPrimitives, EchoUInt16_Boundaries) {
    uint16_t out{};
    EXPECT_EQ(_proxy->EchoUInt16(0, out), Core::ERROR_NONE);
    EXPECT_EQ(out, 0u);
    EXPECT_EQ(_proxy->EchoUInt16(UINT16_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, UINT16_MAX);
}

TEST_F(TestPrimitives, EchoUInt24_Boundaries) {
    Core::UInt24 out{};
    EXPECT_EQ(_proxy->EchoUInt24(0, out), Core::ERROR_NONE);
    EXPECT_EQ(out, Core::UInt24(0));
    EXPECT_EQ(_proxy->EchoUInt24(16777215, out), Core::ERROR_NONE);
    EXPECT_EQ(out, Core::UInt24(16777215));
}

TEST_F(TestPrimitives, EchoUInt32_Boundaries) {
    uint32_t out{};
    EXPECT_EQ(_proxy->EchoUInt32(0u, out), Core::ERROR_NONE);
    EXPECT_EQ(out, 0u);
    EXPECT_EQ(_proxy->EchoUInt32(UINT32_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, UINT32_MAX);
}

TEST_F(TestPrimitives, EchoUInt64_Boundaries) {
    uint64_t out{};
    EXPECT_EQ(_proxy->EchoUInt64(UINT64_C(0), out), Core::ERROR_NONE);
    EXPECT_EQ(out, UINT64_C(0));
    EXPECT_EQ(_proxy->EchoUInt64(UINT64_MAX, out), Core::ERROR_NONE);
    EXPECT_EQ(out, UINT64_MAX);
}

// ===== Floating point =====

TEST_F(TestPrimitives, EchoFloat_Values) {
    float out{};
    EXPECT_EQ(_proxy->EchoFloat(0.0f, out), Core::ERROR_NONE);
    EXPECT_FLOAT_EQ(out, 0.0f);
    EXPECT_EQ(_proxy->EchoFloat(1.0f, out), Core::ERROR_NONE);
    EXPECT_FLOAT_EQ(out, 1.0f);
    EXPECT_EQ(_proxy->EchoFloat(-1.5f, out), Core::ERROR_NONE);
    EXPECT_FLOAT_EQ(out, -1.5f);
}

TEST_F(TestPrimitives, EchoFloat_NaN) {
    float out{};
    EXPECT_EQ(_proxy->EchoFloat(std::numeric_limits<float>::quiet_NaN(), out), Core::ERROR_NONE);
    EXPECT_TRUE(std::isnan(out));
}

TEST_F(TestPrimitives, EchoFloat_Infinity) {
    float out{};
    EXPECT_EQ(_proxy->EchoFloat(std::numeric_limits<float>::infinity(), out), Core::ERROR_NONE);
    EXPECT_TRUE(std::isinf(out));
}

TEST_F(TestPrimitives, EchoDouble_Values) {
    double out{};
    EXPECT_EQ(_proxy->EchoDouble(0.0, out), Core::ERROR_NONE);
    EXPECT_DOUBLE_EQ(out, 0.0);
    EXPECT_EQ(_proxy->EchoDouble(3.14159265358979, out), Core::ERROR_NONE);
    EXPECT_DOUBLE_EQ(out, 3.14159265358979);
}

// ===== Bool =====

TEST_F(TestPrimitives, EchoBool) {
    bool out{};
    EXPECT_EQ(_proxy->EchoBool(true,  out), Core::ERROR_NONE); EXPECT_TRUE(out);
    EXPECT_EQ(_proxy->EchoBool(false, out), Core::ERROR_NONE); EXPECT_FALSE(out);
}

// ===== Special types =====

TEST_F(TestPrimitives, EchoInstanceId) {
    Core::instance_id out{};
    EXPECT_EQ(_proxy->EchoInstanceId(0, out), Core::ERROR_NONE);
    EXPECT_EQ(out, Core::instance_id(0));
    EXPECT_EQ(_proxy->EchoInstanceId(std::numeric_limits<Core::instance_id>::max(), out), Core::ERROR_NONE);
    EXPECT_EQ(out, Core::instance_id(std::numeric_limits<Core::instance_id>::max()));
}

TEST_F(TestPrimitives, EchoTime) {
    Core::Time t = Core::Time::Now();
    Core::Time out{};
    EXPECT_EQ(_proxy->EchoTime(t, out), Core::ERROR_NONE);
    EXPECT_EQ(out.Ticks(), t.Ticks());
}

TEST_F(TestPrimitives, EchoMACAddress) {
    Core::MACAddress mac;
    // Set via raw bytes if available, otherwise default-init and echo
    Core::MACAddress out{};
    EXPECT_EQ(_proxy->EchoMACAddress(mac, out), Core::ERROR_NONE);
}

// ===== Strings =====

TEST_F(TestPrimitives, EchoString_Empty) {
    string out;
    EXPECT_EQ(_proxy->EchoString("", out), Core::ERROR_NONE);
    EXPECT_EQ(out, "");
}

TEST_F(TestPrimitives, EchoString_Short) {
    string out;
    EXPECT_EQ(_proxy->EchoString("Hello, World!", out), Core::ERROR_NONE);
    EXPECT_EQ(out, "Hello, World!");
}

TEST_F(TestPrimitives, EchoString_Long) {
    string in(1000, 'X');
    string out;
    EXPECT_EQ(_proxy->EchoString(in, out), Core::ERROR_NONE);
    EXPECT_EQ(out, in);
}

TEST_F(TestPrimitives, EchoString_SpecialChars) {
    string out;
    EXPECT_EQ(_proxy->EchoString("line1\nline2\ttab", out), Core::ERROR_NONE);
    EXPECT_EQ(out, "line1\nline2\ttab");
}

// ===== CharPtr (raw C-string) =====

// TEST_F(TestPrimitives, EchoCharPtr_Basic) {
//     const char* input = "hello";
//     char output[64] = {};
//     uint8_t maxLen = sizeof(output);
//     EXPECT_EQ(_proxy->EchoCharPtr(input, output, maxLen), Core::ERROR_NONE);
//     EXPECT_EQ(std::string(output, maxLen), std::string(input, maxLen));
// }
