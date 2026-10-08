// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_TestTextOptionsTestLegacy.h"
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace QualityAssurance {

    namespace TestTextOptions {

        namespace JTestLegacy {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ITestTextOptions::ITestLegacy* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JTestLegacy"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'testlegacy' - Validates legacy which is lowercase
                _module__.PluginHost::JSONRPC::template Register<JsonData::TestTextOptions::TestLegacy::TestLegacyParamsInfo, void>(_T("testlegacy"),
                    [_implementation__](const JsonData::TestTextOptions::TestLegacy::TestLegacyParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint32_t _firstTestParam_{params.FirstTestParam};
                            const uint32_t _secondTestParam_{params.SecondTestParam};
                            const QualityAssurance::ITestTextOptions::ITestLegacy::TestDetails _thirdTestParam_(params.ThirdTestParam);
                            const QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions _fourthTestParam_{params.FourthTestParam};

                            _errorCode__ = _implementation__->TestLegacy(_firstTestParam_, _secondTestParam_, _thirdTestParam_, _fourthTestParam_);

                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("testlegacy"));
            }

            namespace Event {

                // Event: 'testevent'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const JsonData::TestTextOptions::TestLegacy::TestLegacyParamsInfo& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("testevent"), params, sendIfMethod_);
                }

                // Event: 'testevent'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const Core::JSON::DecUInt32& firstTestParam, const Core::JSON::DecUInt32& secondTestParam, const JsonData::TestTextOptions::TestLegacy::TestDetailsInfo& thirdTestParam, const Core::JSON::EnumType<QualityAssurance::ITestTextOptions::ITestLegacy::EnumTextOptions>& fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::TestTextOptions::TestLegacy::TestLegacyParamsInfo params_;
                    params_.FirstTestParam = firstTestParam;
                    params_.SecondTestParam = secondTestParam;
                    params_.ThirdTestParam = thirdTestParam;
                    params_.FourthTestParam = fourthTestParam;

                    TestEvent(module_, params_, sendIfMethod_);
                }

                // Event: 'testevent'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const uint32_t firstTestParam, const uint32_t secondTestParam, const ITestTextOptions::ITestLegacy::TestDetails& thirdTestParam, const ITestTextOptions::ITestLegacy::EnumTextOptions fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::TestTextOptions::TestLegacy::TestLegacyParamsInfo params_;
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

        } // namespace JTestLegacy

    } // namespace TestTextOptions

} // namespace QualityAssurance

} // namespace Thunder

