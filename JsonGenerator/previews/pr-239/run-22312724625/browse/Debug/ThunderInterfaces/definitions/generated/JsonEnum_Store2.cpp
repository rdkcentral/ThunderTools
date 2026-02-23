// Enumeration code for Store2 API.
// Generated automatically from 'IStore2.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IStore2.h>
#include "JsonData_Store2.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IStore2::ScopeType)
    { Exchange::IStore2::ScopeType::DEVICE, _TXT("device") },
    { Exchange::IStore2::ScopeType::ACCOUNT, _TXT("account") },
ENUM_CONVERSION_END(Exchange::IStore2::ScopeType)

}
