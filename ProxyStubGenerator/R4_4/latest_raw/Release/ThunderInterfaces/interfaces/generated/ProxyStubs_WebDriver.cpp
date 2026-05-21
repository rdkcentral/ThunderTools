//
// generated automatically from "IWebDriver.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IWebDriver
//

#include "Module.h"
#include "IWebDriver.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IWebDriver interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //

    ProxyStub::MethodHandler ExchangeWebDriverStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebDriver* implementation = reinterpret_cast<Exchange::IWebDriver*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id frameworkImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _framework = nullptr;
            ProxyStub::UnknownProxy* frameworkProxy = nullptr;
            if (frameworkImplementation != 0) {
                frameworkProxy = RPC::Administrator::Instance().ProxyInstance(channel, frameworkImplementation, false, _framework);

                ASSERT((_framework != nullptr) && (frameworkProxy != nullptr));
            }

            uint32_t result = implementation->Configure(_framework);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (frameworkProxy != nullptr) {
                RPC::Administrator::Instance().Release(frameworkProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeWebDriverStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IWebDriver interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //

    class ExchangeWebDriverProxy final : public ProxyStub::UnknownProxyType<Exchange::IWebDriver> {
    public:
        ExchangeWebDriverProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Configure(PluginHost::IShell* _framework) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_framework));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

    }; // class ExchangeWebDriverProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IWebDriver, ExchangeWebDriverStubMethods> ExchangeWebDriverStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IWebDriver, ExchangeWebDriverProxy, ExchangeWebDriverStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IWebDriver>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
