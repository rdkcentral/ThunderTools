//
// generated automatically from "IDsgccClient.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IDsgccClient
//   - class Exchange::IDsgccClient::INotification
//

#include "Module.h"
#include "IDsgccClient.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IDsgccClient interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual string GetChannels() const = 0
    //  (2) virtual string State() const = 0
    //  (3) virtual void Restart() = 0
    //  (4) virtual void Callback(Exchange::IDsgccClient::INotification*) = 0
    //  (5) virtual void DsgccClientSet(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeDsgccClientStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDsgccClient* implementation = reinterpret_cast<Exchange::IDsgccClient*>(message->Parameters().Implementation());
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

        // (1) virtual string GetChannels() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDsgccClient* implementation = reinterpret_cast<const Exchange::IDsgccClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->GetChannels();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual string State() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDsgccClient* implementation = reinterpret_cast<const Exchange::IDsgccClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->State();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (3) virtual void Restart() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDsgccClient* implementation = reinterpret_cast<Exchange::IDsgccClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Restart();
        },

        // (4) virtual void Callback(Exchange::IDsgccClient::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDsgccClient* implementation = reinterpret_cast<Exchange::IDsgccClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::IDsgccClient::INotification* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            implementation->Callback(_callback);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (5) virtual void DsgccClientSet(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDsgccClient* implementation = reinterpret_cast<Exchange::IDsgccClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _str = reader.Text();

            implementation->DsgccClientSet(static_cast<const string&>(_str));
        }
        , nullptr
    }; // ExchangeDsgccClientStubMethods

    //
    // Exchange::IDsgccClient::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const Exchange::IDsgccClient::state) = 0
    //

    ProxyStub::MethodHandler ExchangeDsgccClientNotificationStubMethods[] = {
        // (0) virtual void StateChange(const Exchange::IDsgccClient::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDsgccClient::INotification* implementation = reinterpret_cast<Exchange::IDsgccClient::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IDsgccClient::state _newState = reader.Number<Exchange::IDsgccClient::state>();

            implementation->StateChange(_newState);
        }
        , nullptr
    }; // ExchangeDsgccClientNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IDsgccClient interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual string GetChannels() const = 0
    //  (2) virtual string State() const = 0
    //  (3) virtual void Restart() = 0
    //  (4) virtual void Callback(Exchange::IDsgccClient::INotification*) = 0
    //  (5) virtual void DsgccClientSet(const string&) = 0
    //

    class ExchangeDsgccClientProxy final : public ProxyStub::UnknownProxyType<Exchange::IDsgccClient> {
    public:
        ExchangeDsgccClientProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        string GetChannels() const override
        {
            IPCMessage message(BaseClass::Message(1));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        string State() const override
        {
            IPCMessage message(BaseClass::Message(2));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Restart() override
        {
            IPCMessage message(BaseClass::Message(3));

            UnknownProxyType::Invoke(message);
        }

        void Callback(Exchange::IDsgccClient::INotification* _callback) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void DsgccClientSet(const string& _str) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_str));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeDsgccClientProxy

    //
    // Exchange::IDsgccClient::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const Exchange::IDsgccClient::state) = 0
    //

    class ExchangeDsgccClientNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IDsgccClient::INotification> {
    public:
        ExchangeDsgccClientNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void StateChange(const Exchange::IDsgccClient::state _newState) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDsgccClient::state>(_newState);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeDsgccClientNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IDsgccClient, ExchangeDsgccClientStubMethods> ExchangeDsgccClientStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDsgccClient::INotification, ExchangeDsgccClientNotificationStubMethods> ExchangeDsgccClientNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IDsgccClient, ExchangeDsgccClientProxy, ExchangeDsgccClientStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDsgccClient::INotification, ExchangeDsgccClientNotificationProxy, ExchangeDsgccClientNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IDsgccClient>();
                RPC::Administrator::Instance().Recall<Exchange::IDsgccClient::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
