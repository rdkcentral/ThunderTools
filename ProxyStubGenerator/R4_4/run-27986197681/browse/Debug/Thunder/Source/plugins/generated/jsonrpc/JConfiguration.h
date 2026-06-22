// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace WPEFramework {

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

                // Method: 'persist' - Stores the configuration to persistent memory
                _module__.PluginHost::JSONRPC::Register<void, void>(_T("persist"),
                    [_implementation__]() -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        _errorCode__ = _implementation__->Persist();

                        return (_errorCode__);
                    });

                // Method: 'storeconfig' - Stores the configuration to persistent memory
                _module__.PluginHost::JSONRPC::Register<void, void>(_T("storeconfig"),
                    [_implementation__]() -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        _errorCode__ = _implementation__->Persist();

                        return (_errorCode__);
                    });

                // Indexed Property: 'configuration' - Provides configuration value of a request service
                _module__.PluginHost::JSONRPC::Register<Core::JSON::String, Core::JSON::String, std::function<uint32_t(const string&, const Core::JSON::String&, Core::JSON::String&)>>(_T("configuration"),
                    [_implementation__](const string& callsign, const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if (callsign.empty() == true) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (params.IsSet() == false) {
                                string _result_{};

                                _errorCode__ = (static_cast<const IConfiguration*>(_implementation__))->Configuration(callsign, _result_);

                                if (_errorCode__ == Core::ERROR_NONE) {

                                    if (_result_.empty() == false) {
                                        result = _result_;
                                        result.SetQuoted(false);
                                    }
                                }
                            }
                            else {
                                const string _params_{params};

                                _errorCode__ = _implementation__->Configuration(callsign, _params_);

                                result.Null(true);
                            }
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
                _module__.PluginHost::JSONRPC::Unregister(_T("configuration"));
            }

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JConfiguration

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

