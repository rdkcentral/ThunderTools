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

namespace Thunder {

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

    static ProxyStub::MethodHandler ExchangeExternalStubMethods[] = {
        // (0) virtual void Register(Exchange::IExternal::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal* implementation = reinterpret_cast<Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IExternal::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IExternal::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal* implementation = reinterpret_cast<Exchange::IExternal*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IExternal::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
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

    static ProxyStub::MethodHandler ExchangeExternalNotificationStubMethods[] = {
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

    static ProxyStub::MethodHandler ExchangeExternalCatalogStubMethods[] = {
        // (0) virtual void Register(Exchange::IExternal::ICatalog::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog* implementation = reinterpret_cast<Exchange::IExternal::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IExternal::ICatalog::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IExternal::ICatalog::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog* implementation = reinterpret_cast<Exchange::IExternal::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IExternal::ICatalog::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
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

    static ProxyStub::MethodHandler ExchangeExternalCatalogNotificationStubMethods[] = {
        // (0) virtual void Activated(Exchange::IExternal*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog::INotification* implementation = reinterpret_cast<Exchange::IExternal::ICatalog::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sourceInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IExternal* _source{};
            ProxyStub::UnknownProxy* _sourceProxy__ = nullptr;
            if (_sourceInstanceId__ != 0) {
                _sourceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sourceInstanceId__, false, _source);
                ASSERT((_source != nullptr) && (_sourceProxy__ != nullptr));
            }

            implementation->Activated(_source);

            if (_sourceProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sourceProxy__, message->Response());
            }
        },

        // (1) virtual void Deactivated(Exchange::IExternal*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IExternal::ICatalog::INotification* implementation = reinterpret_cast<Exchange::IExternal::ICatalog::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sourceInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IExternal* _source{};
            ProxyStub::UnknownProxy* _sourceProxy__ = nullptr;
            if (_sourceInstanceId__ != 0) {
                _sourceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sourceInstanceId__, false, _source);
                ASSERT((_source != nullptr) && (_sourceProxy__ != nullptr));
            }

            implementation->Deactivated(_source);

            if (_sourceProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sourceProxy__, message->Response());
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

        void Register(Exchange::IExternal::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::IExternal::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        Exchange::IExternal::condition Condition() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Exchange::IExternal::condition result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IExternal::condition>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Identifier() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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

        uint32_t Type() const override
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

        int32_t Minimum() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            int32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<int32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        int32_t Maximum() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            int32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<int32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Get(int32_t& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _value = reader.Number<int32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Set(const int32_t _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_value);

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

        void Evaluate() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        string Metadata() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

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

        void Update(const uint32_t _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

        void Register(Exchange::IExternal::ICatalog::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::IExternal::ICatalog::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        Exchange::IExternal* Resource(const uint32_t _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Exchange::IExternal* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IExternal*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IExternal::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
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

        void Activated(Exchange::IExternal* _source) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_source));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Deactivated(Exchange::IExternal* _source) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_source));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
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
