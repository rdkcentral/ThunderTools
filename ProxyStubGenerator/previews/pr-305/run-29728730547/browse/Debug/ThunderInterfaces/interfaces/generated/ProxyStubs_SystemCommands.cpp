//
// generated automatically from "ISystemCommands.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ISystemCommands
//

#include "Module.h"
#include "ISystemCommands.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ISystemCommands interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult USBReset(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeSystemCommandsStubMethods[] = {
        // (0) virtual Core::hresult USBReset(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISystemCommands* implementation = reinterpret_cast<Exchange::ISystemCommands*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _device = reader.Text();

            Core::hresult result = implementation->USBReset(static_cast<const string&>(_device));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeSystemCommandsStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ISystemCommands interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult USBReset(const string&) = 0
    //

    class ExchangeSystemCommandsProxy final : public ProxyStub::UnknownProxyType<Exchange::ISystemCommands> {
    public:
        ExchangeSystemCommandsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult USBReset(const string& _device) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_device);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeSystemCommandsProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ISystemCommands, ExchangeSystemCommandsStubMethods> ExchangeSystemCommandsStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ISystemCommands, ExchangeSystemCommandsProxy, ExchangeSystemCommandsStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ISystemCommands>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
