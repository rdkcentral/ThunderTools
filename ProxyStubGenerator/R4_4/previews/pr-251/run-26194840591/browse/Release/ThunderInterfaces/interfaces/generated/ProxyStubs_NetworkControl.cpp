//
// generated automatically from "INetworkControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::INetworkControl::NetworkInfo, INTERFACE_ID = Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR]
//   - class Exchange::INetworkControl
//   - class Exchange::INetworkControl::INotification
//

#include "Module.h"
#include "INetworkControl.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstanceC653EBEA interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceC653EBEAStubMethods[] = {
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
    }; // RPCIteratorTypeInstanceC653EBEAStubMethods

    //
    // RPC::IIteratorTypeInstanceFEC9196A interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceFEC9196AStubMethods[] = {
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
    }; // RPCIteratorTypeInstanceFEC9196AStubMethods

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

    ProxyStub::MethodHandler ExchangeNetworkControlStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::INetworkControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::INotification* _sink = nullptr;
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

        // (1) virtual uint32_t Unregister(Exchange::INetworkControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkControl* implementation = reinterpret_cast<Exchange::INetworkControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::INotification* _sink = nullptr;
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
            const Core::instance_id networkInfoImplementation = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::INetworkInfoIterator* _networkInfo = nullptr;
            ProxyStub::UnknownProxy* networkInfoProxy = nullptr;
            if (networkInfoImplementation != 0) {
                networkInfoProxy = RPC::Administrator::Instance().ProxyInstance(channel, networkInfoImplementation, false, _networkInfo);

                ASSERT((_networkInfo != nullptr) && (networkInfoProxy != nullptr));
            }

            uint32_t result = implementation->Network(static_cast<const string&>(_interface), static_cast<Exchange::INetworkControl::INetworkInfoIterator* const&>(_networkInfo));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (networkInfoProxy != nullptr) {
                RPC::Administrator::Instance().Release(networkInfoProxy, message->Response());
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
            const Core::instance_id dnsImplementation = reader.Number<Core::instance_id>();

            Exchange::INetworkControl::IStringIterator* _dns = nullptr;
            ProxyStub::UnknownProxy* dnsProxy = nullptr;
            if (dnsImplementation != 0) {
                dnsProxy = RPC::Administrator::Instance().ProxyInstance(channel, dnsImplementation, false, _dns);

                ASSERT((_dns != nullptr) && (dnsProxy != nullptr));
            }

            uint32_t result = implementation->DNS(static_cast<Exchange::INetworkControl::IStringIterator* const&>(_dns));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (dnsProxy != nullptr) {
                RPC::Administrator::Instance().Release(dnsProxy, message->Response());
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

    ProxyStub::MethodHandler ExchangeNetworkControlNotificationStubMethods[] = {
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
    // RPC::IIteratorTypeInstanceC653EBEA interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (1) virtual bool Previous(Exchange::INetworkControl::NetworkInfo&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::INetworkControl::NetworkInfo Current() const = 0
    //

    class RPCIteratorTypeInstanceC653EBEAProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>> {
    public:
        RPCIteratorTypeInstanceC653EBEAProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::INetworkControl::NetworkInfo& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.address = reader.Text();
            _info.defaultGateway = reader.Text();
            _info.mask = reader.Number<uint8_t>();
            _info.mode = reader.Number<Exchange::INetworkControl::ModeType>();

            return (result);
        }

        bool Previous(Exchange::INetworkControl::NetworkInfo& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.address = reader.Text();
            _info.defaultGateway = reader.Text();
            _info.mask = reader.Number<uint8_t>();
            _info.mode = reader.Number<Exchange::INetworkControl::ModeType>();

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

        Exchange::INetworkControl::NetworkInfo Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::INetworkControl::NetworkInfo result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result.address = reader.Text();
            result.defaultGateway = reader.Text();
            result.mask = reader.Number<uint8_t>();
            result.mode = reader.Number<Exchange::INetworkControl::ModeType>();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceC653EBEAProxy

    //
    // RPC::IIteratorTypeInstanceFEC9196A interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstanceFEC9196AProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstanceFEC9196AProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstanceFEC9196AProxy

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

        uint32_t Register(Exchange::INetworkControl::INotification* _sink) override
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

        uint32_t Unregister(Exchange::INetworkControl::INotification* _sink) override
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

        uint32_t Interfaces(Exchange::INetworkControl::IStringIterator*& _interfaces) const override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _interfaces = reinterpret_cast<Exchange::INetworkControl::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::IStringIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Status(const string& _interface, Exchange::INetworkControl::StatusType& _status) const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_interface));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _status = reader.Number<Exchange::INetworkControl::StatusType>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Network(const string& _interface, Exchange::INetworkControl::INetworkInfoIterator*& _networkInfo) const override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_interface));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _networkInfo = reinterpret_cast<Exchange::INetworkControl::INetworkInfoIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::INetworkInfoIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Network(const string& _interface, Exchange::INetworkControl::INetworkInfoIterator* const& _networkInfo) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_interface));
            writer.Number<Core::instance_id>(RPC::instance_cast(static_cast<Exchange::INetworkControl::INetworkInfoIterator* const&>(_networkInfo)));

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

        uint32_t DNS(Exchange::INetworkControl::IStringIterator*& _dns) const override
        {
            IPCMessage message(BaseClass::Message(6));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _dns = reinterpret_cast<Exchange::INetworkControl::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::INetworkControl::IStringIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t DNS(Exchange::INetworkControl::IStringIterator* const& _dns) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(static_cast<Exchange::INetworkControl::IStringIterator* const&>(_dns)));

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

        uint32_t Up(const string& _interface, bool& _up) const override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_interface));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _up = reader.Boolean();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Up(const string& _interface, const bool _up) override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_interface));
            writer.Boolean(_up);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Flush(const string& _interface) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_interface));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
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

        void Update(const string& _interfaceName) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_interfaceName));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeNetworkControlNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstanceC653EBEAStubMethods> RPCIteratorTypeInstanceC653EBEAStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstanceFEC9196AStubMethods> RPCIteratorTypeInstanceFEC9196AStub;
        typedef ProxyStub::UnknownStubType<Exchange::INetworkControl, ExchangeNetworkControlStubMethods> ExchangeNetworkControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::INetworkControl::INotification, ExchangeNetworkControlNotificationStubMethods> ExchangeNetworkControlNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::INetworkControl::NetworkInfo, Exchange::ID_NETWORKCONTROL_NETWORK_INFO_ITERATOR>, RPCIteratorTypeInstanceC653EBEAProxy, RPCIteratorTypeInstanceC653EBEAStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstanceFEC9196AProxy, RPCIteratorTypeInstanceFEC9196AStub>();
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
