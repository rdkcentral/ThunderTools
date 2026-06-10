// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace Thunder {

namespace Exchange {

    namespace Controller {

        namespace JLifeTime {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            struct IHandler {
                virtual ~IHandler() = default;
                virtual void OnStateChangeEventRegistration(const string& client, const Core::OptionalType<string>& index, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
                virtual void OnStateControlStateChangeEventRegistration(const string& client, const Core::OptionalType<string>& index, const PluginHost::JSONRPCSupportsEventStatus::Status status) = 0;
            };

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ILifeTime* _implementation__, IHandler* _handler_)
            {
                ASSERT(_implementation__ != nullptr);
                ASSERT(_handler_ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JLifeTime"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'activate' - Activates a plugin
                _module__.PluginHost::JSONRPC::template Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("activate"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};

                            _errorCode__ = _implementation__->Activate(_callsign_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'deactivate' - Deactivates a plugin
                _module__.PluginHost::JSONRPC::template Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("deactivate"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};

                            _errorCode__ = _implementation__->Deactivate(_callsign_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'unavailable' - Makes a plugin unavailable for interaction
                _module__.PluginHost::JSONRPC::template Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("unavailable"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};

                            _errorCode__ = _implementation__->Unavailable(_callsign_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'hibernate' - Hibernates a plugin
                _module__.PluginHost::JSONRPC::template Register<JsonData::LifeTime::HibernateParamsData, void>(_T("hibernate"),
                    [_implementation__](const JsonData::LifeTime::HibernateParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};
                            const uint32_t _timeout_{params.Timeout};

                            _errorCode__ = _implementation__->Hibernate(_callsign_, _timeout_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'suspend' - Suspends a plugin
                _module__.PluginHost::JSONRPC::template Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("suspend"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};

                            _errorCode__ = _implementation__->Suspend(_callsign_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'resume' - Resumes a plugin
                _module__.PluginHost::JSONRPC::template Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("resume"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};

                            _errorCode__ = _implementation__->Resume(_callsign_);

                        }

                        return (_errorCode__);
                    });

                // Register event status listeners...

                _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("statechange"),
                    [_handler_](const uint32_t, const string&, const string& client_, const string& index_, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<string> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _indexOpt__ = index_;
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            _handler_->OnStateChangeEventRegistration(client_, _indexOpt__, status_);
                        }
                    });

                _module__.PluginHost::JSONRPCSupportsEventStatus::RegisterEventStatusListener(_T("statecontrolstatechange"),
                    [_handler_](const uint32_t, const string&, const string& client_, const string& index_, const PluginHost::JSONRPCSupportsEventStatus::Status status_) {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<string> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _indexOpt__ = index_;
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            _handler_->OnStateControlStateChangeEventRegistration(client_, _indexOpt__, status_);
                        }
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("activate"));
                _module__.PluginHost::JSONRPC::Unregister(_T("deactivate"));
                _module__.PluginHost::JSONRPC::Unregister(_T("unavailable"));
                _module__.PluginHost::JSONRPC::Unregister(_T("hibernate"));
                _module__.PluginHost::JSONRPC::Unregister(_T("suspend"));
                _module__.PluginHost::JSONRPC::Unregister(_T("resume"));

                // Unregister event status listeners...
                _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("statechange"));
                _module__.PluginHost::JSONRPCSupportsEventStatus::UnregisterEventStatusListener(_T("statecontrolstatechange"));
            }

            namespace Event {

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateChangeParamsData& params, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(_T("statechange"), params, [&id_](const string&, const string& index_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            Core::OptionalType<string> _indexOpt__{};

                            if (index_.empty() == true) {
                                // no error, optional
                            }
                            else {
                                _indexOpt__ = index_;
                            }

                            return ((_errorCode__ == Core::ERROR_NONE) && ((_indexOpt__.IsSet() == false) || (id_ == _indexOpt__)));
                        });
                    }
                    else {
                        module_.Notify(_T("statechange"), params, sendIfMethod_);
                    }
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateChangeParamsData& params, const string& client_)
                {
                    module_.Notify(_T("statechange"), params, [&id_, &client_](const string& designator_, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<string> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _indexOpt__ = index_;
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && ((_indexOpt__.IsSet() == false) || (id_ == _indexOpt__)) && (client_ == designator_));
                    });
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateChangeParamsData& params, const bool, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(_T("statechange"), params, [&id_](const string&, const string& index_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            Core::OptionalType<string> _indexOpt__{};

                            if (index_.empty() == true) {
                                // no error, optional
                            }
                            else {
                                _indexOpt__ = index_;
                            }

                            return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexOpt__));
                        });
                    }
                    else {
                        module_.Notify(_T("statechange"), params, sendIfMethod_);
                    }
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateChangeParamsData& params, const bool, const string& client_)
                {
                    module_.Notify(_T("statechange"), params, [&id_, &client_](const string& designator_, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<string> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _indexOpt__ = index_;
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexOpt__) && (client_ == designator_));
                    });
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::JSON::String& callsign, const Core::JSON::EnumType<PluginHost::IShell::state>& state, const Core::JSON::EnumType<PluginHost::IShell::reason>& reason, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;
                    params_.Callsign = callsign;
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, id_, params_, sendIfMethod_);
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::JSON::String& callsign, const Core::JSON::EnumType<PluginHost::IShell::state>& state, const Core::JSON::EnumType<PluginHost::IShell::reason>& reason, const string& client_)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;
                    params_.Callsign = callsign;
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, id_, params_, client_);
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& callsign, const PluginHost::IShell::state& state, const PluginHost::IShell::reason& reason, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, callsign.Value(), params_, sendIfMethod_);
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& callsign, const PluginHost::IShell::state& state, const PluginHost::IShell::reason& reason, const string& client_)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, callsign.Value(), params_, client_);
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::OptionalType<string>& callsign, const PluginHost::IShell::state& state, const PluginHost::IShell::reason& reason, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, id_, params_, true, sendIfMethod_);
                }

                // Event: 'statechange' - Notifies of a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::OptionalType<string>& callsign, const PluginHost::IShell::state& state, const PluginHost::IShell::reason& reason, const string& client_)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, id_, params_, true, client_);
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateControlStateChangeParamsData& params, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(_T("statecontrolstatechange"), params, [&id_](const string&, const string& index_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            Core::OptionalType<string> _indexOpt__{};

                            if (index_.empty() == true) {
                                // no error, optional
                            }
                            else {
                                _indexOpt__ = index_;
                            }

                            return ((_errorCode__ == Core::ERROR_NONE) && ((_indexOpt__.IsSet() == false) || (id_ == _indexOpt__)));
                        });
                    }
                    else {
                        module_.Notify(_T("statecontrolstatechange"), params, sendIfMethod_);
                    }
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateControlStateChangeParamsData& params, const string& client_)
                {
                    module_.Notify(_T("statecontrolstatechange"), params, [&id_, &client_](const string& designator_, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<string> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _indexOpt__ = index_;
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && ((_indexOpt__.IsSet() == false) || (id_ == _indexOpt__)) && (client_ == designator_));
                    });
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateControlStateChangeParamsData& params, const bool, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    if (sendIfMethod_ == nullptr) {
                        module_.Notify(_T("statecontrolstatechange"), params, [&id_](const string&, const string& index_) -> bool {
                            Core::hresult _errorCode__ = Core::ERROR_NONE;
                            Core::OptionalType<string> _indexOpt__{};

                            if (index_.empty() == true) {
                                // no error, optional
                            }
                            else {
                                _indexOpt__ = index_;
                            }

                            return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexOpt__));
                        });
                    }
                    else {
                        module_.Notify(_T("statecontrolstatechange"), params, sendIfMethod_);
                    }
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const JsonData::LifeTime::StateControlStateChangeParamsData& params, const bool, const string& client_)
                {
                    module_.Notify(_T("statecontrolstatechange"), params, [&id_, &client_](const string& designator_, const string& index_) -> bool {
                        Core::hresult _errorCode__ = Core::ERROR_NONE;
                        Core::OptionalType<string> _indexOpt__{};

                        if (index_.empty() == true) {
                            // no error, optional
                        }
                        else {
                            _indexOpt__ = index_;
                        }

                        return ((_errorCode__ == Core::ERROR_NONE) && (id_ == _indexOpt__) && (client_ == designator_));
                    });
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::JSON::String& callsign, const Core::JSON::EnumType<Exchange::Controller::ILifeTime::state>& state, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateControlStateChangeParamsData params_;
                    params_.Callsign = callsign;
                    params_.State = state;

                    StateControlStateChange(module_, id_, params_, sendIfMethod_);
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::JSON::String& callsign, const Core::JSON::EnumType<Exchange::Controller::ILifeTime::state>& state, const string& client_)
                {
                    JsonData::LifeTime::StateControlStateChangeParamsData params_;
                    params_.Callsign = callsign;
                    params_.State = state;

                    StateControlStateChange(module_, id_, params_, client_);
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& callsign, const ILifeTime::state& state, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateControlStateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;

                    StateControlStateChange(module_, callsign.Value(), params_, sendIfMethod_);
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& callsign, const ILifeTime::state& state, const string& client_)
                {
                    JsonData::LifeTime::StateControlStateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;

                    StateControlStateChange(module_, callsign.Value(), params_, client_);
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::OptionalType<string>& callsign, const ILifeTime::state& state, typename MODULE::SendIfMethodIndexed sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateControlStateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;

                    StateControlStateChange(module_, id_, params_, true, sendIfMethod_);
                }

                // Event: 'statecontrolstatechange' - Notifies of a plugin state change controlled by IStateControl
                template<typename MODULE>
                static void StateControlStateChange(const MODULE& module_, const Core::OptionalType<string>& id_, const Core::OptionalType<string>& callsign, const ILifeTime::state& state, const string& client_)
                {
                    JsonData::LifeTime::StateControlStateChangeParamsData params_;

                    if (callsign.IsSet() == true) {
                        params_.Callsign = callsign.Value();
                    }
                    params_.State = state;

                    StateControlStateChange(module_, id_, params_, true, client_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JLifeTime

    } // namespace Controller

} // namespace Exchange

} // namespace Thunder

