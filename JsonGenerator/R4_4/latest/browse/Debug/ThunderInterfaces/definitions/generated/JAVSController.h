// Generated automatically from 'IAVSClient.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_AVSController.h"
#include <interfaces/IAVSClient.h>

namespace WPEFramework {

namespace Exchange {

    namespace JAVSController {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IAVSController* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JAVSController"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'mute' - Mutes the audio output of AVS
            _module_.Register<Core::JSON::Boolean, void>(_T("mute"), 
                [_impl_](const Core::JSON::Boolean& muted) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const bool _muted{muted};

                    _errorCode = _impl_->Mute(_muted);

                    return (_errorCode);
                });

            // Method: 'record' - Starts or stops the voice recording, skipping keyword detection
            _module_.Register<Core::JSON::Boolean, void>(_T("record"), 
                [_impl_](const Core::JSON::Boolean& started) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const bool _started{started};

                    _errorCode = _impl_->Record(_started);

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("mute"));
            _module_.Unregister(_T("record"));
        }

        namespace Event {

            // Event: 'dialoguestatechange' - notifies about dialogue state changes
            static void DialogueStateChange(const JSONRPC& _module_, const Core::JSON::EnumType<Exchange::IAVSController::INotification::dialoguestate>& state)
            {
                _module_.Notify(_T("dialoguestatechange"), state);
            }

            // Event: 'dialoguestatechange' - notifies about dialogue state changes
            static void DialogueStateChange(const JSONRPC& _module_, const Exchange::IAVSController::INotification::dialoguestate& state)
            {
                Core::JSON::EnumType<Exchange::IAVSController::INotification::dialoguestate> _params_;
                _params_ = state;

                DialogueStateChange(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JAVSController

} // namespace Exchange

} // namespace WPEFramework

