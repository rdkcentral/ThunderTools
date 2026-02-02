//
// generated automatically from "IComposition.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioCapability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Capability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Profile, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceVideoCapabilities::VideoOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceVideoCapabilities::ScreenResolution, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION] [[iterator]]
//   - class Exchange::IComposition
//   - class Exchange::IComposition::IClient
//   - class Exchange::IComposition::INotification
//   - class Exchange::IComposition::IDisplay
//   - class Exchange::IBrightness
//

#include "Module.h"
#include "IComposition.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_c05b33a2ffea23f6 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_c05b33a2ffea23f6StubMethods[] = {
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
    }; // RPCIteratorTypeInstance_c05b33a2ffea23f6StubMethods

    //
    // RPC::IIteratorTypeInstance_47f9365de0b38ac1 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_47f9365de0b38ac1StubMethods[] = {
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
    }; // RPCIteratorTypeInstance_47f9365de0b38ac1StubMethods

    //
    // RPC::IIteratorTypeInstance_ed3acc81bd14fad7 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_ed3acc81bd14fad7StubMethods[] = {
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
    }; // RPCIteratorTypeInstance_ed3acc81bd14fad7StubMethods

    //
    // RPC::IIteratorTypeInstance_291157d7989c288e interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_291157d7989c288eStubMethods[] = {
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
    }; // RPCIteratorTypeInstance_291157d7989c288eStubMethods

    //
    // RPC::IIteratorTypeInstance_0abf4e195a83835b interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_0abf4e195a83835bStubMethods[] = {
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
    }; // RPCIteratorTypeInstance_0abf4e195a83835bStubMethods

    //
    // RPC::IIteratorTypeInstance_848ec395838dfece interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_848ec395838dfeceStubMethods[] = {
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
    }; // RPCIteratorTypeInstance_848ec395838dfeceStubMethods

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

    static ProxyStub::MethodHandler ExchangeCompositionStubMethods[] = {
        // (0) virtual void Register(Exchange::IComposition::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IComposition::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            implementation->Register(_notification);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IComposition::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IComposition::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            implementation->Unregister(_notification);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _serviceInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _service{};
            ProxyStub::UnknownProxy* _serviceProxy__ = nullptr;
            if (_serviceInstanceId__ != 0) {
                _serviceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _serviceInstanceId__, false, _service);
                ASSERT((_service != nullptr) && (_serviceProxy__ != nullptr));
            }

            uint32_t result = implementation->Configure(_service);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_serviceProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_serviceProxy__, message->Response());
            }
        },

        // (3) virtual uint32_t Resolution(const Exchange::IComposition::ScreenResolution) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition* implementation = reinterpret_cast<Exchange::IComposition*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IComposition::ScreenResolution _parameter_ef72b6a6 = reader.Number<Exchange::IComposition::ScreenResolution>();

            uint32_t result = implementation->Resolution(_parameter_ef72b6a6);

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

    static ProxyStub::MethodHandler ExchangeCompositionClientStubMethods[] = {
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
            _rectangle.x = reader.Number<int32_t>();
            _rectangle.y = reader.Number<int32_t>();
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
            writer.Number<int32_t>(result.x);
            writer.Number<int32_t>(result.y);
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
    // Exchange::IComposition::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Attached(const string&, Exchange::IComposition::IClient*) = 0
    //  (1) virtual void Detached(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeCompositionNotificationStubMethods[] = {
        // (0) virtual void Attached(const string&, Exchange::IComposition::IClient*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IComposition::INotification* implementation = reinterpret_cast<Exchange::IComposition::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();
            Core::instance_id _clientInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IComposition::IClient* _client{};
            ProxyStub::UnknownProxy* _clientProxy__ = nullptr;
            if (_clientInstanceId__ != 0) {
                _clientProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _clientInstanceId__, false, _client);
                ASSERT((_client != nullptr) && (_clientProxy__ != nullptr));
            }

            implementation->Attached(static_cast<const string&>(_name), _client);

            if (_clientProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_clientProxy__, message->Response());
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

    static ProxyStub::MethodHandler ExchangeCompositionDisplayStubMethods[] = {
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
            const Exchange::IComposition::ScreenResolution _parameter_19a69410 = reader.Number<Exchange::IComposition::ScreenResolution>();

            uint32_t result = implementation->Resolution(_parameter_19a69410);

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

    static ProxyStub::MethodHandler ExchangeBrightnessStubMethods[] = {
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
    // RPC::IIteratorTypeInstance_c05b33a2ffea23f6 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
    //

    class RPCIteratorTypeInstance_c05b33a2ffea23f6Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>> {
    public:
        RPCIteratorTypeInstance_c05b33a2ffea23f6Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDeviceAudioCapabilities::AudioOutput& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();
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

        Exchange::IDeviceAudioCapabilities::AudioOutput Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::AudioOutput result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_c05b33a2ffea23f6Proxy

    //
    // RPC::IIteratorTypeInstance_47f9365de0b38ac1 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
    //

    class RPCIteratorTypeInstance_47f9365de0b38ac1Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>> {
    public:
        RPCIteratorTypeInstance_47f9365de0b38ac1Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDeviceAudioCapabilities::AudioCapability& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();
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

        Exchange::IDeviceAudioCapabilities::AudioCapability Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::AudioCapability result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_47f9365de0b38ac1Proxy

    //
    // RPC::IIteratorTypeInstance_ed3acc81bd14fad7 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
    //

    class RPCIteratorTypeInstance_ed3acc81bd14fad7Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>> {
    public:
        RPCIteratorTypeInstance_ed3acc81bd14fad7Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDeviceAudioCapabilities::MS12Capability& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();
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

        Exchange::IDeviceAudioCapabilities::MS12Capability Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::MS12Capability result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_ed3acc81bd14fad7Proxy

    //
    // RPC::IIteratorTypeInstance_291157d7989c288e interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
    //

    class RPCIteratorTypeInstance_291157d7989c288eProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>> {
    public:
        RPCIteratorTypeInstance_291157d7989c288eProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDeviceAudioCapabilities::MS12Profile& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();
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

        Exchange::IDeviceAudioCapabilities::MS12Profile Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::MS12Profile result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_291157d7989c288eProxy

    //
    // RPC::IIteratorTypeInstance_0abf4e195a83835b interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
    //

    class RPCIteratorTypeInstance_0abf4e195a83835bProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>> {
    public:
        RPCIteratorTypeInstance_0abf4e195a83835bProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDeviceVideoCapabilities::VideoOutput& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();
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

        Exchange::IDeviceVideoCapabilities::VideoOutput Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceVideoCapabilities::VideoOutput result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_0abf4e195a83835bProxy

    //
    // RPC::IIteratorTypeInstance_848ec395838dfece interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
    //

    class RPCIteratorTypeInstance_848ec395838dfeceProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>> {
    public:
        RPCIteratorTypeInstance_848ec395838dfeceProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDeviceVideoCapabilities::ScreenResolution& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();
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

        Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceVideoCapabilities::ScreenResolution result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_848ec395838dfeceProxy

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

        void Register(Exchange::IComposition::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::IComposition::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Configure(PluginHost::IShell* _service) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

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

        uint32_t Resolution(const Exchange::IComposition::ScreenResolution _parameter_ef72b6a6) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IComposition::ScreenResolution>(_parameter_ef72b6a6);

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

        Exchange::IComposition::ScreenResolution Resolution() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Exchange::IComposition::ScreenResolution result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IComposition::ScreenResolution>();
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

        Core::instance_id Native() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::instance_id result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Core::instance_id>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Name() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        void Opacity(const uint32_t _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_value);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        uint32_t Opacity() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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

        uint32_t Geometry(const Exchange::IComposition::Rectangle& _rectangle) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_rectangle.x);
            writer.Number<int32_t>(_rectangle.y);
            writer.Number<uint32_t>(_rectangle.width);
            writer.Number<uint32_t>(_rectangle.height);

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

        Exchange::IComposition::Rectangle Geometry() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IComposition::Rectangle result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result.x = reader.Number<int32_t>();
                result.y = reader.Number<int32_t>();
                result.width = reader.Number<uint32_t>();
                result.height = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t ZOrder(const uint16_t _index) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_index);

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

        uint32_t ZOrder() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

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

    }; // class ExchangeCompositionClientProxy

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

        void Attached(const string& _name, Exchange::IComposition::IClient* _client) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);
            writer.Number<Core::instance_id>(RPC::instance_cast(_client));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Detached(const string& _name) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

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

        Core::instance_id Native() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::instance_id result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Core::instance_id>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Port() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        Exchange::IComposition::IClient* CreateClient(const string& _name, const uint32_t _width, const uint32_t _height) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);
            writer.Number<uint32_t>(_width);
            writer.Number<uint32_t>(_height);

            Exchange::IComposition::IClient* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IComposition::IClient*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IComposition::IClient::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Resolution(const Exchange::IComposition::ScreenResolution _parameter_19a69410) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IComposition::ScreenResolution>(_parameter_19a69410);

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

        Exchange::IComposition::ScreenResolution Resolution() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Exchange::IComposition::ScreenResolution result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IComposition::ScreenResolution>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

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

        uint32_t SdrToHdrGraphicsBrightness(Exchange::IBrightness::Brightness& _brightness) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _brightness = reader.Number<Exchange::IBrightness::Brightness>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t SdrToHdrGraphicsBrightness(const Exchange::IBrightness::Brightness& _brightness) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IBrightness::Brightness>(_brightness);

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

    }; // class ExchangeBrightnessProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>, RPCIteratorTypeInstance_c05b33a2ffea23f6StubMethods> RPCIteratorTypeInstance_c05b33a2ffea23f6Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>, RPCIteratorTypeInstance_47f9365de0b38ac1StubMethods> RPCIteratorTypeInstance_47f9365de0b38ac1Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>, RPCIteratorTypeInstance_ed3acc81bd14fad7StubMethods> RPCIteratorTypeInstance_ed3acc81bd14fad7Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>, RPCIteratorTypeInstance_291157d7989c288eStubMethods> RPCIteratorTypeInstance_291157d7989c288eStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>, RPCIteratorTypeInstance_0abf4e195a83835bStubMethods> RPCIteratorTypeInstance_0abf4e195a83835bStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>, RPCIteratorTypeInstance_848ec395838dfeceStubMethods> RPCIteratorTypeInstance_848ec395838dfeceStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition, ExchangeCompositionStubMethods> ExchangeCompositionStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::IClient, ExchangeCompositionClientStubMethods> ExchangeCompositionClientStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::INotification, ExchangeCompositionNotificationStubMethods> ExchangeCompositionNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IComposition::IDisplay, ExchangeCompositionDisplayStubMethods> ExchangeCompositionDisplayStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrightness, ExchangeBrightnessStubMethods> ExchangeBrightnessStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>, RPCIteratorTypeInstance_c05b33a2ffea23f6Proxy, RPCIteratorTypeInstance_c05b33a2ffea23f6Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>, RPCIteratorTypeInstance_47f9365de0b38ac1Proxy, RPCIteratorTypeInstance_47f9365de0b38ac1Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>, RPCIteratorTypeInstance_ed3acc81bd14fad7Proxy, RPCIteratorTypeInstance_ed3acc81bd14fad7Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>, RPCIteratorTypeInstance_291157d7989c288eProxy, RPCIteratorTypeInstance_291157d7989c288eStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>, RPCIteratorTypeInstance_0abf4e195a83835bProxy, RPCIteratorTypeInstance_0abf4e195a83835bStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>, RPCIteratorTypeInstance_848ec395838dfeceProxy, RPCIteratorTypeInstance_848ec395838dfeceStub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition, ExchangeCompositionProxy, ExchangeCompositionStub>();
                RPC::Administrator::Instance().Announce<Exchange::IComposition::IClient, ExchangeCompositionClientProxy, ExchangeCompositionClientStub>();
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
                RPC::Administrator::Instance().Recall<Exchange::IComposition::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IComposition::IDisplay>();
                RPC::Administrator::Instance().Recall<Exchange::IBrightness>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
