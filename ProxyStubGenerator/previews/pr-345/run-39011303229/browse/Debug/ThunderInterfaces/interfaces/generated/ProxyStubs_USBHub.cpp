//
// generated automatically from "IUSBHub.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class Exchange::IUSBHub
//   - class Exchange::IUSBHub::INotification
//   - class Exchange::IUSBHub::IDevice
//

#include "Module.h"
#include "IUSBHub.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_b3acff3685df4032StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_b3acff3685df4032StubMethods

    //
    // Exchange::IUSBHub interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IUSBHub::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IUSBHub::INotification*) = 0
    //  (2) virtual Core::hresult Devices(Exchange::IUSBHub::IStringIterator*&) const = 0
    //  (3) virtual Core::hresult VendorDevices(const uint16_t, const uint16_t, Exchange::IUSBHub::IStringIterator*&) const = 0
    //  (4) virtual Core::hresult Device(const string&, Exchange::IUSBHub::DeviceMetadata&) const = 0
    //  (5) virtual Core::hresult Acquire(const string&, Exchange::IUSBHub::IDevice*&) const = 0
    //  (6) virtual Core::hresult Relinquish(const Exchange::IUSBHub::IDevice*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeUSBHubStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IUSBHub::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUSBHub* implementation = reinterpret_cast<Exchange::IUSBHub*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IUSBHub::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(const Exchange::IUSBHub::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUSBHub* implementation = reinterpret_cast<Exchange::IUSBHub*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IUSBHub::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult Devices(Exchange::IUSBHub::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUSBHub* implementation = reinterpret_cast<const Exchange::IUSBHub*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IUSBHub::IStringIterator* _iterator{};

            Core::hresult result = implementation->Devices(_iterator);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_iterator));

            RPC::Administrator::Instance().RegisterInterface(channel, _iterator);
        },

        // (3) virtual Core::hresult VendorDevices(const uint16_t, const uint16_t, Exchange::IUSBHub::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUSBHub* implementation = reinterpret_cast<const Exchange::IUSBHub*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _vendorId = reader.Number<uint16_t>();
            const uint16_t _productId = reader.Number<uint16_t>();

            Exchange::IUSBHub::IStringIterator* _iterator{};

            Core::hresult result = implementation->VendorDevices(_vendorId, _productId, _iterator);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_iterator));

            RPC::Administrator::Instance().RegisterInterface(channel, _iterator);
        },

        // (4) virtual Core::hresult Device(const string&, Exchange::IUSBHub::DeviceMetadata&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUSBHub* implementation = reinterpret_cast<const Exchange::IUSBHub*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _deviceName = reader.Text();

            Exchange::IUSBHub::DeviceMetadata _device{};

            Core::hresult result = implementation->Device(static_cast<const string&>(_deviceName), _device);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_device.deviceName);
            writer.Number<uint32_t>(_device.parentId);
            writer.Number<Exchange::IUSBHub::Status>(_device.status);
            writer.Number<uint8_t>(_device.deviceLevel);
            writer.Number<uint8_t>(_device.portNumber);
            writer.Number<uint8_t>(_device.protocol);
            writer.Number<Exchange::IUSBHub::Speed>(_device.busSpeed);
            writer.Text(_device.serialNumber);
            writer.Number<Exchange::IUSBHub::Flags>(_device.flags);
            writer.Number<uint16_t>(_device.vendorId);
            writer.Number<uint16_t>(_device.productId);
            writer.Number<uint8_t>(_device.deviceClass);
            writer.Number<uint8_t>(_device.deviceSubclass);
            writer.Text(_device.devicePath);
            writer.Number<uint32_t>(_device.features);
            writer.Number<uint8_t>(_device.numLanguageIds);
            writer.Number<uint8_t>(_device.productInfo1.languageId);
            writer.Text(_device.productInfo1.serialNumber);
            writer.Text(_device.productInfo1.manufacturer);
            writer.Text(_device.productInfo1.product);
            writer.Number<uint8_t>(_device.productInfo2.languageId);
            writer.Text(_device.productInfo2.serialNumber);
            writer.Text(_device.productInfo2.manufacturer);
            writer.Text(_device.productInfo2.product);
            writer.Number<uint8_t>(_device.productInfo3.languageId);
            writer.Text(_device.productInfo3.serialNumber);
            writer.Text(_device.productInfo3.manufacturer);
            writer.Text(_device.productInfo3.product);
            writer.Number<uint8_t>(_device.productInfo4.languageId);
            writer.Text(_device.productInfo4.serialNumber);
            writer.Text(_device.productInfo4.manufacturer);
            writer.Text(_device.productInfo4.product);
        },

        // (5) virtual Core::hresult Acquire(const string&, Exchange::IUSBHub::IDevice*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUSBHub* implementation = reinterpret_cast<const Exchange::IUSBHub*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _deviceName = reader.Text();

            Exchange::IUSBHub::IDevice* _device{};

            Core::hresult result = implementation->Acquire(static_cast<const string&>(_deviceName), _device);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_device));

            RPC::Administrator::Instance().RegisterInterface(channel, _device);
        },

        // (6) virtual Core::hresult Relinquish(const Exchange::IUSBHub::IDevice*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUSBHub* implementation = reinterpret_cast<const Exchange::IUSBHub*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            const Exchange::IUSBHub::IDevice* _device{};

            Core::hresult result = implementation->Relinquish(_device);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_device));

            RPC::Administrator::Instance().RegisterInterface(channel, _device);
        }
        , nullptr
    }; // ExchangeUSBHubStubMethods

    //
    // Exchange::IUSBHub::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Announce(const Exchange::IUSBHub::DeviceMetadata&) = 0
    //  (1) virtual void Revoke(const Exchange::IUSBHub::DeviceMetadata&) = 0
    //

    static ProxyStub::MethodHandler ExchangeUSBHubNotificationStubMethods[] = {
        // (0) virtual void Announce(const Exchange::IUSBHub::DeviceMetadata&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUSBHub::INotification* implementation = reinterpret_cast<Exchange::IUSBHub::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::IUSBHub::DeviceMetadata _device{};
            _device.deviceName = reader.Text();
            _device.parentId = reader.Number<uint32_t>();
            _device.status = reader.Number<Exchange::IUSBHub::Status>();
            _device.deviceLevel = reader.Number<uint8_t>();
            _device.portNumber = reader.Number<uint8_t>();
            _device.protocol = reader.Number<uint8_t>();
            _device.busSpeed = reader.Number<Exchange::IUSBHub::Speed>();
            _device.serialNumber = reader.Text();
            _device.flags = reader.Number<Exchange::IUSBHub::Flags>();
            _device.vendorId = reader.Number<uint16_t>();
            _device.productId = reader.Number<uint16_t>();
            _device.deviceClass = reader.Number<uint8_t>();
            _device.deviceSubclass = reader.Number<uint8_t>();
            _device.devicePath = reader.Text();
            _device.features = reader.Number<uint32_t>();
            _device.numLanguageIds = reader.Number<uint8_t>();
            _device.productInfo1.languageId = reader.Number<uint8_t>();
            _device.productInfo1.serialNumber = reader.Text();
            _device.productInfo1.manufacturer = reader.Text();
            _device.productInfo1.product = reader.Text();
            _device.productInfo2.languageId = reader.Number<uint8_t>();
            _device.productInfo2.serialNumber = reader.Text();
            _device.productInfo2.manufacturer = reader.Text();
            _device.productInfo2.product = reader.Text();
            _device.productInfo3.languageId = reader.Number<uint8_t>();
            _device.productInfo3.serialNumber = reader.Text();
            _device.productInfo3.manufacturer = reader.Text();
            _device.productInfo3.product = reader.Text();
            _device.productInfo4.languageId = reader.Number<uint8_t>();
            _device.productInfo4.serialNumber = reader.Text();
            _device.productInfo4.manufacturer = reader.Text();
            _device.productInfo4.product = reader.Text();

            implementation->Announce(static_cast<const Exchange::IUSBHub::DeviceMetadata&>(_device));
        },

        // (1) virtual void Revoke(const Exchange::IUSBHub::DeviceMetadata&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUSBHub::INotification* implementation = reinterpret_cast<Exchange::IUSBHub::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::IUSBHub::DeviceMetadata _device{};
            _device.deviceName = reader.Text();
            _device.parentId = reader.Number<uint32_t>();
            _device.status = reader.Number<Exchange::IUSBHub::Status>();
            _device.deviceLevel = reader.Number<uint8_t>();
            _device.portNumber = reader.Number<uint8_t>();
            _device.protocol = reader.Number<uint8_t>();
            _device.busSpeed = reader.Number<Exchange::IUSBHub::Speed>();
            _device.serialNumber = reader.Text();
            _device.flags = reader.Number<Exchange::IUSBHub::Flags>();
            _device.vendorId = reader.Number<uint16_t>();
            _device.productId = reader.Number<uint16_t>();
            _device.deviceClass = reader.Number<uint8_t>();
            _device.deviceSubclass = reader.Number<uint8_t>();
            _device.devicePath = reader.Text();
            _device.features = reader.Number<uint32_t>();
            _device.numLanguageIds = reader.Number<uint8_t>();
            _device.productInfo1.languageId = reader.Number<uint8_t>();
            _device.productInfo1.serialNumber = reader.Text();
            _device.productInfo1.manufacturer = reader.Text();
            _device.productInfo1.product = reader.Text();
            _device.productInfo2.languageId = reader.Number<uint8_t>();
            _device.productInfo2.serialNumber = reader.Text();
            _device.productInfo2.manufacturer = reader.Text();
            _device.productInfo2.product = reader.Text();
            _device.productInfo3.languageId = reader.Number<uint8_t>();
            _device.productInfo3.serialNumber = reader.Text();
            _device.productInfo3.manufacturer = reader.Text();
            _device.productInfo3.product = reader.Text();
            _device.productInfo4.languageId = reader.Number<uint8_t>();
            _device.productInfo4.serialNumber = reader.Text();
            _device.productInfo4.manufacturer = reader.Text();
            _device.productInfo4.product = reader.Text();

            implementation->Revoke(static_cast<const Exchange::IUSBHub::DeviceMetadata&>(_device));
        }
        , nullptr
    }; // ExchangeUSBHubNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_b3acff3685df4032Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_b3acff3685df4032Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_b3acff3685df4032Proxy

    //
    // Exchange::IUSBHub interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IUSBHub::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IUSBHub::INotification*) = 0
    //  (2) virtual Core::hresult Devices(Exchange::IUSBHub::IStringIterator*&) const = 0
    //  (3) virtual Core::hresult VendorDevices(const uint16_t, const uint16_t, Exchange::IUSBHub::IStringIterator*&) const = 0
    //  (4) virtual Core::hresult Device(const string&, Exchange::IUSBHub::DeviceMetadata&) const = 0
    //  (5) virtual Core::hresult Acquire(const string&, Exchange::IUSBHub::IDevice*&) const = 0
    //  (6) virtual Core::hresult Relinquish(const Exchange::IUSBHub::IDevice*&) const = 0
    //

    class ExchangeUSBHubProxy final : public ProxyStub::UnknownProxyType<Exchange::IUSBHub> {
    public:
        ExchangeUSBHubProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::IUSBHub::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unregister(const Exchange::IUSBHub::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Devices(Exchange::IUSBHub::IStringIterator*& _iterator) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _iterator = reinterpret_cast<Exchange::IUSBHub::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IUSBHub::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult VendorDevices(const uint16_t _vendorId, const uint16_t _productId, Exchange::IUSBHub::IStringIterator*& _iterator) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_vendorId);
            writer.Number<uint16_t>(_productId);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _iterator = reinterpret_cast<Exchange::IUSBHub::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IUSBHub::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Device(const string& _deviceName, Exchange::IUSBHub::DeviceMetadata& _device) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_deviceName);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _device.deviceName = reader.Text();
                _device.parentId = reader.Number<uint32_t>();
                _device.status = reader.Number<Exchange::IUSBHub::Status>();
                _device.deviceLevel = reader.Number<uint8_t>();
                _device.portNumber = reader.Number<uint8_t>();
                _device.protocol = reader.Number<uint8_t>();
                _device.busSpeed = reader.Number<Exchange::IUSBHub::Speed>();
                _device.serialNumber = reader.Text();
                _device.flags = reader.Number<Exchange::IUSBHub::Flags>();
                _device.vendorId = reader.Number<uint16_t>();
                _device.productId = reader.Number<uint16_t>();
                _device.deviceClass = reader.Number<uint8_t>();
                _device.deviceSubclass = reader.Number<uint8_t>();
                _device.devicePath = reader.Text();
                _device.features = reader.Number<uint32_t>();
                _device.numLanguageIds = reader.Number<uint8_t>();
                _device.productInfo1.languageId = reader.Number<uint8_t>();
                _device.productInfo1.serialNumber = reader.Text();
                _device.productInfo1.manufacturer = reader.Text();
                _device.productInfo1.product = reader.Text();
                _device.productInfo2.languageId = reader.Number<uint8_t>();
                _device.productInfo2.serialNumber = reader.Text();
                _device.productInfo2.manufacturer = reader.Text();
                _device.productInfo2.product = reader.Text();
                _device.productInfo3.languageId = reader.Number<uint8_t>();
                _device.productInfo3.serialNumber = reader.Text();
                _device.productInfo3.manufacturer = reader.Text();
                _device.productInfo3.product = reader.Text();
                _device.productInfo4.languageId = reader.Number<uint8_t>();
                _device.productInfo4.serialNumber = reader.Text();
                _device.productInfo4.manufacturer = reader.Text();
                _device.productInfo4.product = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Acquire(const string& _deviceName, Exchange::IUSBHub::IDevice*& _device) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_deviceName);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _device = reinterpret_cast<Exchange::IUSBHub::IDevice*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IUSBHub::IDevice::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Relinquish(const Exchange::IUSBHub::IDevice*& _device) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _device = reinterpret_cast<const Exchange::IUSBHub::IDevice*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IUSBHub::IDevice::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

    }; // class ExchangeUSBHubProxy

    //
    // Exchange::IUSBHub::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Announce(const Exchange::IUSBHub::DeviceMetadata&) = 0
    //  (1) virtual void Revoke(const Exchange::IUSBHub::DeviceMetadata&) = 0
    //

    class ExchangeUSBHubNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IUSBHub::INotification> {
    public:
        ExchangeUSBHubNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Announce(const Exchange::IUSBHub::DeviceMetadata& _device) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_device.deviceName);
            writer.Number<uint32_t>(_device.parentId);
            writer.Number<Exchange::IUSBHub::Status>(_device.status);
            writer.Number<uint8_t>(_device.deviceLevel);
            writer.Number<uint8_t>(_device.portNumber);
            writer.Number<uint8_t>(_device.protocol);
            writer.Number<Exchange::IUSBHub::Speed>(_device.busSpeed);
            writer.Text(_device.serialNumber);
            writer.Number<Exchange::IUSBHub::Flags>(_device.flags);
            writer.Number<uint16_t>(_device.vendorId);
            writer.Number<uint16_t>(_device.productId);
            writer.Number<uint8_t>(_device.deviceClass);
            writer.Number<uint8_t>(_device.deviceSubclass);
            writer.Text(_device.devicePath);
            writer.Number<uint32_t>(_device.features);
            writer.Number<uint8_t>(_device.numLanguageIds);
            writer.Number<uint8_t>(_device.productInfo1.languageId);
            writer.Text(_device.productInfo1.serialNumber);
            writer.Text(_device.productInfo1.manufacturer);
            writer.Text(_device.productInfo1.product);
            writer.Number<uint8_t>(_device.productInfo2.languageId);
            writer.Text(_device.productInfo2.serialNumber);
            writer.Text(_device.productInfo2.manufacturer);
            writer.Text(_device.productInfo2.product);
            writer.Number<uint8_t>(_device.productInfo3.languageId);
            writer.Text(_device.productInfo3.serialNumber);
            writer.Text(_device.productInfo3.manufacturer);
            writer.Text(_device.productInfo3.product);
            writer.Number<uint8_t>(_device.productInfo4.languageId);
            writer.Text(_device.productInfo4.serialNumber);
            writer.Text(_device.productInfo4.manufacturer);
            writer.Text(_device.productInfo4.product);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Revoke(const Exchange::IUSBHub::DeviceMetadata& _device) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_device.deviceName);
            writer.Number<uint32_t>(_device.parentId);
            writer.Number<Exchange::IUSBHub::Status>(_device.status);
            writer.Number<uint8_t>(_device.deviceLevel);
            writer.Number<uint8_t>(_device.portNumber);
            writer.Number<uint8_t>(_device.protocol);
            writer.Number<Exchange::IUSBHub::Speed>(_device.busSpeed);
            writer.Text(_device.serialNumber);
            writer.Number<Exchange::IUSBHub::Flags>(_device.flags);
            writer.Number<uint16_t>(_device.vendorId);
            writer.Number<uint16_t>(_device.productId);
            writer.Number<uint8_t>(_device.deviceClass);
            writer.Number<uint8_t>(_device.deviceSubclass);
            writer.Text(_device.devicePath);
            writer.Number<uint32_t>(_device.features);
            writer.Number<uint8_t>(_device.numLanguageIds);
            writer.Number<uint8_t>(_device.productInfo1.languageId);
            writer.Text(_device.productInfo1.serialNumber);
            writer.Text(_device.productInfo1.manufacturer);
            writer.Text(_device.productInfo1.product);
            writer.Number<uint8_t>(_device.productInfo2.languageId);
            writer.Text(_device.productInfo2.serialNumber);
            writer.Text(_device.productInfo2.manufacturer);
            writer.Text(_device.productInfo2.product);
            writer.Number<uint8_t>(_device.productInfo3.languageId);
            writer.Text(_device.productInfo3.serialNumber);
            writer.Text(_device.productInfo3.manufacturer);
            writer.Text(_device.productInfo3.product);
            writer.Number<uint8_t>(_device.productInfo4.languageId);
            writer.Text(_device.productInfo4.serialNumber);
            writer.Text(_device.productInfo4.manufacturer);
            writer.Text(_device.productInfo4.product);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeUSBHubNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IUSBHub, ExchangeUSBHubStubMethods> ExchangeUSBHubStub;
        typedef ProxyStub::UnknownStubType<Exchange::IUSBHub::INotification, ExchangeUSBHubNotificationStubMethods> ExchangeUSBHubNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IUSBHub, ExchangeUSBHubProxy, ExchangeUSBHubStub>();
                RPC::Administrator::Instance().Announce<Exchange::IUSBHub::INotification, ExchangeUSBHubNotificationProxy, ExchangeUSBHubNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IUSBHub>();
                RPC::Administrator::Instance().Recall<Exchange::IUSBHub::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
