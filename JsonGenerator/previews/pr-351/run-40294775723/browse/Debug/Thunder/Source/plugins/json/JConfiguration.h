// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace Thunder {

namespace Exchange {

    namespace Controller {

        namespace JConfiguration {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IConfiguration* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JConfiguration"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'persist' - Stores configuration to the persistent memory
                _module__.PluginHost::JSONRPC::template Register<JsonData::Configuration::PersistParamsInfo, void>(_T("persist"),
                    [_implementation__](const JsonData::Configuration::PersistParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == true) && (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JConfiguration"), _T("persist")));
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            Core::OptionalType<string> _callsign_{};
                            if (params.Callsign.IsSet() == true) {
                                _callsign_ = params.Callsign;
                            }

                            _errorCode__ = _implementation__->Persist(_callsign_);

                        }

                        return (_errorCode__);
                    });

                _module__.PluginHost::JSONRPC::Register(_T("storeconfig"), _T("persist"));

                // Method: 'restore' - Restores configuration back to default
                _module__.PluginHost::JSONRPC::template Register<JsonData::Configuration::PersistParamsInfo, void>(_T("restore"),
                    [_implementation__](const JsonData::Configuration::PersistParamsInfo& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == true) && (params.IsDataValid() == false)) {
                            TRACE_GLOBAL(Trace::Error, (_T("Invalid parameters for JSON-RPC call: %s.%s"), _T("JConfiguration"), _T("restore")));
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            Core::OptionalType<string> _callsign_{};
                            if (params.Callsign.IsSet() == true) {
                                _callsign_ = params.Callsign;
                            }

                            _errorCode__ = _implementation__->Restore(_callsign_);

                        }

                        return (_errorCode__);
                    });

                // Indexed Property: 'configuration' - Service configuration
                _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String, std::function<uint32_t(const string&, const Core::JSON::String&, Core::JSON::String&)>>(_T("configuration"),
                    [_implementation__](const string& callsign, const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            Core::OptionalType<string> _callsignOpt__{};

                            if (callsign.empty() == true) {
                                // no error, optional
                            }
                            else {
                                _callsignOpt__ = callsign;
                            }

                            string _result_{};

                            _errorCode__ = (static_cast<const IConfiguration*>(_implementation__))->Configuration(_callsignOpt__, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {

                                if (_result_.empty() == false) {
                                    result = _result_;
                                    result.SetQuoted(false);
                                }
                            }
                        }
                        else {

                            if (callsign.empty() == true) {
                                TRACE_GLOBAL(Trace::Error, (_T("Missing index for JSON-RPC call: %s.%s"), _T("JConfiguration"), _T("configuration")));
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }

                            if (_errorCode__ == Core::ERROR_NONE) {
                                const string _params_{params};

                                _errorCode__ = _implementation__->Configuration(callsign, _params_);

                            }

                            result.Null(true);
                        }

                        return (_errorCode__);
                    });

                // Indexed Property: 'attribute' - Framework attributes
                _module__.PluginHost::JSONRPC::template Register<Core::JSON::String, Core::JSON::String, std::function<uint32_t(const string&, const Core::JSON::String&, Core::JSON::String&)>>(_T("attribute"),
                    [_implementation__](const string& attribute, const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            Core::OptionalType<Exchange::Controller::IConfiguration::attribute> _attributeOpt__{};

                            if (attribute.empty() == true) {
                                // no error, optional
                            }
                            else {
                                Exchange::Controller::IConfiguration::attribute _attributeConv__{};
                                Core::EnumerateType<Exchange::Controller::IConfiguration::attribute> _attributeConvEnum__(attribute.c_str());
                                const bool _attributeConvResult__ = _attributeConvEnum__.IsSet();
                                _attributeConv__ = _attributeConvEnum__.Value();

                                if (_attributeConvResult__ == false) {
                                    TRACE_GLOBAL(Trace::Error, (_T("Invalid index for JSON-RPC call: %s.%s"), _T("JConfiguration"), _T("attribute")));
                                    _errorCode__ = Core::ERROR_BAD_REQUEST;
                                }
                                else {
                                    _attributeOpt__ = _attributeConv__;
                                }
                            }

                            if (_errorCode__ == Core::ERROR_NONE) {
                                string _result_{};

                                _errorCode__ = (static_cast<const IConfiguration*>(_implementation__))->Attribute(_attributeOpt__, _result_);

                                if (_errorCode__ == Core::ERROR_NONE) {

                                    if (_result_.empty() == false) {
                                        result = _result_;
                                        result.SetQuoted(false);
                                    }
                                }
                            }
                        }
                        else {
                            Exchange::Controller::IConfiguration::attribute _attributeConv__{};

                            if (attribute.empty() == true) {
                                TRACE_GLOBAL(Trace::Error, (_T("Missing index for JSON-RPC call: %s.%s"), _T("JConfiguration"), _T("attribute")));
                                _errorCode__ = Core::ERROR_BAD_REQUEST;
                            }
                            else {
                                Core::EnumerateType<Exchange::Controller::IConfiguration::attribute> _attributeConvEnum__(attribute.c_str());
                                const bool _attributeConvResult__ = _attributeConvEnum__.IsSet();
                                _attributeConv__ = _attributeConvEnum__.Value();

                                if (_attributeConvResult__ == false) {
                                    TRACE_GLOBAL(Trace::Error, (_T("Invalid index for JSON-RPC call: %s.%s"), _T("JConfiguration"), _T("attribute")));
                                    _errorCode__ = Core::ERROR_BAD_REQUEST;
                                }
                            }

                            if (_errorCode__ == Core::ERROR_NONE) {
                                const string _params_{params};

                                _errorCode__ = _implementation__->Attribute(_attributeConv__, _params_);

                            }

                            result.Null(true);
                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("persist"));
                _module__.PluginHost::JSONRPC::Unregister(_T("storeconfig"));
                _module__.PluginHost::JSONRPC::Unregister(_T("restore"));
                _module__.PluginHost::JSONRPC::Unregister(_T("configuration"));
                _module__.PluginHost::JSONRPC::Unregister(_T("attribute"));
            }

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JConfiguration

    } // namespace Controller

} // namespace Exchange

} // namespace Thunder

