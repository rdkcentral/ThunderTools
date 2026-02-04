// C++ types for SubsystemControl API.
// Generated automatically from 'ISubsystemControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/ISubsystemControl.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SubsystemControl {

        // Method params/result classes
        //

        class ActivateParamsData : public Core::JSON::Container {
        public:
            ActivateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("subsystem"), &Subsystem);
                Add(_T("configuration"), &Configuration);
                Configuration.SetQuoted(false);
            }

            ActivateParamsData(const ActivateParamsData&) = delete;
            ActivateParamsData(ActivateParamsData&&) noexcept  = delete;

            ActivateParamsData& operator=(const ActivateParamsData&) = delete;
            ActivateParamsData& operator=(ActivateParamsData&&) noexcept  = delete;

            ~ActivateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Subsystem.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<PluginHost::ISubSystem::subsystem> Subsystem; // Subsystem to activate
            Core::JSON::String Configuration; // A JSON string that holds the information applicable to the subsystem to be activated
        }; // class ActivateParamsData

    } // namespace SubsystemControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(PluginHost::ISubSystem::subsystem)

}

