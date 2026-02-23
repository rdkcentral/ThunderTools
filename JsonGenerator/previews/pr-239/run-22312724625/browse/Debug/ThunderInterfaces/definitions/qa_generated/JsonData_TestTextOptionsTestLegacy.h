// C++ types for TestLegacy API.
// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestTextOptions {

        namespace TestLegacy {

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

                TestDetailsInfo(const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails& _other)
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

                TestDetailsInfo& operator=(const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails& _rhs)
                {
                    TestDetailsFirst = _rhs.testDetailsFirst;
                    TestDetailsSecond = _rhs.testDetailsSecond;
                    return (*this);
                }

                operator QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails() const
                {
                    QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails _value{};
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
                    Add(_T("testdetailsfirst"), &TestDetailsFirst);
                    Add(_T("testdetailssecond"), &TestDetailsSecond);
                }

            public:
                Core::JSON::String TestDetailsFirst;
                Core::JSON::String TestDetailsSecond;
            }; // class TestDetailsInfo

            class TestLegacyParamsInfo : public Core::JSON::Container {
            public:
                TestLegacyParamsInfo()
                    : Core::JSON::Container()
                {
                    Add(_T("firsttestparam"), &FirstTestParam);
                    Add(_T("secondtestparam"), &SecondTestParam);
                    Add(_T("thirdtestparam"), &ThirdTestParam);
                    Add(_T("fourthtestparam"), &FourthTestParam);
                }

                TestLegacyParamsInfo(const TestLegacyParamsInfo&) = delete;
                TestLegacyParamsInfo(TestLegacyParamsInfo&&) noexcept  = delete;

                TestLegacyParamsInfo& operator=(const TestLegacyParamsInfo&) = delete;
                TestLegacyParamsInfo& operator=(TestLegacyParamsInfo&&) noexcept  = delete;

                ~TestLegacyParamsInfo() = default;

            public:
                bool IsDataValid() const
                {
                    return ((FirstTestParam.IsSet() == true) && (SecondTestParam.IsSet() == true) && ((ThirdTestParam.IsSet() == true) && (ThirdTestParam.IsDataValid() == true)) && (FourthTestParam.IsSet() == true));
                }

            public:
                Core::JSON::DecUInt32 FirstTestParam; // Validates legacy which is lowercase
                Core::JSON::DecUInt32 SecondTestParam; // Validates legacy which is lowercase
                TestDetailsInfo ThirdTestParam; // Validates legacy which is lowercase
                Core::JSON::EnumType<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions> FourthTestParam; // Validates legacy which is lowercase
            }; // class TestLegacyParamsInfo

            // Method params/result classes
            //

        } // namespace TestLegacy

    } // namespace TestTextOptions

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions)

}

