// Generated automatically from 'BluetoothControl.json'. DO NOT EDIT.

#pragma once

#if _IMPLEMENTATION_STUB
// sample implementation class
class JSONRPCImplementation {
public:
    uint32_t SetDiscoverable(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const Core::JSON::Boolean& connectable, const Core::JSON::DecUInt16& duration) { return (Core::ERROR_NONE); }
    uint32_t StopDiscoverable(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type) { return (Core::ERROR_NONE); }
    uint32_t Scan(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const Core::JSON::DecUInt16& timeout, const Core::JSON::DecUInt16& duration) { return (Core::ERROR_NONE); }
    uint32_t StopScanning(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type) { return (Core::ERROR_NONE); }
    uint32_t Connect(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t Disconnect(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t Pair(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::pairingcapabilities>& capabilities, const Core::JSON::DecUInt16& timeout) { return (Core::ERROR_NONE); }
    uint32_t Unpair(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t AbortPairing(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t ProvidePINCode(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::String& secret) { return (Core::ERROR_NONE); }
    uint32_t ProvidePasskey(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::DecUInt32& secret) { return (Core::ERROR_NONE); }
    uint32_t ConfirmPasskey(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::Boolean& iscorrect) { return (Core::ERROR_NONE); }
    uint32_t Forget(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t GetDeviceList(Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>& result) { return (Core::ERROR_NONE); }
    uint32_t GetDeviceInfo(Core::JSON::String& address, Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, Core::JSON::String& name, Core::JSON::DecUInt32& class_, Core::JSON::DecUInt32& appearance, Core::JSON::ArrayType<Core::JSON::String>& services, Core::JSON::Boolean& connected, Core::JSON::Boolean& paired) { return (Core::ERROR_NONE); }
    uint32_t Adapters(Core::JSON::ArrayType<Core::JSON::DecUInt16>& result) const { return (Core::ERROR_NONE); }
    uint32_t Adapter(const string& index, Core::JSON::DecUInt16& id, Core::JSON::String& address, Core::JSON::String& interface, Core::JSON::EnumType<JsonData::BluetoothControl::AdapterData::adaptertype>& type, Core::JSON::DecUInt8& version, Core::JSON::DecUInt16& manufacturer, Core::JSON::DecUInt32& class_, Core::JSON::String& name, Core::JSON::String& shortname) const { return (Core::ERROR_NONE); }
    uint32_t Devices(Core::JSON::ArrayType<Core::JSON::String>& result) const { return (Core::ERROR_NONE); }
    uint32_t Device(const string& index, Core::JSON::String& address, Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, Core::JSON::String& name, Core::JSON::DecUInt32& class_, Core::JSON::DecUInt32& appearance, Core::JSON::ArrayType<Core::JSON::String>& services, Core::JSON::Boolean& connected, Core::JSON::Boolean& paired) const { return (Core::ERROR_NONE); }
    void OnDiscoverableStartedEventRegistration(const string& client, const string& index, const PluginHost::JSONRPCSupportsEventStatus::Status status) { }
    void OnScanStartedEventRegistration(const string& client, const string& index, const PluginHost::JSONRPCSupportsEventStatus::Status status) { }
    void OnDeviceStateChangedEventRegistration(const string& client, const string& index, const PluginHost::JSONRPCSupportsEventStatus::Status status) { }
}; // class JSONRPCImplementation
#endif // _IMPLEMENTATION_STUB

#include "Module.h"
#include "JsonData_BluetoothControl.h"

namespace WPEFramework {

namespace Exchange {

    namespace JBluetoothControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        using JSONRPC = PluginHost::JSONRPCSupportsEventStatus;

        template<typename IMPLEMENTATION>
        static void Register(JSONRPC& _module__, IMPLEMENTATION& _implementation__)
        {

            // Register methods and properties...

            // Method: 'setdiscoverable' - Starts advertising (or inquiry scanning), making the local interface visible by nearby Bluetooth devices
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::SetdiscoverableParamsData, void>(_T("setdiscoverable"),
                [&_implementation__](const JsonData::BluetoothControl::SetdiscoverableParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("setdiscoverable")));
                    }

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type_{params.Type};
                    const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& _mode_{params.Mode};
                    const Core::JSON::Boolean& _connectable_{params.Connectable};
                    const Core::JSON::DecUInt16& _duration_{params.Duration};
                    _errorCode__ = _implementation__.SetDiscoverable(_type_, _mode_, _connectable_, _duration_);

                    return (_errorCode__);
                });

            // Method: 'stopdiscoverable' - Stops advertising (or inquiry scanning) operation
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::StopdiscoverableParamsInfo, void>(_T("stopdiscoverable"),
                [&_implementation__](const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("stopdiscoverable")));
                    }

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type_{params.Type};
                    _errorCode__ = _implementation__.StopDiscoverable(_type_);

                    return (_errorCode__);
                });

            // Method: 'scan' - Starts active discovery (or inquiry) of nearby Bluetooth devices
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ScanParamsData, void>(_T("scan"),
                [&_implementation__](const JsonData::BluetoothControl::ScanParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("scan")));
                    }

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type_{params.Type};
                    const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& _mode_{params.Mode};
                    const Core::JSON::DecUInt16& _timeout_{params.Timeout};
                    const Core::JSON::DecUInt16& _duration_{params.Duration};
                    _errorCode__ = _implementation__.Scan(_type_, _mode_, _timeout_, _duration_);

                    return (_errorCode__);
                });

            // Method: 'stopscanning' - Stops discovery (or inquiry) operation
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::StopdiscoverableParamsInfo, void>(_T("stopscanning"),
                [&_implementation__](const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == true) && (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("stopscanning")));
                    }

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type_{params.Type};
                    _errorCode__ = _implementation__.StopScanning(_type_);

                    return (_errorCode__);
                });

            // Method: 'connect' - Connects to a Bluetooth device
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("connect"),
                [&_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("connect")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    _errorCode__ = _implementation__.Connect(_address_, _type_);

                    return (_errorCode__);
                });

            // Method: 'disconnect' - Disconnects from a connected Bluetooth device
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("disconnect"),
                [&_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("disconnect")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    _errorCode__ = _implementation__.Disconnect(_address_, _type_);

                    return (_errorCode__);
                });

            // Method: 'pair' - Pairs a Bluetooth device
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::PairParamsData, void>(_T("pair"),
                [&_implementation__](const JsonData::BluetoothControl::PairParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("pair")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::pairingcapabilities>& _capabilities_{params.Capabilities};
                    const Core::JSON::DecUInt16& _timeout_{params.Timeout};
                    _errorCode__ = _implementation__.Pair(_address_, _type_, _capabilities_, _timeout_);

                    return (_errorCode__);
                });

            // Method: 'unpair' - Unpairs a paired Bluetooth device
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("unpair"),
                [&_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("unpair")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    _errorCode__ = _implementation__.Unpair(_address_, _type_);

                    return (_errorCode__);
                });

            // Method: 'abortpairing' - Aborts pairing operation
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("abortpairing"),
                [&_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("abortpairing")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    _errorCode__ = _implementation__.AbortPairing(_address_, _type_);

                    return (_errorCode__);
                });

            // Method: 'providepincode' - Provides a PIN-code for authentication during a legacy pairing process
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ProvidepincodeParamsData, void>(_T("providepincode"),
                [&_implementation__](const JsonData::BluetoothControl::ProvidepincodeParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("providepincode")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    const Core::JSON::String& _secret_{params.Secret};
                    _errorCode__ = _implementation__.ProvidePINCode(_address_, _type_, _secret_);

                    return (_errorCode__);
                });

            // Method: 'providepasskey' - Provides a passkey for authentication during a pairing process
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ProvidepasskeyParamsData, void>(_T("providepasskey"),
                [&_implementation__](const JsonData::BluetoothControl::ProvidepasskeyParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("providepasskey")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    const Core::JSON::DecUInt32& _secret_{params.Secret};
                    _errorCode__ = _implementation__.ProvidePasskey(_address_, _type_, _secret_);

                    return (_errorCode__);
                });

            // Method: 'confirmpasskey' - Confirms a passkey for authentication during a pairing process
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ConfirmpasskeyParamsData, void>(_T("confirmpasskey"),
                [&_implementation__](const JsonData::BluetoothControl::ConfirmpasskeyParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("confirmpasskey")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    const Core::JSON::Boolean& _iscorrect_{params.Iscorrect};
                    _errorCode__ = _implementation__.ConfirmPasskey(_address_, _type_, _iscorrect_);

                    return (_errorCode__);
                });

            // Method: 'forget' - Forgets a known Bluetooth device
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("forget"),
                [&_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("forget")));
                    }

                    const Core::JSON::String& _address_{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{params.Type};
                    _errorCode__ = _implementation__.Forget(_address_, _type_);

                    return (_errorCode__);
                });

            // Method: 'getdevicelist' - Retrieves a list of known remote Bluetooth devices
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>>(_T("getdevicelist"),
                [&_implementation__](Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>& _result_{result};
                    _errorCode__ = _implementation__.GetDeviceList(_result_);

                    return (_errorCode__);
                });

            // Method: 'getdeviceinfo' - Retrieves detailed information about a known Bluetooth device
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothControl::ConnectParamsInfo, JsonData::BluetoothControl::DeviceData>(_T("getdeviceinfo"),
                [&_implementation__](const JsonData::BluetoothControl::ConnectParamsInfo& params, JsonData::BluetoothControl::DeviceData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBluetoothControl"), _T("getdeviceinfo")));
                    }

                    result.Address = params.Address;
                    Core::JSON::String& _address_{result.Address};
                    result.Type = params.Type;
                    Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{result.Type};
                    Core::JSON::String& _name_{result.Name};
                    Core::JSON::DecUInt32& _class__{result.Class};
                    Core::JSON::DecUInt32& _appearance_{result.Appearance};
                    Core::JSON::ArrayType<Core::JSON::String>& _services_{result.Services};
                    Core::JSON::Boolean& _connected_{result.Connected};
                    Core::JSON::Boolean& _paired_{result.Paired};
                    _errorCode__ = _implementation__.GetDeviceInfo(_address_, _type_, _name_, _class__, _appearance_, _services_, _connected_, _paired_);

                    return (_errorCode__);
                });

            // Property: 'adapters' - List of local Bluetooth adapters (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::ArrayType<Core::JSON::DecUInt16>>(_T("adapters"),
                [&_implementation__](Core::JSON::ArrayType<Core::JSON::DecUInt16>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Core::JSON::ArrayType<Core::JSON::DecUInt16>& _result_{result};
                    _errorCode__ = _implementation__.Adapters(_result_);

                    return (_errorCode__);
                });

            // Indexed Property: 'adapter' - Local Bluetooth adapter information (r/o)
            _module__.PluginHost::JSONRPC::Register<void, JsonData::BluetoothControl::AdapterData, std::function<uint32_t(const string&, JsonData::BluetoothControl::AdapterData&)>>(_T("adapter"),
                [&_implementation__](const string& index, JsonData::BluetoothControl::AdapterData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (index.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        Core::JSON::DecUInt16& _id_{result.Id};
                        Core::JSON::String& _address_{result.Address};
                        Core::JSON::String& _interface_{result.Interface};
                        Core::JSON::EnumType<JsonData::BluetoothControl::AdapterData::adaptertype>& _type_{result.Type};
                        Core::JSON::DecUInt8& _version_{result.Version};
                        Core::JSON::DecUInt16& _manufacturer_{result.Manufacturer};
                        Core::JSON::DecUInt32& _class__{result.Class};
                        Core::JSON::String& _name_{result.Name};
                        Core::JSON::String& _shortname_{result.Shortname};
                        _errorCode__ = _implementation__.Adapter(index, _id_, _address_, _interface_, _type_, _version_, _manufacturer_, _class__, _name_, _shortname_);

                    }

                    return (_errorCode__);
                });

            // Property: 'devices' - List of known remote Bluetooth devices (DEPRECATED) (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("devices"),
                [&_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Core::JSON::ArrayType<Core::JSON::String>& _result_{result};
                    _errorCode__ = _implementation__.Devices(_result_);

                    return (_errorCode__);
                });

            // Indexed Property: 'device' - Remote Bluetooth device information (DEPRECATED) (r/o)
            _module__.PluginHost::JSONRPC::Register<void, JsonData::BluetoothControl::DeviceData, std::function<uint32_t(const string&, JsonData::BluetoothControl::DeviceData&)>>(_T("device"),
                [&_implementation__](const string& index, JsonData::BluetoothControl::DeviceData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (index.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        Core::JSON::String& _address_{result.Address};
                        Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type_{result.Type};
                        Core::JSON::String& _name_{result.Name};
                        Core::JSON::DecUInt32& _class__{result.Class};
                        Core::JSON::DecUInt32& _appearance_{result.Appearance};
                        Core::JSON::ArrayType<Core::JSON::String>& _services_{result.Services};
                        Core::JSON::Boolean& _connected_{result.Connected};
                        Core::JSON::Boolean& _paired_{result.Paired};
                        _errorCode__ = _implementation__.Device(index, _address_, _type_, _name_, _class__, _appearance_, _services_, _connected_, _paired_);

                    }

                    return (_errorCode__);
                });

            // Register event status listeners...

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("discoverablestarted"),
                [&_implementation__](const uint32_t, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    _implementation__.OnDiscoverableStartedEventRegistration(client_, status_);
                });

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("scanstarted"),
                [&_implementation__](const uint32_t, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    _implementation__.OnScanStartedEventRegistration(client_, status_);
                });

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("devicestatechange"),
                [&_implementation__](const uint32_t, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    _implementation__.OnDeviceStateChangedEventRegistration(client_, status_);
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
            _module__.PluginHost::JSONRPC::Unregister(_T("providepasskey"));
            _module__.PluginHost::JSONRPC::Unregister(_T("confirmpasskey"));
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
            _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("devicestatechange"));
        }

        namespace Event {

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            template<typename MODULE>
            static void DiscoverableStarted(const MODULE& module_, const JsonData::BluetoothControl::DiscoverablestartedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("discoverablestarted"), params, sendIfMethod_);
            }

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            template<typename MODULE>
            static void DiscoverableStarted(const MODULE& module_, const JsonData::BluetoothControl::DiscoverablestartedParamsData& params, const string& client_)
            {
                module_.Notify(_T("discoverablestarted"), params, [&client_](const string& designator_) -> bool {
                    return ((client_ == designator_));
                });
            }

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            template<typename MODULE>
            static void DiscoverableStarted(const MODULE& module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const Core::JSON::Boolean& connectable, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::DiscoverablestartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;
                params_.Connectable = connectable;

                DiscoverableStarted(module_, params_, sendIfMethod_);
            }

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            template<typename MODULE>
            static void DiscoverableStarted(const MODULE& module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const Core::JSON::Boolean& connectable, const string& client_)
            {
                JsonData::BluetoothControl::DiscoverablestartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;
                params_.Connectable = connectable;

                DiscoverableStarted(module_, params_, client_);
            }

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            template<typename MODULE>
            static void DiscoverableStarted(const MODULE& module_, JsonData::BluetoothControl::scantype type, JsonData::BluetoothControl::scanmode mode, bool connectable, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::DiscoverablestartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;
                params_.Connectable = connectable;

                DiscoverableStarted(module_, params_, sendIfMethod_);
            }

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            template<typename MODULE>
            static void DiscoverableStarted(const MODULE& module_, JsonData::BluetoothControl::scantype type, JsonData::BluetoothControl::scanmode mode, bool connectable, const string& client_)
            {
                JsonData::BluetoothControl::DiscoverablestartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;
                params_.Connectable = connectable;

                DiscoverableStarted(module_, params_, client_);
            }

            // Event: 'discoverablecomplete' - Notifies of leaving the discoverable state
            template<typename MODULE>
            static void DiscoverableComplete(const MODULE& module_, const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("discoverablecomplete"), params, sendIfMethod_);
            }

            // Event: 'discoverablecomplete' - Notifies of leaving the discoverable state
            template<typename MODULE>
            static void DiscoverableComplete(const MODULE& module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo params_;
                params_.Type = type;

                DiscoverableComplete(module_, params_, sendIfMethod_);
            }

            // Event: 'discoverablecomplete' - Notifies of leaving the discoverable state
            template<typename MODULE>
            static void DiscoverableComplete(const MODULE& module_, JsonData::BluetoothControl::scantype type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo params_;
                params_.Type = type;

                DiscoverableComplete(module_, params_, sendIfMethod_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            template<typename MODULE>
            static void ScanStarted(const MODULE& module_, const JsonData::BluetoothControl::ScanstartedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("scanstarted"), params, sendIfMethod_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            template<typename MODULE>
            static void ScanStarted(const MODULE& module_, const JsonData::BluetoothControl::ScanstartedParamsData& params, const string& client_)
            {
                module_.Notify(_T("scanstarted"), params, [&client_](const string& designator_) -> bool {
                    return ((client_ == designator_));
                });
            }

            // Event: 'scanstarted' - Notifies of scan start
            template<typename MODULE>
            static void ScanStarted(const MODULE& module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::ScanstartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;

                ScanStarted(module_, params_, sendIfMethod_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            template<typename MODULE>
            static void ScanStarted(const MODULE& module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const string& client_)
            {
                JsonData::BluetoothControl::ScanstartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;

                ScanStarted(module_, params_, client_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            template<typename MODULE>
            static void ScanStarted(const MODULE& module_, JsonData::BluetoothControl::scantype type, JsonData::BluetoothControl::scanmode mode, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::ScanstartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;

                ScanStarted(module_, params_, sendIfMethod_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            template<typename MODULE>
            static void ScanStarted(const MODULE& module_, JsonData::BluetoothControl::scantype type, JsonData::BluetoothControl::scanmode mode, const string& client_)
            {
                JsonData::BluetoothControl::ScanstartedParamsData params_;
                params_.Type = type;
                params_.Mode = mode;

                ScanStarted(module_, params_, client_);
            }

            // Event: 'scancomplete' - Notifies of scan completion
            template<typename MODULE>
            static void ScanComplete(const MODULE& module_, const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("scancomplete"), params, sendIfMethod_);
            }

            // Event: 'scancomplete' - Notifies of scan completion
            template<typename MODULE>
            static void ScanComplete(const MODULE& module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo params_;
                params_.Type = type;

                ScanComplete(module_, params_, sendIfMethod_);
            }

            // Event: 'scancomplete' - Notifies of scan completion
            template<typename MODULE>
            static void ScanComplete(const MODULE& module_, JsonData::BluetoothControl::scantype type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo params_;
                params_.Type = type;

                ScanComplete(module_, params_, sendIfMethod_);
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            template<typename MODULE>
            static void DeviceStateChanged(const MODULE& module_, const string& id_, const JsonData::BluetoothControl::DevicestatechangeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                if (sendIfMethod_ == nullptr) {
                    module_.Notify(_T("devicestatechange"), params, [&id_](const string& designator_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        const string index_ = designator_.substr(0, designator_.find('.'));

                        if (index_.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        return ((_errorCode__ == Core::ERROR_NONE) && (id_ == index_));
                    });
                }
                else {
                    module_.Notify(_T("devicestatechange"), params, sendIfMethod_);
                }
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            template<typename MODULE>
            static void DeviceStateChanged(const MODULE& module_, const string& id_, const JsonData::BluetoothControl::DevicestatechangeParamsData& params, const string& client_)
            {
                module_.Notify(_T("devicestatechange"), params, [&id_, &client_](const string& designator_) -> bool {
                    Core::hresult _errorCode__ = Core::ERROR_NONE;
                    const size_t _dot = designator_.find('.');
                    const string index_ = designator_.substr(0, _dot);

                    if (index_.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    return ((_errorCode__ == Core::ERROR_NONE) && ((client_.empty() == true) || (client_ == designator_.substr(_dot + 1))) && (id_ == index_));
                });
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            template<typename MODULE>
            static void DeviceStateChanged(const MODULE& module_, const string& id_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate>& state, const Core::JSON::EnumType<JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason>& disconnectreason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::DevicestatechangeParamsData params_;
                params_.Address = address;
                params_.Type = type;
                params_.State = state;
                params_.Disconnectreason = disconnectreason;

                DeviceStateChanged(module_, id_, params_, sendIfMethod_);
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            template<typename MODULE>
            static void DeviceStateChanged(const MODULE& module_, const string& id_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate>& state, const Core::JSON::EnumType<JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason>& disconnectreason, const string& client_)
            {
                JsonData::BluetoothControl::DevicestatechangeParamsData params_;
                params_.Address = address;
                params_.Type = type;
                params_.State = state;
                params_.Disconnectreason = disconnectreason;

                DeviceStateChanged(module_, id_, params_, client_);
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            template<typename MODULE>
            static void DeviceStateChanged(const MODULE& module_, const string& id_, string address, const IBluetooth::IDevice::type type, JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate state, JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason disconnectreason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::DevicestatechangeParamsData params_;
                params_.Address = address;
                params_.Type = type;
                params_.State = state;
                params_.Disconnectreason = disconnectreason;

                DeviceStateChanged(module_, id_, params_, sendIfMethod_);
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            template<typename MODULE>
            static void DeviceStateChanged(const MODULE& module_, const string& id_, string address, const IBluetooth::IDevice::type type, JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate state, JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason disconnectreason, const string& client_)
            {
                JsonData::BluetoothControl::DevicestatechangeParamsData params_;
                params_.Address = address;
                params_.Type = type;
                params_.State = state;
                params_.Disconnectreason = disconnectreason;

                DeviceStateChanged(module_, id_, params_, client_);
            }

            // Event: 'pincoderequest' - Notifies of a PIN code request
            template<typename MODULE>
            static void PINCodeRequest(const MODULE& module_, const JsonData::BluetoothControl::ConnectParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("pincoderequest"), params, sendIfMethod_);
            }

            // Event: 'pincoderequest' - Notifies of a PIN code request
            template<typename MODULE>
            static void PINCodeRequest(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::ConnectParamsInfo params_;
                params_.Address = address;
                params_.Type = type;

                PINCodeRequest(module_, params_, sendIfMethod_);
            }

            // Event: 'pincoderequest' - Notifies of a PIN code request
            template<typename MODULE>
            static void PINCodeRequest(const MODULE& module_, string address, const IBluetooth::IDevice::type type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::ConnectParamsInfo params_;
                params_.Address = address;
                params_.Type = type;

                PINCodeRequest(module_, params_, sendIfMethod_);
            }

            // Event: 'passkeyrequest' - Notifies of a passkey request
            template<typename MODULE>
            static void PasskeyRequest(const MODULE& module_, const JsonData::BluetoothControl::ConnectParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("passkeyrequest"), params, sendIfMethod_);
            }

            // Event: 'passkeyrequest' - Notifies of a passkey request
            template<typename MODULE>
            static void PasskeyRequest(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::ConnectParamsInfo params_;
                params_.Address = address;
                params_.Type = type;

                PasskeyRequest(module_, params_, sendIfMethod_);
            }

            // Event: 'passkeyrequest' - Notifies of a passkey request
            template<typename MODULE>
            static void PasskeyRequest(const MODULE& module_, string address, const IBluetooth::IDevice::type type, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::ConnectParamsInfo params_;
                params_.Address = address;
                params_.Type = type;

                PasskeyRequest(module_, params_, sendIfMethod_);
            }

            // Event: 'passkeyconfirmrequest' - Notifies of a passkey confirmation request
            template<typename MODULE>
            static void PasskeyConfirmRequest(const MODULE& module_, const JsonData::BluetoothControl::PasskeyconfirmrequestParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("passkeyconfirmrequest"), params, sendIfMethod_);
            }

            // Event: 'passkeyconfirmrequest' - Notifies of a passkey confirmation request
            template<typename MODULE>
            static void PasskeyConfirmRequest(const MODULE& module_, const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::DecUInt32& secret, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::PasskeyconfirmrequestParamsData params_;
                params_.Address = address;
                params_.Type = type;
                params_.Secret = secret;

                PasskeyConfirmRequest(module_, params_, sendIfMethod_);
            }

            // Event: 'passkeyconfirmrequest' - Notifies of a passkey confirmation request
            template<typename MODULE>
            static void PasskeyConfirmRequest(const MODULE& module_, string address, const IBluetooth::IDevice::type type, uint32_t secret, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothControl::PasskeyconfirmrequestParamsData params_;
                params_.Address = address;
                params_.Type = type;
                params_.Secret = secret;

                PasskeyConfirmRequest(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JBluetoothControl

} // namespace Exchange

} // namespace WPEFramework

