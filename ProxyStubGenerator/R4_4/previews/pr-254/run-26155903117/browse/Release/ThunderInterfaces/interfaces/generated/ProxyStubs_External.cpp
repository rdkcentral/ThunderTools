//
// generated automatically from "IExternal.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IExternal
//   - class Exchange::IExternal::INotification
//   - class Exchange::IExternal::ICatalog
//   - class Exchange::IExternal::ICatalog::INotification
//

#include "Module.h"
#include "IExternal.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IExternal interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IExternal::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IExternal::INotification*) = 0
    //  (2) virtual Exchange::IExternal::condition Condition() const = 0
    //  (3) virtual uint32_t Identifier() const = 0
    //  (4) virtual uint32_t Type() const = 0
    //  (5) virtual int32_t Minimum() const = 0
    //  (6) virtual int32_t Maximum() const = 0
    //  (7) virtual uint32_t Get(int32_t&) const = 0
    //  (8) virtual uint32_t Set(const int32_t) = 0
    //  (9) virtual void Evaluate() = 0
    //  (10) virtual string Metadata() const = 0
    //

    ProxyStub::MethodHandler ExchangeExternalStubMethods[] = {
        // (0) virtual void Register(Exchange::IExternal::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal* implementation = reinterpret_cast<Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IExternal::INotification* _sink = nullptr;
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

        // (1) virtual void Unregister(Exchange::IExternal::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal* implementation = reinterpret_cast<Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IExternal::INotification* _sink = nullptr;
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

        // (2) virtual Exchange::IExternal::condition Condition() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IExternal* implementation = reinterpret_cast<const Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IExternal::condition result = implementation->Condition();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IExternal::condition>(result);
        },

        // (3) virtual uint32_t Identifier() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IExternal* implementation = reinterpret_cast<const Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Identifier();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t Type() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IExternal* implementation = reinterpret_cast<const Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Type();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual int32_t Minimum() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IExternal* implementation = reinterpret_cast<const Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t result = implementation->Minimum();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
        },

        // (6) virtual int32_t Maximum() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IExternal* implementation = reinterpret_cast<const Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t result = implementation->Maximum();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
        },

        // (7) virtual uint32_t Get(int32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IExternal* implementation = reinterpret_cast<const Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t _value{};

            uint32_t result = implementation->Get(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<int32_t>(_value);
        },

        // (8) virtual uint32_t Set(const int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal* implementation = reinterpret_cast<Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _value = reader.Number<int32_t>();

            uint32_t result = implementation->Set(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual void Evaluate() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal* implementation = reinterpret_cast<Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Evaluate();
        },

        // (10) virtual string Metadata() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IExternal* implementation = reinterpret_cast<const Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Metadata();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // ExchangeExternalStubMethods

    //
    // Exchange::IExternal::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Update(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeExternalNotificationStubMethods[] = {
        // (0) virtual void Update(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::INotification* implementation = reinterpret_cast<Exchange::IExternal::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            implementation->Update(_id);
        }
        , nullptr
    }; // ExchangeExternalNotificationStubMethods

    //
    // Exchange::IExternal::ICatalog interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IExternal::ICatalog::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IExternal::ICatalog::INotification*) = 0
    //  (2) virtual Exchange::IExternal* Resource(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeExternalCatalogStubMethods[] = {
        // (0) virtual void Register(Exchange::IExternal::ICatalog::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog* implementation = reinterpret_cast<Exchange::IExternal::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IExternal::ICatalog::INotification* _sink = nullptr;
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

        // (1) virtual void Unregister(Exchange::IExternal::ICatalog::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog* implementation = reinterpret_cast<Exchange::IExternal::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IExternal::ICatalog::INotification* _sink = nullptr;
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

        // (2) virtual Exchange::IExternal* Resource(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog* implementation = reinterpret_cast<Exchange::IExternal::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            Exchange::IExternal* result = implementation->Resource(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeExternalCatalogStubMethods

    //
    // Exchange::IExternal::ICatalog::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Activated(Exchange::IExternal*) = 0
    //  (1) virtual void Deactivated(Exchange::IExternal*) = 0
    //

    ProxyStub::MethodHandler ExchangeExternalCatalogNotificationStubMethods[] = {
        // (0) virtual void Activated(Exchange::IExternal*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog::INotification* implementation = reinterpret_cast<Exchange::IExternal::ICatalog::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sourceImplementation = reader.Number<Core::instance_id>();

            Exchange::IExternal* _source = nullptr;
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

        // (1) virtual void Deactivated(Exchange::IExternal*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog::INotification* implementation = reinterpret_cast<Exchange::IExternal::ICatalog::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sourceImplementation = reader.Number<Core::instance_id>();

            Exchange::IExternal* _source = nullptr;
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
    }; // ExchangeExternalCatalogNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IExternal interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IExternal::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IExternal::INotification*) = 0
    //  (2) virtual Exchange::IExternal::condition Condition() const = 0
    //  (3) virtual uint32_t Identifier() const = 0
    //  (4) virtual uint32_t Type() const = 0
    //  (5) virtual int32_t Minimum() const = 0
    //  (6) virtual int32_t Maximum() const = 0
    //  (7) virtual uint32_t Get(int32_t&) const = 0
    //  (8) virtual uint32_t Set(const int32_t) = 0
    //  (9) virtual void Evaluate() = 0
    //  (10) virtual string Metadata() const = 0
    //

    class ExchangeExternalProxy final : public ProxyStub::UnknownProxyType<Exchange::IExternal> {
    public:
        ExchangeExternalProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IExternal::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IExternal::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        Exchange::IExternal::condition Condition() const override
        {
            IPCMessage message(BaseClass::Message(2));

            Exchange::IExternal::condition result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IExternal::condition>();

            return (result);
        }

        uint32_t Identifier() const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Type() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        int32_t Minimum() const override
        {
            IPCMessage message(BaseClass::Message(5));

            int32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<int32_t>();

            return (result);
        }

        int32_t Maximum() const override
        {
            IPCMessage message(BaseClass::Message(6));

            int32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<int32_t>();

            return (result);
        }

        uint32_t Get(int32_t& _value) const override
        {
            IPCMessage message(BaseClass::Message(7));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Number<int32_t>();

            return (result);
        }

        uint32_t Set(const int32_t _value) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_value);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        void Evaluate() override
        {
            IPCMessage message(BaseClass::Message(9));

            UnknownProxyType::Invoke(message);
        }

        string Metadata() const override
        {
            IPCMessage message(BaseClass::Message(10));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class ExchangeExternalProxy

    //
    // Exchange::IExternal::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Update(const uint32_t) = 0
    //

    class ExchangeExternalNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IExternal::INotification> {
    public:
        ExchangeExternalNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class ExchangeExternalNotificationProxy

    //
    // Exchange::IExternal::ICatalog interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IExternal::ICatalog::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IExternal::ICatalog::INotification*) = 0
    //  (2) virtual Exchange::IExternal* Resource(const uint32_t) = 0
    //

    class ExchangeExternalCatalogProxy final : public ProxyStub::UnknownProxyType<Exchange::IExternal::ICatalog> {
    public:
        ExchangeExternalCatalogProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IExternal::ICatalog::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IExternal::ICatalog::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        Exchange::IExternal* Resource(const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Exchange::IExternal* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IExternal*>(Interface(reader.Number<Core::instance_id>(), Exchange::IExternal::ID));

            return (result);
        }

    }; // class ExchangeExternalCatalogProxy

    //
    // Exchange::IExternal::ICatalog::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Activated(Exchange::IExternal*) = 0
    //  (1) virtual void Deactivated(Exchange::IExternal*) = 0
    //

    class ExchangeExternalCatalogNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IExternal::ICatalog::INotification> {
    public:
        ExchangeExternalCatalogNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Activated(Exchange::IExternal* _source) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_source));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Deactivated(Exchange::IExternal* _source) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_source));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeExternalCatalogNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IExternal, ExchangeExternalStubMethods> ExchangeExternalStub;
        typedef ProxyStub::UnknownStubType<Exchange::IExternal::INotification, ExchangeExternalNotificationStubMethods> ExchangeExternalNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IExternal::ICatalog, ExchangeExternalCatalogStubMethods> ExchangeExternalCatalogStub;
        typedef ProxyStub::UnknownStubType<Exchange::IExternal::ICatalog::INotification, ExchangeExternalCatalogNotificationStubMethods> ExchangeExternalCatalogNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IExternal, ExchangeExternalProxy, ExchangeExternalStub>();
                RPC::Administrator::Instance().Announce<Exchange::IExternal::INotification, ExchangeExternalNotificationProxy, ExchangeExternalNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IExternal::ICatalog, ExchangeExternalCatalogProxy, ExchangeExternalCatalogStub>();
                RPC::Administrator::Instance().Announce<Exchange::IExternal::ICatalog::INotification, ExchangeExternalCatalogNotificationProxy, ExchangeExternalCatalogNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IExternal>();
                RPC::Administrator::Instance().Recall<Exchange::IExternal::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IExternal::ICatalog>();
                RPC::Administrator::Instance().Recall<Exchange::IExternal::ICatalog::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
