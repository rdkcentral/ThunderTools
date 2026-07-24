// C++ types for Remote Control API.
// Generated automatically from 'RemoteControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace RemoteControl {

        // Common enums
        //

        // Key modifier
        enum ModifiersType : uint8_t {
            LEFTSHIFT = 1,
            RIGHTSHIFT = 2,
            LEFTALT = 4,
            RIGHTALT = 8,
            LEFTCTRL = 16,
            RIGHTCTRL = 32
        };

        // Common classes
        //

        class KeyobjInfo : public Core::JSON::Container {
        public:
            KeyobjInfo()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
                Add(_T("code"), &Code);
            }

            KeyobjInfo(const KeyobjInfo&) = delete;
            KeyobjInfo(KeyobjInfo&&) noexcept  = delete;

            KeyobjInfo& operator=(const KeyobjInfo&) = delete;
            KeyobjInfo& operator=(KeyobjInfo&&) noexcept  = delete;

            ~KeyobjInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Device.IsSet() == true) && (Code.IsSet() == true));
            }

        public:
            Core::JSON::String Device; // Device name
            Core::JSON::DecUInt32 Code; // Key code
        }; // class KeyobjInfo

        class LoadParamsInfo : public Core::JSON::Container {
        public:
            LoadParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
            }

            LoadParamsInfo(const LoadParamsInfo&) = delete;
            LoadParamsInfo(LoadParamsInfo&&) noexcept  = delete;

            LoadParamsInfo& operator=(const LoadParamsInfo&) = delete;
            LoadParamsInfo& operator=(LoadParamsInfo&&) noexcept  = delete;

            ~LoadParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Device.IsSet() == true);
            }

        public:
            Core::JSON::String Device; // Device name
        }; // class LoadParamsInfo

        class RcobjInfo : public Core::JSON::Container {
        public:
            RcobjInfo()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
                Add(_T("code"), &Code);
                Add(_T("key"), &Key);
                Add(_T("modifiers"), &Modifiers);
            }

            RcobjInfo(const RcobjInfo&) = delete;
            RcobjInfo(RcobjInfo&&) noexcept  = delete;

            RcobjInfo& operator=(const RcobjInfo&) = delete;
            RcobjInfo& operator=(RcobjInfo&&) noexcept  = delete;

            ~RcobjInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Device.IsSet() == true) && (Code.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::String Device; // Device name
            Core::JSON::DecUInt32 Code; // Key code
            Core::JSON::DecUInt16 Key; // Key ingest value
            Core::JSON::ArrayType<Core::JSON::EnumType<ModifiersType>> Modifiers; // List of key modifiers
        }; // class RcobjInfo

        // Method params/result classes
        //

        class DeviceData : public Core::JSON::Container {
        public:
            DeviceData()
                : Core::JSON::Container()
            {
                Add(_T("metadata"), &Metadata);
            }

            DeviceData(const DeviceData&) = delete;
            DeviceData(DeviceData&&) noexcept  = delete;

            DeviceData& operator=(const DeviceData&) = delete;
            DeviceData& operator=(DeviceData&&) noexcept  = delete;

            ~DeviceData() = default;

        public:
            bool IsDataValid() const
            {
                return (Metadata.IsSet() == true);
            }

        public:
            Core::JSON::String Metadata; // Device metadata
        }; // class DeviceData

        class KeyResultData : public Core::JSON::Container {
        public:
            KeyResultData()
                : Core::JSON::Container()
            {
                Add(_T("code"), &Code);
                Add(_T("key"), &Key);
                Add(_T("modifiers"), &Modifiers);
            }

            KeyResultData(const KeyResultData&) = delete;
            KeyResultData(KeyResultData&&) noexcept  = delete;

            KeyResultData& operator=(const KeyResultData&) = delete;
            KeyResultData& operator=(KeyResultData&&) noexcept  = delete;

            ~KeyResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Code.IsSet() == true) && (Key.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Code; // Key code
            Core::JSON::DecUInt16 Key; // Key ingest value
            Core::JSON::ArrayType<Core::JSON::EnumType<ModifiersType>> Modifiers; // List of key modifiers
        }; // class KeyResultData

        class KeypressedParamsData : public Core::JSON::Container {
        public:
            KeypressedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("pressed"), &Pressed);
            }

            KeypressedParamsData(const KeypressedParamsData&) = delete;
            KeypressedParamsData(KeypressedParamsData&&) noexcept  = delete;

            KeypressedParamsData& operator=(const KeypressedParamsData&) = delete;
            KeypressedParamsData& operator=(KeypressedParamsData&&) noexcept  = delete;

            ~KeypressedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Pressed.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Pressed; // Denotes if the key was pressed (true) or released (false)
        }; // class KeypressedParamsData

        class UnpairParamsData : public Core::JSON::Container {
        public:
            UnpairParamsData()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
                Add(_T("bindid"), &Bindid);
            }

            UnpairParamsData(const UnpairParamsData&) = delete;
            UnpairParamsData(UnpairParamsData&&) noexcept  = delete;

            UnpairParamsData& operator=(const UnpairParamsData&) = delete;
            UnpairParamsData& operator=(UnpairParamsData&&) noexcept  = delete;

            ~UnpairParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Device.IsSet() == true) && (Bindid.IsSet() == true));
            }

        public:
            Core::JSON::String Device; // Device name
            Core::JSON::String Bindid; // Binding ID
        }; // class UnpairParamsData

    } // namespace RemoteControl

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::RemoteControl::ModifiersType)

}

