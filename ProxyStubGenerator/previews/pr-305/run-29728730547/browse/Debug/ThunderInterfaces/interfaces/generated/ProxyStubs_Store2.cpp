//
// generated automatically from "IStore2.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IStoreInspector::NamespaceSize, INTERFACE_ID = Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR] [[iterator]]
//   - class Exchange::IStore2
//   - class Exchange::IStore2::INotification
//   - class Exchange::IStoreInspector
//   - class Exchange::IStoreLimit
//

#include "Module.h"
#include "IStore2.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_b3acff3685df4032StubMethods[] = {
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
    }; // RPCIteratorTypeInstance_b3acff3685df4032StubMethods

    //
    // RPC::IIteratorTypeInstance_77510a160bee9699 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IStoreInspector::NamespaceSize&) = 0
    //  (1) virtual bool Previous(Exchange::IStoreInspector::NamespaceSize&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IStoreInspector::NamespaceSize Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_77510a160bee9699StubMethods[] = {
        // (0) virtual bool Next(Exchange::IStoreInspector::NamespaceSize&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStoreInspector::NamespaceSize _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.ns);
            writer.Number<uint32_t>(_info.size);
        },

        // (1) virtual bool Previous(Exchange::IStoreInspector::NamespaceSize&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStoreInspector::NamespaceSize _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.ns);
            writer.Number<uint32_t>(_info.size);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IStoreInspector::NamespaceSize Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IStoreInspector::NamespaceSize result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result.ns);
            writer.Number<uint32_t>(result.size);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_77510a160bee9699StubMethods

    //
    // Exchange::IStore2 interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IStore2::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IStore2::INotification*) = 0
    //  (2) virtual uint32_t SetValue(const Exchange::IStore2::ScopeType, const string&, const string&, const string&, const uint32_t) = 0
    //  (3) virtual uint32_t GetValue(const Exchange::IStore2::ScopeType, const string&, const string&, string&, uint32_t&) = 0
    //  (4) virtual uint32_t DeleteKey(const Exchange::IStore2::ScopeType, const string&, const string&) = 0
    //  (5) virtual uint32_t DeleteNamespace(const Exchange::IStore2::ScopeType, const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeStore2StubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IStore2::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore2* implementation = reinterpret_cast<Exchange::IStore2*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStore2::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            uint32_t result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::IStore2::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore2* implementation = reinterpret_cast<Exchange::IStore2*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStore2::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            uint32_t result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t SetValue(const Exchange::IStore2::ScopeType, const string&, const string&, const string&, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore2* implementation = reinterpret_cast<Exchange::IStore2*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStore2::ScopeType _scope = reader.Number<Exchange::IStore2::ScopeType>();
            const string _ns = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();
            const uint32_t _ttl = reader.Number<uint32_t>();

            uint32_t result = implementation->SetValue(_scope, static_cast<const string&>(_ns), static_cast<const string&>(_key), static_cast<const string&>(_value), _ttl);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t GetValue(const Exchange::IStore2::ScopeType, const string&, const string&, string&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore2* implementation = reinterpret_cast<Exchange::IStore2*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStore2::ScopeType _scope = reader.Number<Exchange::IStore2::ScopeType>();
            const string _ns = reader.Text();
            const string _key = reader.Text();

            string _value{};
            uint32_t _ttl{};

            uint32_t result = implementation->GetValue(_scope, static_cast<const string&>(_ns), static_cast<const string&>(_key), _value, _ttl);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
            writer.Number<uint32_t>(_ttl);
        },

        // (4) virtual uint32_t DeleteKey(const Exchange::IStore2::ScopeType, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore2* implementation = reinterpret_cast<Exchange::IStore2*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStore2::ScopeType _scope = reader.Number<Exchange::IStore2::ScopeType>();
            const string _ns = reader.Text();
            const string _key = reader.Text();

            uint32_t result = implementation->DeleteKey(_scope, static_cast<const string&>(_ns), static_cast<const string&>(_key));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t DeleteNamespace(const Exchange::IStore2::ScopeType, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore2* implementation = reinterpret_cast<Exchange::IStore2*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStore2::ScopeType _scope = reader.Number<Exchange::IStore2::ScopeType>();
            const string _ns = reader.Text();

            uint32_t result = implementation->DeleteNamespace(_scope, static_cast<const string&>(_ns));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeStore2StubMethods

    //
    // Exchange::IStore2::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void ValueChanged(const Exchange::IStore2::ScopeType, const string&, const string&, const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeStore2NotificationStubMethods[] = {
        // (0) virtual void ValueChanged(const Exchange::IStore2::ScopeType, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore2::INotification* implementation = reinterpret_cast<Exchange::IStore2::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStore2::ScopeType _scope = reader.Number<Exchange::IStore2::ScopeType>();
            const string _ns = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();

            implementation->ValueChanged(_scope, static_cast<const string&>(_ns), static_cast<const string&>(_key), static_cast<const string&>(_value));
        }
        , nullptr
    }; // ExchangeStore2NotificationStubMethods

    //
    // Exchange::IStoreInspector interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t GetKeys(const Exchange::IStoreInspector::ScopeType, const string&, Exchange::IStoreInspector::IStringIterator*&) = 0
    //  (1) virtual uint32_t GetNamespaces(const Exchange::IStoreInspector::ScopeType, Exchange::IStoreInspector::IStringIterator*&) = 0
    //  (2) virtual uint32_t GetStorageSizes(const Exchange::IStoreInspector::ScopeType, Exchange::IStoreInspector::INamespaceSizeIterator*&) = 0
    //

    static ProxyStub::MethodHandler ExchangeStoreInspectorStubMethods[] = {
        // (0) virtual uint32_t GetKeys(const Exchange::IStoreInspector::ScopeType, const string&, Exchange::IStoreInspector::IStringIterator*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStoreInspector* implementation = reinterpret_cast<Exchange::IStoreInspector*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStoreInspector::ScopeType _scope = reader.Number<Exchange::IStoreInspector::ScopeType>();
            const string _ns = reader.Text();

            Exchange::IStoreInspector::IStringIterator* _keys{};

            uint32_t result = implementation->GetKeys(_scope, static_cast<const string&>(_ns), _keys);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_keys));

            RPC::Administrator::Instance().RegisterInterface(channel, _keys);
        },

        // (1) virtual uint32_t GetNamespaces(const Exchange::IStoreInspector::ScopeType, Exchange::IStoreInspector::IStringIterator*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStoreInspector* implementation = reinterpret_cast<Exchange::IStoreInspector*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStoreInspector::ScopeType _scope = reader.Number<Exchange::IStoreInspector::ScopeType>();

            Exchange::IStoreInspector::IStringIterator* _namespaces{};

            uint32_t result = implementation->GetNamespaces(_scope, _namespaces);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_namespaces));

            RPC::Administrator::Instance().RegisterInterface(channel, _namespaces);
        },

        // (2) virtual uint32_t GetStorageSizes(const Exchange::IStoreInspector::ScopeType, Exchange::IStoreInspector::INamespaceSizeIterator*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStoreInspector* implementation = reinterpret_cast<Exchange::IStoreInspector*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStoreInspector::ScopeType _scope = reader.Number<Exchange::IStoreInspector::ScopeType>();

            Exchange::IStoreInspector::INamespaceSizeIterator* _storageList{};

            uint32_t result = implementation->GetStorageSizes(_scope, _storageList);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_storageList));

            RPC::Administrator::Instance().RegisterInterface(channel, _storageList);
        }
        , nullptr
    }; // ExchangeStoreInspectorStubMethods

    //
    // Exchange::IStoreLimit interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t SetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType, const string&, const uint32_t) = 0
    //  (1) virtual uint32_t GetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType, const string&, uint32_t&) = 0
    //

    static ProxyStub::MethodHandler ExchangeStoreLimitStubMethods[] = {
        // (0) virtual uint32_t SetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType, const string&, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStoreLimit* implementation = reinterpret_cast<Exchange::IStoreLimit*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStoreLimit::ScopeType _scope = reader.Number<Exchange::IStoreLimit::ScopeType>();
            const string _ns = reader.Text();
            const uint32_t _size = reader.Number<uint32_t>();

            uint32_t result = implementation->SetNamespaceStorageLimit(_scope, static_cast<const string&>(_ns), _size);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t GetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType, const string&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStoreLimit* implementation = reinterpret_cast<Exchange::IStoreLimit*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IStoreLimit::ScopeType _scope = reader.Number<Exchange::IStoreLimit::ScopeType>();
            const string _ns = reader.Text();

            uint32_t _size{};

            uint32_t result = implementation->GetNamespaceStorageLimit(_scope, static_cast<const string&>(_ns), _size);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_size);
        }
        , nullptr
    }; // ExchangeStoreLimitStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_b3acff3685df4032Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_b3acff3685df4032Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstance_b3acff3685df4032Proxy

    //
    // RPC::IIteratorTypeInstance_77510a160bee9699 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IStoreInspector::NamespaceSize&) = 0
    //  (1) virtual bool Previous(Exchange::IStoreInspector::NamespaceSize&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IStoreInspector::NamespaceSize Current() const = 0
    //

    class RPCIteratorTypeInstance_77510a160bee9699Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_77510a160bee9699Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IStoreInspector::NamespaceSize& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.ns = reader.Text();
                _info.size = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IStoreInspector::NamespaceSize& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.ns = reader.Text();
                _info.size = reader.Number<uint32_t>();
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

        Exchange::IStoreInspector::NamespaceSize Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Exchange::IStoreInspector::NamespaceSize result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result.ns = reader.Text();
                result.size = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_77510a160bee9699Proxy

    //
    // Exchange::IStore2 interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IStore2::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IStore2::INotification*) = 0
    //  (2) virtual uint32_t SetValue(const Exchange::IStore2::ScopeType, const string&, const string&, const string&, const uint32_t) = 0
    //  (3) virtual uint32_t GetValue(const Exchange::IStore2::ScopeType, const string&, const string&, string&, uint32_t&) = 0
    //  (4) virtual uint32_t DeleteKey(const Exchange::IStore2::ScopeType, const string&, const string&) = 0
    //  (5) virtual uint32_t DeleteNamespace(const Exchange::IStore2::ScopeType, const string&) = 0
    //

    class ExchangeStore2Proxy final : public ProxyStub::UnknownProxyType<Exchange::IStore2> {
    public:
        ExchangeStore2Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::IStore2::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Unregister(Exchange::IStore2::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t SetValue(const Exchange::IStore2::ScopeType _scope, const string& _ns, const string& _key, const string& _value, const uint32_t _ttl) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStore2::ScopeType>(_scope);
            writer.Text(_ns);
            writer.Text(_key);
            writer.Text(_value);
            writer.Number<uint32_t>(_ttl);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t GetValue(const Exchange::IStore2::ScopeType _scope, const string& _ns, const string& _key, string& _value, uint32_t& _ttl) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStore2::ScopeType>(_scope);
            writer.Text(_ns);
            writer.Text(_key);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _value = reader.Text();
                _ttl = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t DeleteKey(const Exchange::IStore2::ScopeType _scope, const string& _ns, const string& _key) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStore2::ScopeType>(_scope);
            writer.Text(_ns);
            writer.Text(_key);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t DeleteNamespace(const Exchange::IStore2::ScopeType _scope, const string& _ns) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStore2::ScopeType>(_scope);
            writer.Text(_ns);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
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

    }; // class ExchangeStore2Proxy

    //
    // Exchange::IStore2::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void ValueChanged(const Exchange::IStore2::ScopeType, const string&, const string&, const string&) = 0
    //

    class ExchangeStore2NotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IStore2::INotification> {
    public:
        ExchangeStore2NotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void ValueChanged(const Exchange::IStore2::ScopeType _scope, const string& _ns, const string& _key, const string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStore2::ScopeType>(_scope);
            writer.Text(_ns);
            writer.Text(_key);
            writer.Text(_value);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeStore2NotificationProxy

    //
    // Exchange::IStoreInspector interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t GetKeys(const Exchange::IStoreInspector::ScopeType, const string&, Exchange::IStoreInspector::IStringIterator*&) = 0
    //  (1) virtual uint32_t GetNamespaces(const Exchange::IStoreInspector::ScopeType, Exchange::IStoreInspector::IStringIterator*&) = 0
    //  (2) virtual uint32_t GetStorageSizes(const Exchange::IStoreInspector::ScopeType, Exchange::IStoreInspector::INamespaceSizeIterator*&) = 0
    //

    class ExchangeStoreInspectorProxy final : public ProxyStub::UnknownProxyType<Exchange::IStoreInspector> {
    public:
        ExchangeStoreInspectorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t GetKeys(const Exchange::IStoreInspector::ScopeType _scope, const string& _ns, Exchange::IStoreInspector::IStringIterator*& _keys) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStoreInspector::ScopeType>(_scope);
            writer.Text(_ns);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _keys = reinterpret_cast<Exchange::IStoreInspector::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStoreInspector::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t GetNamespaces(const Exchange::IStoreInspector::ScopeType _scope, Exchange::IStoreInspector::IStringIterator*& _namespaces) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStoreInspector::ScopeType>(_scope);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _namespaces = reinterpret_cast<Exchange::IStoreInspector::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStoreInspector::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t GetStorageSizes(const Exchange::IStoreInspector::ScopeType _scope, Exchange::IStoreInspector::INamespaceSizeIterator*& _storageList) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStoreInspector::ScopeType>(_scope);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _storageList = reinterpret_cast<Exchange::IStoreInspector::INamespaceSizeIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IStoreInspector::INamespaceSizeIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeStoreInspectorProxy

    //
    // Exchange::IStoreLimit interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t SetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType, const string&, const uint32_t) = 0
    //  (1) virtual uint32_t GetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType, const string&, uint32_t&) = 0
    //

    class ExchangeStoreLimitProxy final : public ProxyStub::UnknownProxyType<Exchange::IStoreLimit> {
    public:
        ExchangeStoreLimitProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t SetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType _scope, const string& _ns, const uint32_t _size) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStoreLimit::ScopeType>(_scope);
            writer.Text(_ns);
            writer.Number<uint32_t>(_size);

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

        uint32_t GetNamespaceStorageLimit(const Exchange::IStoreLimit::ScopeType _scope, const string& _ns, uint32_t& _size) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IStoreLimit::ScopeType>(_scope);
            writer.Text(_ns);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _size = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeStoreLimitProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>, RPCIteratorTypeInstance_77510a160bee9699StubMethods> RPCIteratorTypeInstance_77510a160bee9699Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IStore2, ExchangeStore2StubMethods> ExchangeStore2Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IStore2::INotification, ExchangeStore2NotificationStubMethods> ExchangeStore2NotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStoreInspector, ExchangeStoreInspectorStubMethods> ExchangeStoreInspectorStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStoreLimit, ExchangeStoreLimitStubMethods> ExchangeStoreLimitStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>, RPCIteratorTypeInstance_77510a160bee9699Proxy, RPCIteratorTypeInstance_77510a160bee9699Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IStore2, ExchangeStore2Proxy, ExchangeStore2Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IStore2::INotification, ExchangeStore2NotificationProxy, ExchangeStore2NotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStoreInspector, ExchangeStoreInspectorProxy, ExchangeStoreInspectorStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStoreLimit, ExchangeStoreLimitProxy, ExchangeStoreLimitStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IStoreInspector::NamespaceSize, Exchange::ID_STORE_INSPECTOR_NAMESPACE_SIZE_ITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IStore2>();
                RPC::Administrator::Instance().Recall<Exchange::IStore2::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IStoreInspector>();
                RPC::Administrator::Instance().Recall<Exchange::IStoreLimit>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
