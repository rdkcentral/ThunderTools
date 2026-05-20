//
// generated automatically from "IWifiControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IWifiControl::SecurityInfo, INTERFACE_ID = Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IWifiControl::NetworkInfo, INTERFACE_ID = Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR]
//   - class Exchange::IWifiControl
//   - class Exchange::IWifiControl::INotification
//

#include "Module.h"
#include "IWifiControl.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstanceC60E25DD interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::SecurityInfo Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceC60E25DDStubMethods[] = {
        // (0) virtual bool Next(Exchange::IWifiControl::SecurityInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::SecurityInfo _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IWifiControl::Security>(_info.method);
            writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_info.keys);
        },

        // (1) virtual bool Previous(Exchange::IWifiControl::SecurityInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::SecurityInfo _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IWifiControl::Security>(_info.method);
            writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_info.keys);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IWifiControl::SecurityInfo Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::SecurityInfo result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IWifiControl::Security>(result.method);
            writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(result.keys);
        }
        , nullptr
    }; // RPCIteratorTypeInstanceC60E25DDStubMethods

    //
    // RPC::IIteratorTypeInstance2F0E863E interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::NetworkInfo Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance2F0E863EStubMethods[] = {
        // (0) virtual bool Next(Exchange::IWifiControl::NetworkInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::NetworkInfo _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.ssid);
            writer.Number<uint64_t>(_info.bssid);
            writer.Number<uint32_t>(_info.frequency);
            writer.Number<int32_t>(_info.signal);
            writer.Number<Exchange::IWifiControl::Security>(_info.security);
        },

        // (1) virtual bool Previous(Exchange::IWifiControl::NetworkInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::NetworkInfo _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.ssid);
            writer.Number<uint64_t>(_info.bssid);
            writer.Number<uint32_t>(_info.frequency);
            writer.Number<int32_t>(_info.signal);
            writer.Number<Exchange::IWifiControl::Security>(_info.security);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IWifiControl::NetworkInfo Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::NetworkInfo result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result.ssid);
            writer.Number<uint64_t>(result.bssid);
            writer.Number<uint32_t>(result.frequency);
            writer.Number<int32_t>(result.signal);
            writer.Number<Exchange::IWifiControl::Security>(result.security);
        }
        , nullptr
    }; // RPCIteratorTypeInstance2F0E863EStubMethods

    //
    // RPC::IIteratorTypeInstanceC48BBF52 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceC48BBF52StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstanceC48BBF52StubMethods

    //
    // Exchange::IWifiControl interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IWifiControl::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IWifiControl::INotification*) = 0
    //  (2) virtual uint32_t Networks(Exchange::IWifiControl::INetworkInfoIterator*&) const = 0
    //  (3) virtual uint32_t Securities(const string&, Exchange::IWifiControl::ISecurityIterator*&) const = 0
    //  (4) virtual uint32_t Configs(Exchange::IWifiControl::IStringIterator*&) const = 0
    //  (5) virtual uint32_t Config(const string&, Exchange::IWifiControl::ConfigInfo&) const = 0
    //  (6) virtual uint32_t Config(const string&, const Exchange::IWifiControl::ConfigInfo&) = 0
    //  (7) virtual uint32_t Scan() = 0
    //  (8) virtual uint32_t AbortScan() = 0
    //  (9) virtual uint32_t Connect(const string&) = 0
    //  (10) virtual uint32_t Disconnect(const string&) = 0
    //  (11) virtual uint32_t Status(string&, bool&) const = 0
    //

    ProxyStub::MethodHandler ExchangeWifiControlStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IWifiControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IWifiControl::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            uint32_t result = implementation->Register(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::IWifiControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IWifiControl::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            uint32_t result = implementation->Unregister(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Networks(Exchange::IWifiControl::INetworkInfoIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWifiControl* implementation = reinterpret_cast<const Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::INetworkInfoIterator* _networkInfoList{};

            uint32_t result = implementation->Networks(_networkInfoList);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_networkInfoList));

            RPC::Administrator::Instance().RegisterInterface(channel, _networkInfoList);
        },

        // (3) virtual uint32_t Securities(const string&, Exchange::IWifiControl::ISecurityIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWifiControl* implementation = reinterpret_cast<const Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ssid = reader.Text();

            Exchange::IWifiControl::ISecurityIterator* _securityMethods{};

            uint32_t result = implementation->Securities(static_cast<const string&>(_ssid), _securityMethods);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_securityMethods));

            RPC::Administrator::Instance().RegisterInterface(channel, _securityMethods);
        },

        // (4) virtual uint32_t Configs(Exchange::IWifiControl::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWifiControl* implementation = reinterpret_cast<const Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWifiControl::IStringIterator* _configs{};

            uint32_t result = implementation->Configs(_configs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_configs));

            RPC::Administrator::Instance().RegisterInterface(channel, _configs);
        },

        // (5) virtual uint32_t Config(const string&, Exchange::IWifiControl::ConfigInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWifiControl* implementation = reinterpret_cast<const Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ssid = reader.Text();

            Exchange::IWifiControl::ConfigInfo _configInfo{};

            uint32_t result = implementation->Config(static_cast<const string&>(_ssid), _configInfo);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_configInfo.hidden);
            writer.Boolean(_configInfo.accesspoint);
            writer.Text(_configInfo.ssid);
            writer.Text(_configInfo.secret);
            writer.Text(_configInfo.identity);
            writer.Number<Exchange::IWifiControl::Security>(_configInfo.method);
            writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_configInfo.key);
        },

        // (6) virtual uint32_t Config(const string&, const Exchange::IWifiControl::ConfigInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ssid = reader.Text();
            Exchange::IWifiControl::ConfigInfo _configInfo{};
            _configInfo.hidden = reader.Boolean();
            _configInfo.accesspoint = reader.Boolean();
            _configInfo.ssid = reader.Text();
            _configInfo.secret = reader.Text();
            _configInfo.identity = reader.Text();
            _configInfo.method = reader.Number<Exchange::IWifiControl::Security>();
            _configInfo.key = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();

            uint32_t result = implementation->Config(static_cast<const string&>(_ssid), static_cast<const Exchange::IWifiControl::ConfigInfo&>(_configInfo));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t Scan() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Scan();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (8) virtual uint32_t AbortScan() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->AbortScan();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t Connect(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _configSSID = reader.Text();

            uint32_t result = implementation->Connect(static_cast<const string&>(_configSSID));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (10) virtual uint32_t Disconnect(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _configSSID = reader.Text();

            uint32_t result = implementation->Disconnect(static_cast<const string&>(_configSSID));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (11) virtual uint32_t Status(string&, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWifiControl* implementation = reinterpret_cast<const Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _connectedSsid{};
            bool _isScanning{};

            uint32_t result = implementation->Status(_connectedSsid, _isScanning);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_connectedSsid);
            writer.Boolean(_isScanning);
        }
        , nullptr
    }; // ExchangeWifiControlStubMethods

    //
    // Exchange::IWifiControl::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void NetworkChange() = 0
    //  (1) virtual void ConnectionChange(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeWifiControlNotificationStubMethods[] = {
        // (0) virtual void NetworkChange() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl::INotification* implementation = reinterpret_cast<Exchange::IWifiControl::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->NetworkChange();
        },

        // (1) virtual void ConnectionChange(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl::INotification* implementation = reinterpret_cast<Exchange::IWifiControl::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ssid = reader.Text();

            implementation->ConnectionChange(static_cast<const string&>(_ssid));
        }
        , nullptr
    }; // ExchangeWifiControlNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstanceC60E25DD interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::SecurityInfo Current() const = 0
    //

    class RPCIteratorTypeInstanceC60E25DDProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>> {
    public:
        RPCIteratorTypeInstanceC60E25DDProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        bool Next(Exchange::IWifiControl::SecurityInfo& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.method = reader.Number<Exchange::IWifiControl::Security>();
            _info.keys = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();

            return (result);
        }

        bool Previous(Exchange::IWifiControl::SecurityInfo& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.method = reader.Number<Exchange::IWifiControl::Security>();
            _info.keys = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IWifiControl::SecurityInfo Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IWifiControl::SecurityInfo result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result.method = reader.Number<Exchange::IWifiControl::Security>();
            result.keys = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceC60E25DDProxy

    //
    // RPC::IIteratorTypeInstance2F0E863E interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::NetworkInfo Current() const = 0
    //

    class RPCIteratorTypeInstance2F0E863EProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>> {
    public:
        RPCIteratorTypeInstance2F0E863EProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        bool Next(Exchange::IWifiControl::NetworkInfo& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.ssid = reader.Text();
            _info.bssid = reader.Number<uint64_t>();
            _info.frequency = reader.Number<uint32_t>();
            _info.signal = reader.Number<int32_t>();
            _info.security = reader.Number<Exchange::IWifiControl::Security>();

            return (result);
        }

        bool Previous(Exchange::IWifiControl::NetworkInfo& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.ssid = reader.Text();
            _info.bssid = reader.Number<uint64_t>();
            _info.frequency = reader.Number<uint32_t>();
            _info.signal = reader.Number<int32_t>();
            _info.security = reader.Number<Exchange::IWifiControl::Security>();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IWifiControl::NetworkInfo Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IWifiControl::NetworkInfo result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result.ssid = reader.Text();
            result.bssid = reader.Number<uint64_t>();
            result.frequency = reader.Number<uint32_t>();
            result.signal = reader.Number<int32_t>();
            result.security = reader.Number<Exchange::IWifiControl::Security>();

            return (result);
        }

    }; // class RPCIteratorTypeInstance2F0E863EProxy

    //
    // RPC::IIteratorTypeInstanceC48BBF52 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstanceC48BBF52Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstanceC48BBF52Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        bool Next(string& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Text();

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Text();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceC48BBF52Proxy

    //
    // Exchange::IWifiControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IWifiControl::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IWifiControl::INotification*) = 0
    //  (2) virtual uint32_t Networks(Exchange::IWifiControl::INetworkInfoIterator*&) const = 0
    //  (3) virtual uint32_t Securities(const string&, Exchange::IWifiControl::ISecurityIterator*&) const = 0
    //  (4) virtual uint32_t Configs(Exchange::IWifiControl::IStringIterator*&) const = 0
    //  (5) virtual uint32_t Config(const string&, Exchange::IWifiControl::ConfigInfo&) const = 0
    //  (6) virtual uint32_t Config(const string&, const Exchange::IWifiControl::ConfigInfo&) = 0
    //  (7) virtual uint32_t Scan() = 0
    //  (8) virtual uint32_t AbortScan() = 0
    //  (9) virtual uint32_t Connect(const string&) = 0
    //  (10) virtual uint32_t Disconnect(const string&) = 0
    //  (11) virtual uint32_t Status(string&, bool&) const = 0
    //

    class ExchangeWifiControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IWifiControl> {
    public:
        ExchangeWifiControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        uint32_t Register(Exchange::IWifiControl::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Unregister(Exchange::IWifiControl::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Networks(Exchange::IWifiControl::INetworkInfoIterator*& _networkInfoList) const override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _networkInfoList = reinterpret_cast<Exchange::IWifiControl::INetworkInfoIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IWifiControl::INetworkInfoIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Securities(const string& _ssid, Exchange::IWifiControl::ISecurityIterator*& _securityMethods) const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_ssid));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _securityMethods = reinterpret_cast<Exchange::IWifiControl::ISecurityIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IWifiControl::ISecurityIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Configs(Exchange::IWifiControl::IStringIterator*& _configs) const override
        {
            IPCMessage message(BaseClass::Message(4));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _configs = reinterpret_cast<Exchange::IWifiControl::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IWifiControl::IStringIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Config(const string& _ssid, Exchange::IWifiControl::ConfigInfo& _configInfo) const override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_ssid));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _configInfo.hidden = reader.Boolean();
                    _configInfo.accesspoint = reader.Boolean();
                    _configInfo.ssid = reader.Text();
                    _configInfo.secret = reader.Text();
                    _configInfo.identity = reader.Text();
                    _configInfo.method = reader.Number<Exchange::IWifiControl::Security>();
                    _configInfo.key = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Config(const string& _ssid, const Exchange::IWifiControl::ConfigInfo& _configInfo) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_ssid));
            writer.Boolean(_configInfo.hidden);
            writer.Boolean(_configInfo.accesspoint);
            writer.Text(_configInfo.ssid);
            writer.Text(_configInfo.secret);
            writer.Text(_configInfo.identity);
            writer.Number<Exchange::IWifiControl::Security>(_configInfo.method);
            writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_configInfo.key);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Scan() override
        {
            IPCMessage message(BaseClass::Message(7));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t AbortScan() override
        {
            IPCMessage message(BaseClass::Message(8));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Connect(const string& _configSSID) override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_configSSID));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Disconnect(const string& _configSSID) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_configSSID));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Status(string& _connectedSsid, bool& _isScanning) const override
        {
            IPCMessage message(BaseClass::Message(11));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _connectedSsid = reader.Text();
                    _isScanning = reader.Boolean();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeWifiControlProxy

    //
    // Exchange::IWifiControl::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void NetworkChange() = 0
    //  (1) virtual void ConnectionChange(const string&) = 0
    //

    class ExchangeWifiControlNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IWifiControl::INotification> {
    public:
        ExchangeWifiControlNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void NetworkChange() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

        void ConnectionChange(const string& _ssid) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_ssid));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeWifiControlNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>, RPCIteratorTypeInstanceC60E25DDStubMethods> RPCIteratorTypeInstanceC60E25DDStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance2F0E863EStubMethods> RPCIteratorTypeInstance2F0E863EStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstanceC48BBF52StubMethods> RPCIteratorTypeInstanceC48BBF52Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IWifiControl, ExchangeWifiControlStubMethods> ExchangeWifiControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWifiControl::INotification, ExchangeWifiControlNotificationStubMethods> ExchangeWifiControlNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>, RPCIteratorTypeInstanceC60E25DDProxy, RPCIteratorTypeInstanceC60E25DDStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance2F0E863EProxy, RPCIteratorTypeInstance2F0E863EStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstanceC48BBF52Proxy, RPCIteratorTypeInstanceC48BBF52Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IWifiControl, ExchangeWifiControlProxy, ExchangeWifiControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IWifiControl::INotification, ExchangeWifiControlNotificationProxy, ExchangeWifiControlNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IWifiControl>();
                RPC::Administrator::Instance().Recall<Exchange::IWifiControl::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
