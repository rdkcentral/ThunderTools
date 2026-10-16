// C++ types for Messenger API.
// Generated automatically from 'IMessenger.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IMessenger.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Messenger {

        // Method params/result classes
        //

        class JoinParamsData : public Core::JSON::Container {
        public:
            JoinParamsData()
                : Core::JSON::Container()
            {
                Add(_T("room"), &Room);
                Add(_T("user"), &User);
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
                return ((Room.IsSet() == true) && (User.IsSet() == true));
            }

        public:
            Core::JSON::String Room; // Name of the room to join
            Core::JSON::String User; // Name of ther user to join as
            Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::security> Secure; // Denotes if the room is secure (by default not secure)
            Core::JSON::ArrayType<Core::JSON::String> Acl; // List of URL origins with possible wildcards
        }; // class JoinParamsData

        class LeaveParamsData : public Core::JSON::Container {
        public:
            LeaveParamsData()
                : Core::JSON::Container()
            {
                Add(_T("roomid"), &RoomId);
            }

            LeaveParamsData(const LeaveParamsData&) = delete;
            LeaveParamsData(LeaveParamsData&&) noexcept  = delete;

            LeaveParamsData& operator=(const LeaveParamsData&) = delete;
            LeaveParamsData& operator=(LeaveParamsData&&) noexcept  = delete;

            ~LeaveParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (RoomId.IsSet() == true);
            }

        public:
            Core::JSON::String RoomId; // Token of the room to leave
        }; // class LeaveParamsData

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
            Core::JSON::String Message; // Contents of the sent message
        }; // class MessageParamsData

        class RoomUpdateParamsData : public Core::JSON::Container {
        public:
            RoomUpdateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("room"), &Room);
                Add(_T("action"), &Action);
                Add(_T("secure"), &Secure);
            }

            RoomUpdateParamsData(const RoomUpdateParamsData&) = delete;
            RoomUpdateParamsData(RoomUpdateParamsData&&) noexcept  = delete;

            RoomUpdateParamsData& operator=(const RoomUpdateParamsData&) = delete;
            RoomUpdateParamsData& operator=(RoomUpdateParamsData&&) noexcept  = delete;

            ~RoomUpdateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Room.IsSet() == true) && (Action.IsSet() == true) && (Secure.IsSet() == true));
            }

        public:
            Core::JSON::String Room; // Name of the room that has changed its status
            Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::INotification::roomupdate> Action; // New room status
            Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::security> Secure; // Denotes if the room is secure
        }; // class RoomUpdateParamsData

        class SendParamsData : public Core::JSON::Container {
        public:
            SendParamsData()
                : Core::JSON::Container()
            {
                Add(_T("roomid"), &RoomId);
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
                return ((RoomId.IsSet() == true) && (Message.IsSet() == true));
            }

        public:
            Core::JSON::String RoomId; // Token of the room to send the message to
            Core::JSON::String Message; // Contents of the message to send
        }; // class SendParamsData

        class UserUpdateParamsData : public Core::JSON::Container {
        public:
            UserUpdateParamsData()
                : Core::JSON::Container()
            {
                Add(_T("user"), &User);
                Add(_T("action"), &Action);
            }

            UserUpdateParamsData(const UserUpdateParamsData&) = delete;
            UserUpdateParamsData(UserUpdateParamsData&&) noexcept  = delete;

            UserUpdateParamsData& operator=(const UserUpdateParamsData&) = delete;
            UserUpdateParamsData& operator=(UserUpdateParamsData&&) noexcept  = delete;

            ~UserUpdateParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((User.IsSet() == true) && (Action.IsSet() == true));
            }

        public:
            Core::JSON::String User; // Name of the user that has changed its status
            Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::INotification::userupdate> Action; // New user status
        }; // class UserUpdateParamsData

    } // namespace Messenger

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IMessenger::security)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IMessenger::INotification::roomupdate)
ENUM_CONVERSION_HANDLER(Exchange::JSONRPC::IMessenger::INotification::userupdate)

}

