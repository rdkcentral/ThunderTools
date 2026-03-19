//
// generated automatically from "ISimpleAsync.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = uint32_t, INTERFACE_ID = RPC::ID_VALUEITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = RPC::Environment, INTERFACE_ID = RPC::ID_ENVIRONMENTITERATOR] [[iterator]]
//   - class Example::ISimpleAsync
//   - class Example::ISimpleAsync::ICallback
//   - class Example::ISimpleAsync::INotification
//   - class Example::ISimpleAsync::IBindNotification
//

#include "Module.h"
#include "ISimpleAsync.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_bd6e04b8d151c1f7 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_bd6e04b8d151c1f7StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_bd6e04b8d151c1f7StubMethods

    //
    // RPC::IIteratorTypeInstance_60eba5a793c685ea interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(uint32_t&) = 0
    //  (1) virtual bool Previous(uint32_t&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual uint32_t Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_60eba5a793c685eaStubMethods[] = {
        // (0) virtual bool Next(uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<uint32_t>(_info);
        },

        // (1) virtual bool Previous(uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<uint32_t>(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_60eba5a793c685eaStubMethods

    //
    // RPC::IIteratorTypeInstance_195e88cf7f955a2e interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(RPC::Environment&) = 0
    //  (1) virtual bool Previous(RPC::Environment&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual RPC::Environment Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_195e88cf7f955a2eStubMethods[] = {
        // (0) virtual bool Next(RPC::Environment&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Environment _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.Key);
            writer.Text(_info.Value);
            writer.Number<RPC::Environment::scope>(_info.Scope);
        },

        // (1) virtual bool Previous(RPC::Environment&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Environment _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.Key);
            writer.Text(_info.Value);
            writer.Number<RPC::Environment::scope>(_info.Scope);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual RPC::Environment Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Environment result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result.Key);
            writer.Text(result.Value);
            writer.Number<RPC::Environment::scope>(result.Scope);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_195e88cf7f955a2eStubMethods

    //
    // Example::ISimpleAsync interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Connect(const Core::OptionalType<std::vector<uint8_t>>&, const Core::OptionalType<uint16_t>&, Example::ISimpleAsync::ICallback* const) = 0
    //  (1) virtual Core::hresult Abort() = 0
    //  (2) virtual Core::hresult Disconnect() = 0
    //  (3) virtual Core::hresult Connected(const std::vector<uint8_t>&, bool&) const = 0
    //  (4) virtual Core::hresult Link(const uint8_t[6]) = 0
    //  (5) virtual Core::hresult Unlink(const uint8_t[6]) = 0
    //  (6) virtual Core::hresult LinkedDevice(uint8_t[6]) const = 0
    //  (7) virtual Core::hresult Register(Example::ISimpleAsync::INotification* const) = 0
    //  (8) virtual Core::hresult Unregister(const Example::ISimpleAsync::INotification* const) = 0
    //  (9) virtual Core::hresult Metadata(const uint8_t[6], const string&) = 0
    //  (10) virtual Core::hresult Metadata(const uint8_t[6], string&) const = 0
    //  (11) virtual Core::hresult Bind(const Core::MACAddress&) = 0
    //  (12) virtual Core::hresult Unbind(const Core::MACAddress&) = 0
    //  (13) virtual Core::hresult BoundDevice(Core::MACAddress&) const = 0
    //  (14) virtual Core::hresult Type(const Core::MACAddress&, const string&) = 0
    //  (15) virtual Core::hresult Type(const Core::MACAddress&, string&) const = 0
    //  (16) virtual Core::hresult Register(Example::ISimpleAsync::IBindNotification* const) = 0
    //  (17) virtual Core::hresult Unregister(const Example::ISimpleAsync::IBindNotification* const) = 0
    //  (18) virtual Core::hresult Tables(const bool, std::vector<string>&) = 0
    //  (19) virtual Core::hresult Tables2(const bool, std::vector<string>&, std::vector<uint8_t>&) = 0
    //  (20) virtual Core::hresult Tables3(const bool, Core::OptionalType<std::vector<string>>&) = 0
    //  (21) virtual Core::hresult Tables4(const bool, RPC::IStringIterator*&) = 0
    //  (22) virtual Core::hresult Tables5(const bool, RPC::IStringIterator*&, RPC::IValueIterator*&) = 0
    //  (23) virtual Core::hresult Tables6(const bool, Example::ISimpleAsync::Record&) = 0
    //  (24) virtual Core::hresult Tables7(const bool, Core::OptionalType<Example::ISimpleAsync::Record>&) = 0
    //  (25) virtual Core::hresult Tables8(const bool, Core::OptionalType<Example::ISimpleAsync::Record2>&) = 0
    //  (26) virtual Core::hresult Tables9(const bool, Example::ISimpleAsync::Record2&) = 0
    //  (27) virtual Core::hresult OptionalResult(const bool, Core::OptionalType<string>&) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleAsyncStubMethods[] = {
        // (0) virtual Core::hresult Connect(const Core::OptionalType<std::vector<uint8_t>>&, const Core::OptionalType<uint16_t>&, Example::ISimpleAsync::ICallback* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<std::vector<uint8_t>> _address{};
            if (reader.Boolean() == true) {
                std::vector<uint8_t> _addressObject__{};
                uint8_t _addressObject__Size = reader.Number<uint8_t>();
                ASSERT((_addressObject__Size >= 6) && (_addressObject__Size <= 6));
                _address.Value().reserve(_addressObject__Size);
                for (uint8_t i = 0; i < _addressObject__Size; i++) {
                    uint8_t _addressObject__Item = reader.Number<uint8_t>();
                    _address.Value().push_back(std::move(_addressObject__Item));
                }
                _address = std::move(_addressObject__);
            }
            Core::OptionalType<uint16_t> _timeout{};
            if (reader.Boolean() == true) {
                _timeout = reader.Number<uint16_t>();
            }
            Core::instance_id _cbInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleAsync::ICallback* _cb{};
            ProxyStub::UnknownProxy* _cbProxy__ = nullptr;
            if (_cbInstanceId__ != 0) {
                _cbProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _cbInstanceId__, false, _cb);
                ASSERT((_cb != nullptr) && (_cbProxy__ != nullptr));
            }

            Core::hresult result = implementation->Connect(static_cast<const Core::OptionalType<std::vector<uint8_t>>&>(_address), static_cast<const Core::OptionalType<uint16_t>&>(_timeout), _cb);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_cbProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_cbProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Abort() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Abort();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (2) virtual Core::hresult Disconnect() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Disconnect();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult Connected(const std::vector<uint8_t>&, bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleAsync* implementation = reinterpret_cast<const Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            std::vector<uint8_t> _address{};
            uint8_t _addressSize = reader.Number<uint8_t>();
            ASSERT((_addressSize >= 6) && (_addressSize <= 6));
            _address.reserve(_addressSize);
            for (uint8_t i = 0; i < _addressSize; i++) {
                uint8_t _addressItem = reader.Number<uint8_t>();
                _address.push_back(std::move(_addressItem));
            }

            bool _result{};

            Core::hresult result = implementation->Connected(static_cast<const std::vector<uint8_t>&>(_address), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_result);
        },

        // (4) virtual Core::hresult Link(const uint8_t[6]) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _address{};
            uint8_t addressFixedLen = reader.LockBuffer<uint8_t>(_address);
            reader.UnlockBuffer(addressFixedLen);

            Core::hresult result = implementation->Link(_address);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (5) virtual Core::hresult Unlink(const uint8_t[6]) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _address{};
            uint8_t addressFixedLen = reader.LockBuffer<uint8_t>(_address);
            reader.UnlockBuffer(addressFixedLen);

            Core::hresult result = implementation->Unlink(_address);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (6) virtual Core::hresult LinkedDevice(uint8_t[6]) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleAsync* implementation = reinterpret_cast<const Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t* _address{};

            _address = static_cast<uint8_t*>(ALLOCA(6 * sizeof(uint8_t)));
            ASSERT(_address != nullptr);

            Core::hresult result = implementation->LinkedDevice(_address);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Buffer<uint8_t>(6, _address);
        },

        // (7) virtual Core::hresult Register(Example::ISimpleAsync::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleAsync::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (8) virtual Core::hresult Unregister(const Example::ISimpleAsync::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Example::ISimpleAsync::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (9) virtual Core::hresult Metadata(const uint8_t[6], const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _address{};
            uint8_t addressFixedLen = reader.LockBuffer<uint8_t>(_address);
            reader.UnlockBuffer(addressFixedLen);
            const string _metadata = reader.Text();

            Core::hresult result = implementation->Metadata(_address, static_cast<const string&>(_metadata));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (10) virtual Core::hresult Metadata(const uint8_t[6], string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleAsync* implementation = reinterpret_cast<const Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _address{};
            uint8_t addressFixedLen = reader.LockBuffer<uint8_t>(_address);
            reader.UnlockBuffer(addressFixedLen);

            string _metadata{};

            Core::hresult result = implementation->Metadata(_address, _metadata);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_metadata);
        },

        // (11) virtual Core::hresult Bind(const Core::MACAddress&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* addressBuffer{};
            const uint8_t addressLength = reader.LockBuffer<uint8_t>(addressBuffer);
            ASSERT(addressLength == 6);
            reader.UnlockBuffer(addressLength);
            Core::MACAddress _address{addressBuffer};

            Core::hresult result = implementation->Bind(static_cast<const Core::MACAddress&>(_address));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (12) virtual Core::hresult Unbind(const Core::MACAddress&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* addressBuffer{};
            const uint8_t addressLength = reader.LockBuffer<uint8_t>(addressBuffer);
            ASSERT(addressLength == 6);
            reader.UnlockBuffer(addressLength);
            Core::MACAddress _address{addressBuffer};

            Core::hresult result = implementation->Unbind(static_cast<const Core::MACAddress&>(_address));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (13) virtual Core::hresult BoundDevice(Core::MACAddress&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleAsync* implementation = reinterpret_cast<const Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::MACAddress _address{};

            Core::hresult result = implementation->BoundDevice(_address);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Buffer<uint8_t>(6, _address);
        },

        // (14) virtual Core::hresult Type(const Core::MACAddress&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* addressBuffer{};
            const uint8_t addressLength = reader.LockBuffer<uint8_t>(addressBuffer);
            ASSERT(addressLength == 6);
            reader.UnlockBuffer(addressLength);
            Core::MACAddress _address{addressBuffer};
            const string _value = reader.Text();

            Core::hresult result = implementation->Type(static_cast<const Core::MACAddress&>(_address), static_cast<const string&>(_value));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (15) virtual Core::hresult Type(const Core::MACAddress&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Example::ISimpleAsync* implementation = reinterpret_cast<const Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* addressBuffer{};
            const uint8_t addressLength = reader.LockBuffer<uint8_t>(addressBuffer);
            ASSERT(addressLength == 6);
            reader.UnlockBuffer(addressLength);
            Core::MACAddress _address{addressBuffer};

            string _value{};

            Core::hresult result = implementation->Type(static_cast<const Core::MACAddress&>(_address), _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_value);
        },

        // (16) virtual Core::hresult Register(Example::ISimpleAsync::IBindNotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Example::ISimpleAsync::IBindNotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (17) virtual Core::hresult Unregister(const Example::ISimpleAsync::IBindNotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Example::ISimpleAsync::IBindNotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (18) virtual Core::hresult Tables(const bool, std::vector<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            std::vector<string> _stringTables{};

            Core::hresult result = implementation->Tables(_fill, _stringTables);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint8_t>(_stringTables.size());
            for (uint8_t i = 0; i < _stringTables.size(); i++) {
                writer.Text(_stringTables[i]);
            }
        },

        // (19) virtual Core::hresult Tables2(const bool, std::vector<string>&, std::vector<uint8_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            std::vector<string> _stringTables{};
            std::vector<uint8_t> _intTables{};

            Core::hresult result = implementation->Tables2(_fill, _stringTables, _intTables);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint8_t>(_stringTables.size());
            for (uint8_t i = 0; i < _stringTables.size(); i++) {
                writer.Text(_stringTables[i]);
            }
            writer.Number<uint8_t>(_intTables.size());
            for (uint8_t i = 0; i < _intTables.size(); i++) {
                writer.Number<uint8_t>(_intTables[i]);
            }
        },

        // (20) virtual Core::hresult Tables3(const bool, Core::OptionalType<std::vector<string>>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            Core::OptionalType<std::vector<string>> _stringTables{};

            Core::hresult result = implementation->Tables3(_fill, _stringTables);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_stringTables.IsSet());
            if (_stringTables.IsSet() == true) {
                writer.Number<uint8_t>(_stringTables.Value().size());
                for (uint8_t i = 0; i < _stringTables.Value().size(); i++) {
                    writer.Text(_stringTables.Value()[i]);
                }
            }
        },

        // (21) virtual Core::hresult Tables4(const bool, RPC::IStringIterator*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            RPC::IStringIterator* _stringTables{};

            Core::hresult result = implementation->Tables4(_fill, _stringTables);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_stringTables));

            RPC::Administrator::Instance().RegisterInterface(channel, _stringTables);
        },

        // (22) virtual Core::hresult Tables5(const bool, RPC::IStringIterator*&, RPC::IValueIterator*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            RPC::IStringIterator* _stringTables{};
            RPC::IValueIterator* _intTables{};

            Core::hresult result = implementation->Tables5(_fill, _stringTables, _intTables);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_stringTables));
            writer.Number<Core::instance_id>(RPC::instance_cast(_intTables));

            RPC::Administrator::Instance().RegisterInterface(channel, _stringTables);
            RPC::Administrator::Instance().RegisterInterface(channel, _intTables);
        },

        // (23) virtual Core::hresult Tables6(const bool, Example::ISimpleAsync::Record&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            Example::ISimpleAsync::Record _pod{};

            Core::hresult result = implementation->Tables6(_fill, _pod);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_pod.param0);
            writer.Number<uint8_t>(_pod.param1.size());
            for (uint8_t i = 0; i < _pod.param1.size(); i++) {
                writer.Text(_pod.param1[i]);
            }
            writer.Number<uint8_t>(_pod.param2.size());
            for (uint8_t i = 0; i < _pod.param2.size(); i++) {
                writer.Text(_pod.param2[i]);
            }
            writer.Boolean(_pod.param3.IsSet());
            if (_pod.param3.IsSet() == true) {
                writer.Number<uint8_t>(_pod.param3.Value().size());
                for (uint8_t i = 0; i < _pod.param3.Value().size(); i++) {
                    writer.Text(_pod.param3.Value()[i]);
                }
            }
            writer.Boolean(_pod.param4.IsSet());
            if (_pod.param4.IsSet() == true) {
                writer.Number<uint8_t>(_pod.param4.Value().size());
                for (uint8_t i = 0; i < _pod.param4.Value().size(); i++) {
                    writer.Text(_pod.param4.Value()[i]);
                }
            }
            writer.Text(_pod.param5.param0);
            writer.Boolean(_pod.param5.param1);
            writer.Boolean(_pod.param6.IsSet());
            if (_pod.param6.IsSet() == true) {
                writer.Text(_pod.param6.Value().param0);
                writer.Boolean(_pod.param6.Value().param1);
            }
        },

        // (24) virtual Core::hresult Tables7(const bool, Core::OptionalType<Example::ISimpleAsync::Record>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            Core::OptionalType<Example::ISimpleAsync::Record> _pod{};

            Core::hresult result = implementation->Tables7(_fill, _pod);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_pod.IsSet());
            if (_pod.IsSet() == true) {
                writer.Text(_pod.Value().param0);
                writer.Number<uint8_t>(_pod.Value().param1.size());
                for (uint8_t i = 0; i < _pod.Value().param1.size(); i++) {
                    writer.Text(_pod.Value().param1[i]);
                }
                writer.Number<uint8_t>(_pod.Value().param2.size());
                for (uint8_t i = 0; i < _pod.Value().param2.size(); i++) {
                    writer.Text(_pod.Value().param2[i]);
                }
                writer.Boolean(_pod.Value().param3.IsSet());
                if (_pod.Value().param3.IsSet() == true) {
                    writer.Number<uint8_t>(_pod.Value().param3.Value().size());
                    for (uint8_t i = 0; i < _pod.Value().param3.Value().size(); i++) {
                        writer.Text(_pod.Value().param3.Value()[i]);
                    }
                }
                writer.Boolean(_pod.Value().param4.IsSet());
                if (_pod.Value().param4.IsSet() == true) {
                    writer.Number<uint8_t>(_pod.Value().param4.Value().size());
                    for (uint8_t i = 0; i < _pod.Value().param4.Value().size(); i++) {
                        writer.Text(_pod.Value().param4.Value()[i]);
                    }
                }
                writer.Text(_pod.Value().param5.param0);
                writer.Boolean(_pod.Value().param5.param1);
                writer.Boolean(_pod.Value().param6.IsSet());
                if (_pod.Value().param6.IsSet() == true) {
                    writer.Text(_pod.Value().param6.Value().param0);
                    writer.Boolean(_pod.Value().param6.Value().param1);
                }
            }
        },

        // (25) virtual Core::hresult Tables8(const bool, Core::OptionalType<Example::ISimpleAsync::Record2>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            Core::OptionalType<Example::ISimpleAsync::Record2> _pod{};

            Core::hresult result = implementation->Tables8(_fill, _pod);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_pod.IsSet());
            if (_pod.IsSet() == true) {
                writer.Boolean(_pod.Value().param3.IsSet());
                if (_pod.Value().param3.IsSet() == true) {
                    writer.Number<uint8_t>(_pod.Value().param3.Value().size());
                    for (uint8_t i = 0; i < _pod.Value().param3.Value().size(); i++) {
                        writer.Text(_pod.Value().param3.Value()[i]);
                    }
                }
                writer.Boolean(_pod.Value().param4.IsSet());
                if (_pod.Value().param4.IsSet() == true) {
                    writer.Number<uint8_t>(_pod.Value().param4.Value().size());
                    for (uint8_t i = 0; i < _pod.Value().param4.Value().size(); i++) {
                        writer.Text(_pod.Value().param4.Value()[i]);
                    }
                }
            }
        },

        // (26) virtual Core::hresult Tables9(const bool, Example::ISimpleAsync::Record2&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            Example::ISimpleAsync::Record2 _pod{};

            Core::hresult result = implementation->Tables9(_fill, _pod);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_pod.param3.IsSet());
            if (_pod.param3.IsSet() == true) {
                writer.Number<uint8_t>(_pod.param3.Value().size());
                for (uint8_t i = 0; i < _pod.param3.Value().size(); i++) {
                    writer.Text(_pod.param3.Value()[i]);
                }
            }
            writer.Boolean(_pod.param4.IsSet());
            if (_pod.param4.IsSet() == true) {
                writer.Number<uint8_t>(_pod.param4.Value().size());
                for (uint8_t i = 0; i < _pod.param4.Value().size(); i++) {
                    writer.Text(_pod.param4.Value()[i]);
                }
            }
        },

        // (27) virtual Core::hresult OptionalResult(const bool, Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync* implementation = reinterpret_cast<Example::ISimpleAsync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _fill = reader.Boolean();

            Core::OptionalType<string> _result{};

            Core::hresult result = implementation->OptionalResult(_fill, _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_result.IsSet());
            if (_result.IsSet() == true) {
                writer.Text(_result.Value());
            }
        }
        , nullptr
    }; // ExampleSimpleAsyncStubMethods

    //
    // Example::ISimpleAsync::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Complete(const Core::OptionalType<std::vector<uint8_t>>&, const Example::ISimpleAsync::state) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleAsyncCallbackStubMethods[] = {
        // (0) virtual void Complete(const Core::OptionalType<std::vector<uint8_t>>&, const Example::ISimpleAsync::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync::ICallback* implementation = reinterpret_cast<Example::ISimpleAsync::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<std::vector<uint8_t>> _address{};
            if (reader.Boolean() == true) {
                std::vector<uint8_t> _addressObject__{};
                uint8_t _addressObject__Size = reader.Number<uint8_t>();
                ASSERT((_addressObject__Size >= 6) && (_addressObject__Size <= 6));
                _address.Value().reserve(_addressObject__Size);
                for (uint8_t i = 0; i < _addressObject__Size; i++) {
                    uint8_t _addressObject__Item = reader.Number<uint8_t>();
                    _address.Value().push_back(std::move(_addressObject__Item));
                }
                _address = std::move(_addressObject__);
            }
            const Example::ISimpleAsync::state _state = reader.Number<Example::ISimpleAsync::state>();

            implementation->Complete(static_cast<const Core::OptionalType<std::vector<uint8_t>>&>(_address), _state);
        }
        , nullptr
    }; // ExampleSimpleAsyncCallbackStubMethods

    //
    // Example::ISimpleAsync::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StatusChanged(const uint8_t[6], const bool) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleAsyncNotificationStubMethods[] = {
        // (0) virtual void StatusChanged(const uint8_t[6], const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync::INotification* implementation = reinterpret_cast<Example::ISimpleAsync::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _address{};
            uint8_t addressFixedLen = reader.LockBuffer<uint8_t>(_address);
            reader.UnlockBuffer(addressFixedLen);
            const bool _linked = reader.Boolean();

            implementation->StatusChanged(_address, _linked);
        }
        , nullptr
    }; // ExampleSimpleAsyncNotificationStubMethods

    //
    // Example::ISimpleAsync::IBindNotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void BindingChanged(const Core::MACAddress&, const bool) = 0
    //

    static ProxyStub::MethodHandler ExampleSimpleAsyncBindNotificationStubMethods[] = {
        // (0) virtual void BindingChanged(const Core::MACAddress&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Example::ISimpleAsync::IBindNotification* implementation = reinterpret_cast<Example::ISimpleAsync::IBindNotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* addressBuffer{};
            const uint8_t addressLength = reader.LockBuffer<uint8_t>(addressBuffer);
            ASSERT(addressLength == 6);
            reader.UnlockBuffer(addressLength);
            Core::MACAddress _address{addressBuffer};
            const bool _bound = reader.Boolean();

            implementation->BindingChanged(static_cast<const Core::MACAddress&>(_address), _bound);
        }
        , nullptr
    }; // ExampleSimpleAsyncBindNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_bd6e04b8d151c1f7 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
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

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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

    }; // class RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy

    //
    // RPC::IIteratorTypeInstance_60eba5a793c685ea interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(uint32_t&) = 0
    //  (1) virtual bool Previous(uint32_t&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual uint32_t Current() const = 0
    //

    class RPCIteratorTypeInstance_60eba5a793c685eaProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>> {
    public:
        RPCIteratorTypeInstance_60eba5a793c685eaProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(uint32_t& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(uint32_t& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Number<uint32_t>();
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

        uint32_t Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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

    }; // class RPCIteratorTypeInstance_60eba5a793c685eaProxy

    //
    // RPC::IIteratorTypeInstance_195e88cf7f955a2e interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(RPC::Environment&) = 0
    //  (1) virtual bool Previous(RPC::Environment&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual RPC::Environment Current() const = 0
    //

    class RPCIteratorTypeInstance_195e88cf7f955a2eProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>> {
    public:
        RPCIteratorTypeInstance_195e88cf7f955a2eProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(RPC::Environment& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.Key = reader.Text();
                _info.Value = reader.Text();
                _info.Scope = reader.Number<RPC::Environment::scope>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(RPC::Environment& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.Key = reader.Text();
                _info.Value = reader.Text();
                _info.Scope = reader.Number<RPC::Environment::scope>();
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

        RPC::Environment Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Environment result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result.Key = reader.Text();
                result.Value = reader.Text();
                result.Scope = reader.Number<RPC::Environment::scope>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_195e88cf7f955a2eProxy

    //
    // Example::ISimpleAsync interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Connect(const Core::OptionalType<std::vector<uint8_t>>&, const Core::OptionalType<uint16_t>&, Example::ISimpleAsync::ICallback* const) = 0
    //  (1) virtual Core::hresult Abort() = 0
    //  (2) virtual Core::hresult Disconnect() = 0
    //  (3) virtual Core::hresult Connected(const std::vector<uint8_t>&, bool&) const = 0
    //  (4) virtual Core::hresult Link(const uint8_t[6]) = 0
    //  (5) virtual Core::hresult Unlink(const uint8_t[6]) = 0
    //  (6) virtual Core::hresult LinkedDevice(uint8_t[6]) const = 0
    //  (7) virtual Core::hresult Register(Example::ISimpleAsync::INotification* const) = 0
    //  (8) virtual Core::hresult Unregister(const Example::ISimpleAsync::INotification* const) = 0
    //  (9) virtual Core::hresult Metadata(const uint8_t[6], const string&) = 0
    //  (10) virtual Core::hresult Metadata(const uint8_t[6], string&) const = 0
    //  (11) virtual Core::hresult Bind(const Core::MACAddress&) = 0
    //  (12) virtual Core::hresult Unbind(const Core::MACAddress&) = 0
    //  (13) virtual Core::hresult BoundDevice(Core::MACAddress&) const = 0
    //  (14) virtual Core::hresult Type(const Core::MACAddress&, const string&) = 0
    //  (15) virtual Core::hresult Type(const Core::MACAddress&, string&) const = 0
    //  (16) virtual Core::hresult Register(Example::ISimpleAsync::IBindNotification* const) = 0
    //  (17) virtual Core::hresult Unregister(const Example::ISimpleAsync::IBindNotification* const) = 0
    //  (18) virtual Core::hresult Tables(const bool, std::vector<string>&) = 0
    //  (19) virtual Core::hresult Tables2(const bool, std::vector<string>&, std::vector<uint8_t>&) = 0
    //  (20) virtual Core::hresult Tables3(const bool, Core::OptionalType<std::vector<string>>&) = 0
    //  (21) virtual Core::hresult Tables4(const bool, RPC::IStringIterator*&) = 0
    //  (22) virtual Core::hresult Tables5(const bool, RPC::IStringIterator*&, RPC::IValueIterator*&) = 0
    //  (23) virtual Core::hresult Tables6(const bool, Example::ISimpleAsync::Record&) = 0
    //  (24) virtual Core::hresult Tables7(const bool, Core::OptionalType<Example::ISimpleAsync::Record>&) = 0
    //  (25) virtual Core::hresult Tables8(const bool, Core::OptionalType<Example::ISimpleAsync::Record2>&) = 0
    //  (26) virtual Core::hresult Tables9(const bool, Example::ISimpleAsync::Record2&) = 0
    //  (27) virtual Core::hresult OptionalResult(const bool, Core::OptionalType<string>&) = 0
    //

    class ExampleSimpleAsyncProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleAsync> {
    public:
        ExampleSimpleAsyncProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Connect(const Core::OptionalType<std::vector<uint8_t>>& _address, const Core::OptionalType<uint16_t>& _timeout, Example::ISimpleAsync::ICallback* const _cb) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_address.IsSet());
            if (_address.IsSet() == true) {
                writer.Number<uint8_t>(_address.Value().size());
                for (uint8_t i = 0; i < _address.Value().size(); i++) {
                    writer.Number<uint8_t>(_address.Value()[i]);
                }
            }
            writer.Boolean(_timeout.IsSet());
            if (_timeout.IsSet() == true) {
                writer.Number<uint16_t>(_timeout.Value());
            }
            writer.Number<Core::instance_id>(RPC::instance_cast(_cb));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Abort() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Disconnect() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Connected(const std::vector<uint8_t>& _address, bool& _result) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_address.size());
            for (uint8_t i = 0; i < _address.size(); i++) {
                writer.Number<uint8_t>(_address[i]);
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Link(const uint8_t _address[6]) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unlink(const uint8_t _address[6]) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult LinkedDevice(uint8_t _address[6]) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                reader.Buffer<uint8_t>(6, _address);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Register(Example::ISimpleAsync::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unregister(const Example::ISimpleAsync::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Metadata(const uint8_t _address[6], const string& _metadata) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);
            writer.Text(_metadata);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Metadata(const uint8_t _address[6], string& _metadata) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _metadata = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Bind(const Core::MACAddress& _address) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unbind(const Core::MACAddress& _address) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult BoundDevice(Core::MACAddress& _address) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                reader.Buffer<uint8_t>(6, _address);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Type(const Core::MACAddress& _address, const string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);
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

        Core::hresult Type(const Core::MACAddress& _address, string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _value = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Register(Example::ISimpleAsync::IBindNotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(16));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unregister(const Example::ISimpleAsync::IBindNotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(17));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables(const bool _fill, std::vector<string>& _stringTables) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(18));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                uint8_t _stringTablesSize{};
                _stringTablesSize = reader.Number<uint8_t>();
                _stringTables.reserve(_stringTablesSize);
                for (uint8_t i = 0; i < _stringTablesSize; i++) {
                    string _stringTablesItem{};
                    _stringTablesItem = reader.Text();
                    _stringTables.push_back(std::move(_stringTablesItem));
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables2(const bool _fill, std::vector<string>& _stringTables, std::vector<uint8_t>& _intTables) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(19));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                uint8_t _stringTablesSize{};
                _stringTablesSize = reader.Number<uint8_t>();
                _stringTables.reserve(_stringTablesSize);
                for (uint8_t i = 0; i < _stringTablesSize; i++) {
                    string _stringTablesItem{};
                    _stringTablesItem = reader.Text();
                    _stringTables.push_back(std::move(_stringTablesItem));
                }
                uint8_t _intTablesSize{};
                _intTablesSize = reader.Number<uint8_t>();
                _intTables.reserve(_intTablesSize);
                for (uint8_t i = 0; i < _intTablesSize; i++) {
                    uint8_t _intTablesItem{};
                    _intTablesItem = reader.Number<uint8_t>();
                    _intTables.push_back(std::move(_intTablesItem));
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables3(const bool _fill, Core::OptionalType<std::vector<string>>& _stringTables) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(20));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    uint8_t _stringTablesSize{};
                    _stringTablesSize = reader.Number<uint8_t>();
                    _stringTables.Value().reserve(_stringTablesSize);
                    for (uint8_t i = 0; i < _stringTablesSize; i++) {
                        string _stringTablesItem{};
                        _stringTablesItem = reader.Text();
                        _stringTables.Value().push_back(std::move(_stringTablesItem));
                    }
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables4(const bool _fill, RPC::IStringIterator*& _stringTables) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(21));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _stringTables = reinterpret_cast<RPC::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables5(const bool _fill, RPC::IStringIterator*& _stringTables, RPC::IValueIterator*& _intTables) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(22));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _stringTables = reinterpret_cast<RPC::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));
                _intTables = reinterpret_cast<RPC::IValueIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), RPC::IValueIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables6(const bool _fill, Example::ISimpleAsync::Record& _pod) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(23));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _pod.param0 = reader.Text();
                uint8_t _pod_param1Size{};
                _pod_param1Size = reader.Number<uint8_t>();
                _pod.param1.reserve(_pod_param1Size);
                for (uint8_t i = 0; i < _pod_param1Size; i++) {
                    string _pod_param1Item{};
                    _pod_param1Item = reader.Text();
                    _pod.param1.push_back(std::move(_pod_param1Item));
                }
                uint8_t _pod_param2Size{};
                _pod_param2Size = reader.Number<uint8_t>();
                _pod.param2.reserve(_pod_param2Size);
                for (uint8_t i = 0; i < _pod_param2Size; i++) {
                    string _pod_param2Item{};
                    _pod_param2Item = reader.Text();
                    _pod.param2.push_back(std::move(_pod_param2Item));
                }
                if (reader.Boolean() == true) {
                    uint8_t _pod_param3Size{};
                    _pod_param3Size = reader.Number<uint8_t>();
                    _pod.param3.Value().reserve(_pod_param3Size);
                    for (uint8_t i = 0; i < _pod_param3Size; i++) {
                        string _pod_param3Item{};
                        _pod_param3Item = reader.Text();
                        _pod.param3.Value().push_back(std::move(_pod_param3Item));
                    }
                }
                if (reader.Boolean() == true) {
                    uint8_t _pod_param4Size{};
                    _pod_param4Size = reader.Number<uint8_t>();
                    _pod.param4.Value().reserve(_pod_param4Size);
                    for (uint8_t i = 0; i < _pod_param4Size; i++) {
                        string _pod_param4Item{};
                        _pod_param4Item = reader.Text();
                        _pod.param4.Value().push_back(std::move(_pod_param4Item));
                    }
                }
                _pod.param5.param0 = reader.Text();
                _pod.param5.param1 = reader.Boolean();
                if (reader.Boolean() == true) {
                    Example::ISimpleAsync::SmallRecord _pod_param6Object__{};
                    _pod_param6Object__.param0 = reader.Text();
                    _pod_param6Object__.param1 = reader.Boolean();
                    _pod.param6 = std::move(_pod_param6Object__);
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables7(const bool _fill, Core::OptionalType<Example::ISimpleAsync::Record>& _pod) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(24));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    Example::ISimpleAsync::Record _podObject__{};
                    _podObject__.param0 = reader.Text();
                    uint8_t _podObject___param1Size{};
                    _podObject___param1Size = reader.Number<uint8_t>();
                    _podObject__.param1.reserve(_podObject___param1Size);
                    for (uint8_t i = 0; i < _podObject___param1Size; i++) {
                        string _podObject___param1Item{};
                        _podObject___param1Item = reader.Text();
                        _podObject__.param1.push_back(std::move(_podObject___param1Item));
                    }
                    uint8_t _podObject___param2Size{};
                    _podObject___param2Size = reader.Number<uint8_t>();
                    _podObject__.param2.reserve(_podObject___param2Size);
                    for (uint8_t i = 0; i < _podObject___param2Size; i++) {
                        string _podObject___param2Item{};
                        _podObject___param2Item = reader.Text();
                        _podObject__.param2.push_back(std::move(_podObject___param2Item));
                    }
                    if (reader.Boolean() == true) {
                        uint8_t _podObject___param3Size{};
                        _podObject___param3Size = reader.Number<uint8_t>();
                        _podObject__.param3.Value().reserve(_podObject___param3Size);
                        for (uint8_t i = 0; i < _podObject___param3Size; i++) {
                            string _podObject___param3Item{};
                            _podObject___param3Item = reader.Text();
                            _podObject__.param3.Value().push_back(std::move(_podObject___param3Item));
                        }
                    }
                    if (reader.Boolean() == true) {
                        uint8_t _podObject___param4Size{};
                        _podObject___param4Size = reader.Number<uint8_t>();
                        _podObject__.param4.Value().reserve(_podObject___param4Size);
                        for (uint8_t i = 0; i < _podObject___param4Size; i++) {
                            string _podObject___param4Item{};
                            _podObject___param4Item = reader.Text();
                            _podObject__.param4.Value().push_back(std::move(_podObject___param4Item));
                        }
                    }
                    _podObject__.param5.param0 = reader.Text();
                    _podObject__.param5.param1 = reader.Boolean();
                    if (reader.Boolean() == true) {
                        Example::ISimpleAsync::SmallRecord _podObject___param6Object__{};
                        _podObject___param6Object__.param0 = reader.Text();
                        _podObject___param6Object__.param1 = reader.Boolean();
                        _podObject__.param6 = std::move(_podObject___param6Object__);
                    }
                    _pod = std::move(_podObject__);
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables8(const bool _fill, Core::OptionalType<Example::ISimpleAsync::Record2>& _pod) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(25));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    Example::ISimpleAsync::Record2 _podObject__{};
                    if (reader.Boolean() == true) {
                        uint8_t _podObject___param3Size{};
                        _podObject___param3Size = reader.Number<uint8_t>();
                        _podObject__.param3.Value().reserve(_podObject___param3Size);
                        for (uint8_t i = 0; i < _podObject___param3Size; i++) {
                            string _podObject___param3Item{};
                            _podObject___param3Item = reader.Text();
                            _podObject__.param3.Value().push_back(std::move(_podObject___param3Item));
                        }
                    }
                    if (reader.Boolean() == true) {
                        uint8_t _podObject___param4Size{};
                        _podObject___param4Size = reader.Number<uint8_t>();
                        _podObject__.param4.Value().reserve(_podObject___param4Size);
                        for (uint8_t i = 0; i < _podObject___param4Size; i++) {
                            string _podObject___param4Item{};
                            _podObject___param4Item = reader.Text();
                            _podObject__.param4.Value().push_back(std::move(_podObject___param4Item));
                        }
                    }
                    _pod = std::move(_podObject__);
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Tables9(const bool _fill, Example::ISimpleAsync::Record2& _pod) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(26));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    uint8_t _pod_param3Size{};
                    _pod_param3Size = reader.Number<uint8_t>();
                    _pod.param3.Value().reserve(_pod_param3Size);
                    for (uint8_t i = 0; i < _pod_param3Size; i++) {
                        string _pod_param3Item{};
                        _pod_param3Item = reader.Text();
                        _pod.param3.Value().push_back(std::move(_pod_param3Item));
                    }
                }
                if (reader.Boolean() == true) {
                    uint8_t _pod_param4Size{};
                    _pod_param4Size = reader.Number<uint8_t>();
                    _pod.param4.Value().reserve(_pod_param4Size);
                    for (uint8_t i = 0; i < _pod_param4Size; i++) {
                        string _pod_param4Item{};
                        _pod_param4Item = reader.Text();
                        _pod.param4.Value().push_back(std::move(_pod_param4Item));
                    }
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult OptionalResult(const bool _fill, Core::OptionalType<string>& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(27));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_fill);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    _result = reader.Text();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
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

    }; // class ExampleSimpleAsyncProxy

    //
    // Example::ISimpleAsync::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Complete(const Core::OptionalType<std::vector<uint8_t>>&, const Example::ISimpleAsync::state) = 0
    //

    class ExampleSimpleAsyncCallbackProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleAsync::ICallback> {
    public:
        ExampleSimpleAsyncCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Complete(const Core::OptionalType<std::vector<uint8_t>>& _address, const Example::ISimpleAsync::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_address.IsSet());
            if (_address.IsSet() == true) {
                writer.Number<uint8_t>(_address.Value().size());
                for (uint8_t i = 0; i < _address.Value().size(); i++) {
                    writer.Number<uint8_t>(_address.Value()[i]);
                }
            }
            writer.Number<Example::ISimpleAsync::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExampleSimpleAsyncCallbackProxy

    //
    // Example::ISimpleAsync::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StatusChanged(const uint8_t[6], const bool) = 0
    //

    class ExampleSimpleAsyncNotificationProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleAsync::INotification> {
    public:
        ExampleSimpleAsyncNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StatusChanged(const uint8_t _address[6], const bool _linked) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);
            writer.Boolean(_linked);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExampleSimpleAsyncNotificationProxy

    //
    // Example::ISimpleAsync::IBindNotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void BindingChanged(const Core::MACAddress&, const bool) = 0
    //

    class ExampleSimpleAsyncBindNotificationProxy final : public ProxyStub::UnknownProxyType<Example::ISimpleAsync::IBindNotification> {
    public:
        ExampleSimpleAsyncBindNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void BindingChanged(const Core::MACAddress& _address, const bool _bound) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(6, _address);
            writer.Boolean(_bound);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExampleSimpleAsyncBindNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_bd6e04b8d151c1f7StubMethods> RPCIteratorTypeInstance_bd6e04b8d151c1f7Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>, RPCIteratorTypeInstance_60eba5a793c685eaStubMethods> RPCIteratorTypeInstance_60eba5a793c685eaStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>, RPCIteratorTypeInstance_195e88cf7f955a2eStubMethods> RPCIteratorTypeInstance_195e88cf7f955a2eStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleAsync, ExampleSimpleAsyncStubMethods> ExampleSimpleAsyncStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleAsync::ICallback, ExampleSimpleAsyncCallbackStubMethods> ExampleSimpleAsyncCallbackStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleAsync::INotification, ExampleSimpleAsyncNotificationStubMethods> ExampleSimpleAsyncNotificationStub;
        typedef ProxyStub::UnknownStubType<Example::ISimpleAsync::IBindNotification, ExampleSimpleAsyncBindNotificationStubMethods> ExampleSimpleAsyncBindNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy, RPCIteratorTypeInstance_bd6e04b8d151c1f7Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>, RPCIteratorTypeInstance_60eba5a793c685eaProxy, RPCIteratorTypeInstance_60eba5a793c685eaStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>, RPCIteratorTypeInstance_195e88cf7f955a2eProxy, RPCIteratorTypeInstance_195e88cf7f955a2eStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleAsync, ExampleSimpleAsyncProxy, ExampleSimpleAsyncStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleAsync::ICallback, ExampleSimpleAsyncCallbackProxy, ExampleSimpleAsyncCallbackStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleAsync::INotification, ExampleSimpleAsyncNotificationProxy, ExampleSimpleAsyncNotificationStub>();
                RPC::Administrator::Instance().Announce<Example::ISimpleAsync::IBindNotification, ExampleSimpleAsyncBindNotificationProxy, ExampleSimpleAsyncBindNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>>();
                RPC::Administrator::Instance().Recall<Example::ISimpleAsync>();
                RPC::Administrator::Instance().Recall<Example::ISimpleAsync::ICallback>();
                RPC::Administrator::Instance().Recall<Example::ISimpleAsync::INotification>();
                RPC::Administrator::Instance().Recall<Example::ISimpleAsync::IBindNotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
