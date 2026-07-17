// C++ types for TimeSync API.
// Generated automatically from 'ITimeSync.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/ITimeSync.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TimeSync {

        // Method params/result classes
        //

        class TimeInfoData : public Core::JSON::Container {
        public:
            TimeInfoData()
                : Core::JSON::Container()
            {
                _Init();
            }

            TimeInfoData(const TimeInfoData& _other)
                : Core::JSON::Container()
                , Time(_other.Time)
                , Source(_other.Source)
            {
                _Init();
            }

            TimeInfoData(TimeInfoData&& _other) noexcept
                : Core::JSON::Container()
                , Time(std::move(_other.Time))
                , Source(std::move(_other.Source))
            {
                _Init();
            }

            TimeInfoData(const Exchange::ITimeSync::TimeInfo& _other)
                : Core::JSON::Container()
            {
                Time = _other.time.ToISO8601();
                if (_other.source.IsSet() == true) {
                    Source = _other.source.Value();
                }
                _Init();
            }

            TimeInfoData& operator=(const TimeInfoData& _rhs)
            {
                Time = _rhs.Time;
                if (_rhs.Source.IsSet() == true) {
                    Source = _rhs.Source;
                }
                return (*this);
            }

            TimeInfoData& operator=(TimeInfoData&& _rhs) noexcept
            {
                Time = std::move(_rhs.Time);
                Source = std::move(_rhs.Source);
                return (*this);
            }

            TimeInfoData& operator=(const Exchange::ITimeSync::TimeInfo& _rhs)
            {
                Time = _rhs.time.ToISO8601();
                if (_rhs.source.IsSet() == true) {
                    Source = _rhs.source.Value();
                }
                return (*this);
            }

            operator Exchange::ITimeSync::TimeInfo() const
            {
                Exchange::ITimeSync::TimeInfo _value{};
                _value.time.FromISO8601(Time);
                if (Source.IsSet() == true) {
                    _value.source = Source;
                }
                return (_value);
            }

            ~TimeInfoData() = default;

        public:
            bool IsDataValid() const
            {
                return (Time.IsSet() == true);
            }

        private:
            void _Init()
            {
                Add(_T("time"), &Time);
                Add(_T("source"), &Source);
            }

        public:
            Core::JSON::String Time; // Synchronized time (in ISO8601 format); empty string if the time has never been synchronized
            Core::JSON::String Source; // The synchronization source like an NTP server
        }; // class TimeInfoData

        class TimeData : public Core::JSON::Container {
        public:
            TimeData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            TimeData(const TimeData&) = delete;
            TimeData(TimeData&&) noexcept  = delete;

            TimeData& operator=(const TimeData&) = delete;
            TimeData& operator=(TimeData&&) noexcept  = delete;

            ~TimeData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::String Value; // Current system time
        }; // class TimeData

    } // namespace TimeSync

    POP_WARNING()

} // namespace JsonData

}

