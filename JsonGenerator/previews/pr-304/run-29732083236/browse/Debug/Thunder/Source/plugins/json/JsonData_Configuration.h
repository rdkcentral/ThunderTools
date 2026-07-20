// C++ types for Configuration API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Configuration {

        // Common classes
        //

        class PersistParamsInfo : public Core::JSON::Container {
        public:
            PersistParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
            }

            PersistParamsInfo(const PersistParamsInfo&) = delete;
            PersistParamsInfo(PersistParamsInfo&&) noexcept  = delete;

            PersistParamsInfo& operator=(const PersistParamsInfo&) = delete;
            PersistParamsInfo& operator=(PersistParamsInfo&&) noexcept  = delete;

            ~PersistParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        public:
            Core::JSON::String Callsign; // Plugin callsign to persist (omit for all plugins, empty string for Controller only)
        }; // class PersistParamsInfo

        // Method params/result classes
        //

    } // namespace Configuration

    POP_WARNING()

} // namespace JsonData

}

