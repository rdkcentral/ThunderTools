// C++ classes for Output API JSON-RPC API.
// Generated automatically from 'IDolby.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IDolby.h>

namespace WPEFramework {

namespace JsonData {

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

                bool IsValid() const
                {
                    return (true);
                }

                AudioModeChangedParamsData(const AudioModeChangedParamsData&) = delete;
                AudioModeChangedParamsData& operator=(const AudioModeChangedParamsData&) = delete;

            public:
                Core::JSON::EnumType<Exchange::Dolby::IOutput::SoundModes> Mode; // Changed Mode
                Core::JSON::Boolean Enabled; // Enabled/Disabled
            }; // class AudioModeChangedParamsData

        } // namespace Output

    } // namespace Dolby

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::Dolby::IOutput::SoundModes)
ENUM_CONVERSION_HANDLER(Exchange::Dolby::IOutput::Type)

}

