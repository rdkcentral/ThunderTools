//
// generated automatically from "IPlayerInfo.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IPlayerProperties::AudioCodec, INTERFACE_ID = Exchange::ID_PLAYER_PROPERTIES_AUDIO] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IPlayerProperties::VideoCodec, INTERFACE_ID = Exchange::ID_PLAYER_PROPERTIES_VIDEO] [[iterator]]
//   - class Exchange::IPlayerProperties
//

#include "Module.h"
#include "IPlayerInfo.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_0169caca45928b69 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::AudioCodec Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_0169caca45928b69StubMethods[] = {
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
    }; // RPCIteratorTypeInstance_0169caca45928b69StubMethods

    //
    // RPC::IIteratorTypeInstance_5574229b507eba30 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::VideoCodec Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_5574229b507eba30StubMethods[] = {
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
    }; // RPCIteratorTypeInstance_5574229b507eba30StubMethods

    //
    // Exchange::IPlayerProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t AudioCodecs(Exchange::IPlayerProperties::IAudioCodecIterator*&) const = 0
    //  (1) virtual uint32_t VideoCodecs(Exchange::IPlayerProperties::IVideoCodecIterator*&) const = 0
    //  (2) virtual uint32_t Resolution(Exchange::IPlayerProperties::PlaybackResolution&) const = 0
    //  (3) virtual uint32_t IsAudioEquivalenceEnabled(bool&) const = 0
    //

    static ProxyStub::MethodHandler ExchangePlayerPropertiesStubMethods[] = {
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
    // RPC::IIteratorTypeInstance_0169caca45928b69 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::AudioCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::AudioCodec Current() const = 0
    //

    class RPCIteratorTypeInstance_0169caca45928b69Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>> {
    public:
        RPCIteratorTypeInstance_0169caca45928b69Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IPlayerProperties::AudioCodec& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IPlayerProperties::AudioCodec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IPlayerProperties::AudioCodec& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IPlayerProperties::AudioCodec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
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

        Exchange::IPlayerProperties::AudioCodec Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IPlayerProperties::AudioCodec result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IPlayerProperties::AudioCodec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_0169caca45928b69Proxy

    //
    // RPC::IIteratorTypeInstance_5574229b507eba30 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (1) virtual bool Previous(Exchange::IPlayerProperties::VideoCodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPlayerProperties::VideoCodec Current() const = 0
    //

    class RPCIteratorTypeInstance_5574229b507eba30Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>> {
    public:
        RPCIteratorTypeInstance_5574229b507eba30Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IPlayerProperties::VideoCodec& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IPlayerProperties::VideoCodec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IPlayerProperties::VideoCodec& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IPlayerProperties::VideoCodec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
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

        Exchange::IPlayerProperties::VideoCodec Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IPlayerProperties::VideoCodec result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IPlayerProperties::VideoCodec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_5574229b507eba30Proxy

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

        uint32_t AudioCodecs(Exchange::IPlayerProperties::IAudioCodecIterator*& _codec) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _codec = reinterpret_cast<Exchange::IPlayerProperties::IAudioCodecIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IPlayerProperties::IAudioCodecIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t VideoCodecs(Exchange::IPlayerProperties::IVideoCodecIterator*& _codec) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _codec = reinterpret_cast<Exchange::IPlayerProperties::IVideoCodecIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IPlayerProperties::IVideoCodecIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Resolution(Exchange::IPlayerProperties::PlaybackResolution& _res) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _res = reader.Number<Exchange::IPlayerProperties::PlaybackResolution>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t IsAudioEquivalenceEnabled(bool& _ae) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _ae = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>, RPCIteratorTypeInstance_0169caca45928b69StubMethods> RPCIteratorTypeInstance_0169caca45928b69Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>, RPCIteratorTypeInstance_5574229b507eba30StubMethods> RPCIteratorTypeInstance_5574229b507eba30Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IPlayerProperties, ExchangePlayerPropertiesStubMethods> ExchangePlayerPropertiesStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IPlayerProperties::AudioCodec, Exchange::ID_PLAYER_PROPERTIES_AUDIO>, RPCIteratorTypeInstance_0169caca45928b69Proxy, RPCIteratorTypeInstance_0169caca45928b69Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IPlayerProperties::VideoCodec, Exchange::ID_PLAYER_PROPERTIES_VIDEO>, RPCIteratorTypeInstance_5574229b507eba30Proxy, RPCIteratorTypeInstance_5574229b507eba30Stub>();
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
