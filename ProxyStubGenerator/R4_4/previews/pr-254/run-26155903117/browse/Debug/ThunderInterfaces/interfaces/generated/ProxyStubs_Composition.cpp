//
// generated automatically from "IComposition.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioCapability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Capability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Profile, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceVideoCapabilities::VideoOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IDeviceVideoCapabilities::ScreenResolution, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION]
//   - class Exchange::IComposition
//   - class Exchange::IComposition::IClient
//   - class Exchange::IComposition::IClient::IProperties
//   - class Exchange::IComposition::IRender
//   - class Exchange::IComposition::INotification
//   - class Exchange::IComposition::IDisplay
//   - class Exchange::IBrightness
//

#include "Module.h"
#include "IComposition.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance226C7F40 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance226C7F40StubMethods[] = {
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
    }; // RPCIteratorTypeInstance226C7F40StubMethods

    //
    // RPC::IIteratorTypeInstance66CCF245 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance66CCF245StubMethods[] = {
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
    }; // RPCIteratorTypeInstance66CCF245StubMethods

    //
    // RPC::IIteratorTypeInstanceD2F0771E interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceD2F0771EStubMethods[] = {
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
    }; // RPCIteratorTypeInstanceD2F0771EStubMethods

    //
    // RPC::IIteratorTypeInstance9AE4036E interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance9AE4036EStubMethods[] = {
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
    }; // RPCIteratorTypeInstance9AE4036EStubMethods

    //
    // RPC::IIteratorTypeInstanceA658B971 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceA658B971StubMethods[] = {
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
    }; // RPCIteratorTypeInstanceA658B971StubMethods

    //
    // RPC::IIteratorTypeInstanceE407EEB3 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceE407EEB3StubMethods[] = {
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
    }; // RPCIteratorTypeInstanceE407EEB3StubMethods

    //
    // Exchange::IComposition interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IComposition::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IComposition::INotification*) = 0
    //  (2) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (3) virtual uint32_t Resolution(const Exchange::IComposition::ScreenResolution) = 0
    //  (4) virtual Exchange::IComposition::ScreenResolution Resolution() const = 0
    //

    ProxyStub::MethodHandler ExchangeCompositionStubMethods[] = {
        // (0) virtual void Register(Exchange::IComposition::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IComposition::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            implementation->Register(_notification);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IComposition::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IComposition::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            implementation->Unregister(_notification);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
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

        // (3) virtual uint32_t Resolution(const Exchange::IComposition::ScreenResolution) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IComposition::ScreenResolution _parameter_37dd7dd9 = reader.Number<Exchange::IComposition::ScreenResolution>();

            uint32_t result = implementation->Resolution(_parameter_37dd7dd9);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual Exchange::IComposition::ScreenResolution Resolution() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition* implementation = reinterpret_cast<const Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IComposition::ScreenResolution result = implementation->Resolution();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IComposition::ScreenResolution>(result);
        }
        , nullptr
    }; // ExchangeCompositionStubMethods

    //
    // Exchange::IComposition::IClient interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::instance_id Native() const
    //  (1) virtual string Name() const = 0
    //  (2) virtual void Opacity(const uint32_t) = 0
    //  (3) virtual uint32_t Opacity() const
    //  (4) virtual uint32_t Geometry(const Exchange::IComposition::Rectangle&) = 0
    //  (5) virtual Exchange::IComposition::Rectangle Geometry() const = 0
    //  (6) virtual uint32_t ZOrder(const uint16_t) = 0
    //  (7) virtual uint32_t ZOrder() const = 0
    //

    ProxyStub::MethodHandler ExchangeCompositionClientStubMethods[] = {
        // (0) virtual Core::instance_id Native() const
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IClient* implementation = reinterpret_cast<const Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::instance_id result = implementation->Native();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(result);
        },

        // (1) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IClient* implementation = reinterpret_cast<const Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual void Opacity(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IClient* implementation = reinterpret_cast<Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _value = reader.Number<uint32_t>();

            implementation->Opacity(_value);
        },

        // (3) virtual uint32_t Opacity() const
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IClient* implementation = reinterpret_cast<const Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Opacity();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t Geometry(const Exchange::IComposition::Rectangle&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IClient* implementation = reinterpret_cast<Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::IComposition::Rectangle _rectangle{};
            _rectangle.x = reader.Number<uint32_t>();
            _rectangle.y = reader.Number<uint32_t>();
            _rectangle.width = reader.Number<uint32_t>();
            _rectangle.height = reader.Number<uint32_t>();

            uint32_t result = implementation->Geometry(static_cast<const Exchange::IComposition::Rectangle&>(_rectangle));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IComposition::Rectangle Geometry() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IClient* implementation = reinterpret_cast<const Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IComposition::Rectangle result = implementation->Geometry();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result.x);
            writer.Number<uint32_t>(result.y);
            writer.Number<uint32_t>(result.width);
            writer.Number<uint32_t>(result.height);
        },

        // (6) virtual uint32_t ZOrder(const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IClient* implementation = reinterpret_cast<Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _index = reader.Number<uint16_t>();

            uint32_t result = implementation->ZOrder(_index);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t ZOrder() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IClient* implementation = reinterpret_cast<const Exchange::IComposition::IClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->ZOrder();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeCompositionClientStubMethods

    //
    // Exchange::IComposition::IClient::IProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Stride() = 0
    //  (1) virtual uint32_t Format() = 0
    //  (2) virtual uint32_t Offset() = 0
    //  (3) virtual uint64_t Modifier() = 0
    //

    ProxyStub::MethodHandler ExchangeCompositionClientPropertiesStubMethods[] = {
        // (0) virtual uint32_t Stride() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IClient::IProperties* implementation = reinterpret_cast<Exchange::IComposition::IClient::IProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Stride();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t Format() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IClient::IProperties* implementation = reinterpret_cast<Exchange::IComposition::IClient::IProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Format();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Offset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IClient::IProperties* implementation = reinterpret_cast<Exchange::IComposition::IClient::IProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Offset();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint64_t Modifier() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IClient::IProperties* implementation = reinterpret_cast<Exchange::IComposition::IClient::IProperties*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t result = implementation->Modifier();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(result);
        }
        , nullptr
    }; // ExchangeCompositionClientPropertiesStubMethods

    //
    // Exchange::IComposition::IRender interface stub definitions
    //
    // Methods:
    //  (0) virtual void ScanOut() = 0
    //  (1) virtual void PreScanOut()
    //  (2) virtual void PostScanOut()
    //

    ProxyStub::MethodHandler ExchangeCompositionRenderStubMethods[] = {
        // (0) virtual void ScanOut() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IRender* implementation = reinterpret_cast<Exchange::IComposition::IRender*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->ScanOut();
        },

        // (1) virtual void PreScanOut()
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IRender* implementation = reinterpret_cast<Exchange::IComposition::IRender*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->PreScanOut();
        },

        // (2) virtual void PostScanOut()
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IRender* implementation = reinterpret_cast<Exchange::IComposition::IRender*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->PostScanOut();
        }
        , nullptr
    }; // ExchangeCompositionRenderStubMethods

    //
    // Exchange::IComposition::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Attached(const string&, Exchange::IComposition::IClient*) = 0
    //  (1) virtual void Detached(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeCompositionNotificationStubMethods[] = {
        // (0) virtual void Attached(const string&, Exchange::IComposition::IClient*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::INotification* implementation = reinterpret_cast<Exchange::IComposition::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();
            const Core::instance_id clientImplementation = reader.Number<Core::instance_id>();

            Exchange::IComposition::IClient* _client = nullptr;
            ProxyStub::UnknownProxy* clientProxy = nullptr;
            if (clientImplementation != 0) {
                clientProxy = RPC::Administrator::Instance().ProxyInstance(channel, clientImplementation, false, _client);

                ASSERT((_client != nullptr) && (clientProxy != nullptr));
            }

            implementation->Attached(static_cast<const string&>(_name), _client);

            if (clientProxy != nullptr) {
                RPC::Administrator::Instance().Release(clientProxy, message->Response());
            }
        },

        // (1) virtual void Detached(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::INotification* implementation = reinterpret_cast<Exchange::IComposition::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            implementation->Detached(static_cast<const string&>(_name));
        }
        , nullptr
    }; // ExchangeCompositionNotificationStubMethods

    //
    // Exchange::IComposition::IDisplay interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::instance_id Native() const = 0
    //  (1) virtual string Port() const = 0
    //  (2) virtual Exchange::IComposition::IClient* CreateClient(const string&, const uint32_t, const uint32_t) = 0
    //  (3) virtual uint32_t Resolution(const Exchange::IComposition::ScreenResolution) = 0
    //  (4) virtual Exchange::IComposition::ScreenResolution Resolution() const = 0
    //

    ProxyStub::MethodHandler ExchangeCompositionDisplayStubMethods[] = {
        // (0) virtual Core::instance_id Native() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IDisplay* implementation = reinterpret_cast<const Exchange::IComposition::IDisplay*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::instance_id result = implementation->Native();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(result);
        },

        // (1) virtual string Port() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IDisplay* implementation = reinterpret_cast<const Exchange::IComposition::IDisplay*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Port();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual Exchange::IComposition::IClient* CreateClient(const string&, const uint32_t, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IDisplay* implementation = reinterpret_cast<Exchange::IComposition::IDisplay*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();
            const uint32_t _width = reader.Number<uint32_t>();
            const uint32_t _height = reader.Number<uint32_t>();

            Exchange::IComposition::IClient* result = implementation->CreateClient(static_cast<const string&>(_name), _width, _height);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (3) virtual uint32_t Resolution(const Exchange::IComposition::ScreenResolution) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::IDisplay* implementation = reinterpret_cast<Exchange::IComposition::IDisplay*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IComposition::ScreenResolution _parameter_602d442e = reader.Number<Exchange::IComposition::ScreenResolution>();

            uint32_t result = implementation->Resolution(_parameter_602d442e);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual Exchange::IComposition::ScreenResolution Resolution() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IComposition::IDisplay* implementation = reinterpret_cast<const Exchange::IComposition::IDisplay*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IComposition::ScreenResolution result = implementation->Resolution();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IComposition::ScreenResolution>(result);
        }
        , nullptr
    }; // ExchangeCompositionDisplayStubMethods

    //
    // Exchange::IBrightness interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t SdrToHdrGraphicsBrightness(Exchange::IBrightness::Brightness&) const = 0
    //  (1) virtual uint32_t SdrToHdrGraphicsBrightness(const Exchange::IBrightness::Brightness&) = 0
    //

    ProxyStub::MethodHandler ExchangeBrightnessStubMethods[] = {
        // (0) virtual uint32_t SdrToHdrGraphicsBrightness(Exchange::IBrightness::Brightness&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrightness* implementation = reinterpret_cast<const Exchange::IBrightness*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBrightness::Brightness _brightness{};

            uint32_t result = implementation->SdrToHdrGraphicsBrightness(_brightness);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IBrightness::Brightness>(_brightness);
        },

        // (1) virtual uint32_t SdrToHdrGraphicsBrightness(const Exchange::IBrightness::Brightness&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrightness* implementation = reinterpret_cast<Exchange::IBrightness*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IBrightness::Brightness _brightness = reader.Number<Exchange::IBrightness::Brightness>();

            uint32_t result = implementation->SdrToHdrGraphicsBrightness(static_cast<const Exchange::IBrightness::Brightness&>(_brightness));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeBrightnessStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance226C7F40 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
    //

    class RPCIteratorTypeInstance226C7F40Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>> {
    public:
        RPCIteratorTypeInstance226C7F40Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstance226C7F40Proxy

    //
    // RPC::IIteratorTypeInstance66CCF245 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
    //

    class RPCIteratorTypeInstance66CCF245Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>> {
    public:
        RPCIteratorTypeInstance66CCF245Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstance66CCF245Proxy

    //
    // RPC::IIteratorTypeInstanceD2F0771E interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
    //

    class RPCIteratorTypeInstanceD2F0771EProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>> {
    public:
        RPCIteratorTypeInstanceD2F0771EProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstanceD2F0771EProxy

    //
    // RPC::IIteratorTypeInstance9AE4036E interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
    //

    class RPCIteratorTypeInstance9AE4036EProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>> {
    public:
        RPCIteratorTypeInstance9AE4036EProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstance9AE4036EProxy

    //
    // RPC::IIteratorTypeInstanceA658B971 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
    //

    class RPCIteratorTypeInstanceA658B971Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>> {
    public:
        RPCIteratorTypeInstanceA658B971Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstanceA658B971Proxy

    //
    // RPC::IIteratorTypeInstanceE407EEB3 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
    //

    class RPCIteratorTypeInstanceE407EEB3Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>> {
    public:
        RPCIteratorTypeInstanceE407EEB3Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstanceE407EEB3Proxy

    //
    // Exchange::IComposition interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IComposition::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IComposition::INotification*) = 0
    //  (2) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (3) virtual uint32_t Resolution(const Exchange::IComposition::ScreenResolution) = 0
    //  (4) virtual Exchange::IComposition::ScreenResolution Resolution() const = 0
    //

    class ExchangeCompositionProxy final : public ProxyStub::UnknownProxyType<Exchange::IComposition> {
    public:
        ExchangeCompositionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IComposition::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IComposition::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Configure(PluginHost::IShell* _service) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Resolution(const Exchange::IComposition::ScreenResolution _parameter_37dd7dd9) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IComposition::ScreenResolution>(_parameter_37dd7dd9);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IComposition::ScreenResolution Resolution() const override
        {
            IPCMessage message(BaseClass::Message(4));

            Exchange::IComposition::ScreenResolution result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IComposition::ScreenResolution>();

            return (result);
        }

    }; // class ExchangeCompositionProxy

    //
    // Exchange::IComposition::IClient interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::instance_id Native() const
    //  (1) virtual string Name() const = 0
    //  (2) virtual void Opacity(const uint32_t) = 0
    //  (3) virtual uint32_t Opacity() const
    //  (4) virtual uint32_t Geometry(const Exchange::IComposition::Rectangle&) = 0
    //  (5) virtual Exchange::IComposition::Rectangle Geometry() const = 0
    //  (6) virtual uint32_t ZOrder(const uint16_t) = 0
    //  (7) virtual uint32_t ZOrder() const = 0
    //

    class ExchangeCompositionClientProxy final : public ProxyStub::UnknownProxyType<Exchange::IComposition::IClient> {
    public:
        ExchangeCompositionClientProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::instance_id Native() const override
        {
            IPCMessage message(BaseClass::Message(0));

            Core::instance_id result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Core::instance_id>();

            return (result);
        }

        string Name() const override
        {
            IPCMessage message(BaseClass::Message(1));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Opacity(const uint32_t _value) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_value);

            UnknownProxyType::Invoke(message);
        }

        uint32_t Opacity() const override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Geometry(const Exchange::IComposition::Rectangle& _rectangle) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_rectangle.x);
            writer.Number<uint32_t>(_rectangle.y);
            writer.Number<uint32_t>(_rectangle.width);
            writer.Number<uint32_t>(_rectangle.height);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IComposition::Rectangle Geometry() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IComposition::Rectangle result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result.x = reader.Number<uint32_t>();
            result.y = reader.Number<uint32_t>();
            result.width = reader.Number<uint32_t>();
            result.height = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t ZOrder(const uint16_t _index) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_index);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t ZOrder() const override
        {
            IPCMessage message(BaseClass::Message(7));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeCompositionClientProxy

    //
    // Exchange::IComposition::IClient::IProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Stride() = 0
    //  (1) virtual uint32_t Format() = 0
    //  (2) virtual uint32_t Offset() = 0
    //  (3) virtual uint64_t Modifier() = 0
    //

    class ExchangeCompositionClientPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IComposition::IClient::IProperties> {
    public:
        ExchangeCompositionClientPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Stride() override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Format() override
        {
            IPCMessage message(BaseClass::Message(1));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Offset() override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint64_t Modifier() override
        {
            IPCMessage message(BaseClass::Message(3));

            uint64_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint64_t>();

            return (result);
        }

    }; // class ExchangeCompositionClientPropertiesProxy

    //
    // Exchange::IComposition::IRender interface proxy definitions
    //
    // Methods:
    //  (0) virtual void ScanOut() = 0
    //  (1) virtual void PreScanOut()
    //  (2) virtual void PostScanOut()
    //

    class ExchangeCompositionRenderProxy final : public ProxyStub::UnknownProxyType<Exchange::IComposition::IRender> {
    public:
        ExchangeCompositionRenderProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void ScanOut() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

        void PreScanOut() override
        {
            IPCMessage message(BaseClass::Message(1));

            UnknownProxyType::Invoke(message);
        }

        void PostScanOut() override
        {
            IPCMessage message(BaseClass::Message(2));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeCompositionRenderProxy

    //
    // Exchange::IComposition::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Attached(const string&, Exchange::IComposition::IClient*) = 0
    //  (1) virtual void Detached(const string&) = 0
    //

    class ExchangeCompositionNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IComposition::INotification> {
    public:
        ExchangeCompositionNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Attached(const string& _name, Exchange::IComposition::IClient* _client) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));
            writer.Number<Core::instance_id>(RPC::instance_cast(_client));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Detached(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeCompositionNotificationProxy

    //
    // Exchange::IComposition::IDisplay interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::instance_id Native() const = 0
    //  (1) virtual string Port() const = 0
    //  (2) virtual Exchange::IComposition::IClient* CreateClient(const string&, const uint32_t, const uint32_t) = 0
    //  (3) virtual uint32_t Resolution(const Exchange::IComposition::ScreenResolution) = 0
    //  (4) virtual Exchange::IComposition::ScreenResolution Resolution() const = 0
    //

    class ExchangeCompositionDisplayProxy final : public ProxyStub::UnknownProxyType<Exchange::IComposition::IDisplay> {
    public:
        ExchangeCompositionDisplayProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::instance_id Native() const override
        {
            IPCMessage message(BaseClass::Message(0));

            Core::instance_id result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Core::instance_id>();

            return (result);
        }

        string Port() const override
        {
            IPCMessage message(BaseClass::Message(1));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        Exchange::IComposition::IClient* CreateClient(const string& _name, const uint32_t _width, const uint32_t _height) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));
            writer.Number<uint32_t>(_width);
            writer.Number<uint32_t>(_height);

            Exchange::IComposition::IClient* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IComposition::IClient*>(Interface(reader.Number<Core::instance_id>(), Exchange::IComposition::IClient::ID));

            return (result);
        }

        uint32_t Resolution(const Exchange::IComposition::ScreenResolution _parameter_602d442e) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IComposition::ScreenResolution>(_parameter_602d442e);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IComposition::ScreenResolution Resolution() const override
        {
            IPCMessage message(BaseClass::Message(4));

            Exchange::IComposition::ScreenResolution result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::IComposition::ScreenResolution>();

            return (result);
        }

    }; // class ExchangeCompositionDisplayProxy

    //
    // Exchange::IBrightness interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t SdrToHdrGraphicsBrightness(Exchange::IBrightness::Brightness&) const = 0
    //  (1) virtual uint32_t SdrToHdrGraphicsBrightness(const Exchange::IBrightness::Brightness&) = 0
    //

    class ExchangeBrightnessProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrightness> {
    public:
        ExchangeBrightnessProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t SdrToHdrGraphicsBrightness(Exchange::IBrightness::Brightness& _brightness) const override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _brightness = reader.Number<Exchange::IBrightness::Brightness>();

            return (result);
        }

        uint32_t SdrToHdrGraphicsBrightness(const Exchange::IBrightness::Brightness& _brightness) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IBrightness::Brightness>(static_cast<const Exchange::IBrightness::Brightness&>(_brightness));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

    }; // class ExchangeBrightnessProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>, RPCIteratorTypeInstance226C7F40StubMethods> RPCIteratorTypeInstance226C7F40Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>, RPCIteratorTypeInstance66CCF245StubMethods> RPCIteratorTypeInstance66CCF245Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>, RPCIteratorTypeInstanceD2F0771EStubMethods> RPCIteratorTypeInstanceD2F0771EStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>, RPCIteratorTypeInstance9AE4036EStubMethods> RPCIteratorTypeInstance9AE4036EStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>, RPCIteratorTypeInstanceA658B971StubMethods> RPCIteratorTypeInstanceA658B971Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>, RPCIteratorTypeInstanceE407EEB3StubMethods> RPCIteratorTypeInstanceE407EEB3Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition, ExchangeCompositionStubMethods> ExchangeCompositionStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::IClient, ExchangeCompositionClientStubMethods> ExchangeCompositionClientStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::IClient::IProperties, ExchangeCompositionClientPropertiesStubMethods> ExchangeCompositionClientPropertiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::IRender, ExchangeCompositionRenderStubMethods> ExchangeCompositionRenderStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::INotification, ExchangeCompositionNotificationStubMethods> ExchangeCompositionNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::IDisplay, ExchangeCompositionDisplayStubMethods> ExchangeCompositionDisplayStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrightness, ExchangeBrightnessStubMethods> ExchangeBrightnessStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>, RPCIteratorTypeInstance226C7F40Proxy, RPCIteratorTypeInstance226C7F40Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>, RPCIteratorTypeInstance66CCF245Proxy, RPCIteratorTypeInstance66CCF245Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>, RPCIteratorTypeInstanceD2F0771EProxy, RPCIteratorTypeInstanceD2F0771EStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>, RPCIteratorTypeInstance9AE4036EProxy, RPCIteratorTypeInstance9AE4036EStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>, RPCIteratorTypeInstanceA658B971Proxy, RPCIteratorTypeInstanceA658B971Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>, RPCIteratorTypeInstanceE407EEB3Proxy, RPCIteratorTypeInstanceE407EEB3Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition, ExchangeCompositionProxy, ExchangeCompositionStub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition::IClient, ExchangeCompositionClientProxy, ExchangeCompositionClientStub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition::IClient::IProperties, ExchangeCompositionClientPropertiesProxy, ExchangeCompositionClientPropertiesStub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition::IRender, ExchangeCompositionRenderProxy, ExchangeCompositionRenderStub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition::INotification, ExchangeCompositionNotificationProxy, ExchangeCompositionNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition::IDisplay, ExchangeCompositionDisplayProxy, ExchangeCompositionDisplayStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrightness, ExchangeBrightnessProxy, ExchangeBrightnessStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>>();
                RPC::Administrator::Instance().Recall<Exchange::IComposition>();
                RPC::Administrator::Instance().Recall<Exchange::IComposition::IClient>();
                RPC::Administrator::Instance().Recall<Exchange::IComposition::IClient::IProperties>();
                RPC::Administrator::Instance().Recall<Exchange::IComposition::IRender>();
                RPC::Administrator::Instance().Recall<Exchange::IComposition::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IComposition::IDisplay>();
                RPC::Administrator::Instance().Recall<Exchange::IBrightness>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
