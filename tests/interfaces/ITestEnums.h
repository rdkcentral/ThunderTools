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

    // Test enum serialization over COM-RPC
    // @json 1.0.0
    struct EXTERNAL ITestEnums : virtual public Core::IUnknown {
        enum { ID = ID_TEST_ENUMS };

        // ===== Basic enums =====

        enum Color : uint8_t {
            RED    = 0,
            GREEN  = 1,
            BLUE   = 2,
            YELLOW = 3
        };

        // @encode:text
        enum State : uint8_t {
            IDLE    = 0,
            RUNNING = 1,
            PAUSED  = 2,
            STOPPED = 3,
            ERROR   = 255
        };

        enum Priority : uint16_t {
            LOW      = 0,
            NORMAL   = 100,
            HIGH     = 200,
            CRITICAL = 1000
        };

        enum Capabilities : uint8_t {
            CAP_NONE    = 0x00,
            CAP_AUDIO   = 0x01,
            CAP_VIDEO   = 0x02,
            CAP_NETWORK = 0x04,
            CAP_STORAGE = 0x08
        };

        // @property
        // @brief Active color — read-write
        virtual Core::hresult ActiveColor(Color& color /* @out */) const = 0;
        virtual Core::hresult ActiveColor(const Color color /* @in */) = 0;

        // @property
        // @brief Current state — read-only
        virtual Core::hresult CurrentState(State& state /* @out */) const = 0;

        // @property
        // @brief Requested priority — write-only
        virtual Core::hresult RequestedPriority(const Priority priority /* @in */) = 0;

        // @brief Retrieve the bitmask of active capabilities.
        //        The @encode:bitmask annotation causes the JSON-RPC layer to represent
        //        the value as a JSON array of flag names rather than a raw integer.
        // @param caps Receives the bitmask of currently enabled Capabilities flags.
        virtual Core::hresult GetCapabilities(Capabilities& caps /* @out @encode:bitmask */) const = 0;

        // @brief Set the bitmask of active capabilities.
        //        The @encode:bitmask annotation causes the JSON-RPC layer to accept a
        //        JSON array of flag names and convert it to the bitmask on the wire.
        // @param caps Bitmask of Capabilities flags to activate; all others are cleared.
        virtual Core::hresult SetCapabilities(const Capabilities caps /* @in @encode:bitmask */) = 0;

        // ===== Enum as input parameter =====

        // @brief Store a Color value.
        // @param color Color to store.
        virtual Core::hresult SetColor(const Color color /* @in */) = 0;

        // @brief Store a State value.
        //        State is declared with @encode:text; the JSON-RPC layer transmits it as
        //        a string name rather than an integer.
        // @param state State to store.
        virtual Core::hresult SetState(const State state /* @in */) = 0;

        // @brief Store a Priority value.
        // @param priority Priority to store.
        virtual Core::hresult SetPriority(const Priority priority /* @in */) = 0;

        // ===== Enum as output parameter =====

        // @brief Retrieve the last stored Color value.
        // @param color Receives the stored Color.
        virtual Core::hresult GetColor(Color& color /* @out */) const = 0;

        // @brief Retrieve the last stored State value.
        // @param state Receives the stored State.
        virtual Core::hresult GetState(State& state /* @out */) const = 0;

        // @brief Retrieve the last stored Priority value.
        // @param priority Receives the stored Priority.
        virtual Core::hresult GetPriority(Priority& priority /* @out */) const = 0;

        // ===== Enum as inout parameter =====

        // @brief Advance color to the next value in declaration order, wrapping after YELLOW.
        // @param color On entry, the current Color; on return, the next Color.
        virtual Core::hresult ToggleColor(Color& color /* @inout */) = 0;

        // @brief Advance state to the next value in declaration order, wrapping after ERROR.
        // @param state On entry, the current State; on return, the next State.
        virtual Core::hresult NextState(State& state /* @inout */) = 0;

        // ===== Multiple enum parameters =====

        // @brief Test whether two Color values are identical.
        // @param color1 First color to compare.
        // @param color2 Second color to compare.
        // @param equal  Receives true if color1 == color2, false otherwise.
        virtual Core::hresult CompareColors(
            const Color color1 /* @in */,
            const Color color2 /* @in */,
            bool& equal /* @out */) const = 0;

        // @brief Derive a result State from two State inputs.
        //        Returns RUNNING if current == desired, PAUSED if they differ,
        //        ERROR if either is invalid.
        // @param current Current State.
        // @param desired Target State.
        // @param result  Receives the derived State.
        virtual Core::hresult ComputeState(
            const State current /* @in */,
            const State desired /* @in */,
            State& result /* @out */) const = 0;

        // ===== Enum with optional parameters =====

        // @brief Set the active color, using RED as the default when color is not set.
        //        Core::OptionalType supersedes the @optional tag (Thunder R4+).
        // @param color Optional Color to apply; defaults to RED when not set.
        virtual Core::hresult SetColorWithDefault(
            const Core::OptionalType<Color>& color /* @in */) = 0;

        // @brief Compute a Priority by applying an optional modifier to a base value.
        //        When modifier is not set the base value is returned unchanged.
        // @param base     Starting Priority.
        // @param modifier Optional Priority delta to apply.
        // @param result   Receives the adjusted Priority (clamped to valid enum range).
        virtual Core::hresult AdjustPriority(
            const Priority base /* @in */,
            const Core::OptionalType<Priority>& modifier /* @in */,
            Priority& result /* @out */) const = 0;

        // ===== Enum arrays =====

        // FIXME: variable-length C arrays of enum are not supported by the generator.
        // Use std::vector instead (see ITestStructs for the vector pattern).
        // virtual Core::hresult GetColorPalette(
        //     Color colors[] /* @ out @ length:written @ maxlength:maxColors */,
        //     const uint16_t maxColors,
        //     uint16_t& written /* @ out */) const = 0;

        // virtual Core::hresult SetColorPalette(
        //     const Color colors[] /* @ in @ length:numColors */,
        //     const uint16_t numColors) = 0;

        // ===== Edge cases =====

        // @brief Echo a Color value unchanged (round-trip marshalling test).
        // @param color  Input Color.
        // @param result Receives a copy of color.
        virtual Core::hresult EchoColor(
            const Color color /* @in */,
            Color& result /* @out */) const = 0;

        // @brief Determine whether a State enumerator maps to a declared value.
        // @param state Input State (may be an out-of-range cast value).
        // @param valid Receives true if state is a declared enumerator.
        virtual Core::hresult IsValidState(
            const State state /* @in */,
            bool& valid /* @out */) const = 0;

        // @brief Convert a Color enumerator to its lowercase ASCII name.
        // @param color  Input Color.
        // @param result Receives the name string (e.g. "red", "green").
        virtual Core::hresult ColorToString(
            const Color color /* @in */,
            string& result /* @out */) const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder