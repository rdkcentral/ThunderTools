// Generated automatically from 'ITestPlugin.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_TestPlugin.h"
#include <qa_interfaces/ITestPlugin.h>

namespace Thunder {

namespace QualityAssurance {

    namespace JTestPlugin {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ITestPlugin* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JTestPlugin"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'echo'
            _module__.PluginHost::JSONRPC::template Register<JsonData::TestPlugin::EchoParamsData, Core::JSON::String>(_T("echo"),
                [_implementation__](const JsonData::TestPlugin::EchoParamsData& params, Core::JSON::String& output) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JTestPlugin"), _T("echo")));
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _input_{params.Input};
                        string _output_{};

                        _errorCode__ = _implementation__->Echo(_input_, _output_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            output = _output_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'greet'
            _module__.PluginHost::JSONRPC::template Register<JsonData::TestPlugin::GreetParamsData, Core::JSON::String>(_T("greet"),
                [_implementation__](const JsonData::TestPlugin::GreetParamsData& params, Core::JSON::String& message) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JTestPlugin"), _T("greet")));
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _name_{params.Name};
                        string _message_{};

                        _errorCode__ = _implementation__->Greet(_name_, _message_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            message = _message_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("echo"));
            _module__.PluginHost::JSONRPC::Unregister(_T("greet"));
        }

        namespace Event {

            // Event: 'onGreeting'
            template<typename MODULE>
            static void OnGreeting(const MODULE& module_, const JsonData::TestPlugin::OnGreetingParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("onGreeting"), params, sendIfMethod_);
            }

            // Event: 'onGreeting'
            template<typename MODULE>
            static void OnGreeting(const MODULE& module_, const Core::JSON::String& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::TestPlugin::OnGreetingParamsData params_;
                params_.Message = message;

                OnGreeting(module_, params_, sendIfMethod_);
            }

            // Event: 'onGreeting'
            template<typename MODULE>
            static void OnGreeting(const MODULE& module_, const string& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::TestPlugin::OnGreetingParamsData params_;
                params_.Message = message;

                OnGreeting(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JTestPlugin

} // namespace QualityAssurance

} // namespace Thunder

