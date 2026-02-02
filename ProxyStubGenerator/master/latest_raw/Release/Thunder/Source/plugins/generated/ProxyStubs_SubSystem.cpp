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
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->BuildTreeHash();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual uint8_t Major() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint8_t result = implementation->Major();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint8_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual uint8_t Minor() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint8_t result = implementation->Minor();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint8_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual uint8_t Patch() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const IMetadata* implementation = reinterpret_cast<const IMetadata*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IMetadata::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint8_t result = implementation->Patch();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint8_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem* implementation = reinterpret_cast<ISubSystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                ISubSystem::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->Register(_notification);

                if (_notificationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual void Unregister(ISubSystem::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem* implementation = reinterpret_cast<ISubSystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

                ISubSystem::INotification* _notification{};
                ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
                if (_notificationInstanceId__ != 0) {
                    _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                    ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
                    if ((_notification == nullptr) || (_notificationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->Unregister(_notification);

                if (_notificationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual Core::hresult Set(const ISubSystem::subsystem, Core::IUnknown*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem* implementation = reinterpret_cast<ISubSystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<ISubSystem::subsystem>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const ISubSystem::subsystem _type = reader.Number<ISubSystem::subsystem>();
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _informationInstanceId__ = reader.Number<Core::instance_id>();

                Core::IUnknown* _information{};
                ProxyStub::UnknownProxy* _informationProxy__ = nullptr;
                if (_informationInstanceId__ != 0) {
                    _informationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _informationInstanceId__, false, _information);
                    ASSERT((_information != nullptr) && (_informationProxy__ != nullptr));
                    if ((_information == nullptr) || (_informationProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Set(_type, _information);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_informationProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_informationProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 2, hresult);
            }
        },

        // (3) virtual const Core::IUnknown* Get(const ISubSystem::subsystem) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<ISubSystem::subsystem>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const ISubSystem::subsystem _type = reader.Number<ISubSystem::subsystem>();

                const Core::IUnknown* result = implementation->Get(_type);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::instance_id>(RPC::instance_cast(result));

                RPC::Administrator::Instance().RegisterInterface(channel, result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual bool IsActive(const ISubSystem::subsystem) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<ISubSystem::subsystem>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const ISubSystem::subsystem _type = reader.Number<ISubSystem::subsystem>();

                bool result = implementation->IsActive(_type);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual string BuildTreeHash() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->BuildTreeHash();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (6) virtual string Version() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem* implementation = reinterpret_cast<const ISubSystem*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Version();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem::INotification* implementation = reinterpret_cast<ISubSystem::INotification*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::INotification::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                implementation->Updated();

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ISecurity* implementation = reinterpret_cast<const ISubSystem::ISecurity*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ISecurity::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Callsign();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ISecurity::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IInternet* implementation = reinterpret_cast<const ISubSystem::IInternet*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IInternet::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->PublicIPAddress();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IInternet::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual ISubSystem::IInternet::network_type NetworkType() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IInternet* implementation = reinterpret_cast<const ISubSystem::IInternet*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IInternet::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                ISubSystem::IInternet::network_type result = implementation->NetworkType();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<ISubSystem::IInternet::network_type>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IInternet::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ILocation::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->TimeZone();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual string Country() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ILocation::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Country();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual string Region() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ILocation::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Region();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual string City() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ILocation::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->City();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual int32_t Latitude() const
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ILocation::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                int32_t result = implementation->Latitude();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<int32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual int32_t Longitude() const
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ILocation* implementation = reinterpret_cast<const ISubSystem::ILocation*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ILocation::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                int32_t result = implementation->Longitude();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<int32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IIdentifier::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _length = reader.Number<uint8_t>();

                uint8_t* _buffer{};

                if (_length != 0) {
                    _buffer = static_cast<uint8_t*>(ALLOCA(_length * sizeof(uint8_t)));
                    ASSERT(_buffer != nullptr);
                    if (_buffer == nullptr) { return (Core::ERROR_GENERAL); }
                }

                uint8_t result = implementation->Identifier(_length, _buffer);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Buffer<uint8_t>(result, _buffer);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual string Architecture() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IIdentifier::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Architecture();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual string Chipset() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IIdentifier::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Chipset();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual string FirmwareVersion() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IIdentifier* implementation = reinterpret_cast<const ISubSystem::IIdentifier*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IIdentifier::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->FirmwareVersion();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::ITime* implementation = reinterpret_cast<const ISubSystem::ITime*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::ITime::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint64_t result = implementation->TimeSync();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint64_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ITime::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IProvisioning::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Storage();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem::IProvisioning* implementation = reinterpret_cast<ISubSystem::IProvisioning*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IProvisioning::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem::IProvisioning* implementation = reinterpret_cast<ISubSystem::IProvisioning*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IProvisioning::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem::IProvisioning* implementation = reinterpret_cast<ISubSystem::IProvisioning*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IProvisioning::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IProvisioning::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IProvisioning::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (6) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IProvisioning* implementation = reinterpret_cast<const ISubSystem::IProvisioning*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IProvisioning::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem::IDecryption* implementation = reinterpret_cast<ISubSystem::IDecryption*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IDecryption::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _info{};

                bool result = implementation->Next(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem::IDecryption* implementation = reinterpret_cast<ISubSystem::IDecryption*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IDecryption::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string _info{};

                bool result = implementation->Previous(_info);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);
                writer.Text(_info);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                ISubSystem::IDecryption* implementation = reinterpret_cast<ISubSystem::IDecryption*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IDecryption::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _position = reader.Number<uint32_t>();

                implementation->Reset(_position);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IDecryption* implementation = reinterpret_cast<const ISubSystem::IDecryption*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IDecryption::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                bool result = implementation->IsValid();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Boolean(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IDecryption* implementation = reinterpret_cast<const ISubSystem::IDecryption*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IDecryption::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                uint32_t result = implementation->Count();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                const ISubSystem::IDecryption* implementation = reinterpret_cast<const ISubSystem::IDecryption*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), ISubSystem::IDecryption::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                string result = implementation->Current();

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Text(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint8_t Major() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            uint8_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint8_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint8_t Minor() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint8_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint8_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint8_t Patch() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            uint8_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint8_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IMetadata::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), ISubSystem::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
        }

        void Unregister(ISubSystem::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_notification), ISubSystem::INotification::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
        }

        Core::hresult Set(const ISubSystem::subsystem _type, Core::IUnknown* _information) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<ISubSystem::subsystem>(_type);
            writer.Number<Core::instance_id>(RPC::instance_cast(_information));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_information), Core::IUnknown::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 2, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        const Core::IUnknown* Get(const ISubSystem::subsystem _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<ISubSystem::subsystem>(_type);

            const Core::IUnknown* result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    result = reinterpret_cast<const Core::IUnknown*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Core::IUnknown::ID));

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool IsActive(const ISubSystem::subsystem _type) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<ISubSystem::subsystem>(_type);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string BuildTreeHash() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Version() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::INotification::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ISecurity::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IInternet::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        ISubSystem::IInternet::network_type NetworkType() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            ISubSystem::IInternet::network_type result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<ISubSystem::IInternet::network_type>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<ISubSystem::IInternet::network_type>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IInternet::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Country() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Region() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string City() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        int32_t Latitude() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            int32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<int32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<int32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        int32_t Longitude() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            int32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<int32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<int32_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ILocation::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint8_t _bufferPeekedLen__ = reader.PeekNumber<uint8_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint8_t>()) + _bufferPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Buffer<uint8_t>(_length, _buffer);

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Architecture() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Chipset() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string FirmwareVersion() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IIdentifier::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint64_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint64_t>();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::ITime::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Next(string& _info) override
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
                    const uint16_t _infoPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _infoPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 1, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            bool result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _infoPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _infoPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 2, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 3, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IProvisioning::ID, 6, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Boolean();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _infoPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _infoPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        bool Previous(string& _info) override
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
                    const uint16_t _infoPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _infoPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _info = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 1, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 2, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 3, hresult);
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 4, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            string result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t resultPeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + resultPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", ISubSystem::IDecryption::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<IMetadata, MetadataProxy, MetadataStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem, SubSystemProxy, SubSystemStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::INotification, SubSystemNotificationProxy, SubSystemNotificationStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::ISecurity, SubSystemSecurityProxy, SubSystemSecurityStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::IInternet, SubSystemInternetProxy, SubSystemInternetStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::ILocation, SubSystemLocationProxy, SubSystemLocationStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::IIdentifier, SubSystemIdentifierProxy, SubSystemIdentifierStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::ITime, SubSystemTimeProxy, SubSystemTimeStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::IProvisioning, SubSystemProvisioningProxy, SubSystemProvisioningStub>(security);
                RPC::Administrator::Instance().Announce<ISubSystem::IDecryption, SubSystemDecryptionProxy, SubSystemDecryptionStub>(security);
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
