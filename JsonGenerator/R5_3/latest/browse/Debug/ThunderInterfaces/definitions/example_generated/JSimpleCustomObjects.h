// Generated automatically from 'ISimpleCustomObjects.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SimpleCustomObjects.h"
#include <example_interfaces/ISimpleCustomObjects.h>

namespace Thunder {

namespace Example {

    namespace JSimpleCustomObjects {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        struct IHandler {
            virtual ~IHandler() = default;
            virtual void OnAddedEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
            virtual void OnNameChangedEventRegistration(ISimpleCustomObjects::IAccessory* object, const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
        };

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ISimpleCustomObjects* _implementation__, IHandler* _handler_)
        {
            ASSERT(_implementation__ != nullptr);
            ASSERT(_handler_ != nullptr);

            ASSERT(_module__.template Exists<ISimpleCustomObjects::IAccessory>() == true);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSimpleCustomObjects"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Indexed Property: 'accessory' - Accessory by name (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String, std::function<uint32_t(const Core::JSONRPC::Context&, const string&, Core::JSON::String&)>>(_T("accessory"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, const string& name, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (name.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        string _result_{};
                        Example::ISimpleCustomObjects::IAccessory* _real_result_{};

                        _errorCode__ = _implementation__->Accessory(name, _real_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            _result_ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Example::ISimpleCustomObjects::IAccessory>(_real_result_, context_);
                            _real_result_->Release();
                            result = std::move(_result_);
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'accessory::name' - Name of the accessory
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleCustomObjects::NameData, Core::JSON::String, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, const JsonData::SimpleCustomObjects::NameData&, Core::JSON::String&)>>(_T("accessory::name"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, const JsonData::SimpleCustomObjects::NameData& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        const ISimpleCustomObjects::IAccessory* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleCustomObjects::IAccessory>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            string _result_{};

                            _errorCode__ = (static_cast<const ISimpleCustomObjects::IAccessory*>(_implementation__))->Name(_result_);
                            _implementation__->Release();

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            ISimpleCustomObjects::IAccessory* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleCustomObjects::IAccessory>(instanceId_, context_);

                            if (_implementation__ != nullptr) {
                                const string _value_{params.Value};

                                _errorCode__ = _implementation__->Name(_value_);
                                _implementation__->Release();

                            }
                            else {
                                _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                            }
                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'accessory::pin' - Pin state
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleCustomObjects::PinData, Core::JSON::Boolean, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, const string&, const JsonData::SimpleCustomObjects::PinData&, Core::JSON::Boolean&)>>(_T("accessory::pin"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, const string& pin, const JsonData::SimpleCustomObjects::PinData& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint8_t _pinConv__{};

                    if (pin.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _pinConvResult__ = Core::FromString(pin, _pinConv__);

                        if (_pinConvResult__ == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            const ISimpleCustomObjects::IAccessory* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleCustomObjects::IAccessory>(instanceId_, context_);

                            if (_implementation__ != nullptr) {
                                bool _result_{};

                                _errorCode__ = (static_cast<const ISimpleCustomObjects::IAccessory*>(_implementation__))->Pin(_pinConv__, _result_);
                                _implementation__->Release();

                                if (_errorCode__ == Core::ERROR_NONE) {
                                    result = _result_;
                                }
                            }
                            else {
                                _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                ISimpleCustomObjects::IAccessory* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleCustomObjects::IAccessory>(instanceId_, context_);

                                if (_implementation__ != nullptr) {
                                    const bool _value_{params.Value};

                                    _errorCode__ = _implementation__->Pin(_pinConv__, _value_);
                                    _implementation__->Release();

                                }
                                else {
                                    _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                                }
                            }

                            result.Null(true);
                        }
                    }

                    return (_errorCode__);
                });

            // Register event status listeners...

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("added"),
                [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    _handler_->OnAddedEventRegistration(client_, status_);
                });

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("accessory::nameChanged"),
                [&_module__,_handler_](const uint32_t channelId_, const string& instanceId_, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    ISimpleCustomObjects::IAccessory* _object__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleCustomObjects::IAccessory>(instanceId_, Core::JSONRPC::Context(channelId_));
                    if (_object__ != nullptr) {
                        _handler_->OnNameChangedEventRegistration(_object__, client_, status_);
                        _object__->Release();
                    }
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("accessory"));
            _module__.PluginHost::JSONRPC::Unregister(_T("accessory::name"));
            _module__.PluginHost::JSONRPC::Unregister(_T("accessory::pin"));

            // Unregister event status listeners...
            _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("added"));
            _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("accessory::nameChanged"));
        }

        namespace Event {

            // Event: 'added' - Signals addition of a accessory
            template<typename MODULE>
            static void Added(const MODULE& module_, const JsonData::SimpleCustomObjects::AddedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("added"), params, sendIfMethod_);
            }

            // Event: 'added' - Signals addition of a accessory
            template<typename MODULE>
            static void Added(const MODULE& module_, const JsonData::SimpleCustomObjects::AddedParamsInfo& params, const string& client_)
            {
                module_.Notify(_T("added"), params, [&client_](const string& designator_) -> bool {
                    return ((client_ == designator_));
                });
            }

            // Event: 'added' - Signals addition of a accessory
            template<typename MODULE>
            static void Added(const MODULE& module_, const Core::JSON::String& accessory, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleCustomObjects::AddedParamsInfo params_;
                params_.Accessory = accessory;

                Added(module_, params_, sendIfMethod_);
            }

            // Event: 'added' - Signals addition of a accessory
            template<typename MODULE>
            static void Added(const MODULE& module_, const Core::JSON::String& accessory, const string& client_)
            {
                JsonData::SimpleCustomObjects::AddedParamsInfo params_;
                params_.Accessory = accessory;

                Added(module_, params_, client_);
            }

            // Event: 'added' - Signals addition of a accessory
            template<typename MODULE>
            static void Added(const MODULE& module_, ISimpleCustomObjects::IAccessory* const accessory, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleCustomObjects::AddedParamsInfo params_;
                params_.Accessory = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Example::ISimpleCustomObjects::IAccessory>(accessory);

                Added(module_, params_, sendIfMethod_);
            }

            // Event: 'added' - Signals addition of a accessory
            template<typename MODULE>
            static void Added(const MODULE& module_, ISimpleCustomObjects::IAccessory* const accessory, const string& client_)
            {
                JsonData::SimpleCustomObjects::AddedParamsInfo params_;
                params_.Accessory = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Example::ISimpleCustomObjects::IAccessory>(accessory);

                Added(module_, params_, client_);
            }

            // Event: 'removed' - Signals removal of a accessory
            template<typename MODULE>
            static void Removed(const MODULE& module_, const JsonData::SimpleCustomObjects::AddedParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("removed"), params, sendIfMethod_);
            }

            // Event: 'removed' - Signals removal of a accessory
            template<typename MODULE>
            static void Removed(const MODULE& module_, const Core::JSON::String& accessory, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleCustomObjects::AddedParamsInfo params_;
                params_.Accessory = accessory;

                Removed(module_, params_, sendIfMethod_);
            }

            // Event: 'removed' - Signals removal of a accessory
            template<typename MODULE>
            static void Removed(const MODULE& module_, ISimpleCustomObjects::IAccessory* const accessory, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleCustomObjects::AddedParamsInfo params_;
                params_.Accessory = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<Example::ISimpleCustomObjects::IAccessory>(accessory);

                Removed(module_, params_, sendIfMethod_);
            }

            // Event: 'accessory#ID::nameChanged' - Signals addition of a accessory
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleCustomObjects::IAccessory* const _obj, const JsonData::SimpleCustomObjects::NameChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleCustomObjects::IAccessory>(_obj);
                if (_instanceId.empty() == false) {
                    module_.Notify(Core::Format(_T("accessory#%s::nameChanged"), _instanceId.c_str()), params, sendIfMethod_);
                }
            }

            // Event: 'accessory#ID::nameChanged' - Signals addition of a accessory
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleCustomObjects::IAccessory* const _obj, const JsonData::SimpleCustomObjects::NameChangedParamsData& params, const string& client_)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleCustomObjects::IAccessory>(_obj);
                if (_instanceId.empty() == false) {
                    module_.Notify(Core::Format(_T("accessory#%s::nameChanged"), _instanceId.c_str()), params, [&client_](const string& designator_) -> bool {
                        return ((client_ == designator_));
                    });
                }
            }

            // Event: 'accessory#ID::nameChanged' - Signals addition of a accessory
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleCustomObjects::IAccessory* const _obj, const Core::JSON::String& name, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleCustomObjects::NameChangedParamsData params_;
                params_.Name = name;

                NameChanged(module_, _obj, params_, sendIfMethod_);
            }

            // Event: 'accessory#ID::nameChanged' - Signals addition of a accessory
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleCustomObjects::IAccessory* const _obj, const Core::JSON::String& name, const string& client_)
            {
                JsonData::SimpleCustomObjects::NameChangedParamsData params_;
                params_.Name = name;

                NameChanged(module_, _obj, params_, client_);
            }

            // Event: 'accessory#ID::nameChanged' - Signals addition of a accessory
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleCustomObjects::IAccessory* const _obj, const string& name, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleCustomObjects::NameChangedParamsData params_;
                params_.Name = name;

                NameChanged(module_, _obj, params_, sendIfMethod_);
            }

            // Event: 'accessory#ID::nameChanged' - Signals addition of a accessory
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleCustomObjects::IAccessory* const _obj, const string& name, const string& client_)
            {
                JsonData::SimpleCustomObjects::NameChangedParamsData params_;
                params_.Name = name;

                NameChanged(module_, _obj, params_, client_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSimpleCustomObjects

} // namespace Example

} // namespace Thunder

