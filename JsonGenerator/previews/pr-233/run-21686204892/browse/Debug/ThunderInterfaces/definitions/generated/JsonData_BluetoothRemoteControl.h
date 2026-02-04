// C++ types for BluetoothRemoteControl API.
// Generated automatically from 'IBluetoothRemoteControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBluetoothRemoteControl.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace BluetoothRemoteControl {

        // Method params/result classes
        //

        class AssignParamsData : public Core::JSON::Container {
        public:
            AssignParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
            }

            AssignParamsData(const AssignParamsData&) = delete;
            AssignParamsData(AssignParamsData&&) noexcept  = delete;

            AssignParamsData& operator=(const AssignParamsData&) = delete;
            AssignParamsData& operator=(AssignParamsData&&) noexcept  = delete;

            ~AssignParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Address.IsSet() == true);
            }

        public:
            Core::JSON::String Address; // Address of the Bluetooth device to assign
        }; // class AssignParamsData

        class BatteryLevelChangeParamsData : public Core::JSON::Container {
        public:
            BatteryLevelChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("level"), &Level);
            }

            BatteryLevelChangeParamsData(const BatteryLevelChangeParamsData&) = delete;
            BatteryLevelChangeParamsData(BatteryLevelChangeParamsData&&) noexcept  = delete;

            BatteryLevelChangeParamsData& operator=(const BatteryLevelChangeParamsData&) = delete;
            BatteryLevelChangeParamsData& operator=(BatteryLevelChangeParamsData&&) noexcept  = delete;

            ~BatteryLevelChangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Level.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt8 Level; // Battery level in percent
        }; // class BatteryLevelChangeParamsData

        class UnitmetadataData : public Core::JSON::Container {
        public:
            UnitmetadataData()
                : Core::JSON::Container()
            {
                _Init();
            }

            UnitmetadataData(const UnitmetadataData& _other)
                : Core::JSON::Container()
                , Name(_other.Name)
                , Model(_other.Model)
                , Serial(_other.Serial)
                , Firmware(_other.Firmware)
                , Software(_other.Software)
                , Manufacturer(_other.Manufacturer)
            {
                _Init();
            }

            UnitmetadataData(UnitmetadataData&& _other) noexcept
                : Core::JSON::Container()
                , Name(std::move(_other.Name))
                , Model(std::move(_other.Model))
                , Serial(std::move(_other.Serial))
                , Firmware(std::move(_other.Firmware))
                , Software(std::move(_other.Software))
                , Manufacturer(std::move(_other.Manufacturer))
            {
                _Init();
            }

            UnitmetadataData(const Exchange::IBluetoothRemoteControl::unitmetadata& _other)
                : Core::JSON::Container()
            {
                Name = _other.name;
                if (_other.model.IsSet() == true) {
                    Model = _other.model.Value();
                }
                if (_other.serial.IsSet() == true) {
                    Serial = _other.serial.Value();
                }
                if (_other.firmware.IsSet() == true) {
                    Firmware = _other.firmware.Value();
                }
                if (_other.software.IsSet() == true) {
                    Software = _other.software.Value();
                }
                if (_other.manufacturer.IsSet() == true) {
                    Manufacturer = _other.manufacturer.Value();
                }
                _Init();
            }

            UnitmetadataData& operator=(const UnitmetadataData& _rhs)
            {
                Name = _rhs.Name;
                if (_rhs.Model.IsSet() == true) {
                    Model = _rhs.Model;
                }
                if (_rhs.Serial.IsSet() == true) {
                    Serial = _rhs.Serial;
                }
                if (_rhs.Firmware.IsSet() == true) {
                    Firmware = _rhs.Firmware;
                }
                if (_rhs.Software.IsSet() == true) {
                    Software = _rhs.Software;
                }
                if (_rhs.Manufacturer.IsSet() == true) {
                    Manufacturer = _rhs.Manufacturer;
                }
                return (*this);
            }

            UnitmetadataData& operator=(UnitmetadataData&& _rhs) noexcept
            {
                Name = std::move(_rhs.Name);
                Model = std::move(_rhs.Model);
                Serial = std::move(_rhs.Serial);
                Firmware = std::move(_rhs.Firmware);
                Software = std::move(_rhs.Software);
                Manufacturer = std::move(_rhs.Manufacturer);
                return (*this);
            }

            UnitmetadataData& operator=(const Exchange::IBluetoothRemoteControl::unitmetadata& _rhs)
            {
                Name = _rhs.name;
                if (_rhs.model.IsSet() == true) {
                    Model = _rhs.model.Value();
                }
                if (_rhs.serial.IsSet() == true) {
                    Serial = _rhs.serial.Value();
                }
                if (_rhs.firmware.IsSet() == true) {
                    Firmware = _rhs.firmware.Value();
                }
                if (_rhs.software.IsSet() == true) {
                    Software = _rhs.software.Value();
                }
                if (_rhs.manufacturer.IsSet() == true) {
                    Manufacturer = _rhs.manufacturer.Value();
                }
                return (*this);
            }

            operator Exchange::IBluetoothRemoteControl::unitmetadata() const
            {
                Exchange::IBluetoothRemoteControl::unitmetadata _value{};
                _value.name = Name;
                if (Model.IsSet() == true) {
                    _value.model = Model;
                }
                if (Serial.IsSet() == true) {
                    _value.serial = Serial;
                }
                if (Firmware.IsSet() == true) {
                    _value.firmware = Firmware;
                }
                if (Software.IsSet() == true) {
                    _value.software = Software;
                }
                if (Manufacturer.IsSet() == true) {
                    _value.manufacturer = Manufacturer;
                }
                return (_value);
            }

            ~UnitmetadataData() = default;

        public:
            bool IsDataValid() const
            {
                return (Name.IsSet() == true);
            }

        private:
            void _Init()
            {
                Add(_T("name"), &Name);
                Add(_T("model"), &Model);
                Add(_T("serial"), &Serial);
                Add(_T("firmware"), &Firmware);
                Add(_T("software"), &Software);
                Add(_T("manufacturer"), &Manufacturer);
            }

        public:
            Core::JSON::String Name; // Name of the unit
            Core::JSON::String Model; // Model name
            Core::JSON::String Serial; // Serial number
            Core::JSON::String Firmware; // Firmware version
            Core::JSON::String Software; // Software version
            Core::JSON::String Manufacturer; // Vendor/manufacturer name
        }; // class UnitmetadataData

        class VoiceControlData : public Core::JSON::Container {
        public:
            VoiceControlData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            VoiceControlData(const VoiceControlData&) = delete;
            VoiceControlData(VoiceControlData&&) noexcept  = delete;

            VoiceControlData& operator=(const VoiceControlData&) = delete;
            VoiceControlData& operator=(VoiceControlData&&) noexcept  = delete;

            ~VoiceControlData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Value; // Toggle voice control
        }; // class VoiceControlData

    } // namespace BluetoothRemoteControl

    POP_WARNING()

} // namespace JsonData

}

