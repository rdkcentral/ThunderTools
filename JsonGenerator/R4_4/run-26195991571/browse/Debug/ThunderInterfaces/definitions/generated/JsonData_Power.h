// C++ types for Power API.
// Generated automatically from 'Power.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Power {

        // Common enums
        //

        // Power state
        enum StateType : uint8_t {
            ON = 1,
            ACTIVESTANDBY = 2,
            PASSIVESTANDBY = 3,
            SUSPENDTORAM = 4,
            HIBERNATE = 5,
            POWEROFF = 6
        };

        // Method params/result classes
        //

        class PowerData : public Core::JSON::Container {
        public:
            PowerData()
                : Core::JSON::Container()
            {
                Add(_T("powerstate"), &Powerstate);
                Add(_T("timeout"), &Timeout);
            }

            PowerData(const PowerData&) = delete;
            PowerData(PowerData&&) noexcept  = delete;

            PowerData& operator=(const PowerData&) = delete;
            PowerData& operator=(PowerData&&) noexcept  = delete;

            ~PowerData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Powerstate.IsSet() == true) && (Timeout.IsSet() == true));
            }

        public:
            Core::JSON::EnumType<StateType> Powerstate; // Power state
            Core::JSON::DecUInt32 Timeout; // Time to wait for power state change
        }; // class PowerData

    } // namespace Power

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Power::StateType)

}

