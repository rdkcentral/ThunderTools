// C++ classes for Streamer API JSON-RPC API.
// Generated automatically from 'Streamer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    namespace Streamer {

        // Common enums
        //

        // DRM used
        enum class DrmType : uint8_t {
            NONE,
            CLEARKEY,
            PLAYREADY,
            WIDEVINE,
            UNKNOWN
        };

        // Stream state
        enum class StateType : uint8_t {
            IDLE,
            LOADING,
            PREPARED,
            CONTROLLED,
            ERROR
        };

        // Stream type
        enum class StreamType : uint8_t {
            UNDEFINED = 0,
            CABLE = 1,
            HANDHELD = 2,
            SATELLITE = 4,
            TERRESTRIAL = 8,
            DAB = 16,
            RF = 31,
            UNICAST = 32,
            MULTICAST = 64,
            IP = 96
        };

        // Common classes
        //

        class IdInfo : public Core::JSON::Container {
        public:
            IdInfo()
                : Core::JSON::Container()
            {
                Add(_T("id"), &Id);
            }

            bool IsValid() const
            {
                return (true);
            }

            IdInfo(const IdInfo&) = delete;
            IdInfo& operator=(const IdInfo&) = delete;

        public:
            Core::JSON::DecUInt8 Id; // Stream ID
        }; // class IdInfo

        class StreamParamsInfo : public Core::JSON::Container {
        public:
            StreamParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("code"), &Code);
            }

            bool IsValid() const
            {
                return (true);
            }

            StreamParamsInfo(const StreamParamsInfo&) = delete;
            StreamParamsInfo& operator=(const StreamParamsInfo&) = delete;

        public:
            Core::JSON::DecUInt32 Code; // Implementation-specific incident code
        }; // class StreamParamsInfo

        // Method params/result classes
        //

        class CreateParamsData : public Core::JSON::Container {
        public:
            CreateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("type"), &Type);
            }

            bool IsValid() const
            {
                return (true);
            }

            CreateParamsData(const CreateParamsData&) = delete;
            CreateParamsData& operator=(const CreateParamsData&) = delete;

        public:
            Core::JSON::EnumType<StreamType> Type; // Stream type
        }; // class CreateParamsData

        class StreamelementData : public Core::JSON::Container {
        public:
            // Stream element type
            enum class ElementType : uint8_t {
                VIDEO,
                AUDIO,
                SUBTITLES,
                TELETEXT,
                DATA
            };

            StreamelementData()
                : Core::JSON::Container()
            {
                _Init();
            }

            StreamelementData(const StreamelementData& _other)
                : Core::JSON::Container()
                , Type(_other.Type)
            {
                _Init();
            }

            StreamelementData& operator=(const StreamelementData& _rhs)
            {
                Type = _rhs.Type;
                return (*this);
            }

            bool IsValid() const
            {
                return (true);
            }

        private:
            void _Init()
            {
                Add(_T("type"), &Type);
            }

        public:
            Core::JSON::EnumType<StreamelementData::ElementType> Type; // Stream element type
        }; // class StreamelementData

        class LoadParamsData : public Core::JSON::Container {
        public:
            LoadParamsData()
                : Core::JSON::Container()
            {
                Add(_T("id"), &Id);
                Add(_T("location"), &Location);
            }

            bool IsValid() const
            {
                return (true);
            }

            LoadParamsData(const LoadParamsData&) = delete;
            LoadParamsData& operator=(const LoadParamsData&) = delete;

        public:
            Core::JSON::DecUInt8 Id; // Stream ID
            Core::JSON::String Location; // Location of the source to load
        }; // class LoadParamsData

        class StatechangeParamsData : public Core::JSON::Container {
        public:
            StatechangeParamsData()
                : Core::JSON::Container()
            {
                Add(_T("state"), &State);
            }

            bool IsValid() const
            {
                return (true);
            }

            StatechangeParamsData(const StatechangeParamsData&) = delete;
            StatechangeParamsData& operator=(const StatechangeParamsData&) = delete;

        public:
            Core::JSON::EnumType<StateType> State; // Stream state
        }; // class StatechangeParamsData

        class TimeupdateParamsData : public Core::JSON::Container {
        public:
            TimeupdateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("time"), &Time);
            }

            bool IsValid() const
            {
                return (true);
            }

            TimeupdateParamsData(const TimeupdateParamsData&) = delete;
            TimeupdateParamsData& operator=(const TimeupdateParamsData&) = delete;

        public:
            Core::JSON::DecUInt64 Time; // Stream position in miliseconds
        }; // class TimeupdateParamsData

        class WindowData : public Core::JSON::Container {
        public:
            WindowData()
                : Core::JSON::Container()
            {
                Add(_T("x"), &X);
                Add(_T("y"), &Y);
                Add(_T("width"), &Width);
                Add(_T("height"), &Height);
            }

            bool IsValid() const
            {
                return (true);
            }

            WindowData(const WindowData&) = delete;
            WindowData& operator=(const WindowData&) = delete;

        public:
            Core::JSON::DecUInt32 X; // Horizontal position of the window (in pixels)
            Core::JSON::DecUInt32 Y; // Vertical position of the window (in pixels)
            Core::JSON::DecUInt32 Width; // Width of the window (in pixels)
            Core::JSON::DecUInt32 Height; // Height of the window (in pixels)
        }; // class WindowData

    } // namespace Streamer

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Streamer::StreamType)
ENUM_CONVERSION_HANDLER(JsonData::Streamer::DrmType)
ENUM_CONVERSION_HANDLER(JsonData::Streamer::StateType)
ENUM_CONVERSION_HANDLER(JsonData::Streamer::StreamelementData::ElementType)

}

