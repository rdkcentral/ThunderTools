// C++ classes for Performance Monitor API JSON-RPC API.
// Generated automatically from 'PerformanceMonitor.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            BufferInfo(const BufferInfo&) = delete;
            BufferInfo& operator=(const BufferInfo&) = delete;

        public:
            Core::JSON::String Data; // Any string data upto the size specified in the length
            Core::JSON::DecUInt16 Length;
            Core::JSON::DecUInt16 Duration;
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

                bool IsValid() const
                {
                    return (true);
                }

                StatisticsData(const StatisticsData&) = delete;
                StatisticsData& operator=(const StatisticsData&) = delete;

            public:
                Core::JSON::DecUInt32 Minimum;
                Core::JSON::DecUInt32 Maximum;
                Core::JSON::DecUInt32 Average;
                Core::JSON::DecUInt32 Count;
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

            bool IsValid() const
            {
                return (true);
            }

            MeasurementData(const MeasurementData&) = delete;
            MeasurementData& operator=(const MeasurementData&) = delete;

        public:
            MeasurementData::StatisticsData Serialization; // Time taken to complete serialization
            StatisticsData Deserialization; // Time taken to complete deserialization
            StatisticsData Execution; // Time taken to complete execution
            StatisticsData Threadpool; // Time taken to complete threadpool wait
            StatisticsData Communication; // Time taken to complete communication
            StatisticsData Total; // Time taken to complete whole jsonrpc process
        }; // class MeasurementData

    } // namespace PerformanceMonitor

} // namespace JsonData

}

