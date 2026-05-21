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

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, IBluetoothAudioSink* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JBluetoothAudioSink"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'assign' - Assigns a Bluetooth device for audio playback
            _module_.Register<JsonData::BluetoothAudioSink::AssignParamsData, void>(_T("assign"), 
                [_impl_](const JsonData::BluetoothAudioSink::AssignParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _address{params.Address};

                    _errorCode = _impl_->Assign(_address);

                    return (_errorCode);
                });

            // Method: 'revoke' - Revokes a Bluetooth device from audio playback
            _module_.Register<void, void>(_T("revoke"), 
                [_impl_]() -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    _errorCode = _impl_->Revoke();

                    return (_errorCode);
                });

            // Property: 'latency' - Sink audio latency
            _module_.Register<JsonData::BluetoothAudioSink::LatencyData, Core::JSON::DecSInt16>(_T("latency"), 
                [_impl_](const JsonData::BluetoothAudioSink::LatencyData& params, Core::JSON::DecSInt16& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        // property get
                        int16_t _result{};

                        _errorCode = (static_cast<const IBluetoothAudioSink*>(_impl_))->Latency(_result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                        }

                    } else {
                        // property set
                        const int16_t _value{params.Value};

                        _errorCode = _impl_->Latency(_value);

                        result.Null(true);
                    }
                    return (_errorCode);
                });

            // Property: 'state' - Current audio sink state (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudioSink::state>>(_T("state"), 
                [_impl_](Core::JSON::EnumType<Exchange::IBluetoothAudioSink::state>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IBluetoothAudioSink::state _result{};

                    _errorCode = _impl_->State(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'type' - Audio sink type (r/o)
            _module_.Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudioSink::devicetype>>(_T("type"), 
                [_impl_](Core::JSON::EnumType<Exchange::IBluetoothAudioSink::devicetype>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IBluetoothAudioSink::devicetype _result{};

                    _errorCode = _impl_->Type(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'supportedcodecs' - Audio codecs supported by the sink (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::audiocodec>>>(_T("supportedcodecs"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::audiocodec>>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IBluetoothAudioSink::audiocodec, ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>* _result{};

                    _errorCode = _impl_->SupportedCodecs(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IBluetoothAudioSink::audiocodec _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Property: 'supporteddrms' - DRM schemes supported by the sink (r/o)
            _module_.Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::drmscheme>>>(_T("supporteddrms"), 
                [_impl_](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IBluetoothAudioSink::drmscheme>>& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    ::WPEFramework::RPC::IIteratorType<IBluetoothAudioSink::drmscheme, ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>* _result{};

                    _errorCode = _impl_->SupportedDRMs(_result);

                    if (_errorCode == Core::ERROR_NONE) {

                        if (_result != nullptr) {
                            Exchange::IBluetoothAudioSink::drmscheme _resultItem_{};
                            while (_result->Next(_resultItem_) == true) { result.Add() = _resultItem_; }
                            _result->Release();
                        }
                    }

                    return (_errorCode);
                });

            // Property: 'codec' - Properites of the currently used codec (r/o)
            _module_.Register<void, JsonData::BluetoothAudioSink::CodecPropertiesData>(_T("codec"), 
                [_impl_](JsonData::BluetoothAudioSink::CodecPropertiesData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IBluetoothAudioSink::CodecProperties _result{};

                    _errorCode = _impl_->Codec(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'drm' - Properties of the currently used DRM scheme (r/o)
            _module_.Register<void, JsonData::BluetoothAudioSink::DRMPropertiesData>(_T("drm"), 
                [_impl_](JsonData::BluetoothAudioSink::DRMPropertiesData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IBluetoothAudioSink::DRMProperties _result{};

                    _errorCode = _impl_->DRM(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

            // Property: 'stream' - Properties of the current output stream (r/o)
            _module_.Register<void, JsonData::BluetoothAudioSink::StreamPropertiesData>(_T("stream"), 
                [_impl_](JsonData::BluetoothAudioSink::StreamPropertiesData& result) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    // read-only property get
                    Exchange::IBluetoothAudioSink::StreamProperties _result{};

                    _errorCode = _impl_->Stream(_result);

                    if (_errorCode == Core::ERROR_NONE) {
                        result = _result;
                    }

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("assign"));
            _module_.Unregister(_T("revoke"));
            _module_.Unregister(_T("latency"));
            _module_.Unregister(_T("state"));
            _module_.Unregister(_T("type"));
            _module_.Unregister(_T("supportedcodecs"));
            _module_.Unregister(_T("supporteddrms"));
            _module_.Unregister(_T("codec"));
            _module_.Unregister(_T("drm"));
            _module_.Unregister(_T("stream"));
        }

        namespace Event {

            // Event: 'updated' - Signals audio sink state change or stream properties update
            static void Updated(const JSONRPC& _module_)
            {
                _module_.Notify(_T("updated"));
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JBluetoothAudioSink

} // namespace Exchange

} // namespace WPEFramework

