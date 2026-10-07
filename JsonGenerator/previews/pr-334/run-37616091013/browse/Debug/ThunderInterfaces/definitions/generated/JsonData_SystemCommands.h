// C++ types for SystemCommands API.
// Generated automatically from 'ISystemCommands.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/ISystemCommands.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SystemCommands {

        // Method params/result classes
        //

        class USBResetParamsData : public Core::JSON::Container {
        public:
            USBResetParamsData()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
            }

            USBResetParamsData(const USBResetParamsData&) = delete;
            USBResetParamsData(USBResetParamsData&&) noexcept  = delete;

            USBResetParamsData& operator=(const USBResetParamsData&) = delete;
            USBResetParamsData& operator=(USBResetParamsData&&) noexcept  = delete;

            ~USBResetParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Device.IsSet() == true);
            }

        public:
            Core::JSON::String Device; // USB device to reset
        }; // class USBResetParamsData

    } // namespace SystemCommands

    POP_WARNING()

} // namespace JsonData

}

