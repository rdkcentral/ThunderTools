// Generated automatically from 'ISubsystemControl.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SubsystemControl.h"
#include <interfaces/ISubsystemControl.h>

namespace Thunder {

namespace Exchange {

    namespace JSubsystemControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ISubsystemControl* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSubsystemControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'activate' - Activates a subsystem
            _module__.PluginHost::JSONRPC::template Register<JsonData::SubsystemControl::ActivateParamsData, void>(_T("activate"),
                [_implementation__](const JsonData::SubsystemControl::ActivateParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const PluginHost::ISubSystem::subsystem _subsystem_{params.Subsystem};
                        Core::OptionalType<string> _configuration_{};
                        if (params.Configuration.IsSet() == true) {
                            _configuration_ = params.Configuration;
                        }

                        _errorCode__ = _implementation__->Activate(_subsystem_, _configuration_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("activate"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSubsystemControl

} // namespace Exchange

} // namespace Thunder

