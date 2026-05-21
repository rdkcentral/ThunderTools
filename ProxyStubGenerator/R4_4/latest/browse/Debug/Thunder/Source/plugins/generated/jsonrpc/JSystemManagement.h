// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace WPEFramework {

namespace Exchange {

    namespace Controller {

        namespace JSystemManagement {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, ISystemManagement* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JSystemManagement"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'reboot' - Reboot the device
                _module__.PluginHost::JSONRPC::Register<void, void>(_T("reboot"),
                    [_implementation__]() -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        _errorCode__ = _implementation__->Reboot();

                        return (_errorCode__);
                    });

                // Method: 'harakiri' - Reboot the device
                _module__.PluginHost::JSONRPC::Register<void, void>(_T("harakiri"),
                    [_implementation__]() -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        _errorCode__ = _implementation__->Reboot();

                        return (_errorCode__);
                    });

                // Method: 'delete' - Removes contents of a directory from the persistent storage
                _module__.PluginHost::JSONRPC::Register<JsonData::SystemManagement::DeleteParamsData, void>(_T("delete"),
                    [_implementation__](const JsonData::SystemManagement::DeleteParamsData& params) -> uint32_t {
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

                // Method: 'clone' - Create a clone of given plugin to requested new callsign
                _module__.PluginHost::JSONRPC::Register<JsonData::SystemManagement::CloneParamsData, Core::JSON::String>(_T("clone"),
                    [_implementation__](const JsonData::SystemManagement::CloneParamsData& params, Core::JSON::String& response) -> uint32_t {
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

                // Indexed Property: 'environment' - Provides the value of request environment variable (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("environment"),
                    [_implementation__](const string& index, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (index.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {
                            string _result_{};

                            _errorCode__ = _implementation__->Environment(index, _result_);

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
                _module__.PluginHost::JSONRPC::Unregister(_T("environment"));
            }

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JSystemManagement

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

