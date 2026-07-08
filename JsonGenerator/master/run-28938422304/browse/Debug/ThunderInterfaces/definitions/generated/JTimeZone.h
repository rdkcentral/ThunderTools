// Generated automatically from 'ITimeZone.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include <interfaces/ITimeZone.h>

namespace Thunder {

namespace Exchange {

    namespace JTimeZone {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ITimeZone* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JTimeZone"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'timezone' - TimeZone for system
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String>(_T("timezone"),
                [_implementation__](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const ITimeZone*>(_implementation__))->TimeZone(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->TimeZone(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("timezone"));
        }

        namespace Event {

            // Event: 'timezonechanged' - TimeZone was set for the system
            template<typename MODULE>
            static void TimeZoneChanged(const MODULE& module_, const Core::JSON::String& timeZone, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("timezonechanged"), timeZone, sendIfMethod_);
            }

            // Event: 'timezonechanged' - TimeZone was set for the system
            template<typename MODULE>
            static void TimeZoneChanged(const MODULE& module_, const string& timeZone, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                Core::JSON::String params_;
                params_ = timeZone;

                TimeZoneChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JTimeZone

} // namespace Exchange

} // namespace Thunder

