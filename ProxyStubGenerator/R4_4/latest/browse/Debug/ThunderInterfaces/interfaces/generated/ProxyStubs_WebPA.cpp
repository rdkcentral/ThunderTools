//
// generated automatically from "IWebPA.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IWebPA
//   - class Exchange::IWebPA::IWebPAClient
//

#include "Module.h"
#include "IWebPA.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IWebPA interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Initialize(PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialize(PluginHost::IShell*) = 0
    //  (2) virtual Exchange::IWebPA::IWebPAClient* Client(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeWebPAStubMethods[] = {
        // (0) virtual uint32_t Initialize(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebPA* implementation = reinterpret_cast<Exchange::IWebPA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_0023ef11Implementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_0023ef11 = nullptr;
            ProxyStub::UnknownProxy* parameter_0023ef11Proxy = nullptr;
            if (parameter_0023ef11Implementation != 0) {
                parameter_0023ef11Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_0023ef11Implementation, false, _parameter_0023ef11);

                ASSERT((_parameter_0023ef11 != nullptr) && (parameter_0023ef11Proxy != nullptr));
            }

            uint32_t result = implementation->Initialize(_parameter_0023ef11);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_0023ef11Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_0023ef11Proxy, message->Response());
            }
        },

        // (1) virtual void Deinitialize(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebPA* implementation = reinterpret_cast<Exchange::IWebPA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_5a0b0490Implementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_5a0b0490 = nullptr;
            ProxyStub::UnknownProxy* parameter_5a0b0490Proxy = nullptr;
            if (parameter_5a0b0490Implementation != 0) {
                parameter_5a0b0490Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_5a0b0490Implementation, false, _parameter_5a0b0490);

                ASSERT((_parameter_5a0b0490 != nullptr) && (parameter_5a0b0490Proxy != nullptr));
            }

            implementation->Deinitialize(_parameter_5a0b0490);

            if (parameter_5a0b0490Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_5a0b0490Proxy, message->Response());
            }
        },

        // (2) virtual Exchange::IWebPA::IWebPAClient* Client(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebPA* implementation = reinterpret_cast<Exchange::IWebPA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::IWebPA::IWebPAClient* result = implementation->Client(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeWebPAStubMethods

    //
    // Exchange::IWebPA::IWebPAClient interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual uint32_t Launch() = 0
    //

    ProxyStub::MethodHandler ExchangeWebPAWebPAClientStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebPA::IWebPAClient* implementation = reinterpret_cast<Exchange::IWebPA::IWebPAClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_9fc01659Implementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_9fc01659 = nullptr;
            ProxyStub::UnknownProxy* parameter_9fc01659Proxy = nullptr;
            if (parameter_9fc01659Implementation != 0) {
                parameter_9fc01659Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_9fc01659Implementation, false, _parameter_9fc01659);

                ASSERT((_parameter_9fc01659 != nullptr) && (parameter_9fc01659Proxy != nullptr));
            }

            uint32_t result = implementation->Configure(_parameter_9fc01659);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_9fc01659Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_9fc01659Proxy, message->Response());
            }
        },

        // (1) virtual uint32_t Launch() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebPA::IWebPAClient* implementation = reinterpret_cast<Exchange::IWebPA::IWebPAClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Launch();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeWebPAWebPAClientStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IWebPA interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Initialize(PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialize(PluginHost::IShell*) = 0
    //  (2) virtual Exchange::IWebPA::IWebPAClient* Client(const string&) = 0
    //

    class ExchangeWebPAProxy final : public ProxyStub::UnknownProxyType<Exchange::IWebPA> {
    public:
        ExchangeWebPAProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Initialize(PluginHost::IShell* _parameter_0023ef11) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_0023ef11));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        void Deinitialize(PluginHost::IShell* _parameter_5a0b0490) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_5a0b0490));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        Exchange::IWebPA::IWebPAClient* Client(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::IWebPA::IWebPAClient* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IWebPA::IWebPAClient*>(Interface(reader.Number<Core::instance_id>(), Exchange::IWebPA::IWebPAClient::ID));

            return (result);
        }

    }; // class ExchangeWebPAProxy

    //
    // Exchange::IWebPA::IWebPAClient interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual uint32_t Launch() = 0
    //

    class ExchangeWebPAWebPAClientProxy final : public ProxyStub::UnknownProxyType<Exchange::IWebPA::IWebPAClient> {
    public:
        ExchangeWebPAWebPAClientProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Configure(PluginHost::IShell* _parameter_9fc01659) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_9fc01659));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Launch() override
        {
            IPCMessage message(BaseClass::Message(1));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeWebPAWebPAClientProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IWebPA, ExchangeWebPAStubMethods> ExchangeWebPAStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWebPA::IWebPAClient, ExchangeWebPAWebPAClientStubMethods> ExchangeWebPAWebPAClientStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IWebPA, ExchangeWebPAProxy, ExchangeWebPAStub>();
                RPC::Administrator::Instance().Announce<Exchange::IWebPA::IWebPAClient, ExchangeWebPAWebPAClientProxy, ExchangeWebPAWebPAClientStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IWebPA>();
                RPC::Administrator::Instance().Recall<Exchange::IWebPA::IWebPAClient>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
