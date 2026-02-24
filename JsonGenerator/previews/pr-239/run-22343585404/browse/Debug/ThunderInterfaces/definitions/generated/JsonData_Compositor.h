// C++ types for Compositor API.
// Generated automatically from 'Compositor.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Compositor {

        // Common enums
        //

        // Brightness of SDR graphics in HDR display
        enum class BrightnessType : uint8_t {
            DEFAULT,
            MATCH_VIDEO,
            MAX
        };

        // Screen resolution
        enum class ResolutionType : uint8_t {
            UNKNOWN,
            E480I,
            E480P,
            E720P50,
            E720P60,
            E1080P24,
            E1080I50,
            E1080P50,
            E1080P60,
            E2160P50,
            E2160P60
        };

        // Client surface visibility
        enum class VisiblityType : uint8_t {
            VISIBLE,
            HIDDEN
        };

        // Common classes
        //

        class PutontopParamsInfo : public Core::JSON::Container {
        public:
            PutontopParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("client"), &Client);
            }

            PutontopParamsInfo(const PutontopParamsInfo&) = delete;
            PutontopParamsInfo(PutontopParamsInfo&&) noexcept  = delete;

            PutontopParamsInfo& operator=(const PutontopParamsInfo&) = delete;
            PutontopParamsInfo& operator=(PutontopParamsInfo&&) noexcept  = delete;

            ~PutontopParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Client.IsSet() == true);
            }

        public:
            Core::JSON::String Client; // Client name
        }; // class PutontopParamsInfo

        // Method params/result classes
        //

        class GeometryData : public Core::JSON::Container {
        public:
            GeometryData()
                : Core::JSON::Container()
            {
                Add(_T("x"), &X);
                Add(_T("y"), &Y);
                Add(_T("width"), &Width);
                Add(_T("height"), &Height);
            }

            GeometryData(const GeometryData&) = delete;
            GeometryData(GeometryData&&) noexcept  = delete;

            GeometryData& operator=(const GeometryData&) = delete;
            GeometryData& operator=(GeometryData&&) noexcept  = delete;

            ~GeometryData() = default;

        public:
            bool IsDataValid() const
            {
                return ((X.IsSet() == true) && (Y.IsSet() == true) && (Width.IsSet() == true) && (Height.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 X; // Horizontal coordinate of the surface
            Core::JSON::DecUInt32 Y; // Vertical coordinate of the surface
            Core::JSON::DecUInt32 Width; // Surface width
            Core::JSON::DecUInt32 Height; // Surface height
        }; // class GeometryData

        class PutbelowParamsData : public Core::JSON::Container {
        public:
            PutbelowParamsData()
                : Core::JSON::Container()
            {
                Add(_T("client"), &Client);
                Add(_T("relative"), &Relative);
            }

            PutbelowParamsData(const PutbelowParamsData&) = delete;
            PutbelowParamsData(PutbelowParamsData&&) noexcept  = delete;

            PutbelowParamsData& operator=(const PutbelowParamsData&) = delete;
            PutbelowParamsData& operator=(PutbelowParamsData&&) noexcept  = delete;

            ~PutbelowParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Client.IsSet() == true) && (Relative.IsSet() == true));
            }

        public:
            Core::JSON::String Client; // Client name to change z-order position
            Core::JSON::String Relative; // Client to put the other surface below
        }; // class PutbelowParamsData

    } // namespace Compositor

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Compositor::ResolutionType)
ENUM_CONVERSION_HANDLER(JsonData::Compositor::BrightnessType)
ENUM_CONVERSION_HANDLER(JsonData::Compositor::VisiblityType)

}

