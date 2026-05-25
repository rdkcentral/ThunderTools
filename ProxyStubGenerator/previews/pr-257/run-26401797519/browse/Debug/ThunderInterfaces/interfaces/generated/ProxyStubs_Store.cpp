//
// generated automatically from "IStore.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IStore
//   - class Exchange::IStore::INotification
//

#include "Module.h"
#include "IStore.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IStore interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IStore::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IStore::INotification*) = 0
    //  (2) virtual uint32_t SetValue(const string&, const string&, const string&) = 0
    //  (3) virtual uint32_t GetValue(const string&, const string&, string&) = 0
    //  (4) virtual uint32_t DeleteKey(const string&, const string&) = 0
    //  (5) virtual uint32_t DeleteNamespace(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeStoreStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IStore::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore* implementation = reinterpret_cast<Exchange::IStore*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStore::INotification* _notification{};
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

        // (1) virtual uint32_t Unregister(Exchange::IStore::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore* implementation = reinterpret_cast<Exchange::IStore*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IStore::INotification* _notification{};
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

        // (2) virtual uint32_t SetValue(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore* implementation = reinterpret_cast<Exchange::IStore*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ns = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();

            uint32_t result = implementation->SetValue(static_cast<const string&>(_ns), static_cast<const string&>(_key), static_cast<const string&>(_value));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t GetValue(const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore* implementation = reinterpret_cast<Exchange::IStore*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ns = reader.Text();
            const string _key = reader.Text();

            string _value{};

            uint32_t result = implementation->GetValue(static_cast<const string&>(_ns), static_cast<const string&>(_key), _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        },

        // (4) virtual uint32_t DeleteKey(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore* implementation = reinterpret_cast<Exchange::IStore*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ns = reader.Text();
            const string _key = reader.Text();

            uint32_t result = implementation->DeleteKey(static_cast<const string&>(_ns), static_cast<const string&>(_key));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t DeleteNamespace(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore* implementation = reinterpret_cast<Exchange::IStore*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ns = reader.Text();

            uint32_t result = implementation->DeleteNamespace(static_cast<const string&>(_ns));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeStoreStubMethods

    //
    // Exchange::IStore::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void ValueChanged(const string&, const string&, const string&) = 0
    //  (1) virtual void StorageExceeded() = 0
    //

    static ProxyStub::MethodHandler ExchangeStoreNotificationStubMethods[] = {
        // (0) virtual void ValueChanged(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore::INotification* implementation = reinterpret_cast<Exchange::IStore::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _ns = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();

            implementation->ValueChanged(static_cast<const string&>(_ns), static_cast<const string&>(_key), static_cast<const string&>(_value));
        },

        // (1) virtual void StorageExceeded() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IStore::INotification* implementation = reinterpret_cast<Exchange::IStore::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->StorageExceeded();
        }
        , nullptr
    }; // ExchangeStoreNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IStore interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IStore::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IStore::INotification*) = 0
    //  (2) virtual uint32_t SetValue(const string&, const string&, const string&) = 0
    //  (3) virtual uint32_t GetValue(const string&, const string&, string&) = 0
    //  (4) virtual uint32_t DeleteKey(const string&, const string&) = 0
    //  (5) virtual uint32_t DeleteNamespace(const string&) = 0
    //

    class ExchangeStoreProxy final : public ProxyStub::UnknownProxyType<Exchange::IStore> {
    public:
        ExchangeStoreProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::IStore::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

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

        uint32_t Unregister(Exchange::IStore::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

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

        uint32_t SetValue(const string& _ns, const string& _key, const string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ns);
            writer.Text(_key);
            writer.Text(_value);

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

        uint32_t GetValue(const string& _ns, const string& _key, string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ns);
            writer.Text(_key);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _value = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t DeleteKey(const string& _ns, const string& _key) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ns);
            writer.Text(_key);

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

        uint32_t DeleteNamespace(const string& _ns) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ns);

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

    }; // class ExchangeStoreProxy

    //
    // Exchange::IStore::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void ValueChanged(const string&, const string&, const string&) = 0
    //  (1) virtual void StorageExceeded() = 0
    //

    class ExchangeStoreNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IStore::INotification> {
    public:
        ExchangeStoreNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void ValueChanged(const string& _ns, const string& _key, const string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_ns);
            writer.Text(_key);
            writer.Text(_value);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void StorageExceeded() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeStoreNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IStore, ExchangeStoreStubMethods> ExchangeStoreStub;
        typedef ProxyStub::UnknownStubType<Exchange::IStore::INotification, ExchangeStoreNotificationStubMethods> ExchangeStoreNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IStore, ExchangeStoreProxy, ExchangeStoreStub>();
                RPC::Administrator::Instance().Announce<Exchange::IStore::INotification, ExchangeStoreNotificationProxy, ExchangeStoreNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IStore>();
                RPC::Administrator::Instance().Recall<Exchange::IStore::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
