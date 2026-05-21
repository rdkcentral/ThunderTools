//
// generated automatically from "IRtspClient.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IRtspClient
//

#include "Module.h"
#include "IRtspClient.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IRtspClient interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual uint32_t Setup(const string&, uint32_t) = 0
    //  (2) virtual uint32_t Play(int32_t, uint32_t) = 0
    //  (3) virtual uint32_t Teardown() = 0
    //  (4) virtual void Set(const string&, const string&) = 0
    //  (5) virtual string Get(const string&) const = 0
    //

    ProxyStub::MethodHandler ExchangeRtspClientStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRtspClient* implementation = reinterpret_cast<Exchange::IRtspClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id serviceImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _service = nullptr;
            ProxyStub::UnknownProxy* serviceProxy = nullptr;
            if (serviceImplementation != 0) {
                serviceProxy = RPC::Administrator::Instance().ProxyInstance(channel, serviceImplementation, false, _service);

                ASSERT((_service != nullptr) && (serviceProxy != nullptr));
            }

            uint32_t result = implementation->Configure(_service);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (serviceProxy != nullptr) {
                RPC::Administrator::Instance().Release(serviceProxy, message->Response());
            }
        },

        // (1) virtual uint32_t Setup(const string&, uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRtspClient* implementation = reinterpret_cast<Exchange::IRtspClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _assetId = reader.Text();
            uint32_t _position = reader.Number<uint32_t>();

            uint32_t result = implementation->Setup(static_cast<const string&>(_assetId), _position);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Play(int32_t, uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRtspClient* implementation = reinterpret_cast<Exchange::IRtspClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            int32_t _scale = reader.Number<int32_t>();
            uint32_t _position = reader.Number<uint32_t>();

            uint32_t result = implementation->Play(_scale, _position);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Teardown() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRtspClient* implementation = reinterpret_cast<Exchange::IRtspClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Teardown();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual void Set(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IRtspClient* implementation = reinterpret_cast<Exchange::IRtspClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();
            const string _value = reader.Text();

            implementation->Set(static_cast<const string&>(_name), static_cast<const string&>(_value));
        },

        // (5) virtual string Get(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IRtspClient* implementation = reinterpret_cast<const Exchange::IRtspClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            string result = implementation->Get(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // ExchangeRtspClientStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IRtspClient interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual uint32_t Setup(const string&, uint32_t) = 0
    //  (2) virtual uint32_t Play(int32_t, uint32_t) = 0
    //  (3) virtual uint32_t Teardown() = 0
    //  (4) virtual void Set(const string&, const string&) = 0
    //  (5) virtual string Get(const string&) const = 0
    //

    class ExchangeRtspClientProxy final : public ProxyStub::UnknownProxyType<Exchange::IRtspClient> {
    public:
        ExchangeRtspClientProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Configure(PluginHost::IShell* _service) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Setup(const string& _assetId, uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_assetId));
            writer.Number<uint32_t>(_position);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Play(int32_t _scale, uint32_t _position) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_scale);
            writer.Number<uint32_t>(_position);

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        uint32_t Teardown() override
        {
            IPCMessage message(BaseClass::Message(3));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        void Set(const string& _name, const string& _value) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));
            writer.Text(static_cast<const string&>(_value));

            UnknownProxyType::Invoke(message);
        }

        string Get(const string& _name) const override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

    }; // class ExchangeRtspClientProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IRtspClient, ExchangeRtspClientStubMethods> ExchangeRtspClientStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IRtspClient, ExchangeRtspClientProxy, ExchangeRtspClientStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IRtspClient>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
