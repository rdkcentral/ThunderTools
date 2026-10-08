// Generated automatically from 'IPlayerInfo.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_PlayerProperties.h"
#include <interfaces/IPlayerInfo.h>

namespace Thunder {

namespace Exchange {

    namespace JPlayerProperties {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IPlayerProperties* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JPlayerProperties"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'audiocodecs' - Query Audio Codecs List (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IPlayerProperties::AudioCodec>>>(_T("audiocodecs"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IPlayerProperties::AudioCodec>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<IPlayerProperties::AudioCodec, ID_PLAYER_PROPERTIES_AUDIO>* _result_{};

                    _errorCode__ = _implementation__->AudioCodecs(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IPlayerProperties::AudioCodec _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'videocodecs' - Query Video Codecs List (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IPlayerProperties::VideoCodec>>>(_T("videocodecs"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IPlayerProperties::VideoCodec>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    ::Thunder::RPC::IIteratorType<IPlayerProperties::VideoCodec, ID_PLAYER_PROPERTIES_VIDEO>* _result_{};

                    _errorCode__ = _implementation__->VideoCodecs(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);

                        if (_result_ != nullptr) {
                            Exchange::IPlayerProperties::VideoCodec _resultItem__{};
                            while (_result_->Next(_resultItem__) == true) { result.Add() = _resultItem__; }
                            _result_->Release();
                        }
                    }

                    return (_errorCode__);
                });

            // Property: 'resolution' - Current Video playback resolution (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IPlayerProperties::PlaybackResolution>>(_T("resolution"),
                [_implementation__](Core::JSON::EnumType<Exchange::IPlayerProperties::PlaybackResolution>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IPlayerProperties::PlaybackResolution _result_{};

                    _errorCode__ = _implementation__->Resolution(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'isaudioequivalenceenabled' - Checks Loudness Equivalence in platform (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::Boolean>(_T("isaudioequivalenceenabled"),
                [_implementation__](Core::JSON::Boolean& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    bool _result_{};

                    _errorCode__ = _implementation__->IsAudioEquivalenceEnabled(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("audiocodecs"));
            _module__.PluginHost::JSONRPC::Unregister(_T("videocodecs"));
            _module__.PluginHost::JSONRPC::Unregister(_T("resolution"));
            _module__.PluginHost::JSONRPC::Unregister(_T("isaudioequivalenceenabled"));
        }

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JPlayerProperties

} // namespace Exchange

} // namespace Thunder

