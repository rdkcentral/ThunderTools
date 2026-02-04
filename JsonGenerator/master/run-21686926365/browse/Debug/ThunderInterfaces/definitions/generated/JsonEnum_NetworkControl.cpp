// Enumeration code for NetworkControl API.
// Generated automatically from 'INetworkControl.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/INetworkControl.h>
#include "JsonData_NetworkControl.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::INetworkControl::StatusType)
    { Exchange::INetworkControl::StatusType::UNAVAILABLE, _TXT("Unavailable") },
    { Exchange::INetworkControl::StatusType::AVAILABLE, _TXT("Available") },
ENUM_CONVERSION_END(Exchange::INetworkControl::StatusType)

ENUM_CONVERSION_BEGIN(Exchange::INetworkControl::ModeType)
    { Exchange::INetworkControl::ModeType::STATIC, _TXT("Static") },
    { Exchange::INetworkControl::ModeType::DYNAMIC, _TXT("Dynamic") },
ENUM_CONVERSION_END(Exchange::INetworkControl::ModeType)

}
