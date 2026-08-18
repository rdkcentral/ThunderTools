// C++ types for Streamer API.
// Generated automatically from 'Streamer.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            IdInfo(const IdInfo&) = delete;
            IdInfo(IdInfo&&) noexcept  = delete;

            IdInfo& operator=(const IdInfo&) = delete;
            IdInfo& operator=(IdInfo&&) noexcept  = delete;

            ~IdInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Id.IsSet() == true);
            }

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

            StreamParamsInfo(const StreamParamsInfo&) = delete;
            StreamParamsInfo(StreamParamsInfo&&) noexcept  = delete;

            StreamParamsInfo& operator=(const StreamParamsInfo&) = delete;
            StreamParamsInfo& operator=(StreamParamsInfo&&) noexcept  = delete;

            ~StreamParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Code.IsSet() == true);
            }

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

            CreateParamsData(const CreateParamsData&) = delete;
            CreateParamsData(CreateParamsData&&) noexcept  = delete;

            CreateParamsData& operator=(const CreateParamsData&) = delete;
            CreateParamsData& operator=(CreateParamsData&&) noexcept  = delete;

            ~CreateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
            }

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

            StreamelementData(StreamelementData&& _other) noexcept
                : Core::JSON::Container()
                , Type(std::move(_other.Type))
            {
                _Init();
            }

            StreamelementData& operator=(const StreamelementData& _rhs)
            {
                Type = _rhs.Type;
                return (*this);
            }

            StreamelementData& operator=(StreamelementData&& _rhs) noexcept
            {
                Type = std::move(_rhs.Type);
                return (*this);
            }

            ~StreamelementData() = default;

        public:
            bool IsDataValid() const
            {
                return (Type.IsSet() == true);
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

            LoadParamsData(const LoadParamsData&) = delete;
            LoadParamsData(LoadParamsData&&) noexcept  = delete;

            LoadParamsData& operator=(const LoadParamsData&) = delete;
            LoadParamsData& operator=(LoadParamsData&&) noexcept  = delete;

            ~LoadParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Id.IsSet() == true) && (Location.IsSet() == true));
            }

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

            StatechangeParamsData(const StatechangeParamsData&) = delete;
            StatechangeParamsData(StatechangeParamsData&&) noexcept  = delete;

            StatechangeParamsData& operator=(const StatechangeParamsData&) = delete;
            StatechangeParamsData& operator=(StatechangeParamsData&&) noexcept  = delete;

            ~StatechangeParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (State.IsSet() == true);
            }

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

            TimeupdateParamsData(const TimeupdateParamsData&) = delete;
            TimeupdateParamsData(TimeupdateParamsData&&) noexcept  = delete;

            TimeupdateParamsData& operator=(const TimeupdateParamsData&) = delete;
            TimeupdateParamsData& operator=(TimeupdateParamsData&&) noexcept  = delete;

            ~TimeupdateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Time.IsSet() == true);
            }

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

            WindowData(const WindowData&) = delete;
            WindowData(WindowData&&) noexcept  = delete;

            WindowData& operator=(const WindowData&) = delete;
            WindowData& operator=(WindowData&&) noexcept  = delete;

            ~WindowData() = default;

        public:
            bool IsDataValid() const
            {
                return ((X.IsSet() == true) && (Y.IsSet() == true) && (Width.IsSet() == true) && (Height.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 X; // Horizontal position of the window (in pixels)
            Core::JSON::DecUInt32 Y; // Vertical position of the window (in pixels)
            Core::JSON::DecUInt32 Width; // Width of the window (in pixels)
            Core::JSON::DecUInt32 Height; // Height of the window (in pixels)
        }; // class WindowData

    } // namespace Streamer

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Streamer::StreamType)
ENUM_CONVERSION_HANDLER(JsonData::Streamer::DrmType)
ENUM_CONVERSION_HANDLER(JsonData::Streamer::StateType)
ENUM_CONVERSION_HANDLER(JsonData::Streamer::StreamelementData::ElementType)

}

