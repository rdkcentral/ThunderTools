// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_WebBrowser.h"
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace Exchange {

    namespace JWebBrowser {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IWebBrowser* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JWebBrowser"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'collectgarbage' - Initiate garbage collection
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("collectgarbage"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->CollectGarbage();

                    return (_errorCode__);
                });

            // Property: 'url' - Page loaded in the browser
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String>(_T("url"),
                [_implementation__](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const IWebBrowser*>(_implementation__))->URL(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->URL(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'visibility' - Browser window visibility state
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>, Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>>(_T("visibility"),
                [_implementation__](const Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>& params, Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Exchange::IWebBrowser::VisibilityType _result_{};

                        _errorCode__ = (static_cast<const IWebBrowser*>(_implementation__))->Visibility(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const Exchange::IWebBrowser::VisibilityType _params_{params};

                        _errorCode__ = _implementation__->Visibility(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'fps' - Current framerate the browser is rendering at (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt8>(_T("fps"),
                [_implementation__](Core::JSON::DecUInt8& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint8_t _result_{};

                    _errorCode__ = _implementation__->FPS(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'headers' - Headers to send on all requests that the browser makes
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String>(_T("headers"),
                [_implementation__](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const IWebBrowser*>(_implementation__))->HeaderList(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->HeaderList(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'useragent' - UserAgent string used by the browser
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String>(_T("useragent"),
                [_implementation__](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const IWebBrowser*>(_implementation__))->UserAgent(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->UserAgent(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'localstorageenabled' - Controls the local storage availability
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::Boolean, Core::JSON::Boolean>(_T("localstorageenabled"),
                [_implementation__](const Core::JSON::Boolean& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        bool _result_{};

                        _errorCode__ = (static_cast<const IWebBrowser*>(_implementation__))->LocalStorageEnabled(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const bool _params_{params};

                        _errorCode__ = _implementation__->LocalStorageEnabled(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'httpcookieacceptpolicy' - HTTP cookies accept policy
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>, Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>>(_T("httpcookieacceptpolicy"),
                [_implementation__](const Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>& params, Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Exchange::IWebBrowser::HTTPCookieAcceptPolicyType _result_{};

                        _errorCode__ = (static_cast<const IWebBrowser*>(_implementation__))->HTTPCookieAcceptPolicy(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const Exchange::IWebBrowser::HTTPCookieAcceptPolicyType _params_{params};

                        _errorCode__ = _implementation__->HTTPCookieAcceptPolicy(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'bridgereply' - Response for legacy $badger (w/o)
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, void>(_T("bridgereply"),
                [_implementation__](const Core::JSON::String& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->BridgeReply(_params_);

                    }

                    return (_errorCode__);
                });

            // Property: 'bridgeevent' - Send legacy $badger event (w/o)
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, void>(_T("bridgeevent"),
                [_implementation__](const Core::JSON::String& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _params_{params};

                        _errorCode__ = _implementation__->BridgeEvent(_params_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("collectgarbage"));
            _module__.PluginHost::JSONRPC::Unregister(_T("url"));
            _module__.PluginHost::JSONRPC::Unregister(_T("visibility"));
            _module__.PluginHost::JSONRPC::Unregister(_T("fps"));
            _module__.PluginHost::JSONRPC::Unregister(_T("headers"));
            _module__.PluginHost::JSONRPC::Unregister(_T("useragent"));
            _module__.PluginHost::JSONRPC::Unregister(_T("localstorageenabled"));
            _module__.PluginHost::JSONRPC::Unregister(_T("httpcookieacceptpolicy"));
            _module__.PluginHost::JSONRPC::Unregister(_T("bridgereply"));
            _module__.PluginHost::JSONRPC::Unregister(_T("bridgeevent"));
        }

        namespace Event {

            // Event: 'loadfinished' - Initial HTML document has been completely loaded and parsed
            template<typename MODULE>
            static void LoadFinished(const MODULE& module_, const JsonData::WebBrowser::LoadFinishedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("loadfinished"), params, sendIfMethod_);
            }

            // Event: 'loadfinished' - Initial HTML document has been completely loaded and parsed
            template<typename MODULE>
            static void LoadFinished(const MODULE& module_, const Core::JSON::String& URL, const Core::JSON::DecSInt32& httpstatus, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::LoadFinishedParamsData params_;
                params_.URL = URL;
                params_.Httpstatus = httpstatus;

                LoadFinished(module_, params_, sendIfMethod_);
            }

            // Event: 'loadfinished' - Initial HTML document has been completely loaded and parsed
            template<typename MODULE>
            static void LoadFinished(const MODULE& module_, const string& URL, const int32_t httpstatus, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::LoadFinishedParamsData params_;
                params_.URL = URL;
                params_.Httpstatus = httpstatus;

                LoadFinished(module_, params_, sendIfMethod_);
            }

            // Event: 'loadfailed' - Browser failed to load page
            template<typename MODULE>
            static void LoadFailed(const MODULE& module_, const JsonData::WebBrowser::LoadFailedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("loadfailed"), params, sendIfMethod_);
            }

            // Event: 'loadfailed' - Browser failed to load page
            template<typename MODULE>
            static void LoadFailed(const MODULE& module_, const Core::JSON::String& URL, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::LoadFailedParamsData params_;
                params_.URL = URL;

                LoadFailed(module_, params_, sendIfMethod_);
            }

            // Event: 'loadfailed' - Browser failed to load page
            template<typename MODULE>
            static void LoadFailed(const MODULE& module_, const string& URL, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::LoadFailedParamsData params_;
                params_.URL = URL;

                LoadFailed(module_, params_, sendIfMethod_);
            }

            // Event: 'urlchange' - Signals a URL change in the browser
            template<typename MODULE>
            static void URLChange(const MODULE& module_, const JsonData::WebBrowser::URLChangeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("urlchange"), params, sendIfMethod_);
            }

            // Event: 'urlchange' - Signals a URL change in the browser
            template<typename MODULE>
            static void URLChange(const MODULE& module_, const Core::JSON::String& URL, const Core::JSON::Boolean& loaded, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::URLChangeParamsData params_;
                params_.URL = URL;
                params_.Loaded = loaded;

                URLChange(module_, params_, sendIfMethod_);
            }

            // Event: 'urlchange' - Signals a URL change in the browser
            template<typename MODULE>
            static void URLChange(const MODULE& module_, const string& URL, const bool loaded, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::URLChangeParamsData params_;
                params_.URL = URL;
                params_.Loaded = loaded;

                URLChange(module_, params_, sendIfMethod_);
            }

            // Event: 'visibilitychange' - Signals a visibility change of the browser
            template<typename MODULE>
            static void VisibilityChange(const MODULE& module_, const JsonData::WebBrowser::VisibilityChangeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("visibilitychange"), params, sendIfMethod_);
            }

            // Event: 'visibilitychange' - Signals a visibility change of the browser
            template<typename MODULE>
            static void VisibilityChange(const MODULE& module_, const Core::JSON::Boolean& hidden, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::VisibilityChangeParamsData params_;
                params_.Hidden = hidden;

                VisibilityChange(module_, params_, sendIfMethod_);
            }

            // Event: 'visibilitychange' - Signals a visibility change of the browser
            template<typename MODULE>
            static void VisibilityChange(const MODULE& module_, const bool hidden, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::VisibilityChangeParamsData params_;
                params_.Hidden = hidden;

                VisibilityChange(module_, params_, sendIfMethod_);
            }

            // Event: 'pageclosure' - Notifies that the web page requests to close its window
            template<typename MODULE>
            static void PageClosure(const MODULE& module_, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("pageclosure"), sendIfMethod_);
            }

            // Event: 'bridgequery' - A Base64 encoded JSON message from legacy $badger bridge
            template<typename MODULE>
            static void BridgeQuery(const MODULE& module_, const JsonData::WebBrowser::BridgeQueryParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("bridgequery"), params, sendIfMethod_);
            }

            // Event: 'bridgequery' - A Base64 encoded JSON message from legacy $badger bridge
            template<typename MODULE>
            static void BridgeQuery(const MODULE& module_, const Core::JSON::String& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::BridgeQueryParamsData params_;
                params_.Message = message;

                BridgeQuery(module_, params_, sendIfMethod_);
            }

            // Event: 'bridgequery' - A Base64 encoded JSON message from legacy $badger bridge
            template<typename MODULE>
            static void BridgeQuery(const MODULE& module_, const string& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::WebBrowser::BridgeQueryParamsData params_;
                params_.Message = message;

                BridgeQuery(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JWebBrowser

} // namespace Exchange

} // namespace Thunder

