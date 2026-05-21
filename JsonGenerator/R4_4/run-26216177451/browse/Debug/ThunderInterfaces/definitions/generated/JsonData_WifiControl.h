// C++ classes for WifiControl API JSON-RPC API.
// Generated automatically from 'IWifiControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IWifiControl.h>

namespace WPEFramework {

namespace JsonData {

    namespace WifiControl {

        // Common classes
        //

        class ConfigInfoInfo : public Core::JSON::Container {
        public:
            ConfigInfoInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            ConfigInfoInfo(const Exchange::IWifiControl::ConfigInfo& _other)
                : Core::JSON::Container()
            {
                Hidden = _other.hidden;
                Accesspoint = _other.accesspoint;
                Ssid = _other.ssid;
                Secret = _other.secret;
                Identity = _other.identity;
                Method = _other.method;
                Key = _other.key;
                _Init();
            }

            ConfigInfoInfo& operator=(const Exchange::IWifiControl::ConfigInfo& _rhs)
            {
                Hidden = _rhs.hidden;
                Accesspoint = _rhs.accesspoint;
                Ssid = _rhs.ssid;
                Secret = _rhs.secret;
                Identity = _rhs.identity;
                Method = _rhs.method;
                Key = _rhs.key;
                return (*this);
            }

            operator Exchange::IWifiControl::ConfigInfo() const
            {
                Exchange::IWifiControl::ConfigInfo _value{};
                _value.hidden = Hidden;
                _value.accesspoint = Accesspoint;
                _value.ssid = Ssid;
                _value.secret = Secret;
                _value.identity = Identity;
                _value.method = Method;
                _value.key = Key;
                return (_value);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("hidden"), &Hidden);
                Add(_T("accesspoint"), &Accesspoint);
                Add(_T("ssid"), &Ssid);
                Add(_T("secret"), &Secret);
                Add(_T("identity"), &Identity);
                Add(_T("method"), &Method);
                Add(_T("key"), &Key);
            }

        public:
            Core::JSON::Boolean Hidden;
            Core::JSON::Boolean Accesspoint;
            Core::JSON::String Ssid;
            Core::JSON::String Secret;
            Core::JSON::String Identity;
            Core::JSON::EnumType<Exchange::IWifiControl::Security> Method;
            Core::JSON::EnumType<Exchange::IWifiControl::SecurityInfo::Key> Key;
        }; // class ConfigInfoInfo

        class ConnectParamsInfo : public Core::JSON::Container {
        public:
            ConnectParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("configssid"), &ConfigSSID);
            }

            bool IsValid() const
            {
                return (true);
            }

            ConnectParamsInfo(const ConnectParamsInfo&) = delete;
            ConnectParamsInfo& operator=(const ConnectParamsInfo&) = delete;

        public:
            Core::JSON::String ConfigSSID; // Connect device to requested SSID
        }; // class ConnectParamsInfo

        // Method params/result classes
        //

        class ConfigData : public Core::JSON::Container {
        public:
            ConfigData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            bool IsValid() const
            {
                return (true);
            }

            ConfigData(const ConfigData&) = delete;
            ConfigData& operator=(const ConfigData&) = delete;

        public:
            ConfigInfoInfo Value; // Provide config details for requested SSID
        }; // class ConfigData

        class ConnectionChangeParamsData : public Core::JSON::Container {
        public:
            ConnectionChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("ssid"), &Ssid);
            }

            bool IsValid() const
            {
                return (true);
            }

            ConnectionChangeParamsData(const ConnectionChangeParamsData&) = delete;
            ConnectionChangeParamsData& operator=(const ConnectionChangeParamsData&) = delete;

        public:
            Core::JSON::String Ssid; // Notifies that wifi connection changes
        }; // class ConnectionChangeParamsData

        class NetworkInfoData : public Core::JSON::Container {
        public:
            NetworkInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            NetworkInfoData(const NetworkInfoData& _other)
                : Core::JSON::Container()
                , Ssid(_other.Ssid)
                , Bssid(_other.Bssid)
                , Frequency(_other.Frequency)
                , Signal(_other.Signal)
                , Security(_other.Security)
            {
                _Init();
            }

            NetworkInfoData& operator=(const NetworkInfoData& _rhs)
            {
                Ssid = _rhs.Ssid;
                Bssid = _rhs.Bssid;
                Frequency = _rhs.Frequency;
                Signal = _rhs.Signal;
                Security = _rhs.Security;
                return (*this);
            }

            NetworkInfoData(const Exchange::IWifiControl::NetworkInfo& _other)
                : Core::JSON::Container()
            {
                Ssid = _other.ssid;
                Bssid = _other.bssid;
                Frequency = _other.frequency;
                Signal = _other.signal;
                Security = _other.security;
                _Init();
            }

            NetworkInfoData& operator=(const Exchange::IWifiControl::NetworkInfo& _rhs)
            {
                Ssid = _rhs.ssid;
                Bssid = _rhs.bssid;
                Frequency = _rhs.frequency;
                Signal = _rhs.signal;
                Security = _rhs.security;
                return (*this);
            }

            operator Exchange::IWifiControl::NetworkInfo() const
            {
                Exchange::IWifiControl::NetworkInfo _value{};
                _value.ssid = Ssid;
                _value.bssid = Bssid;
                _value.frequency = Frequency;
                _value.signal = Signal;
                _value.security = Security;
                return (_value);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("ssid"), &Ssid);
                Add(_T("bssid"), &Bssid);
                Add(_T("frequency"), &Frequency);
                Add(_T("signal"), &Signal);
                Add(_T("security"), &Security);
            }

        public:
            Core::JSON::String Ssid;
            Core::JSON::DecUInt64 Bssid;
            Core::JSON::DecUInt32 Frequency;
            Core::JSON::DecSInt32 Signal;
            Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IWifiControl::Security>> Security;
        }; // class NetworkInfoData

        class SecurityInfoData : public Core::JSON::Container {
        public:
            SecurityInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            SecurityInfoData(const SecurityInfoData& _other)
                : Core::JSON::Container()
                , Method(_other.Method)
                , Keys(_other.Keys)
            {
                _Init();
            }

            SecurityInfoData& operator=(const SecurityInfoData& _rhs)
            {
                Method = _rhs.Method;
                Keys = _rhs.Keys;
                return (*this);
            }

            SecurityInfoData(const Exchange::IWifiControl::SecurityInfo& _other)
                : Core::JSON::Container()
            {
                Method = _other.method;
                Keys = _other.keys;
                _Init();
            }

            SecurityInfoData& operator=(const Exchange::IWifiControl::SecurityInfo& _rhs)
            {
                Method = _rhs.method;
                Keys = _rhs.keys;
                return (*this);
            }

            operator Exchange::IWifiControl::SecurityInfo() const
            {
                Exchange::IWifiControl::SecurityInfo _value{};
                _value.method = Method;
                _value.keys = Keys;
                return (_value);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("method"), &Method);
                Add(_T("keys"), &Keys);
            }

        public:
            Core::JSON::EnumType<Exchange::IWifiControl::Security> Method;
            Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IWifiControl::SecurityInfo::Key>> Keys;
        }; // class SecurityInfoData

        class StatusResultData : public Core::JSON::Container {
        public:
            StatusResultData()
                : Core::JSON::Container()
            {
                Add(_T("connectedssid"), &ConnectedSsid);
                Add(_T("isscanning"), &IsScanning);
            }

            bool IsValid() const
            {
                return (true);
            }

            StatusResultData(const StatusResultData&) = delete;
            StatusResultData& operator=(const StatusResultData&) = delete;

        public:
            Core::JSON::String ConnectedSsid; // Status of current device, like which SSID is connected and it is in scanning state or not
            Core::JSON::Boolean IsScanning; // Status of current device, like which SSID is connected and it is in scanning state or not
        }; // class StatusResultData

    } // namespace WifiControl

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWifiControl::Security)
ENUM_CONVERSION_HANDLER(Exchange::IWifiControl::SecurityInfo::Key)

}

