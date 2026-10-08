// Generated automatically from 'IWifiControl.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_WifiControl.h"
#include <interfaces/IWifiControl.h>

namespace Thunder {

namespace Exchange {

    namespace JWifiControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IWifiControl* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JWifiControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'scan' - Trigger Scanning
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("scan"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->Scan();

                    return (_errorCode__);
                });

            // Method: 'abortscan' - Abort Currentlt running scan
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("abortscan"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->AbortScan();

                    return (_errorCode__);
                });

            // Method: 'connect' - Connect device to requested SSID
            _module__.PluginHost::JSONRPC::template Register<JsonData::WifiControl::ConnectParamsInfo, void>(_T("connect"),
                [_implementation__](const JsonData::WifiControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _configSSID_{params.ConfigSSID};

                        _errorCode__ = _implementation__->Connect(_configSSID_);

                    }

                    return (_errorCode__);
                });

            // Method: 'disconnect' - Disconnect device from requested SSID
            _module__.PluginHost::JSONRPC::template Register<JsonData::WifiControl::ConnectParamsInfo, void>(_T("disconnect"),
                [_implementation__](const JsonData::WifiControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _configSSID_{params.ConfigSSID};

                        _errorCode__ = _implementation__->Disconnect(_configSSID_);

                    }

                    return (_errorCode__);
                });

            // Method: 'status' - Status of current device, like which SSID is connected and it is in scanning state or not
            _module__.PluginHost::JSONRPC::template Register<void, JsonData::WifiControl::StatusResultData>(_T("status"),
                [_implementation__](JsonData::WifiControl::StatusResultData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _connectedSsid_{};
                    bool _isScanning_{};

                    _errorCode__ = _implementation__->Status(_connectedSsid_, _isScanning_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.ConnectedSsid = _connectedSsid_;
                        result.IsScanning = _isScanning_;
                    }

                    return (_errorCode__);
                });

            // Property: 'networks' - Provides available networks information (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::WifiControl::NetworkInfoData>>(_T("networks"),
                [_implementation__](Core::JSON::ArrayType<JsonData::WifiControl::NetworkInfoData>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<IWifiControl::NetworkInfo, ID_WIFICONTROL_NETWORK_INFO_ITERATOR>* _result_{};

                    _errorCode__ = _implementation__->Networks(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IWifiControl::NetworkInfo _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'securities' - Provides security method of requested SSID (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::WifiControl::SecurityInfoData>, std::function<uint32_t(const string&, Core::JSON::ArrayType<JsonData::WifiControl::SecurityInfoData>&)>>(_T("securities"),
                [_implementation__](const string& ssid, Core::JSON::ArrayType<JsonData::WifiControl::SecurityInfoData>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (ssid.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        ::Thunder::RPC::IIteratorType<IWifiControl::SecurityInfo, ID_WIFICONTROL_SECURITY_INFO_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Securities(ssid, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::IWifiControl::SecurityInfo _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'configs' - Provides configs list (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("configs"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result_{};

                    _errorCode__ = _implementation__->Configs(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            string _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'config' - Provide config details for requested SSID
            _module__.PluginHost::JSONRPC::template Register<JsonData::WifiControl::ConfigData, JsonData::WifiControl::ConfigInfoInfo, std::function<uint32_t(const string&, const JsonData::WifiControl::ConfigData&, JsonData::WifiControl::ConfigInfoInfo&)>>(_T("config"),
                [_implementation__](const string& ssid, const JsonData::WifiControl::ConfigData& params, JsonData::WifiControl::ConfigInfoInfo& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (ssid.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            Exchange::IWifiControl::ConfigInfo _result_{};

                            _errorCode__ = (static_cast<const IWifiControl*>(_implementation__))->Config(ssid, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Set(true);
                                result = _result_;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                const Exchange::IWifiControl::ConfigInfo _value_(params.Value);

                                _errorCode__ = _implementation__->Config(ssid, _value_);

                            }

                            result.Null(true);
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("scan"));
            _module__.PluginHost::JSONRPC::Unregister(_T("abortscan"));
            _module__.PluginHost::JSONRPC::Unregister(_T("connect"));
            _module__.PluginHost::JSONRPC::Unregister(_T("disconnect"));
            _module__.PluginHost::JSONRPC::Unregister(_T("status"));
            _module__.PluginHost::JSONRPC::Unregister(_T("networks"));
            _module__.PluginHost::JSONRPC::Unregister(_T("securities"));
            _module__.PluginHost::JSONRPC::Unregister(_T("configs"));
            _module__.PluginHost::JSONRPC::Unregister(_T("config"));
        }

        namespace Event {

            // Event: 'networkchange' - Notifies that Network were added, removed or modified
            template<typename MODULE>
            static void NetworkChange(const MODULE& module_, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("networkchange"), sendIfMethod_);
            }

            // Event: 'connectionchange' - Notifies that wifi connection changes
            template<typename MODULE>
            static void ConnectionChange(const MODULE& module_, const JsonData::WifiControl::ConnectionChangeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("connectionchange"), params, sendIfMethod_);
            }

            // Event: 'connectionchange' - Notifies that wifi connection changes
            template<typename MODULE>
            static void ConnectionChange(const MODULE& module_, const Core::JSON::String& ssid, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WifiControl::ConnectionChangeParamsData params_;
                params_.Ssid = ssid;

                ConnectionChange(module_, params_, sendIfMethod_);
            }

            // Event: 'connectionchange' - Notifies that wifi connection changes
            template<typename MODULE>
            static void ConnectionChange(const MODULE& module_, const string& ssid, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WifiControl::ConnectionChangeParamsData params_;
                params_.Ssid = ssid;

                ConnectionChange(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JWifiControl

} // namespace Exchange

} // namespace Thunder

