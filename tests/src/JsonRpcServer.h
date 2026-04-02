/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2026 Metrological
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Module.h"
#include "Ids.h"

namespace Thunder {
namespace JsonRpcServer {

    // Minimal mock IShell for JSON-RPC testing
    // Only provides callsign functionality needed by JSONRPC base class
    class MockShell : public PluginHost::IShell {
    public:
        MockShell(const string& callsign) : _callsign(callsign), _refCount(1) {}
        ~MockShell() override = default;

        // IReferenceCounted
        uint32_t AddRef() const override {
            Core::InterlockedIncrement(_refCount);
            return Core::ERROR_NONE;
        }

        uint32_t Release() const override {
            if (Core::InterlockedDecrement(_refCount) == 0) {
                delete this;
            }
            return Core::ERROR_NONE;
        }

        // Essential IShell methods - Callsign() is used by JSONRPC
        string Callsign() const override { return _callsign; }
        
        // Stub implementations for other required virtual methods
        void EnableWebServer(const string&, const string&) override {}
        void DisableWebServer() override {}
        string Model() const override { return string(); }
        bool Background() const override { return false; }
        string Accessor() const override { return string(); }
        string WebPrefix() const override { return string(); }
        string Locator() const override { return string(); }
        string ClassName() const override { return string(); }
        string PersistentPath() const override { return string(); }
        string VolatilePath() const override { return string(); }
        string DataPath() const override { return string(); }
        string ProxyStubPath() const override { return string(); }
        string SystemPath() const override { return string(); }
        string PluginPath() const override { return string(); }
        string SystemRootPath() const override { return string(); }
        Core::hresult SystemRootPath(const string&) override { return Core::ERROR_NONE; }
        startmode StartMode() const override { return startmode::DEACTIVATED; }
        Core::hresult StartMode(const startmode) override { return Core::ERROR_NONE; }
        string Substitute(const string&) const override { return string(); }
        bool Resumed() const override { return false; }
        Core::hresult Resumed(const bool) override { return Core::ERROR_NONE; }
        string HashKey() const override { return string(); }
        string ConfigLine() const override { return string(); }
        Core::hresult ConfigLine(const string&) override { return Core::ERROR_NONE; }
        Core::hresult Metadata(string&) const override { return Core::ERROR_NONE; }
        PluginHost::ISubSystem* SubSystems() override { return nullptr; }
        void Notify(const string&, const string&) override {}
        void Register(PluginHost::IPlugin::INotification*, const Core::OptionalType<string>& = {}) override {}
        void Unregister(PluginHost::IPlugin::INotification*, const Core::OptionalType<string>& = {}) override {}
        state State() const override { return state::DEACTIVATED; }
        void* QueryInterfaceByCallsign(const uint32_t, const string&) override { return nullptr; }
        Core::hresult Activate(const reason) override { return Core::ERROR_NONE; }
        Core::hresult Deactivate(const reason) override { return Core::ERROR_NONE; }
        Core::hresult Unavailable(const reason) override { return Core::ERROR_NONE; }
        Core::hresult Hibernate(const uint32_t) override { return Core::ERROR_NONE; }
        reason Reason() const override { return reason::REQUESTED; }
        uint32_t Submit(const uint32_t, const Core::ProxyType<Core::JSON::IElement>&) override { return Core::ERROR_NONE; }
        RPC::IStringIterator* GetLibrarySearchPaths(const string&) const override { return nullptr; }

        BEGIN_INTERFACE_MAP(MockShell)
            INTERFACE_ENTRY(PluginHost::IShell)
        END_INTERFACE_MAP

    private:
        string _callsign;
        mutable uint32_t _refCount;
    };

    // JSON-RPC test server that properly inherits from PluginHost::JSONRPC
    // This enables actual JSON-RPC dispatch and testing of generated JSON stubs
    class JsonRpcServer : public PluginHost::IPlugin,
                          public PluginHost::JSONRPC {
    public:
        JsonRpcServer()
            : _refCount(1)
            , _service(nullptr)
        {
        }

        ~JsonRpcServer() override = default;

        BEGIN_INTERFACE_MAP(JsonRpcServer)
            INTERFACE_ENTRY(PluginHost::IPlugin)
            INTERFACE_ENTRY(PluginHost::IDispatcher)
        END_INTERFACE_MAP

        // IReferenceCounted implementation
        uint32_t AddRef() const override {
            Core::InterlockedIncrement(_refCount);
            return Core::ERROR_NONE;
        }

        uint32_t Release() const override {
            if (Core::InterlockedDecrement(_refCount) == 0) {
                // Note: Deletion is managed by Start/Stop functions
                // Don't delete here
            }
            return Core::ERROR_NONE;
        }

        // IPlugin interface
        const string Initialize(PluginHost::IShell* service) override {
            _service = service;
            if (_service != nullptr) {
                _service->AddRef();
                
                // Attach the JSONRPC dispatcher to get the callsign set
                PluginHost::IShell::IConnectionServer::INotification* sink = nullptr;
                Attach(sink, service);
                if (sink != nullptr) {
                    sink->Release();
                }
            }
            return string();
        }

        void Deinitialize(PluginHost::IShell* service) override {
            // Detach the JSONRPC dispatcher
            if (_service != nullptr) {
                PluginHost::IShell::IConnectionServer::INotification* sink = nullptr;
                Detach(sink);
                if (sink != nullptr) {
                    sink->Release();
                }
                
                _service->Release();
                _service = nullptr;
            }
        }

        string Information() const override {
            return string(_T("JSON-RPC Test Server"));
        }

    private:
        mutable uint32_t _refCount;
        PluginHost::IShell* _service;
    };

    // Registration provider for JSON-RPC interfaces
    class JsonRpcRegistrationProvider {
    public:
        using RegistrationFunc = std::function<void(JsonRpcServer&, std::vector<Core::IUnknown*>&)>;
        
        static JsonRpcRegistrationProvider& Instance() {
            static JsonRpcRegistrationProvider instance;
            return instance;
        }
        
        void Register(RegistrationFunc func) {
            _registrations.push_back(func);
        }
        
        void RegisterAll(JsonRpcServer& server, std::vector<Core::IUnknown*>& implementations) {
            for (auto& registration : _registrations) {
                registration(server, implementations);
            }
        }
        
    private:
        std::vector<RegistrationFunc> _registrations;
    };
    
    // Global server instance management
    extern JsonRpcServer* g_server;
    extern Core::ProxyType<MockShell> g_shell;
    extern std::vector<Core::IUnknown*> g_implementations;

    // -----------------------------------------------------------------------
    // Versioned handler provider (phase 2)
    //
    // Lambdas registered here run AFTER all base interface registrations so
    // that CreateHandler() clones have fully populated base handler tables.
    //
    // This is the correct place to implement the Thunder handwritten versioning
    // pattern (mirrors ThunderNanoServices JSONRPCPlugin.cpp CreateHandler use).
    // -----------------------------------------------------------------------
    class JsonRpcVersionedHandlerProvider {
    public:
        using HandlerSetupFunc = std::function<void(JsonRpcServer&)>;

        static JsonRpcVersionedHandlerProvider& Instance() {
            static JsonRpcVersionedHandlerProvider instance;
            return instance;
        }

        void Register(HandlerSetupFunc func) {
            _registrations.push_back(func);
        }

        void Apply(JsonRpcServer& server) {
            for (auto& reg : _registrations) {
                reg(server);
            }
        }

    private:
        std::vector<HandlerSetupFunc> _registrations;
    };
    
    inline void Start() {
        if (g_server == nullptr) {
            printf("Starting JsonRpcServer...\n");
            
            // Create mock shell
            g_shell = Core::ProxyType<MockShell>::Create("TestPlugin");
            
            // Create and initialize server
            g_server = new JsonRpcServer();
            g_server->Initialize(g_shell.operator->());
            
            // Phase 1: register all base interfaces via static registrations
            printf("JsonRpcServer: Registering JSON-RPC interfaces...\n");
            JsonRpcRegistrationProvider::Instance().RegisterAll(*g_server, g_implementations);
            printf("JsonRpcServer: JSON-RPC registration complete\n");

            // Phase 2: set up versioned handlers (runs after phase 1 so clones
            // of the base handler capture all previously registered methods)
            JsonRpcVersionedHandlerProvider::Instance().Apply(*g_server);

            printf("JsonRpcServer started successfully\n");
        }
    }

    inline void Stop() {
        if (g_server != nullptr) {
            printf("Stopping JsonRpcServer...\n");
            
            g_server->Deinitialize(g_shell.operator->());
            SleepMs(10);
            
            delete g_server;
            g_server = nullptr;
            
            // Cleanup tracked implementations
            for (auto* impl : g_implementations) {
                if (impl != nullptr) {
                    impl->Release();
                }
            }
            g_implementations.clear();
            
            g_shell.Release();
            
            printf("JsonRpcServer stopped\n");
        }
    }

    inline JsonRpcServer* Instance() {
        return g_server;
    }
    
    // Template registrar for automatic JSON-RPC interface registration
    // Usage: static JsonRpcServer::JsonRpcRegistrar<ITestPrimitives, TestPrimitivesImpl> g_jsonrpc_registrar(FunctionalTest::JTestPrimitives::Register);
    template <typename INTERFACE, typename IMPLEMENTATION>
    class JsonRpcRegistrar {
    public:
        template <typename RegisterFunc>
        JsonRpcRegistrar(RegisterFunc registerFunc) {
            // Register a lambda that will create and register this interface
            JsonRpcRegistrationProvider::Instance().Register(
                [registerFunc](JsonRpcServer& server, std::vector<Core::IUnknown*>& implementations) {
                    auto* impl = Core::Service<IMPLEMENTATION>::template Create<INTERFACE>();
                    if (impl) {
                        registerFunc(server, impl);
                        implementations.push_back(impl);
                        printf("  [ok] %s registered\n", typeid(INTERFACE).name());
                    }
                }
            );
        }
    };

    // Static registrar for handwritten versioned handler setup.
    // Usage:
    //   static JsonRpcServer::JsonRpcVersionedRegistrar g_reg(
    //       [](JsonRpcServer::JsonRpcServer& server) {
    //           Core::JSONRPC::Handler* v1 = server.GetHandler(1);
    //           Core::JSONRPC::Handler& v2 = server.CreateHandler({2}, *v1);
    //           v2.Register("myMethod", Core::JSONRPC::InvokeFunction(...));
    //       });
    class JsonRpcVersionedRegistrar {
    public:
        JsonRpcVersionedRegistrar(std::function<void(JsonRpcServer&)> setupFunc) {
            JsonRpcVersionedHandlerProvider::Instance().Register(setupFunc);
        }
    };

} // namespace JsonRpcServer
} // namespace Thunder
