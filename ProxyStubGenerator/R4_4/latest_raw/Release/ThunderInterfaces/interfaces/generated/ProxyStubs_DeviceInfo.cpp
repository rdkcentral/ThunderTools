//
// generated automatically from "IDeviceInfo.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioCapability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Capability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Profile, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceVideoCapabilities::VideoOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceVideoCapabilities::ScreenResolution, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION]
//   - class Exchange::IDeviceInfo
//   - class Exchange::IDeviceAudioCapabilities
//   - class Exchange::IDeviceVideoCapabilities
//

#include "Module.h"
#include "IDeviceInfo.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance14E658F7 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance14E658F7StubMethods[] = {
        // (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::AudioOutput _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_info);
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::AudioOutput _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::AudioOutput result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance14E658F7StubMethods

    //
    // RPC::IIteratorTypeInstanceF18AD6E1 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceF18AD6E1StubMethods[] = {
        // (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::AudioCapability _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>(_info);
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::AudioCapability _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::AudioCapability result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstanceF18AD6E1StubMethods

    //
    // RPC::IIteratorTypeInstanceBB80C46B interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceBB80C46BStubMethods[] = {
        // (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::MS12Capability _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>(_info);
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::MS12Capability _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::MS12Capability result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstanceBB80C46BStubMethods

    //
    // RPC::IIteratorTypeInstance13575469 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance13575469StubMethods[] = {
        // (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::MS12Profile _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>(_info);
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::MS12Profile _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::MS12Profile result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance13575469StubMethods

    //
    // RPC::IIteratorTypeInstanceF42528E2 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceF42528E2StubMethods[] = {
        // (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceVideoCapabilities::VideoOutput _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_info);
        },

        // (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceVideoCapabilities::VideoOutput _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceVideoCapabilities::VideoOutput result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstanceF42528E2StubMethods

    //
    // RPC::IIteratorTypeInstance8CD36199 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance8CD36199StubMethods[] = {
        // (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceVideoCapabilities::ScreenResolution _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(_info);
        },

        // (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceVideoCapabilities::ScreenResolution _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceVideoCapabilities::ScreenResolution result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance8CD36199StubMethods

    //
    // Exchange::IDeviceInfo interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(const PluginHost::IShell*) = 0
    //  (1) virtual uint32_t SerialNumber(string&) const = 0
    //  (2) virtual uint32_t Sku(string&) const = 0
    //  (3) virtual uint32_t Make(string&) const = 0
    //  (4) virtual uint32_t ModelName(string&) const = 0
    //  (5) virtual uint32_t ModelYear(uint16_t&) const = 0
    //  (6) virtual uint32_t FriendlyName(string&) const = 0
    //  (7) virtual uint32_t DeviceType(string&) const = 0
    //  (8) virtual uint32_t PlatformName(string&) const = 0
    //  (9) virtual uint32_t DistributorId(string&) const = 0
    //

    ProxyStub::MethodHandler ExchangeDeviceInfoStubMethods[] = {
        // (0) virtual uint32_t Configure(const PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDeviceInfo* implementation = reinterpret_cast<Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id serviceImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _service = nullptr;
            ProxyStub::UnknownProxy* serviceProxy = nullptr;
            if (serviceImplementation != 0) {
                serviceProxy = RPC::Administrator::Instance().ProxyInstance(channel, serviceImplementation, false, _service);

                ASSERT((_service != nullptr) && (serviceProxy != nullptr));
            }

            uint32_t result = implementation->Configure(_service);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (serviceProxy != nullptr) {
                RPC::Administrator::Instance().Release(serviceProxy, message->Response());
            }
        },

        // (1) virtual uint32_t SerialNumber(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->SerialNumber(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (2) virtual uint32_t Sku(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->Sku(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (3) virtual uint32_t Make(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->Make(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (4) virtual uint32_t ModelName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->ModelName(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (5) virtual uint32_t ModelYear(uint16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint16_t _value{};

            uint32_t result = implementation->ModelYear(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint16_t>(_value);
        },

        // (6) virtual uint32_t FriendlyName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->FriendlyName(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (7) virtual uint32_t DeviceType(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->DeviceType(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (8) virtual uint32_t PlatformName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->PlatformName(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (9) virtual uint32_t DistributorId(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->DistributorId(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        }
        , nullptr
    }; // ExchangeDeviceInfoStubMethods

    //
    // Exchange::IDeviceAudioCapabilities interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t AudioOutputs(Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*&) const = 0
    //  (1) virtual uint32_t AudioCapabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*&) const = 0
    //  (2) virtual uint32_t MS12Capabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*&) const = 0
    //  (3) virtual uint32_t MS12AudioProfiles(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*&) const = 0
    //

    ProxyStub::MethodHandler ExchangeDeviceAudioCapabilitiesStubMethods[] = {
        // (0) virtual uint32_t AudioOutputs(Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceAudioCapabilities::IAudioOutputIterator* _audioOutputs{};

            uint32_t result = implementation->AudioOutputs(_audioOutputs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_audioOutputs));

            RPC::Administrator::Instance().RegisterInterface(channel, _audioOutputs);
        },

        // (1) virtual uint32_t AudioCapabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

            Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator* _audioCapabilities{};

            uint32_t result = implementation->AudioCapabilities(_audioOutput, _audioCapabilities);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_audioCapabilities));

            RPC::Administrator::Instance().RegisterInterface(channel, _audioCapabilities);
        },

        // (2) virtual uint32_t MS12Capabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

            Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator* _ms12Capabilities{};

            uint32_t result = implementation->MS12Capabilities(_audioOutput, _ms12Capabilities);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_ms12Capabilities));

            RPC::Administrator::Instance().RegisterInterface(channel, _ms12Capabilities);
        },

        // (3) virtual uint32_t MS12AudioProfiles(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

            Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator* _ms12Profiles{};

            uint32_t result = implementation->MS12AudioProfiles(_audioOutput, _ms12Profiles);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_ms12Profiles));

            RPC::Administrator::Instance().RegisterInterface(channel, _ms12Profiles);
        }
        , nullptr
    }; // ExchangeDeviceAudioCapabilitiesStubMethods

    //
    // Exchange::IDeviceVideoCapabilities interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t VideoOutputs(Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*&) const = 0
    //  (1) virtual uint32_t DefaultResolution(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::ScreenResolution&) const = 0
    //  (2) virtual uint32_t Resolutions(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*&) const = 0
    //  (3) virtual uint32_t Hdcp(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::CopyProtection&) const = 0
    //  (4) virtual uint32_t HostEDID(string&) const = 0
    //  (5) virtual uint32_t HDR(bool&) const = 0
    //  (6) virtual uint32_t Atmos(bool&) const = 0
    //  (7) virtual uint32_t CEC(bool&) const = 0
    //

    ProxyStub::MethodHandler ExchangeDeviceVideoCapabilitiesStubMethods[] = {
        // (0) virtual uint32_t VideoOutputs(Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IDeviceVideoCapabilities::IVideoOutputIterator* _videoOutputs{};

            uint32_t result = implementation->VideoOutputs(_videoOutputs);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_videoOutputs));

            RPC::Administrator::Instance().RegisterInterface(channel, _videoOutputs);
        },

        // (1) virtual uint32_t DefaultResolution(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::ScreenResolution&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

            Exchange::IDeviceVideoCapabilities::ScreenResolution _defaultResolution{};

            uint32_t result = implementation->DefaultResolution(_videoOutput, _defaultResolution);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(_defaultResolution);
        },

        // (2) virtual uint32_t Resolutions(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

            Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator* _resolutions{};

            uint32_t result = implementation->Resolutions(_videoOutput, _resolutions);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_resolutions));

            RPC::Administrator::Instance().RegisterInterface(channel, _resolutions);
        },

        // (3) virtual uint32_t Hdcp(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::CopyProtection&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

            Exchange::IDeviceVideoCapabilities::CopyProtection _hdcpVersion{};

            uint32_t result = implementation->Hdcp(_videoOutput, _hdcpVersion);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IDeviceVideoCapabilities::CopyProtection>(_hdcpVersion);
        },

        // (4) virtual uint32_t HostEDID(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _edid{};

            uint32_t result = implementation->HostEDID(_edid);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_edid);
        },

        // (5) virtual uint32_t HDR(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _supportsHDR{};

            uint32_t result = implementation->HDR(_supportsHDR);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_supportsHDR);
        },

        // (6) virtual uint32_t Atmos(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _supportsAtmos{};

            uint32_t result = implementation->Atmos(_supportsAtmos);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_supportsAtmos);
        },

        // (7) virtual uint32_t CEC(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _supportsCEC{};

            uint32_t result = implementation->CEC(_supportsCEC);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_supportsCEC);
        }
        , nullptr
    }; // ExchangeDeviceVideoCapabilitiesStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance14E658F7 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
    //

    class RPCIteratorTypeInstance14E658F7Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>> {
    public:
        RPCIteratorTypeInstance14E658F7Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

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

        Exchange::IDeviceAudioCapabilities::AudioOutput Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IDeviceAudioCapabilities::AudioOutput result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

            return (result);
        }

    }; // class RPCIteratorTypeInstance14E658F7Proxy

    //
    // RPC::IIteratorTypeInstanceF18AD6E1 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
    //

    class RPCIteratorTypeInstanceF18AD6E1Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>> {
    public:
        RPCIteratorTypeInstanceF18AD6E1Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();

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

        Exchange::IDeviceAudioCapabilities::AudioCapability Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IDeviceAudioCapabilities::AudioCapability result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceF18AD6E1Proxy

    //
    // RPC::IIteratorTypeInstanceBB80C46B interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
    //

    class RPCIteratorTypeInstanceBB80C46BProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>> {
    public:
        RPCIteratorTypeInstanceBB80C46BProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();

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

        Exchange::IDeviceAudioCapabilities::MS12Capability Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IDeviceAudioCapabilities::MS12Capability result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceBB80C46BProxy

    //
    // RPC::IIteratorTypeInstance13575469 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
    //

    class RPCIteratorTypeInstance13575469Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>> {
    public:
        RPCIteratorTypeInstance13575469Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();

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

        Exchange::IDeviceAudioCapabilities::MS12Profile Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IDeviceAudioCapabilities::MS12Profile result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();

            return (result);
        }

    }; // class RPCIteratorTypeInstance13575469Proxy

    //
    // RPC::IIteratorTypeInstanceF42528E2 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
    //

    class RPCIteratorTypeInstanceF42528E2Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>> {
    public:
        RPCIteratorTypeInstanceF42528E2Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

            return (result);
        }

        bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

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

        Exchange::IDeviceVideoCapabilities::VideoOutput Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IDeviceVideoCapabilities::VideoOutput result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceF42528E2Proxy

    //
    // RPC::IIteratorTypeInstance8CD36199 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
    //

    class RPCIteratorTypeInstance8CD36199Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>> {
    public:
        RPCIteratorTypeInstance8CD36199Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

            return (result);
        }

        bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

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

        Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IDeviceVideoCapabilities::ScreenResolution result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

            return (result);
        }

    }; // class RPCIteratorTypeInstance8CD36199Proxy

    //
    // Exchange::IDeviceInfo interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(const PluginHost::IShell*) = 0
    //  (1) virtual uint32_t SerialNumber(string&) const = 0
    //  (2) virtual uint32_t Sku(string&) const = 0
    //  (3) virtual uint32_t Make(string&) const = 0
    //  (4) virtual uint32_t ModelName(string&) const = 0
    //  (5) virtual uint32_t ModelYear(uint16_t&) const = 0
    //  (6) virtual uint32_t FriendlyName(string&) const = 0
    //  (7) virtual uint32_t DeviceType(string&) const = 0
    //  (8) virtual uint32_t PlatformName(string&) const = 0
    //  (9) virtual uint32_t DistributorId(string&) const = 0
    //

    class ExchangeDeviceInfoProxy final : public ProxyStub::UnknownProxyType<Exchange::IDeviceInfo> {
    public:
        ExchangeDeviceInfoProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Configure(const PluginHost::IShell* _service) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t SerialNumber(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(1));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        uint32_t Sku(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        uint32_t Make(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        uint32_t ModelName(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        uint32_t ModelYear(uint16_t& _value) const override
        {
            IPCMessage message(BaseClass::Message(5));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Number<uint16_t>();

            return (result);
        }

        uint32_t FriendlyName(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(6));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        uint32_t DeviceType(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(7));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        uint32_t PlatformName(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(8));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

        uint32_t DistributorId(string& _value) const override
        {
            IPCMessage message(BaseClass::Message(9));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _value = reader.Text();

            return (result);
        }

    }; // class ExchangeDeviceInfoProxy

    //
    // Exchange::IDeviceAudioCapabilities interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t AudioOutputs(Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*&) const = 0
    //  (1) virtual uint32_t AudioCapabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*&) const = 0
    //  (2) virtual uint32_t MS12Capabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*&) const = 0
    //  (3) virtual uint32_t MS12AudioProfiles(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*&) const = 0
    //

    class ExchangeDeviceAudioCapabilitiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IDeviceAudioCapabilities> {
    public:
        ExchangeDeviceAudioCapabilitiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t AudioOutputs(Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*& _audioOutputs) const override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _audioOutputs = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IAudioOutputIterator::ID));

            return (result);
        }

        uint32_t AudioCapabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput, Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*& _audioCapabilities) const override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_audioOutput);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _audioCapabilities = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator::ID));

            return (result);
        }

        uint32_t MS12Capabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput, Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*& _ms12Capabilities) const override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_audioOutput);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _ms12Capabilities = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator::ID));

            return (result);
        }

        uint32_t MS12AudioProfiles(const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput, Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*& _ms12Profiles) const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_audioOutput);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _ms12Profiles = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator::ID));

            return (result);
        }

    }; // class ExchangeDeviceAudioCapabilitiesProxy

    //
    // Exchange::IDeviceVideoCapabilities interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t VideoOutputs(Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*&) const = 0
    //  (1) virtual uint32_t DefaultResolution(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::ScreenResolution&) const = 0
    //  (2) virtual uint32_t Resolutions(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*&) const = 0
    //  (3) virtual uint32_t Hdcp(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::CopyProtection&) const = 0
    //  (4) virtual uint32_t HostEDID(string&) const = 0
    //  (5) virtual uint32_t HDR(bool&) const = 0
    //  (6) virtual uint32_t Atmos(bool&) const = 0
    //  (7) virtual uint32_t CEC(bool&) const = 0
    //

    class ExchangeDeviceVideoCapabilitiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IDeviceVideoCapabilities> {
    public:
        ExchangeDeviceVideoCapabilitiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t VideoOutputs(Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*& _videoOutputs) const override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _videoOutputs = reinterpret_cast<Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceVideoCapabilities::IVideoOutputIterator::ID));

            return (result);
        }

        uint32_t DefaultResolution(const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput, Exchange::IDeviceVideoCapabilities::ScreenResolution& _defaultResolution) const override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_videoOutput);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _defaultResolution = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

            return (result);
        }

        uint32_t Resolutions(const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput, Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*& _resolutions) const override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_videoOutput);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _resolutions = reinterpret_cast<Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator::ID));

            return (result);
        }

        uint32_t Hdcp(const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput, Exchange::IDeviceVideoCapabilities::CopyProtection& _hdcpVersion) const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_videoOutput);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _hdcpVersion = reader.Number<Exchange::IDeviceVideoCapabilities::CopyProtection>();

            return (result);
        }

        uint32_t HostEDID(string& _edid) const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _edid = reader.Text();

            return (result);
        }

        uint32_t HDR(bool& _supportsHDR) const override
        {
            IPCMessage message(BaseClass::Message(5));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _supportsHDR = reader.Boolean();

            return (result);
        }

        uint32_t Atmos(bool& _supportsAtmos) const override
        {
            IPCMessage message(BaseClass::Message(6));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _supportsAtmos = reader.Boolean();

            return (result);
        }

        uint32_t CEC(bool& _supportsCEC) const override
        {
            IPCMessage message(BaseClass::Message(7));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _supportsCEC = reader.Boolean();

            return (result);
        }

    }; // class ExchangeDeviceVideoCapabilitiesProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>, RPCIteratorTypeInstance14E658F7StubMethods> RPCIteratorTypeInstance14E658F7Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>, RPCIteratorTypeInstanceF18AD6E1StubMethods> RPCIteratorTypeInstanceF18AD6E1Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>, RPCIteratorTypeInstanceBB80C46BStubMethods> RPCIteratorTypeInstanceBB80C46BStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>, RPCIteratorTypeInstance13575469StubMethods> RPCIteratorTypeInstance13575469Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>, RPCIteratorTypeInstanceF42528E2StubMethods> RPCIteratorTypeInstanceF42528E2Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>, RPCIteratorTypeInstance8CD36199StubMethods> RPCIteratorTypeInstance8CD36199Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IDeviceInfo, ExchangeDeviceInfoStubMethods> ExchangeDeviceInfoStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDeviceAudioCapabilities, ExchangeDeviceAudioCapabilitiesStubMethods> ExchangeDeviceAudioCapabilitiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDeviceVideoCapabilities, ExchangeDeviceVideoCapabilitiesStubMethods> ExchangeDeviceVideoCapabilitiesStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>, RPCIteratorTypeInstance14E658F7Proxy, RPCIteratorTypeInstance14E658F7Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>, RPCIteratorTypeInstanceF18AD6E1Proxy, RPCIteratorTypeInstanceF18AD6E1Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>, RPCIteratorTypeInstanceBB80C46BProxy, RPCIteratorTypeInstanceBB80C46BStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>, RPCIteratorTypeInstance13575469Proxy, RPCIteratorTypeInstance13575469Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>, RPCIteratorTypeInstanceF42528E2Proxy, RPCIteratorTypeInstanceF42528E2Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>, RPCIteratorTypeInstance8CD36199Proxy, RPCIteratorTypeInstance8CD36199Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IDeviceInfo, ExchangeDeviceInfoProxy, ExchangeDeviceInfoStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDeviceAudioCapabilities, ExchangeDeviceAudioCapabilitiesProxy, ExchangeDeviceAudioCapabilitiesStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDeviceVideoCapabilities, ExchangeDeviceVideoCapabilitiesProxy, ExchangeDeviceVideoCapabilitiesStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>>();
                RPC::Administrator::Instance().Recall<Exchange::IDeviceInfo>();
                RPC::Administrator::Instance().Recall<Exchange::IDeviceAudioCapabilities>();
                RPC::Administrator::Instance().Recall<Exchange::IDeviceVideoCapabilities>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
