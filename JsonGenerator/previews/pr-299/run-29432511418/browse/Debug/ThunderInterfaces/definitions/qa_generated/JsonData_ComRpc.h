// C++ types for ComRpc API.
// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace ComRpc {

        // Method params/result classes
        //

        class TestBigStringParamsData : public Core::JSON::Container {
        public:
            TestBigStringParamsData()
                : Core::JSON::Container()
            {
                Add(_T("length"), &Length);
            }

            TestBigStringParamsData(const TestBigStringParamsData&) = delete;
            TestBigStringParamsData(TestBigStringParamsData&&) noexcept  = delete;

            TestBigStringParamsData& operator=(const TestBigStringParamsData&) = delete;
            TestBigStringParamsData& operator=(TestBigStringParamsData&&) noexcept  = delete;

            ~TestBigStringParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Length.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt32 Length; // Validates big string over proxy-stub with given length of KB
        }; // class TestBigStringParamsData

    } // namespace ComRpc

    POP_WARNING()

} // namespace JsonData

}

