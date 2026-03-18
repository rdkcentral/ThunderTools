// Enumeration code for StateController API.
// Generated automatically from 'IStateController.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_StateController.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(PluginHost::IStateController::command)
    { PluginHost::IStateController::command::SUSPEND, _TXT("Suspend") },
    { PluginHost::IStateController::command::RESUME, _TXT("Resume") },
ENUM_CONVERSION_END(PluginHost::IStateController::command)

ENUM_CONVERSION_BEGIN(PluginHost::IStateController::state)
    { PluginHost::IStateController::state::UNKNOWN, _TXT("Unknown") },
    { PluginHost::IStateController::state::SUSPENDED, _TXT("Suspended") },
    { PluginHost::IStateController::state::RESUMED, _TXT("Resumed") },
ENUM_CONVERSION_END(PluginHost::IStateController::state)

}
