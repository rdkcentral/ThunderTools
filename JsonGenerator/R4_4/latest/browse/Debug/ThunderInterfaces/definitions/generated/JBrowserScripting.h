// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_BrowserScripting.h"
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace Exchange {

    namespace JBrowserScripting {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IBrowserScripting* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JBrowserScripting"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'runjavascript' - Run javascript in main frame
            _module_.Register<JsonData::BrowserScripting::RunJavaScriptParamsData, void>(_T("runjavascript"), 
                [_impl_](const JsonData::BrowserScripting::RunJavaScriptParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _script{params.Script};

                    _errorCode = _impl_->RunJavaScript(_script);

                    return (_errorCode);
                });

            // Method: 'adduserscript' - Add user script to be executed at document start
            _module_.Register<JsonData::BrowserScripting::AddUserScriptParamsData, void>(_T("adduserscript"), 
                [_impl_](const JsonData::BrowserScripting::AddUserScriptParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _script{params.Script};
                    const bool _topFrameOnly{params.TopFrameOnly};

                    _errorCode = _impl_->AddUserScript(_script, _topFrameOnly);

                    return (_errorCode);
                });

            // Method: 'removealluserscripts' - Remove all user scripts
            _module_.Register<void, void>(_T("removealluserscripts"), 
                [_impl_]() -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    _errorCode = _impl_->RemoveAllUserScripts();

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("runjavascript"));
            _module_.Unregister(_T("adduserscript"));
            _module_.Unregister(_T("removealluserscripts"));
        }

        POP_WARNING()

    } // namespace JBrowserScripting

} // namespace Exchange

} // namespace WPEFramework

