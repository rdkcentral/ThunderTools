//
// generated automatically from "IButler.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IButler
//   - class Exchange::IButler::INotification
//

#include "Module.h"
#include "IButler.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IButler interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IButler::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IButler::INotification*) = 0
    //  (2) virtual Exchange::IValuePoint* Element(const string&) = 0
    //  (3) virtual Exchange::IValuePoint* Element(const uint32_t) = 0
    //  (4) virtual string Source(const uint32_t) const = 0
    //  (5) virtual uint32_t Branch(const string&) = 0
    //  (6) virtual uint32_t Link(const string&, const uint32_t) = 0
    //  (7) virtual uint32_t Move(const string&, const string&) = 0
    //  (8) virtual uint32_t Delete(const string&) = 0
    //  (9) virtual RPC::IValueIterator* Orphans(const uint8_t) const = 0
    //

    ProxyStub::MethodHandler ExchangeButlerStubMethods[] = {
        // (0) virtual void Register(Exchange::IButler::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IButler::INotification* _sink = nullptr;
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

        // (1) virtual void Unregister(Exchange::IButler::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IButler::INotification* _sink = nullptr;
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

        // (2) virtual Exchange::IValuePoint* Element(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::IValuePoint* result = implementation->Element(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (3) virtual Exchange::IValuePoint* Element(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            Exchange::IValuePoint* result = implementation->Element(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (4) virtual string Source(const uint32_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IButler* implementation = reinterpret_cast<const Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _module = reader.Number<uint32_t>();

            string result = implementation->Source(_module);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (5) virtual uint32_t Branch(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _path = reader.Text();

            uint32_t result = implementation->Branch(static_cast<const string&>(_path));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t Link(const string&, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _path = reader.Text();
            const uint32_t _id = reader.Number<uint32_t>();

            uint32_t result = implementation->Link(static_cast<const string&>(_path), _id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t Move(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _path = reader.Text();
            const string _newName = reader.Text();

            uint32_t result = implementation->Move(static_cast<const string&>(_path), static_cast<const string&>(_newName));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (8) virtual uint32_t Delete(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler* implementation = reinterpret_cast<Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _path = reader.Text();

            uint32_t result = implementation->Delete(static_cast<const string&>(_path));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual RPC::IValueIterator* Orphans(const uint8_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IButler* implementation = reinterpret_cast<const Exchange::IButler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _module = reader.Number<uint8_t>();

            RPC::IValueIterator* result = implementation->Orphans(_module);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeButlerStubMethods

    //
    // Exchange::IButler::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Added(Exchange::IValuePoint*) = 0
    //  (1) virtual void Removed(Exchange::IValuePoint*) = 0
    //  (2) virtual void Updated(Exchange::IValuePoint*) = 0
    //  (3) virtual void Metadata(Exchange::IValuePoint*) = 0
    //

    ProxyStub::MethodHandler ExchangeButlerNotificationStubMethods[] = {
        // (0) virtual void Added(Exchange::IValuePoint*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler::INotification* implementation = reinterpret_cast<Exchange::IButler::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id elementImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint* _element = nullptr;
            ProxyStub::UnknownProxy* elementProxy = nullptr;
            if (elementImplementation != 0) {
                elementProxy = RPC::Administrator::Instance().ProxyInstance(channel, elementImplementation, false, _element);

                ASSERT((_element != nullptr) && (elementProxy != nullptr));
            }

            implementation->Added(_element);

            if (elementProxy != nullptr) {
                RPC::Administrator::Instance().Release(elementProxy, message->Response());
            }
        },

        // (1) virtual void Removed(Exchange::IValuePoint*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler::INotification* implementation = reinterpret_cast<Exchange::IButler::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id elementImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint* _element = nullptr;
            ProxyStub::UnknownProxy* elementProxy = nullptr;
            if (elementImplementation != 0) {
                elementProxy = RPC::Administrator::Instance().ProxyInstance(channel, elementImplementation, false, _element);

                ASSERT((_element != nullptr) && (elementProxy != nullptr));
            }

            implementation->Removed(_element);

            if (elementProxy != nullptr) {
                RPC::Administrator::Instance().Release(elementProxy, message->Response());
            }
        },

        // (2) virtual void Updated(Exchange::IValuePoint*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler::INotification* implementation = reinterpret_cast<Exchange::IButler::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id elementImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint* _element = nullptr;
            ProxyStub::UnknownProxy* elementProxy = nullptr;
            if (elementImplementation != 0) {
                elementProxy = RPC::Administrator::Instance().ProxyInstance(channel, elementImplementation, false, _element);

                ASSERT((_element != nullptr) && (elementProxy != nullptr));
            }

            implementation->Updated(_element);

            if (elementProxy != nullptr) {
                RPC::Administrator::Instance().Release(elementProxy, message->Response());
            }
        },

        // (3) virtual void Metadata(Exchange::IValuePoint*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IButler::INotification* implementation = reinterpret_cast<Exchange::IButler::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id elementImplementation = reader.Number<Core::instance_id>();

            Exchange::IValuePoint* _element = nullptr;
            ProxyStub::UnknownProxy* elementProxy = nullptr;
            if (elementImplementation != 0) {
                elementProxy = RPC::Administrator::Instance().ProxyInstance(channel, elementImplementation, false, _element);

                ASSERT((_element != nullptr) && (elementProxy != nullptr));
            }

            implementation->Metadata(_element);

            if (elementProxy != nullptr) {
                RPC::Administrator::Instance().Release(elementProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeButlerNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IButler interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IButler::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IButler::INotification*) = 0
    //  (2) virtual Exchange::IValuePoint* Element(const string&) = 0
    //  (3) virtual Exchange::IValuePoint* Element(const uint32_t) = 0
    //  (4) virtual string Source(const uint32_t) const = 0
    //  (5) virtual uint32_t Branch(const string&) = 0
    //  (6) virtual uint32_t Link(const string&, const uint32_t) = 0
    //  (7) virtual uint32_t Move(const string&, const string&) = 0
    //  (8) virtual uint32_t Delete(const string&) = 0
    //  (9) virtual RPC::IValueIterator* Orphans(const uint8_t) const = 0
    //

    class ExchangeButlerProxy final : public ProxyStub::UnknownProxyType<Exchange::IButler> {
    public:
        ExchangeButlerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IButler::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IButler::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        Exchange::IValuePoint* Element(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::IValuePoint* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IValuePoint*>(Interface(reader.Number<Core::instance_id>(), Exchange::IValuePoint::ID));

            return (result);
        }

        Exchange::IValuePoint* Element(const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Exchange::IValuePoint* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IValuePoint*>(Interface(reader.Number<Core::instance_id>(), Exchange::IValuePoint::ID));

            return (result);
        }

        string Source(const uint32_t _module) const override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_module);

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        uint32_t Branch(const string& _path) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_path));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Link(const string& _path, const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_path));
            writer.Number<uint32_t>(_id);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Move(const string& _path, const string& _newName) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_path));
            writer.Text(static_cast<const string&>(_newName));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Delete(const string& _path) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_path));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        RPC::IValueIterator* Orphans(const uint8_t _module) const override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_module);

            RPC::IValueIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<RPC::IValueIterator*>(Interface(reader.Number<Core::instance_id>(), RPC::IValueIterator::ID));

            return (result);
        }

    }; // class ExchangeButlerProxy

    //
    // Exchange::IButler::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Added(Exchange::IValuePoint*) = 0
    //  (1) virtual void Removed(Exchange::IValuePoint*) = 0
    //  (2) virtual void Updated(Exchange::IValuePoint*) = 0
    //  (3) virtual void Metadata(Exchange::IValuePoint*) = 0
    //

    class ExchangeButlerNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IButler::INotification> {
    public:
        ExchangeButlerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Added(Exchange::IValuePoint* _element) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_element));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Removed(Exchange::IValuePoint* _element) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_element));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Updated(Exchange::IValuePoint* _element) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_element));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Metadata(Exchange::IValuePoint* _element) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_element));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeButlerNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IButler, ExchangeButlerStubMethods> ExchangeButlerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IButler::INotification, ExchangeButlerNotificationStubMethods> ExchangeButlerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IButler, ExchangeButlerProxy, ExchangeButlerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IButler::INotification, ExchangeButlerNotificationProxy, ExchangeButlerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IButler>();
                RPC::Administrator::Instance().Recall<Exchange::IButler::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
