// Generated automatically from 'IScriptEngine.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_ScriptEngine.h"
#include <interfaces/IScriptEngine.h>

namespace WPEFramework {

namespace Exchange {

    namespace JScriptEngine {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IScriptEngine* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JScriptEngine"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'url' - Script to be loaded into the engine and to be executed
            _module_.Register<JsonData::ScriptEngine::URLData, Core::JSON::String>(_T("url"), 
                [_impl_](const JsonData::ScriptEngine::URLData& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        string _result{};

                        _errorCode = (static_cast<const IScriptEngine*>(_impl_))->URL(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const string _value{params.Value};

                        _errorCode = _impl_->URL(_value);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("url"));
        }

        namespace Event {

            // Event: 'urlchanged'
            static void URLChanged(const JSONRPC& _module_, const JsonData::ScriptEngine::URLChangedParamsData& params)
            {
                _module_.Notify(_T("urlchanged"), params);
            }

            // Event: 'urlchanged'
            static void URLChanged(const JSONRPC& _module_, const Core::JSON::String& URL)
            {
                JsonData::ScriptEngine::URLChangedParamsData _params_;
                _params_.URL = URL;

                URLChanged(_module_, _params_);
            }

            // Event: 'urlchanged'
            static void URLChanged(const JSONRPC& _module_, const string& URL)
            {
                JsonData::ScriptEngine::URLChangedParamsData _params_;
                _params_.URL = URL;

                URLChanged(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JScriptEngine

} // namespace Exchange

} // namespace WPEFramework

