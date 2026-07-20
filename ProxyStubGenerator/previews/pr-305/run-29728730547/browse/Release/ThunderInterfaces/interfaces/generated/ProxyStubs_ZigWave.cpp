//
// generated automatically from "IZigWave.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IZigWave::Device, INTERFACE_ID = Exchange::ID_ZIGWAVE_DEVICE_ITERATOR] [[iterator]]
//   - class Exchange::IZigWave
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IZigWave.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_8cf2fde167b3c2b7 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IZigWave::Device&) = 0
    //  (1) virtual bool Previous(Exchange::IZigWave::Device&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IZigWave::Device Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_8cf2fde167b3c2b7StubMethods[] = {
        // (0) virtual bool Next(Exchange::IZigWave::Device&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IZigWave::Device _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<uint32_t>(_info.Parent);
                writer.Number<uint32_t>(_info.Address);
                writer.Number<Exchange::IZigWave::Device::type>(_info.Type);
                writer.Number<uint16_t>(_info.Manufacturer);
                writer.Text(_info.Metadata);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(Exchange::IZigWave::Device&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IZigWave::Device _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<uint32_t>(_info.Parent);
                writer.Number<uint32_t>(_info.Address);
                writer.Number<Exchange::IZigWave::Device::type>(_info.Type);
                writer.Number<uint16_t>(_info.Manufacturer);
                writer.Text(_info.Metadata);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual Exchange::IZigWave::Device Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IZigWave::Device result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result.Parent);
                writer.Number<uint32_t>(result.Address);
                writer.Number<Exchange::IZigWave::Device::type>(result.Type);
                writer.Number<uint16_t>(result.Manufacturer);
                writer.Text(result.Metadata);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_8cf2fde167b3c2b7StubMethods

    //
    // Exchange::IZigWave interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Permutable(const uint32_t, bool&) const = 0
    //  (1) virtual Core::hresult Permutable(const uint32_t, const bool) = 0
    //  (2) virtual Core::hresult Devices(const uint32_t, Exchange::IZigWave::IDeviceIterator*&) const = 0
    //  (3) virtual Core::hresult Bind(const uint32_t, const uint32_t) = 0
    //  (4) virtual Core::hresult Unbind(const uint32_t, const uint32_t) = 0
    //  (5) virtual Core::hresult Metadata(Exchange::IZigWave::Controller&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeZigWaveStubMethods[] = {
        // (0) virtual Core::hresult Permutable(const uint32_t, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IZigWave* implementation = reinterpret_cast<const Exchange::IZigWave*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IZigWave::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _address = reader.Number<uint32_t>();

                bool _enabled{};

                Core::hresult result = implementation->Permutable(_address, _enabled);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Boolean(_enabled);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult Permutable(const uint32_t, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IZigWave* implementation = reinterpret_cast<Exchange::IZigWave*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IZigWave::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _address = reader.Number<uint32_t>();
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _enabled = reader.Boolean();

                Core::hresult result = implementation->Permutable(_address, _enabled);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Devices(const uint32_t, Exchange::IZigWave::IDeviceIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IZigWave* implementation = reinterpret_cast<const Exchange::IZigWave*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IZigWave::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _id = reader.Number<uint32_t>();

                Exchange::IZigWave::IDeviceIterator* _devices{};

                Core::hresult result = implementation->Devices(_id, _devices);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_devices));

                RPC::Administrator::Instance().RegisterInterface(channel, _devices);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Bind(const uint32_t, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IZigWave* implementation = reinterpret_cast<Exchange::IZigWave*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IZigWave::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _source = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _destination = reader.Number<uint32_t>();

                Core::hresult result = implementation->Bind(_source, _destination);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Unbind(const uint32_t, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IZigWave* implementation = reinterpret_cast<Exchange::IZigWave*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IZigWave::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _source = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _destination = reader.Number<uint32_t>();

                Core::hresult result = implementation->Unbind(_source, _destination);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult Metadata(Exchange::IZigWave::Controller&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const Exchange::IZigWave* implementation = reinterpret_cast<const Exchange::IZigWave*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IZigWave::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Exchange::IZigWave::Controller _metadata{};

                Core::hresult result = implementation->Metadata(_metadata);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Boolean(_metadata.Permutable);
                writer.Text(_metadata.Port);
                writer.Number<uint32_t>(_metadata.Id);
                writer.Number<uint8_t>(_metadata.Major);
                writer.Number<uint8_t>(_metadata.Minor);
                writer.Number<uint16_t>(_metadata.Nodes);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 5, hresult);
            }
        }
        , nullptr
    }; // ExchangeZigWaveStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_8cf2fde167b3c2b7 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IZigWave::Device&) = 0
    //  (1) virtual bool Previous(Exchange::IZigWave::Device&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IZigWave::Device Current() const = 0
    //

    class RPCIteratorTypeInstance_8cf2fde167b3c2b7Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_8cf2fde167b3c2b7Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IZigWave::Device& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Parent = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Address = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::IZigWave::Device::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Type = reader.Number<Exchange::IZigWave::Device::type>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Manufacturer = reader.Number<uint16_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_MetadataPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_MetadataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Metadata = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(Exchange::IZigWave::Device& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Parent = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Address = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::IZigWave::Device::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Type = reader.Number<Exchange::IZigWave::Device::type>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Manufacturer = reader.Number<uint16_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_MetadataPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_MetadataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.Metadata = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 1, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 2, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 3, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Exchange::IZigWave::Device Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IZigWave::Device result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.Parent = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.Address = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<Exchange::IZigWave::Device::type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.Type = reader.Number<Exchange::IZigWave::Device::type>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.Manufacturer = reader.Number<uint16_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t result_MetadataPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + result_MetadataPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.Metadata = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_8cf2fde167b3c2b7Proxy

    //
    // Exchange::IZigWave interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Permutable(const uint32_t, bool&) const = 0
    //  (1) virtual Core::hresult Permutable(const uint32_t, const bool) = 0
    //  (2) virtual Core::hresult Devices(const uint32_t, Exchange::IZigWave::IDeviceIterator*&) const = 0
    //  (3) virtual Core::hresult Bind(const uint32_t, const uint32_t) = 0
    //  (4) virtual Core::hresult Unbind(const uint32_t, const uint32_t) = 0
    //  (5) virtual Core::hresult Metadata(Exchange::IZigWave::Controller&) const = 0
    //

    class ExchangeZigWaveProxy final : public ProxyStub::UnknownProxyType<Exchange::IZigWave> {
    public:
        ExchangeZigWaveProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Permutable(const uint32_t _address, bool& _enabled) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _enabled = reader.Boolean();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult Permutable(const uint32_t _address, const bool _enabled) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_address);
            writer.Boolean(_enabled);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 1, hresult);
            }

            return (hresult);
        }

        Core::hresult Devices(const uint32_t _id, Exchange::IZigWave::IDeviceIterator*& _devices) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _devices = reinterpret_cast<Exchange::IZigWave::IDeviceIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IZigWave::IDeviceIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult Bind(const uint32_t _source, const uint32_t _destination) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_source);
            writer.Number<uint32_t>(_destination);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult Unbind(const uint32_t _source, const uint32_t _destination) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_source);
            writer.Number<uint32_t>(_destination);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult Metadata(Exchange::IZigWave::Controller& _metadata) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _metadata.Permutable = reader.Boolean();
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _metadata_PortPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _metadata_PortPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _metadata.Port = reader.Text();
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _metadata.Id = reader.Number<uint32_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _metadata.Major = reader.Number<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _metadata.Minor = reader.Number<uint8_t>();
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _metadata.Nodes = reader.Number<uint16_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IZigWave::ID, 5, hresult);
            }

            return (hresult);
        }

    }; // class ExchangeZigWaveProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>, RPCIteratorTypeInstance_8cf2fde167b3c2b7StubMethods> RPCIteratorTypeInstance_8cf2fde167b3c2b7Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IZigWave, ExchangeZigWaveStubMethods> ExchangeZigWaveStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>, RPCIteratorTypeInstance_8cf2fde167b3c2b7Proxy, RPCIteratorTypeInstance_8cf2fde167b3c2b7Stub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IZigWave, ExchangeZigWaveProxy, ExchangeZigWaveStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IZigWave::Device, Exchange::ID_ZIGWAVE_DEVICE_ITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IZigWave>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
