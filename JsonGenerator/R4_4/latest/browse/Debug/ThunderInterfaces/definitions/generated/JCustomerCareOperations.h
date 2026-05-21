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

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, ICustomerCareOperations* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JCustomerCareOperations"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'factoryreset' - Executes all operations needed for a plugin's factory reset
            _module_.Register<void, void>(_T("factoryreset"), 
                [_impl_]() -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    _errorCode = _impl_->FactoryReset();

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("factoryreset"));
        }

        POP_WARNING()

    } // namespace JCustomerCareOperations

} // namespace Exchange

} // namespace WPEFramework

