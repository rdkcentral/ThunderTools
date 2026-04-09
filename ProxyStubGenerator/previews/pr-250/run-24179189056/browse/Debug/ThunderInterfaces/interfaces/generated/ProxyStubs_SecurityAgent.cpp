//
// generated automatically from "ISecurityAgent.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ISecurityAgent
//

#include "Module.h"
#include "ISecurityAgent.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ISecurityAgent interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Validate(const string&, bool&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeSecurityAgentStubMethods[] = {
        // (0) virtual Core::hresult Validate(const string&, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISecurityAgent* implementation = reinterpret_cast<const Exchange::ISecurityAgent*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _token = reader.Text();

            bool _valid{};

            Core::hresult result = implementation->Validate(static_cast<const string&>(_token), _valid);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_valid);
        }
        , nullptr
    }; // ExchangeSecurityAgentStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ISecurityAgent interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Validate(const string&, bool&) const = 0
    //

    class ExchangeSecurityAgentProxy final : public ProxyStub::UnknownProxyType<Exchange::ISecurityAgent> {
    public:
        ExchangeSecurityAgentProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Validate(const string& _token, bool& _valid) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_token);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _valid = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeSecurityAgentProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ISecurityAgent, ExchangeSecurityAgentStubMethods> ExchangeSecurityAgentStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ISecurityAgent, ExchangeSecurityAgentProxy, ExchangeSecurityAgentStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ISecurityAgent>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
