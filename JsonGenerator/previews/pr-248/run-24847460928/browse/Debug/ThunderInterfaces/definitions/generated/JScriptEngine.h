// Generated automatically from 'IScriptEngine.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_ScriptEngine.h"
#include <interfaces/IScriptEngine.h>

namespace Thunder {

namespace Exchange {

    namespace JScriptEngine {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IScriptEngine* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JScriptEngine"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'url' - Script to be loaded into the engine and to be executed
            _module__.PluginHost::JSONRPC::template Register<JsonData::ScriptEngine::URLData, Core::JSON::String>(_T("url"),
                [_implementation__](const JsonData::ScriptEngine::URLData& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        string _result_{};

                        _errorCode__ = (static_cast<const IScriptEngine*>(_implementation__))->URL(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _value_{params.Value};

                            _errorCode__ = _implementation__->URL(_value_);

                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("url"));
        }

        namespace Event {

            // Event: 'urlchanged' - Signal changes on the subscribed namespace
            template<typename MODULE>
            static void URLChanged(const MODULE& module_, const JsonData::ScriptEngine::URLChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("urlchanged"), params, sendIfMethod_);
            }

            // Event: 'urlchanged' - Signal changes on the subscribed namespace
            template<typename MODULE>
            static void URLChanged(const MODULE& module_, const Core::JSON::String& URL, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::ScriptEngine::URLChangedParamsData params_;
                params_.URL = URL;

                URLChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'urlchanged' - Signal changes on the subscribed namespace
            template<typename MODULE>
            static void URLChanged(const MODULE& module_, const string& URL, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::ScriptEngine::URLChangedParamsData params_;
                params_.URL = URL;

                URLChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JScriptEngine

} // namespace Exchange

} // namespace Thunder

