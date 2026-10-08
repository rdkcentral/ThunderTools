// Generated automatically from 'IStateController.h'. DO NOT EDIT.

#pragma once

namespace Thunder {

namespace PluginHost {

    namespace JStateController {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IStateController* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JStateController"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'statecontrol::request' - Request a change to the specified state
            _module__.PluginHost::JSONRPC::template Register<JsonData::StateController::RequestParamsData, void>(_T("statecontrol::request"),
                [_implementation__](const JsonData::StateController::RequestParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const PluginHost::IStateController::command _state_{params.State};

                        _errorCode__ = _implementation__->Request(_state_);

                    }

                    return (_errorCode__);
                });

            // Property: 'statecontrol::state' - Running state of the service (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<PluginHost::IStateController::state>>(_T("statecontrol::state"),
                [_implementation__](Core::JSON::EnumType<PluginHost::IStateController::state>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    PluginHost::IStateController::state _result_{};

                    _errorCode__ = _implementation__->State(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("statecontrol::request"));
            _module__.PluginHost::JSONRPC::Unregister(_T("statecontrol::state"));
        }

        namespace Event {

            // Event: 'statecontrol::statechanged' - Signals a state change of the service
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const JsonData::StateController::StateChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("statecontrol::statechanged"), params, sendIfMethod_);
            }

            // Event: 'statecontrol::statechanged' - Signals a state change of the service
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const Core::JSON::EnumType<PluginHost::IStateController::state>& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::StateController::StateChangedParamsData params_;
                params_.State = state;

                StateChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'statecontrol::statechanged' - Signals a state change of the service
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const IStateController::state state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::StateController::StateChangedParamsData params_;
                params_.State = state;

                StateChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JStateController

} // namespace PluginHost

} // namespace Thunder

