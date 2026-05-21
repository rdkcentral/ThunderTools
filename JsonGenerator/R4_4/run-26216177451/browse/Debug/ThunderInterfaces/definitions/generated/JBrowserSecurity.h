// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_BrowserSecurity.h"
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace Exchange {

    namespace JBrowserSecurity {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IBrowserSecurity* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JBrowserSecurity"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'securityprofile' - Security profile for secure connections
            _module_.Register<Core::JSON::String, Core::JSON::String>(_T("securityprofile"), 
                [_impl_](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        string _result{};

                        _errorCode = (static_cast<const IBrowserSecurity*>(_impl_))->SecurityProfile(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const string _params{params};

                        _errorCode = _impl_->SecurityProfile(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'mixedcontentpolicy' - Mixed content policy
            _module_.Register<Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>,
                     Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>>(_T("mixedcontentpolicy"), 
                [_impl_](const Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>& params,
                         Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        Exchange::IBrowserSecurity::MixedContentPolicyType _result{};

                        _errorCode = (static_cast<const IBrowserSecurity*>(_impl_))->MixedContentPolicy(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const Exchange::IBrowserSecurity::MixedContentPolicyType _params{params};

                        _errorCode = _impl_->MixedContentPolicy(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("securityprofile"));
            _module_.Unregister(_T("mixedcontentpolicy"));
        }

        POP_WARNING()

    } // namespace JBrowserSecurity

} // namespace Exchange

} // namespace WPEFramework

