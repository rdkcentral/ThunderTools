// Generated automatically from 'IApplication.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Application.h"
#include <interfaces/IApplication.h>

namespace Thunder {

namespace Exchange {

    namespace JApplication {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IApplication* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JApplication"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'reset' - Resets application data
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::EnumType<Exchange::IApplication::resettype>, void>(_T("reset"),
                [_implementation__](const Core::JSON::EnumType<Exchange::IApplication::resettype>& type) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (type.IsSet() == false) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IApplication::resettype _type_{type};

                        _errorCode__ = _implementation__->Reset(_type_);

                    }

                    return (_errorCode__);
                });

            // Property: 'identifier' - Application-specific identification string (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("identifier"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->Identifier(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'contentlink' - URI of the associated application-specific content (w/o)
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, void>(_T("contentlink"),
                [_implementation__](const Core::JSON::String& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->ContentLink(_params_);

                    }

                    return (_errorCode__);
                });

            // Property: 'launchpoint' - Application launching point
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::EnumType<Exchange::IApplication::launchpointtype>, Core::JSON::EnumType<Exchange::IApplication::launchpointtype>>(_T("launchpoint"),
                [_implementation__](const Core::JSON::EnumType<Exchange::IApplication::launchpointtype>& params, Core::JSON::EnumType<Exchange::IApplication::launchpointtype>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Exchange::IApplication::launchpointtype _result_{};

                        _errorCode__ = (static_cast<const IApplication*>(_implementation__))->LaunchPoint(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const Exchange::IApplication::launchpointtype _params_{params};

                        _errorCode__ = _implementation__->LaunchPoint(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'visible' - Current application visibility
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::Boolean, Core::JSON::Boolean>(_T("visible"),
                [_implementation__](const Core::JSON::Boolean& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        bool _result_{};

                        _errorCode__ = (static_cast<const IApplication*>(_implementation__))->Visible(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const bool _params_{params};

                        _errorCode__ = _implementation__->Visible(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'language' - Current application user interface language
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String>(_T("language"),
                [_implementation__](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const IApplication*>(_implementation__))->Language(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->Language(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("reset"));
            _module__.PluginHost::JSONRPC::Unregister(_T("identifier"));
            _module__.PluginHost::JSONRPC::Unregister(_T("contentlink"));
            _module__.PluginHost::JSONRPC::Unregister(_T("launchpoint"));
            _module__.PluginHost::JSONRPC::Unregister(_T("visible"));
            _module__.PluginHost::JSONRPC::Unregister(_T("language"));
        }

        namespace Event {

            // Event: 'visibilitychange' - Application visibility changes
            template<typename MODULE>
            static void VisibilityChange(const MODULE& module_, const Core::JSON::Boolean& hidden, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("visibilitychange"), hidden, sendIfMethod_);
            }

            // Event: 'visibilitychange' - Application visibility changes
            template<typename MODULE>
            static void VisibilityChange(const MODULE& module_, const bool hidden, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                Core::JSON::Boolean params_;
                params_ = hidden;

                VisibilityChange(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JApplication

} // namespace Exchange

} // namespace Thunder

