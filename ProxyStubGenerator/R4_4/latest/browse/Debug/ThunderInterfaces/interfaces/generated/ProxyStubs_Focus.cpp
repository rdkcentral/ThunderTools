//
// generated automatically from "IFocus.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IFocus
//

#include "Module.h"
#include "IFocus.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IFocus interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Focused(const bool) = 0
    //

    ProxyStub::MethodHandler ExchangeFocusStubMethods[] = {
        // (0) virtual uint32_t Focused(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IFocus* implementation = reinterpret_cast<Exchange::IFocus*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _focused = reader.Boolean();

            uint32_t result = implementation->Focused(_focused);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeFocusStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IFocus interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Focused(const bool) = 0
    //

    class ExchangeFocusProxy final : public ProxyStub::UnknownProxyType<Exchange::IFocus> {
    public:
        ExchangeFocusProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Focused(const bool _focused) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_focused);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeFocusProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IFocus, ExchangeFocusStubMethods> ExchangeFocusStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IFocus, ExchangeFocusProxy, ExchangeFocusStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IFocus>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
