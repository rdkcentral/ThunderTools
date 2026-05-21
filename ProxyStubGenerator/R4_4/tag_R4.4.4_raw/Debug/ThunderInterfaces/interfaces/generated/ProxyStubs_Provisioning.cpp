//
// generated automatically from "IProvisioning.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IProvisioning
//   - class Exchange::IProvisioning::INotification
//

#include "Module.h"
#include "IProvisioning.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IProvisioning interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IProvisioning::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IProvisioning::INotification*) = 0
    //  (2) virtual uint32_t DeviceId(string&) const = 0
    //  (3) virtual uint32_t DRMId(const string&, uint16_t&, uint8_t*) const = 0
    //

    ProxyStub::MethodHandler ExchangeProvisioningStubMethods[] = {
        // (0) virtual void Register(Exchange::IProvisioning::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IProvisioning* implementation = reinterpret_cast<Exchange::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id provisioningImplementation = reader.Number<Core::instance_id>();

            Exchange::IProvisioning::INotification* _provisioning = nullptr;
            ProxyStub::UnknownProxy* provisioningProxy = nullptr;
            if (provisioningImplementation != 0) {
                provisioningProxy = RPC::Administrator::Instance().ProxyInstance(channel, provisioningImplementation, false, _provisioning);

                ASSERT((_provisioning != nullptr) && (provisioningProxy != nullptr));
            }

            implementation->Register(_provisioning);

            if (provisioningProxy != nullptr) {
                RPC::Administrator::Instance().Release(provisioningProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IProvisioning::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IProvisioning* implementation = reinterpret_cast<Exchange::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id provisioningImplementation = reader.Number<Core::instance_id>();

            Exchange::IProvisioning::INotification* _provisioning = nullptr;
            ProxyStub::UnknownProxy* provisioningProxy = nullptr;
            if (provisioningImplementation != 0) {
                provisioningProxy = RPC::Administrator::Instance().ProxyInstance(channel, provisioningImplementation, false, _provisioning);

                ASSERT((_provisioning != nullptr) && (provisioningProxy != nullptr));
            }

            implementation->Unregister(_provisioning);

            if (provisioningProxy != nullptr) {
                RPC::Administrator::Instance().Release(provisioningProxy, message->Response());
            }
        },

        // (2) virtual uint32_t DeviceId(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IProvisioning* implementation = reinterpret_cast<const Exchange::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _deviceId{};

            uint32_t result = implementation->DeviceId(_deviceId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_deviceId);
        },

        // (3) virtual uint32_t DRMId(const string&, uint16_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IProvisioning* implementation = reinterpret_cast<const Exchange::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _label = reader.Text();
            uint16_t _size = reader.Number<uint16_t>();

            uint8_t* _data{};

            if (_size != 0) {
                _data = static_cast<uint8_t*>(ALLOCA(_size));
            }

            uint32_t result = implementation->DRMId(static_cast<const string&>(_label), _size, _data);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Buffer<uint16_t>((_data == nullptr? 0 : _size), _data);
            writer.Number<uint16_t>(_size);
        }
        , nullptr
    }; // ExchangeProvisioningStubMethods

    //
    // Exchange::IProvisioning::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Provisioned(RPC::IStringIterator*) = 0
    //

    ProxyStub::MethodHandler ExchangeProvisioningNotificationStubMethods[] = {
        // (0) virtual void Provisioned(RPC::IStringIterator*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IProvisioning::INotification* implementation = reinterpret_cast<Exchange::IProvisioning::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id labelsImplementation = reader.Number<Core::instance_id>();

            RPC::IStringIterator* _labels = nullptr;
            ProxyStub::UnknownProxy* labelsProxy = nullptr;
            if (labelsImplementation != 0) {
                labelsProxy = RPC::Administrator::Instance().ProxyInstance(channel, labelsImplementation, false, _labels);

                ASSERT((_labels != nullptr) && (labelsProxy != nullptr));
            }

            implementation->Provisioned(_labels);

            if (labelsProxy != nullptr) {
                RPC::Administrator::Instance().Release(labelsProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeProvisioningNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IProvisioning interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IProvisioning::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IProvisioning::INotification*) = 0
    //  (2) virtual uint32_t DeviceId(string&) const = 0
    //  (3) virtual uint32_t DRMId(const string&, uint16_t&, uint8_t*) const = 0
    //

    class ExchangeProvisioningProxy final : public ProxyStub::UnknownProxyType<Exchange::IProvisioning> {
    public:
        ExchangeProvisioningProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void Register(Exchange::IProvisioning::INotification* _provisioning) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_provisioning));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IProvisioning::INotification* _provisioning) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_provisioning));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t DeviceId(string& _deviceId) const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _deviceId = reader.Text();

            return (result);
        }

        uint32_t DRMId(const string& _label, uint16_t& _size, uint8_t* _data) const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_label));
            writer.Number<uint16_t>(_size);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            reader.Buffer<uint16_t>(_size, _data);
            _size = reader.Number<uint16_t>();

            return (result);
        }

    }; // class ExchangeProvisioningProxy

    //
    // Exchange::IProvisioning::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Provisioned(RPC::IStringIterator*) = 0
    //

    class ExchangeProvisioningNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IProvisioning::INotification> {
    public:
        ExchangeProvisioningNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void Provisioned(RPC::IStringIterator* _labels) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_labels));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeProvisioningNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IProvisioning, ExchangeProvisioningStubMethods> ExchangeProvisioningStub;
        typedef ProxyStub::UnknownStubType<Exchange::IProvisioning::INotification, ExchangeProvisioningNotificationStubMethods> ExchangeProvisioningNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IProvisioning, ExchangeProvisioningProxy, ExchangeProvisioningStub>();
                RPC::Administrator::Instance().Announce<Exchange::IProvisioning::INotification, ExchangeProvisioningNotificationProxy, ExchangeProvisioningNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IProvisioning>();
                RPC::Administrator::Instance().Recall<Exchange::IProvisioning::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
