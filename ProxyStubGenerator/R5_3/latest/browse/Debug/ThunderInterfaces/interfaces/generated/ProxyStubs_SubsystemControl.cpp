//
// generated automatically from "ISubsystemControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ISubsystemControl
//

#include "Module.h"
#include "ISubsystemControl.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ISubsystemControl interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Activate(const PluginHost::ISubSystem::subsystem, const Core::OptionalType<string>&) = 0
    //

    static ProxyStub::MethodHandler ExchangeSubsystemControlStubMethods[] = {
        // (0) virtual Core::hresult Activate(const PluginHost::ISubSystem::subsystem, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISubsystemControl* implementation = reinterpret_cast<Exchange::ISubsystemControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const PluginHost::ISubSystem::subsystem _subsystem = reader.Number<PluginHost::ISubSystem::subsystem>();
            Core::OptionalType<string> _configuration{};
            if (reader.Boolean() == true) {
                _configuration = reader.Text();
            }

            Core::hresult result = implementation->Activate(_subsystem, static_cast<const Core::OptionalType<string>&>(_configuration));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeSubsystemControlStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ISubsystemControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Activate(const PluginHost::ISubSystem::subsystem, const Core::OptionalType<string>&) = 0
    //

    class ExchangeSubsystemControlProxy final : public ProxyStub::UnknownProxyType<Exchange::ISubsystemControl> {
    public:
        ExchangeSubsystemControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Activate(const PluginHost::ISubSystem::subsystem _subsystem, const Core::OptionalType<string>& _configuration) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<PluginHost::ISubSystem::subsystem>(_subsystem);
            writer.Boolean(_configuration.IsSet());
            if (_configuration.IsSet() == true) {
                writer.Text(_configuration.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeSubsystemControlProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ISubsystemControl, ExchangeSubsystemControlStubMethods> ExchangeSubsystemControlStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ISubsystemControl, ExchangeSubsystemControlProxy, ExchangeSubsystemControlStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ISubsystemControl>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
