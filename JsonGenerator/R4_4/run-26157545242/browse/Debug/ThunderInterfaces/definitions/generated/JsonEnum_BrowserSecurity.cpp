// Enumeration code for BrowserSecurity API JSON-RPC API.
// Generated automatically from 'IBrowser.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IBrowser.h>
#include "JsonData_BrowserSecurity.h"

namespace WPEFramework {

ENUM_CONVERSION_BEGIN(Exchange::IBrowserSecurity::MixedContentPolicyType)
    { Exchange::IBrowserSecurity::MixedContentPolicyType::ALLOWED, _TXT("allowed") },
    { Exchange::IBrowserSecurity::MixedContentPolicyType::BLOCKED, _TXT("blocked") },
ENUM_CONVERSION_END(Exchange::IBrowserSecurity::MixedContentPolicyType)

}
