// Enumeration code for Compositor API.
// Generated automatically from 'Compositor.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_Compositor.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::Compositor::ResolutionType)
    { JsonData::Compositor::ResolutionType::UNKNOWN, _TXT("unknown") },
    { JsonData::Compositor::ResolutionType::E480I, _TXT("480i") },
    { JsonData::Compositor::ResolutionType::E480P, _TXT("480p") },
    { JsonData::Compositor::ResolutionType::E720P50, _TXT("720p50") },
    { JsonData::Compositor::ResolutionType::E720P60, _TXT("720p60") },
    { JsonData::Compositor::ResolutionType::E1080P24, _TXT("1080p24") },
    { JsonData::Compositor::ResolutionType::E1080I50, _TXT("1080i50") },
    { JsonData::Compositor::ResolutionType::E1080P50, _TXT("1080p50") },
    { JsonData::Compositor::ResolutionType::E1080P60, _TXT("1080p60") },
    { JsonData::Compositor::ResolutionType::E2160P50, _TXT("2160p50") },
    { JsonData::Compositor::ResolutionType::E2160P60, _TXT("2160p60") },
ENUM_CONVERSION_END(JsonData::Compositor::ResolutionType)

ENUM_CONVERSION_BEGIN(JsonData::Compositor::BrightnessType)
    { JsonData::Compositor::BrightnessType::DEFAULT, _TXT("default") },
    { JsonData::Compositor::BrightnessType::MATCH_VIDEO, _TXT("match_video") },
    { JsonData::Compositor::BrightnessType::MAX, _TXT("max") },
ENUM_CONVERSION_END(JsonData::Compositor::BrightnessType)

ENUM_CONVERSION_BEGIN(JsonData::Compositor::VisiblityType)
    { JsonData::Compositor::VisiblityType::VISIBLE, _TXT("visible") },
    { JsonData::Compositor::VisiblityType::HIDDEN, _TXT("hidden") },
ENUM_CONVERSION_END(JsonData::Compositor::VisiblityType)

}
