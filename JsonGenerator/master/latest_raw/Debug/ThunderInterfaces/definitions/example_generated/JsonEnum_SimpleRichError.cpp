// Enumeration code for SimpleRichError API.
// Generated automatically from 'ISimpleRichError.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <example_interfaces/ISimpleRichError.h>
#include "JsonData_SimpleRichError.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Example::ISimpleRichError::coffeetype)
    { Example::ISimpleRichError::coffeetype::ESPRESSO, _TXT("ESPRESSO") },
    { Example::ISimpleRichError::coffeetype::CAPPUCCINO, _TXT("CAPPUCCINO") },
    { Example::ISimpleRichError::coffeetype::LATTE, _TXT("LATTE") },
    { Example::ISimpleRichError::coffeetype::RISTRETTO, _TXT("RISTRETTO") },
ENUM_CONVERSION_END(Example::ISimpleRichError::coffeetype)

ENUM_CONVERSION_BEGIN(Example::ISimpleRichError::Diagnostic::failreason)
    { Example::ISimpleRichError::Diagnostic::failreason::HARDWARE_FAILURE, _TXT("HARDWARE_FAILURE") },
    { Example::ISimpleRichError::Diagnostic::failreason::NO_WATER, _TXT("NO_WATER") },
    { Example::ISimpleRichError::Diagnostic::failreason::NO_MILK, _TXT("NO_MILK") },
    { Example::ISimpleRichError::Diagnostic::failreason::NO_BEANS, _TXT("NO_BEANS") },
    { Example::ISimpleRichError::Diagnostic::failreason::DRIP_TRAY_FULL, _TXT("DRIP_TRAY_FULL") },
    { Example::ISimpleRichError::Diagnostic::failreason::GROUNDS_CONTAINER_FULL, _TXT("GROUNDS_CONTAINER_FULL") },
ENUM_CONVERSION_END(Example::ISimpleRichError::Diagnostic::failreason)

}
