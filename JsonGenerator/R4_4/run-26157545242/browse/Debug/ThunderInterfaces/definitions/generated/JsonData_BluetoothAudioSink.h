// C++ classes for BluetoothAudioSink API JSON-RPC API.
// Generated automatically from 'IBluetoothAudio.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IBluetoothAudio.h>

namespace WPEFramework {

namespace JsonData {

    namespace BluetoothAudioSink {

        // Method params/result classes
        //

        class AssignParamsData : public Core::JSON::Container {
        public:
            AssignParamsData()
                : Core::JSON::Container()
            {
                Add(_T("address"), &Address);
            }

            bool IsValid() const
            {
                return (true);
            }

            AssignParamsData(const AssignParamsData&) = delete;
            AssignParamsData& operator=(const AssignParamsData&) = delete;

        public:
            Core::JSON::String Address; // Address of the bluetooth device to assign
        }; // class AssignParamsData

        class CodecPropertiesData : public Core::JSON::Container {
        public:
            CodecPropertiesData()
                : Core::JSON::Container()
            {
                _Init();
            }

            CodecPropertiesData(const Exchange::IBluetoothAudioSink::CodecProperties& _other)
                : Core::JSON::Container()
            {
                Codec = _other.Codec;
                Settings = _other.Settings;
                _Init();
            }

            CodecPropertiesData& operator=(const Exchange::IBluetoothAudioSink::CodecProperties& _rhs)
            {
                Codec = _rhs.Codec;
                Settings = _rhs.Settings;
                return (*this);
            }

            operator Exchange::IBluetoothAudioSink::CodecProperties() const
            {
                Exchange::IBluetoothAudioSink::CodecProperties _value{};
                _value.Codec = Codec;
                _value.Settings = Settings;
                return (_value);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("codec"), &Codec);
                Add(_T("settings"), &Settings);
            }

        public:
            Core::JSON::EnumType<Exchange::IBluetoothAudioSink::audiocodec> Codec; // Audio codec used
            Core::JSON::String Settings; // Codec-specific audio quality preset, compression profile, etc
        }; // class CodecPropertiesData

        class DRMPropertiesData : public Core::JSON::Container {
        public:
            DRMPropertiesData()
                : Core::JSON::Container()
            {
                _Init();
            }

            DRMPropertiesData(const Exchange::IBluetoothAudioSink::DRMProperties& _other)
                : Core::JSON::Container()
            {
                DRM = _other.DRM;
                Settings = _other.Settings;
                _Init();
            }

            DRMPropertiesData& operator=(const Exchange::IBluetoothAudioSink::DRMProperties& _rhs)
            {
                DRM = _rhs.DRM;
                Settings = _rhs.Settings;
                return (*this);
            }

            operator Exchange::IBluetoothAudioSink::DRMProperties() const
            {
                Exchange::IBluetoothAudioSink::DRMProperties _value{};
                _value.DRM = DRM;
                _value.Settings = Settings;
                return (_value);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("drm"), &DRM);
                Add(_T("settings"), &Settings);
            }

        public:
            Core::JSON::EnumType<Exchange::IBluetoothAudioSink::drmscheme> DRM; // Content protection scheme used
            Core::JSON::String Settings; // DRM-specific content protection level, encoding rules, etc
        }; // class DRMPropertiesData

        class LatencyData : public Core::JSON::Container {
        public:
            LatencyData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            bool IsValid() const
            {
                return (true);
            }

            LatencyData(const LatencyData&) = delete;
            LatencyData& operator=(const LatencyData&) = delete;

        public:
            Core::JSON::DecSInt16 Value; // Audio latency of the sink in milliseconds
        }; // class LatencyData

        class StreamPropertiesData : public Core::JSON::Container {
        public:
            StreamPropertiesData()
                : Core::JSON::Container()
            {
                _Init();
            }

            StreamPropertiesData(const Exchange::IBluetoothAudioSink::StreamProperties& _other)
                : Core::JSON::Container()
            {
                SampleRate = _other.SampleRate;
                BitRate = _other.BitRate;
                Channels = _other.Channels;
                Resolution = _other.Resolution;
                IsResampling = _other.IsResampling;
                _Init();
            }

            StreamPropertiesData& operator=(const Exchange::IBluetoothAudioSink::StreamProperties& _rhs)
            {
                SampleRate = _rhs.SampleRate;
                BitRate = _rhs.BitRate;
                Channels = _rhs.Channels;
                Resolution = _rhs.Resolution;
                IsResampling = _rhs.IsResampling;
                return (*this);
            }

            operator Exchange::IBluetoothAudioSink::StreamProperties() const
            {
                Exchange::IBluetoothAudioSink::StreamProperties _value{};
                _value.SampleRate = SampleRate;
                _value.BitRate = BitRate;
                _value.Channels = Channels;
                _value.Resolution = Resolution;
                _value.IsResampling = IsResampling;
                return (_value);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("samplerate"), &SampleRate);
                Add(_T("bitrate"), &BitRate);
                Add(_T("channels"), &Channels);
                Add(_T("resolution"), &Resolution);
                Add(_T("isresampling"), &IsResampling);
            }

        public:
            Core::JSON::DecUInt32 SampleRate; // Sample rate in Hz
            Core::JSON::DecUInt32 BitRate; // Target bitrate in bits per second (eg. 320000)
            Core::JSON::DecUInt8 Channels; // Number of audio channels
            Core::JSON::DecUInt8 Resolution; // Sampling resolution in bits per sample
            Core::JSON::Boolean IsResampling; // Indicates if the sink is resampling the input stream
        }; // class StreamPropertiesData

    } // namespace BluetoothAudioSink

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudioSink::state)
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudioSink::devicetype)
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudioSink::audiocodec)
ENUM_CONVERSION_HANDLER(Exchange::IBluetoothAudioSink::drmscheme)

}

