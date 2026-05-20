// C++ classes for Security Agent API JSON-RPC API.
// Generated automatically from 'SecurityAgent.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            CreatetokenResultInfo(const CreatetokenResultInfo&) = delete;
            CreatetokenResultInfo& operator=(const CreatetokenResultInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            CreatetokenParamsData(const CreatetokenParamsData&) = delete;
            CreatetokenParamsData& operator=(const CreatetokenParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            ValidateResultData(const ValidateResultData&) = delete;
            ValidateResultData& operator=(const ValidateResultData&) = delete;

        public:
            Core::JSON::Boolean Valid; // Tells whether token is signature is correct
        }; // class ValidateResultData

    } // namespace SecurityAgent

} // namespace JsonData

}

