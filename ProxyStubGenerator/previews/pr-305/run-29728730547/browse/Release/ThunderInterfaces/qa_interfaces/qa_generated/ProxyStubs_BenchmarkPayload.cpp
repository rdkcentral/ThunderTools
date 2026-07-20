//
// generated automatically from "IBenchmarkPayload.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = QualityAssurance::IBenchmarkPayload::PayloadType, INTERFACE_ID = QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR] [[iterator]]
//   - class QualityAssurance::IBenchmarkPayload
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IBenchmarkPayload.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_05353879ce17b341 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(QualityAssurance::IBenchmarkPayload::PayloadType&) = 0
    //  (1) virtual bool Previous(QualityAssurance::IBenchmarkPayload::PayloadType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual QualityAssurance::IBenchmarkPayload::PayloadType Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_05353879ce17b341StubMethods[] = {
        // (0) virtual bool Next(QualityAssurance::IBenchmarkPayload::PayloadType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmarkPayload::PayloadType _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<QualityAssurance::IBenchmarkPayload::PayloadType>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(QualityAssurance::IBenchmarkPayload::PayloadType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmarkPayload::PayloadType _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Number<QualityAssurance::IBenchmarkPayload::PayloadType>(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual QualityAssurance::IBenchmarkPayload::PayloadType Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmarkPayload::PayloadType result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<QualityAssurance::IBenchmarkPayload::PayloadType>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_05353879ce17b341StubMethods

    //
    // QualityAssurance::IBenchmarkPayload interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult GetPayloadTypes(QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator*&) const = 0
    //  (1) virtual Core::hresult SendUint16(const uint16_t) = 0
    //  (2) virtual Core::hresult SendUint32(const uint32_t) = 0
    //  (3) virtual Core::hresult SendUint64(const uint64_t) = 0
    //  (4) virtual Core::hresult SendBool(const bool) = 0
    //  (5) virtual Core::hresult SendFloat(const float) = 0
    //  (6) virtual Core::hresult SendDouble(const double) = 0
    //  (7) virtual Core::hresult SendString(const string&) = 0
    //  (8) virtual Core::hresult SendSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&) = 0
    //  (9) virtual Core::hresult SendNoPayload() = 0
    //  (10) virtual Core::hresult SendBuffer(const uint16_t, const uint8_t*) = 0
    //  (11) virtual Core::hresult SendUint32Vector(const std::vector<uint32_t>&) = 0
    //  (12) virtual Core::hresult SendReceiveUint16(const uint16_t, uint16_t&) const = 0
    //  (13) virtual Core::hresult SendReceiveUint32(const uint32_t, uint32_t&) const = 0
    //  (14) virtual Core::hresult SendReceiveUint64(const uint64_t, uint64_t&) const = 0
    //  (15) virtual Core::hresult SendReceiveBool(const bool, bool&) const = 0
    //  (16) virtual Core::hresult SendReceiveFloat(const float, float&) const = 0
    //  (17) virtual Core::hresult SendReceiveDouble(const double, double&) const = 0
    //  (18) virtual Core::hresult SendReceiveString(const string&, string&) const = 0
    //  (19) virtual Core::hresult SendReceiveSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&, QualityAssurance::IBenchmarkPayload::SampleData&) const = 0
    //  (20) virtual Core::hresult SendReceiveBuffer(uint16_t&, uint8_t*) const = 0
    //  (21) virtual Core::hresult SendReceiveUint32Vector(const std::vector<uint32_t>&, std::vector<uint32_t>&) const = 0
    //  (22) virtual Core::hresult Add(const uint32_t, const uint32_t, uint32_t&) const = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceBenchmarkPayloadStubMethods[] = {
        // (0) virtual Core::hresult GetPayloadTypes(QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator* _types{};

                Core::hresult result = implementation->GetPayloadTypes(_types);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_types));

                RPC::Administrator::Instance().RegisterInterface(channel, _types);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult SendUint16(const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _value = reader.Number<uint16_t>();

                Core::hresult result = implementation->SendUint16(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult SendUint32(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _value = reader.Number<uint32_t>();

                Core::hresult result = implementation->SendUint32(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult SendUint64(const uint64_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint64_t _value = reader.Number<uint64_t>();

                Core::hresult result = implementation->SendUint64(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult SendBool(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _value = reader.Boolean();

                Core::hresult result = implementation->SendBool(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult SendFloat(const float) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<float>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const float _value = reader.Number<float>();

                Core::hresult result = implementation->SendFloat(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 5, hresult);
            }
        },

        // (6) virtual Core::hresult SendDouble(const double) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<double>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const double _value = reader.Number<double>();

                Core::hresult result = implementation->SendDouble(_value);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 6, hresult);
            }
        },

        // (7) virtual Core::hresult SendString(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _valuePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _valuePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _value = reader.Text();

                Core::hresult result = implementation->SendString(static_cast<const string&>(_value));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 7, hresult);
            }
        },

        // (8) virtual Core::hresult SendSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                QualityAssurance::IBenchmarkPayload::SampleData _data{};
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.value = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _data_namePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _data_namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _data.name = reader.Text();

                Core::hresult result = implementation->SendSampleData(static_cast<const QualityAssurance::IBenchmarkPayload::SampleData&>(_data));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 8, hresult);
            }
        },

        // (9) virtual Core::hresult SendNoPayload() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                Core::hresult result = implementation->SendNoPayload();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 9, hresult);
            }
        },

        // (10) virtual Core::hresult SendBuffer(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _bufferPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _bufferPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t* _buffer{};
                const uint16_t _bufferSize = reader.LockBuffer<uint16_t>(_buffer);
                reader.UnlockBuffer(_bufferSize);

                Core::hresult result = implementation->SendBuffer(_bufferSize, _buffer);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 10, hresult);
            }
        },

        // (11) virtual Core::hresult SendUint32Vector(const std::vector<uint32_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                std::vector<uint32_t> _data{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint16_t _dataSize = reader.Number<uint16_t>();
                ASSERT((_dataSize >= 1) && (_dataSize <= 1024));
                if (!((_dataSize >= 1) && (_dataSize <= 1024))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                _data.reserve(_dataSize);
                for (uint16_t i = 0; i < _dataSize; i++) {
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    uint32_t _dataItem = reader.Number<uint32_t>();
                    _data.push_back(std::move(_dataItem));
                }

                Core::hresult result = implementation->SendUint32Vector(static_cast<const std::vector<uint32_t>&>(_data));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 11, hresult);
            }
        },

        // (12) virtual Core::hresult SendReceiveUint16(const uint16_t, uint16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _input = reader.Number<uint16_t>();

                uint16_t _output{};

                Core::hresult result = implementation->SendReceiveUint16(_input, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint16_t>(_output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 12, hresult);
            }
        },

        // (13) virtual Core::hresult SendReceiveUint32(const uint32_t, uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _input = reader.Number<uint32_t>();

                uint32_t _output{};

                Core::hresult result = implementation->SendReceiveUint32(_input, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint32_t>(_output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 13, hresult);
            }
        },

        // (14) virtual Core::hresult SendReceiveUint64(const uint64_t, uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint64_t _input = reader.Number<uint64_t>();

                uint64_t _output{};

                Core::hresult result = implementation->SendReceiveUint64(_input, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint64_t>(_output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 14, hresult);
            }
        },

        // (15) virtual Core::hresult SendReceiveBool(const bool, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const bool _input = reader.Boolean();

                bool _output{};

                Core::hresult result = implementation->SendReceiveBool(_input, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Boolean(_output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 15, hresult);
            }
        },

        // (16) virtual Core::hresult SendReceiveFloat(const float, float&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<float>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const float _input = reader.Number<float>();

                float _output{};

                Core::hresult result = implementation->SendReceiveFloat(_input, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<float>(_output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 16, hresult);
            }
        },

        // (17) virtual Core::hresult SendReceiveDouble(const double, double&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<double>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const double _input = reader.Number<double>();

                double _output{};

                Core::hresult result = implementation->SendReceiveDouble(_input, _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<double>(_output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 17, hresult);
            }
        },

        // (18) virtual Core::hresult SendReceiveString(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _inputPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _inputPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _input = reader.Text();

                string _output{};

                Core::hresult result = implementation->SendReceiveString(static_cast<const string&>(_input), _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Text(_output);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 18, hresult);
            }
        },

        // (19) virtual Core::hresult SendReceiveSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&, QualityAssurance::IBenchmarkPayload::SampleData&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                QualityAssurance::IBenchmarkPayload::SampleData _input{};
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _input.id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _input.value = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _input_namePeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _input_namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                _input.name = reader.Text();

                QualityAssurance::IBenchmarkPayload::SampleData _output{};

                Core::hresult result = implementation->SendReceiveSampleData(static_cast<const QualityAssurance::IBenchmarkPayload::SampleData&>(_input), _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint32_t>(_output.id);
                writer.Number<uint32_t>(_output.value);
                writer.Text(_output.name);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 19, hresult);
            }
        },

        // (20) virtual Core::hresult SendReceiveBuffer(uint16_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _bufferPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _bufferPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint8_t* _buffer{};
                uint16_t _bufferSize = reader.LockBuffer<uint16_t>(const_cast<const uint8_t*&>(_buffer));
                reader.UnlockBuffer(_bufferSize);


                Core::hresult result = implementation->SendReceiveBuffer(_bufferSize, _buffer);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Buffer<uint16_t>((_buffer == nullptr? 0 : _bufferSize), _buffer);
                writer.Number<uint16_t>(_bufferSize);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 20, hresult);
            }
        },

        // (21) virtual Core::hresult SendReceiveUint32Vector(const std::vector<uint32_t>&, std::vector<uint32_t>&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                std::vector<uint32_t> _input{};
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                uint16_t _inputSize = reader.Number<uint16_t>();
                ASSERT((_inputSize >= 1) && (_inputSize <= 1024));
                if (!((_inputSize >= 1) && (_inputSize <= 1024))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                _input.reserve(_inputSize);
                for (uint16_t i = 0; i < _inputSize; i++) {
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    uint32_t _inputItem = reader.Number<uint32_t>();
                    _input.push_back(std::move(_inputItem));
                }

                std::vector<uint32_t> _output{};

                Core::hresult result = implementation->SendReceiveUint32Vector(static_cast<const std::vector<uint32_t>&>(_input), _output);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint16_t>(_output.size());
                for (uint16_t i = 0; i < _output.size(); i++) {
                    writer.Number<uint32_t>(_output[i]);
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 21, hresult);
            }
        },

        // (22) virtual Core::hresult Add(const uint32_t, const uint32_t, uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmarkPayload::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _a = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _b = reader.Number<uint32_t>();

                uint32_t _result{};

                Core::hresult result = implementation->Add(_a, _b, _result);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint32_t>(_result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 22, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceBenchmarkPayloadStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_05353879ce17b341 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(QualityAssurance::IBenchmarkPayload::PayloadType&) = 0
    //  (1) virtual bool Previous(QualityAssurance::IBenchmarkPayload::PayloadType&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual QualityAssurance::IBenchmarkPayload::PayloadType Current() const = 0
    //

    class RPCIteratorTypeInstance_05353879ce17b341Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_05353879ce17b341Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(QualityAssurance::IBenchmarkPayload::PayloadType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<QualityAssurance::IBenchmarkPayload::PayloadType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<QualityAssurance::IBenchmarkPayload::PayloadType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(QualityAssurance::IBenchmarkPayload::PayloadType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<QualityAssurance::IBenchmarkPayload::PayloadType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Number<QualityAssurance::IBenchmarkPayload::PayloadType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 1, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 2, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 3, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        QualityAssurance::IBenchmarkPayload::PayloadType Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            QualityAssurance::IBenchmarkPayload::PayloadType result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<QualityAssurance::IBenchmarkPayload::PayloadType>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<QualityAssurance::IBenchmarkPayload::PayloadType>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_05353879ce17b341Proxy

    //
    // QualityAssurance::IBenchmarkPayload interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult GetPayloadTypes(QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator*&) const = 0
    //  (1) virtual Core::hresult SendUint16(const uint16_t) = 0
    //  (2) virtual Core::hresult SendUint32(const uint32_t) = 0
    //  (3) virtual Core::hresult SendUint64(const uint64_t) = 0
    //  (4) virtual Core::hresult SendBool(const bool) = 0
    //  (5) virtual Core::hresult SendFloat(const float) = 0
    //  (6) virtual Core::hresult SendDouble(const double) = 0
    //  (7) virtual Core::hresult SendString(const string&) = 0
    //  (8) virtual Core::hresult SendSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&) = 0
    //  (9) virtual Core::hresult SendNoPayload() = 0
    //  (10) virtual Core::hresult SendBuffer(const uint16_t, const uint8_t*) = 0
    //  (11) virtual Core::hresult SendUint32Vector(const std::vector<uint32_t>&) = 0
    //  (12) virtual Core::hresult SendReceiveUint16(const uint16_t, uint16_t&) const = 0
    //  (13) virtual Core::hresult SendReceiveUint32(const uint32_t, uint32_t&) const = 0
    //  (14) virtual Core::hresult SendReceiveUint64(const uint64_t, uint64_t&) const = 0
    //  (15) virtual Core::hresult SendReceiveBool(const bool, bool&) const = 0
    //  (16) virtual Core::hresult SendReceiveFloat(const float, float&) const = 0
    //  (17) virtual Core::hresult SendReceiveDouble(const double, double&) const = 0
    //  (18) virtual Core::hresult SendReceiveString(const string&, string&) const = 0
    //  (19) virtual Core::hresult SendReceiveSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&, QualityAssurance::IBenchmarkPayload::SampleData&) const = 0
    //  (20) virtual Core::hresult SendReceiveBuffer(uint16_t&, uint8_t*) const = 0
    //  (21) virtual Core::hresult SendReceiveUint32Vector(const std::vector<uint32_t>&, std::vector<uint32_t>&) const = 0
    //  (22) virtual Core::hresult Add(const uint32_t, const uint32_t, uint32_t&) const = 0
    //

    class QualityAssuranceBenchmarkPayloadProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::IBenchmarkPayload> {
    public:
        QualityAssuranceBenchmarkPayloadProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult GetPayloadTypes(QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator*& _types) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _types = reinterpret_cast<QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult SendUint16(const uint16_t _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 1, hresult);
            }

            return (hresult);
        }

        Core::hresult SendUint32(const uint32_t _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult SendUint64(const uint64_t _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint64_t>(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult SendBool(const bool _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult SendFloat(const float _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<float>(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 5, hresult);
            }

            return (hresult);
        }

        Core::hresult SendDouble(const double _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<double>(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 6, hresult);
            }

            return (hresult);
        }

        Core::hresult SendString(const string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_value);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 7, hresult);
            }

            return (hresult);
        }

        Core::hresult SendSampleData(const QualityAssurance::IBenchmarkPayload::SampleData& _data) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_data.id);
            writer.Number<uint32_t>(_data.value);
            writer.Text(_data.name);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 8, hresult);
            }

            return (hresult);
        }

        Core::hresult SendNoPayload() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 9, hresult);
            }

            return (hresult);
        }

        Core::hresult SendBuffer(const uint16_t _bufferSize, const uint8_t* _buffer) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_bufferSize, _buffer);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 10, hresult);
            }

            return (hresult);
        }

        Core::hresult SendUint32Vector(const std::vector<uint32_t>& _data) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_data.size());
            for (uint16_t i = 0; i < _data.size(); i++) {
                writer.Number<uint32_t>(_data[i]);
            }

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 11, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveUint16(const uint16_t _input, uint16_t& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output = reader.Number<uint16_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 12, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveUint32(const uint32_t _input, uint32_t& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 13, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveUint64(const uint64_t _input, uint64_t& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint64_t>(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output = reader.Number<uint64_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 14, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveBool(const bool _input, bool& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output = reader.Boolean();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 15, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveFloat(const float _input, float& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(16));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<float>(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<float>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output = reader.Number<float>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 16, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveDouble(const double _input, double& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(17));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<double>(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<double>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output = reader.Number<double>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 17, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveString(const string& _input, string& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(18));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _outputPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _outputPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 18, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveSampleData(const QualityAssurance::IBenchmarkPayload::SampleData& _input, QualityAssurance::IBenchmarkPayload::SampleData& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(19));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_input.id);
            writer.Number<uint32_t>(_input.value);
            writer.Text(_input.name);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output.id = reader.Number<uint32_t>();
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output.value = reader.Number<uint32_t>();
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _output_namePeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _output_namePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _output.name = reader.Text();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 19, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveBuffer(uint16_t& _bufferSize, uint8_t* _buffer) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(20));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_bufferSize, _buffer);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        const uint16_t _bufferPeekedLen__ = reader.PeekNumber<uint16_t>();
                        if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _bufferPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        reader.Buffer<uint16_t>(_bufferSize, _buffer);
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _bufferSize = reader.Number<uint16_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 20, hresult);
            }

            return (hresult);
        }

        Core::hresult SendReceiveUint32Vector(const std::vector<uint32_t>& _input, std::vector<uint32_t>& _output) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(21));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_input.size());
            for (uint16_t i = 0; i < _input.size(); i++) {
                writer.Number<uint32_t>(_input[i]);
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        uint16_t _outputSize{};
                        if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _outputSize = reader.Number<uint16_t>();
                        _output.reserve(_outputSize);
                        for (uint16_t i = 0; i < _outputSize; i++) {
                            uint32_t _outputItem{};
                            if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                            _outputItem = reader.Number<uint32_t>();
                            _output.push_back(std::move(_outputItem));
                        }
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 21, hresult);
            }

            return (hresult);
        }

        Core::hresult Add(const uint32_t _a, const uint32_t _b, uint32_t& _result) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(22));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_a);
            writer.Number<uint32_t>(_b);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _result = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmarkPayload::ID, 22, hresult);
            }

            return (hresult);
        }

    }; // class QualityAssuranceBenchmarkPayloadProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>, RPCIteratorTypeInstance_05353879ce17b341StubMethods> RPCIteratorTypeInstance_05353879ce17b341Stub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::IBenchmarkPayload, QualityAssuranceBenchmarkPayloadStubMethods> QualityAssuranceBenchmarkPayloadStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>, RPCIteratorTypeInstance_05353879ce17b341Proxy, RPCIteratorTypeInstance_05353879ce17b341Stub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::IBenchmarkPayload, QualityAssuranceBenchmarkPayloadProxy, QualityAssuranceBenchmarkPayloadStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>>();
                RPC::Administrator::Instance().Recall<QualityAssurance::IBenchmarkPayload>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
