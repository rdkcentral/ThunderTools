// C++ classes for NetworkControl API JSON-RPC API.
// Generated automatically from 'INetworkControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/INetworkControl.h>

namespace WPEFramework {

namespace JsonData {

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

            NetworkInfoInfo& operator=(const NetworkInfoInfo& _rhs)
            {
                Address = _rhs.Address;
                DefaultGateway = _rhs.DefaultGateway;
                Mask = _rhs.Mask;
                Mode = _rhs.Mode;
                return (*this);
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

            bool IsValid() const
            {
                return (true);
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
            Core::JSON::String Address;
            Core::JSON::String DefaultGateway;
            Core::JSON::DecUInt8 Mask;
            Core::JSON::EnumType<Exchange::INetworkControl::ModeType> Mode;
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

            bool IsValid() const
            {
                return (true);
            }

            DNSData(const DNSData&) = delete;
            DNSData& operator=(const DNSData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            FlushParamsData(const FlushParamsData&) = delete;
            FlushParamsData& operator=(const FlushParamsData&) = delete;

        public:
            Core::JSON::String Interface; // Flush and reload requested interface
        }; // class FlushParamsData

        class NetworkData : public Core::JSON::Container {
        public:
            NetworkData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            bool IsValid() const
            {
                return (true);
            }

            NetworkData(const NetworkData&) = delete;
            NetworkData& operator=(const NetworkData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            UpData(const UpData&) = delete;
            UpData& operator=(const UpData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            UpdateParamsData(const UpdateParamsData&) = delete;
            UpdateParamsData& operator=(const UpdateParamsData&) = delete;

        public:
            Core::JSON::String InterfaceName;
        }; // class UpdateParamsData

    } // namespace NetworkControl

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::INetworkControl::StatusType)
ENUM_CONVERSION_HANDLER(Exchange::INetworkControl::ModeType)

}

