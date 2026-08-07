// Enumeration code for DIAL Server API.
// Generated automatically from 'DIALServer.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_DIALServer.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::DIALServer::StateType)
    { JsonData::DIALServer::StateType::STOPPED, _TXT("Stopped") },
    { JsonData::DIALServer::StateType::STARTED, _TXT("Started") },
    { JsonData::DIALServer::StateType::HIDDEN, _TXT("Hidden") },
ENUM_CONVERSION_END(JsonData::DIALServer::StateType)

}
