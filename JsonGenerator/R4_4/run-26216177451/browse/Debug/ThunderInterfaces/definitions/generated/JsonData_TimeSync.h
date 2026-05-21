// C++ classes for Time Sync API JSON-RPC API.
// Generated automatically from 'TimeSync.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            SynctimeData(const SynctimeData&) = delete;
            SynctimeData& operator=(const SynctimeData&) = delete;

        public:
            Core::JSON::String Time; // Synchronized time (in ISO8601 format); empty string if the time has never been synchronized
            Core::JSON::String Source; // The synchronization source e.g. an NTP server
        }; // class SynctimeData

    } // namespace TimeSync

} // namespace JsonData

}

