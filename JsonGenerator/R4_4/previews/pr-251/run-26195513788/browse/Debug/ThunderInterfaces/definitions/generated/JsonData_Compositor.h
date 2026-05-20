// C++ classes for Compositor API JSON-RPC API.
// Generated automatically from 'Compositor.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            PutontopParamsInfo(const PutontopParamsInfo&) = delete;
            PutontopParamsInfo& operator=(const PutontopParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            GeometryData(const GeometryData&) = delete;
            GeometryData& operator=(const GeometryData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            PutbelowParamsData(const PutbelowParamsData&) = delete;
            PutbelowParamsData& operator=(const PutbelowParamsData&) = delete;

        public:
            Core::JSON::String Client; // Client name to change z-order position
            Core::JSON::String Relative; // Client to put the other surface below
        }; // class PutbelowParamsData

    } // namespace Compositor

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Compositor::ResolutionType)
ENUM_CONVERSION_HANDLER(JsonData::Compositor::BrightnessType)
ENUM_CONVERSION_HANDLER(JsonData::Compositor::VisiblityType)

}

