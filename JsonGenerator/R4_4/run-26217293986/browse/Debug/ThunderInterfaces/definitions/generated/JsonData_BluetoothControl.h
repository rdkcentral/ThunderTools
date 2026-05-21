// C++ types for Bluetooth Control API.
// Generated automatically from 'BluetoothControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBluetooth.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace BluetoothControl {

        // Common enums
        //

        // Discoverable mode
        enum class scanmode : uint8_t {
            GENERAL,
            LIMITED
        };

        // Discoverable type
        enum class scantype : uint8_t {
            CLASSIC,
            LOW_ENERGY
        };

        // Common classes
        //

        class ConnectParamsInfo : public Core::JSON::Container {
        public:
            ConnectParamsInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            ConnectParamsInfo(const ConnectParamsInfo& _other)
                : Core::JSON::Container()
                , Address(_other.Address)
                , Type(_other.Type)
            {
                _Init();
            }

            ConnectParamsInfo(ConnectParamsInfo&& _other) noexcept
                : Core::JSON::Container()
                , Address(std::move(_other.Address))
                , Type(std::move(_other.Type))
            {
                _Init();
            }

            ConnectParamsInfo& operator=(const ConnectParamsInfo& _rhs)
            {
                Address = _rhs.Address;
                Type = _rhs.Type;
                return (*this);
            }

            ConnectParamsInfo& operator=(ConnectParamsInfo&& _rhs) noexcept
            {
                Address = std::move(_rhs.Address);
                Type = std::move(_rhs.Type);
                return (*this);
            }

            ~ConnectParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Address.IsSet() == true);
            }

        private:
            void _Init()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
        }; // class ConnectParamsInfo

        class DeviceData : public Core::JSON::Container {
        public:
            DeviceData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("name"), &Name);
                Add(_T("class"), &Class);
                Add(_T("appearance"), &Appearance);
                Add(_T("services"), &Services);
                Add(_T("connected"), &Connected);
                Add(_T("paired"), &Paired);
            }

            DeviceData(const DeviceData&) = delete;
            DeviceData(DeviceData&&) noexcept  = delete;

            DeviceData& operator=(const DeviceData&) = delete;
            DeviceData& operator=(DeviceData&&) noexcept  = delete;

            ~DeviceData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (Connected.IsSet() == true) && (Paired.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
            Core::JSON::String Name; // Name of the device
            Core::JSON::DecUInt32 Class; // Class of device
            Core::JSON::DecUInt32 Appearance; // Appearance value
            Core::JSON::ArrayType<Core::JSON::String> Services; // List of supported services
            Core::JSON::Boolean Connected; // Indicates if the device is currently connected
            Core::JSON::Boolean Paired; // Indicates if the device is currently paired
        }; // class DeviceData

        class StopdiscoverableParamsInfo : public Core::JSON::Container {
        public:
            StopdiscoverableParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
            }

            StopdiscoverableParamsInfo(const StopdiscoverableParamsInfo&) = delete;
            StopdiscoverableParamsInfo(StopdiscoverableParamsInfo&&) noexcept  = delete;

            StopdiscoverableParamsInfo& operator=(const StopdiscoverableParamsInfo&) = delete;
            StopdiscoverableParamsInfo& operator=(StopdiscoverableParamsInfo&&) noexcept  = delete;

            ~StopdiscoverableParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<scantype> Type; // Discoverable type
        }; // class StopdiscoverableParamsInfo

        // Method params/result classes
        //

        class AdapterData : public Core::JSON::Container {
        public:
            // Adapter type
            enum class adaptertype : uint8_t {
                CLASSIC,
                LOW_ENERGY,
                DUAL
            };

            AdapterData()
                : Core::JSON::Container()
            {
                Add(_T("id"), &Id);
                Add(_T("interface"), &Interface);
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("version"), &Version);
                Add(_T("manufacturer"), &Manufacturer);
                Add(_T("class"), &Class);
                Add(_T("name"), &Name);
                Add(_T("shortname"), &Shortname);
            }

            AdapterData(const AdapterData&) = delete;
            AdapterData(AdapterData&&) noexcept  = delete;

            AdapterData& operator=(const AdapterData&) = delete;
            AdapterData& operator=(AdapterData&&) noexcept  = delete;

            ~AdapterData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Id.IsSet() == true) && (Interface.IsSet() == true) && (Address.IsSet() == true) && (Type.IsSet() == true) && (Version.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt16 Id; // Interface ID number
            Core::JSON::String Interface; // Interface name
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<AdapterData::adaptertype> Type; // Adapter type
            Core::JSON::DecUInt8 Version; // Version
            Core::JSON::DecUInt16 Manufacturer; // Manufacturer company identifer
            Core::JSON::DecUInt32 Class; // Class of device
            Core::JSON::String Name; // Name
            Core::JSON::String Shortname; // Short name
        }; // class AdapterData

        class ConfirmpasskeyParamsData : public Core::JSON::Container {
        public:
            ConfirmpasskeyParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("iscorrect"), &Iscorrect);
            }

            ConfirmpasskeyParamsData(const ConfirmpasskeyParamsData&) = delete;
            ConfirmpasskeyParamsData(ConfirmpasskeyParamsData&&) noexcept  = delete;

            ConfirmpasskeyParamsData& operator=(const ConfirmpasskeyParamsData&) = delete;
            ConfirmpasskeyParamsData& operator=(ConfirmpasskeyParamsData&&) noexcept  = delete;

            ~ConfirmpasskeyParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (Iscorrect.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
            Core::JSON::Boolean Iscorrect; // Specifies if the passkey sent in *passkeyconfirmrequest* event is correct (true) or incorrect (false)
        }; // class ConfirmpasskeyParamsData

        class DevicestatechangeParamsData : public Core::JSON::Container {
        public:
            // Device state
            enum class devicestate : uint8_t {
                PAIRING,
                PAIRED,
                UNPAIRED,
                CONNECTED,
                DISCONNECTED
            };

            // Disconnection reason in case of *Disconnected* event
            enum class disconnectreason : uint8_t {
                CONNECTION_TIMEOUT,
                AUTHENTICATION_FAILURE,
                REMOTE_LOW_ON_RESOURCES,
                REMOTE_POWERED_OFF,
                TERMINATED_BY_REMOTE,
                TERMINATED_BY_HOST
            };

            DevicestatechangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("state"), &State);
                Add(_T("disconnectreason"), &Disconnectreason);
            }

            DevicestatechangeParamsData(const DevicestatechangeParamsData&) = delete;
            DevicestatechangeParamsData(DevicestatechangeParamsData&&) noexcept  = delete;

            DevicestatechangeParamsData& operator=(const DevicestatechangeParamsData&) = delete;
            DevicestatechangeParamsData& operator=(DevicestatechangeParamsData&&) noexcept  = delete;

            ~DevicestatechangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (State.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
            Core::JSON::EnumType<DevicestatechangeParamsData::devicestate> State; // Device state
            Core::JSON::EnumType<DevicestatechangeParamsData::disconnectreason> Disconnectreason; // Disconnection reason in case of *Disconnected* event
        }; // class DevicestatechangeParamsData

        class DiscoverablestartedParamsData : public Core::JSON::Container {
        public:
            DiscoverablestartedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
                Add(_T("connectable"), &Connectable);
            }

            DiscoverablestartedParamsData(const DiscoverablestartedParamsData&) = delete;
            DiscoverablestartedParamsData(DiscoverablestartedParamsData&&) noexcept  = delete;

            DiscoverablestartedParamsData& operator=(const DiscoverablestartedParamsData&) = delete;
            DiscoverablestartedParamsData& operator=(DiscoverablestartedParamsData&&) noexcept  = delete;

            ~DiscoverablestartedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Mode.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<scantype> Type; // Discoverable type
            Core::JSON::EnumType<scanmode> Mode; // Discoverable mode
            Core::JSON::Boolean Connectable; // Indicates connectable advertising (true, *LowEnergy* only)
        }; // class DiscoverablestartedParamsData

        class PairParamsData : public Core::JSON::Container {
        public:
            PairParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("capabilities"), &Capabilities);
                Add(_T("timeout"), &Timeout);
            }

            PairParamsData(const PairParamsData&) = delete;
            PairParamsData(PairParamsData&&) noexcept  = delete;

            PairParamsData& operator=(const PairParamsData&) = delete;
            PairParamsData& operator=(PairParamsData&&) noexcept  = delete;

            ~PairParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Address.IsSet() == true);
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::pairingcapabilities> Capabilities; // Pairing capabilities
            Core::JSON::DecUInt16 Timeout; // Maximum time allowed for the pairing process to complete (in seconds)
        }; // class PairParamsData

        class PasskeyconfirmrequestParamsData : public Core::JSON::Container {
        public:
            PasskeyconfirmrequestParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("secret"), &Secret);
            }

            PasskeyconfirmrequestParamsData(const PasskeyconfirmrequestParamsData&) = delete;
            PasskeyconfirmrequestParamsData(PasskeyconfirmrequestParamsData&&) noexcept  = delete;

            PasskeyconfirmrequestParamsData& operator=(const PasskeyconfirmrequestParamsData&) = delete;
            PasskeyconfirmrequestParamsData& operator=(PasskeyconfirmrequestParamsData&&) noexcept  = delete;

            ~PasskeyconfirmrequestParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (Secret.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
            Core::JSON::DecUInt32 Secret; // A six-digit decimal number passkey sent by the remote device for confirmation; may be 0 for a simple accept/forbid paring request
        }; // class PasskeyconfirmrequestParamsData

        class ProvidepincodeParamsData : public Core::JSON::Container {
        public:
            ProvidepincodeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("secret"), &Secret);
            }

            ProvidepincodeParamsData(const ProvidepincodeParamsData&) = delete;
            ProvidepincodeParamsData(ProvidepincodeParamsData&&) noexcept  = delete;

            ProvidepincodeParamsData& operator=(const ProvidepincodeParamsData&) = delete;
            ProvidepincodeParamsData& operator=(ProvidepincodeParamsData&&) noexcept  = delete;

            ~ProvidepincodeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (Secret.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
            Core::JSON::String Secret; // A PIN-code string typically consisting of (but not limited to) four decimal digits
        }; // class ProvidepincodeParamsData

        class ProvidepasskeyParamsData : public Core::JSON::Container {
        public:
            ProvidepasskeyParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("secret"), &Secret);
            }

            ProvidepasskeyParamsData(const ProvidepasskeyParamsData&) = delete;
            ProvidepasskeyParamsData(ProvidepasskeyParamsData&&) noexcept  = delete;

            ProvidepasskeyParamsData& operator=(const ProvidepasskeyParamsData&) = delete;
            ProvidepasskeyParamsData& operator=(ProvidepasskeyParamsData&&) noexcept  = delete;

            ~ProvidepasskeyParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (Secret.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type> Type; // Device type
            Core::JSON::DecUInt32 Secret; // A six-digit decimal number passkey
        }; // class ProvidepasskeyParamsData

        class ScanParamsData : public Core::JSON::Container {
        public:
            ScanParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
                Add(_T("timeout"), &Timeout);
                Add(_T("duration"), &Duration);
            }

            ScanParamsData(const ScanParamsData&) = delete;
            ScanParamsData(ScanParamsData&&) noexcept  = delete;

            ScanParamsData& operator=(const ScanParamsData&) = delete;
            ScanParamsData& operator=(ScanParamsData&&) noexcept  = delete;

            ~ScanParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<scantype> Type; // Scan type
            Core::JSON::EnumType<scanmode> Mode; // Scan mode
            Core::JSON::DecUInt16 Timeout; // Duration of the scan (in seconds)
            Core::JSON::DecUInt16 Duration; // Duration of the scan (in seconds)
        }; // class ScanParamsData

        class ScanstartedParamsData : public Core::JSON::Container {
        public:
            ScanstartedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
            }

            ScanstartedParamsData(const ScanstartedParamsData&) = delete;
            ScanstartedParamsData(ScanstartedParamsData&&) noexcept  = delete;

            ScanstartedParamsData& operator=(const ScanstartedParamsData&) = delete;
            ScanstartedParamsData& operator=(ScanstartedParamsData&&) noexcept  = delete;

            ~ScanstartedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<scantype> Type; // Scan type
            Core::JSON::EnumType<scanmode> Mode; // Scan mode
        }; // class ScanstartedParamsData

        class SetdiscoverableParamsData : public Core::JSON::Container {
        public:
            SetdiscoverableParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
                Add(_T("connectable"), &Connectable);
                Add(_T("duration"), &Duration);
            }

            SetdiscoverableParamsData(const SetdiscoverableParamsData&) = delete;
            SetdiscoverableParamsData(SetdiscoverableParamsData&&) noexcept  = delete;

            SetdiscoverableParamsData& operator=(const SetdiscoverableParamsData&) = delete;
            SetdiscoverableParamsData& operator=(SetdiscoverableParamsData&&) noexcept  = delete;

            ~SetdiscoverableParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<scantype> Type; // Discoverable type
            Core::JSON::EnumType<scanmode> Mode; // Discoverable mode
            Core::JSON::Boolean Connectable; // Selects connectable advertising (true, *LowEnergy* only)
            Core::JSON::DecUInt16 Duration; // Duration of the discoverable operation (in seconds)
        }; // class SetdiscoverableParamsData

    } // namespace BluetoothControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::BluetoothControl::scantype)
ENUM_CONVERSION_HANDLER(JsonData::BluetoothControl::scanmode)
ENUM_CONVERSION_HANDLER(Exchange::IBluetooth::IDevice::type)
ENUM_CONVERSION_HANDLER(Exchange::IBluetooth::IDevice::pairingcapabilities)
ENUM_CONVERSION_HANDLER(JsonData::BluetoothControl::AdapterData::adaptertype)
ENUM_CONVERSION_HANDLER(JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate)
ENUM_CONVERSION_HANDLER(JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason)

}

