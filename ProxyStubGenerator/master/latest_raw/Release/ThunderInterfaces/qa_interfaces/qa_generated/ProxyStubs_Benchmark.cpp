//
// generated automatically from "IBenchmark.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = QualityAssurance::IBenchmark::BenchmarkResult, INTERFACE_ID = QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR] [[iterator]]
//   - class QualityAssurance::IBenchmark
//   - class QualityAssurance::IBenchmark::INotification
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IBenchmark.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_d47fe5f746e372d7 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(QualityAssurance::IBenchmark::BenchmarkResult&) = 0
    //  (1) virtual bool Previous(QualityAssurance::IBenchmark::BenchmarkResult&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual QualityAssurance::IBenchmark::BenchmarkResult Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_d47fe5f746e372d7StubMethods[] = {
        // (0) virtual bool Next(QualityAssurance::IBenchmark::BenchmarkResult&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmark::BenchmarkResult _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info.apiName);
                writer.Number<uint32_t>(_info.iterations);
                writer.Number<uint64_t>(_info.roundTrip.minNs);
                writer.Number<uint64_t>(_info.roundTrip.avgNs);
                writer.Number<uint64_t>(_info.roundTrip.maxNs);
                writer.Number<uint64_t>(_info.roundTrip.stddevNs);
                writer.Number<uint64_t>(_info.memory.residentBefore);
                writer.Number<uint64_t>(_info.memory.residentAfter);
                writer.Number<uint64_t>(_info.memory.allocatedBefore);
                writer.Number<uint64_t>(_info.memory.allocatedAfter);
                writer.Boolean(_info.passed);
                writer.Boolean(_info.failureReason.IsSet());
                if (_info.failureReason.IsSet() == true) {
                    writer.Number<QualityAssurance::IBenchmark::FailureReason>(_info.failureReason.Value());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(QualityAssurance::IBenchmark::BenchmarkResult&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmark::BenchmarkResult _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info.apiName);
                writer.Number<uint32_t>(_info.iterations);
                writer.Number<uint64_t>(_info.roundTrip.minNs);
                writer.Number<uint64_t>(_info.roundTrip.avgNs);
                writer.Number<uint64_t>(_info.roundTrip.maxNs);
                writer.Number<uint64_t>(_info.roundTrip.stddevNs);
                writer.Number<uint64_t>(_info.memory.residentBefore);
                writer.Number<uint64_t>(_info.memory.residentAfter);
                writer.Number<uint64_t>(_info.memory.allocatedBefore);
                writer.Number<uint64_t>(_info.memory.allocatedAfter);
                writer.Boolean(_info.passed);
                writer.Boolean(_info.failureReason.IsSet());
                if (_info.failureReason.IsSet() == true) {
                    writer.Number<QualityAssurance::IBenchmark::FailureReason>(_info.failureReason.Value());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>;

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
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual QualityAssurance::IBenchmark::BenchmarkResult Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                using interface = RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>;

                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), interface::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmark::BenchmarkResult result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result.apiName);
                writer.Number<uint32_t>(result.iterations);
                writer.Number<uint64_t>(result.roundTrip.minNs);
                writer.Number<uint64_t>(result.roundTrip.avgNs);
                writer.Number<uint64_t>(result.roundTrip.maxNs);
                writer.Number<uint64_t>(result.roundTrip.stddevNs);
                writer.Number<uint64_t>(result.memory.residentBefore);
                writer.Number<uint64_t>(result.memory.residentAfter);
                writer.Number<uint64_t>(result.memory.allocatedBefore);
                writer.Number<uint64_t>(result.memory.allocatedAfter);
                writer.Boolean(result.passed);
                writer.Boolean(result.failureReason.IsSet());
                if (result.failureReason.IsSet() == true) {
                    writer.Number<QualityAssurance::IBenchmark::FailureReason>(result.failureReason.Value());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // RPCIteratorTypeInstance_d47fe5f746e372d7StubMethods

    //
    // QualityAssurance::IBenchmark interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Trigger(const uint32_t) = 0
    //  (1) virtual Core::hresult CollectData(QualityAssurance::IBenchmark::IBenchmarkResultIterator*&) const = 0
    //  (2) virtual Core::hresult LatencyThreshold(const uint32_t) = 0
    //  (3) virtual Core::hresult LatencyThreshold(uint32_t&) const = 0
    //  (4) virtual Core::hresult MemoryThreshold(const uint64_t) = 0
    //  (5) virtual Core::hresult MemoryThreshold(uint64_t&) const = 0
    //  (6) virtual Core::hresult Register(QualityAssurance::IBenchmark::INotification*) = 0
    //  (7) virtual Core::hresult Unregister(QualityAssurance::IBenchmark::INotification*) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceBenchmarkStubMethods[] = {
        // (0) virtual Core::hresult Trigger(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmark* implementation = reinterpret_cast<QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _iterations = reader.Number<uint32_t>();

                Core::hresult result = implementation->Trigger(_iterations);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult CollectData(QualityAssurance::IBenchmark::IBenchmarkResultIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmark* implementation = reinterpret_cast<const QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                QualityAssurance::IBenchmark::IBenchmarkResultIterator* _report{};

                Core::hresult result = implementation->CollectData(_report);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_report));

                RPC::Administrator::Instance().RegisterInterface(channel, _report);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult LatencyThreshold(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmark* implementation = reinterpret_cast<QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _maxLatencyDeviationPct = reader.Number<uint32_t>();

                Core::hresult result = implementation->LatencyThreshold(_maxLatencyDeviationPct);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult LatencyThreshold(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmark* implementation = reinterpret_cast<const QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t _maxLatencyDeviationPct{};

                Core::hresult result = implementation->LatencyThreshold(_maxLatencyDeviationPct);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint32_t>(_maxLatencyDeviationPct);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult MemoryThreshold(const uint64_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmark* implementation = reinterpret_cast<QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint64_t _maxMemoryGrowthBytes = reader.Number<uint64_t>();

                Core::hresult result = implementation->MemoryThreshold(_maxMemoryGrowthBytes);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 4, hresult);
            }
        },

        // (5) virtual Core::hresult MemoryThreshold(uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const QualityAssurance::IBenchmark* implementation = reinterpret_cast<const QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint64_t _maxMemoryGrowthBytes{};

                Core::hresult result = implementation->MemoryThreshold(_maxMemoryGrowthBytes);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<uint64_t>(_maxMemoryGrowthBytes);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 5, hresult);
            }
        },

        // (6) virtual Core::hresult Register(QualityAssurance::IBenchmark::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmark* implementation = reinterpret_cast<QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

                QualityAssurance::IBenchmark::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Register(_sink);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 6, hresult);
            }
        },

        // (7) virtual Core::hresult Unregister(QualityAssurance::IBenchmark::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmark* implementation = reinterpret_cast<QualityAssurance::IBenchmark*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

                QualityAssurance::IBenchmark::INotification* _sink{};
                ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
                if (_sinkInstanceId__ != 0) {
                    _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                    ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
                    if ((_sink == nullptr) || (_sinkProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Unregister(_sink);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_sinkProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 7, hresult);
            }
        }
        , nullptr
    }; // QualityAssuranceBenchmarkStubMethods

    //
    // QualityAssurance::IBenchmark::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void PerformanceCheckCompleted() = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceBenchmarkNotificationStubMethods[] = {
        // (0) virtual void PerformanceCheckCompleted() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                QualityAssurance::IBenchmark::INotification* implementation = reinterpret_cast<QualityAssurance::IBenchmark::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), QualityAssurance::IBenchmark::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->PerformanceCheckCompleted();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // QualityAssuranceBenchmarkNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_d47fe5f746e372d7 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(QualityAssurance::IBenchmark::BenchmarkResult&) = 0
    //  (1) virtual bool Previous(QualityAssurance::IBenchmark::BenchmarkResult&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual QualityAssurance::IBenchmark::BenchmarkResult Current() const = 0
    //

    class RPCIteratorTypeInstance_d47fe5f746e372d7Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_d47fe5f746e372d7Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(QualityAssurance::IBenchmark::BenchmarkResult& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_apiNamePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_apiNamePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.apiName = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.iterations = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.minNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.avgNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.maxNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.stddevNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.residentBefore = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.residentAfter = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.allocatedBefore = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.allocatedAfter = reader.Number<uint64_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.passed = reader.Boolean();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    if (reader.Boolean() == true) {
                        if (reader.Length() < (Core::RealSize<QualityAssurance::IBenchmark::FailureReason>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _info.failureReason = reader.Number<QualityAssurance::IBenchmark::FailureReason>();
                    }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(QualityAssurance::IBenchmark::BenchmarkResult& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _info_apiNamePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _info_apiNamePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.apiName = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.iterations = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.minNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.avgNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.maxNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.roundTrip.stddevNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.residentBefore = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.residentAfter = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.allocatedBefore = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.memory.allocatedAfter = reader.Number<uint64_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info.passed = reader.Boolean();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    if (reader.Boolean() == true) {
                        if (reader.Length() < (Core::RealSize<QualityAssurance::IBenchmark::FailureReason>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _info.failureReason = reader.Number<QualityAssurance::IBenchmark::FailureReason>();
                    }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 1, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 2, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 3, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        QualityAssurance::IBenchmark::BenchmarkResult Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            QualityAssurance::IBenchmark::BenchmarkResult result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t result_apiNamePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + result_apiNamePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.apiName = reader.Text();
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.iterations = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.roundTrip.minNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.roundTrip.avgNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.roundTrip.maxNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.roundTrip.stddevNs = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.memory.residentBefore = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.memory.residentAfter = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.memory.allocatedBefore = reader.Number<uint64_t>();
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.memory.allocatedAfter = reader.Number<uint64_t>();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result.passed = reader.Boolean();
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    if (reader.Boolean() == true) {
                        if (reader.Length() < (Core::RealSize<QualityAssurance::IBenchmark::FailureReason>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        result.failureReason = reader.Number<QualityAssurance::IBenchmark::FailureReason>();
                    }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_d47fe5f746e372d7Proxy

    //
    // QualityAssurance::IBenchmark interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Trigger(const uint32_t) = 0
    //  (1) virtual Core::hresult CollectData(QualityAssurance::IBenchmark::IBenchmarkResultIterator*&) const = 0
    //  (2) virtual Core::hresult LatencyThreshold(const uint32_t) = 0
    //  (3) virtual Core::hresult LatencyThreshold(uint32_t&) const = 0
    //  (4) virtual Core::hresult MemoryThreshold(const uint64_t) = 0
    //  (5) virtual Core::hresult MemoryThreshold(uint64_t&) const = 0
    //  (6) virtual Core::hresult Register(QualityAssurance::IBenchmark::INotification*) = 0
    //  (7) virtual Core::hresult Unregister(QualityAssurance::IBenchmark::INotification*) = 0
    //

    class QualityAssuranceBenchmarkProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::IBenchmark> {
    public:
        QualityAssuranceBenchmarkProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Trigger(const uint32_t _iterations) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_iterations);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 0, hresult);
            }

            return (hresult);
        }

        Core::hresult CollectData(QualityAssurance::IBenchmark::IBenchmarkResultIterator*& _report) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _report = reinterpret_cast<QualityAssurance::IBenchmark::IBenchmarkResultIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::IBenchmark::IBenchmarkResultIterator::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 1, hresult);
            }

            return (hresult);
        }

        Core::hresult LatencyThreshold(const uint32_t _maxLatencyDeviationPct) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_maxLatencyDeviationPct);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 2, hresult);
            }

            return (hresult);
        }

        Core::hresult LatencyThreshold(uint32_t& _maxLatencyDeviationPct) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _maxLatencyDeviationPct = reader.Number<uint32_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 3, hresult);
            }

            return (hresult);
        }

        Core::hresult MemoryThreshold(const uint64_t _maxMemoryGrowthBytes) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint64_t>(_maxMemoryGrowthBytes);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 4, hresult);
            }

            return (hresult);
        }

        Core::hresult MemoryThreshold(uint64_t& _maxMemoryGrowthBytes) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                        _maxMemoryGrowthBytes = reader.Number<uint64_t>();
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 5, hresult);
            }

            return (hresult);
        }

        Core::hresult Register(QualityAssurance::IBenchmark::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), QualityAssurance::IBenchmark::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 6, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Unregister(QualityAssurance::IBenchmark::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_sink), QualityAssurance::IBenchmark::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::ID, 7, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

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

    }; // class QualityAssuranceBenchmarkProxy

    //
    // QualityAssurance::IBenchmark::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void PerformanceCheckCompleted() = 0
    //

    class QualityAssuranceBenchmarkNotificationProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::IBenchmark::INotification> {
    public:
        QualityAssuranceBenchmarkNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void PerformanceCheckCompleted() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", QualityAssurance::IBenchmark::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

    }; // class QualityAssuranceBenchmarkNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>, RPCIteratorTypeInstance_d47fe5f746e372d7StubMethods> RPCIteratorTypeInstance_d47fe5f746e372d7Stub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::IBenchmark, QualityAssuranceBenchmarkStubMethods> QualityAssuranceBenchmarkStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::IBenchmark::INotification, QualityAssuranceBenchmarkNotificationStubMethods> QualityAssuranceBenchmarkNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>, RPCIteratorTypeInstance_d47fe5f746e372d7Proxy, RPCIteratorTypeInstance_d47fe5f746e372d7Stub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::IBenchmark, QualityAssuranceBenchmarkProxy, QualityAssuranceBenchmarkStub>(security);
                RPC::Administrator::Instance().Announce<QualityAssurance::IBenchmark::INotification, QualityAssuranceBenchmarkNotificationProxy, QualityAssuranceBenchmarkNotificationStub>(security);
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<QualityAssurance::IBenchmark::BenchmarkResult, QualityAssurance::ID_BENCHMARK_RESULT_ITERATOR>>();
                RPC::Administrator::Instance().Recall<QualityAssurance::IBenchmark>();
                RPC::Administrator::Instance().Recall<QualityAssurance::IBenchmark::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
