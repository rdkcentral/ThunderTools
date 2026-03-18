// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace Thunder {

namespace Exchange {

    namespace Controller {

        namespace JSystem {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ISystem* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSystem"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'reboot' - Reboots the device
                _module__.PluginHost::JSONRPC::template Register<void, void>(_T("reboot"),
                    [_implementation__]() -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        _errorCode__ = _implementation__->Reboot();

                        return (_errorCode__);
                    });

                _module__.PluginHost::JSONRPC::Register(_T("harakiri"), _T("reboot"));

                // Method: 'delete' - Removes contents of a directory from the persistent storage
                _module__.PluginHost::JSONRPC::template Register<JsonData::System::DeleteParamsData, void>(_T("delete"),
                    [_implementation__](const JsonData::System::DeleteParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _path_{params.Path};

                            _errorCode__ = _implementation__->Delete(_path_);

                        }

                        return (_errorCode__);
                    });

                // Method: 'clone' - Creates a clone of given plugin with a new callsign
                _module__.PluginHost::JSONRPC::template Register<JsonData::System::CloneParamsData, Core::JSON::String>(_T("clone"),
                    [_implementation__](const JsonData::System::CloneParamsData& params, Core::JSON::String& response) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};
                            const string _newcallsign_{params.Newcallsign};
                            string _response_{};

                            _errorCode__ = _implementation__->Clone(_callsign_, _newcallsign_, _response_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                response = _response_;
                            }
                        }

                        return (_errorCode__);
                    });

                // Method: 'destroy' - Destroy given plugin
                _module__.PluginHost::JSONRPC::template Register<JsonData::System::DestroyParamsData, void>(_T("destroy"),
                    [_implementation__](const JsonData::System::DestroyParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const string _callsign_{params.Callsign};

                            _errorCode__ = _implementation__->Destroy(_callsign_);

                        }

                        return (_errorCode__);
                    });

                // Indexed Property: 'environment' - Environment variable value (r/o)
                _module__.PluginHost::JSONRPC::template Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("environment"),
                    [_implementation__](const string& variable, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (variable.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            string _result_{};

                            _errorCode__ = _implementation__->Environment(variable, _result_);

                            if (_errorCode__ == Core::ERROR_NONE) {
                                result = _result_;
                            }
                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("reboot"));
                _module__.PluginHost::JSONRPC::Unregister(_T("harakiri"));
                _module__.PluginHost::JSONRPC::Unregister(_T("delete"));
                _module__.PluginHost::JSONRPC::Unregister(_T("clone"));
                _module__.PluginHost::JSONRPC::Unregister(_T("destroy"));
                _module__.PluginHost::JSONRPC::Unregister(_T("environment"));
            }

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JSystem

    } // namespace Controller

} // namespace Exchange

} // namespace Thunder

