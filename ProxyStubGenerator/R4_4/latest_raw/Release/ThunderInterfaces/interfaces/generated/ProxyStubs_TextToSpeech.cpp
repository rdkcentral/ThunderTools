//
// generated automatically from "ITextToSpeech.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ITextToSpeech
//   - class Exchange::ITextToSpeech::INotification
//

#include "Module.h"
#include "ITextToSpeech.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

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
    //  (8) virtual uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration&) const = 0
    //  (9) virtual uint32_t ListVoices(const string, RPC::IStringIterator*&) const = 0
    //  (10) virtual uint32_t Speak(const string, uint32_t&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (11) virtual uint32_t Cancel(const uint32_t) = 0
    //  (12) virtual uint32_t Pause(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (13) virtual uint32_t Resume(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (14) virtual uint32_t GetSpeechState(const uint32_t, Exchange::ITextToSpeech::SpeechState&) = 0
    //

    ProxyStub::MethodHandler ExchangeTextToSpeechStubMethods[] = {
        // (0) virtual void Register(Exchange::ITextToSpeech::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::ITextToSpeech::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Register(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::ITextToSpeech::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::ITextToSpeech::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Unregister(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
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

        // (8) virtual uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration&) const = 0
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

        // (9) virtual uint32_t ListVoices(const string, RPC::IStringIterator*&) const = 0
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

        // (10) virtual uint32_t Speak(const string, uint32_t&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITextToSpeech* implementation = reinterpret_cast<Exchange::ITextToSpeech*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _text = reader.Text();

            uint32_t _speechid{};
            Exchange::ITextToSpeech::TTSErrorDetail _status{};

            uint32_t result = implementation->Speak(_text, _speechid, _status);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_speechid);
            writer.Number<Exchange::ITextToSpeech::TTSErrorDetail>(_status);
        },

        // (11) virtual uint32_t Cancel(const uint32_t) = 0
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

        // (12) virtual uint32_t Pause(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
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

        // (13) virtual uint32_t Resume(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
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

        // (14) virtual uint32_t GetSpeechState(const uint32_t, Exchange::ITextToSpeech::SpeechState&) = 0
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

    ProxyStub::MethodHandler ExchangeTextToSpeechNotificationStubMethods[] = {
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
    //  (8) virtual uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration&) const = 0
    //  (9) virtual uint32_t ListVoices(const string, RPC::IStringIterator*&) const = 0
    //  (10) virtual uint32_t Speak(const string, uint32_t&, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (11) virtual uint32_t Cancel(const uint32_t) = 0
    //  (12) virtual uint32_t Pause(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (13) virtual uint32_t Resume(const uint32_t, Exchange::ITextToSpeech::TTSErrorDetail&) = 0
    //  (14) virtual uint32_t GetSpeechState(const uint32_t, Exchange::ITextToSpeech::SpeechState&) = 0
    //

    class ExchangeTextToSpeechProxy final : public ProxyStub::UnknownProxyType<Exchange::ITextToSpeech> {
    public:
        ExchangeTextToSpeechProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::ITextToSpeech::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::ITextToSpeech::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Enable(const bool _enable) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enable);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Enable(bool& _enable) const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _enable = reader.Boolean();

            return (result);
        }

        uint32_t SetConfiguration(const Exchange::ITextToSpeech::Configuration& _config, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_config.ttsEndPoint);
            writer.Text(_config.ttsEndPointSecured);
            writer.Text(_config.language);
            writer.Text(_config.voice);
            writer.Text(_config.speechRate);
            writer.Number<uint8_t>(_config.volume);
            writer.Number<uint8_t>(_config.rate);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();

            return (result);
        }

        uint32_t SetFallbackText(const string _scenario, const string _value) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_scenario);
            writer.Text(_value);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t SetAPIKey(const string _apikey) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_apikey);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t SetPrimaryVolDuck(const uint8_t _prim) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_prim);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t GetConfiguration(Exchange::ITextToSpeech::Configuration& _config) const override
        {
            IPCMessage message(BaseClass::Message(8));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _config.ttsEndPoint = reader.Text();
            _config.ttsEndPointSecured = reader.Text();
            _config.language = reader.Text();
            _config.voice = reader.Text();
            _config.speechRate = reader.Text();
            _config.volume = reader.Number<uint8_t>();
            _config.rate = reader.Number<uint8_t>();

            return (result);
        }

        uint32_t ListVoices(const string _language, RPC::IStringIterator*& _voices) const override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_language);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _voices = reinterpret_cast<RPC::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));

            return (result);
        }

        uint32_t Speak(const string _text, uint32_t& _speechid, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_text);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _speechid = reader.Number<uint32_t>();
            _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();

            return (result);
        }

        uint32_t Cancel(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Pause(const uint32_t _speechid, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(BaseClass::Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();

            return (result);
        }

        uint32_t Resume(const uint32_t _speechid, Exchange::ITextToSpeech::TTSErrorDetail& _status) override
        {
            IPCMessage message(BaseClass::Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _status = reader.Number<Exchange::ITextToSpeech::TTSErrorDetail>();

            return (result);
        }

        uint32_t GetSpeechState(const uint32_t _speechid, Exchange::ITextToSpeech::SpeechState& _state) override
        {
            IPCMessage message(BaseClass::Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _state = reader.Number<Exchange::ITextToSpeech::SpeechState>();

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

        void Enabled(const bool _state) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_state);

            UnknownProxyType::Invoke(message);
        }

        void VoiceChanged(const string _voice) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_voice);

            UnknownProxyType::Invoke(message);
        }

        void WillSpeak(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

        void SpeechStart(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

        void SpeechPause(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

        void SpeechResume(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

        void SpeechInterrupted(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

        void NetworkError(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

        void PlaybackError(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

        void SpeechComplete(const uint32_t _speechid) override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_speechid);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeTextToSpeechNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ITextToSpeech, ExchangeTextToSpeechStubMethods> ExchangeTextToSpeechStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITextToSpeech::INotification, ExchangeTextToSpeechNotificationStubMethods> ExchangeTextToSpeechNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ITextToSpeech, ExchangeTextToSpeechProxy, ExchangeTextToSpeechStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITextToSpeech::INotification, ExchangeTextToSpeechNotificationProxy, ExchangeTextToSpeechNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ITextToSpeech>();
                RPC::Administrator::Instance().Recall<Exchange::ITextToSpeech::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
