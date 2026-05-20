// Enumeration code for Power API JSON-RPC API.
// Generated automatically from 'Power.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_Power.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::Power::StateType)
    { JsonData::Power::StateType::ON, _TXT("on") },
    { JsonData::Power::StateType::ACTIVESTANDBY, _TXT("activestandby") },
    { JsonData::Power::StateType::PASSIVESTANDBY, _TXT("passivestandby") },
    { JsonData::Power::StateType::SUSPENDTORAM, _TXT("suspendtoram") },
    { JsonData::Power::StateType::HIBERNATE, _TXT("hibernate") },
    { JsonData::Power::StateType::POWEROFF, _TXT("poweroff") },
ENUM_CONVERSION_END(JsonData::Power::StateType)

}
