// Generated automatically from 'IAmazonPrime.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include <interfaces/IAmazonPrime.h>

namespace WPEFramework {

namespace Exchange {

    namespace JAmazonPrime {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IAmazonPrime* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JAmazonPrime"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'send' - Send a message over the message bus to ignition
            _module_.Register<Core::JSON::String, void>(_T("send"), 
                [_impl_](const Core::JSON::String& message) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _message{message};

                    _errorCode = _impl_->Send(_message);

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("send"));
        }

        namespace Event {

            // Event: 'receive' - Receive a message from the generic message bus
            static void Receive(const JSONRPC& _module_, const Core::JSON::String& message)
            {
                _module_.Notify(_T("receive"), message);
            }

            // Event: 'receive' - Receive a message from the generic message bus
            static void Receive(const JSONRPC& _module_, const string& message)
            {
                Core::JSON::String _params_;
                _params_ = message;

                Receive(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JAmazonPrime

} // namespace Exchange

} // namespace WPEFramework

