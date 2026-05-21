// C++ classes for Netflix API JSON-RPC API.
// Generated automatically from 'Netflix.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace Netflix {

        // Common enums
        //

        // Current Netflix visibility
        enum class VisibilityType : uint8_t {
            VISIBLE,
            HIDDEN
        };

        // Method params/result classes
        //

        class PlaybackchangeParamsData : public Core::JSON::Container {
        public:
            PlaybackchangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("playing"), &Playing);
            }

            bool IsValid() const
            {
                return (true);
            }

            PlaybackchangeParamsData(const PlaybackchangeParamsData&) = delete;
            PlaybackchangeParamsData& operator=(const PlaybackchangeParamsData&) = delete;

        public:
            Core::JSON::Boolean Playing; // Determines if the Netflix is in playing mode (true) or not playing (false)
        }; // class PlaybackchangeParamsData

        class SystemcommandParamsData : public Core::JSON::Container {
        public:
            SystemcommandParamsData()
                : Core::JSON::Container()
            {
                Add(_T("command"), &Command);
            }

            bool IsValid() const
            {
                return (true);
            }

            SystemcommandParamsData(const SystemcommandParamsData&) = delete;
            SystemcommandParamsData& operator=(const SystemcommandParamsData&) = delete;

        public:
            Core::JSON::String Command; // Command to send to Netflix
        }; // class SystemcommandParamsData

    } // namespace Netflix

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Netflix::VisibilityType)

}

