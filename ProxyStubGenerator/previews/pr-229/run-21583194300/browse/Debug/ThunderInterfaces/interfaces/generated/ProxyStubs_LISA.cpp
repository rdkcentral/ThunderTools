//
// generated automatically from "ILISA.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ILISA
//   - class Exchange::ILISA::IStorage
//   - class Exchange::ILISA::IStoragePayload
//   - class Exchange::ILISA::IKeyValue
//   - class Exchange::ILISA::IKeyValueIterator
//   - class Exchange::ILISA::IMetadataPayload
//   - class Exchange::ILISA::INotification
//   - class Exchange::ILISA::IAppVersion
//   - class Exchange::ILISA::IAppVersion::IIterator
//   - class Exchange::ILISA::IApp
//   - class Exchange::ILISA::IApp::IIterator
//   - class Exchange::ILISA::IAppsPayload
//   - class Exchange::ILISA::IHandleResult
//   - class Exchange::ILISA::ILockInfo
//

#include "Module.h"
#include "ILISA.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ILISA interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Install(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
    //  (1) virtual uint32_t Uninstall(const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
    //  (2) virtual uint32_t Download(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
    //  (3) virtual uint32_t Reset(const std::string&, const std::string&, const std::string&, const std::string&) = 0
    //  (4) virtual uint32_t GetStorageDetails(const std::string&, const std::string&, const std::string&, Exchange::ILISA::IStoragePayload*&) = 0
    //  (5) virtual uint32_t SetAuxMetadata(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) = 0
    //  (6) virtual uint32_t ClearAuxMetadata(const std::string&, const std::string&, const std::string&, const std::string&) = 0
    //  (7) virtual uint32_t GetMetadata(const std::string&, const std::string&, const std::string&, Exchange::ILISA::IMetadataPayload*&) = 0
    //  (8) virtual uint32_t Cancel(const std::string&) = 0
    //  (9) virtual uint32_t GetProgress(const std::string&, uint32_t&) = 0
    //  (10) virtual uint32_t Register(Exchange::ILISA::INotification*) = 0
    //  (11) virtual uint32_t Unregister(Exchange::ILISA::INotification*) = 0
    //  (12) virtual uint32_t Configure(const std::string&) = 0
    //  (13) virtual uint32_t GetList(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, Exchange::ILISA::IAppsPayload*&) const = 0
    //  (14) virtual uint32_t Lock(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, Exchange::ILISA::IHandleResult*&) = 0
    //  (15) virtual uint32_t Unlock(const std::string&) = 0
    //  (16) virtual uint32_t GetLockInfo(const std::string&, const std::string&, const std::string&, Exchange::ILISA::ILockInfo*&) = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAStubMethods[] = {
        // (0) virtual uint32_t Install(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _url = reader.Text();
            const std::string _appName = reader.Text();
            const std::string _category = reader.Text();

            std::string _handle{};

            uint32_t result = implementation->Install(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_url), static_cast<const std::string&>(_appName), static_cast<const std::string&>(_category), _handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        },

        // (1) virtual uint32_t Uninstall(const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _uninstallType = reader.Text();

            std::string _handle{};

            uint32_t result = implementation->Uninstall(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_uninstallType), _handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        },

        // (2) virtual uint32_t Download(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _resKey = reader.Text();
            const std::string _url = reader.Text();

            std::string _handle{};

            uint32_t result = implementation->Download(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_resKey), static_cast<const std::string&>(_url), _handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        },

        // (3) virtual uint32_t Reset(const std::string&, const std::string&, const std::string&, const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _resetType = reader.Text();

            uint32_t result = implementation->Reset(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_resetType));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t GetStorageDetails(const std::string&, const std::string&, const std::string&, Exchange::ILISA::IStoragePayload*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();

            Exchange::ILISA::IStoragePayload* _result{};

            uint32_t result = implementation->GetStorageDetails(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_result));

            RPC::Administrator::Instance().RegisterInterface(channel, _result);
        },

        // (5) virtual uint32_t SetAuxMetadata(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _key = reader.Text();
            const std::string _value = reader.Text();

            uint32_t result = implementation->SetAuxMetadata(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_key), static_cast<const std::string&>(_value));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t ClearAuxMetadata(const std::string&, const std::string&, const std::string&, const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _key = reader.Text();

            uint32_t result = implementation->ClearAuxMetadata(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_key));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t GetMetadata(const std::string&, const std::string&, const std::string&, Exchange::ILISA::IMetadataPayload*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();

            Exchange::ILISA::IMetadataPayload* _result{};

            uint32_t result = implementation->GetMetadata(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_result));

            RPC::Administrator::Instance().RegisterInterface(channel, _result);
        },

        // (8) virtual uint32_t Cancel(const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _handle = reader.Text();

            uint32_t result = implementation->Cancel(static_cast<const std::string&>(_handle));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t GetProgress(const std::string&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _handle = reader.Text();

            uint32_t _progress{};

            uint32_t result = implementation->GetProgress(static_cast<const std::string&>(_handle), _progress);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_progress);
        },

        // (10) virtual uint32_t Register(Exchange::ILISA::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ILISA::INotification* _notification{};
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

        // (11) virtual uint32_t Unregister(Exchange::ILISA::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ILISA::INotification* _notification{};
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

        // (12) virtual uint32_t Configure(const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _config = reader.Text();

            uint32_t result = implementation->Configure(static_cast<const std::string&>(_config));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (13) virtual uint32_t GetList(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, Exchange::ILISA::IAppsPayload*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA* implementation = reinterpret_cast<const Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _appName = reader.Text();
            const std::string _category = reader.Text();

            Exchange::ILISA::IAppsPayload* _result{};

            uint32_t result = implementation->GetList(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_appName), static_cast<const std::string&>(_category), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_result));

            RPC::Administrator::Instance().RegisterInterface(channel, _result);
        },

        // (14) virtual uint32_t Lock(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, Exchange::ILISA::IHandleResult*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();
            const std::string _reason = reader.Text();
            const std::string _owner = reader.Text();

            Exchange::ILISA::IHandleResult* _result{};

            uint32_t result = implementation->Lock(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), static_cast<const std::string&>(_reason), static_cast<const std::string&>(_owner), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_result));

            RPC::Administrator::Instance().RegisterInterface(channel, _result);
        },

        // (15) virtual uint32_t Unlock(const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _handle = reader.Text();

            uint32_t result = implementation->Unlock(static_cast<const std::string&>(_handle));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (16) virtual uint32_t GetLockInfo(const std::string&, const std::string&, const std::string&, Exchange::ILISA::ILockInfo*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA* implementation = reinterpret_cast<Exchange::ILISA*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _type = reader.Text();
            const std::string _id = reader.Text();
            const std::string _version = reader.Text();

            Exchange::ILISA::ILockInfo* _result{};

            uint32_t result = implementation->GetLockInfo(static_cast<const std::string&>(_type), static_cast<const std::string&>(_id), static_cast<const std::string&>(_version), _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_result));

            RPC::Administrator::Instance().RegisterInterface(channel, _result);
        }
        , nullptr
    }; // ExchangeLISAStubMethods

    //
    // Exchange::ILISA::IStorage interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Path(string&) const = 0
    //  (1) virtual uint32_t QuotaKB(string&) const = 0
    //  (2) virtual uint32_t UsedKB(string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAStorageStubMethods[] = {
        // (0) virtual uint32_t Path(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IStorage* implementation = reinterpret_cast<const Exchange::ILISA::IStorage*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _path{};

            uint32_t result = implementation->Path(_path);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_path);
        },

        // (1) virtual uint32_t QuotaKB(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IStorage* implementation = reinterpret_cast<const Exchange::ILISA::IStorage*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _quotaKB{};

            uint32_t result = implementation->QuotaKB(_quotaKB);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_quotaKB);
        },

        // (2) virtual uint32_t UsedKB(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IStorage* implementation = reinterpret_cast<const Exchange::ILISA::IStorage*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _usedKB{};

            uint32_t result = implementation->UsedKB(_usedKB);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_usedKB);
        }
        , nullptr
    }; // ExchangeLISAStorageStubMethods

    //
    // Exchange::ILISA::IStoragePayload interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Apps(Exchange::ILISA::IStorage*&) const = 0
    //  (1) virtual uint32_t Persistent(Exchange::ILISA::IStorage*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAStoragePayloadStubMethods[] = {
        // (0) virtual uint32_t Apps(Exchange::ILISA::IStorage*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IStoragePayload* implementation = reinterpret_cast<const Exchange::ILISA::IStoragePayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IStorage* _storage{};

            uint32_t result = implementation->Apps(_storage);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_storage));

            RPC::Administrator::Instance().RegisterInterface(channel, _storage);
        },

        // (1) virtual uint32_t Persistent(Exchange::ILISA::IStorage*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IStoragePayload* implementation = reinterpret_cast<const Exchange::ILISA::IStoragePayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IStorage* _storage{};

            uint32_t result = implementation->Persistent(_storage);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_storage));

            RPC::Administrator::Instance().RegisterInterface(channel, _storage);
        }
        , nullptr
    }; // ExchangeLISAStoragePayloadStubMethods

    //
    // Exchange::ILISA::IKeyValue interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Key(string&) const = 0
    //  (1) virtual uint32_t Value(string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAKeyValueStubMethods[] = {
        // (0) virtual uint32_t Key(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IKeyValue* implementation = reinterpret_cast<const Exchange::ILISA::IKeyValue*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _key{};

            uint32_t result = implementation->Key(_key);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_key);
        },

        // (1) virtual uint32_t Value(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IKeyValue* implementation = reinterpret_cast<const Exchange::ILISA::IKeyValue*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _value{};

            uint32_t result = implementation->Value(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_value);
        }
        , nullptr
    }; // ExchangeLISAKeyValueStubMethods

    //
    // Exchange::ILISA::IKeyValueIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reset() = 0
    //  (1) virtual uint32_t IsValid(bool&) const = 0
    //  (2) virtual uint32_t Next(bool&) = 0
    //  (3) virtual uint32_t Current(Exchange::ILISA::IKeyValue*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAKeyValueIteratorStubMethods[] = {
        // (0) virtual uint32_t Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA::IKeyValueIterator* implementation = reinterpret_cast<Exchange::ILISA::IKeyValueIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Reset();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t IsValid(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IKeyValueIterator* implementation = reinterpret_cast<const Exchange::ILISA::IKeyValueIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _isValid{};

            uint32_t result = implementation->IsValid(_isValid);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_isValid);
        },

        // (2) virtual uint32_t Next(bool&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA::IKeyValueIterator* implementation = reinterpret_cast<Exchange::ILISA::IKeyValueIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _hasNext{};

            uint32_t result = implementation->Next(_hasNext);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_hasNext);
        },

        // (3) virtual uint32_t Current(Exchange::ILISA::IKeyValue*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IKeyValueIterator* implementation = reinterpret_cast<const Exchange::ILISA::IKeyValueIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IKeyValue* _keyValue{};

            uint32_t result = implementation->Current(_keyValue);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_keyValue));

            RPC::Administrator::Instance().RegisterInterface(channel, _keyValue);
        }
        , nullptr
    }; // ExchangeLISAKeyValueIteratorStubMethods

    //
    // Exchange::ILISA::IMetadataPayload interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t AppName(std::string&) const = 0
    //  (1) virtual uint32_t Category(std::string&) const = 0
    //  (2) virtual uint32_t Url(std::string&) const = 0
    //  (3) virtual uint32_t Resources(Exchange::ILISA::IKeyValueIterator*&) const = 0
    //  (4) virtual uint32_t AuxMetadata(Exchange::ILISA::IKeyValueIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAMetadataPayloadStubMethods[] = {
        // (0) virtual uint32_t AppName(std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IMetadataPayload* implementation = reinterpret_cast<const Exchange::ILISA::IMetadataPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string _appName{};

            uint32_t result = implementation->AppName(_appName);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_appName);
        },

        // (1) virtual uint32_t Category(std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IMetadataPayload* implementation = reinterpret_cast<const Exchange::ILISA::IMetadataPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string _category{};

            uint32_t result = implementation->Category(_category);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_category);
        },

        // (2) virtual uint32_t Url(std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IMetadataPayload* implementation = reinterpret_cast<const Exchange::ILISA::IMetadataPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string _url{};

            uint32_t result = implementation->Url(_url);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_url);
        },

        // (3) virtual uint32_t Resources(Exchange::ILISA::IKeyValueIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IMetadataPayload* implementation = reinterpret_cast<const Exchange::ILISA::IMetadataPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IKeyValueIterator* _resources{};

            uint32_t result = implementation->Resources(_resources);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_resources));

            RPC::Administrator::Instance().RegisterInterface(channel, _resources);
        },

        // (4) virtual uint32_t AuxMetadata(Exchange::ILISA::IKeyValueIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IMetadataPayload* implementation = reinterpret_cast<const Exchange::ILISA::IMetadataPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IKeyValueIterator* _auxMetadata{};

            uint32_t result = implementation->AuxMetadata(_auxMetadata);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_auxMetadata));

            RPC::Administrator::Instance().RegisterInterface(channel, _auxMetadata);
        }
        , nullptr
    }; // ExchangeLISAMetadataPayloadStubMethods

    //
    // Exchange::ILISA::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void operationStatus(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeLISANotificationStubMethods[] = {
        // (0) virtual void operationStatus(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA::INotification* implementation = reinterpret_cast<Exchange::ILISA::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _handle = reader.Text();
            const string _operation = reader.Text();
            const string _type = reader.Text();
            const string _id = reader.Text();
            const string _version = reader.Text();
            const string _status = reader.Text();
            const string _details = reader.Text();

            implementation->operationStatus(static_cast<const string&>(_handle), static_cast<const string&>(_operation), static_cast<const string&>(_type), static_cast<const string&>(_id), static_cast<const string&>(_version), static_cast<const string&>(_status), static_cast<const string&>(_details));
        }
        , nullptr
    }; // ExchangeLISANotificationStubMethods

    //
    // Exchange::ILISA::IAppVersion interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Version(string&) const = 0
    //  (1) virtual uint32_t AppName(string&) const = 0
    //  (2) virtual uint32_t Category(string&) const = 0
    //  (3) virtual uint32_t Url(string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAAppVersionStubMethods[] = {
        // (0) virtual uint32_t Version(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IAppVersion* implementation = reinterpret_cast<const Exchange::ILISA::IAppVersion*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _version{};

            uint32_t result = implementation->Version(_version);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_version);
        },

        // (1) virtual uint32_t AppName(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IAppVersion* implementation = reinterpret_cast<const Exchange::ILISA::IAppVersion*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _appName{};

            uint32_t result = implementation->AppName(_appName);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_appName);
        },

        // (2) virtual uint32_t Category(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IAppVersion* implementation = reinterpret_cast<const Exchange::ILISA::IAppVersion*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _category{};

            uint32_t result = implementation->Category(_category);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_category);
        },

        // (3) virtual uint32_t Url(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IAppVersion* implementation = reinterpret_cast<const Exchange::ILISA::IAppVersion*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _url{};

            uint32_t result = implementation->Url(_url);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_url);
        }
        , nullptr
    }; // ExchangeLISAAppVersionStubMethods

    //
    // Exchange::ILISA::IAppVersion::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reset() = 0
    //  (1) virtual uint32_t IsValid(bool&) const = 0
    //  (2) virtual uint32_t Next(bool&) = 0
    //  (3) virtual uint32_t Current(Exchange::ILISA::IAppVersion*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAAppVersionIteratorStubMethods[] = {
        // (0) virtual uint32_t Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA::IAppVersion::IIterator* implementation = reinterpret_cast<Exchange::ILISA::IAppVersion::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Reset();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t IsValid(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IAppVersion::IIterator* implementation = reinterpret_cast<const Exchange::ILISA::IAppVersion::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _isValid{};

            uint32_t result = implementation->IsValid(_isValid);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_isValid);
        },

        // (2) virtual uint32_t Next(bool&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA::IAppVersion::IIterator* implementation = reinterpret_cast<Exchange::ILISA::IAppVersion::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _hasNext{};

            uint32_t result = implementation->Next(_hasNext);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_hasNext);
        },

        // (3) virtual uint32_t Current(Exchange::ILISA::IAppVersion*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IAppVersion::IIterator* implementation = reinterpret_cast<const Exchange::ILISA::IAppVersion::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IAppVersion* _app{};

            uint32_t result = implementation->Current(_app);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_app));

            RPC::Administrator::Instance().RegisterInterface(channel, _app);
        }
        , nullptr
    }; // ExchangeLISAAppVersionIteratorStubMethods

    //
    // Exchange::ILISA::IApp interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Type(string&) const = 0
    //  (1) virtual uint32_t Id(string&) const = 0
    //  (2) virtual uint32_t Installed(Exchange::ILISA::IAppVersion::IIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAAppStubMethods[] = {
        // (0) virtual uint32_t Type(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IApp* implementation = reinterpret_cast<const Exchange::ILISA::IApp*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _type{};

            uint32_t result = implementation->Type(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_type);
        },

        // (1) virtual uint32_t Id(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IApp* implementation = reinterpret_cast<const Exchange::ILISA::IApp*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _id{};

            uint32_t result = implementation->Id(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_id);
        },

        // (2) virtual uint32_t Installed(Exchange::ILISA::IAppVersion::IIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IApp* implementation = reinterpret_cast<const Exchange::ILISA::IApp*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IAppVersion::IIterator* _versions{};

            uint32_t result = implementation->Installed(_versions);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_versions));

            RPC::Administrator::Instance().RegisterInterface(channel, _versions);
        }
        , nullptr
    }; // ExchangeLISAAppStubMethods

    //
    // Exchange::ILISA::IApp::IIterator interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reset() = 0
    //  (1) virtual uint32_t IsValid(bool&) const = 0
    //  (2) virtual uint32_t Next(bool&) = 0
    //  (3) virtual uint32_t Current(Exchange::ILISA::IApp*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAAppIteratorStubMethods[] = {
        // (0) virtual uint32_t Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA::IApp::IIterator* implementation = reinterpret_cast<Exchange::ILISA::IApp::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Reset();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t IsValid(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IApp::IIterator* implementation = reinterpret_cast<const Exchange::ILISA::IApp::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _isValid{};

            uint32_t result = implementation->IsValid(_isValid);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_isValid);
        },

        // (2) virtual uint32_t Next(bool&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILISA::IApp::IIterator* implementation = reinterpret_cast<Exchange::ILISA::IApp::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _hasNext{};

            uint32_t result = implementation->Next(_hasNext);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_hasNext);
        },

        // (3) virtual uint32_t Current(Exchange::ILISA::IApp*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IApp::IIterator* implementation = reinterpret_cast<const Exchange::ILISA::IApp::IIterator*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IApp* _app{};

            uint32_t result = implementation->Current(_app);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_app));

            RPC::Administrator::Instance().RegisterInterface(channel, _app);
        }
        , nullptr
    }; // ExchangeLISAAppIteratorStubMethods

    //
    // Exchange::ILISA::IAppsPayload interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Apps(Exchange::ILISA::IApp::IIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAAppsPayloadStubMethods[] = {
        // (0) virtual uint32_t Apps(Exchange::ILISA::IApp::IIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IAppsPayload* implementation = reinterpret_cast<const Exchange::ILISA::IAppsPayload*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILISA::IApp::IIterator* _apps{};

            uint32_t result = implementation->Apps(_apps);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_apps));

            RPC::Administrator::Instance().RegisterInterface(channel, _apps);
        }
        , nullptr
    }; // ExchangeLISAAppsPayloadStubMethods

    //
    // Exchange::ILISA::IHandleResult interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Handle(std::string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISAHandleResultStubMethods[] = {
        // (0) virtual uint32_t Handle(std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::IHandleResult* implementation = reinterpret_cast<const Exchange::ILISA::IHandleResult*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string _handle{};

            uint32_t result = implementation->Handle(_handle);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_handle);
        }
        , nullptr
    }; // ExchangeLISAHandleResultStubMethods

    //
    // Exchange::ILISA::ILockInfo interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reason(std::string&) const = 0
    //  (1) virtual uint32_t Owner(std::string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLISALockInfoStubMethods[] = {
        // (0) virtual uint32_t Reason(std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::ILockInfo* implementation = reinterpret_cast<const Exchange::ILISA::ILockInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string _reason{};

            uint32_t result = implementation->Reason(_reason);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_reason);
        },

        // (1) virtual uint32_t Owner(std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILISA::ILockInfo* implementation = reinterpret_cast<const Exchange::ILISA::ILockInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string _owner{};

            uint32_t result = implementation->Owner(_owner);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_owner);
        }
        , nullptr
    }; // ExchangeLISALockInfoStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ILISA interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Install(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
    //  (1) virtual uint32_t Uninstall(const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
    //  (2) virtual uint32_t Download(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, std::string&) = 0
    //  (3) virtual uint32_t Reset(const std::string&, const std::string&, const std::string&, const std::string&) = 0
    //  (4) virtual uint32_t GetStorageDetails(const std::string&, const std::string&, const std::string&, Exchange::ILISA::IStoragePayload*&) = 0
    //  (5) virtual uint32_t SetAuxMetadata(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&) = 0
    //  (6) virtual uint32_t ClearAuxMetadata(const std::string&, const std::string&, const std::string&, const std::string&) = 0
    //  (7) virtual uint32_t GetMetadata(const std::string&, const std::string&, const std::string&, Exchange::ILISA::IMetadataPayload*&) = 0
    //  (8) virtual uint32_t Cancel(const std::string&) = 0
    //  (9) virtual uint32_t GetProgress(const std::string&, uint32_t&) = 0
    //  (10) virtual uint32_t Register(Exchange::ILISA::INotification*) = 0
    //  (11) virtual uint32_t Unregister(Exchange::ILISA::INotification*) = 0
    //  (12) virtual uint32_t Configure(const std::string&) = 0
    //  (13) virtual uint32_t GetList(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, Exchange::ILISA::IAppsPayload*&) const = 0
    //  (14) virtual uint32_t Lock(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, Exchange::ILISA::IHandleResult*&) = 0
    //  (15) virtual uint32_t Unlock(const std::string&) = 0
    //  (16) virtual uint32_t GetLockInfo(const std::string&, const std::string&, const std::string&, Exchange::ILISA::ILockInfo*&) = 0
    //

    class ExchangeLISAProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA> {
    public:
        ExchangeLISAProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Install(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _url, const std::string& _appName, const std::string& _category, std::string& _handle) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
            writer.Text(_url);
            writer.Text(_appName);
            writer.Text(_category);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _handle = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Uninstall(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _uninstallType, std::string& _handle) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
            writer.Text(_uninstallType);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _handle = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Download(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _resKey, const std::string& _url, std::string& _handle) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
            writer.Text(_resKey);
            writer.Text(_url);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _handle = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Reset(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _resetType) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
            writer.Text(_resetType);

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

        uint32_t GetStorageDetails(const std::string& _type, const std::string& _id, const std::string& _version, Exchange::ILISA::IStoragePayload*& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _result = reinterpret_cast<Exchange::ILISA::IStoragePayload*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IStoragePayload::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t SetAuxMetadata(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _key, const std::string& _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
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

        uint32_t ClearAuxMetadata(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _key) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
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

        uint32_t GetMetadata(const std::string& _type, const std::string& _id, const std::string& _version, Exchange::ILISA::IMetadataPayload*& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _result = reinterpret_cast<Exchange::ILISA::IMetadataPayload*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IMetadataPayload::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Cancel(const std::string& _handle) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_handle);

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

        uint32_t GetProgress(const std::string& _handle, uint32_t& _progress) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_handle);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _progress = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Register(Exchange::ILISA::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

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

        uint32_t Unregister(Exchange::ILISA::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

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

        uint32_t Configure(const std::string& _config) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_config);

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

        uint32_t GetList(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _appName, const std::string& _category, Exchange::ILISA::IAppsPayload*& _result) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
            writer.Text(_appName);
            writer.Text(_category);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _result = reinterpret_cast<Exchange::ILISA::IAppsPayload*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IAppsPayload::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Lock(const std::string& _type, const std::string& _id, const std::string& _version, const std::string& _reason, const std::string& _owner, Exchange::ILISA::IHandleResult*& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
            writer.Text(_reason);
            writer.Text(_owner);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _result = reinterpret_cast<Exchange::ILISA::IHandleResult*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IHandleResult::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Unlock(const std::string& _handle) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_handle);

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

        uint32_t GetLockInfo(const std::string& _type, const std::string& _id, const std::string& _version, Exchange::ILISA::ILockInfo*& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(16));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _result = reinterpret_cast<Exchange::ILISA::ILockInfo*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::ILockInfo::ID));
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

    }; // class ExchangeLISAProxy

    //
    // Exchange::ILISA::IStorage interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Path(string&) const = 0
    //  (1) virtual uint32_t QuotaKB(string&) const = 0
    //  (2) virtual uint32_t UsedKB(string&) const = 0
    //

    class ExchangeLISAStorageProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IStorage> {
    public:
        ExchangeLISAStorageProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Path(string& _path) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _path = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t QuotaKB(string& _quotaKB) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _quotaKB = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t UsedKB(string& _usedKB) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _usedKB = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAStorageProxy

    //
    // Exchange::ILISA::IStoragePayload interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Apps(Exchange::ILISA::IStorage*&) const = 0
    //  (1) virtual uint32_t Persistent(Exchange::ILISA::IStorage*&) const = 0
    //

    class ExchangeLISAStoragePayloadProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IStoragePayload> {
    public:
        ExchangeLISAStoragePayloadProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Apps(Exchange::ILISA::IStorage*& _storage) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _storage = reinterpret_cast<Exchange::ILISA::IStorage*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IStorage::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Persistent(Exchange::ILISA::IStorage*& _storage) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _storage = reinterpret_cast<Exchange::ILISA::IStorage*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IStorage::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAStoragePayloadProxy

    //
    // Exchange::ILISA::IKeyValue interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Key(string&) const = 0
    //  (1) virtual uint32_t Value(string&) const = 0
    //

    class ExchangeLISAKeyValueProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IKeyValue> {
    public:
        ExchangeLISAKeyValueProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Key(string& _key) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _key = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Value(string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

    }; // class ExchangeLISAKeyValueProxy

    //
    // Exchange::ILISA::IKeyValueIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reset() = 0
    //  (1) virtual uint32_t IsValid(bool&) const = 0
    //  (2) virtual uint32_t Next(bool&) = 0
    //  (3) virtual uint32_t Current(Exchange::ILISA::IKeyValue*&) const = 0
    //

    class ExchangeLISAKeyValueIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IKeyValueIterator> {
    public:
        ExchangeLISAKeyValueIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Reset() override
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

        uint32_t IsValid(bool& _isValid) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _isValid = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Next(bool& _hasNext) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _hasNext = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Current(Exchange::ILISA::IKeyValue*& _keyValue) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _keyValue = reinterpret_cast<Exchange::ILISA::IKeyValue*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IKeyValue::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAKeyValueIteratorProxy

    //
    // Exchange::ILISA::IMetadataPayload interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t AppName(std::string&) const = 0
    //  (1) virtual uint32_t Category(std::string&) const = 0
    //  (2) virtual uint32_t Url(std::string&) const = 0
    //  (3) virtual uint32_t Resources(Exchange::ILISA::IKeyValueIterator*&) const = 0
    //  (4) virtual uint32_t AuxMetadata(Exchange::ILISA::IKeyValueIterator*&) const = 0
    //

    class ExchangeLISAMetadataPayloadProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IMetadataPayload> {
    public:
        ExchangeLISAMetadataPayloadProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t AppName(std::string& _appName) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _appName = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Category(std::string& _category) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _category = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Url(std::string& _url) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _url = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Resources(Exchange::ILISA::IKeyValueIterator*& _resources) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _resources = reinterpret_cast<Exchange::ILISA::IKeyValueIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IKeyValueIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t AuxMetadata(Exchange::ILISA::IKeyValueIterator*& _auxMetadata) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _auxMetadata = reinterpret_cast<Exchange::ILISA::IKeyValueIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IKeyValueIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAMetadataPayloadProxy

    //
    // Exchange::ILISA::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void operationStatus(const string&, const string&, const string&, const string&, const string&, const string&, const string&) = 0
    //

    class ExchangeLISANotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::INotification> {
    public:
        ExchangeLISANotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void operationStatus(const string& _handle, const string& _operation, const string& _type, const string& _id, const string& _version, const string& _status, const string& _details) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_handle);
            writer.Text(_operation);
            writer.Text(_type);
            writer.Text(_id);
            writer.Text(_version);
            writer.Text(_status);
            writer.Text(_details);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeLISANotificationProxy

    //
    // Exchange::ILISA::IAppVersion interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Version(string&) const = 0
    //  (1) virtual uint32_t AppName(string&) const = 0
    //  (2) virtual uint32_t Category(string&) const = 0
    //  (3) virtual uint32_t Url(string&) const = 0
    //

    class ExchangeLISAAppVersionProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IAppVersion> {
    public:
        ExchangeLISAAppVersionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Version(string& _version) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _version = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t AppName(string& _appName) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _appName = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Category(string& _category) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _category = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Url(string& _url) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _url = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAAppVersionProxy

    //
    // Exchange::ILISA::IAppVersion::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reset() = 0
    //  (1) virtual uint32_t IsValid(bool&) const = 0
    //  (2) virtual uint32_t Next(bool&) = 0
    //  (3) virtual uint32_t Current(Exchange::ILISA::IAppVersion*&) const = 0
    //

    class ExchangeLISAAppVersionIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IAppVersion::IIterator> {
    public:
        ExchangeLISAAppVersionIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Reset() override
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

        uint32_t IsValid(bool& _isValid) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _isValid = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Next(bool& _hasNext) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _hasNext = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Current(Exchange::ILISA::IAppVersion*& _app) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _app = reinterpret_cast<Exchange::ILISA::IAppVersion*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IAppVersion::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAAppVersionIteratorProxy

    //
    // Exchange::ILISA::IApp interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Type(string&) const = 0
    //  (1) virtual uint32_t Id(string&) const = 0
    //  (2) virtual uint32_t Installed(Exchange::ILISA::IAppVersion::IIterator*&) const = 0
    //

    class ExchangeLISAAppProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IApp> {
    public:
        ExchangeLISAAppProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Type(string& _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _type = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Id(string& _id) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _id = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Installed(Exchange::ILISA::IAppVersion::IIterator*& _versions) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _versions = reinterpret_cast<Exchange::ILISA::IAppVersion::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IAppVersion::IIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAAppProxy

    //
    // Exchange::ILISA::IApp::IIterator interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reset() = 0
    //  (1) virtual uint32_t IsValid(bool&) const = 0
    //  (2) virtual uint32_t Next(bool&) = 0
    //  (3) virtual uint32_t Current(Exchange::ILISA::IApp*&) const = 0
    //

    class ExchangeLISAAppIteratorProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IApp::IIterator> {
    public:
        ExchangeLISAAppIteratorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Reset() override
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

        uint32_t IsValid(bool& _isValid) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _isValid = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Next(bool& _hasNext) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _hasNext = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Current(Exchange::ILISA::IApp*& _app) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _app = reinterpret_cast<Exchange::ILISA::IApp*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IApp::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAAppIteratorProxy

    //
    // Exchange::ILISA::IAppsPayload interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Apps(Exchange::ILISA::IApp::IIterator*&) const = 0
    //

    class ExchangeLISAAppsPayloadProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IAppsPayload> {
    public:
        ExchangeLISAAppsPayloadProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Apps(Exchange::ILISA::IApp::IIterator*& _apps) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _apps = reinterpret_cast<Exchange::ILISA::IApp::IIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::ILISA::IApp::IIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAAppsPayloadProxy

    //
    // Exchange::ILISA::IHandleResult interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Handle(std::string&) const = 0
    //

    class ExchangeLISAHandleResultProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::IHandleResult> {
    public:
        ExchangeLISAHandleResultProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Handle(std::string& _handle) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _handle = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISAHandleResultProxy

    //
    // Exchange::ILISA::ILockInfo interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Reason(std::string&) const = 0
    //  (1) virtual uint32_t Owner(std::string&) const = 0
    //

    class ExchangeLISALockInfoProxy final : public ProxyStub::UnknownProxyType<Exchange::ILISA::ILockInfo> {
    public:
        ExchangeLISALockInfoProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Reason(std::string& _reason) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _reason = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Owner(std::string& _owner) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
                _owner = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class ExchangeLISALockInfoProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ILISA, ExchangeLISAStubMethods> ExchangeLISAStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IStorage, ExchangeLISAStorageStubMethods> ExchangeLISAStorageStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IStoragePayload, ExchangeLISAStoragePayloadStubMethods> ExchangeLISAStoragePayloadStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IKeyValue, ExchangeLISAKeyValueStubMethods> ExchangeLISAKeyValueStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IKeyValueIterator, ExchangeLISAKeyValueIteratorStubMethods> ExchangeLISAKeyValueIteratorStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IMetadataPayload, ExchangeLISAMetadataPayloadStubMethods> ExchangeLISAMetadataPayloadStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::INotification, ExchangeLISANotificationStubMethods> ExchangeLISANotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IAppVersion, ExchangeLISAAppVersionStubMethods> ExchangeLISAAppVersionStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IAppVersion::IIterator, ExchangeLISAAppVersionIteratorStubMethods> ExchangeLISAAppVersionIteratorStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IApp, ExchangeLISAAppStubMethods> ExchangeLISAAppStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IApp::IIterator, ExchangeLISAAppIteratorStubMethods> ExchangeLISAAppIteratorStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IAppsPayload, ExchangeLISAAppsPayloadStubMethods> ExchangeLISAAppsPayloadStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::IHandleResult, ExchangeLISAHandleResultStubMethods> ExchangeLISAHandleResultStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILISA::ILockInfo, ExchangeLISALockInfoStubMethods> ExchangeLISALockInfoStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ILISA, ExchangeLISAProxy, ExchangeLISAStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IStorage, ExchangeLISAStorageProxy, ExchangeLISAStorageStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IStoragePayload, ExchangeLISAStoragePayloadProxy, ExchangeLISAStoragePayloadStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IKeyValue, ExchangeLISAKeyValueProxy, ExchangeLISAKeyValueStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IKeyValueIterator, ExchangeLISAKeyValueIteratorProxy, ExchangeLISAKeyValueIteratorStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IMetadataPayload, ExchangeLISAMetadataPayloadProxy, ExchangeLISAMetadataPayloadStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::INotification, ExchangeLISANotificationProxy, ExchangeLISANotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IAppVersion, ExchangeLISAAppVersionProxy, ExchangeLISAAppVersionStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IAppVersion::IIterator, ExchangeLISAAppVersionIteratorProxy, ExchangeLISAAppVersionIteratorStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IApp, ExchangeLISAAppProxy, ExchangeLISAAppStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IApp::IIterator, ExchangeLISAAppIteratorProxy, ExchangeLISAAppIteratorStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IAppsPayload, ExchangeLISAAppsPayloadProxy, ExchangeLISAAppsPayloadStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::IHandleResult, ExchangeLISAHandleResultProxy, ExchangeLISAHandleResultStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILISA::ILockInfo, ExchangeLISALockInfoProxy, ExchangeLISALockInfoStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ILISA>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IStorage>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IStoragePayload>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IKeyValue>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IKeyValueIterator>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IMetadataPayload>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IAppVersion>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IAppVersion::IIterator>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IApp>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IApp::IIterator>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IAppsPayload>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::IHandleResult>();
                RPC::Administrator::Instance().Recall<Exchange::ILISA::ILockInfo>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
