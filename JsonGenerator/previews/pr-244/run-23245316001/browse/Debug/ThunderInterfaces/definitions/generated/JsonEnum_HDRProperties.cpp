// Enumeration code for HDRProperties API.
// Generated automatically from 'IDisplayInfo.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IDisplayInfo.h>
#include "JsonData_HDRProperties.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IHDRProperties::HDRType)
    { Exchange::IHDRProperties::HDRType::HDR_OFF, _TXT("HdrOff") },
    { Exchange::IHDRProperties::HDRType::HDR_10, _TXT("Hdr10") },
    { Exchange::IHDRProperties::HDRType::HDR_10PLUS, _TXT("Hdr10plus") },
    { Exchange::IHDRProperties::HDRType::HDR_HLG, _TXT("HdrHlg") },
    { Exchange::IHDRProperties::HDRType::HDR_DOLBYVISION, _TXT("HdrDolbyvision") },
    { Exchange::IHDRProperties::HDRType::HDR_TECHNICOLOR, _TXT("HdrTechnicolor") },
ENUM_CONVERSION_END(Exchange::IHDRProperties::HDRType)

}
