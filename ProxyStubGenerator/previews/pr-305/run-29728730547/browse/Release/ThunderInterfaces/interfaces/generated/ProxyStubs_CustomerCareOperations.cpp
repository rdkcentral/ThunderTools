//
// generated automatically from "ICustomerCareOperations.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ICustomerCareOperations
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::ICustomerCareOperations* implementation = reinterpret_cast<Exchange::ICustomerCareOperations*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::ICustomerCareOperations::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->FactoryReset();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::ICustomerCareOperations::ID, 0, hresult);
            }
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
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::ICustomerCareOperations::ID, 0, hresult);
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::ICustomerCareOperations, ExchangeCustomerCareOperationsProxy, ExchangeCustomerCareOperationsStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ICustomerCareOperations>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
