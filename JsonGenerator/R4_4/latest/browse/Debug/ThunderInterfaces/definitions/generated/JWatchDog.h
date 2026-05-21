// Generated automatically from 'IWatchDog.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_WatchDog.h"
#include <interfaces/IWatchDog.h>

namespace WPEFramework {

namespace Exchange {

    namespace JWatchDog {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IWatchDog* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JWatchDog"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'touch' - Touch the watchdog as a sign of life
            _module_.Register<JsonData::WatchDog::TouchParamsData, void>(_T("touch"), 
                [_impl_](const JsonData::WatchDog::TouchParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _callsign{params.Callsign};

                    _errorCode = _impl_->Touch(_callsign);

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("touch"));
        }

        POP_WARNING()

    } // namespace JWatchDog

} // namespace Exchange

} // namespace WPEFramework

