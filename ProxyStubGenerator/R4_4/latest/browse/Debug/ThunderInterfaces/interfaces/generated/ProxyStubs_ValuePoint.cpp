//
// generated automatically from "IValuePoint.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IValuePoint
//   - class Exchange::IValuePoint::ICatalog
//   - class Exchange::IValuePoint::ICatalog::INotification
//   - class Exchange::IValuePoint::INotification
//

#include "Module.h"
#include "IValuePoint.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IValuePoint interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IValuePoint::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IValuePoint::INotification*) = 0
    //  (2) virtual uint32_t Identifier(uint32_t&) const = 0
    //  (3) virtual uint32_t Bundle(uint32_t&) const = 0
    //  (4) virtual uint32_t Condition(Exchange::IValuePoint::condition&) const = 0
    //  (5) virtual uint32_t Type(uint32_t&) const = 0
    //  (6) virtual uint32_t Minimum(int32_t&) const = 0
    //  (7) virtual uint32_t Maximum(int32_t&) const = 0
    //  (8) virtual uint32_t Value(int32_t&) const = 0
    //  (9) virtual uint32_t Value(const int32_t) = 0
    //  (10) virtual uint32_t Metadata(string&) const = 0
    //  (11) virtual bool Evaluate() = 0
    //

    ProxyStub::MethodHandler ExchangeValuePointStubMethods[] = {
        // (0) virtual void Register(Exchange::IValuePoint::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint* implementation = reinterpret_cast<Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Register(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IValuePoint::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint* implementation = reinterpret_cast<Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Unregister(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Identifier(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _ID{};

            uint32_t result = implementation->Identifier(_ID);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_ID);
        },

        // (3) virtual uint32_t Bundle(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _ID{};

            uint32_t result = implementation->Bundle(_ID);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_ID);
        },

        // (4) virtual uint32_t Condition(Exchange::IValuePoint::condition&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IValuePoint::condition _value{};

            uint32_t result = implementation->Condition(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IValuePoint::condition>(_value);
        },

        // (5) virtual uint32_t Type(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _value{};

            uint32_t result = implementation->Type(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_value);
        },

        // (6) virtual uint32_t Minimum(int32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t _value{};

            uint32_t result = implementation->Minimum(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<int32_t>(_value);
        },

        // (7) virtual uint32_t Maximum(int32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t _value{};

            uint32_t result = implementation->Maximum(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<int32_t>(_value);
        },

        // (8) virtual uint32_t Value(int32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t _value{};

            uint32_t result = implementation->Value(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<int32_t>(_value);
        },

        // (9) virtual uint32_t Value(const int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint* implementation = reinterpret_cast<Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _value = reader.Number<int32_t>();

            uint32_t result = implementation->Value(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (10) virtual uint32_t Metadata(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IValuePoint* implementation = reinterpret_cast<const Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->Metadata(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (11) virtual bool Evaluate() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint* implementation = reinterpret_cast<Exchange::IValuePoint*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Evaluate();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        }
        , nullptr
    }; // ExchangeValuePointStubMethods

    //
    // Exchange::IValuePoint::ICatalog interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IValuePoint::ICatalog::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IValuePoint::ICatalog::INotification*) = 0
    //  (2) virtual Exchange::IValuePoint* Resource(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeValuePointCatalogStubMethods[] = {
        // (0) virtual void Register(Exchange::IValuePoint::ICatalog::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint::ICatalog* implementation = reinterpret_cast<Exchange::IValuePoint::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint::ICatalog::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Register(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(const Exchange::IValuePoint::ICatalog::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint::ICatalog* implementation = reinterpret_cast<Exchange::IValuePoint::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint::ICatalog::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Unregister(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (2) virtual Exchange::IValuePoint* Resource(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint::ICatalog* implementation = reinterpret_cast<Exchange::IValuePoint::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            Exchange::IValuePoint* result = implementation->Resource(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeValuePointCatalogStubMethods

    //
    // Exchange::IValuePoint::ICatalog::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Activated(Exchange::IValuePoint*) = 0
    //  (1) virtual void Deactivated(Exchange::IValuePoint*) = 0
    //

    ProxyStub::MethodHandler ExchangeValuePointCatalogNotificationStubMethods[] = {
        // (0) virtual void Activated(Exchange::IValuePoint*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint::ICatalog::INotification* implementation = reinterpret_cast<Exchange::IValuePoint::ICatalog::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sourceImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint* _source = nullptr;
            ProxyStub::UnknownProxy* sourceProxy = nullptr;
            if (sourceImplementation != 0) {
                sourceProxy = RPC::Administrator::Instance().ProxyInstance(channel, sourceImplementation, false, _source);

                ASSERT((_source != nullptr) && (sourceProxy != nullptr));
            }

            implementation->Activated(_source);

            if (sourceProxy != nullptr) {
                RPC::Administrator::Instance().Release(sourceProxy, message->Response());
            }
        },

        // (1) virtual void Deactivated(Exchange::IValuePoint*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint::ICatalog::INotification* implementation = reinterpret_cast<Exchange::IValuePoint::ICatalog::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sourceImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint* _source = nullptr;
            ProxyStub::UnknownProxy* sourceProxy = nullptr;
            if (sourceImplementation != 0) {
                sourceProxy = RPC::Administrator::Instance().ProxyInstance(channel, sourceImplementation, false, _source);

                ASSERT((_source != nullptr) && (sourceProxy != nullptr));
            }

            implementation->Deactivated(_source);

            if (sourceProxy != nullptr) {
                RPC::Administrator::Instance().Release(sourceProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeValuePointCatalogNotificationStubMethods

    //
    // Exchange::IValuePoint::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Update(const uint32_t) = 0
    //  (1) virtual void Metadata(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeValuePointNotificationStubMethods[] = {
        // (0) virtual void Update(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint::INotification* implementation = reinterpret_cast<Exchange::IValuePoint::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            implementation->Update(_id);
        },

        // (1) virtual void Metadata(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IValuePoint::INotification* implementation = reinterpret_cast<Exchange::IValuePoint::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            implementation->Metadata(_id);
        }
        , nullptr
    }; // ExchangeValuePointNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IValuePoint interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IValuePoint::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IValuePoint::INotification*) = 0
    //  (2) virtual uint32_t Identifier(uint32_t&) const = 0
    //  (3) virtual uint32_t Bundle(uint32_t&) const = 0
    //  (4) virtual uint32_t Condition(Exchange::IValuePoint::condition&) const = 0
    //  (5) virtual uint32_t Type(uint32_t&) const = 0
    //  (6) virtual uint32_t Minimum(int32_t&) const = 0
    //  (7) virtual uint32_t Maximum(int32_t&) const = 0
    //  (8) virtual uint32_t Value(int32_t&) const = 0
    //  (9) virtual uint32_t Value(const int32_t) = 0
    //  (10) virtual uint32_t Metadata(string&) const = 0
    //  (11) virtual bool Evaluate() = 0
    //

    class ExchangeValuePointProxy final : public ProxyStub::UnknownProxyType<Exchange::IValuePoint> {
    public:
        ExchangeValuePointProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IValuePoint::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IValuePoint::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Identifier(uint32_t& _ID) const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _ID = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Bundle(uint32_t& _ID) const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _ID = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Condition(Exchange::IValuePoint::condition& _value) const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Number<Exchange::IValuePoint::condition>();

            return (result);
        }

        uint32_t Type(uint32_t& _value) const override
        {
            IPCMessage message(BaseClass::Message(5));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Minimum(int32_t& _value) const override
        {
            IPCMessage message(BaseClass::Message(6));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Number<int32_t>();

            return (result);
        }

        uint32_t Maximum(int32_t& _value) const override
        {
            IPCMessage message(BaseClass::Message(7));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Number<int32_t>();

            return (result);
        }

        uint32_t Value(int32_t& _value) const override
        {
            IPCMessage message(BaseClass::Message(8));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Number<int32_t>();

            return (result);
        }

        uint32_t Value(const int32_t _value) override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_value);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Metadata(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(10));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        bool Evaluate() override
        {
            IPCMessage message(BaseClass::Message(11));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

    }; // class ExchangeValuePointProxy

    //
    // Exchange::IValuePoint::ICatalog interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IValuePoint::ICatalog::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IValuePoint::ICatalog::INotification*) = 0
    //  (2) virtual Exchange::IValuePoint* Resource(const uint32_t) = 0
    //

    class ExchangeValuePointCatalogProxy final : public ProxyStub::UnknownProxyType<Exchange::IValuePoint::ICatalog> {
    public:
        ExchangeValuePointCatalogProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IValuePoint::ICatalog::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(const Exchange::IValuePoint::ICatalog::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        Exchange::IValuePoint* Resource(const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Exchange::IValuePoint* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IValuePoint*>(Interface(reader.Number<Core::instance_id>(), Exchange::IValuePoint::ID));

            return (result);
        }

    }; // class ExchangeValuePointCatalogProxy

    //
    // Exchange::IValuePoint::ICatalog::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Activated(Exchange::IValuePoint*) = 0
    //  (1) virtual void Deactivated(Exchange::IValuePoint*) = 0
    //

    class ExchangeValuePointCatalogNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IValuePoint::ICatalog::INotification> {
    public:
        ExchangeValuePointCatalogNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Activated(Exchange::IValuePoint* _source) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_source));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Deactivated(Exchange::IValuePoint* _source) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_source));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeValuePointCatalogNotificationProxy

    //
    // Exchange::IValuePoint::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Update(const uint32_t) = 0
    //  (1) virtual void Metadata(const uint32_t) = 0
    //

    class ExchangeValuePointNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IValuePoint::INotification> {
    public:
        ExchangeValuePointNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Update(const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            UnknownProxyType::Invoke(message);
        }

        void Metadata(const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeValuePointNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IValuePoint, ExchangeValuePointStubMethods> ExchangeValuePointStub;
        typedef ProxyStub::UnknownStubType<Exchange::IValuePoint::ICatalog, ExchangeValuePointCatalogStubMethods> ExchangeValuePointCatalogStub;
        typedef ProxyStub::UnknownStubType<Exchange::IValuePoint::ICatalog::INotification, ExchangeValuePointCatalogNotificationStubMethods> ExchangeValuePointCatalogNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IValuePoint::INotification, ExchangeValuePointNotificationStubMethods> ExchangeValuePointNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IValuePoint, ExchangeValuePointProxy, ExchangeValuePointStub>();
                RPC::Administrator::Instance().Announce<Exchange::IValuePoint::ICatalog, ExchangeValuePointCatalogProxy, ExchangeValuePointCatalogStub>();
                RPC::Administrator::Instance().Announce<Exchange::IValuePoint::ICatalog::INotification, ExchangeValuePointCatalogNotificationProxy, ExchangeValuePointCatalogNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IValuePoint::INotification, ExchangeValuePointNotificationProxy, ExchangeValuePointNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IValuePoint>();
                RPC::Administrator::Instance().Recall<Exchange::IValuePoint::ICatalog>();
                RPC::Administrator::Instance().Recall<Exchange::IValuePoint::ICatalog::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IValuePoint::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
