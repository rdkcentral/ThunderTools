// C++ types for TestCustom API.
// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestTextOptions {

        namespace TestCustom {

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

                TestDetailsInfo(const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails& _other)
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

                TestDetailsInfo& operator=(const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails& _rhs)
                {
                    TestDetailsFirst = _rhs.testDetailsFirst;
                    TestDetailsSecond = _rhs.testDetailsSecond;
                    return (*this);
                }

                operator QualityAssurance::ITestTextOptions::ITestCustom::TestDetails() const
                {
                    QualityAssurance::ITestTextOptions::ITestCustom::TestDetails _value{};
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
                    Add(_T("TestDetailsFirst"), &TestDetailsFirst);
                    Add(_T("TestDetailsSecond"), &TestDetailsSecond);
                }

            public:
                Core::JSON::String TestDetailsFirst;
                Core::JSON::String TestDetailsSecond;
            }; // class TestDetailsInfo

            class TestCustomParamsInfo : public Core::JSON::Container {
            public:
                TestCustomParamsInfo()
                    : Core::JSON::Container()
                {
                    Add(_T("FIRST_TEST_PARAM"), &FirstTestParam);
                    Add(_T("SECOND_TEST_PARAM"), &SecondTestParam);
                    Add(_T("THIRD_TEST_PARAM"), &ThirdTestParam);
                    Add(_T("FOURTH_TEST_PARAM"), &FourthTestParam);
                }

                TestCustomParamsInfo(const TestCustomParamsInfo&) = delete;
                TestCustomParamsInfo(TestCustomParamsInfo&&) noexcept  = delete;

                TestCustomParamsInfo& operator=(const TestCustomParamsInfo&) = delete;
                TestCustomParamsInfo& operator=(TestCustomParamsInfo&&) noexcept  = delete;

                ~TestCustomParamsInfo() = default;

            public:
                bool IsDataValid() const
                {
                    return ((FirstTestParam.IsSet() == true) && (SecondTestParam.IsSet() == true) && ((ThirdTestParam.IsSet() == true) && (ThirdTestParam.IsDataValid() == true)) && (FourthTestParam.IsSet() == true));
                }

            public:
                Core::JSON::DecUInt32 FirstTestParam; // Validates custom generation
                Core::JSON::DecUInt32 SecondTestParam; // Validates custom generation
                TestDetailsInfo ThirdTestParam; // Validates custom generation
                Core::JSON::EnumType<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions> FourthTestParam; // Validates custom generation
            }; // class TestCustomParamsInfo

            // Method params/result classes
            //

        } // namespace TestCustom

    } // namespace TestTextOptions

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions)

}

