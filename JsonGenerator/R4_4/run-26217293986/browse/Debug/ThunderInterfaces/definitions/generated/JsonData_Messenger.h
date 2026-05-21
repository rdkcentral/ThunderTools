// C++ types for Messenger API.
// Generated automatically from 'Messenger.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Messenger {

        // Common enums
        //

        // Room security
        enum class SecureType : uint8_t {
            INSECURE,
            SECURE
        };

        // Common classes
        //

        class JoinResultInfo : public Core::JSON::Container {
        public:
            JoinResultInfo()
                : Core::JSON::Container()
            {
                Add(_T("roomid"), &Roomid);
            }

            JoinResultInfo(const JoinResultInfo&) = delete;
            JoinResultInfo(JoinResultInfo&&) noexcept  = delete;

            JoinResultInfo& operator=(const JoinResultInfo&) = delete;
            JoinResultInfo& operator=(JoinResultInfo&&) noexcept  = delete;

            ~JoinResultInfo() = default;

        public:
            bool IsDataValid() const
            {
                return (Roomid.IsSet() == true);
            }

        public:
            Core::JSON::String Roomid; // Unique ID of the room
        }; // class JoinResultInfo

        // Method params/result classes
        //

        class JoinParamsData : public Core::JSON::Container {
        public:
            JoinParamsData()
                : Core::JSON::Container()
            {
                Add(_T("user"), &User);
                Add(_T("room"), &Room);
                Add(_T("secure"), &Secure);
                Add(_T("acl"), &Acl);
            }

            JoinParamsData(const JoinParamsData&) = delete;
            JoinParamsData(JoinParamsData&&) noexcept  = delete;

            JoinParamsData& operator=(const JoinParamsData&) = delete;
            JoinParamsData& operator=(JoinParamsData&&) noexcept  = delete;

            ~JoinParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((User.IsSet() == true) && (Room.IsSet() == true));
            }

        public:
            Core::JSON::String User; // User name to join the room under (must not be empty)
            Core::JSON::String Room; // Name of the room to join (must not be empty)
            Core::JSON::EnumType<SecureType> Secure; // Room security
            Core::JSON::ArrayType<Core::JSON::String> Acl; // Access-control list for secure room
        }; // class JoinParamsData

        class MessageParamsData : public Core::JSON::Container {
        public:
            MessageParamsData()
                : Core::JSON::Container()
            {
                Add(_T("user"), &User);
                Add(_T("message"), &Message);
            }

            MessageParamsData(const MessageParamsData&) = delete;
            MessageParamsData(MessageParamsData&&) noexcept  = delete;

            MessageParamsData& operator=(const MessageParamsData&) = delete;
            MessageParamsData& operator=(MessageParamsData&&) noexcept  = delete;

            ~MessageParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((User.IsSet() == true) && (Message.IsSet() == true));
            }

        public:
            Core::JSON::String User; // Name of the user that has sent the message
            Core::JSON::String Message; // Content of the message
        }; // class MessageParamsData

        class RoomupdateParamsData : public Core::JSON::Container {
        public:
            // Specifies the room status change, e.g. created or destroyed
            enum class ActionType : uint8_t {
                CREATED,
                DESTROYED
            };

            RoomupdateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("room"), &Room);
                Add(_T("secure"), &Secure);
                Add(_T("action"), &Action);
            }

            RoomupdateParamsData(const RoomupdateParamsData&) = delete;
            RoomupdateParamsData(RoomupdateParamsData&&) noexcept  = delete;

            RoomupdateParamsData& operator=(const RoomupdateParamsData&) = delete;
            RoomupdateParamsData& operator=(RoomupdateParamsData&&) noexcept  = delete;

            ~RoomupdateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Room.IsSet() == true) && (Action.IsSet() == true));
            }

        public:
            Core::JSON::String Room; // Name of the room this notification relates to
            Core::JSON::EnumType<SecureType> Secure; // Room security
            Core::JSON::EnumType<RoomupdateParamsData::ActionType> Action; // Specifies the room status change, e.g. created or destroyed
        }; // class RoomupdateParamsData

        class SendParamsData : public Core::JSON::Container {
        public:
            SendParamsData()
                : Core::JSON::Container()
            {
                Add(_T("roomid"), &Roomid);
                Add(_T("message"), &Message);
            }

            SendParamsData(const SendParamsData&) = delete;
            SendParamsData(SendParamsData&&) noexcept  = delete;

            SendParamsData& operator=(const SendParamsData&) = delete;
            SendParamsData& operator=(SendParamsData&&) noexcept  = delete;

            ~SendParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Roomid.IsSet() == true) && (Message.IsSet() == true));
            }

        public:
            Core::JSON::String Roomid; // ID of the room to send the message to
            Core::JSON::String Message; // The message content to send
        }; // class SendParamsData

        class UserupdateParamsData : public Core::JSON::Container {
        public:
            // Specifies the user status change, e.g. join or leave a room
            enum class ActionType : uint8_t {
                JOINED,
                LEFT
            };

            UserupdateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("user"), &User);
                Add(_T("action"), &Action);
            }

            UserupdateParamsData(const UserupdateParamsData&) = delete;
            UserupdateParamsData(UserupdateParamsData&&) noexcept  = delete;

            UserupdateParamsData& operator=(const UserupdateParamsData&) = delete;
            UserupdateParamsData& operator=(UserupdateParamsData&&) noexcept  = delete;

            ~UserupdateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((User.IsSet() == true) && (Action.IsSet() == true));
            }

        public:
            Core::JSON::String User; // Name of the user that has this notification relates to
            Core::JSON::EnumType<UserupdateParamsData::ActionType> Action; // Specifies the user status change, e.g. join or leave a room
        }; // class UserupdateParamsData

    } // namespace Messenger

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Messenger::SecureType)
ENUM_CONVERSION_HANDLER(JsonData::Messenger::RoomupdateParamsData::ActionType)
ENUM_CONVERSION_HANDLER(JsonData::Messenger::UserupdateParamsData::ActionType)

}

