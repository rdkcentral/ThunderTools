// Generated automatically from 'IAmazonPrime.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include <interfaces/IAmazonPrime.h>

namespace Thunder {

namespace Exchange {

    namespace JAmazonPrime {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IAmazonPrime* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JAmazonPrime"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'send' - Send a message over the message bus to ignition
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, void>(_T("send"),
                [_implementation__](const Core::JSON::String& message) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (message.IsSet() == false) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _message_{message};

                        _errorCode__ = _implementation__->Send(_message_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("send"));
        }

        namespace Event {

            // Event: 'receive' - Receive a message from the generic message bus
            template<typename MODULE>
            static void Receive(const MODULE& module_, const Core::JSON::String& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("receive"), message, sendIfMethod_);
            }

            // Event: 'receive' - Receive a message from the generic message bus
            template<typename MODULE>
            static void Receive(const MODULE& module_, const string& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                Core::JSON::String params_;
                params_ = message;

                Receive(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JAmazonPrime

} // namespace Exchange

} // namespace Thunder

