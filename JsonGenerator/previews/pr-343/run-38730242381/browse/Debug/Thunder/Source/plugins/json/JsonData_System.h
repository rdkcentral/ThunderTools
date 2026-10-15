// C++ types for System API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace System {

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
            Core::JSON::String Callsign; // Callsign of the plugin
            Core::JSON::String Newcallsign; // Callsign for the cloned plugin
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
            Core::JSON::String Path; // Path to the directory within the persisent storage
        }; // class DeleteParamsData

        class DestroyParamsData : public Core::JSON::Container {
        public:
            DestroyParamsData()
                : Core::JSON::Container()
            {
                Add(_T("callsign"), &Callsign);
            }

            DestroyParamsData(const DestroyParamsData&) = delete;
            DestroyParamsData(DestroyParamsData&&) noexcept  = delete;

            DestroyParamsData& operator=(const DestroyParamsData&) = delete;
            DestroyParamsData& operator=(DestroyParamsData&&) noexcept  = delete;

            ~DestroyParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Callsign.IsSet() == true);
            }

        public:
            Core::JSON::String Callsign; // Callsign of the plugin
        }; // class DestroyParamsData

    } // namespace System

    POP_WARNING()

} // namespace JsonData

}

