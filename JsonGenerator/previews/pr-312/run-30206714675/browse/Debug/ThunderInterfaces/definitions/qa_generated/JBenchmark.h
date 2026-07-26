// Generated automatically from 'IBenchmark.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Benchmark.h"
#include <qa_interfaces/IBenchmark.h>

namespace Thunder {

namespace QualityAssurance {

    namespace JBenchmark {

        namespace Version {

            constexpr uint8_t Major = 2;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IBenchmark* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JBenchmark"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'trigger' - Run the benchmark
            _module__.PluginHost::JSONRPC::template Register<JsonData::Benchmark::TriggerParamsData, void>(_T("trigger"),
                [_implementation__](const JsonData::Benchmark::TriggerParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBenchmark"), _T("trigger")));
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _iterations_{params.Iterations};

                        _errorCode__ = _implementation__->Trigger(_iterations_);

                    }

                    return (_errorCode__);
                });

            // Method: 'collectData' - Collect the results of the most recent benchmark run
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<JsonData::Benchmark::BenchmarkResultData>>(_T("collectData"),
                [_implementation__](Core::JSON::ArrayType<JsonData::Benchmark::BenchmarkResultData>& report) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>* _report_{};

                    _errorCode__ = _implementation__->CollectData(_report_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        report.Set(true);

                        if (_report_ != nullptr) {
                            QualityAssurance::IBenchmark::BenchmarkResult _resultItem__{};
                            while (_report_->Next(_resultItem__) == true) { report.Add() = _resultItem__; }
                            _report_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'latencyThreshold' - Maximum allowed deviation in avg latency compared to first-run baseline, in millipercent (1000 = 1%, 0 = no latency check)
            _module__.PluginHost::JSONRPC::template Register<JsonData::Benchmark::LatencyThresholdData, Core::JSON::DecUInt32>(_T("latencyThreshold"),
                [_implementation__](const JsonData::Benchmark::LatencyThresholdData& params, Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        uint32_t _result_{};

                        _errorCode__ = (static_cast<const IBenchmark*>(_implementation__))->LatencyThreshold(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBenchmark"), _T("latencyThreshold")));
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint32_t _value_{params.Value};

                            _errorCode__ = _implementation__->LatencyThreshold(_value_);

                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'memoryThreshold' - Maximum allowed RSS growth in bytes per method (0 = no memory check)
            _module__.PluginHost::JSONRPC::template Register<JsonData::Benchmark::MemoryThresholdData, Core::JSON::DecUInt64>(_T("memoryThreshold"),
                [_implementation__](const JsonData::Benchmark::MemoryThresholdData& params, Core::JSON::DecUInt64& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        uint64_t _result_{};

                        _errorCode__ = (static_cast<const IBenchmark*>(_implementation__))->MemoryThreshold(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JBenchmark"), _T("memoryThreshold")));
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint64_t _value_{params.Value};

                            _errorCode__ = _implementation__->MemoryThreshold(_value_);

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
            _module__.PluginHost::JSONRPC::Unregister(_T("trigger"));
            _module__.PluginHost::JSONRPC::Unregister(_T("collectData"));
            _module__.PluginHost::JSONRPC::Unregister(_T("latencyThreshold"));
            _module__.PluginHost::JSONRPC::Unregister(_T("memoryThreshold"));
        }

        namespace Event {

            // Event: 'performanceCheckCompleted'
            template<typename MODULE>
            static void PerformanceCheckCompleted(const MODULE& module_, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("performanceCheckCompleted"), sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JBenchmark

} // namespace QualityAssurance

} // namespace Thunder

