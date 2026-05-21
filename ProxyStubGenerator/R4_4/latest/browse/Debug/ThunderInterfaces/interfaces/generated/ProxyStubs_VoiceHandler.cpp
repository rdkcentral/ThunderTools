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

namespace WPEFramework {

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

    ProxyStub::MethodHandler ExchangeVoiceProducerStubMethods[] = {
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
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IVoiceHandler* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            uint32_t result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
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

    ProxyStub::MethodHandler ExchangeVoiceProducerProfileStubMethods[] = {
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

    ProxyStub::MethodHandler ExchangeVoiceHandlerStubMethods[] = {
        // (0) virtual void Start(const Exchange::IVoiceProducer::IProfile*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IVoiceHandler* implementation = reinterpret_cast<Exchange::IVoiceHandler*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id profileImplementation = reader.Number<Core::instance_id>();

            Exchange::IVoiceProducer::IProfile* _profile = nullptr;
            ProxyStub::UnknownProxy* profileProxy = nullptr;
            if (profileImplementation != 0) {
                profileProxy = RPC::Administrator::Instance().ProxyInstance(channel, profileImplementation, false, _profile);

                ASSERT((_profile != nullptr) && (profileProxy != nullptr));
            }

            implementation->Start(_profile);

            if (profileProxy != nullptr) {
                RPC::Administrator::Instance().Release(profileProxy, message->Response());
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
            const uint16_t dataLen = reader.LockBuffer<uint16_t>(_data);
            reader.UnlockBuffer(dataLen);

            implementation->Data(_sequenceNo, _data, dataLen);
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

        string Name() const override
        {
            IPCMessage message(BaseClass::Message(0));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        uint32_t Callback(Exchange::IVoiceHandler* _callback) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Error() const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string MetaData() const override
        {
            IPCMessage message(BaseClass::Message(3));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Configure(const string& _settings) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_settings));

            UnknownProxyType::Invoke(message);
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

        Exchange::IVoiceProducer::IProfile::codec Codec() const override
        {
            IPCMessage message(BaseClass::Message(0));

            Exchange::IVoiceProducer::IProfile::codec result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IVoiceProducer::IProfile::codec>();

            return (result);
        }

        uint8_t Channels() const override
        {
            IPCMessage message(BaseClass::Message(1));

            uint8_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint8_t>();

            return (result);
        }

        uint32_t SampleRate() const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint8_t Resolution() const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint8_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint8_t>();

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

        void Start(const Exchange::IVoiceProducer::IProfile* _profile) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_profile));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Stop() override
        {
            IPCMessage message(BaseClass::Message(1));

            UnknownProxyType::Invoke(message);
        }

        void Data(const uint32_t _sequenceNo, const uint8_t* _data, const uint16_t dataLen) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_sequenceNo);
            writer.Buffer<uint16_t>(dataLen, _data);

            UnknownProxyType::Invoke(message);
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
