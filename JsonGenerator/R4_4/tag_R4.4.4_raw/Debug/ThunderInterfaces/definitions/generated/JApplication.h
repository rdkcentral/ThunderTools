// Generated automatically from 'IApplication.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_Application.h"
#include <interfaces/IApplication.h>

namespace WPEFramework {

namespace Exchange {

    namespace JApplication {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IApplication* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JApplication"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'reset' - Resets application data
            _module_.Register<Core::JSON::EnumType<Exchange::IApplication::resettype>, void>(_T("reset"), 
                [_impl_](const Core::JSON::EnumType<Exchange::IApplication::resettype>& type) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const Exchange::IApplication::resettype _type{type};

                    _errorCode = _impl_->Reset(_type);

                    return (_errorCode);
                });

            // Property: 'identifier' - Application-specific identification string (r/o)
            _module_.Register<void, Core::JSON::String>(_T("identifier"), 
                [_impl_](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    string _result{};

                    _errorCode = _impl_->Identifier(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'contentlink' - URI of the associated application-specific content (w/o)
            _module_.Register<Core::JSON::String, void>(_T("contentlink"), 
                [_impl_](const Core::JSON::String& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _params{params};

                    _errorCode = _impl_->ContentLink(_params);

                    return (_errorCode);
                });

            // Property: 'launchpoint' - Application launching point
            _module_.Register<Core::JSON::EnumType<Exchange::IApplication::launchpointtype>,
                     Core::JSON::EnumType<Exchange::IApplication::launchpointtype>>(_T("launchpoint"), 
                [_impl_](const Core::JSON::EnumType<Exchange::IApplication::launchpointtype>& params,
                         Core::JSON::EnumType<Exchange::IApplication::launchpointtype>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        Exchange::IApplication::launchpointtype _result{};

                        _errorCode = (static_cast<const IApplication*>(_impl_))->LaunchPoint(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const Exchange::IApplication::launchpointtype _params{params};

                        _errorCode = _impl_->LaunchPoint(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'visible' - Current application visibility
            _module_.Register<Core::JSON::Boolean, Core::JSON::Boolean>(_T("visible"), 
                [_impl_](const Core::JSON::Boolean& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        bool _result{};

                        _errorCode = (static_cast<const IApplication*>(_impl_))->Visible(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const bool _params{params};

                        _errorCode = _impl_->Visible(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'language' - Current application user interface language
            _module_.Register<Core::JSON::String, Core::JSON::String>(_T("language"), 
                [_impl_](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        string _result{};

                        _errorCode = (static_cast<const IApplication*>(_impl_))->Language(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const string _params{params};

                        _errorCode = _impl_->Language(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("reset"));
            _module_.Unregister(_T("identifier"));
            _module_.Unregister(_T("contentlink"));
            _module_.Unregister(_T("launchpoint"));
            _module_.Unregister(_T("visible"));
            _module_.Unregister(_T("language"));
        }

        namespace Event {

            // Event: 'visibilitychange' - Application visibility changes
            static void VisibilityChange(const JSONRPC& _module_, const Core::JSON::Boolean& hidden)
            {
                _module_.Notify(_T("visibilitychange"), hidden);
            }

            // Event: 'visibilitychange' - Application visibility changes
            static void VisibilityChange(const JSONRPC& _module_, const bool& hidden)
            {
                Core::JSON::Boolean _params_;
                _params_ = hidden;

                VisibilityChange(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JApplication

} // namespace Exchange

} // namespace WPEFramework

