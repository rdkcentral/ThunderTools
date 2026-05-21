// C++ classes for BrowserSecurity API JSON-RPC API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace JsonData {

    namespace BrowserSecurity {

        // Method params/result classes
        //

    } // namespace BrowserSecurity

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)
ENUM_CONVERSION_HANDLER(Exchange::IBrowserSecurity::MixedContentPolicyType)

}

