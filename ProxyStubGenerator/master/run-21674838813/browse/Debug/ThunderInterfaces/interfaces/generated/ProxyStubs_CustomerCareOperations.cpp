//
// generated automatically from "ICustomerCareOperations.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ICustomerCareOperations
//

#include "Module.h"
#include "ICustomerCareOperations.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ICustomerCareOperations interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t FactoryReset() = 0
    //

    static ProxyStub::MethodHandler ExchangeCustomerCareOperationsStubMethods[] = {
        // (0) virtual uint32_t FactoryReset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ICustomerCareOperations* implementation = reinterpret_cast<Exchange::ICustomerCareOperations*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->FactoryReset();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeCustomerCareOperationsStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ICustomerCareOperations interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t FactoryReset() = 0
    //

    class ExchangeCustomerCareOperationsProxy final : public ProxyStub::UnknownProxyType<Exchange::ICustomerCareOperations> {
    public:
        ExchangeCustomerCareOperationsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t FactoryReset() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeCustomerCareOperationsProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ICustomerCareOperations, ExchangeCustomerCareOperationsStubMethods> ExchangeCustomerCareOperationsStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ICustomerCareOperations, ExchangeCustomerCareOperationsProxy, ExchangeCustomerCareOperationsStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ICustomerCareOperations>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
