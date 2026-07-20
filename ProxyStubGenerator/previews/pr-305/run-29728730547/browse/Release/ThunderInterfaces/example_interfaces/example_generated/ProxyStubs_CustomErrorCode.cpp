//
// generated automatically from "ICustomErrorCode.h"
//
// implements COM-RPC proxy stubs for:
//   - class Example::ICustomErrorCode
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Example::ICustomErrorCode* implementation = reinterpret_cast<const Example::ICustomErrorCode*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ICustomErrorCode::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<int32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const int32_t _errorcode = reader.Number<int32_t>();

                Core::hresult result = implementation->TriggerCustomError(_errorcode);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ICustomErrorCode::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult TriggerNonCustomError(const uint32_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Example::ICustomErrorCode* implementation = reinterpret_cast<const Example::ICustomErrorCode*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ICustomErrorCode::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _errorcode = reader.Number<uint32_t>();

                Core::hresult result = implementation->TriggerNonCustomError(_errorcode);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ICustomErrorCode::ID, 1, hresult);
            }
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
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ICustomErrorCode::ID, 0, hresult);
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
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ICustomErrorCode::ID, 1, hresult);
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Example::ICustomErrorCode, ExampleCustomErrorCodeProxy, ExampleCustomErrorCodeStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Example::ICustomErrorCode>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
