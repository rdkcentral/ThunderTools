//
// generated automatically from "IStateController.h"
//
// implements COM-RPC proxy stubs for:
//   - class PluginHost::IStateController
//   - class PluginHost::IStateController::INotification
//

#include "Module.h"
#include "IStateController.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // PluginHost::IStateController interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(PluginHost::IStateController::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const PluginHost::IStateController::INotification* const) = 0
    //  (2) virtual Core::hresult State(PluginHost::IStateController::state&) const = 0
    //  (3) virtual Core::hresult Request(const PluginHost::IStateController::command) = 0
    //

    static ProxyStub::MethodHandler PluginHostStateControllerStubMethods[] = {
        // (0) virtual Core::hresult Register(PluginHost::IStateController::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IStateController* implementation = reinterpret_cast<PluginHost::IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IStateController::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const PluginHost::IStateController::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IStateController* implementation = reinterpret_cast<PluginHost::IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const PluginHost::IStateController::INotification* _notification{};
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

        // (2) virtual Core::hresult State(PluginHost::IStateController::state&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const PluginHost::IStateController* implementation = reinterpret_cast<const PluginHost::IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            PluginHost::IStateController::state _state{};

            Core::hresult result = implementation->State(_state);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<PluginHost::IStateController::state>(_state);
        },

        // (3) virtual Core::hresult Request(const PluginHost::IStateController::command) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IStateController* implementation = reinterpret_cast<PluginHost::IStateController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const PluginHost::IStateController::command _state = reader.Number<PluginHost::IStateController::command>();

            Core::hresult result = implementation->Request(_state);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // PluginHostStateControllerStubMethods

    //
    // PluginHost::IStateController::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const PluginHost::IStateController::state) = 0
    //

    static ProxyStub::MethodHandler PluginHostStateControllerNotificationStubMethods[] = {
        // (0) virtual void StateChanged(const PluginHost::IStateController::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IStateController::INotification* implementation = reinterpret_cast<PluginHost::IStateController::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const PluginHost::IStateController::state _state = reader.Number<PluginHost::IStateController::state>();

            implementation->StateChanged(_state);
        }
        , nullptr
    }; // PluginHostStateControllerNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // PluginHost::IStateController interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(PluginHost::IStateController::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const PluginHost::IStateController::INotification* const) = 0
    //  (2) virtual Core::hresult State(PluginHost::IStateController::state&) const = 0
    //  (3) virtual Core::hresult Request(const PluginHost::IStateController::command) = 0
    //

    class PluginHostStateControllerProxy final : public ProxyStub::UnknownProxyType<PluginHost::IStateController> {
    public:
        PluginHostStateControllerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(PluginHost::IStateController::INotification* const _notification) override
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

        Core::hresult Unregister(const PluginHost::IStateController::INotification* const _notification) override
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

        Core::hresult State(PluginHost::IStateController::state& _state) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _state = reader.Number<PluginHost::IStateController::state>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Request(const PluginHost::IStateController::command _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<PluginHost::IStateController::command>(_state);

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

    }; // class PluginHostStateControllerProxy

    //
    // PluginHost::IStateController::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const PluginHost::IStateController::state) = 0
    //

    class PluginHostStateControllerNotificationProxy final : public ProxyStub::UnknownProxyType<PluginHost::IStateController::INotification> {
    public:
        PluginHostStateControllerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChanged(const PluginHost::IStateController::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<PluginHost::IStateController::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class PluginHostStateControllerNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<PluginHost::IStateController, PluginHostStateControllerStubMethods> PluginHostStateControllerStub;
        typedef ProxyStub::UnknownStubType<PluginHost::IStateController::INotification, PluginHostStateControllerNotificationStubMethods> PluginHostStateControllerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<PluginHost::IStateController, PluginHostStateControllerProxy, PluginHostStateControllerStub>();
                RPC::Administrator::Instance().Announce<PluginHost::IStateController::INotification, PluginHostStateControllerNotificationProxy, PluginHostStateControllerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<PluginHost::IStateController>();
                RPC::Administrator::Instance().Recall<PluginHost::IStateController::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
