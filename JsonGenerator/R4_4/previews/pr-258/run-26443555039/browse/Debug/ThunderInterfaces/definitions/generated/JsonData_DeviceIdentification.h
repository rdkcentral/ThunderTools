// C++ types for Device Identification API.
// Generated automatically from 'DeviceIdentification.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace DeviceIdentification {

        // Method params/result classes
        //

        class DeviceidentificationData : public Core::JSON::Container {
        public:
            DeviceidentificationData()
                : Core::JSON::Container()
            {
                Add(_T("firmwareversion"), &Firmwareversion);
                Add(_T("chipset"), &Chipset);
                Add(_T("deviceid"), &Deviceid);
            }

            DeviceidentificationData(const DeviceidentificationData&) = delete;
            DeviceidentificationData(DeviceidentificationData&&) noexcept  = delete;

            DeviceidentificationData& operator=(const DeviceidentificationData&) = delete;
            DeviceidentificationData& operator=(DeviceidentificationData&&) noexcept  = delete;

            ~DeviceidentificationData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Firmwareversion.IsSet() == true) && (Chipset.IsSet() == true) && (Deviceid.IsSet() == true));
            }

        public:
            Core::JSON::String Firmwareversion; // Version of the device firmware
            Core::JSON::String Chipset; // Chipset used for this device
            Core::JSON::String Deviceid; // Device ID
        }; // class DeviceidentificationData

    } // namespace DeviceIdentification

    POP_WARNING()

} // namespace JsonData

}

