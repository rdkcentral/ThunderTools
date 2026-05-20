// Enumeration code for Trace Control API JSON-RPC API.
// Generated automatically from 'TraceControl.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_TraceControl.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::TraceControl::StateType)
    { JsonData::TraceControl::StateType::ENABLED, _TXT("enabled") },
    { JsonData::TraceControl::StateType::DISABLED, _TXT("disabled") },
    { JsonData::TraceControl::StateType::TRISTATED, _TXT("tristated") },
ENUM_CONVERSION_END(JsonData::TraceControl::StateType)

}
