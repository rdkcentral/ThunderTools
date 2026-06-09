// Enumeration code for WifiControl API.
// Generated automatically from 'IWifiControl.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IWifiControl.h>
#include "JsonData_WifiControl.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IWifiControl::Security)
    { Exchange::IWifiControl::Security::OPEN, _TXT("Open") },
    { Exchange::IWifiControl::Security::WEP, _TXT("WEP") },
    { Exchange::IWifiControl::Security::WPA, _TXT("WPA") },
    { Exchange::IWifiControl::Security::WPA2, _TXT("WPA2") },
    { Exchange::IWifiControl::Security::WPS, _TXT("WPS") },
    { Exchange::IWifiControl::Security::ENTERPRISE, _TXT("Enterprise") },
    { Exchange::IWifiControl::Security::WPA_WPA2, _TXT("WPA_WPA2") },
    { Exchange::IWifiControl::Security::UNKNOWN, _TXT("Unknown") },
ENUM_CONVERSION_END(Exchange::IWifiControl::Security)

ENUM_CONVERSION_BEGIN(Exchange::IWifiControl::SecurityInfo::Key)
    { Exchange::IWifiControl::SecurityInfo::Key::PSK, _TXT("PSK") },
    { Exchange::IWifiControl::SecurityInfo::Key::EAP, _TXT("EAP") },
    { Exchange::IWifiControl::SecurityInfo::Key::CCMP, _TXT("CCMP") },
    { Exchange::IWifiControl::SecurityInfo::Key::TKIP, _TXT("TKIP") },
    { Exchange::IWifiControl::SecurityInfo::Key::PREAUTH, _TXT("Preauth") },
    { Exchange::IWifiControl::SecurityInfo::Key::PBC, _TXT("PBC") },
    { Exchange::IWifiControl::SecurityInfo::Key::PIN, _TXT("PIN") },
    { Exchange::IWifiControl::SecurityInfo::Key::PSK_HASHED, _TXT("PSK_HASHED") },
    { Exchange::IWifiControl::SecurityInfo::Key::NONE, _TXT("None") },
ENUM_CONVERSION_END(Exchange::IWifiControl::SecurityInfo::Key)

}
