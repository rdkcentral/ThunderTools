// C++ classes for Remote Control API JSON-RPC API.
// Generated automatically from 'RemoteControl.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            KeyobjInfo(const KeyobjInfo&) = delete;
            KeyobjInfo& operator=(const KeyobjInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            LoadParamsInfo(const LoadParamsInfo&) = delete;
            LoadParamsInfo& operator=(const LoadParamsInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            RcobjInfo(const RcobjInfo&) = delete;
            RcobjInfo& operator=(const RcobjInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            DeviceData(const DeviceData&) = delete;
            DeviceData& operator=(const DeviceData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            KeyResultData(const KeyResultData&) = delete;
            KeyResultData& operator=(const KeyResultData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            KeypressedParamsData(const KeypressedParamsData&) = delete;
            KeypressedParamsData& operator=(const KeypressedParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            UnpairParamsData(const UnpairParamsData&) = delete;
            UnpairParamsData& operator=(const UnpairParamsData&) = delete;

        public:
            Core::JSON::String Device; // Device name
            Core::JSON::String Bindid; // Binding ID
        }; // class UnpairParamsData

    } // namespace RemoteControl

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::RemoteControl::ModifiersType)

}

