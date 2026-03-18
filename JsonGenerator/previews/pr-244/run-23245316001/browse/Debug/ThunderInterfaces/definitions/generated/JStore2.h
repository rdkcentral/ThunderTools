// Generated automatically from 'IStore2.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Store2.h"
#include <interfaces/IStore2.h>

namespace Thunder {

namespace Exchange {

    namespace JStore2 {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IStore2* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JStore2"), Version::Major, Version::Minor, Version::Patch);

            // Register alternative notification names...
            _module__.PluginHost::JSONRPC::RegisterEventAlias(_T("onValueChanged"), _T("valueChanged"));

            // Register methods and properties...

            // Method: 'setValue'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Store2::SetValueParamsData, void>(_T("setValue"),
                [_implementation__](const JsonData::Store2::SetValueParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IStore2::ScopeType _scope_{params.Scope};
                        const string _ns_{params.Ns};
                        const string _key_{params.Key};
                        const string _value_{params.Value};
                        const uint32_t _ttl_{params.Ttl};

                        _errorCode__ = _implementation__->SetValue(_scope_, _ns_, _key_, _value_, _ttl_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("setValue"), _T("setValue"));

            // Method: 'getValue'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Store2::GetValueParamsInfo, JsonData::Store2::GetValueResultData>(_T("getValue"),
                [_implementation__](const JsonData::Store2::GetValueParamsInfo& params, JsonData::Store2::GetValueResultData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IStore2::ScopeType _scope_{params.Scope};
                        const string _ns_{params.Ns};
                        const string _key_{params.Key};
                        string _value_{};
                        uint32_t _ttl_{};

                        _errorCode__ = _implementation__->GetValue(_scope_, _ns_, _key_, _value_, _ttl_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Value = _value_;
                            result.Ttl = _ttl_;
                        }
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("getValue"), _T("getValue"));

            // Method: 'deleteKey'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Store2::GetValueParamsInfo, void>(_T("deleteKey"),
                [_implementation__](const JsonData::Store2::GetValueParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IStore2::ScopeType _scope_{params.Scope};
                        const string _ns_{params.Ns};
                        const string _key_{params.Key};

                        _errorCode__ = _implementation__->DeleteKey(_scope_, _ns_, _key_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("deleteKey"), _T("deleteKey"));

            // Method: 'deleteNamespace'
            _module__.PluginHost::JSONRPC::template Register<JsonData::Store2::DeleteNamespaceParamsData, void>(_T("deleteNamespace"),
                [_implementation__](const JsonData::Store2::DeleteNamespaceParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IStore2::ScopeType _scope_{params.Scope};
                        const string _ns_{params.Ns};

                        _errorCode__ = _implementation__->DeleteNamespace(_scope_, _ns_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("deleteNamespace"), _T("deleteNamespace"));

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("setValue"));
            _module__.PluginHost::JSONRPC::Unregister(_T("setValue"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getValue"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getValue"));
            _module__.PluginHost::JSONRPC::Unregister(_T("deleteKey"));
            _module__.PluginHost::JSONRPC::Unregister(_T("deleteKey"));
            _module__.PluginHost::JSONRPC::Unregister(_T("deleteNamespace"));
            _module__.PluginHost::JSONRPC::Unregister(_T("deleteNamespace"));

            // Unegister alternative notification names...
            _module__.PluginHost::JSONRPC::UnregisterEventAlias(_T("onValueChanged"), _T("valueChanged"));
        }

        namespace Event {

            // Event: 'valueChanged'
            template<typename MODULE>
            static void ValueChanged(const MODULE& module_, const JsonData::Store2::ValueChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("valueChanged"), params, sendIfMethod_);
            }

            // Event: 'valueChanged'
            template<typename MODULE>
            static void ValueChanged(const MODULE& module_, const Core::JSON::EnumType<Exchange::IStore2::ScopeType>& scope, const Core::JSON::String& ns, const Core::JSON::String& key, const Core::JSON::String& value, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Store2::ValueChangedParamsData params_;
                params_.Scope = scope;
                params_.Ns = ns;
                params_.Key = key;
                params_.Value = value;

                ValueChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'valueChanged'
            template<typename MODULE>
            static void ValueChanged(const MODULE& module_, const IStore2::ScopeType scope, const string& ns, const string& key, const string& value, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Store2::ValueChangedParamsData params_;
                params_.Scope = scope;
                params_.Ns = ns;
                params_.Key = key;
                params_.Value = value;

                ValueChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JStore2

} // namespace Exchange

} // namespace Thunder

