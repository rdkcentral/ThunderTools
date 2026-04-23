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

#pragma once

#include "Module.h"
#include "Ids.h"

namespace Thunder {
namespace FunctionalTest {

    // Test @async pattern: asynchronous JSON-RPC methods whose completion is
    // delivered via a callback interface. On the JSON-RPC side the ICallback*
    // parameter is replaced by a client ID string; the generator creates an
    // ICallback implementation that fires a JSON-RPC event when Complete() is called.
    //
    // Up to 7 calculations may run concurrently, each identified by a slot index
    // (0..6) returned by Calculate. SlotResult uses @index to let callers poll
    // individual slots via the JSON-RPC property API.
    // @json 1.0.0
    struct EXTERNAL ITestAsync : virtual public Core::IUnknown {
        enum { ID = ID_TEST_ASYNC };

        // Result status passed to Complete().
        enum Result : uint8_t {
            SUCCESS  = 0,
            FAILED   = 1,
            TIMEOUT  = 2,
            ABORTED  = 3
        };

        // The generator creates an implementation of ICallback that translates
        // Complete() into a JSON-RPC event directed at the originating client.
        struct ICallback : virtual public Core::IUnknown {
            enum { ID = ID_TEST_ASYNC_CALLBACK };

            // @brief Signals completion of the Calculate operation.
            // @param result Outcome of the operation.
            // @param value  Computed value; only meaningful when result == SUCCESS.
            virtual void Complete(
                const Result result,
                const Core::OptionalType<uint32_t>& value /* @default:0 */) = 0;
        };

        // @async
        //
        // Starts an asynchronous calculation on a free slot. Up to 7 slots
        // (0..6) may be active concurrently; the server picks a free one and
        // returns it in slot. The caller uses the slot to poll SlotResult and
        // to abort via Abort. cb->Complete() is called exactly once when the
        // operation finishes, regardless of outcome.
        //
        // @brief Starts an asynchronous calculation on the next free slot.
        // @param value  Input value to process.
        // @param delayMs Simulated processing delay in milliseconds. @default:100
        // @param slot   Receives the slot index (0..6) assigned to this operation.
        // @param cb     Completion callback; the generator substitutes a client ID on JSON-RPC.
        // @retval ERROR_UNAVAILABLE All 7 slots are currently occupied.
        virtual Core::hresult Calculate(
            const uint32_t value /* @in */,
            const Core::OptionalType<uint16_t>& delayMs /* @in @default:100 */,
            uint8_t& slot /* @out @restrict:0..6 */,
            ICallback* const cb) = 0;

        // @brief Abort the calculation running on the given slot.
        // @param slot Slot index (0..6) to abort.
        // @retval ERROR_ILLEGAL_STATE The slot is not currently running a calculation.
        // @retval ERROR_INVALID_INPUT slot is outside [0..6].
        virtual Core::hresult Abort(const uint8_t slot /* @in @restrict:0..6 */) = 0;

        // @property
        // @brief Computed result for the given slot.
        //        Returns the value produced by Calculate on success.
        //        The entry is consumed on read — the slot is freed automatically.
        //        Poll this after receiving the Complete callback with result == SUCCESS.
        // @param slot   Slot index (0..6); used as the JSON-RPC property index.
        // @param result Receives the computed uint32_t value.
        // @retval ERROR_INPROGRESS  The calculation on this slot has not completed yet.
        // @retval ERROR_NOT_EXIST   The slot was never assigned or has already been consumed.
        virtual Core::hresult SlotResult(const uint8_t slot /* @index @restrict:0..6 */, uint32_t& result /* @out */) const = 0;

        // @brief Returns whether the given slot is currently running a calculation.
        // @param slot       Slot index (0..6) to query.
        // @param inProgress Receives true if the slot has an active calculation.
        // @retval ERROR_INVALID_INPUT slot is outside [0..6].
        virtual Core::hresult InProgress(const uint8_t slot /* @in @restrict:0..6 */, bool& inProgress /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder