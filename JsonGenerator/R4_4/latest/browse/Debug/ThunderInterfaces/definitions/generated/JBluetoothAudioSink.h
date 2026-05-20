// Generated automatically from 'IBluetoothAudio.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BluetoothAudioSink.h"
#include <interfaces/IBluetoothAudio.h>

namespace WPEFramework {

namespace Exchange {

    namespace JBluetoothAudioSink {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IBluetoothAudioSink* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JBluetoothAudioSink"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'assign' - Assigns a Bluetooth device for audio playback
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothAudioSink::AssignParamsData, void>(_T("assign"),
                [_implementation__](const JsonData::BluetoothAudioSink::AssignParamsData& params) -> uint32_t {
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

            // Method: 'revoke' - Revokes a Bluetooth device from audio playback
            _module__.PluginHost::JSONRPC::Register<void, void>(_T("revoke"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->Revoke();

                    return (_errorCode__);
                });

            // Property: 'latency' - Sink audio latency
            _module__.PluginHost::JSONRPC::Register<JsonData::BluetoothAudioSink::LatencyData, Core::JSON::DecSInt16>(_T("latency"),
                [_implementation__](const JsonData::BluetoothAudioSink::LatencyData& params, Core::JSON::DecSInt16& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        int16_t _result_{};

                        _errorCode__ = (static_cast<const IBluetoothAudioSink*>(_implementation__))->Latency(_result_);

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

            // Property: 'state' - Current audio sink state (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudioSink::state>>(_T("state"),
                [_implementation__](Core::JSON::EnumType<Exchange::IBluetoothAudioSink::state>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IBluetoothAudioSink::state _result_{};

                    _errorCode__ = _implementation__->State(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'type' - Audio sink type (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudioSink::devicetype>>(_T("type"),
                [_implementation__](Core::JSON::EnumType<Exchange::IBluetoothAudioSink::devicetype>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IBluetoothAudioSink::devicetype _result_{};

                    _errorCode__ = _implementation__->Type(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'supportedcodecs' - Audio codecs supported by the sink (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::audiocodec>>>(_T("supportedcodecs"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::audiocodec>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::WPEFramework::RPC::IIteratorType<IBluetoothAudioSink::audiocodec, ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>* _result_{};

                    _errorCode__ = _implementation__->SupportedCodecs(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IBluetoothAudioSink::audiocodec _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'supporteddrms' - DRM schemes supported by the sink (r/o)
            _module__.PluginHost::JSONRPC::Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::drmscheme>>>(_T("supporteddrms"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::drmscheme>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::WPEFramework::RPC::IIteratorType<IBluetoothAudioSink::drmscheme, ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>* _result_{};

                    _errorCode__ = _implementation__->SupportedDRMs(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IBluetoothAudioSink::drmscheme _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'codec' - Properites of the currently used codec (r/o)
            _module__.PluginHost::JSONRPC::Register<void, JsonData::BluetoothAudioSink::CodecPropertiesData>(_T("codec"),
                [_implementation__](JsonData::BluetoothAudioSink::CodecPropertiesData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IBluetoothAudioSink::CodecProperties _result_{};

                    _errorCode__ = _implementation__->Codec(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'drm' - Properties of the currently used DRM scheme (r/o)
            _module__.PluginHost::JSONRPC::Register<void, JsonData::BluetoothAudioSink::DRMPropertiesData>(_T("drm"),
                [_implementation__](JsonData::BluetoothAudioSink::DRMPropertiesData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IBluetoothAudioSink::DRMProperties _result_{};

                    _errorCode__ = _implementation__->DRM(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'stream' - Properties of the current output stream (r/o)
            _module__.PluginHost::JSONRPC::Register<void, JsonData::BluetoothAudioSink::StreamPropertiesData>(_T("stream"),
                [_implementation__](JsonData::BluetoothAudioSink::StreamPropertiesData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IBluetoothAudioSink::StreamProperties _result_{};

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
            _module__.PluginHost::JSONRPC::Unregister(_T("assign"));
            _module__.PluginHost::JSONRPC::Unregister(_T("revoke"));
            _module__.PluginHost::JSONRPC::Unregister(_T("latency"));
            _module__.PluginHost::JSONRPC::Unregister(_T("state"));
            _module__.PluginHost::JSONRPC::Unregister(_T("type"));
            _module__.PluginHost::JSONRPC::Unregister(_T("supportedcodecs"));
            _module__.PluginHost::JSONRPC::Unregister(_T("supporteddrms"));
            _module__.PluginHost::JSONRPC::Unregister(_T("codec"));
            _module__.PluginHost::JSONRPC::Unregister(_T("drm"));
            _module__.PluginHost::JSONRPC::Unregister(_T("stream"));
        }

        namespace Event {

            // Event: 'updated' - Signals audio sink state change or stream properties update
            template<typename MODULE>
            static void Updated(const MODULE& module_, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("updated"), sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JBluetoothAudioSink

} // namespace Exchange

} // namespace WPEFramework

