// C++ classes for BrowserCookieJar API JSON-RPC API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace WPEFramework {

namespace JsonData {

    namespace BrowserCookieJar {

        // Method params/result classes
        //

        class ConfigData : public Core::JSON::Container {
        public:
            ConfigData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ConfigData(const Exchange::IBrowserCookieJar::Config& _other)
                : Core::JSON::Container()
            {
                Version = _other.version;
                Checksum = _other.checksum;
                Payload = _other.payload;
                _Init();
            }

            ConfigData& operator=(const Exchange::IBrowserCookieJar::Config& _rhs)
            {
                Version = _rhs.version;
                Checksum = _rhs.checksum;
                Payload = _rhs.payload;
                return (*this);
            }

            operator Exchange::IBrowserCookieJar::Config() const
            {
                Exchange::IBrowserCookieJar::Config _value{};
                _value.version = Version;
                _value.checksum = Checksum;
                _value.payload = Payload;
                return (_value);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("version"), &Version);
                Add(_T("checksum"), &Checksum);
                Add(_T("payload"), &Payload);
            }

        public:
            Core::JSON::DecUInt32 Version;
            Core::JSON::DecUInt32 Checksum;
            Core::JSON::String Payload;
        }; // class ConfigData

    } // namespace BrowserCookieJar

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)
ENUM_CONVERSION_HANDLER(Exchange::IBrowserSecurity::MixedContentPolicyType)

}

