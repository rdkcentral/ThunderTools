//
// generated automatically from "IBluetoothAudio.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IBluetoothAudio::IStream
//   - class Exchange::IBluetoothAudio::ISink
//   - class Exchange::IBluetoothAudio::ISink::IControl
//   - class Exchange::IBluetoothAudio::ISink::ICallback
//   - class Exchange::IBluetoothAudio::ISource
//   - class Exchange::IBluetoothAudio::ISource::IControl
//   - class Exchange::IBluetoothAudio::ISource::ICallback
//

#include "Module.h"
#include "IBluetoothAudio.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IBluetoothAudio::IStream interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Configure(const Exchange::IBluetoothAudio::IStream::Format&) = 0
    //  (1) virtual Core::hresult Acquire(const string&) = 0
    //  (2) virtual Core::hresult Relinquish() = 0
    //  (3) virtual Core::hresult Speed(const int8_t) = 0
    //  (4) virtual Core::hresult Time(uint32_t&) const = 0
    //  (5) virtual Core::hresult Delay(uint32_t&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothAudioStreamStubMethods[] = {
        // (0) virtual Core::hresult Configure(const Exchange::IBluetoothAudio::IStream::Format&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::IStream* implementation = reinterpret_cast<Exchange::IBluetoothAudio::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::IBluetoothAudio::IStream::Format _pcmStreamFormat{};
            _pcmStreamFormat.SampleRate = reader.Number<uint32_t>();
            _pcmStreamFormat.FrameRate = reader.Number<uint16_t>();
            _pcmStreamFormat.Resolution = reader.Number<uint8_t>();
            _pcmStreamFormat.Channels = reader.Number<uint8_t>();

            Core::hresult result = implementation->Configure(static_cast<const Exchange::IBluetoothAudio::IStream::Format&>(_pcmStreamFormat));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Acquire(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::IStream* implementation = reinterpret_cast<Exchange::IBluetoothAudio::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _connector = reader.Text();

            Core::hresult result = implementation->Acquire(static_cast<const string&>(_connector));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (2) virtual Core::hresult Relinquish() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::IStream* implementation = reinterpret_cast<Exchange::IBluetoothAudio::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Relinquish();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult Speed(const int8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::IStream* implementation = reinterpret_cast<Exchange::IBluetoothAudio::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int8_t _speedPercent = reader.Number<int8_t>();

            Core::hresult result = implementation->Speed(_speedPercent);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Time(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::IStream* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _timeMs{};

            Core::hresult result = implementation->Time(_timeMs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_timeMs);
        },

        // (5) virtual Core::hresult Delay(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::IStream* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _delayMs{};

            Core::hresult result = implementation->Delay(_delayMs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_delayMs);
        }
        , nullptr
    }; // ExchangeBluetoothAudioStreamStubMethods

    //
    // Exchange::IBluetoothAudio::ISink interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Callback(Exchange::IBluetoothAudio::ISink::ICallback*) = 0
    //  (1) virtual Core::hresult Assign(const string&) = 0
    //  (2) virtual Core::hresult Revoke() = 0
    //  (3) virtual Core::hresult State(Exchange::IBluetoothAudio::state&) const = 0
    //  (4) virtual Core::hresult Device(string&) const = 0
    //  (5) virtual Core::hresult Type(Exchange::IBluetoothAudio::ISink::devicetype&) const = 0
    //  (6) virtual Core::hresult Latency(const int16_t) = 0
    //  (7) virtual Core::hresult Latency(int16_t&) const = 0
    //  (8) virtual Core::hresult SupportedCodecs(Exchange::IBluetoothAudio::audiocodec&) const = 0
    //  (9) virtual Core::hresult SupportedDRMs(Exchange::IBluetoothAudio::drmscheme&) const = 0
    //  (10) virtual Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties&) const = 0
    //  (11) virtual Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties&) const = 0
    //  (12) virtual Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothAudioSinkStubMethods[] = {
        // (0) virtual Core::hresult Callback(Exchange::IBluetoothAudio::ISink::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBluetoothAudio::ISink::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            Core::hresult result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Assign(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _address = reader.Text();

            Core::hresult result = implementation->Assign(static_cast<const string&>(_address));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (2) virtual Core::hresult Revoke() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Revoke();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult State(Exchange::IBluetoothAudio::state&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::state _sinkState{};

            Core::hresult result = implementation->State(_sinkState);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::state>(_sinkState);
        },

        // (4) virtual Core::hresult Device(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _address{};

            Core::hresult result = implementation->Device(_address);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_address);
        },

        // (5) virtual Core::hresult Type(Exchange::IBluetoothAudio::ISink::devicetype&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::ISink::devicetype _sinkType{};

            Core::hresult result = implementation->Type(_sinkType);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::ISink::devicetype>(_sinkType);
        },

        // (6) virtual Core::hresult Latency(const int16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int16_t _latency = reader.Number<int16_t>();

            Core::hresult result = implementation->Latency(_latency);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (7) virtual Core::hresult Latency(int16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int16_t _latency{};

            Core::hresult result = implementation->Latency(_latency);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<int16_t>(_latency);
        },

        // (8) virtual Core::hresult SupportedCodecs(Exchange::IBluetoothAudio::audiocodec&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::audiocodec _codecs{};

            Core::hresult result = implementation->SupportedCodecs(_codecs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::audiocodec>(_codecs);
        },

        // (9) virtual Core::hresult SupportedDRMs(Exchange::IBluetoothAudio::drmscheme&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::drmscheme _drms{};

            Core::hresult result = implementation->SupportedDRMs(_drms);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::drmscheme>(_drms);
        },

        // (10) virtual Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::CodecProperties _properties{};

            Core::hresult result = implementation->Codec(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::audiocodec>(_properties.Codec);
            writer.Text(_properties.Settings);
        },

        // (11) virtual Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::DRMProperties _properties{};

            Core::hresult result = implementation->DRM(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::drmscheme>(_properties.DRM);
            writer.Text(_properties.Settings);
        },

        // (12) virtual Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISink* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::StreamProperties _properties{};

            Core::hresult result = implementation->Stream(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_properties.SampleRate);
            writer.Number<uint32_t>(_properties.BitRate);
            writer.Number<uint8_t>(_properties.Channels);
            writer.Number<uint8_t>(_properties.Resolution);
            writer.Boolean(_properties.IsResampled);
        }
        , nullptr
    }; // ExchangeBluetoothAudioSinkStubMethods

    //
    // Exchange::IBluetoothAudio::ISink::IControl interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Source(Exchange::IBluetoothAudio::IStream*) = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothAudioSinkControlStubMethods[] = {
        // (0) virtual Core::hresult Source(Exchange::IBluetoothAudio::IStream*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISink::IControl* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISink::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sourceInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBluetoothAudio::IStream* _source{};
            ProxyStub::UnknownProxy* _sourceProxy__ = nullptr;
            if (_sourceInstanceId__ != 0) {
                _sourceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sourceInstanceId__, false, _source);
                ASSERT((_source != nullptr) && (_sourceProxy__ != nullptr));
            }

            Core::hresult result = implementation->Source(_source);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sourceProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sourceProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExchangeBluetoothAudioSinkControlStubMethods

    //
    // Exchange::IBluetoothAudio::ISink::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const Exchange::IBluetoothAudio::state) = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothAudioSinkCallbackStubMethods[] = {
        // (0) virtual void StateChanged(const Exchange::IBluetoothAudio::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISink::ICallback* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISink::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IBluetoothAudio::state _state = reader.Number<Exchange::IBluetoothAudio::state>();

            implementation->StateChanged(_state);
        }
        , nullptr
    }; // ExchangeBluetoothAudioSinkCallbackStubMethods

    //
    // Exchange::IBluetoothAudio::ISource interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Callback(Exchange::IBluetoothAudio::ISource::ICallback*) = 0
    //  (1) virtual Core::hresult State(Exchange::IBluetoothAudio::state&) const = 0
    //  (2) virtual Core::hresult Device(string&) const = 0
    //  (3) virtual Core::hresult Type(Exchange::IBluetoothAudio::ISource::devicetype&) const = 0
    //  (4) virtual Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties&) const = 0
    //  (5) virtual Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties&) const = 0
    //  (6) virtual Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothAudioSourceStubMethods[] = {
        // (0) virtual Core::hresult Callback(Exchange::IBluetoothAudio::ISource::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISource* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBluetoothAudio::ISource::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            Core::hresult result = implementation->Callback(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult State(Exchange::IBluetoothAudio::state&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISource* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::state _sourceState{};

            Core::hresult result = implementation->State(_sourceState);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::state>(_sourceState);
        },

        // (2) virtual Core::hresult Device(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISource* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _address{};

            Core::hresult result = implementation->Device(_address);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_address);
        },

        // (3) virtual Core::hresult Type(Exchange::IBluetoothAudio::ISource::devicetype&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISource* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::ISource::devicetype _sourceType{};

            Core::hresult result = implementation->Type(_sourceType);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::ISource::devicetype>(_sourceType);
        },

        // (4) virtual Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISource* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::CodecProperties _properties{};

            Core::hresult result = implementation->Codec(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::audiocodec>(_properties.Codec);
            writer.Text(_properties.Settings);
        },

        // (5) virtual Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISource* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::DRMProperties _properties{};

            Core::hresult result = implementation->DRM(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Exchange::IBluetoothAudio::drmscheme>(_properties.DRM);
            writer.Text(_properties.Settings);
        },

        // (6) virtual Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudio::ISource* implementation = reinterpret_cast<const Exchange::IBluetoothAudio::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudio::StreamProperties _properties{};

            Core::hresult result = implementation->Stream(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_properties.SampleRate);
            writer.Number<uint32_t>(_properties.BitRate);
            writer.Number<uint8_t>(_properties.Channels);
            writer.Number<uint8_t>(_properties.Resolution);
            writer.Boolean(_properties.IsResampled);
        }
        , nullptr
    }; // ExchangeBluetoothAudioSourceStubMethods

    //
    // Exchange::IBluetoothAudio::ISource::IControl interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Sink(Exchange::IBluetoothAudio::IStream*) = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothAudioSourceControlStubMethods[] = {
        // (0) virtual Core::hresult Sink(Exchange::IBluetoothAudio::IStream*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISource::IControl* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISource::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBluetoothAudio::IStream* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            Core::hresult result = implementation->Sink(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExchangeBluetoothAudioSourceControlStubMethods

    //
    // Exchange::IBluetoothAudio::ISource::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const Exchange::IBluetoothAudio::state) = 0
    //

    static ProxyStub::MethodHandler ExchangeBluetoothAudioSourceCallbackStubMethods[] = {
        // (0) virtual void StateChanged(const Exchange::IBluetoothAudio::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudio::ISource::ICallback* implementation = reinterpret_cast<Exchange::IBluetoothAudio::ISource::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IBluetoothAudio::state _state = reader.Number<Exchange::IBluetoothAudio::state>();

            implementation->StateChanged(_state);
        }
        , nullptr
    }; // ExchangeBluetoothAudioSourceCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IBluetoothAudio::IStream interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Configure(const Exchange::IBluetoothAudio::IStream::Format&) = 0
    //  (1) virtual Core::hresult Acquire(const string&) = 0
    //  (2) virtual Core::hresult Relinquish() = 0
    //  (3) virtual Core::hresult Speed(const int8_t) = 0
    //  (4) virtual Core::hresult Time(uint32_t&) const = 0
    //  (5) virtual Core::hresult Delay(uint32_t&) const = 0
    //

    class ExchangeBluetoothAudioStreamProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudio::IStream> {
    public:
        ExchangeBluetoothAudioStreamProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Configure(const Exchange::IBluetoothAudio::IStream::Format& _pcmStreamFormat) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_pcmStreamFormat.SampleRate);
            writer.Number<uint16_t>(_pcmStreamFormat.FrameRate);
            writer.Number<uint8_t>(_pcmStreamFormat.Resolution);
            writer.Number<uint8_t>(_pcmStreamFormat.Channels);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Acquire(const string& _connector) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_connector);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Relinquish() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Speed(const int8_t _speedPercent) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int8_t>(_speedPercent);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Time(uint32_t& _timeMs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _timeMs = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Delay(uint32_t& _delayMs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _delayMs = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeBluetoothAudioStreamProxy

    //
    // Exchange::IBluetoothAudio::ISink interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Callback(Exchange::IBluetoothAudio::ISink::ICallback*) = 0
    //  (1) virtual Core::hresult Assign(const string&) = 0
    //  (2) virtual Core::hresult Revoke() = 0
    //  (3) virtual Core::hresult State(Exchange::IBluetoothAudio::state&) const = 0
    //  (4) virtual Core::hresult Device(string&) const = 0
    //  (5) virtual Core::hresult Type(Exchange::IBluetoothAudio::ISink::devicetype&) const = 0
    //  (6) virtual Core::hresult Latency(const int16_t) = 0
    //  (7) virtual Core::hresult Latency(int16_t&) const = 0
    //  (8) virtual Core::hresult SupportedCodecs(Exchange::IBluetoothAudio::audiocodec&) const = 0
    //  (9) virtual Core::hresult SupportedDRMs(Exchange::IBluetoothAudio::drmscheme&) const = 0
    //  (10) virtual Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties&) const = 0
    //  (11) virtual Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties&) const = 0
    //  (12) virtual Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties&) const = 0
    //

    class ExchangeBluetoothAudioSinkProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudio::ISink> {
    public:
        ExchangeBluetoothAudioSinkProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Callback(Exchange::IBluetoothAudio::ISink::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Assign(const string& _address) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Revoke() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult State(Exchange::IBluetoothAudio::state& _sinkState) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _sinkState = reader.Number<Exchange::IBluetoothAudio::state>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Device(string& _address) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _address = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Type(Exchange::IBluetoothAudio::ISink::devicetype& _sinkType) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _sinkType = reader.Number<Exchange::IBluetoothAudio::ISink::devicetype>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Latency(const int16_t _latency) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int16_t>(_latency);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Latency(int16_t& _latency) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _latency = reader.Number<int16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult SupportedCodecs(Exchange::IBluetoothAudio::audiocodec& _codecs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _codecs = reader.Number<Exchange::IBluetoothAudio::audiocodec>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult SupportedDRMs(Exchange::IBluetoothAudio::drmscheme& _drms) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _drms = reader.Number<Exchange::IBluetoothAudio::drmscheme>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties& _properties) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _properties.Codec = reader.Number<Exchange::IBluetoothAudio::audiocodec>();
                _properties.Settings = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties& _properties) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _properties.DRM = reader.Number<Exchange::IBluetoothAudio::drmscheme>();
                _properties.Settings = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties& _properties) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _properties.SampleRate = reader.Number<uint32_t>();
                _properties.BitRate = reader.Number<uint32_t>();
                _properties.Channels = reader.Number<uint8_t>();
                _properties.Resolution = reader.Number<uint8_t>();
                _properties.IsResampled = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
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

    }; // class ExchangeBluetoothAudioSinkProxy

    //
    // Exchange::IBluetoothAudio::ISink::IControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Source(Exchange::IBluetoothAudio::IStream*) = 0
    //

    class ExchangeBluetoothAudioSinkControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudio::ISink::IControl> {
    public:
        ExchangeBluetoothAudioSinkControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Source(Exchange::IBluetoothAudio::IStream* _source) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_source));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
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

    }; // class ExchangeBluetoothAudioSinkControlProxy

    //
    // Exchange::IBluetoothAudio::ISink::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const Exchange::IBluetoothAudio::state) = 0
    //

    class ExchangeBluetoothAudioSinkCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudio::ISink::ICallback> {
    public:
        ExchangeBluetoothAudioSinkCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChanged(const Exchange::IBluetoothAudio::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IBluetoothAudio::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeBluetoothAudioSinkCallbackProxy

    //
    // Exchange::IBluetoothAudio::ISource interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Callback(Exchange::IBluetoothAudio::ISource::ICallback*) = 0
    //  (1) virtual Core::hresult State(Exchange::IBluetoothAudio::state&) const = 0
    //  (2) virtual Core::hresult Device(string&) const = 0
    //  (3) virtual Core::hresult Type(Exchange::IBluetoothAudio::ISource::devicetype&) const = 0
    //  (4) virtual Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties&) const = 0
    //  (5) virtual Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties&) const = 0
    //  (6) virtual Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties&) const = 0
    //

    class ExchangeBluetoothAudioSourceProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudio::ISource> {
    public:
        ExchangeBluetoothAudioSourceProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Callback(Exchange::IBluetoothAudio::ISource::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult State(Exchange::IBluetoothAudio::state& _sourceState) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _sourceState = reader.Number<Exchange::IBluetoothAudio::state>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Device(string& _address) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _address = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Type(Exchange::IBluetoothAudio::ISource::devicetype& _sourceType) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _sourceType = reader.Number<Exchange::IBluetoothAudio::ISource::devicetype>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Codec(Exchange::IBluetoothAudio::CodecProperties& _properties) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _properties.Codec = reader.Number<Exchange::IBluetoothAudio::audiocodec>();
                _properties.Settings = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult DRM(Exchange::IBluetoothAudio::DRMProperties& _properties) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _properties.DRM = reader.Number<Exchange::IBluetoothAudio::drmscheme>();
                _properties.Settings = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Stream(Exchange::IBluetoothAudio::StreamProperties& _properties) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _properties.SampleRate = reader.Number<uint32_t>();
                _properties.BitRate = reader.Number<uint32_t>();
                _properties.Channels = reader.Number<uint8_t>();
                _properties.Resolution = reader.Number<uint8_t>();
                _properties.IsResampled = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
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

    }; // class ExchangeBluetoothAudioSourceProxy

    //
    // Exchange::IBluetoothAudio::ISource::IControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Sink(Exchange::IBluetoothAudio::IStream*) = 0
    //

    class ExchangeBluetoothAudioSourceControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudio::ISource::IControl> {
    public:
        ExchangeBluetoothAudioSourceControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Sink(Exchange::IBluetoothAudio::IStream* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
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

    }; // class ExchangeBluetoothAudioSourceControlProxy

    //
    // Exchange::IBluetoothAudio::ISource::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChanged(const Exchange::IBluetoothAudio::state) = 0
    //

    class ExchangeBluetoothAudioSourceCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudio::ISource::ICallback> {
    public:
        ExchangeBluetoothAudioSourceCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChanged(const Exchange::IBluetoothAudio::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IBluetoothAudio::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeBluetoothAudioSourceCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudio::IStream, ExchangeBluetoothAudioStreamStubMethods> ExchangeBluetoothAudioStreamStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudio::ISink, ExchangeBluetoothAudioSinkStubMethods> ExchangeBluetoothAudioSinkStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudio::ISink::IControl, ExchangeBluetoothAudioSinkControlStubMethods> ExchangeBluetoothAudioSinkControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudio::ISink::ICallback, ExchangeBluetoothAudioSinkCallbackStubMethods> ExchangeBluetoothAudioSinkCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudio::ISource, ExchangeBluetoothAudioSourceStubMethods> ExchangeBluetoothAudioSourceStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudio::ISource::IControl, ExchangeBluetoothAudioSourceControlStubMethods> ExchangeBluetoothAudioSourceControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudio::ISource::ICallback, ExchangeBluetoothAudioSourceCallbackStubMethods> ExchangeBluetoothAudioSourceCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudio::IStream, ExchangeBluetoothAudioStreamProxy, ExchangeBluetoothAudioStreamStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudio::ISink, ExchangeBluetoothAudioSinkProxy, ExchangeBluetoothAudioSinkStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudio::ISink::IControl, ExchangeBluetoothAudioSinkControlProxy, ExchangeBluetoothAudioSinkControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudio::ISink::ICallback, ExchangeBluetoothAudioSinkCallbackProxy, ExchangeBluetoothAudioSinkCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudio::ISource, ExchangeBluetoothAudioSourceProxy, ExchangeBluetoothAudioSourceStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudio::ISource::IControl, ExchangeBluetoothAudioSourceControlProxy, ExchangeBluetoothAudioSourceControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudio::ISource::ICallback, ExchangeBluetoothAudioSourceCallbackProxy, ExchangeBluetoothAudioSourceCallbackStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudio::IStream>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudio::ISink>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudio::ISink::IControl>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudio::ISink::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudio::ISource>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudio::ISource::IControl>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudio::ISource::ICallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
