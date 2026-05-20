// Enumeration code for Subsystem Control API JSON-RPC API.
// Generated automatically from 'SubsystemControl.json'.

#include <core/Enumerate.h>

#include "definitions.h"
#include "JsonData_SubsystemControl.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(JsonData::SubsystemControl::SubsystemType)
    { JsonData::SubsystemControl::SubsystemType::PLATFORM, _TXT("platform") },
    { JsonData::SubsystemControl::SubsystemType::NETWORK, _TXT("network") },
    { JsonData::SubsystemControl::SubsystemType::INTERNET, _TXT("internet") },
    { JsonData::SubsystemControl::SubsystemType::TIME, _TXT("time") },
    { JsonData::SubsystemControl::SubsystemType::SECURITY, _TXT("security") },
    { JsonData::SubsystemControl::SubsystemType::LOCATION, _TXT("location") },
    { JsonData::SubsystemControl::SubsystemType::IDENTIFIER, _TXT("identifier") },
    { JsonData::SubsystemControl::SubsystemType::PROVISIONING, _TXT("provisioning") },
    { JsonData::SubsystemControl::SubsystemType::DECRYPTION, _TXT("decryption") },
    { JsonData::SubsystemControl::SubsystemType::BLUETOOTH, _TXT("bluetooth") },
    { JsonData::SubsystemControl::SubsystemType::WEBSOURCE, _TXT("websource") },
    { JsonData::SubsystemControl::SubsystemType::GRAPHICS, _TXT("graphics") },
    { JsonData::SubsystemControl::SubsystemType::STREAMING, _TXT("streaming") },
    { JsonData::SubsystemControl::SubsystemType::CRYPTOGRAPHY, _TXT("cryptography") },
    { JsonData::SubsystemControl::SubsystemType::INSTALLATION, _TXT("installation") },
ENUM_CONVERSION_END(JsonData::SubsystemControl::SubsystemType)

}
