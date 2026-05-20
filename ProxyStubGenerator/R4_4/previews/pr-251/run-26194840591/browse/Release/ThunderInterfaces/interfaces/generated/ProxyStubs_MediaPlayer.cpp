//
// generated automatically from "IMediaPlayer.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IMediaPlayer
//   - class Exchange::IMediaPlayer::IMediaStream
//   - class Exchange::IMediaPlayer::IMediaStream::INotification
//

#include "Module.h"
#include "IMediaPlayer.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IMediaPlayer interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IMediaPlayer::IMediaStream* CreateStream(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeMediaPlayerStubMethods[] = {
        // (0) virtual Exchange::IMediaPlayer::IMediaStream* CreateStream(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer* implementation = reinterpret_cast<Exchange::IMediaPlayer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _id = reader.Text();

            Exchange::IMediaPlayer::IMediaStream* result = implementation->CreateStream(static_cast<const string&>(_id));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeMediaPlayerStubMethods

    //
    // Exchange::IMediaPlayer::IMediaStream interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Load(const string&, bool) = 0
    //  (1) virtual uint32_t SetRate(int32_t) = 0
    //  (2) virtual uint32_t SeekTo(int32_t) = 0
    //  (3) virtual uint32_t Stop() = 0
    //  (4) virtual uint32_t InitConfig(const string&) = 0
    //  (5) virtual uint32_t InitDRMConfig(const string&) = 0
    //  (6) virtual uint32_t Register(Exchange::IMediaPlayer::IMediaStream::INotification*) = 0
    //  (7) virtual uint32_t Unregister(Exchange::IMediaPlayer::IMediaStream::INotification*) = 0
    //

    ProxyStub::MethodHandler ExchangeMediaPlayerMediaStreamStubMethods[] = {
        // (0) virtual uint32_t Load(const string&, bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _url = reader.Text();
            bool _autoPlay = reader.Boolean();

            uint32_t result = implementation->Load(static_cast<const string&>(_url), _autoPlay);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t SetRate(int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            int32_t _rate = reader.Number<int32_t>();

            uint32_t result = implementation->SetRate(_rate);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t SeekTo(int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            int32_t _positionSec = reader.Number<int32_t>();

            uint32_t result = implementation->SeekTo(_positionSec);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Stop() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Stop();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t InitConfig(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _configurationJson = reader.Text();

            uint32_t result = implementation->InitConfig(static_cast<const string&>(_configurationJson));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t InitDRMConfig(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _configurationJson = reader.Text();

            uint32_t result = implementation->InitDRMConfig(static_cast<const string&>(_configurationJson));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t Register(Exchange::IMediaPlayer::IMediaStream::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IMediaPlayer::IMediaStream::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            uint32_t result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (7) virtual uint32_t Unregister(Exchange::IMediaPlayer::IMediaStream::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IMediaPlayer::IMediaStream::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            uint32_t result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeMediaPlayerMediaStreamStubMethods

    //
    // Exchange::IMediaPlayer::IMediaStream::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Event(const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeMediaPlayerMediaStreamNotificationStubMethods[] = {
        // (0) virtual void Event(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream::INotification* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _eventName = reader.Text();
            const string _parametersJson = reader.Text();

            implementation->Event(static_cast<const string&>(_eventName), static_cast<const string&>(_parametersJson));
        }
        , nullptr
    }; // ExchangeMediaPlayerMediaStreamNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IMediaPlayer interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IMediaPlayer::IMediaStream* CreateStream(const string&) = 0
    //

    class ExchangeMediaPlayerProxy final : public ProxyStub::UnknownProxyType<Exchange::IMediaPlayer> {
    public:
        ExchangeMediaPlayerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::IMediaPlayer::IMediaStream* CreateStream(const string& _id) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_id));

            Exchange::IMediaPlayer::IMediaStream* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(Interface(reader.Number<Core::instance_id>(), Exchange::IMediaPlayer::IMediaStream::ID));

            return (result);
        }

    }; // class ExchangeMediaPlayerProxy

    //
    // Exchange::IMediaPlayer::IMediaStream interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Load(const string&, bool) = 0
    //  (1) virtual uint32_t SetRate(int32_t) = 0
    //  (2) virtual uint32_t SeekTo(int32_t) = 0
    //  (3) virtual uint32_t Stop() = 0
    //  (4) virtual uint32_t InitConfig(const string&) = 0
    //  (5) virtual uint32_t InitDRMConfig(const string&) = 0
    //  (6) virtual uint32_t Register(Exchange::IMediaPlayer::IMediaStream::INotification*) = 0
    //  (7) virtual uint32_t Unregister(Exchange::IMediaPlayer::IMediaStream::INotification*) = 0
    //

    class ExchangeMediaPlayerMediaStreamProxy final : public ProxyStub::UnknownProxyType<Exchange::IMediaPlayer::IMediaStream> {
    public:
        ExchangeMediaPlayerMediaStreamProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Load(const string& _url, bool _autoPlay) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_url));
            writer.Boolean(_autoPlay);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t SetRate(int32_t _rate) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_rate);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t SeekTo(int32_t _positionSec) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_positionSec);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Stop() override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t InitConfig(const string& _configurationJson) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_configurationJson));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t InitDRMConfig(const string& _configurationJson) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_configurationJson));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Register(Exchange::IMediaPlayer::IMediaStream::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Unregister(Exchange::IMediaPlayer::IMediaStream::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

    }; // class ExchangeMediaPlayerMediaStreamProxy

    //
    // Exchange::IMediaPlayer::IMediaStream::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Event(const string&, const string&) = 0
    //

    class ExchangeMediaPlayerMediaStreamNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IMediaPlayer::IMediaStream::INotification> {
    public:
        ExchangeMediaPlayerMediaStreamNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Event(const string& _eventName, const string& _parametersJson) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_eventName));
            writer.Text(static_cast<const string&>(_parametersJson));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeMediaPlayerMediaStreamNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IMediaPlayer, ExchangeMediaPlayerStubMethods> ExchangeMediaPlayerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IMediaPlayer::IMediaStream, ExchangeMediaPlayerMediaStreamStubMethods> ExchangeMediaPlayerMediaStreamStub;
        typedef ProxyStub::UnknownStubType<Exchange::IMediaPlayer::IMediaStream::INotification, ExchangeMediaPlayerMediaStreamNotificationStubMethods> ExchangeMediaPlayerMediaStreamNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IMediaPlayer, ExchangeMediaPlayerProxy, ExchangeMediaPlayerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IMediaPlayer::IMediaStream, ExchangeMediaPlayerMediaStreamProxy, ExchangeMediaPlayerMediaStreamStub>();
                RPC::Administrator::Instance().Announce<Exchange::IMediaPlayer::IMediaStream::INotification, ExchangeMediaPlayerMediaStreamNotificationProxy, ExchangeMediaPlayerMediaStreamNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IMediaPlayer>();
                RPC::Administrator::Instance().Recall<Exchange::IMediaPlayer::IMediaStream>();
                RPC::Administrator::Instance().Recall<Exchange::IMediaPlayer::IMediaStream::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
