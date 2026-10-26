// C++ types for DIAL Server API.
// Generated automatically from 'DIALServer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            HideParamsInfo(const HideParamsInfo&) = delete;
            HideParamsInfo(HideParamsInfo&&) noexcept  = delete;

            HideParamsInfo& operator=(const HideParamsInfo&) = delete;
            HideParamsInfo& operator=(HideParamsInfo&&) noexcept  = delete;

            ~HideParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Application.IsSet() == true);
            }

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

            StartParamsData(const StartParamsData&) = delete;
            StartParamsData(StartParamsData&&) noexcept  = delete;

            StartParamsData& operator=(const StartParamsData&) = delete;
            StartParamsData& operator=(StartParamsData&&) noexcept  = delete;

            ~StartParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Application.IsSet() == true);
            }

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

            StopParamsData(const StopParamsData&) = delete;
            StopParamsData(StopParamsData&&) noexcept  = delete;

            StopParamsData& operator=(const StopParamsData&) = delete;
            StopParamsData& operator=(StopParamsData&&) noexcept  = delete;

            ~StopParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Application.IsSet() == true);
            }

        public:
            Core::JSON::String Application; // Application name
            Core::JSON::String Parameters; // Additional application-specific parameters
        }; // class StopParamsData

    } // namespace DIALServer

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::DIALServer::StateType)

}

