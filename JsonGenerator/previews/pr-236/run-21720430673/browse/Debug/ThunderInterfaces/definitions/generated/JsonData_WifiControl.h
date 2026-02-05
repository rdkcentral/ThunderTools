// C++ types for WifiControl API.
// Generated automatically from 'IWifiControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IWifiControl.h>

namespace Thunder {

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
                if (_other.ssid.IsSet() == true) {
                    Ssid = _other.ssid.Value();
                }
                if (_other.secret.IsSet() == true) {
                    Secret = _other.secret.Value();
                }
                if (_other.identity.IsSet() == true) {
                    Identity = _other.identity.Value();
                }
                Method = _other.method;
                if (_other.key.IsSet() == true) {
                    Key = _other.key.Value();
                }
                _Init();
            }

            ConfigInfoInfo& operator=(const ConfigInfoInfo& _rhs)
            {
                Hidden = _rhs.Hidden;
                Accesspoint = _rhs.Accesspoint;
                if (_rhs.Ssid.IsSet() == true) {
                    Ssid = _rhs.Ssid;
                }
                if (_rhs.Secret.IsSet() == true) {
                    Secret = _rhs.Secret;
                }
                if (_rhs.Identity.IsSet() == true) {
                    Identity = _rhs.Identity;
                }
                Method = _rhs.Method;
                if (_rhs.Key.IsSet() == true) {
                    Key = _rhs.Key;
                }
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
                if (_rhs.ssid.IsSet() == true) {
                    Ssid = _rhs.ssid.Value();
                }
                if (_rhs.secret.IsSet() == true) {
                    Secret = _rhs.secret.Value();
                }
                if (_rhs.identity.IsSet() == true) {
                    Identity = _rhs.identity.Value();
                }
                Method = _rhs.method;
                if (_rhs.key.IsSet() == true) {
                    Key = _rhs.key.Value();
                }
                return (*this);
            }

            operator Exchange::IWifiControl::ConfigInfo() const
            {
                Exchange::IWifiControl::ConfigInfo _value{};
                _value.hidden = Hidden;
                _value.accesspoint = Accesspoint;
                if (Ssid.IsSet() == true) {
                    _value.ssid = Ssid;
                }
                if (Secret.IsSet() == true) {
                    _value.secret = Secret;
                }
                if (Identity.IsSet() == true) {
                    _value.identity = Identity;
                }
                _value.method = Method;
                if (Key.IsSet() == true) {
                    _value.key = Key;
                }
                return (_value);
            }

            ~ConfigInfoInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Hidden.IsSet() == true) && (Accesspoint.IsSet() == true) && (Method.IsSet() == true));
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
            Core::JSON::Boolean Hidden; // Visibility of the router (hidden or visible)
            Core::JSON::Boolean Accesspoint; // Accesspoint or not
            Core::JSON::String Ssid; // SSID of the router/ap
            Core::JSON::String Secret; // Secret key used
            Core::JSON::String Identity; // Identity
            Core::JSON::EnumType<Exchange::IWifiControl::Security> Method; // Security method
            Core::JSON::EnumType<Exchange::IWifiControl::SecurityInfo::Key> Key; // Security Info: method and keys
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
            Core::JSON::String ConfigSSID; // SSID to be connected
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
            Core::JSON::String Ssid; // SSID of connection changed network
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
                if (_other.ssid.IsSet() == true) {
                    Ssid = _other.ssid.Value();
                }
                Bssid = _other.bssid;
                Frequency = _other.frequency;
                Signal = _other.signal;
                Security.Set(true);
                Security = _other.security;
                _Init();
            }

            NetworkInfoData& operator=(const NetworkInfoData& _rhs)
            {
                if (_rhs.Ssid.IsSet() == true) {
                    Ssid = _rhs.Ssid;
                }
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
                if (_rhs.ssid.IsSet() == true) {
                    Ssid = _rhs.ssid.Value();
                }
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
                if (Ssid.IsSet() == true) {
                    _value.ssid = Ssid;
                }
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
                return ((Bssid.IsSet() == true) && (Frequency.IsSet() == true) && (Signal.IsSet() == true) && (Security.IsSet() == true));
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
            Core::JSON::String Ssid; // SSID of the network
            Core::JSON::DecUInt64 Bssid; // BSSID of the network
            Core::JSON::DecUInt32 Frequency; // Frequency used
            Core::JSON::DecSInt32 Signal; // Signal strength
            Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IWifiControl::Security>> Security; // Security method
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
                if (_other.keys.IsSet() == true) {
                    Keys.Set(true);
                    Keys = _other.keys.Value();
                }
                _Init();
            }

            SecurityInfoData& operator=(const SecurityInfoData& _rhs)
            {
                Method = _rhs.Method;
                if (_rhs.Keys.IsSet() == true) {
                    Keys = _rhs.Keys;
                }
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
                if (_rhs.keys.IsSet() == true) {
                    Keys.Set(true);
                    Keys = _rhs.keys.Value();
                }
                return (*this);
            }

            operator Exchange::IWifiControl::SecurityInfo() const
            {
                Exchange::IWifiControl::SecurityInfo _value{};
                _value.method = Method;
                if (Keys.IsSet() == true) {
                    _value.keys = Keys;
                }
                return (_value);
            }

            ~SecurityInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return (Method.IsSet() == true);
            }

        private:
            void _Init()
            {
                Add(_T("method"), &Method);
                Add(_T("keys"), &Keys);
            }

        public:
            Core::JSON::EnumType<Exchange::IWifiControl::Security> Method; // Security method
            Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IWifiControl::SecurityInfo::Key>> Keys; // Security Keys
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
            Core::JSON::String ConnectedSsid; // SSID of connected router/ap
            Core::JSON::Boolean IsScanning; // Scanning is in progress or not
        }; // class StatusResultData

    } // namespace WifiControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWifiControl::Security)
ENUM_CONVERSION_HANDLER(Exchange::IWifiControl::SecurityInfo::Key)

}

