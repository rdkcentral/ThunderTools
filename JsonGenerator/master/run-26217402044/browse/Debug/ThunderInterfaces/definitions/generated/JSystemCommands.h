// Generated automatically from 'ISystemCommands.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SystemCommands.h"
#include <interfaces/ISystemCommands.h>

namespace Thunder {

namespace Exchange {

    namespace JSystemCommands {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ISystemCommands* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSystemCommands"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'usbreset' - Resets a USB device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SystemCommands::USBResetParamsData, void>(_T("usbreset"),
                [_implementation__](const JsonData::SystemCommands::USBResetParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _device_{params.Device};

                        _errorCode__ = _implementation__->USBReset(_device_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("usbreset"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSystemCommands

} // namespace Exchange

} // namespace Thunder

