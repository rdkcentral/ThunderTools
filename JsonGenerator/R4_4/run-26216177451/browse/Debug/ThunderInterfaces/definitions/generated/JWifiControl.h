// Generated automatically from 'IWifiControl.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_WifiControl.h"
#include <interfaces/IWifiControl.h>

namespace WPEFramework {

namespace Exchange {

    namespace JWifiControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IWifiControl* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JWifiControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'scan' - Trigger Scanning
            _module_.Register<void, void>(_T("scan"), 
                [_impl_]() -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    _errorCode = _impl_->Scan();

                    return (_errorCode);
                });

            // Method: 'abortscan' - Abort Currentlt running scan
            _module_.Register<void, void>(_T("abortscan"), 
                [_impl_]() -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    _errorCode = _impl_->AbortScan();

                    return (_errorCode);
                });

            // Method: 'connect' - Connect device to requested SSID
            _module_.Register<JsonData::WifiControl::ConnectParamsInfo, void>(_T("connect"), 
                [_impl_](const JsonData::WifiControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _configSSID{params.ConfigSSID};

                    _errorCode = _impl_->Connect(_configSSID);

                    return (_errorCode);
                });

            // Method: 'disconnect' - Disconnect device from requested SSID
            _module_.Register<JsonData::WifiControl::ConnectParamsInfo, void>(_T("disconnect"), 
                [_impl_](const JsonData::WifiControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _configSSID{params.ConfigSSID};

                    _errorCode = _impl_->Disconnect(_configSSID);

                    return (_errorCode);
                });

            // Method: 'status' - Status of current device, like which SSID is connected and it is in scanning state or not
            _module_.Register<void, JsonData::WifiControl::StatusResultData>(_T("status"), 
                [_impl_](JsonData::WifiControl::StatusResultData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    string _connectedSsid{};
                    bool _isScanning{};

                    _errorCode = _impl_->Status(_connectedSsid, _isScanning);

                    if (_errorCode == Core::ERROR_NONE) {
                        result.ConnectedSsid = _connectedSsid;
                        result.IsScanning = _isScanning;
                    }

                    return (_errorCode);
                });

            // Property: 'networks' - Provides available networks information (r/o)
            _module_.Register<void, Core::JSON::ArrayType<JsonData::WifiControl::NetworkInfoData>>(_T("networks"), 
                [_impl_](Core::JSON::ArrayType<JsonData::WifiControl::NetworkInfoData>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IWifiControl::NetworkInfo, ID_WIFICONTROL_NETWORK_INFO_ITERATOR>* _result{};

                    _errorCode = _impl_->Networks(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IWifiControl::NetworkInfo _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Indexed Property: 'securities' - Provides security method of requested SSID (r/o)
            _module_.Register<void, Core::JSON::ArrayType<JsonData::WifiControl::SecurityInfoData>, std::function<uint32_t(const string&,
                     Core::JSON::ArrayType<JsonData::WifiControl::SecurityInfoData>&)>>(_T("securities"), 
                [_impl_](const string& _index_, Core::JSON::ArrayType<JsonData::WifiControl::SecurityInfoData>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IWifiControl::SecurityInfo, ID_WIFICONTROL_SECURITY_INFO_ITERATOR>* _result{};

                    _errorCode = _impl_->Securities(_index_, _result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IWifiControl::SecurityInfo _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Property: 'configs' - Provides configs list (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("configs"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result{};

                    _errorCode = _impl_->Configs(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            string _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Indexed Property: 'config' - Provide config details for requested SSID
            _module_.Register<JsonData::WifiControl::ConfigData, JsonData::WifiControl::ConfigInfoInfo, std::function<uint32_t(const string&,
                     const JsonData::WifiControl::ConfigData&, JsonData::WifiControl::ConfigInfoInfo&)>>(_T("config"), 
                [_impl_](const string& _index_, const JsonData::WifiControl::ConfigData& params, JsonData::WifiControl::ConfigInfoInfo& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        Exchange::IWifiControl::ConfigInfo _result{};

                        _errorCode = (static_cast<const IWifiControl*>(_impl_))->Config(_index_, _result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const Exchange::IWifiControl::ConfigInfo _value(params.Value);

                        _errorCode = _impl_->Config(_index_, _value);

                        // result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("scan"));
            _module_.Unregister(_T("abortscan"));
            _module_.Unregister(_T("connect"));
            _module_.Unregister(_T("disconnect"));
            _module_.Unregister(_T("status"));
            _module_.Unregister(_T("networks"));
            _module_.Unregister(_T("securities"));
            _module_.Unregister(_T("configs"));
            _module_.Unregister(_T("config"));
        }

        namespace Event {

            // Event: 'networkchange' - Notifies that Network were added, removed or modified
            static void NetworkChange(const JSONRPC& _module_)
            {
                _module_.Notify(_T("networkchange"));
            }

            // Event: 'connectionchange' - Notifies that wifi connection changes
            static void ConnectionChange(const JSONRPC& _module_, const JsonData::WifiControl::ConnectionChangeParamsData& params)
            {
                _module_.Notify(_T("connectionchange"), params);
            }

            // Event: 'connectionchange' - Notifies that wifi connection changes
            static void ConnectionChange(const JSONRPC& _module_, const Core::JSON::String& ssid)
            {
                JsonData::WifiControl::ConnectionChangeParamsData _params_;
                _params_.Ssid = ssid;

                ConnectionChange(_module_, _params_);
            }

            // Event: 'connectionchange' - Notifies that wifi connection changes
            static void ConnectionChange(const JSONRPC& _module_, const string& ssid)
            {
                JsonData::WifiControl::ConnectionChangeParamsData _params_;
                _params_.Ssid = ssid;

                ConnectionChange(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JWifiControl

} // namespace Exchange

} // namespace WPEFramework

