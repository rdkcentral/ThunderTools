// Generated automatically from 'ITimeSync.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_TimeSync.h"
#include <interfaces/ITimeSync.h>

namespace Thunder {

namespace Exchange {

    namespace JTimeSync {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ITimeSync* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JTimeSync"), Version::Major, Version::Minor, Version::Patch);

            // Register alternative notification names...
            _module__.PluginHost::JSONRPC::RegisterEventAlias(_T("timechange"), _T("timechanged"));

            // Register methods and properties...

            // Method: 'synchronize' - Synchronizes time (DEPRECATED)
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("synchronize"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->Synchronize();

                    return (_errorCode__);
                });

            // Property: 'synctime' - Time of the most recent synchronization (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, JsonData::TimeSync::TimeInfoData>(_T("synctime"),
                [_implementation__](JsonData::TimeSync::TimeInfoData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::ITimeSync::TimeInfo _result_{};

                    _errorCode__ = _implementation__->SyncTime(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'time' - Current system time (DEPRECATED)
            _module__.PluginHost::JSONRPC::template Register<JsonData::TimeSync::TimeData, Core::JSON::String>(_T("time"),
                [_implementation__](const JsonData::TimeSync::TimeData& params, Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Core::Time _result_{};

                        _errorCode__ = (static_cast<const ITimeSync*>(_implementation__))->Time(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_.ToISO8601();
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            Core::Time _value_{};
                            _value_.FromISO8601(params.Value);

                            _errorCode__ = _implementation__->Time(static_cast<Core::Time const&>(_value_));

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
            _module__.PluginHost::JSONRPC::Unregister(_T("synchronize"));
            _module__.PluginHost::JSONRPC::Unregister(_T("synctime"));
            _module__.PluginHost::JSONRPC::Unregister(_T("time"));

            // Unegister alternative notification names...
            _module__.PluginHost::JSONRPC::UnregisterEventAlias(_T("timechange"), _T("timechanged"));
        }

        namespace Event {

            // Event: 'timechanged' - Signals a time change
            template<typename MODULE>
            static void TimeChanged(const MODULE& module_, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("timechanged"), sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JTimeSync

} // namespace Exchange

} // namespace Thunder

