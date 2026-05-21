//
// generated automatically from "IScriptEngine.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IScriptEngine
//   - class Exchange::IScriptEngine::INotification
//

#include "Module.h"
#include "IScriptEngine.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IScriptEngine interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IScriptEngine::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IScriptEngine::INotification*) = 0
    //  (2) virtual Core::hresult URL(string&) const = 0
    //  (3) virtual Core::hresult URL(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeScriptEngineStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IScriptEngine::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IScriptEngine* implementation = reinterpret_cast<Exchange::IScriptEngine*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IScriptEngine::INotification* _sink = nullptr;
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

        // (1) virtual Core::hresult Unregister(const Exchange::IScriptEngine::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IScriptEngine* implementation = reinterpret_cast<Exchange::IScriptEngine*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IScriptEngine::INotification* _sink = nullptr;
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

        // (2) virtual Core::hresult URL(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IScriptEngine* implementation = reinterpret_cast<const Exchange::IScriptEngine*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _url{};

            Core::hresult result = implementation->URL(_url);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_url);
        },

        // (3) virtual Core::hresult URL(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IScriptEngine* implementation = reinterpret_cast<Exchange::IScriptEngine*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _url = reader.Text();

            Core::hresult result = implementation->URL(static_cast<const string&>(_url));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeScriptEngineStubMethods

    //
    // Exchange::IScriptEngine::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void URLChanged(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeScriptEngineNotificationStubMethods[] = {
        // (0) virtual void URLChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IScriptEngine::INotification* implementation = reinterpret_cast<Exchange::IScriptEngine::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URL = reader.Text();

            implementation->URLChanged(static_cast<const string&>(_URL));
        }
        , nullptr
    }; // ExchangeScriptEngineNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IScriptEngine interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IScriptEngine::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IScriptEngine::INotification*) = 0
    //  (2) virtual Core::hresult URL(string&) const = 0
    //  (3) virtual Core::hresult URL(const string&) = 0
    //

    class ExchangeScriptEngineProxy final : public ProxyStub::UnknownProxyType<Exchange::IScriptEngine> {
    public:
        ExchangeScriptEngineProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult Register(Exchange::IScriptEngine::INotification* _sink) override
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

        Core::hresult Unregister(const Exchange::IScriptEngine::INotification* _sink) override
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

        Core::hresult URL(string& _url) const override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    _url = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult URL(const string& _url) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_url));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeScriptEngineProxy

    //
    // Exchange::IScriptEngine::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void URLChanged(const string&) = 0
    //

    class ExchangeScriptEngineNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IScriptEngine::INotification> {
    public:
        ExchangeScriptEngineNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void URLChanged(const string& _URL) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_URL));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeScriptEngineNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IScriptEngine, ExchangeScriptEngineStubMethods> ExchangeScriptEngineStub;
        typedef ProxyStub::UnknownStubType<Exchange::IScriptEngine::INotification, ExchangeScriptEngineNotificationStubMethods> ExchangeScriptEngineNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IScriptEngine, ExchangeScriptEngineProxy, ExchangeScriptEngineStub>();
                RPC::Administrator::Instance().Announce<Exchange::IScriptEngine::INotification, ExchangeScriptEngineNotificationProxy, ExchangeScriptEngineNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IScriptEngine>();
                RPC::Administrator::Instance().Recall<Exchange::IScriptEngine::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
