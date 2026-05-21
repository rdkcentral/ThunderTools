//
// generated automatically from "IWifiControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IWifiControl::SecurityInfo, INTERFACE_ID = Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IWifiControl::NetworkInfo, INTERFACE_ID = Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class Exchange::IWifiControl
//   - class Exchange::IWifiControl::INotification
//

#include "Module.h"
#include "IWifiControl.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_c46f4bc0bed3f7fd interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::SecurityInfo Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_c46f4bc0bed3f7fdStubMethods[] = {
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
            writer.Boolean(_info.keys.IsSet());
            if (_info.keys.IsSet() == true) {
                writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_info.keys.Value());
            }
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
            writer.Boolean(_info.keys.IsSet());
            if (_info.keys.IsSet() == true) {
                writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_info.keys.Value());
            }
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
            writer.Boolean(result.keys.IsSet());
            if (result.keys.IsSet() == true) {
                writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(result.keys.Value());
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_c46f4bc0bed3f7fdStubMethods

    //
    // RPC::IIteratorTypeInstance_7ed557741e4e75e2 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::NetworkInfo Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_7ed557741e4e75e2StubMethods[] = {
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
            writer.Boolean(_info.ssid.IsSet());
            if (_info.ssid.IsSet() == true) {
                writer.Text(_info.ssid.Value());
            }
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
            writer.Boolean(_info.ssid.IsSet());
            if (_info.ssid.IsSet() == true) {
                writer.Text(_info.ssid.Value());
            }
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
            writer.Boolean(result.ssid.IsSet());
            if (result.ssid.IsSet() == true) {
                writer.Text(result.ssid.Value());
            }
            writer.Number<uint64_t>(result.bssid);
            writer.Number<uint32_t>(result.frequency);
            writer.Number<int32_t>(result.signal);
            writer.Number<Exchange::IWifiControl::Security>(result.security);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_7ed557741e4e75e2StubMethods

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_b3acff3685df4032StubMethods[] = {
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
    }; // RPCIteratorTypeInstance_b3acff3685df4032StubMethods

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

    static ProxyStub::MethodHandler ExchangeWifiControlStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IWifiControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IWifiControl::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            uint32_t result = implementation->Register(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::IWifiControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWifiControl* implementation = reinterpret_cast<Exchange::IWifiControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IWifiControl::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            uint32_t result = implementation->Unregister(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
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
            writer.Boolean(_configInfo.ssid.IsSet());
            if (_configInfo.ssid.IsSet() == true) {
                writer.Text(_configInfo.ssid.Value());
            }
            writer.Boolean(_configInfo.secret.IsSet());
            if (_configInfo.secret.IsSet() == true) {
                writer.Text(_configInfo.secret.Value());
            }
            writer.Boolean(_configInfo.identity.IsSet());
            if (_configInfo.identity.IsSet() == true) {
                writer.Text(_configInfo.identity.Value());
            }
            writer.Number<Exchange::IWifiControl::Security>(_configInfo.method);
            writer.Boolean(_configInfo.key.IsSet());
            if (_configInfo.key.IsSet() == true) {
                writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_configInfo.key.Value());
            }
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
            if (reader.Boolean() == true) {
                _configInfo.ssid = reader.Text();
            }
            if (reader.Boolean() == true) {
                _configInfo.secret = reader.Text();
            }
            if (reader.Boolean() == true) {
                _configInfo.identity = reader.Text();
            }
            _configInfo.method = reader.Number<Exchange::IWifiControl::Security>();
            if (reader.Boolean() == true) {
                _configInfo.key = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();
            }

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

    static ProxyStub::MethodHandler ExchangeWifiControlNotificationStubMethods[] = {
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
    // RPC::IIteratorTypeInstance_c46f4bc0bed3f7fd interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::SecurityInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::SecurityInfo Current() const = 0
    //

    class RPCIteratorTypeInstance_c46f4bc0bed3f7fdProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_c46f4bc0bed3f7fdProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IWifiControl::SecurityInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.method = reader.Number<Exchange::IWifiControl::Security>();
                if (reader.Boolean() == true) {
                    _info.keys = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IWifiControl::SecurityInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.method = reader.Number<Exchange::IWifiControl::Security>();
                if (reader.Boolean() == true) {
                    _info.keys = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IWifiControl::SecurityInfo Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IWifiControl::SecurityInfo result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result.method = reader.Number<Exchange::IWifiControl::Security>();
                if (reader.Boolean() == true) {
                    result.keys = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_c46f4bc0bed3f7fdProxy

    //
    // RPC::IIteratorTypeInstance_7ed557741e4e75e2 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::IWifiControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IWifiControl::NetworkInfo Current() const = 0
    //

    class RPCIteratorTypeInstance_7ed557741e4e75e2Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_7ed557741e4e75e2Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IWifiControl::NetworkInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                if (reader.Boolean() == true) {
                    _info.ssid = reader.Text();
                }
                _info.bssid = reader.Number<uint64_t>();
                _info.frequency = reader.Number<uint32_t>();
                _info.signal = reader.Number<int32_t>();
                _info.security = reader.Number<Exchange::IWifiControl::Security>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IWifiControl::NetworkInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                if (reader.Boolean() == true) {
                    _info.ssid = reader.Text();
                }
                _info.bssid = reader.Number<uint64_t>();
                _info.frequency = reader.Number<uint32_t>();
                _info.signal = reader.Number<int32_t>();
                _info.security = reader.Number<Exchange::IWifiControl::Security>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IWifiControl::NetworkInfo Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IWifiControl::NetworkInfo result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                if (reader.Boolean() == true) {
                    result.ssid = reader.Text();
                }
                result.bssid = reader.Number<uint64_t>();
                result.frequency = reader.Number<uint32_t>();
                result.signal = reader.Number<int32_t>();
                result.security = reader.Number<Exchange::IWifiControl::Security>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_7ed557741e4e75e2Proxy

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_b3acff3685df4032Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_b3acff3685df4032Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_b3acff3685df4032Proxy

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

        uint32_t Register(Exchange::IWifiControl::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Unregister(Exchange::IWifiControl::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Networks(Exchange::IWifiControl::INetworkInfoIterator*& _networkInfoList) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _networkInfoList = reinterpret_cast<Exchange::IWifiControl::INetworkInfoIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IWifiControl::INetworkInfoIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Securities(const string& _ssid, Exchange::IWifiControl::ISecurityIterator*& _securityMethods) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ssid);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _securityMethods = reinterpret_cast<Exchange::IWifiControl::ISecurityIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IWifiControl::ISecurityIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Configs(Exchange::IWifiControl::IStringIterator*& _configs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _configs = reinterpret_cast<Exchange::IWifiControl::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IWifiControl::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Config(const string& _ssid, Exchange::IWifiControl::ConfigInfo& _configInfo) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ssid);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _configInfo.hidden = reader.Boolean();
                _configInfo.accesspoint = reader.Boolean();
                if (reader.Boolean() == true) {
                    _configInfo.ssid = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _configInfo.secret = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _configInfo.identity = reader.Text();
                }
                _configInfo.method = reader.Number<Exchange::IWifiControl::Security>();
                if (reader.Boolean() == true) {
                    _configInfo.key = reader.Number<Exchange::IWifiControl::SecurityInfo::Key>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Config(const string& _ssid, const Exchange::IWifiControl::ConfigInfo& _configInfo) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ssid);
            writer.Boolean(_configInfo.hidden);
            writer.Boolean(_configInfo.accesspoint);
            writer.Boolean(_configInfo.ssid.IsSet());
            if (_configInfo.ssid.IsSet() == true) {
                writer.Text(_configInfo.ssid.Value());
            }
            writer.Boolean(_configInfo.secret.IsSet());
            if (_configInfo.secret.IsSet() == true) {
                writer.Text(_configInfo.secret.Value());
            }
            writer.Boolean(_configInfo.identity.IsSet());
            if (_configInfo.identity.IsSet() == true) {
                writer.Text(_configInfo.identity.Value());
            }
            writer.Number<Exchange::IWifiControl::Security>(_configInfo.method);
            writer.Boolean(_configInfo.key.IsSet());
            if (_configInfo.key.IsSet() == true) {
                writer.Number<Exchange::IWifiControl::SecurityInfo::Key>(_configInfo.key.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Scan() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t AbortScan() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Connect(const string& _configSSID) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_configSSID);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Disconnect(const string& _configSSID) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_configSSID);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Status(string& _connectedSsid, bool& _isScanning) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _connectedSsid = reader.Text();
                _isScanning = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
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

        void NetworkChange() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void ConnectionChange(const string& _ssid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ssid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeWifiControlNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>, RPCIteratorTypeInstance_c46f4bc0bed3f7fdStubMethods> RPCIteratorTypeInstance_c46f4bc0bed3f7fdStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance_7ed557741e4e75e2StubMethods> RPCIteratorTypeInstance_7ed557741e4e75e2Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IWifiControl, ExchangeWifiControlStubMethods> ExchangeWifiControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWifiControl::INotification, ExchangeWifiControlNotificationStubMethods> ExchangeWifiControlNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IWifiControl::SecurityInfo, Exchange::ID_WIFICONTROL_SECURITY_INFO_ITERATOR>, RPCIteratorTypeInstance_c46f4bc0bed3f7fdProxy, RPCIteratorTypeInstance_c46f4bc0bed3f7fdStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IWifiControl::NetworkInfo, Exchange::ID_WIFICONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance_7ed557741e4e75e2Proxy, RPCIteratorTypeInstance_7ed557741e4e75e2Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>();
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
