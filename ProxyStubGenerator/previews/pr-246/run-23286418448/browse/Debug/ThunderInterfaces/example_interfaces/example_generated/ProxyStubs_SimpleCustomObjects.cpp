//
// generated automatically from "ISimpleCustomObjects.h"
//
// implements COM-RPC proxy stubs for:
//   - class Example::ISimpleCustomObjects
//   - class Example::ISimpleCustomObjects::IAccessory
//   - class Example::ISimpleCustomObjects::IAccessory::INotification
//   - class Example::ISimpleCustomObjects::INotification
//

#include "Module.h"
#include "ISimpleCustomObjects.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Example::ISimpleCustomObjects interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Example::ISimpleCustomObjects::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Example::ISimpleCustomObjects::INotification* const) = 0
    //  (2) virtual Core::hresult Accessory(const string&, Example::ISimpleCustomObjects::IAccessory*&) const = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleCustomObjectsStubMethods[] = {
        // (0) virtual Core::hresult Register(Example::ISimpleCustomObjects::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects* implementation = reinterpret_cast<Example::ISimpleCustomObjects*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleCustomObjects::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const Example::ISimpleCustomObjects::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects* implementation = reinterpret_cast<Example::ISimpleCustomObjects*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Example::ISimpleCustomObjects::INotification* _notification{};
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

        // (2) virtual Core::hresult Accessory(const string&, Example::ISimpleCustomObjects::IAccessory*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleCustomObjects* implementation = reinterpret_cast<const Example::ISimpleCustomObjects*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Example::ISimpleCustomObjects::IAccessory* _accessory{};

            Core::hresult result = implementation->Accessory(static_cast<const string&>(_name), _accessory);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_accessory));

            RPC::Administrator::Instance().RegisterInterface(channel, _accessory);
        }
        , nullptr
    }; // ExampleSimpleCustomObjectsStubMethods

    //
    // Example::ISimpleCustomObjects::IAccessory interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Example::ISimpleCustomObjects::IAccessory::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Example::ISimpleCustomObjects::IAccessory::INotification* const) = 0
    //  (2) virtual Core::hresult Name(string&) const = 0
    //  (3) virtual Core::hresult Name(const string&) = 0
    //  (4) virtual Core::hresult Pin(const uint8_t, const bool) = 0
    //  (5) virtual Core::hresult Pin(const uint8_t, bool&) const = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleCustomObjectsAccessoryStubMethods[] = {
        // (0) virtual Core::hresult Register(Example::ISimpleCustomObjects::IAccessory::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects::IAccessory* implementation = reinterpret_cast<Example::ISimpleCustomObjects::IAccessory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleCustomObjects::IAccessory::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const Example::ISimpleCustomObjects::IAccessory::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects::IAccessory* implementation = reinterpret_cast<Example::ISimpleCustomObjects::IAccessory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Example::ISimpleCustomObjects::IAccessory::INotification* _notification{};
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

        // (2) virtual Core::hresult Name(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleCustomObjects::IAccessory* implementation = reinterpret_cast<const Example::ISimpleCustomObjects::IAccessory*>(message->Parameters().Implementation());
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
            Example::ISimpleCustomObjects::IAccessory* implementation = reinterpret_cast<Example::ISimpleCustomObjects::IAccessory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Core::hresult result = implementation->Name(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Pin(const uint8_t, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects::IAccessory* implementation = reinterpret_cast<Example::ISimpleCustomObjects::IAccessory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _pin = reader.Number<uint8_t>();
            const bool _value = reader.Boolean();

            Core::hresult result = implementation->Pin(_pin, _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (5) virtual Core::hresult Pin(const uint8_t, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleCustomObjects::IAccessory* implementation = reinterpret_cast<const Example::ISimpleCustomObjects::IAccessory*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _pin = reader.Number<uint8_t>();

            bool _value{};

            Core::hresult result = implementation->Pin(_pin, _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_value);
        }
        , nullptr
    }; // ExampleSimpleCustomObjectsAccessoryStubMethods

    //
    // Example::ISimpleCustomObjects::IAccessory::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void NameChanged(const string&) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleCustomObjectsAccessoryNotificationStubMethods[] = {
        // (0) virtual void NameChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects::IAccessory::INotification* implementation = reinterpret_cast<Example::ISimpleCustomObjects::IAccessory::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            implementation->NameChanged(static_cast<const string&>(_name));
        }
        , nullptr
    }; // ExampleSimpleCustomObjectsAccessoryNotificationStubMethods

    //
    // Example::ISimpleCustomObjects::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Added(Example::ISimpleCustomObjects::IAccessory* const) = 0
    //  (1) virtual void Removed(Example::ISimpleCustomObjects::IAccessory* const) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleCustomObjectsNotificationStubMethods[] = {
        // (0) virtual void Added(Example::ISimpleCustomObjects::IAccessory* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects::INotification* implementation = reinterpret_cast<Example::ISimpleCustomObjects::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _accessoryInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleCustomObjects::IAccessory* _accessory{};
            ProxyStub::UnknownProxy* _accessoryProxy__ = nullptr;
            if (_accessoryInstanceId__ != 0) {
                _accessoryProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _accessoryInstanceId__, false, _accessory);
                ASSERT((_accessory != nullptr) && (_accessoryProxy__ != nullptr));
            }

            implementation->Added(_accessory);

            if (_accessoryProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_accessoryProxy__, message->Response());
            }
        },

        // (1) virtual void Removed(Example::ISimpleCustomObjects::IAccessory* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleCustomObjects::INotification* implementation = reinterpret_cast<Example::ISimpleCustomObjects::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _accessoryInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleCustomObjects::IAccessory* _accessory{};
            ProxyStub::UnknownProxy* _accessoryProxy__ = nullptr;
            if (_accessoryInstanceId__ != 0) {
                _accessoryProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _accessoryInstanceId__, false, _accessory);
                ASSERT((_accessory != nullptr) && (_accessoryProxy__ != nullptr));
            }

            implementation->Removed(_accessory);

            if (_accessoryProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_accessoryProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExampleSimpleCustomObjectsNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Example::ISimpleCustomObjects interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Example::ISimpleCustomObjects::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Example::ISimpleCustomObjects::INotification* const) = 0
    //  (2) virtual Core::hresult Accessory(const string&, Example::ISimpleCustomObjects::IAccessory*&) const = 0
    //

    class ExampleSimpleCustomObjectsProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleCustomObjects> {
    public:
        ExampleSimpleCustomObjectsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Example::ISimpleCustomObjects::INotification* const _notification) override
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

        Core::hresult Unregister(const Example::ISimpleCustomObjects::INotification* const _notification) override
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

        Core::hresult Accessory(const string& _name, Example::ISimpleCustomObjects::IAccessory*& _accessory) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _accessory = reinterpret_cast<Example::ISimpleCustomObjects::IAccessory*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Example::ISimpleCustomObjects::IAccessory::ID));
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

    }; // class ExampleSimpleCustomObjectsProxy

    //
    // Example::ISimpleCustomObjects::IAccessory interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Example::ISimpleCustomObjects::IAccessory::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Example::ISimpleCustomObjects::IAccessory::INotification* const) = 0
    //  (2) virtual Core::hresult Name(string&) const = 0
    //  (3) virtual Core::hresult Name(const string&) = 0
    //  (4) virtual Core::hresult Pin(const uint8_t, const bool) = 0
    //  (5) virtual Core::hresult Pin(const uint8_t, bool&) const = 0
    //

    class ExampleSimpleCustomObjectsAccessoryProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleCustomObjects::IAccessory> {
    public:
        ExampleSimpleCustomObjectsAccessoryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Example::ISimpleCustomObjects::IAccessory::INotification* const _notification) override
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

        Core::hresult Unregister(const Example::ISimpleCustomObjects::IAccessory::INotification* const _notification) override
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

        Core::hresult Pin(const uint8_t _pin, const bool _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_pin);
            writer.Boolean(_value);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Pin(const uint8_t _pin, bool& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_pin);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _value = reader.Boolean();
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

    }; // class ExampleSimpleCustomObjectsAccessoryProxy

    //
    // Example::ISimpleCustomObjects::IAccessory::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void NameChanged(const string&) = 0
    //

    class ExampleSimpleCustomObjectsAccessoryNotificationProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleCustomObjects::IAccessory::INotification> {
    public:
        ExampleSimpleCustomObjectsAccessoryNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void NameChanged(const string& _name) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExampleSimpleCustomObjectsAccessoryNotificationProxy

    //
    // Example::ISimpleCustomObjects::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Added(Example::ISimpleCustomObjects::IAccessory* const) = 0
    //  (1) virtual void Removed(Example::ISimpleCustomObjects::IAccessory* const) = 0
    //

    class ExampleSimpleCustomObjectsNotificationProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleCustomObjects::INotification> {
    public:
        ExampleSimpleCustomObjectsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Added(Example::ISimpleCustomObjects::IAccessory* const _accessory) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_accessory));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Removed(Example::ISimpleCustomObjects::IAccessory* const _accessory) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_accessory));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
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

    }; // class ExampleSimpleCustomObjectsNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Example::ISimpleCustomObjects, ExampleSimpleCustomObjectsStubMethods> ExampleSimpleCustomObjectsStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleCustomObjects::IAccessory, ExampleSimpleCustomObjectsAccessoryStubMethods> ExampleSimpleCustomObjectsAccessoryStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleCustomObjects::IAccessory::INotification, ExampleSimpleCustomObjectsAccessoryNotificationStubMethods> ExampleSimpleCustomObjectsAccessoryNotificationStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleCustomObjects::INotification, ExampleSimpleCustomObjectsNotificationStubMethods> ExampleSimpleCustomObjectsNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Example::ISimpleCustomObjects, ExampleSimpleCustomObjectsProxy, ExampleSimpleCustomObjectsStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleCustomObjects::IAccessory, ExampleSimpleCustomObjectsAccessoryProxy, ExampleSimpleCustomObjectsAccessoryStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleCustomObjects::IAccessory::INotification, ExampleSimpleCustomObjectsAccessoryNotificationProxy, ExampleSimpleCustomObjectsAccessoryNotificationStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleCustomObjects::INotification, ExampleSimpleCustomObjectsNotificationProxy, ExampleSimpleCustomObjectsNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Example::ISimpleCustomObjects>();
                RPC::Administrator::Instance().Recall<Example::ISimpleCustomObjects::IAccessory>();
                RPC::Administrator::Instance().Recall<Example::ISimpleCustomObjects::IAccessory::INotification>();
                RPC::Administrator::Instance().Recall<Example::ISimpleCustomObjects::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
