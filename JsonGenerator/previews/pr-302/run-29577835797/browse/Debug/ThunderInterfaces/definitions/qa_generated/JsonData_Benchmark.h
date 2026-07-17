// C++ types for Benchmark API.
// Generated automatically from 'IBenchmark.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/IBenchmark.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Benchmark {

        // Method params/result classes
        //

        class BenchmarkResultData : public Core::JSON::Container {
        public:
            class MemoryStatsData : public Core::JSON::Container {
            public:
                MemoryStatsData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                MemoryStatsData(const MemoryStatsData& _other)
                    : Core::JSON::Container()
                    , ResidentBefore(_other.ResidentBefore)
                    , ResidentAfter(_other.ResidentAfter)
                    , AllocatedBefore(_other.AllocatedBefore)
                    , AllocatedAfter(_other.AllocatedAfter)
                {
                    _Init();
                }

                MemoryStatsData(MemoryStatsData&& _other) noexcept
                    : Core::JSON::Container()
                    , ResidentBefore(std::move(_other.ResidentBefore))
                    , ResidentAfter(std::move(_other.ResidentAfter))
                    , AllocatedBefore(std::move(_other.AllocatedBefore))
                    , AllocatedAfter(std::move(_other.AllocatedAfter))
                {
                    _Init();
                }

                MemoryStatsData(const QualityAssurance::IBenchmark::MemoryStats& _other)
                    : Core::JSON::Container()
                {
                    ResidentBefore = _other.residentBefore;
                    ResidentAfter = _other.residentAfter;
                    AllocatedBefore = _other.allocatedBefore;
                    AllocatedAfter = _other.allocatedAfter;
                    _Init();
                }

                MemoryStatsData& operator=(const MemoryStatsData& _rhs)
                {
                    ResidentBefore = _rhs.ResidentBefore;
                    ResidentAfter = _rhs.ResidentAfter;
                    AllocatedBefore = _rhs.AllocatedBefore;
                    AllocatedAfter = _rhs.AllocatedAfter;
                    return (*this);
                }

                MemoryStatsData& operator=(MemoryStatsData&& _rhs) noexcept
                {
                    ResidentBefore = std::move(_rhs.ResidentBefore);
                    ResidentAfter = std::move(_rhs.ResidentAfter);
                    AllocatedBefore = std::move(_rhs.AllocatedBefore);
                    AllocatedAfter = std::move(_rhs.AllocatedAfter);
                    return (*this);
                }

                MemoryStatsData& operator=(const QualityAssurance::IBenchmark::MemoryStats& _rhs)
                {
                    ResidentBefore = _rhs.residentBefore;
                    ResidentAfter = _rhs.residentAfter;
                    AllocatedBefore = _rhs.allocatedBefore;
                    AllocatedAfter = _rhs.allocatedAfter;
                    return (*this);
                }

                operator QualityAssurance::IBenchmark::MemoryStats() const
                {
                    QualityAssurance::IBenchmark::MemoryStats _value{};
                    _value.residentBefore = ResidentBefore;
                    _value.residentAfter = ResidentAfter;
                    _value.allocatedBefore = AllocatedBefore;
                    _value.allocatedAfter = AllocatedAfter;
                    return (_value);
                }

                ~MemoryStatsData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((ResidentBefore.IsSet() == true) && (ResidentAfter.IsSet() == true) && (AllocatedBefore.IsSet() == true) && (AllocatedAfter.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("residentBefore"), &ResidentBefore);
                    Add(_T("residentAfter"), &ResidentAfter);
                    Add(_T("allocatedBefore"), &AllocatedBefore);
                    Add(_T("allocatedAfter"), &AllocatedAfter);
                }

            public:
                Core::JSON::DecUInt64 ResidentBefore;
                Core::JSON::DecUInt64 ResidentAfter;
                Core::JSON::DecUInt64 AllocatedBefore;
                Core::JSON::DecUInt64 AllocatedAfter;
            }; // class MemoryStatsData

            class RoundTripStatsData : public Core::JSON::Container {
            public:
                RoundTripStatsData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                RoundTripStatsData(const RoundTripStatsData& _other)
                    : Core::JSON::Container()
                    , MinNs(_other.MinNs)
                    , AvgNs(_other.AvgNs)
                    , MaxNs(_other.MaxNs)
                    , StddevNs(_other.StddevNs)
                {
                    _Init();
                }

                RoundTripStatsData(RoundTripStatsData&& _other) noexcept
                    : Core::JSON::Container()
                    , MinNs(std::move(_other.MinNs))
                    , AvgNs(std::move(_other.AvgNs))
                    , MaxNs(std::move(_other.MaxNs))
                    , StddevNs(std::move(_other.StddevNs))
                {
                    _Init();
                }

                RoundTripStatsData(const QualityAssurance::IBenchmark::RoundTripStats& _other)
                    : Core::JSON::Container()
                {
                    MinNs = _other.minNs;
                    AvgNs = _other.avgNs;
                    MaxNs = _other.maxNs;
                    StddevNs = _other.stddevNs;
                    _Init();
                }

                RoundTripStatsData& operator=(const RoundTripStatsData& _rhs)
                {
                    MinNs = _rhs.MinNs;
                    AvgNs = _rhs.AvgNs;
                    MaxNs = _rhs.MaxNs;
                    StddevNs = _rhs.StddevNs;
                    return (*this);
                }

                RoundTripStatsData& operator=(RoundTripStatsData&& _rhs) noexcept
                {
                    MinNs = std::move(_rhs.MinNs);
                    AvgNs = std::move(_rhs.AvgNs);
                    MaxNs = std::move(_rhs.MaxNs);
                    StddevNs = std::move(_rhs.StddevNs);
                    return (*this);
                }

                RoundTripStatsData& operator=(const QualityAssurance::IBenchmark::RoundTripStats& _rhs)
                {
                    MinNs = _rhs.minNs;
                    AvgNs = _rhs.avgNs;
                    MaxNs = _rhs.maxNs;
                    StddevNs = _rhs.stddevNs;
                    return (*this);
                }

                operator QualityAssurance::IBenchmark::RoundTripStats() const
                {
                    QualityAssurance::IBenchmark::RoundTripStats _value{};
                    _value.minNs = MinNs;
                    _value.avgNs = AvgNs;
                    _value.maxNs = MaxNs;
                    _value.stddevNs = StddevNs;
                    return (_value);
                }

                ~RoundTripStatsData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((MinNs.IsSet() == true) && (AvgNs.IsSet() == true) && (MaxNs.IsSet() == true) && (StddevNs.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("minNs"), &MinNs);
                    Add(_T("avgNs"), &AvgNs);
                    Add(_T("maxNs"), &MaxNs);
                    Add(_T("stddevNs"), &StddevNs);
                }

            public:
                Core::JSON::DecUInt64 MinNs;
                Core::JSON::DecUInt64 AvgNs;
                Core::JSON::DecUInt64 MaxNs;
                Core::JSON::DecUInt64 StddevNs;
            }; // class RoundTripStatsData

            BenchmarkResultData()
                : Core::JSON::Container()
            {
                _Init();
            }

            BenchmarkResultData(const BenchmarkResultData& _other)
                : Core::JSON::Container()
                , ApiName(_other.ApiName)
                , Iterations(_other.Iterations)
                , RoundTrip(_other.RoundTrip)
                , Memory(_other.Memory)
                , Passed(_other.Passed)
                , FailureReason(_other.FailureReason)
            {
                _Init();
            }

            BenchmarkResultData(BenchmarkResultData&& _other) noexcept
                : Core::JSON::Container()
                , ApiName(std::move(_other.ApiName))
                , Iterations(std::move(_other.Iterations))
                , RoundTrip(std::move(_other.RoundTrip))
                , Memory(std::move(_other.Memory))
                , Passed(std::move(_other.Passed))
                , FailureReason(std::move(_other.FailureReason))
            {
                _Init();
            }

            BenchmarkResultData(const QualityAssurance::IBenchmark::BenchmarkResult& _other)
                : Core::JSON::Container()
            {
                ApiName = _other.apiName;
                Iterations = _other.iterations;
                RoundTrip.Set(true);
                RoundTrip = _other.roundTrip;
                Memory.Set(true);
                Memory = _other.memory;
                Passed = _other.passed;
                if (_other.failureReason.IsSet() == true) {
                    FailureReason = _other.failureReason.Value();
                }
                _Init();
            }

            BenchmarkResultData& operator=(const BenchmarkResultData& _rhs)
            {
                ApiName = _rhs.ApiName;
                Iterations = _rhs.Iterations;
                RoundTrip = _rhs.RoundTrip;
                Memory = _rhs.Memory;
                Passed = _rhs.Passed;
                if (_rhs.FailureReason.IsSet() == true) {
                    FailureReason = _rhs.FailureReason;
                }
                return (*this);
            }

            BenchmarkResultData& operator=(BenchmarkResultData&& _rhs) noexcept
            {
                ApiName = std::move(_rhs.ApiName);
                Iterations = std::move(_rhs.Iterations);
                RoundTrip = std::move(_rhs.RoundTrip);
                Memory = std::move(_rhs.Memory);
                Passed = std::move(_rhs.Passed);
                FailureReason = std::move(_rhs.FailureReason);
                return (*this);
            }

            BenchmarkResultData& operator=(const QualityAssurance::IBenchmark::BenchmarkResult& _rhs)
            {
                ApiName = _rhs.apiName;
                Iterations = _rhs.iterations;
                RoundTrip.Set(true);
                RoundTrip = _rhs.roundTrip;
                Memory.Set(true);
                Memory = _rhs.memory;
                Passed = _rhs.passed;
                if (_rhs.failureReason.IsSet() == true) {
                    FailureReason = _rhs.failureReason.Value();
                }
                return (*this);
            }

            operator QualityAssurance::IBenchmark::BenchmarkResult() const
            {
                QualityAssurance::IBenchmark::BenchmarkResult _value{};
                _value.apiName = ApiName;
                _value.iterations = Iterations;
                _value.roundTrip = RoundTrip;
                _value.memory = Memory;
                _value.passed = Passed;
                if (FailureReason.IsSet() == true) {
                    _value.failureReason = FailureReason;
                }
                return (_value);
            }

            ~BenchmarkResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((ApiName.IsSet() == true) && (Iterations.IsSet() == true) && ((RoundTrip.IsSet() == true) && (RoundTrip.IsDataValid() == true)) && ((Memory.IsSet() == true) && (Memory.IsDataValid() == true)) && (Passed.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("apiName"), &ApiName);
                Add(_T("iterations"), &Iterations);
                Add(_T("roundTrip"), &RoundTrip);
                Add(_T("memory"), &Memory);
                Add(_T("passed"), &Passed);
                Add(_T("failureReason"), &FailureReason);
            }

        public:
            Core::JSON::String ApiName;
            Core::JSON::DecUInt32 Iterations;
            BenchmarkResultData::RoundTripStatsData RoundTrip;
            BenchmarkResultData::MemoryStatsData Memory;
            Core::JSON::Boolean Passed;
            Core::JSON::EnumType<QualityAssurance::IBenchmark::FailureReason> FailureReason;
        }; // class BenchmarkResultData

        class LatencyThresholdData : public Core::JSON::Container {
        public:
            LatencyThresholdData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            LatencyThresholdData(const LatencyThresholdData&) = delete;
            LatencyThresholdData(LatencyThresholdData&&) noexcept  = delete;

            LatencyThresholdData& operator=(const LatencyThresholdData&) = delete;
            LatencyThresholdData& operator=(LatencyThresholdData&&) noexcept  = delete;

            ~LatencyThresholdData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Value; // Maximum allowed deviation in avg latency compared to first-run baseline, in millipercent (1000 = 1%, 0 = no latency check)
        }; // class LatencyThresholdData

        class MemoryThresholdData : public Core::JSON::Container {
        public:
            MemoryThresholdData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            MemoryThresholdData(const MemoryThresholdData&) = delete;
            MemoryThresholdData(MemoryThresholdData&&) noexcept  = delete;

            MemoryThresholdData& operator=(const MemoryThresholdData&) = delete;
            MemoryThresholdData& operator=(MemoryThresholdData&&) noexcept  = delete;

            ~MemoryThresholdData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt64 Value; // Maximum allowed RSS growth in bytes per method (0 = no memory check)
        }; // class MemoryThresholdData

        class TriggerParamsData : public Core::JSON::Container {
        public:
            TriggerParamsData()
                : Core::JSON::Container()
            {
                Add(_T("iterations"), &Iterations);
            }

            TriggerParamsData(const TriggerParamsData&) = delete;
            TriggerParamsData(TriggerParamsData&&) noexcept  = delete;

            TriggerParamsData& operator=(const TriggerParamsData&) = delete;
            TriggerParamsData& operator=(TriggerParamsData&&) noexcept  = delete;

            ~TriggerParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Iterations.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Iterations; // Denotes the number of iterations the benchmark should run
        }; // class TriggerParamsData

    } // namespace Benchmark

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(QualityAssurance::IBenchmark::FailureReason)

}

