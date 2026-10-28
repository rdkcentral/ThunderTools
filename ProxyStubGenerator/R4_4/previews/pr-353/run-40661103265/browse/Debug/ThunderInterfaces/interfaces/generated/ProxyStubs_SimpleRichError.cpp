//
// generated automatically from "ISimpleRichError.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ISimpleRichError
//

#include "Module.h"
#include "ISimpleRichError.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ISimpleRichError interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>&) = 0
    //  (1) virtual Core::hresult MakeCoffee(const Exchange::ISimpleRichError::coffeetype&, uint16_t&, Core::OptionalType<Exchange::ISimpleRichError::Error>&) = 0
    //

    static ProxyStub::MethodHandler ExchangeSimpleRichErrorStubMethods[] = {
        // (0) virtual Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISimpleRichError* implementation = reinterpret_cast<Exchange::ISimpleRichError*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

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
        },

        // (1) virtual Core::hresult MakeCoffee(const Exchange::ISimpleRichError::coffeetype&, uint16_t&, Core::OptionalType<Exchange::ISimpleRichError::Error>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISimpleRichError* implementation = reinterpret_cast<Exchange::ISimpleRichError*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::ISimpleRichError::coffeetype _type = reader.Number<Exchange::ISimpleRichError::coffeetype>();

            uint16_t _duration{};
            Core::OptionalType<Exchange::ISimpleRichError::Error> _errorDetails{};

            Core::hresult result = implementation->MakeCoffee(static_cast<const Exchange::ISimpleRichError::coffeetype&>(_type), _duration, _errorDetails);

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
                    writer.Number<Exchange::ISimpleRichError::Diagnostic::failreason>(_errorDetails.Value().data.Value().reason);
                    writer.Number<uint8_t>(_errorDetails.Value().data.Value().water_temperature);
                    writer.Number<uint8_t>(_errorDetails.Value().data.Value().water_level);
                    writer.Number<uint8_t>(_errorDetails.Value().data.Value().brew_pressure);
                    writer.Boolean(_errorDetails.Value().data.Value().info.IsSet());
                    if (_errorDetails.Value().data.Value().info.IsSet() == true) {
                        writer.Text(_errorDetails.Value().data.Value().info.Value());
                    }
                }
            }
        }
        , nullptr
    }; // ExchangeSimpleRichErrorStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ISimpleRichError interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>&) = 0
    //  (1) virtual Core::hresult MakeCoffee(const Exchange::ISimpleRichError::coffeetype&, uint16_t&, Core::OptionalType<Exchange::ISimpleRichError::Error>&) = 0
    //

    class ExchangeSimpleRichErrorProxy final : public ProxyStub::UnknownProxyType<Exchange::ISimpleRichError> {
    public:
        ExchangeSimpleRichErrorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Restart(Core::OptionalType<Core::ErrorDetails<void>>& _errorDetails) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    Core::ErrorDetails<void> _errorDetailsObject__{};
                    if (reader.Boolean() == true) {
                        _errorDetailsObject__.code = reader.Number<int32_t>();
                    }
                    else {
                        _errorDetailsObject__.code = Core::OptionalType<int32_t>();
                    }
                    if (reader.Boolean() == true) {
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
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult MakeCoffee(const Exchange::ISimpleRichError::coffeetype& _type, uint16_t& _duration, Core::OptionalType<Exchange::ISimpleRichError::Error>& _errorDetails) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::ISimpleRichError::coffeetype>(_type);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _duration = reader.Number<uint16_t>();
                if (reader.Boolean() == true) {
                    Exchange::ISimpleRichError::Error _errorDetailsObject__{};
                    if (reader.Boolean() == true) {
                        _errorDetailsObject__.code = reader.Number<int32_t>();
                    }
                    else {
                        _errorDetailsObject__.code = Core::OptionalType<int32_t>();
                    }
                    if (reader.Boolean() == true) {
                        _errorDetailsObject__.message = reader.Text();
                    }
                    else {
                        _errorDetailsObject__.message = Core::OptionalType<string>();
                    }
                    if (reader.Boolean() == true) {
                        Exchange::ISimpleRichError::Diagnostic _errorDetailsObject___dataObject__{};
                        _errorDetailsObject___dataObject__.reason = reader.Number<Exchange::ISimpleRichError::Diagnostic::failreason>();
                        _errorDetailsObject___dataObject__.water_temperature = reader.Number<uint8_t>();
                        _errorDetailsObject___dataObject__.water_level = reader.Number<uint8_t>();
                        _errorDetailsObject___dataObject__.brew_pressure = reader.Number<uint8_t>();
                        if (reader.Boolean() == true) {
                            _errorDetailsObject___dataObject__.info = reader.Text();
                        }
                        else {
                            _errorDetailsObject___dataObject__.info = Core::OptionalType<string>();
                        }
                        _errorDetailsObject__.data = std::move(_errorDetailsObject___dataObject__);
                    }
                    else {
                        _errorDetailsObject__.data = Core::OptionalType<Exchange::ISimpleRichError::Diagnostic>();
                    }
                    _errorDetails = std::move(_errorDetailsObject__);
                }
                else {
                    _errorDetails = Core::OptionalType<Exchange::ISimpleRichError::Error>();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeSimpleRichErrorProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ISimpleRichError, ExchangeSimpleRichErrorStubMethods> ExchangeSimpleRichErrorStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ISimpleRichError, ExchangeSimpleRichErrorProxy, ExchangeSimpleRichErrorStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ISimpleRichError>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
