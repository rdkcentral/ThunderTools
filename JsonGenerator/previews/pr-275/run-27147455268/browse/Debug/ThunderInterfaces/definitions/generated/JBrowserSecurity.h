// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BrowserSecurity.h"
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace Exchange {

    namespace JBrowserSecurity {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IBrowserSecurity* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JBrowserSecurity"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'securityprofile' - Security profile for secure connections
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String>(_T("securityprofile"),
                [_implementation__](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const IBrowserSecurity*>(_implementation__))->SecurityProfile(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->SecurityProfile(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'mixedcontentpolicy' - Mixed content policy
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>, Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>>(_T("mixedcontentpolicy"),
                [_implementation__](const Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>& params, Core::JSON::EnumType<Exchange::IBrowserSecurity::MixedContentPolicyType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Exchange::IBrowserSecurity::MixedContentPolicyType _result_{};

                        _errorCode__ = (static_cast<const IBrowserSecurity*>(_implementation__))->MixedContentPolicy(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const Exchange::IBrowserSecurity::MixedContentPolicyType _params_{params};

                        _errorCode__ = _implementation__->MixedContentPolicy(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("securityprofile"));
            _module__.PluginHost::JSONRPC::Unregister(_T("mixedcontentpolicy"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JBrowserSecurity

} // namespace Exchange

} // namespace Thunder

