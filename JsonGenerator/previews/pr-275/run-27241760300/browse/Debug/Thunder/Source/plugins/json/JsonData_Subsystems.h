// C++ types for Subsystems API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Subsystems {

        // Common classes
        //

        class SubsystemInfo : public Core::JSON::Container {
        public:
            SubsystemInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            SubsystemInfo(const SubsystemInfo& _other)
                : Core::JSON::Container()
                , Subsystem(_other.Subsystem)
                , Active(_other.Active)
            {
                _Init();
            }

            SubsystemInfo(SubsystemInfo&& _other) noexcept
                : Core::JSON::Container()
                , Subsystem(std::move(_other.Subsystem))
                , Active(std::move(_other.Active))
            {
                _Init();
            }

            SubsystemInfo(const Exchange::Controller::ISubsystems::Subsystem& _other)
                : Core::JSON::Container()
            {
                Subsystem = _other.Subsystem;
                Active = _other.Active;
                _Init();
            }

            SubsystemInfo& operator=(const SubsystemInfo& _rhs)
            {
                Subsystem = _rhs.Subsystem;
                Active = _rhs.Active;
                return (*this);
            }

            SubsystemInfo& operator=(SubsystemInfo&& _rhs) noexcept
            {
                Subsystem = std::move(_rhs.Subsystem);
                Active = std::move(_rhs.Active);
                return (*this);
            }

            SubsystemInfo& operator=(const Exchange::Controller::ISubsystems::Subsystem& _rhs)
            {
                Subsystem = _rhs.Subsystem;
                Active = _rhs.Active;
                return (*this);
            }

            operator Exchange::Controller::ISubsystems::Subsystem() const
            {
                Exchange::Controller::ISubsystems::Subsystem _value{};
                _value.Subsystem = Subsystem;
                _value.Active = Active;
                return (_value);
            }

            ~SubsystemInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Subsystem.IsSet() == true) && (Active.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("subsystem"), &Subsystem);
                Add(_T("active"), &Active);
            }

        public:
            Core::JSON::EnumType<PluginHost::ISubSystem::subsystem> Subsystem; // Name of the subsystem
            Core::JSON::Boolean Active; // Denotes if the subsystem is currently active
        }; // class SubsystemInfo

        // Method params/result classes
        //

    } // namespace Subsystems

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(PluginHost::IShell::state)
ENUM_CONVERSION_HANDLER(PluginHost::IShell::reason)
ENUM_CONVERSION_HANDLER(Exchange::Controller::ILifeTime::state)
ENUM_CONVERSION_HANDLER(PluginHost::ISubSystem::subsystem)

}

