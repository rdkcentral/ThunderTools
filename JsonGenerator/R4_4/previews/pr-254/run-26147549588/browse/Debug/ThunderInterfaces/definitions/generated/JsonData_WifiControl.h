// C++ types for WifiControl API.
// Generated automatically from 'IWifiControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IWifiControl.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            ConfigInfoInfo(const ConfigInfoInfo& _other)
                : Core::JSON::Container()
                , Hidden(_other.Hidden)
                , Accesspoint(_other.Accesspoint)
                , Ssid(_other.Ssid)
                , Secret(_other.Secret)
                , Identity(_other.Identity)
                , Method(_other.Method)
                , Key(_other.Key)
            {
                _Init();
            }

            ConfigInfoInfo(ConfigInfoInfo&& _other) noexcept
                : Core::JSON::Container()
                , Hidden(std::move(_other.Hidden))
                , Accesspoint(std::move(_other.Accesspoint))
                , Ssid(std::move(_other.Ssid))
                , Secret(std::move(_other.Secret))
                , Identity(std::move(_other.Identity))
                , Method(std::move(_other.Method))
                , Key(std::move(_other.Key))
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

            ConfigInfoInfo& operator=(const ConfigInfoInfo& _rhs)
            {
                Hidden = _rhs.Hidden;
                Accesspoint = _rhs.Accesspoint;
                Ssid = _rhs.Ssid;
                Secret = _rhs.Secret;
                Identity = _rhs.Identity;
                Method = _rhs.Method;
                Key = _rhs.Key;
                return (*this);
            }

            ConfigInfoInfo& operator=(ConfigInfoInfo&& _rhs) noexcept
            {
                Hidden = std::move(_rhs.Hidden);
                Accesspoint = std::move(_rhs.Accesspoint);
                Ssid = std::move(_rhs.Ssid);
                Secret = std::move(_rhs.Secret);
                Identity = std::move(_rhs.Identity);
                Method = std::move(_rhs.Method);
                Key = std::move(_rhs.Key);
                return (*this);
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

            ~ConfigInfoInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Hidden.IsSet() == true) && (Accesspoint.IsSet() == true) && (Ssid.IsSet() == true) && (Secret.IsSet() == true) && (Identity.IsSet() == true) && (Method.IsSet() == true) && (Key.IsSet() == true));
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

            ConnectParamsInfo(const ConnectParamsInfo&) = delete;
            ConnectParamsInfo(ConnectParamsInfo&&) noexcept  = delete;

            ConnectParamsInfo& operator=(const ConnectParamsInfo&) = delete;
            ConnectParamsInfo& operator=(ConnectParamsInfo&&) noexcept  = delete;

            ~ConnectParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (ConfigSSID.IsSet() == true);
            }

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

            ConfigData(const ConfigData&) = delete;
            ConfigData(ConfigData&&) noexcept  = delete;

            ConfigData& operator=(const ConfigData&) = delete;
            ConfigData& operator=(ConfigData&&) noexcept  = delete;

            ~ConfigData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Value.IsSet() == true) && (Value.IsDataValid() == true));
            }

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

            ConnectionChangeParamsData(const ConnectionChangeParamsData&) = delete;
            ConnectionChangeParamsData(ConnectionChangeParamsData&&) noexcept  = delete;

            ConnectionChangeParamsData& operator=(const ConnectionChangeParamsData&) = delete;
            ConnectionChangeParamsData& operator=(ConnectionChangeParamsData&&) noexcept  = delete;

            ~ConnectionChangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Ssid.IsSet() == true);
            }

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

            NetworkInfoData(NetworkInfoData&& _other) noexcept
                : Core::JSON::Container()
                , Ssid(std::move(_other.Ssid))
                , Bssid(std::move(_other.Bssid))
                , Frequency(std::move(_other.Frequency))
                , Signal(std::move(_other.Signal))
                , Security(std::move(_other.Security))
            {
                _Init();
            }

            NetworkInfoData(const Exchange::IWifiControl::NetworkInfo& _other)
                : Core::JSON::Container()
            {
                Ssid = _other.ssid;
                Bssid = _other.bssid;
                Frequency = _other.frequency;
                Signal = _other.signal;
                Security.Set(true);
                Security = _other.security;
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

            NetworkInfoData& operator=(NetworkInfoData&& _rhs) noexcept
            {
                Ssid = std::move(_rhs.Ssid);
                Bssid = std::move(_rhs.Bssid);
                Frequency = std::move(_rhs.Frequency);
                Signal = std::move(_rhs.Signal);
                Security = std::move(_rhs.Security);
                return (*this);
            }

            NetworkInfoData& operator=(const Exchange::IWifiControl::NetworkInfo& _rhs)
            {
                Ssid = _rhs.ssid;
                Bssid = _rhs.bssid;
                Frequency = _rhs.frequency;
                Signal = _rhs.signal;
                Security.Set(true);
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

            ~NetworkInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Ssid.IsSet() == true) && (Bssid.IsSet() == true) && (Frequency.IsSet() == true) && (Signal.IsSet() == true) && (Security.IsSet() == true));
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

            SecurityInfoData(SecurityInfoData&& _other) noexcept
                : Core::JSON::Container()
                , Method(std::move(_other.Method))
                , Keys(std::move(_other.Keys))
            {
                _Init();
            }

            SecurityInfoData(const Exchange::IWifiControl::SecurityInfo& _other)
                : Core::JSON::Container()
            {
                Method = _other.method;
                Keys.Set(true);
                Keys = _other.keys;
                _Init();
            }

            SecurityInfoData& operator=(const SecurityInfoData& _rhs)
            {
                Method = _rhs.Method;
                Keys = _rhs.Keys;
                return (*this);
            }

            SecurityInfoData& operator=(SecurityInfoData&& _rhs) noexcept
            {
                Method = std::move(_rhs.Method);
                Keys = std::move(_rhs.Keys);
                return (*this);
            }

            SecurityInfoData& operator=(const Exchange::IWifiControl::SecurityInfo& _rhs)
            {
                Method = _rhs.method;
                Keys.Set(true);
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

            ~SecurityInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Method.IsSet() == true) && (Keys.IsSet() == true));
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

            StatusResultData(const StatusResultData&) = delete;
            StatusResultData(StatusResultData&&) noexcept  = delete;

            StatusResultData& operator=(const StatusResultData&) = delete;
            StatusResultData& operator=(StatusResultData&&) noexcept  = delete;

            ~StatusResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((ConnectedSsid.IsSet() == true) && (IsScanning.IsSet() == true));
            }

        public:
            Core::JSON::String ConnectedSsid; // Status of current device, like which SSID is connected and it is in scanning state or not
            Core::JSON::Boolean IsScanning; // Status of current device, like which SSID is connected and it is in scanning state or not
        }; // class StatusResultData

    } // namespace WifiControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWifiControl::Security)
ENUM_CONVERSION_HANDLER(Exchange::IWifiControl::SecurityInfo::Key)

}

