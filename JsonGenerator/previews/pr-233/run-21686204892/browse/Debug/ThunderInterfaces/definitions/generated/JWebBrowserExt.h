// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_WebBrowserExt.h"
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace Exchange {

    namespace JWebBrowserExt {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IWebBrowserExt* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JWebBrowserExt"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'deletedir' - Removes contents of a directory from the persistent storage (DEPRECATED)
            _module__.PluginHost::JSONRPC::template Register<JsonData::WebBrowserExt::DeleteDirParamsData, void>(_T("deletedir"),
                [_implementation__](const JsonData::WebBrowserExt::DeleteDirParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _path_{params.Path};

                        _errorCode__ = _implementation__->DeleteDir(_path_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("delete"), _T("deletedir"));

            // Property: 'languages' - User preferred languages
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::ArrayType<Core::JSON::String>, Core::JSON::ArrayType<Core::JSON::String>>(_T("languages"),
                [_implementation__](const Core::JSON::ArrayType<Core::JSON::String>& params, Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result_{};

                        _errorCode__ = (static_cast<const IWebBrowserExt*>(_implementation__))->Languages(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                string _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }
                    }
                    else {
                        ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _params_{};
                        std::list<string> _paramsElements_{};
                        auto _paramsIterator_ = params.Elements();
                        while (_paramsIterator_.Next() == true) { _paramsElements_.push_back(_paramsIterator_.Current()); }
                        using _paramsIteratorImplType_ = ::Thunder::RPC::IteratorType<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>;
                        _params_ = Core::ServiceType<_paramsIteratorImplType_>::Create<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>(std::move(_paramsElements_));
                        ASSERT(_params_ != nullptr);

                        _errorCode__ = _implementation__->Languages(static_cast<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* const&>(_params_));

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("deletedir"));
            _module__.PluginHost::JSONRPC::Unregister(_T("delete"));
            _module__.PluginHost::JSONRPC::Unregister(_T("languages"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JWebBrowserExt

} // namespace Exchange

} // namespace Thunder

