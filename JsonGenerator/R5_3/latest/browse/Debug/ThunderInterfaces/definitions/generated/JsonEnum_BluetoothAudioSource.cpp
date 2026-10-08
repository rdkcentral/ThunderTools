// Enumeration code for Source API.
// Generated automatically from 'IBluetoothAudio.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IBluetoothAudio.h>
#include "JsonData_BluetoothAudioSource.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudio::ISource::devicetype)
    { Exchange::IBluetoothAudio::ISource::devicetype::UNKNOWN, _TXT("Unknown") },
    { Exchange::IBluetoothAudio::ISource::devicetype::PLAYER, _TXT("Player") },
    { Exchange::IBluetoothAudio::ISource::devicetype::MICROPHONE, _TXT("Microphone") },
    { Exchange::IBluetoothAudio::ISource::devicetype::TUNER, _TXT("Tuner") },
    { Exchange::IBluetoothAudio::ISource::devicetype::MIXER, _TXT("Mixer") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudio::ISource::devicetype)

}
