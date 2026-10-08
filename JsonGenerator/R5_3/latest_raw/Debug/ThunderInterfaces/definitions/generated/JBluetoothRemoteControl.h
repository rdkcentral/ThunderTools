// Generated automatically from 'IBluetoothRemoteControl.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BluetoothRemoteControl.h"
#include <interfaces/IBluetoothRemoteControl.h>

namespace Thunder {

namespace Exchange {

    namespace JBluetoothRemoteControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        struct IHandler {
            virtual ~IHandler() = default;
            virtual void OnBatteryLevelChangeEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
        };

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IBluetoothRemoteControl* _implementation__, IHandler* _handler_)
        {
            ASSERT(_implementation__ != nullptr);
            ASSERT(_handler_ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JBluetoothRemoteControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'assign' - Assigns a Bluetooth device as a RCU
            _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothRemoteControl::AssignParamsData, void>(_T("assign"),
                [_implementation__](const JsonData::BluetoothRemoteControl::AssignParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _address_{params.Address};

                        _errorCode__ = _implementation__->Assign(_address_);

                    }

                    return (_errorCode__);
                });

            // Method: 'revoke' - Revokes a Bluetooth device from RCU operation
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("revoke"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->Revoke();

                    return (_errorCode__);
                });

            // Property: 'device' - Bluetooth address (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("device"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->Device(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("address"), _T("device"));

            // Property: 'metadata' - Device metadata (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothRemoteControl::UnitmetadataData>(_T("metadata"),
                [_implementation__](JsonData::BluetoothRemoteControl::UnitmetadataData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IBluetoothRemoteControl::unitmetadata _result_{};

                    _errorCode__ = _implementation__->Metadata(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("info"), _T("metadata"));

            // Property: 'batterylevel' - Battery level (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt8>(_T("batterylevel"),
                [_implementation__](Core::JSON::DecUInt8& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint8_t _result_{};

                    _errorCode__ = _implementation__->BatteryLevel(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'voicecontrol' - Toggle voice control
            _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothRemoteControl::VoiceControlData, Core::JSON::Boolean>(_T("voicecontrol"),
                [_implementation__](const JsonData::BluetoothRemoteControl::VoiceControlData& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        bool _result_{};

                        _errorCode__ = (static_cast<const IBluetoothRemoteControl*>(_implementation__))->VoiceControl(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const bool _value_{params.Value};

                            _errorCode__ = _implementation__->VoiceControl(_value_);

                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Register event status listeners...

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("batterylevelchange"),
                [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    _handler_->OnBatteryLevelChangeEventRegistration(client_, status_);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("assign"));
            _module__.PluginHost::JSONRPC::Unregister(_T("revoke"));
            _module__.PluginHost::JSONRPC::Unregister(_T("device"));
            _module__.PluginHost::JSONRPC::Unregister(_T("address"));
            _module__.PluginHost::JSONRPC::Unregister(_T("metadata"));
            _module__.PluginHost::JSONRPC::Unregister(_T("info"));
            _module__.PluginHost::JSONRPC::Unregister(_T("batterylevel"));
            _module__.PluginHost::JSONRPC::Unregister(_T("voicecontrol"));

            // Unregister event status listeners...
            _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("batterylevelchange"));
        }

        namespace Event {

            // Event: 'batterylevelchange' - Signals battery level change
            template<typename MODULE>
            static void BatteryLevelChange(const MODULE& module_, const JsonData::BluetoothRemoteControl::BatteryLevelChangeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("batterylevelchange"), params, sendIfMethod_);
            }

            // Event: 'batterylevelchange' - Signals battery level change
            template<typename MODULE>
            static void BatteryLevelChange(const MODULE& module_, const JsonData::BluetoothRemoteControl::BatteryLevelChangeParamsData& params, const string& client_)
            {
                module_.Notify(_T("batterylevelchange"), params, [&client_](const string& designator_) -> bool {
                    return ((client_ == designator_));
                });
            }

            // Event: 'batterylevelchange' - Signals battery level change
            template<typename MODULE>
            static void BatteryLevelChange(const MODULE& module_, const Core::JSON::DecUInt8& level, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothRemoteControl::BatteryLevelChangeParamsData params_;
                params_.Level = level;

                BatteryLevelChange(module_, params_, sendIfMethod_);
            }

            // Event: 'batterylevelchange' - Signals battery level change
            template<typename MODULE>
            static void BatteryLevelChange(const MODULE& module_, const Core::JSON::DecUInt8& level, const string& client_)
            {
                JsonData::BluetoothRemoteControl::BatteryLevelChangeParamsData params_;
                params_.Level = level;

                BatteryLevelChange(module_, params_, client_);
            }

            // Event: 'batterylevelchange' - Signals battery level change
            template<typename MODULE>
            static void BatteryLevelChange(const MODULE& module_, const uint8_t level, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::BluetoothRemoteControl::BatteryLevelChangeParamsData params_;
                params_.Level = level;

                BatteryLevelChange(module_, params_, sendIfMethod_);
            }

            // Event: 'batterylevelchange' - Signals battery level change
            template<typename MODULE>
            static void BatteryLevelChange(const MODULE& module_, const uint8_t level, const string& client_)
            {
                JsonData::BluetoothRemoteControl::BatteryLevelChangeParamsData params_;
                params_.Level = level;

                BatteryLevelChange(module_, params_, client_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JBluetoothRemoteControl

} // namespace Exchange

} // namespace Thunder

