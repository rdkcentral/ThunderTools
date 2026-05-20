//
// generated automatically from "IPlayerInfo.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IPlayerProperties::AudioCodec, INTERFACE_ID = Exchange::ID_PLAYER_PROPERTIES_AUDIO]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IPlayerProperties::VideoCodec, INTERFACE_ID = Exchange::ID_PLAYER_PROPERTIES_VIDEO]
//   - class Exchange::IPlayerProperties
//

#include "Module.h"
#include "IPlayerInfo.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstanceDAE78555 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::AudioCodec Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceDAE78555StubMethods[] = {
        // (0) virtual bool Next(Exchange::IPlayerProperties::AudioCodec&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::AudioCodec _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IPlayerProperties::AudioCodec>(_info);
        },

        // (1) virtual bool Previous(Exchange::IPlayerProperties::AudioCodec&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::AudioCodec _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IPlayerProperties::AudioCodec>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IPlayerProperties::AudioCodec Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::AudioCodec result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IPlayerProperties::AudioCodec>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstanceDAE78555StubMethods

    //
    // RPC::IIteratorTypeInstance788C84FF interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::VideoCodec Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance788C84FFStubMethods[] = {
        // (0) virtual bool Next(Exchange::IPlayerProperties::VideoCodec&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::VideoCodec _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IPlayerProperties::VideoCodec>(_info);
        },

        // (1) virtual bool Previous(Exchange::IPlayerProperties::VideoCodec&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::VideoCodec _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IPlayerProperties::VideoCodec>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IPlayerProperties::VideoCodec Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::VideoCodec result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IPlayerProperties::VideoCodec>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance788C84FFStubMethods

    //
    // Exchange::IPlayerProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t AudioCodecs(Exchange::IPlayerProperties::IAudioCodecIterator*&) const = 0
    //  (1) virtual uint32_t VideoCodecs(Exchange::IPlayerProperties::IVideoCodecIterator*&) const = 0
    //  (2) virtual uint32_t Resolution(Exchange::IPlayerProperties::PlaybackResolution&) const = 0
    //  (3) virtual uint32_t IsAudioEquivalenceEnabled(bool&) const = 0
    //

    ProxyStub::MethodHandler ExchangePlayerPropertiesStubMethods[] = {
        // (0) virtual uint32_t AudioCodecs(Exchange::IPlayerProperties::IAudioCodecIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPlayerProperties* implementation = reinterpret_cast<const Exchange::IPlayerProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::IAudioCodecIterator* _codec{};

            uint32_t result = implementation->AudioCodecs(_codec);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_codec));

            RPC::Administrator::Instance().RegisterInterface(channel, _codec);
        },

        // (1) virtual uint32_t VideoCodecs(Exchange::IPlayerProperties::IVideoCodecIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPlayerProperties* implementation = reinterpret_cast<const Exchange::IPlayerProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::IVideoCodecIterator* _codec{};

            uint32_t result = implementation->VideoCodecs(_codec);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_codec));

            RPC::Administrator::Instance().RegisterInterface(channel, _codec);
        },

        // (2) virtual uint32_t Resolution(Exchange::IPlayerProperties::PlaybackResolution&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPlayerProperties* implementation = reinterpret_cast<const Exchange::IPlayerProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPlayerProperties::PlaybackResolution _res{};

            uint32_t result = implementation->Resolution(_res);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IPlayerProperties::PlaybackResolution>(_res);
        },

        // (3) virtual uint32_t IsAudioEquivalenceEnabled(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPlayerProperties* implementation = reinterpret_cast<const Exchange::IPlayerProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _ae{};

            uint32_t result = implementation->IsAudioEquivalenceEnabled(_ae);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_ae);
        }
        , nullptr
    }; // ExchangePlayerPropertiesStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstanceDAE78555 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::AudioCodec Current() const = 0
    //

    class RPCIteratorTypeInstanceDAE78555Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>> {
    public:
        RPCIteratorTypeInstanceDAE78555Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IPlayerProperties::AudioCodec& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IPlayerProperties::AudioCodec>();

            return (result);
        }

        bool Previous(Exchange::IPlayerProperties::AudioCodec& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IPlayerProperties::AudioCodec>();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IPlayerProperties::AudioCodec Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IPlayerProperties::AudioCodec result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IPlayerProperties::AudioCodec>();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceDAE78555Proxy

    //
    // RPC::IIteratorTypeInstance788C84FF interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::VideoCodec Current() const = 0
    //

    class RPCIteratorTypeInstance788C84FFProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>> {
    public:
        RPCIteratorTypeInstance788C84FFProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IPlayerProperties::VideoCodec& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IPlayerProperties::VideoCodec>();

            return (result);
        }

        bool Previous(Exchange::IPlayerProperties::VideoCodec& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IPlayerProperties::VideoCodec>();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IPlayerProperties::VideoCodec Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IPlayerProperties::VideoCodec result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IPlayerProperties::VideoCodec>();

            return (result);
        }

    }; // class RPCIteratorTypeInstance788C84FFProxy

    //
    // Exchange::IPlayerProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t AudioCodecs(Exchange::IPlayerProperties::IAudioCodecIterator*&) const = 0
    //  (1) virtual uint32_t VideoCodecs(Exchange::IPlayerProperties::IVideoCodecIterator*&) const = 0
    //  (2) virtual uint32_t Resolution(Exchange::IPlayerProperties::PlaybackResolution&) const = 0
    //  (3) virtual uint32_t IsAudioEquivalenceEnabled(bool&) const = 0
    //

    class ExchangePlayerPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IPlayerProperties> {
    public:
        ExchangePlayerPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t AudioCodecs(Exchange::IPlayerProperties::IAudioCodecIterator*& _codec) const override
        {
            IPCMessage message(BaseClass::Message(0));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _codec = reinterpret_cast<Exchange::IPlayerProperties::IAudioCodecIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IPlayerProperties::IAudioCodecIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t VideoCodecs(Exchange::IPlayerProperties::IVideoCodecIterator*& _codec) const override
        {
            IPCMessage message(BaseClass::Message(1));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _codec = reinterpret_cast<Exchange::IPlayerProperties::IVideoCodecIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IPlayerProperties::IVideoCodecIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Resolution(Exchange::IPlayerProperties::PlaybackResolution& _res) const override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _res = reader.Number<Exchange::IPlayerProperties::PlaybackResolution>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t IsAudioEquivalenceEnabled(bool& _ae) const override
        {
            IPCMessage message(BaseClass::Message(3));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _ae = reader.Boolean();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangePlayerPropertiesProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>, RPCIteratorTypeInstanceDAE78555StubMethods> RPCIteratorTypeInstanceDAE78555Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>, RPCIteratorTypeInstance788C84FFStubMethods> RPCIteratorTypeInstance788C84FFStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPlayerProperties, ExchangePlayerPropertiesStubMethods> ExchangePlayerPropertiesStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>, RPCIteratorTypeInstanceDAE78555Proxy, RPCIteratorTypeInstanceDAE78555Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>, RPCIteratorTypeInstance788C84FFProxy, RPCIteratorTypeInstance788C84FFStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPlayerProperties, ExchangePlayerPropertiesProxy, ExchangePlayerPropertiesStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>>();
                RPC::Administrator::Instance().Recall<Exchange::IPlayerProperties>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
