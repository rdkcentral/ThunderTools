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

            using JSONRPC = PluginHost::JSONRPC;

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

            static void Register(JSONRPC& _module_, ILifeTime* _impl_)
            {
                ASSERT(_impl_ != nullptr);

                _module_.RegisterVersion(_T("JLifeTime"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'activate' - Activate a plugin, i
                _module_.Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("activate"), 
                    [_impl_](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _callsign{params.Callsign};

                        _errorCode = _impl_->Activate(_callsign);

                        return (_errorCode);
                    });

                // Method: 'deactivate' - Deactivate a plugin, i
                _module_.Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("deactivate"), 
                    [_impl_](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _callsign{params.Callsign};

                        _errorCode = _impl_->Deactivate(_callsign);

                        return (_errorCode);
                    });

                // Method: 'unavailable' - Set a plugin unavailable for interaction
                _module_.Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("unavailable"), 
                    [_impl_](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _callsign{params.Callsign};

                        _errorCode = _impl_->Unavailable(_callsign);

                        return (_errorCode);
                    });

                // Method: 'hibernate' - Set a plugin in Hibernate state
                _module_.Register<JsonData::LifeTime::HibernateParamsData, void>(_T("hibernate"), 
                    [_impl_](const JsonData::LifeTime::HibernateParamsData& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _callsign{params.Callsign};
                        const uint32_t _timeout{params.Timeout};

                        _errorCode = _impl_->Hibernate(_callsign, _timeout);

                        return (_errorCode);
                    });

                // Method: 'suspend' - Suspend a plugin
                _module_.Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("suspend"), 
                    [_impl_](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _callsign{params.Callsign};

                        _errorCode = _impl_->Suspend(_callsign);

                        return (_errorCode);
                    });

                // Method: 'resume' - Resumes a plugin
                _module_.Register<JsonData::LifeTime::ActivateParamsInfo, void>(_T("resume"), 
                    [_impl_](const JsonData::LifeTime::ActivateParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _callsign{params.Callsign};

                        _errorCode = _impl_->Resume(_callsign);

                        return (_errorCode);
                    });

            }

            static void Unregister(JSONRPC& _module_)
            {
                // Unregister methods and properties...
                _module_.Unregister(_T("activate"));
                _module_.Unregister(_T("deactivate"));
                _module_.Unregister(_T("unavailable"));
                _module_.Unregister(_T("hibernate"));
                _module_.Unregister(_T("suspend"));
                _module_.Unregister(_T("resume"));
            }

            namespace Event {

                // Event: 'statechange' - Notifies a plugin state change
                static void StateChange(const JSONRPC& _module_, const JsonData::LifeTime::StateChangeParamsData& params)
                {
                    _module_.Notify(_T("statechange"), params);
                }

                // Event: 'statechange' - Notifies a plugin state change
                static void StateChange(const JSONRPC& _module_, const Core::JSON::String& callsign,
                         const Core::JSON::EnumType<PluginHost::IShell::state>& state, const Core::JSON::EnumType<PluginHost::IShell::reason>& reason)
                {
                    JsonData::LifeTime::StateChangeParamsData _params_;
                    _params_.Callsign = callsign;
                    _params_.State = state;
                    _params_.Reason = reason;

                    StateChange(_module_, _params_);
                }

                // Event: 'statechange' - Notifies a plugin state change
                static void StateChange(const JSONRPC& _module_, const string& callsign, const PluginHost::IShell::state& state,
                         const PluginHost::IShell::reason& reason)
                {
                    JsonData::LifeTime::StateChangeParamsData _params_;
                    _params_.Callsign = callsign;
                    _params_.State = state;
                    _params_.Reason = reason;

                    StateChange(_module_, _params_);
                }

            } // namespace Event

            POP_WARNING()

        } // namespace JLifeTime

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

