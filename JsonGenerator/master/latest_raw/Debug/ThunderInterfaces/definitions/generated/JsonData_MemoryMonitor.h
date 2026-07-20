// C++ types for MemoryMonitor API.
// Generated automatically from 'IMemoryMonitor.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IMemoryMonitor.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace MemoryMonitor {

        // Common classes
        //

        class RestartInfo : public Core::JSON::Container {
        public:
            RestartInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            RestartInfo(const RestartInfo& _other)
                : Core::JSON::Container()
                , Limit(_other.Limit)
                , Window(_other.Window)
            {
                _Init();
            }

            RestartInfo(RestartInfo&& _other) noexcept
                : Core::JSON::Container()
                , Limit(std::move(_other.Limit))
                , Window(std::move(_other.Window))
            {
                _Init();
            }

            RestartInfo(const Exchange::IMemoryMonitor::Restart& _other)
                : Core::JSON::Container()
            {
                Limit = _other.limit;
                Window = _other.window;
                _Init();
            }

            RestartInfo& operator=(const RestartInfo& _rhs)
            {
                Limit = _rhs.Limit;
                Window = _rhs.Window;
                return (*this);
            }

            RestartInfo& operator=(RestartInfo&& _rhs) noexcept
            {
                Limit = std::move(_rhs.Limit);
                Window = std::move(_rhs.Window);
                return (*this);
            }

            RestartInfo& operator=(const Exchange::IMemoryMonitor::Restart& _rhs)
            {
                Limit = _rhs.limit;
                Window = _rhs.window;
                return (*this);
            }

            operator Exchange::IMemoryMonitor::Restart() const
            {
                Exchange::IMemoryMonitor::Restart _value{};
                _value.limit = Limit;
                _value.window = Window;
                return (_value);
            }

            ~RestartInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Limit.IsSet() == true) && (Window.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("limit"), &Limit);
                Add(_T("window"), &Window);
            }

        public:
            Core::JSON::DecUInt8 Limit; // Maximum number or restarts to be attempted
            Core::JSON::DecUInt16 Window; // Time period (in seconds) within which failures must happen for the limit to be considered crossed
        }; // class RestartInfo

        // Method params/result classes
        //

        class StatisticsData : public Core::JSON::Container {
        public:
            class MeasurementData : public Core::JSON::Container {
            public:
                MeasurementData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                MeasurementData(const MeasurementData& _other)
                    : Core::JSON::Container()
                    , Min(_other.Min)
                    , Max(_other.Max)
                    , Average(_other.Average)
                    , Last(_other.Last)
                {
                    _Init();
                }

                MeasurementData(MeasurementData&& _other) noexcept
                    : Core::JSON::Container()
                    , Min(std::move(_other.Min))
                    , Max(std::move(_other.Max))
                    , Average(std::move(_other.Average))
                    , Last(std::move(_other.Last))
                {
                    _Init();
                }

                MeasurementData(const Exchange::IMemoryMonitor::Measurement& _other)
                    : Core::JSON::Container()
                {
                    Min = _other.min;
                    Max = _other.max;
                    Average = _other.average;
                    Last = _other.last;
                    _Init();
                }

                MeasurementData& operator=(const MeasurementData& _rhs)
                {
                    Min = _rhs.Min;
                    Max = _rhs.Max;
                    Average = _rhs.Average;
                    Last = _rhs.Last;
                    return (*this);
                }

                MeasurementData& operator=(MeasurementData&& _rhs) noexcept
                {
                    Min = std::move(_rhs.Min);
                    Max = std::move(_rhs.Max);
                    Average = std::move(_rhs.Average);
                    Last = std::move(_rhs.Last);
                    return (*this);
                }

                MeasurementData& operator=(const Exchange::IMemoryMonitor::Measurement& _rhs)
                {
                    Min = _rhs.min;
                    Max = _rhs.max;
                    Average = _rhs.average;
                    Last = _rhs.last;
                    return (*this);
                }

                operator Exchange::IMemoryMonitor::Measurement() const
                {
                    Exchange::IMemoryMonitor::Measurement _value{};
                    _value.min = Min;
                    _value.max = Max;
                    _value.average = Average;
                    _value.last = Last;
                    return (_value);
                }

                ~MeasurementData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Min.IsSet() == true) && (Max.IsSet() == true) && (Average.IsSet() == true) && (Last.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("min"), &Min);
                    Add(_T("max"), &Max);
                    Add(_T("average"), &Average);
                    Add(_T("last"), &Last);
                }

            public:
                Core::JSON::DecUInt64 Min; // Minimal value measured
                Core::JSON::DecUInt64 Max; // Maximal value measured
                Core::JSON::DecUInt64 Average; // Average of all measurements
                Core::JSON::DecUInt64 Last; // Last measured value
            }; // class MeasurementData

            StatisticsData()
                : Core::JSON::Container()
            {
                _Init();
            }

            StatisticsData(const StatisticsData& _other)
                : Core::JSON::Container()
                , Resident(_other.Resident)
                , Allocated(_other.Allocated)
                , Shared(_other.Shared)
                , Process(_other.Process)
                , Operational(_other.Operational)
                , Count(_other.Count)
            {
                _Init();
            }

            StatisticsData(StatisticsData&& _other) noexcept
                : Core::JSON::Container()
                , Resident(std::move(_other.Resident))
                , Allocated(std::move(_other.Allocated))
                , Shared(std::move(_other.Shared))
                , Process(std::move(_other.Process))
                , Operational(std::move(_other.Operational))
                , Count(std::move(_other.Count))
            {
                _Init();
            }

            StatisticsData(const Exchange::IMemoryMonitor::Statistics& _other)
                : Core::JSON::Container()
            {
                Resident.Set(true);
                Resident = _other.resident;
                Allocated.Set(true);
                Allocated = _other.allocated;
                Shared.Set(true);
                Shared = _other.shared;
                Process.Set(true);
                Process = _other.process;
                Operational = _other.operational;
                Count = _other.count;
                _Init();
            }

            StatisticsData& operator=(const StatisticsData& _rhs)
            {
                Resident = _rhs.Resident;
                Allocated = _rhs.Allocated;
                Shared = _rhs.Shared;
                Process = _rhs.Process;
                Operational = _rhs.Operational;
                Count = _rhs.Count;
                return (*this);
            }

            StatisticsData& operator=(StatisticsData&& _rhs) noexcept
            {
                Resident = std::move(_rhs.Resident);
                Allocated = std::move(_rhs.Allocated);
                Shared = std::move(_rhs.Shared);
                Process = std::move(_rhs.Process);
                Operational = std::move(_rhs.Operational);
                Count = std::move(_rhs.Count);
                return (*this);
            }

            StatisticsData& operator=(const Exchange::IMemoryMonitor::Statistics& _rhs)
            {
                Resident.Set(true);
                Resident = _rhs.resident;
                Allocated.Set(true);
                Allocated = _rhs.allocated;
                Shared.Set(true);
                Shared = _rhs.shared;
                Process.Set(true);
                Process = _rhs.process;
                Operational = _rhs.operational;
                Count = _rhs.count;
                return (*this);
            }

            operator Exchange::IMemoryMonitor::Statistics() const
            {
                Exchange::IMemoryMonitor::Statistics _value{};
                _value.resident = Resident;
                _value.allocated = Allocated;
                _value.shared = Shared;
                _value.process = Process;
                _value.operational = Operational;
                _value.count = Count;
                return (_value);
            }

            ~StatisticsData() = default;

        public:
            bool IsDataValid() const
            {
                return (((Resident.IsSet() == true) && (Resident.IsDataValid() == true)) && ((Allocated.IsSet() == true) && (Allocated.IsDataValid() == true)) && ((Shared.IsSet() == true) && (Shared.IsDataValid() == true)) && ((Process.IsSet() == true) && (Process.IsDataValid() == true)) && (Operational.IsSet() == true) && (Count.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("resident"), &Resident);
                Add(_T("allocated"), &Allocated);
                Add(_T("shared"), &Shared);
                Add(_T("process"), &Process);
                Add(_T("operational"), &Operational);
                Add(_T("count"), &Count);
            }

        public:
            StatisticsData::MeasurementData Resident; // Resident memory measurement
            MeasurementData Allocated; // Allocated memory measurement
            MeasurementData Shared; // Shared memory measurement
            MeasurementData Process; // Processes measurement
            Core::JSON::Boolean Operational; // Whether the service is up and running
            Core::JSON::DecUInt32 Count; // Number of measurements
        }; // class StatisticsData

        class ResetStatisticsParamsData : public Core::JSON::Container {
        public:
            ResetStatisticsParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
            }

            ResetStatisticsParamsData(const ResetStatisticsParamsData&) = delete;
            ResetStatisticsParamsData(ResetStatisticsParamsData&&) noexcept  = delete;

            ResetStatisticsParamsData& operator=(const ResetStatisticsParamsData&) = delete;
            ResetStatisticsParamsData& operator=(ResetStatisticsParamsData&&) noexcept  = delete;

            ~ResetStatisticsParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Callsign.IsSet() == true);
            }

        public:
            Core::JSON::String Callsign; // Callsign of the service
        }; // class ResetStatisticsParamsData

        class RestartingLimitsData : public Core::JSON::Container {
        public:
            RestartingLimitsData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            RestartingLimitsData(const RestartingLimitsData&) = delete;
            RestartingLimitsData(RestartingLimitsData&&) noexcept  = delete;

            RestartingLimitsData& operator=(const RestartingLimitsData&) = delete;
            RestartingLimitsData& operator=(RestartingLimitsData&&) noexcept  = delete;

            ~RestartingLimitsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Value.IsSet() == true) && (Value.IsDataValid() == true));
            }

        public:
            RestartInfo Value; // Limits of restarts applying to a given service
        }; // class RestartingLimitsData

        class StatusChangedParamsData : public Core::JSON::Container {
        public:
            StatusChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("action"), &Action);
                Add(_T("reason"), &Reason);
            }

            StatusChangedParamsData(const StatusChangedParamsData&) = delete;
            StatusChangedParamsData(StatusChangedParamsData&&) noexcept  = delete;

            StatusChangedParamsData& operator=(const StatusChangedParamsData&) = delete;
            StatusChangedParamsData& operator=(StatusChangedParamsData&&) noexcept  = delete;

            ~StatusChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Callsign.IsSet() == true) && (Action.IsSet() == true));
            }

        public:
            Core::JSON::String Callsign; // Callsign of the service the Monitor acted upon
            Core::JSON::EnumType<Exchange::IMemoryMonitor::INotification::action> Action; // Ation executed by the Monitor on a service
            Core::JSON::EnumType<Exchange::IMemoryMonitor::INotification::reason> Reason; // Mssage describing the reason the action was taken
        }; // class StatusChangedParamsData

    } // namespace MemoryMonitor

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IMemoryMonitor::INotification::action)
ENUM_CONVERSION_HANDLER(Exchange::IMemoryMonitor::INotification::reason)

}

