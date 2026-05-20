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

namespace WPEFramework {

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
    //  (0) virtual void Register(Exchange::IPower::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IPower::INotification*) = 0
    //  (2) virtual Exchange::IPower::PCState GetState() const = 0
    //  (3) virtual uint32_t SetState(const Exchange::IPower::PCState, const uint32_t) = 0
    //  (4) virtual void PowerKey() = 0
    //

    ProxyStub::MethodHandler ExchangePowerStubMethods[] = {
        // (0) virtual void Register(Exchange::IPower::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower* implementation = reinterpret_cast<Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IPower::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Register(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IPower::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower* implementation = reinterpret_cast<Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IPower::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Unregister(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (2) virtual Exchange::IPower::PCState GetState() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPower* implementation = reinterpret_cast<const Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPower::PCState result = implementation->GetState();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IPower::PCState>(result);
        },

        // (3) virtual uint32_t SetState(const Exchange::IPower::PCState, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower* implementation = reinterpret_cast<Exchange::IPower*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IPower::PCState _parameter_5980d737 = reader.Number<Exchange::IPower::PCState>();
            const uint32_t _parameter_8e824baa = reader.Number<uint32_t>();

            uint32_t result = implementation->SetState(_parameter_5980d737, _parameter_8e824baa);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
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
    //  (0) virtual void StateChange(const Exchange::IPower::PCState, const Exchange::IPower::PCState, const Exchange::IPower::PCPhase) = 0
    //

    ProxyStub::MethodHandler ExchangePowerNotificationStubMethods[] = {
        // (0) virtual void StateChange(const Exchange::IPower::PCState, const Exchange::IPower::PCState, const Exchange::IPower::PCPhase) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPower::INotification* implementation = reinterpret_cast<Exchange::IPower::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IPower::PCState _origin = reader.Number<Exchange::IPower::PCState>();
            const Exchange::IPower::PCState _destination = reader.Number<Exchange::IPower::PCState>();
            const Exchange::IPower::PCPhase _phase = reader.Number<Exchange::IPower::PCPhase>();

            implementation->StateChange(_origin, _destination, _phase);
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
    //  (0) virtual void Register(Exchange::IPower::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IPower::INotification*) = 0
    //  (2) virtual Exchange::IPower::PCState GetState() const = 0
    //  (3) virtual uint32_t SetState(const Exchange::IPower::PCState, const uint32_t) = 0
    //  (4) virtual void PowerKey() = 0
    //

    class ExchangePowerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPower> {
    public:
        ExchangePowerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IPower::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IPower::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        Exchange::IPower::PCState GetState() const override
        {
            IPCMessage message(BaseClass::Message(2));

            Exchange::IPower::PCState result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IPower::PCState>();

            return (result);
        }

        uint32_t SetState(const Exchange::IPower::PCState _parameter_5980d737, const uint32_t _parameter_8e824baa) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IPower::PCState>(_parameter_5980d737);
            writer.Number<uint32_t>(_parameter_8e824baa);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        void PowerKey() override
        {
            IPCMessage message(BaseClass::Message(4));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangePowerProxy

    //
    // Exchange::IPower::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const Exchange::IPower::PCState, const Exchange::IPower::PCState, const Exchange::IPower::PCPhase) = 0
    //

    class ExchangePowerNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IPower::INotification> {
    public:
        ExchangePowerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void StateChange(const Exchange::IPower::PCState _origin, const Exchange::IPower::PCState _destination, const Exchange::IPower::PCPhase _phase) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IPower::PCState>(_origin);
            writer.Number<Exchange::IPower::PCState>(_destination);
            writer.Number<Exchange::IPower::PCPhase>(_phase);

            UnknownProxyType::Invoke(message);
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
