//
// generated automatically from "IResourceMonitor.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IResourceMonitor
//

#include "Module.h"
#include "IResourceMonitor.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IResourceMonitor interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual string CompileMemoryCsv() = 0
    //

    ProxyStub::MethodHandler ExchangeResourceMonitorStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IResourceMonitor* implementation = reinterpret_cast<Exchange::IResourceMonitor*>(message->Parameters().Implementation());
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
        },

        // (1) virtual string CompileMemoryCsv() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IResourceMonitor* implementation = reinterpret_cast<Exchange::IResourceMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->CompileMemoryCsv();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // ExchangeResourceMonitorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IResourceMonitor interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual string CompileMemoryCsv() = 0
    //

    class ExchangeResourceMonitorProxy final : public ProxyStub::UnknownProxyType<Exchange::IResourceMonitor> {
    public:
        ExchangeResourceMonitorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        string CompileMemoryCsv() override
        {
            IPCMessage message(BaseClass::Message(1));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class ExchangeResourceMonitorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IResourceMonitor, ExchangeResourceMonitorStubMethods> ExchangeResourceMonitorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IResourceMonitor, ExchangeResourceMonitorProxy, ExchangeResourceMonitorStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IResourceMonitor>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
