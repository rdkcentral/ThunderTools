// Enumeration code for BrowserSecurity API.
// Generated automatically from 'IBrowser.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IBrowser.h>
#include "JsonData_BrowserSecurity.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IBrowserSecurity::MixedContentPolicyType)
    { Exchange::IBrowserSecurity::MixedContentPolicyType::ALLOWED, _TXT("allowed") },
    { Exchange::IBrowserSecurity::MixedContentPolicyType::BLOCKED, _TXT("blocked") },
ENUM_CONVERSION_END(Exchange::IBrowserSecurity::MixedContentPolicyType)

}
