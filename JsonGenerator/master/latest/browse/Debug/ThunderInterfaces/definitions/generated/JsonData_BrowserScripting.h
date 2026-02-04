// C++ types for BrowserScripting API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            AddUserScriptParamsData(const AddUserScriptParamsData&) = delete;
            AddUserScriptParamsData(AddUserScriptParamsData&&) noexcept  = delete;

            AddUserScriptParamsData& operator=(const AddUserScriptParamsData&) = delete;
            AddUserScriptParamsData& operator=(AddUserScriptParamsData&&) noexcept  = delete;

            ~AddUserScriptParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Script.IsSet() == true) && (TopFrameOnly.IsSet() == true));
            }

        public:
            Core::JSON::String Script; // Utf8 encoded JS code string.
            Core::JSON::Boolean TopFrameOnly; // Enable only top frame
        }; // class AddUserScriptParamsData

        class RunJavaScriptParamsData : public Core::JSON::Container {
        public:
            RunJavaScriptParamsData()
                : Core::JSON::Container()
            {
                Add(_T("script"), &Script);
            }

            RunJavaScriptParamsData(const RunJavaScriptParamsData&) = delete;
            RunJavaScriptParamsData(RunJavaScriptParamsData&&) noexcept  = delete;

            RunJavaScriptParamsData& operator=(const RunJavaScriptParamsData&) = delete;
            RunJavaScriptParamsData& operator=(RunJavaScriptParamsData&&) noexcept  = delete;

            ~RunJavaScriptParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Script.IsSet() == true);
            }

        public:
            Core::JSON::String Script; // Utf8 encoded JS code string.
        }; // class RunJavaScriptParamsData

    } // namespace BrowserScripting

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)
ENUM_CONVERSION_HANDLER(Exchange::IBrowserSecurity::MixedContentPolicyType)

}

