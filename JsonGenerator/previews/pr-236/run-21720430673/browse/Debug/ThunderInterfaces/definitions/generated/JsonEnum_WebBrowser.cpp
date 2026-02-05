// Enumeration code for WebBrowser API.
// Generated automatically from 'IBrowser.h'.

#include <core/Enumerate.h>

#include "definitions.h"
#include <interfaces/IBrowser.h>
#include "JsonData_WebBrowser.h"

namespace Thunder {

ENUM_CONVERSION_BEGIN(Exchange::IWebBrowser::VisibilityType)
    { Exchange::IWebBrowser::VisibilityType::HIDDEN, _TXT("hidden") },
    { Exchange::IWebBrowser::VisibilityType::VISIBLE, _TXT("visible") },
ENUM_CONVERSION_END(Exchange::IWebBrowser::VisibilityType)

ENUM_CONVERSION_BEGIN(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)
    { Exchange::IWebBrowser::HTTPCookieAcceptPolicyType::ALWAYS, _TXT("always") },
    { Exchange::IWebBrowser::HTTPCookieAcceptPolicyType::NEVER, _TXT("never") },
    { Exchange::IWebBrowser::HTTPCookieAcceptPolicyType::ONLY_FROM_MAIN_DOCUMENT_DOMAIN, _TXT("onlyfrommaindocumentdomain") },
    { Exchange::IWebBrowser::HTTPCookieAcceptPolicyType::EXCLUSIVELY_FROM_MAIN_DOCUMENT_DOMAIN, _TXT("exclusivelyfrommaindocumentdomain") },
ENUM_CONVERSION_END(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)

}
