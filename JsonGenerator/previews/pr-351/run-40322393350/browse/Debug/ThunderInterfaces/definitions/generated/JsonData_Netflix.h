// C++ types for Netflix API.
// Generated automatically from 'Netflix.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            PlaybackchangeParamsData(const PlaybackchangeParamsData&) = delete;
            PlaybackchangeParamsData(PlaybackchangeParamsData&&) noexcept  = delete;

            PlaybackchangeParamsData& operator=(const PlaybackchangeParamsData&) = delete;
            PlaybackchangeParamsData& operator=(PlaybackchangeParamsData&&) noexcept  = delete;

            ~PlaybackchangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Playing.IsSet() == true);
            }

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

            SystemcommandParamsData(const SystemcommandParamsData&) = delete;
            SystemcommandParamsData(SystemcommandParamsData&&) noexcept  = delete;

            SystemcommandParamsData& operator=(const SystemcommandParamsData&) = delete;
            SystemcommandParamsData& operator=(SystemcommandParamsData&&) noexcept  = delete;

            ~SystemcommandParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Command.IsSet() == true);
            }

        public:
            Core::JSON::String Command; // Command to send to Netflix
        }; // class SystemcommandParamsData

    } // namespace Netflix

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Netflix::VisibilityType)

}

