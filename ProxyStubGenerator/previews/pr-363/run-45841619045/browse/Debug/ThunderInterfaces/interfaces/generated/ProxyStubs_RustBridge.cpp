//
// generated automatically from "IRustBridge.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IRustBridge
//   - class Exchange::IRustBridge::ICallback
//

#include "Module.h"
#include "IRustBridge.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IRustBridge interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*, Exchange::IRustBridge::ICallback*) = 0
    //  (1) virtual void Request(const uint32_t, const string&, const string&, const string&) = 0
    //  (2) virtual void Event(const string&, const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeRustBridgeStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*, Exchange::IRustBridge::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRustBridge* implementation = reinterpret_cast<Exchange::IRustBridge*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _frameworkInstanceId__ = reader.Number<Core::instance_id>();
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _framework{};
            ProxyStub::UnknownProxy* _frameworkProxy__ = nullptr;
            if (_frameworkInstanceId__ != 0) {
                _frameworkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _frameworkInstanceId__, false, _framework);
                ASSERT((_framework != nullptr) && (_frameworkProxy__ != nullptr));
            }
            Exchange::IRustBridge::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            uint32_t result = implementation->Configure(_framework, _callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_frameworkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_frameworkProxy__, message->Response());
            }
            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (1) virtual void Request(const uint32_t, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRustBridge* implementation = reinterpret_cast<Exchange::IRustBridge*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();
            const string _context = reader.Text();
            const string _method = reader.Text();
            const string _parmeters = reader.Text();

            implementation->Request(_id, static_cast<const string&>(_context), static_cast<const string&>(_method), static_cast<const string&>(_parmeters));
        },

        // (2) virtual void Event(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRustBridge* implementation = reinterpret_cast<Exchange::IRustBridge*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _event = reader.Text();
            const string _parmeters = reader.Text();

            implementation->Event(static_cast<const string&>(_event), static_cast<const string&>(_parmeters));
        }
        , nullptr
    }; // ExchangeRustBridgeStubMethods

    //
    // Exchange::IRustBridge::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Invoke(const string&, const string&, const string&, string&, uint32_t&) = 0
    //  (1) virtual void Event(const string&, const string&) = 0
    //  (2) virtual void Response(const uint32_t, const string&, const uint32_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeRustBridgeCallbackStubMethods[] = {
        // (0) virtual void Invoke(const string&, const string&, const string&, string&, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRustBridge::ICallback* implementation = reinterpret_cast<Exchange::IRustBridge::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _context = reader.Text();
            const string _method = reader.Text();
            const string _parmeters = reader.Text();

            string _response{};
            uint32_t _result{};

            implementation->Invoke(static_cast<const string&>(_context), static_cast<const string&>(_method), static_cast<const string&>(_parmeters), _response, _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(_response);
            writer.Number<uint32_t>(_result);
        },

        // (1) virtual void Event(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRustBridge::ICallback* implementation = reinterpret_cast<Exchange::IRustBridge::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _event = reader.Text();
            const string _parmeters = reader.Text();

            implementation->Event(static_cast<const string&>(_event), static_cast<const string&>(_parmeters));
        },

        // (2) virtual void Response(const uint32_t, const string&, const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRustBridge::ICallback* implementation = reinterpret_cast<Exchange::IRustBridge::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();
            const string _response = reader.Text();
            const uint32_t _error = reader.Number<uint32_t>();

            implementation->Response(_id, static_cast<const string&>(_response), _error);
        }
        , nullptr
    }; // ExchangeRustBridgeCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IRustBridge interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*, Exchange::IRustBridge::ICallback*) = 0
    //  (1) virtual void Request(const uint32_t, const string&, const string&, const string&) = 0
    //  (2) virtual void Event(const string&, const string&) = 0
    //

    class ExchangeRustBridgeProxy final : public ProxyStub::UnknownProxyType<Exchange::IRustBridge> {
    public:
        ExchangeRustBridgeProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Configure(PluginHost::IShell* _framework, Exchange::IRustBridge::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_framework));
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

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

        void Request(const uint32_t _id, const string& _context, const string& _method, const string& _parmeters) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Text(_context);
            writer.Text(_method);
            writer.Text(_parmeters);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Event(const string& _event, const string& _parmeters) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_event);
            writer.Text(_parmeters);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

    }; // class ExchangeRustBridgeProxy

    //
    // Exchange::IRustBridge::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Invoke(const string&, const string&, const string&, string&, uint32_t&) = 0
    //  (1) virtual void Event(const string&, const string&) = 0
    //  (2) virtual void Response(const uint32_t, const string&, const uint32_t) = 0
    //

    class ExchangeRustBridgeCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IRustBridge::ICallback> {
    public:
        ExchangeRustBridgeCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Invoke(const string& _context, const string& _method, const string& _parmeters, string& _response, uint32_t& _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_context);
            writer.Text(_method);
            writer.Text(_parmeters);

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                _response = reader.Text();
                _result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Event(const string& _event, const string& _parmeters) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_event);
            writer.Text(_parmeters);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Response(const uint32_t _id, const string& _response, const uint32_t _error) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);
            writer.Text(_response);
            writer.Number<uint32_t>(_error);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeRustBridgeCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IRustBridge, ExchangeRustBridgeStubMethods> ExchangeRustBridgeStub;
        typedef ProxyStub::UnknownStubType<Exchange::IRustBridge::ICallback, ExchangeRustBridgeCallbackStubMethods> ExchangeRustBridgeCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IRustBridge, ExchangeRustBridgeProxy, ExchangeRustBridgeStub>();
                RPC::Administrator::Instance().Announce<Exchange::IRustBridge::ICallback, ExchangeRustBridgeCallbackProxy, ExchangeRustBridgeCallbackStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IRustBridge>();
                RPC::Administrator::Instance().Recall<Exchange::IRustBridge::ICallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
