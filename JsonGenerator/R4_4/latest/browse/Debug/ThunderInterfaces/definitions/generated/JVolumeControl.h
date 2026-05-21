// Generated automatically from 'IVolumeControl.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_VolumeControl.h"
#include <interfaces/IVolumeControl.h>

namespace WPEFramework {

namespace Exchange {

    namespace JVolumeControl {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IVolumeControl* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JVolumeControl"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'muted' - Audio mute state
            _module_.Register<Core::JSON::Boolean, Core::JSON::Boolean>(_T("muted"), 
                [_impl_](const Core::JSON::Boolean& params, Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        bool _result{};

                        _errorCode = (static_cast<const IVolumeControl*>(_impl_))->Muted(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const bool _params{params};

                        _errorCode = _impl_->Muted(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'volume' - Audio volume level
            _module_.Register<Core::JSON::DecUInt8, Core::JSON::DecUInt8>(_T("volume"), 
                [_impl_](const Core::JSON::DecUInt8& params, Core::JSON::DecUInt8& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        uint8_t _result{};

                        _errorCode = (static_cast<const IVolumeControl*>(_impl_))->Volume(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const uint8_t _params{params};

                        _errorCode = _impl_->Volume(_params);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("muted"));
            _module_.Unregister(_T("volume"));
        }

        namespace Event {

            // Event: 'volume' - Signals volume change
            static void Volume(const JSONRPC& _module_, const JsonData::VolumeControl::VolumeParamsData& params)
            {
                _module_.Notify(_T("volume"), params);
            }

            // Event: 'volume' - Signals volume change
            static void Volume(const JSONRPC& _module_, const Core::JSON::DecUInt8& volume)
            {
                JsonData::VolumeControl::VolumeParamsData _params_;
                _params_.Volume = volume;

                Volume(_module_, _params_);
            }

            // Event: 'volume' - Signals volume change
            static void Volume(const JSONRPC& _module_, const uint8_t& volume)
            {
                JsonData::VolumeControl::VolumeParamsData _params_;
                _params_.Volume = volume;

                Volume(_module_, _params_);
            }

            // Event: 'muted' - Signals mute state change
            static void Muted(const JSONRPC& _module_, const JsonData::VolumeControl::MutedParamsData& params)
            {
                _module_.Notify(_T("muted"), params);
            }

            // Event: 'muted' - Signals mute state change
            static void Muted(const JSONRPC& _module_, const Core::JSON::Boolean& muted)
            {
                JsonData::VolumeControl::MutedParamsData _params_;
                _params_.Muted = muted;

                Muted(_module_, _params_);
            }

            // Event: 'muted' - Signals mute state change
            static void Muted(const JSONRPC& _module_, const bool& muted)
            {
                JsonData::VolumeControl::MutedParamsData _params_;
                _params_.Muted = muted;

                Muted(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JVolumeControl

} // namespace Exchange

} // namespace WPEFramework

