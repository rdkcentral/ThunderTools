// Generated automatically from 'IMessenger.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_Messenger.h"
#include <interfaces/IMessenger.h>

namespace Thunder {

namespace Exchange {

    namespace JSONRPC {

        namespace JMessenger {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            struct IHandler {
                virtual ~IHandler() = default;
                virtual void OnRoomUpdateEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
                virtual void OnUserUpdateEventRegistration(const string& client, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
            };

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IMessenger* _implementation__, IHandler* _handler_)
            {
                ASSERT(_implementation__ != nullptr);
                ASSERT(_handler_ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JMessenger"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'join' - Joins a messaging room
                _module__.PluginHost::JSONRPC::template Register<JsonData::Messenger::JoinParamsData, Core::JSON::String, std::function<uint32_t(const Core::JSONRPC::Context&, const JsonData::Messenger::JoinParamsData&, Core::JSON::String&)>>(_T("join"),
                    [_implementation__](const Core::JSONRPC::Context& context_, const JsonData::Messenger::JoinParamsData& params, Core::JSON::String& roomId) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _room_{params.Room};
                            const string _user_{params.User};
                            const Exchange::JSONRPC::IMessenger::security _secure_{params.Secure};
                            ::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>* _acl_{};
                            std::list<string> _aclElements_{};
                            auto _aclIterator_ = params.Acl.Elements();
                            while (_aclIterator_.Next() == true) { _aclElements_.push_back(_aclIterator_.Current()); }
                            using _aclIteratorImplType_ = ::Thunder::RPC::IteratorType<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>;
                            _acl_ = Core::ServiceType<_aclIteratorImplType_>::Create<::Thunder::RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>(std::move(_aclElements_));
                            ASSERT(_acl_ != nullptr);

                            string _roomId_{};

                            _errorCode__ = _implementation__->Join(context_, _room_, _user_, _secure_, _acl_, _roomId_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                roomId = _roomId_;
                            }
                        }

                        return (_errorCode__);
                    });

                // Method: 'leave' - Leaves a messaging room
                _module__.PluginHost::JSONRPC::template Register<JsonData::Messenger::LeaveParamsData, void>(_T("leave"),
                    [_implementation__](const JsonData::Messenger::LeaveParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _roomId_{params.RoomId};

                            _errorCode__ = _implementation__->Leave(_roomId_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'send' - Sends a message to a messaging room
                _module__.PluginHost::JSONRPC::template Register<JsonData::Messenger::SendParamsData, void>(_T("send"),
                    [_implementation__](const JsonData::Messenger::SendParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _roomId_{params.RoomId};
                            const string _message_{params.Message};

                            _errorCode__ = _implementation__->Send(_roomId_, _message_);

                        }

                        return (_errorCode__);
                    });

                // Register event status listeners...

                _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("roomupdate"),
                    [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                        _handler_->OnRoomUpdateEventRegistration(client_, status_);
                    });

                _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("userupdate"),
                    [_handler_](const uint32_t, const string&, const string& client_, const string&, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                        _handler_->OnUserUpdateEventRegistration(client_, status_);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("join"));
                _module__.PluginHost::JSONRPC::Unregister(_T("leave"));
                _module__.PluginHost::JSONRPC::Unregister(_T("send"));

                // Unregister event status listeners...
                _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("roomupdate"));
                _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("userupdate"));
            }

            namespace Event {

                // Event: 'roomupdate' - Notifies of room status changes
                template<typename MODULE>
                static void RoomUpdate(const MODULE& module_, const JsonData::Messenger::RoomUpdateParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("roomupdate"), params, sendIfMethod_);
                }

                // Event: 'roomupdate' - Notifies of room status changes
                template<typename MODULE>
                static void RoomUpdate(const MODULE& module_, const JsonData::Messenger::RoomUpdateParamsData& params, const string& client_)
                {
                    module_.Notify(_T("roomupdate"), params, [&client_](const string& designator_) -> bool {
                        return ((client_ == designator_));
                    });
                }

                // Event: 'roomupdate' - Notifies of room status changes
                template<typename MODULE>
                static void RoomUpdate(const MODULE& module_, const Core::JSON::String& room, const Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::INotification::roomupdate>& action, const Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::security>& secure, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Messenger::RoomUpdateParamsData params_;
                    params_.Room = room;
                    params_.Action = action;
                    params_.Secure = secure;

                    RoomUpdate(module_, params_, sendIfMethod_);
                }

                // Event: 'roomupdate' - Notifies of room status changes
                template<typename MODULE>
                static void RoomUpdate(const MODULE& module_, const Core::JSON::String& room, const Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::INotification::roomupdate>& action, const Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::security>& secure, const string& client_)
                {
                    JsonData::Messenger::RoomUpdateParamsData params_;
                    params_.Room = room;
                    params_.Action = action;
                    params_.Secure = secure;

                    RoomUpdate(module_, params_, client_);
                }

                // Event: 'roomupdate' - Notifies of room status changes
                template<typename MODULE>
                static void RoomUpdate(const MODULE& module_, const string& room, const IMessenger::INotification::roomupdate action, const IMessenger::security secure, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Messenger::RoomUpdateParamsData params_;
                    params_.Room = room;
                    params_.Action = action;
                    params_.Secure = secure;

                    RoomUpdate(module_, params_, sendIfMethod_);
                }

                // Event: 'roomupdate' - Notifies of room status changes
                template<typename MODULE>
                static void RoomUpdate(const MODULE& module_, const string& room, const IMessenger::INotification::roomupdate action, const IMessenger::security secure, const string& client_)
                {
                    JsonData::Messenger::RoomUpdateParamsData params_;
                    params_.Room = room;
                    params_.Action = action;
                    params_.Secure = secure;

                    RoomUpdate(module_, params_, client_);
                }

                // Event: 'userupdate' - Notifies of user status changes
                template<typename MODULE>
                static void UserUpdate(const MODULE& module_, const string& id_, const JsonData::Messenger::UserUpdateParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(_T("userupdate"), params, [&id_](const string& designator_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            const string designatorId_ = designator_.substr(0, designator_.find('.'));

                            if (designatorId_.empty() == true) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            return ((_errorCode__ == Core::ERROR_NONE) && (id_ == designatorId_));
                        });
                    }
                    else {
                        module_.Notify(_T("userupdate"), params, sendIfMethod_);
                    }
                }

                // Event: 'userupdate' - Notifies of user status changes
                template<typename MODULE>
                static void UserUpdate(const MODULE& module_, const string& id_, const JsonData::Messenger::UserUpdateParamsData& params, const string& client_)
                {
                    module_.Notify(_T("userupdate"), params, [&id_, &client_](const string& designator_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        const size_t _dot = designator_.find('.');
                        const string designatorId_ = designator_.substr(0, _dot);

                        if (designatorId_.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        return ((_errorCode__ == Core::ERROR_NONE) && ((client_.empty() == true) || (client_ == designator_.substr(_dot + 1))) && (id_ == designatorId_));
                    });
                }

                // Event: 'userupdate' - Notifies of user status changes
                template<typename MODULE>
                static void UserUpdate(const MODULE& module_, const string& id_, const Core::JSON::String& user, const Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::INotification::userupdate>& action, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Messenger::UserUpdateParamsData params_;
                    params_.User = user;
                    params_.Action = action;

                    UserUpdate(module_, id_, params_, sendIfMethod_);
                }

                // Event: 'userupdate' - Notifies of user status changes
                template<typename MODULE>
                static void UserUpdate(const MODULE& module_, const string& id_, const Core::JSON::String& user, const Core::JSON::EnumType<Exchange::JSONRPC::IMessenger::INotification::userupdate>& action, const string& client_)
                {
                    JsonData::Messenger::UserUpdateParamsData params_;
                    params_.User = user;
                    params_.Action = action;

                    UserUpdate(module_, id_, params_, client_);
                }

                // Event: 'userupdate' - Notifies of user status changes
                template<typename MODULE>
                static void UserUpdate(const MODULE& module_, const string& id_, const string& user, const IMessenger::INotification::userupdate action, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Messenger::UserUpdateParamsData params_;
                    params_.User = user;
                    params_.Action = action;

                    UserUpdate(module_, id_, params_, sendIfMethod_);
                }

                // Event: 'userupdate' - Notifies of user status changes
                template<typename MODULE>
                static void UserUpdate(const MODULE& module_, const string& id_, const string& user, const IMessenger::INotification::userupdate action, const string& client_)
                {
                    JsonData::Messenger::UserUpdateParamsData params_;
                    params_.User = user;
                    params_.Action = action;

                    UserUpdate(module_, id_, params_, client_);
                }

                // Event: 'message' - Notifies of messages sent the the room
                template<typename MODULE>
                static void Message(const MODULE& module_, const string& id_, const JsonData::Messenger::MessageParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(_T("message"), params, [&id_](const string& designator_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            const string designatorId_ = designator_.substr(0, designator_.find('.'));

                            if (designatorId_.empty() == true) {
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            return ((_errorCode__ == Core::ERROR_NONE) && (id_ == designatorId_));
                        });
                    }
                    else {
                        module_.Notify(_T("message"), params, sendIfMethod_);
                    }
                }

                // Event: 'message' - Notifies of messages sent the the room
                template<typename MODULE>
                static void Message(const MODULE& module_, const string& id_, const Core::JSON::String& user, const Core::JSON::String& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Messenger::MessageParamsData params_;
                    params_.User = user;
                    params_.Message = message;

                    Message(module_, id_, params_, sendIfMethod_);
                }

                // Event: 'message' - Notifies of messages sent the the room
                template<typename MODULE>
                static void Message(const MODULE& module_, const string& id_, const string& user, const string& message, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::Messenger::MessageParamsData params_;
                    params_.User = user;
                    params_.Message = message;

                    Message(module_, id_, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JMessenger

    } // namespace JSONRPC

} // namespace Exchange

} // namespace Thunder

