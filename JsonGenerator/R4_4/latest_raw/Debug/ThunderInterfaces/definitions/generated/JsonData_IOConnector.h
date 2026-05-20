// C++ classes for IO Connector API JSON-RPC API.
// Generated automatically from 'IOConnector.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    namespace IOConnector {

        // Method params/result classes
        //

        class ActivityParamsData : public Core::JSON::Container {
        public:
            ActivityParamsData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            bool IsValid() const
            {
                return (true);
            }

            ActivityParamsData(const ActivityParamsData&) = delete;
            ActivityParamsData& operator=(const ActivityParamsData&) = delete;

        public:
            Core::JSON::DecSInt32 Value;
        }; // class ActivityParamsData

    } // namespace IOConnector

} // namespace JsonData

}

