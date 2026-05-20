// C++ classes for WebBrowser API JSON-RPC API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace JsonData {

    namespace WebBrowser {

        // Method params/result classes
        //

        class LoadFailedParamsData : public Core::JSON::Container {
        public:
            LoadFailedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &URL);
            }

            bool IsValid() const
            {
                return (true);
            }

            LoadFailedParamsData(const LoadFailedParamsData&) = delete;
            LoadFailedParamsData& operator=(const LoadFailedParamsData&) = delete;

        public:
            Core::JSON::String URL; // The URL that has been failed to load
        }; // class LoadFailedParamsData

        class LoadFinishedParamsData : public Core::JSON::Container {
        public:
            LoadFinishedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &URL);
                Add(_T("httpstatus"), &Httpstatus);
            }

            bool IsValid() const
            {
                return (true);
            }

            LoadFinishedParamsData(const LoadFinishedParamsData&) = delete;
            LoadFinishedParamsData& operator=(const LoadFinishedParamsData&) = delete;

        public:
            Core::JSON::String URL; // The URL that has been loaded
            Core::JSON::DecSInt32 Httpstatus; // The response code of main resource request
        }; // class LoadFinishedParamsData

        class URLChangeParamsData : public Core::JSON::Container {
        public:
            URLChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &URL);
                Add(_T("loaded"), &Loaded);
            }

            bool IsValid() const
            {
                return (true);
            }

            URLChangeParamsData(const URLChangeParamsData&) = delete;
            URLChangeParamsData& operator=(const URLChangeParamsData&) = delete;

        public:
            Core::JSON::String URL; // The URL that has been loaded or requested
            Core::JSON::Boolean Loaded; // loaded (true) or not (false)
        }; // class URLChangeParamsData

        class VisibilityChangeParamsData : public Core::JSON::Container {
        public:
            VisibilityChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("hidden"), &Hidden);
            }

            bool IsValid() const
            {
                return (true);
            }

            VisibilityChangeParamsData(const VisibilityChangeParamsData&) = delete;
            VisibilityChangeParamsData& operator=(const VisibilityChangeParamsData&) = delete;

        public:
            Core::JSON::Boolean Hidden; // hidden (true) or visible (false)
        }; // class VisibilityChangeParamsData

    } // namespace WebBrowser

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)

}

