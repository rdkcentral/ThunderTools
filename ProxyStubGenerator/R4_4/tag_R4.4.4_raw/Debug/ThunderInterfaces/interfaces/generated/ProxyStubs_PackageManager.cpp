//
// generated automatically from "IPackageManager.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IPackageManager::KeyValue, INTERFACE_ID = Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR]
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = Exchange::IPackageManager::PackageKey, INTERFACE_ID = Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR]
//   - class Exchange::IPackageManager
//   - class Exchange::IPackageManager::INotification
//   - class Exchange::IPackageManagerBroker
//   - class Exchange::IPackageManagerCallback
//

#include "Module.h"
#include "IPackageManager.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstanceF3A0ECC7 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstanceF3A0ECC7StubMethods[] = {
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
    }; // RPCIteratorTypeInstanceF3A0ECC7StubMethods

    //
    // RPC::IIteratorTypeInstance313F165B interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPackageManager::KeyValue&) = 0
    //  (1) virtual bool Previous(Exchange::IPackageManager::KeyValue&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPackageManager::KeyValue Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance313F165BStubMethods[] = {
        // (0) virtual bool Next(Exchange::IPackageManager::KeyValue&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPackageManager::KeyValue _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.key);
            writer.Text(_info.value);
        },

        // (1) virtual bool Previous(Exchange::IPackageManager::KeyValue&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPackageManager::KeyValue _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.key);
            writer.Text(_info.value);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IPackageManager::KeyValue Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPackageManager::KeyValue result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result.key);
            writer.Text(result.value);
        }
        , nullptr
    }; // RPCIteratorTypeInstance313F165BStubMethods

    //
    // RPC::IIteratorTypeInstance46356EDF interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPackageManager::PackageKey&) = 0
    //  (1) virtual bool Previous(Exchange::IPackageManager::PackageKey&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPackageManager::PackageKey Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance46356EDFStubMethods[] = {
        // (0) virtual bool Next(Exchange::IPackageManager::PackageKey&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPackageManager::PackageKey _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.id);
            writer.Text(_info.version);
        },

        // (1) virtual bool Previous(Exchange::IPackageManager::PackageKey&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPackageManager::PackageKey _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info.id);
            writer.Text(_info.version);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IPackageManager::PackageKey Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPackageManager::PackageKey result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result.id);
            writer.Text(result.version);
        }
        , nullptr
    }; // RPCIteratorTypeInstance46356EDFStubMethods

    //
    // Exchange::IPackageManager interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Install(const string&, const string&, const string&, const string&, const string&, const string&, string&) = 0
    //  (1) virtual uint32_t Uninstall(const string&, const string&, const string&, const string&, string&) = 0
    //  (2) virtual uint32_t Download(const string&, const string&, const string&, const string&, const string&, string&) = 0
    //  (3) virtual uint32_t Reset(const string&, const string&, const string&, const string&) = 0
    //  (4) virtual uint32_t GetStorageDetails(const string&, const string&, const string&, Exchange::IPackageManager::StorageInfo&) const = 0
    //  (5) virtual uint32_t SetAuxMetadata(const string&, const string&, const string&, const string&, const string&) = 0
    //  (6) virtual uint32_t ClearAuxMetadata(const string&, const string&, const string&, const string&) = 0
    //  (7) virtual uint32_t GetMetadata(const string&, const string&, const string&, Exchange::IPackageManager::MetadataPayload&, Exchange::IPackageManager::IKeyValueIterator*&, Exchange::IPackageManager::IKeyValueIterator*&) const = 0
    //  (8) virtual uint32_t Cancel(const string&) = 0
    //  (9) virtual uint32_t GetProgress(const string&, uint32_t&) const = 0
    //  (10) virtual uint32_t Register(Exchange::IPackageManager::INotification*) = 0
    //  (11) virtual uint32_t Unregister(Exchange::IPackageManager::INotification*) = 0
    //  (12) virtual uint32_t GetList(const string&, const string&, const string&, const string&, const string&, Exchange::IPackageManager::IPackageKeyIterator*&) const = 0
    //  (13) virtual uint32_t Lock(const string&, const string&, const string&, const string&, const string&, string&) = 0
    //  (14) virtual uint32_t Unlock(const string&) = 0
    //  (15) virtual uint32_t GetLockInfo(const string&, const string&, const string&, Exchange::IPackageManager::LockInfo&) const = 0
    //

    ProxyStub::MethodHandler ExchangePackageManagerStubMethods[] = {
        // (0) virtual uint32_t Install(const string&, const string&, const string&, const string&, const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _url = reader.Text();
            const string _appName = reader.Text();
            const string _category = reader.Text();

            string _handle{};

            uint32_t result = implementation->Install(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_url), static_cast<const string&>(_appName), static_cast<const string&>(_category), _handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        },

        // (1) virtual uint32_t Uninstall(const string&, const string&, const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _uninstallType = reader.Text();

            string _handle{};

            uint32_t result = implementation->Uninstall(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_uninstallType), _handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        },

        // (2) virtual uint32_t Download(const string&, const string&, const string&, const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _resKey = reader.Text();
            const string _url = reader.Text();

            string _handle{};

            uint32_t result = implementation->Download(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_resKey), static_cast<const string&>(_url), _handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        },

        // (3) virtual uint32_t Reset(const string&, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _resetType = reader.Text();

            uint32_t result = implementation->Reset(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_resetType));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t GetStorageDetails(const string&, const string&, const string&, Exchange::IPackageManager::StorageInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackageManager* implementation = reinterpret_cast<const Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();

            Exchange::IPackageManager::StorageInfo _storageinfo{};

            uint32_t result = implementation->GetStorageDetails(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), _storageinfo);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_storageinfo.apps.path);
            writer.Text(_storageinfo.apps.quotaKB);
            writer.Text(_storageinfo.apps.usedKB);
            writer.Text(_storageinfo.persistent.path);
            writer.Text(_storageinfo.persistent.quotaKB);
            writer.Text(_storageinfo.persistent.usedKB);
        },

        // (5) virtual uint32_t SetAuxMetadata(const string&, const string&, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();

            uint32_t result = implementation->SetAuxMetadata(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_key), static_cast<const string&>(_value));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t ClearAuxMetadata(const string&, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _key = reader.Text();

            uint32_t result = implementation->ClearAuxMetadata(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_key));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t GetMetadata(const string&, const string&, const string&, Exchange::IPackageManager::MetadataPayload&, Exchange::IPackageManager::IKeyValueIterator*&, Exchange::IPackageManager::IKeyValueIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackageManager* implementation = reinterpret_cast<const Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();

            Exchange::IPackageManager::MetadataPayload _metadata{};
            Exchange::IPackageManager::IKeyValueIterator* _resources{};
            Exchange::IPackageManager::IKeyValueIterator* _auxMetadata{};

            uint32_t result = implementation->GetMetadata(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), _metadata, _resources, _auxMetadata);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_metadata.appName);
            writer.Text(_metadata.type);
            writer.Text(_metadata.category);
            writer.Text(_metadata.url);
            writer.Number<Core::instance_id>(RPC::instance_cast(_resources));
            writer.Number<Core::instance_id>(RPC::instance_cast(_auxMetadata));

            RPC::Administrator::Instance().RegisterInterface(channel, _resources);
            RPC::Administrator::Instance().RegisterInterface(channel, _auxMetadata);
        },

        // (8) virtual uint32_t Cancel(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _handle = reader.Text();

            uint32_t result = implementation->Cancel(static_cast<const string&>(_handle));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t GetProgress(const string&, uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackageManager* implementation = reinterpret_cast<const Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _handle = reader.Text();

            uint32_t _progress{};

            uint32_t result = implementation->GetProgress(static_cast<const string&>(_handle), _progress);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_progress);
        },

        // (10) virtual uint32_t Register(Exchange::IPackageManager::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IPackageManager::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            uint32_t result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (11) virtual uint32_t Unregister(Exchange::IPackageManager::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IPackageManager::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            uint32_t result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (12) virtual uint32_t GetList(const string&, const string&, const string&, const string&, const string&, Exchange::IPackageManager::IPackageKeyIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackageManager* implementation = reinterpret_cast<const Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _appName = reader.Text();
            const string _category = reader.Text();

            Exchange::IPackageManager::IPackageKeyIterator* _installedIds{};

            uint32_t result = implementation->GetList(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_appName), static_cast<const string&>(_category), _installedIds);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_installedIds));

            RPC::Administrator::Instance().RegisterInterface(channel, _installedIds);
        },

        // (13) virtual uint32_t Lock(const string&, const string&, const string&, const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _reason = reader.Text();
            const string _owner = reader.Text();

            string _handle{};

            uint32_t result = implementation->Lock(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_reason), static_cast<const string&>(_owner), _handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        },

        // (14) virtual uint32_t Unlock(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager* implementation = reinterpret_cast<Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _handle = reader.Text();

            uint32_t result = implementation->Unlock(static_cast<const string&>(_handle));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (15) virtual uint32_t GetLockInfo(const string&, const string&, const string&, Exchange::IPackageManager::LockInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackageManager* implementation = reinterpret_cast<const Exchange::IPackageManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();

            Exchange::IPackageManager::LockInfo _result{};

            uint32_t result = implementation->GetLockInfo(static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_result.reason);
            writer.Text(_result.owner);
        }
        , nullptr
    }; // ExchangePackageManagerStubMethods

    //
    // Exchange::IPackageManager::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void OperationStatus(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangePackageManagerNotificationStubMethods[] = {
        // (0) virtual void OperationStatus(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManager::INotification* implementation = reinterpret_cast<Exchange::IPackageManager::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _handle = reader.Text();
            const string _operation = reader.Text();
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _status = reader.Text();
            const string _details = reader.Text();

            implementation->OperationStatus(static_cast<const string&>(_handle), static_cast<const string&>(_operation), static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_status), static_cast<const string&>(_details));
        }
        , nullptr
    }; // ExchangePackageManagerNotificationStubMethods

    //
    // Exchange::IPackageManagerBroker interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Offer(Exchange::IPackageManager*) = 0
    //  (1) virtual uint32_t Revoke(const Exchange::IPackageManager*) = 0
    //

    ProxyStub::MethodHandler ExchangePackageManagerBrokerStubMethods[] = {
        // (0) virtual uint32_t Offer(Exchange::IPackageManager*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManagerBroker* implementation = reinterpret_cast<Exchange::IPackageManagerBroker*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id packagemanagerImplementation = reader.Number<Core::instance_id>();

            Exchange::IPackageManager* _packagemanager = nullptr;
            ProxyStub::UnknownProxy* packagemanagerProxy = nullptr;
            if (packagemanagerImplementation != 0) {
                packagemanagerProxy = RPC::Administrator::Instance().ProxyInstance(channel, packagemanagerImplementation, false, _packagemanager);

                ASSERT((_packagemanager != nullptr) && (packagemanagerProxy != nullptr));
            }

            uint32_t result = implementation->Offer(_packagemanager);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (packagemanagerProxy != nullptr) {
                RPC::Administrator::Instance().Release(packagemanagerProxy, message->Response());
            }
        },

        // (1) virtual uint32_t Revoke(const Exchange::IPackageManager*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManagerBroker* implementation = reinterpret_cast<Exchange::IPackageManagerBroker*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id packagemanagerImplementation = reader.Number<Core::instance_id>();

            Exchange::IPackageManager* _packagemanager = nullptr;
            ProxyStub::UnknownProxy* packagemanagerProxy = nullptr;
            if (packagemanagerImplementation != 0) {
                packagemanagerProxy = RPC::Administrator::Instance().ProxyInstance(channel, packagemanagerImplementation, false, _packagemanager);

                ASSERT((_packagemanager != nullptr) && (packagemanagerProxy != nullptr));
            }

            uint32_t result = implementation->Revoke(_packagemanager);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (packagemanagerProxy != nullptr) {
                RPC::Administrator::Instance().Release(packagemanagerProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangePackageManagerBrokerStubMethods

    //
    // Exchange::IPackageManagerCallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void OperationStatusUpdate(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangePackageManagerCallbackStubMethods[] = {
        // (0) virtual void OperationStatusUpdate(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackageManagerCallback* implementation = reinterpret_cast<Exchange::IPackageManagerCallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _handle = reader.Text();
            const string _operation = reader.Text();
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _status = reader.Text();
            const string _details = reader.Text();

            implementation->OperationStatusUpdate(static_cast<const string&>(_handle), static_cast<const string&>(_operation), static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_status), static_cast<const string&>(_details));
        }
        , nullptr
    }; // ExchangePackageManagerCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstanceF3A0ECC7 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstanceF3A0ECC7Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstanceF3A0ECC7Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        bool Next(string& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Text();

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info = reader.Text();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class RPCIteratorTypeInstanceF3A0ECC7Proxy

    //
    // RPC::IIteratorTypeInstance313F165B interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPackageManager::KeyValue&) = 0
    //  (1) virtual bool Previous(Exchange::IPackageManager::KeyValue&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPackageManager::KeyValue Current() const = 0
    //

    class RPCIteratorTypeInstance313F165BProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>> {
    public:
        RPCIteratorTypeInstance313F165BProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        bool Next(Exchange::IPackageManager::KeyValue& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.key = reader.Text();
            _info.value = reader.Text();

            return (result);
        }

        bool Previous(Exchange::IPackageManager::KeyValue& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.key = reader.Text();
            _info.value = reader.Text();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IPackageManager::KeyValue Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IPackageManager::KeyValue result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result.key = reader.Text();
            result.value = reader.Text();

            return (result);
        }

    }; // class RPCIteratorTypeInstance313F165BProxy

    //
    // RPC::IIteratorTypeInstance46356EDF interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IPackageManager::PackageKey&) = 0
    //  (1) virtual bool Previous(Exchange::IPackageManager::PackageKey&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IPackageManager::PackageKey Current() const = 0
    //

    class RPCIteratorTypeInstance46356EDFProxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>> {
    public:
        RPCIteratorTypeInstance46356EDFProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        bool Next(Exchange::IPackageManager::PackageKey& _info) override
        {
            IPCMessage message(BaseClass::Message(0));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.id = reader.Text();
            _info.version = reader.Text();

            return (result);
        }

        bool Previous(Exchange::IPackageManager::PackageKey& _info) override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();
            _info.id = reader.Text();
            _info.version = reader.Text();

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(BaseClass::Message(4));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::IPackageManager::PackageKey Current() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::IPackageManager::PackageKey result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result.id = reader.Text();
            result.version = reader.Text();

            return (result);
        }

    }; // class RPCIteratorTypeInstance46356EDFProxy

    //
    // Exchange::IPackageManager interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Install(const string&, const string&, const string&, const string&, const string&, const string&, string&) = 0
    //  (1) virtual uint32_t Uninstall(const string&, const string&, const string&, const string&, string&) = 0
    //  (2) virtual uint32_t Download(const string&, const string&, const string&, const string&, const string&, string&) = 0
    //  (3) virtual uint32_t Reset(const string&, const string&, const string&, const string&) = 0
    //  (4) virtual uint32_t GetStorageDetails(const string&, const string&, const string&, Exchange::IPackageManager::StorageInfo&) const = 0
    //  (5) virtual uint32_t SetAuxMetadata(const string&, const string&, const string&, const string&, const string&) = 0
    //  (6) virtual uint32_t ClearAuxMetadata(const string&, const string&, const string&, const string&) = 0
    //  (7) virtual uint32_t GetMetadata(const string&, const string&, const string&, Exchange::IPackageManager::MetadataPayload&, Exchange::IPackageManager::IKeyValueIterator*&, Exchange::IPackageManager::IKeyValueIterator*&) const = 0
    //  (8) virtual uint32_t Cancel(const string&) = 0
    //  (9) virtual uint32_t GetProgress(const string&, uint32_t&) const = 0
    //  (10) virtual uint32_t Register(Exchange::IPackageManager::INotification*) = 0
    //  (11) virtual uint32_t Unregister(Exchange::IPackageManager::INotification*) = 0
    //  (12) virtual uint32_t GetList(const string&, const string&, const string&, const string&, const string&, Exchange::IPackageManager::IPackageKeyIterator*&) const = 0
    //  (13) virtual uint32_t Lock(const string&, const string&, const string&, const string&, const string&, string&) = 0
    //  (14) virtual uint32_t Unlock(const string&) = 0
    //  (15) virtual uint32_t GetLockInfo(const string&, const string&, const string&, Exchange::IPackageManager::LockInfo&) const = 0
    //

    class ExchangePackageManagerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackageManager> {
    public:
        ExchangePackageManagerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        uint32_t Install(const string& _type, const string& _id, const string& _version, const string& _url, const string& _appName, const string& _category, string& _handle) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_url));
            writer.Text(static_cast<const string&>(_appName));
            writer.Text(static_cast<const string&>(_category));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _handle = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Uninstall(const string& _type, const string& _id, const string& _version, const string& _uninstallType, string& _handle) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_uninstallType));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _handle = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Download(const string& _type, const string& _id, const string& _version, const string& _resKey, const string& _url, string& _handle) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_resKey));
            writer.Text(static_cast<const string&>(_url));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _handle = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Reset(const string& _type, const string& _id, const string& _version, const string& _resetType) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_resetType));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetStorageDetails(const string& _type, const string& _id, const string& _version, Exchange::IPackageManager::StorageInfo& _storageinfo) const override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _storageinfo.apps.path = reader.Text();
                    _storageinfo.apps.quotaKB = reader.Text();
                    _storageinfo.apps.usedKB = reader.Text();
                    _storageinfo.persistent.path = reader.Text();
                    _storageinfo.persistent.quotaKB = reader.Text();
                    _storageinfo.persistent.usedKB = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetAuxMetadata(const string& _type, const string& _id, const string& _version, const string& _key, const string& _value) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_key));
            writer.Text(static_cast<const string&>(_value));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t ClearAuxMetadata(const string& _type, const string& _id, const string& _version, const string& _key) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_key));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetMetadata(const string& _type, const string& _id, const string& _version, Exchange::IPackageManager::MetadataPayload& _metadata, Exchange::IPackageManager::IKeyValueIterator*& _resources, Exchange::IPackageManager::IKeyValueIterator*& _auxMetadata) const override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _metadata.appName = reader.Text();
                    _metadata.type = reader.Text();
                    _metadata.category = reader.Text();
                    _metadata.url = reader.Text();
                    _resources = reinterpret_cast<Exchange::IPackageManager::IKeyValueIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IPackageManager::IKeyValueIterator::ID));
                    _auxMetadata = reinterpret_cast<Exchange::IPackageManager::IKeyValueIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IPackageManager::IKeyValueIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Cancel(const string& _handle) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_handle));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetProgress(const string& _handle, uint32_t& _progress) const override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_handle));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _progress = reader.Number<uint32_t>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Register(Exchange::IPackageManager::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Unregister(Exchange::IPackageManager::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetList(const string& _type, const string& _id, const string& _version, const string& _appName, const string& _category, Exchange::IPackageManager::IPackageKeyIterator*& _installedIds) const override
        {
            IPCMessage message(BaseClass::Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_appName));
            writer.Text(static_cast<const string&>(_category));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _installedIds = reinterpret_cast<Exchange::IPackageManager::IPackageKeyIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IPackageManager::IPackageKeyIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Lock(const string& _type, const string& _id, const string& _version, const string& _reason, const string& _owner, string& _handle) override
        {
            IPCMessage message(BaseClass::Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_reason));
            writer.Text(static_cast<const string&>(_owner));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _handle = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Unlock(const string& _handle) override
        {
            IPCMessage message(BaseClass::Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_handle));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetLockInfo(const string& _type, const string& _id, const string& _version, Exchange::IPackageManager::LockInfo& _result) const override
        {
            IPCMessage message(BaseClass::Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _result.reason = reader.Text();
                    _result.owner = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangePackageManagerProxy

    //
    // Exchange::IPackageManager::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OperationStatus(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
    //

    class ExchangePackageManagerNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackageManager::INotification> {
    public:
        ExchangePackageManagerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void OperationStatus(const string& _handle, const string& _operation, const string& _type, const string& _id, const string& _version, const string& _status, const string& _details) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_handle));
            writer.Text(static_cast<const string&>(_operation));
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_status));
            writer.Text(static_cast<const string&>(_details));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangePackageManagerNotificationProxy

    //
    // Exchange::IPackageManagerBroker interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Offer(Exchange::IPackageManager*) = 0
    //  (1) virtual uint32_t Revoke(const Exchange::IPackageManager*) = 0
    //

    class ExchangePackageManagerBrokerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackageManagerBroker> {
    public:
        ExchangePackageManagerBrokerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        uint32_t Offer(Exchange::IPackageManager* _packagemanager) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_packagemanager));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Revoke(const Exchange::IPackageManager* _packagemanager) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_packagemanager));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

    }; // class ExchangePackageManagerBrokerProxy

    //
    // Exchange::IPackageManagerCallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OperationStatusUpdate(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
    //

    class ExchangePackageManagerCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackageManagerCallback> {
    public:
        ExchangePackageManagerCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Complete(RPC::Data::Frame::Reader& reader)
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

        void OperationStatusUpdate(const string& _handle, const string& _operation, const string& _type, const string& _id, const string& _version, const string& _status, const string& _details) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_handle));
            writer.Text(static_cast<const string&>(_operation));
            writer.Text(static_cast<const string&>(_type));
            writer.Text(static_cast<const string&>(_id));
            writer.Text(static_cast<const string&>(_version));
            writer.Text(static_cast<const string&>(_status));
            writer.Text(static_cast<const string&>(_details));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangePackageManagerCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstanceF3A0ECC7StubMethods> RPCIteratorTypeInstanceF3A0ECC7Stub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>, RPCIteratorTypeInstance313F165BStubMethods> RPCIteratorTypeInstance313F165BStub;
        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>, RPCIteratorTypeInstance46356EDFStubMethods> RPCIteratorTypeInstance46356EDFStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPackageManager, ExchangePackageManagerStubMethods> ExchangePackageManagerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPackageManager::INotification, ExchangePackageManagerNotificationStubMethods> ExchangePackageManagerNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPackageManagerBroker, ExchangePackageManagerBrokerStubMethods> ExchangePackageManagerBrokerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPackageManagerCallback, ExchangePackageManagerCallbackStubMethods> ExchangePackageManagerCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstanceF3A0ECC7Proxy, RPCIteratorTypeInstanceF3A0ECC7Stub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>, RPCIteratorTypeInstance313F165BProxy, RPCIteratorTypeInstance313F165BStub>();
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>, RPCIteratorTypeInstance46356EDFProxy, RPCIteratorTypeInstance46356EDFStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPackageManager, ExchangePackageManagerProxy, ExchangePackageManagerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPackageManager::INotification, ExchangePackageManagerNotificationProxy, ExchangePackageManagerNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPackageManagerBroker, ExchangePackageManagerBrokerProxy, ExchangePackageManagerBrokerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPackageManagerCallback, ExchangePackageManagerCallbackProxy, ExchangePackageManagerCallbackStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IPackageManager::KeyValue, Exchange::ID_PACKAGEMANAGER_KEY_VALUE_ITERATOR>>();
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IPackageManager::PackageKey, Exchange::ID_PACKAGEMANAGER_PACKAGE_KEY_ITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IPackageManager>();
                RPC::Administrator::Instance().Recall<Exchange::IPackageManager::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IPackageManagerBroker>();
                RPC::Administrator::Instance().Recall<Exchange::IPackageManagerCallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
