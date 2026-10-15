// C++ types for Power API.
// Generated automatically from 'IPower.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IPower.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Power {

        // Method params/result classes
        //

        class SetStateParamsData : public Core::JSON::Container {
        public:
            SetStateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("state"), &State);
                Add(_T("waittime"), &WaitTime);
            }

            SetStateParamsData(const SetStateParamsData&) = delete;
            SetStateParamsData(SetStateParamsData&&) noexcept  = delete;

            SetStateParamsData& operator=(const SetStateParamsData&) = delete;
            SetStateParamsData& operator=(SetStateParamsData&&) noexcept  = delete;

            ~SetStateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((State.IsSet() == true) && (WaitTime.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::IPower::PCState> State; // The power state to set
            Core::JSON::DecUInt32 WaitTime; // The time to wait for the power state to be set in seconds
        }; // class SetStateParamsData

        class StateChangeParamsData : public Core::JSON::Container {
        public:
            StateChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("origin"), &Origin);
                Add(_T("destination"), &Destination);
                Add(_T("phase"), &Phase);
            }

            StateChangeParamsData(const StateChangeParamsData&) = delete;
            StateChangeParamsData(StateChangeParamsData&&) noexcept  = delete;

            StateChangeParamsData& operator=(const StateChangeParamsData&) = delete;
            StateChangeParamsData& operator=(StateChangeParamsData&&) noexcept  = delete;

            ~StateChangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Origin.IsSet() == true) && (Destination.IsSet() == true) && (Phase.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<Exchange::IPower::PCState> Origin; // The state the device is transitioning from
            Core::JSON::EnumType<Exchange::IPower::PCState> Destination; // The state the device is transitioning to
            Core::JSON::EnumType<Exchange::IPower::PCPhase> Phase; // The phase of the transition
        }; // class StateChangeParamsData

    } // namespace Power

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IPower::PCState)
ENUM_CONVERSION_HANDLER(Exchange::IPower::PCPhase)

}

