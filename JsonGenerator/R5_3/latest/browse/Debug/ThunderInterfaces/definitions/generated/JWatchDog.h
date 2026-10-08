// Generated automatically from 'IWatchDog.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_WatchDog.h"
#include <interfaces/IWatchDog.h>

namespace Thunder {

namespace Exchange {

    namespace JWatchDog {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IWatchDog* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JWatchDog"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'touch' - Touch the watchdog as a sign of life
            _module__.PluginHost::JSONRPC::template Register<JsonData::WatchDog::TouchParamsData, void>(_T("touch"),
                [_implementation__](const JsonData::WatchDog::TouchParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _callsign_{params.Callsign};

                        _errorCode__ = _implementation__->Touch(_callsign_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("touch"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JWatchDog

} // namespace Exchange

} // namespace Thunder

