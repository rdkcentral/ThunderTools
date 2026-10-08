// Generated automatically from 'IBluetoothAudio.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BluetoothAudioSink.h"
#include <interfaces/IBluetoothAudio.h>

namespace Thunder {

namespace Exchange {

    namespace BluetoothAudio {

        namespace JSink {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IBluetoothAudio::ISink* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSink"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'sink::assign' - Assigns a Bluetooth sink device for audio playback
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothAudio::Sink::AssignParamsData, void>(_T("sink::assign"),
                    [_implementation__](const JsonData::BluetoothAudio::Sink::AssignParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _address_{params.Address};

                            _errorCode__ = _implementation__->Assign(_address_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'sink::revoke' - Revokes a Bluetooth sink device from audio playback
                _module__.PluginHost::JSONRPC::template Register<void, void>(_T("sink::revoke"),
                    [_implementation__]() -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        _errorCode__ = _implementation__->Revoke();

                        return (_errorCode__);
                    });

                // Property: 'sink::state' - Current state o the audio sink device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudio::state>>(_T("sink::state"),
                    [_implementation__](Core::JSON::EnumType<Exchange::IBluetoothAudio::state>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::state _result_{};

                        _errorCode__ = _implementation__->State(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::device' - Bluetooth address of the audio sink device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("sink::device"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->Device(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::type' - Type of the audio sink device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudio::ISink::devicetype>>(_T("sink::type"),
                    [_implementation__](Core::JSON::EnumType<Exchange::IBluetoothAudio::ISink::devicetype>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::ISink::devicetype _result_{};

                        _errorCode__ = _implementation__->Type(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::latency' - Latency of the audio sink device
                _module__.PluginHost::JSONRPC::template Register<JsonData::BluetoothAudio::Sink::LatencyData, Core::JSON::DecSInt16>(_T("sink::latency"),
                    [_implementation__](const JsonData::BluetoothAudio::Sink::LatencyData& params, Core::JSON::DecSInt16& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            int16_t _result_{};

                            _errorCode__ = (static_cast<const IBluetoothAudio::ISink*>(_implementation__))->Latency(_result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }
                        else {

                            if (params.IsDataValid() == false) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                const int16_t _value_{params.Value};

                                _errorCode__ = _implementation__->Latency(_value_);

                            }

                            result.Null(true);
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::supportedcodecs' - Audio codecs supported by the audio sink device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudio::audiocodec>>>(_T("sink::supportedcodecs"),
                    [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudio::audiocodec>>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::audiocodec _result_{};

                        _errorCode__ = _implementation__->SupportedCodecs(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::supporteddrms' - DRM schemes supported by the audio sink device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudio::drmscheme>>>(_T("sink::supporteddrms"),
                    [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudio::drmscheme>>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::drmscheme _result_{};

                        _errorCode__ = _implementation__->SupportedDRMs(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::codec' - Properites of the currently used audio codec (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothAudio::Sink::CodecPropertiesData>(_T("sink::codec"),
                    [_implementation__](JsonData::BluetoothAudio::Sink::CodecPropertiesData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::CodecProperties _result_{};

                        _errorCode__ = _implementation__->Codec(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::drm' - Properites of the currently used DRM scheme (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothAudio::Sink::DRMPropertiesData>(_T("sink::drm"),
                    [_implementation__](JsonData::BluetoothAudio::Sink::DRMPropertiesData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::DRMProperties _result_{};

                        _errorCode__ = _implementation__->DRM(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'sink::stream' - Properties of the currently transmitted audio stream (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothAudio::Sink::StreamPropertiesData>(_T("sink::stream"),
                    [_implementation__](JsonData::BluetoothAudio::Sink::StreamPropertiesData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::StreamProperties _result_{};

                        _errorCode__ = _implementation__->Stream(_result_);

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
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::assign"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::revoke"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::state"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::device"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::type"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::latency"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::supportedcodecs"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::supporteddrms"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::codec"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::drm"));
                _module__.PluginHost::JSONRPC::Unregister(_T("sink::stream"));
            }

            namespace Event {

                // Event: 'sink::statechanged' - Signals audio sink state change
                template<typename MODULE>
                static void StateChanged(const MODULE& module_, const JsonData::BluetoothAudio::Sink::StateChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("sink::statechanged"), params, sendIfMethod_);
                }

                // Event: 'sink::statechanged' - Signals audio sink state change
                template<typename MODULE>
                static void StateChanged(const MODULE& module_, const Core::JSON::EnumType<Exchange::IBluetoothAudio::state>& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothAudio::Sink::StateChangedParamsData params_;
                    params_.State = state;

                    StateChanged(module_, params_, sendIfMethod_);
                }

                // Event: 'sink::statechanged' - Signals audio sink state change
                template<typename MODULE>
                static void StateChanged(const MODULE& module_, const IBluetoothAudio::state state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothAudio::Sink::StateChangedParamsData params_;
                    params_.State = state;

                    StateChanged(module_, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JSink

    } // namespace BluetoothAudio

} // namespace Exchange

} // namespace Thunder

