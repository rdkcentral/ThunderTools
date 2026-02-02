//
// generated automatically from "IShell.h"
//
// implements COM-RPC proxy stubs for:
//   - class IShell
//   - class IShell::IConnectionServer
//   - class IShell::IConnectionServer::INotification
//

#include "Module.h"
#include "IShell.h"

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
    // IShell interface stub definitions
    //
    // Methods:
    //  (0) virtual void EnableWebServer(const string&, const string&) = 0
    //  (1) virtual void DisableWebServer() = 0
    //  (2) virtual string Model() const = 0
    //  (3) virtual bool Background() const = 0
    //  (4) virtual string Accessor() const = 0
    //  (5) virtual string WebPrefix() const = 0
    //  (6) virtual string Locator() const = 0
    //  (7) virtual string ClassName() const = 0
    //  (8) virtual string Callsign() const = 0
    //  (9) virtual string PersistentPath() const = 0
    //  (10) virtual string VolatilePath() const = 0
    //  (11) virtual string DataPath() const = 0
    //  (12) virtual string ProxyStubPath() const = 0
    //  (13) virtual string SystemPath() const = 0
    //  (14) virtual string PluginPath() const = 0
    //  (15) virtual string SystemRootPath() const = 0
    //  (16) virtual Core::hresult SystemRootPath(const string&) = 0
    //  (17) virtual IShell::startmode StartMode() const = 0
    //  (18) virtual Core::hresult StartMode(const IShell::startmode) = 0
    //  (19) virtual string Substitute(const string&) const = 0
    //  (20) virtual bool Resumed() const = 0
    //  (21) virtual Core::hresult Resumed(const bool) = 0
    //  (22) virtual string HashKey() const = 0
    //  (23) virtual string ConfigLine() const = 0
    //  (24) virtual Core::hresult ConfigLine(const string&) = 0
    //  (25) virtual Core::hresult Metadata(string&) const = 0
    //  (26) virtual ISubSystem* SubSystems() = 0
    //  (27) virtual void Notify(const string&, const string&) = 0
    //  (28) virtual void Register(IPlugin::INotification*, const Core::OptionalType<string>&) = 0
    //  (29) virtual void Unregister(IPlugin::INotification*, const Core::OptionalType<string>&) = 0
    //  (30) virtual IShell::state State() const = 0
    //  (31) virtual void* QueryInterfaceByCallsign(const uint32_t, const string&) = 0
    //  (32) virtual Core::hresult Activate(const IShell::reason) = 0
    //  (33) virtual Core::hresult Deactivate(const IShell::reason) = 0
    //  (34) virtual Core::hresult Unavailable(const IShell::reason) = 0
    //  (35) virtual Core::hresult Hibernate(const uint32_t) = 0
    //  (36) virtual IShell::reason Reason() const = 0
    //  (37) virtual uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) = 0
    //  (38) virtual RPC::IStringIterator* GetLibrarySearchPaths(const string&) const = 0
    //

    static ProxyStub::MethodHandler ShellStubMethods[] = {
        // (0) virtual void EnableWebServer(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URLPath = reader.Text();
            const string _fileSystemPath = reader.Text();

            implementation->EnableWebServer(static_cast<const string&>(_URLPath), static_cast<const string&>(_fileSystemPath));
        },

        // (1) virtual void DisableWebServer() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->DisableWebServer();
        },

        // (2) virtual string Model() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Model();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (3) virtual bool Background() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Background();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual string Accessor() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Accessor();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (5) virtual string WebPrefix() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->WebPrefix();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (6) virtual string Locator() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Locator();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (7) virtual string ClassName() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->ClassName();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (8) virtual string Callsign() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Callsign();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (9) virtual string PersistentPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->PersistentPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (10) virtual string VolatilePath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->VolatilePath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (11) virtual string DataPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->DataPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (12) virtual string ProxyStubPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->ProxyStubPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (13) virtual string SystemPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->SystemPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (14) virtual string PluginPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->PluginPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (15) virtual string SystemRootPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->SystemRootPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (16) virtual Core::hresult SystemRootPath(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _systemRootPath = reader.Text();

            Core::hresult result = implementation->SystemRootPath(static_cast<const string&>(_systemRootPath));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (17) virtual IShell::startmode StartMode() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            IShell::startmode result = implementation->StartMode();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<IShell::startmode>(result);
        },

        // (18) virtual Core::hresult StartMode(const IShell::startmode) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::startmode _value = reader.Number<IShell::startmode>();

            Core::hresult result = implementation->StartMode(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (19) virtual string Substitute(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _input = reader.Text();

            string result = implementation->Substitute(static_cast<const string&>(_input));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (20) virtual bool Resumed() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Resumed();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (21) virtual Core::hresult Resumed(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _value = reader.Boolean();

            Core::hresult result = implementation->Resumed(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (22) virtual string HashKey() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->HashKey();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (23) virtual string ConfigLine() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->ConfigLine();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (24) virtual Core::hresult ConfigLine(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _config = reader.Text();

            Core::hresult result = implementation->ConfigLine(static_cast<const string&>(_config));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (25) virtual Core::hresult Metadata(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            Core::hresult result = implementation->Metadata(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_info);
        },

        // (26) virtual ISubSystem* SubSystems() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            ISubSystem* result = implementation->SubSystems();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (27) virtual void Notify(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _event = reader.Text();
            const string _message = reader.Text();

            implementation->Notify(static_cast<const string&>(_event), static_cast<const string&>(_message));
        },

        // (28) virtual void Register(IPlugin::INotification*, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();
            Core::OptionalType<string> _callsign{};
            if (reader.Boolean() == true) {
                _callsign = reader.Text();
            }

            IPlugin::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink, static_cast<const Core::OptionalType<string>&>(_callsign));

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (29) virtual void Unregister(IPlugin::INotification*, const Core::OptionalType<string>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();
            Core::OptionalType<string> _callsign{};
            if (reader.Boolean() == true) {
                _callsign = reader.Text();
            }

            IPlugin::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink, static_cast<const Core::OptionalType<string>&>(_callsign));

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (30) virtual IShell::state State() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            IShell::state result = implementation->State();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<IShell::state>(result);
        },

        // (31) virtual void* QueryInterfaceByCallsign(const uint32_t, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();
            const string _name = reader.Text();

            void* result = implementation->QueryInterfaceByCallsign(_id, static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result, _id);
        },

        // (32) virtual Core::hresult Activate(const IShell::reason) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::reason _parameter_e8222324 = reader.Number<IShell::reason>();

            Core::hresult result = implementation->Activate(_parameter_e8222324);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (33) virtual Core::hresult Deactivate(const IShell::reason) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::reason _parameter_fc125f61 = reader.Number<IShell::reason>();

            Core::hresult result = implementation->Deactivate(_parameter_fc125f61);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (34) virtual Core::hresult Unavailable(const IShell::reason) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::reason _parameter_b20eb704 = reader.Number<IShell::reason>();

            Core::hresult result = implementation->Unavailable(_parameter_b20eb704);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (35) virtual Core::hresult Hibernate(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _timeout = reader.Number<uint32_t>();

            Core::hresult result = implementation->Hibernate(_timeout);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (36) virtual IShell::reason Reason() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            IShell::reason result = implementation->Reason();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<IShell::reason>(result);
        },

        // (37) virtual uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& /* message */) {
            // stubbed method, no implementation
        },

        // (38) virtual RPC::IStringIterator* GetLibrarySearchPaths(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_97b1b7ef = reader.Text();

            RPC::IStringIterator* result = implementation->GetLibrarySearchPaths(static_cast<const string&>(_parameter_97b1b7ef));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ShellStubMethods

    //
    // IShell::IConnectionServer interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(IShell::IConnectionServer::INotification*) = 0
    //  (1) virtual void Unregister(const IShell::IConnectionServer::INotification*) = 0
    //

    static ProxyStub::MethodHandler ShellConnectionServerStubMethods[] = {
        // (0) virtual void Register(IShell::IConnectionServer::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell::IConnectionServer* implementation = reinterpret_cast<IShell::IConnectionServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            IShell::IConnectionServer::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(const IShell::IConnectionServer::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell::IConnectionServer* implementation = reinterpret_cast<IShell::IConnectionServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            const IShell::IConnectionServer::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        }
        , nullptr
    }; // ShellConnectionServerStubMethods

    //
    // IShell::IConnectionServer::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Opened(const uint32_t) = 0
    //  (1) virtual void Closed(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler ShellConnectionServerNotificationStubMethods[] = {
        // (0) virtual void Opened(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell::IConnectionServer::INotification* implementation = reinterpret_cast<IShell::IConnectionServer::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _channelId = reader.Number<uint32_t>();

            implementation->Opened(_channelId);
        },

        // (1) virtual void Closed(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell::IConnectionServer::INotification* implementation = reinterpret_cast<IShell::IConnectionServer::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _channelId = reader.Number<uint32_t>();

            implementation->Closed(_channelId);
        }
        , nullptr
    }; // ShellConnectionServerNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // IShell interface proxy definitions
    //
    // Methods:
    //  (0) virtual void EnableWebServer(const string&, const string&) = 0
    //  (1) virtual void DisableWebServer() = 0
    //  (2) virtual string Model() const = 0
    //  (3) virtual bool Background() const = 0
    //  (4) virtual string Accessor() const = 0
    //  (5) virtual string WebPrefix() const = 0
    //  (6) virtual string Locator() const = 0
    //  (7) virtual string ClassName() const = 0
    //  (8) virtual string Callsign() const = 0
    //  (9) virtual string PersistentPath() const = 0
    //  (10) virtual string VolatilePath() const = 0
    //  (11) virtual string DataPath() const = 0
    //  (12) virtual string ProxyStubPath() const = 0
    //  (13) virtual string SystemPath() const = 0
    //  (14) virtual string PluginPath() const = 0
    //  (15) virtual string SystemRootPath() const = 0
    //  (16) virtual Core::hresult SystemRootPath(const string&) = 0
    //  (17) virtual IShell::startmode StartMode() const = 0
    //  (18) virtual Core::hresult StartMode(const IShell::startmode) = 0
    //  (19) virtual string Substitute(const string&) const = 0
    //  (20) virtual bool Resumed() const = 0
    //  (21) virtual Core::hresult Resumed(const bool) = 0
    //  (22) virtual string HashKey() const = 0
    //  (23) virtual string ConfigLine() const = 0
    //  (24) virtual Core::hresult ConfigLine(const string&) = 0
    //  (25) virtual Core::hresult Metadata(string&) const = 0
    //  (26) virtual ISubSystem* SubSystems() = 0
    //  (27) virtual void Notify(const string&, const string&) = 0
    //  (28) virtual void Register(IPlugin::INotification*, const Core::OptionalType<string>&) = 0
    //  (29) virtual void Unregister(IPlugin::INotification*, const Core::OptionalType<string>&) = 0
    //  (30) virtual IShell::state State() const = 0
    //  (31) virtual void* QueryInterfaceByCallsign(const uint32_t, const string&) = 0
    //  (32) virtual Core::hresult Activate(const IShell::reason) = 0
    //  (33) virtual Core::hresult Deactivate(const IShell::reason) = 0
    //  (34) virtual Core::hresult Unavailable(const IShell::reason) = 0
    //  (35) virtual Core::hresult Hibernate(const uint32_t) = 0
    //  (36) virtual IShell::reason Reason() const = 0
    //  (37) virtual uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) = 0
    //  (38) virtual RPC::IStringIterator* GetLibrarySearchPaths(const string&) const = 0
    //

    class ShellProxy final : public ProxyStub::UnknownProxyType<IShell> {
    public:
        ShellProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void EnableWebServer(const string& _URLPath, const string& _fileSystemPath) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URLPath);
            writer.Text(_fileSystemPath);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void DisableWebServer() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        string Model() const override
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

        bool Background() const override
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

        string Accessor() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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

        string WebPrefix() const override
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

        string Locator() const override
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

        string ClassName() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

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

        string Callsign() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

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

        string PersistentPath() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

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

        string VolatilePath() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

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

        string DataPath() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

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

        string ProxyStubPath() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

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

        string SystemPath() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

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

        string PluginPath() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(14));

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

        string SystemRootPath() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(15));

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

        Core::hresult SystemRootPath(const string& _systemRootPath) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(16));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_systemRootPath);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        IShell::startmode StartMode() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(17));

            IShell::startmode result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<IShell::startmode>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Core::hresult StartMode(const IShell::startmode _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(18));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::startmode>(_value);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        string Substitute(const string& _input) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(19));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_input);

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

        bool Resumed() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(20));

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

        Core::hresult Resumed(const bool _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(21));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_value);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        string HashKey() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(22));

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

        string ConfigLine() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(23));

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

        Core::hresult ConfigLine(const string& _config) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(24));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_config);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Metadata(string& _info) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(25));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        ISubSystem* SubSystems() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(26));

            ISubSystem* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<ISubSystem*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), ISubSystem::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Notify(const string& _event, const string& _message) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(27));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_event);
            writer.Text(_message);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Register(IPlugin::INotification* _sink, const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(28));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(IPlugin::INotification* _sink, const Core::OptionalType<string>& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(29));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));
            writer.Boolean(_callsign.IsSet());
            if (_callsign.IsSet() == true) {
                writer.Text(_callsign.Value());
            }

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        IShell::state State() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(30));

            IShell::state result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<IShell::state>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void* QueryInterfaceByCallsign(const uint32_t _id, const string& _name) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(31));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Text(_name);

            void* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<void*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), _id));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Core::hresult Activate(const IShell::reason _parameter_e8222324) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(32));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::reason>(_parameter_e8222324);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Deactivate(const IShell::reason _parameter_fc125f61) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(33));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::reason>(_parameter_fc125f61);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unavailable(const IShell::reason _parameter_b20eb704) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(34));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::reason>(_parameter_b20eb704);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Hibernate(const uint32_t _timeout) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(35));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
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

        IShell::reason Reason() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(36));

            IShell::reason result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<IShell::reason>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) override
        {
            // stubbed method, no implementation

            return {};
        }

        RPC::IStringIterator* GetLibrarySearchPaths(const string& _parameter_97b1b7ef) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(38));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_parameter_97b1b7ef);

            RPC::IStringIterator* result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reinterpret_cast<RPC::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));
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

    }; // class ShellProxy

    //
    // IShell::IConnectionServer interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(IShell::IConnectionServer::INotification*) = 0
    //  (1) virtual void Unregister(const IShell::IConnectionServer::INotification*) = 0
    //

    class ShellConnectionServerProxy final : public ProxyStub::UnknownProxyType<IShell::IConnectionServer> {
    public:
        ShellConnectionServerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(IShell::IConnectionServer::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(const IShell::IConnectionServer::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

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

    }; // class ShellConnectionServerProxy

    //
    // IShell::IConnectionServer::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Opened(const uint32_t) = 0
    //  (1) virtual void Closed(const uint32_t) = 0
    //

    class ShellConnectionServerNotificationProxy final : public ProxyStub::UnknownProxyType<IShell::IConnectionServer::INotification> {
    public:
        ShellConnectionServerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Opened(const uint32_t _channelId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channelId);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Closed(const uint32_t _channelId) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channelId);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ShellConnectionServerNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<IShell, ShellStubMethods> ShellStub;
        typedef ProxyStub::UnknownStubType<IShell::IConnectionServer, ShellConnectionServerStubMethods> ShellConnectionServerStub;
        typedef ProxyStub::UnknownStubType<IShell::IConnectionServer::INotification, ShellConnectionServerNotificationStubMethods> ShellConnectionServerNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IShell, ShellProxy, ShellStub>();
                RPC::Administrator::Instance().Announce<IShell::IConnectionServer, ShellConnectionServerProxy, ShellConnectionServerStub>();
                RPC::Administrator::Instance().Announce<IShell::IConnectionServer::INotification, ShellConnectionServerNotificationProxy, ShellConnectionServerNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IShell>();
                RPC::Administrator::Instance().Recall<IShell::IConnectionServer>();
                RPC::Administrator::Instance().Recall<IShell::IConnectionServer::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
