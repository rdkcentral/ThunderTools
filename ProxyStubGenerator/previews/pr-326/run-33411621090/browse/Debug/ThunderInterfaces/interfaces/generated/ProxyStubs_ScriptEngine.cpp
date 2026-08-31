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

namespace Thunder {

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

    static ProxyStub::MethodHandler ExchangeScriptEngineStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IScriptEngine::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IScriptEngine* implementation = reinterpret_cast<Exchange::IScriptEngine*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IScriptEngine::INotification* _sink{};
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

        // (1) virtual Core::hresult Unregister(const Exchange::IScriptEngine::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IScriptEngine* implementation = reinterpret_cast<Exchange::IScriptEngine*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IScriptEngine::INotification* _sink{};
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

    static ProxyStub::MethodHandler ExchangeScriptEngineNotificationStubMethods[] = {
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

        Core::hresult Register(Exchange::IScriptEngine::INotification* _sink) override
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

        Core::hresult Unregister(const Exchange::IScriptEngine::INotification* _sink) override
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

        Core::hresult URL(string& _url) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _url = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult URL(const string& _url) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_url);

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

        void URLChanged(const string& _URL) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URL);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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
