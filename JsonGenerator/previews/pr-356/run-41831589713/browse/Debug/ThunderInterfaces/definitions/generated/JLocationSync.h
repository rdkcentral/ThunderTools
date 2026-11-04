// Generated automatically from 'ILocationSync.h'. DO NOT EDIT.

#pragma once
#include "Module.h"
#include "JsonData_LocationSync.h"
#include <interfaces/ILocationSync.h>

namespace Thunder {

namespace Exchange {

    namespace JLocationSync {

        namespace Version {

            constexpr uint8_t Major = 1;
            constexpr uint8_t Minor = 0;
            constexpr uint8_t Patch = 0;

        } // namespace Version

        PUSH_WARNING(DISABLE_WARNING_UNUSED_FUNCTIONS)
        PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
        PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

        template<typename MODULE>
        static void Register(MODULE& _module__, ILocationSync* _implementation__)
        {
            ASSERT(_implementation__ != nullptr);

            _module__.PluginHost::JSONRPC::RegisterVersion(_T("JLocationSync"), Version::Major, Version::Minor, Version::Patch);

            // Register alternative notification names...
            _module__.PluginHost::JSONRPC::RegisterEventAlias(_T("locationchange"), _T("updated"));

            // Register methods and properties...

            // Method: 'sync' - Synchronize the location
            _module__.PluginHost::JSONRPC::template Register<void, void>(_T("sync"),
                [_implementation__]() -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    _errorCode__ = _implementation__->Sync();

                    return (_errorCode__);
                });

            // Property: 'location' - Get information about the location (r/o)
            _module__.PluginHost::JSONRPC::template Register<void, JsonData::LocationSync::LocationInfoData>(_T("location"),
                [_implementation__](JsonData::LocationSync::LocationInfoData& result) -> uint32_t {
                    uint32_t _errorCode__ = Core::ERROR_NONE;

                    Exchange::ILocationSync::LocationInfo _result_{};

                    _errorCode__ = _implementation__->Location(_result_);

                    if (_errorCode__ == Core::ERROR_NONE) {
                        result = _result_;
                    }

                    return (_errorCode__);
                });

        }

        template<typename MODULE>
        static void Unregister(MODULE& _module__)
        {
            // Unregister methods and properties...
            _module__.PluginHost::JSONRPC::Unregister(_T("sync"));
            _module__.PluginHost::JSONRPC::Unregister(_T("location"));

            // Unegister alternative notification names...
            _module__.PluginHost::JSONRPC::UnregisterEventAlias(_T("locationchange"), _T("updated"));
        }

        namespace Event {

            // Event: 'updated' - Signals a location change
            template<typename MODULE>
            static void Updated(const MODULE& module_, typename MODULE::SendIfMethod sendIfMethod_ = nullptr)
            {
                module_.Notify(_T("updated"), sendIfMethod_);
            }

        } // namespace Event

        POP_WARNING()
        POP_WARNING()
        POP_WARNING()

    } // namespace JLocationSync

} // namespace Exchange

} // namespace Thunder

