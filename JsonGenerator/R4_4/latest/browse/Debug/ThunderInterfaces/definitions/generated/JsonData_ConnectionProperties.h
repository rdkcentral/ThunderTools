// C++ classes for ConnectionProperties API JSON-RPC API.
// Generated automatically from 'IDisplayInfo.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IDisplayInfo.h>

namespace WPEFramework {

namespace JsonData {

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

            bool IsValid() const
            {
                return (true);
            }

            EDIDParamsData(const EDIDParamsData&) = delete;
            EDIDParamsData& operator=(const EDIDParamsData&) = delete;

        public:
            Core::JSON::DecUInt16 Length;
        }; // class EDIDParamsData

        class EDIDResultData : public Core::JSON::Container {
        public:
            EDIDResultData()
                : Core::JSON::Container()
            {
                Add(_T("length"), &Length);
                Add(_T("data"), &Data);
            }

            bool IsValid() const
            {
                return (true);
            }

            EDIDResultData(const EDIDResultData&) = delete;
            EDIDResultData& operator=(const EDIDResultData&) = delete;

        public:
            Core::JSON::DecUInt16 Length;
            Core::JSON::String Data;
        }; // class EDIDResultData

        class UpdatedParamsData : public Core::JSON::Container {
        public:
            UpdatedParamsData()
                : Core::JSON::Container()
            {
                Add(_T("event"), &Event);
            }

            bool IsValid() const
            {
                return (true);
            }

            UpdatedParamsData(const UpdatedParamsData&) = delete;
            UpdatedParamsData& operator=(const UpdatedParamsData&) = delete;

        public:
            Core::JSON::EnumType<Exchange::IConnectionProperties::INotification::Source> Event;
        }; // class UpdatedParamsData

    } // namespace ConnectionProperties

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IConnectionProperties::HDCPProtectionType)
ENUM_CONVERSION_HANDLER(Exchange::IConnectionProperties::INotification::Source)

}

