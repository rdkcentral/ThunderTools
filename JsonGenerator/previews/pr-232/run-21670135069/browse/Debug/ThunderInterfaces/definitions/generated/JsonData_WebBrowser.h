// C++ types for WebBrowser API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace WebBrowser {

        // Method params/result classes
        //

        class BridgeQueryParamsData : public Core::JSON::Container {
        public:
            BridgeQueryParamsData()
                : Core::JSON::Container()
            {
                Add(_T("message"), &Message);
            }

            BridgeQueryParamsData(const BridgeQueryParamsData&) = delete;
            BridgeQueryParamsData(BridgeQueryParamsData&&) noexcept  = delete;

            BridgeQueryParamsData& operator=(const BridgeQueryParamsData&) = delete;
            BridgeQueryParamsData& operator=(BridgeQueryParamsData&&) noexcept  = delete;

            ~BridgeQueryParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Message.IsSet() == true);
            }

        public:
            Core::JSON::String Message; // Requested action
        }; // class BridgeQueryParamsData

        class LoadFailedParamsData : public Core::JSON::Container {
        public:
            LoadFailedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &URL);
            }

            LoadFailedParamsData(const LoadFailedParamsData&) = delete;
            LoadFailedParamsData(LoadFailedParamsData&&) noexcept  = delete;

            LoadFailedParamsData& operator=(const LoadFailedParamsData&) = delete;
            LoadFailedParamsData& operator=(LoadFailedParamsData&&) noexcept  = delete;

            ~LoadFailedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (URL.IsSet() == true);
            }

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

            LoadFinishedParamsData(const LoadFinishedParamsData&) = delete;
            LoadFinishedParamsData(LoadFinishedParamsData&&) noexcept  = delete;

            LoadFinishedParamsData& operator=(const LoadFinishedParamsData&) = delete;
            LoadFinishedParamsData& operator=(LoadFinishedParamsData&&) noexcept  = delete;

            ~LoadFinishedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((URL.IsSet() == true) && (Httpstatus.IsSet() == true));
            }

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

            URLChangeParamsData(const URLChangeParamsData&) = delete;
            URLChangeParamsData(URLChangeParamsData&&) noexcept  = delete;

            URLChangeParamsData& operator=(const URLChangeParamsData&) = delete;
            URLChangeParamsData& operator=(URLChangeParamsData&&) noexcept  = delete;

            ~URLChangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((URL.IsSet() == true) && (Loaded.IsSet() == true));
            }

        public:
            Core::JSON::String URL; // The URL that has been loaded or requested
            Core::JSON::Boolean Loaded; // Loaded (true) or not (false)
        }; // class URLChangeParamsData

        class VisibilityChangeParamsData : public Core::JSON::Container {
        public:
            VisibilityChangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("hidden"), &Hidden);
            }

            VisibilityChangeParamsData(const VisibilityChangeParamsData&) = delete;
            VisibilityChangeParamsData(VisibilityChangeParamsData&&) noexcept  = delete;

            VisibilityChangeParamsData& operator=(const VisibilityChangeParamsData&) = delete;
            VisibilityChangeParamsData& operator=(VisibilityChangeParamsData&&) noexcept  = delete;

            ~VisibilityChangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Hidden.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Hidden; // Hidden (true) or Visible (false)
        }; // class VisibilityChangeParamsData

    } // namespace WebBrowser

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)

}

