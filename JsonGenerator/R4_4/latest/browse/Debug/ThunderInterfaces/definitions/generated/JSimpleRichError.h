// Generated automatically from 'ISimpleRichError.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SimpleRichError.h"
#include <interfaces/ISimpleRichError.h>

namespace WPEFramework {

namespace Exchange {

    namespace JSimpleRichError {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ISimpleRichError* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSimpleRichError"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'restart' - Restarts the coffee machine
            _module__.PluginHost::JSONRPC::RegisterWithError<void, void, JsonData::SimpleRichError::ErrorDetailsInstance445be54d48a2e629Data>(_T("restart"),
                [_implementation__](JsonData::SimpleRichError::ErrorDetailsInstance445be54d48a2e629Data& errorDetails) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Core::OptionalType<Core::ErrorDetails<void>> _errorDetails_{};

                    _errorCode__ = _implementation__->Restart(_errorDetails_);

                    if (_errorCode__ != Core::ERROR_NONE) {
                        errorDetails = _errorDetails_;
                    }

                    return (_errorCode__);
                });

            // Method: 'makecoffee' - Makes a drink
            _module__.PluginHost::JSONRPC::RegisterWithError<JsonData::SimpleRichError::MakeCoffeeParamsData, Core::JSON::DecUInt16, JsonData::SimpleRichError::ErrorData>(_T("makecoffee"),
                [_implementation__](const JsonData::SimpleRichError::MakeCoffeeParamsData& params, Core::JSON::DecUInt16& duration, JsonData::SimpleRichError::ErrorData& errorDetails) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JSimpleRichError"), _T("makecoffee")));
                    }

                    const Exchange::ISimpleRichError::coffeetype _type_{params.Type};
                    uint16_t _duration_{};
                    Core::OptionalType<Exchange::ISimpleRichError::Error> _errorDetails_{};

                    _errorCode__ = _implementation__->MakeCoffee(_type_, _duration_, _errorDetails_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        duration = _duration_;
                    }
                    else {
                        errorDetails = _errorDetails_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("restart"));
            _module__.PluginHost::JSONRPC::Unregister(_T("makecoffee"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSimpleRichError

} // namespace Exchange

} // namespace WPEFramework

