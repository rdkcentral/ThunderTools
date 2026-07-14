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
    // ITestAnnotationEvents
    //
    // COM-RPC-only event interface exercising:
    //   - @index on event notification parameters (per-port delivery)
    //   - @index:deprecated on events (broadcast to all regardless of index)
    //   - @statuslistener (immediate state delivery on registration)
    //
    // WHY SEPARATE: Event notification subscription over COM-RPC requires the
    // interface to be registered for COM-RPC only (not JSON-RPC). When an
    // interface is registered for both COM-RPC and JSON-RPC with HAS_EVENTS,
    // the generated proxy/stub uses a different reverse-channel path that
    // conflicts with direct INotification* registration from test code.
    // Splitting events into a dedicated COM-RPC-only interface avoids this
    // and matches the pattern used by ITestEvents.
    //
    // NOTE: No @json tag here — this interface is COM-RPC only.
    // =========================================================================
    struct EXTERNAL ITestAnnotationEvents : virtual public Core::IUnknown {
        enum { ID = ID_TEST_ANNOTATION_EVENTS };

        // @encode:text
        enum State : uint8_t {
            DISCONNECTED = 0,
            CONNECTING   = 1,
            CONNECTED    = 2,
            ERROR        = 3
        };

        // @bitmask
        enum Caps : uint8_t {
            CAP_NONE  = 0x00,
            CAP_AUDIO = 0x01,
            CAP_VIDEO = 0x02,
            CAP_NET   = 0x04
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_TEST_ANNOTATION_EVENTS_NOTIFICATION };

            // @brief Fired when state changes on a specific port (indexed event).
            // @param port Port identifier for per-client event filtering.
            // @param state New state for this port.
            virtual void OnPortStateChanged(
                const uint8_t port /* @index */,
                const State state) = 0;

            // @brief Fired when capabilities change. Delivers current state on registration.
            // @statuslistener
            // @param caps Current capability flags.
            virtual void OnCapsChanged(const Caps caps) = 0;

            // @brief Fired when a global status update occurs (broadcast, no index).
            // @param message Status message.
            virtual void OnStatusUpdate(const string& message) = 0;

            // @brief Fired when a legacy channel event occurs.
            //        The index is deprecated — event is delivered to all clients
            //        regardless of channel value (broadcast-to-all semantics).
            // @param channel Legacy channel identifier (deprecated index).
            // @param level Signal level.
            virtual void OnLegacyChannelEvent(
                const uint8_t channel /* @index:deprecated */,
                const uint32_t level) = 0;
        };

        // @brief Register for event notifications.
        virtual Core::hresult Register(INotification* notification) = 0;

        // @brief Unregister from event notifications.
        virtual Core::hresult Unregister(INotification* notification) = 0;

        // @brief Set the current capabilities (also notifies subscribers).
        // @param caps New capability flags.
        virtual Core::hresult SetCaps(const Caps caps /* @in */) = 0;

        // @brief Get the current capabilities.
        // @param caps Receives current capability flags.
        virtual Core::hresult GetCaps(Caps& caps /* @out */) const = 0;

        // @brief Trigger port state event for testing.
        // @param port Port index.
        // @param state New state to report.
        virtual Core::hresult TriggerPortState(const uint8_t port /* @in */, const State state /* @in */) = 0;

        // @brief Trigger a global status message for testing.
        // @param message Message to broadcast.
        virtual Core::hresult TriggerStatus(const string& message /* @in */) = 0;

        // @brief Trigger a legacy channel event for testing.
        //        Despite having an index parameter, the event is delivered to all
        //        subscribers because the index is marked deprecated.
        // @param channel Channel value (ignored for filtering due to deprecated index).
        // @param level Signal level to report.
        virtual Core::hresult TriggerLegacyChannel(const uint8_t channel /* @in */, const uint32_t level /* @in */) = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder
