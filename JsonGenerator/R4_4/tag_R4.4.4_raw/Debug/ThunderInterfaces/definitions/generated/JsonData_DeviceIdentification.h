// C++ classes for Device Identification API JSON-RPC API.
// Generated automatically from 'DeviceIdentification.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            DeviceidentificationData(const DeviceidentificationData&) = delete;
            DeviceidentificationData& operator=(const DeviceidentificationData&) = delete;

        public:
            Core::JSON::String Firmwareversion; // Version of the device firmware
            Core::JSON::String Chipset; // Chipset used for this device
            Core::JSON::String Deviceid; // Device ID
        }; // class DeviceidentificationData

    } // namespace DeviceIdentification

} // namespace JsonData

}

