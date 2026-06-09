// Generated automatically from 'IContentProtection.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_ErrorToString.h"
#include <interfaces/IContentProtection.h>

namespace Thunder {

namespace Exchange {

    namespace JErrorToString {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IErrorToString* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JErrorToString"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'errorToString'
            _module__.PluginHost::JSONRPC::template Register<JsonData::ErrorToString::ErrorToStringParamsData, Core::JSON::String>(_T("errorToString"),
                [_implementation__](const JsonData::ErrorToString::ErrorToStringParamsData& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const int32_t _code_{params.Code};
                        string _result_{};

                        _errorCode__ = _implementation__->ErrorToString(_code_, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("errorToString"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JErrorToString

} // namespace Exchange

} // namespace Thunder

