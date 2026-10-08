// Generated automatically from 'IPower.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Power.h"
#include <interfaces/IPower.h>

namespace Thunder {

namespace Exchange {

    namespace JPower {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IPower* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JPower"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'setstate' - Set the power state
            _module__.PluginHost::JSONRPC::template Register<JsonData::Power::SetStateParamsData, void>(_T("setstate"),
                [_implementation__](const JsonData::Power::SetStateParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const Exchange::IPower::PCState _state_{params.State};
                        const uint32_t _waitTime_{params.WaitTime};

                        _errorCode__ = _implementation__->SetState(_state_, _waitTime_);

                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("set"), _T("setstate"));

            // Property: 'getstate' - Get the current power state (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IPower::PCState>>(_T("getstate"),
                [_implementation__](Core::JSON::EnumType<Exchange::IPower::PCState>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IPower::PCState _result_{};

                    _errorCode__ = _implementation__->GetState(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            _module__.PluginHost::JSONRPC::Register(_T("state"), _T("getstate"));

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("setstate"));
            _module__.PluginHost::JSONRPC::Unregister(_T("set"));
            _module__.PluginHost::JSONRPC::Unregister(_T("getstate"));
            _module__.PluginHost::JSONRPC::Unregister(_T("state"));
        }

        namespace Event {

            // Event: 'statechange' - Signals a change in the power state
            template<typename MODULE>
            static void StateChange(const MODULE& module_, const JsonData::Power::StateChangeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("statechange"), params, sendIfMethod_);
            }

            // Event: 'statechange' - Signals a change in the power state
            template<typename MODULE>
            static void StateChange(const MODULE& module_, const Core::JSON::EnumType<Exchange::IPower::PCState>& origin, const Core::JSON::EnumType<Exchange::IPower::PCState>& destination, const Core::JSON::EnumType<Exchange::IPower::PCPhase>& phase, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Power::StateChangeParamsData params_;
                params_.Origin = origin;
                params_.Destination = destination;
                params_.Phase = phase;

                StateChange(module_, params_, sendIfMethod_);
            }

            // Event: 'statechange' - Signals a change in the power state
            template<typename MODULE>
            static void StateChange(const MODULE& module_, const IPower::PCState origin, const IPower::PCState destination, const IPower::PCPhase phase, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::Power::StateChangeParamsData params_;
                params_.Origin = origin;
                params_.Destination = destination;
                params_.Phase = phase;

                StateChange(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JPower

} // namespace Exchange

} // namespace Thunder

