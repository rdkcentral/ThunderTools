// Enumeration code for StateControl API.
// Generated automatically from 'StateControl.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_StateControl.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::StateControl::StateType)
    { JsonData::StateControl::StateType::RESUMED, _TXT("resumed") },
    { JsonData::StateControl::StateType::SUSPENDED, _TXT("suspended") },
ENUM_CONVERSION_END(JsonData::StateControl::StateType)

}
