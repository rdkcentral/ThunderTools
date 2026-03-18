//
// generated automatically from "ITextToSpeech.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = uint32_t, INTERFACE_ID = RPC::ID_VALUEITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = RPC::Environment, INTERFACE_ID = RPC::ID_ENVIRONMENTITERATOR] [[iterator]]
//   - class Exchange::ITextToSpeech
//   - class Exchange::ITextToSpeech::INotification
//

#include "Module.h"
#include "ITextToSpeech.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_bd6e04b8d151c1f7 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_bd6e04b8d151c1f7StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_bd6e04b8d151c1f7StubMethods

    //
    // RPC::IIteratorTypeInstance_60eba5a793c685ea interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(uint32_t&) = 0
    //  (1) virtual bool Previous(uint32_t&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual uint32_t Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_60eba5a793c685eaStubMethods[] = {
        // (0) virtual bool Next(uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<uint32_t>(_info);
        },

        // (1) virtual bool Previous(uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<uint32_t>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_60eba5a793c685eaStubMethods

    //
    // RPC::IIteratorTypeInstance_195e88cf7f955a2e interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(RPC::Environment&) = 0
    //  (1) virtual bool Previous(RPC::Environment&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual RPC::Environment Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_195e88cf7f955a2eStubMethods[] = {
        // (0) virtual bool Next(RPC::Environment&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Environment _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.Key);
            writer.Text(_info.Value);
            writer.Number<RPC::Environment::scope>(_info.Scope);
        },

        // (1) virtual bool Previous(RPC::Environment&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Environment _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.Key);
            writer.Text(_info.Value);
            writer.Number<RPC::Environment::scope>(_info.Scope);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual RPC::Environment Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Environment result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result.Key);
            writer.Text(result.Value);
            writer.Number<RPC::Environment::scope>(result.Scope);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_195e88cf7f955a2eStubMethods

    //
    // Exchange::ITextToSpeech interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::ITextToSpeech::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::ITextToSpeech::INotification*) = 0
    //  (2) virtual uint32_t Enable(const bool) = 0
    //  (3) virtual uint32_t Enable(bool&) const = 0
    //  (4) virtual uint32_t SetConfiguration(const Exchange::ITextToSpeech::Configuration&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (5) virtual uint32_t SetFallbackText(const string, const string) = 0
    //  (6) virtual uint32_t SetAPIKey(const string) = 0
    //  (7) virtual uint32_t SetPrimaryVolDuck(const uint8_t) = 0
    //  (8) virtual uint32_t SetACL(const string, const string) = 0
    //  (9) virtual uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration&) const = 0
    //  (10) virtual uint32_t ListVoices(const string, RPC::IStringIterator*&) const = 0
    //  (11) virtual uint32_t Speak(const string, const string, uint32_t&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (12) virtual uint32_t Cancel(const uint32_t) = 0
    //  (13) virtual uint32_t Pause(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (14) virtual uint32_t Resume(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (15) virtual uint32_t GetSpeechState(const uint32_t, Exchange::ITextToSpeech::SpeechState&) = 0
    //

    static ProxyStub::MethodHandler ExchangeTextToSpeechStubMethods[] = {
        // (0) virtual void Register(Exchange::ITextToSpeech::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ITextToSpeech::INotification* _sink{};
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

        // (1) virtual void Unregister(Exchange::ITextToSpeech::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ITextToSpeech::INotification* _sink{};
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

        // (2) virtual uint32_t Enable(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _enable = reader.Boolean();

            uint32_t result = implementation->Enable(_enable);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Enable(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITextToSpeech* implementation = reinterpret_cast<const Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _enable{};

            uint32_t result = implementation->Enable(_enable);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_enable);
        },

        // (4) virtual uint32_t SetConfiguration(const Exchange::ITextToSpeech::Configuration&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::ITextToSpeech::Configuration _config{};
            _config.ttsEndPoint = reader.Text();
            _config.ttsEndPointSecured = reader.Text();
            _config.language = reader.Text();
            _config.voice = reader.Text();
            _config.speechRate = reader.Text();
            _config.volume = reader.Number<uint8_t>();
            _config.rate = reader.Number<uint8_t>();

            Exchange::ITextToSpeech::TTSErrorDetail _status{};

            uint32_t result = implementation->SetConfiguration(static_cast<const Exchange::ITextToSpeech::Configuration&>(_config), _status);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::ITextToSpeech::TTSErrorDetail>(_status);
        },

        // (5) virtual uint32_t SetFallbackText(const string, const string) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _scenario = reader.Text();
            const string _value = reader.Text();

            uint32_t result = implementation->SetFallbackText(_scenario, _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t SetAPIKey(const string) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _apikey = reader.Text();

            uint32_t result = implementation->SetAPIKey(_apikey);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t SetPrimaryVolDuck(const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _prim = reader.Number<uint8_t>();

            uint32_t result = implementation->SetPrimaryVolDuck(_prim);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (8) virtual uint32_t SetACL(const string, const string) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _method = reader.Text();
            const string _apps = reader.Text();

            uint32_t result = implementation->SetACL(_method, _apps);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITextToSpeech* implementation = reinterpret_cast<const Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ITextToSpeech::Configuration _config{};

            uint32_t result = implementation->GetConfiguration(_config);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_config.ttsEndPoint);
            writer.Text(_config.ttsEndPointSecured);
            writer.Text(_config.language);
            writer.Text(_config.voice);
            writer.Text(_config.speechRate);
            writer.Number<uint8_t>(_config.volume);
            writer.Number<uint8_t>(_config.rate);
        },

        // (10) virtual uint32_t ListVoices(const string, RPC::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITextToSpeech* implementation = reinterpret_cast<const Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _language = reader.Text();

            RPC::IStringIterator* _voices{};

            uint32_t result = implementation->ListVoices(_language, _voices);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_voices));

            RPC::Administrator::Instance().RegisterInterface(channel, _voices);
        },

        // (11) virtual uint32_t Speak(const string, const string, uint32_t&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const string _text = reader.Text();

            uint32_t _speechid{};
            Exchange::ITextToSpeech::TTSErrorDetail _status{};

            uint32_t result = implementation->Speak(_callsign, _text, _speechid, _status);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_speechid);
            writer.Number<Exchange::ITextToSpeech::TTSErrorDetail>(_status);
        },

        // (12) virtual uint32_t Cancel(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            uint32_t result = implementation->Cancel(_speechid);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (13) virtual uint32_t Pause(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            Exchange::ITextToSpeech::TTSErrorDetail _status{};

            uint32_t result = implementation->Pause(_speechid, _status);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::ITextToSpeech::TTSErrorDetail>(_status);
        },

        // (14) virtual uint32_t Resume(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            Exchange::ITextToSpeech::TTSErrorDetail _status{};

            uint32_t result = implementation->Resume(_speechid, _status);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::ITextToSpeech::TTSErrorDetail>(_status);
        },

        // (15) virtual uint32_t GetSpeechState(const uint32_t, Exchange::ITextToSpeech::SpeechState&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            Exchange::ITextToSpeech::SpeechState _state{};

            uint32_t result = implementation->GetSpeechState(_speechid, _state);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::ITextToSpeech::SpeechState>(_state);
        }
        , nullptr
    }; // ExchangeTextToSpeechStubMethods

    //
    // Exchange::ITextToSpeech::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Enabled(const bool) = 0
    //  (1) virtual void VoiceChanged(const string) = 0
    //  (2) virtual void WillSpeak(const uint32_t) = 0
    //  (3) virtual void SpeechStart(const uint32_t) = 0
    //  (4) virtual void SpeechPause(const uint32_t) = 0
    //  (5) virtual void SpeechResume(const uint32_t) = 0
    //  (6) virtual void SpeechInterrupted(const uint32_t) = 0
    //  (7) virtual void NetworkError(const uint32_t) = 0
    //  (8) virtual void PlaybackError(const uint32_t) = 0
    //  (9) virtual void SpeechComplete(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeTextToSpeechNotificationStubMethods[] = {
        // (0) virtual void Enabled(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _state = reader.Boolean();

            implementation->Enabled(_state);
        },

        // (1) virtual void VoiceChanged(const string) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _voice = reader.Text();

            implementation->VoiceChanged(_voice);
        },

        // (2) virtual void WillSpeak(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->WillSpeak(_speechid);
        },

        // (3) virtual void SpeechStart(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->SpeechStart(_speechid);
        },

        // (4) virtual void SpeechPause(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->SpeechPause(_speechid);
        },

        // (5) virtual void SpeechResume(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->SpeechResume(_speechid);
        },

        // (6) virtual void SpeechInterrupted(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->SpeechInterrupted(_speechid);
        },

        // (7) virtual void NetworkError(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->NetworkError(_speechid);
        },

        // (8) virtual void PlaybackError(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->PlaybackError(_speechid);
        },

        // (9) virtual void SpeechComplete(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech::INotification* implementation = reinterpret_cast<Exchange::ITextToSpeech::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _speechid = reader.Number<uint32_t>();

            implementation->SpeechComplete(_speechid);
        }
        , nullptr
    }; // ExchangeTextToSpeechNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_bd6e04b8d151c1f7 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
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

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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

    }; // class RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy

    //
    // RPC::IIteratorTypeInstance_60eba5a793c685ea interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(uint32_t&) = 0
    //  (1) virtual bool Previous(uint32_t&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual uint32_t Current() const = 0
    //

    class RPCIteratorTypeInstance_60eba5a793c685eaProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>> {
    public:
        RPCIteratorTypeInstance_60eba5a793c685eaProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(uint32_t& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(uint32_t& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<uint32_t>();
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

        uint32_t Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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

    }; // class RPCIteratorTypeInstance_60eba5a793c685eaProxy

    //
    // RPC::IIteratorTypeInstance_195e88cf7f955a2e interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(RPC::Environment&) = 0
    //  (1) virtual bool Previous(RPC::Environment&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual RPC::Environment Current() const = 0
    //

    class RPCIteratorTypeInstance_195e88cf7f955a2eProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>> {
    public:
        RPCIteratorTypeInstance_195e88cf7f955a2eProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(RPC::Environment& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.Key = reader.Text();
                _info.Value = reader.Text();
                _info.Scope = reader.Number<RPC::Environment::scope>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(RPC::Environment& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.Key = reader.Text();
                _info.Value = reader.Text();
                _info.Scope = reader.Number<RPC::Environment::scope>();
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

        RPC::Environment Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Environment result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result.Key = reader.Text();
                result.Value = reader.Text();
                result.Scope = reader.Number<RPC::Environment::scope>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_195e88cf7f955a2eProxy

    //
    // Exchange::ITextToSpeech interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::ITextToSpeech::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::ITextToSpeech::INotification*) = 0
    //  (2) virtual uint32_t Enable(const bool) = 0
    //  (3) virtual uint32_t Enable(bool&) const = 0
    //  (4) virtual uint32_t SetConfiguration(const Exchange::ITextToSpeech::Configuration&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (5) virtual uint32_t SetFallbackText(const string, const string) = 0
    //  (6) virtual uint32_t SetAPIKey(const string) = 0
    //  (7) virtual uint32_t SetPrimaryVolDuck(const uint8_t) = 0
    //  (8) virtual uint32_t SetACL(const string, const string) = 0
    //  (9) virtual uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration&) const = 0
    //  (10) virtual uint32_t ListVoices(const string, RPC::IStringIterator*&) const = 0
    //  (11) virtual uint32_t Speak(const string, const string, uint32_t&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (12) virtual uint32_t Cancel(const uint32_t) = 0
    //  (13) virtual uint32_t Pause(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (14) virtual uint32_t Resume(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (15) virtual uint32_t GetSpeechState(const uint32_t, Exchange::ITextToSpeech::SpeechState&) = 0
    //

    class ExchangeTextToSpeechProxy final : public ProxyStub::UnknownProxyType<Exchange::ITextToSpeech> {
    public:
        ExchangeTextToSpeechProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::ITextToSpeech::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::ITextToSpeech::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Enable(const bool _enable) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enable);

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

        uint32_t Enable(bool& _enable) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _enable = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t SetConfiguration(const Exchange::ITextToSpeech::Configuration& _config, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_config.ttsEndPoint);
            writer.Text(_config.ttsEndPointSecured);
            writer.Text(_config.language);
            writer.Text(_config.voice);
            writer.Text(_config.speechRate);
            writer.Number<uint8_t>(_config.volume);
            writer.Number<uint8_t>(_config.rate);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t SetFallbackText(const string _scenario, const string _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_scenario);
            writer.Text(_value);

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

        uint32_t SetAPIKey(const string _apikey) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_apikey);

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

        uint32_t SetPrimaryVolDuck(const uint8_t _prim) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_prim);

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

        uint32_t SetACL(const string _method, const string _apps) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_method);
            writer.Text(_apps);

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

        uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration& _config) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _config.ttsEndPoint = reader.Text();
                _config.ttsEndPointSecured = reader.Text();
                _config.language = reader.Text();
                _config.voice = reader.Text();
                _config.speechRate = reader.Text();
                _config.volume = reader.Number<uint8_t>();
                _config.rate = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t ListVoices(const string _language, RPC::IStringIterator*& _voices) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_language);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _voices = reinterpret_cast<RPC::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Speak(const string _callsign, const string _text, uint32_t& _speechid, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Text(_text);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _speechid = reader.Number<uint32_t>();
                _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Cancel(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

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

        uint32_t Pause(const uint32_t _speechid, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Resume(const uint32_t _speechid, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t GetSpeechState(const uint32_t _speechid, Exchange::ITextToSpeech::SpeechState& _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _state = reader.Number<Exchange::ITextToSpeech::SpeechState>();
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

    }; // class ExchangeTextToSpeechProxy

    //
    // Exchange::ITextToSpeech::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Enabled(const bool) = 0
    //  (1) virtual void VoiceChanged(const string) = 0
    //  (2) virtual void WillSpeak(const uint32_t) = 0
    //  (3) virtual void SpeechStart(const uint32_t) = 0
    //  (4) virtual void SpeechPause(const uint32_t) = 0
    //  (5) virtual void SpeechResume(const uint32_t) = 0
    //  (6) virtual void SpeechInterrupted(const uint32_t) = 0
    //  (7) virtual void NetworkError(const uint32_t) = 0
    //  (8) virtual void PlaybackError(const uint32_t) = 0
    //  (9) virtual void SpeechComplete(const uint32_t) = 0
    //

    class ExchangeTextToSpeechNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::ITextToSpeech::INotification> {
    public:
        ExchangeTextToSpeechNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Enabled(const bool _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void VoiceChanged(const string _voice) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_voice);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void WillSpeak(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void SpeechStart(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void SpeechPause(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void SpeechResume(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void SpeechInterrupted(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void NetworkError(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void PlaybackError(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void SpeechComplete(const uint32_t _speechid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeTextToSpeechNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_bd6e04b8d151c1f7StubMethods> RPCIteratorTypeInstance_bd6e04b8d151c1f7Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>, RPCIteratorTypeInstance_60eba5a793c685eaStubMethods> RPCIteratorTypeInstance_60eba5a793c685eaStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>, RPCIteratorTypeInstance_195e88cf7f955a2eStubMethods> RPCIteratorTypeInstance_195e88cf7f955a2eStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITextToSpeech, ExchangeTextToSpeechStubMethods> ExchangeTextToSpeechStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITextToSpeech::INotification, ExchangeTextToSpeechNotificationStubMethods> ExchangeTextToSpeechNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy, RPCIteratorTypeInstance_bd6e04b8d151c1f7Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>, RPCIteratorTypeInstance_60eba5a793c685eaProxy, RPCIteratorTypeInstance_60eba5a793c685eaStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>, RPCIteratorTypeInstance_195e88cf7f955a2eProxy, RPCIteratorTypeInstance_195e88cf7f955a2eStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITextToSpeech, ExchangeTextToSpeechProxy, ExchangeTextToSpeechStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITextToSpeech::INotification, ExchangeTextToSpeechNotificationProxy, ExchangeTextToSpeechNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::ITextToSpeech>();
                RPC::Administrator::Instance().Recall<Exchange::ITextToSpeech::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
