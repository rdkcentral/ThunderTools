// Enumeration code for USBHub API.
// Generated automatically from 'IUSBHub.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IUSBHub.h>
#include "JsonData_USBHub.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IUSBHub::Status)
    { Exchange::IUSBHub::Status::STATUS_ACTIVE, _TXT("STATUS_ACTIVE") },
    { Exchange::IUSBHub::Status::STATUS_NO_DEVICE_CONNECTED, _TXT("STATUS_NO_DEVICE_CONNECTED") },
    { Exchange::IUSBHub::Status::STATUS_SELF_POWERED, _TXT("STATUS_SELF_POWERED") },
ENUM_CONVERSION_END(Exchange::IUSBHub::Status)

ENUM_CONVERSION_BEGIN(Exchange::IUSBHub::Speed)
    { Exchange::IUSBHub::Speed::SPEED_LOW, _TXT("SPEED_LOW") },
    { Exchange::IUSBHub::Speed::SPEED_FULL, _TXT("SPEED_FULL") },
    { Exchange::IUSBHub::Speed::SPEED_HIGH, _TXT("SPEED_HIGH") },
    { Exchange::IUSBHub::Speed::SPEED_SUPER, _TXT("SPEED_SUPER") },
ENUM_CONVERSION_END(Exchange::IUSBHub::Speed)

ENUM_CONVERSION_BEGIN(Exchange::IUSBHub::Flags)
    { Exchange::IUSBHub::Flags::FLAGS_AVAILABLE, _TXT("FLAGS_AVAILABLE") },
    { Exchange::IUSBHub::Flags::FLAGS_SWITCHABLE, _TXT("FLAGS_SWITCHABLE") },
ENUM_CONVERSION_END(Exchange::IUSBHub::Flags)

}
