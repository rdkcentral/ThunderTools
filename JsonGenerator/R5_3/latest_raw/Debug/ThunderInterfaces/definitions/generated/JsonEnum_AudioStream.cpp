// Enumeration code for AudioStream API.
// Generated automatically from 'IAudioStream.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IAudioStream.h>
#include "JsonData_AudioStream.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IAudioStream::streamstate)
    { Exchange::IAudioStream::streamstate::UNAVAILABLE, _TXT("Unavailable") },
    { Exchange::IAudioStream::streamstate::IDLE, _TXT("Idle") },
    { Exchange::IAudioStream::streamstate::STARTED, _TXT("Started") },
ENUM_CONVERSION_END(Exchange::IAudioStream::streamstate)

ENUM_CONVERSION_BEGIN(Exchange::IAudioStream::codectype)
    { Exchange::IAudioStream::codectype::PCM, _TXT("PCM") },
    { Exchange::IAudioStream::codectype::IMA_ADPCM, _TXT("IMA-ADPCM") },
    { Exchange::IAudioStream::codectype::_, _TXT("") },
    { Exchange::IAudioStream::codectype::ADPCM, _TXT("Adpcm") },
ENUM_CONVERSION_END(Exchange::IAudioStream::codectype)

}
