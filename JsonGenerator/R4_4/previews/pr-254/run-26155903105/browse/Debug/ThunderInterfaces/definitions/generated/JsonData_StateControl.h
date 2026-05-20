// C++ classes for StateControl API JSON-RPC API.
// Generated automatically from 'StateControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace StateControl {

        // Common enums
        //

        // Running state of the service
        enum class StateType : uint8_t {
            RESUMED,
            SUSPENDED
        };

        // Method params/result classes
        //

        class StatechangeParamsData : public Core::JSON::Container {
        public:
            StatechangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("suspended"), &Suspended);
            }

            bool IsValid() const
            {
                return (true);
            }

            StatechangeParamsData(const StatechangeParamsData&) = delete;
            StatechangeParamsData& operator=(const StatechangeParamsData&) = delete;

        public:
            Core::JSON::Boolean Suspended; // Determines if the service has entered suspended state (true) or resumed state (false)
        }; // class StatechangeParamsData

    } // namespace StateControl

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::StateControl::StateType)

}

