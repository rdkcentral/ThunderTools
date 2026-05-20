// Enumeration code for Player Info API JSON-RPC API.
// Generated automatically from 'PlayerInfo.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_PlayerInfo.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::PlayerInfo::CodecsData::AudiocodecsType)
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::UNDEFINED, _TXT("Undefined") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::AAC, _TXT("AAC") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::AC3, _TXT("AC3") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::AC3PLUS, _TXT("AC3Plus") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::DTS, _TXT("DTS") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::MPEG1, _TXT("MPEG1") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::MPEG2, _TXT("MPEG2") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::MPEG3, _TXT("MPEG3") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::MPEG4, _TXT("MPEG4") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::OPUS, _TXT("OPUS") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::VORBISOGG, _TXT("VorbisOGG") },
    { JsonData::PlayerInfo::CodecsData::AudiocodecsType::WAV, _TXT("WAV") },
ENUM_CONVERSION_END(JsonData::PlayerInfo::CodecsData::AudiocodecsType)

ENUM_CONVERSION_BEGIN(JsonData::PlayerInfo::CodecsData::VideocodecsType)
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::UNDEFINED, _TXT("Undefined") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::H263, _TXT("H263") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::H264, _TXT("H264") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::H265, _TXT("H265") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::H26510, _TXT("H26510") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::MPEG, _TXT("MPEG") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::VP8, _TXT("VP8") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::VP9, _TXT("VP9") },
    { JsonData::PlayerInfo::CodecsData::VideocodecsType::VP10, _TXT("VP10") },
ENUM_CONVERSION_END(JsonData::PlayerInfo::CodecsData::VideocodecsType)

ENUM_CONVERSION_BEGIN(JsonData::PlayerInfo::DolbymodeData::DolbyType)
    { JsonData::PlayerInfo::DolbymodeData::DolbyType::DIGITAL_PCM, _TXT("DIGITAL_PCM") },
    { JsonData::PlayerInfo::DolbymodeData::DolbyType::DIGITAL_PLUS, _TXT("DIGITAL_PLUS") },
    { JsonData::PlayerInfo::DolbymodeData::DolbyType::DIGITAL_AC3, _TXT("DIGITAL_AC3") },
    { JsonData::PlayerInfo::DolbymodeData::DolbyType::AUTO, _TXT("AUTO") },
ENUM_CONVERSION_END(JsonData::PlayerInfo::DolbymodeData::DolbyType)

}
