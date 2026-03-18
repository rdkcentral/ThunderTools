//
// generated automatically from "IStoreCache.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IStoreCache
//

#include "Module.h"
#include "IStoreCache.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IStoreCache interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t FlushCache() = 0
    //

    static ProxyStub::MethodHandler ExchangeStoreCacheStubMethods[] = {
        // (0) virtual uint32_t FlushCache() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStoreCache* implementation = reinterpret_cast<Exchange::IStoreCache*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->FlushCache();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeStoreCacheStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IStoreCache interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t FlushCache() = 0
    //

    class ExchangeStoreCacheProxy final : public ProxyStub::UnknownProxyType<Exchange::IStoreCache> {
    public:
        ExchangeStoreCacheProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t FlushCache() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeStoreCacheProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IStoreCache, ExchangeStoreCacheStubMethods> ExchangeStoreCacheStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IStoreCache, ExchangeStoreCacheProxy, ExchangeStoreCacheStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IStoreCache>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
