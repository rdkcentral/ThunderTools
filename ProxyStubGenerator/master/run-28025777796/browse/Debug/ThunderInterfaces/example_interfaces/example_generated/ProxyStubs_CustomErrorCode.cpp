//
// generated automatically from "ICustomErrorCode.h"
//
// implements COM-RPC proxy stubs for:
//   - class Example::ICustomErrorCode
//

#include "Module.h"
#include "ICustomErrorCode.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Example::ICustomErrorCode interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TriggerCustomError(const int32_t) const = 0
    //  (1) virtual Core::hresult TriggerNonCustomError(const uint32_t) const = 0
    //

    static ProxyStub::MethodHandler ExampleCustomErrorCodeStubMethods[] = {
        // (0) virtual Core::hresult TriggerCustomError(const int32_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ICustomErrorCode* implementation = reinterpret_cast<const Example::ICustomErrorCode*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _errorcode = reader.Number<int32_t>();

            Core::hresult result = implementation->TriggerCustomError(_errorcode);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult TriggerNonCustomError(const uint32_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ICustomErrorCode* implementation = reinterpret_cast<const Example::ICustomErrorCode*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _errorcode = reader.Number<uint32_t>();

            Core::hresult result = implementation->TriggerNonCustomError(_errorcode);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExampleCustomErrorCodeStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Example::ICustomErrorCode interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult TriggerCustomError(const int32_t) const = 0
    //  (1) virtual Core::hresult TriggerNonCustomError(const uint32_t) const = 0
    //

    class ExampleCustomErrorCodeProxy final : public ProxyStub::UnknownProxyType<Example::ICustomErrorCode> {
    public:
        ExampleCustomErrorCodeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult TriggerCustomError(const int32_t _errorcode) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_errorcode);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult TriggerNonCustomError(const uint32_t _errorcode) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_errorcode);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExampleCustomErrorCodeProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Example::ICustomErrorCode, ExampleCustomErrorCodeStubMethods> ExampleCustomErrorCodeStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Example::ICustomErrorCode, ExampleCustomErrorCodeProxy, ExampleCustomErrorCodeStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Example::ICustomErrorCode>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
