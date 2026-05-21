// Enumeration code for MessageControl API JSON-RPC API.
// Generated automatically from 'IMessageControl.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IMessageControl.h>
#include "JsonData_MessageControl.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(Exchange::IMessageControl::messagetype)
    { Exchange::IMessageControl::messagetype::TRACING, _TXT("Tracing") },
    { Exchange::IMessageControl::messagetype::LOGGING, _TXT("Logging") },
    { Exchange::IMessageControl::messagetype::REPORTING, _TXT("Reporting") },
    { Exchange::IMessageControl::messagetype::STANDARD_OUT, _TXT("StandardOut") },
    { Exchange::IMessageControl::messagetype::STANDARD_ERROR, _TXT("StandardError") },
ENUM_CONVERSION_END(Exchange::IMessageControl::messagetype)

}
