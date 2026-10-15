//
// generated automatically from "ICOM.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IRemoteConnection
//   - class RPC::IRemoteConnection::INotification
//

#include "Module.h"
#include "ICOM.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IRemoteConnection interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Id() const = 0
    //  (1) virtual uint32_t RemoteId() const = 0
    //  (2) virtual void* Acquire(const uint32_t, const string&, const uint32_t, const uint32_t) = 0
    //  (3) virtual void Terminate() = 0
    //  (4) virtual uint32_t Launch() = 0
    //  (5) virtual void PostMortem() = 0
    //

    static ProxyStub::MethodHandler RPCRemoteConnectionStubMethods[] = {
        // (0) virtual uint32_t Id() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const RPC::IRemoteConnection* implementation = reinterpret_cast<const RPC::IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Id();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t RemoteId() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const RPC::IRemoteConnection* implementation = reinterpret_cast<const RPC::IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->RemoteId();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual void* Acquire(const uint32_t, const string&, const uint32_t, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::IRemoteConnection* implementation = reinterpret_cast<RPC::IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _waitTime = reader.Number<uint32_t>();
            const string _className = reader.Text();
            const uint32_t _interfaceId = reader.Number<uint32_t>();
            const uint32_t _version = reader.Number<uint32_t>();

            void* result = implementation->Acquire(_waitTime, static_cast<const string&>(_className), _interfaceId, _version);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result, _interfaceId);
        },

        // (3) virtual void Terminate() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::IRemoteConnection* implementation = reinterpret_cast<RPC::IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Terminate();
        },

        // (4) virtual uint32_t Launch() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::IRemoteConnection* implementation = reinterpret_cast<RPC::IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Launch();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual void PostMortem() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::IRemoteConnection* implementation = reinterpret_cast<RPC::IRemoteConnection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->PostMortem();
        }
        , nullptr
    }; // RPCRemoteConnectionStubMethods

    //
    // RPC::IRemoteConnection::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Activated(RPC::IRemoteConnection*) = 0
    //  (1) virtual void Deactivated(RPC::IRemoteConnection*) = 0
    //  (2) virtual void Terminated(RPC::IRemoteConnection*)
    //

    static ProxyStub::MethodHandler RPCRemoteConnectionNotificationStubMethods[] = {
        // (0) virtual void Activated(RPC::IRemoteConnection*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::IRemoteConnection::INotification* implementation = reinterpret_cast<RPC::IRemoteConnection::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            RPC::IRemoteConnection* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            implementation->Activated(_parameter_1);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
            }
        },

        // (1) virtual void Deactivated(RPC::IRemoteConnection*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::IRemoteConnection::INotification* implementation = reinterpret_cast<RPC::IRemoteConnection::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            RPC::IRemoteConnection* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            implementation->Deactivated(_parameter_1);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
            }
        },

        // (2) virtual void Terminated(RPC::IRemoteConnection*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            RPC::IRemoteConnection::INotification* implementation = reinterpret_cast<RPC::IRemoteConnection::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            RPC::IRemoteConnection* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            implementation->Terminated(_parameter_1);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
            }
        }
        , nullptr
    }; // RPCRemoteConnectionNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IRemoteConnection interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Id() const = 0
    //  (1) virtual uint32_t RemoteId() const = 0
    //  (2) virtual void* Acquire(const uint32_t, const string&, const uint32_t, const uint32_t) = 0
    //  (3) virtual void Terminate() = 0
    //  (4) virtual uint32_t Launch() = 0
    //  (5) virtual void PostMortem() = 0
    //

    class RPCRemoteConnectionProxy final : public ProxyStub::UnknownProxyType<RPC::IRemoteConnection> {
    public:
        RPCRemoteConnectionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Id() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t RemoteId() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void* Acquire(const uint32_t _waitTime, const string& _className, const uint32_t _interfaceId, const uint32_t _version) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_waitTime);
            writer.Text(_className);
            writer.Number<uint32_t>(_interfaceId);
            writer.Number<uint32_t>(_version);

            void* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<void*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), _interfaceId));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Terminate() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        uint32_t Launch() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void PostMortem() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class RPCRemoteConnectionProxy

    //
    // RPC::IRemoteConnection::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Activated(RPC::IRemoteConnection*) = 0
    //  (1) virtual void Deactivated(RPC::IRemoteConnection*) = 0
    //  (2) virtual void Terminated(RPC::IRemoteConnection*)
    //

    class RPCRemoteConnectionNotificationProxy final : public ProxyStub::UnknownProxyType<RPC::IRemoteConnection::INotification> {
    public:
        RPCRemoteConnectionNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Activated(RPC::IRemoteConnection* _parameter_1) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Deactivated(RPC::IRemoteConnection* _parameter_1) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Terminated(RPC::IRemoteConnection* _parameter_1) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

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

    }; // class RPCRemoteConnectionNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IRemoteConnection, RPCRemoteConnectionStubMethods> RPCRemoteConnectionStub;
        typedef ProxyStub::UnknownStubType<RPC::IRemoteConnection::INotification, RPCRemoteConnectionNotificationStubMethods> RPCRemoteConnectionNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IRemoteConnection, RPCRemoteConnectionProxy, RPCRemoteConnectionStub>();
                RPC::Administrator::Instance().Announce<RPC::IRemoteConnection::INotification, RPCRemoteConnectionNotificationProxy, RPCRemoteConnectionNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IRemoteConnection>();
                RPC::Administrator::Instance().Recall<RPC::IRemoteConnection::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
