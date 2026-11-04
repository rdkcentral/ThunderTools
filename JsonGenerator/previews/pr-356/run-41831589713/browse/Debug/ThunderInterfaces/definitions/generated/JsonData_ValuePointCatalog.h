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

            class InfoData : public Core::JSON::Container {
            public:
                InfoData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                InfoData(const InfoData& _other)
                    : Core::JSON::Container()
                    , Base(_other.Base)
                    , Extended(_other.Extended)
                    , Type(_other.Type)
                    , Fraction(_other.Fraction)
                    , Manufacturer(_other.Manufacturer)
                    , Model(_other.Model)
                    , Communication(_other.Communication)
                    , Metadata(_other.Metadata)
                {
                    _Init();
                }

                InfoData(InfoData&& _other) noexcept
                    : Core::JSON::Container()
                    , Base(std::move(_other.Base))
                    , Extended(std::move(_other.Extended))
                    , Type(std::move(_other.Type))
                    , Fraction(std::move(_other.Fraction))
                    , Manufacturer(std::move(_other.Manufacturer))
                    , Model(std::move(_other.Model))
                    , Communication(std::move(_other.Communication))
                    , Metadata(std::move(_other.Metadata))
                {
                    _Init();
                }

                InfoData(const Exchange::IValuePoint::Info& _other)
                    : Core::JSON::Container()
                {
                    Base = _other.base;
                    Extended = _other.extended;
                    Type = _other.type;
                    Fraction = _other.fraction;
                    Manufacturer = _other.manufacturer;
                    Model = _other.model;
                    Communication = _other.communication;
                    if (_other.metadata.IsSet() == true) {
                        Metadata = _other.metadata.Value();
                    }
                    _Init();
                }

                InfoData& operator=(const InfoData& _rhs)
                {
                    Base = _rhs.Base;
                    Extended = _rhs.Extended;
                    Type = _rhs.Type;
                    Fraction = _rhs.Fraction;
                    Manufacturer = _rhs.Manufacturer;
                    Model = _rhs.Model;
                    Communication = _rhs.Communication;
                    if (_rhs.Metadata.IsSet() == true) {
                        Metadata = _rhs.Metadata;
                    }
                    return (*this);
                }

                InfoData& operator=(InfoData&& _rhs) noexcept
                {
                    Base = std::move(_rhs.Base);
                    Extended = std::move(_rhs.Extended);
                    Type = std::move(_rhs.Type);
                    Fraction = std::move(_rhs.Fraction);
                    Manufacturer = std::move(_rhs.Manufacturer);
                    Model = std::move(_rhs.Model);
                    Communication = std::move(_rhs.Communication);
                    Metadata = std::move(_rhs.Metadata);
                    return (*this);
                }

                InfoData& operator=(const Exchange::IValuePoint::Info& _rhs)
                {
                    Base = _rhs.base;
                    Extended = _rhs.extended;
                    Type = _rhs.type;
                    Fraction = _rhs.fraction;
                    Manufacturer = _rhs.manufacturer;
                    Model = _rhs.model;
                    Communication = _rhs.communication;
                    if (_rhs.metadata.IsSet() == true) {
                        Metadata = _rhs.metadata.Value();
                    }
                    return (*this);
                }

                operator Exchange::IValuePoint::Info() const
                {
                    Exchange::IValuePoint::Info _value{};
                    _value.base = Base;
                    _value.extended = Extended;
                    _value.type = Type;
                    _value.fraction = Fraction;
                    _value.manufacturer = Manufacturer;
                    _value.model = Model;
                    _value.communication = Communication;
                    if (Metadata.IsSet() == true) {
                        _value.metadata = Metadata;
                    }
                    return (_value);
                }

                ~InfoData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Base.IsSet() == true) && (Extended.IsSet() == true) && (Type.IsSet() == true) && (Fraction.IsSet() == true) && (Manufacturer.IsSet() == true) && (Model.IsSet() == true) && (Communication.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("base"), &Base);
                    Add(_T("extended"), &Extended);
                    Add(_T("type"), &Type);
                    Add(_T("fraction"), &Fraction);
                    Add(_T("manufacturer"), &Manufacturer);
                    Add(_T("model"), &Model);
                    Add(_T("communication"), &Communication);
                    Add(_T("metadata"), &Metadata);
                }

            public:
                Core::JSON::EnumType<Exchange::IValuePoint::basic> Base; // There most be more than meets the eye, report it as a JSON string.
                Core::JSON::EnumType<Exchange::IValuePoint::specific> Extended; // There most be more than meets the eye, report it as a JSON string.
                Core::JSON::EnumType<Exchange::IValuePoint::dimension> Type; // There most be more than meets the eye, report it as a JSON string.
                Core::JSON::DecUInt8 Fraction; // There most be more than meets the eye, report it as a JSON string.
                Core::JSON::String Manufacturer; // There most be more than meets the eye, report it as a JSON string.
                Core::JSON::String Model; // There most be more than meets the eye, report it as a JSON string.
                Core::JSON::EnumType<Exchange::IValuePoint::protocol> Communication; // There most be more than meets the eye, report it as a JSON string.
                Core::JSON::String Metadata; // There most be more than meets the eye, report it as a JSON string.
            }; // class InfoData

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

