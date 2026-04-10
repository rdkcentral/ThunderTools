// Enumeration code for SimpleAsync API.
// Generated automatically from 'ISimpleAsync.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <example_interfaces/ISimpleAsync.h>
#include "JsonData_SimpleAsync.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Example::ISimpleAsync::state)
    { Example::ISimpleAsync::state::DISCONNECTED, _TXT("DISCONNECTED") },
    { Example::ISimpleAsync::state::CONNECTING, _TXT("CONNECTING") },
    { Example::ISimpleAsync::state::CONNECTED, _TXT("CONNECTED") },
    { Example::ISimpleAsync::state::CONNECTING_FAILED, _TXT("CONNECTING_FAILED") },
    { Example::ISimpleAsync::state::CONNECTING_TIMED_OUT, _TXT("CONNECTING_TIMED_OUT") },
    { Example::ISimpleAsync::state::CONNECTING_ABORTED, _TXT("CONNECTING_ABORTED") },
ENUM_CONVERSION_END(Example::ISimpleAsync::state)

}
