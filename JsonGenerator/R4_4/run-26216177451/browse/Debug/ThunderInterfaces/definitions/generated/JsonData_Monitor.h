// C++ classes for Monitor API JSON-RPC API.
// Generated automatically from 'Monitor.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            MeasurementInfo& operator=(const MeasurementInfo& _rhs)
            {
                Min = _rhs.Min;
                Max = _rhs.Max;
                Average = _rhs.Average;
                Last = _rhs.Last;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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

            bool IsValid() const
            {
                return (true);
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

            RestartInfo& operator=(const RestartInfo& _rhs)
            {
                Limit = _rhs.Limit;
                Window = _rhs.Window;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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

            InfoInfo& operator=(const InfoInfo& _rhs)
            {
                Measurements = _rhs.Measurements;
                Observable = _rhs.Observable;
                Restart = _rhs.Restart;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
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

            bool IsValid() const
            {
                return (true);
            }

            ActionParamsData(const ActionParamsData&) = delete;
            ActionParamsData& operator=(const ActionParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            ResetstatsParamsData(const ResetstatsParamsData&) = delete;
            ResetstatsParamsData& operator=(const ResetstatsParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            RestartlimitsParamsData(const RestartlimitsParamsData&) = delete;
            RestartlimitsParamsData& operator=(const RestartlimitsParamsData&) = delete;

        public:
            Core::JSON::String Callsign; // The callsign of a service to reset measurements snapshot of
            RestartInfo Restart; // Sets new restart limits for a service
        }; // class RestartlimitsParamsData

    } // namespace Monitor

} // namespace JsonData

}

