//
// generated automatically from "IBluetoothAudio.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IBluetoothAudioSink::audiocodec, INTERFACE_ID = Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IBluetoothAudioSink::drmscheme, INTERFACE_ID = Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR]
//   - class Exchange::IBluetoothAudioSink
//   - class Exchange::IBluetoothAudioSink::IControl
//   - class Exchange::IBluetoothAudioSink::ICallback
//

#include "Module.h"
#include "IBluetoothAudio.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance124C3D5B interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IBluetoothAudioSink::audiocodec&) = 0
    //  (1) virtual bool Previous(Exchange::IBluetoothAudioSink::audiocodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IBluetoothAudioSink::audiocodec Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance124C3D5BStubMethods[] = {
        // (0) virtual bool Next(Exchange::IBluetoothAudioSink::audiocodec&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::audiocodec _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IBluetoothAudioSink::audiocodec>(_info);
        },

        // (1) virtual bool Previous(Exchange::IBluetoothAudioSink::audiocodec&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::audiocodec _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IBluetoothAudioSink::audiocodec>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IBluetoothAudioSink::audiocodec Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::audiocodec result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IBluetoothAudioSink::audiocodec>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance124C3D5BStubMethods

    //
    // RPC::IIteratorTypeInstance281FF53B interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IBluetoothAudioSink::drmscheme&) = 0
    //  (1) virtual bool Previous(Exchange::IBluetoothAudioSink::drmscheme&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IBluetoothAudioSink::drmscheme Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance281FF53BStubMethods[] = {
        // (0) virtual bool Next(Exchange::IBluetoothAudioSink::drmscheme&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::drmscheme _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IBluetoothAudioSink::drmscheme>(_info);
        },

        // (1) virtual bool Previous(Exchange::IBluetoothAudioSink::drmscheme&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::drmscheme _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IBluetoothAudioSink::drmscheme>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IBluetoothAudioSink::drmscheme Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::drmscheme result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IBluetoothAudioSink::drmscheme>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance281FF53BStubMethods

    //
    // Exchange::IBluetoothAudioSink interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Callback(Exchange::IBluetoothAudioSink::ICallback*) = 0
    //  (1) virtual uint32_t Assign(const string&) = 0
    //  (2) virtual uint32_t Revoke() = 0
    //  (3) virtual uint32_t Latency(const int16_t) = 0
    //  (4) virtual uint32_t Latency(int16_t&) const = 0
    //  (5) virtual uint32_t State(Exchange::IBluetoothAudioSink::state&) const = 0
    //  (6) virtual uint32_t Type(Exchange::IBluetoothAudioSink::devicetype&) const = 0
    //  (7) virtual uint32_t SupportedCodecs(Exchange::IBluetoothAudioSink::IAudioCodecIterator*&) const = 0
    //  (8) virtual uint32_t SupportedDRMs(Exchange::IBluetoothAudioSink::IDRMSchemeIterator*&) const = 0
    //  (9) virtual uint32_t Codec(Exchange::IBluetoothAudioSink::CodecProperties&) const = 0
    //  (10) virtual uint32_t DRM(Exchange::IBluetoothAudioSink::DRMProperties&) const = 0
    //  (11) virtual uint32_t Stream(Exchange::IBluetoothAudioSink::StreamProperties&) const = 0
    //

    ProxyStub::MethodHandler ExchangeBluetoothAudioSinkStubMethods[] = {
        // (0) virtual uint32_t Callback(Exchange::IBluetoothAudioSink::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IBluetoothAudioSink::ICallback* _callback = nullptr;
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

        // (1) virtual uint32_t Assign(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _address = reader.Text();

            uint32_t result = implementation->Assign(static_cast<const string&>(_address));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Revoke() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Revoke();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Latency(const int16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int16_t _latency = reader.Number<int16_t>();

            uint32_t result = implementation->Latency(_latency);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t Latency(int16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int16_t _latency{};

            uint32_t result = implementation->Latency(_latency);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<int16_t>(_latency);
        },

        // (5) virtual uint32_t State(Exchange::IBluetoothAudioSink::state&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::state _sinkState{};

            uint32_t result = implementation->State(_sinkState);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IBluetoothAudioSink::state>(_sinkState);
        },

        // (6) virtual uint32_t Type(Exchange::IBluetoothAudioSink::devicetype&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::devicetype _type{};

            uint32_t result = implementation->Type(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IBluetoothAudioSink::devicetype>(_type);
        },

        // (7) virtual uint32_t SupportedCodecs(Exchange::IBluetoothAudioSink::IAudioCodecIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::IAudioCodecIterator* _codecs{};

            uint32_t result = implementation->SupportedCodecs(_codecs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_codecs));

            RPC::Administrator::Instance().RegisterInterface(channel, _codecs);
        },

        // (8) virtual uint32_t SupportedDRMs(Exchange::IBluetoothAudioSink::IDRMSchemeIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::IDRMSchemeIterator* _drms{};

            uint32_t result = implementation->SupportedDRMs(_drms);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_drms));

            RPC::Administrator::Instance().RegisterInterface(channel, _drms);
        },

        // (9) virtual uint32_t Codec(Exchange::IBluetoothAudioSink::CodecProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::CodecProperties _properties{};

            uint32_t result = implementation->Codec(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IBluetoothAudioSink::audiocodec>(_properties.Codec);
            writer.Text(_properties.Settings);
        },

        // (10) virtual uint32_t DRM(Exchange::IBluetoothAudioSink::DRMProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::DRMProperties _properties{};

            uint32_t result = implementation->DRM(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IBluetoothAudioSink::drmscheme>(_properties.DRM);
            writer.Text(_properties.Settings);
        },

        // (11) virtual uint32_t Stream(Exchange::IBluetoothAudioSink::StreamProperties&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBluetoothAudioSink::StreamProperties _properties{};

            uint32_t result = implementation->Stream(_properties);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_properties.SampleRate);
            writer.Number<uint32_t>(_properties.BitRate);
            writer.Number<uint8_t>(_properties.Channels);
            writer.Number<uint8_t>(_properties.Resolution);
            writer.Boolean(_properties.IsResampling);
        }
        , nullptr
    }; // ExchangeBluetoothAudioSinkStubMethods

    //
    // Exchange::IBluetoothAudioSink::IControl interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Acquire(const string&, const Exchange::IBluetoothAudioSink::IControl::Format&) = 0
    //  (1) virtual uint32_t Relinquish() = 0
    //  (2) virtual uint32_t Speed(const int8_t) = 0
    //  (3) virtual uint32_t Time(uint32_t&) const = 0
    //  (4) virtual uint32_t Delay(uint32_t&) const = 0
    //

    ProxyStub::MethodHandler ExchangeBluetoothAudioSinkControlStubMethods[] = {
        // (0) virtual uint32_t Acquire(const string&, const Exchange::IBluetoothAudioSink::IControl::Format&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink::IControl* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _connector = reader.Text();
            Exchange::IBluetoothAudioSink::IControl::Format _format{};
            _format.SampleRate = reader.Number<uint32_t>();
            _format.FrameRate = reader.Number<uint16_t>();
            _format.Resolution = reader.Number<uint8_t>();
            _format.Channels = reader.Number<uint8_t>();

            uint32_t result = implementation->Acquire(static_cast<const string&>(_connector), static_cast<const Exchange::IBluetoothAudioSink::IControl::Format&>(_format));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t Relinquish() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink::IControl* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Relinquish();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Speed(const int8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink::IControl* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int8_t _speed = reader.Number<int8_t>();

            uint32_t result = implementation->Speed(_speed);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Time(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink::IControl* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _position{};

            uint32_t result = implementation->Time(_position);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_position);
        },

        // (4) virtual uint32_t Delay(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBluetoothAudioSink::IControl* implementation = reinterpret_cast<const Exchange::IBluetoothAudioSink::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _delay{};

            uint32_t result = implementation->Delay(_delay);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_delay);
        }
        , nullptr
    }; // ExchangeBluetoothAudioSinkControlStubMethods

    //
    // Exchange::IBluetoothAudioSink::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Updated() = 0
    //

    ProxyStub::MethodHandler ExchangeBluetoothAudioSinkCallbackStubMethods[] = {
        // (0) virtual void Updated() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBluetoothAudioSink::ICallback* implementation = reinterpret_cast<Exchange::IBluetoothAudioSink::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Updated();
        }
        , nullptr
    }; // ExchangeBluetoothAudioSinkCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance124C3D5B interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IBluetoothAudioSink::audiocodec&) = 0
    //  (1) virtual bool Previous(Exchange::IBluetoothAudioSink::audiocodec&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IBluetoothAudioSink::audiocodec Current() const = 0
    //

    class RPCIteratorTypeInstance124C3D5BProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>> {
    public:
        RPCIteratorTypeInstance124C3D5BProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IBluetoothAudioSink::audiocodec& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IBluetoothAudioSink::audiocodec>();

            return (result);
        }

        bool Previous(Exchange::IBluetoothAudioSink::audiocodec& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IBluetoothAudioSink::audiocodec>();

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

        Exchange::IBluetoothAudioSink::audiocodec Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IBluetoothAudioSink::audiocodec result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IBluetoothAudioSink::audiocodec>();

            return (result);
        }

    }; // class RPCIteratorTypeInstance124C3D5BProxy

    //
    // RPC::IIteratorTypeInstance281FF53B interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IBluetoothAudioSink::drmscheme&) = 0
    //  (1) virtual bool Previous(Exchange::IBluetoothAudioSink::drmscheme&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IBluetoothAudioSink::drmscheme Current() const = 0
    //

    class RPCIteratorTypeInstance281FF53BProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>> {
    public:
        RPCIteratorTypeInstance281FF53BProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IBluetoothAudioSink::drmscheme& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IBluetoothAudioSink::drmscheme>();

            return (result);
        }

        bool Previous(Exchange::IBluetoothAudioSink::drmscheme& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IBluetoothAudioSink::drmscheme>();

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

        Exchange::IBluetoothAudioSink::drmscheme Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IBluetoothAudioSink::drmscheme result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IBluetoothAudioSink::drmscheme>();

            return (result);
        }

    }; // class RPCIteratorTypeInstance281FF53BProxy

    //
    // Exchange::IBluetoothAudioSink interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Callback(Exchange::IBluetoothAudioSink::ICallback*) = 0
    //  (1) virtual uint32_t Assign(const string&) = 0
    //  (2) virtual uint32_t Revoke() = 0
    //  (3) virtual uint32_t Latency(const int16_t) = 0
    //  (4) virtual uint32_t Latency(int16_t&) const = 0
    //  (5) virtual uint32_t State(Exchange::IBluetoothAudioSink::state&) const = 0
    //  (6) virtual uint32_t Type(Exchange::IBluetoothAudioSink::devicetype&) const = 0
    //  (7) virtual uint32_t SupportedCodecs(Exchange::IBluetoothAudioSink::IAudioCodecIterator*&) const = 0
    //  (8) virtual uint32_t SupportedDRMs(Exchange::IBluetoothAudioSink::IDRMSchemeIterator*&) const = 0
    //  (9) virtual uint32_t Codec(Exchange::IBluetoothAudioSink::CodecProperties&) const = 0
    //  (10) virtual uint32_t DRM(Exchange::IBluetoothAudioSink::DRMProperties&) const = 0
    //  (11) virtual uint32_t Stream(Exchange::IBluetoothAudioSink::StreamProperties&) const = 0
    //

    class ExchangeBluetoothAudioSinkProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudioSink> {
    public:
        ExchangeBluetoothAudioSinkProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Callback(Exchange::IBluetoothAudioSink::ICallback* _callback) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Assign(const string& _address) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_address));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Revoke() override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Latency(const int16_t _latency) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int16_t>(_latency);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Latency(int16_t& _latency) const override
        {
            IPCMessage message(BaseClass::Message(4));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _latency = reader.Number<int16_t>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t State(Exchange::IBluetoothAudioSink::state& _sinkState) const override
        {
            IPCMessage message(BaseClass::Message(5));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _sinkState = reader.Number<Exchange::IBluetoothAudioSink::state>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Type(Exchange::IBluetoothAudioSink::devicetype& _type) const override
        {
            IPCMessage message(BaseClass::Message(6));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _type = reader.Number<Exchange::IBluetoothAudioSink::devicetype>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SupportedCodecs(Exchange::IBluetoothAudioSink::IAudioCodecIterator*& _codecs) const override
        {
            IPCMessage message(BaseClass::Message(7));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _codecs = reinterpret_cast<Exchange::IBluetoothAudioSink::IAudioCodecIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IBluetoothAudioSink::IAudioCodecIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SupportedDRMs(Exchange::IBluetoothAudioSink::IDRMSchemeIterator*& _drms) const override
        {
            IPCMessage message(BaseClass::Message(8));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _drms = reinterpret_cast<Exchange::IBluetoothAudioSink::IDRMSchemeIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IBluetoothAudioSink::IDRMSchemeIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Codec(Exchange::IBluetoothAudioSink::CodecProperties& _properties) const override
        {
            IPCMessage message(BaseClass::Message(9));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _properties.Codec = reader.Number<Exchange::IBluetoothAudioSink::audiocodec>();
                    _properties.Settings = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t DRM(Exchange::IBluetoothAudioSink::DRMProperties& _properties) const override
        {
            IPCMessage message(BaseClass::Message(10));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _properties.DRM = reader.Number<Exchange::IBluetoothAudioSink::drmscheme>();
                    _properties.Settings = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Stream(Exchange::IBluetoothAudioSink::StreamProperties& _properties) const override
        {
            IPCMessage message(BaseClass::Message(11));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _properties.SampleRate = reader.Number<uint32_t>();
                    _properties.BitRate = reader.Number<uint32_t>();
                    _properties.Channels = reader.Number<uint8_t>();
                    _properties.Resolution = reader.Number<uint8_t>();
                    _properties.IsResampling = reader.Boolean();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeBluetoothAudioSinkProxy

    //
    // Exchange::IBluetoothAudioSink::IControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Acquire(const string&, const Exchange::IBluetoothAudioSink::IControl::Format&) = 0
    //  (1) virtual uint32_t Relinquish() = 0
    //  (2) virtual uint32_t Speed(const int8_t) = 0
    //  (3) virtual uint32_t Time(uint32_t&) const = 0
    //  (4) virtual uint32_t Delay(uint32_t&) const = 0
    //

    class ExchangeBluetoothAudioSinkControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudioSink::IControl> {
    public:
        ExchangeBluetoothAudioSinkControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Acquire(const string& _connector, const Exchange::IBluetoothAudioSink::IControl::Format& _format) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_connector));
            writer.Number<uint32_t>(_format.SampleRate);
            writer.Number<uint16_t>(_format.FrameRate);
            writer.Number<uint8_t>(_format.Resolution);
            writer.Number<uint8_t>(_format.Channels);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Relinquish() override
        {
            IPCMessage message(BaseClass::Message(1));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Speed(const int8_t _speed) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int8_t>(_speed);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Time(uint32_t& _position) const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _position = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Delay(uint32_t& _delay) const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _delay = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeBluetoothAudioSinkControlProxy

    //
    // Exchange::IBluetoothAudioSink::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Updated() = 0
    //

    class ExchangeBluetoothAudioSinkCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IBluetoothAudioSink::ICallback> {
    public:
        ExchangeBluetoothAudioSinkCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Updated() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeBluetoothAudioSinkCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>, RPCIteratorTypeInstance124C3D5BStubMethods> RPCIteratorTypeInstance124C3D5BStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>, RPCIteratorTypeInstance281FF53BStubMethods> RPCIteratorTypeInstance281FF53BStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudioSink, ExchangeBluetoothAudioSinkStubMethods> ExchangeBluetoothAudioSinkStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudioSink::IControl, ExchangeBluetoothAudioSinkControlStubMethods> ExchangeBluetoothAudioSinkControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBluetoothAudioSink::ICallback, ExchangeBluetoothAudioSinkCallbackStubMethods> ExchangeBluetoothAudioSinkCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>, RPCIteratorTypeInstance124C3D5BProxy, RPCIteratorTypeInstance124C3D5BStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>, RPCIteratorTypeInstance281FF53BProxy, RPCIteratorTypeInstance281FF53BStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudioSink, ExchangeBluetoothAudioSinkProxy, ExchangeBluetoothAudioSinkStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudioSink::IControl, ExchangeBluetoothAudioSinkControlProxy, ExchangeBluetoothAudioSinkControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBluetoothAudioSink::ICallback, ExchangeBluetoothAudioSinkCallbackProxy, ExchangeBluetoothAudioSinkCallbackStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IBluetoothAudioSink::audiocodec, Exchange::ID_BLUETOOTHAUDIOSINK_AUDIOCODECITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IBluetoothAudioSink::drmscheme, Exchange::ID_BLUETOOTHAUDIOSINK_DRMSCHEMEITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudioSink>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudioSink::IControl>();
                RPC::Administrator::Instance().Recall<Exchange::IBluetoothAudioSink::ICallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
