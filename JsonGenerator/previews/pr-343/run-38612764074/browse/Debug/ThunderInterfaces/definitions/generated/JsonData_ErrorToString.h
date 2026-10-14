// C++ types for ErrorToString API.
// Generated automatically from 'IContentProtection.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IContentProtection.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace ErrorToString {

        // Method params/result classes
        //

        class ErrorToStringParamsData : public Core::JSON::Container {
        public:
            ErrorToStringParamsData()
                : Core::JSON::Container()
            {
                Add(_T("code"), &Code);
            }

            ErrorToStringParamsData(const ErrorToStringParamsData&) = delete;
            ErrorToStringParamsData(ErrorToStringParamsData&&) noexcept  = delete;

            ErrorToStringParamsData& operator=(const ErrorToStringParamsData&) = delete;
            ErrorToStringParamsData& operator=(ErrorToStringParamsData&&) noexcept  = delete;

            ~ErrorToStringParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Code.IsSet() == true);
            }

        public:
            Core::JSON::DecSInt32 Code;
        }; // class ErrorToStringParamsData

    } // namespace ErrorToString

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IContentProtection::KeySystem)
ENUM_CONVERSION_HANDLER(Exchange::IContentProtection::State)
ENUM_CONVERSION_HANDLER(Exchange::IContentProtection::INotification::Status::State)

}

