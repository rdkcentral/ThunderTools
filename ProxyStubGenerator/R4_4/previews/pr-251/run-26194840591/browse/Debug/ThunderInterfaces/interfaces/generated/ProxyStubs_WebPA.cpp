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
            const Core::instance_id parameter_657fcfd1Implementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_657fcfd1 = nullptr;
            ProxyStub::UnknownProxy* parameter_657fcfd1Proxy = nullptr;
            if (parameter_657fcfd1Implementation != 0) {
                parameter_657fcfd1Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_657fcfd1Implementation, false, _parameter_657fcfd1);

                ASSERT((_parameter_657fcfd1 != nullptr) && (parameter_657fcfd1Proxy != nullptr));
            }

            uint32_t result = implementation->Initialize(_parameter_657fcfd1);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_657fcfd1Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_657fcfd1Proxy, message->Response());
            }
        },

        // (1) virtual void Deinitialize(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebPA* implementation = reinterpret_cast<Exchange::IWebPA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_047125a1Implementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_047125a1 = nullptr;
            ProxyStub::UnknownProxy* parameter_047125a1Proxy = nullptr;
            if (parameter_047125a1Implementation != 0) {
                parameter_047125a1Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_047125a1Implementation, false, _parameter_047125a1);

                ASSERT((_parameter_047125a1 != nullptr) && (parameter_047125a1Proxy != nullptr));
            }

            implementation->Deinitialize(_parameter_047125a1);

            if (parameter_047125a1Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_047125a1Proxy, message->Response());
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
            const Core::instance_id parameter_0dd1a3e9Implementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_0dd1a3e9 = nullptr;
            ProxyStub::UnknownProxy* parameter_0dd1a3e9Proxy = nullptr;
            if (parameter_0dd1a3e9Implementation != 0) {
                parameter_0dd1a3e9Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_0dd1a3e9Implementation, false, _parameter_0dd1a3e9);

                ASSERT((_parameter_0dd1a3e9 != nullptr) && (parameter_0dd1a3e9Proxy != nullptr));
            }

            uint32_t result = implementation->Configure(_parameter_0dd1a3e9);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_0dd1a3e9Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_0dd1a3e9Proxy, message->Response());
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

        uint32_t Initialize(PluginHost::IShell* _parameter_657fcfd1) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_657fcfd1));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        void Deinitialize(PluginHost::IShell* _parameter_047125a1) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_047125a1));

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

        uint32_t Configure(PluginHost::IShell* _parameter_0dd1a3e9) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_0dd1a3e9));

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
