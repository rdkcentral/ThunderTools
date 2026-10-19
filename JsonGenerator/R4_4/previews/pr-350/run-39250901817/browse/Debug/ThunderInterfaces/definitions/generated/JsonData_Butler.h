// C++ types for Butler API.
// Generated automatically from 'Butler.json'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <core/Enumerate.h>

namespace WPEFramework {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace Butler {

        // Common enums
        //

        // Basic description of the device (measure or control)
        enum class BasicenumType : uint8_t {
            CONTROL = 0,
            MEASURE = 1,
            GROUP = 14,
            IDENTIFICATION = 15
        };

        // What is the dimension of the value that is returned by the device
        enum class DimensionenumType : uint8_t {
            LOGIC,
            PERCENTAGE,
            KWH,
            KVAH,
            PULSES,
            DEGREES,
            UNITS
        };

        // More eleborated description of the device
        enum class SpecificenumType : uint8_t {
            GENERAL,
            ELECTRICITY,
            WATER,
            GAS,
            AIR,
            SMOKE,
            CARBONMONOXIDE,
            CARBONDIOXIDE,
            TEMPERATURE,
            ACCESSCONTROL,
            BURGLAR,
            POWERMANAGEMENT,
            SYSTEM,
            EMERGENCY,
            CLOCK,
            LIGHT
        };

        // Common classes
        //

        class DeviceInfo : public Core::JSON::Container {
        public:
            DeviceInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            DeviceInfo(const DeviceInfo& _other)
                : Core::JSON::Container()
                , Id(_other.Id)
                , Bundle(_other.Bundle)
                , Name(_other.Name)
                , Callsign(_other.Callsign)
                , Basic(_other.Basic)
                , Specific(_other.Specific)
                , Dimension(_other.Dimension)
                , Decimals(_other.Decimals)
                , Minimum(_other.Minimum)
                , Maximum(_other.Maximum)
                , Value(_other.Value)
            {
                _Init();
            }

            DeviceInfo(DeviceInfo&& _other) noexcept
                : Core::JSON::Container()
                , Id(std::move(_other.Id))
                , Bundle(std::move(_other.Bundle))
                , Name(std::move(_other.Name))
                , Callsign(std::move(_other.Callsign))
                , Basic(std::move(_other.Basic))
                , Specific(std::move(_other.Specific))
                , Dimension(std::move(_other.Dimension))
                , Decimals(std::move(_other.Decimals))
                , Minimum(std::move(_other.Minimum))
                , Maximum(std::move(_other.Maximum))
                , Value(std::move(_other.Value))
            {
                _Init();
            }

            DeviceInfo& operator=(const DeviceInfo& _rhs)
            {
                Id = _rhs.Id;
                if (_rhs.Bundle != 0) {
                    Bundle = _rhs.Bundle;
                }
                Name = _rhs.Name;
                if (_rhs.Callsign.Value().empty() == false) {
                    Callsign = _rhs.Callsign;
                }
                Basic = _rhs.Basic;
                Specific = _rhs.Specific;
                Dimension = _rhs.Dimension;
                Decimals = _rhs.Decimals;
                Minimum = _rhs.Minimum;
                Maximum = _rhs.Maximum;
                if (_rhs.Value != 0) {
                    Value = _rhs.Value;
                }
                return (*this);
            }

            DeviceInfo& operator=(DeviceInfo&& _rhs) noexcept
            {
                Id = std::move(_rhs.Id);
                Bundle = std::move(_rhs.Bundle);
                Name = std::move(_rhs.Name);
                Callsign = std::move(_rhs.Callsign);
                Basic = std::move(_rhs.Basic);
                Specific = std::move(_rhs.Specific);
                Dimension = std::move(_rhs.Dimension);
                Decimals = std::move(_rhs.Decimals);
                Minimum = std::move(_rhs.Minimum);
                Maximum = std::move(_rhs.Maximum);
                Value = std::move(_rhs.Value);
                return (*this);
            }

            ~DeviceInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Id.IsSet() == true) && (Name.IsSet() == true) && (Basic.IsSet() == true) && (Specific.IsSet() == true) && (Dimension.IsSet() == true) && (Decimals.IsSet() == true) && (Minimum.IsSet() == true) && (Maximum.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("id"), &Id);
                Add(_T("bundle"), &Bundle);
                Add(_T("name"), &Name);
                Add(_T("callsign"), &Callsign);
                Add(_T("basic"), &Basic);
                Add(_T("specific"), &Specific);
                Add(_T("dimension"), &Dimension);
                Add(_T("decimals"), &Decimals);
                Add(_T("minimum"), &Minimum);
                Add(_T("maximum"), &Maximum);
                Add(_T("value"), &Value);
            }

        public:
            Core::JSON::DecUInt32 Id; // Identifier of the device
            Core::JSON::DecUInt32 Bundle; // If this value point belongs to a bundle of more value points
            Core::JSON::String Name; // Name given to this device
            Core::JSON::String Callsign; // The callsign that owns this external
            Core::JSON::EnumType<BasicenumType> Basic; // Basic description of the device (measure or control)
            Core::JSON::EnumType<SpecificenumType> Specific; // More eleborated description of the device
            Core::JSON::EnumType<DimensionenumType> Dimension; // What is the dimension of the value that is returned by the device
            Core::JSON::DecUInt32 Decimals; // Number of digits that should be considered fractional
            Core::JSON::DecSInt32 Minimum; // Minimum value that the device can reach
            Core::JSON::DecSInt32 Maximum; // Maximum value that the device can reach
            Core::JSON::DecSInt32 Value;
        }; // class DeviceInfo

        // Method params/result classes
        //

        class ActivityParamsData : public Core::JSON::Container {
        public:
            ActivityParamsData()
                : Core::JSON::Container()
            {
                Add(_T("id"), &Id);
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
                return ((Id.IsSet() == true) && (Value.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Id; // Identifier of the device
            Core::JSON::DecSInt32 Value;
        }; // class ActivityParamsData

        class GroupData : public Core::JSON::Container {
        public:
            class MembersData : public Core::JSON::Container {
            public:
                MembersData()
                    : Core::JSON::Container()
                {
                    _Init();
                }

                MembersData(const MembersData& _other)
                    : Core::JSON::Container()
                    , Name(_other.Name)
                    , Callsign(_other.Callsign)
                    , Children(_other.Children)
                    , Bundle(_other.Bundle)
                    , Id(_other.Id)
                    , Point(_other.Point)
                {
                    _Init();
                }

                MembersData(MembersData&& _other) noexcept
                    : Core::JSON::Container()
                    , Name(std::move(_other.Name))
                    , Callsign(std::move(_other.Callsign))
                    , Children(std::move(_other.Children))
                    , Bundle(std::move(_other.Bundle))
                    , Id(std::move(_other.Id))
                    , Point(std::move(_other.Point))
                {
                    _Init();
                }

                MembersData& operator=(const MembersData& _rhs)
                {
                    Name = _rhs.Name;
                    Callsign = _rhs.Callsign;
                    Children = _rhs.Children;
                    Bundle = _rhs.Bundle;
                    Id = _rhs.Id;
                    Point = _rhs.Point;
                    return (*this);
                }

                MembersData& operator=(MembersData&& _rhs) noexcept
                {
                    Name = std::move(_rhs.Name);
                    Callsign = std::move(_rhs.Callsign);
                    Children = std::move(_rhs.Children);
                    Bundle = std::move(_rhs.Bundle);
                    Id = std::move(_rhs.Id);
                    Point = std::move(_rhs.Point);
                    return (*this);
                }

                ~MembersData() = default;

            public:
                bool IsDataValid() const
                {
                    return ((Name.IsSet() == true) && (Callsign.IsSet() == true) && (Children.IsSet() == true) && (Bundle.IsSet() == true) && (Id.IsSet() == true) && (Point.IsSet() == true));
                }

            private:
                void _Init()
                {
                    Add(_T("name"), &Name);
                    Add(_T("callsign"), &Callsign);
                    Add(_T("children"), &Children);
                    Add(_T("bundle"), &Bundle);
                    Add(_T("id"), &Id);
                    Add(_T("point"), &Point);
                }

            public:
                Core::JSON::ArrayType<Core::JSON::String> Name; // Name of a room or sensor
                Core::JSON::String Callsign; // The callsign that owns this external
                Core::JSON::DecUInt32 Children; // The number of children in a group
                Core::JSON::DecUInt32 Bundle; // The bundle id if this is a bundle
                Core::JSON::DecUInt32 Id; // The id of the single point in this meber, it is not a bundle
                Core::JSON::ArrayType<DeviceInfo> Point;
            }; // class MembersData

            GroupData()
                : Core::JSON::Container()
            {
                Add(_T("parent"), &Parent);
                Add(_T("id"), &Id);
                Add(_T("base"), &Base);
                Add(_T("members"), &Members);
            }

            GroupData(const GroupData&) = delete;
            GroupData(GroupData&&) noexcept  = delete;

            GroupData& operator=(const GroupData&) = delete;
            GroupData& operator=(GroupData&&) noexcept  = delete;

            ~GroupData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Parent.IsSet() == true) && (Id.IsSet() == true) && (Base.IsSet() == true) && (Members.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Parent; // Identifier of the group to wich this group belongs
            Core::JSON::DecUInt32 Id; // Identifier of this group
            Core::JSON::String Base; // Path identifier leading up to this group
            Core::JSON::ArrayType<GroupData::MembersData> Members;
        }; // class GroupData

        class LinkData : public Core::JSON::Container {
        public:
            LinkData()
                : Core::JSON::Container()
            {
                Add(_T("node"), &Node);
                Add(_T("id"), &Id);
            }

            LinkData(const LinkData&) = delete;
            LinkData(LinkData&&) noexcept  = delete;

            LinkData& operator=(const LinkData&) = delete;
            LinkData& operator=(LinkData&&) noexcept  = delete;

            ~LinkData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Node.IsSet() == true) && (Id.IsSet() == true));
            }

        public:
            Core::JSON::String Node; // Path identifying the the node to which we should link the id
            Core::JSON::DecUInt32 Id; // Identifier of the External to be linked
        }; // class LinkData

        class MoveData : public Core::JSON::Container {
        public:
            MoveData()
                : Core::JSON::Container()
            {
                Add(_T("origin"), &Origin);
                Add(_T("node"), &Node);
            }

            MoveData(const MoveData&) = delete;
            MoveData(MoveData&&) noexcept  = delete;

            MoveData& operator=(const MoveData&) = delete;
            MoveData& operator=(MoveData&&) noexcept  = delete;

            ~MoveData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Origin.IsSet() == true) && (Node.IsSet() == true));
            }

        public:
            Core::JSON::String Origin; // Path identifying the the node that will be moved
            Core::JSON::String Node; // Path identifying where the node it too be placed
        }; // class MoveData

    } // namespace Butler

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(JsonData::Butler::BasicenumType)
ENUM_CONVERSION_HANDLER(JsonData::Butler::SpecificenumType)
ENUM_CONVERSION_HANDLER(JsonData::Butler::DimensionenumType)

}

