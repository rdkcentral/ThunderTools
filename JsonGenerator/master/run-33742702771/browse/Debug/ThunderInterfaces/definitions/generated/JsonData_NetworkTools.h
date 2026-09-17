// C++ types for NetworkTools API.
// Generated automatically from 'INetworkTools.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/INetworkTools.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace NetworkTools {

        // Method params/result classes
        //

        class PingParamsData : public Core::JSON::Container {
        public:
            PingParamsData()
                : Core::JSON::Container()
            {
                Add(_T("destination"), &Destination);
                Add(_T("timeOutInSeconds"), &TimeOutInSeconds);
                Add(_T("count"), &Count);
            }

            PingParamsData(const PingParamsData&) = delete;
            PingParamsData(PingParamsData&&) noexcept  = delete;

            PingParamsData& operator=(const PingParamsData&) = delete;
            PingParamsData& operator=(PingParamsData&&) noexcept  = delete;

            ~PingParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Destination.IsSet() == true) && (TimeOutInSeconds.IsSet() == true) && (Count.IsSet() == true));
            }

        public:
            Core::JSON::String Destination; // The node id of the host we would like to ping (ipv4/ipv6)
            Core::JSON::DecUInt16 TimeOutInSeconds; // Time out, continue to ping for the given duration.
            Core::JSON::DecUInt16 Count; // Maximum number of pings to send.
        }; // class PingParamsData

        class ReportParamsData : public Core::JSON::Container {
        public:
            ReportParamsData()
                : Core::JSON::Container()
            {
                Add(_T("source"), &Source);
                Add(_T("metadata"), &Metadata);
            }

            ReportParamsData(const ReportParamsData&) = delete;
            ReportParamsData(ReportParamsData&&) noexcept  = delete;

            ReportParamsData& operator=(const ReportParamsData&) = delete;
            ReportParamsData& operator=(ReportParamsData&&) noexcept  = delete;

            ~ReportParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Source.IsSet() == true) && (Metadata.IsSet() == true));
            }

        public:
            Core::JSON::String Source; // The NodeId of the system that send the metadta presented in the next field.
            Core::JSON::String Metadata; // Depending on the tool started, this JSON string will contain additional information on this notification.
        }; // class ReportParamsData

        class TraceRouteParamsData : public Core::JSON::Container {
        public:
            TraceRouteParamsData()
                : Core::JSON::Container()
            {
                Add(_T("destination"), &Destination);
                Add(_T("timeOutInSeconds"), &TimeOutInSeconds);
            }

            TraceRouteParamsData(const TraceRouteParamsData&) = delete;
            TraceRouteParamsData(TraceRouteParamsData&&) noexcept  = delete;

            TraceRouteParamsData& operator=(const TraceRouteParamsData&) = delete;
            TraceRouteParamsData& operator=(TraceRouteParamsData&&) noexcept  = delete;

            ~TraceRouteParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Destination.IsSet() == true) && (TimeOutInSeconds.IsSet() == true));
            }

        public:
            Core::JSON::String Destination; // The node id of the host we would like to ping (ipv4/ipv6)
            Core::JSON::DecUInt16 TimeOutInSeconds; // Time out, continue to ping for the given duration.
        }; // class TraceRouteParamsData

    } // namespace NetworkTools

    POP_WARNING()

} // namespace JsonData

}

