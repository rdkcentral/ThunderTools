// Generated automatically from 'IController.h'. DO NOT EDIT.

#pragma once

namespace WPEFramework {

namespace Exchange {

    namespace Controller {

        namespace JDiscovery {

            namespace Version {

                constexpr uint8_t Major = 1;
                constexpr uint8_t Minor = 0;
                constexpr uint8_t Patch = 0;

            } // namespace Version

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
            PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
            PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

            template<typename MODULE>
            static void Register(MODULE& _module__, IDiscovery* _implementation__)
            {
                ASSERT(_implementation__ != nullptr);

                _module__.PluginHost::JSONRPC::RegisterVersion(_T("JDiscovery"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'startdiscovery' - Starts the network discovery
                _module__.PluginHost::JSONRPC::Register<JsonData::Discovery::StartDiscoveryParamsData, void>(_T("startdiscovery"),
                    [_implementation__](const JsonData::Discovery::StartDiscoveryParamsData& params) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        if ((params.IsSet() == true) && (params.IsDataValid() == false)) {
                            _errorCode__ = Core::ERROR_BAD_REQUEST;
                        }
                        else {
                            const uint8_t _ttl_{params.Ttl};

                            _errorCode__ = _implementation__->StartDiscovery(_ttl_);

                        }

                        return (_errorCode__);
                    });

                // Property: 'discoveryresults' - Provides SSDP network discovery results (r/o)
                _module__.PluginHost::JSONRPC::Register<void, Core::JSON::String>(_T("discoveryresults"),
                    [_implementation__](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode__ = Core::ERROR_NONE;

                        string _result_{};

                        _errorCode__ = _implementation__->DiscoveryResults(_result_);

                        if (_errorCode__ == Core::ERROR_NONE) {

                            if (_result_.empty() == false) {
                                result = _result_;
                                result.SetQuoted(false);
                            }
                        }

                        return (_errorCode__);
                    });

            }

            template<typename MODULE>
            static void Unregister(MODULE& _module__)
            {
                // Unregister methods and properties...
                _module__.PluginHost::JSONRPC::Unregister(_T("startdiscovery"));
                _module__.PluginHost::JSONRPC::Unregister(_T("discoveryresults"));
            }

            POP_WARNING()
            POP_WARNING()
            POP_WARNING()

        } // namespace JDiscovery

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

