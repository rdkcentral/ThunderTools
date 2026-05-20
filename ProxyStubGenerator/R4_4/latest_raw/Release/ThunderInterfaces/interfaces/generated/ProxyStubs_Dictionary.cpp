//
// generated automatically from "IDictionary.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IDictionary
//   - class Exchange::IDictionary::INotification
//   - class Exchange::IDictionary::IIterator
//

#include "Module.h"
#include "IDictionary.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IDictionary interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(const string&, Exchange::IDictionary::INotification*) = 0
    //  (1) virtual void Unregister(const string&, Exchange::IDictionary::INotification*) = 0
    //  (2) virtual bool Get(const string&, const string&, string&) const = 0
    //  (3) virtual bool Set(const string&, const string&, const string&) = 0
    //  (4) virtual Exchange::IDictionary::IIterator* Get(const string&) const = 0
    //

    ProxyStub::MethodHandler ExchangeDictionaryStubMethods[] = {
        // (0) virtual void Register(const string&, Exchange::IDictionary::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDictionary* implementation = reinterpret_cast<Exchange::IDictionary*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _nameSpace = reader.Text();
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IDictionary::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Register(static_cast<const string&>(_nameSpace), _sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(const string&, Exchange::IDictionary::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDictionary* implementation = reinterpret_cast<Exchange::IDictionary*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _nameSpace = reader.Text();
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IDictionary::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Unregister(static_cast<const string&>(_nameSpace), _sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (2) virtual bool Get(const string&, const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDictionary* implementation = reinterpret_cast<const Exchange::IDictionary*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _nameSpace = reader.Text();
            const string _key = reader.Text();

            string _value{};

            bool result = implementation->Get(static_cast<const string&>(_nameSpace), static_cast<const string&>(_key), _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_value);
        },

        // (3) virtual bool Set(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDictionary* implementation = reinterpret_cast<Exchange::IDictionary*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _nameSpace = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();

            bool result = implementation->Set(static_cast<const string&>(_nameSpace), static_cast<const string&>(_key), static_cast<const string&>(_value));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual Exchange::IDictionary::IIterator* Get(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDictionary* implementation = reinterpret_cast<const Exchange::IDictionary*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _nameSpace = reader.Text();

            Exchange::IDictionary::IIterator* result = implementation->Get(static_cast<const string&>(_nameSpace));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeDictionaryStubMethods

    //
    // Exchange::IDictionary::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Modified(const string&, const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeDictionaryNotificationStubMethods[] = {
        // (0) virtual void Modified(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDictionary::INotification* implementation = reinterpret_cast<Exchange::IDictionary::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _nameSpace = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();

            implementation->Modified(static_cast<const string&>(_nameSpace), static_cast<const string&>(_key), static_cast<const string&>(_value));
        }
        , nullptr
    }; // ExchangeDictionaryNotificationStubMethods

    //
    // Exchange::IDictionary::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual const string Key() const = 0
    //  (4) virtual const string Value() const = 0
    //

    ProxyStub::MethodHandler ExchangeDictionaryIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDictionary::IIterator* implementation = reinterpret_cast<Exchange::IDictionary::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDictionary::IIterator* implementation = reinterpret_cast<const Exchange::IDictionary::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDictionary::IIterator* implementation = reinterpret_cast<Exchange::IDictionary::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual const string Key() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDictionary::IIterator* implementation = reinterpret_cast<const Exchange::IDictionary::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            const string result = implementation->Key();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual const string Value() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDictionary::IIterator* implementation = reinterpret_cast<const Exchange::IDictionary::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            const string result = implementation->Value();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // ExchangeDictionaryIteratorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IDictionary interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(const string&, Exchange::IDictionary::INotification*) = 0
    //  (1) virtual void Unregister(const string&, Exchange::IDictionary::INotification*) = 0
    //  (2) virtual bool Get(const string&, const string&, string&) const = 0
    //  (3) virtual bool Set(const string&, const string&, const string&) = 0
    //  (4) virtual Exchange::IDictionary::IIterator* Get(const string&) const = 0
    //

    class ExchangeDictionaryProxy final : public ProxyStub::UnknownProxyType<Exchange::IDictionary> {
    public:
        ExchangeDictionaryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(const string& _nameSpace, Exchange::IDictionary::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_nameSpace));
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(const string& _nameSpace, Exchange::IDictionary::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_nameSpace));
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        bool Get(const string& _nameSpace, const string& _key, string& _value) const override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_nameSpace));
            writer.Text(static_cast<const string&>(_key));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _value = reader.Text();

            return (result);
        }

        bool Set(const string& _nameSpace, const string& _key, const string& _value) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_nameSpace));
            writer.Text(static_cast<const string&>(_key));
            writer.Text(static_cast<const string&>(_value));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Exchange::IDictionary::IIterator* Get(const string& _nameSpace) const override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_nameSpace));

            Exchange::IDictionary::IIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IDictionary::IIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDictionary::IIterator::ID));

            return (result);
        }

    }; // class ExchangeDictionaryProxy

    //
    // Exchange::IDictionary::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Modified(const string&, const string&, const string&) = 0
    //

    class ExchangeDictionaryNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IDictionary::INotification> {
    public:
        ExchangeDictionaryNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Modified(const string& _nameSpace, const string& _key, const string& _value) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_nameSpace));
            writer.Text(static_cast<const string&>(_key));
            writer.Text(static_cast<const string&>(_value));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeDictionaryNotificationProxy

    //
    // Exchange::IDictionary::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual const string Key() const = 0
    //  (4) virtual const string Value() const = 0
    //

    class ExchangeDictionaryIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::IDictionary::IIterator> {
    public:
        ExchangeDictionaryIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Reset() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool Next() override
        {
            IPCMessage message(BaseClass::Message(2));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        const string Key() const override
        {
            IPCMessage message(BaseClass::Message(3));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        const string Value() const override
        {
            IPCMessage message(BaseClass::Message(4));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class ExchangeDictionaryIteratorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IDictionary, ExchangeDictionaryStubMethods> ExchangeDictionaryStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDictionary::INotification, ExchangeDictionaryNotificationStubMethods> ExchangeDictionaryNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDictionary::IIterator, ExchangeDictionaryIteratorStubMethods> ExchangeDictionaryIteratorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IDictionary, ExchangeDictionaryProxy, ExchangeDictionaryStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDictionary::INotification, ExchangeDictionaryNotificationProxy, ExchangeDictionaryNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDictionary::IIterator, ExchangeDictionaryIteratorProxy, ExchangeDictionaryIteratorStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IDictionary>();
                RPC::Administrator::Instance().Recall<Exchange::IDictionary::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IDictionary::IIterator>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
