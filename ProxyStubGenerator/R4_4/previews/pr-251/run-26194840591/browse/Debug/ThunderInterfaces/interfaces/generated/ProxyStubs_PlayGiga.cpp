//
// generated automatically from "IPlayGiga.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IPlayGiga
//

#include "Module.h"
#include "IPlayGiga.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IPlayGiga interface stub definitions
    //
    // Methods:
    //  (0) virtual void Launch(const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangePlayGigaStubMethods[] = {
        // (0) virtual void Launch(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPlayGiga* implementation = reinterpret_cast<Exchange::IPlayGiga*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_fe6ff838 = reader.Text();
            const string _parameter_ab5d0321 = reader.Text();

            implementation->Launch(static_cast<const string&>(_parameter_fe6ff838), static_cast<const string&>(_parameter_ab5d0321));
        }
        , nullptr
    }; // ExchangePlayGigaStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IPlayGiga interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Launch(const string&, const string&) = 0
    //

    class ExchangePlayGigaProxy final : public ProxyStub::UnknownProxyType<Exchange::IPlayGiga> {
    public:
        ExchangePlayGigaProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Launch(const string& _parameter_fe6ff838, const string& _parameter_ab5d0321) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_fe6ff838));
            writer.Text(static_cast<const string&>(_parameter_ab5d0321));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangePlayGigaProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IPlayGiga, ExchangePlayGigaStubMethods> ExchangePlayGigaStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IPlayGiga, ExchangePlayGigaProxy, ExchangePlayGigaStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IPlayGiga>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
