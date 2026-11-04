// Generated automatically from 'IVolumeControl.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_VolumeControl.h"
#include <interfaces/IVolumeControl.h>

namespace Thunder {

namespace Exchange {

    namespace JVolumeControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IVolumeControl* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JVolumeControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'muted' - Audio mute state
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::Boolean, Core::JSON::Boolean>(_T("muted"),
                [_implementation__](const Core::JSON::Boolean& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        bool _result_{};

                        _errorCode__ = (static_cast<const IVolumeControl*>(_implementation__))->Muted(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const bool _params_{params};

                        _errorCode__ = _implementation__->Muted(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'volume' - Audio volume level
            _module__.PluginHost::JSONRPC::template Register<Core::JSON::DecUInt8, Core::JSON::DecUInt8>(_T("volume"),
                [_implementation__](const Core::JSON::DecUInt8& params, Core::JSON::DecUInt8& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        uint8_t _result_{};

                        _errorCode__ = (static_cast<const IVolumeControl*>(_implementation__))->Volume(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {
                        const uint8_t _params_{params};

                        _errorCode__ = _implementation__->Volume(_params_);

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("muted"));
            _module__.PluginHost::JSONRPC::Unregister(_T("volume"));
        }

        namespace Event {

            // Event: 'volume' - Signals volume change
            template<typename MODULE>
            static void Volume(const MODULE& module_, const JsonData::VolumeControl::VolumeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("volume"), params, sendIfMethod_);
            }

            // Event: 'volume' - Signals volume change
            template<typename MODULE>
            static void Volume(const MODULE& module_, const Core::JSON::DecUInt8& volume, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::VolumeControl::VolumeParamsData params_;
                params_.Volume = volume;

                Volume(module_, params_, sendIfMethod_);
            }

            // Event: 'volume' - Signals volume change
            template<typename MODULE>
            static void Volume(const MODULE& module_, const uint8_t volume, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::VolumeControl::VolumeParamsData params_;
                params_.Volume = volume;

                Volume(module_, params_, sendIfMethod_);
            }

            // Event: 'muted' - Signals mute state change
            template<typename MODULE>
            static void Muted(const MODULE& module_, const JsonData::VolumeControl::MutedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("muted"), params, sendIfMethod_);
            }

            // Event: 'muted' - Signals mute state change
            template<typename MODULE>
            static void Muted(const MODULE& module_, const Core::JSON::Boolean& muted, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::VolumeControl::MutedParamsData params_;
                params_.Muted = muted;

                Muted(module_, params_, sendIfMethod_);
            }

            // Event: 'muted' - Signals mute state change
            template<typename MODULE>
            static void Muted(const MODULE& module_, const bool muted, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::VolumeControl::MutedParamsData params_;
                params_.Muted = muted;

                Muted(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JVolumeControl

} // namespace Exchange

} // namespace Thunder

