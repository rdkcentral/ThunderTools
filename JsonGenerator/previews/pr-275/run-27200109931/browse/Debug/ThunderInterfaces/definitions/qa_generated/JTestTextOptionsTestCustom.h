// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_TestTextOptionsTestCustom.h"
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace QualityAssurance {

    namespace TestTextOptions {

        namespace JTestCustom {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ITestTextOptions::ITestCustom* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JTestCustom"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'TESTCUSTOM' - Validates custom generation
                _module__.PluginHost::JSONRPC::template Register<JsonData::TestTextOptions::TestCustom::TestCustomParamsInfo, void>(_T("TESTCUSTOM"),
                    [_implementation__](const JsonData::TestTextOptions::TestCustom::TestCustomParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint32_t _firstTestParam_{params.FirstTestParam};
                            const uint32_t _secondTestParam_{params.SecondTestParam};
                            const QualityAssurance::ITestTextOptions::ITestCustom::TestDetails _thirdTestParam_(params.ThirdTestParam);
                            const QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions _fourthTestParam_{params.FourthTestParam};

                            _errorCode__ = _implementation__->TestCustom(_firstTestParam_, _secondTestParam_, _thirdTestParam_, _fourthTestParam_);

                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("TESTCUSTOM"));
            }

            namespace Event {

                // Event: 'test_event'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const JsonData::TestTextOptions::TestCustom::TestCustomParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("test_event"), params, sendIfMethod_);
                }

                // Event: 'test_event'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const Core::JSON::DecUInt32& firstTestParam, const Core::JSON::DecUInt32& secondTestParam, const JsonData::TestTextOptions::TestCustom::TestDetailsInfo& thirdTestParam, const Core::JSON::EnumType<QualityAssurance::ITestTextOptions::ITestCustom::EnumTextOptions>& fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::TestTextOptions::TestCustom::TestCustomParamsInfo params_;
                    params_.FirstTestParam = firstTestParam;
                    params_.SecondTestParam = secondTestParam;
                    params_.ThirdTestParam = thirdTestParam;
                    params_.FourthTestParam = fourthTestParam;

                    TestEvent(module_, params_, sendIfMethod_);
                }

                // Event: 'test_event'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const uint32_t firstTestParam, const uint32_t secondTestParam, const ITestTextOptions::ITestCustom::TestDetails& thirdTestParam, const ITestTextOptions::ITestCustom::EnumTextOptions fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::TestTextOptions::TestCustom::TestCustomParamsInfo params_;
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

        } // namespace JTestCustom

    } // namespace TestTextOptions

} // namespace QualityAssurance

} // namespace Thunder

