// Enumeration code for MessageControl API.
// Generated automatically from 'IMessageControl.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IMessageControl.h>
#include "JsonData_MessageControl.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IMessageControl::messagetype)
    { Exchange::IMessageControl::messagetype::INVALID, _TXT("Invalid") },
    { Exchange::IMessageControl::messagetype::TRACING, _TXT("Tracing") },
    { Exchange::IMessageControl::messagetype::LOGGING, _TXT("Logging") },
    { Exchange::IMessageControl::messagetype::REPORTING, _TXT("Reporting") },
    { Exchange::IMessageControl::messagetype::OPERATIONAL_STREAM, _TXT("OperationalStream") },
    { Exchange::IMessageControl::messagetype::ASSERT, _TXT("Assert") },
ENUM_CONVERSION_END(Exchange::IMessageControl::messagetype)

}
