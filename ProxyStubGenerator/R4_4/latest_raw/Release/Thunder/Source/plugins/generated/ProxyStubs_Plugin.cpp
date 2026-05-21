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

    static ProxyStub::MethodHandler PluginStubMethods[] = {
        // (0) virtual const string Initialize(IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin* implementation = reinterpret_cast<IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _shellInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _shell{};
            ProxyStub::UnknownProxy* _shellProxy__ = nullptr;
            if (_shellInstanceId__ != 0) {
                _shellProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _shellInstanceId__, false, _shell);
                ASSERT((_shell != nullptr) && (_shellProxy__ != nullptr));
            }

            const string result = implementation->Initialize(_shell);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);

            if (_shellProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_shellProxy__, message->Response());
            }
        },

        // (1) virtual void Deinitialize(IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin* implementation = reinterpret_cast<IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _shellInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _shell{};
            ProxyStub::UnknownProxy* _shellProxy__ = nullptr;
            if (_shellInstanceId__ != 0) {
                _shellProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _shellInstanceId__, false, _shell);
                ASSERT((_shell != nullptr) && (_shellProxy__ != nullptr));
            }

            implementation->Deinitialize(_shell);

            if (_shellProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_shellProxy__, message->Response());
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

    static ProxyStub::MethodHandler PluginNotificationStubMethods[] = {
        // (0) virtual void Activated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::INotification* implementation = reinterpret_cast<IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            implementation->Activated(static_cast<const string&>(_callsign), _plugin);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (1) virtual void Deactivated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::INotification* implementation = reinterpret_cast<IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            implementation->Deactivated(static_cast<const string&>(_callsign), _plugin);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (2) virtual void Unavailable(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::INotification* implementation = reinterpret_cast<IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            implementation->Unavailable(static_cast<const string&>(_callsign), _plugin);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
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

    static ProxyStub::MethodHandler PluginLifeTimeStubMethods[] = {
        // (0) virtual void Initialize(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::ILifeTime* implementation = reinterpret_cast<IPlugin::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            implementation->Initialize(static_cast<const string&>(_callsign), _plugin);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (1) virtual void Deinitialized(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IPlugin::ILifeTime* implementation = reinterpret_cast<IPlugin::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            implementation->Deinitialized(static_cast<const string&>(_callsign), _plugin);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
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

    static ProxyStub::MethodHandler CompositPluginStubMethods[] = {
        // (0) virtual uint32_t Register(ICompositPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin* implementation = reinterpret_cast<ICompositPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            ICompositPlugin::INotification* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            uint32_t result = implementation->Register(_parameter_1);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(ICompositPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin* implementation = reinterpret_cast<ICompositPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            ICompositPlugin::INotification* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            uint32_t result = implementation->Unregister(_parameter_1);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
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

    static ProxyStub::MethodHandler CompositPluginNotificationStubMethods[] = {
        // (0) virtual uint32_t Activated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin::INotification* implementation = reinterpret_cast<ICompositPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            uint32_t result = implementation->Activated(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (1) virtual uint32_t Deactivated(const string&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            ICompositPlugin::INotification* implementation = reinterpret_cast<ICompositPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            uint32_t result = implementation->Deactivated(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
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

    static ProxyStub::MethodHandler AuthenticateStubMethods[] = {
        // (0) virtual Core::hresult CreateToken(const uint16_t, const uint8_t*, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IAuthenticate* implementation = reinterpret_cast<IAuthenticate*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _buffer{};
            const uint16_t _length = reader.LockBuffer<uint16_t>(_buffer);
            reader.UnlockBuffer(_length);

            string _token{};

            Core::hresult result = implementation->CreateToken(_length, _buffer, _token);

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

        const string Initialize(IShell* _shell) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_shell));

            string result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Deinitialize(IShell* _shell) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_shell));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        string Information() const override
        {
            IPCMessage message(UnknownProxyType::Message(2));

            string result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

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

        void Activated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Deactivated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unavailable(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(UnknownProxyType::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
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

        void Initialize(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Deinitialized(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
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

        uint32_t Register(ICompositPlugin::INotification* _parameter_1) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

            uint32_t result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Unregister(ICompositPlugin::INotification* _parameter_1) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

            uint32_t result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

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

        uint32_t Activated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            uint32_t result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Deactivated(const string& _callsign, IShell* _plugin) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            uint32_t result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

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

        Core::hresult CreateToken(const uint16_t _length, const uint8_t* _buffer, string& _token) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_length, _buffer);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _token = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        ISecurity* Officer(const string& _token) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_token);

            ISecurity* result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ISecurity*>(UnknownProxyType::Interface(reader.Number<Core::instance_id>(), ISecurity::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

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
