// C++ classes for NetworkTools API JSON-RPC API.
// Generated automatically from 'INetworkTools.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/INetworkTools.h>

namespace WPEFramework {

namespace JsonData {

    namespace NetworkTools {

        // Method params/result classes
        //

        class PingParamsData : public Core::JSON::Container {
        public:
            PingParamsData()
                : Core::JSON::Container()
            {
                Add(_T("destination"), &Destination);
                Add(_T("timeoutinseconds"), &TimeOutInSeconds);
                Add(_T("count"), &Count);
            }

            bool IsValid() const
            {
                return (true);
            }

            PingParamsData(const PingParamsData&) = delete;
            PingParamsData& operator=(const PingParamsData&) = delete;

        public:
            Core::JSON::String Destination; // Ping the given destination with ICMP packages.
            Core::JSON::DecUInt16 TimeOutInSeconds; // Ping the given destination with ICMP packages.
            Core::JSON::DecUInt16 Count; // Ping the given destination with ICMP packages.
        }; // class PingParamsData

        class ReportParamsData : public Core::JSON::Container {
        public:
            ReportParamsData()
                : Core::JSON::Container()
            {
                Add(_T("source"), &Source);
                Add(_T("metadata"), &Metadata);
            }

            bool IsValid() const
            {
                return (true);
            }

            ReportParamsData(const ReportParamsData&) = delete;
            ReportParamsData& operator=(const ReportParamsData&) = delete;

        public:
            Core::JSON::String Source; // is the NodeId of the system that send the metadta presented in the next field.
            Core::JSON::String Metadata; // depending on the tool started, this JSON string will contain additiona information on this notification.
        }; // class ReportParamsData

        class TraceRouteParamsData : public Core::JSON::Container {
        public:
            TraceRouteParamsData()
                : Core::JSON::Container()
            {
                Add(_T("destination"), &Destination);
                Add(_T("timeoutinseconds"), &TimeOutInSeconds);
            }

            bool IsValid() const
            {
                return (true);
            }

            TraceRouteParamsData(const TraceRouteParamsData&) = delete;
            TraceRouteParamsData& operator=(const TraceRouteParamsData&) = delete;

        public:
            Core::JSON::String Destination; // TraceRoute to the given destination with ICMP packages.
            Core::JSON::DecUInt16 TimeOutInSeconds; // TraceRoute to the given destination with ICMP packages.
        }; // class TraceRouteParamsData

    } // namespace NetworkTools

} // namespace JsonData

}

