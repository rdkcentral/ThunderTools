//
// generated automatically from "IRPCLink.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IRPCLink
//   - class Exchange::IRPCLink::INotification
//

#include "Module.h"
#include "IRPCLink.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IRPCLink interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IRPCLink::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IRPCLink::INotification*) = 0
    //  (2) virtual uint32_t Start(const uint32_t, const string&) = 0
    //  (3) virtual uint32_t Stop() = 0
    //  (4) virtual uint32_t ForceCallback() = 0
    //

    ProxyStub::MethodHandler ExchangeRPCLinkStubMethods[] = {
        // (0) virtual void Register(Exchange::IRPCLink::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRPCLink* implementation = reinterpret_cast<Exchange::IRPCLink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IRPCLink::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            implementation->Register(_notification);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IRPCLink::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRPCLink* implementation = reinterpret_cast<Exchange::IRPCLink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IRPCLink::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            implementation->Unregister(_notification);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Start(const uint32_t, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRPCLink* implementation = reinterpret_cast<Exchange::IRPCLink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();
            const string _name = reader.Text();

            uint32_t result = implementation->Start(_id, static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Stop() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRPCLink* implementation = reinterpret_cast<Exchange::IRPCLink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Stop();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t ForceCallback() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRPCLink* implementation = reinterpret_cast<Exchange::IRPCLink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->ForceCallback();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeRPCLinkStubMethods

    //
    // Exchange::IRPCLink::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Completed(const uint32_t, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeRPCLinkNotificationStubMethods[] = {
        // (0) virtual void Completed(const uint32_t, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRPCLink::INotification* implementation = reinterpret_cast<Exchange::IRPCLink::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();
            const string _name = reader.Text();

            implementation->Completed(_id, static_cast<const string&>(_name));
        }
        , nullptr
    }; // ExchangeRPCLinkNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IRPCLink interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IRPCLink::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IRPCLink::INotification*) = 0
    //  (2) virtual uint32_t Start(const uint32_t, const string&) = 0
    //  (3) virtual uint32_t Stop() = 0
    //  (4) virtual uint32_t ForceCallback() = 0
    //

    class ExchangeRPCLinkProxy final : public ProxyStub::UnknownProxyType<Exchange::IRPCLink> {
    public:
        ExchangeRPCLinkProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IRPCLink::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IRPCLink::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Start(const uint32_t _id, const string& _name) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Text(static_cast<const string&>(_name));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Stop() override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t ForceCallback() override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeRPCLinkProxy

    //
    // Exchange::IRPCLink::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Completed(const uint32_t, const string&) = 0
    //

    class ExchangeRPCLinkNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IRPCLink::INotification> {
    public:
        ExchangeRPCLinkNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Completed(const uint32_t _id, const string& _name) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Text(static_cast<const string&>(_name));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeRPCLinkNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IRPCLink, ExchangeRPCLinkStubMethods> ExchangeRPCLinkStub;
        typedef ProxyStub::UnknownStubType<Exchange::IRPCLink::INotification, ExchangeRPCLinkNotificationStubMethods> ExchangeRPCLinkNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IRPCLink, ExchangeRPCLinkProxy, ExchangeRPCLinkStub>();
                RPC::Administrator::Instance().Announce<Exchange::IRPCLink::INotification, ExchangeRPCLinkNotificationProxy, ExchangeRPCLinkNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IRPCLink>();
                RPC::Administrator::Instance().Recall<Exchange::IRPCLink::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
