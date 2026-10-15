//
// generated automatically from "IPlugin.h"
//
// implements COM-RPC proxy stubs for:
//   - class PluginHost::IPlugin
//   - class PluginHost::IPlugin::INotification
//   - class PluginHost::IPlugin::INotificationExtended
//   - class PluginHost::IPlugin::ILifeTime
//   - class PluginHost::ICompositPlugin
//   - class PluginHost::ICompositPlugin::ICallback
//   - class PluginHost::IAuthenticate
//

#include "Module.h"
#include "IPlugin.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // PluginHost::IPlugin interface stub definitions
    //
    // Methods:
    //  (0) virtual const string Initialize(PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialize(PluginHost::IShell*) = 0
    //  (2) virtual string Information() const = 0
    //

    static ProxyStub::MethodHandler PluginHostPluginStubMethods[] = {
        // (0) virtual const string Initialize(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin* implementation = reinterpret_cast<PluginHost::IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _shellInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _shell{};
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

        // (1) virtual void Deinitialize(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin* implementation = reinterpret_cast<PluginHost::IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _shellInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _shell{};
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
            const PluginHost::IPlugin* implementation = reinterpret_cast<const PluginHost::IPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Information();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // PluginHostPluginStubMethods

    //
    // PluginHost::IPlugin::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CancelableActivated(const string&, PluginHost::IShell*)
    //  (1) virtual Core::hresult CancelableDeactivated(const string&, PluginHost::IShell*)
    //  (2) virtual Core::hresult CancelableUnavailable(const string&, PluginHost::IShell*)
    //

    static ProxyStub::MethodHandler PluginHostPluginNotificationStubMethods[] = {
        // (0) virtual Core::hresult CancelableActivated(const string&, PluginHost::IShell*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin::INotification* implementation = reinterpret_cast<PluginHost::IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            Core::hresult result = implementation->CancelableActivated(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult CancelableDeactivated(const string&, PluginHost::IShell*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin::INotification* implementation = reinterpret_cast<PluginHost::IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            Core::hresult result = implementation->CancelableDeactivated(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult CancelableUnavailable(const string&, PluginHost::IShell*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin::INotification* implementation = reinterpret_cast<PluginHost::IPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            Core::hresult result = implementation->CancelableUnavailable(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        }
        , nullptr
    }; // PluginHostPluginNotificationStubMethods

    //
    // PluginHost::IPlugin::INotificationExtended interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CancelableHibernated(const string&, PluginHost::IShell*)
    //  (1) virtual Core::hresult CancelableDestroyed(const string&, PluginHost::IShell*)
    //

    static ProxyStub::MethodHandler PluginHostPluginNotificationExtendedStubMethods[] = {
        // (0) virtual Core::hresult CancelableHibernated(const string&, PluginHost::IShell*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin::INotificationExtended* implementation = reinterpret_cast<PluginHost::IPlugin::INotificationExtended*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            Core::hresult result = implementation->CancelableHibernated(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult CancelableDestroyed(const string&, PluginHost::IShell*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin::INotificationExtended* implementation = reinterpret_cast<PluginHost::IPlugin::INotificationExtended*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            Core::hresult result = implementation->CancelableDestroyed(static_cast<const string&>(_callsign), _plugin);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        }
        , nullptr
    }; // PluginHostPluginNotificationExtendedStubMethods

    //
    // PluginHost::IPlugin::ILifeTime interface stub definitions
    //
    // Methods:
    //  (0) virtual void Initialize(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialized(const string&, PluginHost::IShell*) = 0
    //

    static ProxyStub::MethodHandler PluginHostPluginLifeTimeStubMethods[] = {
        // (0) virtual void Initialize(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin::ILifeTime* implementation = reinterpret_cast<PluginHost::IPlugin::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
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

        // (1) virtual void Deinitialized(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IPlugin::ILifeTime* implementation = reinterpret_cast<PluginHost::IPlugin::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
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
    }; // PluginHostPluginLifeTimeStubMethods

    //
    // PluginHost::ICompositPlugin interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Callback(PluginHost::ICompositPlugin::ICallback*) = 0
    //

    static ProxyStub::MethodHandler PluginHostCompositPluginStubMethods[] = {
        // (0) virtual uint32_t Callback(PluginHost::ICompositPlugin::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::ICompositPlugin* implementation = reinterpret_cast<PluginHost::ICompositPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::ICompositPlugin::ICallback* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            uint32_t result = implementation->Callback(_parameter_1);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
            }
        }
        , nullptr
    }; // PluginHostCompositPluginStubMethods

    //
    // PluginHost::ICompositPlugin::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
    //  (2) virtual void Activated(const string&, PluginHost::IShell*) = 0
    //  (3) virtual void Deactivated(const string&, PluginHost::IShell*) = 0
    //  (4) virtual void Unavailable(const string&, PluginHost::IShell*) = 0
    //

    static ProxyStub::MethodHandler PluginHostCompositPluginCallbackStubMethods[] = {
        // (0) virtual void Created(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::ICompositPlugin::ICallback* implementation = reinterpret_cast<PluginHost::ICompositPlugin::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            implementation->Created(static_cast<const string&>(_callsign), _plugin);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::ICompositPlugin::ICallback* implementation = reinterpret_cast<PluginHost::ICompositPlugin::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
            ProxyStub::UnknownProxy* _pluginProxy__ = nullptr;
            if (_pluginInstanceId__ != 0) {
                _pluginProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _pluginInstanceId__, false, _plugin);
                ASSERT((_plugin != nullptr) && (_pluginProxy__ != nullptr));
            }

            implementation->Destroy(static_cast<const string&>(_callsign), _plugin);

            if (_pluginProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_pluginProxy__, message->Response());
            }
        },

        // (2) virtual void Activated(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::ICompositPlugin::ICallback* implementation = reinterpret_cast<PluginHost::ICompositPlugin::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
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

        // (3) virtual void Deactivated(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::ICompositPlugin::ICallback* implementation = reinterpret_cast<PluginHost::ICompositPlugin::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
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

        // (4) virtual void Unavailable(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::ICompositPlugin::ICallback* implementation = reinterpret_cast<PluginHost::ICompositPlugin::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::instance_id _pluginInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _plugin{};
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
    }; // PluginHostCompositPluginCallbackStubMethods

    //
    // PluginHost::IAuthenticate interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CreateToken(const uint16_t, const uint8_t*, string&) = 0
    //  (1) virtual PluginHost::ISecurity* Officer(const string&) = 0
    //

    static ProxyStub::MethodHandler PluginHostAuthenticateStubMethods[] = {
        // (0) virtual Core::hresult CreateToken(const uint16_t, const uint8_t*, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IAuthenticate* implementation = reinterpret_cast<PluginHost::IAuthenticate*>(message->Parameters().Implementation());
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

        // (1) virtual PluginHost::ISecurity* Officer(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            PluginHost::IAuthenticate* implementation = reinterpret_cast<PluginHost::IAuthenticate*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _token = reader.Text();

            PluginHost::ISecurity* result = implementation->Officer(static_cast<const string&>(_token));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // PluginHostAuthenticateStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // PluginHost::IPlugin interface proxy definitions
    //
    // Methods:
    //  (0) virtual const string Initialize(PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialize(PluginHost::IShell*) = 0
    //  (2) virtual string Information() const = 0
    //

    class PluginHostPluginProxy final : public ProxyStub::UnknownProxyType<PluginHost::IPlugin> {
    public:
        PluginHostPluginProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        const string Initialize(PluginHost::IShell* _shell) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_shell));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Deinitialize(PluginHost::IShell* _shell) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_shell));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        string Information() const override
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

    }; // class PluginHostPluginProxy

    //
    // PluginHost::IPlugin::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CancelableActivated(const string&, PluginHost::IShell*)
    //  (1) virtual Core::hresult CancelableDeactivated(const string&, PluginHost::IShell*)
    //  (2) virtual Core::hresult CancelableUnavailable(const string&, PluginHost::IShell*)
    //

    class PluginHostPluginNotificationProxy final : public ProxyStub::UnknownProxyType<PluginHost::IPlugin::INotification> {
    public:
        PluginHostPluginNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult CancelableActivated(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

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

        Core::hresult CancelableDeactivated(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

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

        Core::hresult CancelableUnavailable(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

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

    }; // class PluginHostPluginNotificationProxy

    //
    // PluginHost::IPlugin::INotificationExtended interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CancelableHibernated(const string&, PluginHost::IShell*)
    //  (1) virtual Core::hresult CancelableDestroyed(const string&, PluginHost::IShell*)
    //

    class PluginHostPluginNotificationExtendedProxy final : public ProxyStub::UnknownProxyType<PluginHost::IPlugin::INotificationExtended> {
    public:
        PluginHostPluginNotificationExtendedProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult CancelableHibernated(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

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

        Core::hresult CancelableDestroyed(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

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

    }; // class PluginHostPluginNotificationExtendedProxy

    //
    // PluginHost::IPlugin::ILifeTime interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Initialize(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialized(const string&, PluginHost::IShell*) = 0
    //

    class PluginHostPluginLifeTimeProxy final : public ProxyStub::UnknownProxyType<PluginHost::IPlugin::ILifeTime> {
    public:
        PluginHostPluginLifeTimeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Initialize(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Deinitialized(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

    }; // class PluginHostPluginLifeTimeProxy

    //
    // PluginHost::ICompositPlugin interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Callback(PluginHost::ICompositPlugin::ICallback*) = 0
    //

    class PluginHostCompositPluginProxy final : public ProxyStub::UnknownProxyType<PluginHost::ICompositPlugin> {
    public:
        PluginHostCompositPluginProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Callback(PluginHost::ICompositPlugin::ICallback* _parameter_1) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

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

    }; // class PluginHostCompositPluginProxy

    //
    // PluginHost::ICompositPlugin::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
    //  (2) virtual void Activated(const string&, PluginHost::IShell*) = 0
    //  (3) virtual void Deactivated(const string&, PluginHost::IShell*) = 0
    //  (4) virtual void Unavailable(const string&, PluginHost::IShell*) = 0
    //

    class PluginHostCompositPluginCallbackProxy final : public ProxyStub::UnknownProxyType<PluginHost::ICompositPlugin::ICallback> {
    public:
        PluginHostCompositPluginCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Created(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Destroy(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Activated(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Deactivated(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unavailable(const string& _callsign, PluginHost::IShell* _plugin) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Core::instance_id>(RPC::instance_cast(_plugin));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

                result = static_cast<const ProxyStub::UnknownProxy&>(*this).Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
        }

    }; // class PluginHostCompositPluginCallbackProxy

    //
    // PluginHost::IAuthenticate interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult CreateToken(const uint16_t, const uint8_t*, string&) = 0
    //  (1) virtual PluginHost::ISecurity* Officer(const string&) = 0
    //

    class PluginHostAuthenticateProxy final : public ProxyStub::UnknownProxyType<PluginHost::IAuthenticate> {
    public:
        PluginHostAuthenticateProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult CreateToken(const uint16_t _length, const uint8_t* _buffer, string& _token) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(_length, _buffer);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _token = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        PluginHost::ISecurity* Officer(const string& _token) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_token);

            PluginHost::ISecurity* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<PluginHost::ISecurity*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), PluginHost::ISecurity::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class PluginHostAuthenticateProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<PluginHost::IPlugin, PluginHostPluginStubMethods> PluginHostPluginStub;
        typedef ProxyStub::UnknownStubType<PluginHost::IPlugin::INotification, PluginHostPluginNotificationStubMethods> PluginHostPluginNotificationStub;
        typedef ProxyStub::UnknownStubType<PluginHost::IPlugin::INotificationExtended, PluginHostPluginNotificationExtendedStubMethods> PluginHostPluginNotificationExtendedStub;
        typedef ProxyStub::UnknownStubType<PluginHost::IPlugin::ILifeTime, PluginHostPluginLifeTimeStubMethods> PluginHostPluginLifeTimeStub;
        typedef ProxyStub::UnknownStubType<PluginHost::ICompositPlugin, PluginHostCompositPluginStubMethods> PluginHostCompositPluginStub;
        typedef ProxyStub::UnknownStubType<PluginHost::ICompositPlugin::ICallback, PluginHostCompositPluginCallbackStubMethods> PluginHostCompositPluginCallbackStub;
        typedef ProxyStub::UnknownStubType<PluginHost::IAuthenticate, PluginHostAuthenticateStubMethods> PluginHostAuthenticateStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<PluginHost::IPlugin, PluginHostPluginProxy, PluginHostPluginStub>();
                RPC::Administrator::Instance().Announce<PluginHost::IPlugin::INotification, PluginHostPluginNotificationProxy, PluginHostPluginNotificationStub>();
                RPC::Administrator::Instance().Announce<PluginHost::IPlugin::INotificationExtended, PluginHostPluginNotificationExtendedProxy, PluginHostPluginNotificationExtendedStub>();
                RPC::Administrator::Instance().Announce<PluginHost::IPlugin::ILifeTime, PluginHostPluginLifeTimeProxy, PluginHostPluginLifeTimeStub>();
                RPC::Administrator::Instance().Announce<PluginHost::ICompositPlugin, PluginHostCompositPluginProxy, PluginHostCompositPluginStub>();
                RPC::Administrator::Instance().Announce<PluginHost::ICompositPlugin::ICallback, PluginHostCompositPluginCallbackProxy, PluginHostCompositPluginCallbackStub>();
                RPC::Administrator::Instance().Announce<PluginHost::IAuthenticate, PluginHostAuthenticateProxy, PluginHostAuthenticateStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<PluginHost::IPlugin>();
                RPC::Administrator::Instance().Recall<PluginHost::IPlugin::INotification>();
                RPC::Administrator::Instance().Recall<PluginHost::IPlugin::INotificationExtended>();
                RPC::Administrator::Instance().Recall<PluginHost::IPlugin::ILifeTime>();
                RPC::Administrator::Instance().Recall<PluginHost::ICompositPlugin>();
                RPC::Administrator::Instance().Recall<PluginHost::ICompositPlugin::ICallback>();
                RPC::Administrator::Instance().Recall<PluginHost::IAuthenticate>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
