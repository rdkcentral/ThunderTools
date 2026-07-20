// C++ types for Events API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Events {

        // Method params/result classes
        //

        class ForwardMessageParamsData : public Core::JSON::Container {
        public:
            ForwardMessageParamsData()
                : Core::JSON::Container()
            {
                Add(_T("event"), &Event);
                Add(_T("callsign"), &Callsign);
                Add(_T("params"), &Params);
                Params.SetQuoted(false);
            }

            ForwardMessageParamsData(const ForwardMessageParamsData&) = delete;
            ForwardMessageParamsData(ForwardMessageParamsData&&) noexcept  = delete;

            ForwardMessageParamsData& operator=(const ForwardMessageParamsData&) = delete;
            ForwardMessageParamsData& operator=(ForwardMessageParamsData&&) noexcept  = delete;

            ~ForwardMessageParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Event.IsSet() == true);
            }

        public:
            Core::JSON::String Event; // Name of the message
            Core::JSON::String Callsign; // Origin of the message
            Core::JSON::String Params; // Contents of the message
        }; // class ForwardMessageParamsData

    } // namespace Events

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(PluginHost::IShell::state)
ENUM_CONVERSION_HANDLER(PluginHost::IShell::reason)
ENUM_CONVERSION_HANDLER(Exchange::Controller::ILifeTime::state)
ENUM_CONVERSION_HANDLER(PluginHost::ISubSystem::subsystem)

}

