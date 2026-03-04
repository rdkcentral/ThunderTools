/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestEnums.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestEnums : public Testing::TestHarness<ITestEnums> {};

// ===== Properties =====

TEST_F(TestEnums, ActiveColor_ReadWrite) {
    ASSERT_EQ(_proxy->ActiveColor(ITestEnums::BLUE), Core::ERROR_NONE);
    ITestEnums::Color color{};
    // static_cast<const ITestEnums*> required to disambiguate getter from setter overload
    ASSERT_EQ(static_cast<const ITestEnums*>(_proxy)->ActiveColor(color), Core::ERROR_NONE);
    EXPECT_EQ(color, ITestEnums::BLUE);
}

TEST_F(TestEnums, CurrentState_ReadOnly) {
    ITestEnums::State state{};
    ASSERT_EQ(_proxy->CurrentState(state), Core::ERROR_NONE);
    // Initial state is IDLE
    EXPECT_EQ(state, ITestEnums::IDLE);
}

TEST_F(TestEnums, RequestedPriority_WriteOnly) {
    EXPECT_EQ(_proxy->RequestedPriority(ITestEnums::HIGH), Core::ERROR_NONE);
}

// ===== Capabilities bitmask =====

TEST_F(TestEnums, Capabilities_RoundTrip) {
    const auto caps = static_cast<ITestEnums::Capabilities>(
        ITestEnums::CAP_AUDIO | ITestEnums::CAP_VIDEO);
    ASSERT_EQ(_proxy->SetCapabilities(caps), Core::ERROR_NONE);
    ITestEnums::Capabilities got{};
    ASSERT_EQ(_proxy->GetCapabilities(got), Core::ERROR_NONE);
    EXPECT_EQ(got, caps);
}

TEST_F(TestEnums, Capabilities_None) {
    ASSERT_EQ(_proxy->SetCapabilities(ITestEnums::CAP_NONE), Core::ERROR_NONE);
    ITestEnums::Capabilities got{};
    ASSERT_EQ(_proxy->GetCapabilities(got), Core::ERROR_NONE);
    EXPECT_EQ(got, ITestEnums::CAP_NONE);
}

// ===== Set/Get round-trips =====

TEST_F(TestEnums, SetGetColor_AllValues) {
    for (auto c : {ITestEnums::RED, ITestEnums::GREEN, ITestEnums::BLUE, ITestEnums::YELLOW}) {
        ASSERT_EQ(_proxy->SetColor(c), Core::ERROR_NONE);
        ITestEnums::Color got{};
        ASSERT_EQ(_proxy->GetColor(got), Core::ERROR_NONE);
        EXPECT_EQ(got, c);
    }
}

TEST_F(TestEnums, SetGetState_AllValues) {
    for (auto s : {ITestEnums::IDLE, ITestEnums::RUNNING, ITestEnums::PAUSED,
                   ITestEnums::STOPPED, ITestEnums::ERROR}) {
        ASSERT_EQ(_proxy->SetState(s), Core::ERROR_NONE);
        ITestEnums::State got{};
        ASSERT_EQ(_proxy->GetState(got), Core::ERROR_NONE);
        EXPECT_EQ(got, s);
    }
}

TEST_F(TestEnums, SetGetPriority) {
    ASSERT_EQ(_proxy->SetPriority(ITestEnums::CRITICAL), Core::ERROR_NONE);
    ITestEnums::Priority got{};
    ASSERT_EQ(_proxy->GetPriority(got), Core::ERROR_NONE);
    EXPECT_EQ(got, ITestEnums::CRITICAL);
}

// ===== Inout =====

TEST_F(TestEnums, ToggleColor_Cycle) {
    ITestEnums::Color c = ITestEnums::RED;
    ASSERT_EQ(_proxy->ToggleColor(c), Core::ERROR_NONE); EXPECT_EQ(c, ITestEnums::GREEN);
    ASSERT_EQ(_proxy->ToggleColor(c), Core::ERROR_NONE); EXPECT_EQ(c, ITestEnums::BLUE);
    ASSERT_EQ(_proxy->ToggleColor(c), Core::ERROR_NONE); EXPECT_EQ(c, ITestEnums::YELLOW);
    ASSERT_EQ(_proxy->ToggleColor(c), Core::ERROR_NONE); EXPECT_EQ(c, ITestEnums::RED);
}

TEST_F(TestEnums, NextState_Cycle) {
    ITestEnums::State s = ITestEnums::IDLE;
    ASSERT_EQ(_proxy->NextState(s), Core::ERROR_NONE); EXPECT_EQ(s, ITestEnums::RUNNING);
    ASSERT_EQ(_proxy->NextState(s), Core::ERROR_NONE); EXPECT_EQ(s, ITestEnums::PAUSED);
}

// ===== Multi-param =====

TEST_F(TestEnums, CompareColors_Equal) {
    bool equal = false;
    ASSERT_EQ(_proxy->CompareColors(ITestEnums::RED, ITestEnums::RED, equal), Core::ERROR_NONE);
    EXPECT_TRUE(equal);
}

TEST_F(TestEnums, CompareColors_NotEqual) {
    bool equal = true;
    ASSERT_EQ(_proxy->CompareColors(ITestEnums::RED, ITestEnums::BLUE, equal), Core::ERROR_NONE);
    EXPECT_FALSE(equal);
}

TEST_F(TestEnums, ComputeState_SameReturnsRunning) {
    ITestEnums::State result{};
    ASSERT_EQ(_proxy->ComputeState(ITestEnums::IDLE, ITestEnums::IDLE, result), Core::ERROR_NONE);
    EXPECT_EQ(result, ITestEnums::RUNNING);
}

TEST_F(TestEnums, ComputeState_DifferentReturnsPaused) {
    ITestEnums::State result{};
    ASSERT_EQ(_proxy->ComputeState(ITestEnums::IDLE, ITestEnums::RUNNING, result), Core::ERROR_NONE);
    EXPECT_EQ(result, ITestEnums::PAUSED);
}

// ===== Optional =====

TEST_F(TestEnums, SetColorWithDefault_Set) {
    ASSERT_EQ(_proxy->SetColorWithDefault(Core::OptionalType<ITestEnums::Color>(ITestEnums::YELLOW)), Core::ERROR_NONE);
    ITestEnums::Color got{};
    ASSERT_EQ(_proxy->GetColor(got), Core::ERROR_NONE);
    EXPECT_EQ(got, ITestEnums::YELLOW);
}

TEST_F(TestEnums, SetColorWithDefault_Unset_UsesRed) {
    ASSERT_EQ(_proxy->SetColorWithDefault(Core::OptionalType<ITestEnums::Color>()), Core::ERROR_NONE);
    ITestEnums::Color got{};
    ASSERT_EQ(_proxy->GetColor(got), Core::ERROR_NONE);
    EXPECT_EQ(got, ITestEnums::RED);
}

TEST_F(TestEnums, AdjustPriority_NoModifier) {
    ITestEnums::Priority result{};
    ASSERT_EQ(_proxy->AdjustPriority(ITestEnums::HIGH, Core::OptionalType<ITestEnums::Priority>(), result), Core::ERROR_NONE);
    EXPECT_EQ(result, ITestEnums::HIGH);
}

// ===== Edge cases =====

TEST_F(TestEnums, EchoColor_AllValues) {
    for (auto c : {ITestEnums::RED, ITestEnums::GREEN, ITestEnums::BLUE, ITestEnums::YELLOW}) {
        ITestEnums::Color result{};
        ASSERT_EQ(_proxy->EchoColor(c, result), Core::ERROR_NONE);
        EXPECT_EQ(result, c);
    }
}

TEST_F(TestEnums, IsValidState_ValidValues) {
    bool valid = false;
    ASSERT_EQ(_proxy->IsValidState(ITestEnums::RUNNING, valid), Core::ERROR_NONE);
    EXPECT_TRUE(valid);
}

TEST_F(TestEnums, IsValidState_InvalidValue) {
    bool valid = true;
    ASSERT_EQ(_proxy->IsValidState(static_cast<ITestEnums::State>(99), valid), Core::ERROR_NONE);
    EXPECT_FALSE(valid);
}

TEST_F(TestEnums, ColorToString_AllValues) {
    string s;
    ASSERT_EQ(_proxy->ColorToString(ITestEnums::RED,    s), Core::ERROR_NONE); EXPECT_EQ(s, "red");
    ASSERT_EQ(_proxy->ColorToString(ITestEnums::GREEN,  s), Core::ERROR_NONE); EXPECT_EQ(s, "green");
    ASSERT_EQ(_proxy->ColorToString(ITestEnums::BLUE,   s), Core::ERROR_NONE); EXPECT_EQ(s, "blue");
    ASSERT_EQ(_proxy->ColorToString(ITestEnums::YELLOW, s), Core::ERROR_NONE); EXPECT_EQ(s, "yellow");
}
