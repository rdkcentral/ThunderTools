// Generated automatically from 'IMath.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_Math.h"
#include <interfaces/IMath.h>

namespace WPEFramework {

namespace Exchange {

    namespace JMath {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IMath* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JMath"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'add'
            _module_.Register<JsonData::Math::AddParamsInfo, Core::JSON::DecUInt16>(_T("add"), 
                [_impl_](const JsonData::Math::AddParamsInfo& params, Core::JSON::DecUInt16& sum) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const uint16_t _a{params.A};
                    const uint16_t _b{params.B};
                    uint16_t _sum{};

                    _errorCode = _impl_->Add(_a, _b, _sum);

                    if (_errorCode == Core::ERROR_NONE) {
                        sum = _sum;
                    }

                    return (_errorCode);
                });

            // Method: 'sub'
            _module_.Register<JsonData::Math::AddParamsInfo, Core::JSON::DecUInt16>(_T("sub"), 
                [_impl_](const JsonData::Math::AddParamsInfo& params, Core::JSON::DecUInt16& sum) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const uint16_t _a{params.A};
                    const uint16_t _b{params.B};
                    uint16_t _sum{};

                    _errorCode = _impl_->Sub(_a, _b, _sum);

                    if (_errorCode == Core::ERROR_NONE) {
                        sum = _sum;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("add"));
            _module_.Unregister(_T("sub"));
        }

        POP_WARNING()

    } // namespace JMath

} // namespace Exchange

} // namespace WPEFramework

