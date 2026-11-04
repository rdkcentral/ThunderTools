//
// generated automatically from "ISimpleRichError.h"
//
// implements COM-RPC proxy stubs for:
//   - class Example::ISimpleRichError
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "ISimpleRichError.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Example::ISimpleRichError interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>&) = 0
    //  (1) virtual Core::hresult MakeCoffee(const Example::ISimpleRichError::coffeetype&, uint16_t&, Core::OptionalType<Example::ISimpleRichError::Error>&) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleRichErrorStubMethods[] = {
        // (0) virtual Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleRichError* implementation = reinterpret_cast<Example::ISimpleRichError*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleRichError::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Core::OptionalType<Core::ErrorDetails<void>> _errorDetails{};

                Core::hresult result = implementation->Restart(_errorDetails);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Boolean(_errorDetails.IsSet());
                if (_errorDetails.IsSet() == true) {
                    writer.Boolean(_errorDetails.Value().code.IsSet());
                    if (_errorDetails.Value().code.IsSet() == true) {
                        writer.Number<int32_t>(_errorDetails.Value().code.Value());
                    }
                    writer.Boolean(_errorDetails.Value().message.IsSet());
                    if (_errorDetails.Value().message.IsSet() == true) {
                        writer.Text(_errorDetails.Value().message.Value());
                    }
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleRichError::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult MakeCoffee(const Example::ISimpleRichError::coffeetype&, uint16_t&, Core::OptionalType<Example::ISimpleRichError::Error>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleRichError* implementation = reinterpret_cast<Example::ISimpleRichError*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleRichError::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Example::ISimpleRichError::coffeetype>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Example::ISimpleRichError::coffeetype _type = reader.Number<Example::ISimpleRichError::coffeetype>();

                uint16_t _duration{};
                Core::OptionalType<Example::ISimpleRichError::Error> _errorDetails{};

                Core::hresult result = implementation->MakeCoffee(static_cast<const Example::ISimpleRichError::coffeetype&>(_type), _duration, _errorDetails);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint16_t>(_duration);
                writer.Boolean(_errorDetails.IsSet());
                if (_errorDetails.IsSet() == true) {
                    writer.Boolean(_errorDetails.Value().code.IsSet());
                    if (_errorDetails.Value().code.IsSet() == true) {
                        writer.Number<int32_t>(_errorDetails.Value().code.Value());
                    }
                    writer.Boolean(_errorDetails.Value().message.IsSet());
                    if (_errorDetails.Value().message.IsSet() == true) {
                        writer.Text(_errorDetails.Value().message.Value());
                    }
                    writer.Boolean(_errorDetails.Value().data.IsSet());
                    if (_errorDetails.Value().data.IsSet() == true) {
                        writer.Number<Example::ISimpleRichError::Diagnostic::failreason>(_errorDetails.Value().data.Value().reason);
                        writer.Number<uint8_t>(_errorDetails.Value().data.Value().water_temperature);
                        writer.Number<uint8_t>(_errorDetails.Value().data.Value().water_level);
                        writer.Number<uint8_t>(_errorDetails.Value().data.Value().brew_pressure);
                        writer.Boolean(_errorDetails.Value().data.Value().info.IsSet());
                        if (_errorDetails.Value().data.Value().info.IsSet() == true) {
                            writer.Text(_errorDetails.Value().data.Value().info.Value());
                        }
                    }
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleRichError::ID, 1, hresult);
            }
        }
        , nullptr
    }; // ExampleSimpleRichErrorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Example::ISimpleRichError interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>&) = 0
    //  (1) virtual Core::hresult MakeCoffee(const Example::ISimpleRichError::coffeetype&, uint16_t&, Core::OptionalType<Example::ISimpleRichError::Error>&) = 0
    //

    class ExampleSimpleRichErrorProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleRichError> {
    public:
        ExampleSimpleRichErrorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>& _errorDetails) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            Core::ErrorDetails<void> _errorDetailsObject__{};
                            if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            if (reader.Boolean() == true) {
                                if (reader.Length() < (Core::RealSize<int32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject__.code = reader.Number<int32_t>();
                            }
                            else {
                                _errorDetailsObject__.code = Core::OptionalType<int32_t>();
                            }
                            if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            if (reader.Boolean() == true) {
                                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                const uint16_t _errorDetailsObject___messagePeekedLen__ = reader.PeekNumber<uint16_t>();
                                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _errorDetailsObject___messagePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject__.message = reader.Text();
                            }
                            else {
                                _errorDetailsObject__.message = Core::OptionalType<string>();
                            }
                            _errorDetails = std::move(_errorDetailsObject__);
                        }
                        else {
                            _errorDetails = Core::OptionalType<Core::ErrorDetails<void>>();
                        }
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleRichError::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult MakeCoffee(const Example::ISimpleRichError::coffeetype& _type, uint16_t& _duration, Core::OptionalType<Example::ISimpleRichError::Error>& _errorDetails) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Example::ISimpleRichError::coffeetype>(_type);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _duration = reader.Number<uint16_t>();
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        if (reader.Boolean() == true) {
                            Example::ISimpleRichError::Error _errorDetailsObject__{};
                            if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            if (reader.Boolean() == true) {
                                if (reader.Length() < (Core::RealSize<int32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject__.code = reader.Number<int32_t>();
                            }
                            else {
                                _errorDetailsObject__.code = Core::OptionalType<int32_t>();
                            }
                            if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            if (reader.Boolean() == true) {
                                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                const uint16_t _errorDetailsObject___messagePeekedLen__ = reader.PeekNumber<uint16_t>();
                                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _errorDetailsObject___messagePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject__.message = reader.Text();
                            }
                            else {
                                _errorDetailsObject__.message = Core::OptionalType<string>();
                            }
                            if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            if (reader.Boolean() == true) {
                                Example::ISimpleRichError::Diagnostic _errorDetailsObject___dataObject__{};
                                if (reader.Length() < (Core::RealSize<Example::ISimpleRichError::Diagnostic::failreason>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject___dataObject__.reason = reader.Number<Example::ISimpleRichError::Diagnostic::failreason>();
                                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject___dataObject__.water_temperature = reader.Number<uint8_t>();
                                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject___dataObject__.water_level = reader.Number<uint8_t>();
                                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                _errorDetailsObject___dataObject__.brew_pressure = reader.Number<uint8_t>();
                                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                if (reader.Boolean() == true) {
                                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                    const uint16_t _errorDetailsObject___dataObject___infoPeekedLen__ = reader.PeekNumber<uint16_t>();
                                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _errorDetailsObject___dataObject___infoPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                                    _errorDetailsObject___dataObject__.info = reader.Text();
                                }
                                else {
                                    _errorDetailsObject___dataObject__.info = Core::OptionalType<string>();
                                }
                                _errorDetailsObject__.data = std::move(_errorDetailsObject___dataObject__);
                            }
                            else {
                                _errorDetailsObject__.data = Core::OptionalType<Example::ISimpleRichError::Diagnostic>();
                            }
                            _errorDetails = std::move(_errorDetailsObject__);
                        }
                        else {
                            _errorDetails = Core::OptionalType<Example::ISimpleRichError::Error>();
                        }
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleRichError::ID, 1, hresult);
            }

            return (hresult);
        }

    }; // class ExampleSimpleRichErrorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Example::ISimpleRichError, ExampleSimpleRichErrorStubMethods> ExampleSimpleRichErrorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Example::ISimpleRichError, ExampleSimpleRichErrorProxy, ExampleSimpleRichErrorStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Example::ISimpleRichError>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
