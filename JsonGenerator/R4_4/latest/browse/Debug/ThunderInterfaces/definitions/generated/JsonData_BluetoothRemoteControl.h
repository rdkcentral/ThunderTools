// C++ classes for Bluetooth Remote Control API JSON-RPC API.
// Generated automatically from 'BluetoothRemoteControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace BluetoothRemoteControl {

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
            Core::JSON::String Address; // Bluetooth address
        }; // class AssignParamsData

        class AudioframeParamsData : public Core::JSON::Container {
        public:
            AudioframeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("seq"), &Seq);
                Add(_T("data"), &Data);
            }

            bool IsValid() const
            {
                return (true);
            }

            AudioframeParamsData(const AudioframeParamsData&) = delete;
            AudioframeParamsData& operator=(const AudioframeParamsData&) = delete;

        public:
            Core::JSON::DecUInt32 Seq; // Sequence number of the audio frame within current audio transmission
            Core::JSON::String Data; // Base64 representation of the binary data of the audio frame; format of the data is specified by the audio profile denoted by the most recent *audiotransmission* notification
        }; // class AudioframeParamsData

        class AudioprofileData : public Core::JSON::Container {
        public:
            // Name of the audio codec (*pcm* for uncompressed audio)
            enum class CodecType : uint8_t {
                PCM,
                ADPCM
            };

            AudioprofileData()
                : Core::JSON::Container()
            {
                Add(_T("codec"), &Codec);
                Add(_T("channels"), &Channels);
                Add(_T("rate"), &Rate);
                Add(_T("resolution"), &Resolution);
            }

            bool IsValid() const
            {
                return (true);
            }

            AudioprofileData(const AudioprofileData&) = delete;
            AudioprofileData& operator=(const AudioprofileData&) = delete;

        public:
            Core::JSON::EnumType<AudioprofileData::CodecType> Codec; // Name of the audio codec (*pcm* for uncompressed audio)
            Core::JSON::DecUInt8 Channels; // Number of audio channels (1: mono, 2: stereo, etc.)
            Core::JSON::DecUInt16 Rate; // Sample rate (in Hz)
            Core::JSON::DecUInt8 Resolution; // Sample resolution (in bits per sample)
        }; // class AudioprofileData

        class AudiotransmissionParamsData : public Core::JSON::Container {
        public:
            AudiotransmissionParamsData()
                : Core::JSON::Container()
            {
                Add(_T("profile"), &Profile);
            }

            bool IsValid() const
            {
                return (true);
            }

            AudiotransmissionParamsData(const AudiotransmissionParamsData&) = delete;
            AudiotransmissionParamsData& operator=(const AudiotransmissionParamsData&) = delete;

        public:
            Core::JSON::String Profile; // Type of audio profile, marking start of transmission; empty in case of end of transmission
        }; // class AudiotransmissionParamsData

        class BatterylevelchangeParamsData : public Core::JSON::Container {
        public:
            BatterylevelchangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("level"), &Level);
            }

            bool IsValid() const
            {
                return (true);
            }

            BatterylevelchangeParamsData(const BatterylevelchangeParamsData&) = delete;
            BatterylevelchangeParamsData& operator=(const BatterylevelchangeParamsData&) = delete;

        public:
            Core::JSON::DecUInt8 Level; // Battery level (in percentage)
        }; // class BatterylevelchangeParamsData

        class InfoData : public Core::JSON::Container {
        public:
            InfoData()
                : Core::JSON::Container()
            {
                Add(_T("model"), &Model);
                Add(_T("serial"), &Serial);
                Add(_T("firmware"), &Firmware);
                Add(_T("software"), &Software);
                Add(_T("manufacturer"), &Manufacturer);
            }

            bool IsValid() const
            {
                return (true);
            }

            InfoData(const InfoData&) = delete;
            InfoData& operator=(const InfoData&) = delete;

        public:
            Core::JSON::String Model; // Unit model name or number
            Core::JSON::String Serial; // Unit serial number
            Core::JSON::String Firmware; // Unit firmware revision
            Core::JSON::String Software; // Unit software revision
            Core::JSON::String Manufacturer; // Unit manufacturer name
        }; // class InfoData

    } // namespace BluetoothRemoteControl

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::BluetoothRemoteControl::AudioprofileData::CodecType)

}

