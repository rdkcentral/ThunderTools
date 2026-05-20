// Enumeration code for Netflix API JSON-RPC API.
// Generated automatically from 'Netflix.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_Netflix.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::Netflix::VisibilityType)
    { JsonData::Netflix::VisibilityType::VISIBLE, _TXT("visible") },
    { JsonData::Netflix::VisibilityType::HIDDEN, _TXT("hidden") },
ENUM_CONVERSION_END(JsonData::Netflix::VisibilityType)

}
