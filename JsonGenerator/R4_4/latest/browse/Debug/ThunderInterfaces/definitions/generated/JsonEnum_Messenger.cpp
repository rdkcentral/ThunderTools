// Enumeration code for Messenger API JSON-RPC API.
// Generated automatically from 'Messenger.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_Messenger.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::Messenger::SecureType)
    { JsonData::Messenger::SecureType::INSECURE, _TXT("insecure") },
    { JsonData::Messenger::SecureType::SECURE, _TXT("secure") },
ENUM_CONVERSION_END(JsonData::Messenger::SecureType)

ENUM_CONVERSION_BEGIN(JsonData::Messenger::RoomupdateParamsData::ActionType)
    { JsonData::Messenger::RoomupdateParamsData::ActionType::CREATED, _TXT("created") },
    { JsonData::Messenger::RoomupdateParamsData::ActionType::DESTROYED, _TXT("destroyed") },
ENUM_CONVERSION_END(JsonData::Messenger::RoomupdateParamsData::ActionType)

ENUM_CONVERSION_BEGIN(JsonData::Messenger::UserupdateParamsData::ActionType)
    { JsonData::Messenger::UserupdateParamsData::ActionType::JOINED, _TXT("joined") },
    { JsonData::Messenger::UserupdateParamsData::ActionType::LEFT, _TXT("left") },
ENUM_CONVERSION_END(JsonData::Messenger::UserupdateParamsData::ActionType)

}
