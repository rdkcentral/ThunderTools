// C++ types for TestKeep API.
// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace TestTextOptions {

        namespace TestKeep {

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

                TestDetailsInfo(const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails& _other)
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

                TestDetailsInfo& operator=(const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails& _rhs)
                {
                    TestDetailsFirst = _rhs.testDetailsFirst;
                    TestDetailsSecond = _rhs.testDetailsSecond;
                    return (*this);
                }

                operator QualityAssurance::ITestTextOptions::ITestKeep::TestDetails() const
                {
                    QualityAssurance::ITestTextOptions::ITestKeep::TestDetails _value{};
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

            // Method params/result classes
            //

            class TestEventParamsData : public Core::JSON::Container {
            public:
                TestEventParamsData()
                    : Core::JSON::Container()
                {
                    Add(_T("firstTestParam"), &FirstTestParam);
                    Add(_T("secondTestParam"), &SecondTestParam);
                    Add(_T("thirdTestParam"), &ThirdTestParam);
                    Add(_T("fourthTestParam"), &FourthTestParam);
                }

                TestEventParamsData(const TestEventParamsData&) = delete;
                TestEventParamsData(TestEventParamsData&&) noexcept  = delete;

                TestEventParamsData& operator=(const TestEventParamsData&) = delete;
                TestEventParamsData& operator=(TestEventParamsData&&) noexcept  = delete;

                ~TestEventParamsData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((FirstTestParam.IsSet() == true) && (SecondTestParam.IsSet() == true) && ((ThirdTestParam.IsSet() == true) && (ThirdTestParam.IsDataValid() == true)) && (FourthTestParam.IsSet() == true));
                }

            public:
                Core::JSON::DecUInt32 FirstTestParam;
                Core::JSON::DecUInt32 SecondTestParam;
                TestDetailsInfo ThirdTestParam;
                Core::JSON::EnumType<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions> FourthTestParam;
            }; // class TestEventParamsData

            class TestKeePParamsData : public Core::JSON::Container {
            public:
                TestKeePParamsData()
                    : Core::JSON::Container()
                {
                    Add(_T("firstTestParaM"), &FirstTestParaM);
                    Add(_T("secondTestParaM"), &SecondTestParaM);
                    Add(_T("thirdTestParaM"), &ThirdTestParaM);
                    Add(_T("fourthTestParaM"), &FourthTestParaM);
                }

                TestKeePParamsData(const TestKeePParamsData&) = delete;
                TestKeePParamsData(TestKeePParamsData&&) noexcept  = delete;

                TestKeePParamsData& operator=(const TestKeePParamsData&) = delete;
                TestKeePParamsData& operator=(TestKeePParamsData&&) noexcept  = delete;

                ~TestKeePParamsData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((FirstTestParaM.IsSet() == true) && (SecondTestParaM.IsSet() == true) && ((ThirdTestParaM.IsSet() == true) && (ThirdTestParaM.IsDataValid() == true)) && (FourthTestParaM.IsSet() == true));
                }

            public:
                Core::JSON::DecUInt32 FirstTestParaM; // Validates keep which is as same as it's coded
                Core::JSON::DecUInt32 SecondTestParaM; // Validates keep which is as same as it's coded
                TestDetailsInfo ThirdTestParaM; // Validates keep which is as same as it's coded
                Core::JSON::EnumType<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions> FourthTestParaM; // Validates keep which is as same as it's coded
            }; // class TestKeePParamsData

        } // namespace TestKeep

    } // namespace TestTextOptions

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions)
ENUM_CONVERSION_HANDLER(QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions)

}

