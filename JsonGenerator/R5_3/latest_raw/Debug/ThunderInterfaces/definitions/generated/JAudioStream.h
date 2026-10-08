// Generated automatically from 'IAudioStream.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_AudioStream.h"
#include <interfaces/IAudioStream.h>

namespace Thunder {

namespace Exchange {

    namespace JAudioStream {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        struct IHandler {
            virtual ~IHandler() = default;
            virtual void OnStateChangedEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
        };

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, IAudioStream* _implementation__, IHandler* _handler_)
        {
            ASSERT(_implementation__ != nullptr);
            ASSERT(_handler_ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JAudioStream"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Property: 'name' - Name of the stream (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String>(_T("name"),
                [_implementation__](Core::JSON::String& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    string _result_{};

                    _errorCode__ = _implementation__->Name(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'state' - Current state of the stream (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::EnumType<Exchange::IAudioStream::streamstate>>(_T("state"),
                [_implementation__](Core::JSON::EnumType<Exchange::IAudioStream::streamstate>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IAudioStream::streamstate _result_{};

                    _errorCode__ = _implementation__->State(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'capabilities' - List of codecs supported by the stream (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IAudioStream::codectype>>>(_T("capabilities"),
                [_implementation__](Core::JSON::ArrayType<Core::JSON::EnumType<Exchange::IAudioStream::codectype>>& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::IAudioStream::codectype _result_{};

                    _errorCode__ = _implementation__->Capabilities(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result.Set(true);
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'audioprofile' - Preferred profile of the stream
            _module__.PluginHost::JSONRPC::template Register<JsonData::AudioStream::ProfileData, JsonData::AudioStream::AudioprofileInfo>(_T("audioprofile"),
                [_implementation__](const JsonData::AudioStream::ProfileData& params, JsonData::AudioStream::AudioprofileInfo& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        Exchange::IAudioStream::audioprofile _result_{};

                        _errorCode__ = (static_cast<const IAudioStream*>(_implementation__))->Profile(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result.Set(true);
                            result = _result_;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const Exchange::IAudioStream::audioprofile _value_(params.Value);

                            _errorCode__ = _implementation__->Profile(_value_);

                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Property: 'time' - Stream position (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::DecUInt32>(_T("time"),
                [_implementation__](Core::JSON::DecUInt32& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    uint32_t _result_{};

                    _errorCode__ = _implementation__->Time(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

            // Property: 'speed' - Stream speed
            _module__.PluginHost::JSONRPC::template Register<JsonData::AudioStream::SpeedData, Core::JSON::DecUInt8>(_T("speed"),
                [_implementation__](const JsonData::AudioStream::SpeedData& params, Core::JSON::DecUInt8& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if (params.IsSet() == false) {
                        uint8_t _result_{};

                        _errorCode__ = (static_cast<const IAudioStream*>(_implementation__))->Speed(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {
                            result = _result_;
                        }
                    }
                    else {

                        if (params.IsDataValid() == false) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint8_t _value_{params.Value};

                            _errorCode__ = _implementation__->Speed(_value_);

                        }

                        result.Null(true);
                    }

                    return (_errorCode__);
                });

            // Register event status listeners...

            _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("audiotransmission"),
                [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                    _handler_->OnStateChangedEventRegistration(client_, status_);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("name"));
            _module__.PluginHost::JSONRPC::Unregister(_T("state"));
            _module__.PluginHost::JSONRPC::Unregister(_T("capabilities"));
            _module__.PluginHost::JSONRPC::Unregister(_T("audioprofile"));
            _module__.PluginHost::JSONRPC::Unregister(_T("time"));
            _module__.PluginHost::JSONRPC::Unregister(_T("speed"));

            // Unregister event status listeners...
            _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("audiotransmission"));
        }

        namespace Event {

            // Event: 'audioframe' - Provides audio data
            template<typename MODULE>
            static void Data(const MODULE& module_, const JsonData::AudioStream::DataParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("audioframe"), params, sendIfMethod_);
            }

            // Event: 'audioframe' - Provides audio data
            template<typename MODULE>
            static void Data(const MODULE& module_, const Core::JSON::DecUInt16& seq, const Core::JSON::DecUInt32& timestamp, const Core::JSON::DecUInt16& length, const Core::JSON::String& data, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AudioStream::DataParamsData params_;
                params_.Seq = seq;
                params_.Timestamp = timestamp;
                params_.Length = length;
                params_.Data = data;

                Data(module_, params_, sendIfMethod_);
            }

            // Event: 'audioframe' - Provides audio data
            template<typename MODULE>
            static void Data(const MODULE& module_, const Core::OptionalType<uint16_t>& seq, const Core::OptionalType<uint32_t>& timestamp, const uint16_t length, const uint8_t* data, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AudioStream::DataParamsData params_;

                if (seq.IsSet() == true) {
                    params_.Seq = seq.Value();
                }

                if (timestamp.IsSet() == true) {
                    params_.Timestamp = timestamp.Value();
                }
                params_.Length = length;
                string _dataEncoded__;
                ASSERT(data != nullptr);
                Core::ToString(data, length, true, _dataEncoded__);
                params_.Data = std::move(_dataEncoded__);

                Data(module_, params_, sendIfMethod_);
            }

            // legacy array as string version
            // Event: 'audioframe' - Provides audio data
            template<typename MODULE>
            static void Data(const MODULE& module_, const Core::OptionalType<uint16_t>& seq, const Core::OptionalType<uint32_t>& timestamp, const uint16_t length, const string& data, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AudioStream::DataParamsData params_;

                if (seq.IsSet() == true) {
                    params_.Seq = seq.Value();
                }

                if (timestamp.IsSet() == true) {
                    params_.Timestamp = timestamp.Value();
                }
                params_.Length = length;
                params_.Data = data;

                Data(module_, params_, sendIfMethod_);
            }

            // Event: 'audiotransmission' - Signals state of the stream
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const JsonData::AudioStream::StateChangedParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("audiotransmission"), params, sendIfMethod_);
            }

            // Event: 'audiotransmission' - Signals state of the stream
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const JsonData::AudioStream::StateChangedParamsData& params, const string& client_)
            {
                module_.Notify(_T("audiotransmission"), params, [&client_](const string& designator_) -> bool {
                    return ((client_ == designator_));
                });
            }

            // Event: 'audiotransmission' - Signals state of the stream
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const Core::JSON::EnumType<Exchange::IAudioStream::streamstate>& state, const JsonData::AudioStream::AudioprofileInfo& profile, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AudioStream::StateChangedParamsData params_;
                params_.State = state;
                params_.Profile = profile;

                StateChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'audiotransmission' - Signals state of the stream
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const Core::JSON::EnumType<Exchange::IAudioStream::streamstate>& state, const JsonData::AudioStream::AudioprofileInfo& profile, const string& client_)
            {
                JsonData::AudioStream::StateChangedParamsData params_;
                params_.State = state;
                params_.Profile = profile;

                StateChanged(module_, params_, client_);
            }

            // Event: 'audiotransmission' - Signals state of the stream
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const IAudioStream::streamstate state, const Core::OptionalType<IAudioStream::audioprofile>& profile, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::AudioStream::StateChangedParamsData params_;
                params_.State = state;

                if (profile.IsSet() == true) {
                    params_.Profile = profile.Value();
                }

                StateChanged(module_, params_, sendIfMethod_);
            }

            // Event: 'audiotransmission' - Signals state of the stream
            template<typename MODULE>
            static void StateChanged(const MODULE& module_, const IAudioStream::streamstate state, const Core::OptionalType<IAudioStream::audioprofile>& profile, const string& client_)
            {
                JsonData::AudioStream::StateChangedParamsData params_;
                params_.State = state;

                if (profile.IsSet() == true) {
                    params_.Profile = profile.Value();
                }

                StateChanged(module_, params_, client_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JAudioStream

} // namespace Exchange

} // namespace Thunder

