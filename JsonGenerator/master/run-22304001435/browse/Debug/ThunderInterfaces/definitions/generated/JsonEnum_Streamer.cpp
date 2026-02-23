// Enumeration code for Streamer API.
// Generated automatically from 'Streamer.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_Streamer.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::Streamer::StreamType)
    { JsonData::Streamer::StreamType::UNDEFINED, _TXT("undefined") },
    { JsonData::Streamer::StreamType::CABLE, _TXT("cable") },
    { JsonData::Streamer::StreamType::HANDHELD, _TXT("handheld") },
    { JsonData::Streamer::StreamType::SATELLITE, _TXT("satellite") },
    { JsonData::Streamer::StreamType::TERRESTRIAL, _TXT("terrestrial") },
    { JsonData::Streamer::StreamType::DAB, _TXT("dab") },
    { JsonData::Streamer::StreamType::RF, _TXT("rf") },
    { JsonData::Streamer::StreamType::UNICAST, _TXT("unicast") },
    { JsonData::Streamer::StreamType::MULTICAST, _TXT("multicast") },
    { JsonData::Streamer::StreamType::IP, _TXT("ip") },
ENUM_CONVERSION_END(JsonData::Streamer::StreamType)

ENUM_CONVERSION_BEGIN(JsonData::Streamer::DrmType)
    { JsonData::Streamer::DrmType::NONE, _TXT("none") },
    { JsonData::Streamer::DrmType::CLEARKEY, _TXT("clearkey") },
    { JsonData::Streamer::DrmType::PLAYREADY, _TXT("playready") },
    { JsonData::Streamer::DrmType::WIDEVINE, _TXT("widevine") },
    { JsonData::Streamer::DrmType::UNKNOWN, _TXT("unknown") },
ENUM_CONVERSION_END(JsonData::Streamer::DrmType)

ENUM_CONVERSION_BEGIN(JsonData::Streamer::StateType)
    { JsonData::Streamer::StateType::IDLE, _TXT("idle") },
    { JsonData::Streamer::StateType::LOADING, _TXT("loading") },
    { JsonData::Streamer::StateType::PREPARED, _TXT("prepared") },
    { JsonData::Streamer::StateType::CONTROLLED, _TXT("controlled") },
    { JsonData::Streamer::StateType::ERROR, _TXT("error") },
ENUM_CONVERSION_END(JsonData::Streamer::StateType)

ENUM_CONVERSION_BEGIN(JsonData::Streamer::StreamelementData::ElementType)
    { JsonData::Streamer::StreamelementData::ElementType::VIDEO, _TXT("video") },
    { JsonData::Streamer::StreamelementData::ElementType::AUDIO, _TXT("audio") },
    { JsonData::Streamer::StreamelementData::ElementType::SUBTITLES, _TXT("subtitles") },
    { JsonData::Streamer::StreamelementData::ElementType::TELETEXT, _TXT("teletext") },
    { JsonData::Streamer::StreamelementData::ElementType::DATA, _TXT("data") },
ENUM_CONVERSION_END(JsonData::Streamer::StreamelementData::ElementType)

}
