// C++ types for ZigWave API.
// Generated automatically from 'IZigWave.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IZigWave.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace ZigWave {

        // Common classes
        //

        class BindParamsInfo : public Core::JSON::Container {
        public:
            BindParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("source"), &Source);
                Add(_T("destination"), &Destination);
            }

            BindParamsInfo(const BindParamsInfo&) = delete;
            BindParamsInfo(BindParamsInfo&&) noexcept  = delete;

            BindParamsInfo& operator=(const BindParamsInfo&) = delete;
            BindParamsInfo& operator=(BindParamsInfo&&) noexcept  = delete;

            ~BindParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Source.IsSet() == true) && (Destination.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt32 Source; // Source to be bound
            Core::JSON::DecUInt32 Destination; // Destination to be bound
        }; // class BindParamsInfo

        // Method params/result classes
        //

        class DeviceData : public Core::JSON::Container {
        public:
            DeviceData()
                : Core::JSON::Container()
            {
                _Init();
            }

            DeviceData(const DeviceData& _other)
                : Core::JSON::Container()
                , Parent(_other.Parent)
                , Address(_other.Address)
                , Type(_other.Type)
                , Manufacturer(_other.Manufacturer)
                , Metadata(_other.Metadata)
            {
                _Init();
            }

            DeviceData(DeviceData&& _other) noexcept
                : Core::JSON::Container()
                , Parent(std::move(_other.Parent))
                , Address(std::move(_other.Address))
                , Type(std::move(_other.Type))
                , Manufacturer(std::move(_other.Manufacturer))
                , Metadata(std::move(_other.Metadata))
            {
                _Init();
            }

            DeviceData(const Exchange::IZigWave::Device& _other)
                : Core::JSON::Container()
            {
                Parent = _other.Parent;
                Address = _other.Address;
                Type = _other.Type;
                Manufacturer = _other.Manufacturer;
                Metadata = _other.Metadata;
                _Init();
            }

            DeviceData& operator=(const DeviceData& _rhs)
            {
                Parent = _rhs.Parent;
                Address = _rhs.Address;
                Type = _rhs.Type;
                Manufacturer = _rhs.Manufacturer;
                Metadata = _rhs.Metadata;
                return (*this);
            }

            DeviceData& operator=(DeviceData&& _rhs) noexcept
            {
                Parent = std::move(_rhs.Parent);
                Address = std::move(_rhs.Address);
                Type = std::move(_rhs.Type);
                Manufacturer = std::move(_rhs.Manufacturer);
                Metadata = std::move(_rhs.Metadata);
                return (*this);
            }

            DeviceData& operator=(const Exchange::IZigWave::Device& _rhs)
            {
                Parent = _rhs.Parent;
                Address = _rhs.Address;
                Type = _rhs.Type;
                Manufacturer = _rhs.Manufacturer;
                Metadata = _rhs.Metadata;
                return (*this);
            }

            operator Exchange::IZigWave::Device() const
            {
                Exchange::IZigWave::Device _value{};
                _value.Parent = Parent;
                _value.Address = Address;
                _value.Type = Type;
                _value.Manufacturer = Manufacturer;
                _value.Metadata = Metadata;
                return (_value);
            }

            ~DeviceData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Parent.IsSet() == true) && (Address.IsSet() == true) && (Type.IsSet() == true) && (Manufacturer.IsSet() == true) && (Metadata.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("parent"), &Parent);
                Add(_T("address"), &Address);
                Add(_T("type"), &Type);
                Add(_T("manufacturer"), &Manufacturer);
                Add(_T("metadata"), &Metadata);
            }

        public:
            Core::JSON::DecUInt32 Parent; // Address of the Parent
            Core::JSON::DecUInt32 Address; // Address of the device
            Core::JSON::EnumType<Exchange::IZigWave::Device::type> Type; // Type of the device
            Core::JSON::DecUInt16 Manufacturer; // Manufactured of this device
            Core::JSON::String Metadata; // Metadata associated with this device
        }; // class DeviceData

        class ControllerData : public Core::JSON::Container {
        public:
            ControllerData()
                : Core::JSON::Container()
            {
                _Init();
            }

            ControllerData(const ControllerData& _other)
                : Core::JSON::Container()
                , Permutable(_other.Permutable)
                , Port(_other.Port)
                , Id(_other.Id)
                , Major(_other.Major)
                , Minor(_other.Minor)
                , Nodes(_other.Nodes)
            {
                _Init();
            }

            ControllerData(ControllerData&& _other) noexcept
                : Core::JSON::Container()
                , Permutable(std::move(_other.Permutable))
                , Port(std::move(_other.Port))
                , Id(std::move(_other.Id))
                , Major(std::move(_other.Major))
                , Minor(std::move(_other.Minor))
                , Nodes(std::move(_other.Nodes))
            {
                _Init();
            }

            ControllerData(const Exchange::IZigWave::Controller& _other)
                : Core::JSON::Container()
            {
                Permutable = _other.Permutable;
                Port = _other.Port;
                Id = _other.Id;
                Major = _other.Major;
                Minor = _other.Minor;
                Nodes = _other.Nodes;
                _Init();
            }

            ControllerData& operator=(const ControllerData& _rhs)
            {
                Permutable = _rhs.Permutable;
                Port = _rhs.Port;
                Id = _rhs.Id;
                Major = _rhs.Major;
                Minor = _rhs.Minor;
                Nodes = _rhs.Nodes;
                return (*this);
            }

            ControllerData& operator=(ControllerData&& _rhs) noexcept
            {
                Permutable = std::move(_rhs.Permutable);
                Port = std::move(_rhs.Port);
                Id = std::move(_rhs.Id);
                Major = std::move(_rhs.Major);
                Minor = std::move(_rhs.Minor);
                Nodes = std::move(_rhs.Nodes);
                return (*this);
            }

            ControllerData& operator=(const Exchange::IZigWave::Controller& _rhs)
            {
                Permutable = _rhs.Permutable;
                Port = _rhs.Port;
                Id = _rhs.Id;
                Major = _rhs.Major;
                Minor = _rhs.Minor;
                Nodes = _rhs.Nodes;
                return (*this);
            }

            operator Exchange::IZigWave::Controller() const
            {
                Exchange::IZigWave::Controller _value{};
                _value.Permutable = Permutable;
                _value.Port = Port;
                _value.Id = Id;
                _value.Major = Major;
                _value.Minor = Minor;
                _value.Nodes = Nodes;
                return (_value);
            }

            ~ControllerData() = default;

        public:
            bool IsDataValid() const
            {
                return ((Permutable.IsSet() == true) && (Port.IsSet() == true) && (Id.IsSet() == true) && (Major.IsSet() == true) && (Minor.IsSet() == true) && (Nodes.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("permutable"), &Permutable);
                Add(_T("port"), &Port);
                Add(_T("id"), &Id);
                Add(_T("major"), &Major);
                Add(_T("minor"), &Minor);
                Add(_T("nodes"), &Nodes);
            }

        public:
            Core::JSON::Boolean Permutable; // Permutable or not
            Core::JSON::String Port; // Port number
            Core::JSON::DecUInt32 Id; // Controller Id
            Core::JSON::DecUInt8 Major; // Major number
            Core::JSON::DecUInt8 Minor; // Minor number
            Core::JSON::DecUInt16 Nodes; // Number of Nodes
        }; // class ControllerData

        class PermutableData : public Core::JSON::Container {
        public:
            PermutableData()
                : Core::JSON::Container()
            {
                Add(_T("value"), &Value);
            }

            PermutableData(const PermutableData&) = delete;
            PermutableData(PermutableData&&) noexcept  = delete;

            PermutableData& operator=(const PermutableData&) = delete;
            PermutableData& operator=(PermutableData&&) noexcept  = delete;

            ~PermutableData() = default;

        public:
            bool IsDataValid() const
            {
                return (Value.IsSet() == true);
            }

        public:
            Core::JSON::Boolean Value; // To allow new devices to the network, the controller should be placed into an accepting mode. By enabling this mode, the controller can accept new devices.
        }; // class PermutableData

    } // namespace ZigWave

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IZigWave::Device::type)

}

