// Enumeration code for ContentProtection API.
// Generated automatically from 'IContentProtection.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IContentProtection.h>
#include "JsonData_ContentProtection.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IContentProtection::KeySystem)
    { Exchange::IContentProtection::KeySystem::WIDEVINE, _TXT("widevine") },
    { Exchange::IContentProtection::KeySystem::PLAYREADY, _TXT("playready") },
    { Exchange::IContentProtection::KeySystem::CLEARKEY, _TXT("clearkey") },
ENUM_CONVERSION_END(Exchange::IContentProtection::KeySystem)

ENUM_CONVERSION_BEGIN(Exchange::IContentProtection::State)
    { Exchange::IContentProtection::State::ACTIVE, _TXT("active") },
    { Exchange::IContentProtection::State::INACTIVE, _TXT("inactive") },
ENUM_CONVERSION_END(Exchange::IContentProtection::State)

ENUM_CONVERSION_BEGIN(Exchange::IContentProtection::INotification::Status::State)
    { Exchange::IContentProtection::INotification::Status::State::GRANTED, _TXT("GRANTED") },
    { Exchange::IContentProtection::INotification::Status::State::NOT_REQUIRED, _TXT("NOT_REQUIRED") },
    { Exchange::IContentProtection::INotification::Status::State::DENIED, _TXT("DENIED") },
    { Exchange::IContentProtection::INotification::Status::State::FAILED, _TXT("FAILED") },
ENUM_CONVERSION_END(Exchange::IContentProtection::INotification::Status::State)

}
