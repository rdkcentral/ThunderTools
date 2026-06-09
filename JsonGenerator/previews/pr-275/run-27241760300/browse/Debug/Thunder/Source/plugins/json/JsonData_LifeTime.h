// C++ types for LifeTime API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            ActivateParamsInfo(const ActivateParamsInfo&) = delete;
            ActivateParamsInfo(ActivateParamsInfo&&) noexcept  = delete;

            ActivateParamsInfo& operator=(const ActivateParamsInfo&) = delete;
            ActivateParamsInfo& operator=(ActivateParamsInfo&&) noexcept  = delete;

            ~ActivateParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Callsign.IsSet() == true);
            }

        public:
            Core::JSON::String Callsign; // Callsign of plugin to be activated
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

            HibernateParamsData(const HibernateParamsData&) = delete;
            HibernateParamsData(HibernateParamsData&&) noexcept  = delete;

            HibernateParamsData& operator=(const HibernateParamsData&) = delete;
            HibernateParamsData& operator=(HibernateParamsData&&) noexcept  = delete;

            ~HibernateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Callsign.IsSet() == true) && (Timeout.IsSet() == true));
            }

        public:
            Core::JSON::String Callsign; // Callsign of plugin to be hibernated
            Core::JSON::DecUInt32 Timeout; // Allowed time
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

            StateChangeParamsData(const StateChangeParamsData&) = delete;
            StateChangeParamsData(StateChangeParamsData&&) noexcept  = delete;

            StateChangeParamsData& operator=(const StateChangeParamsData&) = delete;
            StateChangeParamsData& operator=(StateChangeParamsData&&) noexcept  = delete;

            ~StateChangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((State.IsSet() == true) && (Reason.IsSet() == true));
            }

        public:
            Core::JSON::String Callsign; // Plugin callsign
            Core::JSON::EnumType<PluginHost::IShell::state> State; // New state of the plugin
            Core::JSON::EnumType<PluginHost::IShell::reason> Reason; // Reason for state change
        }; // class StateChangeParamsData

        class StateControlStateChangeParamsData : public Core::JSON::Container {
        public:
            StateControlStateChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("state"), &State);
            }

            StateControlStateChangeParamsData(const StateControlStateChangeParamsData&) = delete;
            StateControlStateChangeParamsData(StateControlStateChangeParamsData&&) noexcept  = delete;

            StateControlStateChangeParamsData& operator=(const StateControlStateChangeParamsData&) = delete;
            StateControlStateChangeParamsData& operator=(StateControlStateChangeParamsData&&) noexcept  = delete;

            ~StateControlStateChangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (State.IsSet() == true);
            }

        public:
            Core::JSON::String Callsign; // Plugin callsign
            Core::JSON::EnumType<Exchange::Controller::ILifeTime::state> State; // New state of the plugin
        }; // class StateControlStateChangeParamsData

    } // namespace LifeTime

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(PluginHost::IShell::state)
ENUM_CONVERSION_HANDLER(PluginHost::IShell::reason)
ENUM_CONVERSION_HANDLER(Exchange::Controller::ILifeTime::state)

}

