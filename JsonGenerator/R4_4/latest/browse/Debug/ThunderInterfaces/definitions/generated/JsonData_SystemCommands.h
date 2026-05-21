// C++ types for System Commands API.
// Generated automatically from 'SystemCommands.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SystemCommands {

        // Method params/result classes
        //

        class UsbresetParamsData : public Core::JSON::Container {
        public:
            UsbresetParamsData()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
            }

            UsbresetParamsData(const UsbresetParamsData&) = delete;
            UsbresetParamsData(UsbresetParamsData&&) noexcept  = delete;

            UsbresetParamsData& operator=(const UsbresetParamsData&) = delete;
            UsbresetParamsData& operator=(UsbresetParamsData&&) noexcept  = delete;

            ~UsbresetParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Device.IsSet() == true);
            }

        public:
            Core::JSON::String Device; // USB device to reset
        }; // class UsbresetParamsData

    } // namespace SystemCommands

    POP_WARNING()

} // namespace JsonData

}

