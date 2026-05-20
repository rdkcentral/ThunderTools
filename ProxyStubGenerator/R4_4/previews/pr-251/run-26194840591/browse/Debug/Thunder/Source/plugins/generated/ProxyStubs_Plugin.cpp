//
// generated automatically from "IPlugin.h"
//
// implements COM-RPC proxy stubs for:
//   - class IPlugin
//   - class IPlugin::INotification
//   - class IPlugin::ILifeTime
//   - class ICompositPlugin
//   - class ICompositPlugin::INotification
//   - class IAuthenticate
//

#include "Module.h"
#include "IPlugin.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    using namespace PluginHost;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // IPlugin interface stub definitions
    //
    // Methods:
    //  (0) virtual const string Initialize(IShell*) = 0
    //  (1) virtual void Deinitialize(IShell*) = 0
    //  (2) virtual string Information() const = 0
    //

    ProxyStub::MethodHandler PluginStubMethods[] = {
        // (0) virtual const string Initialize(IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin* implementation = reinterpret_cast<IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id shellImplementation = reader.Number<Core::instance_id>();

            IShell* _shell = nullptr;
            ProxyStub::UnknownProxy* shellProxy = nullptr;
            if (shellImplementation != 0) {
                shellProxy = RPC::Administrator::Instance().ProxyInstance(channel, shellImplementation, false, _shell);

                ASSERT((_shell != nullptr) && (shellProxy != nullptr));
            }

            const string result = implementation->Initialize(_shell);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);

            if (shellProxy != nullptr) {
                RPC::Administrator::Instance().Release(shellProxy, message->Response());
            }
        },

        // (1) virtual void Deinitialize(IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin* implementation = reinterpret_cast<IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id shellImplementation = reader.Number<Core::instance_id>();

            IShell* _shell = nullptr;
            ProxyStub::UnknownProxy* shellProxy = nullptr;
            if (shellImplementation != 0) {
                shellProxy = RPC::Administrator::Instance().ProxyInstance(channel, shellImplementation, false, _shell);

                ASSERT((_shell != nullptr) && (shellProxy != nullptr));
            }

            implementation->Deinitialize(_shell);

            if (shellProxy != nullptr) {
                RPC::Administrator::Instance().Release(shellProxy, message->Response());
            }
        },

        // (2) virtual string Information() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IPlugin* implementation = reinterpret_cast<const IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Information();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // PluginStubMethods

    //
    // IPlugin::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Activated(const string&, IShell*) = 0
    //  (1) virtual void Deactivated(const string&, IShell*) = 0
    //  (2) virtual void Unavailable(const string&, IShell*) = 0
    //

    ProxyStub::MethodHandler PluginNotificationStubMethods[] = {
        // (0) virtual void Activated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::INotification* implementation = reinterpret_cast<IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::instance_id pluginImplementation = reader.Number<Core::instance_id>();

            IShell* _plugin = nullptr;
            ProxyStub::UnknownProxy* pluginProxy = nullptr;
            if (pluginImplementation != 0) {
                pluginProxy = RPC::Administrator::Instance().ProxyInstance(channel, pluginImplementation, false, _plugin);

                ASSERT((_plugin != nullptr) && (pluginProxy != nullptr));
            }

            implementation->Activated(static_cast<const string&>(_callsign), _plugin);

            if (pluginProxy != nullptr) {
                RPC::Administrator::Instance().Release(pluginProxy, message->Response());
            }
        },

        // (1) virtual void Deactivated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::INotification* implementation = reinterpret_cast<IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::instance_id pluginImplementation = reader.Number<Core::instance_id>();

            IShell* _plugin = nullptr;
            ProxyStub::UnknownProxy* pluginProxy = nullptr;
            if (pluginImplementation != 0) {
                pluginProxy = RPC::Administrator::Instance().ProxyInstance(channel, pluginImplementation, false, _plugin);

                ASSERT((_plugin != nullptr) && (pluginProxy != nullptr));
            }

            implementation->Deactivated(static_cast<const string&>(_callsign), _plugin);

            if (pluginProxy != nullptr) {
                RPC::Administrator::Instance().Release(pluginProxy, message->Response());
            }
        },

        // (2) virtual void Unavailable(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::INotification* implementation = reinterpret_cast<IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::instance_id pluginImplementation = reader.Number<Core::instance_id>();

            IShell* _plugin = nullptr;
            ProxyStub::UnknownProxy* pluginProxy = nullptr;
            if (pluginImplementation != 0) {
                pluginProxy = RPC::Administrator::Instance().ProxyInstance(channel, pluginImplementation, false, _plugin);

                ASSERT((_plugin != nullptr) && (pluginProxy != nullptr));
            }

            implementation->Unavailable(static_cast<const string&>(_callsign), _plugin);

            if (pluginProxy != nullptr) {
                RPC::Administrator::Instance().Release(pluginProxy, message->Response());
            }
        }
        , nullptr
    }; // PluginNotificationStubMethods

    //
    // IPlugin::ILifeTime interface stub definitions
    //
    // Methods:
    //  (0) virtual void Initialize(const string&, IShell*) = 0
    //  (1) virtual void Deinitialized(const string&, IShell*) = 0
    //

    ProxyStub::MethodHandler PluginLifeTimeStubMethods[] = {
        // (0) virtual void Initialize(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::ILifeTime* implementation = reinterpret_cast<IPlugin::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::instance_id pluginImplementation = reader.Number<Core::instance_id>();

            IShell* _plugin = nullptr;
            ProxyStub::UnknownProxy* pluginProxy = nullptr;
            if (pluginImplementation != 0) {
                pluginProxy = RPC::Administrator::Instance().ProxyInstance(channel, pluginImplementation, false, _plugin);

                ASSERT((_plugin != nullptr) && (pluginProxy != nullptr));
            }

            implementation->Initialize(static_cast<const string&>(_callsign), _plugin);

            if (pluginProxy != nullptr) {
                RPC::Administrator::Instance().Release(pluginProxy, message->Response());
            }
        },

        // (1) virtual void Deinitialized(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::ILifeTime* implementation = reinterpret_cast<IPlugin::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::instance_id pluginImplementation = reader.Number<Core::instance_id>();

            IShell* _plugin = nullptr;
            ProxyStub::UnknownProxy* pluginProxy = nullptr;
            if (pluginImplementation != 0) {
                pluginProxy = RPC::Administrator::Instance().ProxyInstance(channel, pluginImplementation, false, _plugin);

                ASSERT((_plugin != nullptr) && (pluginProxy != nullptr));
            }

            implementation->Deinitialized(static_cast<const string&>(_callsign), _plugin);

            if (pluginProxy != nullptr) {
                RPC::Administrator::Instance().Release(pluginProxy, message->Response());
            }
        }
        , nullptr
    }; // PluginLifeTimeStubMethods

    //
    // ICompositPlugin interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(ICompositPlugin::INotification*) = 0
    //  (1) virtual uint32_t Unregister(ICompositPlugin::INotification*) = 0
    //

    ProxyStub::MethodHandler CompositPluginStubMethods[] = {
        // (0) virtual uint32_t Register(ICompositPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin* implementation = reinterpret_cast<ICompositPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_7c40ea3aImplementation = reader.Number<Core::instance_id>();

            ICompositPlugin::INotification* _parameter_7c40ea3a = nullptr;
            ProxyStub::UnknownProxy* parameter_7c40ea3aProxy = nullptr;
            if (parameter_7c40ea3aImplementation != 0) {
                parameter_7c40ea3aProxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_7c40ea3aImplementation, false, _parameter_7c40ea3a);

                ASSERT((_parameter_7c40ea3a != nullptr) && (parameter_7c40ea3aProxy != nullptr));
            }

            uint32_t result = implementation->Register(_parameter_7c40ea3a);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_7c40ea3aProxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_7c40ea3aProxy, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(ICompositPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin* implementation = reinterpret_cast<ICompositPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_f8b75171Implementation = reader.Number<Core::instance_id>();

            ICompositPlugin::INotification* _parameter_f8b75171 = nullptr;
            ProxyStub::UnknownProxy* parameter_f8b75171Proxy = nullptr;
            if (parameter_f8b75171Implementation != 0) {
                parameter_f8b75171Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_f8b75171Implementation, false, _parameter_f8b75171);

                ASSERT((_parameter_f8b75171 != nullptr) && (parameter_f8b75171Proxy != nullptr));
            }

            uint32_t result = implementation->Unregister(_parameter_f8b75171);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_f8b75171Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_f8b75171Proxy, message->Response());
            }
        }
        , nullptr
    }; // CompositPluginStubMethods

    //
    // ICompositPlugin::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Activated(const string&, IShell*) = 0
    //  (1) virtual uint32_t Deactivated(const string&, IShell*) = 0
    //

    ProxyStub::MethodHandler CompositPluginNotificationStubMethods[] = {
        // (0) virtual uint32_t Activated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin::INotification* implementation = reinterpret_cast<ICompositPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::instance_id pluginImplementation = reader.Number<Core::instance_id>();

            IShell* _plugin = nullptr;
            ProxyStub::UnknownProxy* pluginProxy = nullptr;
            if (pluginImplementation != 0) {
                pluginProxy = RPC::Administrator::Instance().ProxyInstance(channel, pluginImplementation, false, _plugin);

                ASSERT((_plugin != nullptr) && (pluginProxy != nullptr));
            }

            uint32_t result = implementation->Activated(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (pluginProxy != nullptr) {
                RPC::Administrator::Instance().Release(pluginProxy, message->Response());
            }
        },

        // (1) virtual uint32_t Deactivated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin::INotification* implementation = reinterpret_cast<ICompositPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::instance_id pluginImplementation = reader.Number<Core::instance_id>();

            IShell* _plugin = nullptr;
            ProxyStub::UnknownProxy* pluginProxy = nullptr;
            if (pluginImplementation != 0) {
                pluginProxy = RPC::Administrator::Instance().ProxyInstance(channel, pluginImplementation, false, _plugin);

                ASSERT((_plugin != nullptr) && (pluginProxy != nullptr));
            }

            uint32_t result = implementation->Deactivated(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (pluginProxy != nullptr) {
                RPC::Administrator::Instance().Release(pluginProxy, message->Response());
            }
        }
        , nullptr
    }; // CompositPluginNotificationStubMethods

    //
    // IAuthenticate interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CreateToken(const uint16_t, const uint8_t*, string&) = 0
    //  (1) virtual ISecurity* Officer(const string&) = 0
    //

    ProxyStub::MethodHandler AuthenticateStubMethods[] = {
        // (0) virtual Core::hresult CreateToken(const uint16_t, const uint8_t*, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IAuthenticate* implementation = reinterpret_cast<IAuthenticate*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _buffer{};
            const uint16_t bufferLen = reader.LockBuffer<uint16_t>(_buffer);
            reader.UnlockBuffer(bufferLen);

            string _token{};

            Core::hresult result = implementation->CreateToken(bufferLen, _buffer, _token);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_token);
        },

        // (1) virtual ISecurity* Officer(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IAuthenticate* implementation = reinterpret_cast<IAuthenticate*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _token = reader.Text();

            ISecurity* result = implementation->Officer(static_cast<const string&>(_token));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // AuthenticateStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // IPlugin interface proxy definitions
    //
    // Methods:
    //  (0) virtual const string Initialize(IShell*) = 0
    //  (1) virtual void Deinitialize(IShell*) = 0
    //  (2) virtual string Information() const = 0
    //

    class PluginProxy final : public ProxyStub::UnknownProxyType<IPlugin> {
    public:
        PluginProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        const string Initialize(IShell* _shell) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_shell));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            Complete(reader);

            return (result);
        }

        void Deinitialize(IShell* _shell) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_shell));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        string Information() const override
        {
            IPCMessage message(BaseClass::Message(2));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class PluginProxy

    //
    // IPlugin::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Activated(const string&, IShell*) = 0
    //  (1) virtual void Deactivated(const string&, IShell*) = 0
    //  (2) virtual void Unavailable(const string&, IShell*) = 0
    //

    class PluginNotificationProxy final : public ProxyStub::UnknownProxyType<IPlugin::INotification> {
    public:
        PluginNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Activated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Deactivated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unavailable(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class PluginNotificationProxy

    //
    // IPlugin::ILifeTime interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Initialize(const string&, IShell*) = 0
    //  (1) virtual void Deinitialized(const string&, IShell*) = 0
    //

    class PluginLifeTimeProxy final : public ProxyStub::UnknownProxyType<IPlugin::ILifeTime> {
    public:
        PluginLifeTimeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Initialize(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Deinitialized(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class PluginLifeTimeProxy

    //
    // ICompositPlugin interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(ICompositPlugin::INotification*) = 0
    //  (1) virtual uint32_t Unregister(ICompositPlugin::INotification*) = 0
    //

    class CompositPluginProxy final : public ProxyStub::UnknownProxyType<ICompositPlugin> {
    public:
        CompositPluginProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Register(ICompositPlugin::INotification* _parameter_7c40ea3a) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_7c40ea3a));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Unregister(ICompositPlugin::INotification* _parameter_f8b75171) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_f8b75171));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

    }; // class CompositPluginProxy

    //
    // ICompositPlugin::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Activated(const string&, IShell*) = 0
    //  (1) virtual uint32_t Deactivated(const string&, IShell*) = 0
    //

    class CompositPluginNotificationProxy final : public ProxyStub::UnknownProxyType<ICompositPlugin::INotification> {
    public:
        CompositPluginNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Activated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Deactivated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

    }; // class CompositPluginNotificationProxy

    //
    // IAuthenticate interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CreateToken(const uint16_t, const uint8_t*, string&) = 0
    //  (1) virtual ISecurity* Officer(const string&) = 0
    //

    class AuthenticateProxy final : public ProxyStub::UnknownProxyType<IAuthenticate> {
    public:
        AuthenticateProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult CreateToken(const uint16_t bufferLen, const uint8_t* _buffer, string& _token) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(bufferLen, _buffer);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _token = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        ISecurity* Officer(const string& _token) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_token));

            ISecurity* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<ISecurity*>(Interface(reader.Number<Core::instance_id>(), ISecurity::ID));

            return (result);
        }

    }; // class AuthenticateProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<IPlugin, PluginStubMethods> PluginStub;
        typedef ProxyStub::UnknownStubType<IPlugin::INotification, PluginNotificationStubMethods> PluginNotificationStub;
        typedef ProxyStub::UnknownStubType<IPlugin::ILifeTime, PluginLifeTimeStubMethods> PluginLifeTimeStub;
        typedef ProxyStub::UnknownStubType<ICompositPlugin, CompositPluginStubMethods> CompositPluginStub;
        typedef ProxyStub::UnknownStubType<ICompositPlugin::INotification, CompositPluginNotificationStubMethods> CompositPluginNotificationStub;
        typedef ProxyStub::UnknownStubType<IAuthenticate, AuthenticateStubMethods> AuthenticateStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IPlugin, PluginProxy, PluginStub>();
                RPC::Administrator::Instance().Announce<IPlugin::INotification, PluginNotificationProxy, PluginNotificationStub>();
                RPC::Administrator::Instance().Announce<IPlugin::ILifeTime, PluginLifeTimeProxy, PluginLifeTimeStub>();
                RPC::Administrator::Instance().Announce<ICompositPlugin, CompositPluginProxy, CompositPluginStub>();
                RPC::Administrator::Instance().Announce<ICompositPlugin::INotification, CompositPluginNotificationProxy, CompositPluginNotificationStub>();
                RPC::Administrator::Instance().Announce<IAuthenticate, AuthenticateProxy, AuthenticateStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IPlugin>();
                RPC::Administrator::Instance().Recall<IPlugin::INotification>();
                RPC::Administrator::Instance().Recall<IPlugin::ILifeTime>();
                RPC::Administrator::Instance().Recall<ICompositPlugin>();
                RPC::Administrator::Instance().Recall<ICompositPlugin::INotification>();
                RPC::Administrator::Instance().Recall<IAuthenticate>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
