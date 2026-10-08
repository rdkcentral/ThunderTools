// Generated automatically from 'ITestAutomation.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_ComRpc.h"
#include <qa_interfaces/ITestAutomation.h>

namespace Thunder {

namespace QualityAssurance {

    namespace JComRpc {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IComRpc* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JComRpc"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'testbigstring' - Validates big string over proxy-stub with given length of KB
            _module__.PluginHost::JSONRPC::template Register<JsonData::ComRpc::TestBigStringParamsData, void>(_T("testbigstring"),
                [_implementation__](const JsonData::ComRpc::TestBigStringParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const uint32_t _length_{params.Length};

                        _errorCode__ = _implementation__->TestBigString(_length_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("testbigstring"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JComRpc

} // namespace QualityAssurance

} // namespace Thunder

