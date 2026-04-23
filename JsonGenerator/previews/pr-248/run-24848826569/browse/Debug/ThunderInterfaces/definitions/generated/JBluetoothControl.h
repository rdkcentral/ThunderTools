// Generated automatically from 'IBluetooth.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BluetoothControl.h"
#include <interfaces/IBluetooth.h>

namespace Thunder {

namespace Exchange {

    namespace JSONRPC {

        namespace JBluetoothControl {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            struct IHandler {
                virtual ~IHandler() = default;
                virtual void OnDiscoverableStartedEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
                virtual void OnScanStartedEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
                virtual void OnDeviceStateChangedEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
            };

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IBluetoothControl* _implementation__, IHandler* _handler_)
            {
                ASSERT(_implementation__ != nullptr);
                ASSERT(_handler_ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JBluetoothControl"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'setdiscoverable' - Starts LE advertising or BR/EDR inquiry scanning, making the local interface visible for nearby Bluetooth devices
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::SetDiscoverableParamsData, void>(_T("setdiscoverable"),
                    [_implementation__](const JsonData::BluetoothControl::SetDiscoverableParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const Exchange::JSONRPC::IBluetoothControl::scantype _type_{params.Type};
                            const Core::OptionalType<Exchange::JSONRPC::IBluetoothControl::scanmode> _mode_{params.Mode};
                            const Core::OptionalType<bool> _connectable_{params.Connectable};
                            const Core::OptionalType<uint16_t> _duration_{params.Duration};

                            _errorCode__ = _implementation__->SetDiscoverable(_type_, _mode_, _connectable_, _duration_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'stopdiscoverable' - Stops LE advertising or BR/EDR inquiry scanning operation
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::StopDiscoverableParamsInfo, void>(_T("stopdiscoverable"),
                    [_implementation__](const JsonData::BluetoothControl::StopDiscoverableParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const Exchange::JSONRPC::IBluetoothControl::scantype _type_{params.Type};

                            _errorCode__ = _implementation__->StopDiscoverable(_type_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'scan' - Starts LE active discovery or BR/EDR inquiry of nearby Bluetooth devices
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ScanParamsData, void>(_T("scan"),
                    [_implementation__](const JsonData::BluetoothControl::ScanParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const Exchange::JSONRPC::IBluetoothControl::scantype _type_{params.Type};
                            const Core::OptionalType<Exchange::JSONRPC::IBluetoothControl::scanmode> _mode_{params.Mode};
                            const Core::OptionalType<uint16_t> _duration_{params.Duration};

                            _errorCode__ = _implementation__->Scan(_type_, _mode_, _duration_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'stopscanning' - Stops LE discovery or BR/EDR inquiry operation
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::StopDiscoverableParamsInfo, void>(_T("stopscanning"),
                    [_implementation__](const JsonData::BluetoothControl::StopDiscoverableParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const Exchange::JSONRPC::IBluetoothControl::scantype _type_{params.Type};

                            _errorCode__ = _implementation__->StopScanning(_type_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'connect' - Connects to a Bluetooth device
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("connect"),
                    [_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};

                            _errorCode__ = _implementation__->Connect(_address_, _type_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'disconnect' - Disconnects from a connected Bluetooth device
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("disconnect"),
                    [_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};

                            _errorCode__ = _implementation__->Disconnect(_address_, _type_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'pair' - Pairs a Bluetooth device
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::PairParamsData, void>(_T("pair"),
                    [_implementation__](const JsonData::BluetoothControl::PairParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};
                            const Core::OptionalType<Exchange::JSONRPC::IBluetoothControl::pairingcapabilities> _capabilities_{params.Capabilities};
                            const Core::OptionalType<uint16_t> _timeout_{params.Timeout};

                            _errorCode__ = _implementation__->Pair(_address_, _type_, _capabilities_, _timeout_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'unpair' - Unpairs a paired Bluetooth device
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("unpair"),
                    [_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};

                            _errorCode__ = _implementation__->Unpair(_address_, _type_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'abortpairing' - Aborts pairing operation
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("abortpairing"),
                    [_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};

                            _errorCode__ = _implementation__->AbortPairing(_address_, _type_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'providepincode' - Provides a PIN-code for authentication during a legacy pairing process
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ProvidePINCodeParamsData, void>(_T("providepincode"),
                    [_implementation__](const JsonData::BluetoothControl::ProvidePINCodeParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};
                            const string _secret_{params.Secret};

                            _errorCode__ = _implementation__->ProvidePINCode(_address_, _type_, _secret_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'confirmpasskey' - Confirms a passkey for authentication during a BR/EDR SSP pairing processs
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ConfirmPasskeyParamsData, void>(_T("confirmpasskey"),
                    [_implementation__](const JsonData::BluetoothControl::ConfirmPasskeyParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};
                            const bool _accept_{params.Accept};

                            _errorCode__ = _implementation__->ConfirmPasskey(_address_, _type_, _accept_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'providepasskey' - Provides a passkey for authentication during a pairing process
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ProvidePasskeyParamsInfo, void>(_T("providepasskey"),
                    [_implementation__](const JsonData::BluetoothControl::ProvidePasskeyParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};
                            const uint32_t _secret_{params.Secret};

                            _errorCode__ = _implementation__->ProvidePasskey(_address_, _type_, _secret_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'forget' - Forgets a previously seen Bluetooth device
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("forget"),
                    [_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};
                            const Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};

                            _errorCode__ = _implementation__->Forget(_address_, _type_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'getdevicelist' - Retrieves a list of known remote Bluetooth devices
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::BluetoothControl::DeviceData>>(_T("getdevicelist"),
                    [_implementation__](Core::JSON::ArrayType<JsonData::BluetoothControl::DeviceData>& devices) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<IBluetoothControl::device, 0>* _devices_{};

                        _errorCode__ = _implementation__->GetDeviceList(_devices_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            devices.Set(true);

                            if (_devices_ != nullptr) {
                                Exchange::JSONRPC::IBluetoothControl::device _resultItem__{};
                                while (_devices_->Next(_resultItem__) == true) { devices.Add() = _resultItem__; }
                                _devices_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

                // Method: 'getdeviceinfo' - Retrieves detailed information about a known Bluetooth device
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothControl::ConnectParamsInfo, JsonData::BluetoothControl::GetDeviceInfoResultData>(_T("getdeviceinfo"),
                    [_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params, JsonData::BluetoothControl::GetDeviceInfoResultData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            string _address_{params.Address};
                            Exchange::JSONRPC::IBluetoothControl::devicetype _type_{params.Type};
                            Core::OptionalType<string> _name_{};
                            Core::OptionalType<uint8_t> _version_{};
                            Core::OptionalType<uint16_t> _manufacturer_{};
                            Core::OptionalType<uint32_t> _cod_{};
                            Core::OptionalType<uint16_t> _appearance_{};
                            Core::OptionalType<::Thunder::RPC::IIteratorType<string, 0>*> _services_{};
                            bool _paired_{};
                            bool _connected_{};

                            _errorCode__ = _implementation__->GetDeviceInfo(_address_, _type_, _name_, _version_, _manufacturer_, _cod_, _appearance_, _services_, _paired_, _connected_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Address = _address_;
                                result.Type = _type_;
                                result.Name = _name_;
                                result.Version = _version_;
                                result.Manufacturer = _manufacturer_;
                                result.Cod = _cod_;
                                result.Appearance = _appearance_;

                                if ((_services_.IsSet() == true) && (_services_.Value() != nullptr)) {
                                    string _servicesItem__{};
                                    while (_services_.Value()->Next(_servicesItem__) == true) { result.Services.Add() = _servicesItem__; }
                                    _services_.Value()->Release();
                                }
                                result.Paired = _paired_;
                                result.Connected = _connected_;
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'adapters' - List of local Bluetooth adapters (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::DecUInt8>>(_T("adapters"),
                    [_implementation__](Core::JSON::ArrayType<Core::JSON::DecUInt8>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<uint8_t, 0>* _result_{};

                        _errorCode__ = _implementation__->Adapters(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                uint8_t _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

                // Indexed Property: 'adapter' - Local Bluetooth adapter information (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothControl::AdapterinfoData, std::function<uint32_t(const string&, JsonData::BluetoothControl::AdapterinfoData&)>>(_T("adapter"),
                    [_implementation__](const string& adapter, JsonData::BluetoothControl::AdapterinfoData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        uint8_t _adapterConv__{};

                        if (adapter.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const bool _adapterConvResult__ = Core::FromString(adapter, _adapterConv__);

                            if (_adapterConvResult__ == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            Exchange::JSONRPC::IBluetoothControl::adapterinfo _result_{};

                            _errorCode__ = _implementation__->Adapter(_adapterConv__, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Set(true);
                                result = _result_;
                            }
                        }

                        return (_errorCode__);
                    });

                // Property: 'devices' - List of known remote Bluetooth LE devices (DEPRECATED) (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("devices"),
                    [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<string, 0>* _result_{};

                        _errorCode__ = _implementation__->Devices(_result_);

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

                // Indexed Property: 'device' - Remote Bluetooth LE device information (DEPRECATED) (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothControl::DeviceinfoData, std::function<uint32_t(const string&, JsonData::BluetoothControl::DeviceinfoData&)>>(_T("device"),
                    [_implementation__](const string& deviceAddress, JsonData::BluetoothControl::DeviceinfoData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (deviceAddress.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            Exchange::JSONRPC::IBluetoothControl::deviceinfo _result_{};

                            _errorCode__ = _implementation__->Device(deviceAddress, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Set(true);
                                result = _result_;
                            }
                        }

                        return (_errorCode__);
                    });

                // Register event status listeners...

                _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("discoverablestarted"),
                    [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                        _handler_->OnDiscoverableStartedEventRegistration(client_, status_);
                    });

                _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("scanstarted"),
                    [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                        _handler_->OnScanStartedEventRegistration(client_, status_);
                    });

                _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("devicestatechanged"),
                    [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                        _handler_->OnDeviceStateChangedEventRegistration(client_, status_);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("setdiscoverable"));
                _module__.PluginHost::JSONRPC::Unregister(_T("stopdiscoverable"));
                _module__.PluginHost::JSONRPC::Unregister(_T("scan"));
                _module__.PluginHost::JSONRPC::Unregister(_T("stopscanning"));
                _module__.PluginHost::JSONRPC::Unregister(_T("connect"));
                _module__.PluginHost::JSONRPC::Unregister(_T("disconnect"));
                _module__.PluginHost::JSONRPC::Unregister(_T("pair"));
                _module__.PluginHost::JSONRPC::Unregister(_T("unpair"));
                _module__.PluginHost::JSONRPC::Unregister(_T("abortpairing"));
                _module__.PluginHost::JSONRPC::Unregister(_T("providepincode"));
                _module__.PluginHost::JSONRPC::Unregister(_T("confirmpasskey"));
                _module__.PluginHost::JSONRPC::Unregister(_T("providepasskey"));
                _module__.PluginHost::JSONRPC::Unregister(_T("forget"));
                _module__.PluginHost::JSONRPC::Unregister(_T("getdevicelist"));
                _module__.PluginHost::JSONRPC::Unregister(_T("getdeviceinfo"));
                _module__.PluginHost::JSONRPC::Unregister(_T("adapters"));
                _module__.PluginHost::JSONRPC::Unregister(_T("adapter"));
                _module__.PluginHost::JSONRPC::Unregister(_T("devices"));
                _module__.PluginHost::JSONRPC::Unregister(_T("device"));

                // Unregister event status listeners...
                _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("discoverablestarted"));
                _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("scanstarted"));
                _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("devicestatechanged"));
            }

            namespace Event {

                // Event: 'discoverablestarted' - Reports entering the discoverable state
                template<typename MODULE>
                static void DiscoverableStarted(const MODULE& module_, const JsonData::BluetoothControl::DiscoverableStartedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("discoverablestarted"), params, sendIfMethod_);
                }

                // Event: 'discoverablestarted' - Reports entering the discoverable state
                template<typename MODULE>
                static void DiscoverableStarted(const MODULE& module_, const JsonData::BluetoothControl::DiscoverableStartedParamsData& params, const string& client_)
                {
                    module_.Notify(_T("discoverablestarted"), params, [&client_](const string& designator_) -> bool {
                        return ((client_ == designator_));
                    });
                }

                // Event: 'discoverablestarted' - Reports entering the discoverable state
                template<typename MODULE>
                static void DiscoverableStarted(const MODULE& module_, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype>& type, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode>& mode, const Core::JSON::Boolean& connectable, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::DiscoverableStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;
                    params_.Connectable = connectable;

                    DiscoverableStarted(module_, params_, sendIfMethod_);
                }

                // Event: 'discoverablestarted' - Reports entering the discoverable state
                template<typename MODULE>
                static void DiscoverableStarted(const MODULE& module_, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype>& type, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode>& mode, const Core::JSON::Boolean& connectable, const string& client_)
                {
                    JsonData::BluetoothControl::DiscoverableStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;
                    params_.Connectable = connectable;

                    DiscoverableStarted(module_, params_, client_);
                }

                // Event: 'discoverablestarted' - Reports entering the discoverable state
                template<typename MODULE>
                static void DiscoverableStarted(const MODULE& module_, const IBluetoothControl::scantype type, const IBluetoothControl::scanmode mode, const Core::OptionalType<bool>& connectable, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::DiscoverableStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;

                    if (connectable.IsSet() == true) {
                        params_.Connectable = connectable.Value();
                    }

                    DiscoverableStarted(module_, params_, sendIfMethod_);
                }

                // Event: 'discoverablestarted' - Reports entering the discoverable state
                template<typename MODULE>
                static void DiscoverableStarted(const MODULE& module_, const IBluetoothControl::scantype type, const IBluetoothControl::scanmode mode, const Core::OptionalType<bool>& connectable, const string& client_)
                {
                    JsonData::BluetoothControl::DiscoverableStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;

                    if (connectable.IsSet() == true) {
                        params_.Connectable = connectable.Value();
                    }

                    DiscoverableStarted(module_, params_, client_);
                }

                // Event: 'discoverablecomplete' - Reports leaving the discoverable state
                template<typename MODULE>
                static void DiscoverableComplete(const MODULE& module_, const JsonData::BluetoothControl::StopDiscoverableParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("discoverablecomplete"), params, sendIfMethod_);
                }

                // Event: 'discoverablecomplete' - Reports leaving the discoverable state
                template<typename MODULE>
                static void DiscoverableComplete(const MODULE& module_, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::StopDiscoverableParamsInfo params_;
                    params_.Type = type;

                    DiscoverableComplete(module_, params_, sendIfMethod_);
                }

                // Event: 'discoverablecomplete' - Reports leaving the discoverable state
                template<typename MODULE>
                static void DiscoverableComplete(const MODULE& module_, const IBluetoothControl::scantype type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::StopDiscoverableParamsInfo params_;
                    params_.Type = type;

                    DiscoverableComplete(module_, params_, sendIfMethod_);
                }

                // Event: 'scanstarted' - Reports start of scanning
                template<typename MODULE>
                static void ScanStarted(const MODULE& module_, const JsonData::BluetoothControl::ScanStartedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("scanstarted"), params, sendIfMethod_);
                }

                // Event: 'scanstarted' - Reports start of scanning
                template<typename MODULE>
                static void ScanStarted(const MODULE& module_, const JsonData::BluetoothControl::ScanStartedParamsData& params, const string& client_)
                {
                    module_.Notify(_T("scanstarted"), params, [&client_](const string& designator_) -> bool {
                        return ((client_ == designator_));
                    });
                }

                // Event: 'scanstarted' - Reports start of scanning
                template<typename MODULE>
                static void ScanStarted(const MODULE& module_, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype>& type, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode>& mode, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ScanStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;

                    ScanStarted(module_, params_, sendIfMethod_);
                }

                // Event: 'scanstarted' - Reports start of scanning
                template<typename MODULE>
                static void ScanStarted(const MODULE& module_, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype>& type, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scanmode>& mode, const string& client_)
                {
                    JsonData::BluetoothControl::ScanStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;

                    ScanStarted(module_, params_, client_);
                }

                // Event: 'scanstarted' - Reports start of scanning
                template<typename MODULE>
                static void ScanStarted(const MODULE& module_, const IBluetoothControl::scantype type, const IBluetoothControl::scanmode mode, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ScanStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;

                    ScanStarted(module_, params_, sendIfMethod_);
                }

                // Event: 'scanstarted' - Reports start of scanning
                template<typename MODULE>
                static void ScanStarted(const MODULE& module_, const IBluetoothControl::scantype type, const IBluetoothControl::scanmode mode, const string& client_)
                {
                    JsonData::BluetoothControl::ScanStartedParamsData params_;
                    params_.Type = type;
                    params_.Mode = mode;

                    ScanStarted(module_, params_, client_);
                }

                // Event: 'scancomplete' - Reports end of scanning
                template<typename MODULE>
                static void ScanComplete(const MODULE& module_, const JsonData::BluetoothControl::StopDiscoverableParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("scancomplete"), params, sendIfMethod_);
                }

                // Event: 'scancomplete' - Reports end of scanning
                template<typename MODULE>
                static void ScanComplete(const MODULE& module_, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::scantype>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::StopDiscoverableParamsInfo params_;
                    params_.Type = type;

                    ScanComplete(module_, params_, sendIfMethod_);
                }

                // Event: 'scancomplete' - Reports end of scanning
                template<typename MODULE>
                static void ScanComplete(const MODULE& module_, const IBluetoothControl::scantype type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::StopDiscoverableParamsInfo params_;
                    params_.Type = type;

                    ScanComplete(module_, params_, sendIfMethod_);
                }

                // Event: 'devicestatechanged' - disconnectReason If disconnected specifies the cause of disconnection
                template<typename MODULE>
                static void DeviceStateChanged(const MODULE& module_, const JsonData::BluetoothControl::DeviceStateChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("devicestatechanged"), params, sendIfMethod_);
                }

                // Event: 'devicestatechanged' - disconnectReason If disconnected specifies the cause of disconnection
                template<typename MODULE>
                static void DeviceStateChanged(const MODULE& module_, const JsonData::BluetoothControl::DeviceStateChangedParamsData& params, const string& client_)
                {
                    module_.Notify(_T("devicestatechanged"), params, [&client_](const string& designator_) -> bool {
                        return ((client_ == designator_));
                    });
                }

                // Event: 'devicestatechanged' - disconnectReason If disconnected specifies the cause of disconnection
                template<typename MODULE>
                static void DeviceStateChanged(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype>& type, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicestate>& state, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::disconnectreason>& disconnectReason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::DeviceStateChangedParamsData params_;
                    params_.Address = address;
                    params_.Type = type;
                    params_.State = state;
                    params_.DisconnectReason = disconnectReason;

                    DeviceStateChanged(module_, params_, sendIfMethod_);
                }

                // Event: 'devicestatechanged' - disconnectReason If disconnected specifies the cause of disconnection
                template<typename MODULE>
                static void DeviceStateChanged(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype>& type, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicestate>& state, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::disconnectreason>& disconnectReason, const string& client_)
                {
                    JsonData::BluetoothControl::DeviceStateChangedParamsData params_;
                    params_.Address = address;
                    params_.Type = type;
                    params_.State = state;
                    params_.DisconnectReason = disconnectReason;

                    DeviceStateChanged(module_, params_, client_);
                }

                // Event: 'devicestatechanged' - disconnectReason If disconnected specifies the cause of disconnection
                template<typename MODULE>
                static void DeviceStateChanged(const MODULE& module_, const string& address, const IBluetoothControl::devicetype type, const IBluetoothControl::devicestate state, const Core::OptionalType<IBluetoothControl::disconnectreason>& disconnectReason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::DeviceStateChangedParamsData params_;
                    params_.Address = address;
                    params_.Type = type;
                    params_.State = state;

                    if (disconnectReason.IsSet() == true) {
                        params_.DisconnectReason = disconnectReason.Value();
                    }

                    DeviceStateChanged(module_, params_, sendIfMethod_);
                }

                // Event: 'devicestatechanged' - disconnectReason If disconnected specifies the cause of disconnection
                template<typename MODULE>
                static void DeviceStateChanged(const MODULE& module_, const string& address, const IBluetoothControl::devicetype type, const IBluetoothControl::devicestate state, const Core::OptionalType<IBluetoothControl::disconnectreason>& disconnectReason, const string& client_)
                {
                    JsonData::BluetoothControl::DeviceStateChangedParamsData params_;
                    params_.Address = address;
                    params_.Type = type;
                    params_.State = state;

                    if (disconnectReason.IsSet() == true) {
                        params_.DisconnectReason = disconnectReason.Value();
                    }

                    DeviceStateChanged(module_, params_, client_);
                }

                // Event: 'pincoderequest' - Notifies of a PIN code request during authenticated BR/EDR legacy pairing process
                template<typename MODULE>
                static void PINCodeRequest(const MODULE& module_, const JsonData::BluetoothControl::ConnectParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("pincoderequest"), params, sendIfMethod_);
                }

                // Event: 'pincoderequest' - Notifies of a PIN code request during authenticated BR/EDR legacy pairing process
                template<typename MODULE>
                static void PINCodeRequest(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ConnectParamsInfo params_;
                    params_.Address = address;
                    params_.Type = type;

                    PINCodeRequest(module_, params_, sendIfMethod_);
                }

                // Event: 'pincoderequest' - Notifies of a PIN code request during authenticated BR/EDR legacy pairing process
                template<typename MODULE>
                static void PINCodeRequest(const MODULE& module_, const string& address, const IBluetoothControl::devicetype type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ConnectParamsInfo params_;
                    params_.Address = address;
                    params_.Type = type;

                    PINCodeRequest(module_, params_, sendIfMethod_);
                }

                // Event: 'passkeyconfirmrequest' - Notifies of a user confirmation request during authenticated BR/EDR SSP pairing process
                template<typename MODULE>
                static void PasskeyConfirmRequest(const MODULE& module_, const JsonData::BluetoothControl::PasskeyConfirmRequestParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("passkeyconfirmrequest"), params, sendIfMethod_);
                }

                // Event: 'passkeyconfirmrequest' - Notifies of a user confirmation request during authenticated BR/EDR SSP pairing process
                template<typename MODULE>
                static void PasskeyConfirmRequest(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype>& type, const Core::JSON::DecUInt32& secret, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::PasskeyConfirmRequestParamsData params_;
                    params_.Address = address;
                    params_.Type = type;
                    params_.Secret = secret;

                    PasskeyConfirmRequest(module_, params_, sendIfMethod_);
                }

                // Event: 'passkeyconfirmrequest' - Notifies of a user confirmation request during authenticated BR/EDR SSP pairing process
                template<typename MODULE>
                static void PasskeyConfirmRequest(const MODULE& module_, const string& address, const IBluetoothControl::devicetype type, const Core::OptionalType<uint32_t>& secret, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::PasskeyConfirmRequestParamsData params_;
                    params_.Address = address;
                    params_.Type = type;

                    if (secret.IsSet() == true) {
                        params_.Secret = secret.Value();
                    }

                    PasskeyConfirmRequest(module_, params_, sendIfMethod_);
                }

                // Event: 'passkeyrequest' - Notifies of a passkey supply request during authenticated LE pairing process
                template<typename MODULE>
                static void PasskeyRequest(const MODULE& module_, const JsonData::BluetoothControl::ConnectParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("passkeyrequest"), params, sendIfMethod_);
                }

                // Event: 'passkeyrequest' - Notifies of a passkey supply request during authenticated LE pairing process
                template<typename MODULE>
                static void PasskeyRequest(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ConnectParamsInfo params_;
                    params_.Address = address;
                    params_.Type = type;

                    PasskeyRequest(module_, params_, sendIfMethod_);
                }

                // Event: 'passkeyrequest' - Notifies of a passkey supply request during authenticated LE pairing process
                template<typename MODULE>
                static void PasskeyRequest(const MODULE& module_, const string& address, const IBluetoothControl::devicetype type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ConnectParamsInfo params_;
                    params_.Address = address;
                    params_.Type = type;

                    PasskeyRequest(module_, params_, sendIfMethod_);
                }

                // Event: 'passkeydisplayrequest' - Notifies of a passkey presentation request during authenticated LE pairing process
                template<typename MODULE>
                static void PasskeyDisplayRequest(const MODULE& module_, const JsonData::BluetoothControl::ProvidePasskeyParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("passkeydisplayrequest"), params, sendIfMethod_);
                }

                // Event: 'passkeydisplayrequest' - Notifies of a passkey presentation request during authenticated LE pairing process
                template<typename MODULE>
                static void PasskeyDisplayRequest(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::JSONRPC::IBluetoothControl::devicetype>& type, const Core::JSON::DecUInt32& secret, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ProvidePasskeyParamsInfo params_;
                    params_.Address = address;
                    params_.Type = type;
                    params_.Secret = secret;

                    PasskeyDisplayRequest(module_, params_, sendIfMethod_);
                }

                // Event: 'passkeydisplayrequest' - Notifies of a passkey presentation request during authenticated LE pairing process
                template<typename MODULE>
                static void PasskeyDisplayRequest(const MODULE& module_, const string& address, const IBluetoothControl::devicetype type, const uint32_t secret, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothControl::ProvidePasskeyParamsInfo params_;
                    params_.Address = address;
                    params_.Type = type;
                    params_.Secret = secret;

                    PasskeyDisplayRequest(module_, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JBluetoothControl

    } // namespace JSONRPC

} // namespace Exchange

} // namespace Thunder

