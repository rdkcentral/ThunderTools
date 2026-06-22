// Generated automatically from 'IMessagingControl.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_MessagingControl.h"
#include <interfaces/IMessagingControl.h>

namespace Thunder {

namespace Exchange {

    namespace JMessagingControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IMessagingControl* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JMessagingControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'enable' - Enables/disables a message control
            _module__.PluginHost::JSONRPC::template Register<JsonData::MessagingControl::ControlInfo, void>(_T("enable"),
                [_implementation__](const JsonData::MessagingControl::ControlInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JMessagingControl"), _T("enable")));
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IMessagingControl::messagetype _type_{params.Type};
                        const string _category_{params.Category};
                        const string _module_{params.Module};
                        const bool _enabled_{params.Enabled};

                        _errorCode__ = _implementation__->Enable(_type_, _category_, _module_, _enabled_);

                    }

                    return (_errorCode__);
                });

            // Property: 'modules' - Retrieves a list of current message modules (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("modules"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<string, ::Thunder::RPC::ID_STRINGITERATOR>* _result_{};

                    _errorCode__ = _implementation__->Modules(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            string _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'controls' - Retrieves a list of current message controls for a specific module (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::MessagingControl::ControlInfo>, std::function<uint32_t(const string&, Core::JSON::ArrayType<JsonData::MessagingControl::ControlInfo>&)>>(_T("controls"),
                [_implementation__](const string& module, Core::JSON::ArrayType<JsonData::MessagingControl::ControlInfo>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (module.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        ::Thunder::RPC::IIteratorType<IMessagingControl::Control, ID_MESSAGING_CONTROL_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Controls(module, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::IMessagingControl::Control _resultItem__{};
                                while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                                _result_->Release();
                            }
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("enable"));
            _module__.PluginHost::JSONRPC::Unregister(_T("modules"));
            _module__.PluginHost::JSONRPC::Unregister(_T("controls"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JMessagingControl

} // namespace Exchange

} // namespace Thunder

