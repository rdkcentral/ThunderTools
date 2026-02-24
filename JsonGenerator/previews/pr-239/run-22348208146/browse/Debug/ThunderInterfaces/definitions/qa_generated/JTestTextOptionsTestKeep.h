// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_TestTextOptionsTestKeep.h"
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace QualityAssurance {

    namespace TestTextOptions {

        namespace JTestKeep {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ITestTextOptions::ITestKeep* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JTestKeep"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'TestKeeP' - Validates keep which is as same as it's coded
                _module__.PluginHost::JSONRPC::template Register<JsonData::TestTextOptions::TestKeep::TestKeePParamsData, void>(_T("TestKeeP"),
                    [_implementation__](const JsonData::TestTextOptions::TestKeep::TestKeePParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint32_t _firstTestParaM_{params.FirstTestParaM};
                            const uint32_t _secondTestParaM_{params.SecondTestParaM};
                            const QualityAssurance::ITestTextOptions::ITestKeep::TestDetails _thirdTestParaM_(params.ThirdTestParaM);
                            const QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions _fourthTestParaM_{params.FourthTestParaM};

                            _errorCode__ = _implementation__->TestKeeP(_firstTestParaM_, _secondTestParaM_, _thirdTestParaM_, _fourthTestParaM_);

                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("TestKeeP"));
            }

            namespace Event {

                // Event: 'TestEvent'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const JsonData::TestTextOptions::TestKeep::TestEventParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("TestEvent"), params, sendIfMethod_);
                }

                // Event: 'TestEvent'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const Core::JSON::DecUInt32& firstTestParam, const Core::JSON::DecUInt32& secondTestParam, const JsonData::TestTextOptions::TestKeep::TestDetailsInfo& thirdTestParam, const Core::JSON::EnumType<QualityAssurance::ITestTextOptions::ITestKeep::EnumTextOptions>& fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::TestTextOptions::TestKeep::TestEventParamsData params_;
                    params_.FirstTestParam = firstTestParam;
                    params_.SecondTestParam = secondTestParam;
                    params_.ThirdTestParam = thirdTestParam;
                    params_.FourthTestParam = fourthTestParam;

                    TestEvent(module_, params_, sendIfMethod_);
                }

                // Event: 'TestEvent'
                template<typename MODULE>
                static void TestEvent(const MODULE& module_, const uint32_t firstTestParam, const uint32_t secondTestParam, const ITestTextOptions::ITestKeep::TestDetails& thirdTestParam, const ITestTextOptions::ITestKeep::EnumTextOptions fourthTestParam, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::TestTextOptions::TestKeep::TestEventParamsData params_;
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

        } // namespace JTestKeep

    } // namespace TestTextOptions

} // namespace QualityAssurance

} // namespace Thunder

