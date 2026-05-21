// Generated automatically from 'INetworkTools.h'. DO NOT EDIT.

#pragma once

#include "Module.h"
#include "JsonData_NetworkTools.h"
#include <interfaces/INetworkTools.h>

namespace WPEFramework {

namespace Exchange {

    namespace JNetworkTools {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        using JSONRPC = PluginHost::JSONRPC;

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)

        static void Register(JSONRPC& _module_, INetworkTools* _impl_)
        {
            ASSERT(_impl_ != nullptr);

            _module_.RegisterVersion(_T("JNetworkTools"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'ping' - Ping the given destination with ICMP packages
            _module_.Register<JsonData::NetworkTools::PingParamsData, void>(_T("ping"), 
                [_impl_](const JsonData::NetworkTools::PingParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _destination{params.Destination};
                    const uint16_t _timeOutInSeconds{params.TimeOutInSeconds};
                    const uint16_t _count{params.Count};

                    _errorCode = _impl_->Ping(_destination, _timeOutInSeconds, _count);

                    return (_errorCode);
                });

            // Method: 'traceroute' - TraceRoute to the given destination with ICMP packages
            _module_.Register<JsonData::NetworkTools::TraceRouteParamsData, void>(_T("traceroute"), 
                [_impl_](const JsonData::NetworkTools::TraceRouteParamsData& params) -> uint32_t {
                    uint32_t _errorCode = Core::ERROR_NONE;

                    const string _destination{params.Destination};
                    const uint16_t _timeOutInSeconds{params.TimeOutInSeconds};

                    _errorCode = _impl_->TraceRoute(_destination, _timeOutInSeconds);

                    return (_errorCode);
                });

        }

        static void Unregister(JSONRPC& _module_)
        {
            // Unregister methods and properties...
            _module_.Unregister(_T("ping"));
            _module_.Unregister(_T("traceroute"));
        }

        namespace Event {

            // Event: 'report' - Signals an message from a given host
            static void Report(const JSONRPC& _module_, const JsonData::NetworkTools::ReportParamsData& params)
            {
                _module_.Notify(_T("report"), params);
            }

            // Event: 'report' - Signals an message from a given host
            static void Report(const JSONRPC& _module_, const Core::JSON::String& source, const Core::JSON::String& metadata)
            {
                JsonData::NetworkTools::ReportParamsData _params_;
                _params_.Source = source;
                _params_.Metadata = metadata;

                Report(_module_, _params_);
            }

            // Event: 'report' - Signals an message from a given host
            static void Report(const JSONRPC& _module_, const string& source, const string& metadata)
            {
                JsonData::NetworkTools::ReportParamsData _params_;
                _params_.Source = source;
                _params_.Metadata = metadata;

                Report(_module_, _params_);
            }

        } // namespace Event

        POP_WARNING()

    } // namespace JNetworkTools

} // namespace Exchange

} // namespace WPEFramework

