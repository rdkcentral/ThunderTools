// C++ types for Math API.
// Generated automatically from 'IMath.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IMath.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Math {

        // Common classes
        //

        class AddParamsInfo : public Core::JSON::Container {
        public:
            AddParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("a"), &A);
                Add(_T("b"), &B);
            }

            AddParamsInfo(const AddParamsInfo&) = delete;
            AddParamsInfo(AddParamsInfo&&) noexcept  = delete;

            AddParamsInfo& operator=(const AddParamsInfo&) = delete;
            AddParamsInfo& operator=(AddParamsInfo&&) noexcept  = delete;

            ~AddParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((A.IsSet() == true) && (B.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt16 A; // First input
            Core::JSON::DecUInt16 B; // Second input
        }; // class AddParamsInfo

        // Method params/result classes
        //

    } // namespace Math

    POP_WARNING()

} // namespace JsonData

}

