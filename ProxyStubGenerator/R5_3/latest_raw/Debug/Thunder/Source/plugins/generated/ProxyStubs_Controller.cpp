//
// generated automatically from "IController.h"
//
// implements COM-RPC proxy stubs for:
//   - class Controller::ISystem
//   - class Controller::IDiscovery
//   - class Controller::IConfiguration
//   - class Controller::ILifeTime
//   - class Controller::ILifeTime::INotification
//   - class Controller::IShells
//   - class Controller::IShells::INotification
//   - class Controller::ISubsystems
//   - class Controller::ISubsystems::INotification
//   - class Controller::IEvents
//   - class Controller::IEvents::INotification
//   - class Controller::IMetadata
//

#include "Module.h"
#include "IController.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    using namespace Exchange;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Controller::ISystem interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Reboot() = 0
    //  (1) virtual Core::hresult Delete(const string&) = 0
    //  (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
    //  (3) virtual Core::hresult Destroy(const string&) = 0
    //  (4) virtual Core::hresult Environment(const string&, string&) const = 0
    //

    static ProxyStub::MethodHandler ControllerSystemStubMethods[] = {
        // (0) virtual Core::hresult Reboot() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ISystem* implementation = reinterpret_cast<Controller::ISystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Reboot();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Delete(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ISystem* implementation = reinterpret_cast<Controller::ISystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _path = reader.Text();

            Core::hresult result = implementation->Delete(static_cast<const string&>(_path));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ISystem* implementation = reinterpret_cast<Controller::ISystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const string _newcallsign = reader.Text();

            string _response{};

            Core::hresult result = implementation->Clone(static_cast<const string&>(_callsign), static_cast<const string&>(_newcallsign), _response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (3) virtual Core::hresult Destroy(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ISystem* implementation = reinterpret_cast<Controller::ISystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->Destroy(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Environment(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::ISystem* implementation = reinterpret_cast<const Controller::ISystem*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _variable = reader.Text();

            string _value{};

            Core::hresult result = implementation->Environment(static_cast<const string&>(_variable), _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_value);
        }
        , nullptr
    }; // ControllerSystemStubMethods

    //
    // Controller::IDiscovery interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>&) = 0
    //  (1) virtual Core::hresult DiscoveryResults(Controller::IDiscovery::Data::IDiscoveryResultsIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ControllerDiscoveryStubMethods[] = {
        // (0) virtual Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IDiscovery* implementation = reinterpret_cast<Controller::IDiscovery*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<uint8_t> _ttl{};
            if (reader.Boolean() == true) {
                _ttl = reader.Number<uint8_t>();
                ASSERT((static_cast<const Core::OptionalType<uint8_t>&>(_ttl) >= 1) && (static_cast<const Core::OptionalType<uint8_t>&>(_ttl) <= 255));
            }

            Core::hresult result = implementation->StartDiscovery(static_cast<const Core::OptionalType<uint8_t>&>(_ttl));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult DiscoveryResults(Controller::IDiscovery::Data::IDiscoveryResultsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IDiscovery* implementation = reinterpret_cast<const Controller::IDiscovery*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Controller::IDiscovery::Data::IDiscoveryResultsIterator* _results{};

            Core::hresult result = implementation->DiscoveryResults(_results);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_results));

            RPC::Administrator::Instance().RegisterInterface(channel, _results);
        }
        , nullptr
    }; // ControllerDiscoveryStubMethods

    //
    // Controller::IConfiguration interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Persist() = 0
    //  (1) virtual Core::hresult Configuration(const Core::OptionalType<string>&, string&) const = 0
    //  (2) virtual Core::hresult Configuration(const string&, const string&) = 0
    //

    static ProxyStub::MethodHandler ControllerConfigurationStubMethods[] = {
        // (0) virtual Core::hresult Persist() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IConfiguration* implementation = reinterpret_cast<Controller::IConfiguration*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Persist();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Configuration(const Core::OptionalType<string>&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IConfiguration* implementation = reinterpret_cast<const Controller::IConfiguration*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<string> _callsign{};
            if (reader.Boolean() == true) {
                _callsign = reader.Text();
            }

            string _configuration{};

            Core::hresult result = implementation->Configuration(static_cast<const Core::OptionalType<string>&>(_callsign), _configuration);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_configuration);
        },

        // (2) virtual Core::hresult Configuration(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IConfiguration* implementation = reinterpret_cast<Controller::IConfiguration*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const string _configuration = reader.Text();

            Core::hresult result = implementation->Configuration(static_cast<const string&>(_callsign), static_cast<const string&>(_configuration));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ControllerConfigurationStubMethods

    //
    // Controller::ILifeTime interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (1) virtual Core::hresult Unregister(Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (2) virtual Core::hresult Activate(const string&) = 0
    //  (3) virtual Core::hresult Deactivate(const string&) = 0
    //  (4) virtual Core::hresult Unavailable(const string&) = 0
    //  (5) virtual Core::hresult Hibernate(const string&, const uint32_t) = 0
    //  (6) virtual Core::hresult Suspend(const string&) = 0
    //  (7) virtual Core::hresult Resume(const string&) = 0
    //

    static ProxyStub::MethodHandler ControllerLifeTimeStubMethods[] = {
        // (0) virtual Core::hresult Register(Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();
            Core::OptionalType<string> _callsign{};
            if (reader.Boolean() == true) {
                _callsign = reader.Text();
            }

            Controller::ILifeTime::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_sink, static_cast<const Core::OptionalType<string>&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();
            Core::OptionalType<string> _callsign{};
            if (reader.Boolean() == true) {
                _callsign = reader.Text();
            }

            Controller::ILifeTime::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_sink, static_cast<const Core::OptionalType<string>&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult Activate(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->Activate(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult Deactivate(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->Deactivate(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Unavailable(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->Unavailable(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (5) virtual Core::hresult Hibernate(const string&, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const uint32_t _timeout = reader.Number<uint32_t>();

            Core::hresult result = implementation->Hibernate(static_cast<const string&>(_callsign), _timeout);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (6) virtual Core::hresult Suspend(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->Suspend(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (7) virtual Core::hresult Resume(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->Resume(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ControllerLifeTimeStubMethods

    //
    // Controller::ILifeTime::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const string&, const PluginHost::IShell::state&, const PluginHost::IShell::reason&) = 0
    //  (1) virtual void StateControlStateChange(const string&, const Controller::ILifeTime::state&) = 0
    //

    static ProxyStub::MethodHandler ControllerLifeTimeNotificationStubMethods[] = {
        // (0) virtual void StateChange(const string&, const PluginHost::IShell::state&, const PluginHost::IShell::reason&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime::INotification* implementation = reinterpret_cast<Controller::ILifeTime::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const PluginHost::IShell::state _state = reader.Number<PluginHost::IShell::state>();
            const PluginHost::IShell::reason _reason = reader.Number<PluginHost::IShell::reason>();

            implementation->StateChange(static_cast<const string&>(_callsign), static_cast<const PluginHost::IShell::state&>(_state), static_cast<const PluginHost::IShell::reason&>(_reason));
        },

        // (1) virtual void StateControlStateChange(const string&, const Controller::ILifeTime::state&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime::INotification* implementation = reinterpret_cast<Controller::ILifeTime::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Controller::ILifeTime::state _state = reader.Number<Controller::ILifeTime::state>();

            implementation->StateControlStateChange(static_cast<const string&>(_callsign), static_cast<const Controller::ILifeTime::state&>(_state));
        }
        , nullptr
    }; // ControllerLifeTimeNotificationStubMethods

    //
    // Controller::IShells interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Controller::IShells::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Controller::IShells::INotification*) = 0
    //

    static ProxyStub::MethodHandler ControllerShellsStubMethods[] = {
        // (0) virtual Core::hresult Register(Controller::IShells::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IShells* implementation = reinterpret_cast<Controller::IShells*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Controller::IShells::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(Controller::IShells::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IShells* implementation = reinterpret_cast<Controller::IShells*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Controller::IShells::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        }
        , nullptr
    }; // ControllerShellsStubMethods

    //
    // Controller::IShells::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
    //

    static ProxyStub::MethodHandler ControllerShellsNotificationStubMethods[] = {
        // (0) virtual void Created(const string&, PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IShells::INotification* implementation = reinterpret_cast<Controller::IShells::INotification*>(message->Parameters().Implementation());
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
            Controller::IShells::INotification* implementation = reinterpret_cast<Controller::IShells::INotification*>(message->Parameters().Implementation());
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
        }
        , nullptr
    }; // ControllerShellsNotificationStubMethods

    //
    // Controller::ISubsystems interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Subsystems(Controller::ISubsystems::ISubsystemsIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ControllerSubsystemsStubMethods[] = {
        // (0) virtual Core::hresult Subsystems(Controller::ISubsystems::ISubsystemsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::ISubsystems* implementation = reinterpret_cast<const Controller::ISubsystems*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Controller::ISubsystems::ISubsystemsIterator* _subsystems{};

            Core::hresult result = implementation->Subsystems(_subsystems);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_subsystems));

            RPC::Administrator::Instance().RegisterInterface(channel, _subsystems);
        }
        , nullptr
    }; // ControllerSubsystemsStubMethods

    //
    // Controller::ISubsystems::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void SubsystemChange(Controller::ISubsystems::ISubsystemsIterator* const) = 0
    //

    static ProxyStub::MethodHandler ControllerSubsystemsNotificationStubMethods[] = {
        // (0) virtual void SubsystemChange(Controller::ISubsystems::ISubsystemsIterator* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ISubsystems::INotification* implementation = reinterpret_cast<Controller::ISubsystems::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _subsystemsInstanceId__ = reader.Number<Core::instance_id>();

            Controller::ISubsystems::ISubsystemsIterator* _subsystems{};
            ProxyStub::UnknownProxy* _subsystemsProxy__ = nullptr;
            if (_subsystemsInstanceId__ != 0) {
                _subsystemsProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _subsystemsInstanceId__, false, _subsystems);
                ASSERT((_subsystems != nullptr) && (_subsystemsProxy__ != nullptr));
            }

            implementation->SubsystemChange(_subsystems);

            if (_subsystemsProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_subsystemsProxy__, message->Response());
            }
        }
        , nullptr
    }; // ControllerSubsystemsNotificationStubMethods

    //
    // Controller::IEvents::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void ForwardMessage(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&) = 0
    //

    static ProxyStub::MethodHandler ControllerEventsNotificationStubMethods[] = {
        // (0) virtual void ForwardMessage(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IEvents::INotification* implementation = reinterpret_cast<Controller::IEvents::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _event = reader.Text();
            Core::OptionalType<string> _callsign{};
            if (reader.Boolean() == true) {
                _callsign = reader.Text();
            }
            Core::OptionalType<string> _params{};
            if (reader.Boolean() == true) {
                _params = reader.Text();
            }

            implementation->ForwardMessage(static_cast<const string&>(_event), static_cast<const Core::OptionalType<string>&>(_callsign), static_cast<const Core::OptionalType<string>&>(_params));
        }
        , nullptr
    }; // ControllerEventsNotificationStubMethods

    //
    // Controller::IMetadata interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Services(const Core::OptionalType<string>&, Controller::IMetadata::Data::IServicesIterator*&) const = 0
    //  (1) virtual Core::hresult Links(Controller::IMetadata::Data::ILinksIterator*&) const = 0
    //  (2) virtual Core::hresult Proxies(const Core::OptionalType<string>&, Controller::IMetadata::Data::IProxiesIterator*&) const = 0
    //  (3) virtual Core::hresult Framework(Controller::IMetadata::Data::Version&) const = 0
    //  (4) virtual Core::hresult Threads(Controller::IMetadata::Data::IThreadsIterator*&) const = 0
    //  (5) virtual Core::hresult PendingRequests(Controller::IMetadata::Data::IPendingRequestsIterator*&) const = 0
    //  (6) virtual Core::hresult CallStack(const uint8_t, Controller::IMetadata::Data::ICallStackIterator*&) const = 0
    //  (7) virtual Core::hresult BuildInfo(Controller::IMetadata::Data::BuildInfo&) const = 0
    //

    static ProxyStub::MethodHandler ControllerMetadataStubMethods[] = {
        // (0) virtual Core::hresult Services(const Core::OptionalType<string>&, Controller::IMetadata::Data::IServicesIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<string> _callsign{};
            if (reader.Boolean() == true) {
                _callsign = reader.Text();
            }

            Controller::IMetadata::Data::IServicesIterator* _services{};

            Core::hresult result = implementation->Services(static_cast<const Core::OptionalType<string>&>(_callsign), _services);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_services));

            RPC::Administrator::Instance().RegisterInterface(channel, _services);
        },

        // (1) virtual Core::hresult Links(Controller::IMetadata::Data::ILinksIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Controller::IMetadata::Data::ILinksIterator* _links{};

            Core::hresult result = implementation->Links(_links);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_links));

            RPC::Administrator::Instance().RegisterInterface(channel, _links);
        },

        // (2) virtual Core::hresult Proxies(const Core::OptionalType<string>&, Controller::IMetadata::Data::IProxiesIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::OptionalType<string> _linkID{};
            if (reader.Boolean() == true) {
                _linkID = reader.Text();
            }

            Controller::IMetadata::Data::IProxiesIterator* _proxies{};

            Core::hresult result = implementation->Proxies(static_cast<const Core::OptionalType<string>&>(_linkID), _proxies);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_proxies));

            RPC::Administrator::Instance().RegisterInterface(channel, _proxies);
        },

        // (3) virtual Core::hresult Framework(Controller::IMetadata::Data::Version&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Controller::IMetadata::Data::Version _version{};

            Core::hresult result = implementation->Framework(_version);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text<uint8_t>(_version.Hash);
            writer.Number<uint8_t>(_version.Major);
            writer.Number<uint8_t>(_version.Minor);
            writer.Number<uint8_t>(_version.Patch);
        },

        // (4) virtual Core::hresult Threads(Controller::IMetadata::Data::IThreadsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Controller::IMetadata::Data::IThreadsIterator* _threads{};

            Core::hresult result = implementation->Threads(_threads);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_threads));

            RPC::Administrator::Instance().RegisterInterface(channel, _threads);
        },

        // (5) virtual Core::hresult PendingRequests(Controller::IMetadata::Data::IPendingRequestsIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Controller::IMetadata::Data::IPendingRequestsIterator* _requests{};

            Core::hresult result = implementation->PendingRequests(_requests);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_requests));

            RPC::Administrator::Instance().RegisterInterface(channel, _requests);
        },

        // (6) virtual Core::hresult CallStack(const uint8_t, Controller::IMetadata::Data::ICallStackIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _thread = reader.Number<uint8_t>();

            Controller::IMetadata::Data::ICallStackIterator* _callstack{};

            Core::hresult result = implementation->CallStack(_thread, _callstack);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_callstack));

            RPC::Administrator::Instance().RegisterInterface(channel, _callstack);
        },

        // (7) virtual Core::hresult BuildInfo(Controller::IMetadata::Data::BuildInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Controller::IMetadata::Data::BuildInfo _buildInfo{};

            Core::hresult result = implementation->BuildInfo(_buildInfo);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Controller::IMetadata::Data::BuildInfo::systemtype>(_buildInfo.SystemType);
            writer.Number<Controller::IMetadata::Data::BuildInfo::buildtype>(_buildInfo.BuildType);
            writer.Boolean(_buildInfo.Extensions.IsSet());
            if (_buildInfo.Extensions.IsSet() == true) {
                writer.Number<Controller::IMetadata::Data::BuildInfo::extensiontype>(_buildInfo.Extensions.Value());
            }
            writer.Boolean(_buildInfo.Messaging);
            writer.Boolean(_buildInfo.ExceptionCatching);
            writer.Boolean(_buildInfo.DeadlockDetection);
            writer.Boolean(_buildInfo.WCharSupport);
            writer.Number<uint8_t>(_buildInfo.InstanceIDBits);
            writer.Boolean(_buildInfo.TraceLevel.IsSet());
            if (_buildInfo.TraceLevel.IsSet() == true) {
                writer.Number<uint8_t>(_buildInfo.TraceLevel.Value());
            }
            writer.Number<uint8_t>(_buildInfo.ThreadPoolCount);
            writer.Number<uint32_t>(_buildInfo.COMRPCTimeOut);
        }
        , nullptr
    }; // ControllerMetadataStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Controller::ISystem interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Reboot() = 0
    //  (1) virtual Core::hresult Delete(const string&) = 0
    //  (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
    //  (3) virtual Core::hresult Destroy(const string&) = 0
    //  (4) virtual Core::hresult Environment(const string&, string&) const = 0
    //

    class ControllerSystemProxy final : public ProxyStub::UnknownProxyType<Controller::ISystem> {
    public:
        ControllerSystemProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Reboot() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Delete(const string& _path) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_path);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Clone(const string& _callsign, const string& _newcallsign, string& _response) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Text(_newcallsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _response = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Destroy(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Environment(const string& _variable, string& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_variable);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _value = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ControllerSystemProxy

    //
    // Controller::IDiscovery interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>&) = 0
    //  (1) virtual Core::hresult DiscoveryResults(Controller::IDiscovery::Data::IDiscoveryResultsIterator*&) const = 0
    //

    class ControllerDiscoveryProxy final : public ProxyStub::UnknownProxyType<Controller::IDiscovery> {
    public:
        ControllerDiscoveryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult StartDiscovery(const Core::OptionalType<uint8_t>& _ttl) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_ttl.IsSet());
            if (_ttl.IsSet() == true) {
                writer.Number<uint8_t>(_ttl.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult DiscoveryResults(Controller::IDiscovery::Data::IDiscoveryResultsIterator*& _results) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _results = reinterpret_cast<Controller::IDiscovery::Data::IDiscoveryResultsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::IDiscovery::Data::IDiscoveryResultsIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ControllerDiscoveryProxy

    //
    // Controller::IConfiguration interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Persist() = 0
    //  (1) virtual Core::hresult Configuration(const Core::OptionalType<string>&, string&) const = 0
    //  (2) virtual Core::hresult Configuration(const string&, const string&) = 0
    //

    class ControllerConfigurationProxy final : public ProxyStub::UnknownProxyType<Controller::IConfiguration> {
    public:
        ControllerConfigurationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Persist() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Configuration(const Core::OptionalType<string>& _callsign, string& _configuration) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _configuration = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Configuration(const string& _callsign, const string& _configuration) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Text(_configuration);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ControllerConfigurationProxy

    //
    // Controller::ILifeTime interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (1) virtual Core::hresult Unregister(Controller::ILifeTime::INotification*, const Core::OptionalType<string>&) = 0
    //  (2) virtual Core::hresult Activate(const string&) = 0
    //  (3) virtual Core::hresult Deactivate(const string&) = 0
    //  (4) virtual Core::hresult Unavailable(const string&) = 0
    //  (5) virtual Core::hresult Hibernate(const string&, const uint32_t) = 0
    //  (6) virtual Core::hresult Suspend(const string&) = 0
    //  (7) virtual Core::hresult Resume(const string&) = 0
    //

    class ControllerLifeTimeProxy final : public ProxyStub::UnknownProxyType<Controller::ILifeTime> {
    public:
        ControllerLifeTimeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Controller::ILifeTime::INotification* _sink, const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

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

        Core::hresult Unregister(Controller::ILifeTime::INotification* _sink, const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

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

        Core::hresult Activate(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Deactivate(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unavailable(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Hibernate(const string& _callsign, const uint32_t _timeout) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<uint32_t>(_timeout);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Suspend(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Resume(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
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

    }; // class ControllerLifeTimeProxy

    //
    // Controller::ILifeTime::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const string&, const PluginHost::IShell::state&, const PluginHost::IShell::reason&) = 0
    //  (1) virtual void StateControlStateChange(const string&, const Controller::ILifeTime::state&) = 0
    //

    class ControllerLifeTimeNotificationProxy final : public ProxyStub::UnknownProxyType<Controller::ILifeTime::INotification> {
    public:
        ControllerLifeTimeNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChange(const string& _callsign, const PluginHost::IShell::state& _state, const PluginHost::IShell::reason& _reason) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<PluginHost::IShell::state>(_state);
            writer.Number<PluginHost::IShell::reason>(_reason);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void StateControlStateChange(const string& _callsign, const Controller::ILifeTime::state& _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Controller::ILifeTime::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ControllerLifeTimeNotificationProxy

    //
    // Controller::IShells interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Controller::IShells::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Controller::IShells::INotification*) = 0
    //

    class ControllerShellsProxy final : public ProxyStub::UnknownProxyType<Controller::IShells> {
    public:
        ControllerShellsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Controller::IShells::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

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

        Core::hresult Unregister(Controller::IShells::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

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

    }; // class ControllerShellsProxy

    //
    // Controller::IShells::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Created(const string&, PluginHost::IShell*) = 0
    //  (1) virtual void Destroy(const string&, PluginHost::IShell*) = 0
    //

    class ControllerShellsNotificationProxy final : public ProxyStub::UnknownProxyType<Controller::IShells::INotification> {
    public:
        ControllerShellsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

    }; // class ControllerShellsNotificationProxy

    //
    // Controller::ISubsystems interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Subsystems(Controller::ISubsystems::ISubsystemsIterator*&) const = 0
    //

    class ControllerSubsystemsProxy final : public ProxyStub::UnknownProxyType<Controller::ISubsystems> {
    public:
        ControllerSubsystemsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Subsystems(Controller::ISubsystems::ISubsystemsIterator*& _subsystems) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _subsystems = reinterpret_cast<Controller::ISubsystems::ISubsystemsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::ISubsystems::ISubsystemsIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ControllerSubsystemsProxy

    //
    // Controller::ISubsystems::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void SubsystemChange(Controller::ISubsystems::ISubsystemsIterator* const) = 0
    //

    class ControllerSubsystemsNotificationProxy final : public ProxyStub::UnknownProxyType<Controller::ISubsystems::INotification> {
    public:
        ControllerSubsystemsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void SubsystemChange(Controller::ISubsystems::ISubsystemsIterator* const _subsystems) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_subsystems));

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

    }; // class ControllerSubsystemsNotificationProxy

    //
    // Controller::IEvents::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void ForwardMessage(const string&, const Core::OptionalType<string>&, const Core::OptionalType<string>&) = 0
    //

    class ControllerEventsNotificationProxy final : public ProxyStub::UnknownProxyType<Controller::IEvents::INotification> {
    public:
        ControllerEventsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void ForwardMessage(const string& _event, const Core::OptionalType<string>& _callsign, const Core::OptionalType<string>& _params) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_event);
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }
            writer.Boolean(_params.IsSet());
            if (_params.IsSet() == true) {
                writer.Text(_params.Value());
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ControllerEventsNotificationProxy

    //
    // Controller::IMetadata interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Services(const Core::OptionalType<string>&, Controller::IMetadata::Data::IServicesIterator*&) const = 0
    //  (1) virtual Core::hresult Links(Controller::IMetadata::Data::ILinksIterator*&) const = 0
    //  (2) virtual Core::hresult Proxies(const Core::OptionalType<string>&, Controller::IMetadata::Data::IProxiesIterator*&) const = 0
    //  (3) virtual Core::hresult Framework(Controller::IMetadata::Data::Version&) const = 0
    //  (4) virtual Core::hresult Threads(Controller::IMetadata::Data::IThreadsIterator*&) const = 0
    //  (5) virtual Core::hresult PendingRequests(Controller::IMetadata::Data::IPendingRequestsIterator*&) const = 0
    //  (6) virtual Core::hresult CallStack(const uint8_t, Controller::IMetadata::Data::ICallStackIterator*&) const = 0
    //  (7) virtual Core::hresult BuildInfo(Controller::IMetadata::Data::BuildInfo&) const = 0
    //

    class ControllerMetadataProxy final : public ProxyStub::UnknownProxyType<Controller::IMetadata> {
    public:
        ControllerMetadataProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Services(const Core::OptionalType<string>& _callsign, Controller::IMetadata::Data::IServicesIterator*& _services) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _services = reinterpret_cast<Controller::IMetadata::Data::IServicesIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::IMetadata::Data::IServicesIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Links(Controller::IMetadata::Data::ILinksIterator*& _links) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _links = reinterpret_cast<Controller::IMetadata::Data::ILinksIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::IMetadata::Data::ILinksIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Proxies(const Core::OptionalType<string>& _linkID, Controller::IMetadata::Data::IProxiesIterator*& _proxies) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_linkID.IsSet());
            if (_linkID.IsSet() == true) {
                writer.Text(_linkID.Value());
            }

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _proxies = reinterpret_cast<Controller::IMetadata::Data::IProxiesIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::IMetadata::Data::IProxiesIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Framework(Controller::IMetadata::Data::Version& _version) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                ASSERT((reader.PeekNumber<uint8_t>() >= 64) && (reader.PeekNumber<uint8_t>() <= 64));
                _version.Hash = reader.Text<uint8_t>();
                _version.Major = reader.Number<uint8_t>();
                _version.Minor = reader.Number<uint8_t>();
                _version.Patch = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Threads(Controller::IMetadata::Data::IThreadsIterator*& _threads) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _threads = reinterpret_cast<Controller::IMetadata::Data::IThreadsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::IMetadata::Data::IThreadsIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult PendingRequests(Controller::IMetadata::Data::IPendingRequestsIterator*& _requests) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _requests = reinterpret_cast<Controller::IMetadata::Data::IPendingRequestsIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::IMetadata::Data::IPendingRequestsIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult CallStack(const uint8_t _thread, Controller::IMetadata::Data::ICallStackIterator*& _callstack) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_thread);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _callstack = reinterpret_cast<Controller::IMetadata::Data::ICallStackIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Controller::IMetadata::Data::ICallStackIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult BuildInfo(Controller::IMetadata::Data::BuildInfo& _buildInfo) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _buildInfo.SystemType = reader.Number<Controller::IMetadata::Data::BuildInfo::systemtype>();
                _buildInfo.BuildType = reader.Number<Controller::IMetadata::Data::BuildInfo::buildtype>();
                if (reader.Boolean() == true) {
                    _buildInfo.Extensions = reader.Number<Controller::IMetadata::Data::BuildInfo::extensiontype>();
                }
                _buildInfo.Messaging = reader.Boolean();
                _buildInfo.ExceptionCatching = reader.Boolean();
                _buildInfo.DeadlockDetection = reader.Boolean();
                _buildInfo.WCharSupport = reader.Boolean();
                _buildInfo.InstanceIDBits = reader.Number<uint8_t>();
                if (reader.Boolean() == true) {
                    _buildInfo.TraceLevel = reader.Number<uint8_t>();
                }
                _buildInfo.ThreadPoolCount = reader.Number<uint8_t>();
                _buildInfo.COMRPCTimeOut = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ControllerMetadataProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Controller::ISystem, ControllerSystemStubMethods> ControllerSystemStub;
        typedef ProxyStub::UnknownStubType<Controller::IDiscovery, ControllerDiscoveryStubMethods> ControllerDiscoveryStub;
        typedef ProxyStub::UnknownStubType<Controller::IConfiguration, ControllerConfigurationStubMethods> ControllerConfigurationStub;
        typedef ProxyStub::UnknownStubType<Controller::ILifeTime, ControllerLifeTimeStubMethods> ControllerLifeTimeStub;
        typedef ProxyStub::UnknownStubType<Controller::ILifeTime::INotification, ControllerLifeTimeNotificationStubMethods> ControllerLifeTimeNotificationStub;
        typedef ProxyStub::UnknownStubType<Controller::IShells, ControllerShellsStubMethods> ControllerShellsStub;
        typedef ProxyStub::UnknownStubType<Controller::IShells::INotification, ControllerShellsNotificationStubMethods> ControllerShellsNotificationStub;
        typedef ProxyStub::UnknownStubType<Controller::ISubsystems, ControllerSubsystemsStubMethods> ControllerSubsystemsStub;
        typedef ProxyStub::UnknownStubType<Controller::ISubsystems::INotification, ControllerSubsystemsNotificationStubMethods> ControllerSubsystemsNotificationStub;
        typedef ProxyStub::UnknownStubType<Controller::IEvents::INotification, ControllerEventsNotificationStubMethods> ControllerEventsNotificationStub;
        typedef ProxyStub::UnknownStubType<Controller::IMetadata, ControllerMetadataStubMethods> ControllerMetadataStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Controller::ISystem, ControllerSystemProxy, ControllerSystemStub>();
                RPC::Administrator::Instance().Announce<Controller::IDiscovery, ControllerDiscoveryProxy, ControllerDiscoveryStub>();
                RPC::Administrator::Instance().Announce<Controller::IConfiguration, ControllerConfigurationProxy, ControllerConfigurationStub>();
                RPC::Administrator::Instance().Announce<Controller::ILifeTime, ControllerLifeTimeProxy, ControllerLifeTimeStub>();
                RPC::Administrator::Instance().Announce<Controller::ILifeTime::INotification, ControllerLifeTimeNotificationProxy, ControllerLifeTimeNotificationStub>();
                RPC::Administrator::Instance().Announce<Controller::IShells, ControllerShellsProxy, ControllerShellsStub>();
                RPC::Administrator::Instance().Announce<Controller::IShells::INotification, ControllerShellsNotificationProxy, ControllerShellsNotificationStub>();
                RPC::Administrator::Instance().Announce<Controller::ISubsystems, ControllerSubsystemsProxy, ControllerSubsystemsStub>();
                RPC::Administrator::Instance().Announce<Controller::ISubsystems::INotification, ControllerSubsystemsNotificationProxy, ControllerSubsystemsNotificationStub>();
                RPC::Administrator::Instance().Announce<Controller::IEvents::INotification, ControllerEventsNotificationProxy, ControllerEventsNotificationStub>();
                RPC::Administrator::Instance().Announce<Controller::IMetadata, ControllerMetadataProxy, ControllerMetadataStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Controller::ISystem>();
                RPC::Administrator::Instance().Recall<Controller::IDiscovery>();
                RPC::Administrator::Instance().Recall<Controller::IConfiguration>();
                RPC::Administrator::Instance().Recall<Controller::ILifeTime>();
                RPC::Administrator::Instance().Recall<Controller::ILifeTime::INotification>();
                RPC::Administrator::Instance().Recall<Controller::IShells>();
                RPC::Administrator::Instance().Recall<Controller::IShells::INotification>();
                RPC::Administrator::Instance().Recall<Controller::ISubsystems>();
                RPC::Administrator::Instance().Recall<Controller::ISubsystems::INotification>();
                RPC::Administrator::Instance().Recall<Controller::IEvents::INotification>();
                RPC::Administrator::Instance().Recall<Controller::IMetadata>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
