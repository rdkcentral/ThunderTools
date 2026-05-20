//
// generated automatically from "IShell.h"
//
// implements COM-RPC proxy stubs for:
//   - class IShell
//

#include "Module.h"
#include "IShell.h"

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
    //  (8) virtual string Versions() const = 0
    //  (9) virtual string Callsign() const = 0
    //  (10) virtual string PersistentPath() const = 0
    //  (11) virtual string VolatilePath() const = 0
    //  (12) virtual string DataPath() const = 0
    //  (13) virtual string ProxyStubPath() const = 0
    //  (14) virtual string SystemPath() const = 0
    //  (15) virtual string PluginPath() const = 0
    //  (16) virtual string SystemRootPath() const = 0
    //  (17) virtual Core::hresult SystemRootPath(const string&) = 0
    //  (18) virtual IShell::startup Startup() const = 0
    //  (19) virtual Core::hresult Startup(const IShell::startup) = 0
    //  (20) virtual string Substitute(const string&) const = 0
    //  (21) virtual bool Resumed() const = 0
    //  (22) virtual Core::hresult Resumed(const bool) = 0
    //  (23) virtual string HashKey() const = 0
    //  (24) virtual string ConfigLine() const = 0
    //  (25) virtual Core::hresult ConfigLine(const string&) = 0
    //  (26) virtual Core::hresult Metadata(string&) const = 0
    //  (27) virtual bool IsSupported(const uint8_t) const = 0
    //  (28) virtual ISubSystem* SubSystems() = 0
    //  (29) virtual void Notify(const string&) = 0
    //  (30) virtual void Register(IPlugin::INotification*) = 0
    //  (31) virtual void Unregister(IPlugin::INotification*) = 0
    //  (32) virtual IShell::state State() const = 0
    //  (33) virtual void* QueryInterfaceByCallsign(const uint32_t, const string&) = 0
    //  (34) virtual Core::hresult Activate(const IShell::reason) = 0
    //  (35) virtual Core::hresult Deactivate(const IShell::reason) = 0
    //  (36) virtual Core::hresult Unavailable(const IShell::reason) = 0
    //  (37) virtual Core::hresult Hibernate(const uint32_t) = 0
    //  (38) virtual IShell::reason Reason() const = 0
    //  (39) virtual uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) = 0
    //  (40) virtual IShell::ICOMLink* COMLink() = 0
    //

    ProxyStub::MethodHandler ShellStubMethods[] = {
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

        // (8) virtual string Versions() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Versions();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (9) virtual string Callsign() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Callsign();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (10) virtual string PersistentPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->PersistentPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (11) virtual string VolatilePath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->VolatilePath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (12) virtual string DataPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->DataPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (13) virtual string ProxyStubPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->ProxyStubPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (14) virtual string SystemPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->SystemPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (15) virtual string PluginPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->PluginPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (16) virtual string SystemRootPath() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->SystemRootPath();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (17) virtual Core::hresult SystemRootPath(const string&) = 0
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

        // (18) virtual IShell::startup Startup() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            IShell::startup result = implementation->Startup();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<IShell::startup>(result);
        },

        // (19) virtual Core::hresult Startup(const IShell::startup) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::startup _value = reader.Number<IShell::startup>();

            Core::hresult result = implementation->Startup(_value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (20) virtual string Substitute(const string&) const = 0
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

        // (21) virtual bool Resumed() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Resumed();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (22) virtual Core::hresult Resumed(const bool) = 0
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

        // (23) virtual string HashKey() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->HashKey();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (24) virtual string ConfigLine() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->ConfigLine();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (25) virtual Core::hresult ConfigLine(const string&) = 0
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

        // (26) virtual Core::hresult Metadata(string&) const = 0
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

        // (27) virtual bool IsSupported(const uint8_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t _version = reader.Number<uint8_t>();

            bool result = implementation->IsSupported(_version);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (28) virtual ISubSystem* SubSystems() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            ISubSystem* result = implementation->SubSystems();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (29) virtual void Notify(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _message = reader.Text();

            implementation->Notify(static_cast<const string&>(_message));
        },

        // (30) virtual void Register(IPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            IPlugin::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Register(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (31) virtual void Unregister(IPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            IPlugin::INotification* _sink = nullptr;
            ProxyStub::UnknownProxy* sinkProxy = nullptr;
            if (sinkImplementation != 0) {
                sinkProxy = RPC::Administrator::Instance().ProxyInstance(channel, sinkImplementation, false, _sink);

                ASSERT((_sink != nullptr) && (sinkProxy != nullptr));
            }

            implementation->Unregister(_sink);

            if (sinkProxy != nullptr) {
                RPC::Administrator::Instance().Release(sinkProxy, message->Response());
            }
        },

        // (32) virtual IShell::state State() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            IShell::state result = implementation->State();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<IShell::state>(result);
        },

        // (33) virtual void* QueryInterfaceByCallsign(const uint32_t, const string&) = 0
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

        // (34) virtual Core::hresult Activate(const IShell::reason) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::reason _parameter_5032102b = reader.Number<IShell::reason>();

            Core::hresult result = implementation->Activate(_parameter_5032102b);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (35) virtual Core::hresult Deactivate(const IShell::reason) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::reason _parameter_34ff1e93 = reader.Number<IShell::reason>();

            Core::hresult result = implementation->Deactivate(_parameter_34ff1e93);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (36) virtual Core::hresult Unavailable(const IShell::reason) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IShell* implementation = reinterpret_cast<IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const IShell::reason _parameter_8bc15b2f = reader.Number<IShell::reason>();

            Core::hresult result = implementation->Unavailable(_parameter_8bc15b2f);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (37) virtual Core::hresult Hibernate(const uint32_t) = 0
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

        // (38) virtual IShell::reason Reason() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IShell* implementation = reinterpret_cast<const IShell*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            IShell::reason result = implementation->Reason();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<IShell::reason>(result);
        },

        // (39) virtual uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& /* message */) {
            // stubbed method, no implementation
        },

        // (40) virtual IShell::ICOMLink* COMLink() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& /* message */) {
            // stubbed method, no implementation
        }
        , nullptr
    }; // ShellStubMethods

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
    //  (8) virtual string Versions() const = 0
    //  (9) virtual string Callsign() const = 0
    //  (10) virtual string PersistentPath() const = 0
    //  (11) virtual string VolatilePath() const = 0
    //  (12) virtual string DataPath() const = 0
    //  (13) virtual string ProxyStubPath() const = 0
    //  (14) virtual string SystemPath() const = 0
    //  (15) virtual string PluginPath() const = 0
    //  (16) virtual string SystemRootPath() const = 0
    //  (17) virtual Core::hresult SystemRootPath(const string&) = 0
    //  (18) virtual IShell::startup Startup() const = 0
    //  (19) virtual Core::hresult Startup(const IShell::startup) = 0
    //  (20) virtual string Substitute(const string&) const = 0
    //  (21) virtual bool Resumed() const = 0
    //  (22) virtual Core::hresult Resumed(const bool) = 0
    //  (23) virtual string HashKey() const = 0
    //  (24) virtual string ConfigLine() const = 0
    //  (25) virtual Core::hresult ConfigLine(const string&) = 0
    //  (26) virtual Core::hresult Metadata(string&) const = 0
    //  (27) virtual bool IsSupported(const uint8_t) const = 0
    //  (28) virtual ISubSystem* SubSystems() = 0
    //  (29) virtual void Notify(const string&) = 0
    //  (30) virtual void Register(IPlugin::INotification*) = 0
    //  (31) virtual void Unregister(IPlugin::INotification*) = 0
    //  (32) virtual IShell::state State() const = 0
    //  (33) virtual void* QueryInterfaceByCallsign(const uint32_t, const string&) = 0
    //  (34) virtual Core::hresult Activate(const IShell::reason) = 0
    //  (35) virtual Core::hresult Deactivate(const IShell::reason) = 0
    //  (36) virtual Core::hresult Unavailable(const IShell::reason) = 0
    //  (37) virtual Core::hresult Hibernate(const uint32_t) = 0
    //  (38) virtual IShell::reason Reason() const = 0
    //  (39) virtual uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) = 0
    //  (40) virtual IShell::ICOMLink* COMLink() = 0
    //

    class ShellProxy final : public ProxyStub::UnknownProxyType<IShell> {
    public:
        ShellProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void EnableWebServer(const string& _URLPath, const string& _fileSystemPath) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_URLPath));
            writer.Text(static_cast<const string&>(_fileSystemPath));

            UnknownProxyType::Invoke(message);
        }

        void DisableWebServer() override
        {
            IPCMessage message(BaseClass::Message(1));

            UnknownProxyType::Invoke(message);
        }

        string Model() const override
        {
            IPCMessage message(BaseClass::Message(2));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        bool Background() const override
        {
            IPCMessage message(BaseClass::Message(3));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        string Accessor() const override
        {
            IPCMessage message(BaseClass::Message(4));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string WebPrefix() const override
        {
            IPCMessage message(BaseClass::Message(5));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string Locator() const override
        {
            IPCMessage message(BaseClass::Message(6));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string ClassName() const override
        {
            IPCMessage message(BaseClass::Message(7));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string Versions() const override
        {
            IPCMessage message(BaseClass::Message(8));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string Callsign() const override
        {
            IPCMessage message(BaseClass::Message(9));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string PersistentPath() const override
        {
            IPCMessage message(BaseClass::Message(10));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string VolatilePath() const override
        {
            IPCMessage message(BaseClass::Message(11));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string DataPath() const override
        {
            IPCMessage message(BaseClass::Message(12));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string ProxyStubPath() const override
        {
            IPCMessage message(BaseClass::Message(13));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string SystemPath() const override
        {
            IPCMessage message(BaseClass::Message(14));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string PluginPath() const override
        {
            IPCMessage message(BaseClass::Message(15));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string SystemRootPath() const override
        {
            IPCMessage message(BaseClass::Message(16));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        Core::hresult SystemRootPath(const string& _systemRootPath) override
        {
            IPCMessage message(BaseClass::Message(17));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_systemRootPath));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        IShell::startup Startup() const override
        {
            IPCMessage message(BaseClass::Message(18));

            IShell::startup result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<IShell::startup>();

            return (result);
        }

        Core::hresult Startup(const IShell::startup _value) override
        {
            IPCMessage message(BaseClass::Message(19));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::startup>(_value);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        string Substitute(const string& _input) const override
        {
            IPCMessage message(BaseClass::Message(20));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_input));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        bool Resumed() const override
        {
            IPCMessage message(BaseClass::Message(21));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Core::hresult Resumed(const bool _value) override
        {
            IPCMessage message(BaseClass::Message(22));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_value);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        string HashKey() const override
        {
            IPCMessage message(BaseClass::Message(23));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string ConfigLine() const override
        {
            IPCMessage message(BaseClass::Message(24));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        Core::hresult ConfigLine(const string& _config) override
        {
            IPCMessage message(BaseClass::Message(25));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_config));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Metadata(string& _info) const override
        {
            IPCMessage message(BaseClass::Message(26));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _info = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        bool IsSupported(const uint8_t _version) const override
        {
            IPCMessage message(BaseClass::Message(27));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint8_t>(_version);

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        ISubSystem* SubSystems() override
        {
            IPCMessage message(BaseClass::Message(28));

            ISubSystem* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<ISubSystem*>(Interface(reader.Number<Core::instance_id>(), ISubSystem::ID));

            return (result);
        }

        void Notify(const string& _message) override
        {
            IPCMessage message(BaseClass::Message(29));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_message));

            UnknownProxyType::Invoke(message);
        }

        void Register(IPlugin::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(30));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(IPlugin::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(31));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        IShell::state State() const override
        {
            IPCMessage message(BaseClass::Message(32));

            IShell::state result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<IShell::state>();

            return (result);
        }

        void* QueryInterfaceByCallsign(const uint32_t _id, const string& _name) override
        {
            IPCMessage message(BaseClass::Message(33));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Text(static_cast<const string&>(_name));

            void* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<void*>(Interface(reader.Number<Core::instance_id>(), _id));

            return (result);
        }

        Core::hresult Activate(const IShell::reason _parameter_5032102b) override
        {
            IPCMessage message(BaseClass::Message(34));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::reason>(_parameter_5032102b);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Deactivate(const IShell::reason _parameter_34ff1e93) override
        {
            IPCMessage message(BaseClass::Message(35));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::reason>(_parameter_34ff1e93);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Unavailable(const IShell::reason _parameter_8bc15b2f) override
        {
            IPCMessage message(BaseClass::Message(36));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<IShell::reason>(_parameter_8bc15b2f);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Hibernate(const uint32_t _timeout) override
        {
            IPCMessage message(BaseClass::Message(37));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_timeout);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        IShell::reason Reason() const override
        {
            IPCMessage message(BaseClass::Message(38));

            IShell::reason result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<IShell::reason>();

            return (result);
        }

        uint32_t Submit(const uint32_t, /* undefined type */ const Core::ProxyType<Core::JSON::IElement>&) override
        {
            // stubbed method, no implementation

            return {};
        }

        IShell::ICOMLink* COMLink() override
        {
            // stubbed method, no implementation

            return {};
        }

    }; // class ShellProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<IShell, ShellStubMethods> ShellStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IShell, ShellProxy, ShellStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IShell>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
