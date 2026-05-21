// Enumeration code for Butler API JSON-RPC API.
// Generated automatically from 'Butler.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_Butler.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::Butler::BasicenumType)
    { JsonData::Butler::BasicenumType::CONTROL, _TXT("control") },
    { JsonData::Butler::BasicenumType::MEASURE, _TXT("measure") },
    { JsonData::Butler::BasicenumType::GROUP, _TXT("group") },
    { JsonData::Butler::BasicenumType::IDENTIFICATION, _TXT("identification") },
ENUM_CONVERSION_END(JsonData::Butler::BasicenumType)

ENUM_CONVERSION_BEGIN(JsonData::Butler::SpecificenumType)
    { JsonData::Butler::SpecificenumType::GENERAL, _TXT("general") },
    { JsonData::Butler::SpecificenumType::ELECTRICITY, _TXT("electricity") },
    { JsonData::Butler::SpecificenumType::WATER, _TXT("water") },
    { JsonData::Butler::SpecificenumType::GAS, _TXT("gas") },
    { JsonData::Butler::SpecificenumType::AIR, _TXT("air") },
    { JsonData::Butler::SpecificenumType::SMOKE, _TXT("smoke") },
    { JsonData::Butler::SpecificenumType::CARBONMONOXIDE, _TXT("carbonMonoxide") },
    { JsonData::Butler::SpecificenumType::CARBONDIOXIDE, _TXT("carbonDioxide") },
    { JsonData::Butler::SpecificenumType::TEMPERATURE, _TXT("temperature") },
    { JsonData::Butler::SpecificenumType::ACCESSCONTROL, _TXT("accessControl") },
    { JsonData::Butler::SpecificenumType::BURGLAR, _TXT("burglar") },
    { JsonData::Butler::SpecificenumType::POWERMANAGEMENT, _TXT("powerManagement") },
    { JsonData::Butler::SpecificenumType::SYSTEM, _TXT("system") },
    { JsonData::Butler::SpecificenumType::EMERGENCY, _TXT("emergency") },
    { JsonData::Butler::SpecificenumType::CLOCK, _TXT("clock") },
    { JsonData::Butler::SpecificenumType::LIGHT, _TXT("light") },
ENUM_CONVERSION_END(JsonData::Butler::SpecificenumType)

ENUM_CONVERSION_BEGIN(JsonData::Butler::DimensionenumType)
    { JsonData::Butler::DimensionenumType::LOGIC, _TXT("logic") },
    { JsonData::Butler::DimensionenumType::PERCENTAGE, _TXT("percentage") },
    { JsonData::Butler::DimensionenumType::KWH, _TXT("kwh") },
    { JsonData::Butler::DimensionenumType::KVAH, _TXT("kvah") },
    { JsonData::Butler::DimensionenumType::PULSES, _TXT("pulses") },
    { JsonData::Butler::DimensionenumType::DEGREES, _TXT("degrees") },
    { JsonData::Butler::DimensionenumType::UNITS, _TXT("units") },
ENUM_CONVERSION_END(JsonData::Butler::DimensionenumType)

}
