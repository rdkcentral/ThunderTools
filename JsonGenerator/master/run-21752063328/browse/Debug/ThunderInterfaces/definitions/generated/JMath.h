// Generated automatically from 'IMath.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Math.h"
#include <interfaces/IMath.h>

namespace Thunder {

namespace Exchange {

    namespace JMath {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IMath* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JMath"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'add' - Perform addition on given inputs
            _module__.PluginHost::JSONRPC::template Register<JsonData::Math::AddParamsInfo, Core::JSON::DecUInt16>(_T("add"),
                [_implementation__](const JsonData::Math::AddParamsInfo& params, Core::JSON::DecUInt16& sum) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint16_t _a_{params.A};
                        const uint16_t _b_{params.B};
                        uint16_t _sum_{};

                        _errorCode__ = _implementation__->Add(_a_, _b_, _sum_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            sum = _sum_;
                        }
                    }

                    return (_errorCode__);
                });

            // Method: 'sub' - Perform subtraction on given inputs
            _module__.PluginHost::JSONRPC::template Register<JsonData::Math::AddParamsInfo, Core::JSON::DecUInt16>(_T("sub"),
                [_implementation__](const JsonData::Math::AddParamsInfo& params, Core::JSON::DecUInt16& sum) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint16_t _a_{params.A};
                        const uint16_t _b_{params.B};
                        uint16_t _sum_{};

                        _errorCode__ = _implementation__->Sub(_a_, _b_, _sum_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            sum = _sum_;
                        }
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("add"));
            _module__.PluginHost::JSONRPC::Unregister(_T("sub"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JMath

} // namespace Exchange

} // namespace Thunder

