// C++ types for Security Agent API.
// Generated automatically from 'SecurityAgent.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SecurityAgent {

        // Common classes
        //

        class CreatetokenResultInfo : public Core::JSON::Container {
        public:
            CreatetokenResultInfo()
                : Core::JSON::Container()
            {
                Add(_T("token"), &Token);
            }

            CreatetokenResultInfo(const CreatetokenResultInfo&) = delete;
            CreatetokenResultInfo(CreatetokenResultInfo&&) noexcept  = delete;

            CreatetokenResultInfo& operator=(const CreatetokenResultInfo&) = delete;
            CreatetokenResultInfo& operator=(CreatetokenResultInfo&&) noexcept  = delete;

            ~CreatetokenResultInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Token.IsSet() == true);
            }

        public:
            Core::JSON::String Token; // Signed JsonWeb token
        }; // class CreatetokenResultInfo

        // Method params/result classes
        //

        class CreatetokenParamsData : public Core::JSON::Container {
        public:
            CreatetokenParamsData()
                : Core::JSON::Container()
            {
                Add(_T("url"), &Url);
                Add(_T("user"), &User);
                Add(_T("hash"), &Hash);
            }

            CreatetokenParamsData(const CreatetokenParamsData&) = delete;
            CreatetokenParamsData(CreatetokenParamsData&&) noexcept  = delete;

            CreatetokenParamsData& operator=(const CreatetokenParamsData&) = delete;
            CreatetokenParamsData& operator=(CreatetokenParamsData&&) noexcept  = delete;

            ~CreatetokenParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Url.IsSet() == true) && (User.IsSet() == true) && (Hash.IsSet() == true));
            }

        public:
            Core::JSON::String Url; // Url of application origin
            Core::JSON::String User; // Username
            Core::JSON::String Hash; // Random hash
        }; // class CreatetokenParamsData

        class ValidateResultData : public Core::JSON::Container {
        public:
            ValidateResultData()
                : Core::JSON::Container()
            {
                Add(_T("valid"), &Valid);
            }

            ValidateResultData(const ValidateResultData&) = delete;
            ValidateResultData(ValidateResultData&&) noexcept  = delete;

            ValidateResultData& operator=(const ValidateResultData&) = delete;
            ValidateResultData& operator=(ValidateResultData&&) noexcept  = delete;

            ~ValidateResultData() = default;

        public:
            bool IsDataValid() const
            {
                return (Valid.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Valid; // Tells whether token is signature is correct
        }; // class ValidateResultData

    } // namespace SecurityAgent

    POP_WARNING()

} // namespace JsonData

}

