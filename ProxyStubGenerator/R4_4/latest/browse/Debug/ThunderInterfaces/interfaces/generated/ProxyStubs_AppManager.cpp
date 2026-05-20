//
// generated automatically from "IAppManager.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR]
//   - class Exchange::IAppManager
//   - class Exchange::IAppManager::INotification
//

#include "Module.h"
#include "IAppManager.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance3E73C254 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    ProxyStub::MethodHandler RPCIteratorTypeInstance3E73C254StubMethods[] = {
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
    }; // RPCIteratorTypeInstance3E73C254StubMethods

    //
    // Exchange::IAppManager interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IAppManager::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IAppManager::INotification*) = 0
    //  (2) virtual uint32_t GetLaunchableApps(Exchange::IAppManager::IStringIterator*&) = 0
    //  (3) virtual uint32_t GetLoadedApps(Exchange::IAppManager::IStringIterator*&) = 0
    //  (4) virtual uint32_t LaunchApp(const string&, const string&, const string&) = 0
    //  (5) virtual uint32_t LoadApp(const string&, const string&, const string&) = 0
    //  (6) virtual uint32_t PrepareApp(const string&) = 0
    //  (7) virtual uint32_t SendMessage(const string&, const string&) = 0
    //  (8) virtual uint32_t CloseApp(const string&) = 0
    //  (9) virtual uint32_t TerminateApp(const string&) = 0
    //  (10) virtual uint32_t ClearAppData(const string&) = 0
    //  (11) virtual uint32_t SetAppFocus(const string&) = 0
    //  (12) virtual uint32_t GetAppMetaData(const string&, const string&) = 0
    //  (13) virtual uint32_t GetAppProperty(const string&, const string&) = 0
    //  (14) virtual uint32_t SetAppProperty(const string&, const string&, const string&) = 0
    //  (15) virtual uint32_t SetMaxInactiveApps(const uint32_t) = 0
    //  (16) virtual uint32_t GetMaxInactiveApps(uint32_t&) const = 0
    //  (17) virtual uint32_t SetMaxHibernatedApps(const uint32_t) = 0
    //  (18) virtual uint32_t GetMaxHibernatedApps(uint32_t&) const = 0
    //  (19) virtual uint32_t SetMaxHibernatedFlashUsage(const uint32_t) = 0
    //  (20) virtual uint32_t GetMaxHibernatedFlashUsage(uint32_t&) const = 0
    //  (21) virtual uint32_t SetMaxInactiveRamUsage(const uint32_t) = 0
    //  (22) virtual uint32_t GetMaxInactiveRamUsage(uint32_t&) const = 0
    //

    ProxyStub::MethodHandler ExchangeAppManagerStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IAppManager::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IAppManager::INotification* _notification = nullptr;
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

        // (1) virtual uint32_t Unregister(Exchange::IAppManager::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IAppManager::INotification* _notification = nullptr;
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

        // (2) virtual uint32_t GetLaunchableApps(Exchange::IAppManager::IStringIterator*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IAppManager::IStringIterator* _result{};

            uint32_t result = implementation->GetLaunchableApps(_result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_result));

            RPC::Administrator::Instance().RegisterInterface(channel, _result);
        },

        // (3) virtual uint32_t GetLoadedApps(Exchange::IAppManager::IStringIterator*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IAppManager::IStringIterator* _result{};

            uint32_t result = implementation->GetLoadedApps(_result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_result));

            RPC::Administrator::Instance().RegisterInterface(channel, _result);
        },

        // (4) virtual uint32_t LaunchApp(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _intent = reader.Text();
            const string _launchArgs = reader.Text();

            uint32_t result = implementation->LaunchApp(static_cast<const string&>(_appId), static_cast<const string&>(_intent), static_cast<const string&>(_launchArgs));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t LoadApp(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _intent = reader.Text();
            const string _launchArgs = reader.Text();

            uint32_t result = implementation->LoadApp(static_cast<const string&>(_appId), static_cast<const string&>(_intent), static_cast<const string&>(_launchArgs));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t PrepareApp(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();

            uint32_t result = implementation->PrepareApp(static_cast<const string&>(_appId));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t SendMessage(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _messagae = reader.Text();

            uint32_t result = implementation->SendMessage(static_cast<const string&>(_appId), static_cast<const string&>(_messagae));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (8) virtual uint32_t CloseApp(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();

            uint32_t result = implementation->CloseApp(static_cast<const string&>(_appId));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t TerminateApp(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();

            uint32_t result = implementation->TerminateApp(static_cast<const string&>(_appId));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (10) virtual uint32_t ClearAppData(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();

            uint32_t result = implementation->ClearAppData(static_cast<const string&>(_appId));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (11) virtual uint32_t SetAppFocus(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();

            uint32_t result = implementation->SetAppFocus(static_cast<const string&>(_appId));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (12) virtual uint32_t GetAppMetaData(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _key = reader.Text();

            uint32_t result = implementation->GetAppMetaData(static_cast<const string&>(_appId), static_cast<const string&>(_key));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (13) virtual uint32_t GetAppProperty(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _key = reader.Text();

            uint32_t result = implementation->GetAppProperty(static_cast<const string&>(_appId), static_cast<const string&>(_key));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (14) virtual uint32_t SetAppProperty(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _key = reader.Text();
            const string _value = reader.Text();

            uint32_t result = implementation->SetAppProperty(static_cast<const string&>(_appId), static_cast<const string&>(_key), static_cast<const string&>(_value));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (15) virtual uint32_t SetMaxInactiveApps(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _maxInteractiveApps = reader.Number<uint32_t>();

            uint32_t result = implementation->SetMaxInactiveApps(_maxInteractiveApps);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (16) virtual uint32_t GetMaxInactiveApps(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAppManager* implementation = reinterpret_cast<const Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _maxInteractiveApps{};

            uint32_t result = implementation->GetMaxInactiveApps(_maxInteractiveApps);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_maxInteractiveApps);
        },

        // (17) virtual uint32_t SetMaxHibernatedApps(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _maxHibernatedApps = reader.Number<uint32_t>();

            uint32_t result = implementation->SetMaxHibernatedApps(_maxHibernatedApps);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (18) virtual uint32_t GetMaxHibernatedApps(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAppManager* implementation = reinterpret_cast<const Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _maxHibernatedApps{};

            uint32_t result = implementation->GetMaxHibernatedApps(_maxHibernatedApps);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_maxHibernatedApps);
        },

        // (19) virtual uint32_t SetMaxHibernatedFlashUsage(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _maxHibernatedFlashUsage = reader.Number<uint32_t>();

            uint32_t result = implementation->SetMaxHibernatedFlashUsage(_maxHibernatedFlashUsage);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (20) virtual uint32_t GetMaxHibernatedFlashUsage(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAppManager* implementation = reinterpret_cast<const Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _maxHibernatedFlashUsage{};

            uint32_t result = implementation->GetMaxHibernatedFlashUsage(_maxHibernatedFlashUsage);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_maxHibernatedFlashUsage);
        },

        // (21) virtual uint32_t SetMaxInactiveRamUsage(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager* implementation = reinterpret_cast<Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _maxInactiveRamUsage = reader.Number<uint32_t>();

            uint32_t result = implementation->SetMaxInactiveRamUsage(_maxInactiveRamUsage);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (22) virtual uint32_t GetMaxInactiveRamUsage(uint32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAppManager* implementation = reinterpret_cast<const Exchange::IAppManager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t _maxInactiveRamUsage{};

            uint32_t result = implementation->GetMaxInactiveRamUsage(_maxInactiveRamUsage);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_maxInactiveRamUsage);
        }
        , nullptr
    }; // ExchangeAppManagerStubMethods

    //
    // Exchange::IAppManager::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void OnAppInstalled(const string&, const string&) = 0
    //  (1) virtual void OnAppUninstalled(const string&) = 0
    //  (2) virtual void OnAppStateChanged(const string&, const string&) = 0
    //  (3) virtual void OnAppLaunchRequest(const string&, const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeAppManagerNotificationStubMethods[] = {
        // (0) virtual void OnAppInstalled(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager::INotification* implementation = reinterpret_cast<Exchange::IAppManager::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _version = reader.Text();

            implementation->OnAppInstalled(static_cast<const string&>(_appId), static_cast<const string&>(_version));
        },

        // (1) virtual void OnAppUninstalled(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager::INotification* implementation = reinterpret_cast<Exchange::IAppManager::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();

            implementation->OnAppUninstalled(static_cast<const string&>(_appId));
        },

        // (2) virtual void OnAppStateChanged(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager::INotification* implementation = reinterpret_cast<Exchange::IAppManager::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _state = reader.Text();

            implementation->OnAppStateChanged(static_cast<const string&>(_appId), static_cast<const string&>(_state));
        },

        // (3) virtual void OnAppLaunchRequest(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAppManager::INotification* implementation = reinterpret_cast<Exchange::IAppManager::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _appId = reader.Text();
            const string _intent = reader.Text();
            const string _source = reader.Text();

            implementation->OnAppLaunchRequest(static_cast<const string&>(_appId), static_cast<const string&>(_intent), static_cast<const string&>(_source));
        }
        , nullptr
    }; // ExchangeAppManagerNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance3E73C254 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance3E73C254Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance3E73C254Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class RPCIteratorTypeInstance3E73C254Proxy

    //
    // Exchange::IAppManager interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IAppManager::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IAppManager::INotification*) = 0
    //  (2) virtual uint32_t GetLaunchableApps(Exchange::IAppManager::IStringIterator*&) = 0
    //  (3) virtual uint32_t GetLoadedApps(Exchange::IAppManager::IStringIterator*&) = 0
    //  (4) virtual uint32_t LaunchApp(const string&, const string&, const string&) = 0
    //  (5) virtual uint32_t LoadApp(const string&, const string&, const string&) = 0
    //  (6) virtual uint32_t PrepareApp(const string&) = 0
    //  (7) virtual uint32_t SendMessage(const string&, const string&) = 0
    //  (8) virtual uint32_t CloseApp(const string&) = 0
    //  (9) virtual uint32_t TerminateApp(const string&) = 0
    //  (10) virtual uint32_t ClearAppData(const string&) = 0
    //  (11) virtual uint32_t SetAppFocus(const string&) = 0
    //  (12) virtual uint32_t GetAppMetaData(const string&, const string&) = 0
    //  (13) virtual uint32_t GetAppProperty(const string&, const string&) = 0
    //  (14) virtual uint32_t SetAppProperty(const string&, const string&, const string&) = 0
    //  (15) virtual uint32_t SetMaxInactiveApps(const uint32_t) = 0
    //  (16) virtual uint32_t GetMaxInactiveApps(uint32_t&) const = 0
    //  (17) virtual uint32_t SetMaxHibernatedApps(const uint32_t) = 0
    //  (18) virtual uint32_t GetMaxHibernatedApps(uint32_t&) const = 0
    //  (19) virtual uint32_t SetMaxHibernatedFlashUsage(const uint32_t) = 0
    //  (20) virtual uint32_t GetMaxHibernatedFlashUsage(uint32_t&) const = 0
    //  (21) virtual uint32_t SetMaxInactiveRamUsage(const uint32_t) = 0
    //  (22) virtual uint32_t GetMaxInactiveRamUsage(uint32_t&) const = 0
    //

    class ExchangeAppManagerProxy final : public ProxyStub::UnknownProxyType<Exchange::IAppManager> {
    public:
        ExchangeAppManagerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Register(Exchange::IAppManager::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(0));

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

        uint32_t Unregister(Exchange::IAppManager::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(1));

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

        uint32_t GetLaunchableApps(Exchange::IAppManager::IStringIterator*& _result) override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _result = reinterpret_cast<Exchange::IAppManager::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IAppManager::IStringIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetLoadedApps(Exchange::IAppManager::IStringIterator*& _result) override
        {
            IPCMessage message(BaseClass::Message(3));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _result = reinterpret_cast<Exchange::IAppManager::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), Exchange::IAppManager::IStringIterator::ID));
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t LaunchApp(const string& _appId, const string& _intent, const string& _launchArgs) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
            writer.Text(static_cast<const string&>(_intent));
            writer.Text(static_cast<const string&>(_launchArgs));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t LoadApp(const string& _appId, const string& _intent, const string& _launchArgs) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
            writer.Text(static_cast<const string&>(_intent));
            writer.Text(static_cast<const string&>(_launchArgs));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t PrepareApp(const string& _appId) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SendMessage(const string& _appId, const string& _messagae) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
            writer.Text(static_cast<const string&>(_messagae));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t CloseApp(const string& _appId) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t TerminateApp(const string& _appId) override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t ClearAppData(const string& _appId) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetAppFocus(const string& _appId) override
        {
            IPCMessage message(BaseClass::Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetAppMetaData(const string& _appId, const string& _key) override
        {
            IPCMessage message(BaseClass::Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
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

        uint32_t GetAppProperty(const string& _appId, const string& _key) override
        {
            IPCMessage message(BaseClass::Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
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

        uint32_t SetAppProperty(const string& _appId, const string& _key, const string& _value) override
        {
            IPCMessage message(BaseClass::Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
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

        uint32_t SetMaxInactiveApps(const uint32_t _maxInteractiveApps) override
        {
            IPCMessage message(BaseClass::Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_maxInteractiveApps);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetMaxInactiveApps(uint32_t& _maxInteractiveApps) const override
        {
            IPCMessage message(BaseClass::Message(16));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _maxInteractiveApps = reader.Number<uint32_t>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetMaxHibernatedApps(const uint32_t _maxHibernatedApps) override
        {
            IPCMessage message(BaseClass::Message(17));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_maxHibernatedApps);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetMaxHibernatedApps(uint32_t& _maxHibernatedApps) const override
        {
            IPCMessage message(BaseClass::Message(18));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _maxHibernatedApps = reader.Number<uint32_t>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetMaxHibernatedFlashUsage(const uint32_t _maxHibernatedFlashUsage) override
        {
            IPCMessage message(BaseClass::Message(19));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_maxHibernatedFlashUsage);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetMaxHibernatedFlashUsage(uint32_t& _maxHibernatedFlashUsage) const override
        {
            IPCMessage message(BaseClass::Message(20));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _maxHibernatedFlashUsage = reader.Number<uint32_t>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetMaxInactiveRamUsage(const uint32_t _maxInactiveRamUsage) override
        {
            IPCMessage message(BaseClass::Message(21));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_maxInactiveRamUsage);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetMaxInactiveRamUsage(uint32_t& _maxInactiveRamUsage) const override
        {
            IPCMessage message(BaseClass::Message(22));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _maxInactiveRamUsage = reader.Number<uint32_t>();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeAppManagerProxy

    //
    // Exchange::IAppManager::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OnAppInstalled(const string&, const string&) = 0
    //  (1) virtual void OnAppUninstalled(const string&) = 0
    //  (2) virtual void OnAppStateChanged(const string&, const string&) = 0
    //  (3) virtual void OnAppLaunchRequest(const string&, const string&, const string&) = 0
    //

    class ExchangeAppManagerNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IAppManager::INotification> {
    public:
        ExchangeAppManagerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void OnAppInstalled(const string& _appId, const string& _version) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
            writer.Text(static_cast<const string&>(_version));

            UnknownProxyType::Invoke(message);
        }

        void OnAppUninstalled(const string& _appId) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));

            UnknownProxyType::Invoke(message);
        }

        void OnAppStateChanged(const string& _appId, const string& _state) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
            writer.Text(static_cast<const string&>(_state));

            UnknownProxyType::Invoke(message);
        }

        void OnAppLaunchRequest(const string& _appId, const string& _intent, const string& _source) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_appId));
            writer.Text(static_cast<const string&>(_intent));
            writer.Text(static_cast<const string&>(_source));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeAppManagerNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance3E73C254StubMethods> RPCIteratorTypeInstance3E73C254Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IAppManager, ExchangeAppManagerStubMethods> ExchangeAppManagerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAppManager::INotification, ExchangeAppManagerNotificationStubMethods> ExchangeAppManagerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance3E73C254Proxy, RPCIteratorTypeInstance3E73C254Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IAppManager, ExchangeAppManagerProxy, ExchangeAppManagerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IAppManager::INotification, ExchangeAppManagerNotificationProxy, ExchangeAppManagerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IAppManager>();
                RPC::Administrator::Instance().Recall<Exchange::IAppManager::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
