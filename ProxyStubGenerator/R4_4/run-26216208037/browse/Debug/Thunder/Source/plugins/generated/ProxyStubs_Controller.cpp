//
// generated automatically from "IController.h"
//
// implements COM-RPC proxy stubs for:
//   - class Controller::ISystemManagement
//   - class Controller::IDiscovery
//   - class Controller::IConfiguration
//   - class Controller::ILifeTime
//   - class Controller::ILifeTime::INotification
//   - class Controller::IMetadata
//

#include "Module.h"
#include "IController.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    using namespace Exchange;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Controller::ISystemManagement interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Reboot() = 0
    //  (1) virtual Core::hresult Delete(const string&) = 0
    //  (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
    //  (3) virtual Core::hresult Environment(const string&, string&) const = 0
    //

    ProxyStub::MethodHandler ControllerSystemManagementStubMethods[] = {
        // (0) virtual Core::hresult Reboot() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ISystemManagement* implementation = reinterpret_cast<Controller::ISystemManagement*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Reboot();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Delete(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ISystemManagement* implementation = reinterpret_cast<Controller::ISystemManagement*>(message->Parameters().Implementation());
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
            Controller::ISystemManagement* implementation = reinterpret_cast<Controller::ISystemManagement*>(message->Parameters().Implementation());
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

        // (3) virtual Core::hresult Environment(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::ISystemManagement* implementation = reinterpret_cast<const Controller::ISystemManagement*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _index = reader.Text();

            string _environment{};

            Core::hresult result = implementation->Environment(static_cast<const string&>(_index), _environment);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_environment);
        }
        , nullptr
    }; // ControllerSystemManagementStubMethods

    //
    // Controller::IDiscovery interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StartDiscovery(const uint8_t&) = 0
    //  (1) virtual Core::hresult DiscoveryResults(string&) const = 0
    //

    ProxyStub::MethodHandler ControllerDiscoveryStubMethods[] = {
        // (0) virtual Core::hresult StartDiscovery(const uint8_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IDiscovery* implementation = reinterpret_cast<Controller::IDiscovery*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _ttl = reader.Number<uint8_t>();

            Core::hresult result = implementation->StartDiscovery(static_cast<const uint8_t&>(_ttl));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult DiscoveryResults(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IDiscovery* implementation = reinterpret_cast<const Controller::IDiscovery*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _response{};

            Core::hresult result = implementation->DiscoveryResults(_response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        }
        , nullptr
    }; // ControllerDiscoveryStubMethods

    //
    // Controller::IConfiguration interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Persist() = 0
    //  (1) virtual Core::hresult Configuration(const string&, string&) const = 0
    //  (2) virtual Core::hresult Configuration(const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ControllerConfigurationStubMethods[] = {
        // (0) virtual Core::hresult Persist() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::IConfiguration* implementation = reinterpret_cast<Controller::IConfiguration*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Persist();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Configuration(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IConfiguration* implementation = reinterpret_cast<const Controller::IConfiguration*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            string _configuration{};

            Core::hresult result = implementation->Configuration(static_cast<const string&>(_callsign), _configuration);

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
    //  (0) virtual Core::hresult Register(Controller::ILifeTime::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Controller::ILifeTime::INotification*) = 0
    //  (2) virtual Core::hresult Activate(const string&) = 0
    //  (3) virtual Core::hresult Deactivate(const string&) = 0
    //  (4) virtual Core::hresult Unavailable(const string&) = 0
    //  (5) virtual Core::hresult Hibernate(const string&, const Core::hresult) = 0
    //  (6) virtual Core::hresult Suspend(const string&) = 0
    //  (7) virtual Core::hresult Resume(const string&) = 0
    //

    ProxyStub::MethodHandler ControllerLifeTimeStubMethods[] = {
        // (0) virtual Core::hresult Register(Controller::ILifeTime::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Controller::ILifeTime::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            Core::hresult result = implementation->Register(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(Controller::ILifeTime::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Controller::ILifeTime::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            Core::hresult result = implementation->Unregister(_sink);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
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

        // (5) virtual Core::hresult Hibernate(const string&, const Core::hresult) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Controller::ILifeTime* implementation = reinterpret_cast<Controller::ILifeTime*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Core::hresult _timeout = reader.Number<Core::hresult>();

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
    //

    ProxyStub::MethodHandler ControllerLifeTimeNotificationStubMethods[] = {
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
        }
        , nullptr
    }; // ControllerLifeTimeNotificationStubMethods

    //
    // Controller::IMetadata interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Proxies(string&) const = 0
    //  (1) virtual Core::hresult Status(const string&, string&) const = 0
    //  (2) virtual Core::hresult Links(string&) const = 0
    //  (3) virtual Core::hresult ProcessInfo(string&) const = 0
    //  (4) virtual Core::hresult Subsystems(string&) const = 0
    //  (5) virtual Core::hresult Version(string&) const = 0
    //  (6) virtual Core::hresult CallStack(const string&, string&) const = 0
    //

    ProxyStub::MethodHandler ControllerMetadataStubMethods[] = {
        // (0) virtual Core::hresult Proxies(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _response{};

            Core::hresult result = implementation->Proxies(_response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (1) virtual Core::hresult Status(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _index = reader.Text();

            string _response{};

            Core::hresult result = implementation->Status(static_cast<const string&>(_index), _response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (2) virtual Core::hresult Links(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _response{};

            Core::hresult result = implementation->Links(_response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (3) virtual Core::hresult ProcessInfo(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _response{};

            Core::hresult result = implementation->ProcessInfo(_response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (4) virtual Core::hresult Subsystems(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _response{};

            Core::hresult result = implementation->Subsystems(_response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (5) virtual Core::hresult Version(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _response{};

            Core::hresult result = implementation->Version(_response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (6) virtual Core::hresult CallStack(const string&, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Controller::IMetadata* implementation = reinterpret_cast<const Controller::IMetadata*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _index = reader.Text();

            string _callstack{};

            Core::hresult result = implementation->CallStack(static_cast<const string&>(_index), _callstack);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_callstack);
        }
        , nullptr
    }; // ControllerMetadataStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Controller::ISystemManagement interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Reboot() = 0
    //  (1) virtual Core::hresult Delete(const string&) = 0
    //  (2) virtual Core::hresult Clone(const string&, const string&, string&) = 0
    //  (3) virtual Core::hresult Environment(const string&, string&) const = 0
    //

    class ControllerSystemManagementProxy final : public ProxyStub::UnknownProxyType<Controller::ISystemManagement> {
    public:
        ControllerSystemManagementProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult Reboot() override
        {
            IPCMessage message(BaseClass::Message(0));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Delete(const string& _path) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_path));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Clone(const string& _callsign, const string& _newcallsign, string& _response) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Text(static_cast<const string&>(_newcallsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Environment(const string& _index, string& _environment) const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_index));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _environment = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ControllerSystemManagementProxy

    //
    // Controller::IDiscovery interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult StartDiscovery(const uint8_t&) = 0
    //  (1) virtual Core::hresult DiscoveryResults(string&) const = 0
    //

    class ControllerDiscoveryProxy final : public ProxyStub::UnknownProxyType<Controller::IDiscovery> {
    public:
        ControllerDiscoveryProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult StartDiscovery(const uint8_t& _ttl) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(static_cast<const uint8_t&>(_ttl));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult DiscoveryResults(string& _response) const override
        {
            IPCMessage message(BaseClass::Message(1));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ControllerDiscoveryProxy

    //
    // Controller::IConfiguration interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Persist() = 0
    //  (1) virtual Core::hresult Configuration(const string&, string&) const = 0
    //  (2) virtual Core::hresult Configuration(const string&, const string&) = 0
    //

    class ControllerConfigurationProxy final : public ProxyStub::UnknownProxyType<Controller::IConfiguration> {
    public:
        ControllerConfigurationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult Persist() override
        {
            IPCMessage message(BaseClass::Message(0));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Configuration(const string& _callsign, string& _configuration) const override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _configuration = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Configuration(const string& _callsign, const string& _configuration) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Text(static_cast<const string&>(_configuration));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ControllerConfigurationProxy

    //
    // Controller::ILifeTime interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Controller::ILifeTime::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Controller::ILifeTime::INotification*) = 0
    //  (2) virtual Core::hresult Activate(const string&) = 0
    //  (3) virtual Core::hresult Deactivate(const string&) = 0
    //  (4) virtual Core::hresult Unavailable(const string&) = 0
    //  (5) virtual Core::hresult Hibernate(const string&, const Core::hresult) = 0
    //  (6) virtual Core::hresult Suspend(const string&) = 0
    //  (7) virtual Core::hresult Resume(const string&) = 0
    //

    class ControllerLifeTimeProxy final : public ProxyStub::UnknownProxyType<Controller::ILifeTime> {
    public:
        ControllerLifeTimeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult Register(Controller::ILifeTime::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Unregister(Controller::ILifeTime::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Activate(const string& _callsign) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Deactivate(const string& _callsign) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Unavailable(const string& _callsign) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Hibernate(const string& _callsign, const Core::hresult _timeout) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<Core::hresult>(_timeout);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Suspend(const string& _callsign) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Resume(const string& _callsign) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ControllerLifeTimeProxy

    //
    // Controller::ILifeTime::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const string&, const PluginHost::IShell::state&, const PluginHost::IShell::reason&) = 0
    //

    class ControllerLifeTimeNotificationProxy final : public ProxyStub::UnknownProxyType<Controller::ILifeTime::INotification> {
    public:
        ControllerLifeTimeNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void StateChange(const string& _callsign, const PluginHost::IShell::state& _state, const PluginHost::IShell::reason& _reason) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_callsign));
            writer.Number<PluginHost::IShell::state>(static_cast<const PluginHost::IShell::state&>(_state));
            writer.Number<PluginHost::IShell::reason>(static_cast<const PluginHost::IShell::reason&>(_reason));

            UnknownProxyType::Invoke(message);
        }

    }; // class ControllerLifeTimeNotificationProxy

    //
    // Controller::IMetadata interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Proxies(string&) const = 0
    //  (1) virtual Core::hresult Status(const string&, string&) const = 0
    //  (2) virtual Core::hresult Links(string&) const = 0
    //  (3) virtual Core::hresult ProcessInfo(string&) const = 0
    //  (4) virtual Core::hresult Subsystems(string&) const = 0
    //  (5) virtual Core::hresult Version(string&) const = 0
    //  (6) virtual Core::hresult CallStack(const string&, string&) const = 0
    //

    class ControllerMetadataProxy final : public ProxyStub::UnknownProxyType<Controller::IMetadata> {
    public:
        ControllerMetadataProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult Proxies(string& _response) const override
        {
            IPCMessage message(BaseClass::Message(0));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Status(const string& _index, string& _response) const override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_index));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Links(string& _response) const override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult ProcessInfo(string& _response) const override
        {
            IPCMessage message(BaseClass::Message(3));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Subsystems(string& _response) const override
        {
            IPCMessage message(BaseClass::Message(4));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Version(string& _response) const override
        {
            IPCMessage message(BaseClass::Message(5));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _response = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult CallStack(const string& _index, string& _callstack) const override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_index));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _callstack = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
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

        typedef ProxyStub::UnknownStubType<Controller::ISystemManagement, ControllerSystemManagementStubMethods> ControllerSystemManagementStub;
        typedef ProxyStub::UnknownStubType<Controller::IDiscovery, ControllerDiscoveryStubMethods> ControllerDiscoveryStub;
        typedef ProxyStub::UnknownStubType<Controller::IConfiguration, ControllerConfigurationStubMethods> ControllerConfigurationStub;
        typedef ProxyStub::UnknownStubType<Controller::ILifeTime, ControllerLifeTimeStubMethods> ControllerLifeTimeStub;
        typedef ProxyStub::UnknownStubType<Controller::ILifeTime::INotification, ControllerLifeTimeNotificationStubMethods> ControllerLifeTimeNotificationStub;
        typedef ProxyStub::UnknownStubType<Controller::IMetadata, ControllerMetadataStubMethods> ControllerMetadataStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Controller::ISystemManagement, ControllerSystemManagementProxy, ControllerSystemManagementStub>();
                RPC::Administrator::Instance().Announce<Controller::IDiscovery, ControllerDiscoveryProxy, ControllerDiscoveryStub>();
                RPC::Administrator::Instance().Announce<Controller::IConfiguration, ControllerConfigurationProxy, ControllerConfigurationStub>();
                RPC::Administrator::Instance().Announce<Controller::ILifeTime, ControllerLifeTimeProxy, ControllerLifeTimeStub>();
                RPC::Administrator::Instance().Announce<Controller::ILifeTime::INotification, ControllerLifeTimeNotificationProxy, ControllerLifeTimeNotificationStub>();
                RPC::Administrator::Instance().Announce<Controller::IMetadata, ControllerMetadataProxy, ControllerMetadataStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Controller::ISystemManagement>();
                RPC::Administrator::Instance().Recall<Controller::IDiscovery>();
                RPC::Administrator::Instance().Recall<Controller::IConfiguration>();
                RPC::Administrator::Instance().Recall<Controller::ILifeTime>();
                RPC::Administrator::Instance().Recall<Controller::ILifeTime::INotification>();
                RPC::Administrator::Instance().Recall<Controller::IMetadata>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
