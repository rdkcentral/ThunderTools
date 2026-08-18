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

namespace Thunder {

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

    static ProxyStub::MethodHandler ExchangeMediaPlayerStubMethods[] = {
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

    static ProxyStub::MethodHandler ExchangeMediaPlayerMediaStreamStubMethods[] = {
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
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IMediaPlayer::IMediaStream::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            uint32_t result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (7) virtual uint32_t Unregister(Exchange::IMediaPlayer::IMediaStream::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMediaPlayer::IMediaStream* implementation = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IMediaPlayer::IMediaStream::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            uint32_t result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
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

    static ProxyStub::MethodHandler ExchangeMediaPlayerMediaStreamNotificationStubMethods[] = {
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

        Exchange::IMediaPlayer::IMediaStream* CreateStream(const string& _id) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_id);

            Exchange::IMediaPlayer::IMediaStream* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IMediaPlayer::IMediaStream*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IMediaPlayer::IMediaStream::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

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

        uint32_t Load(const string& _url, bool _autoPlay) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_url);
            writer.Boolean(_autoPlay);

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

        uint32_t SetRate(int32_t _rate) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_rate);

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

        uint32_t SeekTo(int32_t _positionSec) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_positionSec);

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

        uint32_t Stop() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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

        uint32_t InitConfig(const string& _configurationJson) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_configurationJson);

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

        uint32_t InitDRMConfig(const string& _configurationJson) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_configurationJson);

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

        uint32_t Register(Exchange::IMediaPlayer::IMediaStream::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Unregister(Exchange::IMediaPlayer::IMediaStream::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();

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

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

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

        void Event(const string& _eventName, const string& _parametersJson) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_eventName);
            writer.Text(_parametersJson);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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
