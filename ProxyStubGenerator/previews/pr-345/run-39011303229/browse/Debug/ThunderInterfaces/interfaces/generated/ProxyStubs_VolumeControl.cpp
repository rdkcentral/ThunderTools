//
// generated automatically from "IVolumeControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IVolumeControl
//   - class Exchange::IVolumeControl::INotification
//

#include "Module.h"
#include "IVolumeControl.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IVolumeControl interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IVolumeControl::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IVolumeControl::INotification*) = 0
    //  (2) virtual uint32_t Muted(const bool) = 0
    //  (3) virtual uint32_t Muted(bool&) const = 0
    //  (4) virtual uint32_t Volume(const uint8_t) = 0
    //  (5) virtual uint32_t Volume(uint8_t&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeVolumeControlStubMethods[] = {
        // (0) virtual void Register(Exchange::IVolumeControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVolumeControl* implementation = reinterpret_cast<Exchange::IVolumeControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IVolumeControl::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(const Exchange::IVolumeControl::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVolumeControl* implementation = reinterpret_cast<Exchange::IVolumeControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IVolumeControl::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t Muted(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVolumeControl* implementation = reinterpret_cast<Exchange::IVolumeControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _muted = reader.Boolean();

            uint32_t result = implementation->Muted(_muted);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Muted(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVolumeControl* implementation = reinterpret_cast<const Exchange::IVolumeControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _muted{};

            uint32_t result = implementation->Muted(_muted);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_muted);
        },

        // (4) virtual uint32_t Volume(const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVolumeControl* implementation = reinterpret_cast<Exchange::IVolumeControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _volume = reader.Number<uint8_t>();

            uint32_t result = implementation->Volume(_volume);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t Volume(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVolumeControl* implementation = reinterpret_cast<const Exchange::IVolumeControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t _volume{};

            uint32_t result = implementation->Volume(_volume);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint8_t>(_volume);
        }
        , nullptr
    }; // ExchangeVolumeControlStubMethods

    //
    // Exchange::IVolumeControl::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Volume(const uint8_t) = 0
    //  (1) virtual void Muted(const bool) = 0
    //

    static ProxyStub::MethodHandler ExchangeVolumeControlNotificationStubMethods[] = {
        // (0) virtual void Volume(const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVolumeControl::INotification* implementation = reinterpret_cast<Exchange::IVolumeControl::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _volume = reader.Number<uint8_t>();

            implementation->Volume(_volume);
        },

        // (1) virtual void Muted(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVolumeControl::INotification* implementation = reinterpret_cast<Exchange::IVolumeControl::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _muted = reader.Boolean();

            implementation->Muted(_muted);
        }
        , nullptr
    }; // ExchangeVolumeControlNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IVolumeControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IVolumeControl::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IVolumeControl::INotification*) = 0
    //  (2) virtual uint32_t Muted(const bool) = 0
    //  (3) virtual uint32_t Muted(bool&) const = 0
    //  (4) virtual uint32_t Volume(const uint8_t) = 0
    //  (5) virtual uint32_t Volume(uint8_t&) const = 0
    //

    class ExchangeVolumeControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IVolumeControl> {
    public:
        ExchangeVolumeControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::IVolumeControl::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(const Exchange::IVolumeControl::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Muted(const bool _muted) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_muted);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Muted(bool& _muted) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _muted = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Volume(const uint8_t _volume) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_volume);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Volume(uint8_t& _volume) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _volume = reader.Number<uint8_t>();
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

    }; // class ExchangeVolumeControlProxy

    //
    // Exchange::IVolumeControl::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Volume(const uint8_t) = 0
    //  (1) virtual void Muted(const bool) = 0
    //

    class ExchangeVolumeControlNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IVolumeControl::INotification> {
    public:
        ExchangeVolumeControlNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Volume(const uint8_t _volume) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_volume);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Muted(const bool _muted) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_muted);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeVolumeControlNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IVolumeControl, ExchangeVolumeControlStubMethods> ExchangeVolumeControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IVolumeControl::INotification, ExchangeVolumeControlNotificationStubMethods> ExchangeVolumeControlNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IVolumeControl, ExchangeVolumeControlProxy, ExchangeVolumeControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IVolumeControl::INotification, ExchangeVolumeControlNotificationProxy, ExchangeVolumeControlNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IVolumeControl>();
                RPC::Administrator::Instance().Recall<Exchange::IVolumeControl::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
