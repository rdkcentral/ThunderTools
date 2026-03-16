//
// generated automatically from "ISubSystem.h"
//
// implements COM-RPC proxy stubs for:
//   - class IMetadata
//   - class ISubSystem
//   - class ISubSystem::INotification
//   - class ISubSystem::ISecurity
//   - class ISubSystem::IInternet
//   - class ISubSystem::ILocation
//   - class ISubSystem::IIdentifier
//   - class ISubSystem::ITime
//   - class ISubSystem::IProvisioning
//   - class ISubSystem::IDecryption
//

#include "Module.h"
#include "ISubSystem.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    using namespace PluginHost;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // IMetadata interface stub definitions
    //
    // Methods:
    //  (0) virtual string BuildTreeHash() const = 0
    //  (1) virtual uint8_t Major() const = 0
    //  (2) virtual uint8_t Minor() const = 0
    //  (3) virtual uint8_t Patch() const = 0
    //

    static ProxyStub::MethodHandler MetadataStubMethods[] = {
        // (0) virtual string BuildTreeHash() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->BuildTreeHash();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual uint8_t Major() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t result = implementation->Major();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint8_t>(result);
        },

        // (2) virtual uint8_t Minor() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t result = implementation->Minor();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint8_t>(result);
        },

        // (3) virtual uint8_t Patch() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t result = implementation->Patch();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint8_t>(result);
        }
        , nullptr
    }; // MetadataStubMethods

    //
    // ISubSystem interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(ISubSystem::INotification*) = 0
    //  (1) virtual void Unregister(ISubSystem::INotification*) = 0
    //  (2) virtual Core::hresult Set(const ISubSystem::subsystem, Core::IUnknown*) = 0
    //  (3) virtual const Core::IUnknown* Get(const ISubSystem::subsystem) const = 0
    //  (4) virtual bool IsActive(const ISubSystem::subsystem) const = 0
    //  (5) virtual string BuildTreeHash() const = 0
    //  (6) virtual string Version() const = 0
    //

    static ProxyStub::MethodHandler SubSystemStubMethods[] = {
        // (0) virtual void Register(ISubSystem::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem* implementation = reinterpret_cast<ISubSystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            ISubSystem::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            implementation->Register(_notification);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(ISubSystem::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem* implementation = reinterpret_cast<ISubSystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            ISubSystem::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            implementation->Unregister(_notification);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult Set(const ISubSystem::subsystem, Core::IUnknown*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem* implementation = reinterpret_cast<ISubSystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const ISubSystem::subsystem _type = reader.Number<ISubSystem::subsystem>();
            Core::instance_id _informationInstanceId__ = reader.Number<Core::instance_id>();

            Core::IUnknown* _information{};
            ProxyStub::UnknownProxy* _informationProxy__ = nullptr;
            if (_informationInstanceId__ != 0) {
                _informationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _informationInstanceId__, false, _information);
                ASSERT((_information != nullptr) && (_informationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Set(_type, _information);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_informationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_informationProxy__, message->Response());
            }
        },

        // (3) virtual const Core::IUnknown* Get(const ISubSystem::subsystem) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const ISubSystem::subsystem _type = reader.Number<ISubSystem::subsystem>();

            const Core::IUnknown* result = implementation->Get(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (4) virtual bool IsActive(const ISubSystem::subsystem) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const ISubSystem::subsystem _type = reader.Number<ISubSystem::subsystem>();

            bool result = implementation->IsActive(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (5) virtual string BuildTreeHash() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->BuildTreeHash();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (6) virtual string Version() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Version();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // SubSystemStubMethods

    //
    // ISubSystem::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Updated() = 0
    //

    static ProxyStub::MethodHandler SubSystemNotificationStubMethods[] = {
        // (0) virtual void Updated() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem::INotification* implementation = reinterpret_cast<ISubSystem::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Updated();
        }
        , nullptr
    }; // SubSystemNotificationStubMethods

    //
    // ISubSystem::ISecurity interface stub definitions
    //
    // Methods:
    //  (0) virtual string Callsign() const = 0
    //

    static ProxyStub::MethodHandler SubSystemSecurityStubMethods[] = {
        // (0) virtual string Callsign() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ISecurity* implementation = reinterpret_cast<const ISubSystem::ISecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Callsign();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // SubSystemSecurityStubMethods

    //
    // ISubSystem::IInternet interface stub definitions
    //
    // Methods:
    //  (0) virtual string PublicIPAddress() const = 0
    //  (1) virtual ISubSystem::IInternet::network_type NetworkType() const = 0
    //

    static ProxyStub::MethodHandler SubSystemInternetStubMethods[] = {
        // (0) virtual string PublicIPAddress() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IInternet* implementation = reinterpret_cast<const ISubSystem::IInternet*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->PublicIPAddress();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual ISubSystem::IInternet::network_type NetworkType() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IInternet* implementation = reinterpret_cast<const ISubSystem::IInternet*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            ISubSystem::IInternet::network_type result = implementation->NetworkType();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<ISubSystem::IInternet::network_type>(result);
        }
        , nullptr
    }; // SubSystemInternetStubMethods

    //
    // ISubSystem::ILocation interface stub definitions
    //
    // Methods:
    //  (0) virtual string TimeZone() const = 0
    //  (1) virtual string Country() const = 0
    //  (2) virtual string Region() const = 0
    //  (3) virtual string City() const = 0
    //  (4) virtual int32_t Latitude() const
    //  (5) virtual int32_t Longitude() const
    //

    static ProxyStub::MethodHandler SubSystemLocationStubMethods[] = {
        // (0) virtual string TimeZone() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->TimeZone();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual string Country() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Country();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string Region() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Region();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (3) virtual string City() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->City();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual int32_t Latitude() const
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t result = implementation->Latitude();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
        },

        // (5) virtual int32_t Longitude() const
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            int32_t result = implementation->Longitude();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<int32_t>(result);
        }
        , nullptr
    }; // SubSystemLocationStubMethods

    //
    // ISubSystem::IIdentifier interface stub definitions
    //
    // Methods:
    //  (0) virtual uint8_t Identifier(const uint8_t, uint8_t*) const = 0
    //  (1) virtual string Architecture() const = 0
    //  (2) virtual string Chipset() const = 0
    //  (3) virtual string FirmwareVersion() const = 0
    //

    static ProxyStub::MethodHandler SubSystemIdentifierStubMethods[] = {
        // (0) virtual uint8_t Identifier(const uint8_t, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _length = reader.Number<uint8_t>();

            uint8_t* _buffer{};

            if (_length != 0) {
                _buffer = static_cast<uint8_t*>(ALLOCA(_length * sizeof(uint8_t)));
                ASSERT(_buffer != nullptr);
            }

            uint8_t result = implementation->Identifier(_length, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Buffer<uint8_t>(result, _buffer);
        },

        // (1) virtual string Architecture() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Architecture();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string Chipset() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Chipset();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (3) virtual string FirmwareVersion() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->FirmwareVersion();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // SubSystemIdentifierStubMethods

    //
    // ISubSystem::ITime interface stub definitions
    //
    // Methods:
    //  (0) virtual uint64_t TimeSync() const = 0
    //

    static ProxyStub::MethodHandler SubSystemTimeStubMethods[] = {
        // (0) virtual uint64_t TimeSync() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::ITime* implementation = reinterpret_cast<const ISubSystem::ITime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t result = implementation->TimeSync();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(result);
        }
        , nullptr
    }; // SubSystemTimeStubMethods

    //
    // ISubSystem::IProvisioning interface stub definitions
    //
    // Methods:
    //  (0) virtual string Storage() const = 0
    //  (1) virtual bool Next(string&) = 0
    //  (2) virtual bool Previous(string&) = 0
    //  (3) virtual void Reset(const uint32_t) = 0
    //  (4) virtual bool IsValid() const = 0
    //  (5) virtual uint32_t Count() const = 0
    //  (6) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler SubSystemProvisioningStubMethods[] = {
        // (0) virtual string Storage() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Storage();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem::IProvisioning* implementation = reinterpret_cast<ISubSystem::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem::IProvisioning* implementation = reinterpret_cast<ISubSystem::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (3) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem::IProvisioning* implementation = reinterpret_cast<ISubSystem::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (4) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (5) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // SubSystemProvisioningStubMethods

    //
    // ISubSystem::IDecryption interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler SubSystemDecryptionStubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            ISubSystem::IDecryption* implementation = reinterpret_cast<ISubSystem::IDecryption*>(message->Parameters().Implementation());
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
            ISubSystem::IDecryption* implementation = reinterpret_cast<ISubSystem::IDecryption*>(message->Parameters().Implementation());
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
            ISubSystem::IDecryption* implementation = reinterpret_cast<ISubSystem::IDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IDecryption* implementation = reinterpret_cast<const ISubSystem::IDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IDecryption* implementation = reinterpret_cast<const ISubSystem::IDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const ISubSystem::IDecryption* implementation = reinterpret_cast<const ISubSystem::IDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // SubSystemDecryptionStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // IMetadata interface proxy definitions
    //
    // Methods:
    //  (0) virtual string BuildTreeHash() const = 0
    //  (1) virtual uint8_t Major() const = 0
    //  (2) virtual uint8_t Minor() const = 0
    //  (3) virtual uint8_t Patch() const = 0
    //

    class MetadataProxy final : public ProxyStub::UnknownProxyType<IMetadata> {
    public:
        MetadataProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string BuildTreeHash() const override
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

        uint8_t Major() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint8_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint8_t Minor() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint8_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint8_t Patch() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint8_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class MetadataProxy

    //
    // ISubSystem interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(ISubSystem::INotification*) = 0
    //  (1) virtual void Unregister(ISubSystem::INotification*) = 0
    //  (2) virtual Core::hresult Set(const ISubSystem::subsystem, Core::IUnknown*) = 0
    //  (3) virtual const Core::IUnknown* Get(const ISubSystem::subsystem) const = 0
    //  (4) virtual bool IsActive(const ISubSystem::subsystem) const = 0
    //  (5) virtual string BuildTreeHash() const = 0
    //  (6) virtual string Version() const = 0
    //

    class SubSystemProxy final : public ProxyStub::UnknownProxyType<ISubSystem> {
    public:
        SubSystemProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(ISubSystem::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(ISubSystem::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        Core::hresult Set(const ISubSystem::subsystem _type, Core::IUnknown* _information) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<ISubSystem::subsystem>(_type);
            writer.Number<Core::instance_id>(RPC::instance_cast(_information));

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

        const Core::IUnknown* Get(const ISubSystem::subsystem _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<ISubSystem::subsystem>(_type);

            const Core::IUnknown* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<const Core::IUnknown*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Core::IUnknown::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool IsActive(const ISubSystem::subsystem _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<ISubSystem::subsystem>(_type);

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

        string BuildTreeHash() const override
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

        string Version() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

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

    }; // class SubSystemProxy

    //
    // ISubSystem::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Updated() = 0
    //

    class SubSystemNotificationProxy final : public ProxyStub::UnknownProxyType<ISubSystem::INotification> {
    public:
        SubSystemNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Updated() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class SubSystemNotificationProxy

    //
    // ISubSystem::ISecurity interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Callsign() const = 0
    //

    class SubSystemSecurityProxy final : public ProxyStub::UnknownProxyType<ISubSystem::ISecurity> {
    public:
        SubSystemSecurityProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string Callsign() const override
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

    }; // class SubSystemSecurityProxy

    //
    // ISubSystem::IInternet interface proxy definitions
    //
    // Methods:
    //  (0) virtual string PublicIPAddress() const = 0
    //  (1) virtual ISubSystem::IInternet::network_type NetworkType() const = 0
    //

    class SubSystemInternetProxy final : public ProxyStub::UnknownProxyType<ISubSystem::IInternet> {
    public:
        SubSystemInternetProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string PublicIPAddress() const override
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

        ISubSystem::IInternet::network_type NetworkType() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            ISubSystem::IInternet::network_type result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<ISubSystem::IInternet::network_type>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class SubSystemInternetProxy

    //
    // ISubSystem::ILocation interface proxy definitions
    //
    // Methods:
    //  (0) virtual string TimeZone() const = 0
    //  (1) virtual string Country() const = 0
    //  (2) virtual string Region() const = 0
    //  (3) virtual string City() const = 0
    //  (4) virtual int32_t Latitude() const
    //  (5) virtual int32_t Longitude() const
    //

    class SubSystemLocationProxy final : public ProxyStub::UnknownProxyType<ISubSystem::ILocation> {
    public:
        SubSystemLocationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string TimeZone() const override
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

        string Country() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        string Region() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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

        string City() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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

        int32_t Latitude() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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

        int32_t Longitude() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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

    }; // class SubSystemLocationProxy

    //
    // ISubSystem::IIdentifier interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint8_t Identifier(const uint8_t, uint8_t*) const = 0
    //  (1) virtual string Architecture() const = 0
    //  (2) virtual string Chipset() const = 0
    //  (3) virtual string FirmwareVersion() const = 0
    //

    class SubSystemIdentifierProxy final : public ProxyStub::UnknownProxyType<ISubSystem::IIdentifier> {
    public:
        SubSystemIdentifierProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint8_t Identifier(const uint8_t _length, uint8_t* _buffer) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_length);

            uint8_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Buffer<uint8_t>(_length, _buffer);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Architecture() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        string Chipset() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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

        string FirmwareVersion() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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

    }; // class SubSystemIdentifierProxy

    //
    // ISubSystem::ITime interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint64_t TimeSync() const = 0
    //

    class SubSystemTimeProxy final : public ProxyStub::UnknownProxyType<ISubSystem::ITime> {
    public:
        SubSystemTimeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint64_t TimeSync() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

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

    }; // class SubSystemTimeProxy

    //
    // ISubSystem::IProvisioning interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Storage() const = 0
    //  (1) virtual bool Next(string&) = 0
    //  (2) virtual bool Previous(string&) = 0
    //  (3) virtual void Reset(const uint32_t) = 0
    //  (4) virtual bool IsValid() const = 0
    //  (5) virtual uint32_t Count() const = 0
    //  (6) virtual string Current() const = 0
    //

    class SubSystemProvisioningProxy final : public ProxyStub::UnknownProxyType<ISubSystem::IProvisioning> {
    public:
        SubSystemProvisioningProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string Storage() const override
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

        bool Next(string& _info) override
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

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

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
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

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

    }; // class SubSystemProvisioningProxy

    //
    // ISubSystem::IDecryption interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class SubSystemDecryptionProxy final : public ProxyStub::UnknownProxyType<ISubSystem::IDecryption> {
    public:
        SubSystemDecryptionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class SubSystemDecryptionProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<IMetadata, MetadataStubMethods> MetadataStub;
        typedef ProxyStub::UnknownStubType<ISubSystem, SubSystemStubMethods> SubSystemStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::INotification, SubSystemNotificationStubMethods> SubSystemNotificationStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::ISecurity, SubSystemSecurityStubMethods> SubSystemSecurityStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::IInternet, SubSystemInternetStubMethods> SubSystemInternetStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::ILocation, SubSystemLocationStubMethods> SubSystemLocationStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::IIdentifier, SubSystemIdentifierStubMethods> SubSystemIdentifierStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::ITime, SubSystemTimeStubMethods> SubSystemTimeStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::IProvisioning, SubSystemProvisioningStubMethods> SubSystemProvisioningStub;
        typedef ProxyStub::UnknownStubType<ISubSystem::IDecryption, SubSystemDecryptionStubMethods> SubSystemDecryptionStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IMetadata, MetadataProxy, MetadataStub>();
                RPC::Administrator::Instance().Announce<ISubSystem, SubSystemProxy, SubSystemStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::INotification, SubSystemNotificationProxy, SubSystemNotificationStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::ISecurity, SubSystemSecurityProxy, SubSystemSecurityStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::IInternet, SubSystemInternetProxy, SubSystemInternetStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::ILocation, SubSystemLocationProxy, SubSystemLocationStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::IIdentifier, SubSystemIdentifierProxy, SubSystemIdentifierStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::ITime, SubSystemTimeProxy, SubSystemTimeStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::IProvisioning, SubSystemProvisioningProxy, SubSystemProvisioningStub>();
                RPC::Administrator::Instance().Announce<ISubSystem::IDecryption, SubSystemDecryptionProxy, SubSystemDecryptionStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IMetadata>();
                RPC::Administrator::Instance().Recall<ISubSystem>();
                RPC::Administrator::Instance().Recall<ISubSystem::INotification>();
                RPC::Administrator::Instance().Recall<ISubSystem::ISecurity>();
                RPC::Administrator::Instance().Recall<ISubSystem::IInternet>();
                RPC::Administrator::Instance().Recall<ISubSystem::ILocation>();
                RPC::Administrator::Instance().Recall<ISubSystem::IIdentifier>();
                RPC::Administrator::Instance().Recall<ISubSystem::ITime>();
                RPC::Administrator::Instance().Recall<ISubSystem::IProvisioning>();
                RPC::Administrator::Instance().Recall<ISubSystem::IDecryption>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
