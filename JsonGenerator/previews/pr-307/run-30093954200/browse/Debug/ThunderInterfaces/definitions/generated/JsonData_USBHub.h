// C++ types for USBHub API.
// Generated automatically from 'IUSBHub.h'. DO NOT EDIT.

// Note: This code is inherently not thread safe. If required, proper synchronisation must be added.

#pragma once

#include <core/JSON.h>
#include <interfaces/IUSBHub.h>

namespace Thunder {

namespace JsonData {

    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    namespace USBHub {

        // Common classes
        //

        class ProductMetadataInfo : public Core::JSON::Container {
        public:
            ProductMetadataInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            ProductMetadataInfo(const ProductMetadataInfo& _other)
                : Core::JSON::Container()
                , LanguageId(_other.LanguageId)
                , SerialNumber(_other.SerialNumber)
                , Manufacturer(_other.Manufacturer)
                , Product(_other.Product)
            {
                _Init();
            }

            ProductMetadataInfo(ProductMetadataInfo&& _other) noexcept
                : Core::JSON::Container()
                , LanguageId(std::move(_other.LanguageId))
                , SerialNumber(std::move(_other.SerialNumber))
                , Manufacturer(std::move(_other.Manufacturer))
                , Product(std::move(_other.Product))
            {
                _Init();
            }

            ProductMetadataInfo(const Exchange::IUSBHub::ProductMetadata& _other)
                : Core::JSON::Container()
            {
                LanguageId = _other.languageId;
                SerialNumber = _other.serialNumber;
                Manufacturer = _other.manufacturer;
                Product = _other.product;
                _Init();
            }

            ProductMetadataInfo& operator=(const ProductMetadataInfo& _rhs)
            {
                LanguageId = _rhs.LanguageId;
                SerialNumber = _rhs.SerialNumber;
                Manufacturer = _rhs.Manufacturer;
                Product = _rhs.Product;
                return (*this);
            }

            ProductMetadataInfo& operator=(ProductMetadataInfo&& _rhs) noexcept
            {
                LanguageId = std::move(_rhs.LanguageId);
                SerialNumber = std::move(_rhs.SerialNumber);
                Manufacturer = std::move(_rhs.Manufacturer);
                Product = std::move(_rhs.Product);
                return (*this);
            }

            ProductMetadataInfo& operator=(const Exchange::IUSBHub::ProductMetadata& _rhs)
            {
                LanguageId = _rhs.languageId;
                SerialNumber = _rhs.serialNumber;
                Manufacturer = _rhs.manufacturer;
                Product = _rhs.product;
                return (*this);
            }

            operator Exchange::IUSBHub::ProductMetadata() const
            {
                Exchange::IUSBHub::ProductMetadata _value{};
                _value.languageId = LanguageId;
                _value.serialNumber = SerialNumber;
                _value.manufacturer = Manufacturer;
                _value.product = Product;
                return (_value);
            }

            ~ProductMetadataInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((LanguageId.IsSet() == true) && (SerialNumber.IsSet() == true) && (Manufacturer.IsSet() == true) && (Product.IsSet() == true));
            }

        private:
            void _Init()
            {
                Add(_T("languageId"), &LanguageId);
                Add(_T("serialNumber"), &SerialNumber);
                Add(_T("manufacturer"), &Manufacturer);
                Add(_T("product"), &Product);
            }

        public:
            Core::JSON::DecUInt8 LanguageId; // language id present on the device
            Core::JSON::String SerialNumber; // unicode string representing the serial number of the device
            Core::JSON::String Manufacturer; // unicode string representing the manufacturer of the device
            Core::JSON::String Product; // unicode string representing the product
        }; // class ProductMetadataInfo

        class DeviceMetadataInfo : public Core::JSON::Container {
        public:
            DeviceMetadataInfo()
                : Core::JSON::Container()
            {
                _Init();
            }

            DeviceMetadataInfo(const DeviceMetadataInfo& _other)
                : Core::JSON::Container()
                , DeviceName(_other.DeviceName)
                , ParentId(_other.ParentId)
                , Status(_other.Status)
                , DeviceLevel(_other.DeviceLevel)
                , PortNumber(_other.PortNumber)
                , Protocol(_other.Protocol)
                , BusSpeed(_other.BusSpeed)
                , SerialNumber(_other.SerialNumber)
                , Flags(_other.Flags)
                , VendorId(_other.VendorId)
                , ProductId(_other.ProductId)
                , DeviceClass(_other.DeviceClass)
                , DeviceSubclass(_other.DeviceSubclass)
                , DevicePath(_other.DevicePath)
                , Features(_other.Features)
                , NumLanguageIds(_other.NumLanguageIds)
                , ProductInfo1(_other.ProductInfo1)
                , ProductInfo2(_other.ProductInfo2)
                , ProductInfo3(_other.ProductInfo3)
                , ProductInfo4(_other.ProductInfo4)
            {
                _Init();
            }

            DeviceMetadataInfo(DeviceMetadataInfo&& _other) noexcept
                : Core::JSON::Container()
                , DeviceName(std::move(_other.DeviceName))
                , ParentId(std::move(_other.ParentId))
                , Status(std::move(_other.Status))
                , DeviceLevel(std::move(_other.DeviceLevel))
                , PortNumber(std::move(_other.PortNumber))
                , Protocol(std::move(_other.Protocol))
                , BusSpeed(std::move(_other.BusSpeed))
                , SerialNumber(std::move(_other.SerialNumber))
                , Flags(std::move(_other.Flags))
                , VendorId(std::move(_other.VendorId))
                , ProductId(std::move(_other.ProductId))
                , DeviceClass(std::move(_other.DeviceClass))
                , DeviceSubclass(std::move(_other.DeviceSubclass))
                , DevicePath(std::move(_other.DevicePath))
                , Features(std::move(_other.Features))
                , NumLanguageIds(std::move(_other.NumLanguageIds))
                , ProductInfo1(std::move(_other.ProductInfo1))
                , ProductInfo2(std::move(_other.ProductInfo2))
                , ProductInfo3(std::move(_other.ProductInfo3))
                , ProductInfo4(std::move(_other.ProductInfo4))
            {
                _Init();
            }

            DeviceMetadataInfo(const Exchange::IUSBHub::DeviceMetadata& _other)
                : Core::JSON::Container()
            {
                DeviceName = _other.deviceName;
                ParentId = _other.parentId;
                Status = _other.status;
                DeviceLevel = _other.deviceLevel;
                PortNumber = _other.portNumber;
                Protocol = _other.protocol;
                BusSpeed = _other.busSpeed;
                SerialNumber = _other.serialNumber;
                Flags = _other.flags;
                VendorId = _other.vendorId;
                ProductId = _other.productId;
                DeviceClass = _other.deviceClass;
                DeviceSubclass = _other.deviceSubclass;
                DevicePath = _other.devicePath;
                Features = _other.features;
                NumLanguageIds = _other.numLanguageIds;
                ProductInfo1.Set(true);
                ProductInfo1 = _other.productInfo1;
                ProductInfo2.Set(true);
                ProductInfo2 = _other.productInfo2;
                ProductInfo3.Set(true);
                ProductInfo3 = _other.productInfo3;
                ProductInfo4.Set(true);
                ProductInfo4 = _other.productInfo4;
                _Init();
            }

            DeviceMetadataInfo& operator=(const DeviceMetadataInfo& _rhs)
            {
                DeviceName = _rhs.DeviceName;
                ParentId = _rhs.ParentId;
                Status = _rhs.Status;
                DeviceLevel = _rhs.DeviceLevel;
                PortNumber = _rhs.PortNumber;
                Protocol = _rhs.Protocol;
                BusSpeed = _rhs.BusSpeed;
                SerialNumber = _rhs.SerialNumber;
                Flags = _rhs.Flags;
                VendorId = _rhs.VendorId;
                ProductId = _rhs.ProductId;
                DeviceClass = _rhs.DeviceClass;
                DeviceSubclass = _rhs.DeviceSubclass;
                DevicePath = _rhs.DevicePath;
                Features = _rhs.Features;
                NumLanguageIds = _rhs.NumLanguageIds;
                ProductInfo1 = _rhs.ProductInfo1;
                ProductInfo2 = _rhs.ProductInfo2;
                ProductInfo3 = _rhs.ProductInfo3;
                ProductInfo4 = _rhs.ProductInfo4;
                return (*this);
            }

            DeviceMetadataInfo& operator=(DeviceMetadataInfo&& _rhs) noexcept
            {
                DeviceName = std::move(_rhs.DeviceName);
                ParentId = std::move(_rhs.ParentId);
                Status = std::move(_rhs.Status);
                DeviceLevel = std::move(_rhs.DeviceLevel);
                PortNumber = std::move(_rhs.PortNumber);
                Protocol = std::move(_rhs.Protocol);
                BusSpeed = std::move(_rhs.BusSpeed);
                SerialNumber = std::move(_rhs.SerialNumber);
                Flags = std::move(_rhs.Flags);
                VendorId = std::move(_rhs.VendorId);
                ProductId = std::move(_rhs.ProductId);
                DeviceClass = std::move(_rhs.DeviceClass);
                DeviceSubclass = std::move(_rhs.DeviceSubclass);
                DevicePath = std::move(_rhs.DevicePath);
                Features = std::move(_rhs.Features);
                NumLanguageIds = std::move(_rhs.NumLanguageIds);
                ProductInfo1 = std::move(_rhs.ProductInfo1);
                ProductInfo2 = std::move(_rhs.ProductInfo2);
                ProductInfo3 = std::move(_rhs.ProductInfo3);
                ProductInfo4 = std::move(_rhs.ProductInfo4);
                return (*this);
            }

            DeviceMetadataInfo& operator=(const Exchange::IUSBHub::DeviceMetadata& _rhs)
            {
                DeviceName = _rhs.deviceName;
                ParentId = _rhs.parentId;
                Status = _rhs.status;
                DeviceLevel = _rhs.deviceLevel;
                PortNumber = _rhs.portNumber;
                Protocol = _rhs.protocol;
                BusSpeed = _rhs.busSpeed;
                SerialNumber = _rhs.serialNumber;
                Flags = _rhs.flags;
                VendorId = _rhs.vendorId;
                ProductId = _rhs.productId;
                DeviceClass = _rhs.deviceClass;
                DeviceSubclass = _rhs.deviceSubclass;
                DevicePath = _rhs.devicePath;
                Features = _rhs.features;
                NumLanguageIds = _rhs.numLanguageIds;
                ProductInfo1.Set(true);
                ProductInfo1 = _rhs.productInfo1;
                ProductInfo2.Set(true);
                ProductInfo2 = _rhs.productInfo2;
                ProductInfo3.Set(true);
                ProductInfo3 = _rhs.productInfo3;
                ProductInfo4.Set(true);
                ProductInfo4 = _rhs.productInfo4;
                return (*this);
            }

            operator Exchange::IUSBHub::DeviceMetadata() const
            {
                Exchange::IUSBHub::DeviceMetadata _value{};
                _value.deviceName = DeviceName;
                _value.parentId = ParentId;
                _value.status = Status;
                _value.deviceLevel = DeviceLevel;
                _value.portNumber = PortNumber;
                _value.protocol = Protocol;
                _value.busSpeed = BusSpeed;
                _value.serialNumber = SerialNumber;
                _value.flags = Flags;
                _value.vendorId = VendorId;
                _value.productId = ProductId;
                _value.deviceClass = DeviceClass;
                _value.deviceSubclass = DeviceSubclass;
                _value.devicePath = DevicePath;
                _value.features = Features;
                _value.numLanguageIds = NumLanguageIds;
                _value.productInfo1 = ProductInfo1;
                _value.productInfo2 = ProductInfo2;
                _value.productInfo3 = ProductInfo3;
                _value.productInfo4 = ProductInfo4;
                return (_value);
            }

            ~DeviceMetadataInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((DeviceName.IsSet() == true) && (ParentId.IsSet() == true) && (Status.IsSet() == true) && (DeviceLevel.IsSet() == true) && (PortNumber.IsSet() == true) && (Protocol.IsSet() == true) && (BusSpeed.IsSet() == true) && (SerialNumber.IsSet() == true) && (Flags.IsSet() == true) && (VendorId.IsSet() == true) && (ProductId.IsSet() == true) && (DeviceClass.IsSet() == true) && (DeviceSubclass.IsSet() == true) && (DevicePath.IsSet() == true) && (Features.IsSet() == true) && (NumLanguageIds.IsSet() == true) && ((ProductInfo1.IsSet() == true) && (ProductInfo1.IsDataValid() == true)) && ((ProductInfo2.IsSet() == true) && (ProductInfo2.IsDataValid() == true)) && ((ProductInfo3.IsSet() == true) && (ProductInfo3.IsDataValid() == true)) && ((ProductInfo4.IsSet() == true) && (ProductInfo4.IsDataValid() == true)));
            }

        private:
            void _Init()
            {
                Add(_T("deviceName"), &DeviceName);
                Add(_T("parentId"), &ParentId);
                Add(_T("status"), &Status);
                Add(_T("deviceLevel"), &DeviceLevel);
                Add(_T("portNumber"), &PortNumber);
                Add(_T("protocol"), &Protocol);
                Add(_T("busSpeed"), &BusSpeed);
                Add(_T("serialNumber"), &SerialNumber);
                Add(_T("flags"), &Flags);
                Add(_T("vendorId"), &VendorId);
                Add(_T("productId"), &ProductId);
                Add(_T("deviceClass"), &DeviceClass);
                Add(_T("deviceSubclass"), &DeviceSubclass);
                Add(_T("devicePath"), &DevicePath);
                Add(_T("features"), &Features);
                Add(_T("numLanguageIds"), &NumLanguageIds);
                Add(_T("productInfo1"), &ProductInfo1);
                Add(_T("productInfo2"), &ProductInfo2);
                Add(_T("productInfo3"), &ProductInfo3);
                Add(_T("productInfo4"), &ProductInfo4);
            }

        public:
            Core::JSON::String DeviceName; // Name of the USB device
            Core::JSON::DecUInt32 ParentId; // Parent Node ID of the device
            Core::JSON::EnumType<Exchange::IUSBHub::Status> Status; // current device status
            Core::JSON::DecUInt8 DeviceLevel; // device level
            Core::JSON::DecUInt8 PortNumber; // port number of USB on which the device is attached
            Core::JSON::DecUInt8 Protocol; // Protocol supported by the device
            Core::JSON::EnumType<Exchange::IUSBHub::Speed> BusSpeed; // Speed of the device
            Core::JSON::String SerialNumber; // Serial number of the device
            Core::JSON::EnumType<Exchange::IUSBHub::Flags> Flags; // Flags of the device
            Core::JSON::DecUInt16 VendorId; // the vendor Id assigned to this device
            Core::JSON::DecUInt16 ProductId; // the product Id assigned to this device
            Core::JSON::DecUInt8 DeviceClass; // USB class of the device as per USB specificiation
            Core::JSON::DecUInt8 DeviceSubclass; // USB sub class of the device as per USB specificiation
            Core::JSON::String DevicePath; // the path to be used for the USB device ex: /dev/sdX
            Core::JSON::DecUInt32 Features; // Features supported by the device - reserved
            Core::JSON::DecUInt8 NumLanguageIds; // number of language ids present on the device
            ProductMetadataInfo ProductInfo1; // Get the metadata information about the name passed in the paramater.
            ProductMetadataInfo ProductInfo2; // Get the metadata information about the name passed in the paramater.
            ProductMetadataInfo ProductInfo3; // Get the metadata information about the name passed in the paramater.
            ProductMetadataInfo ProductInfo4; // Get the metadata information about the name passed in the paramater.
        }; // class DeviceMetadataInfo

        class AnnounceParamsInfo : public Core::JSON::Container {
        public:
            AnnounceParamsInfo()
                : Core::JSON::Container()
            {
                Add(_T("device"), &Device);
            }

            AnnounceParamsInfo(const AnnounceParamsInfo&) = delete;
            AnnounceParamsInfo(AnnounceParamsInfo&&) noexcept  = delete;

            AnnounceParamsInfo& operator=(const AnnounceParamsInfo&) = delete;
            AnnounceParamsInfo& operator=(AnnounceParamsInfo&&) noexcept  = delete;

            ~AnnounceParamsInfo() = default;

        public:
            bool IsDataValid() const
            {
                return ((Device.IsSet() == true) && (Device.IsDataValid() == true));
            }

        public:
            DeviceMetadataInfo Device; // USB information of the plugged in device
        }; // class AnnounceParamsInfo

        // Method params/result classes
        //

        class DeviceParamsData : public Core::JSON::Container {
        public:
            DeviceParamsData()
                : Core::JSON::Container()
            {
                Add(_T("deviceName"), &DeviceName);
            }

            DeviceParamsData(const DeviceParamsData&) = delete;
            DeviceParamsData(DeviceParamsData&&) noexcept  = delete;

            DeviceParamsData& operator=(const DeviceParamsData&) = delete;
            DeviceParamsData& operator=(DeviceParamsData&&) noexcept  = delete;

            ~DeviceParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return (DeviceName.IsSet() == true);
            }

        public:
            Core::JSON::String DeviceName; // Name of the device
        }; // class DeviceParamsData

        class VendorDevicesParamsData : public Core::JSON::Container {
        public:
            VendorDevicesParamsData()
                : Core::JSON::Container()
            {
                Add(_T("vendorId"), &VendorId);
                Add(_T("productId"), &ProductId);
            }

            VendorDevicesParamsData(const VendorDevicesParamsData&) = delete;
            VendorDevicesParamsData(VendorDevicesParamsData&&) noexcept  = delete;

            VendorDevicesParamsData& operator=(const VendorDevicesParamsData&) = delete;
            VendorDevicesParamsData& operator=(VendorDevicesParamsData&&) noexcept  = delete;

            ~VendorDevicesParamsData() = default;

        public:
            bool IsDataValid() const
            {
                return ((VendorId.IsSet() == true) && (ProductId.IsSet() == true));
            }

        public:
            Core::JSON::DecUInt16 VendorId; // Get a string array defining all devices hooked up to this hub cmpliant to the given VendorId/ProductId
            Core::JSON::DecUInt16 ProductId; // Get a string array defining all devices hooked up to this hub cmpliant to the given VendorId/ProductId
        }; // class VendorDevicesParamsData

    } // namespace USBHub

    POP_WARNING()

} // namespace JsonData

// Enum conversion handlers
ENUM_CONVERSION_HANDLER(Exchange::IUSBHub::Status)
ENUM_CONVERSION_HANDLER(Exchange::IUSBHub::Speed)
ENUM_CONVERSION_HANDLER(Exchange::IUSBHub::Flags)

}

