// Generated automatically from 'ITimeZone.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include <interfaces/ITimeZone.h>

namespace WPEFramework {

namespace Exchange {

    namespace JTimeZone {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, ITimeZone* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JTimeZone"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'timezone' - TimeZone for system
            _module_.Register<Core::JSON::String, Core::JSON::String>(_T("timezone"), 
                [_impl_](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        string _result{};

                        _errorCode = (static_cast<const ITimeZone*>(_impl_))->TimeZone(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const string _params{params};

                        _errorCode = _impl_->TimeZone(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("timezone"));
        }

        namespace Event {

            // Event: 'timezonechanged' - TimeZone was set for the system
            static void TimeZoneChanged(const JSONRPC& _module_, const Core::JSON::String& timeZone)
            {
                _module_.Notify(_T("timezonechanged"), timeZone);
            }

            // Event: 'timezonechanged' - TimeZone was set for the system
            static void TimeZoneChanged(const JSONRPC& _module_, const string& timeZone)
            {
                Core::JSON::String _params_;
                _params_ = timeZone;

                TimeZoneChanged(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JTimeZone

} // namespace Exchange

} // namespace WPEFramework

