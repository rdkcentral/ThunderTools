// Enumeration code for OpenCDMi API.
// Generated automatically from 'OCDM.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_OCDM.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::OCDM::DrminitializationstatusParamsData::StatusType)
    { JsonData::OCDM::DrminitializationstatusParamsData::StatusType::BUSY, _TXT("BUSY") },
    { JsonData::OCDM::DrminitializationstatusParamsData::StatusType::SUCCESS, _TXT("SUCCESS") },
    { JsonData::OCDM::DrminitializationstatusParamsData::StatusType::FAILED, _TXT("FAILED") },
ENUM_CONVERSION_END(JsonData::OCDM::DrminitializationstatusParamsData::StatusType)

}
