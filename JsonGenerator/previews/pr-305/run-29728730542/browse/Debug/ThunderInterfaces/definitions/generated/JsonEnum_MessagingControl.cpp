// Enumeration code for MessagingControl API.
// Generated automatically from 'IMessagingControl.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IMessagingControl.h>
#include "JsonData_MessagingControl.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IMessagingControl::messagetype)
    { Exchange::IMessagingControl::messagetype::INVALID, _TXT("Invalid") },
    { Exchange::IMessagingControl::messagetype::TRACING, _TXT("Tracing") },
    { Exchange::IMessagingControl::messagetype::LOGGING, _TXT("Logging") },
    { Exchange::IMessagingControl::messagetype::REPORTING, _TXT("Reporting") },
    { Exchange::IMessagingControl::messagetype::OPERATIONAL_STREAM, _TXT("OperationalStream") },
    { Exchange::IMessagingControl::messagetype::ASSERT, _TXT("Assert") },
    { Exchange::IMessagingControl::messagetype::TELEMETRY, _TXT("Telemetry") },
ENUM_CONVERSION_END(Exchange::IMessagingControl::messagetype)

}
