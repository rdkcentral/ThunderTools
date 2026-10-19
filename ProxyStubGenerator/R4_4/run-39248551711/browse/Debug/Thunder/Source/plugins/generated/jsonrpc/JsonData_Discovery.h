// C++ types for Discovery API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Discovery {

        // Method params/result classes
        //

        class StartDiscoveryParamsData : public Core::JSON::Container {
        public:
            StartDiscoveryParamsData()
                : Core::JSON::Container()
                , Ttl(1)
            {
                Add(_T("ttl"), &Ttl);
            }

            StartDiscoveryParamsData(const StartDiscoveryParamsData&) = delete;
            StartDiscoveryParamsData(StartDiscoveryParamsData&&) noexcept  = delete;

            StartDiscoveryParamsData& operator=(const StartDiscoveryParamsData&) = delete;
            StartDiscoveryParamsData& operator=(StartDiscoveryParamsData&&) noexcept  = delete;

            ~StartDiscoveryParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (true);
            }

        public:
            Core::JSON::DecUInt8 Ttl; // Starts the network discovery. Use this method to initiate SSDP network discovery process.
        }; // class StartDiscoveryParamsData

    } // namespace Discovery

    POP_WARNING()

} // namespace JsonData

}

