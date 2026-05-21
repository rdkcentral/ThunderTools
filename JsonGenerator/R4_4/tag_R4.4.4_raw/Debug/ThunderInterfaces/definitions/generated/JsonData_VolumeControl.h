// C++ classes for VolumeControl API JSON-RPC API.
// Generated automatically from 'IVolumeControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IVolumeControl.h>

namespace WPEFramework {

namespace JsonData {

    namespace VolumeControl {

        // Method params/result classes
        //

        class MutedParamsData : public Core::JSON::Container {
        public:
            MutedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("muted"), &Muted);
            }

            bool IsValid() const
            {
                return (true);
            }

            MutedParamsData(const MutedParamsData&) = delete;
            MutedParamsData& operator=(const MutedParamsData&) = delete;

        public:
            Core::JSON::Boolean Muted; // New mute state (true: muted, false: un-muted)
        }; // class MutedParamsData

        class VolumeParamsData : public Core::JSON::Container {
        public:
            VolumeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("volume"), &Volume);
            }

            bool IsValid() const
            {
                return (true);
            }

            VolumeParamsData(const VolumeParamsData&) = delete;
            VolumeParamsData& operator=(const VolumeParamsData&) = delete;

        public:
            Core::JSON::DecUInt8 Volume; // New bolume level in percent
        }; // class VolumeParamsData

    } // namespace VolumeControl

} // namespace JsonData

}

