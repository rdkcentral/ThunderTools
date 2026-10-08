// C++ types for Performance Monitor API.
// Generated automatically from 'PerformanceMonitor.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace PerformanceMonitor {

        // Common classes
        //

        class BufferInfo : public Core::JSON::Container {
        public:
            BufferInfo()
                : Core::JSON::Container()
            {
                Add(_T("data"), &Data);
                Add(_T("length"), &Length);
                Add(_T("duration"), &Duration);
            }

            BufferInfo(const BufferInfo&) = delete;
            BufferInfo(BufferInfo&&) noexcept  = delete;

            BufferInfo& operator=(const BufferInfo&) = delete;
            BufferInfo& operator=(BufferInfo&&) noexcept  = delete;

            ~BufferInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Data.IsSet() == true) && (Length.IsSet() == true) && (Duration.IsSet() == true));
            }

        public:
            Core::JSON::String Data; // Any string data upto the size specified in the length
            Core::JSON::DecUInt16 Length; // Size of the data
            Core::JSON::DecUInt16 Duration; // Duration of the measurements
        }; // class BufferInfo

        // Method params/result classes
        //

        class MeasurementData : public Core::JSON::Container {
        public:
            class StatisticsData : public Core::JSON::Container {
            public:
                StatisticsData()
                    : Core::JSON::Container()
                {
                    Add(_T("minimum"), &Minimum);
                    Add(_T("maximum"), &Maximum);
                    Add(_T("average"), &Average);
                    Add(_T("count"), &Count);
                }

                StatisticsData(const StatisticsData&) = delete;
                StatisticsData(StatisticsData&&) noexcept  = delete;

                StatisticsData& operator=(const StatisticsData&) = delete;
                StatisticsData& operator=(StatisticsData&&) noexcept  = delete;

                ~StatisticsData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Minimum.IsSet() == true) && (Maximum.IsSet() == true) && (Average.IsSet() == true) && (Count.IsSet() == true));
                }

            public:
                Core::JSON::DecUInt32 Minimum; // Minimum value of measurements
                Core::JSON::DecUInt32 Maximum; // Maximum value of measurements
                Core::JSON::DecUInt32 Average; // Average value of measurements
                Core::JSON::DecUInt32 Count; // How many times measurement has been collected
            }; // class StatisticsData

            MeasurementData()
                : Core::JSON::Container()
            {
                Add(_T("serialization"), &Serialization);
                Add(_T("deserialization"), &Deserialization);
                Add(_T("execution"), &Execution);
                Add(_T("threadpool"), &Threadpool);
                Add(_T("communication"), &Communication);
                Add(_T("total"), &Total);
            }

            MeasurementData(const MeasurementData&) = delete;
            MeasurementData(MeasurementData&&) noexcept  = delete;

            MeasurementData& operator=(const MeasurementData&) = delete;
            MeasurementData& operator=(MeasurementData&&) noexcept  = delete;

            ~MeasurementData() = default;

        public:
            bool IsDataValid() const
            {
                return (((Serialization.IsSet() == true) && (Serialization.IsDataValid() == true)) && ((Deserialization.IsSet() == true) && (Deserialization.IsDataValid() == true)) && ((Execution.IsSet() == true) && (Execution.IsDataValid() == true)) && ((Threadpool.IsSet() == true) && (Threadpool.IsDataValid() == true)) && ((Communication.IsSet() == true) && (Communication.IsDataValid() == true)) && ((Total.IsSet() == true) && (Total.IsDataValid() == true)));
            }

        public:
            MeasurementData::StatisticsData Serialization; // Time taken to complete serialization
            StatisticsData Deserialization; // Time taken to complete deserialization
            StatisticsData Execution; // Time taken to complete execution
            StatisticsData Threadpool; // Time taken to complete threadpool wait
            StatisticsData Communication; // Time taken to complete communication
            StatisticsData Total; // Time taken to complete whole jsonrpc process
        }; // class MeasurementData

    } // namespace PerformanceMonitor

    POP_WARNING()

} // namespace JsonData

}

