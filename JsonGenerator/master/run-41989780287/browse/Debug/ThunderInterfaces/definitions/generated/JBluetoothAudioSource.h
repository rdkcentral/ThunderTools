// Generated automatically from 'IBluetoothAudio.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_BluetoothAudioSource.h"
#include <interfaces/IBluetoothAudio.h>

namespace Thunder {

namespace Exchange {

    namespace BluetoothAudio {

        namespace JSource {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IBluetoothAudio::ISource* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSource"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Property: 'source::state' - Current state of the source device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudio::state>>(_T("source::state"),
                    [_implementation__](Core::JSON::EnumType<Exchange::IBluetoothAudio::state>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::state _result_{};

                        _errorCode__ = _implementation__->State(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'source::device' - Bluetooth address of the source device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("source::device"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->Device(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'source::type' - Type of the audio source device (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IBluetoothAudio::ISource::devicetype>>(_T("source::type"),
                    [_implementation__](Core::JSON::EnumType<Exchange::IBluetoothAudio::ISource::devicetype>& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::ISource::devicetype _result_{};

                        _errorCode__ = _implementation__->Type(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'source::codec' - Properites of the currently used codec (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothAudio::Source::CodecPropertiesData>(_T("source::codec"),
                    [_implementation__](JsonData::BluetoothAudio::Source::CodecPropertiesData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::CodecProperties _result_{};

                        _errorCode__ = _implementation__->Codec(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'source::drm' - Properties of the currently used DRM scheme (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothAudio::Source::DRMPropertiesData>(_T("source::drm"),
                    [_implementation__](JsonData::BluetoothAudio::Source::DRMPropertiesData& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        Exchange::IBluetoothAudio::DRMProperties _result_{};

                        _errorCode__ = _implementation__->DRM(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }

                        return (_errorCode__);
                    });

                // Property: 'source::stream' - Properites of the currently transmitted audio stream (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, JsonData::BluetoothAudio::Source::StreamPropertiesData>(_T("source::stream"),
                    [_implementation__](JsonData::BluetoothAudio::Source::StreamPropertiesData& result) -> uint32_t {
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
                _module__.PluginHost::JSONRPC::Unregister(_T("source::state"));
                _module__.PluginHost::JSONRPC::Unregister(_T("source::device"));
                _module__.PluginHost::JSONRPC::Unregister(_T("source::type"));
                _module__.PluginHost::JSONRPC::Unregister(_T("source::codec"));
                _module__.PluginHost::JSONRPC::Unregister(_T("source::drm"));
                _module__.PluginHost::JSONRPC::Unregister(_T("source::stream"));
            }

            namespace Event {

                // Event: 'source::statechanged' - Signals audio source state change
                template<typename MODULE>
                static void StateChanged(const MODULE& module_, const JsonData::BluetoothAudio::Source::StateChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("source::statechanged"), params, sendIfMethod_);
                }

                // Event: 'source::statechanged' - Signals audio source state change
                template<typename MODULE>
                static void StateChanged(const MODULE& module_, const Core::JSON::EnumType<Exchange::IBluetoothAudio::state>& state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothAudio::Source::StateChangedParamsData params_;
                    params_.State = state;

                    StateChanged(module_, params_, sendIfMethod_);
                }

                // Event: 'source::statechanged' - Signals audio source state change
                template<typename MODULE>
                static void StateChanged(const MODULE& module_, const IBluetoothAudio::state state, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::BluetoothAudio::Source::StateChangedParamsData params_;
                    params_.State = state;

                    StateChanged(module_, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JSource

    } // namespace BluetoothAudio

} // namespace Exchange

} // namespace Thunder

