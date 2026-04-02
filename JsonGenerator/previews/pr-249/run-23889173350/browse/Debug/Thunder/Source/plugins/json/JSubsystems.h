// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace Thunder {

namespace Exchange {

    namespace Controller {

        namespace JSubsystems {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ISubsystems* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSubsystems"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Property: 'subsystems' - Subsystems status (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::Subsystems::SubsystemInfo>>(_T("subsystems"),
                    [_implementation__](Core::JSON::ArrayType<JsonData::Subsystems::SubsystemInfo>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        ::Thunder::RPC::IIteratorType<ISubsystems::Subsystem, ::Thunder::RPC::ID_CONTROLLER_SUBSYSTEMS_ITERATOR>* _result_{};

                        _errorCode__ = _implementation__->Subsystems(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);

                            if (_result_ != nullptr) {
                                Exchange::Controller::ISubsystems::Subsystem _paramsItem__{};
                                while (_result_->Next(_paramsItem__) == true) { result.Add() = _paramsItem__; }
                                _result_->Release();
                            }
                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("subsystems"));
            }

            namespace Event {

                // Event: 'subsystemchange' - Notifies a subsystem change
                template<typename MODULE>
                static void SubsystemChange(const MODULE& module_, const Core::JSON::ArrayType<JsonData::Subsystems::SubsystemInfo>& subsystems, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("subsystemchange"), subsystems, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JSubsystems

    } // namespace Controller

} // namespace Exchange

} // namespace Thunder

