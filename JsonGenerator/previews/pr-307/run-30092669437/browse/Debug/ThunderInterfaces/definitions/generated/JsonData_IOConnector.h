// C++ types for IOConnector API.
// Generated automatically from 'IIOConnector.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IIOConnector.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace IOConnector {

        // Common classes
        //

        class PinInfo : public Core::JSON::Container {
        public:
            PinInfo()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            PinInfo(const PinInfo&) = delete;
            PinInfo(PinInfo&&) noexcept  = delete;

            PinInfo& operator=(const PinInfo&) = delete;
            PinInfo& operator=(PinInfo&&) noexcept  = delete;

            ~PinInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::DecSInt32 Value; // value of the pin
        }; // class PinInfo

        // Method params/result classes
        //

    } // namespace IOConnector

    POP_WARNING()

} // namespace JsonData

}

