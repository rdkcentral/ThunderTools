/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestOptionals.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestOptionals : public Testing::TestHarness<ITestOptionals> {};

// ===== Optional input =====

TEST_F(TestOptionals, Add_BothSet) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->Add(10, Core::OptionalType<uint32_t>(5), result), Core::ERROR_NONE);
    EXPECT_EQ(result, 15u);
}

TEST_F(TestOptionals, Add_BIsUnset_DefaultsToZero) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->Add(10, Core::OptionalType<uint32_t>(), result), Core::ERROR_NONE);
    EXPECT_EQ(result, 10u);
}

TEST_F(TestOptionals, Multiply_BothSet) {
    int32_t result = 0;
    ASSERT_EQ(_proxy->Multiply(7, Core::OptionalType<int32_t>(3), result), Core::ERROR_NONE);
    EXPECT_EQ(result, 21);
}

TEST_F(TestOptionals, Multiply_MultiplierUnset_ReturnsValue) {
    int32_t result = 0;
    ASSERT_EQ(_proxy->Multiply(7, Core::OptionalType<int32_t>(), result), Core::ERROR_NONE);
    EXPECT_EQ(result, 7);
}

TEST_F(TestOptionals, Concatenate_BothSet) {
    string result;
    ASSERT_EQ(_proxy->Concatenate("Hello", Core::OptionalType<string>(" World"), result), Core::ERROR_NONE);
    EXPECT_EQ(result, "Hello World");
}

TEST_F(TestOptionals, Concatenate_SecondUnset) {
    string result;
    ASSERT_EQ(_proxy->Concatenate("Hello", Core::OptionalType<string>(), result), Core::ERROR_NONE);
    EXPECT_EQ(result, "Hello");
}

// ===== Optional output =====

// TODO: Generator bug - @out OptionalType<T> parameters do not forward the caller's
// IsSet() state to the stub, so the "caller hints via IsSet" pattern is broken.
// The proxy never sends the initial IsSet() to the stub, causing the implementation
// to always see an unset optional and skip writing the value back.
// Needs fix in StubGenerator.py before re-enabling.

TEST_F(TestOptionals, DISABLED_Divide_WithRemainder) {
    uint32_t quotient = 0;
    Core::OptionalType<uint32_t> remainder(0u); // IsSet = true → server fills it
    ASSERT_EQ(_proxy->Divide(17, 5, quotient, remainder), Core::ERROR_NONE);
    EXPECT_EQ(quotient, 3u);
    ASSERT_TRUE(remainder.IsSet());
    EXPECT_EQ(remainder.Value(), 2u);
}

TEST_F(TestOptionals, Divide_WithoutRemainder) {
    uint32_t quotient = 0;
    Core::OptionalType<uint32_t> remainder; // IsSet = false → server skips it
    ASSERT_EQ(_proxy->Divide(17, 5, quotient, remainder), Core::ERROR_NONE);
    EXPECT_EQ(quotient, 3u);
    EXPECT_FALSE(remainder.IsSet());
}

TEST_F(TestOptionals, Divide_ByZero) {
    uint32_t quotient = 0;
    Core::OptionalType<uint32_t> remainder;
    EXPECT_EQ(_proxy->Divide(10, 0, quotient, remainder), Core::ERROR_BAD_REQUEST);
}

TEST_F(TestOptionals, DISABLED_ParseInt_ValidNumber) {
    int32_t value = 0;
    Core::OptionalType<bool> success(false);
    ASSERT_EQ(_proxy->ParseInt("42", value, success), Core::ERROR_NONE);
    EXPECT_EQ(value, 42);
    ASSERT_TRUE(success.IsSet());
    EXPECT_TRUE(success.Value());
}

TEST_F(TestOptionals, DISABLED_ParseInt_NegativeNumber) {
    int32_t value = 0;
    Core::OptionalType<bool> success(false);
    ASSERT_EQ(_proxy->ParseInt("-100", value, success), Core::ERROR_NONE);
    EXPECT_EQ(value, -100);
    EXPECT_TRUE(success.Value());
}

TEST_F(TestOptionals, DISABLED_ParseInt_InvalidString) {
    int32_t value = 0;
    Core::OptionalType<bool> success(true);
    ASSERT_EQ(_proxy->ParseInt("not_a_number", value, success), Core::ERROR_NONE);
    ASSERT_TRUE(success.IsSet());
    EXPECT_FALSE(success.Value());
}

TEST_F(TestOptionals, ParseInt_SuccessUnset) {
    int32_t value = 0;
    Core::OptionalType<bool> success; // don't care about success flag
    ASSERT_EQ(_proxy->ParseInt("99", value, success), Core::ERROR_NONE);
    EXPECT_EQ(value, 99);
    EXPECT_FALSE(success.IsSet()); // server should not set it when caller didn't ask
}

// ===== Multiple optionals =====

TEST_F(TestOptionals, Format_AllSet) {
    string result;
    ASSERT_EQ(_proxy->Format("world",
        Core::OptionalType<string>("Hello, "),
        Core::OptionalType<string>("!"),
        result), Core::ERROR_NONE);
    EXPECT_EQ(result, "Hello, world!");
}

TEST_F(TestOptionals, Format_NoneSet) {
    string result;
    ASSERT_EQ(_proxy->Format("bare",
        Core::OptionalType<string>(),
        Core::OptionalType<string>(),
        result), Core::ERROR_NONE);
    EXPECT_EQ(result, "bare");
}

TEST_F(TestOptionals, Calculate_BothBounds) {
    int32_t result = 0;
    ASSERT_EQ(_proxy->Calculate(50,
        Core::OptionalType<int32_t>(10),
        Core::OptionalType<int32_t>(100),
        result), Core::ERROR_NONE);
    EXPECT_EQ(result, 50);
}

TEST_F(TestOptionals, Calculate_ClampToMin) {
    int32_t result = 0;
    ASSERT_EQ(_proxy->Calculate(5,
        Core::OptionalType<int32_t>(10),
        Core::OptionalType<int32_t>(100),
        result), Core::ERROR_NONE);
    EXPECT_EQ(result, 10);
}

TEST_F(TestOptionals, Calculate_ClampToMax) {
    int32_t result = 0;
    ASSERT_EQ(_proxy->Calculate(200,
        Core::OptionalType<int32_t>(10),
        Core::OptionalType<int32_t>(100),
        result), Core::ERROR_NONE);
    EXPECT_EQ(result, 100);
}

TEST_F(TestOptionals, Calculate_NoBounds) {
    int32_t result = 0;
    ASSERT_EQ(_proxy->Calculate(-9999,
        Core::OptionalType<int32_t>(),
        Core::OptionalType<int32_t>(),
        result), Core::ERROR_NONE);
    EXPECT_EQ(result, -9999);
}

// ===== Optional buffer =====

TEST_F(TestOptionals, ProcessOptionalBuffer_WithOutput) {
    const uint8_t input[]  = {0x01, 0x02, 0x03};
    uint8_t       output[3] = {};
    uint16_t written = 0;
    ASSERT_EQ(_proxy->ProcessOptionalBuffer(input, 3, output, 3, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 3u);
    EXPECT_EQ(output[0], static_cast<uint8_t>(~0x01));
}

TEST_F(TestOptionals, ProcessOptionalBuffer_NoOutput) {
    const uint8_t input[] = {0xAA, 0xBB};
    uint8_t dummy[1] = {};
    uint16_t written = 99;
    ASSERT_EQ(_proxy->ProcessOptionalBuffer(input, 2, dummy, 0, written), Core::ERROR_NONE);
    EXPECT_EQ(written, 0u);
}

// ===== AllOptional =====

TEST_F(TestOptionals, AllOptional_AllUnset) {
    uint32_t result = 99;
    ASSERT_EQ(_proxy->AllOptional({}, {}, {}, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 0u);
}

TEST_F(TestOptionals, AllOptional_AllSet) {
    uint32_t result = 0;
    ASSERT_EQ(_proxy->AllOptional(
        Core::OptionalType<uint32_t>(1),
        Core::OptionalType<uint32_t>(2),
        Core::OptionalType<uint32_t>(3),
        result), Core::ERROR_NONE);
    EXPECT_EQ(result, 6u);
}

// ===== WithDefault =====

TEST_F(TestOptionals, WithDefault_NoUppercase) {
    string result;
    ASSERT_EQ(_proxy->WithDefault("hello", Core::OptionalType<bool>(), result), Core::ERROR_NONE);
    EXPECT_EQ(result, "hello");
}

TEST_F(TestOptionals, WithDefault_Uppercase) {
    string result;
    ASSERT_EQ(_proxy->WithDefault("hello", Core::OptionalType<bool>(true), result), Core::ERROR_NONE);
    EXPECT_EQ(result, "HELLO");
}

TEST_F(TestOptionals, WithDefault_ExplicitFalse) {
    string result;
    ASSERT_EQ(_proxy->WithDefault("hello", Core::OptionalType<bool>(false), result), Core::ERROR_NONE);
    EXPECT_EQ(result, "hello");
}
