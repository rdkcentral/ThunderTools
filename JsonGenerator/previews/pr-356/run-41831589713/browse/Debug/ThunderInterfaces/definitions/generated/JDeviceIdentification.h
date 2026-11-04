// Generated automatically from 'IDeviceIdentification.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_DeviceIdentification.h"
#include <interfaces/IDeviceIdentification.h>

namespace Thunder {

namespace Exchange {

    namespace JDeviceIdentification {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IDeviceIdentification* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JDeviceIdentification"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'deviceidentification' - Get device paltform specific information (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, JsonData::DeviceIdentification::DeviceInfoData>(_T("deviceidentification"),
                [_implementation__](JsonData::DeviceIdentification::DeviceInfoData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IDeviceIdentification::DeviceInfo _result_{};

                    _errorCode__ = _implementation__->Identification(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);
                        result = _result_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("deviceidentification"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JDeviceIdentification

} // namespace Exchange

} // namespace Thunder

