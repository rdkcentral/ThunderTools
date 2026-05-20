// Enumeration code for Display Info API JSON-RPC API.
// Generated automatically from 'DisplayInfo.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_DisplayInfo.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::DisplayInfo::DisplayinfoData::HdcpprotectionType)
    { JsonData::DisplayInfo::DisplayinfoData::HdcpprotectionType::UNENCRYPTED, _TXT("Unencrypted") },
    { JsonData::DisplayInfo::DisplayinfoData::HdcpprotectionType::HDCP1X, _TXT("HDCP1x") },
    { JsonData::DisplayInfo::DisplayinfoData::HdcpprotectionType::HDCP2X, _TXT("HDCP2x") },
ENUM_CONVERSION_END(JsonData::DisplayInfo::DisplayinfoData::HdcpprotectionType)

ENUM_CONVERSION_BEGIN(JsonData::DisplayInfo::DisplayinfoData::HdrtypeType)
    { JsonData::DisplayInfo::DisplayinfoData::HdrtypeType::HDROFF, _TXT("HDROff") },
    { JsonData::DisplayInfo::DisplayinfoData::HdrtypeType::HDR10, _TXT("HDR10") },
    { JsonData::DisplayInfo::DisplayinfoData::HdrtypeType::HDR10PLUS, _TXT("HDR10Plus") },
    { JsonData::DisplayInfo::DisplayinfoData::HdrtypeType::HDRDOLBYVISION, _TXT("HDRDolbyVision") },
    { JsonData::DisplayInfo::DisplayinfoData::HdrtypeType::HDRTECHNICOLOR, _TXT("HDRTechnicolor") },
ENUM_CONVERSION_END(JsonData::DisplayInfo::DisplayinfoData::HdrtypeType)

}
