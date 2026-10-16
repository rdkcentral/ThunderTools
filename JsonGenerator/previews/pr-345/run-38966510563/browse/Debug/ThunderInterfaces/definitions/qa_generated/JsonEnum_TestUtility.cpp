// Enumeration code for Test Utility API.
// Generated automatically from 'TestUtility.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_TestUtility.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::TestUtility::TypeType)
    { JsonData::TestUtility::TypeType::NUMBER, _TXT("Number") },
    { JsonData::TestUtility::TypeType::STRING, _TXT("String") },
    { JsonData::TestUtility::TypeType::BOOLEAN, _TXT("Boolean") },
    { JsonData::TestUtility::TypeType::OBJECT, _TXT("Object") },
    { JsonData::TestUtility::TypeType::SYMBOL, _TXT("Symbol") },
ENUM_CONVERSION_END(JsonData::TestUtility::TypeType)

}
