//
// generated automatically from "IStateController.h"
//
// implements COM-RPC proxy stubs for:
//   - class IStateController
//   - class IStateController::INotification
//

#include "Module.h"
#include "IStateController.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    using namespace PluginHost;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // IStateController interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(IStateController::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const IStateController::INotification* const) = 0
    //  (2) virtual Core::hresult State(IStateController::state&) const = 0
    //  (3) virtual Core::hresult Request(const IStateController::command) = 0
    //

    static ProxyStub::MethodHandler StateControllerStubMethods[] = {
        // (0) virtual Core::hresult Register(IStateController::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IStateController* implementation = reinterpret_cast<IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            IStateController::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const IStateController::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IStateController* implementation = reinterpret_cast<IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const IStateController::INotification* _notification{};
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

        // (2) virtual Core::hresult State(IStateController::state&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IStateController* implementation = reinterpret_cast<const IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            IStateController::state _state{};

            Core::hresult result = implementation->State(_state);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<IStateController::state>(_state);
        },

        // (3) virtual Core::hresult Request(const IStateController::command) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IStateController* implementation = reinterpret_cast<IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IStateController::command _state = reader.Number<IStateController::command>();

            Core::hresult result = implementation->Request(_state);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // StateControllerStubMethods

    //
    // IStateController::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const IStateController::state) = 0
    //

    static ProxyStub::MethodHandler StateControllerNotificationStubMethods[] = {
        // (0) virtual void StateChanged(const IStateController::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IStateController::INotification* implementation = reinterpret_cast<IStateController::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IStateController::state _state = reader.Number<IStateController::state>();

            implementation->StateChanged(_state);
        }
        , nullptr
    }; // StateControllerNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // IStateController interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(IStateController::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const IStateController::INotification* const) = 0
    //  (2) virtual Core::hresult State(IStateController::state&) const = 0
    //  (3) virtual Core::hresult Request(const IStateController::command) = 0
    //

    class StateControllerProxy final : public ProxyStub::UnknownProxyType<IStateController> {
    public:
        StateControllerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(IStateController::INotification* const _notification) override
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

        Core::hresult Unregister(const IStateController::INotification* const _notification) override
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

        Core::hresult State(IStateController::state& _state) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _state = reader.Number<IStateController::state>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Request(const IStateController::command _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IStateController::command>(_state);

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

    }; // class StateControllerProxy

    //
    // IStateController::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const IStateController::state) = 0
    //

    class StateControllerNotificationProxy final : public ProxyStub::UnknownProxyType<IStateController::INotification> {
    public:
        StateControllerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChanged(const IStateController::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IStateController::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class StateControllerNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<IStateController, StateControllerStubMethods> StateControllerStub;
        typedef ProxyStub::UnknownStubType<IStateController::INotification, StateControllerNotificationStubMethods> StateControllerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IStateController, StateControllerProxy, StateControllerStub>();
                RPC::Administrator::Instance().Announce<IStateController::INotification, StateControllerNotificationProxy, StateControllerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IStateController>();
                RPC::Administrator::Instance().Recall<IStateController::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
