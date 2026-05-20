// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_BrowserCookieJar.h"
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace Exchange {

    namespace JBrowserCookieJar {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IBrowserCookieJar* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JBrowserCookieJar"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'cookiejar'
            _module_.Register<JsonData::BrowserCookieJar::ConfigData, JsonData::BrowserCookieJar::ConfigData>(_T("cookiejar"), 
                [_impl_](const JsonData::BrowserCookieJar::ConfigData& params, JsonData::BrowserCookieJar::ConfigData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        Exchange::IBrowserCookieJar::Config _result{};

                        _errorCode = (static_cast<const IBrowserCookieJar*>(_impl_))->CookieJar(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const Exchange::IBrowserCookieJar::Config _params(params);

                        _errorCode = _impl_->CookieJar(_params);

                        // result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("cookiejar"));
        }

        namespace Event {

            // Event: 'cookiejarchanged' - Notifies that cookies were added, removed or modified
            static void CookieJarChanged(const JSONRPC& _module_)
            {
                _module_.Notify(_T("cookiejarchanged"));
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JBrowserCookieJar

} // namespace Exchange

} // namespace WPEFramework

