// C++ types for BluetoothControl API.
// Generated automatically from 'IBluetooth.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBluetooth.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace BluetoothControl {

        // Common classes
        //

        class ConnectParamsInfo : public Core::JSON::Container {
        public:
            ConnectParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
            }

            ConnectParamsInfo(const ConnectParamsInfo&) = delete;
            ConnectParamsInfo(ConnectParamsInfo&&) noexcept  = delete;

            ConnectParamsInfo& operator=(const ConnectParamsInfo&) = delete;
            ConnectParamsInfo& operator=(ConnectParamsInfo&&) noexcept  = delete;

            ~ConnectParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Connects to a Bluetooth device
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Connects to a Bluetooth device
        }; // class ConnectParamsInfo

        class ProvidePasskeyParamsInfo : public Core::JSON::Container {
        public:
            ProvidePasskeyParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("secret"), &Secret);
            }

            ProvidePasskeyParamsInfo(const ProvidePasskeyParamsInfo&) = delete;
            ProvidePasskeyParamsInfo(ProvidePasskeyParamsInfo&&) noexcept  = delete;

            ProvidePasskeyParamsInfo& operator=(const ProvidePasskeyParamsInfo&) = delete;
            ProvidePasskeyParamsInfo& operator=(ProvidePasskeyParamsInfo&&) noexcept  = delete;

            ~ProvidePasskeyParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (((Secret.IsSet() == true) && (Secret.Value() <= 999999))));
            }

        public:
            Core::JSON::String Address; // Provides a passkey for authentication during a pairing process
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Provides a passkey for authentication during a pairing process
            Core::JSON::DecUInt32 Secret; // A decimal six-digit passkey value
        }; // class ProvidePasskeyParamsInfo

        class StopDiscoverableParamsInfo : public Core::JSON::Container {
        public:
            StopDiscoverableParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
            }

            StopDiscoverableParamsInfo(const StopDiscoverableParamsInfo&) = delete;
            StopDiscoverableParamsInfo(StopDiscoverableParamsInfo&&) noexcept  = delete;

            StopDiscoverableParamsInfo& operator=(const StopDiscoverableParamsInfo&) = delete;
            StopDiscoverableParamsInfo& operator=(StopDiscoverableParamsInfo&&) noexcept  = delete;

            ~StopDiscoverableParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype> Type; // Stops LE advertising or BR/EDR inquiry scanning operation
        }; // class StopDiscoverableParamsInfo

        // Method params/result classes
        //

        class AdapterinfoData : public Core::JSON::Container {
        public:
            AdapterinfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            AdapterinfoData(const AdapterinfoData& _other)
                : Core::JSON::Container()
                , Id(_other.Id)
                , Interface(_other.Interface)
                , Address(_other.Address)
                , Type(_other.Type)
                , Version(_other.Version)
                , Manufacturer(_other.Manufacturer)
                , Cod(_other.Cod)
                , Name(_other.Name)
                , ShortName(_other.ShortName)
            {
                _Init();
            }

            AdapterinfoData(AdapterinfoData&& _other) noexcept
                : Core::JSON::Container()
                , Id(std::move(_other.Id))
                , Interface(std::move(_other.Interface))
                , Address(std::move(_other.Address))
                , Type(std::move(_other.Type))
                , Version(std::move(_other.Version))
                , Manufacturer(std::move(_other.Manufacturer))
                , Cod(std::move(_other.Cod))
                , Name(std::move(_other.Name))
                , ShortName(std::move(_other.ShortName))
            {
                _Init();
            }

            AdapterinfoData(const Exchange::JSONRPC::IBluetoothControl::adapterinfo& _other)
                : Core::JSON::Container()
            {
                Id = _other.id;
                Interface = _other.interface;
                Address = _other.address;
                Type = _other.type;
                Version = _other.version;
                if (_other.manufacturer.IsSet() == true) {
                    Manufacturer = _other.manufacturer.Value();
                }
                if (_other.cod.IsSet() == true) {
                    Cod = _other.cod.Value();
                }
                if (_other.name.IsSet() == true) {
                    Name = _other.name.Value();
                }
                if (_other.shortName.IsSet() == true) {
                    ShortName = _other.shortName.Value();
                }
                _Init();
            }

            AdapterinfoData& operator=(const AdapterinfoData& _rhs)
            {
                Id = _rhs.Id;
                Interface = _rhs.Interface;
                Address = _rhs.Address;
                Type = _rhs.Type;
                Version = _rhs.Version;
                if (_rhs.Manufacturer.IsSet() == true) {
                    Manufacturer = _rhs.Manufacturer;
                }
                if (_rhs.Cod.IsSet() == true) {
                    Cod = _rhs.Cod;
                }
                if (_rhs.Name.IsSet() == true) {
                    Name = _rhs.Name;
                }
                if (_rhs.ShortName.IsSet() == true) {
                    ShortName = _rhs.ShortName;
                }
                return (*this);
            }

            AdapterinfoData& operator=(AdapterinfoData&& _rhs) noexcept
            {
                Id = std::move(_rhs.Id);
                Interface = std::move(_rhs.Interface);
                Address = std::move(_rhs.Address);
                Type = std::move(_rhs.Type);
                Version = std::move(_rhs.Version);
                Manufacturer = std::move(_rhs.Manufacturer);
                Cod = std::move(_rhs.Cod);
                Name = std::move(_rhs.Name);
                ShortName = std::move(_rhs.ShortName);
                return (*this);
            }

            AdapterinfoData& operator=(const Exchange::JSONRPC::IBluetoothControl::adapterinfo& _rhs)
            {
                Id = _rhs.id;
                Interface = _rhs.interface;
                Address = _rhs.address;
                Type = _rhs.type;
                Version = _rhs.version;
                if (_rhs.manufacturer.IsSet() == true) {
                    Manufacturer = _rhs.manufacturer.Value();
                }
                if (_rhs.cod.IsSet() == true) {
                    Cod = _rhs.cod.Value();
                }
                if (_rhs.name.IsSet() == true) {
                    Name = _rhs.name.Value();
                }
                if (_rhs.shortName.IsSet() == true) {
                    ShortName = _rhs.shortName.Value();
                }
                return (*this);
            }

            operator Exchange::JSONRPC::IBluetoothControl::adapterinfo() const
            {
                Exchange::JSONRPC::IBluetoothControl::adapterinfo _value{};
                _value.id = Id;
                _value.interface = Interface;
                _value.address = Address;
                _value.type = Type;
                _value.version = Version;
                if (Manufacturer.IsSet() == true) {
                    _value.manufacturer = Manufacturer;
                }
                if (Cod.IsSet() == true) {
                    _value.cod = Cod;
                }
                if (Name.IsSet() == true) {
                    _value.name = Name;
                }
                if (ShortName.IsSet() == true) {
                    _value.shortName = ShortName;
                }
                return (_value);
            }

            ~AdapterinfoData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Id.IsSet() == true) && (Interface.IsSet() == true) && (Address.IsSet() == true) && (Type.IsSet() == true) && (Version.IsSet() == true) && ((Cod.IsSet() == false) || (Cod.Value() <= 16777215)));
            }

        private:
            void _Init()
            {
                Add(_T("id"), &Id);
                Add(_T("interface"), &Interface);
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("version"), &Version);
                Add(_T("manufacturer"), &Manufacturer);
                Add(_T("class"), &Cod);
                Add(_T("name"), &Name);
                Add(_T("shortname"), &ShortName);
            }

        public:
            Core::JSON::DecUInt8 Id; // Adapter ID number
            Core::JSON::String Interface; // Interface name
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::adaptertype> Type; // Adapter type
            Core::JSON::DecUInt8 Version; // Version
            Core::JSON::DecUInt16 Manufacturer; // Company Identification Code (CIC)
            Core::JSON::DecUInt32 Cod; // Class of Device (CoD) value
            Core::JSON::String Name; // Name
            Core::JSON::String ShortName; // Shortened name
        }; // class AdapterinfoData

        class ConfirmPasskeyParamsData : public Core::JSON::Container {
        public:
            ConfirmPasskeyParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("accept"), &Accept);
            }

            ConfirmPasskeyParamsData(const ConfirmPasskeyParamsData&) = delete;
            ConfirmPasskeyParamsData(ConfirmPasskeyParamsData&&) noexcept  = delete;

            ConfirmPasskeyParamsData& operator=(const ConfirmPasskeyParamsData&) = delete;
            ConfirmPasskeyParamsData& operator=(ConfirmPasskeyParamsData&&) noexcept  = delete;

            ~ConfirmPasskeyParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (Accept.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Confirms a passkey for authentication during a BR/EDR SSP pairing processs
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Confirms a passkey for authentication during a BR/EDR SSP pairing processs
            Core::JSON::Boolean Accept; // Confirm pairing (normally if the presented passkey is correct)
        }; // class ConfirmPasskeyParamsData

        class DeviceinfoData : public Core::JSON::Container {
        public:
            DeviceinfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            DeviceinfoData(const DeviceinfoData& _other)
                : Core::JSON::Container()
                , Address(_other.Address)
                , Type(_other.Type)
                , Name(_other.Name)
                , Cod(_other.Cod)
                , Appearance(_other.Appearance)
                , Services(_other.Services)
                , Paired(_other.Paired)
                , Connected(_other.Connected)
            {
                _Init();
            }

            DeviceinfoData(DeviceinfoData&& _other) noexcept
                : Core::JSON::Container()
                , Address(std::move(_other.Address))
                , Type(std::move(_other.Type))
                , Name(std::move(_other.Name))
                , Cod(std::move(_other.Cod))
                , Appearance(std::move(_other.Appearance))
                , Services(std::move(_other.Services))
                , Paired(std::move(_other.Paired))
                , Connected(std::move(_other.Connected))
            {
                _Init();
            }

            DeviceinfoData(const Exchange::JSONRPC::IBluetoothControl::deviceinfo& _other)
                : Core::JSON::Container()
            {
                Address = _other.address;
                Type = _other.type;
                if (_other.name.IsSet() == true) {
                    Name = _other.name.Value();
                }
                if (_other.cod.IsSet() == true) {
                    Cod = _other.cod.Value();
                }
                if (_other.appearance.IsSet() == true) {
                    Appearance = _other.appearance.Value();
                }
                if (_other.services.IsSet() == true) {
                    Services = _other.services.Value();
                }
                Paired = _other.paired;
                Connected = _other.connected;
                _Init();
            }

            DeviceinfoData& operator=(const DeviceinfoData& _rhs)
            {
                Address = _rhs.Address;
                Type = _rhs.Type;
                if (_rhs.Name.IsSet() == true) {
                    Name = _rhs.Name;
                }
                if (_rhs.Cod.IsSet() == true) {
                    Cod = _rhs.Cod;
                }
                if (_rhs.Appearance.IsSet() == true) {
                    Appearance = _rhs.Appearance;
                }
                if (_rhs.Services.IsSet() == true) {
                    Services = _rhs.Services;
                }
                Paired = _rhs.Paired;
                Connected = _rhs.Connected;
                return (*this);
            }

            DeviceinfoData& operator=(DeviceinfoData&& _rhs) noexcept
            {
                Address = std::move(_rhs.Address);
                Type = std::move(_rhs.Type);
                Name = std::move(_rhs.Name);
                Cod = std::move(_rhs.Cod);
                Appearance = std::move(_rhs.Appearance);
                Services = std::move(_rhs.Services);
                Paired = std::move(_rhs.Paired);
                Connected = std::move(_rhs.Connected);
                return (*this);
            }

            DeviceinfoData& operator=(const Exchange::JSONRPC::IBluetoothControl::deviceinfo& _rhs)
            {
                Address = _rhs.address;
                Type = _rhs.type;
                if (_rhs.name.IsSet() == true) {
                    Name = _rhs.name.Value();
                }
                if (_rhs.cod.IsSet() == true) {
                    Cod = _rhs.cod.Value();
                }
                if (_rhs.appearance.IsSet() == true) {
                    Appearance = _rhs.appearance.Value();
                }
                if (_rhs.services.IsSet() == true) {
                    Services = _rhs.services.Value();
                }
                Paired = _rhs.paired;
                Connected = _rhs.connected;
                return (*this);
            }

            operator Exchange::JSONRPC::IBluetoothControl::deviceinfo() const
            {
                Exchange::JSONRPC::IBluetoothControl::deviceinfo _value{};
                _value.address = Address;
                _value.type = Type;
                if (Name.IsSet() == true) {
                    _value.name = Name;
                }
                if (Cod.IsSet() == true) {
                    _value.cod = Cod;
                }
                if (Appearance.IsSet() == true) {
                    _value.appearance = Appearance;
                }
                if (Services.IsSet() == true) {
                    _value.services = Services;
                }
                _value.paired = Paired;
                _value.connected = Connected;
                return (_value);
            }

            ~DeviceinfoData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && ((Cod.IsSet() == false) || (Cod.Value() <= 16777215)) && (Paired.IsSet() == true) && (Connected.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("name"), &Name);
                Add(_T("class"), &Cod);
                Add(_T("appearance"), &Appearance);
                Add(_T("services"), &Services);
                Services.SetQuoted(false);
                Add(_T("paired"), &Paired);
                Add(_T("connected"), &Connected);
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Device type
            Core::JSON::String Name; // Device name
            Core::JSON::DecUInt32 Cod; // Class of Device (CoD) value
            Core::JSON::DecUInt16 Appearance; // Appearance value (LE only)
            Core::JSON::String Services; // Array of supported service UUIDs
            Core::JSON::Boolean Paired; // Specifies if the device is currently paired
            Core::JSON::Boolean Connected; // Specifies if the device is currently connected
        }; // class DeviceinfoData

        class DeviceStateChangedParamsData : public Core::JSON::Container {
        public:
            DeviceStateChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("state"), &State);
                Add(_T("disconnectreason"), &DisconnectReason);
            }

            DeviceStateChangedParamsData(const DeviceStateChangedParamsData&) = delete;
            DeviceStateChangedParamsData(DeviceStateChangedParamsData&&) noexcept  = delete;

            DeviceStateChangedParamsData& operator=(const DeviceStateChangedParamsData&) = delete;
            DeviceStateChangedParamsData& operator=(DeviceStateChangedParamsData&&) noexcept  = delete;

            ~DeviceStateChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (State.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // disconnectReason If disconnected specifies the cause of disconnection
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // disconnectReason If disconnected specifies the cause of disconnection
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicestate> State; // disconnectReason If disconnected specifies the cause of disconnection
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::disconnectreason> DisconnectReason; // disconnectReason If disconnected specifies the cause of disconnection
        }; // class DeviceStateChangedParamsData

        class DiscoverableStartedParamsData : public Core::JSON::Container {
        public:
            DiscoverableStartedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
                Add(_T("connectable"), &Connectable);
            }

            DiscoverableStartedParamsData(const DiscoverableStartedParamsData&) = delete;
            DiscoverableStartedParamsData(DiscoverableStartedParamsData&&) noexcept  = delete;

            DiscoverableStartedParamsData& operator=(const DiscoverableStartedParamsData&) = delete;
            DiscoverableStartedParamsData& operator=(DiscoverableStartedParamsData&&) noexcept  = delete;

            ~DiscoverableStartedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Mode.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype> Type; // Reports entering the discoverable state
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode> Mode; // Advertising or inquiry scanning mode
            Core::JSON::Boolean Connectable; // Specifies if LE advertising reports that the device is connectable (LE-only)
        }; // class DiscoverableStartedParamsData

        class GetDeviceInfoResultData : public Core::JSON::Container {
        public:
            GetDeviceInfoResultData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("name"), &Name);
                Add(_T("version"), &Version);
                Add(_T("manufacturer"), &Manufacturer);
                Add(_T("class"), &Cod);
                Add(_T("appearance"), &Appearance);
                Add(_T("services"), &Services);
                Add(_T("paired"), &Paired);
                Add(_T("connected"), &Connected);
            }

            GetDeviceInfoResultData(const GetDeviceInfoResultData&) = delete;
            GetDeviceInfoResultData(GetDeviceInfoResultData&&) noexcept  = delete;

            GetDeviceInfoResultData& operator=(const GetDeviceInfoResultData&) = delete;
            GetDeviceInfoResultData& operator=(GetDeviceInfoResultData&&) noexcept  = delete;

            ~GetDeviceInfoResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && ((Cod.IsSet() == false) || (Cod.Value() <= 16777215)) && (Paired.IsSet() == true) && (Connected.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Retrieves detailed information about a known Bluetooth device
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Retrieves detailed information about a known Bluetooth device
            Core::JSON::String Name; // Device local name
            Core::JSON::DecUInt8 Version; // Device version
            Core::JSON::DecUInt16 Manufacturer; // Company Identification Code (CIC)
            Core::JSON::DecUInt32 Cod; // Class of Device (CoD) value
            Core::JSON::DecUInt16 Appearance; // Appearance value (LE-only)
            Core::JSON::ArrayType<Core::JSON::String> Services; // A list of supported service UUIDs
            Core::JSON::Boolean Paired; // Specifies if the device is currently paired
            Core::JSON::Boolean Connected; // Specifies if the device is currently connected
        }; // class GetDeviceInfoResultData

        class DeviceData : public Core::JSON::Container {
        public:
            DeviceData()
                : Core::JSON::Container()
            {
                _Init();
            }

            DeviceData(const DeviceData& _other)
                : Core::JSON::Container()
                , Address(_other.Address)
                , Type(_other.Type)
                , Name(_other.Name)
            {
                _Init();
            }

            DeviceData(DeviceData&& _other) noexcept
                : Core::JSON::Container()
                , Address(std::move(_other.Address))
                , Type(std::move(_other.Type))
                , Name(std::move(_other.Name))
            {
                _Init();
            }

            DeviceData(const Exchange::JSONRPC::IBluetoothControl::device& _other)
                : Core::JSON::Container()
            {
                Address = _other.address;
                Type = _other.type;
                Name = _other.name;
                _Init();
            }

            DeviceData& operator=(const DeviceData& _rhs)
            {
                Address = _rhs.Address;
                Type = _rhs.Type;
                Name = _rhs.Name;
                return (*this);
            }

            DeviceData& operator=(DeviceData&& _rhs) noexcept
            {
                Address = std::move(_rhs.Address);
                Type = std::move(_rhs.Type);
                Name = std::move(_rhs.Name);
                return (*this);
            }

            DeviceData& operator=(const Exchange::JSONRPC::IBluetoothControl::device& _rhs)
            {
                Address = _rhs.address;
                Type = _rhs.type;
                Name = _rhs.name;
                return (*this);
            }

            operator Exchange::JSONRPC::IBluetoothControl::device() const
            {
                Exchange::JSONRPC::IBluetoothControl::device _value{};
                _value.address = Address;
                _value.type = Type;
                _value.name = Name;
                return (_value);
            }

            ~DeviceData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (Name.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("name"), &Name);
            }

        public:
            Core::JSON::String Address; // Bluetooth address
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Bluetooth device type
            Core::JSON::String Name; // Bluetooth short name
        }; // class DeviceData

        class PairParamsData : public Core::JSON::Container {
        public:
            PairParamsData()
                : Core::JSON::Container()
                , Capabilities(Exchange::JSONRPC::IBluetoothControl::pairingcapabilities::NO_INPUT_NO_OUTPUT)
                , Timeout(10)
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
                return ((Address.IsSet() == true) && (Type.IsSet() == true));
            }

        public:
            Core::JSON::String Address; // Pairs a Bluetooth device
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Pairs a Bluetooth device
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::pairingcapabilities> Capabilities; // Host device pairing capabilities
            Core::JSON::DecUInt16 Timeout; // Time allowed for the pairing process to complete
        }; // class PairParamsData

        class PasskeyConfirmRequestParamsData : public Core::JSON::Container {
        public:
            PasskeyConfirmRequestParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("secret"), &Secret);
            }

            PasskeyConfirmRequestParamsData(const PasskeyConfirmRequestParamsData&) = delete;
            PasskeyConfirmRequestParamsData(PasskeyConfirmRequestParamsData&&) noexcept  = delete;

            PasskeyConfirmRequestParamsData& operator=(const PasskeyConfirmRequestParamsData&) = delete;
            PasskeyConfirmRequestParamsData& operator=(PasskeyConfirmRequestParamsData&&) noexcept  = delete;

            ~PasskeyConfirmRequestParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && ((Secret.IsSet() == false) || (Secret.Value() <= 999999)));
            }

        public:
            Core::JSON::String Address; // Notifies of a user confirmation request during authenticated BR/EDR SSP pairing process
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Notifies of a user confirmation request during authenticated BR/EDR SSP pairing process
            Core::JSON::DecUInt32 Secret; // A six-digit decimal number sent by the remote device to be presented to the end-user for confirmation on the local device (e.g 123456). The passkey may be omitted for simple yes/no paring.
        }; // class PasskeyConfirmRequestParamsData

        class ProvidePINCodeParamsData : public Core::JSON::Container {
        public:
            ProvidePINCodeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("secret"), &Secret);
            }

            ProvidePINCodeParamsData(const ProvidePINCodeParamsData&) = delete;
            ProvidePINCodeParamsData(ProvidePINCodeParamsData&&) noexcept  = delete;

            ProvidePINCodeParamsData& operator=(const ProvidePINCodeParamsData&) = delete;
            ProvidePINCodeParamsData& operator=(ProvidePINCodeParamsData&&) noexcept  = delete;

            ~ProvidePINCodeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (Type.IsSet() == true) && (((Secret.IsSet() == true) && (Secret.Value().size() <= 16))));
            }

        public:
            Core::JSON::String Address; // Provides a PIN-code for authentication during a legacy pairing process
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype> Type; // Provides a PIN-code for authentication during a legacy pairing process
            Core::JSON::String Secret; // A PIN code, typically 4 ASCII digits
        }; // class ProvidePINCodeParamsData

        class ScanParamsData : public Core::JSON::Container {
        public:
            ScanParamsData()
                : Core::JSON::Container()
                , Mode(Exchange::JSONRPC::IBluetoothControl::scanmode::GENERAL)
                , Duration(12)
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
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
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype> Type; // Starts LE active discovery or BR/EDR inquiry of nearby Bluetooth devices
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode> Mode; // Discovery or inquiry mode (scan picks up only devices discoverable in paricular mode)
            Core::JSON::DecUInt16 Duration; // Time span of the discovery in seconds
        }; // class ScanParamsData

        class ScanStartedParamsData : public Core::JSON::Container {
        public:
            ScanStartedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
            }

            ScanStartedParamsData(const ScanStartedParamsData&) = delete;
            ScanStartedParamsData(ScanStartedParamsData&&) noexcept  = delete;

            ScanStartedParamsData& operator=(const ScanStartedParamsData&) = delete;
            ScanStartedParamsData& operator=(ScanStartedParamsData&&) noexcept  = delete;

            ~ScanStartedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Type.IsSet() == true) && (Mode.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype> Type; // Reports start of scanning
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode> Mode; // Discovery or inquiry mode
        }; // class ScanStartedParamsData

        class SetDiscoverableParamsData : public Core::JSON::Container {
        public:
            SetDiscoverableParamsData()
                : Core::JSON::Container()
                , Mode(Exchange::JSONRPC::IBluetoothControl::scanmode::GENERAL)
                , Connectable(true)
                , Duration(30)
            {
                Add(_T("type"), &Type);
                Add(_T("mode"), &Mode);
                Add(_T("connectable"), &Connectable);
                Add(_T("duration"), &Duration);
            }

            SetDiscoverableParamsData(const SetDiscoverableParamsData&) = delete;
            SetDiscoverableParamsData(SetDiscoverableParamsData&&) noexcept  = delete;

            SetDiscoverableParamsData& operator=(const SetDiscoverableParamsData&) = delete;
            SetDiscoverableParamsData& operator=(SetDiscoverableParamsData&&) noexcept  = delete;

            ~SetDiscoverableParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype> Type; // Starts LE advertising or BR/EDR inquiry scanning, making the local interface visible for nearby Bluetooth devices
            Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode> Mode; // Advertising or inquiry scanning mode
            Core::JSON::Boolean Connectable; // Specifies if LE advertising should report the device is connectable (LE-only)
            Core::JSON::DecUInt16 Duration; // Time span of the discoverable state in seconds
        }; // class SetDiscoverableParamsData

    } // namespace BluetoothControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IBluetoothControl::scantype)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IBluetoothControl::scanmode)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IBluetoothControl::devicetype)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IBluetoothControl::pairingcapabilities)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IBluetoothControl::adaptertype)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IBluetoothControl::devicestate)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IBluetoothControl::disconnectreason)

}

