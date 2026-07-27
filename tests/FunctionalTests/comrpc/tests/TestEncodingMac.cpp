/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>
#include "TestHarness.h"
#include <ITestEncodingMac.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestEncodingMac : public Testing::TestHarness<ITestEncodingMac> {};

TEST_F(TestEncodingMac, SetGetMacAddress) {
    const uint8_t input[6] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB };
    ASSERT_EQ(_proxy->SetMacAddress(input), Core::ERROR_NONE);

    uint8_t output[6] = { 0 };
    ASSERT_EQ(_proxy->GetMacAddress(output), Core::ERROR_NONE);

    for (uint8_t i = 0; i < 6; ++i) {
        EXPECT_EQ(output[i], input[i]);
    }
}

TEST_F(TestEncodingMac, EchoMacAddress) {
    const uint8_t input[6] = { 0xDE, 0xAD, 0xBE, 0xEF, 0x00, 0x01 };
    uint8_t output[6] = { 0 };

    ASSERT_EQ(_proxy->EchoMacAddress(input, output), Core::ERROR_NONE);

    for (uint8_t i = 0; i < 6; ++i) {
        EXPECT_EQ(output[i], input[i]);
    }
}

// ===========================================================================
// Variable-length @encode:mac — works with any buffer size
// ===========================================================================

TEST_F(TestEncodingMac, VariableMac_8Bytes_RoundTrip) {
    const uint8_t input[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
    ASSERT_EQ(_proxy->SetVariableMac(input, 8), Core::ERROR_NONE);

    uint8_t output[32] = { 0 };
    uint16_t written = 0;
    ASSERT_EQ(_proxy->GetVariableMac(output, 32, written), Core::ERROR_NONE);
    ASSERT_EQ(written, 8u);
    EXPECT_EQ(memcmp(input, output, 8), 0);
}

TEST_F(TestEncodingMac, VariableMac_1Byte_RoundTrip) {
    const uint8_t input[] = { 0xFF };
    ASSERT_EQ(_proxy->SetVariableMac(input, 1), Core::ERROR_NONE);

    uint8_t output[32] = { 0 };
    uint16_t written = 0;
    ASSERT_EQ(_proxy->GetVariableMac(output, 32, written), Core::ERROR_NONE);
    ASSERT_EQ(written, 1u);
    EXPECT_EQ(output[0], 0xFF);
}

TEST_F(TestEncodingMac, VariableMac_16Bytes_RoundTrip) {
    const uint8_t input[16] = { 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7,
                                 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7 };
    ASSERT_EQ(_proxy->SetVariableMac(input, 16), Core::ERROR_NONE);

    uint8_t output[32] = { 0 };
    uint16_t written = 0;
    ASSERT_EQ(_proxy->GetVariableMac(output, 32, written), Core::ERROR_NONE);
    ASSERT_EQ(written, 16u);
    EXPECT_EQ(memcmp(input, output, 16), 0);
}
