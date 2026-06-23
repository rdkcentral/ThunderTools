// C++ types for Monitor API.
// Generated automatically from 'Monitor.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Monitor {

        // Common classes
        //

        class MeasurementInfo : public Core::JSON::Container {
        public:
            MeasurementInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            MeasurementInfo(const MeasurementInfo& _other)
                : Core::JSON::Container()
                , Min(_other.Min)
                , Max(_other.Max)
                , Average(_other.Average)
                , Last(_other.Last)
            {
                _Init();
            }

            MeasurementInfo(MeasurementInfo&& _other) noexcept
                : Core::JSON::Container()
                , Min(std::move(_other.Min))
                , Max(std::move(_other.Max))
                , Average(std::move(_other.Average))
                , Last(std::move(_other.Last))
            {
                _Init();
            }

            MeasurementInfo& operator=(const MeasurementInfo& _rhs)
            {
                Min = _rhs.Min;
                Max = _rhs.Max;
                Average = _rhs.Average;
                Last = _rhs.Last;
                return (*this);
            }

            MeasurementInfo& operator=(MeasurementInfo&& _rhs) noexcept
            {
                Min = std::move(_rhs.Min);
                Max = std::move(_rhs.Max);
                Average = std::move(_rhs.Average);
                Last = std::move(_rhs.Last);
                return (*this);
            }

            ~MeasurementInfo() = default;

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
        }; // class MeasurementInfo

        class MeasurementsInfo : public Core::JSON::Container {
        public:
            MeasurementsInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            MeasurementsInfo(const MeasurementsInfo& _other)
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

            MeasurementsInfo(MeasurementsInfo&& _other) noexcept
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

            MeasurementsInfo& operator=(const MeasurementsInfo& _rhs)
            {
                Resident = _rhs.Resident;
                Allocated = _rhs.Allocated;
                Shared = _rhs.Shared;
                Process = _rhs.Process;
                Operational = _rhs.Operational;
                Count = _rhs.Count;
                return (*this);
            }

            MeasurementsInfo& operator=(MeasurementsInfo&& _rhs) noexcept
            {
                Resident = std::move(_rhs.Resident);
                Allocated = std::move(_rhs.Allocated);
                Shared = std::move(_rhs.Shared);
                Process = std::move(_rhs.Process);
                Operational = std::move(_rhs.Operational);
                Count = std::move(_rhs.Count);
                return (*this);
            }

            ~MeasurementsInfo() = default;

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
            MeasurementInfo Resident; // Resident memory measurement
            MeasurementInfo Allocated; // Allocated memory measurement
            MeasurementInfo Shared; // Shared memory measurement
            MeasurementInfo Process; // Processes measurement
            Core::JSON::Boolean Operational; // Whether the service is up and running
            Core::JSON::DecUInt32 Count; // Number of measurements
        }; // class MeasurementsInfo

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

        class InfoInfo : public Core::JSON::Container {
        public:
            InfoInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            InfoInfo(const InfoInfo& _other)
                : Core::JSON::Container()
                , Measurements(_other.Measurements)
                , Observable(_other.Observable)
                , Restart(_other.Restart)
            {
                _Init();
            }

            InfoInfo(InfoInfo&& _other) noexcept
                : Core::JSON::Container()
                , Measurements(std::move(_other.Measurements))
                , Observable(std::move(_other.Observable))
                , Restart(std::move(_other.Restart))
            {
                _Init();
            }

            InfoInfo& operator=(const InfoInfo& _rhs)
            {
                Measurements = _rhs.Measurements;
                Observable = _rhs.Observable;
                Restart = _rhs.Restart;
                return (*this);
            }

            InfoInfo& operator=(InfoInfo&& _rhs) noexcept
            {
                Measurements = std::move(_rhs.Measurements);
                Observable = std::move(_rhs.Observable);
                Restart = std::move(_rhs.Restart);
                return (*this);
            }

            ~InfoInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (((Measurements.IsSet() == true) && (Measurements.IsDataValid() == true)) && (Observable.IsSet() == true) && ((Restart.IsSet() == true) && (Restart.IsDataValid() == true)));
            }

        private:
            void _Init()
            {
                Add(_T("measurements"), &Measurements);
                Add(_T("observable"), &Observable);
                Add(_T("restart"), &Restart);
            }

        public:
            MeasurementsInfo Measurements; // Measurements for the service
            Core::JSON::String Observable; // A callsign of the watched service
            RestartInfo Restart; // Restart limits for failures applying to the service
        }; // class InfoInfo

        // Method params/result classes
        //

        class ActionParamsData : public Core::JSON::Container {
        public:
            ActionParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("action"), &Action);
                Add(_T("reason"), &Reason);
            }

            ActionParamsData(const ActionParamsData&) = delete;
            ActionParamsData(ActionParamsData&&) noexcept  = delete;

            ActionParamsData& operator=(const ActionParamsData&) = delete;
            ActionParamsData& operator=(ActionParamsData&&) noexcept  = delete;

            ~ActionParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Callsign.IsSet() == true) && (Action.IsSet() == true) && (Reason.IsSet() == true));
            }

        public:
            Core::JSON::String Callsign; // Callsign of the service the Monitor acted upon
            Core::JSON::String Action; // The action executed by the Monitor on a service. One of: "Activate", "Deactivate", "StoppedRestarting"
            Core::JSON::String Reason; // A message describing the reason the action was taken
        }; // class ActionParamsData

        class ResetstatsParamsData : public Core::JSON::Container {
        public:
            ResetstatsParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
            }

            ResetstatsParamsData(const ResetstatsParamsData&) = delete;
            ResetstatsParamsData(ResetstatsParamsData&&) noexcept  = delete;

            ResetstatsParamsData& operator=(const ResetstatsParamsData&) = delete;
            ResetstatsParamsData& operator=(ResetstatsParamsData&&) noexcept  = delete;

            ~ResetstatsParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Callsign.IsSet() == true);
            }

        public:
            Core::JSON::String Callsign; // The callsign of a service to reset statistics of
        }; // class ResetstatsParamsData

        class RestartlimitsParamsData : public Core::JSON::Container {
        public:
            RestartlimitsParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("restart"), &Restart);
            }

            RestartlimitsParamsData(const RestartlimitsParamsData&) = delete;
            RestartlimitsParamsData(RestartlimitsParamsData&&) noexcept  = delete;

            RestartlimitsParamsData& operator=(const RestartlimitsParamsData&) = delete;
            RestartlimitsParamsData& operator=(RestartlimitsParamsData&&) noexcept  = delete;

            ~RestartlimitsParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Callsign.IsSet() == true) && ((Restart.IsSet() == true) && (Restart.IsDataValid() == true)));
            }

        public:
            Core::JSON::String Callsign; // The callsign of a service to reset measurements snapshot of
            RestartInfo Restart; // Restart limits for failures applying to the service
        }; // class RestartlimitsParamsData

    } // namespace Monitor

    POP_WARNING()

} // namespace JsonData

}

