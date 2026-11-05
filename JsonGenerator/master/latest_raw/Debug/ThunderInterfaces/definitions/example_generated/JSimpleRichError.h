// Generated automatically from 'ISimpleRichError.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SimpleRichError.h"
#include <example_interfaces/ISimpleRichError.h>

namespace Thunder {

namespace Example {

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
            _module__.PluginHost::JSONRPC::template RegisterWithError<void, void, JsonData::SimpleRichError::ErrorDetailsInstance445be54d48a2e629Data>(_T("restart"),
                [_implementation__](JsonData::SimpleRichError::ErrorDetailsInstance445be54d48a2e629Data& errorDetails) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Core::OptionalType<Core::ErrorDetails<void>> _errorDetails_{};

                    _errorCode__ = _implementation__->Restart(_errorDetails_);

                    if (_errorCode__ != Core::ERROR_NONE) {
                        errorDetails = _errorDetails_;
                    }

                    return (_errorCode__);
                });

            // Method: 'makeCoffee' - Makes a drink
            _module__.PluginHost::JSONRPC::template RegisterWithError<JsonData::SimpleRichError::MakeCoffeeParamsData, Core::JSON::DecUInt16, JsonData::SimpleRichError::ErrorData>(_T("makeCoffee"),
                [_implementation__](const JsonData::SimpleRichError::MakeCoffeeParamsData& params, Core::JSON::DecUInt16& duration, JsonData::SimpleRichError::ErrorData& errorDetails) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JSimpleRichError"), _T("makeCoffee")));
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Example::ISimpleRichError::coffeetype _type_{params.Type};
                        uint16_t _duration_{};
                        Core::OptionalType<Example::ISimpleRichError::Error> _errorDetails_{};

                        _errorCode__ = _implementation__->MakeCoffee(_type_, _duration_, _errorDetails_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            duration = _duration_;
                        }
                        else {
                            errorDetails = _errorDetails_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("restart"));
            _module__.PluginHost::JSONRPC::Unregister(_T("makeCoffee"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSimpleRichError

} // namespace Example

} // namespace Thunder

