// C++ types for WebBrowserExt API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace WebBrowserExt {

        // Method params/result classes
        //

        class DeleteDirParamsData : public Core::JSON::Container {
        public:
            DeleteDirParamsData()
                : Core::JSON::Container()
            {
                Add(_T("path"), &Path);
            }

            DeleteDirParamsData(const DeleteDirParamsData&) = delete;
            DeleteDirParamsData(DeleteDirParamsData&&) noexcept  = delete;

            DeleteDirParamsData& operator=(const DeleteDirParamsData&) = delete;
            DeleteDirParamsData& operator=(DeleteDirParamsData&&) noexcept  = delete;

            ~DeleteDirParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Path.IsSet() == true);
            }

        public:
            Core::JSON::String Path; // Path to directory (within the persistent storage) to delete contents of
        }; // class DeleteDirParamsData

    } // namespace WebBrowserExt

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)

}

