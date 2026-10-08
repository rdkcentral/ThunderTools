//
// generated automatically from "IPlayGiga.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IPlayGiga
//

#include "Module.h"
#include "IPlayGiga.h"

#include <com/com.h>

namespace Thunder {

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

    static ProxyStub::MethodHandler ExchangePlayGigaStubMethods[] = {
        // (0) virtual void Launch(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPlayGiga* implementation = reinterpret_cast<Exchange::IPlayGiga*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_914ebde3 = reader.Text();
            const string _parameter_872a8334 = reader.Text();

            implementation->Launch(static_cast<const string&>(_parameter_914ebde3), static_cast<const string&>(_parameter_872a8334));
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

        void Launch(const string& _parameter_914ebde3, const string& _parameter_872a8334) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_parameter_914ebde3);
            writer.Text(_parameter_872a8334);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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
