// Generated automatically from 'ICustomerCareOperations.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include <interfaces/ICustomerCareOperations.h>

namespace WPEFramework {

namespace Exchange {

    namespace JCustomerCareOperations {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ICustomerCareOperations* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JCustomerCareOperations"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'factoryreset' - Executes all operations needed for a plugin's factory reset
            _module__.PluginHost::JSONRPC::Register<void, void>(_T("factoryreset"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->FactoryReset();

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("factoryreset"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JCustomerCareOperations

} // namespace Exchange

} // namespace WPEFramework

