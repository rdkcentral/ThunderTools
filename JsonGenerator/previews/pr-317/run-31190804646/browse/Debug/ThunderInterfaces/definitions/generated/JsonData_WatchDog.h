// C++ types for WatchDog API.
// Generated automatically from 'IWatchDog.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IWatchDog.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace WatchDog {

        // Method params/result classes
        //

        class TouchParamsData : public Core::JSON::Container {
        public:
            TouchParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
            }

            TouchParamsData(const TouchParamsData&) = delete;
            TouchParamsData(TouchParamsData&&) noexcept  = delete;

            TouchParamsData& operator=(const TouchParamsData&) = delete;
            TouchParamsData& operator=(TouchParamsData&&) noexcept  = delete;

            ~TouchParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Callsign.IsSet() == true);
            }

        public:
            Core::JSON::String Callsign; // In case a specific watchdog needs to be padded pass the name of the callsign for which we want to touch.
        }; // class TouchParamsData

    } // namespace WatchDog

    POP_WARNING()

} // namespace JsonData

}

