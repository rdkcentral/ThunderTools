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

namespace Thunder {

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

    static ProxyStub::MethodHandler ExchangeDsgccClientStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDsgccClient* implementation = reinterpret_cast<Exchange::IDsgccClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _serviceInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _service{};
            ProxyStub::UnknownProxy* _serviceProxy__ = nullptr;
            if (_serviceInstanceId__ != 0) {
                _serviceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _serviceInstanceId__, false, _service);
                ASSERT((_service != nullptr) && (_serviceProxy__ != nullptr));
            }

            uint32_t result = implementation->Configure(_service);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_serviceProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_serviceProxy__, message->Response());
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
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IDsgccClient::INotification* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            implementation->Callback(_callback);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
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

    static ProxyStub::MethodHandler ExchangeDsgccClientNotificationStubMethods[] = {
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

        uint32_t Configure(PluginHost::IShell* _service) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

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

        string GetChannels() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

        string State() const override
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

        void Restart() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Callback(Exchange::IDsgccClient::INotification* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void DsgccClientSet(const string& _str) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_str);

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

        void StateChange(const Exchange::IDsgccClient::state _newState) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IDsgccClient::state>(_newState);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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
