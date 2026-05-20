//
// generated automatically from "IWatchDog.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IWatchDog
//

#include "Module.h"
#include "IWatchDog.h"

#include <com/com.h>

namespace WPEFramework {

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

    ProxyStub::MethodHandler ExchangeWatchDogStubMethods[] = {
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

        uint32_t Touch(const string& _callsign) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
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
