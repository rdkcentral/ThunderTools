// C++ classes for Discovery API JSON-RPC API.
// Generated automatically from 'IController.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    namespace Discovery {

        // Method params/result classes
        //

        class StartDiscoveryParamsData : public Core::JSON::Container {
        public:
            StartDiscoveryParamsData()
                : Core::JSON::Container()
            {
                Add(_T("ttl"), &Ttl);
            }

            bool IsValid() const
            {
                return (true);
            }

            StartDiscoveryParamsData(const StartDiscoveryParamsData&) = delete;
            StartDiscoveryParamsData& operator=(const StartDiscoveryParamsData&) = delete;

        public:
            Core::JSON::DecUInt8 Ttl; // Starts the network discovery. Use this method to initiate SSDP network discovery process.
        }; // class StartDiscoveryParamsData

    } // namespace Discovery

} // namespace JsonData

}

