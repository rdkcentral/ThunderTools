// C++ types for IO Connector API.
// Generated automatically from 'IOConnector.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

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

            ActivityParamsData(const ActivityParamsData&) = delete;
            ActivityParamsData(ActivityParamsData&&) noexcept  = delete;

            ActivityParamsData& operator=(const ActivityParamsData&) = delete;
            ActivityParamsData& operator=(ActivityParamsData&&) noexcept  = delete;

            ~ActivityParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::DecSInt32 Value;
        }; // class ActivityParamsData

    } // namespace IOConnector

    POP_WARNING()

} // namespace JsonData

}

