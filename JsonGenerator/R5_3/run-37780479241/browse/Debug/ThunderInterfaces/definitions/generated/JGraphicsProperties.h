// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include <interfaces/IDisplayInfo.h>

namespace Thunder {

namespace Exchange {

    namespace JGraphicsProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IGraphicsProperties* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JGraphicsProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'totalgpuram' - Total GPU DRAM memory (in bytes) (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt64>(_T("totalgpuram"),
                [_implementation__](Core::JSON::DecUInt64& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint64_t _result_{};

                    _errorCode__ = _implementation__->TotalGpuRam(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'freegpuram' - Free GPU DRAM memory (in bytes) (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt64>(_T("freegpuram"),
                [_implementation__](Core::JSON::DecUInt64& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint64_t _result_{};

                    _errorCode__ = _implementation__->FreeGpuRam(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("totalgpuram"));
            _module__.PluginHost::JSONRPC::Unregister(_T("freegpuram"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JGraphicsProperties

} // namespace Exchange

} // namespace Thunder

