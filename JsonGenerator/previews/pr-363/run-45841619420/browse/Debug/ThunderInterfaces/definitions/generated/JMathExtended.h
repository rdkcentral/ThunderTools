// Generated automatically from 'IMath.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_MathExtended.h"
#include <interfaces/IMath.h>

namespace Thunder {

namespace Exchange {

    namespace JMathExtended {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IMathExtended* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JMathExtended"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'multiply'
            _module__.PluginHost::JSONRPC::template Register<JsonData::MathExtended::MultiplyParamsData, void>(_T("multiply"),
                [_implementation__](const JsonData::MathExtended::MultiplyParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JMathExtended"), _T("multiply")));
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint16_t _a_{params.A};
                        const uint16_t _b_{params.B};

                        _errorCode__ = _implementation__->Multiply(_a_, _b_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("multiply"));
        }

        namespace Event {

            // Event: 'multiplyResult'
            template<typename MODULE>
            static void MultiplyResult(const MODULE& module_, const JsonData::MathExtended::MultiplyResultParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("multiplyResult"), params, sendIfMethod_);
            }

            // Event: 'multiplyResult'
            template<typename MODULE>
            static void MultiplyResult(const MODULE& module_, const Core::JSON::DecUInt32& result, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::MathExtended::MultiplyResultParamsData params_;
                params_.Result = result;

                MultiplyResult(module_, params_, sendIfMethod_);
            }

            // Event: 'multiplyResult'
            template<typename MODULE>
            static void MultiplyResult(const MODULE& module_, const uint32_t result, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::MathExtended::MultiplyResultParamsData params_;
                params_.Result = result;

                MultiplyResult(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JMathExtended

} // namespace Exchange

} // namespace Thunder

