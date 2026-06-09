//
// generated automatically from "IMessenger.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IRoomAdministrator
//   - class Exchange::IRoomAdministrator::INotification
//   - class Exchange::IRoomAdministrator::IRoom
//   - class Exchange::IRoomAdministrator::IRoom::ICallback
//   - class Exchange::IRoomAdministrator::IRoom::IMsgNotification
//

#include "Module.h"
#include "IMessenger.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS TEST
    // -----------------------------------------------------------------

    //
    // Exchange::IRoomAdministrator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IRoomAdministrator::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IRoomAdministrator::INotification*) = 0
    //  (2) virtual Exchange::IRoomAdministrator::IRoom* Join(const string&, const string&, Exchange::IRoomAdministrator::IRoom::IMsgNotification*) = 0
    //

    static ProxyStub::MethodHandler ExchangeRoomAdministratorStubMethods[] = {
        // (0) virtual void Register(Exchange::IRoomAdministrator::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator* implementation = reinterpret_cast<Exchange::IRoomAdministrator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IRoomAdministrator::INotification* _sink{};
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

        // (1) virtual void Unregister(const Exchange::IRoomAdministrator::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator* implementation = reinterpret_cast<Exchange::IRoomAdministrator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IRoomAdministrator::INotification* _sink{};
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

        // (2) virtual Exchange::IRoomAdministrator::IRoom* Join(const string&, const string&, Exchange::IRoomAdministrator::IRoom::IMsgNotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator* implementation = reinterpret_cast<Exchange::IRoomAdministrator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _roomId = reader.Text();
            const string _userId = reader.Text();
            Core::instance_id _messageSinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IRoomAdministrator::IRoom::IMsgNotification* _messageSink{};
            ProxyStub::UnknownProxy* _messageSinkProxy__ = nullptr;
            if (_messageSinkInstanceId__ != 0) {
                _messageSinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _messageSinkInstanceId__, false, _messageSink);
                ASSERT((_messageSink != nullptr) && (_messageSinkProxy__ != nullptr));
            }

            Exchange::IRoomAdministrator::IRoom* result = implementation->Join(static_cast<const string&>(_roomId), static_cast<const string&>(_userId), _messageSink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            if (_messageSinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_messageSinkProxy__, message->Response());
            }

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeRoomAdministratorStubMethods

    //
    // Exchange::IRoomAdministrator::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&) = 0
    //  (1) virtual void Destroyed(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeRoomAdministratorNotificationStubMethods[] = {
        // (0) virtual void Created(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator::INotification* implementation = reinterpret_cast<Exchange::IRoomAdministrator::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _id = reader.Text();

            implementation->Created(static_cast<const string&>(_id));
        },

        // (1) virtual void Destroyed(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator::INotification* implementation = reinterpret_cast<Exchange::IRoomAdministrator::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _id = reader.Text();

            implementation->Destroyed(static_cast<const string&>(_id));
        }
        , nullptr
    }; // ExchangeRoomAdministratorNotificationStubMethods

    //
    // Exchange::IRoomAdministrator::IRoom interface stub definitions
    //
    // Methods:
    //  (0) virtual void SendMessage(const string&) = 0
    //  (1) virtual void SetCallback(Exchange::IRoomAdministrator::IRoom::ICallback*) = 0
    //

    static ProxyStub::MethodHandler ExchangeRoomAdministratorRoomStubMethods[] = {
        // (0) virtual void SendMessage(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator::IRoom* implementation = reinterpret_cast<Exchange::IRoomAdministrator::IRoom*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _message = reader.Text();

            implementation->SendMessage(static_cast<const string&>(_message));
        },

        // (1) virtual void SetCallback(Exchange::IRoomAdministrator::IRoom::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator::IRoom* implementation = reinterpret_cast<Exchange::IRoomAdministrator::IRoom*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IRoomAdministrator::IRoom::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            implementation->SetCallback(_callback);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExchangeRoomAdministratorRoomStubMethods

    //
    // Exchange::IRoomAdministrator::IRoom::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Joined(const string&) = 0
    //  (1) virtual void Left(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeRoomAdministratorRoomCallbackStubMethods[] = {
        // (0) virtual void Joined(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator::IRoom::ICallback* implementation = reinterpret_cast<Exchange::IRoomAdministrator::IRoom::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _userId = reader.Text();

            implementation->Joined(static_cast<const string&>(_userId));
        },

        // (1) virtual void Left(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator::IRoom::ICallback* implementation = reinterpret_cast<Exchange::IRoomAdministrator::IRoom::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _userId = reader.Text();

            implementation->Left(static_cast<const string&>(_userId));
        }
        , nullptr
    }; // ExchangeRoomAdministratorRoomCallbackStubMethods

    //
    // Exchange::IRoomAdministrator::IRoom::IMsgNotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Message(const string&, const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeRoomAdministratorRoomMsgNotificationStubMethods[] = {
        // (0) virtual void Message(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRoomAdministrator::IRoom::IMsgNotification* implementation = reinterpret_cast<Exchange::IRoomAdministrator::IRoom::IMsgNotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _message = reader.Text();
            const string _userId = reader.Text();

            implementation->Message(static_cast<const string&>(_message), static_cast<const string&>(_userId));
        }
        , nullptr
    }; // ExchangeRoomAdministratorRoomMsgNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IRoomAdministrator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IRoomAdministrator::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IRoomAdministrator::INotification*) = 0
    //  (2) virtual Exchange::IRoomAdministrator::IRoom* Join(const string&, const string&, Exchange::IRoomAdministrator::IRoom::IMsgNotification*) = 0
    //

    class ExchangeRoomAdministratorProxy final : public ProxyStub::UnknownProxyType<Exchange::IRoomAdministrator> {
    public:
        ExchangeRoomAdministratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::IRoomAdministrator::INotification* _sink) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(const Exchange::IRoomAdministrator::INotification* _sink) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        Exchange::IRoomAdministrator::IRoom* Join(const string& _roomId, const string& _userId, Exchange::IRoomAdministrator::IRoom::IMsgNotification* _messageSink) override
        {
            IPCMessage message(UnknownProxyType::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_roomId);
            writer.Text(_userId);
            writer.Number<Core::instance_id>(RPC::instance_cast(_messageSink));

            Exchange::IRoomAdministrator::IRoom* result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IRoomAdministrator::IRoom*>(UnknownProxyType::Interface(reader.Number<Core::instance_id>(), Exchange::IRoomAdministrator::IRoom::ID));

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

    }; // class ExchangeRoomAdministratorProxy

    //
    // Exchange::IRoomAdministrator::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&) = 0
    //  (1) virtual void Destroyed(const string&) = 0
    //

    class ExchangeRoomAdministratorNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IRoomAdministrator::INotification> {
    public:
        ExchangeRoomAdministratorNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Created(const string& _id) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_id);

            UnknownProxyType::Invoke(message);
        }

        void Destroyed(const string& _id) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_id);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeRoomAdministratorNotificationProxy

    //
    // Exchange::IRoomAdministrator::IRoom interface proxy definitions
    //
    // Methods:
    //  (0) virtual void SendMessage(const string&) = 0
    //  (1) virtual void SetCallback(Exchange::IRoomAdministrator::IRoom::ICallback*) = 0
    //

    class ExchangeRoomAdministratorRoomProxy final : public ProxyStub::UnknownProxyType<Exchange::IRoomAdministrator::IRoom> {
    public:
        ExchangeRoomAdministratorRoomProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void SendMessage(const string& _message) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_message);

            UnknownProxyType::Invoke(message);
        }

        void SetCallback(Exchange::IRoomAdministrator::IRoom::ICallback* _callback) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

    }; // class ExchangeRoomAdministratorRoomProxy

    //
    // Exchange::IRoomAdministrator::IRoom::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Joined(const string&) = 0
    //  (1) virtual void Left(const string&) = 0
    //

    class ExchangeRoomAdministratorRoomCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IRoomAdministrator::IRoom::ICallback> {
    public:
        ExchangeRoomAdministratorRoomCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Joined(const string& _userId) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_userId);

            UnknownProxyType::Invoke(message);
        }

        void Left(const string& _userId) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_userId);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeRoomAdministratorRoomCallbackProxy

    //
    // Exchange::IRoomAdministrator::IRoom::IMsgNotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Message(const string&, const string&) = 0
    //

    class ExchangeRoomAdministratorRoomMsgNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IRoomAdministrator::IRoom::IMsgNotification> {
    public:
        ExchangeRoomAdministratorRoomMsgNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Message(const string& _message, const string& _userId) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_message);
            writer.Text(_userId);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeRoomAdministratorRoomMsgNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IRoomAdministrator, ExchangeRoomAdministratorStubMethods> ExchangeRoomAdministratorStub;
        typedef ProxyStub::UnknownStubType<Exchange::IRoomAdministrator::INotification, ExchangeRoomAdministratorNotificationStubMethods> ExchangeRoomAdministratorNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IRoomAdministrator::IRoom, ExchangeRoomAdministratorRoomStubMethods> ExchangeRoomAdministratorRoomStub;
        typedef ProxyStub::UnknownStubType<Exchange::IRoomAdministrator::IRoom::ICallback, ExchangeRoomAdministratorRoomCallbackStubMethods> ExchangeRoomAdministratorRoomCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::IRoomAdministrator::IRoom::IMsgNotification, ExchangeRoomAdministratorRoomMsgNotificationStubMethods> ExchangeRoomAdministratorRoomMsgNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IRoomAdministrator, ExchangeRoomAdministratorProxy, ExchangeRoomAdministratorStub>();
                RPC::Administrator::Instance().Announce<Exchange::IRoomAdministrator::INotification, ExchangeRoomAdministratorNotificationProxy, ExchangeRoomAdministratorNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IRoomAdministrator::IRoom, ExchangeRoomAdministratorRoomProxy, ExchangeRoomAdministratorRoomStub>();
                RPC::Administrator::Instance().Announce<Exchange::IRoomAdministrator::IRoom::ICallback, ExchangeRoomAdministratorRoomCallbackProxy, ExchangeRoomAdministratorRoomCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::IRoomAdministrator::IRoom::IMsgNotification, ExchangeRoomAdministratorRoomMsgNotificationProxy, ExchangeRoomAdministratorRoomMsgNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IRoomAdministrator>();
                RPC::Administrator::Instance().Recall<Exchange::IRoomAdministrator::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IRoomAdministrator::IRoom>();
                RPC::Administrator::Instance().Recall<Exchange::IRoomAdministrator::IRoom::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::IRoomAdministrator::IRoom::IMsgNotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
