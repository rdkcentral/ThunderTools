// C++ classes for Messenger API JSON-RPC API.
// Generated automatically from 'Messenger.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            JoinResultInfo(const JoinResultInfo&) = delete;
            JoinResultInfo& operator=(const JoinResultInfo&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            JoinParamsData(const JoinParamsData&) = delete;
            JoinParamsData& operator=(const JoinParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            MessageParamsData(const MessageParamsData&) = delete;
            MessageParamsData& operator=(const MessageParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            RoomupdateParamsData(const RoomupdateParamsData&) = delete;
            RoomupdateParamsData& operator=(const RoomupdateParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            SendParamsData(const SendParamsData&) = delete;
            SendParamsData& operator=(const SendParamsData&) = delete;

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

            bool IsValid() const
            {
                return (true);
            }

            UserupdateParamsData(const UserupdateParamsData&) = delete;
            UserupdateParamsData& operator=(const UserupdateParamsData&) = delete;

        public:
            Core::JSON::String User; // Name of the user that has this notification relates to
            Core::JSON::EnumType<UserupdateParamsData::ActionType> Action; // Specifies the user status change, e.g. join or leave a room
        }; // class UserupdateParamsData

    } // namespace Messenger

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Messenger::SecureType)
ENUM_CONVERSION_HANDLER(JsonData::Messenger::RoomupdateParamsData::ActionType)
ENUM_CONVERSION_HANDLER(JsonData::Messenger::UserupdateParamsData::ActionType)

}

