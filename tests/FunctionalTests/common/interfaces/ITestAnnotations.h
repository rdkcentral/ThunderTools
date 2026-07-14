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

#include "Ids.h"
#include "Module.h"

namespace Thunder {
namespace FunctionalTest {

    // =========================================================================
    // ITestAnnotations
    //
    // Comprehensive interface exercising many IDL annotation tags:
    //   prefix, alt, alt-deprecated, alt-obsolete, deprecated, obsolete,
    //   text on struct members and enum values, bitmask on enum declaration,
    //   end sentinel exclusion, encode:base64, encode:hex on buffers,
    //   index on events, statuslistener, wrapped, extract on struct arrays,
    //   optional on bool, extended property vs method semantics.
    //
    // @json 1.0.0
    // @prefix tags
    // =========================================================================
    struct EXTERNAL ITestAnnotations : virtual public Core::IUnknown {
        enum { ID = ID_TEST_ANNOTATIONS };

        // =================================================================
        // deprecated / obsolete — lifecycle markers
        // =================================================================

        // @brief A deprecated method that is still callable.
        // @deprecated
        // @param value Input value to echo.
        // @param result Receives the echoed value.
        virtual Core::hresult DeprecatedEcho(const uint32_t value /* @in */, uint32_t& result /* @out */) const = 0;

        // @brief An obsolete method that is still callable.
        // @obsolete
        // @param value Input value to echo.
        // @param result Receives the echoed value.
        virtual Core::hresult ObsoleteEcho(const uint32_t value /* @in */, uint32_t& result /* @out */) const = 0;

        // =================================================================
        // alt / alt-deprecated / alt-obsolete — alternative names
        // =================================================================

        // @brief Method with a primary and alternative JSON-RPC name.
        // @alt echoAlt
        // @param value Input value.
        // @param result Receives the echoed value.
        virtual Core::hresult EchoWithAlt(const uint32_t value /* @in */, uint32_t& result /* @out */) const = 0;

        // @brief Method with a deprecated alternative name.
        // @alt-deprecated legacyAdd
        // @param a First operand.
        // @param b Second operand.
        // @param result Receives a + b.
        virtual Core::hresult Add(const uint32_t a /* @in */, const uint32_t b /* @in */, uint32_t& result /* @out */) const = 0;

        // @brief Method with an obsolete alternative name.
        // @alt-obsolete oldSubtract
        // @param a First operand.
        // @param b Second operand.
        // @param result Receives a - b.
        virtual Core::hresult Subtract(const uint32_t a /* @in */, const uint32_t b /* @in */, uint32_t& result /* @out */) const = 0;

        // =================================================================
        // text on struct members — per-field JSON name override
        // =================================================================

        struct DeviceInfo {
            string Name       /* @text deviceName */;
            uint32_t Version  /* @text firmwareVersion */;
            bool Active       /* @text isActive */;
        };

        // @brief Echoes a DeviceInfo struct round-trip.
        //        Text overrides rename C++ members to different JSON keys.
        // @param input Input struct with overridden field names.
        // @param output Receives the echoed struct.
        virtual Core::hresult EchoDeviceInfo(const DeviceInfo& input /* @in */, DeviceInfo& output /* @out */) const = 0;

        // =================================================================
        // text on enum values — per-enumerator JSON name override
        // =================================================================

        // @encode:text
        enum ConnectionState : uint8_t {
            DISCONNECTED = 0,
            // @text connecting
            CONN_IN_PROGRESS = 1,
            CONNECTED = 2,
            // @text auth-failed
            AUTH_FAILURE = 3
        };

        // @brief Set the connection state.
        // @param state Connection state to set.
        virtual Core::hresult SetConnectionState(const ConnectionState state /* @in */) = 0;

        // @brief Get the current connection state.
        // @param state Receives the current connection state.
        virtual Core::hresult GetConnectionState(ConnectionState& state /* @out */) const = 0;

        // =================================================================
        // bitmask on enum declaration (alias for encode:bitmask)
        // =================================================================

        // @bitmask
        enum Features : uint8_t {
            FEAT_NONE       = 0x00,
            FEAT_WIFI       = 0x01,
            FEAT_BLUETOOTH  = 0x02,
            FEAT_ETHERNET   = 0x04,
            FEAT_NFC        = 0x08,
            // @end
            FEAT_ALL        = 0x0F
        };

        // @brief Set active features using bitmask.
        // @param features Active feature flags.
        virtual Core::hresult SetFeatures(const Features features /* @in @encode:bitmask */) = 0;

        // @brief Get active features.
        // @param features Receives the active feature flags.
        virtual Core::hresult GetFeatures(Features& features /* @out @encode:bitmask */) const = 0;

        // =================================================================
        // encode:base64 — variable-length buffer encoding
        // =================================================================

        // @brief Store a base64-encoded payload.
        // @param data Payload bytes.
        // @param size Number of bytes in data.
        // @retval ERROR_BAD_REQUEST data exceeds maximum allowed size.
        virtual Core::hresult SetPayloadBase64(
            const uint8_t data[] /* @in @length:size @encode:base64 */,
            const uint16_t size /* @restrict:1..256 */) = 0;

        // @brief Retrieve the stored payload as base64.
        // @param data Output buffer for payload bytes.
        // @param maxSize Maximum capacity of the buffer.
        // @param written Receives actual bytes written.
        virtual Core::hresult GetPayloadBase64(
            uint8_t data[] /* @out @length:written @maxlength:maxSize @encode:base64 */,
            const uint16_t maxSize,
            uint16_t& written /* @out */) = 0;

        // =================================================================
        // encode:hex — variable-length buffer encoding
        // =================================================================

        // @brief Store a hex-encoded token.
        // @param data Token bytes.
        // @param size Number of bytes in data.
        virtual Core::hresult SetTokenHex(
            const uint8_t data[] /* @in @length:size @encode:hex */,
            const uint16_t size /* @restrict:1..64 */) = 0;

        // @brief Retrieve the stored token as hex.
        // @param data Output buffer for token bytes.
        // @param maxSize Maximum capacity of the buffer.
        // @param written Receives actual bytes written.
        virtual Core::hresult GetTokenHex(
            uint8_t data[] /* @out @length:written @maxlength:maxSize @encode:hex */,
            const uint16_t maxSize,
            uint16_t& written /* @out */) = 0;

        // =================================================================
        // extract on struct arrays
        // =================================================================

        struct Point {
            int32_t x;
            int32_t y;
        };

        // @brief Echo a list of points with extraction.
        //        When a single point is returned, the array wrapper is omitted.
        // @param input Input points.
        // @param output Receives echoed points.
        virtual Core::hresult EchoPoints(
            const std::vector<Point>& input /* @in @extract @restrict:1..16 */,
            std::vector<Point>& output /* @out @extract @restrict:1..16 */) const = 0;

        // =================================================================
        // optional on bool — regression guard
        // =================================================================

        // @brief Concatenate a string with an optional uppercase flag.
        //        When uppercase is not set, it defaults to false.
        // @param text Input string.
        // @param uppercase Optional flag to convert to uppercase.
        // @param result Receives the (possibly uppercased) string.
        virtual Core::hresult FormatText(
            const string& text /* @in */,
            const Core::OptionalType<bool>& uppercase /* @in @default:false */,
            string& result /* @out */) = 0;

        // =================================================================
        // Event with indexed delivery and statuslistener
        // =================================================================

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_TEST_ANNOTATIONS_NOTIFICATION };

            // @brief Fired when connection state changes on a specific port.
            // @param port Port identifier for event filtering.
            // @param state New connection state for this port.
            virtual void OnPortStateChanged(
                const uint8_t port /* @index */,
                const ConnectionState state) = 0;

            // @brief Fired when features change. New subscribers get current state.
            // @statuslistener
            // @param features Current active feature flags.
            virtual void OnFeaturesChanged(const Features features) = 0;
        };

        // @brief Register for notifications.
        virtual Core::hresult Register(INotification* notification) = 0;

        // @brief Unregister from notifications.
        virtual Core::hresult Unregister(INotification* notification) = 0;

        // @brief Trigger a port state change event (for testing).
        // @param port Port index to fire event on.
        // @param state New state to report.
        virtual Core::hresult TriggerPortEvent(const uint8_t port /* @in */, const ConnectionState state /* @in */) = 0;

        // @brief Trigger a feature change event (for testing).
        // @param features New features to report.
        virtual Core::hresult TriggerFeaturesEvent(const Features features /* @in @encode:bitmask */) = 0;

        // =================================================================
        // Empty parameter list (Constraint C5)
        // A method with no input or output params. Verifies the generator
        // produces a callable handler that simply returns success.
        // =================================================================

        // @brief No-op method with empty parameter list.
        virtual Core::hresult Ping() const = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
