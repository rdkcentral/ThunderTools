// Generated automatically from 'ISecurityAgent.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SecurityAgent.h"
#include <interfaces/ISecurityAgent.h>

namespace Thunder {

namespace Exchange {

    namespace JSecurityAgent {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ISecurityAgent* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSecurityAgent"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'validate' - Validates a token
            _module__.PluginHost::JSONRPC::template Register<JsonData::SecurityAgent::ValidateParamsData, Core::JSON::Boolean>(_T("validate"),
                [_implementation__](const JsonData::SecurityAgent::ValidateParamsData& params, Core::JSON::Boolean& valid) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _token_{params.Token};
                        bool _valid_{};

                        _errorCode__ = _implementation__->Validate(_token_, _valid_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            valid = _valid_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("validate"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSecurityAgent

} // namespace Exchange

} // namespace Thunder

