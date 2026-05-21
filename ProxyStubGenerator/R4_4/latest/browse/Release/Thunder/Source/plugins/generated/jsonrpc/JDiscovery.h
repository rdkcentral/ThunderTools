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

            using JSONRPC = PluginHost::JSONRPC;

            PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

            static void Register(JSONRPC& _module_, IDiscovery* _impl_)
            {
                ASSERT(_impl_ != nullptr);

                _module_.RegisterVersion(_T("JDiscovery"), Version::Major, Version::Minor, Version::Patch);

                // Register methods and properties...

                // Method: 'startdiscovery' - Starts the network discovery
                _module_.Register<JsonData::Discovery::StartDiscoveryParamsData, void>(_T("startdiscovery"), 
                    [_impl_](const JsonData::Discovery::StartDiscoveryParamsData& params) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        const uint8_t _ttl{params.Ttl};

                        _errorCode = _impl_->StartDiscovery(_ttl);

                        return (_errorCode);
                    });

                // Property: 'discoveryresults' - Provides SSDP network discovery results (r/o)
                _module_.Register<void, Core::JSON::String>(_T("discoveryresults"), 
                    [_impl_](Core::JSON::String& result) -> uint32_t {
                        uint32_t _errorCode = Core::ERROR_NONE;

                        // read-only property get
                        string _result{};

                        _errorCode = _impl_->DiscoveryResults(_result);

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
                _module_.Unregister(_T("startdiscovery"));
                _module_.Unregister(_T("discoveryresults"));
            }

            POP_WARNING()

        } // namespace JDiscovery

    } // namespace Controller

} // namespace Exchange

} // namespace WPEFramework

