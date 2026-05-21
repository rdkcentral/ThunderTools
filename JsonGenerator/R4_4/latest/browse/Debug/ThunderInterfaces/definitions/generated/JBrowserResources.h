// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_BrowserResources.h"
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace Exchange {

    namespace JBrowserResources {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IBrowserResources* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JBrowserResources"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'userscripts' - User scripts used by the browser
            _module_.Register<Core::JSON::ArrayType<Core::JSON::String>, Core::JSON::ArrayType<Core::JSON::String>>(_T("userscripts"), 
                [_impl_](const Core::JSON::ArrayType<Core::JSON::String>& params, Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        ::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result{};

                        _errorCode = (static_cast<const IBrowserResources*>(_impl_))->UserScripts(_result);

                        if (_errorCode == Core::ERROR_NONE) {

                            if (_result != nullptr) {
                                string _resultItem_{};
                                while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                                _result->Release();
                            }
                        }

                    } else {
                        // property set
                        std::list<string> _elements;
                        auto _Iterator = params.Elements();
                        while (_Iterator.Next() == true) { _elements.push_back(_Iterator.Current()); }

                        ::WPEFramework::RPC::IIteratorType<string,
                                 RPC::ID_STRINGITERATOR>* const _params{Core::Service<::WPEFramework::RPC::IteratorType<::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>>::Create<::WPEFramework::RPC::IIteratorType<string,
                                 RPC::ID_STRINGITERATOR>>(_elements)};

                        ASSERT(_params != nullptr); 

                        if ((_params != nullptr)) {
                            _errorCode = _impl_->UserScripts(_params);
                            _params->Release();
                        } else {
                            _errorCode = Core::ERROR_GENERAL;
                        }

                        // result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'userstylesheets' - User style sheets used by the browser
            _module_.Register<Core::JSON::ArrayType<Core::JSON::String>, Core::JSON::ArrayType<Core::JSON::String>>(_T("userstylesheets"), 
                [_impl_](const Core::JSON::ArrayType<Core::JSON::String>& params, Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        ::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result{};

                        _errorCode = (static_cast<const IBrowserResources*>(_impl_))->UserStyleSheets(_result);

                        if (_errorCode == Core::ERROR_NONE) {

                            if (_result != nullptr) {
                                string _resultItem_{};
                                while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                                _result->Release();
                            }
                        }

                    } else {
                        // property set
                        std::list<string> _elements;
                        auto _Iterator = params.Elements();
                        while (_Iterator.Next() == true) { _elements.push_back(_Iterator.Current()); }

                        ::WPEFramework::RPC::IIteratorType<string,
                                 RPC::ID_STRINGITERATOR>* const _params{Core::Service<::WPEFramework::RPC::IteratorType<::WPEFramework::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>>::Create<::WPEFramework::RPC::IIteratorType<string,
                                 RPC::ID_STRINGITERATOR>>(_elements)};

                        ASSERT(_params != nullptr); 

                        if ((_params != nullptr)) {
                            _errorCode = _impl_->UserStyleSheets(_params);
                            _params->Release();
                        } else {
                            _errorCode = Core::ERROR_GENERAL;
                        }

                        // result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("userscripts"));
            _module_.Unregister(_T("userstylesheets"));
        }

        POP_WARNING()

    } // namespace JBrowserResources

} // namespace Exchange

} // namespace WPEFramework

