// Generated automatically from 'ICustomErrorCode.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_CustomErrorCode.h"
#include <example_interfaces/ICustomErrorCode.h>

namespace Thunder {

namespace Example {

    namespace JCustomErrorCode {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ICustomErrorCode* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JCustomErrorCode"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'triggerCustomError'
            _module__.PluginHost::JSONRPC::template Register<JsonData::CustomErrorCode::TriggerCustomErrorParamsData, void>(_T("triggerCustomError"),
                [_implementation__](const JsonData::CustomErrorCode::TriggerCustomErrorParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const int32_t _errorcode_{params.Errorcode};

                        _errorCode__ = _implementation__->TriggerCustomError(_errorcode_);

                    }

                    return (_errorCode__);
                });

            // Method: 'triggerNonCustomError'
            _module__.PluginHost::JSONRPC::template Register<JsonData::CustomErrorCode::TriggerNonCustomErrorParamsData, void>(_T("triggerNonCustomError"),
                [_implementation__](const JsonData::CustomErrorCode::TriggerNonCustomErrorParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _errorcode_{params.Errorcode};

                        _errorCode__ = _implementation__->TriggerNonCustomError(_errorcode_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("triggerCustomError"));
            _module__.PluginHost::JSONRPC::Unregister(_T("triggerNonCustomError"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JCustomErrorCode

} // namespace Example

} // namespace Thunder

