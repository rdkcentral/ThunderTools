//
// generated automatically from "IBluetoothRemoteControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IBluetoothRemoteControl
//   - class Exchange::IBluetoothRemoteControl::INotification
//

#include "Module.h"
#include "IBluetoothRemoteControl.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IBluetoothRemoteControl interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IBluetoothRemoteControl::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IBluetoothRemoteControl::INotification* const) = 0
    //  (2) virtual Core::hresult Assign(const string&) = 0
    //  (3) virtual Core::hresult Revoke() = 0
    //  (4) virtual Core::hresult Device(string&) const = 0
    //  (5) virtual Core::hresult Metadata(Exchange::IBluetoothRemoteControl::unitmetadata&) const = 0
    //  (6) virtual Core::hresult BatteryLevel(uint8_t&) const = 0
    //  (7) virtual Core::hresult VoiceControl(bool&) const = 0
    //  (8) virtual Core::hresult VoiceControl(const bool) = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothRemoteControlStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IBluetoothRemoteControl::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBluetoothRemoteControl::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const Exchange::IBluetoothRemoteControl::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IBluetoothRemoteControl::INotification* _notification{};
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

        // (2) virtual Core::hresult Assign(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _address = reader.Text();

            Core::hresult result = implementation->Assign(static_cast<const string&>(_address));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult Revoke() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Revoke();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Device(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<const Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _address{};

            Core::hresult result = implementation->Device(_address);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_address);
        },

        // (5) virtual Core::hresult Metadata(Exchange::IBluetoothRemoteControl::unitmetadata&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<const Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothRemoteControl::unitmetadata _info{};

            Core::hresult result = implementation->Metadata(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_info.name);
            writer.Boolean(_info.model.IsSet());
            if (_info.model.IsSet() == true) {
                writer.Text(_info.model.Value());
            }
            writer.Boolean(_info.serial.IsSet());
            if (_info.serial.IsSet() == true) {
                writer.Text(_info.serial.Value());
            }
            writer.Boolean(_info.firmware.IsSet());
            if (_info.firmware.IsSet() == true) {
                writer.Text(_info.firmware.Value());
            }
            writer.Boolean(_info.software.IsSet());
            if (_info.software.IsSet() == true) {
                writer.Text(_info.software.Value());
            }
            writer.Boolean(_info.manufacturer.IsSet());
            if (_info.manufacturer.IsSet() == true) {
                writer.Text(_info.manufacturer.Value());
            }
        },

        // (6) virtual Core::hresult BatteryLevel(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<const Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t _level{};

            Core::hresult result = implementation->BatteryLevel(_level);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint8_t>(_level);
        },

        // (7) virtual Core::hresult VoiceControl(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<const Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _value{};

            Core::hresult result = implementation->VoiceControl(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_value);
        },

        // (8) virtual Core::hresult VoiceControl(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothRemoteControl* implementation = reinterpret_cast<Exchange::IBluetoothRemoteControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _value = reader.Boolean();

            Core::hresult result = implementation->VoiceControl(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeBluetoothRemoteControlStubMethods

    //
    // Exchange::IBluetoothRemoteControl::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void BatteryLevelChange(const uint8_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothRemoteControlNotificationStubMethods[] = {
        // (0) virtual void BatteryLevelChange(const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothRemoteControl::INotification* implementation = reinterpret_cast<Exchange::IBluetoothRemoteControl::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _level = reader.Number<uint8_t>();

            implementation->BatteryLevelChange(_level);
        }
        , nullptr
    }; // ExchangeBluetoothRemoteControlNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IBluetoothRemoteControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IBluetoothRemoteControl::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IBluetoothRemoteControl::INotification* const) = 0
    //  (2) virtual Core::hresult Assign(const string&) = 0
    //  (3) virtual Core::hresult Revoke() = 0
    //  (4) virtual Core::hresult Device(string&) const = 0
    //  (5) virtual Core::hresult Metadata(Exchange::IBluetoothRemoteControl::unitmetadata&) const = 0
    //  (6) virtual Core::hresult BatteryLevel(uint8_t&) const = 0
    //  (7) virtual Core::hresult VoiceControl(bool&) const = 0
    //  (8) virtual Core::hresult VoiceControl(const bool) = 0
    //

    class ExchangeBluetoothRemoteControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothRemoteControl> {
    public:
        ExchangeBluetoothRemoteControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::IBluetoothRemoteControl::INotification* const _notification) override
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

        Core::hresult Unregister(const Exchange::IBluetoothRemoteControl::INotification* const _notification) override
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

        Core::hresult Assign(const string& _address) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Revoke() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Device(string& _address) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _address = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Metadata(Exchange::IBluetoothRemoteControl::unitmetadata& _info) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _info.name = reader.Text();
                if (reader.Boolean() == true) {
                    _info.model = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.serial = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.firmware = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.software = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.manufacturer = reader.Text();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult BatteryLevel(uint8_t& _level) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _level = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult VoiceControl(bool& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

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

        Core::hresult VoiceControl(const bool _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
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

    }; // class ExchangeBluetoothRemoteControlProxy

    //
    // Exchange::IBluetoothRemoteControl::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void BatteryLevelChange(const uint8_t) = 0
    //

    class ExchangeBluetoothRemoteControlNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothRemoteControl::INotification> {
    public:
        ExchangeBluetoothRemoteControlNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void BatteryLevelChange(const uint8_t _level) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_level);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeBluetoothRemoteControlNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothRemoteControl, ExchangeBluetoothRemoteControlStubMethods> ExchangeBluetoothRemoteControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothRemoteControl::INotification, ExchangeBluetoothRemoteControlNotificationStubMethods> ExchangeBluetoothRemoteControlNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothRemoteControl, ExchangeBluetoothRemoteControlProxy, ExchangeBluetoothRemoteControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothRemoteControl::INotification, ExchangeBluetoothRemoteControlNotificationProxy, ExchangeBluetoothRemoteControlNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothRemoteControl>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothRemoteControl::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
