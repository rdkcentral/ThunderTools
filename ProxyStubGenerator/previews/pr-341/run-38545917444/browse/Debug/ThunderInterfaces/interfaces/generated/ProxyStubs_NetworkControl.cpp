//
// generated automatically from "INetworkControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::INetworkControl::NetworkInfo, INTERFACE_ID = Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class Exchange::INetworkControl
//   - class Exchange::INetworkControl::INotification
//

#include "Module.h"
#include "INetworkControl.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_4841f294117251fd interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_4841f294117251fdStubMethods[] = {
        // (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::INetworkControl::NetworkInfo _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.address);
            writer.Text(_info.defaultGateway);
            writer.Number<uint8_t>(_info.mask);
            writer.Number<Exchange::INetworkControl::ModeType>(_info.mode);
        },

        // (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::INetworkControl::NetworkInfo _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.address);
            writer.Text(_info.defaultGateway);
            writer.Number<uint8_t>(_info.mask);
            writer.Number<Exchange::INetworkControl::ModeType>(_info.mode);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::INetworkControl::NetworkInfo result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result.address);
            writer.Text(result.defaultGateway);
            writer.Number<uint8_t>(result.mask);
            writer.Number<Exchange::INetworkControl::ModeType>(result.mode);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_4841f294117251fdStubMethods

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
    // Exchange::INetworkControl interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::INetworkControl::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::INetworkControl::INotification*) = 0
    //  (2) virtual uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (3) virtual uint32_t Status(const string&, Exchange::INetworkControl::StatusType&) const = 0
    //  (4) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator*&) const = 0
    //  (5) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator* const&) = 0
    //  (6) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (7) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator* const&) = 0
    //  (8) virtual uint32_t Up(const string&, bool&) const = 0
    //  (9) virtual uint32_t Up(const string&, const bool) = 0
    //  (10) virtual uint32_t Flush(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeNetworkControlStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::INetworkControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::INotification* _sink{};
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

        // (1) virtual uint32_t Unregister(Exchange::INetworkControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::INotification* _sink{};
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

        // (2) virtual uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::INetworkControl::IStringIterator* _interfaces{};

            uint32_t result = implementation->Interfaces(_interfaces);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_interfaces));

            RPC::Administrator::Instance().RegisterInterface(channel, _interfaces);
        },

        // (3) virtual uint32_t Status(const string&, Exchange::INetworkControl::StatusType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _interface = reader.Text();

            Exchange::INetworkControl::StatusType _status{};

            uint32_t result = implementation->Status(static_cast<const string&>(_interface), _status);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::INetworkControl::StatusType>(_status);
        },

        // (4) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _interface = reader.Text();

            Exchange::INetworkControl::INetworkInfoIterator* _networkInfo{};

            uint32_t result = implementation->Network(static_cast<const string&>(_interface), _networkInfo);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_networkInfo));

            RPC::Administrator::Instance().RegisterInterface(channel, _networkInfo);
        },

        // (5) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator* const&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _interface = reader.Text();
            Core::instance_id _networkInfoInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::INetworkInfoIterator* _networkInfo{};
            ProxyStub::UnknownProxy* _networkInfoProxy__ = nullptr;
            if (_networkInfoInstanceId__ != 0) {
                _networkInfoProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _networkInfoInstanceId__, false, _networkInfo);
                ASSERT((_networkInfo != nullptr) && (_networkInfoProxy__ != nullptr));
            }

            uint32_t result = implementation->Network(static_cast<const string&>(_interface), static_cast<Exchange::INetworkControl::INetworkInfoIterator* const&>(_networkInfo));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_networkInfoProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_networkInfoProxy__, message->Response());
            }
        },

        // (6) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::INetworkControl::IStringIterator* _dns{};

            uint32_t result = implementation->DNS(_dns);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_dns));

            RPC::Administrator::Instance().RegisterInterface(channel, _dns);
        },

        // (7) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator* const&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _dnsInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::IStringIterator* _dns{};
            ProxyStub::UnknownProxy* _dnsProxy__ = nullptr;
            if (_dnsInstanceId__ != 0) {
                _dnsProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _dnsInstanceId__, false, _dns);
                ASSERT((_dns != nullptr) && (_dnsProxy__ != nullptr));
            }

            uint32_t result = implementation->DNS(static_cast<Exchange::INetworkControl::IStringIterator* const&>(_dns));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_dnsProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_dnsProxy__, message->Response());
            }
        },

        // (8) virtual uint32_t Up(const string&, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::INetworkControl* implementation = reinterpret_cast<const Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _interface = reader.Text();

            bool _up{};

            uint32_t result = implementation->Up(static_cast<const string&>(_interface), _up);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_up);
        },

        // (9) virtual uint32_t Up(const string&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _interface = reader.Text();
            const bool _up = reader.Boolean();

            uint32_t result = implementation->Up(static_cast<const string&>(_interface), _up);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (10) virtual uint32_t Flush(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _interface = reader.Text();

            uint32_t result = implementation->Flush(static_cast<const string&>(_interface));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeNetworkControlStubMethods

    //
    // Exchange::INetworkControl::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Update(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeNetworkControlNotificationStubMethods[] = {
        // (0) virtual void Update(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl::INotification* implementation = reinterpret_cast<Exchange::INetworkControl::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _interfaceName = reader.Text();

            implementation->Update(static_cast<const string&>(_interfaceName));
        }
        , nullptr
    }; // ExchangeNetworkControlNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_4841f294117251fd interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
    //

    class RPCIteratorTypeInstance_4841f294117251fdProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_4841f294117251fdProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::INetworkControl::NetworkInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.address = reader.Text();
                _info.defaultGateway = reader.Text();
                _info.mask = reader.Number<uint8_t>();
                _info.mode = reader.Number<Exchange::INetworkControl::ModeType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::INetworkControl::NetworkInfo& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.address = reader.Text();
                _info.defaultGateway = reader.Text();
                _info.mask = reader.Number<uint8_t>();
                _info.mode = reader.Number<Exchange::INetworkControl::ModeType>();
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

        Exchange::INetworkControl::NetworkInfo Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::INetworkControl::NetworkInfo result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result.address = reader.Text();
                result.defaultGateway = reader.Text();
                result.mask = reader.Number<uint8_t>();
                result.mode = reader.Number<Exchange::INetworkControl::ModeType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_4841f294117251fdProxy

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
    // Exchange::INetworkControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::INetworkControl::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::INetworkControl::INotification*) = 0
    //  (2) virtual uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (3) virtual uint32_t Status(const string&, Exchange::INetworkControl::StatusType&) const = 0
    //  (4) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator*&) const = 0
    //  (5) virtual uint32_t Network(const string&, Exchange::INetworkControl::INetworkInfoIterator* const&) = 0
    //  (6) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator*&) const = 0
    //  (7) virtual uint32_t DNS(Exchange::INetworkControl::IStringIterator* const&) = 0
    //  (8) virtual uint32_t Up(const string&, bool&) const = 0
    //  (9) virtual uint32_t Up(const string&, const bool) = 0
    //  (10) virtual uint32_t Flush(const string&) = 0
    //

    class ExchangeNetworkControlProxy final : public ProxyStub::UnknownProxyType<Exchange::INetworkControl> {
    public:
        ExchangeNetworkControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::INetworkControl::INotification* _sink) override
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

        uint32_t Unregister(Exchange::INetworkControl::INotification* _sink) override
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

        uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*& _interfaces) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _interfaces = reinterpret_cast<Exchange::INetworkControl::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Status(const string& _interface, Exchange::INetworkControl::StatusType& _status) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _status = reader.Number<Exchange::INetworkControl::StatusType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Network(const string& _interface, Exchange::INetworkControl::INetworkInfoIterator*& _networkInfo) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _networkInfo = reinterpret_cast<Exchange::INetworkControl::INetworkInfoIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::INetworkInfoIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Network(const string& _interface, Exchange::INetworkControl::INetworkInfoIterator* const& _networkInfo) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);
            writer.Number<Core::instance_id>(RPC::instance_cast(_networkInfo));

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

        uint32_t DNS(Exchange::INetworkControl::IStringIterator*& _dns) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _dns = reinterpret_cast<Exchange::INetworkControl::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t DNS(Exchange::INetworkControl::IStringIterator* const& _dns) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_dns));

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

        uint32_t Up(const string& _interface, bool& _up) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _up = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Up(const string& _interface, const bool _up) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);
            writer.Boolean(_up);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Flush(const string& _interface) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interface);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
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

    }; // class ExchangeNetworkControlProxy

    //
    // Exchange::INetworkControl::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Update(const string&) = 0
    //

    class ExchangeNetworkControlNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::INetworkControl::INotification> {
    public:
        ExchangeNetworkControlNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Update(const string& _interfaceName) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_interfaceName);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeNetworkControlNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance_4841f294117251fdStubMethods> RPCIteratorTypeInstance_4841f294117251fdStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<Exchange::INetworkControl, ExchangeNetworkControlStubMethods> ExchangeNetworkControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::INetworkControl::INotification, ExchangeNetworkControlNotificationStubMethods> ExchangeNetworkControlNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstance_4841f294117251fdProxy, RPCIteratorTypeInstance_4841f294117251fdStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>();
                RPC::Administrator::Instance().Announce<Exchange::INetworkControl, ExchangeNetworkControlProxy, ExchangeNetworkControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::INetworkControl::INotification, ExchangeNetworkControlNotificationProxy, ExchangeNetworkControlNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::INetworkControl>();
                RPC::Administrator::Instance().Recall<Exchange::INetworkControl::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
