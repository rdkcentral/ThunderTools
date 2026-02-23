// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BrowserScripting.h"
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace Exchange {

    namespace JBrowserScripting {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IBrowserScripting* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JBrowserScripting"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'runjavascript' - Run javascript in main frame
            _module__.PluginHost::JSONRPC::template Register<JsonData::BrowserScripting::RunJavaScriptParamsData, void>(_T("runjavascript"),
                [_implementation__](const JsonData::BrowserScripting::RunJavaScriptParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _script_{params.Script};

                        _errorCode__ = _implementation__->RunJavaScript(_script_);

                    }

                    return (_errorCode__);
                });

            // Method: 'adduserscript' - Add user script to be executed at document start
            _module__.PluginHost::JSONRPC::template Register<JsonData::BrowserScripting::AddUserScriptParamsData, void>(_T("adduserscript"),
                [_implementation__](const JsonData::BrowserScripting::AddUserScriptParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _script_{params.Script};
                        const bool _topFrameOnly_{params.TopFrameOnly};

                        _errorCode__ = _implementation__->AddUserScript(_script_, _topFrameOnly_);

                    }

                    return (_errorCode__);
                });

            // Method: 'removealluserscripts' - Remove all user scripts
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("removealluserscripts"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->RemoveAllUserScripts();

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("runjavascript"));
            _module__.PluginHost::JSONRPC::Unregister(_T("adduserscript"));
            _module__.PluginHost::JSONRPC::Unregister(_T("removealluserscripts"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JBrowserScripting

} // namespace Exchange

} // namespace Thunder

