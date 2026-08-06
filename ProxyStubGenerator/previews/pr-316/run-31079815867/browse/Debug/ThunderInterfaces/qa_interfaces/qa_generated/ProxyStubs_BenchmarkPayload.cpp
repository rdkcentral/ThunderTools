//
// generated automatically from "IBenchmarkPayload.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = QualityAssurance::IBenchmarkPayload::PayloadType, INTERFACE_ID = QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR] [[iterator]]
//   - class QualityAssurance::IBenchmarkPayload
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
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::IBenchmarkPayload::PayloadType _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<QualityAssurance::IBenchmarkPayload::PayloadType>(_info);
        },

        // (1) virtual bool Previous(QualityAssurance::IBenchmarkPayload::PayloadType&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::IBenchmarkPayload::PayloadType _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<QualityAssurance::IBenchmarkPayload::PayloadType>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual QualityAssurance::IBenchmarkPayload::PayloadType Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::IBenchmarkPayload::PayloadType result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<QualityAssurance::IBenchmarkPayload::PayloadType>(result);
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
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator* _types{};

            Core::hresult result = implementation->GetPayloadTypes(_types);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_types));

            RPC::Administrator::Instance().RegisterInterface(channel, _types);
        },

        // (1) virtual Core::hresult SendUint16(const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _value = reader.Number<uint16_t>();

            Core::hresult result = implementation->SendUint16(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (2) virtual Core::hresult SendUint32(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _value = reader.Number<uint32_t>();

            Core::hresult result = implementation->SendUint32(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult SendUint64(const uint64_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint64_t _value = reader.Number<uint64_t>();

            Core::hresult result = implementation->SendUint64(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult SendBool(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _value = reader.Boolean();

            Core::hresult result = implementation->SendBool(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (5) virtual Core::hresult SendFloat(const float) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const float _value = reader.Number<float>();

            Core::hresult result = implementation->SendFloat(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (6) virtual Core::hresult SendDouble(const double) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const double _value = reader.Number<double>();

            Core::hresult result = implementation->SendDouble(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (7) virtual Core::hresult SendString(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _value = reader.Text();

            Core::hresult result = implementation->SendString(static_cast<const string&>(_value));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (8) virtual Core::hresult SendSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            QualityAssurance::IBenchmarkPayload::SampleData _data{};
            _data.id = reader.Number<uint32_t>();
            _data.value = reader.Number<uint32_t>();
            _data.name = reader.Text();

            Core::hresult result = implementation->SendSampleData(static_cast<const QualityAssurance::IBenchmarkPayload::SampleData&>(_data));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (9) virtual Core::hresult SendNoPayload() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->SendNoPayload();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (10) virtual Core::hresult SendBuffer(const uint16_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _buffer{};
            const uint16_t _bufferSize = reader.LockBuffer<uint16_t>(_buffer);
            reader.UnlockBuffer(_bufferSize);

            Core::hresult result = implementation->SendBuffer(_bufferSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (11) virtual Core::hresult SendUint32Vector(const std::vector<uint32_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            std::vector<uint32_t> _data{};
            uint16_t _dataSize = reader.Number<uint16_t>();
            ASSERT((_dataSize >= 1) && (_dataSize <= 1024));
            _data.reserve(_dataSize);
            for (uint16_t i = 0; i < _dataSize; i++) {
                uint32_t _dataItem = reader.Number<uint32_t>();
                _data.push_back(std::move(_dataItem));
            }

            Core::hresult result = implementation->SendUint32Vector(static_cast<const std::vector<uint32_t>&>(_data));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (12) virtual Core::hresult SendReceiveUint16(const uint16_t, uint16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _input = reader.Number<uint16_t>();

            uint16_t _output{};

            Core::hresult result = implementation->SendReceiveUint16(_input, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint16_t>(_output);
        },

        // (13) virtual Core::hresult SendReceiveUint32(const uint32_t, uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _input = reader.Number<uint32_t>();

            uint32_t _output{};

            Core::hresult result = implementation->SendReceiveUint32(_input, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_output);
        },

        // (14) virtual Core::hresult SendReceiveUint64(const uint64_t, uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint64_t _input = reader.Number<uint64_t>();

            uint64_t _output{};

            Core::hresult result = implementation->SendReceiveUint64(_input, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint64_t>(_output);
        },

        // (15) virtual Core::hresult SendReceiveBool(const bool, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _input = reader.Boolean();

            bool _output{};

            Core::hresult result = implementation->SendReceiveBool(_input, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_output);
        },

        // (16) virtual Core::hresult SendReceiveFloat(const float, float&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const float _input = reader.Number<float>();

            float _output{};

            Core::hresult result = implementation->SendReceiveFloat(_input, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<float>(_output);
        },

        // (17) virtual Core::hresult SendReceiveDouble(const double, double&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const double _input = reader.Number<double>();

            double _output{};

            Core::hresult result = implementation->SendReceiveDouble(_input, _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<double>(_output);
        },

        // (18) virtual Core::hresult SendReceiveString(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _input = reader.Text();

            string _output{};

            Core::hresult result = implementation->SendReceiveString(static_cast<const string&>(_input), _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_output);
        },

        // (19) virtual Core::hresult SendReceiveSampleData(const QualityAssurance::IBenchmarkPayload::SampleData&, QualityAssurance::IBenchmarkPayload::SampleData&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            QualityAssurance::IBenchmarkPayload::SampleData _input{};
            _input.id = reader.Number<uint32_t>();
            _input.value = reader.Number<uint32_t>();
            _input.name = reader.Text();

            QualityAssurance::IBenchmarkPayload::SampleData _output{};

            Core::hresult result = implementation->SendReceiveSampleData(static_cast<const QualityAssurance::IBenchmarkPayload::SampleData&>(_input), _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_output.id);
            writer.Number<uint32_t>(_output.value);
            writer.Text(_output.name);
        },

        // (20) virtual Core::hresult SendReceiveBuffer(uint16_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint8_t* _buffer{};
            uint16_t _bufferSize = reader.LockBuffer<uint16_t>(const_cast<const uint8_t*&>(_buffer));
            reader.UnlockBuffer(_bufferSize);


            Core::hresult result = implementation->SendReceiveBuffer(_bufferSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Buffer<uint16_t>((_buffer == nullptr? 0 : _bufferSize), _buffer);
            writer.Number<uint16_t>(_bufferSize);
        },

        // (21) virtual Core::hresult SendReceiveUint32Vector(const std::vector<uint32_t>&, std::vector<uint32_t>&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            std::vector<uint32_t> _input{};
            uint16_t _inputSize = reader.Number<uint16_t>();
            ASSERT((_inputSize >= 1) && (_inputSize <= 1024));
            _input.reserve(_inputSize);
            for (uint16_t i = 0; i < _inputSize; i++) {
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
        },

        // (22) virtual Core::hresult Add(const uint32_t, const uint32_t, uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const QualityAssurance::IBenchmarkPayload* implementation = reinterpret_cast<const QualityAssurance::IBenchmarkPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _a = reader.Number<uint32_t>();
            const uint32_t _b = reader.Number<uint32_t>();

            uint32_t _result{};

            Core::hresult result = implementation->Add(_a, _b, _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint32_t>(_result);
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

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<QualityAssurance::IBenchmarkPayload::PayloadType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(QualityAssurance::IBenchmarkPayload::PayloadType& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<QualityAssurance::IBenchmarkPayload::PayloadType>();
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

        QualityAssurance::IBenchmarkPayload::PayloadType Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            QualityAssurance::IBenchmarkPayload::PayloadType result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<QualityAssurance::IBenchmarkPayload::PayloadType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _types = reinterpret_cast<QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), QualityAssurance::IBenchmarkPayload::IPayloadTypeIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult SendNoPayload() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Number<uint64_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Number<float>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Number<double>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output.id = reader.Number<uint32_t>();
                _output.value = reader.Number<uint32_t>();
                _output.name = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                reader.Buffer<uint16_t>(_bufferSize, _buffer);
                _bufferSize = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                uint16_t _outputSize{};
                _outputSize = reader.Number<uint16_t>();
                _output.reserve(_outputSize);
                for (uint16_t i = 0; i < _outputSize; i++) {
                    uint32_t _outputItem{};
                    _outputItem = reader.Number<uint32_t>();
                    _output.push_back(std::move(_outputItem));
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<QualityAssurance::IBenchmarkPayload::PayloadType, QualityAssurance::ID_BENCHMARK_PAYLOADTYPE_ITERATOR>, RPCIteratorTypeInstance_05353879ce17b341Proxy, RPCIteratorTypeInstance_05353879ce17b341Stub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::IBenchmarkPayload, QualityAssuranceBenchmarkPayloadProxy, QualityAssuranceBenchmarkPayloadStub>();
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
