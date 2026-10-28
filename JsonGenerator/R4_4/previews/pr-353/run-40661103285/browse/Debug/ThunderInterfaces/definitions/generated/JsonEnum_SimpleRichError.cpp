// Enumeration code for SimpleRichError API.
// Generated automatically from 'ISimpleRichError.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/ISimpleRichError.h>
#include "JsonData_SimpleRichError.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(Exchange::ISimpleRichError::coffeetype)
    { Exchange::ISimpleRichError::coffeetype::ESPRESSO, _TXT("Espresso") },
    { Exchange::ISimpleRichError::coffeetype::CAPPUCCINO, _TXT("Cappuccino") },
    { Exchange::ISimpleRichError::coffeetype::LATTE, _TXT("Latte") },
    { Exchange::ISimpleRichError::coffeetype::RISTRETTO, _TXT("Ristretto") },
ENUM_CONVERSION_END(Exchange::ISimpleRichError::coffeetype)

ENUM_CONVERSION_BEGIN(Exchange::ISimpleRichError::Diagnostic::failreason)
    { Exchange::ISimpleRichError::Diagnostic::failreason::HARDWARE_FAILURE, _TXT("HardwareFailure") },
    { Exchange::ISimpleRichError::Diagnostic::failreason::NO_WATER, _TXT("NoWater") },
    { Exchange::ISimpleRichError::Diagnostic::failreason::NO_MILK, _TXT("NoMilk") },
    { Exchange::ISimpleRichError::Diagnostic::failreason::NO_BEANS, _TXT("NoBeans") },
    { Exchange::ISimpleRichError::Diagnostic::failreason::DRIP_TRAY_FULL, _TXT("DripTrayFull") },
    { Exchange::ISimpleRichError::Diagnostic::failreason::GROUNDS_CONTAINER_FULL, _TXT("GroundsContainerFull") },
ENUM_CONVERSION_END(Exchange::ISimpleRichError::Diagnostic::failreason)

}
