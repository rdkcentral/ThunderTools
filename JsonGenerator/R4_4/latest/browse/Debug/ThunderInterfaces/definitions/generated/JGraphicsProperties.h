// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include <interfaces/IDisplayInfo.h>

namespace WPEFramework {

namespace Exchange {

    namespace JGraphicsProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IGraphicsProperties* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JGraphicsProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'totalgpuram' - Total GPU DRAM memory (in bytes) (r/o)
            _module_.Register<void, Core::JSON::DecUInt64>(_T("totalgpuram"), 
                [_impl_](Core::JSON::DecUInt64& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint64_t _result{};

                    _errorCode = _impl_->TotalGpuRam(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'freegpuram' - Free GPU DRAM memory (in bytes) (r/o)
            _module_.Register<void, Core::JSON::DecUInt64>(_T("freegpuram"), 
                [_impl_](Core::JSON::DecUInt64& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    uint64_t _result{};

                    _errorCode = _impl_->FreeGpuRam(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("totalgpuram"));
            _module_.Unregister(_T("freegpuram"));
        }

        POP_WARNING()

    } // namespace JGraphicsProperties

} // namespace Exchange

} // namespace WPEFramework

