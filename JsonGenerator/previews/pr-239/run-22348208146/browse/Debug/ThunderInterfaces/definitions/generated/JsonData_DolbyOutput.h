// C++ types for Output API.
// Generated automatically from 'IDolby.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IDolby.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Dolby {

        namespace Output {

            // Method params/result classes
            //

            class AudioModeChangedParamsData : public Core::JSON::Container {
            public:
                AudioModeChangedParamsData()
                    : Core::JSON::Container()
                {
                    Add(_T("mode"), &Mode);
                    Add(_T("enabled"), &Enabled);
                }

                AudioModeChangedParamsData(const AudioModeChangedParamsData&) = delete;
                AudioModeChangedParamsData(AudioModeChangedParamsData&&) noexcept  = delete;

                AudioModeChangedParamsData& operator=(const AudioModeChangedParamsData&) = delete;
                AudioModeChangedParamsData& operator=(AudioModeChangedParamsData&&) noexcept  = delete;

                ~AudioModeChangedParamsData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Mode.IsSet() == true) && (Enabled.IsSet() == true));
                }

            public:
                Core::JSON::EnumType<Exchange::Dolby::IOutput::SoundModes> Mode; // Changed Mode
                Core::JSON::Boolean Enabled; // Enabled/Disabled
            }; // class AudioModeChangedParamsData

        } // namespace Output

    } // namespace Dolby

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::Dolby::IOutput::SoundModes)
ENUM_CONVERSION_HANDLER(Exchange::Dolby::IOutput::Type)

}

