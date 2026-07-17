// C++ types for StateController API.
// Generated automatically from 'IStateController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace StateController {

        // Method params/result classes
        //

        class RequestParamsData : public Core::JSON::Container {
        public:
            RequestParamsData()
                : Core::JSON::Container()
            {
                Add(_T("state"), &State);
            }

            RequestParamsData(const RequestParamsData&) = delete;
            RequestParamsData(RequestParamsData&&) noexcept  = delete;

            RequestParamsData& operator=(const RequestParamsData&) = delete;
            RequestParamsData& operator=(RequestParamsData&&) noexcept  = delete;

            ~RequestParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (State.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<PluginHost::IStateController::command> State; // State to which it is requested to change
        }; // class RequestParamsData

        class StateChangedParamsData : public Core::JSON::Container {
        public:
            StateChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("state"), &State);
            }

            StateChangedParamsData(const StateChangedParamsData&) = delete;
            StateChangedParamsData(StateChangedParamsData&&) noexcept  = delete;

            StateChangedParamsData& operator=(const StateChangedParamsData&) = delete;
            StateChangedParamsData& operator=(StateChangedParamsData&&) noexcept  = delete;

            ~StateChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (State.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<PluginHost::IStateController::state> State; // Current state of the service
        }; // class StateChangedParamsData

    } // namespace StateController

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(PluginHost::IStateController::command)
ENUM_CONVERSION_HANDLER(PluginHost::IStateController::state)

}

