// C++ classes for LifeTime API JSON-RPC API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    namespace LifeTime {

        // Common classes
        //

        class ActivateParamsInfo : public Core::JSON::Container {
        public:
            ActivateParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
            }

            bool IsValid() const
            {
                return (true);
            }

            ActivateParamsInfo(const ActivateParamsInfo&) = delete;
            ActivateParamsInfo& operator=(const ActivateParamsInfo&) = delete;

        public:
            Core::JSON::String Callsign; // Activate a plugin, i.e. move from Deactivated, via Activating to Activated state
        }; // class ActivateParamsInfo

        // Method params/result classes
        //

        class HibernateParamsData : public Core::JSON::Container {
        public:
            HibernateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("timeout"), &Timeout);
            }

            bool IsValid() const
            {
                return (true);
            }

            HibernateParamsData(const HibernateParamsData&) = delete;
            HibernateParamsData& operator=(const HibernateParamsData&) = delete;

        public:
            Core::JSON::String Callsign; // Set a plugin in Hibernate state
            Core::JSON::DecUInt32 Timeout; // Set a plugin in Hibernate state
        }; // class HibernateParamsData

        class StateChangeParamsData : public Core::JSON::Container {
        public:
            StateChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("state"), &State);
                Add(_T("reason"), &Reason);
            }

            bool IsValid() const
            {
                return (true);
            }

            StateChangeParamsData(const StateChangeParamsData&) = delete;
            StateChangeParamsData& operator=(const StateChangeParamsData&) = delete;

        public:
            Core::JSON::String Callsign; // Notifies a plugin state change
            Core::JSON::EnumType<PluginHost::IShell::state> State; // Notifies a plugin state change
            Core::JSON::EnumType<PluginHost::IShell::reason> Reason; // Notifies a plugin state change
        }; // class StateChangeParamsData

    } // namespace LifeTime

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(PluginHost::IShell::state)
ENUM_CONVERSION_HANDLER(PluginHost::IShell::reason)

}

