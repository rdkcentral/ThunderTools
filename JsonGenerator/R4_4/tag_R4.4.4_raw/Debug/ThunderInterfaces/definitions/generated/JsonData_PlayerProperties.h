// C++ classes for PlayerProperties API JSON-RPC API.
// Generated automatically from 'IPlayerInfo.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IPlayerInfo.h>

namespace WPEFramework {

namespace JsonData {

    namespace PlayerProperties {

        // Method params/result classes
        //

    } // namespace PlayerProperties

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IPlayerProperties::AudioCodec)
ENUM_CONVERSION_HANDLER(Exchange::IPlayerProperties::VideoCodec)
ENUM_CONVERSION_HANDLER(Exchange::IPlayerProperties::PlaybackResolution)

}

