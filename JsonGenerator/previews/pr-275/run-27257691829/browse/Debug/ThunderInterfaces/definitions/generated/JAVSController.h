// Generated automatically from 'IAVSClient.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_AVSController.h"
#include <interfaces/IAVSClient.h>

namespace Thunder {

namespace Exchange {

    namespace JAVSController {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IAVSController* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JAVSController"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'mute' - Mutes the audio output of AVS
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::Boolean, void>(_T("mute"),
                [_implementation__](const Core::JSON::Boolean& muted) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (muted.IsSet() == false) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _muted_{muted};

                        _errorCode__ = _implementation__->Mute(_muted_);

                    }

                    return (_errorCode__);
                });

            // Method: 'record' - Starts or stops the voice recording, skipping keyword detection
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::Boolean, void>(_T("record"),
                [_implementation__](const Core::JSON::Boolean& started) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (started.IsSet() == false) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const bool _started_{started};

                        _errorCode__ = _implementation__->Record(_started_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("mute"));
            _module__.PluginHost::JSONRPC::Unregister(_T("record"));
        }

        namespace Event {

            // Event: 'dialoguestatechange' - Notifies about dialogue state changes
            template<typename MODULE>
            static void DialogueStateChange(const MODULE& module_, const Core::JSON::EnumType<Exchange::IAVSController::INotification::dialoguestate>& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("dialoguestatechange"), state, sendIfMethod_);
            }

            // Event: 'dialoguestatechange' - Notifies about dialogue state changes
            template<typename MODULE>
            static void DialogueStateChange(const MODULE& module_, const IAVSController::INotification::dialoguestate state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                Core::JSON::EnumType<Exchange::IAVSController::INotification::dialoguestate> params_;
                params_ = state;

                DialogueStateChange(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JAVSController

} // namespace Exchange

} // namespace Thunder

