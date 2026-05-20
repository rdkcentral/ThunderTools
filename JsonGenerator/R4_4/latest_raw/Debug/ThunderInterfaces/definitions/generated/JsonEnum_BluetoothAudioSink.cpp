// Enumeration code for BluetoothAudioSink API JSON-RPC API.
// Generated automatically from 'IBluetoothAudio.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IBluetoothAudio.h>
#include "JsonData_BluetoothAudioSink.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudioSink::state)
    { Exchange::IBluetoothAudioSink::state::UNASSIGNED, _TXT("Unassigned") },
    { Exchange::IBluetoothAudioSink::state::DISCONNECTED, _TXT("Disconnected") },
    { Exchange::IBluetoothAudioSink::state::CONNECTED_BAD_DEVICE, _TXT("ConnectedBadDevice") },
    { Exchange::IBluetoothAudioSink::state::CONNECTED_RESTRICTED, _TXT("ConnectedRestricted") },
    { Exchange::IBluetoothAudioSink::state::CONNECTED, _TXT("Connected") },
    { Exchange::IBluetoothAudioSink::state::READY, _TXT("Ready") },
    { Exchange::IBluetoothAudioSink::state::STREAMING, _TXT("Streaming") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudioSink::state)

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudioSink::devicetype)
    { Exchange::IBluetoothAudioSink::devicetype::UNKNOWN, _TXT("Unknown") },
    { Exchange::IBluetoothAudioSink::devicetype::HEADPHONE, _TXT("Headphone") },
    { Exchange::IBluetoothAudioSink::devicetype::SPEAKER, _TXT("Speaker") },
    { Exchange::IBluetoothAudioSink::devicetype::RECORDER, _TXT("Recorder") },
    { Exchange::IBluetoothAudioSink::devicetype::AMPLIFIER, _TXT("Amplifier") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudioSink::devicetype)

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudioSink::audiocodec)
    { Exchange::IBluetoothAudioSink::audiocodec::LC_SBC, _TXT("LC-SBC") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudioSink::audiocodec)

ENUM_CONVERSION_BEGIN(Exchange::IBluetoothAudioSink::drmscheme)
    { Exchange::IBluetoothAudioSink::drmscheme::NONE, _TXT("None") },
    { Exchange::IBluetoothAudioSink::drmscheme::DTCP, _TXT("DTCP") },
    { Exchange::IBluetoothAudioSink::drmscheme::SCMS_T, _TXT("SCMS-T") },
ENUM_CONVERSION_END(Exchange::IBluetoothAudioSink::drmscheme)

}
