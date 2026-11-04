// C++ types for TestTextOptions API.
// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestTextOptions {

        // Common classes
        //

        class TestDetailsInfo : public Core::JSON::Container {
        public:
            TestDetailsInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            TestDetailsInfo(const TestDetailsInfo& _other)
                : Core::JSON::Container()
                , TestDetailsFirst(_other.TestDetailsFirst)
                , TestDetailsSecond(_other.TestDetailsSecond)
            {
                _Init();
            }

            TestDetailsInfo(TestDetailsInfo&& _other) noexcept
                : Core::JSON::Container()
                , TestDetailsFirst(std::move(_other.TestDetailsFirst))
                , TestDetailsSecond(std::move(_other.TestDetailsSecond))
            {
                _Init();
            }

            TestDetailsInfo(const QualityAssurance::ITestTextOptions::TestDetails& _other)
                : Core::JSON::Container()
            {
                TestDetailsFirst = _other.testDetailsFirst;
                TestDetailsSecond = _other.testDetailsSecond;
                _Init();
            }

            TestDetailsInfo& operator=(const TestDetailsInfo& _rhs)
            {
                TestDetailsFirst = _rhs.TestDetailsFirst;
                TestDetailsSecond = _rhs.TestDetailsSecond;
                return (*this);
            }

            TestDetailsInfo& operator=(TestDetailsInfo&& _rhs) noexcept
            {
                TestDetailsFirst = std::move(_rhs.TestDetailsFirst);
                TestDetailsSecond = std::move(_rhs.TestDetailsSecond);
                return (*this);
            }

            TestDetailsInfo& operator=(const QualityAssurance::ITestTextOptions::TestDetails& _rhs)
            {
                TestDetailsFirst = _rhs.testDetailsFirst;
                TestDetailsSecond = _rhs.testDetailsSecond;
                return (*this);
            }

            operator QualityAssurance::ITestTextOptions::TestDetails() const
            {
                QualityAssurance::ITestTextOptions::TestDetails _value{};
                _value.testDetailsFirst = TestDetailsFirst;
                _value.testDetailsSecond = TestDetailsSecond;
                return (_value);
            }

            ~TestDetailsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((TestDetailsFirst.IsSet() == true) && (TestDetailsSecond.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("testDetailsFirst"), &TestDetailsFirst);
                Add(_T("testDetailsSecond"), &TestDetailsSecond);
            }

        public:
            Core::JSON::String TestDetailsFirst;
            Core::JSON::String TestDetailsSecond;
        }; // class TestDetailsInfo

        class TestStandardParamsInfo : public Core::JSON::Container {
        public:
            TestStandardParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("firstTestParam"), &FirstTestParam);
                Add(_T("secondTestParam"), &SecondTestParam);
                Add(_T("thirdTestParam"), &ThirdTestParam);
                Add(_T("fourthTestParam"), &FourthTestParam);
            }

            TestStandardParamsInfo(const TestStandardParamsInfo&) = delete;
            TestStandardParamsInfo(TestStandardParamsInfo&&) noexcept  = delete;

            TestStandardParamsInfo& operator=(const TestStandardParamsInfo&) = delete;
            TestStandardParamsInfo& operator=(TestStandardParamsInfo&&) noexcept  = delete;

            ~TestStandardParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((FirstTestParam.IsSet() == true) && (SecondTestParam.IsSet() == true) && ((ThirdTestParam.IsSet() == true) && (ThirdTestParam.IsDataValid() == true)) && (FourthTestParam.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 FirstTestParam; // Validates standard which is camelCase
            Core::JSON::DecUInt32 SecondTestParam; // Validates standard which is camelCase
            TestDetailsInfo ThirdTestParam; // Validates standard which is camelCase
            Core::JSON::EnumType<QualityAssurance::ITestTextOptions::EnumTextOptions> FourthTestParam; // Validates standard which is camelCase
        }; // class TestStandardParamsInfo

        // Method params/result classes
        //

    } // namespace TestTextOptions

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::EnumTextOptions)

}

