// Generated automatically from 'BluetoothControl.json'. DO NOT EDIT.

#pragma once

#if _IMPLEMENTATION_STUB
// sample implementation class
class JSONRPCImplementation {
public:
    uint32_t SetDiscoverable(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type,
             const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const Core::JSON::Boolean& connectable, const Core::JSON::DecUInt16& duration) { return (Core::ERROR_NONE); }
    uint32_t StopDiscoverable(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type) { return (Core::ERROR_NONE); }
    uint32_t Scan(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type,
             const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const Core::JSON::DecUInt16& timeout, const Core::JSON::DecUInt16& duration) { return (Core::ERROR_NONE); }
    uint32_t StopScanning(const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type) { return (Core::ERROR_NONE); }
    uint32_t Connect(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t Disconnect(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t Pair(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type,
             const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::pairingcapabilities>& capabilities, const Core::JSON::DecUInt16& timeout) { return (Core::ERROR_NONE); }
    uint32_t Unpair(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t AbortPairing(const Core::JSON::String& address,
             const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t ProvidePINCode(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type,
             const Core::JSON::String& secret) { return (Core::ERROR_NONE); }
    uint32_t ProvidePasskey(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type,
             const Core::JSON::DecUInt32& secret) { return (Core::ERROR_NONE); }
    uint32_t ConfirmPasskey(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type,
             const Core::JSON::Boolean& iscorrect) { return (Core::ERROR_NONE); }
    uint32_t Forget(const Core::JSON::String& address, const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type) { return (Core::ERROR_NONE); }
    uint32_t GetDeviceList(Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>& result) { return (Core::ERROR_NONE); }
    uint32_t GetDeviceInfo(Core::JSON::String& address, Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, Core::JSON::String& name,
             Core::JSON::DecUInt32& class_, Core::JSON::DecUInt32& appearance, Core::JSON::ArrayType<Core::JSON::String>& services, Core::JSON::Boolean& connected,
             Core::JSON::Boolean& paired) { return (Core::ERROR_NONE); }
    uint32_t Adapters(Core::JSON::ArrayType<Core::JSON::DecUInt16>& result) const { return (Core::ERROR_NONE); }
    uint32_t Adapter(const string& _index_, Core::JSON::DecUInt16& id, Core::JSON::String& address, Core::JSON::String& interface,
             Core::JSON::EnumType<JsonData::BluetoothControl::AdapterData::adaptertype>& type, Core::JSON::DecUInt8& version, Core::JSON::DecUInt16& manufacturer,
             Core::JSON::DecUInt32& class_, Core::JSON::String& name, Core::JSON::String& shortname) const { return (Core::ERROR_NONE); }
    uint32_t Devices(Core::JSON::ArrayType<Core::JSON::String>& result) const { return (Core::ERROR_NONE); }
    uint32_t Device(const string& _index_, Core::JSON::String& address, Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type,
             Core::JSON::String& name, Core::JSON::DecUInt32& class_, Core::JSON::DecUInt32& appearance, Core::JSON::ArrayType<Core::JSON::String>& services,
             Core::JSON::Boolean& connected, Core::JSON::Boolean& paired) const { return (Core::ERROR_NONE); }
    void OnDiscoverableStartedEventRegistration(const string& client, const JBluetoothControl::JSONRPC::Status status) { }
    void OnScanStartedEventRegistration(const string& client, const JBluetoothControl::JSONRPC::Status status) { }
    void OnDeviceStateChangedEventRegistration(const string& client, const JBluetoothControl::JSONRPC::Status status) { }
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

        using JSONRPC = PluginHost::JSONRPCSupportsEventStatus;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        template<typename IMPLEMENTATION>
        static void Register(JSONRPC& _module_, IMPLEMENTATION& _impl_)
        {
            _module_.RegisterVersion(_T("JBluetoothControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'setdiscoverable' - Starts advertising (or inquiry scanning), making the local interface visible by nearby Bluetooth devices
            _module_.Register<JsonData::BluetoothControl::SetdiscoverableParamsData, void>(_T("setdiscoverable"), 
                [&_impl_](const JsonData::BluetoothControl::SetdiscoverableParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type{params.Type};
                    const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& _mode{params.Mode};
                    const Core::JSON::Boolean& _connectable{params.Connectable};
                    const Core::JSON::DecUInt16& _duration{params.Duration};

                    _errorCode = _impl_.SetDiscoverable(_type, _mode, _connectable, _duration);

                    return (_errorCode);
                });

            // Method: 'stopdiscoverable' - Stops advertising (or inquiry scanning) operation
            _module_.Register<JsonData::BluetoothControl::StopdiscoverableParamsInfo, void>(_T("stopdiscoverable"), 
                [&_impl_](const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type{params.Type};

                    _errorCode = _impl_.StopDiscoverable(_type);

                    return (_errorCode);
                });

            // Method: 'scan' - Starts active discovery (or inquiry) of nearby Bluetooth devices
            _module_.Register<JsonData::BluetoothControl::ScanParamsData, void>(_T("scan"), 
                [&_impl_](const JsonData::BluetoothControl::ScanParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type{params.Type};
                    const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& _mode{params.Mode};
                    const Core::JSON::DecUInt16& _timeout{params.Timeout};
                    const Core::JSON::DecUInt16& _duration{params.Duration};

                    _errorCode = _impl_.Scan(_type, _mode, _timeout, _duration);

                    return (_errorCode);
                });

            // Method: 'stopscanning' - Stops discovery (or inquiry) operation
            _module_.Register<JsonData::BluetoothControl::StopdiscoverableParamsInfo, void>(_T("stopscanning"), 
                [&_impl_](const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& _type{params.Type};

                    _errorCode = _impl_.StopScanning(_type);

                    return (_errorCode);
                });

            // Method: 'connect' - Connects to a Bluetooth device
            _module_.Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("connect"), 
                [&_impl_](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};

                    _errorCode = _impl_.Connect(_address, _type);

                    return (_errorCode);
                });

            // Method: 'disconnect' - Disconnects from a connected Bluetooth device
            _module_.Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("disconnect"), 
                [&_impl_](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};

                    _errorCode = _impl_.Disconnect(_address, _type);

                    return (_errorCode);
                });

            // Method: 'pair' - Pairs a Bluetooth device
            _module_.Register<JsonData::BluetoothControl::PairParamsData, void>(_T("pair"), 
                [&_impl_](const JsonData::BluetoothControl::PairParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::pairingcapabilities>& _capabilities{params.Capabilities};
                    const Core::JSON::DecUInt16& _timeout{params.Timeout};

                    _errorCode = _impl_.Pair(_address, _type, _capabilities, _timeout);

                    return (_errorCode);
                });

            // Method: 'unpair' - Unpairs a paired Bluetooth device
            _module_.Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("unpair"), 
                [&_impl_](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};

                    _errorCode = _impl_.Unpair(_address, _type);

                    return (_errorCode);
                });

            // Method: 'abortpairing' - Aborts pairing operation
            _module_.Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("abortpairing"), 
                [&_impl_](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};

                    _errorCode = _impl_.AbortPairing(_address, _type);

                    return (_errorCode);
                });

            // Method: 'providepincode' - Provides a PIN-code for authentication during a legacy pairing process
            _module_.Register<JsonData::BluetoothControl::ProvidepincodeParamsData, void>(_T("providepincode"), 
                [&_impl_](const JsonData::BluetoothControl::ProvidepincodeParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};
                    const Core::JSON::String& _secret{params.Secret};

                    _errorCode = _impl_.ProvidePINCode(_address, _type, _secret);

                    return (_errorCode);
                });

            // Method: 'providepasskey' - Provides a passkey for authentication during a pairing process
            _module_.Register<JsonData::BluetoothControl::ProvidepasskeyParamsData, void>(_T("providepasskey"), 
                [&_impl_](const JsonData::BluetoothControl::ProvidepasskeyParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};
                    const Core::JSON::DecUInt32& _secret{params.Secret};

                    _errorCode = _impl_.ProvidePasskey(_address, _type, _secret);

                    return (_errorCode);
                });

            // Method: 'confirmpasskey' - Confirms a passkey for authentication during a pairing process
            _module_.Register<JsonData::BluetoothControl::ConfirmpasskeyParamsData, void>(_T("confirmpasskey"), 
                [&_impl_](const JsonData::BluetoothControl::ConfirmpasskeyParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};
                    const Core::JSON::Boolean& _iscorrect{params.Iscorrect};

                    _errorCode = _impl_.ConfirmPasskey(_address, _type, _iscorrect);

                    return (_errorCode);
                });

            // Method: 'forget' - Forgets a known Bluetooth device
            _module_.Register<JsonData::BluetoothControl::ConnectParamsInfo, void>(_T("forget"), 
                [&_impl_](const JsonData::BluetoothControl::ConnectParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Core::JSON::String& _address{params.Address};
                    const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{params.Type};

                    _errorCode = _impl_.Forget(_address, _type);

                    return (_errorCode);
                });

            // Method: 'getdevicelist' - Retrieves a list of known remote Bluetooth devices
            _module_.Register<void, Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>>(_T("getdevicelist"), 
                [&_impl_](Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    Core::JSON::ArrayType<JsonData::BluetoothControl::ConnectParamsInfo>& _result{result};

                    _errorCode = _impl_.GetDeviceList(_result);

                    return (_errorCode);
                });

            // Method: 'getdeviceinfo' - Retrieves detailed information about a known Bluetooth device
            _module_.Register<JsonData::BluetoothControl::ConnectParamsInfo, JsonData::BluetoothControl::DeviceData>(_T("getdeviceinfo"), 
                [&_impl_](const JsonData::BluetoothControl::ConnectParamsInfo& params, JsonData::BluetoothControl::DeviceData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    result.Address = params.Address;
                    Core::JSON::String& _address{result.Address};
                    result.Type = params.Type;
                    Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{result.Type};
                    Core::JSON::String& _name{result.Name};
                    Core::JSON::DecUInt32& _class{result.Class};
                    Core::JSON::DecUInt32& _appearance{result.Appearance};
                    Core::JSON::ArrayType<Core::JSON::String>& _services{result.Services};
                    Core::JSON::Boolean& _connected{result.Connected};
                    Core::JSON::Boolean& _paired{result.Paired};

                    _errorCode = _impl_.GetDeviceInfo(_address, _type, _name, _class, _appearance, _services, _connected, _paired);

                    return (_errorCode);
                });

            // Property: 'adapters' - List of local Bluetooth adapters (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::DecUInt16>>(_T("adapters"), 
                [&_impl_](Core::JSON::ArrayType<Core::JSON::DecUInt16>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Core::JSON::ArrayType<Core::JSON::DecUInt16>& _result{result};

                    _errorCode = _impl_.Adapters(_result);

                    return (_errorCode);
                });

            // Indexed Property: 'adapter' - Local Bluetooth adapter information (r/o)
            _module_.Register<void, JsonData::BluetoothControl::AdapterData, std::function<uint32_t(const string&,
                     JsonData::BluetoothControl::AdapterData&)>>(_T("adapter"), 
                [&_impl_](const string& _index_, JsonData::BluetoothControl::AdapterData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Core::JSON::DecUInt16& _id{result.Id};
                    Core::JSON::String& _address{result.Address};
                    Core::JSON::String& _interface{result.Interface};
                    Core::JSON::EnumType<JsonData::BluetoothControl::AdapterData::adaptertype>& _type{result.Type};
                    Core::JSON::DecUInt8& _version{result.Version};
                    Core::JSON::DecUInt16& _manufacturer{result.Manufacturer};
                    Core::JSON::DecUInt32& _class{result.Class};
                    Core::JSON::String& _name{result.Name};
                    Core::JSON::String& _shortname{result.Shortname};

                    _errorCode = _impl_.Adapter(_index_, _id, _address, _interface, _type, _version, _manufacturer, _class, _name, _shortname);

                    return (_errorCode);
                });

            // Property: 'devices' - List of known remote Bluetooth devices (DEPRECATED) (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("devices"), 
                [&_impl_](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Core::JSON::ArrayType<Core::JSON::String>& _result{result};

                    _errorCode = _impl_.Devices(_result);

                    return (_errorCode);
                });

            // Indexed Property: 'device' - Remote Bluetooth device information (DEPRECATED) (r/o)
            _module_.Register<void, JsonData::BluetoothControl::DeviceData, std::function<uint32_t(const string&,
                     JsonData::BluetoothControl::DeviceData&)>>(_T("device"), 
                [&_impl_](const string& _index_, JsonData::BluetoothControl::DeviceData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Core::JSON::String& _address{result.Address};
                    Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& _type{result.Type};
                    Core::JSON::String& _name{result.Name};
                    Core::JSON::DecUInt32& _class{result.Class};
                    Core::JSON::DecUInt32& _appearance{result.Appearance};
                    Core::JSON::ArrayType<Core::JSON::String>& _services{result.Services};
                    Core::JSON::Boolean& _connected{result.Connected};
                    Core::JSON::Boolean& _paired{result.Paired};

                    _errorCode = _impl_.Device(_index_, _address, _type, _name, _class, _appearance, _services, _connected, _paired);

                    return (_errorCode);
                });

            // Register event status listeners...

            _module_.RegisterEventStatusListener(_T("discoverablestarted"),
                [&_impl_](const string& client, const JSONRPC::Status status) {
                    _impl_.OnDiscoverableStartedEventRegistration(client, status);
                });

            _module_.RegisterEventStatusListener(_T("scanstarted"),
                [&_impl_](const string& client, const JSONRPC::Status status) {
                    _impl_.OnScanStartedEventRegistration(client, status);
                });

            _module_.RegisterEventStatusListener(_T("devicestatechange"),
                [&_impl_](const string& client, const JSONRPC::Status status) {
                    _impl_.OnDeviceStateChangedEventRegistration(client, status);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("setdiscoverable"));
            _module_.Unregister(_T("stopdiscoverable"));
            _module_.Unregister(_T("scan"));
            _module_.Unregister(_T("stopscanning"));
            _module_.Unregister(_T("connect"));
            _module_.Unregister(_T("disconnect"));
            _module_.Unregister(_T("pair"));
            _module_.Unregister(_T("unpair"));
            _module_.Unregister(_T("abortpairing"));
            _module_.Unregister(_T("providepincode"));
            _module_.Unregister(_T("providepasskey"));
            _module_.Unregister(_T("confirmpasskey"));
            _module_.Unregister(_T("forget"));
            _module_.Unregister(_T("getdevicelist"));
            _module_.Unregister(_T("getdeviceinfo"));
            _module_.Unregister(_T("adapters"));
            _module_.Unregister(_T("adapter"));
            _module_.Unregister(_T("devices"));
            _module_.Unregister(_T("device"));

            // Unregister event status listeners...
            _module_.UnregisterEventStatusListener(_T("discoverablestarted"));
            _module_.UnregisterEventStatusListener(_T("scanstarted"));
            _module_.UnregisterEventStatusListener(_T("devicestatechange"));
        }

        namespace Event {

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            static void DiscoverableStarted(const JSONRPC& _module_, const JsonData::BluetoothControl::DiscoverablestartedParamsData& params,
                     const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                _module_.Notify(_T("discoverablestarted"), params, _sendIfFunction_);
            }

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            static void DiscoverableStarted(const JSONRPC& _module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type,
                     const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const Core::JSON::Boolean& connectable,
                     const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                JsonData::BluetoothControl::DiscoverablestartedParamsData _params_;
                _params_.Type = type;
                _params_.Mode = mode;
                _params_.Connectable = connectable;

                DiscoverableStarted(_module_, _params_, _sendIfFunction_);
            }

            // Event: 'discoverablestarted' - Notifies of entering the discoverable state
            static void DiscoverableStarted(const JSONRPC& _module_, const JsonData::BluetoothControl::scantype& type,
                     const JsonData::BluetoothControl::scanmode& mode, const bool& connectable, const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                JsonData::BluetoothControl::DiscoverablestartedParamsData _params_;
                _params_.Type = type;
                _params_.Mode = mode;
                _params_.Connectable = connectable;

                DiscoverableStarted(_module_, _params_, _sendIfFunction_);
            }

            // Event: 'discoverablecomplete' - Notifies of leaving the discoverable state
            static void DiscoverableComplete(const JSONRPC& _module_, const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params)
            {
                _module_.Notify(_T("discoverablecomplete"), params);
            }

            // Event: 'discoverablecomplete' - Notifies of leaving the discoverable state
            static void DiscoverableComplete(const JSONRPC& _module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo _params_;
                _params_.Type = type;

                DiscoverableComplete(_module_, _params_);
            }

            // Event: 'discoverablecomplete' - Notifies of leaving the discoverable state
            static void DiscoverableComplete(const JSONRPC& _module_, const JsonData::BluetoothControl::scantype& type)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo _params_;
                _params_.Type = type;

                DiscoverableComplete(_module_, _params_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            static void ScanStarted(const JSONRPC& _module_, const JsonData::BluetoothControl::ScanstartedParamsData& params,
                     const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                _module_.Notify(_T("scanstarted"), params, _sendIfFunction_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            static void ScanStarted(const JSONRPC& _module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type,
                     const Core::JSON::EnumType<JsonData::BluetoothControl::scanmode>& mode, const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                JsonData::BluetoothControl::ScanstartedParamsData _params_;
                _params_.Type = type;
                _params_.Mode = mode;

                ScanStarted(_module_, _params_, _sendIfFunction_);
            }

            // Event: 'scanstarted' - Notifies of scan start
            static void ScanStarted(const JSONRPC& _module_, const JsonData::BluetoothControl::scantype& type, const JsonData::BluetoothControl::scanmode& mode,
                     const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                JsonData::BluetoothControl::ScanstartedParamsData _params_;
                _params_.Type = type;
                _params_.Mode = mode;

                ScanStarted(_module_, _params_, _sendIfFunction_);
            }

            // Event: 'scancomplete' - Notifies of scan completion
            static void ScanComplete(const JSONRPC& _module_, const JsonData::BluetoothControl::StopdiscoverableParamsInfo& params)
            {
                _module_.Notify(_T("scancomplete"), params);
            }

            // Event: 'scancomplete' - Notifies of scan completion
            static void ScanComplete(const JSONRPC& _module_, const Core::JSON::EnumType<JsonData::BluetoothControl::scantype>& type)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo _params_;
                _params_.Type = type;

                ScanComplete(_module_, _params_);
            }

            // Event: 'scancomplete' - Notifies of scan completion
            static void ScanComplete(const JSONRPC& _module_, const JsonData::BluetoothControl::scantype& type)
            {
                JsonData::BluetoothControl::StopdiscoverableParamsInfo _params_;
                _params_.Type = type;

                ScanComplete(_module_, _params_);
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            static void DeviceStateChanged(const JSONRPC& _module_, const string& _id_, const JsonData::BluetoothControl::DevicestatechangeParamsData& params,
                     const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                if (_sendIfFunction_ == nullptr) {
                    _module_.Notify(_T("devicestatechange"), params, [_id_](const string& _designator_) -> bool {
                        const string _designatorId_ = _designator_.substr(0, _designator_.find('.'));
                        return (_id_ == _designatorId_);
                    });
                } else {
                    _module_.Notify(_T("devicestatechange"), params, _sendIfFunction_);
                }
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            static void DeviceStateChanged(const JSONRPC& _module_, const string& _id_, const Core::JSON::String& address,
                     const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::EnumType<JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate>& state,
                     const Core::JSON::EnumType<JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason>& disconnectreason,
                     const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                JsonData::BluetoothControl::DevicestatechangeParamsData _params_;
                _params_.Address = address;
                _params_.Type = type;
                _params_.State = state;
                _params_.Disconnectreason = disconnectreason;

                DeviceStateChanged(_module_, _id_, _params_, _sendIfFunction_);
            }

            // Event: 'devicestatechange' - Notifies of device state changes
            static void DeviceStateChanged(const JSONRPC& _module_, const string& _id_, const string& address, const Exchange::IBluetooth::IDevice::type& type,
                     const JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate& state,
                     const JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason& disconnectreason, const std::function<bool(const string&)>& _sendIfFunction_ = nullptr)
            {
                JsonData::BluetoothControl::DevicestatechangeParamsData _params_;
                _params_.Address = address;
                _params_.Type = type;
                _params_.State = state;
                _params_.Disconnectreason = disconnectreason;

                DeviceStateChanged(_module_, _id_, _params_, _sendIfFunction_);
            }

            // Event: 'pincoderequest' - Notifies of a PIN code request
            static void PINCodeRequest(const JSONRPC& _module_, const JsonData::BluetoothControl::ConnectParamsInfo& params)
            {
                _module_.Notify(_T("pincoderequest"), params);
            }

            // Event: 'pincoderequest' - Notifies of a PIN code request
            static void PINCodeRequest(const JSONRPC& _module_, const Core::JSON::String& address,
                     const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type)
            {
                JsonData::BluetoothControl::ConnectParamsInfo _params_;
                _params_.Address = address;
                _params_.Type = type;

                PINCodeRequest(_module_, _params_);
            }

            // Event: 'pincoderequest' - Notifies of a PIN code request
            static void PINCodeRequest(const JSONRPC& _module_, const string& address, const Exchange::IBluetooth::IDevice::type& type)
            {
                JsonData::BluetoothControl::ConnectParamsInfo _params_;
                _params_.Address = address;
                _params_.Type = type;

                PINCodeRequest(_module_, _params_);
            }

            // Event: 'passkeyrequest' - Notifies of a passkey request
            static void PasskeyRequest(const JSONRPC& _module_, const JsonData::BluetoothControl::ConnectParamsInfo& params)
            {
                _module_.Notify(_T("passkeyrequest"), params);
            }

            // Event: 'passkeyrequest' - Notifies of a passkey request
            static void PasskeyRequest(const JSONRPC& _module_, const Core::JSON::String& address,
                     const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type)
            {
                JsonData::BluetoothControl::ConnectParamsInfo _params_;
                _params_.Address = address;
                _params_.Type = type;

                PasskeyRequest(_module_, _params_);
            }

            // Event: 'passkeyrequest' - Notifies of a passkey request
            static void PasskeyRequest(const JSONRPC& _module_, const string& address, const Exchange::IBluetooth::IDevice::type& type)
            {
                JsonData::BluetoothControl::ConnectParamsInfo _params_;
                _params_.Address = address;
                _params_.Type = type;

                PasskeyRequest(_module_, _params_);
            }

            // Event: 'passkeyconfirmrequest' - Notifies of a passkey confirmation request
            static void PasskeyConfirmRequest(const JSONRPC& _module_, const JsonData::BluetoothControl::PasskeyconfirmrequestParamsData& params)
            {
                _module_.Notify(_T("passkeyconfirmrequest"), params);
            }

            // Event: 'passkeyconfirmrequest' - Notifies of a passkey confirmation request
            static void PasskeyConfirmRequest(const JSONRPC& _module_, const Core::JSON::String& address,
                     const Core::JSON::EnumType<Exchange::IBluetooth::IDevice::type>& type, const Core::JSON::DecUInt32& secret)
            {
                JsonData::BluetoothControl::PasskeyconfirmrequestParamsData _params_;
                _params_.Address = address;
                _params_.Type = type;
                _params_.Secret = secret;

                PasskeyConfirmRequest(_module_, _params_);
            }

            // Event: 'passkeyconfirmrequest' - Notifies of a passkey confirmation request
            static void PasskeyConfirmRequest(const JSONRPC& _module_, const string& address, const Exchange::IBluetooth::IDevice::type& type,
                     const uint32_t& secret)
            {
                JsonData::BluetoothControl::PasskeyconfirmrequestParamsData _params_;
                _params_.Address = address;
                _params_.Type = type;
                _params_.Secret = secret;

                PasskeyConfirmRequest(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JBluetoothControl

} // namespace Exchange

} // namespace WPEFramework

