// C++ classes for Subsystem Control API JSON-RPC API.
// Generated automatically from 'SubsystemControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace SubsystemControl {

        // Common enums
        //

        // Subsystem to activate
        enum class SubsystemType : uint8_t {
            PLATFORM,
            NETWORK,
            INTERNET,
            TIME,
            SECURITY,
            LOCATION,
            IDENTIFIER,
            PROVISIONING,
            DECRYPTION,
            BLUETOOTH,
            WEBSOURCE,
            GRAPHICS,
            STREAMING,
            CRYPTOGRAPHY,
            INSTALLATION
        };

        // Method params/result classes
        //

        class ActivateParamsData : public Core::JSON::Container {
        public:
            ActivateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("system"), &System);
                Add(_T("configuration"), &Configuration);
            }

            bool IsValid() const
            {
                return (true);
            }

            ActivateParamsData(const ActivateParamsData&) = delete;
            ActivateParamsData& operator=(const ActivateParamsData&) = delete;

        public:
            Core::JSON::EnumType<SubsystemType> System; // Subsystem to activate
            Core::JSON::String Configuration; // A JSON string that holds the information applicable to the subsystem to be activated
        }; // class ActivateParamsData

    } // namespace SubsystemControl

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::SubsystemControl::SubsystemType)

}

