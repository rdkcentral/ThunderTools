//
// generated automatically from "IDisplayInfo.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IHDRProperties::HDRType, INTERFACE_ID = Exchange::ID_HDR_ITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IDisplayProperties::ColorimetryType, INTERFACE_ID = Exchange::ID_COLORIMETRY_ITERATOR] [[iterator]]
//   - class Exchange::IGraphicsProperties
//   - class Exchange::IConnectionProperties
//   - class Exchange::IConnectionProperties::INotification
//   - class Exchange::IHDRProperties
//   - class Exchange::IDisplayProperties
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IDisplayInfo.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_c5a5fda69b531db1 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IHDRProperties::HDRType&) = 0
    //  (1) virtual bool Previous(Exchange::IHDRProperties::HDRType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IHDRProperties::HDRType Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_c5a5fda69b531db1StubMethods[] = {
        // (0) virtual bool Next(Exchange::IHDRProperties::HDRType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IHDRProperties::HDRType _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IHDRProperties::HDRType>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IHDRProperties::HDRType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IHDRProperties::HDRType _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IHDRProperties::HDRType>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IHDRProperties::HDRType Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IHDRProperties::HDRType result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IHDRProperties::HDRType>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_c5a5fda69b531db1StubMethods

    //
    // RPC::IIteratorTypeInstance_99f5823ba8ab8d2e interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (1) virtual bool Previous(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDisplayProperties::ColorimetryType Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_99f5823ba8ab8d2eStubMethods[] = {
        // (0) virtual bool Next(Exchange::IDisplayProperties::ColorimetryType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::ColorimetryType _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDisplayProperties::ColorimetryType>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IDisplayProperties::ColorimetryType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::ColorimetryType _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<Exchange::IDisplayProperties::ColorimetryType>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IDisplayProperties::ColorimetryType Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::ColorimetryType result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Exchange::IDisplayProperties::ColorimetryType>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_99f5823ba8ab8d2eStubMethods

    //
    // Exchange::IGraphicsProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t TotalGpuRam(uint64_t&) const = 0
    //  (1) virtual uint32_t FreeGpuRam(uint64_t&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeGraphicsPropertiesStubMethods[] = {
        // (0) virtual uint32_t TotalGpuRam(uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IGraphicsProperties* implementation = reinterpret_cast<const Exchange::IGraphicsProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IGraphicsProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint64_t _total{};

                uint32_t result = implementation->TotalGpuRam(_total);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint64_t>(_total);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IGraphicsProperties::ID, 0, hresult);
            }
        },

        // (1) virtual uint32_t FreeGpuRam(uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IGraphicsProperties* implementation = reinterpret_cast<const Exchange::IGraphicsProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IGraphicsProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint64_t _free{};

                uint32_t result = implementation->FreeGpuRam(_free);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint64_t>(_free);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IGraphicsProperties::ID, 1, hresult);
            }
        }
        , nullptr
    }; // ExchangeGraphicsPropertiesStubMethods

    //
    // Exchange::IConnectionProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IConnectionProperties::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IConnectionProperties::INotification*) = 0
    //  (2) virtual uint32_t IsAudioPassthrough(bool&) const = 0
    //  (3) virtual uint32_t Connected(bool&) const = 0
    //  (4) virtual uint32_t Width(uint32_t&) const = 0
    //  (5) virtual uint32_t Height(uint32_t&) const = 0
    //  (6) virtual uint32_t VerticalFreq(uint32_t&) const = 0
    //  (7) virtual uint32_t EDID(uint16_t&, uint8_t*) const = 0
    //  (8) virtual uint32_t WidthInCentimeters(uint8_t&) const = 0
    //  (9) virtual uint32_t HeightInCentimeters(uint8_t&) const = 0
    //  (10) virtual uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType&) const = 0
    //  (11) virtual uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType) = 0
    //  (12) virtual uint32_t PortName(string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeConnectionPropertiesStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IConnectionProperties::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IConnectionProperties* implementation = reinterpret_cast<Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _parameter_2bce07edInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::IConnectionProperties::INotification* _parameter_2bce07ed{};
                ProxyStub::UnknownProxy* _parameter_2bce07edProxy__ = nullptr;
                if (_parameter_2bce07edInstanceId__ != 0) {
                    _parameter_2bce07edProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_2bce07edInstanceId__, false, _parameter_2bce07ed);
                    ASSERT((_parameter_2bce07ed != nullptr) && (_parameter_2bce07edProxy__ != nullptr));
                    if ((_parameter_2bce07ed == nullptr) || (_parameter_2bce07edProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Register(_parameter_2bce07ed);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_parameter_2bce07edProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_parameter_2bce07edProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 0, hresult);
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::IConnectionProperties::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IConnectionProperties* implementation = reinterpret_cast<Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _parameter_0b632faaInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::IConnectionProperties::INotification* _parameter_0b632faa{};
                ProxyStub::UnknownProxy* _parameter_0b632faaProxy__ = nullptr;
                if (_parameter_0b632faaInstanceId__ != 0) {
                    _parameter_0b632faaProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_0b632faaInstanceId__, false, _parameter_0b632faa);
                    ASSERT((_parameter_0b632faa != nullptr) && (_parameter_0b632faaProxy__ != nullptr));
                    if ((_parameter_0b632faa == nullptr) || (_parameter_0b632faaProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                uint32_t result = implementation->Unregister(_parameter_0b632faa);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                if (_parameter_0b632faaProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_parameter_0b632faaProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 1, hresult);
            }
        },

        // (2) virtual uint32_t IsAudioPassthrough(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool _passthru{};

                uint32_t result = implementation->IsAudioPassthrough(_passthru);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_passthru);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 2, hresult);
            }
        },

        // (3) virtual uint32_t Connected(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool _isconnected{};

                uint32_t result = implementation->Connected(_isconnected);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Boolean(_isconnected);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 3, hresult);
            }
        },

        // (4) virtual uint32_t Width(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t _width{};

                uint32_t result = implementation->Width(_width);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint32_t>(_width);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 4, hresult);
            }
        },

        // (5) virtual uint32_t Height(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t _height{};

                uint32_t result = implementation->Height(_height);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint32_t>(_height);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 5, hresult);
            }
        },

        // (6) virtual uint32_t VerticalFreq(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t _vf{};

                uint32_t result = implementation->VerticalFreq(_vf);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint32_t>(_vf);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 6, hresult);
            }
        },

        // (7) virtual uint32_t EDID(uint16_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint16_t _length = reader.Number<uint16_t>();

                uint8_t* _data{};

                if (_length != 0) {
                    _data = static_cast<uint8_t*>(ALLOCA(_length * sizeof(uint8_t)));
                    ASSERT(_data != nullptr);
                    if (_data == nullptr) { return (Core::ERROR_GENERAL); }
                }

                uint32_t result = implementation->EDID(_length, _data);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Buffer<uint16_t>((_data == nullptr? 0 : _length), _data);
                writer.Number<uint16_t>(_length);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 7, hresult);
            }
        },

        // (8) virtual uint32_t WidthInCentimeters(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint8_t _width{};

                uint32_t result = implementation->WidthInCentimeters(_width);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint8_t>(_width);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 8, hresult);
            }
        },

        // (9) virtual uint32_t HeightInCentimeters(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint8_t _height{};

                uint32_t result = implementation->HeightInCentimeters(_height);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<uint8_t>(_height);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 9, hresult);
            }
        },

        // (10) virtual uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IConnectionProperties::HDCPProtectionType _value{};

                uint32_t result = implementation->HDCPProtection(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IConnectionProperties::HDCPProtectionType>(_value);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 10, hresult);
            }
        },

        // (11) virtual uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IConnectionProperties* implementation = reinterpret_cast<Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IConnectionProperties::HDCPProtectionType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IConnectionProperties::HDCPProtectionType _value = reader.Number<Exchange::IConnectionProperties::HDCPProtectionType>();

                uint32_t result = implementation->HDCPProtection(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 11, hresult);
            }
        },

        // (12) virtual uint32_t PortName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IConnectionProperties* implementation = reinterpret_cast<const Exchange::IConnectionProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _name{};

                uint32_t result = implementation->PortName(_name);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_name);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 12, hresult);
            }
        }
        , nullptr
    }; // ExchangeConnectionPropertiesStubMethods

    //
    // Exchange::IConnectionProperties::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Updated(const Exchange::IConnectionProperties::INotification::Source) = 0
    //

    static ProxyStub::MethodHandler ExchangeConnectionPropertiesNotificationStubMethods[] = {
        // (0) virtual void Updated(const Exchange::IConnectionProperties::INotification::Source) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IConnectionProperties::INotification* implementation = reinterpret_cast<Exchange::IConnectionProperties::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IConnectionProperties::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<Exchange::IConnectionProperties::INotification::Source>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IConnectionProperties::INotification::Source _event = reader.Number<Exchange::IConnectionProperties::INotification::Source>();

                implementation->Updated(_event);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // ExchangeConnectionPropertiesNotificationStubMethods

    //
    // Exchange::IHDRProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (1) virtual uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (2) virtual uint32_t HDRSetting(Exchange::IHDRProperties::HDRType&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeHDRPropertiesStubMethods[] = {
        // (0) virtual uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IHDRProperties* implementation = reinterpret_cast<const Exchange::IHDRProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IHDRProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IHDRProperties::IHDRIterator* _type{};

                uint32_t result = implementation->TVCapabilities(_type);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_type));

                RPC::Administrator::Instance().RegisterInterface(channel, _type);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IHDRProperties::ID, 0, hresult);
            }
        },

        // (1) virtual uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IHDRProperties* implementation = reinterpret_cast<const Exchange::IHDRProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IHDRProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IHDRProperties::IHDRIterator* _type{};

                uint32_t result = implementation->STBCapabilities(_type);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_type));

                RPC::Administrator::Instance().RegisterInterface(channel, _type);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IHDRProperties::ID, 1, hresult);
            }
        },

        // (2) virtual uint32_t HDRSetting(Exchange::IHDRProperties::HDRType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IHDRProperties* implementation = reinterpret_cast<const Exchange::IHDRProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IHDRProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IHDRProperties::HDRType _type{};

                uint32_t result = implementation->HDRSetting(_type);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IHDRProperties::HDRType>(_type);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IHDRProperties::ID, 2, hresult);
            }
        }
        , nullptr
    }; // ExchangeHDRPropertiesStubMethods

    //
    // Exchange::IDisplayProperties interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType&) const = 0
    //  (1) virtual uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType&) const = 0
    //  (2) virtual uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType&) const = 0
    //  (3) virtual uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*&) const = 0
    //  (4) virtual uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType&) const = 0
    //  (5) virtual uint32_t EOTF(Exchange::IDisplayProperties::EotfType&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeDisplayPropertiesStubMethods[] = {
        // (0) virtual uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDisplayProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::ColourSpaceType _cs{};

                uint32_t result = implementation->ColorSpace(_cs);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IDisplayProperties::ColourSpaceType>(_cs);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 0, hresult);
            }
        },

        // (1) virtual uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDisplayProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::FrameRateType _rate{};

                uint32_t result = implementation->FrameRate(_rate);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IDisplayProperties::FrameRateType>(_rate);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 1, hresult);
            }
        },

        // (2) virtual uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDisplayProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::ColourDepthType _colour{};

                uint32_t result = implementation->ColourDepth(_colour);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IDisplayProperties::ColourDepthType>(_colour);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 2, hresult);
            }
        },

        // (3) virtual uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDisplayProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::IColorimetryIterator* _colorimetry{};

                uint32_t result = implementation->Colorimetry(_colorimetry);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_colorimetry));

                RPC::Administrator::Instance().RegisterInterface(channel, _colorimetry);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 3, hresult);
            }
        },

        // (4) virtual uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDisplayProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::QuantizationRangeType _qr{};

                uint32_t result = implementation->QuantizationRange(_qr);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IDisplayProperties::QuantizationRangeType>(_qr);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 4, hresult);
            }
        },

        // (5) virtual uint32_t EOTF(Exchange::IDisplayProperties::EotfType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IDisplayProperties* implementation = reinterpret_cast<const Exchange::IDisplayProperties*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IDisplayProperties::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IDisplayProperties::EotfType _eotf{};

                uint32_t result = implementation->EOTF(_eotf);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Number<Exchange::IDisplayProperties::EotfType>(_eotf);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 5, hresult);
            }
        }
        , nullptr
    }; // ExchangeDisplayPropertiesStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_c5a5fda69b531db1 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IHDRProperties::HDRType&) = 0
    //  (1) virtual bool Previous(Exchange::IHDRProperties::HDRType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IHDRProperties::HDRType Current() const = 0
    //

    class RPCIteratorTypeInstance_c5a5fda69b531db1Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_c5a5fda69b531db1Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IHDRProperties::HDRType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IHDRProperties::HDRType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IHDRProperties::HDRType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IHDRProperties::HDRType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IHDRProperties::HDRType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IHDRProperties::HDRType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 1, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 2, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 3, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IHDRProperties::HDRType Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IHDRProperties::HDRType result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IHDRProperties::HDRType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IHDRProperties::HDRType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_c5a5fda69b531db1Proxy

    //
    // RPC::IIteratorTypeInstance_99f5823ba8ab8d2e interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (1) virtual bool Previous(Exchange::IDisplayProperties::ColorimetryType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IDisplayProperties::ColorimetryType Current() const = 0
    //

    class RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IDisplayProperties::ColorimetryType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::ColorimetryType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDisplayProperties::ColorimetryType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IDisplayProperties::ColorimetryType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::ColorimetryType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<Exchange::IDisplayProperties::ColorimetryType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 1, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 2, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 3, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IDisplayProperties::ColorimetryType Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IDisplayProperties::ColorimetryType result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::ColorimetryType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<Exchange::IDisplayProperties::ColorimetryType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy

    //
    // Exchange::IGraphicsProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t TotalGpuRam(uint64_t&) const = 0
    //  (1) virtual uint32_t FreeGpuRam(uint64_t&) const = 0
    //

    class ExchangeGraphicsPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IGraphicsProperties> {
    public:
        ExchangeGraphicsPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t TotalGpuRam(uint64_t& _total) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _total = reader.Number<uint64_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IGraphicsProperties::ID, 0, hresult);
            }

            return (hresult);
        }

        uint32_t FreeGpuRam(uint64_t& _free) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _free = reader.Number<uint64_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IGraphicsProperties::ID, 1, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeGraphicsPropertiesProxy

    //
    // Exchange::IConnectionProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IConnectionProperties::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IConnectionProperties::INotification*) = 0
    //  (2) virtual uint32_t IsAudioPassthrough(bool&) const = 0
    //  (3) virtual uint32_t Connected(bool&) const = 0
    //  (4) virtual uint32_t Width(uint32_t&) const = 0
    //  (5) virtual uint32_t Height(uint32_t&) const = 0
    //  (6) virtual uint32_t VerticalFreq(uint32_t&) const = 0
    //  (7) virtual uint32_t EDID(uint16_t&, uint8_t*) const = 0
    //  (8) virtual uint32_t WidthInCentimeters(uint8_t&) const = 0
    //  (9) virtual uint32_t HeightInCentimeters(uint8_t&) const = 0
    //  (10) virtual uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType&) const = 0
    //  (11) virtual uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType) = 0
    //  (12) virtual uint32_t PortName(string&) const = 0
    //

    class ExchangeConnectionPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IConnectionProperties> {
    public:
        ExchangeConnectionPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::IConnectionProperties::INotification* _parameter_2bce07ed) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_2bce07ed));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_parameter_2bce07ed), Exchange::IConnectionProperties::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t Unregister(Exchange::IConnectionProperties::INotification* _parameter_0b632faa) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_0b632faa));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_parameter_0b632faa), Exchange::IConnectionProperties::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        uint32_t IsAudioPassthrough(bool& _passthru) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _passthru = reader.Boolean();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 2, hresult);
            }

            return (hresult);
        }

        uint32_t Connected(bool& _isconnected) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _isconnected = reader.Boolean();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 3, hresult);
            }

            return (hresult);
        }

        uint32_t Width(uint32_t& _width) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _width = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 4, hresult);
            }

            return (hresult);
        }

        uint32_t Height(uint32_t& _height) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _height = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 5, hresult);
            }

            return (hresult);
        }

        uint32_t VerticalFreq(uint32_t& _vf) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _vf = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 6, hresult);
            }

            return (hresult);
        }

        uint32_t EDID(uint16_t& _length, uint8_t* _data) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_length);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _dataPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _dataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        reader.Buffer<uint16_t>(_length, _data);
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _length = reader.Number<uint16_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 7, hresult);
            }

            return (hresult);
        }

        uint32_t WidthInCentimeters(uint8_t& _width) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _width = reader.Number<uint8_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 8, hresult);
            }

            return (hresult);
        }

        uint32_t HeightInCentimeters(uint8_t& _height) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _height = reader.Number<uint8_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 9, hresult);
            }

            return (hresult);
        }

        uint32_t HDCPProtection(Exchange::IConnectionProperties::HDCPProtectionType& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IConnectionProperties::HDCPProtectionType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _value = reader.Number<Exchange::IConnectionProperties::HDCPProtectionType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 10, hresult);
            }

            return (hresult);
        }

        uint32_t HDCPProtection(const Exchange::IConnectionProperties::HDCPProtectionType _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IConnectionProperties::HDCPProtectionType>(_value);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 11, hresult);
            }

            return (hresult);
        }

        uint32_t PortName(string& _name) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _namePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _name = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::ID, 12, hresult);
            }

            return (hresult);
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

    }; // class ExchangeConnectionPropertiesProxy

    //
    // Exchange::IConnectionProperties::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Updated(const Exchange::IConnectionProperties::INotification::Source) = 0
    //

    class ExchangeConnectionPropertiesNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IConnectionProperties::INotification> {
    public:
        ExchangeConnectionPropertiesNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Updated(const Exchange::IConnectionProperties::INotification::Source _event) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IConnectionProperties::INotification::Source>(_event);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IConnectionProperties::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class ExchangeConnectionPropertiesNotificationProxy

    //
    // Exchange::IHDRProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (1) virtual uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*&) const = 0
    //  (2) virtual uint32_t HDRSetting(Exchange::IHDRProperties::HDRType&) const = 0
    //

    class ExchangeHDRPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IHDRProperties> {
    public:
        ExchangeHDRPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t TVCapabilities(Exchange::IHDRProperties::IHDRIterator*& _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        _type = reinterpret_cast<Exchange::IHDRProperties::IHDRIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHDRProperties::IHDRIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IHDRProperties::ID, 0, hresult);
            }

            return (hresult);
        }

        uint32_t STBCapabilities(Exchange::IHDRProperties::IHDRIterator*& _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        _type = reinterpret_cast<Exchange::IHDRProperties::IHDRIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IHDRProperties::IHDRIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IHDRProperties::ID, 1, hresult);
            }

            return (hresult);
        }

        uint32_t HDRSetting(Exchange::IHDRProperties::HDRType& _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IHDRProperties::HDRType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _type = reader.Number<Exchange::IHDRProperties::HDRType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IHDRProperties::ID, 2, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeHDRPropertiesProxy

    //
    // Exchange::IDisplayProperties interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType&) const = 0
    //  (1) virtual uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType&) const = 0
    //  (2) virtual uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType&) const = 0
    //  (3) virtual uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*&) const = 0
    //  (4) virtual uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType&) const = 0
    //  (5) virtual uint32_t EOTF(Exchange::IDisplayProperties::EotfType&) const = 0
    //

    class ExchangeDisplayPropertiesProxy final : public ProxyStub::UnknownProxyType<Exchange::IDisplayProperties> {
    public:
        ExchangeDisplayPropertiesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t ColorSpace(Exchange::IDisplayProperties::ColourSpaceType& _cs) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::ColourSpaceType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _cs = reader.Number<Exchange::IDisplayProperties::ColourSpaceType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 0, hresult);
            }

            return (hresult);
        }

        uint32_t FrameRate(Exchange::IDisplayProperties::FrameRateType& _rate) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::FrameRateType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _rate = reader.Number<Exchange::IDisplayProperties::FrameRateType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 1, hresult);
            }

            return (hresult);
        }

        uint32_t ColourDepth(Exchange::IDisplayProperties::ColourDepthType& _colour) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::ColourDepthType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _colour = reader.Number<Exchange::IDisplayProperties::ColourDepthType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 2, hresult);
            }

            return (hresult);
        }

        uint32_t Colorimetry(Exchange::IDisplayProperties::IColorimetryIterator*& _colorimetry) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        _colorimetry = reinterpret_cast<Exchange::IDisplayProperties::IColorimetryIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IDisplayProperties::IColorimetryIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 3, hresult);
            }

            return (hresult);
        }

        uint32_t QuantizationRange(Exchange::IDisplayProperties::QuantizationRangeType& _qr) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::QuantizationRangeType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _qr = reader.Number<Exchange::IDisplayProperties::QuantizationRangeType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 4, hresult);
            }

            return (hresult);
        }

        uint32_t EOTF(Exchange::IDisplayProperties::EotfType& _eotf) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<uint32_t>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<Exchange::IDisplayProperties::EotfType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _eotf = reader.Number<Exchange::IDisplayProperties::EotfType>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IDisplayProperties::ID, 5, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeDisplayPropertiesProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>, RPCIteratorTypeInstance_c5a5fda69b531db1StubMethods> RPCIteratorTypeInstance_c5a5fda69b531db1Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>, RPCIteratorTypeInstance_99f5823ba8ab8d2eStubMethods> RPCIteratorTypeInstance_99f5823ba8ab8d2eStub;
        typedef ProxyStub::UnknownStubType<Exchange::IGraphicsProperties, ExchangeGraphicsPropertiesStubMethods> ExchangeGraphicsPropertiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IConnectionProperties, ExchangeConnectionPropertiesStubMethods> ExchangeConnectionPropertiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IConnectionProperties::INotification, ExchangeConnectionPropertiesNotificationStubMethods> ExchangeConnectionPropertiesNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IHDRProperties, ExchangeHDRPropertiesStubMethods> ExchangeHDRPropertiesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDisplayProperties, ExchangeDisplayPropertiesStubMethods> ExchangeDisplayPropertiesStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>, RPCIteratorTypeInstance_c5a5fda69b531db1Proxy, RPCIteratorTypeInstance_c5a5fda69b531db1Stub>(security);
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>, RPCIteratorTypeInstance_99f5823ba8ab8d2eProxy, RPCIteratorTypeInstance_99f5823ba8ab8d2eStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IGraphicsProperties, ExchangeGraphicsPropertiesProxy, ExchangeGraphicsPropertiesStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IConnectionProperties, ExchangeConnectionPropertiesProxy, ExchangeConnectionPropertiesStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IConnectionProperties::INotification, ExchangeConnectionPropertiesNotificationProxy, ExchangeConnectionPropertiesNotificationStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IHDRProperties, ExchangeHDRPropertiesProxy, ExchangeHDRPropertiesStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IDisplayProperties, ExchangeDisplayPropertiesProxy, ExchangeDisplayPropertiesStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IHDRProperties::HDRType, Exchange::ID_HDR_ITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IDisplayProperties::ColorimetryType, Exchange::ID_COLORIMETRY_ITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IGraphicsProperties>();
                RPC::Administrator::Instance().Recall<Exchange::IConnectionProperties>();
                RPC::Administrator::Instance().Recall<Exchange::IConnectionProperties::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IHDRProperties>();
                RPC::Administrator::Instance().Recall<Exchange::IDisplayProperties>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
