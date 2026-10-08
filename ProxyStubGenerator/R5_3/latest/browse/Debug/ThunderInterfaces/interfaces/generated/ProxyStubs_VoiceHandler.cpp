//
// generated automatically from "IVoiceHandler.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IVoiceProducer
//   - class Exchange::IVoiceProducer::IProfile
//   - class Exchange::IVoiceHandler
//

#include "Module.h"
#include "IVoiceHandler.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IVoiceProducer interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IVoiceHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeVoiceProducerStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVoiceProducer* implementation = reinterpret_cast<const Exchange::IVoiceProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual uint32_t Callback(Exchange::IVoiceHandler*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVoiceProducer* implementation = reinterpret_cast<Exchange::IVoiceProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IVoiceHandler* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            uint32_t result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t Error() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVoiceProducer* implementation = reinterpret_cast<const Exchange::IVoiceProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Error();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual string MetaData() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVoiceProducer* implementation = reinterpret_cast<const Exchange::IVoiceProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->MetaData();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual void Configure(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVoiceProducer* implementation = reinterpret_cast<Exchange::IVoiceProducer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _settings = reader.Text();

            implementation->Configure(static_cast<const string&>(_settings));
        }
        , nullptr
    }; // ExchangeVoiceProducerStubMethods

    //
    // Exchange::IVoiceProducer::IProfile interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IVoiceProducer::IProfile::codec Codec() const = 0
    //  (1) virtual uint8_t Channels() const = 0
    //  (2) virtual uint32_t SampleRate() const = 0
    //  (3) virtual uint8_t Resolution() const = 0
    //

    static ProxyStub::MethodHandler ExchangeVoiceProducerProfileStubMethods[] = {
        // (0) virtual Exchange::IVoiceProducer::IProfile::codec Codec() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVoiceProducer::IProfile* implementation = reinterpret_cast<const Exchange::IVoiceProducer::IProfile*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IVoiceProducer::IProfile::codec result = implementation->Codec();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IVoiceProducer::IProfile::codec>(result);
        },

        // (1) virtual uint8_t Channels() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVoiceProducer::IProfile* implementation = reinterpret_cast<const Exchange::IVoiceProducer::IProfile*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t result = implementation->Channels();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint8_t>(result);
        },

        // (2) virtual uint32_t SampleRate() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVoiceProducer::IProfile* implementation = reinterpret_cast<const Exchange::IVoiceProducer::IProfile*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->SampleRate();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint8_t Resolution() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IVoiceProducer::IProfile* implementation = reinterpret_cast<const Exchange::IVoiceProducer::IProfile*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t result = implementation->Resolution();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint8_t>(result);
        }
        , nullptr
    }; // ExchangeVoiceProducerProfileStubMethods

    //
    // Exchange::IVoiceHandler interface stub definitions
    //
    // Methods:
    //  (0) virtual void Start(const Exchange::IVoiceProducer::IProfile*) = 0
    //  (1) virtual void Stop() = 0
    //  (2) virtual void Data(const uint32_t, const uint8_t*, const uint16_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeVoiceHandlerStubMethods[] = {
        // (0) virtual void Start(const Exchange::IVoiceProducer::IProfile*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVoiceHandler* implementation = reinterpret_cast<Exchange::IVoiceHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _profileInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IVoiceProducer::IProfile* _profile{};
            ProxyStub::UnknownProxy* _profileProxy__ = nullptr;
            if (_profileInstanceId__ != 0) {
                _profileProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _profileInstanceId__, false, _profile);
                ASSERT((_profile != nullptr) && (_profileProxy__ != nullptr));
            }

            implementation->Start(_profile);

            if (_profileProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_profileProxy__, message->Response());
            }
        },

        // (1) virtual void Stop() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVoiceHandler* implementation = reinterpret_cast<Exchange::IVoiceHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Stop();
        },

        // (2) virtual void Data(const uint32_t, const uint8_t*, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVoiceHandler* implementation = reinterpret_cast<Exchange::IVoiceHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _sequenceNo = reader.Number<uint32_t>();
            const uint8_t* _data{};
            const uint16_t _length = reader.LockBuffer<uint16_t>(_data);
            reader.UnlockBuffer(_length);

            implementation->Data(_sequenceNo, _data, _length);
        }
        , nullptr
    }; // ExchangeVoiceHandlerStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IVoiceProducer interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual uint32_t Callback(Exchange::IVoiceHandler*) = 0
    //  (2) virtual uint32_t Error() const = 0
    //  (3) virtual string MetaData() const = 0
    //  (4) virtual void Configure(const string&) = 0
    //

    class ExchangeVoiceProducerProxy final : public ProxyStub::UnknownProxyType<Exchange::IVoiceProducer> {
    public:
        ExchangeVoiceProducerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string Name() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Callback(Exchange::IVoiceHandler* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

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

        uint32_t Error() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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

        string MetaData() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Configure(const string& _settings) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_settings);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

    }; // class ExchangeVoiceProducerProxy

    //
    // Exchange::IVoiceProducer::IProfile interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IVoiceProducer::IProfile::codec Codec() const = 0
    //  (1) virtual uint8_t Channels() const = 0
    //  (2) virtual uint32_t SampleRate() const = 0
    //  (3) virtual uint8_t Resolution() const = 0
    //

    class ExchangeVoiceProducerProfileProxy final : public ProxyStub::UnknownProxyType<Exchange::IVoiceProducer::IProfile> {
    public:
        ExchangeVoiceProducerProfileProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Exchange::IVoiceProducer::IProfile::codec Codec() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Exchange::IVoiceProducer::IProfile::codec result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IVoiceProducer::IProfile::codec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint8_t Channels() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint8_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t SampleRate() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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

        uint8_t Resolution() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint8_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeVoiceProducerProfileProxy

    //
    // Exchange::IVoiceHandler interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Start(const Exchange::IVoiceProducer::IProfile*) = 0
    //  (1) virtual void Stop() = 0
    //  (2) virtual void Data(const uint32_t, const uint8_t*, const uint16_t) = 0
    //

    class ExchangeVoiceHandlerProxy final : public ProxyStub::UnknownProxyType<Exchange::IVoiceHandler> {
    public:
        ExchangeVoiceHandlerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Start(const Exchange::IVoiceProducer::IProfile* _profile) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_profile));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Stop() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Data(const uint32_t _sequenceNo, const uint8_t* _data, const uint16_t _length) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_sequenceNo);
            writer.Buffer<uint16_t>(_length, _data);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

    }; // class ExchangeVoiceHandlerProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IVoiceProducer, ExchangeVoiceProducerStubMethods> ExchangeVoiceProducerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IVoiceProducer::IProfile, ExchangeVoiceProducerProfileStubMethods> ExchangeVoiceProducerProfileStub;
        typedef ProxyStub::UnknownStubType<Exchange::IVoiceHandler, ExchangeVoiceHandlerStubMethods> ExchangeVoiceHandlerStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IVoiceProducer, ExchangeVoiceProducerProxy, ExchangeVoiceProducerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IVoiceProducer::IProfile, ExchangeVoiceProducerProfileProxy, ExchangeVoiceProducerProfileStub>();
                RPC::Administrator::Instance().Announce<Exchange::IVoiceHandler, ExchangeVoiceHandlerProxy, ExchangeVoiceHandlerStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IVoiceProducer>();
                RPC::Administrator::Instance().Recall<Exchange::IVoiceProducer::IProfile>();
                RPC::Administrator::Instance().Recall<Exchange::IVoiceHandler>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
