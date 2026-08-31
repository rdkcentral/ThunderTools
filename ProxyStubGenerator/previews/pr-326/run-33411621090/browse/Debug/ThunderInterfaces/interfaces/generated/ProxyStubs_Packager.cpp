//
// generated automatically from "IPackager.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IPackager
//   - class Exchange::IPackager::IInstallationInfo
//   - class Exchange::IPackager::IPackageInfo
//   - class Exchange::IPackager::INotification
//

#include "Module.h"
#include "IPackager.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IPackager interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IPackager::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IPackager::INotification*) = 0
    //  (2) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (3) virtual uint32_t Install(const string&, const string&, const string&) = 0
    //  (4) virtual uint32_t SynchronizeRepository() = 0
    //

    static ProxyStub::MethodHandler ExchangePackagerStubMethods[] = {
        // (0) virtual void Register(Exchange::IPackager::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager* implementation = reinterpret_cast<Exchange::IPackager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _observerInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IPackager::INotification* _observer{};
            ProxyStub::UnknownProxy* _observerProxy__ = nullptr;
            if (_observerInstanceId__ != 0) {
                _observerProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _observerInstanceId__, false, _observer);
                ASSERT((_observer != nullptr) && (_observerProxy__ != nullptr));
            }

            implementation->Register(_observer);

            if (_observerProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_observerProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(const Exchange::IPackager::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager* implementation = reinterpret_cast<Exchange::IPackager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _observerInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IPackager::INotification* _observer{};
            ProxyStub::UnknownProxy* _observerProxy__ = nullptr;
            if (_observerInstanceId__ != 0) {
                _observerProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _observerInstanceId__, false, _observer);
                ASSERT((_observer != nullptr) && (_observerProxy__ != nullptr));
            }

            implementation->Unregister(_observer);

            if (_observerProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_observerProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager* implementation = reinterpret_cast<Exchange::IPackager*>(message->Parameters().Implementation());
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
        },

        // (3) virtual uint32_t Install(const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager* implementation = reinterpret_cast<Exchange::IPackager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();
            const string _version = reader.Text();
            const string _arch = reader.Text();

            uint32_t result = implementation->Install(static_cast<const string&>(_name), static_cast<const string&>(_version), static_cast<const string&>(_arch));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t SynchronizeRepository() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager* implementation = reinterpret_cast<Exchange::IPackager*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->SynchronizeRepository();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangePackagerStubMethods

    //
    // Exchange::IPackager::IInstallationInfo interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IPackager::state State() const = 0
    //  (1) virtual uint8_t Progress() const = 0
    //  (2) virtual string AppName() const = 0
    //  (3) virtual uint32_t ErrorCode() const = 0
    //  (4) virtual uint32_t Abort() = 0
    //

    static ProxyStub::MethodHandler ExchangePackagerInstallationInfoStubMethods[] = {
        // (0) virtual Exchange::IPackager::state State() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackager::IInstallationInfo* implementation = reinterpret_cast<const Exchange::IPackager::IInstallationInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IPackager::state result = implementation->State();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IPackager::state>(result);
        },

        // (1) virtual uint8_t Progress() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackager::IInstallationInfo* implementation = reinterpret_cast<const Exchange::IPackager::IInstallationInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t result = implementation->Progress();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint8_t>(result);
        },

        // (2) virtual string AppName() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackager::IInstallationInfo* implementation = reinterpret_cast<const Exchange::IPackager::IInstallationInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->AppName();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (3) virtual uint32_t ErrorCode() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackager::IInstallationInfo* implementation = reinterpret_cast<const Exchange::IPackager::IInstallationInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->ErrorCode();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t Abort() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager::IInstallationInfo* implementation = reinterpret_cast<Exchange::IPackager::IInstallationInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Abort();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangePackagerInstallationInfoStubMethods

    //
    // Exchange::IPackager::IPackageInfo interface stub definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual string Version() const = 0
    //  (2) virtual string Architecture() const = 0
    //

    static ProxyStub::MethodHandler ExchangePackagerPackageInfoStubMethods[] = {
        // (0) virtual string Name() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackager::IPackageInfo* implementation = reinterpret_cast<const Exchange::IPackager::IPackageInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Name();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (1) virtual string Version() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackager::IPackageInfo* implementation = reinterpret_cast<const Exchange::IPackager::IPackageInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Version();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string Architecture() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IPackager::IPackageInfo* implementation = reinterpret_cast<const Exchange::IPackager::IPackageInfo*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Architecture();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // ExchangePackagerPackageInfoStubMethods

    //
    // Exchange::IPackager::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChange(Exchange::IPackager::IPackageInfo*, Exchange::IPackager::IInstallationInfo*) = 0
    //  (1) virtual void RepositorySynchronize(uint32_t) = 0
    //

    static ProxyStub::MethodHandler ExchangePackagerNotificationStubMethods[] = {
        // (0) virtual void StateChange(Exchange::IPackager::IPackageInfo*, Exchange::IPackager::IInstallationInfo*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager::INotification* implementation = reinterpret_cast<Exchange::IPackager::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _packageInstanceId__ = reader.Number<Core::instance_id>();
            Core::instance_id _installInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IPackager::IPackageInfo* _package{};
            ProxyStub::UnknownProxy* _packageProxy__ = nullptr;
            if (_packageInstanceId__ != 0) {
                _packageProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _packageInstanceId__, false, _package);
                ASSERT((_package != nullptr) && (_packageProxy__ != nullptr));
            }
            Exchange::IPackager::IInstallationInfo* _install{};
            ProxyStub::UnknownProxy* _installProxy__ = nullptr;
            if (_installInstanceId__ != 0) {
                _installProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _installInstanceId__, false, _install);
                ASSERT((_install != nullptr) && (_installProxy__ != nullptr));
            }

            implementation->StateChange(_package, _install);

            if (_packageProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_packageProxy__, message->Response());
            }
            if (_installProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_installProxy__, message->Response());
            }
        },

        // (1) virtual void RepositorySynchronize(uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPackager::INotification* implementation = reinterpret_cast<Exchange::IPackager::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint32_t _status = reader.Number<uint32_t>();

            implementation->RepositorySynchronize(_status);
        }
        , nullptr
    }; // ExchangePackagerNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IPackager interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IPackager::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IPackager::INotification*) = 0
    //  (2) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (3) virtual uint32_t Install(const string&, const string&, const string&) = 0
    //  (4) virtual uint32_t SynchronizeRepository() = 0
    //

    class ExchangePackagerProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackager> {
    public:
        ExchangePackagerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::IPackager::INotification* _observer) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_observer));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(const Exchange::IPackager::INotification* _observer) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_observer));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Configure(PluginHost::IShell* _service) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

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

        uint32_t Install(const string& _name, const string& _version, const string& _arch) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);
            writer.Text(_version);
            writer.Text(_arch);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t SynchronizeRepository() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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

    }; // class ExchangePackagerProxy

    //
    // Exchange::IPackager::IInstallationInfo interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IPackager::state State() const = 0
    //  (1) virtual uint8_t Progress() const = 0
    //  (2) virtual string AppName() const = 0
    //  (3) virtual uint32_t ErrorCode() const = 0
    //  (4) virtual uint32_t Abort() = 0
    //

    class ExchangePackagerInstallationInfoProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackager::IInstallationInfo> {
    public:
        ExchangePackagerInstallationInfoProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Exchange::IPackager::state State() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Exchange::IPackager::state result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<Exchange::IPackager::state>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint8_t Progress() const override
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

        string AppName() const override
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

        uint32_t ErrorCode() const override
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

        uint32_t Abort() override
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

    }; // class ExchangePackagerInstallationInfoProxy

    //
    // Exchange::IPackager::IPackageInfo interface proxy definitions
    //
    // Methods:
    //  (0) virtual string Name() const = 0
    //  (1) virtual string Version() const = 0
    //  (2) virtual string Architecture() const = 0
    //

    class ExchangePackagerPackageInfoProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackager::IPackageInfo> {
    public:
        ExchangePackagerPackageInfoProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        string Name() const override
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

        string Version() const override
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

        string Architecture() const override
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

    }; // class ExchangePackagerPackageInfoProxy

    //
    // Exchange::IPackager::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChange(Exchange::IPackager::IPackageInfo*, Exchange::IPackager::IInstallationInfo*) = 0
    //  (1) virtual void RepositorySynchronize(uint32_t) = 0
    //

    class ExchangePackagerNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IPackager::INotification> {
    public:
        ExchangePackagerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChange(Exchange::IPackager::IPackageInfo* _package, Exchange::IPackager::IInstallationInfo* _install) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_package));
            writer.Number<Core::instance_id>(RPC::instance_cast(_install));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void RepositorySynchronize(uint32_t _status) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_status);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

    }; // class ExchangePackagerNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IPackager, ExchangePackagerStubMethods> ExchangePackagerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPackager::IInstallationInfo, ExchangePackagerInstallationInfoStubMethods> ExchangePackagerInstallationInfoStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPackager::IPackageInfo, ExchangePackagerPackageInfoStubMethods> ExchangePackagerPackageInfoStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPackager::INotification, ExchangePackagerNotificationStubMethods> ExchangePackagerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IPackager, ExchangePackagerProxy, ExchangePackagerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPackager::IInstallationInfo, ExchangePackagerInstallationInfoProxy, ExchangePackagerInstallationInfoStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPackager::IPackageInfo, ExchangePackagerPackageInfoProxy, ExchangePackagerPackageInfoStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPackager::INotification, ExchangePackagerNotificationProxy, ExchangePackagerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IPackager>();
                RPC::Administrator::Instance().Recall<Exchange::IPackager::IInstallationInfo>();
                RPC::Administrator::Instance().Recall<Exchange::IPackager::IPackageInfo>();
                RPC::Administrator::Instance().Recall<Exchange::IPackager::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
