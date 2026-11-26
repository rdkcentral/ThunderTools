// C++ types for MathExtended API.
// Generated automatically from 'IMath.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IMath.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace MathExtended {

        // Method params/result classes
        //

        class MultiplyParamsData : public Core::JSON::Container {
        public:
            MultiplyParamsData()
                : Core::JSON::Container()
            {
                Add(_T("a"), &A);
                Add(_T("b"), &B);
            }

            MultiplyParamsData(const MultiplyParamsData&) = delete;
            MultiplyParamsData(MultiplyParamsData&&) noexcept  = delete;

            MultiplyParamsData& operator=(const MultiplyParamsData&) = delete;
            MultiplyParamsData& operator=(MultiplyParamsData&&) noexcept  = delete;

            ~MultiplyParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((A.IsSet() == true) && (B.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt16 A;
            Core::JSON::DecUInt16 B;
        }; // class MultiplyParamsData

        class MultiplyResultParamsData : public Core::JSON::Container {
        public:
            MultiplyResultParamsData()
                : Core::JSON::Container()
            {
                Add(_T("result"), &Result);
            }

            MultiplyResultParamsData(const MultiplyResultParamsData&) = delete;
            MultiplyResultParamsData(MultiplyResultParamsData&&) noexcept  = delete;

            MultiplyResultParamsData& operator=(const MultiplyResultParamsData&) = delete;
            MultiplyResultParamsData& operator=(MultiplyResultParamsData&&) noexcept  = delete;

            ~MultiplyResultParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Result.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Result;
        }; // class MultiplyResultParamsData

    } // namespace MathExtended

    POP_WARNING()

} // namespace JsonData

}

