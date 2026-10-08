// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_TestTextOptions.h"
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace QualityAssurance {

    namespace JTestTextOptions {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ITestTextOptions* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JTestTextOptions"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'testStandard' - Validates standard which is camelCase
            _module__.PluginHost::JSONRPC::template Register<JsonData::TestTextOptions::TestStandardParamsInfo, void>(_T("testStandard"),
                [_implementation__](const JsonData::TestTextOptions::TestStandardParamsInfo& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _firstTestParam_{params.FirstTestParam};
                        const uint32_t _secondTestParam_{params.SecondTestParam};
                        const QualityAssurance::ITestTextOptions::TestDetails _thirdTestParam_(params.ThirdTestParam);
                        const QualityAssurance::ITestTextOptions::EnumTextOptions _fourthTestParam_{params.FourthTestParam};

                        _errorCode__ = _implementation__->TestStandard(_firstTestParam_, _secondTestParam_, _thirdTestParam_, _fourthTestParam_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("testStandard"));
        }

        namespace Event {

            // Event: 'testEvent'
            template<typename MODULE>
            static void TestEvent(const MODULE& module_, const JsonData::TestTextOptions::TestStandardParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("testEvent"), params, sendIfMethod_);
            }

            // Event: 'testEvent'
            template<typename MODULE>
            static void TestEvent(const MODULE& module_, const Core::JSON::DecUInt32& firstTestParam, const Core::JSON::DecUInt32& secondTestParam, const JsonData::TestTextOptions::TestDetailsInfo& thirdTestParam, const Core::JSON::EnumType<QualityAssurance::ITestTextOptions::EnumTextOptions>& fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::TestTextOptions::TestStandardParamsInfo params_;
                params_.FirstTestParam = firstTestParam;
                params_.SecondTestParam = secondTestParam;
                params_.ThirdTestParam = thirdTestParam;
                params_.FourthTestParam = fourthTestParam;

                TestEvent(module_, params_, sendIfMethod_);
            }

            // Event: 'testEvent'
            template<typename MODULE>
            static void TestEvent(const MODULE& module_, const uint32_t firstTestParam, const uint32_t secondTestParam, const ITestTextOptions::TestDetails& thirdTestParam, const ITestTextOptions::EnumTextOptions fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::TestTextOptions::TestStandardParamsInfo params_;
                params_.FirstTestParam = firstTestParam;
                params_.SecondTestParam = secondTestParam;
                params_.ThirdTestParam = thirdTestParam;
                params_.FourthTestParam = fourthTestParam;

                TestEvent(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JTestTextOptions

} // namespace QualityAssurance

} // namespace Thunder

