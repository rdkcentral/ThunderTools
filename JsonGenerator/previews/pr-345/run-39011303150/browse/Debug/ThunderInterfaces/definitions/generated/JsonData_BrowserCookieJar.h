// C++ types for BrowserCookieJar API.
// Generated automatically from 'IBrowser.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBrowser.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            ConfigData(const ConfigData& _other)
                : Core::JSON::Container()
                , Version(_other.Version)
                , Checksum(_other.Checksum)
                , Payload(_other.Payload)
            {
                _Init();
            }

            ConfigData(ConfigData&& _other) noexcept
                : Core::JSON::Container()
                , Version(std::move(_other.Version))
                , Checksum(std::move(_other.Checksum))
                , Payload(std::move(_other.Payload))
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

            ConfigData& operator=(const ConfigData& _rhs)
            {
                Version = _rhs.Version;
                Checksum = _rhs.Checksum;
                Payload = _rhs.Payload;
                return (*this);
            }

            ConfigData& operator=(ConfigData&& _rhs) noexcept
            {
                Version = std::move(_rhs.Version);
                Checksum = std::move(_rhs.Checksum);
                Payload = std::move(_rhs.Payload);
                return (*this);
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

            ~ConfigData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Version.IsSet() == true) && (Checksum.IsSet() == true) && (Payload.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("version"), &Version);
                Add(_T("checksum"), &Checksum);
                Add(_T("payload"), &Payload);
            }

        public:
            Core::JSON::DecUInt32 Version; // Version of payload format
            Core::JSON::DecUInt32 Checksum; // The checksum of the string used for payload creation
            Core::JSON::String Payload; // Base64 string representation of compressed and encrypted cookies
        }; // class ConfigData

    } // namespace BrowserCookieJar

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::VisibilityType)
ENUM_CONVERSION_HANDLER(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType)
ENUM_CONVERSION_HANDLER(Exchange::IBrowserSecurity::MixedContentPolicyType)

}

