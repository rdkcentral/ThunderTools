/*
 * Copyright 2026 Metrological - Apache 2.0
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestStructs.h>
#include <cmath>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestStructs : public Testing::TestHarness<ITestStructs> {};

// ===== Point store/retrieve =====

TEST_F(TestStructs, SetGetPoint_RoundTrip) {
    ITestStructs::Point p = {42, -7};
    ASSERT_EQ(_proxy->SetPoint(p), Core::ERROR_NONE);
    ITestStructs::Point got{};
    ASSERT_EQ(_proxy->GetPoint(got), Core::ERROR_NONE);
    EXPECT_EQ(got.x, 42); EXPECT_EQ(got.y, -7);
}

TEST_F(TestStructs, GetPoint_BeforeSet_ReturnsError) {
    ITestStructs::Point got{};
    // Fresh proxy instance — nothing stored yet
    // NOTE: depends on server creating a fresh impl per connection
    // If shared, this may vary; mark as informational
    EXPECT_NE(_proxy->GetPoint(got), Core::ERROR_NONE);
}

TEST_F(TestStructs, SetGetRectangle_RoundTrip) {
    ITestStructs::Rectangle r = {{10, 20}, {100, 200}};
    ASSERT_EQ(_proxy->SetRectangle(r), Core::ERROR_NONE);
    ITestStructs::Rectangle got{};
    ASSERT_EQ(_proxy->GetRectangle(got), Core::ERROR_NONE);
    EXPECT_EQ(got.topLeft.x,     10);
    EXPECT_EQ(got.topLeft.y,     20);
    EXPECT_EQ(got.bottomRight.x, 100);
    EXPECT_EQ(got.bottomRight.y, 200);
}

TEST_F(TestStructs, SetGetColor_RoundTrip) {
    ITestStructs::Color c = {255, 128, 64, 200};
    ASSERT_EQ(_proxy->SetColor(c), Core::ERROR_NONE);
    ITestStructs::Color got{};
    ASSERT_EQ(_proxy->GetColor(got), Core::ERROR_NONE);
    EXPECT_EQ(got.red, 255); EXPECT_EQ(got.green, 128);
    EXPECT_EQ(got.blue, 64); EXPECT_EQ(got.alpha, 200);
}

// ===== Inout =====

TEST_F(TestStructs, MovePoint) {
    ITestStructs::Point p = {10, 20};
    ASSERT_EQ(_proxy->MovePoint(p, 5, -3), Core::ERROR_NONE);
    EXPECT_EQ(p.x, 15); EXPECT_EQ(p.y, 17);
}

TEST_F(TestStructs, ScaleRectangle_Double) {
    ITestStructs::Rectangle r = {{0, 0}, {10, 20}};
    ASSERT_EQ(_proxy->ScaleRectangle(r, 2.0), Core::ERROR_NONE);
    EXPECT_EQ(r.bottomRight.x, 20);
    EXPECT_EQ(r.bottomRight.y, 40);
}

TEST_F(TestStructs, AdjustColor_ClampUpper) {
    ITestStructs::Color c = {200, 200, 200, 255};
    ASSERT_EQ(_proxy->AdjustColor(c, 100), Core::ERROR_NONE);
    EXPECT_EQ(c.red, 255); EXPECT_EQ(c.green, 255); EXPECT_EQ(c.blue, 255);
}

TEST_F(TestStructs, AdjustColor_ClampLower) {
    ITestStructs::Color c = {50, 50, 50, 255};
    ASSERT_EQ(_proxy->AdjustColor(c, -100), Core::ERROR_NONE);
    EXPECT_EQ(c.red, 0); EXPECT_EQ(c.green, 0); EXPECT_EQ(c.blue, 0);
}

// ===== Computations =====

TEST_F(TestStructs, DistanceBetweenPoints_Pythagorean) {
    double d = 0.0;
    ASSERT_EQ(_proxy->DistanceBetweenPoints({0,0}, {3,4}, d), Core::ERROR_NONE);
    EXPECT_DOUBLE_EQ(d, 5.0);
}

TEST_F(TestStructs, RectanglesOverlap_Yes) {
    bool overlap = false;
    ASSERT_EQ(_proxy->RectanglesOverlap({{0,0},{100,100}}, {{50,50},{150,150}}, overlap), Core::ERROR_NONE);
    EXPECT_TRUE(overlap);
}

TEST_F(TestStructs, RectanglesOverlap_No) {
    bool overlap = true;
    ASSERT_EQ(_proxy->RectanglesOverlap({{0,0},{10,10}}, {{20,20},{30,30}}, overlap), Core::ERROR_NONE);
    EXPECT_FALSE(overlap);
}

TEST_F(TestStructs, BlendColors_Midpoint) {
    ITestStructs::Color r{};
    ASSERT_EQ(_proxy->BlendColors({0,0,0,255}, {254,254,254,255}, 0.5, r), Core::ERROR_NONE);
    EXPECT_NEAR(r.red,   127, 2);
    EXPECT_NEAR(r.green, 127, 2);
    EXPECT_NEAR(r.blue,  127, 2);
}

TEST_F(TestStructs, CalculateRectangleArea) {
    uint32_t area = 0;
    ASSERT_EQ(_proxy->CalculateRectangleArea({{0,0},{10,20}}, area), Core::ERROR_NONE);
    EXPECT_EQ(area, 200u);
}

TEST_F(TestStructs, GetRectangleCenter) {
    ITestStructs::Point center{};
    ASSERT_EQ(_proxy->GetRectangleCenter({{0,0},{100,200}}, center), Core::ERROR_NONE);
    EXPECT_EQ(center.x, 50); EXPECT_EQ(center.y, 100);
}

TEST_F(TestStructs, CalculateStatistics_Multiple) {
    ITestStructs::Statistics stats{};
    ASSERT_EQ(_proxy->CalculateStatistics({10, 20, 30, 40, 50}, stats), Core::ERROR_NONE);
    EXPECT_EQ(stats.count, 5u);
    EXPECT_EQ(stats.total, 150ull);
    EXPECT_DOUBLE_EQ(stats.average, 30.0);
    EXPECT_DOUBLE_EQ(stats.min, 10.0);
    EXPECT_DOUBLE_EQ(stats.max, 50.0);
}

// ===== Vectors =====

TEST_F(TestStructs, GetPoints_Correct) {
    std::vector<ITestStructs::Point> pts;
    ASSERT_EQ(_proxy->GetPoints(3, pts), Core::ERROR_NONE);
    ASSERT_EQ(pts.size(), 3u);
    EXPECT_EQ(pts[0].x, 0); EXPECT_EQ(pts[1].x, 10); EXPECT_EQ(pts[2].x, 20);
}

TEST_F(TestStructs, SetPoints_FirstStored) {
    std::vector<ITestStructs::Point> pts = {{99, 88}, {1, 2}};
    ASSERT_EQ(_proxy->SetPoints(pts), Core::ERROR_NONE);
    ITestStructs::Point got{};
    ASSERT_EQ(_proxy->GetPoint(got), Core::ERROR_NONE);
    EXPECT_EQ(got.x, 99); EXPECT_EQ(got.y, 88);
}

TEST_F(TestStructs, SetGetPalette_RoundTrip) {
    std::vector<ITestStructs::Color> pal = {{255,0,0,255}, {0,255,0,255}};
    ASSERT_EQ(_proxy->SetPalette(pal), Core::ERROR_NONE);
    std::vector<ITestStructs::Color> got;
    ASSERT_EQ(_proxy->GetPalette(got), Core::ERROR_NONE);
    ASSERT_EQ(got.size(), 2u);
    EXPECT_EQ(got[0].red, 255);
    EXPECT_EQ(got[1].green, 255);
}

// ===== Config property =====

TEST_F(TestStructs, Config_RoundTrip) {
    ASSERT_EQ(_proxy->SetConfig(string("{\"key\":\"value\"}")), Core::ERROR_NONE);
    string got;
    ASSERT_EQ(_proxy->GetConfig(got), Core::ERROR_NONE);
    EXPECT_EQ(got, "{\"key\":\"value\"}");
}

// ===== SlotPoint indexed property =====

TEST_F(TestStructs, SlotPoint_SetGet) {
    const ITestStructs::Point in = {33, 44};
    ASSERT_EQ(_proxy->SetSlotPoint(uint8_t(0), in), Core::ERROR_NONE);
    ITestStructs::Point out{};
    ASSERT_EQ(_proxy->GetSlotPoint(uint8_t(0), out), Core::ERROR_NONE);
    EXPECT_EQ(out.x, 33); EXPECT_EQ(out.y, 44);
}

TEST_F(TestStructs, SlotPoint_UnknownSlot) {
    ITestStructs::Point out{};
    EXPECT_EQ(_proxy->GetSlotPoint(uint8_t(200), out), Core::ERROR_NOT_EXIST);
}

// ===== Edge cases =====

TEST_F(TestStructs, EchoPoint) {
    ITestStructs::Point result{};
    ASSERT_EQ(_proxy->EchoPoint({-100, 200}, result), Core::ERROR_NONE);
    EXPECT_EQ(result.x, -100); EXPECT_EQ(result.y, 200);
}

TEST_F(TestStructs, IsValidRectangle_Valid) {
    bool valid = false;
    ASSERT_EQ(_proxy->IsValidRectangle({{0,0},{10,10}}, valid), Core::ERROR_NONE);
    EXPECT_TRUE(valid);
}

TEST_F(TestStructs, IsValidRectangle_Inverted) {
    bool valid = true;
    ASSERT_EQ(_proxy->IsValidRectangle({{100,100},{0,0}}, valid), Core::ERROR_NONE);
    EXPECT_FALSE(valid);
}
