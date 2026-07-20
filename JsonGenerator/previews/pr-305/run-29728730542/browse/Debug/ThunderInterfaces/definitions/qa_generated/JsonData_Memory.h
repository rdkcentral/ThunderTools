// C++ types for Memory API.
// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Memory {

        // Method params/result classes
        //

        class AllocateMemoryParamsData : public Core::JSON::Container {
        public:
            AllocateMemoryParamsData()
                : Core::JSON::Container()
            {
                Add(_T("size"), &Size);
            }

            AllocateMemoryParamsData(const AllocateMemoryParamsData&) = delete;
            AllocateMemoryParamsData(AllocateMemoryParamsData&&) noexcept  = delete;

            AllocateMemoryParamsData& operator=(const AllocateMemoryParamsData&) = delete;
            AllocateMemoryParamsData& operator=(AllocateMemoryParamsData&&) noexcept  = delete;

            ~AllocateMemoryParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Size.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Size; // Allocates Memory as given size of MB
        }; // class AllocateMemoryParamsData

    } // namespace Memory

    POP_WARNING()

} // namespace JsonData

}

