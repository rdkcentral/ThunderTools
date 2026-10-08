// Enumeration code for Output API.
// Generated automatically from 'IDolby.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IDolby.h>
#include "JsonData_DolbyOutput.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::Dolby::IOutput::SoundModes)
    { Exchange::Dolby::IOutput::SoundModes::UNKNOWN, _TXT("Unknown") },
    { Exchange::Dolby::IOutput::SoundModes::MONO, _TXT("Mono") },
    { Exchange::Dolby::IOutput::SoundModes::STEREO, _TXT("Stereo") },
    { Exchange::Dolby::IOutput::SoundModes::SURROUND, _TXT("Surround") },
    { Exchange::Dolby::IOutput::SoundModes::PASSTHRU, _TXT("Passthru") },
    { Exchange::Dolby::IOutput::SoundModes::DOLBYDIGITAL, _TXT("Dolbydigital") },
    { Exchange::Dolby::IOutput::SoundModes::DOLBYDIGITALPLUS, _TXT("Dolbydigitalplus") },
    { Exchange::Dolby::IOutput::SoundModes::SOUNDMODE_AUTO, _TXT("SoundmodeAuto") },
ENUM_CONVERSION_END(Exchange::Dolby::IOutput::SoundModes)

ENUM_CONVERSION_BEGIN(Exchange::Dolby::IOutput::Type)
    { Exchange::Dolby::IOutput::Type::DIGITAL_PCM, _TXT("DigitalPcm") },
    { Exchange::Dolby::IOutput::Type::DIGITAL_PLUS, _TXT("DigitalPlus") },
    { Exchange::Dolby::IOutput::Type::DIGITAL_AC3, _TXT("DigitalAc3") },
    { Exchange::Dolby::IOutput::Type::AUTO, _TXT("Auto") },
    { Exchange::Dolby::IOutput::Type::DIGITAL_PASSTHROUGH, _TXT("DigitalPassthrough") },
    { Exchange::Dolby::IOutput::Type::MS12, _TXT("Ms12") },
ENUM_CONVERSION_END(Exchange::Dolby::IOutput::Type)

}
