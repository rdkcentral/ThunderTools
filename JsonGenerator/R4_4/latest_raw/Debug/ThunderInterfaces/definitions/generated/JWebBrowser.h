// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_WebBrowser.h"
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace Exchange {

    namespace JWebBrowser {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IWebBrowser* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JWebBrowser"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'collectgarbage' - Initiate garbage collection
            _module_.Register<void, void>(_T("collectgarbage"), 
                [_impl_]() -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    _errorCode = _impl_->CollectGarbage();

                    return (_errorCode);
                });

            // Property: 'url' - Page loaded in the browser
            _module_.Register<Core::JSON::String, Core::JSON::String>(_T("url"), 
                [_impl_](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        string _result{};

                        _errorCode = (static_cast<const IWebBrowser*>(_impl_))->URL(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const string _params{params};

                        _errorCode = _impl_->URL(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'visibility' - Browser window visibility state
            _module_.Register<Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>,
                     Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>>(_T("visibility"), 
                [_impl_](const Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>& params,
                         Core::JSON::EnumType<Exchange::IWebBrowser::VisibilityType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        Exchange::IWebBrowser::VisibilityType _result{};

                        _errorCode = (static_cast<const IWebBrowser*>(_impl_))->Visibility(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const Exchange::IWebBrowser::VisibilityType _params{params};

                        _errorCode = _impl_->Visibility(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'fps' - Current framerate the browser is rendering at (r/o)
            _module_.Register<void, Core::JSON::DecUInt8>(_T("fps"), 
                [_impl_](Core::JSON::DecUInt8& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint8_t _result{};

                    _errorCode = _impl_->FPS(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'useragent' - UserAgent string used by the browser
            _module_.Register<Core::JSON::String, Core::JSON::String>(_T("useragent"), 
                [_impl_](const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        string _result{};

                        _errorCode = (static_cast<const IWebBrowser*>(_impl_))->UserAgent(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const string _params{params};

                        _errorCode = _impl_->UserAgent(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'localstorageenabled' - Controls the local storage availability
            _module_.Register<Core::JSON::Boolean, Core::JSON::Boolean>(_T("localstorageenabled"), 
                [_impl_](const Core::JSON::Boolean& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        bool _result{};

                        _errorCode = (static_cast<const IWebBrowser*>(_impl_))->LocalStorageEnabled(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const bool _params{params};

                        _errorCode = _impl_->LocalStorageEnabled(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'httpcookieacceptpolicy' - HTTP cookies accept policy
            _module_.Register<Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>,
                     Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>>(_T("httpcookieacceptpolicy"), 
                [_impl_](const Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>& params,
                         Core::JSON::EnumType<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        Exchange::IWebBrowser::HTTPCookieAcceptPolicyType _result{};

                        _errorCode = (static_cast<const IWebBrowser*>(_impl_))->HTTPCookieAcceptPolicy(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const Exchange::IWebBrowser::HTTPCookieAcceptPolicyType _params{params};

                        _errorCode = _impl_->HTTPCookieAcceptPolicy(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'bridgereply' - Response for legacy $badger (w/o)
            _module_.Register<Core::JSON::String, void>(_T("bridgereply"), 
                [_impl_](const Core::JSON::String& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _params{params};

                    _errorCode = _impl_->BridgeReply(_params);

                    return (_errorCode);
                });

            // Property: 'bridgeevent' - Send legacy $badger event (w/o)
            _module_.Register<Core::JSON::String, void>(_T("bridgeevent"), 
                [_impl_](const Core::JSON::String& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // write-only property set
                    const string _params{params};

                    _errorCode = _impl_->BridgeEvent(_params);

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("collectgarbage"));
            _module_.Unregister(_T("url"));
            _module_.Unregister(_T("visibility"));
            _module_.Unregister(_T("fps"));
            _module_.Unregister(_T("useragent"));
            _module_.Unregister(_T("localstorageenabled"));
            _module_.Unregister(_T("httpcookieacceptpolicy"));
            _module_.Unregister(_T("bridgereply"));
            _module_.Unregister(_T("bridgeevent"));
        }

        namespace Event {

            // Event: 'loadfinished' - Initial HTML document has been completely loaded and parsed
            static void LoadFinished(const JSONRPC& _module_, const JsonData::WebBrowser::LoadFinishedParamsData& params)
            {
                _module_.Notify(_T("loadfinished"), params);
            }

            // Event: 'loadfinished' - Initial HTML document has been completely loaded and parsed
            static void LoadFinished(const JSONRPC& _module_, const Core::JSON::String& URL, const Core::JSON::DecSInt32& httpstatus)
            {
                JsonData::WebBrowser::LoadFinishedParamsData _params_;
                _params_.URL = URL;
                _params_.Httpstatus = httpstatus;

                LoadFinished(_module_, _params_);
            }

            // Event: 'loadfinished' - Initial HTML document has been completely loaded and parsed
            static void LoadFinished(const JSONRPC& _module_, const string& URL, const int32_t& httpstatus)
            {
                JsonData::WebBrowser::LoadFinishedParamsData _params_;
                _params_.URL = URL;
                _params_.Httpstatus = httpstatus;

                LoadFinished(_module_, _params_);
            }

            // Event: 'loadfailed' - Browser failed to load page
            static void LoadFailed(const JSONRPC& _module_, const JsonData::WebBrowser::LoadFailedParamsData& params)
            {
                _module_.Notify(_T("loadfailed"), params);
            }

            // Event: 'loadfailed' - Browser failed to load page
            static void LoadFailed(const JSONRPC& _module_, const Core::JSON::String& URL)
            {
                JsonData::WebBrowser::LoadFailedParamsData _params_;
                _params_.URL = URL;

                LoadFailed(_module_, _params_);
            }

            // Event: 'loadfailed' - Browser failed to load page
            static void LoadFailed(const JSONRPC& _module_, const string& URL)
            {
                JsonData::WebBrowser::LoadFailedParamsData _params_;
                _params_.URL = URL;

                LoadFailed(_module_, _params_);
            }

            // Event: 'urlchange' - Signals a URL change in the browser
            static void URLChange(const JSONRPC& _module_, const JsonData::WebBrowser::URLChangeParamsData& params)
            {
                _module_.Notify(_T("urlchange"), params);
            }

            // Event: 'urlchange' - Signals a URL change in the browser
            static void URLChange(const JSONRPC& _module_, const Core::JSON::String& URL, const Core::JSON::Boolean& loaded)
            {
                JsonData::WebBrowser::URLChangeParamsData _params_;
                _params_.URL = URL;
                _params_.Loaded = loaded;

                URLChange(_module_, _params_);
            }

            // Event: 'urlchange' - Signals a URL change in the browser
            static void URLChange(const JSONRPC& _module_, const string& URL, const bool& loaded)
            {
                JsonData::WebBrowser::URLChangeParamsData _params_;
                _params_.URL = URL;
                _params_.Loaded = loaded;

                URLChange(_module_, _params_);
            }

            // Event: 'visibilitychange' - Signals a visibility change of the browser
            static void VisibilityChange(const JSONRPC& _module_, const JsonData::WebBrowser::VisibilityChangeParamsData& params)
            {
                _module_.Notify(_T("visibilitychange"), params);
            }

            // Event: 'visibilitychange' - Signals a visibility change of the browser
            static void VisibilityChange(const JSONRPC& _module_, const Core::JSON::Boolean& hidden)
            {
                JsonData::WebBrowser::VisibilityChangeParamsData _params_;
                _params_.Hidden = hidden;

                VisibilityChange(_module_, _params_);
            }

            // Event: 'visibilitychange' - Signals a visibility change of the browser
            static void VisibilityChange(const JSONRPC& _module_, const bool& hidden)
            {
                JsonData::WebBrowser::VisibilityChangeParamsData _params_;
                _params_.Hidden = hidden;

                VisibilityChange(_module_, _params_);
            }

            // Event: 'pageclosure' - Notifies that the web page requests to close its window
            static void PageClosure(const JSONRPC& _module_)
            {
                _module_.Notify(_T("pageclosure"));
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JWebBrowser

} // namespace Exchange

} // namespace WPEFramework

