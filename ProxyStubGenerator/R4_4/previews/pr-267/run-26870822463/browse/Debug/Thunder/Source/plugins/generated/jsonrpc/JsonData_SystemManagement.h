// C++ types for SystemManagement API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SystemManagement {

        // Method params/result classes
        //

        class CloneParamsData : public Core::JSON::Container {
        public:
            CloneParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
                Add(_T("newcallsign"), &Newcallsign);
            }

            CloneParamsData(const CloneParamsData&) = delete;
            CloneParamsData(CloneParamsData&&) noexcept  = delete;

            CloneParamsData& operator=(const CloneParamsData&) = delete;
            CloneParamsData& operator=(CloneParamsData&&) noexcept  = delete;

            ~CloneParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Callsign.IsSet() == true) && (Newcallsign.IsSet() == true));
            }

        public:
            Core::JSON::String Callsign; // Create a clone of given plugin to requested new callsign
            Core::JSON::String Newcallsign; // Create a clone of given plugin to requested new callsign
        }; // class CloneParamsData

        class DeleteParamsData : public Core::JSON::Container {
        public:
            DeleteParamsData()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
            }

            DeleteParamsData(const DeleteParamsData&) = delete;
            DeleteParamsData(DeleteParamsData&&) noexcept  = delete;

            DeleteParamsData& operator=(const DeleteParamsData&) = delete;
            DeleteParamsData& operator=(DeleteParamsData&&) noexcept  = delete;

            ~DeleteParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Path.IsSet() == true);
            }

        public:
            Core::JSON::String Path; // Removes contents of a directory from the persistent storage.
        }; // class DeleteParamsData

    } // namespace SystemManagement

    POP_WARNING()

} // namespace JsonData

}

