// C++ types for DeviceIdentification API.
// Generated automatically from 'IDeviceIdentification.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IDeviceIdentification.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace DeviceIdentification {

        // Method params/result classes
        //

        class DeviceInfoData : public Core::JSON::Container {
        public:
            DeviceInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            DeviceInfoData(const DeviceInfoData& _other)
                : Core::JSON::Container()
                , DeviceID(_other.DeviceID)
                , FirmwareVersion(_other.FirmwareVersion)
                , Chipset(_other.Chipset)
            {
                _Init();
            }

            DeviceInfoData(DeviceInfoData&& _other) noexcept
                : Core::JSON::Container()
                , DeviceID(std::move(_other.DeviceID))
                , FirmwareVersion(std::move(_other.FirmwareVersion))
                , Chipset(std::move(_other.Chipset))
            {
                _Init();
            }

            DeviceInfoData(const Exchange::IDeviceIdentification::DeviceInfo& _other)
                : Core::JSON::Container()
            {
                DeviceID = _other.deviceID;
                if (_other.firmwareVersion.IsSet() == true) {
                    FirmwareVersion = _other.firmwareVersion.Value();
                }
                if (_other.chipset.IsSet() == true) {
                    Chipset = _other.chipset.Value();
                }
                _Init();
            }

            DeviceInfoData& operator=(const DeviceInfoData& _rhs)
            {
                DeviceID = _rhs.DeviceID;
                if (_rhs.FirmwareVersion.IsSet() == true) {
                    FirmwareVersion = _rhs.FirmwareVersion;
                }
                if (_rhs.Chipset.IsSet() == true) {
                    Chipset = _rhs.Chipset;
                }
                return (*this);
            }

            DeviceInfoData& operator=(DeviceInfoData&& _rhs) noexcept
            {
                DeviceID = std::move(_rhs.DeviceID);
                FirmwareVersion = std::move(_rhs.FirmwareVersion);
                Chipset = std::move(_rhs.Chipset);
                return (*this);
            }

            DeviceInfoData& operator=(const Exchange::IDeviceIdentification::DeviceInfo& _rhs)
            {
                DeviceID = _rhs.deviceID;
                if (_rhs.firmwareVersion.IsSet() == true) {
                    FirmwareVersion = _rhs.firmwareVersion.Value();
                }
                if (_rhs.chipset.IsSet() == true) {
                    Chipset = _rhs.chipset.Value();
                }
                return (*this);
            }

            operator Exchange::IDeviceIdentification::DeviceInfo() const
            {
                Exchange::IDeviceIdentification::DeviceInfo _value{};
                _value.deviceID = DeviceID;
                if (FirmwareVersion.IsSet() == true) {
                    _value.firmwareVersion = FirmwareVersion;
                }
                if (Chipset.IsSet() == true) {
                    _value.chipset = Chipset;
                }
                return (_value);
            }

            ~DeviceInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return (DeviceID.IsSet() == true);
            }

        private:
            void _Init()
            {
                Add(_T("deviceid"), &DeviceID);
                Add(_T("firmwareversion"), &FirmwareVersion);
                Add(_T("chipset"), &Chipset);
            }

        public:
            Core::JSON::String DeviceID; // Device ID
            Core::JSON::String FirmwareVersion; // Version of the device firmware
            Core::JSON::String Chipset; // Chipset used for this device
        }; // class DeviceInfoData

    } // namespace DeviceIdentification

    POP_WARNING()

} // namespace JsonData

}

