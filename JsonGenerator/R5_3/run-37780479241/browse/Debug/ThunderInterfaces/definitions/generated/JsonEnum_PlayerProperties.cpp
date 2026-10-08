// Enumeration code for PlayerProperties API.
// Generated automatically from 'IPlayerInfo.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IPlayerInfo.h>
#include "JsonData_PlayerProperties.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IPlayerProperties::AudioCodec)
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_UNDEFINED, _TXT("AudioUndefined") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_AAC, _TXT("AudioAac") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_AC3, _TXT("AudioAc3") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_AC3_PLUS, _TXT("AudioAc3Plus") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_DTS, _TXT("AudioDts") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_MPEG1, _TXT("AudioMpeg1") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_MPEG2, _TXT("AudioMpeg2") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_MPEG3, _TXT("AudioMpeg3") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_MPEG4, _TXT("AudioMpeg4") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_OPUS, _TXT("AudioOpus") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_VORBIS_OGG, _TXT("AudioVorbisOgg") },
    { Exchange::IPlayerProperties::AudioCodec::AUDIO_WAV, _TXT("AudioWav") },
ENUM_CONVERSION_END(Exchange::IPlayerProperties::AudioCodec)

ENUM_CONVERSION_BEGIN(Exchange::IPlayerProperties::VideoCodec)
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_UNDEFINED, _TXT("VideoUndefined") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_H263, _TXT("VideoH263") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_H264, _TXT("VideoH264") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_H265, _TXT("VideoH265") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_H265_10, _TXT("VideoH26510") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_MPEG, _TXT("VideoMpeg") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_MPEG2, _TXT("VideoMpeg2") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_MPEG4, _TXT("VideoMpeg4") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_VP8, _TXT("VideoVp8") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_VP9, _TXT("VideoVp9") },
    { Exchange::IPlayerProperties::VideoCodec::VIDEO_VP10, _TXT("VideoVp10") },
ENUM_CONVERSION_END(Exchange::IPlayerProperties::VideoCodec)

ENUM_CONVERSION_BEGIN(Exchange::IPlayerProperties::PlaybackResolution)
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_UNKNOWN, _TXT("ResolutionUnknown") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480I24, _TXT("Resolution480i24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480I25, _TXT("Resolution480i25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480I30, _TXT("Resolution480i30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480I50, _TXT("Resolution480i50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480I, _TXT("Resolution480i") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480P24, _TXT("Resolution480p24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480P25, _TXT("Resolution480p25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480P30, _TXT("Resolution480p30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480P50, _TXT("Resolution480p50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_480P, _TXT("Resolution480p") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576I24, _TXT("Resolution576i24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576I25, _TXT("Resolution576i25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576I30, _TXT("Resolution576i30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576I50, _TXT("Resolution576i50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576I, _TXT("Resolution576i") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576P24, _TXT("Resolution576p24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576P25, _TXT("Resolution576p25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576P30, _TXT("Resolution576p30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576P50, _TXT("Resolution576p50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_576P, _TXT("Resolution576p") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_720P24, _TXT("Resolution720p24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_720P25, _TXT("Resolution720p25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_720P30, _TXT("Resolution720p30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_720P50, _TXT("Resolution720p50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_720P, _TXT("Resolution720p") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080I24, _TXT("Resolution1080i24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080I25, _TXT("Resolution1080i25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080I30, _TXT("Resolution1080i30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080I50, _TXT("Resolution1080i50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080I, _TXT("Resolution1080i") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080P24, _TXT("Resolution1080p24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080P25, _TXT("Resolution1080p25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080P30, _TXT("Resolution1080p30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080P50, _TXT("Resolution1080p50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_1080P, _TXT("Resolution1080p") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_2160P24, _TXT("Resolution2160p24") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_2160P25, _TXT("Resolution2160p25") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_2160P30, _TXT("Resolution2160p30") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_2160P50, _TXT("Resolution2160p50") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_2160P60, _TXT("Resolution2160p60") },
    { Exchange::IPlayerProperties::PlaybackResolution::RESOLUTION_2160P, _TXT("Resolution2160p") },
ENUM_CONVERSION_END(Exchange::IPlayerProperties::PlaybackResolution)

}
