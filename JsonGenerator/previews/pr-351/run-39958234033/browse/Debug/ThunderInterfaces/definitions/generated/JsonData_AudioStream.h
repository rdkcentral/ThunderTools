// C++ types for AudioStream API.
// Generated automatically from 'IAudioStream.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IAudioStream.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace AudioStream {

        // Common classes
        //

        class AudioprofileInfo : public Core::JSON::Container {
        public:
            AudioprofileInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            AudioprofileInfo(const AudioprofileInfo& _other)
                : Core::JSON::Container()
                , Codec(_other.Codec)
                , CodecParams(_other.CodecParams)
                , Channels(_other.Channels)
                , Resolution(_other.Resolution)
                , SampleRate(_other.SampleRate)
                , BitRate(_other.BitRate)
            {
                _Init();
            }

            AudioprofileInfo(AudioprofileInfo&& _other) noexcept
                : Core::JSON::Container()
                , Codec(std::move(_other.Codec))
                , CodecParams(std::move(_other.CodecParams))
                , Channels(std::move(_other.Channels))
                , Resolution(std::move(_other.Resolution))
                , SampleRate(std::move(_other.SampleRate))
                , BitRate(std::move(_other.BitRate))
            {
                _Init();
            }

            AudioprofileInfo(const Exchange::IAudioStream::audioprofile& _other)
                : Core::JSON::Container()
            {
                Codec = _other.codec;
                if (_other.codecParams.IsSet() == true) {
                    CodecParams = _other.codecParams.Value();
                }
                Channels = _other.channels;
                Resolution = _other.resolution;
                SampleRate = _other.sampleRate;
                if (_other.bitRate.IsSet() == true) {
                    BitRate = _other.bitRate.Value();
                }
                _Init();
            }

            AudioprofileInfo& operator=(const AudioprofileInfo& _rhs)
            {
                Codec = _rhs.Codec;
                if (_rhs.CodecParams.IsSet() == true) {
                    CodecParams = _rhs.CodecParams;
                }
                Channels = _rhs.Channels;
                Resolution = _rhs.Resolution;
                SampleRate = _rhs.SampleRate;
                if (_rhs.BitRate.IsSet() == true) {
                    BitRate = _rhs.BitRate;
                }
                return (*this);
            }

            AudioprofileInfo& operator=(AudioprofileInfo&& _rhs) noexcept
            {
                Codec = std::move(_rhs.Codec);
                CodecParams = std::move(_rhs.CodecParams);
                Channels = std::move(_rhs.Channels);
                Resolution = std::move(_rhs.Resolution);
                SampleRate = std::move(_rhs.SampleRate);
                BitRate = std::move(_rhs.BitRate);
                return (*this);
            }

            AudioprofileInfo& operator=(const Exchange::IAudioStream::audioprofile& _rhs)
            {
                Codec = _rhs.codec;
                if (_rhs.codecParams.IsSet() == true) {
                    CodecParams = _rhs.codecParams.Value();
                }
                Channels = _rhs.channels;
                Resolution = _rhs.resolution;
                SampleRate = _rhs.sampleRate;
                if (_rhs.bitRate.IsSet() == true) {
                    BitRate = _rhs.bitRate.Value();
                }
                return (*this);
            }

            operator Exchange::IAudioStream::audioprofile() const
            {
                Exchange::IAudioStream::audioprofile _value{};
                _value.codec = Codec;
                if (CodecParams.IsSet() == true) {
                    _value.codecParams = CodecParams;
                }
                _value.channels = Channels;
                _value.resolution = Resolution;
                _value.sampleRate = SampleRate;
                if (BitRate.IsSet() == true) {
                    _value.bitRate = BitRate;
                }
                return (_value);
            }

            ~AudioprofileInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Codec.IsSet() == true) && (Channels.IsSet() == true) && (Resolution.IsSet() == true) && (SampleRate.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("codec"), &Codec);
                Add(_T("codecparams"), &CodecParams);
                CodecParams.SetQuoted(false);
                Add(_T("channels"), &Channels);
                Add(_T("resolution"), &Resolution);
                Add(_T("samplerate"), &SampleRate);
                Add(_T("bitrate"), &BitRate);
            }

        public:
            Core::JSON::EnumType<Exchange::IAudioStream::codectype> Codec; // Compression method (PCM: uncompressed)
            Core::JSON::String CodecParams; // Additional parameters for codec
            Core::JSON::DecUInt8 Channels; // Number of audio channels
            Core::JSON::DecUInt8 Resolution; // Sample resultion in bits
            Core::JSON::DecUInt32 SampleRate; // Sample rate in hertz
            Core::JSON::DecUInt32 BitRate; // Data rate of the compressed stream in bits per second
        }; // class AudioprofileInfo

        // Method params/result classes
        //

        class DataParamsData : public Core::JSON::Container {
        public:
            DataParamsData()
                : Core::JSON::Container()
            {
                Add(_T("seq"), &Seq);
                Add(_T("timestamp"), &Timestamp);
                Add(_T("length"), &Length);
                Add(_T("data"), &Data);
            }

            DataParamsData(const DataParamsData&) = delete;
            DataParamsData(DataParamsData&&) noexcept  = delete;

            DataParamsData& operator=(const DataParamsData&) = delete;
            DataParamsData& operator=(DataParamsData&&) noexcept  = delete;

            ~DataParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Length.IsSet() == true) && (Data.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt16 Seq; // Frame number in current transmission
            Core::JSON::DecUInt32 Timestamp; // Timestamp of the frame
            Core::JSON::DecUInt16 Length; // Size of the raw data frame in bytes
            Core::JSON::String Data; // Raw audio data, the format of the data is specified in the most recent *audiotransmission* notification
        }; // class DataParamsData

        class ProfileData : public Core::JSON::Container {
        public:
            ProfileData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            ProfileData(const ProfileData&) = delete;
            ProfileData(ProfileData&&) noexcept  = delete;

            ProfileData& operator=(const ProfileData&) = delete;
            ProfileData& operator=(ProfileData&&) noexcept  = delete;

            ~ProfileData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Value.IsSet() == true) && (Value.IsDataValid() == true));
            }

        public:
            AudioprofileInfo Value; // Preferred profile of the stream
        }; // class ProfileData

        class SpeedData : public Core::JSON::Container {
        public:
            SpeedData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            SpeedData(const SpeedData&) = delete;
            SpeedData(SpeedData&&) noexcept  = delete;

            SpeedData& operator=(const SpeedData&) = delete;
            SpeedData& operator=(SpeedData&&) noexcept  = delete;

            ~SpeedData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt8 Value; // Stream speed
        }; // class SpeedData

        class StateChangedParamsData : public Core::JSON::Container {
        public:
            StateChangedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("state"), &State);
                Add(_T("profile"), &Profile);
            }

            StateChangedParamsData(const StateChangedParamsData&) = delete;
            StateChangedParamsData(StateChangedParamsData&&) noexcept  = delete;

            StateChangedParamsData& operator=(const StateChangedParamsData&) = delete;
            StateChangedParamsData& operator=(StateChangedParamsData&&) noexcept  = delete;

            ~StateChangedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((State.IsSet() == true) && ((Profile.IsSet() == false) || (Profile.IsDataValid() == true)));
            }

        public:
            Core::JSON::EnumType<Exchange::IAudioStream::streamstate> State; // New state of the stream
            AudioprofileInfo Profile; // Details on the format used in the stream
        }; // class StateChangedParamsData

    } // namespace AudioStream

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IAudioStream::streamstate)
ENUM_CONVERSION_HANDLER(Exchange::IAudioStream::codectype)

}

