// Enumeration code for SimpleInstanceObjects API.
// Generated automatically from 'ISimpleInstanceObjects.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <example_interfaces/ISimpleInstanceObjects.h>
#include "JsonData_SimpleInstanceObjects.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Example::ISimpleInstanceObjects::state)
    { Example::ISimpleInstanceObjects::state::ENABLED, _TXT("ENABLED") },
    { Example::ISimpleInstanceObjects::state::DISABLED, _TXT("DISABLED") },
ENUM_CONVERSION_END(Example::ISimpleInstanceObjects::state)

}
