// Enumeration code for DTV API.
// Generated automatically from 'DTV.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_DTV.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(JsonData::DTV::LnbtypeType)
    { JsonData::DTV::LnbtypeType::SINGLE, _TXT("single") },
    { JsonData::DTV::LnbtypeType::UNIVERSAL, _TXT("universal") },
    { JsonData::DTV::LnbtypeType::UNICABLE, _TXT("unicable") },
ENUM_CONVERSION_END(JsonData::DTV::LnbtypeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::LnbpowerType)
    { JsonData::DTV::LnbpowerType::OFF, _TXT("off") },
    { JsonData::DTV::LnbpowerType::ON, _TXT("on") },
    { JsonData::DTV::LnbpowerType::AUTO, _TXT("auto") },
ENUM_CONVERSION_END(JsonData::DTV::LnbpowerType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::Diseqc_toneType)
    { JsonData::DTV::Diseqc_toneType::OFF, _TXT("off") },
    { JsonData::DTV::Diseqc_toneType::A, _TXT("a") },
    { JsonData::DTV::Diseqc_toneType::B, _TXT("b") },
ENUM_CONVERSION_END(JsonData::DTV::Diseqc_toneType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::Diseqc_cswitchType)
    { JsonData::DTV::Diseqc_cswitchType::OFF, _TXT("off") },
    { JsonData::DTV::Diseqc_cswitchType::A, _TXT("a") },
    { JsonData::DTV::Diseqc_cswitchType::B, _TXT("b") },
    { JsonData::DTV::Diseqc_cswitchType::C, _TXT("c") },
    { JsonData::DTV::Diseqc_cswitchType::D, _TXT("d") },
ENUM_CONVERSION_END(JsonData::DTV::Diseqc_cswitchType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::TunertypeType)
    { JsonData::DTV::TunertypeType::NONE, _TXT("none") },
    { JsonData::DTV::TunertypeType::DVBS, _TXT("dvbs") },
    { JsonData::DTV::TunertypeType::DVBT, _TXT("dvbt") },
    { JsonData::DTV::TunertypeType::DVBC, _TXT("dvbc") },
ENUM_CONVERSION_END(JsonData::DTV::TunertypeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::StartServiceSearchParamsData::SearchtypeType)
    { JsonData::DTV::StartServiceSearchParamsData::SearchtypeType::FREQUENCY, _TXT("frequency") },
    { JsonData::DTV::StartServiceSearchParamsData::SearchtypeType::NETWORK, _TXT("network") },
ENUM_CONVERSION_END(JsonData::DTV::StartServiceSearchParamsData::SearchtypeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::PolarityType)
    { JsonData::DTV::PolarityType::HORIZONTAL, _TXT("horizontal") },
    { JsonData::DTV::PolarityType::VERTICAL, _TXT("vertical") },
    { JsonData::DTV::PolarityType::LEFT, _TXT("left") },
    { JsonData::DTV::PolarityType::RIGHT, _TXT("right") },
ENUM_CONVERSION_END(JsonData::DTV::PolarityType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::FecType)
    { JsonData::DTV::FecType::FECAUTO, _TXT("fecauto") },
    { JsonData::DTV::FecType::FEC1_2, _TXT("fec1_2") },
    { JsonData::DTV::FecType::FEC2_3, _TXT("fec2_3") },
    { JsonData::DTV::FecType::FEC3_4, _TXT("fec3_4") },
    { JsonData::DTV::FecType::FEC5_6, _TXT("fec5_6") },
    { JsonData::DTV::FecType::FEC7_8, _TXT("fec7_8") },
    { JsonData::DTV::FecType::FEC1_4, _TXT("fec1_4") },
    { JsonData::DTV::FecType::FEC1_3, _TXT("fec1_3") },
    { JsonData::DTV::FecType::FEC2_5, _TXT("fec2_5") },
    { JsonData::DTV::FecType::FEC8_9, _TXT("fec8_9") },
    { JsonData::DTV::FecType::FEC9_10, _TXT("fec9_10") },
    { JsonData::DTV::FecType::FEC3_5, _TXT("fec3_5") },
    { JsonData::DTV::FecType::FEC4_5, _TXT("fec4_5") },
ENUM_CONVERSION_END(JsonData::DTV::FecType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::DvbsmodulationType)
    { JsonData::DTV::DvbsmodulationType::AUTO, _TXT("auto") },
    { JsonData::DTV::DvbsmodulationType::QPSK, _TXT("qpsk") },
    { JsonData::DTV::DvbsmodulationType::E8PSK, _TXT("8psk") },
    { JsonData::DTV::DvbsmodulationType::E16QAM, _TXT("16qam") },
ENUM_CONVERSION_END(JsonData::DTV::DvbsmodulationType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::DvbcmodulationType)
    { JsonData::DTV::DvbcmodulationType::AUTO, _TXT("auto") },
    { JsonData::DTV::DvbcmodulationType::E4QAM, _TXT("4qam") },
    { JsonData::DTV::DvbcmodulationType::E8QAM, _TXT("8qam") },
    { JsonData::DTV::DvbcmodulationType::E16QAM, _TXT("16qam") },
    { JsonData::DTV::DvbcmodulationType::E32QAM, _TXT("32qam") },
    { JsonData::DTV::DvbcmodulationType::E64QAM, _TXT("64qam") },
    { JsonData::DTV::DvbcmodulationType::E128QAM, _TXT("128qam") },
    { JsonData::DTV::DvbcmodulationType::E256QAM, _TXT("256qam") },
ENUM_CONVERSION_END(JsonData::DTV::DvbcmodulationType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::DvbtbandwidthType)
    { JsonData::DTV::DvbtbandwidthType::E5MHZ, _TXT("5MHz") },
    { JsonData::DTV::DvbtbandwidthType::E6MHZ, _TXT("6MHz") },
    { JsonData::DTV::DvbtbandwidthType::E7MHZ, _TXT("7MHz") },
    { JsonData::DTV::DvbtbandwidthType::E8MHZ, _TXT("8MHz") },
    { JsonData::DTV::DvbtbandwidthType::E10MHZ, _TXT("10MHz") },
    { JsonData::DTV::DvbtbandwidthType::UNDEFINED, _TXT("undefined") },
ENUM_CONVERSION_END(JsonData::DTV::DvbtbandwidthType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::OfdmmodeType)
    { JsonData::DTV::OfdmmodeType::OFDM_1K, _TXT("ofdm_1K") },
    { JsonData::DTV::OfdmmodeType::OFDM_2K, _TXT("ofdm_2K") },
    { JsonData::DTV::OfdmmodeType::OFDM_4K, _TXT("ofdm_4K") },
    { JsonData::DTV::OfdmmodeType::OFDM_8K, _TXT("ofdm_8K") },
    { JsonData::DTV::OfdmmodeType::OFDM_16K, _TXT("ofdm_16K") },
    { JsonData::DTV::OfdmmodeType::OFDM_32K, _TXT("ofdm_32K") },
    { JsonData::DTV::OfdmmodeType::UNDEFINED, _TXT("undefined") },
ENUM_CONVERSION_END(JsonData::DTV::OfdmmodeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::ServicetypeType)
    { JsonData::DTV::ServicetypeType::TV, _TXT("tv") },
    { JsonData::DTV::ServicetypeType::RADIO, _TXT("radio") },
    { JsonData::DTV::ServicetypeType::TELETEXT, _TXT("teletext") },
    { JsonData::DTV::ServicetypeType::NVOD, _TXT("nvod") },
    { JsonData::DTV::ServicetypeType::NVOD_TIMESHIFT, _TXT("nvod_timeshift") },
    { JsonData::DTV::ServicetypeType::MOSAIC, _TXT("mosaic") },
    { JsonData::DTV::ServicetypeType::AVC_RADIO, _TXT("avc_radio") },
    { JsonData::DTV::ServicetypeType::AVC_MOSAIC, _TXT("avc_mosaic") },
    { JsonData::DTV::ServicetypeType::DATA, _TXT("data") },
    { JsonData::DTV::ServicetypeType::MPEG2_HD, _TXT("mpeg2_hd") },
    { JsonData::DTV::ServicetypeType::AVC_SD_TV, _TXT("avc_sd_tv") },
    { JsonData::DTV::ServicetypeType::AVC_SD_NVOD_TIMESHIFT, _TXT("avc_sd_nvod_timeshift") },
    { JsonData::DTV::ServicetypeType::AVC_SD_NVOD, _TXT("avc_sd_nvod") },
    { JsonData::DTV::ServicetypeType::HD_TV, _TXT("hd_tv") },
    { JsonData::DTV::ServicetypeType::AVC_HD_NVOD_TIMESHIFT, _TXT("avc_hd_nvod_timeshift") },
    { JsonData::DTV::ServicetypeType::AVC_HD_NVOD, _TXT("avc_hd_nvod") },
    { JsonData::DTV::ServicetypeType::UHD_TV, _TXT("uhd_tv") },
    { JsonData::DTV::ServicetypeType::UNKNOWN, _TXT("unknown") },
ENUM_CONVERSION_END(JsonData::DTV::ServicetypeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::RunningstatusType)
    { JsonData::DTV::RunningstatusType::UNDEFINED, _TXT("undefined") },
    { JsonData::DTV::RunningstatusType::NOTRUNNING, _TXT("notrunning") },
    { JsonData::DTV::RunningstatusType::STARTSSOON, _TXT("startssoon") },
    { JsonData::DTV::RunningstatusType::PAUSING, _TXT("pausing") },
    { JsonData::DTV::RunningstatusType::RUNNING, _TXT("running") },
    { JsonData::DTV::RunningstatusType::OFFAIR, _TXT("offair") },
ENUM_CONVERSION_END(JsonData::DTV::RunningstatusType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::ComponentData::TypeType)
    { JsonData::DTV::ComponentData::TypeType::VIDEO, _TXT("video") },
    { JsonData::DTV::ComponentData::TypeType::AUDIO, _TXT("audio") },
    { JsonData::DTV::ComponentData::TypeType::SUBTITLES, _TXT("subtitles") },
    { JsonData::DTV::ComponentData::TypeType::TELETEXT, _TXT("teletext") },
    { JsonData::DTV::ComponentData::TypeType::DATA, _TXT("data") },
ENUM_CONVERSION_END(JsonData::DTV::ComponentData::TypeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::CodecType)
    { JsonData::DTV::CodecType::MPEG2, _TXT("mpeg2") },
    { JsonData::DTV::CodecType::H264, _TXT("h264") },
    { JsonData::DTV::CodecType::H265, _TXT("h265") },
    { JsonData::DTV::CodecType::AVS, _TXT("avs") },
    { JsonData::DTV::CodecType::MPEG1, _TXT("mpeg1") },
    { JsonData::DTV::CodecType::AAC, _TXT("aac") },
    { JsonData::DTV::CodecType::HEAAC, _TXT("heaac") },
    { JsonData::DTV::CodecType::HEAACV2, _TXT("heaacv2") },
    { JsonData::DTV::CodecType::AC3, _TXT("ac3") },
    { JsonData::DTV::CodecType::EAC3, _TXT("eac3") },
ENUM_CONVERSION_END(JsonData::DTV::CodecType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::ComponentData::AudioData::TypeType)
    { JsonData::DTV::ComponentData::AudioData::TypeType::UNDEFINED, _TXT("undefined") },
    { JsonData::DTV::ComponentData::AudioData::TypeType::CLEAN, _TXT("clean") },
    { JsonData::DTV::ComponentData::AudioData::TypeType::HEARINGIMPAIRED, _TXT("hearingimpaired") },
    { JsonData::DTV::ComponentData::AudioData::TypeType::VISUALLYIMPAIRED, _TXT("visuallyimpaired") },
    { JsonData::DTV::ComponentData::AudioData::TypeType::UNKNOWN, _TXT("unknown") },
ENUM_CONVERSION_END(JsonData::DTV::ComponentData::AudioData::TypeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::ComponentData::AudioData::ModeType)
    { JsonData::DTV::ComponentData::AudioData::ModeType::MONO, _TXT("mono") },
    { JsonData::DTV::ComponentData::AudioData::ModeType::LEFT, _TXT("left") },
    { JsonData::DTV::ComponentData::AudioData::ModeType::RIGHT, _TXT("right") },
    { JsonData::DTV::ComponentData::AudioData::ModeType::STEREO, _TXT("stereo") },
    { JsonData::DTV::ComponentData::AudioData::ModeType::MULTICHANNEL, _TXT("multichannel") },
    { JsonData::DTV::ComponentData::AudioData::ModeType::UNDEFINED, _TXT("undefined") },
ENUM_CONVERSION_END(JsonData::DTV::ComponentData::AudioData::ModeType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::ComponentData::SubtitlesData::FormatType)
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::DEFAULT, _TXT("default") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::E4_3, _TXT("4_3") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::E16_9, _TXT("16_9") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::E221_1, _TXT("221_1") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::HD, _TXT("hd") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::HARDOFHEARING, _TXT("hardofhearing") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::HARDOFHEARING4_3, _TXT("hardofhearing4_3") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::HARDOFHEARING16_9, _TXT("hardofhearing16_9") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::HARDOFHEARING221_1, _TXT("hardofhearing221_1") },
    { JsonData::DTV::ComponentData::SubtitlesData::FormatType::HARDOFHEARINGHD, _TXT("hardofhearinghd") },
ENUM_CONVERSION_END(JsonData::DTV::ComponentData::SubtitlesData::FormatType)

ENUM_CONVERSION_BEGIN(JsonData::DTV::EventtypeType)
    { JsonData::DTV::EventtypeType::SERVICESEARCHSTATUS, _TXT("ServiceSearchStatus") },
    { JsonData::DTV::EventtypeType::SERVICEUPDATED, _TXT("serviceupdated") },
    { JsonData::DTV::EventtypeType::SERVICEADDED, _TXT("serviceadded") },
    { JsonData::DTV::EventtypeType::SERVICEDELETED, _TXT("servicedeleted") },
    { JsonData::DTV::EventtypeType::VIDEOCHANGED, _TXT("videochanged") },
    { JsonData::DTV::EventtypeType::AUDIOCHANGED, _TXT("audiochanged") },
    { JsonData::DTV::EventtypeType::SUBTITLESCHANGED, _TXT("subtitleschanged") },
    { JsonData::DTV::EventtypeType::EVENTCHANGED, _TXT("eventchanged") },
ENUM_CONVERSION_END(JsonData::DTV::EventtypeType)

}
