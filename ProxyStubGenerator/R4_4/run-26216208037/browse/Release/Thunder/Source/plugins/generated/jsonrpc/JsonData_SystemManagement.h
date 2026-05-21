// C++ classes for SystemManagement API JSON-RPC API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            CloneParamsData(const CloneParamsData&) = delete;
            CloneParamsData& operator=(const CloneParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            DeleteParamsData(const DeleteParamsData&) = delete;
            DeleteParamsData& operator=(const DeleteParamsData&) = delete;

        public:
            Core::JSON::String Path; // Removes contents of a directory from the persistent storage.
        }; // class DeleteParamsData

    } // namespace SystemManagement

} // namespace JsonData

}

