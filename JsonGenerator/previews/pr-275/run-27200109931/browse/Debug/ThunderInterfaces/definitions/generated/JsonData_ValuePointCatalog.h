// C++ types for Catalog API.
// Generated automatically from 'IValuePoint.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IValuePoint.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace ValuePoint {

        namespace Catalog {

            // Common classes
            //

            class ActivatedParamsInfo : public Core::JSON::Container {
            public:
                ActivatedParamsInfo()
                    : Core::JSON::Container()
                {
                    Add(_T("id"), &Id);
                }

                ActivatedParamsInfo(const ActivatedParamsInfo&) = delete;
                ActivatedParamsInfo(ActivatedParamsInfo&&) noexcept  = delete;

                ActivatedParamsInfo& operator=(const ActivatedParamsInfo&) = delete;
                ActivatedParamsInfo& operator=(ActivatedParamsInfo&&) noexcept  = delete;

                ~ActivatedParamsInfo() = default;

            public:
                bool IsDataValid() const
                {
                    return (Id.IsSet() == true);
                }

            public:
                Core::JSON::String Id; // Id of the IValuePoint
            }; // class ActivatedParamsInfo

            class ResourceParamsInfo : public Core::JSON::Container {
            public:
                ResourceParamsInfo()
                    : Core::JSON::Container()
                {
                    Add(_T("id"), &Id);
                }

                ResourceParamsInfo(const ResourceParamsInfo&) = delete;
                ResourceParamsInfo(ResourceParamsInfo&&) noexcept  = delete;

                ResourceParamsInfo& operator=(const ResourceParamsInfo&) = delete;
                ResourceParamsInfo& operator=(ResourceParamsInfo&&) noexcept  = delete;

                ~ResourceParamsInfo() = default;

            public:
                bool IsDataValid() const
                {
                    return (Id.IsSet() == true);
                }

            public:
                Core::JSON::DecUInt32 Id;
            }; // class ResourceParamsInfo

            // Method params/result classes
            //

            class ValueData : public Core::JSON::Container {
            public:
                ValueData()
                    : Core::JSON::Container()
                {
                    Add(_T("value"), &Value);
                }

                ValueData(const ValueData&) = delete;
                ValueData(ValueData&&) noexcept  = delete;

                ValueData& operator=(const ValueData&) = delete;
                ValueData& operator=(ValueData&&) noexcept  = delete;

                ~ValueData() = default;

            public:
                bool IsDataValid() const
                {
                    return (Value.IsSet() == true);
                }

            public:
                Core::JSON::DecSInt32 Value; // The current value of this IValuePoint.
            }; // class ValueData

        } // namespace Catalog

    } // namespace ValuePoint

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IValuePoint::condition)
ENUM_CONVERSION_HANDLER(Exchange::IValuePoint::basic)
ENUM_CONVERSION_HANDLER(Exchange::IValuePoint::specific)
ENUM_CONVERSION_HANDLER(Exchange::IValuePoint::dimension)
ENUM_CONVERSION_HANDLER(Exchange::IValuePoint::protocol)

}

