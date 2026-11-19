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
#include <ITestLengthModes.h>

using namespace Thunder;
using namespace Thunder::FunctionalTest;

class TestLengthModes : public Testing::TestHarness<ITestLengthModes> {};

TEST_F(TestLengthModes, EchoSingleByte) {
    const uint8_t input = 0x5A;
    uint8_t output[1] = { 0 };

    ASSERT_EQ(_proxy->EchoSingleByte(input, output), Core::ERROR_NONE);
    EXPECT_EQ(output[0], input);
}

TEST_F(TestLengthModes, ReadPayloadHonorsCapacity) {
    uint8_t output[16] = { 0 };

    const uint16_t written = _proxy->ReadPayload(output, static_cast<uint16_t>(sizeof(output)));
    EXPECT_LE(written, static_cast<uint16_t>(sizeof(output)));
    // impl writes a fixed 4-byte pattern {0xDE, 0xAD, 0xBE, 0xEF}; verify bytes were actually written
    EXPECT_GT(written, 0u);
    EXPECT_EQ(output[0], 0xDE);
    EXPECT_EQ(output[1], 0xAD);
    EXPECT_EQ(output[2], 0xBE);
    EXPECT_EQ(output[3], 0xEF);
}
