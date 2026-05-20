//
// generated automatically from "IStoreCache.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IStoreCache
//

#include "Module.h"
#include "IStoreCache.h"

#include <com/com.h>

namespace WPEFramework {

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

    ProxyStub::MethodHandler ExchangeStoreCacheStubMethods[] = {
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

        uint32_t FlushCache() override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

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
