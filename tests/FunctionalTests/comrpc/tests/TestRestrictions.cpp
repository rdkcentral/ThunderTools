/*
 * Copyright 2026 Metrological - Apache 2.0
 *
 * NOTE: The generator emits ASSERT()s for @restrict ranges in the stub.
 * Out-of-range values will fire the ASSERT before reaching the implementation,
 * so tests that validate rejection of out-of-range values exercise the
 * generator's validation code path, not the implementation.
 *
 * In-range tests prove that marshalling itself doesn't corrupt values.
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestRestrictions.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestRestrictions : public Testing::TestHarness<ITestRestrictions> {};

// ===== Unsigned integers =====

TEST_F(TestRestrictions, SetFixedValue_Correct) {
    EXPECT_EQ(_proxy->SetFixedValue(42), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetFixedValue_Wrong) {
    EXPECT_NE(_proxy->SetFixedValue(41), Core::ERROR_NONE);
    EXPECT_NE(_proxy->SetFixedValue(43), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetPercentage_Boundaries) {
    EXPECT_EQ(_proxy->SetPercentage(0),   Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetPercentage(50),  Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetPercentage(100), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetByte_RoundTrip) {
    uint8_t result = 0;
    ASSERT_EQ(_proxy->SetByte(123, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 123u);
    ASSERT_EQ(_proxy->SetByte(0,   result), Core::ERROR_NONE);
    EXPECT_EQ(result, 0u);
    ASSERT_EQ(_proxy->SetByte(255, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 255u);
}

// ===== Signed integers =====

TEST_F(TestRestrictions, SetTemperature_ValidRange) {
    EXPECT_EQ(_proxy->SetTemperature(-40), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetTemperature(  0), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetTemperature(125), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetNegative_ValidRange) {
    EXPECT_EQ(_proxy->SetNegative(-1),    Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetNegative(-500),  Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetNegative(-1000), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetNegative_ZeroRejected) {
    EXPECT_NE(_proxy->SetNegative(0), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetPositiveSigned_ValidRange) {
    EXPECT_EQ(_proxy->SetPositiveSigned(1),    Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetPositiveSigned(500),  Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetPositiveSigned(1000), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetOffset_ValidRange) {
    EXPECT_EQ(_proxy->SetOffset(-127), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetOffset(   0), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetOffset( 127), Core::ERROR_NONE);
}

// ===== Floating point =====

TEST_F(TestRestrictions, SetRatio_Boundaries) {
    EXPECT_EQ(_proxy->SetRatio(0.0f), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetRatio(0.5f), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetRatio(1.0f), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetRatio_OutOfRange) {
    EXPECT_NE(_proxy->SetRatio(-0.1f), Core::ERROR_NONE);
    EXPECT_NE(_proxy->SetRatio( 1.1f), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetVoltage_ValidRange) {
    EXPECT_EQ(_proxy->SetVoltage(  0.0), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetVoltage(120.0), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetVoltage(240.0), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetDecibels_ValidRange) {
    EXPECT_EQ(_proxy->SetDecibels(-100.0f), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetDecibels( -20.0f), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetDecibels(   0.0f), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetFrequency_ValidRange) {
    EXPECT_EQ(_proxy->SetFrequency(   20.0), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetFrequency( 1000.0), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetFrequency(20000.0), Core::ERROR_NONE);
}

// ===== Strings =====

TEST_F(TestRestrictions, SetName_Valid) {
    EXPECT_EQ(_proxy->SetName("Alice"),       Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetName(string(64,'X')), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetName_EmptyRejected) {
    EXPECT_NE(_proxy->SetName(""), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetName_TooLongRejected) {
    EXPECT_NE(_proxy->SetName(string(65,'X')), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetUsername_NonEmpty) {
    EXPECT_EQ(_proxy->SetUsername("user"), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetUsername_EmptyRejected) {
    EXPECT_NE(_proxy->SetUsername(""), Core::ERROR_NONE);
}

// ===== Multi-param =====

TEST_F(TestRestrictions, ClampedAdd_ValidInputs) {
    int16_t result = 0;
    ASSERT_EQ(_proxy->ClampedAdd(50, 50, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 100);
    ASSERT_EQ(_proxy->ClampedAdd(-100, 100, result), Core::ERROR_NONE);
    EXPECT_EQ(result, 0);
}

TEST_F(TestRestrictions, Configure_ValidInputs) {
    EXPECT_EQ(_proxy->Configure(0, 100,   0.0f), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->Configure(3, 30000, 10.0f), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->Configure(1, 5000,  2.5f), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, Configure_InvalidMode) {
    EXPECT_NE(_proxy->Configure(4, 5000, 1.0f), Core::ERROR_NONE);
}

// ===== Reference params =====

TEST_F(TestRestrictions, GetRange) {
    uint8_t min = 99, max = 0;
    ASSERT_EQ(_proxy->GetRange(min, max), Core::ERROR_NONE);
    EXPECT_EQ(min, 0u); EXPECT_EQ(max, 100u);
}

TEST_F(TestRestrictions, ClampValue_UpperClamp) {
    int16_t val = 2000;
    ASSERT_EQ(_proxy->ClampValue(val), Core::ERROR_NONE);
    EXPECT_EQ(val, 1000);
}

TEST_F(TestRestrictions, ClampValue_LowerClamp) {
    int16_t val = -5000;
    ASSERT_EQ(_proxy->ClampValue(val), Core::ERROR_NONE);
    EXPECT_EQ(val, -1000);
}

TEST_F(TestRestrictions, ClampValue_InRange) {
    int16_t val = 500;
    ASSERT_EQ(_proxy->ClampValue(val), Core::ERROR_NONE);
    EXPECT_EQ(val, 500);
}

// ===== Output params =====

TEST_F(TestRestrictions, GetPercentage_InRange) {
    uint8_t val = 0;
    ASSERT_EQ(_proxy->GetPercentage(val), Core::ERROR_NONE);
    EXPECT_LE(val, 100u);
}

TEST_F(TestRestrictions, GetRatio_InRange) {
    float val = 0.0f;
    ASSERT_EQ(_proxy->GetRatio(val), Core::ERROR_NONE);
    EXPECT_GE(val, 0.0f);
    EXPECT_LE(val, 1.0f);
}

// ===== Edge cases =====

TEST_F(TestRestrictions, SetPageSize_Correct) {
    EXPECT_EQ(_proxy->SetPageSize(4096), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetPageSize_Wrong) {
    EXPECT_NE(_proxy->SetPageSize(4095), Core::ERROR_NONE);
    EXPECT_NE(_proxy->SetPageSize(4097), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetPort_ValidOptional) {
    EXPECT_EQ(_proxy->SetPort(Core::OptionalType<uint16_t>(8080)), Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetPort(Core::OptionalType<uint16_t>(1)),    Core::ERROR_NONE);
    EXPECT_EQ(_proxy->SetPort(Core::OptionalType<uint16_t>(65535)), Core::ERROR_NONE);
}

TEST_F(TestRestrictions, SetPort_Unset_NoChange) {
    EXPECT_EQ(_proxy->SetPort(Core::OptionalType<uint16_t>()), Core::ERROR_NONE);
}

// ===== Validation helpers =====

TEST_F(TestRestrictions, IsValidPercentage) {
    bool v = false;
    ASSERT_EQ(_proxy->IsValidPercentage(0,   v), Core::ERROR_NONE); EXPECT_TRUE(v);
    ASSERT_EQ(_proxy->IsValidPercentage(100, v), Core::ERROR_NONE); EXPECT_TRUE(v);
    ASSERT_EQ(_proxy->IsValidPercentage(101, v), Core::ERROR_NONE); EXPECT_FALSE(v);
}

TEST_F(TestRestrictions, IsValidTemperature) {
    bool v = false;
    ASSERT_EQ(_proxy->IsValidTemperature(-40,  v), Core::ERROR_NONE); EXPECT_TRUE(v);
    ASSERT_EQ(_proxy->IsValidTemperature(125,  v), Core::ERROR_NONE); EXPECT_TRUE(v);
    ASSERT_EQ(_proxy->IsValidTemperature(-41,  v), Core::ERROR_NONE); EXPECT_FALSE(v);
    ASSERT_EQ(_proxy->IsValidTemperature(126,  v), Core::ERROR_NONE); EXPECT_FALSE(v);
}

TEST_F(TestRestrictions, IsValidRatio) {
    bool v = false;
    ASSERT_EQ(_proxy->IsValidRatio(0.0f, v), Core::ERROR_NONE); EXPECT_TRUE(v);
    ASSERT_EQ(_proxy->IsValidRatio(1.0f, v), Core::ERROR_NONE); EXPECT_TRUE(v);
    ASSERT_EQ(_proxy->IsValidRatio(1.1f, v), Core::ERROR_NONE); EXPECT_FALSE(v);
}

TEST_F(TestRestrictions, GetPercentageRange) {
    uint8_t min = 99, max = 0;
    ASSERT_EQ(_proxy->GetPercentageRange(min, max), Core::ERROR_NONE);
    EXPECT_EQ(min, 0u); EXPECT_EQ(max, 100u);
}

TEST_F(TestRestrictions, GetTemperatureRange) {
    int32_t min = 99, max = 0;
    ASSERT_EQ(_proxy->GetTemperatureRange(min, max), Core::ERROR_NONE);
    EXPECT_EQ(min, -40); EXPECT_EQ(max, 125);
}
