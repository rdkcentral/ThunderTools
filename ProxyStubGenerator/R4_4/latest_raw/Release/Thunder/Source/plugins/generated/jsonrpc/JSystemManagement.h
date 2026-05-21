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

            using JSONRPC = PluginHost::JSONRPC;

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

            static void Register(JSONRPC& _module_, ISystemManagement* _impl_)
            {
                ASSERT(_impl_ != nullptr);

                _module_.RegisterVersion(_T("JSystemManagement"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'reboot' - Reboot the device
                _module_.Register<void, void>(_T("reboot"), 
                    [_impl_]() -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        _errorCode = _impl_->Reboot();

                        return (_errorCode);
                    });

                // Method: 'harakiri' - Reboot the device
                _module_.Register<void, void>(_T("harakiri"), 
                    [_impl_]() -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        _errorCode = _impl_->Reboot();

                        return (_errorCode);
                    });

                // Method: 'delete' - Removes contents of a directory from the persistent storage
                _module_.Register<JsonData::SystemManagement::DeleteParamsData, void>(_T("delete"), 
                    [_impl_](const JsonData::SystemManagement::DeleteParamsData& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _path{params.Path};

                        _errorCode = _impl_->Delete(_path);

                        return (_errorCode);
                    });

                // Method: 'clone' - Create a clone of given plugin to requested new callsign
                _module_.Register<JsonData::SystemManagement::CloneParamsData, Core::JSON::String>(_T("clone"), 
                    [_impl_](const JsonData::SystemManagement::CloneParamsData& params, Core::JSON::String& response) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const string _callsign{params.Callsign};
                        const string _newcallsign{params.Newcallsign};
                        string _response{};

                        _errorCode = _impl_->Clone(_callsign, _newcallsign, _response);

                        if (_errorCode == Core::ERROR_NONE) {
                            response = _response;
                        }

                        return (_errorCode);
                    });

                // Indexed Property: 'environment' - Provides the value of request environment variable (r/o)
                _module_.Register<void, Core::JSON::String, std::function<uint32_t(const string&, Core::JSON::String&)>>(_T("environment"), 
                    [_impl_](const string& _index_, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->Environment(_index_, _result);

                        if (_errorCode == Core::ERROR_NONE) {
                            result = _result;
                            result.SetQuoted(false);
                        }

                        return (_errorCode);
                    });

            }

            static void Unregister(JSONRPC& _module_)
            {
                // Unregister methods and properties...
                _module_.Unregister(_T("reboot"));
                _module_.Unregister(_T("harakiri"));
                _module_.Unregister(_T("delete"));
                _module_.Unregister(_T("clone"));
                _module_.Unregister(_T("environment"));
            }

            POP_WARNING()

        } // namespace JSystemManagement

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

