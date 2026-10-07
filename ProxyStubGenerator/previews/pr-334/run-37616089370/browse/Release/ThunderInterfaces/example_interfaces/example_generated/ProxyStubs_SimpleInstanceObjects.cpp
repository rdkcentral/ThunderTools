//
// generated automatically from "ISimpleInstanceObjects.h"
//
// implements COM-RPC proxy stubs for:
//   - class Example::ISimpleInstanceObjects
//   - class Example::ISimpleInstanceObjects::IDevice
//   - class Example::ISimpleInstanceObjects::IDevice::INotification
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
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
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects* implementation = reinterpret_cast<Example::ISimpleInstanceObjects*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _namePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _name = reader.Text();

                Example::ISimpleInstanceObjects::IDevice* _device{};

                Core::hresult result = implementation->Acquire(static_cast<const string&>(_name), _device);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_device));

                RPC::Administrator::Instance().RegisterInterface(channel, _device);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Relinquish(Example::ISimpleInstanceObjects::IDevice* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects* implementation = reinterpret_cast<Example::ISimpleInstanceObjects*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _deviceInstanceId__ = reader.Number<Core::instance_id>();

                Example::ISimpleInstanceObjects::IDevice* _device{};
                ProxyStub::UnknownProxy* _deviceProxy__ = nullptr;
                if (_deviceInstanceId__ != 0) {
                    _deviceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _deviceInstanceId__, false, _device);
                    ASSERT((_device != nullptr) && (_deviceProxy__ != nullptr));
                    if ((_device == nullptr) || (_deviceProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Relinquish(_device);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_deviceProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_deviceProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::ID, 1, hresult);
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
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();
                Core::OptionalType<uint8_t> _pin{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _pin = reader.Number<uint8_t>();
                }

                Example::ISimpleInstanceObjects::IDevice::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Register(_notification, static_cast<const Core::OptionalType<uint8_t>&>(_pin));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_notificationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Unregister(const Example::ISimpleInstanceObjects::IDevice::INotification* const, const Core::OptionalType<uint8_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificaitonInstanceId__ = reader.Number<Core::instance_id>();
                Core::OptionalType<uint8_t> _pin{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _pin = reader.Number<uint8_t>();
                }

                const Example::ISimpleInstanceObjects::IDevice::INotification* _notificaiton{};
                ProxyStub::UnknownProxy* _notificaitonProxy__ = nullptr;
                if (_notificaitonInstanceId__ != 0) {
                    _notificaitonProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificaitonInstanceId__, false, _notificaiton);
                    ASSERT((_notificaiton != nullptr) && (_notificaitonProxy__ != nullptr));
                    if ((_notificaiton == nullptr) || (_notificaitonProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Unregister(_notificaiton, static_cast<const Core::OptionalType<uint8_t>&>(_pin));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_notificaitonProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificaitonProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Name(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<const Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _name{};

                Core::hresult result = implementation->Name(_name);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_name);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Name(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _namePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _name = reader.Text();

                Core::hresult result = implementation->Name(static_cast<const string&>(_name));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Enable() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Core::hresult result = implementation->Enable();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult Disable() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Core::hresult result = implementation->Disable();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 5, hresult);
            }
        },

        // (6) virtual Core::hresult Pin(const uint8_t, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _pin = reader.Number<uint8_t>();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _high = reader.Boolean();

                Core::hresult result = implementation->Pin(_pin, _high);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 6, hresult);
            }
        },

        // (7) virtual Core::hresult Pin(const uint8_t, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Example::ISimpleInstanceObjects::IDevice* implementation = reinterpret_cast<const Example::ISimpleInstanceObjects::IDevice*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _pin = reader.Number<uint8_t>();

                bool _high{};

                Core::hresult result = implementation->Pin(_pin, _high);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Boolean(_high);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 7, hresult);
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice::INotification* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _statePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _statePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _state = reader.Text();

                implementation->NameChanged(static_cast<const string&>(_state));

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual void StateChanged(const Example::ISimpleInstanceObjects::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice::INotification* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Example::ISimpleInstanceObjects::state>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Example::ISimpleInstanceObjects::state _state = reader.Number<Example::ISimpleInstanceObjects::state>();

                implementation->StateChanged(_state);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::INotification::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void PinChanged(const uint8_t, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Example::ISimpleInstanceObjects::IDevice::INotification* implementation = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Example::ISimpleInstanceObjects::IDevice::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _pin = reader.Number<uint8_t>();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _high = reader.Boolean();

                implementation->PinChanged(_pin, _high);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::INotification::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _device = reinterpret_cast<Example::ISimpleInstanceObjects::IDevice*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Example::ISimpleInstanceObjects::IDevice::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult Relinquish(Example::ISimpleInstanceObjects::IDevice* const _device) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_device));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_device), Example::ISimpleInstanceObjects::IDevice::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const size_t entrySize = (sizeof(Core::instance_id) + sizeof(uint32_t) + sizeof(RPC::Data::Output::mode));
                if (reader.Length() < entrySize) { result = (COM_ERROR | Core::ERROR_READ_ERROR); break; }

                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                if (RPC::Administrator::Instance().IsValid(static_cast<const ProxyStub::UnknownProxy&>(*this).Channel(), implementation, id) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

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

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), Example::ISimpleInstanceObjects::IDevice::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

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

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notificaiton), Example::ISimpleInstanceObjects::IDevice::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Name(string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _namePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _name = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 2, hresult);
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
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult Enable() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult Disable() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 5, hresult);
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
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 6, hresult);
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
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _high = reader.Boolean();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::ID, 7, hresult);
            }

            return (hresult);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const size_t entrySize = (sizeof(Core::instance_id) + sizeof(uint32_t) + sizeof(RPC::Data::Output::mode));
                if (reader.Length() < entrySize) { result = (COM_ERROR | Core::ERROR_READ_ERROR); break; }

                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                if (RPC::Administrator::Instance().IsValid(static_cast<const ProxyStub::UnknownProxy&>(*this).Channel(), implementation, id) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        void StateChanged(const Example::ISimpleInstanceObjects::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Example::ISimpleInstanceObjects::state>(_state);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::INotification::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        void PinChanged(const uint8_t _pin, const bool _high) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_pin);
            writer.Boolean(_high);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Example::ISimpleInstanceObjects::IDevice::INotification::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Example::ISimpleInstanceObjects, ExampleSimpleInstanceObjectsProxy, ExampleSimpleInstanceObjectsStub>(security);
                RPC::Administrator::Instance().Announce<Example::ISimpleInstanceObjects::IDevice, ExampleSimpleInstanceObjectsDeviceProxy, ExampleSimpleInstanceObjectsDeviceStub>(security);
                RPC::Administrator::Instance().Announce<Example::ISimpleInstanceObjects::IDevice::INotification, ExampleSimpleInstanceObjectsDeviceNotificationProxy, ExampleSimpleInstanceObjectsDeviceNotificationStub>(security);
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
