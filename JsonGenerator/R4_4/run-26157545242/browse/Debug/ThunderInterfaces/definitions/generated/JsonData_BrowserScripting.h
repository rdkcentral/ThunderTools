// C++ classes for BrowserScripting API JSON-RPC API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace JsonData {

    namespace BrowserScripting {

        // Method params/result classes
        //

        class AddUserScriptParamsData : public Core::JSON::Container {
        public:
            AddUserScriptParamsData()
                : Core::JSON::Container()
            {
                Add(_T("script"), &Script);
                Add(_T("topframeonly"), &TopFrameOnly);
            }

            bool IsValid() const
            {
                return (true);
            }

            AddUserScriptParamsData(const AddUserScriptParamsData&) = delete;
            AddUserScriptParamsData& operator=(const AddUserScriptParamsData&) = delete;

        public:
            Core::JSON::String Script; // Utf8 encoded JS code string.
            Core::JSON::Boolean TopFrameOnly;
        }; // class AddUserScriptParamsData

        class RunJavaScriptParamsData : public Core::JSON::Container {
        public:
            RunJavaScriptParamsData()
                : Core::JSON::Container()
            {
                Add(_T("script"), &Script);
            }

            bool IsValid() const
            {
                return (true);
            }

            RunJavaScriptParamsData(const RunJavaScriptParamsData&) = delete;
            RunJavaScriptParamsData& operator=(const RunJavaScriptParamsData&) = delete;

        public:
            Core::JSON::String Script; // Utf8 encoded JS code string.
        }; // class RunJavaScriptParamsData

    } // namespace BrowserScripting

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)
ENUM_CONVERSION_HANDLER(Exchange::IBrowserSecurity::MixedContentPolicyType)

}

