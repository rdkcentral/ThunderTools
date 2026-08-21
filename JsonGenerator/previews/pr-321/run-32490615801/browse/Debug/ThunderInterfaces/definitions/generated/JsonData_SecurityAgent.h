// C++ types for SecurityAgent API.
// Generated automatically from 'ISecurityAgent.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/ISecurityAgent.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace SecurityAgent {

        // Method params/result classes
        //

        class ValidateParamsData : public Core::JSON::Container {
        public:
            ValidateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("token"), &Token);
            }

            ValidateParamsData(const ValidateParamsData&) = delete;
            ValidateParamsData(ValidateParamsData&&) noexcept  = delete;

            ValidateParamsData& operator=(const ValidateParamsData&) = delete;
            ValidateParamsData& operator=(ValidateParamsData&&) noexcept  = delete;

            ~ValidateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Token.IsSet() == true);
            }

        public:
            Core::JSON::String Token; // Token that will be validated
        }; // class ValidateParamsData

    } // namespace SecurityAgent

    POP_WARNING()

} // namespace JsonData

}

