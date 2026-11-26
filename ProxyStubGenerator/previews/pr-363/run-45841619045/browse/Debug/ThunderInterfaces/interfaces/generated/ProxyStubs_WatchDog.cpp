//
// generated automatically from "IWatchDog.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IWatchDog
//

#include "Module.h"
#include "IWatchDog.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IWatchDog interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Touch(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeWatchDogStubMethods[] = {
        // (0) virtual uint32_t Touch(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWatchDog* implementation = reinterpret_cast<Exchange::IWatchDog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            uint32_t result = implementation->Touch(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeWatchDogStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IWatchDog interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Touch(const string&) = 0
    //

    class ExchangeWatchDogProxy final : public ProxyStub::UnknownProxyType<Exchange::IWatchDog> {
    public:
        ExchangeWatchDogProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Touch(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeWatchDogProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IWatchDog, ExchangeWatchDogStubMethods> ExchangeWatchDogStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IWatchDog, ExchangeWatchDogProxy, ExchangeWatchDogStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IWatchDog>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
