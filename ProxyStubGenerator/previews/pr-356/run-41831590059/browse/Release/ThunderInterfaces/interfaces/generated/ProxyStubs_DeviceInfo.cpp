//
// generated automatically from "IDeviceInfo.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::AudioCapability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Capability, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceAudioCapabilities::MS12Profile, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceVideoCapabilities::VideoOutput, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDeviceVideoCapabilities::ScreenResolution, INTERFACE_ID = Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION] [[iterator]]
//   - class Exchange::IDeviceInfo
//   - class Exchange::IDeviceAudioCapabilities
//   - class Exchange::IDeviceVideoCapabilities
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IDeviceInfo.h"

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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::AudioOutput _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::AudioOutput _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::AudioOutput Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::AudioOutput result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::AudioCapability _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::AudioCapability _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::AudioCapability Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::AudioCapability result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::MS12Capability _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::MS12Capability _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::MS12Capability Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::MS12Capability result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::MS12Profile _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::MS12Profile _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IDeviceAudioCapabilities::MS12Profile Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::MS12Profile result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceVideoCapabilities::VideoOutput _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceVideoCapabilities::VideoOutput _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IDeviceVideoCapabilities::VideoOutput Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceVideoCapabilities::VideoOutput result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceVideoCapabilities::ScreenResolution _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceVideoCapabilities::ScreenResolution _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceVideoCapabilities::ScreenResolution result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_848ec395838dfeceStubMethods

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

    static ProxyStub::MethodHandler ExchangeDeviceInfoStubMethods[] = {
        // (0) virtual uint32_t Configure(const PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IDeviceInfo* implementation = reinterpret_cast<Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _serviceInstanceId__ = reader.Number<Core::instance_id>();

                const PluginHost::IShell* _service{};
                ProxyStub::UnknownProxy* _serviceProxy__ = nullptr;
                if (_serviceInstanceId__ != 0) {
                    _serviceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _serviceInstanceId__, false, _service);
                    ASSERT((_service != nullptr) && (_serviceProxy__ != nullptr));
                    if ((_service == nullptr) || (_serviceProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Configure(_service);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_serviceProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_serviceProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint32_t SerialNumber(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->SerialNumber(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual uint32_t Sku(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->Sku(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual uint32_t Make(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->Make(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t ModelName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->ModelName(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual uint32_t ModelYear(uint16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint16_t _value{};

                uint32_t result = implementation->ModelYear(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint16_t>(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (6) virtual uint32_t FriendlyName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->FriendlyName(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (7) virtual uint32_t DeviceType(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->DeviceType(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (8) virtual uint32_t PlatformName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->PlatformName(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 8, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (9) virtual uint32_t DistributorId(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceInfo* implementation = reinterpret_cast<const Exchange::IDeviceInfo*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceInfo::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _value{};

                uint32_t result = implementation->DistributorId(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 9, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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

    static ProxyStub::MethodHandler ExchangeDeviceAudioCapabilitiesStubMethods[] = {
        // (0) virtual uint32_t AudioOutputs(Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceAudioCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceAudioCapabilities::IAudioOutputIterator* _audioOutputs{};

                uint32_t result = implementation->AudioOutputs(_audioOutputs);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_audioOutputs));

                RPC::Administrator::Instance().RegisterInterface(channel, _audioOutputs);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint32_t AudioCapabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceAudioCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

                Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator* _audioCapabilities{};

                uint32_t result = implementation->AudioCapabilities(_audioOutput, _audioCapabilities);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_audioCapabilities));

                RPC::Administrator::Instance().RegisterInterface(channel, _audioCapabilities);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual uint32_t MS12Capabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceAudioCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

                Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator* _ms12Capabilities{};

                uint32_t result = implementation->MS12Capabilities(_audioOutput, _ms12Capabilities);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_ms12Capabilities));

                RPC::Administrator::Instance().RegisterInterface(channel, _ms12Capabilities);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual uint32_t MS12AudioProfiles(const Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceAudioCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceAudioCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceAudioCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

                Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator* _ms12Profiles{};

                uint32_t result = implementation->MS12AudioProfiles(_audioOutput, _ms12Profiles);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_ms12Profiles));

                RPC::Administrator::Instance().RegisterInterface(channel, _ms12Profiles);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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

    static ProxyStub::MethodHandler ExchangeDeviceVideoCapabilitiesStubMethods[] = {
        // (0) virtual uint32_t VideoOutputs(Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDeviceVideoCapabilities::IVideoOutputIterator* _videoOutputs{};

                uint32_t result = implementation->VideoOutputs(_videoOutputs);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_videoOutputs));

                RPC::Administrator::Instance().RegisterInterface(channel, _videoOutputs);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint32_t DefaultResolution(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::ScreenResolution&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::VideoOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

                Exchange::IDeviceVideoCapabilities::ScreenResolution _defaultResolution{};

                uint32_t result = implementation->DefaultResolution(_videoOutput, _defaultResolution);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>(_defaultResolution);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual uint32_t Resolutions(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::VideoOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

                Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator* _resolutions{};

                uint32_t result = implementation->Resolutions(_videoOutput, _resolutions);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_resolutions));

                RPC::Administrator::Instance().RegisterInterface(channel, _resolutions);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual uint32_t Hdcp(const Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::IDeviceVideoCapabilities::CopyProtection&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::VideoOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

                Exchange::IDeviceVideoCapabilities::CopyProtection _hdcpVersion{};

                uint32_t result = implementation->Hdcp(_videoOutput, _hdcpVersion);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IDeviceVideoCapabilities::CopyProtection>(_hdcpVersion);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t HostEDID(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _edid{};

                uint32_t result = implementation->HostEDID(_edid);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_edid);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual uint32_t HDR(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool _supportsHDR{};

                uint32_t result = implementation->HDR(_supportsHDR);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_supportsHDR);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (6) virtual uint32_t Atmos(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool _supportsAtmos{};

                uint32_t result = implementation->Atmos(_supportsAtmos);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_supportsAtmos);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (7) virtual uint32_t CEC(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDeviceVideoCapabilities* implementation = reinterpret_cast<const Exchange::IDeviceVideoCapabilities*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDeviceVideoCapabilities::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool _supportsCEC{};

                uint32_t result = implementation->CEC(_supportsCEC);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_supportsCEC);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeDeviceVideoCapabilitiesStubMethods

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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::AudioOutput& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDeviceAudioCapabilities::AudioOutput Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::AudioOutput result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioCapability>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::AudioCapability& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioCapability>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDeviceAudioCapabilities::AudioCapability Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::AudioCapability result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::AudioCapability>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IDeviceAudioCapabilities::AudioCapability>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::MS12Capability>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::MS12Capability& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::MS12Capability>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDeviceAudioCapabilities::MS12Capability Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::MS12Capability result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::MS12Capability>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Capability>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::MS12Profile>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceAudioCapabilities::MS12Profile& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::MS12Profile>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDeviceAudioCapabilities::MS12Profile Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceAudioCapabilities::MS12Profile result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceAudioCapabilities::MS12Profile>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IDeviceAudioCapabilities::MS12Profile>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::VideoOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceVideoCapabilities::VideoOutput& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::VideoOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDeviceVideoCapabilities::VideoOutput Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceVideoCapabilities::VideoOutput result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::VideoOutput>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::ScreenResolution>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IDeviceVideoCapabilities::ScreenResolution& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::ScreenResolution>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDeviceVideoCapabilities::ScreenResolution Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDeviceVideoCapabilities::ScreenResolution result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::ScreenResolution>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_848ec395838dfeceProxy

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

        uint32_t Configure(const PluginHost::IShell* _service) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_service), PluginHost::IShell::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (result);
        }

        uint32_t SerialNumber(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Sku(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Make(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t ModelName(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t ModelYear(uint16_t& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Number<uint16_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t FriendlyName(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t DeviceType(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t PlatformName(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 8, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t DistributorId(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _value = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceInfo::ID, 9, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const size_t entrySize = (sizeof(Core::instance_id) + sizeof(uint32_t) + sizeof(RPC::Data::Output::mode));
                if (reader.Length() < entrySize) { result = (COM_ERROR | Core::ERROR_READ_ERROR); break; }

                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                if (RPC::Administrator::Instance().IsValid(static_cast<const ProxyStub::UnknownProxy&>(*this).Channel(), implementation, id) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

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

        uint32_t AudioOutputs(Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*& _audioOutputs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    _audioOutputs = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IAudioOutputIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IAudioOutputIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t AudioCapabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput, Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*& _audioCapabilities) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_audioOutput);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    _audioCapabilities = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IAudioCapabilityIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t MS12Capabilities(const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput, Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*& _ms12Capabilities) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_audioOutput);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    _ms12Capabilities = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IMS12CapabilityIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t MS12AudioProfiles(const Exchange::IDeviceAudioCapabilities::AudioOutput _audioOutput, Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*& _ms12Profiles) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceAudioCapabilities::AudioOutput>(_audioOutput);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    _ms12Profiles = reinterpret_cast<Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceAudioCapabilities::IMS12ProfileIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceAudioCapabilities::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

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

        uint32_t VideoOutputs(Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*& _videoOutputs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    _videoOutputs = reinterpret_cast<Exchange::IDeviceVideoCapabilities::IVideoOutputIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceVideoCapabilities::IVideoOutputIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t DefaultResolution(const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput, Exchange::IDeviceVideoCapabilities::ScreenResolution& _defaultResolution) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_videoOutput);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::ScreenResolution>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _defaultResolution = reader.Number<Exchange::IDeviceVideoCapabilities::ScreenResolution>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Resolutions(const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput, Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*& _resolutions) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_videoOutput);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    _resolutions = reinterpret_cast<Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDeviceVideoCapabilities::IScreenResolutionIterator::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Hdcp(const Exchange::IDeviceVideoCapabilities::VideoOutput _videoOutput, Exchange::IDeviceVideoCapabilities::CopyProtection& _hdcpVersion) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDeviceVideoCapabilities::VideoOutput>(_videoOutput);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::IDeviceVideoCapabilities::CopyProtection>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _hdcpVersion = reader.Number<Exchange::IDeviceVideoCapabilities::CopyProtection>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t HostEDID(string& _edid) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _edidPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _edidPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _edid = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t HDR(bool& _supportsHDR) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _supportsHDR = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Atmos(bool& _supportsAtmos) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _supportsAtmos = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t CEC(bool& _supportsCEC) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _supportsCEC = reader.Boolean();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDeviceVideoCapabilities::ID, 7, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class ExchangeDeviceVideoCapabilitiesProxy

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
        typedef ProxyStub::UnknownStubType<Exchange::IDeviceInfo, ExchangeDeviceInfoStubMethods> ExchangeDeviceInfoStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDeviceAudioCapabilities, ExchangeDeviceAudioCapabilitiesStubMethods> ExchangeDeviceAudioCapabilitiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDeviceVideoCapabilities, ExchangeDeviceVideoCapabilitiesStubMethods> ExchangeDeviceVideoCapabilitiesStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioOutput, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_OUTPUT>, RPCIteratorTypeInstance_c05b33a2ffea23f6Proxy, RPCIteratorTypeInstance_c05b33a2ffea23f6Stub>(security);
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::AudioCapability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_CAPABILITY>, RPCIteratorTypeInstance_47f9365de0b38ac1Proxy, RPCIteratorTypeInstance_47f9365de0b38ac1Stub>(security);
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Capability, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_CAPABILITY>, RPCIteratorTypeInstance_ed3acc81bd14fad7Proxy, RPCIteratorTypeInstance_ed3acc81bd14fad7Stub>(security);
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceAudioCapabilities::MS12Profile, Exchange::ID_DEVICE_CAPABILITIES_AUDIO_MS12_PROFILE>, RPCIteratorTypeInstance_291157d7989c288eProxy, RPCIteratorTypeInstance_291157d7989c288eStub>(security);
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::VideoOutput, Exchange::ID_DEVICE_CAPABILITIES_VIDEO_OUTPUT>, RPCIteratorTypeInstance_0abf4e195a83835bProxy, RPCIteratorTypeInstance_0abf4e195a83835bStub>(security);
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDeviceVideoCapabilities::ScreenResolution, Exchange::ID_DEVICE_CAPABILITIES_RESOLUTION>, RPCIteratorTypeInstance_848ec395838dfeceProxy, RPCIteratorTypeInstance_848ec395838dfeceStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IDeviceInfo, ExchangeDeviceInfoProxy, ExchangeDeviceInfoStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IDeviceAudioCapabilities, ExchangeDeviceAudioCapabilitiesProxy, ExchangeDeviceAudioCapabilitiesStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IDeviceVideoCapabilities, ExchangeDeviceVideoCapabilitiesProxy, ExchangeDeviceVideoCapabilitiesStub>(security);
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
