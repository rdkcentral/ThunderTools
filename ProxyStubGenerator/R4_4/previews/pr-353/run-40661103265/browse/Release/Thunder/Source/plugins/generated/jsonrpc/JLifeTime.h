// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace WPEFramework {

namespace Exchange {

    namespace Controller {

        namespace JLifeTime {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ILifeTime* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JLifeTime"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'activate' - Activate a plugin, i
                _module__.PluginHost::JSONRPC::Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("activate"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JLifeTime"), _T("activate")));
                        }

                        const string _callsign_{params.Callsign};

                        _errorCode__ = _implementation__->Activate(_callsign_);

                        return (_errorCode__);
                    });

                // Method: 'deactivate' - Deactivate a plugin, i
                _module__.PluginHost::JSONRPC::Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("deactivate"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JLifeTime"), _T("deactivate")));
                        }

                        const string _callsign_{params.Callsign};

                        _errorCode__ = _implementation__->Deactivate(_callsign_);

                        return (_errorCode__);
                    });

                // Method: 'unavailable' - Set a plugin unavailable for interaction
                _module__.PluginHost::JSONRPC::Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("unavailable"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JLifeTime"), _T("unavailable")));
                        }

                        const string _callsign_{params.Callsign};

                        _errorCode__ = _implementation__->Unavailable(_callsign_);

                        return (_errorCode__);
                    });

                // Method: 'hibernate' - Set a plugin in Hibernate state
                _module__.PluginHost::JSONRPC::Register<JsonData::LifeTime::HibernateParamsData, void>(_T("hibernate"),
                    [_implementation__](const JsonData::LifeTime::HibernateParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JLifeTime"), _T("hibernate")));
                        }

                        const string _callsign_{params.Callsign};
                        const uint32_t _timeout_{params.Timeout};

                        _errorCode__ = _implementation__->Hibernate(_callsign_, _timeout_);

                        return (_errorCode__);
                    });

                // Method: 'suspend' - Suspend a plugin
                _module__.PluginHost::JSONRPC::Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("suspend"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JLifeTime"), _T("suspend")));
                        }

                        const string _callsign_{params.Callsign};

                        _errorCode__ = _implementation__->Suspend(_callsign_);

                        return (_errorCode__);
                    });

                // Method: 'resume' - Resumes a plugin
                _module__.PluginHost::JSONRPC::Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("resume"),
                    [_implementation__](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JLifeTime"), _T("resume")));
                        }

                        const string _callsign_{params.Callsign};

                        _errorCode__ = _implementation__->Resume(_callsign_);

                        return (_errorCode__);
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
            }

            namespace Event {

                // Event: 'statechange' - Notifies a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const JsonData::LifeTime::StateChangeParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    module_.Notify(_T("statechange"), params, sendIfMethod_);
                }

                // Event: 'statechange' - Notifies a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const Core::JSON::String& callsign, const Core::JSON::EnumType<PluginHost::IShell::state>& state, const Core::JSON::EnumType<PluginHost::IShell::reason>& reason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;
                    params_.Callsign = callsign;
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, params_, sendIfMethod_);
                }

                // Event: 'statechange' - Notifies a plugin state change
                template<typename MODULE>
                static void StateChange(const MODULE& module_, const string& callsign, const PluginHost::IShell::state& state, const PluginHost::IShell::reason& reason, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
                {
                    JsonData::LifeTime::StateChangeParamsData params_;
                    params_.Callsign = callsign;
                    params_.State = state;
                    params_.Reason = reason;

                    StateChange(module_, params_, sendIfMethod_);
                }

            } // namespace Event

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JLifeTime

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

