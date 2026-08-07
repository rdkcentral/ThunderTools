// C++ types for Time Sync API.
// Generated automatically from 'TimeSync.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TimeSync {

        // Method params/result classes
        //

        class SynctimeData : public Core::JSON::Container {
        public:
            SynctimeData()
                : Core::JSON::Container()
            {
                Add(_T("time"), &Time);
                Add(_T("source"), &Source);
            }

            SynctimeData(const SynctimeData&) = delete;
            SynctimeData(SynctimeData&&) noexcept  = delete;

            SynctimeData& operator=(const SynctimeData&) = delete;
            SynctimeData& operator=(SynctimeData&&) noexcept  = delete;

            ~SynctimeData() = default;

        public:
            bool IsDataValid() const
            {
                return (Time.IsSet() == true);
            }

        public:
            Core::JSON::String Time; // Synchronized time (in ISO8601 format); empty string if the time has never been synchronized
            Core::JSON::String Source; // The synchronization source e.g. an NTP server
        }; // class SynctimeData

    } // namespace TimeSync

    POP_WARNING()

} // namespace JsonData

}

