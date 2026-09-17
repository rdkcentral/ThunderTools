// C++ types for NetworkControl API.
// Generated automatically from 'INetworkControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/INetworkControl.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace NetworkControl {

        // Common classes
        //

        class NetworkInfoInfo : public Core::JSON::Container {
        public:
            NetworkInfoInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            NetworkInfoInfo(const NetworkInfoInfo& _other)
                : Core::JSON::Container()
                , Address(_other.Address)
                , DefaultGateway(_other.DefaultGateway)
                , Mask(_other.Mask)
                , Mode(_other.Mode)
            {
                _Init();
            }

            NetworkInfoInfo(NetworkInfoInfo&& _other) noexcept
                : Core::JSON::Container()
                , Address(std::move(_other.Address))
                , DefaultGateway(std::move(_other.DefaultGateway))
                , Mask(std::move(_other.Mask))
                , Mode(std::move(_other.Mode))
            {
                _Init();
            }

            NetworkInfoInfo(const Exchange::INetworkControl::NetworkInfo& _other)
                : Core::JSON::Container()
            {
                Address = _other.address;
                DefaultGateway = _other.defaultGateway;
                Mask = _other.mask;
                Mode = _other.mode;
                _Init();
            }

            NetworkInfoInfo& operator=(const NetworkInfoInfo& _rhs)
            {
                Address = _rhs.Address;
                DefaultGateway = _rhs.DefaultGateway;
                Mask = _rhs.Mask;
                Mode = _rhs.Mode;
                return (*this);
            }

            NetworkInfoInfo& operator=(NetworkInfoInfo&& _rhs) noexcept
            {
                Address = std::move(_rhs.Address);
                DefaultGateway = std::move(_rhs.DefaultGateway);
                Mask = std::move(_rhs.Mask);
                Mode = std::move(_rhs.Mode);
                return (*this);
            }

            NetworkInfoInfo& operator=(const Exchange::INetworkControl::NetworkInfo& _rhs)
            {
                Address = _rhs.address;
                DefaultGateway = _rhs.defaultGateway;
                Mask = _rhs.mask;
                Mode = _rhs.mode;
                return (*this);
            }

            operator Exchange::INetworkControl::NetworkInfo() const
            {
                Exchange::INetworkControl::NetworkInfo _value{};
                _value.address = Address;
                _value.defaultGateway = DefaultGateway;
                _value.mask = Mask;
                _value.mode = Mode;
                return (_value);
            }

            ~NetworkInfoInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Address.IsSet() == true) && (DefaultGateway.IsSet() == true) && (Mask.IsSet() == true) && (Mode.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("address"), &Address);
                Add(_T("defaultgateway"), &DefaultGateway);
                Add(_T("mask"), &Mask);
                Add(_T("mode"), &Mode);
            }

        public:
            Core::JSON::String Address; // IP Address
            Core::JSON::String DefaultGateway; // Default Gateway
            Core::JSON::DecUInt8 Mask; // Network mask
            Core::JSON::EnumType<Exchange::INetworkControl::ModeType> Mode; // Mode of interface activation Dynamic or Static
        }; // class NetworkInfoInfo

        // Method params/result classes
        //

        class DNSData : public Core::JSON::Container {
        public:
            DNSData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            DNSData(const DNSData&) = delete;
            DNSData(DNSData&&) noexcept  = delete;

            DNSData& operator=(const DNSData&) = delete;
            DNSData& operator=(DNSData&&) noexcept  = delete;

            ~DNSData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::ArrayType<Core::JSON::String> Value; // DNS list
        }; // class DNSData

        class FlushParamsData : public Core::JSON::Container {
        public:
            FlushParamsData()
                : Core::JSON::Container()
            {
                Add(_T("interface"), &Interface);
            }

            FlushParamsData(const FlushParamsData&) = delete;
            FlushParamsData(FlushParamsData&&) noexcept  = delete;

            FlushParamsData& operator=(const FlushParamsData&) = delete;
            FlushParamsData& operator=(FlushParamsData&&) noexcept  = delete;

            ~FlushParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Interface.IsSet() == true);
            }

        public:
            Core::JSON::String Interface; // Name of the interface to be flushed
        }; // class FlushParamsData

        class NetworkData : public Core::JSON::Container {
        public:
            NetworkData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            NetworkData(const NetworkData&) = delete;
            NetworkData(NetworkData&&) noexcept  = delete;

            NetworkData& operator=(const NetworkData&) = delete;
            NetworkData& operator=(NetworkData&&) noexcept  = delete;

            ~NetworkData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::ArrayType<NetworkInfoInfo> Value; // Network info of requested interface
        }; // class NetworkData

        class UpData : public Core::JSON::Container {
        public:
            UpData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            UpData(const UpData&) = delete;
            UpData(UpData&&) noexcept  = delete;

            UpData& operator=(const UpData&) = delete;
            UpData& operator=(UpData&&) noexcept  = delete;

            ~UpData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Value; // Provides given requested interface is up or not
        }; // class UpData

        class UpdateParamsData : public Core::JSON::Container {
        public:
            UpdateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("interfacename"), &InterfaceName);
            }

            UpdateParamsData(const UpdateParamsData&) = delete;
            UpdateParamsData(UpdateParamsData&&) noexcept  = delete;

            UpdateParamsData& operator=(const UpdateParamsData&) = delete;
            UpdateParamsData& operator=(UpdateParamsData&&) noexcept  = delete;

            ~UpdateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (InterfaceName.IsSet() == true);
            }

        public:
            Core::JSON::String InterfaceName; // Name of the interface where an update occured
        }; // class UpdateParamsData

    } // namespace NetworkControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::INetworkControl::StatusType)
ENUM_CONVERSION_HANDLER(Exchange::INetworkControl::ModeType)

}

