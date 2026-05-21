// C++ classes for Power API JSON-RPC API.
// Generated automatically from 'Power.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            PowerData(const PowerData&) = delete;
            PowerData& operator=(const PowerData&) = delete;

        public:
            Core::JSON::EnumType<StateType> Powerstate; // Power state
            Core::JSON::DecUInt32 Timeout; // Time to wait for power state change
        }; // class PowerData

    } // namespace Power

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Power::StateType)

}

