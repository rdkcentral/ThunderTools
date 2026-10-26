// Enumeration code for BluetoothControl API.
// Generated automatically from 'IBluetooth.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IBluetooth.h>
#include "JsonData_BluetoothControl.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IBluetoothControl::scantype)
    { Exchange::JSONRPC::IBluetoothControl::scantype::CLASSIC, _TXT("Classic") },
    { Exchange::JSONRPC::IBluetoothControl::scantype::LOW_ENERGY, _TXT("LowEnergy") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IBluetoothControl::scantype)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IBluetoothControl::scanmode)
    { Exchange::JSONRPC::IBluetoothControl::scanmode::GENERAL, _TXT("General") },
    { Exchange::JSONRPC::IBluetoothControl::scanmode::LIMITED, _TXT("Limited") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IBluetoothControl::scanmode)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IBluetoothControl::devicetype)
    { Exchange::JSONRPC::IBluetoothControl::devicetype::CLASSIC, _TXT("Classic") },
    { Exchange::JSONRPC::IBluetoothControl::devicetype::LOW_ENERGY, _TXT("LowEnergy") },
    { Exchange::JSONRPC::IBluetoothControl::devicetype::LOW_ENERGY_RANDOM, _TXT("LowEnergyRandom") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IBluetoothControl::devicetype)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IBluetoothControl::pairingcapabilities)
    { Exchange::JSONRPC::IBluetoothControl::pairingcapabilities::DISPLAY_ONLY, _TXT("DisplayOnly") },
    { Exchange::JSONRPC::IBluetoothControl::pairingcapabilities::DISPLAY_YES_NO, _TXT("DisplayYesNo") },
    { Exchange::JSONRPC::IBluetoothControl::pairingcapabilities::KEYBOARD_ONLY, _TXT("KeyboardOnly") },
    { Exchange::JSONRPC::IBluetoothControl::pairingcapabilities::NO_INPUT_NO_OUTPUT, _TXT("NoInputNoOutput") },
    { Exchange::JSONRPC::IBluetoothControl::pairingcapabilities::KEYBOARD_DISPLAY, _TXT("KeyboardDisplay") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IBluetoothControl::pairingcapabilities)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IBluetoothControl::adaptertype)
    { Exchange::JSONRPC::IBluetoothControl::adaptertype::CLASSIC, _TXT("Classic") },
    { Exchange::JSONRPC::IBluetoothControl::adaptertype::LOW_ENERGY, _TXT("LowEnergy") },
    { Exchange::JSONRPC::IBluetoothControl::adaptertype::DUAL, _TXT("Dual") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IBluetoothControl::adaptertype)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IBluetoothControl::devicestate)
    { Exchange::JSONRPC::IBluetoothControl::devicestate::PAIRING, _TXT("Pairing") },
    { Exchange::JSONRPC::IBluetoothControl::devicestate::PAIRED, _TXT("Paired") },
    { Exchange::JSONRPC::IBluetoothControl::devicestate::UNPAIRED, _TXT("Unpaired") },
    { Exchange::JSONRPC::IBluetoothControl::devicestate::CONNECTED, _TXT("Connected") },
    { Exchange::JSONRPC::IBluetoothControl::devicestate::DISCONNECTED, _TXT("Disconnected") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IBluetoothControl::devicestate)

ENUM_CONVERSION_BEGIN(Exchange::JSONRPC::IBluetoothControl::disconnectreason)
    { Exchange::JSONRPC::IBluetoothControl::disconnectreason::CONNECTION_TIMEOUT, _TXT("ConnectionTimeout") },
    { Exchange::JSONRPC::IBluetoothControl::disconnectreason::AUTHENTICATION_FAILURE, _TXT("AuthenticationFailure") },
    { Exchange::JSONRPC::IBluetoothControl::disconnectreason::REMOTE_LOW_ON_RESOURCES, _TXT("RemoteLowOnResources") },
    { Exchange::JSONRPC::IBluetoothControl::disconnectreason::REMOTE_POWERED_OFF, _TXT("RemotePoweredOff") },
    { Exchange::JSONRPC::IBluetoothControl::disconnectreason::TERMINATED_BY_REMOTE, _TXT("TerminatedByRemote") },
    { Exchange::JSONRPC::IBluetoothControl::disconnectreason::TERMINATED_BY_HOST, _TXT("TerminatedByHost") },
ENUM_CONVERSION_END(Exchange::JSONRPC::IBluetoothControl::disconnectreason)

}
