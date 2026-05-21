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

            using JSONRPC = PluginHost::JSONRPC;

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

            static void Register(JSONRPC& _module_, IConfiguration* _impl_)
            {
                ASSERT(_impl_ != nullptr);

                _module_.RegisterVersion(_T("JConfiguration"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'persist' - Stores the configuration to persistent memory
                _module_.Register<void, void>(_T("persist"), 
                    [_impl_]() -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        _errorCode = _impl_->Persist();

                        return (_errorCode);
                    });

                // Method: 'storeconfig' - Stores the configuration to persistent memory
                _module_.Register<void, void>(_T("storeconfig"), 
                    [_impl_]() -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        _errorCode = _impl_->Persist();

                        return (_errorCode);
                    });

                // Indexed Property: 'configuration' - Provides configuration value of a request service
                _module_.Register<Core::JSON::String, Core::JSON::String, std::function<uint32_t(const string&, const Core::JSON::String&,
                         Core::JSON::String&)>>(_T("configuration"), 
                    [_impl_](const string& _index_, const Core::JSON::String& params, Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        if (params.IsSet() == false) {
                            // property get
                            string _result{};

                            _errorCode = (static_cast<const IConfiguration*>(_impl_))->Configuration(_index_, _result);

                            if (_errorCode == Core::ERROR_NONE) {
                                result = _result;
                                result.SetQuoted(false);
                            }

                        } else {
                            // property set
                            const string _params{params};

                            _errorCode = _impl_->Configuration(_index_, _params);

                            result.Null(true);
                        }
                        return (_errorCode);
                    });

            }

            static void Unregister(JSONRPC& _module_)
            {
                // Unregister methods and properties...
                _module_.Unregister(_T("persist"));
                _module_.Unregister(_T("storeconfig"));
                _module_.Unregister(_T("configuration"));
            }

            POP_WARNING()

        } // namespace JConfiguration

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

