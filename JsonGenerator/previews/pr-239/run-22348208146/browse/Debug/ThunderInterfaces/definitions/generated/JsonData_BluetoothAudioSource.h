// C++ types for Source API.
// Generated automatically from 'IBluetoothAudio.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBluetoothAudio.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace BluetoothAudio {

        namespace Source {

            // Method params/result classes
            //

            class CodecPropertiesData : public Core::JSON::Container {
            public:
                CodecPropertiesData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                CodecPropertiesData(const CodecPropertiesData& _other)
                    : Core::JSON::Container()
                    , Codec(_other.Codec)
                    , Settings(_other.Settings)
                {
                    _Init();
                }

                CodecPropertiesData(CodecPropertiesData&& _other) noexcept
                    : Core::JSON::Container()
                    , Codec(std::move(_other.Codec))
                    , Settings(std::move(_other.Settings))
                {
                    _Init();
                }

                CodecPropertiesData(const Exchange::IBluetoothAudio::CodecProperties& _other)
                    : Core::JSON::Container()
                {
                    Codec = _other.Codec;
                    if (_other.Settings.empty() == false) {
                        Settings = _other.Settings;
                    }
                    _Init();
                }

                CodecPropertiesData& operator=(const CodecPropertiesData& _rhs)
                {
                    Codec = _rhs.Codec;
                    if (_rhs.Settings.Value().empty() == false) {
                        Settings = _rhs.Settings;
                    }
                    return (*this);
                }

                CodecPropertiesData& operator=(CodecPropertiesData&& _rhs) noexcept
                {
                    Codec = std::move(_rhs.Codec);
                    Settings = std::move(_rhs.Settings);
                    return (*this);
                }

                CodecPropertiesData& operator=(const Exchange::IBluetoothAudio::CodecProperties& _rhs)
                {
                    Codec = _rhs.Codec;
                    if (_rhs.Settings.empty() == false) {
                        Settings = _rhs.Settings;
                    }
                    return (*this);
                }

                operator Exchange::IBluetoothAudio::CodecProperties() const
                {
                    Exchange::IBluetoothAudio::CodecProperties _value{};
                    _value.Codec = Codec;
                    _value.Settings = Settings;
                    return (_value);
                }

                ~CodecPropertiesData() = default;

            public:
                bool IsDataValid() const
                {
                    return (Codec.IsSet() == true);
                }

            private:
                void _Init()
                {
                    Add(_T("codec"), &Codec);
                    Add(_T("settings"), &Settings);
                    Settings.SetQuoted(false);
                }

            public:
                Core::JSON::EnumType<Exchange::IBluetoothAudio::audiocodec> Codec; // Audio codec used
                Core::JSON::String Settings; // Codec-specific audio quality preset, compression profile, etc
            }; // class CodecPropertiesData

            class DRMPropertiesData : public Core::JSON::Container {
            public:
                DRMPropertiesData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                DRMPropertiesData(const DRMPropertiesData& _other)
                    : Core::JSON::Container()
                    , DRM(_other.DRM)
                    , Settings(_other.Settings)
                {
                    _Init();
                }

                DRMPropertiesData(DRMPropertiesData&& _other) noexcept
                    : Core::JSON::Container()
                    , DRM(std::move(_other.DRM))
                    , Settings(std::move(_other.Settings))
                {
                    _Init();
                }

                DRMPropertiesData(const Exchange::IBluetoothAudio::DRMProperties& _other)
                    : Core::JSON::Container()
                {
                    DRM = _other.DRM;
                    if (_other.Settings.empty() == false) {
                        Settings = _other.Settings;
                    }
                    _Init();
                }

                DRMPropertiesData& operator=(const DRMPropertiesData& _rhs)
                {
                    DRM = _rhs.DRM;
                    if (_rhs.Settings.Value().empty() == false) {
                        Settings = _rhs.Settings;
                    }
                    return (*this);
                }

                DRMPropertiesData& operator=(DRMPropertiesData&& _rhs) noexcept
                {
                    DRM = std::move(_rhs.DRM);
                    Settings = std::move(_rhs.Settings);
                    return (*this);
                }

                DRMPropertiesData& operator=(const Exchange::IBluetoothAudio::DRMProperties& _rhs)
                {
                    DRM = _rhs.DRM;
                    if (_rhs.Settings.empty() == false) {
                        Settings = _rhs.Settings;
                    }
                    return (*this);
                }

                operator Exchange::IBluetoothAudio::DRMProperties() const
                {
                    Exchange::IBluetoothAudio::DRMProperties _value{};
                    _value.DRM = DRM;
                    _value.Settings = Settings;
                    return (_value);
                }

                ~DRMPropertiesData() = default;

            public:
                bool IsDataValid() const
                {
                    return (DRM.IsSet() == true);
                }

            private:
                void _Init()
                {
                    Add(_T("drm"), &DRM);
                    Add(_T("settings"), &Settings);
                    Settings.SetQuoted(false);
                }

            public:
                Core::JSON::EnumType<Exchange::IBluetoothAudio::drmscheme> DRM; // Content protection scheme used
                Core::JSON::String Settings; // DRM-specific content protection level, encoding rules, etc
            }; // class DRMPropertiesData

            class StateChangedParamsData : public Core::JSON::Container {
            public:
                StateChangedParamsData()
                    : Core::JSON::Container()
                {
                    Add(_T("state"), &State);
                }

                StateChangedParamsData(const StateChangedParamsData&) = delete;
                StateChangedParamsData(StateChangedParamsData&&) noexcept  = delete;

                StateChangedParamsData& operator=(const StateChangedParamsData&) = delete;
                StateChangedParamsData& operator=(StateChangedParamsData&&) noexcept  = delete;

                ~StateChangedParamsData() = default;

            public:
                bool IsDataValid() const
                {
                    return (State.IsSet() == true);
                }

            public:
                Core::JSON::EnumType<Exchange::IBluetoothAudio::state> State; // Changed BluetoothAudio State
            }; // class StateChangedParamsData

            class StreamPropertiesData : public Core::JSON::Container {
            public:
                StreamPropertiesData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                StreamPropertiesData(const StreamPropertiesData& _other)
                    : Core::JSON::Container()
                    , SampleRate(_other.SampleRate)
                    , BitRate(_other.BitRate)
                    , Channels(_other.Channels)
                    , Resolution(_other.Resolution)
                    , IsResampled(_other.IsResampled)
                {
                    _Init();
                }

                StreamPropertiesData(StreamPropertiesData&& _other) noexcept
                    : Core::JSON::Container()
                    , SampleRate(std::move(_other.SampleRate))
                    , BitRate(std::move(_other.BitRate))
                    , Channels(std::move(_other.Channels))
                    , Resolution(std::move(_other.Resolution))
                    , IsResampled(std::move(_other.IsResampled))
                {
                    _Init();
                }

                StreamPropertiesData(const Exchange::IBluetoothAudio::StreamProperties& _other)
                    : Core::JSON::Container()
                {
                    SampleRate = _other.SampleRate;
                    BitRate = _other.BitRate;
                    Channels = _other.Channels;
                    Resolution = _other.Resolution;
                    IsResampled = _other.IsResampled;
                    _Init();
                }

                StreamPropertiesData& operator=(const StreamPropertiesData& _rhs)
                {
                    SampleRate = _rhs.SampleRate;
                    BitRate = _rhs.BitRate;
                    Channels = _rhs.Channels;
                    Resolution = _rhs.Resolution;
                    IsResampled = _rhs.IsResampled;
                    return (*this);
                }

                StreamPropertiesData& operator=(StreamPropertiesData&& _rhs) noexcept
                {
                    SampleRate = std::move(_rhs.SampleRate);
                    BitRate = std::move(_rhs.BitRate);
                    Channels = std::move(_rhs.Channels);
                    Resolution = std::move(_rhs.Resolution);
                    IsResampled = std::move(_rhs.IsResampled);
                    return (*this);
                }

                StreamPropertiesData& operator=(const Exchange::IBluetoothAudio::StreamProperties& _rhs)
                {
                    SampleRate = _rhs.SampleRate;
                    BitRate = _rhs.BitRate;
                    Channels = _rhs.Channels;
                    Resolution = _rhs.Resolution;
                    IsResampled = _rhs.IsResampled;
                    return (*this);
                }

                operator Exchange::IBluetoothAudio::StreamProperties() const
                {
                    Exchange::IBluetoothAudio::StreamProperties _value{};
                    _value.SampleRate = SampleRate;
                    _value.BitRate = BitRate;
                    _value.Channels = Channels;
                    _value.Resolution = Resolution;
                    _value.IsResampled = IsResampled;
                    return (_value);
                }

                ~StreamPropertiesData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((SampleRate.IsSet() == true) && (BitRate.IsSet() == true) && (Channels.IsSet() == true) && (Resolution.IsSet() == true) && (IsResampled.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("samplerate"), &SampleRate);
                    Add(_T("bitrate"), &BitRate);
                    Add(_T("channels"), &Channels);
                    Add(_T("resolution"), &Resolution);
                    Add(_T("isresampled"), &IsResampled);
                }

            public:
                Core::JSON::DecUInt32 SampleRate; // Sample rate in Hz
                Core::JSON::DecUInt32 BitRate; // Target bitrate in bits per second (eg. 320000)
                Core::JSON::DecUInt8 Channels; // Number of audio channels
                Core::JSON::DecUInt8 Resolution; // Sampling resolution in bits per sample
                Core::JSON::Boolean IsResampled; // Indicates if the source stream is being resampled by the stack to match sink capabilities
            }; // class StreamPropertiesData

        } // namespace Source

    } // namespace BluetoothAudio

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudio::state)
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudio::ISink::devicetype)
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudio::audiocodec)
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudio::drmscheme)
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudio::ISource::devicetype)

}

