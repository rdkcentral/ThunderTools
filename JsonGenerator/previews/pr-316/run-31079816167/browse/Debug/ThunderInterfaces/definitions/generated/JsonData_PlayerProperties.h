// C++ types for PlayerProperties API.
// Generated automatically from 'IPlayerInfo.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IPlayerInfo.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace PlayerProperties {

        // Method params/result classes
        //

    } // namespace PlayerProperties

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IPlayerProperties::AudioCodec)
ENUM_CONVERSION_HANDLER(Exchange::IPlayerProperties::VideoCodec)
ENUM_CONVERSION_HANDLER(Exchange::IPlayerProperties::PlaybackResolution)

}

