// Generated automatically from 'IMemoryMonitor.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_MemoryMonitor.h"
#include <interfaces/IMemoryMonitor.h>

namespace Thunder {

namespace Exchange {

    namespace JMemoryMonitor {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IMemoryMonitor* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JMemoryMonitor"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'resetstatistics' - Resets memory statistics for a given service
            _module__.PluginHost::JSONRPC::template Register<JsonData::MemoryMonitor::ResetStatisticsParamsData, void>(_T("resetstatistics"),
                [_implementation__](const JsonData::MemoryMonitor::ResetStatisticsParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _callsign_{params.Callsign};

                        _errorCode__ = _implementation__->ResetStatistics(_callsign_);

                    }

                    return (_errorCode__);
                });

            // Indexed Property: 'restartinglimits' - Limits of restarting of a service
            _module__.PluginHost::JSONRPC::template Register<JsonData::MemoryMonitor::RestartingLimitsData, JsonData::MemoryMonitor::RestartInfo, std::function<uint32_t(const string&, const JsonData::MemoryMonitor::RestartingLimitsData&, JsonData::MemoryMonitor::RestartInfo&)>>(_T("restartinglimits"),
                [_implementation__](const string& callsign, const JsonData::MemoryMonitor::RestartingLimitsData& params, JsonData::MemoryMonitor::RestartInfo& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (callsign.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {

                        if (params.IsSet() == false) {
                            Exchange::IMemoryMonitor::Restart _result_{};

                            _errorCode__ = (static_cast<const IMemoryMonitor*>(_implementation__))->RestartingLimits(callsign, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result.Set(true);
                                result = _result_;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                const Exchange::IMemoryMonitor::Restart _value_(params.Value);

                                _errorCode__ = _implementation__->RestartingLimits(callsign, _value_);

                            }

                            result.Null(true);
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'observables' - List of services watched by the Monitor (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::String>>(_T("observables"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::String>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _result_{};

                    _errorCode__ = _implementation__->Observables(_result_);

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

            // Indexed Property: 'measurementdata' - Memory statistics for a given service (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, JsonData::MemoryMonitor::StatisticsData, std::function<uint32_t(const string&, JsonData::MemoryMonitor::StatisticsData&)>>(_T("measurementdata"),
                [_implementation__](const string& callsign, JsonData::MemoryMonitor::StatisticsData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (callsign.empty() == true) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }

                    if (_errorCode__ == Core::ERROR_NONE) {
                        Exchange::IMemoryMonitor::Statistics _result_{};

                        _errorCode__ = _implementation__->MeasurementData(callsign, _result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("resetstatistics"));
            _module__.PluginHost::JSONRPC::Unregister(_T("restartinglimits"));
            _module__.PluginHost::JSONRPC::Unregister(_T("observables"));
            _module__.PluginHost::JSONRPC::Unregister(_T("measurementdata"));
        }

        namespace Event {

            // Event: 'statuschanged' - Signals an action taken by the Monitor
            template<typename MODULE>
            static void StatusChanged(const MODULE& module_, const JsonData::MemoryMonitor::StatusChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("statuschanged"), params, sendIfMethod_);
            }

            // Event: 'statuschanged' - Signals an action taken by the Monitor
            template<typename MODULE>
            static void StatusChanged(const MODULE& module_, const Core::JSON::String& callsign, const Core::JSON::EnumType<Exchange::IMemoryMonitor::INotification::action>& action, const Core::JSON::EnumType<Exchange::IMemoryMonitor::INotification::reason>& reason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::MemoryMonitor::StatusChangedParamsData params_;
                params_.Callsign = callsign;
                params_.Action = action;
                params_.Reason = reason;

                StatusChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'statuschanged' - Signals an action taken by the Monitor
            template<typename MODULE>
            static void StatusChanged(const MODULE& module_, const string& callsign, const IMemoryMonitor::INotification::action action, const Core::OptionalType<IMemoryMonitor::INotification::reason>& reason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::MemoryMonitor::StatusChangedParamsData params_;
                params_.Callsign = callsign;
                params_.Action = action;

                if (reason.IsSet() == true) {
                    params_.Reason = reason.Value();
                }

                StatusChanged(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JMemoryMonitor

} // namespace Exchange

} // namespace Thunder

