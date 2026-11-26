//
// generated automatically from "ISimpleInstanceObjects.h"
//
// implements COM-RPC proxy stubs for:
//   - class Example::ISimpleInstanceObjects
//   - class Example::ISimpleInstanceObjects::IDevice
//   - class Example::ISimpleInstanceObjects::IDevice::INotification
//

#include "Module.h"
#include "ISimpleInstanceObjects.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Example::ISimpleInstanceObjects interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Acquire(const string&, Example::ISimpleInstanceObjects::IDevice*&) = 0
    //  (1) virtual Core::hresult Relinquish(Example::ISimpleInstanceObjects::IDevice* const) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleInstanceObjectsStubMethods[] = {
        // (0) virtual Core::hresult Acquire(const string&, Example::ISimpleInstanceObjects::IDevice*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects* implementation = reinterpret_cast<Example::ISimpleInstanceObjects*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Example::ISimpleInstanceObjects::IDevice* _device{};

            Core::hresult result = implementation->Acquire(static_cast<const string&>(_name), _device);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_device));

            RPC::Administrator::Instance().RegisterInterface(channel, _device);
        },

        // (1) virtual Core::hresult Relinquish(Example::ISimpleInstanceObjects::IDevice* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects* implementation = reinterpret_cast<Example::ISimpleInstanceObjects*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _deviceInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleInstanceObjects::IDevice* _device{};
            ProxyStub::UnknownProxy* _deviceProxy__ = nullptr;
            if (_deviceInstanceId__ != 0) {
                _deviceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _deviceInstanceId__, false, _device);
                ASSERT((_device != nullptr) && (_deviceProxy__ != nullptr));
            }

            Core::hresult result = implementation->Relinquish(_device);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_deviceProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_deviceProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExampleSimpleInstanceObjectsStubMethods

    //
    // Example::ISimpleInstanceObjects::IDevice interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Example::ISimpleInstanceObjects::IDevice::INotification* const, const Core::OptionalType<uint8_t>&) = 0
    //  (1) virtual Core::hresult Unregister(const Example::ISimpleInstanceObjects::IDevice::INotification* const, const Core::OptionalType<uint8_t>&) = 0
    //  (2) virtual Core::hresult Name(string&) const = 0
    //  (3) virtual Core::hresult Name(const string&) = 0
    //  (4) virtual Core::hresult Enable() = 0
    //  (5) virtual Core::hresult Disable() = 0
    //  (6) virtual Core::hresult Pin(const uint8_t, const bool) = 0
    //  (7) virtual Core::hresult Pin(const uint8_t, bool&) const = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleInstanceObjectsDeviceStubMethods[] = {
        // (0) virtual Core::hresult Register(Example::ISimpleInstanceObjects::IDevice::INotification* const, const Core::OptionalType<uint8_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();
            Core::OptionalType<uint8_t> _pin{};
            if (reader.Boolean() == true) {
                _pin = reader.Number<uint8_t>();
            }

            Example::ISimpleInstanceObjects::IDevice::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_notification, static_cast<const Core::OptionalType<uint8_t>&>(_pin));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(const Example::ISimpleInstanceObjects::IDevice::INotification* const, const Core::OptionalType<uint8_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificaitonInstanceId__ = reader.Number<Core::instance_id>();
            Core::OptionalType<uint8_t> _pin{};
            if (reader.Boolean() == true) {
                _pin = reader.Number<uint8_t>();
            }

            const Example::ISimpleInstanceObjects::IDevice::INotification* _notificaiton{};
            ProxyStub::UnknownProxy* _notificaitonProxy__ = nullptr;
            if (_notificaitonInstanceId__ != 0) {
                _notificaitonProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificaitonInstanceId__, false, _notificaiton);
                ASSERT((_notificaiton != nullptr) && (_notificaitonProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_notificaiton, static_cast<const Core::OptionalType<uint8_t>&>(_pin));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificaitonProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificaitonProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult Name(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<const Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _name{};

            Core::hresult result = implementation->Name(_name);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_name);
        },

        // (3) virtual Core::hresult Name(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Core::hresult result = implementation->Name(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Enable() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Enable();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (5) virtual Core::hresult Disable() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Disable();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (6) virtual Core::hresult Pin(const uint8_t, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _pin = reader.Number<uint8_t>();
            const bool _high = reader.Boolean();

            Core::hresult result = implementation->Pin(_pin, _high);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (7) virtual Core::hresult Pin(const uint8_t, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<const Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _pin = reader.Number<uint8_t>();

            bool _high{};

            Core::hresult result = implementation->Pin(_pin, _high);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_high);
        }
        , nullptr
    }; // ExampleSimpleInstanceObjectsDeviceStubMethods

    //
    // Example::ISimpleInstanceObjects::IDevice::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void NameChanged(const string&) = 0
    //  (1) virtual void StateChanged(const Example::ISimpleInstanceObjects::state) = 0
    //  (2) virtual void PinChanged(const uint8_t, const bool) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleInstanceObjectsDeviceNotificationStubMethods[] = {
        // (0) virtual void NameChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice::INotification* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _state = reader.Text();

            implementation->NameChanged(static_cast<const string&>(_state));
        },

        // (1) virtual void StateChanged(const Example::ISimpleInstanceObjects::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice::INotification* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Example::ISimpleInstanceObjects::state _state = reader.Number<Example::ISimpleInstanceObjects::state>();

            implementation->StateChanged(_state);
        },

        // (2) virtual void PinChanged(const uint8_t, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleInstanceObjects::IDevice::INotification* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _pin = reader.Number<uint8_t>();
            const bool _high = reader.Boolean();

            implementation->PinChanged(_pin, _high);
        }
        , nullptr
    }; // ExampleSimpleInstanceObjectsDeviceNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Example::ISimpleInstanceObjects interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Acquire(const string&, Example::ISimpleInstanceObjects::IDevice*&) = 0
    //  (1) virtual Core::hresult Relinquish(Example::ISimpleInstanceObjects::IDevice* const) = 0
    //

    class ExampleSimpleInstanceObjectsProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleInstanceObjects> {
    public:
        ExampleSimpleInstanceObjectsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Acquire(const string& _name, Example::ISimpleInstanceObjects::IDevice*& _device) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _device = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Example::ISimpleInstanceObjects::IDevice::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Relinquish(Example::ISimpleInstanceObjects::IDevice* const _device) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_device));

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

    }; // class ExampleSimpleInstanceObjectsProxy

    //
    // Example::ISimpleInstanceObjects::IDevice interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Example::ISimpleInstanceObjects::IDevice::INotification* const, const Core::OptionalType<uint8_t>&) = 0
    //  (1) virtual Core::hresult Unregister(const Example::ISimpleInstanceObjects::IDevice::INotification* const, const Core::OptionalType<uint8_t>&) = 0
    //  (2) virtual Core::hresult Name(string&) const = 0
    //  (3) virtual Core::hresult Name(const string&) = 0
    //  (4) virtual Core::hresult Enable() = 0
    //  (5) virtual Core::hresult Disable() = 0
    //  (6) virtual Core::hresult Pin(const uint8_t, const bool) = 0
    //  (7) virtual Core::hresult Pin(const uint8_t, bool&) const = 0
    //

    class ExampleSimpleInstanceObjectsDeviceProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleInstanceObjects::IDevice> {
    public:
        ExampleSimpleInstanceObjectsDeviceProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Example::ISimpleInstanceObjects::IDevice::INotification* const _notification, const Core::OptionalType<uint8_t>& _pin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));
            writer.Boolean(_pin.IsSet());
            if (_pin.IsSet() == true) {
                writer.Number<uint8_t>(_pin.Value());
            }

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

        Core::hresult Unregister(const Example::ISimpleInstanceObjects::IDevice::INotification* const _notificaiton, const Core::OptionalType<uint8_t>& _pin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notificaiton));
            writer.Boolean(_pin.IsSet());
            if (_pin.IsSet() == true) {
                writer.Number<uint8_t>(_pin.Value());
            }

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

        Core::hresult Name(string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _name = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Name(const string& _name) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Enable() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Disable() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Pin(const uint8_t _pin, const bool _high) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_pin);
            writer.Boolean(_high);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Pin(const uint8_t _pin, bool& _high) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_pin);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _high = reader.Boolean();
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

    }; // class ExampleSimpleInstanceObjectsDeviceProxy

    //
    // Example::ISimpleInstanceObjects::IDevice::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void NameChanged(const string&) = 0
    //  (1) virtual void StateChanged(const Example::ISimpleInstanceObjects::state) = 0
    //  (2) virtual void PinChanged(const uint8_t, const bool) = 0
    //

    class ExampleSimpleInstanceObjectsDeviceNotificationProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleInstanceObjects::IDevice::INotification> {
    public:
        ExampleSimpleInstanceObjectsDeviceNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void NameChanged(const string& _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void StateChanged(const Example::ISimpleInstanceObjects::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Example::ISimpleInstanceObjects::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void PinChanged(const uint8_t _pin, const bool _high) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_pin);
            writer.Boolean(_high);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExampleSimpleInstanceObjectsDeviceNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Example::ISimpleInstanceObjects, ExampleSimpleInstanceObjectsStubMethods> ExampleSimpleInstanceObjectsStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleInstanceObjects::IDevice, ExampleSimpleInstanceObjectsDeviceStubMethods> ExampleSimpleInstanceObjectsDeviceStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleInstanceObjects::IDevice::INotification, ExampleSimpleInstanceObjectsDeviceNotificationStubMethods> ExampleSimpleInstanceObjectsDeviceNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Example::ISimpleInstanceObjects, ExampleSimpleInstanceObjectsProxy, ExampleSimpleInstanceObjectsStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleInstanceObjects::IDevice, ExampleSimpleInstanceObjectsDeviceProxy, ExampleSimpleInstanceObjectsDeviceStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleInstanceObjects::IDevice::INotification, ExampleSimpleInstanceObjectsDeviceNotificationProxy, ExampleSimpleInstanceObjectsDeviceNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Example::ISimpleInstanceObjects>();
                RPC::Administrator::Instance().Recall<Example::ISimpleInstanceObjects::IDevice>();
                RPC::Administrator::Instance().Recall<Example::ISimpleInstanceObjects::IDevice::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
