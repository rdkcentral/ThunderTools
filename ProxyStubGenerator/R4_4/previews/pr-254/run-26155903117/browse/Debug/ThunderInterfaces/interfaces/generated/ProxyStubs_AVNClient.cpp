//
// generated automatically from "IAVNClient.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IAVNClient
//

#include "Module.h"
#include "IAVNClient.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IAVNClient interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual void Launch(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeAVNClientStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVNClient* implementation = reinterpret_cast<Exchange::IAVNClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_cdb6a2a0Implementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_cdb6a2a0 = nullptr;
            ProxyStub::UnknownProxy* parameter_cdb6a2a0Proxy = nullptr;
            if (parameter_cdb6a2a0Implementation != 0) {
                parameter_cdb6a2a0Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_cdb6a2a0Implementation, false, _parameter_cdb6a2a0);

                ASSERT((_parameter_cdb6a2a0 != nullptr) && (parameter_cdb6a2a0Proxy != nullptr));
            }

            uint32_t result = implementation->Configure(_parameter_cdb6a2a0);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_cdb6a2a0Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_cdb6a2a0Proxy, message->Response());
            }
        },

        // (1) virtual void Launch(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVNClient* implementation = reinterpret_cast<Exchange::IAVNClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_4df451c1 = reader.Text();

            implementation->Launch(static_cast<const string&>(_parameter_4df451c1));
        }
        , nullptr
    }; // ExchangeAVNClientStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IAVNClient interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual void Launch(const string&) = 0
    //

    class ExchangeAVNClientProxy final : public ProxyStub::UnknownProxyType<Exchange::IAVNClient> {
    public:
        ExchangeAVNClientProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Configure(PluginHost::IShell* _parameter_cdb6a2a0) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_cdb6a2a0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        void Launch(const string& _parameter_4df451c1) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_4df451c1));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeAVNClientProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IAVNClient, ExchangeAVNClientStubMethods> ExchangeAVNClientStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IAVNClient, ExchangeAVNClientProxy, ExchangeAVNClientStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IAVNClient>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
