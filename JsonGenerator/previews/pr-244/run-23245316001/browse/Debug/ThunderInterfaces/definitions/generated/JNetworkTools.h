// Generated automatically from 'INetworkTools.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_NetworkTools.h"
#include <interfaces/INetworkTools.h>

namespace Thunder {

namespace Exchange {

    namespace JNetworkTools {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, INetworkTools* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JNetworkTools"), Version::Major, Version::Minor, Version::Patch);

            // Register methods and properties...

            // Method: 'ping' - Ping the given destination with ICMP packages
            _module__.PluginHost::JSONRPC::template Register<JsonData::NetworkTools::PingParamsData, void>(_T("ping"),
                [_implementation__](const JsonData::NetworkTools::PingParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _destination_{params.Destination};
                        const uint16_t _timeOutInSeconds_{params.TimeOutInSeconds};
                        const uint16_t _count_{params.Count};

                        _errorCode__ = _implementation__->Ping(_destination_, _timeOutInSeconds_, _count_);

                    }

                    return (_errorCode__);
                });

            // Method: 'traceRoute' - TraceRoute to the given destination with ICMP packages
            _module__.PluginHost::JSONRPC::template Register<JsonData::NetworkTools::TraceRouteParamsData, void>(_T("traceRoute"),
                [_implementation__](const JsonData::NetworkTools::TraceRouteParamsData& params) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    if ((params.IsSet() == false) || (params.IsDataValid() == false)) {
                        _errorCode__ = Core::ERROR_BAD_REQUEST;
                    }
                    else {
                        const string _destination_{params.Destination};
                        const uint16_t _timeOutInSeconds_{params.TimeOutInSeconds};

                        _errorCode__ = _implementation__->TraceRoute(_destination_, _timeOutInSeconds_);

                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("ping"));
            _module__.PluginHost::JSONRPC::Unregister(_T("traceRoute"));
        }

        namespace Event {

            // Event: 'report' - Signals an message from a given host
            template<typename MODULE>
            static void Report(const MODULE& module_, const JsonData::NetworkTools::ReportParamsData& params, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("report"), params, sendIfMethod_);
            }

            // Event: 'report' - Signals an message from a given host
            template<typename MODULE>
            static void Report(const MODULE& module_, const Core::JSON::String& source, const Core::JSON::String& metadata, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::NetworkTools::ReportParamsData params_;
                params_.Source = source;
                params_.Metadata = metadata;

                Report(module_, params_, sendIfMethod_);
            }

            // Event: 'report' - Signals an message from a given host
            template<typename MODULE>
            static void Report(const MODULE& module_, const string& source, const string& metadata, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                JsonData::NetworkTools::ReportParamsData params_;
                params_.Source = source;
                params_.Metadata = metadata;

                Report(module_, params_, sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JNetworkTools

} // namespace Exchange

} // namespace Thunder

