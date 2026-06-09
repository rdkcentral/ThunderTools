// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BrowserCookieJar.h"
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace Exchange {

    namespace JBrowserCookieJar {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IBrowserCookieJar* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JBrowserCookieJar"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'cookiejar' - Get/Set CookieJar config details
            _module__.PluginHost::JSONRPC::template Register<JsonData::BrowserCookieJar::ConfigData, JsonData::BrowserCookieJar::ConfigData>(_T("cookiejar"),
                [_implementation__](const JsonData::BrowserCookieJar::ConfigData& params, JsonData::BrowserCookieJar::ConfigData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Exchange::IBrowserCookieJar::Config _result_{};

                        _errorCode__ = (static_cast<const IBrowserCookieJar*>(_implementation__))->CookieJar(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const Exchange::IBrowserCookieJar::Config _params_(params);

                            _errorCode__ = _implementation__->CookieJar(_params_);

                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("cookiejar"));
        }

        namespace Event {

            // Event: 'cookiejarchanged' - Notifies that cookies were added, removed or modified
            template<typename MODULE>
            static void CookieJarChanged(const MODULE& module_, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("cookiejarchanged"), sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JBrowserCookieJar

} // namespace Exchange

} // namespace Thunder

