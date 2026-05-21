// C++ classes for DIAL Server API JSON-RPC API.
// Generated automatically from 'DIALServer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace DIALServer {

        // Common enums
        //

        // Current application running state
        enum class StateType : uint8_t {
            STOPPED,
            STARTED,
            HIDDEN
        };

        // Common classes
        //

        class HideParamsInfo : public Core::JSON::Container {
        public:
            HideParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("application"), &Application);
            }

            bool IsValid() const
            {
                return (true);
            }

            HideParamsInfo(const HideParamsInfo&) = delete;
            HideParamsInfo& operator=(const HideParamsInfo&) = delete;

        public:
            Core::JSON::String Application; // Application name
        }; // class HideParamsInfo

        // Method params/result classes
        //

        class StartParamsData : public Core::JSON::Container {
        public:
            StartParamsData()
                : Core::JSON::Container()
            {
                Add(_T("application"), &Application);
                Add(_T("parameters"), &Parameters);
                Add(_T("payload"), &Payload);
            }

            bool IsValid() const
            {
                return (true);
            }

            StartParamsData(const StartParamsData&) = delete;
            StartParamsData& operator=(const StartParamsData&) = delete;

        public:
            Core::JSON::String Application; // Application name
            Core::JSON::String Parameters; // Additional application-specific parameters
            Core::JSON::String Payload; // Additional application-specific payload
        }; // class StartParamsData

        class StopParamsData : public Core::JSON::Container {
        public:
            StopParamsData()
                : Core::JSON::Container()
            {
                Add(_T("application"), &Application);
                Add(_T("parameters"), &Parameters);
            }

            bool IsValid() const
            {
                return (true);
            }

            StopParamsData(const StopParamsData&) = delete;
            StopParamsData& operator=(const StopParamsData&) = delete;

        public:
            Core::JSON::String Application; // Application name
            Core::JSON::String Parameters; // Additional application-specific parameters
        }; // class StopParamsData

    } // namespace DIALServer

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::DIALServer::StateType)

}

