// Enumeration code for ConnectionProperties API.
// Generated automatically from 'IDisplayInfo.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IDisplayInfo.h>
#include "JsonData_ConnectionProperties.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IConnectionProperties::HDCPProtectionType)
    { Exchange::IConnectionProperties::HDCPProtectionType::HDCP_Unencrypted, _TXT("HdcpUnencrypted") },
    { Exchange::IConnectionProperties::HDCPProtectionType::HDCP_1X, _TXT("Hdcp1x") },
    { Exchange::IConnectionProperties::HDCPProtectionType::HDCP_2X, _TXT("Hdcp2x") },
    { Exchange::IConnectionProperties::HDCPProtectionType::HDCP_AUTO, _TXT("HdcpAuto") },
ENUM_CONVERSION_END(Exchange::IConnectionProperties::HDCPProtectionType)

ENUM_CONVERSION_BEGIN(Exchange::IConnectionProperties::INotification::Source)
    { Exchange::IConnectionProperties::INotification::Source::PRE_RESOLUTION_CHANGE, _TXT("PreResolutionChange") },
    { Exchange::IConnectionProperties::INotification::Source::POST_RESOLUTION_CHANGE, _TXT("PostResolutionChange") },
    { Exchange::IConnectionProperties::INotification::Source::HDMI_CHANGE, _TXT("HdmiChange") },
    { Exchange::IConnectionProperties::INotification::Source::HDCP_CHANGE, _TXT("HdcpChange") },
ENUM_CONVERSION_END(Exchange::IConnectionProperties::INotification::Source)

}
