// Generated automatically from 'ISimpleInstanceObjects.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_SimpleInstanceObjects.h"
#include <example_interfaces/ISimpleInstanceObjects.h>

namespace Thunder {

namespace Example {

    namespace JSimpleInstanceObjects {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        struct IHandler {
            virtual ~IHandler() = default;
            virtual void OnStateChangedEventRegistration(ISimpleInstanceObjects::IDevice* object, const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
            virtual void OnPinChangedEventRegistration(ISimpleInstanceObjects::IDevice* object, const string& client, const Core::OptionalType<uint8_t>& index, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
        };

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ISimpleInstanceObjects* _implementation__, IHandler* _handler_)
        {
            ASSERT(_implementation__ != nullptr);
            ASSERT(_handler_ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSimpleInstanceObjects"), Version::Major, Version::Minor, Version::Patch);

            // Install lookup handlers
            _module__.PluginHost::JSONRPCSupportsAutoObjectLookup::template InstallHandler<ISimpleInstanceObjects::IDevice>();

            // Install subscription assessor

            _module__.SetSubscribeAssessor([&_module__](const uint32_t channelId, const string& prefix, const string& instanceId, const string&, const string&) -> bool {
                    bool result = true;

                    if (instanceId.empty() == false) {
                        if (prefix == _T("device")) {
                            result = _module__.PluginHost::JSONRPCSupportsAutoObjectLookup::template Check<ISimpleInstanceObjects::IDevice>(instanceId, channelId);
                        }
                    }

                    return (result);
                });

            // Register methods and properties...

            // Method: 'acquire' - Acquires a device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleInstanceObjects::AcquireParamsData, Core::JSON::DecUInt32, std::function<uint32_t(const Core::JSONRPC::Context&, const JsonData::SimpleInstanceObjects::AcquireParamsData&, Core::JSON::DecUInt32&)>>(_T("acquire"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, const JsonData::SimpleInstanceObjects::AcquireParamsData& params, Core::JSON::DecUInt32& device) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _name_{params.Name};
                        uint32_t _device_{};
                        Example::ISimpleInstanceObjects::IDevice* _real_device_{};

                        _errorCode__ = _implementation__->Acquire(_name_, _real_device_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            _device_ = _module__.PluginHost::JSONRPCSupportsAutoObjectLookup::template Store<Example::ISimpleInstanceObjects::IDevice>(_real_device_, context_);
                            _real_device_->Release();
                            device = std::move(_device_);
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'relinquish' - Relinquishes a device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleInstanceObjects::RelinquishParamsData, void, std::function<uint32_t(const Core::JSONRPC::Context&, const JsonData::SimpleInstanceObjects::RelinquishParamsData&)>>(_T("relinquish"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, const JsonData::SimpleInstanceObjects::RelinquishParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _device_{params.Device};
                        Example::ISimpleInstanceObjects::IDevice* _real_device_{};
                        _real_device_ = _module__.template Dispose<Example::ISimpleInstanceObjects::IDevice>(context_, _device_);

                        if (_real_device_ != nullptr) {
                            _errorCode__ = _implementation__->Relinquish(_real_device_);
                        }
                        else {
                            _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                        }

                    }

                    return (_errorCode__);
                });

            // Method: 'device::enable' - Enable the device
            _module__.PluginHost::JSONRPC::template Register<void, void, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&)>>(_T("device::enable"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ISimpleInstanceObjects::IDevice* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, context_);

                    if (_implementation__ != nullptr) {

                        _errorCode__ = _implementation__->Enable();
                        _implementation__->Release();

                    }
                    else {
                        _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                    }

                    return (_errorCode__);
                });

            // Method: 'device::disable' - Disable the device
            _module__.PluginHost::JSONRPC::template Register<void, void, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&)>>(_T("device::disable"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ISimpleInstanceObjects::IDevice* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, context_);

                    if (_implementation__ != nullptr) {

                        _errorCode__ = _implementation__->Disable();
                        _implementation__->Release();

                    }
                    else {
                        _errorCode__ = Core::ERROR_UNKNOWN_KEY;
                    }

                    return (_errorCode__);
                });

            // Property: 'device::name' - Name of the device
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleInstanceObjects::NameData, Core::JSON::String, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, const JsonData::SimpleInstanceObjects::NameData&, Core::JSON::String&)>>(_T("device::name"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, const JsonData::SimpleInstanceObjects::NameData& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        const ISimpleInstanceObjects::IDevice* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, context_);

                        if (_implementation__ != nullptr) {
                            string _result_{};

                            _errorCode__ = _implementation__->Name(_result_);
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
                            ISimpleInstanceObjects::IDevice* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, context_);

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

            // Indexed Property: 'device::pin' - A pin
            _module__.PluginHost::JSONRPC::template Register<JsonData::SimpleInstanceObjects::PinData, Core::JSON::Boolean, std::function<uint32_t(const Core::JSONRPC::Context&, Core::JSONRPC::instance_id_follows_t, const string&, const string&, const JsonData::SimpleInstanceObjects::PinData&, Core::JSON::Boolean&)>>(_T("device::pin"),
                [_implementation__, &_module__](const Core::JSONRPC::Context& context_, Core::JSONRPC::instance_id_follows_t, const string& instanceId_, const string& pin, const JsonData::SimpleInstanceObjects::PinData& params, Core::JSON::Boolean& result) -> uint32_t {
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
                            const ISimpleInstanceObjects::IDevice* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, context_);

                            if (_implementation__ != nullptr) {
                                bool _result_{};

                                _errorCode__ = _implementation__->Pin(_pinConv__, _result_);
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
                                ISimpleInstanceObjects::IDevice* const _implementation__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, context_);

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

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("device::stateChanged"),
                [&_module__,_handler_](const uint32_t channelId_, const string& instanceId_, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    ISimpleInstanceObjects::IDevice* _object__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, Core::JSONRPC::Context(channelId_));
                    if (_object__ != nullptr) {
                        _handler_->OnStateChangedEventRegistration(_object__, client_, status_);
                        _object__->Release();
                    }
                });

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("device::pinChanged"),
                [&_module__,_handler_](const uint32_t channelId_, const string& instanceId_, const string& client_, const string& index_, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    ISimpleInstanceObjects::IDevice* _object__ = _module__.PluginHost::JSONRPCSupportsObjectLookup::template LookUp<ISimpleInstanceObjects::IDevice>(instanceId_, Core::JSONRPC::Context(channelId_));
                    if (_object__ != nullptr) {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<uint8_t> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            uint8_t _indexConv__{};
                            const bool _indexConvResult__ = Core::FromString(index_, _indexConv__);

                            if (_indexConvResult__ == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                _indexOpt__ = _indexConv__;
                            }
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            _handler_->OnPinChangedEventRegistration(_object__, client_, _indexOpt__, status_);
                        }
                        _object__->Release();
                    }
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("acquire"));
            _module__.PluginHost::JSONRPC::Unregister(_T("relinquish"));
            _module__.PluginHost::JSONRPC::Unregister(_T("device::enable"));
            _module__.PluginHost::JSONRPC::Unregister(_T("device::disable"));
            _module__.PluginHost::JSONRPC::Unregister(_T("device::name"));
            _module__.PluginHost::JSONRPC::Unregister(_T("device::pin"));

            // Unregister event status listeners...
            _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("device::stateChanged"));
            _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("device::pinChanged"));

            // Uninstall subscription assessor
            _module__.SetSubscribeAssessor(nullptr);
        }

        namespace Event {

            // Event: 'device#ID::nameChanged' - Signals device name changes
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const JsonData::SimpleInstanceObjects::NameChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleInstanceObjects::IDevice>(_obj);
                if (_instanceId.empty() == false) {
                    module_.Notify(Core::Format(_T("device#%s::nameChanged"), _instanceId.c_str()), params, sendIfMethod_);
                }
            }

            // Event: 'device#ID::nameChanged' - Signals device name changes
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::JSON::String& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleInstanceObjects::NameChangedParamsData params_;
                params_.State = state;

                NameChanged(module_, _obj, params_, sendIfMethod_);
            }

            // Event: 'device#ID::nameChanged' - Signals device name changes
            template<typename MODULE>
            static void NameChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const string& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleInstanceObjects::NameChangedParamsData params_;
                params_.State = state;

                NameChanged(module_, _obj, params_, sendIfMethod_);
            }

            // Event: 'device#ID::stateChanged' - Signals device state changes
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const JsonData::SimpleInstanceObjects::StateChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleInstanceObjects::IDevice>(_obj);
                if (_instanceId.empty() == false) {
                    module_.Notify(Core::Format(_T("device#%s::stateChanged"), _instanceId.c_str()), params, sendIfMethod_);
                }
            }

            // Event: 'device#ID::stateChanged' - Signals device state changes
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const JsonData::SimpleInstanceObjects::StateChangedParamsData& params, const string& client_)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleInstanceObjects::IDevice>(_obj);
                if (_instanceId.empty() == false) {
                    module_.Notify(Core::Format(_T("device#%s::stateChanged"), _instanceId.c_str()), params, [&client_](const string& designator_) -> bool {
                        return ((client_ == designator_));
                    });
                }
            }

            // Event: 'device#ID::stateChanged' - Signals device state changes
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::JSON::EnumType<Example::ISimpleInstanceObjects::state>& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleInstanceObjects::StateChangedParamsData params_;
                params_.State = state;

                StateChanged(module_, _obj, params_, sendIfMethod_);
            }

            // Event: 'device#ID::stateChanged' - Signals device state changes
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::JSON::EnumType<Example::ISimpleInstanceObjects::state>& state, const string& client_)
            {
                JsonData::SimpleInstanceObjects::StateChangedParamsData params_;
                params_.State = state;

                StateChanged(module_, _obj, params_, client_);
            }

            // Event: 'device#ID::stateChanged' - Signals device state changes
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const ISimpleInstanceObjects::state state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::SimpleInstanceObjects::StateChangedParamsData params_;
                params_.State = state;

                StateChanged(module_, _obj, params_, sendIfMethod_);
            }

            // Event: 'device#ID::stateChanged' - Signals device state changes
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const ISimpleInstanceObjects::state state, const string& client_)
            {
                JsonData::SimpleInstanceObjects::StateChangedParamsData params_;
                params_.State = state;

                StateChanged(module_, _obj, params_, client_);
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const JsonData::SimpleInstanceObjects::PinChangedParamsData& params, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleInstanceObjects::IDevice>(_obj);
                if (_instanceId.empty() == false) {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(Core::Format(_T("device#%s::pinChanged"), _instanceId.c_str()), params, [&id_](const string&, const string& index_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            Core::OptionalType<uint8_t> _indexOpt__{};

                            if (index_.empty() == true) {
                                // no error, optional
                            }
                            else {
                                uint8_t _indexConv__{};
                                const bool _indexConvResult__ = Core::FromString(index_, _indexConv__);
                                _indexOpt__ = _indexConv__;
                            }

                            return ((_errorCode__ == Core::ERROR_NONE) && ((_indexOpt__.IsSet() == false) || (id_ == _indexOpt__)));
                        });
                    }
                    else {
                        module_.Notify(Core::Format(_T("device#%s::pinChanged"), _instanceId.c_str()), params, sendIfMethod_);
                    }
                }
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const JsonData::SimpleInstanceObjects::PinChangedParamsData& params, const string& client_)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleInstanceObjects::IDevice>(_obj);
                if (_instanceId.empty() == false) {
                    module_.Notify(Core::Format(_T("device#%s::pinChanged"), _instanceId.c_str()), params, [&id_, &client_](const string& designator_, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<uint8_t> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            uint8_t _indexConv__{};
                            const bool _indexConvResult__ = Core::FromString(index_, _indexConv__);
                            _indexOpt__ = _indexConv__;
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && ((_indexOpt__.IsSet() == false) || (id_ == _indexOpt__)) && (client_ == designator_));
                    });
                }
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const JsonData::SimpleInstanceObjects::PinChangedParamsData& params, const bool, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleInstanceObjects::IDevice>(_obj);
                if (_instanceId.empty() == false) {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(Core::Format(_T("device#%s::pinChanged"), _instanceId.c_str()), params, [&id_](const string&, const string& index_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            Core::OptionalType<uint8_t> _indexOpt__{};

                            if (index_.empty() == true) {
                                // no error, optional
                            }
                            else {
                                uint8_t _indexConv__{};
                                const bool _indexConvResult__ = Core::FromString(index_, _indexConv__);
                                _indexOpt__ = _indexConv__;
                            }

                            return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexOpt__));
                        });
                    }
                    else {
                        module_.Notify(Core::Format(_T("device#%s::pinChanged"), _instanceId.c_str()), params, sendIfMethod_);
                    }
                }
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const JsonData::SimpleInstanceObjects::PinChangedParamsData& params, const bool, const string& client_)
            {
                ASSERT(_obj != nullptr);

                const string _instanceId = module_.PluginHost::JSONRPCSupportsObjectLookup::template InstanceId<ISimpleInstanceObjects::IDevice>(_obj);
                if (_instanceId.empty() == false) {
                    module_.Notify(Core::Format(_T("device#%s::pinChanged"), _instanceId.c_str()), params, [&id_, &client_](const string& designator_, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<uint8_t> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            uint8_t _indexConv__{};
                            const bool _indexConvResult__ = Core::FromString(index_, _indexConv__);
                            _indexOpt__ = _indexConv__;
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexOpt__) && (client_ == designator_));
                    });
                }
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const Core::JSON::DecUInt8& pin, const Core::JSON::Boolean& high, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::SimpleInstanceObjects::PinChangedParamsData params_;
                params_.Pin = pin;
                params_.High = high;

                PinChanged(module_, _obj, id_, params_, sendIfMethod_);
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const Core::JSON::DecUInt8& pin, const Core::JSON::Boolean& high, const string& client_)
            {
                JsonData::SimpleInstanceObjects::PinChangedParamsData params_;
                params_.Pin = pin;
                params_.High = high;

                PinChanged(module_, _obj, id_, params_, client_);
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& pin, const bool high, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::SimpleInstanceObjects::PinChangedParamsData params_;

                if (pin.IsSet() == true) {
                    params_.Pin = pin.Value();
                }
                params_.High = high;

                PinChanged(module_, _obj, pin.Value(), params_, sendIfMethod_);
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& pin, const bool high, const string& client_)
            {
                JsonData::SimpleInstanceObjects::PinChangedParamsData params_;

                if (pin.IsSet() == true) {
                    params_.Pin = pin.Value();
                }
                params_.High = high;

                PinChanged(module_, _obj, pin.Value(), params_, client_);
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const Core::OptionalType<uint8_t>& pin, const bool high, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
            {
                JsonData::SimpleInstanceObjects::PinChangedParamsData params_;

                if (pin.IsSet() == true) {
                    params_.Pin = pin.Value();
                }
                params_.High = high;

                PinChanged(module_, _obj, id_, params_, true, sendIfMethod_);
            }

            // Event: 'device#ID::pinChanged' - Signals pin state changes
            template<typename MODULE>
            static void PinChanged(const MODULE& module_, const ISimpleInstanceObjects::IDevice* const _obj, const Core::OptionalType<uint8_t>& id_, const Core::OptionalType<uint8_t>& pin, const bool high, const string& client_)
            {
                JsonData::SimpleInstanceObjects::PinChangedParamsData params_;

                if (pin.IsSet() == true) {
                    params_.Pin = pin.Value();
                }
                params_.High = high;

                PinChanged(module_, _obj, id_, params_, true, client_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JSimpleInstanceObjects

} // namespace Example

} // namespace Thunder

