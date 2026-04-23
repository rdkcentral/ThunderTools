// Enumeration code for Sink API.
// Generated automatically from 'IBluetoothAudio.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IBluetoothAudio.h>
#include "JsonData_BluetoothAudioSink.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudio::state)
    { Exchange::IBluetoothAudio::state::UNASSIGNED, _TXT("Unassigned") },
    { Exchange::IBluetoothAudio::state::DISCONNECTED, _TXT("Disconnected") },
    { Exchange::IBluetoothAudio::state::CONNECTING, _TXT("Connecting") },
    { Exchange::IBluetoothAudio::state::CONNECTED, _TXT("Connected") },
    { Exchange::IBluetoothAudio::state::CONNECTED_BAD, _TXT("ConnectedBad") },
    { Exchange::IBluetoothAudio::state::CONNECTED_RESTRICTED, _TXT("ConnectedRestricted") },
    { Exchange::IBluetoothAudio::state::READY, _TXT("Ready") },
    { Exchange::IBluetoothAudio::state::STREAMING, _TXT("Streaming") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudio::state)

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudio::ISink::devicetype)
    { Exchange::IBluetoothAudio::ISink::devicetype::UNKNOWN, _TXT("Unknown") },
    { Exchange::IBluetoothAudio::ISink::devicetype::HEADPHONE, _TXT("Headphone") },
    { Exchange::IBluetoothAudio::ISink::devicetype::SPEAKER, _TXT("Speaker") },
    { Exchange::IBluetoothAudio::ISink::devicetype::RECORDER, _TXT("Recorder") },
    { Exchange::IBluetoothAudio::ISink::devicetype::AMPLIFIER, _TXT("Amplifier") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudio::ISink::devicetype)

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudio::audiocodec)
    { Exchange::IBluetoothAudio::audiocodec::LC_SBC, _TXT("LC-SBC") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudio::audiocodec)

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudio::drmscheme)
    { Exchange::IBluetoothAudio::drmscheme::DTCP, _TXT("DTCP") },
    { Exchange::IBluetoothAudio::drmscheme::SCMS_T, _TXT("SCMS-T") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudio::drmscheme)

}
