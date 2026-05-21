// Enumeration code for Bluetooth Control API JSON-RPC API.
// Generated automatically from 'BluetoothControl.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_BluetoothControl.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::BluetoothControl::scantype)
    { JsonData::BluetoothControl::scantype::CLASSIC, _TXT("Classic") },
    { JsonData::BluetoothControl::scantype::LOW_ENERGY, _TXT("LowEnergy") },
ENUM_CONVERSION_END(JsonData::BluetoothControl::scantype)

ENUM_CONVERSION_BEGIN(JsonData::BluetoothControl::scanmode)
    { JsonData::BluetoothControl::scanmode::GENERAL, _TXT("General") },
    { JsonData::BluetoothControl::scanmode::LIMITED, _TXT("Limited") },
ENUM_CONVERSION_END(JsonData::BluetoothControl::scanmode)

ENUM_CONVERSION_BEGIN(Exchange::IBluetooth::IDevice::type)
    { Exchange::IBluetooth::IDevice::type::ADDRESS_BREDR, _TXT("Classic") },
    { Exchange::IBluetooth::IDevice::type::ADDRESS_LE_PUBLIC, _TXT("LowEnergy") },
    { Exchange::IBluetooth::IDevice::type::ADDRESS_LE_RANDOM, _TXT("LowEnergyRandom") },
ENUM_CONVERSION_END(Exchange::IBluetooth::IDevice::type)

ENUM_CONVERSION_BEGIN(Exchange::IBluetooth::IDevice::pairingcapabilities)
    { Exchange::IBluetooth::IDevice::pairingcapabilities::DISPLAY_ONLY, _TXT("DisplayOnly") },
    { Exchange::IBluetooth::IDevice::pairingcapabilities::DISPLAY_YES_NO, _TXT("DisplayYesNo") },
    { Exchange::IBluetooth::IDevice::pairingcapabilities::KEYBOARD_ONLY, _TXT("KeyboardOnly") },
    { Exchange::IBluetooth::IDevice::pairingcapabilities::NO_INPUT_NO_OUTPUT, _TXT("NoInputNoOutput") },
    { Exchange::IBluetooth::IDevice::pairingcapabilities::KEYBOARD_DISPLAY, _TXT("KeyboardDisplay") },
ENUM_CONVERSION_END(Exchange::IBluetooth::IDevice::pairingcapabilities)

ENUM_CONVERSION_BEGIN(JsonData::BluetoothControl::AdapterData::adaptertype)
    { JsonData::BluetoothControl::AdapterData::adaptertype::CLASSIC, _TXT("Classic") },
    { JsonData::BluetoothControl::AdapterData::adaptertype::LOW_ENERGY, _TXT("LowEnergy") },
    { JsonData::BluetoothControl::AdapterData::adaptertype::DUAL, _TXT("Dual") },
ENUM_CONVERSION_END(JsonData::BluetoothControl::AdapterData::adaptertype)

ENUM_CONVERSION_BEGIN(JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate)
    { JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate::PAIRING, _TXT("Pairing") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate::PAIRED, _TXT("Paired") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate::UNPAIRED, _TXT("Unpaired") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate::CONNECTED, _TXT("Connected") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate::DISCONNECTED, _TXT("Disconnected") },
ENUM_CONVERSION_END(JsonData::BluetoothControl::DevicestatechangeParamsData::devicestate)

ENUM_CONVERSION_BEGIN(JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason)
    { JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason::CONNECTION_TIMEOUT, _TXT("ConnectionTimeout") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason::AUTHENTICATION_FAILURE, _TXT("AuthenticationFailure") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason::REMOTE_LOW_ON_RESOURCES, _TXT("RemoteLowOnResources") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason::REMOTE_POWERED_OFF, _TXT("RemotePoweredOff") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason::TERMINATED_BY_REMOTE, _TXT("TerminatedByRemote") },
    { JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason::TERMINATED_BY_HOST, _TXT("TerminatedByHost") },
ENUM_CONVERSION_END(JsonData::BluetoothControl::DevicestatechangeParamsData::disconnectreason)

}
