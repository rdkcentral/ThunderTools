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

// Tests the following annotation tags via ITestAsync in JSON-RPC mode:
//
//   @async   — Calculate() maps to a non-blocking JSON-RPC call that returns a
//              slot index synchronously; completion is delivered via a JSON-RPC
//              event.  The ICallback* parameter is replaced by event machinery;
//              callers poll SlotResult or subscribe to the completion event.
//
//   @default — delayMs carries @default:100; omitting it from the request body
//              should succeed (the generator substitutes the default value).
//
//   @index   — SlotResult is an @index @property; each slot is independently
//              addressable as slotResult@<N>.

#include <gtest/gtest.h>
#include "JsonRpcTestHarness.h"
#include <ITestAsync.h>
#include <chrono>
#include <thread>

using namespace Thunder;

class TestAsyncJsonRpc : public JsonRpcTesting::JsonRpcTestHarness {};

// Helper: parse the slot number from a calculate response that contains "slot":<N>.
// Returns 255 and marks the test failed if the field is not found.
static uint8_t ParseSlot(const string& response)
{
    auto pos = response.find("\"slot\":");
    if (pos == string::npos) {
        ADD_FAILURE() << "No \"slot\" field in calculate response: " << response;
        return 255;
    }
    return static_cast<uint8_t>(std::stoi(response.substr(pos + 7)));
}

// @async — calculate() returns a slot index synchronously in the JSON-RPC response;
// the ICallback is replaced by the framework's event-delivery mechanism.
TEST_F(TestAsyncJsonRpc, Calculate_ReturnsSlot)
{
    string response;
    ASSERT_EQ(Core::ERROR_NONE,
        CallMethod("calculate", R"({"value":21,"delayMs":50})", response));
    uint8_t slot = ParseSlot(response);
    ASSERT_LE(slot, 6u) << "Slot must be in range [0..6]: " << response;

    // Abort the running calculation so the slot does not leak into other tests.
    CallMethod("abort", R"({"slot":)" + std::to_string(slot) + "}", response);
}

// @default — omitting delayMs should apply the @default:100 annotation value
// and the call must still succeed.
TEST_F(TestAsyncJsonRpc, Calculate_DefaultDelay)
{
    string response;
    ASSERT_EQ(Core::ERROR_NONE,
        CallMethod("calculate", R"({"value":10})", response));
    uint8_t slot = ParseSlot(response);
    ASSERT_LE(slot, 6u) << "Slot must be in range [0..6]: " << response;

    // Wait for the default-delay (100 ms) calculation to complete, then consume
    // the result so the slot is freed before the next test.
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    CallMethod("slotResult@" + std::to_string(slot), "{}", response);
}

// @async state — inProgress must report true while the calculation is still running.
TEST_F(TestAsyncJsonRpc, InProgress_WhileRunning)
{
    string response;
    ASSERT_EQ(Core::ERROR_NONE,
        CallMethod("calculate", R"({"value":1,"delayMs":500})", response));
    uint8_t slot = ParseSlot(response);
    ASSERT_LE(slot, 6u);

    string ipResponse;
    ASSERT_EQ(Core::ERROR_NONE,
        CallMethod("inProgress", R"({"slot":)" + std::to_string(slot) + "}", ipResponse));
    EXPECT_NE(ipResponse.find("true"), string::npos) << "Response: " << ipResponse;

    // Abort so the slow calculation does not run for the full 500 ms.
    CallMethod("abort", R"({"slot":)" + std::to_string(slot) + "}", response);
}

// @index — SlotResult is an @index @property; after the calculation completes
// the result is read via the indexed accessor slotResult@<N>.
TEST_F(TestAsyncJsonRpc, SlotResult_IndexProperty)
{
    string response;
    ASSERT_EQ(Core::ERROR_NONE,
        CallMethod("calculate", R"({"value":21,"delayMs":50})", response));
    uint8_t slot = ParseSlot(response);
    ASSERT_LE(slot, 6u);

    // Wait for the 50 ms calculation to finish.
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    // Read the result via the @index property: slotResult@<N>
    string resultResponse;
    ASSERT_EQ(Core::ERROR_NONE,
        CallMethod("slotResult@" + std::to_string(slot), "{}", resultResponse));
    // impl computes value * 2, so 21 * 2 = 42
    EXPECT_NE(resultResponse.find("42"), string::npos) << "Response: " << resultResponse;
}
