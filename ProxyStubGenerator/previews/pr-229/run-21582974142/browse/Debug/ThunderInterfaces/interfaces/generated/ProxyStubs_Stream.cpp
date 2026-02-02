//
// generated automatically from "IStream.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = uint32_t, INTERFACE_ID = RPC::ID_VALUEITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = RPC::Environment, INTERFACE_ID = RPC::ID_ENVIRONMENTITERATOR] [[iterator]]
//   - class Exchange::IStream
//   - class Exchange::IStream::IElement
//   - class Exchange::IStream::IElement::IIterator
//   - class Exchange::IStream::IControl
//   - class Exchange::IStream::IControl::IGeometry
//   - class Exchange::IStream::IControl::ICallback
//   - class Exchange::IStream::ICallback
//   - class Exchange::IPlayer
//

#include "Module.h"
#include "IStream.h"

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
    // Exchange::IStream interface stub definitions
    //
    // Methods:
    //  (0) virtual string Metadata() const = 0
    //  (1) virtual Exchange::IStream::streamtype Type() const = 0
    //  (2) virtual Exchange::IStream::drmtype DRM() const = 0
    //  (3) virtual Exchange::IStream::IControl* Control() = 0
    //  (4) virtual void Callback(Exchange::IStream::ICallback*)
    //  (5) virtual void Attach(Exchange::IStream::ICallback*) = 0
    //  (6) virtual uint32_t Detach(Exchange::IStream::ICallback*) = 0
    //  (7) virtual Exchange::IStream::state State() const = 0
    //  (8) virtual uint32_t Load(const string&) = 0
    //  (9) virtual uint32_t Error() const = 0
    //  (10) virtual Exchange::IStream::IElement::IIterator* Elements() = 0
    //

    static ProxyStub::MethodHandler ExchangeStreamStubMethods[] = {
        // (0) virtual string Metadata() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Metadata();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual Exchange::IStream::streamtype Type() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::streamtype result = implementation->Type();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::streamtype>(result);
        },

        // (2) virtual Exchange::IStream::drmtype DRM() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::drmtype result = implementation->DRM();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::drmtype>(result);
        },

        // (3) virtual Exchange::IStream::IControl* Control() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IControl* result = implementation->Control();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (4) virtual void Callback(Exchange::IStream::ICallback*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_5f09baf7InstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStream::ICallback* _parameter_5f09baf7{};
            ProxyStub::UnknownProxy* _parameter_5f09baf7Proxy__ = nullptr;
            if (_parameter_5f09baf7InstanceId__ != 0) {
                _parameter_5f09baf7Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_5f09baf7InstanceId__, false, _parameter_5f09baf7);
                ASSERT((_parameter_5f09baf7 != nullptr) && (_parameter_5f09baf7Proxy__ != nullptr));
            }

            implementation->Callback(_parameter_5f09baf7);

            if (_parameter_5f09baf7Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_5f09baf7Proxy__, message->Response());
            }
        },

        // (5) virtual void Attach(Exchange::IStream::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStream::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            implementation->Attach(_callback);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (6) virtual uint32_t Detach(Exchange::IStream::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStream::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            uint32_t result = implementation->Detach(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (7) virtual Exchange::IStream::state State() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::state result = implementation->State();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::state>(result);
        },

        // (8) virtual uint32_t Load(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _configuration = reader.Text();

            uint32_t result = implementation->Load(static_cast<const string&>(_configuration));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t Error() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream* implementation = reinterpret_cast<const Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Error();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (10) virtual Exchange::IStream::IElement::IIterator* Elements() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream* implementation = reinterpret_cast<Exchange::IStream*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IElement::IIterator* result = implementation->Elements();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeStreamStubMethods

    //
    // Exchange::IStream::IElement interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream::IElement::type Type() const = 0
    //

    static ProxyStub::MethodHandler ExchangeStreamElementStubMethods[] = {
        // (0) virtual Exchange::IStream::IElement::type Type() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IElement* implementation = reinterpret_cast<const Exchange::IStream::IElement*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IElement::type result = implementation->Type();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IStream::IElement::type>(result);
        }
        , nullptr
    }; // ExchangeStreamElementStubMethods

    //
    // Exchange::IStream::IElement::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::IStream::IElement* Current() = 0
    //

    static ProxyStub::MethodHandler ExchangeStreamElementIteratorStubMethods[] = {
        // (0) virtual void Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Reset();
        },

        // (1) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<const Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual bool Next() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Next();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (3) virtual Exchange::IStream::IElement* Current() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IElement::IIterator* implementation = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IElement* result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeStreamElementIteratorStubMethods

    //
    // Exchange::IStream::IControl interface stub definitions
    //
    // Methods:
    //  (0) virtual RPC::IValueIterator* Speeds() const = 0
    //  (1) virtual void Speed(const int32_t) = 0
    //  (2) virtual int32_t Speed() const = 0
    //  (3) virtual void Position(const uint64_t) = 0
    //  (4) virtual uint64_t Position() const = 0
    //  (5) virtual void TimeRange(uint64_t&, uint64_t&) const = 0
    //  (6) virtual Exchange::IStream::IControl::IGeometry* Geometry() const = 0
    //  (7) virtual void Geometry(const Exchange::IStream::IControl::IGeometry*) = 0
    //  (8) virtual void Callback(Exchange::IStream::IControl::ICallback*) = 0
    //

    static ProxyStub::MethodHandler ExchangeStreamControlStubMethods[] = {
        // (0) virtual RPC::IValueIterator* Speeds() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::IValueIterator* result = implementation->Speeds();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (1) virtual void Speed(const int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _request = reader.Number<int32_t>();

            implementation->Speed(_request);
        },

        // (2) virtual int32_t Speed() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t result = implementation->Speed();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
        },

        // (3) virtual void Position(const uint64_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint64_t _absoluteTime = reader.Number<uint64_t>();

            implementation->Position(_absoluteTime);
        },

        // (4) virtual uint64_t Position() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t result = implementation->Position();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(result);
        },

        // (5) virtual void TimeRange(uint64_t&, uint64_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t _begin{};
            uint64_t _end{};

            implementation->TimeRange(_begin, _end);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(_begin);
            writer.Number<uint64_t>(_end);
        },

        // (6) virtual Exchange::IStream::IControl::IGeometry* Geometry() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl* implementation = reinterpret_cast<const Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStream::IControl::IGeometry* result = implementation->Geometry();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (7) virtual void Geometry(const Exchange::IStream::IControl::IGeometry*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _settingsInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IStream::IControl::IGeometry* _settings{};
            ProxyStub::UnknownProxy* _settingsProxy__ = nullptr;
            if (_settingsInstanceId__ != 0) {
                _settingsProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _settingsInstanceId__, false, _settings);
                ASSERT((_settings != nullptr) && (_settingsProxy__ != nullptr));
            }

            implementation->Geometry(_settings);

            if (_settingsProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_settingsProxy__, message->Response());
            }
        },

        // (8) virtual void Callback(Exchange::IStream::IControl::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl* implementation = reinterpret_cast<Exchange::IStream::IControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStream::IControl::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            implementation->Callback(_callback);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExchangeStreamControlStubMethods

    //
    // Exchange::IStream::IControl::IGeometry interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t X() const = 0
    //  (1) virtual uint32_t Y() const = 0
    //  (2) virtual uint32_t Z() const = 0
    //  (3) virtual uint32_t Width() const = 0
    //  (4) virtual uint32_t Height() const = 0
    //

    static ProxyStub::MethodHandler ExchangeStreamControlGeometryStubMethods[] = {
        // (0) virtual uint32_t X() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->X();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t Y() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Y();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Z() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Z();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Width() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Width();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t Height() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IStream::IControl::IGeometry* implementation = reinterpret_cast<const Exchange::IStream::IControl::IGeometry*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Height();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeStreamControlGeometryStubMethods

    //
    // Exchange::IStream::IControl::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Event(const uint32_t) = 0
    //  (1) virtual void TimeUpdate(const uint64_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeStreamControlCallbackStubMethods[] = {
        // (0) virtual void Event(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl::ICallback* implementation = reinterpret_cast<Exchange::IStream::IControl::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _eventid = reader.Number<uint32_t>();

            implementation->Event(_eventid);
        },

        // (1) virtual void TimeUpdate(const uint64_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::IControl::ICallback* implementation = reinterpret_cast<Exchange::IStream::IControl::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint64_t _position = reader.Number<uint64_t>();

            implementation->TimeUpdate(_position);
        }
        , nullptr
    }; // ExchangeStreamControlCallbackStubMethods

    //
    // Exchange::IStream::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void DRM(const uint32_t) = 0
    //  (1) virtual void StateChange(const Exchange::IStream::state) = 0
    //  (2) virtual void Event(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeStreamCallbackStubMethods[] = {
        // (0) virtual void DRM(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::ICallback* implementation = reinterpret_cast<Exchange::IStream::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _state = reader.Number<uint32_t>();

            implementation->DRM(_state);
        },

        // (1) virtual void StateChange(const Exchange::IStream::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::ICallback* implementation = reinterpret_cast<Exchange::IStream::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStream::state _newState = reader.Number<Exchange::IStream::state>();

            implementation->StateChange(_newState);
        },

        // (2) virtual void Event(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStream::ICallback* implementation = reinterpret_cast<Exchange::IStream::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _eventid = reader.Number<uint32_t>();

            implementation->Event(_eventid);
        }
        , nullptr
    }; // ExchangeStreamCallbackStubMethods

    //
    // Exchange::IPlayer interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream* CreateStream(const Exchange::IStream::streamtype) = 0
    //  (1) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //

    static ProxyStub::MethodHandler ExchangePlayerStubMethods[] = {
        // (0) virtual Exchange::IStream* CreateStream(const Exchange::IStream::streamtype) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPlayer* implementation = reinterpret_cast<Exchange::IPlayer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStream::streamtype _streamType = reader.Number<Exchange::IStream::streamtype>();

            Exchange::IStream* result = implementation->CreateStream(_streamType);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (1) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPlayer* implementation = reinterpret_cast<Exchange::IPlayer*>(message->Parameters().Implementation());
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
        }
        , nullptr
    }; // ExchangePlayerStubMethods

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
    // Exchange::IStream interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Metadata() const = 0
    //  (1) virtual Exchange::IStream::streamtype Type() const = 0
    //  (2) virtual Exchange::IStream::drmtype DRM() const = 0
    //  (3) virtual Exchange::IStream::IControl* Control() = 0
    //  (4) virtual void Callback(Exchange::IStream::ICallback*)
    //  (5) virtual void Attach(Exchange::IStream::ICallback*) = 0
    //  (6) virtual uint32_t Detach(Exchange::IStream::ICallback*) = 0
    //  (7) virtual Exchange::IStream::state State() const = 0
    //  (8) virtual uint32_t Load(const string&) = 0
    //  (9) virtual uint32_t Error() const = 0
    //  (10) virtual Exchange::IStream::IElement::IIterator* Elements() = 0
    //

    class ExchangeStreamProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream> {
    public:
        ExchangeStreamProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string Metadata() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

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

        Exchange::IStream::streamtype Type() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Exchange::IStream::streamtype result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IStream::streamtype>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IStream::drmtype DRM() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Exchange::IStream::drmtype result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IStream::drmtype>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IStream::IControl* Control() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Exchange::IStream::IControl* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IStream::IControl*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IControl::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Callback(Exchange::IStream::ICallback* _parameter_5f09baf7) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_5f09baf7));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Attach(Exchange::IStream::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Detach(Exchange::IStream::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

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

        Exchange::IStream::state State() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Exchange::IStream::state result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IStream::state>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Load(const string& _configuration) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_configuration);

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

        uint32_t Error() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

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

        Exchange::IStream::IElement::IIterator* Elements() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            Exchange::IStream::IElement::IIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IStream::IElement::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IElement::IIterator::ID));
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

    }; // class ExchangeStreamProxy

    //
    // Exchange::IStream::IElement interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream::IElement::type Type() const = 0
    //

    class ExchangeStreamElementProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IElement> {
    public:
        ExchangeStreamElementProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Exchange::IStream::IElement::type Type() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Exchange::IStream::IElement::type result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IStream::IElement::type>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeStreamElementProxy

    //
    // Exchange::IStream::IElement::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Reset() = 0
    //  (1) virtual bool IsValid() const = 0
    //  (2) virtual bool Next() = 0
    //  (3) virtual Exchange::IStream::IElement* Current() = 0
    //

    class ExchangeStreamElementIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IElement::IIterator> {
    public:
        ExchangeStreamElementIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Reset() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        bool Next() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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

        Exchange::IStream::IElement* Current() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Exchange::IStream::IElement* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IStream::IElement*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IElement::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeStreamElementIteratorProxy

    //
    // Exchange::IStream::IControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual RPC::IValueIterator* Speeds() const = 0
    //  (1) virtual void Speed(const int32_t) = 0
    //  (2) virtual int32_t Speed() const = 0
    //  (3) virtual void Position(const uint64_t) = 0
    //  (4) virtual uint64_t Position() const = 0
    //  (5) virtual void TimeRange(uint64_t&, uint64_t&) const = 0
    //  (6) virtual Exchange::IStream::IControl::IGeometry* Geometry() const = 0
    //  (7) virtual void Geometry(const Exchange::IStream::IControl::IGeometry*) = 0
    //  (8) virtual void Callback(Exchange::IStream::IControl::ICallback*) = 0
    //

    class ExchangeStreamControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IControl> {
    public:
        ExchangeStreamControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        RPC::IValueIterator* Speeds() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::IValueIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<RPC::IValueIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), RPC::IValueIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Speed(const int32_t _request) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_request);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        int32_t Speed() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            int32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<int32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Position(const uint64_t _absoluteTime) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint64_t>(_absoluteTime);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        uint64_t Position() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint64_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint64_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void TimeRange(uint64_t& _begin, uint64_t& _end) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                _begin = reader.Number<uint64_t>();
                _end = reader.Number<uint64_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        Exchange::IStream::IControl::IGeometry* Geometry() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Exchange::IStream::IControl::IGeometry* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IStream::IControl::IGeometry*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStream::IControl::IGeometry::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Geometry(const Exchange::IStream::IControl::IGeometry* _settings) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_settings));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Callback(Exchange::IStream::IControl::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
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

    }; // class ExchangeStreamControlProxy

    //
    // Exchange::IStream::IControl::IGeometry interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t X() const = 0
    //  (1) virtual uint32_t Y() const = 0
    //  (2) virtual uint32_t Z() const = 0
    //  (3) virtual uint32_t Width() const = 0
    //  (4) virtual uint32_t Height() const = 0
    //

    class ExchangeStreamControlGeometryProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IControl::IGeometry> {
    public:
        ExchangeStreamControlGeometryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t X() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

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

        uint32_t Y() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        uint32_t Z() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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

        uint32_t Width() const override
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

        uint32_t Height() const override
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

    }; // class ExchangeStreamControlGeometryProxy

    //
    // Exchange::IStream::IControl::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Event(const uint32_t) = 0
    //  (1) virtual void TimeUpdate(const uint64_t) = 0
    //

    class ExchangeStreamControlCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::IControl::ICallback> {
    public:
        ExchangeStreamControlCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Event(const uint32_t _eventid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_eventid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void TimeUpdate(const uint64_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint64_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeStreamControlCallbackProxy

    //
    // Exchange::IStream::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void DRM(const uint32_t) = 0
    //  (1) virtual void StateChange(const Exchange::IStream::state) = 0
    //  (2) virtual void Event(const uint32_t) = 0
    //

    class ExchangeStreamCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IStream::ICallback> {
    public:
        ExchangeStreamCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void DRM(const uint32_t _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void StateChange(const Exchange::IStream::state _newState) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStream::state>(_newState);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Event(const uint32_t _eventid) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_eventid);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeStreamCallbackProxy

    //
    // Exchange::IPlayer interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IStream* CreateStream(const Exchange::IStream::streamtype) = 0
    //  (1) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //

    class ExchangePlayerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPlayer> {
    public:
        ExchangePlayerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Exchange::IStream* CreateStream(const Exchange::IStream::streamtype _streamType) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStream::streamtype>(_streamType);

            Exchange::IStream* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<Exchange::IStream*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStream::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Configure(PluginHost::IShell* _service) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

    }; // class ExchangePlayerProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_bd6e04b8d151c1f7StubMethods> RPCIteratorTypeInstance_bd6e04b8d151c1f7Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>, RPCIteratorTypeInstance_60eba5a793c685eaStubMethods> RPCIteratorTypeInstance_60eba5a793c685eaStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>, RPCIteratorTypeInstance_195e88cf7f955a2eStubMethods> RPCIteratorTypeInstance_195e88cf7f955a2eStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream, ExchangeStreamStubMethods> ExchangeStreamStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IElement, ExchangeStreamElementStubMethods> ExchangeStreamElementStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IElement::IIterator, ExchangeStreamElementIteratorStubMethods> ExchangeStreamElementIteratorStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IControl, ExchangeStreamControlStubMethods> ExchangeStreamControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IControl::IGeometry, ExchangeStreamControlGeometryStubMethods> ExchangeStreamControlGeometryStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::IControl::ICallback, ExchangeStreamControlCallbackStubMethods> ExchangeStreamControlCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStream::ICallback, ExchangeStreamCallbackStubMethods> ExchangeStreamCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPlayer, ExchangePlayerStubMethods> ExchangePlayerStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_bd6e04b8d151c1f7Proxy, RPCIteratorTypeInstance_bd6e04b8d151c1f7Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>, RPCIteratorTypeInstance_60eba5a793c685eaProxy, RPCIteratorTypeInstance_60eba5a793c685eaStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>, RPCIteratorTypeInstance_195e88cf7f955a2eProxy, RPCIteratorTypeInstance_195e88cf7f955a2eStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream, ExchangeStreamProxy, ExchangeStreamStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IElement, ExchangeStreamElementProxy, ExchangeStreamElementStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IElement::IIterator, ExchangeStreamElementIteratorProxy, ExchangeStreamElementIteratorStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IControl, ExchangeStreamControlProxy, ExchangeStreamControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IControl::IGeometry, ExchangeStreamControlGeometryProxy, ExchangeStreamControlGeometryStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::IControl::ICallback, ExchangeStreamControlCallbackProxy, ExchangeStreamControlCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStream::ICallback, ExchangeStreamCallbackProxy, ExchangeStreamCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPlayer, ExchangePlayerProxy, ExchangePlayerStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<uint32_t, RPC::ID_VALUEITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<RPC::Environment, RPC::ID_ENVIRONMENTITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IStream>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IElement>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IElement::IIterator>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IControl>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IControl::IGeometry>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::IControl::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::IStream::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::IPlayer>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
