/*
 * ITestEvents.h - Event Callback Testing Interface
 *
 * Tests event callbacks including complex payloads like iterators and structs.
 * This validates Thunder's event notification system with all data types.
 */

#pragma once

#include "Ids.h"
#include "Module.h"

// @stubgen:include <com/IIteratorType.h>

namespace Thunder {
namespace FunctionalTest {

    // @json 1.0.0
    struct EXTERNAL ITestEvents : virtual public Core::IUnknown {
        enum { ID = ID_TEST_EVENTS };

        // ===== Complex Data Structures for Events =====

        /* @brief Scan result for a discovered network entry. */
        struct ScanResult {
            /* @brief Name of the discovered network */
            string name;
            /* @brief Signal strength in dBm */
            uint32_t signalStrength;
            /* @brief Channel number of the discovered network */
            uint8_t channel;
            /* @brief Whether the network is secured */
            bool secured;
        };

        /* @brief Display mode information for a detected display mode. */
        struct DisplayMode {
            /* @brief Horizontal resolution in pixels */
            uint16_t width;
            /* @brief Vertical resolution in pixels */
            uint16_t height;
            /* @brief Refresh rate in Hz */
            uint8_t refreshRate;
            /* @brief Whether the mode is interlaced (true) or progressive (false) */
            bool interlaced;
        };

        // @event
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_TEST_EVENTS_NOTIFICATION };

            // ===== Basic Events =====

            // @brief Fired when a raw string payload arrives from the source.
            //        The @statuslistener annotation causes the generator to emit
            //        registration/unregistration status callbacks alongside the event.
            // @param data The received string payload.
            // @statuslistener
            virtual void OnDataReceived(const string& data) = 0;

            // @brief Fired when the state of a numbered channel changes.
            // @param state   New state value for the channel.
            virtual void OnStateChanged(const uint32_t state) = 0;

            // @brief Fired to report incremental progress of an ongoing operation.
            // @param current Number of units completed so far.
            // @param total   Total number of units in the operation.
            virtual void OnProgress(const uint32_t current, const uint32_t total) = 0;

            // @brief Fired when an asynchronous operation finishes with no payload.
            virtual void OnCompleted() = 0;

            // @brief Fired when the active color changes.
            // @param color New color value encoded as a uint8_t enumerator.
            virtual void OnColorChanged(const uint8_t color) = 0;

            // ===== Complex Events =====

            // @brief Fired when a single scan result becomes available.
            // @param result Struct describing the discovered network entry.
            virtual void OnScanResultAvailable(const ScanResult& result) = 0;

            // @brief Fired when a display mode is detected on a specific display.
            // @param displayId Identifier of the display that reported the mode.
            // @param mode      Struct describing the detected display mode.
            virtual void OnDisplayModeDetected(const string& displayId, const DisplayMode& mode) = 0;

            // ===== Iterator Payload Events =====

            // @brief Fired when a full network scan completes, delivering all results at once.
            //        The @restrict:0..200 annotation limits the vector to at most 200 entries.
            // @param results Vector of ScanResult entries found during the scan.
            virtual void OnScanCompleted(const std::vector<ScanResult>& results /* @in @restrict:0..200*/) = 0;

            // @brief Fired when the set of available display modes is determined for a display.
            //        The modes parameter is optional; it is unset when no modes could be determined.
            //        The @restrict:0..1000 annotation limits the vector to at most 1000 entries.
            // @param displayId Identifier of the display.
            // @param modes     Optional vector of available DisplayMode structs.
            virtual void OnDisplayModesAvailable(const string& displayId, const Core::OptionalType<std::vector<DisplayMode>>& modes /* @in @restrict:0..1000*/) = 0;

            // ===== Optional Parameter Events =====

            // @brief Fired when an optional string payload is received.
            //        When data is not set the event signals that no data is available.
            // @param data Optional string payload.
            virtual void OnOptionalDataReceived(const Core::OptionalType<string>& data) = 0;

            // @brief Fired when an optional integer value changes.
            //        When value is not set the event signals that the value became unavailable.
            // @param value Optional new value.
            virtual void OnOptionalValueChanged(const Core::OptionalType<uint32_t>& value) = 0;
        };

        // ===== Subscription Management =====

        // @brief Register a notification sink to receive events from this interface.
        //        Registering the same pointer twice has no effect (idempotent).
        // @param notification Observer to register; must not be nullptr.
        // @retval ERROR_ALREADY_CONNECTED notification is already registered.
        // @ interface tag is only for void*/interface-ID pairs — not needed for typed pointers.
        virtual Core::hresult Register(INotification* notification /* @in */) = 0;

        // @brief Unregister a previously registered notification sink.
        // @param notification Observer to unregister; must not be nullptr.
        // @retval ERROR_NOT_EXIST notification was not registered.
        virtual Core::hresult Unregister(INotification* notification /* @in */) = 0;

        // ===== Event Triggers (for testing) =====

        // @brief Trigger OnDataReceived on all registered listeners.
        // @param data Payload to deliver.
        virtual Core::hresult TriggerDataReceived(const string& data) = 0;

        // @brief Trigger OnStateChanged on all registered listeners.
        // @param state   State value to deliver.
        virtual Core::hresult TriggerStateChanged(const uint32_t state) = 0;

        // @brief Trigger OnProgress on all registered listeners.
        // @param current Completed-units value to deliver.
        // @param total   Total-units value to deliver.
        virtual Core::hresult TriggerProgress(const uint32_t current, const uint32_t total) = 0;

        // @brief Trigger OnCompleted on all registered listeners.
        virtual Core::hresult TriggerCompleted() = 0;

        // @brief Trigger OnColorChanged on all registered listeners.
        // @param color Color value to deliver.
        virtual Core::hresult TriggerColorChanged(const uint8_t color) = 0;

        // @brief Trigger OnScanResultAvailable on all registered listeners.
        // @param result ScanResult struct to deliver.
        virtual Core::hresult TriggerScanResultAvailable(const ScanResult& result) = 0;

        // @brief Trigger OnDisplayModeDetected on all registered listeners.
        // @param displayId Display identifier to deliver.
        // @param mode      DisplayMode struct to deliver.
        virtual Core::hresult TriggerDisplayModeDetected(const string& displayId, const DisplayMode& mode) = 0;

        // @brief Generate resultCount synthetic ScanResult entries and fire OnScanCompleted.
        //        The server synthesises the entries internally so the client need not supply them.
        // @param resultCount Number of synthetic ScanResult entries to include (0..200).
        virtual Core::hresult TriggerScanCompleted(const uint16_t resultCount) = 0;

        // @brief Generate modeCount synthetic DisplayMode entries and fire OnDisplayModesAvailable.
        //        Pass modeCount=0 to fire the event with an unset optional (no-modes case).
        // @param displayId  Display identifier to include in the event.
        // @param modeCount  Number of synthetic DisplayMode entries (0 = unset optional).
        virtual Core::hresult TriggerDisplayModesAvailable(const string& displayId, const uint16_t modeCount) = 0;

        // @brief Fire OnOptionalDataReceived on all registered listeners.
        // @param data Optional string to deliver; pass unset to exercise the no-data path.
        virtual Core::hresult TriggerOptionalDataReceived(const Core::OptionalType<string>& data) = 0;

        // @brief Fire OnOptionalValueChanged on all registered listeners.
        // @param value Optional uint32_t to deliver; pass unset to exercise the unavailable-value path.
        virtual Core::hresult TriggerOptionalValueChanged(const Core::OptionalType<uint32_t>& value) = 0;

        // ===== Query Methods =====

        // @brief Return the number of currently registered INotification listeners.
        // @param count Receives the listener count.
        virtual Core::hresult ListenerCount(uint32_t& count /* @out */) const = 0;

        // @brief Unregister and release all currently registered INotification listeners.
        virtual Core::hresult ClearListeners() = 0;
    };

} // namespace FunctionalTest
} // namespace Thunder