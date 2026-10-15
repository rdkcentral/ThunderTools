//
// generated automatically from "IStateController.h"
//
// implements COM-RPC proxy stubs for:
//   - class PluginHost::IStateController
//   - class PluginHost::IStateController::INotification
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
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
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                PluginHost::IStateController* implementation = reinterpret_cast<PluginHost::IStateController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), PluginHost::IStateController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                PluginHost::IStateController::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Register(_notification);

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Unregister(const PluginHost::IStateController::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                PluginHost::IStateController* implementation = reinterpret_cast<PluginHost::IStateController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), PluginHost::IStateController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                const PluginHost::IStateController::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Unregister(_notification);

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult State(PluginHost::IStateController::state&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const PluginHost::IStateController* implementation = reinterpret_cast<const PluginHost::IStateController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), PluginHost::IStateController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                PluginHost::IStateController::state _state{};

                Core::hresult result = implementation->State(_state);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<PluginHost::IStateController::state>(_state);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Request(const PluginHost::IStateController::command) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                PluginHost::IStateController* implementation = reinterpret_cast<PluginHost::IStateController*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), PluginHost::IStateController::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<PluginHost::IStateController::command>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const PluginHost::IStateController::command _state = reader.Number<PluginHost::IStateController::command>();

                Core::hresult result = implementation->Request(_state);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 3, hresult);
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                PluginHost::IStateController::INotification* implementation = reinterpret_cast<PluginHost::IStateController::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), PluginHost::IStateController::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<PluginHost::IStateController::state>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const PluginHost::IStateController::state _state = reader.Number<PluginHost::IStateController::state>();

                implementation->StateChanged(_state);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), PluginHost::IStateController::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Unregister(const PluginHost::IStateController::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), PluginHost::IStateController::INotification::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult State(PluginHost::IStateController::state& _state) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<PluginHost::IStateController::state>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _state = reader.Number<PluginHost::IStateController::state>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 2, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::ID, 3, hresult);
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", PluginHost::IStateController::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<PluginHost::IStateController, PluginHostStateControllerProxy, PluginHostStateControllerStub>(security);
                RPC::Administrator::Instance().Announce<PluginHost::IStateController::INotification, PluginHostStateControllerNotificationProxy, PluginHostStateControllerNotificationStub>(security);
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
