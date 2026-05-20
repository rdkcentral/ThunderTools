//
// generated automatically from "IAmazonPrime.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IAmazonPrime
//   - class Exchange::IAmazonPrime::INotification
//

#include "Module.h"
#include "IAmazonPrime.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IAmazonPrime interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IAmazonPrime::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IAmazonPrime::INotification*) = 0
    //  (2) virtual uint32_t Send(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeAmazonPrimeStubMethods[] = {
        // (0) virtual void Register(Exchange::IAmazonPrime::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAmazonPrime* implementation = reinterpret_cast<Exchange::IAmazonPrime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id ignitionImplementation = reader.Number<Core::instance_id>();

            Exchange::IAmazonPrime::INotification* _ignition = nullptr;
            ProxyStub::UnknownProxy* ignitionProxy = nullptr;
            if (ignitionImplementation != 0) {
                ignitionProxy = RPC::Administrator::Instance().ProxyInstance(channel, ignitionImplementation, false, _ignition);

                ASSERT((_ignition != nullptr) && (ignitionProxy != nullptr));
            }

            implementation->Register(_ignition);

            if (ignitionProxy != nullptr) {
                RPC::Administrator::Instance().Release(ignitionProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IAmazonPrime::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAmazonPrime* implementation = reinterpret_cast<Exchange::IAmazonPrime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id ignitionImplementation = reader.Number<Core::instance_id>();

            Exchange::IAmazonPrime::INotification* _ignition = nullptr;
            ProxyStub::UnknownProxy* ignitionProxy = nullptr;
            if (ignitionImplementation != 0) {
                ignitionProxy = RPC::Administrator::Instance().ProxyInstance(channel, ignitionImplementation, false, _ignition);

                ASSERT((_ignition != nullptr) && (ignitionProxy != nullptr));
            }

            implementation->Unregister(_ignition);

            if (ignitionProxy != nullptr) {
                RPC::Administrator::Instance().Release(ignitionProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Send(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAmazonPrime* implementation = reinterpret_cast<Exchange::IAmazonPrime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _message = reader.Text();

            uint32_t result = implementation->Send(static_cast<const string&>(_message));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeAmazonPrimeStubMethods

    //
    // Exchange::IAmazonPrime::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Receive(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeAmazonPrimeNotificationStubMethods[] = {
        // (0) virtual void Receive(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAmazonPrime::INotification* implementation = reinterpret_cast<Exchange::IAmazonPrime::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _message = reader.Text();

            implementation->Receive(static_cast<const string&>(_message));
        }
        , nullptr
    }; // ExchangeAmazonPrimeNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IAmazonPrime interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IAmazonPrime::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IAmazonPrime::INotification*) = 0
    //  (2) virtual uint32_t Send(const string&) = 0
    //

    class ExchangeAmazonPrimeProxy final : public ProxyStub::UnknownProxyType<Exchange::IAmazonPrime> {
    public:
        ExchangeAmazonPrimeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IAmazonPrime::INotification* _ignition) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_ignition));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IAmazonPrime::INotification* _ignition) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_ignition));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Send(const string& _message) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_message));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeAmazonPrimeProxy

    //
    // Exchange::IAmazonPrime::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Receive(const string&) = 0
    //

    class ExchangeAmazonPrimeNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IAmazonPrime::INotification> {
    public:
        ExchangeAmazonPrimeNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Receive(const string& _message) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_message));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeAmazonPrimeNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IAmazonPrime, ExchangeAmazonPrimeStubMethods> ExchangeAmazonPrimeStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAmazonPrime::INotification, ExchangeAmazonPrimeNotificationStubMethods> ExchangeAmazonPrimeNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IAmazonPrime, ExchangeAmazonPrimeProxy, ExchangeAmazonPrimeStub>();
                RPC::Administrator::Instance().Announce<Exchange::IAmazonPrime::INotification, ExchangeAmazonPrimeNotificationProxy, ExchangeAmazonPrimeNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IAmazonPrime>();
                RPC::Administrator::Instance().Recall<Exchange::IAmazonPrime::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
