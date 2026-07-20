// C++ types for VolumeControl API.
// Generated automatically from 'IVolumeControl.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IVolumeControl.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            MutedParamsData(const MutedParamsData&) = delete;
            MutedParamsData(MutedParamsData&&) noexcept  = delete;

            MutedParamsData& operator=(const MutedParamsData&) = delete;
            MutedParamsData& operator=(MutedParamsData&&) noexcept  = delete;

            ~MutedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Muted.IsSet() == true);
            }

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

            VolumeParamsData(const VolumeParamsData&) = delete;
            VolumeParamsData(VolumeParamsData&&) noexcept  = delete;

            VolumeParamsData& operator=(const VolumeParamsData&) = delete;
            VolumeParamsData& operator=(VolumeParamsData&&) noexcept  = delete;

            ~VolumeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Volume.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt8 Volume; // New bolume level in percent
        }; // class VolumeParamsData

    } // namespace VolumeControl

    POP_WARNING()

} // namespace JsonData

}

