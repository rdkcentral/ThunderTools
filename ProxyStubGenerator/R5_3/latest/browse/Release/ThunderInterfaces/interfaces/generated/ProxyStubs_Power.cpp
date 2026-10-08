//
// generated automatically from "IPower.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IPower
//   - class Exchange::IPower::INotification
//

#include "Module.h"
#include "IPower.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IPower interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IPower::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IPower::INotification* const) = 0
    //  (2) virtual Core::hresult GetState(Exchange::IPower::PCState&) const = 0
    //  (3) virtual Core::hresult SetState(const Exchange::IPower::PCState&, const uint32_t) = 0
    //  (4) virtual void PowerKey() = 0
    //

    static ProxyStub::MethodHandler ExchangePowerStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IPower::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower* implementation = reinterpret_cast<Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IPower::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(const Exchange::IPower::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower* implementation = reinterpret_cast<Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IPower::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult GetState(Exchange::IPower::PCState&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPower* implementation = reinterpret_cast<const Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPower::PCState _state{};

            Core::hresult result = implementation->GetState(_state);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IPower::PCState>(_state);
        },

        // (3) virtual Core::hresult SetState(const Exchange::IPower::PCState&, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower* implementation = reinterpret_cast<Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IPower::PCState _state = reader.Number<Exchange::IPower::PCState>();
            const uint32_t _waitTime = reader.Number<uint32_t>();

            Core::hresult result = implementation->SetState(static_cast<const Exchange::IPower::PCState&>(_state), _waitTime);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual void PowerKey() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower* implementation = reinterpret_cast<Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->PowerKey();
        }
        , nullptr
    }; // ExchangePowerStubMethods

    //
    // Exchange::IPower::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StateChange(const Exchange::IPower::PCState, const Exchange::IPower::PCState, const Exchange::IPower::PCPhase) = 0
    //

    static ProxyStub::MethodHandler ExchangePowerNotificationStubMethods[] = {
        // (0) virtual Core::hresult StateChange(const Exchange::IPower::PCState, const Exchange::IPower::PCState, const Exchange::IPower::PCPhase) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower::INotification* implementation = reinterpret_cast<Exchange::IPower::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IPower::PCState _origin = reader.Number<Exchange::IPower::PCState>();
            const Exchange::IPower::PCState _destination = reader.Number<Exchange::IPower::PCState>();
            const Exchange::IPower::PCPhase _phase = reader.Number<Exchange::IPower::PCPhase>();

            Core::hresult result = implementation->StateChange(_origin, _destination, _phase);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangePowerNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IPower interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IPower::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IPower::INotification* const) = 0
    //  (2) virtual Core::hresult GetState(Exchange::IPower::PCState&) const = 0
    //  (3) virtual Core::hresult SetState(const Exchange::IPower::PCState&, const uint32_t) = 0
    //  (4) virtual void PowerKey() = 0
    //

    class ExchangePowerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPower> {
    public:
        ExchangePowerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::IPower::INotification* const _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

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

        Core::hresult Unregister(const Exchange::IPower::INotification* const _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

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

        Core::hresult GetState(Exchange::IPower::PCState& _state) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _state = reader.Number<Exchange::IPower::PCState>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult SetState(const Exchange::IPower::PCState& _state, const uint32_t _waitTime) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IPower::PCState>(_state);
            writer.Number<uint32_t>(_waitTime);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        void PowerKey() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

    }; // class ExchangePowerProxy

    //
    // Exchange::IPower::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StateChange(const Exchange::IPower::PCState, const Exchange::IPower::PCState, const Exchange::IPower::PCPhase) = 0
    //

    class ExchangePowerNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IPower::INotification> {
    public:
        ExchangePowerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult StateChange(const Exchange::IPower::PCState _origin, const Exchange::IPower::PCState _destination, const Exchange::IPower::PCPhase _phase) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IPower::PCState>(_origin);
            writer.Number<Exchange::IPower::PCState>(_destination);
            writer.Number<Exchange::IPower::PCPhase>(_phase);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangePowerNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IPower, ExchangePowerStubMethods> ExchangePowerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPower::INotification, ExchangePowerNotificationStubMethods> ExchangePowerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IPower, ExchangePowerProxy, ExchangePowerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPower::INotification, ExchangePowerNotificationProxy, ExchangePowerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IPower>();
                RPC::Administrator::Instance().Recall<Exchange::IPower::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
