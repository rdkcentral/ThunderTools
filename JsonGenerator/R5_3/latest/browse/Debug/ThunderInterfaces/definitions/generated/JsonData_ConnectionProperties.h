// C++ types for ConnectionProperties API.
// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IDisplayInfo.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace ConnectionProperties {

        // Method params/result classes
        //

        class EDIDParamsData : public Core::JSON::Container {
        public:
            EDIDParamsData()
                : Core::JSON::Container()
            {
                Add(_T("length"), &Length);
            }

            EDIDParamsData(const EDIDParamsData&) = delete;
            EDIDParamsData(EDIDParamsData&&) noexcept  = delete;

            EDIDParamsData& operator=(const EDIDParamsData&) = delete;
            EDIDParamsData& operator=(EDIDParamsData&&) noexcept  = delete;

            ~EDIDParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Length.IsSet() == true);
            }

        public:
            Core::JSON::DecUInt16 Length; // Length of EDID byte string
        }; // class EDIDParamsData

        class EDIDResultData : public Core::JSON::Container {
        public:
            EDIDResultData()
                : Core::JSON::Container()
            {
                Add(_T("length"), &Length);
                Add(_T("data"), &Data);
            }

            EDIDResultData(const EDIDResultData&) = delete;
            EDIDResultData(EDIDResultData&&) noexcept  = delete;

            EDIDResultData& operator=(const EDIDResultData&) = delete;
            EDIDResultData& operator=(EDIDResultData&&) noexcept  = delete;

            ~EDIDResultData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Length.IsSet() == true) && (Data.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt16 Length; // Length of EDID byte string
            Core::JSON::String Data; // EDID byte string
        }; // class EDIDResultData

        class UpdatedParamsData : public Core::JSON::Container {
        public:
            UpdatedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("event"), &Event);
            }

            UpdatedParamsData(const UpdatedParamsData&) = delete;
            UpdatedParamsData(UpdatedParamsData&&) noexcept  = delete;

            UpdatedParamsData& operator=(const UpdatedParamsData&) = delete;
            UpdatedParamsData& operator=(UpdatedParamsData&&) noexcept  = delete;

            ~UpdatedParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (Event.IsSet() == true);
            }

        public:
            Core::JSON::EnumType<Exchange::IConnectionProperties::INotification::Source> Event; // Source of this event
        }; // class UpdatedParamsData

    } // namespace ConnectionProperties

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IConnectionProperties::HDCPProtectionType)
ENUM_CONVERSION_HANDLER(Exchange::IConnectionProperties::INotification::Source)

}

