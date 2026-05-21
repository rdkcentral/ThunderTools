//
// generated automatically from "IAVSClient.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IAVSController
//   - class Exchange::IAVSController::INotification
//   - class Exchange::IAVSClient
//

#include "Module.h"
#include "IAVSClient.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IAVSController interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IAVSController::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IAVSController::INotification*) = 0
    //  (2) virtual uint32_t Mute(const bool) = 0
    //  (3) virtual uint32_t Record(const bool) = 0
    //

    ProxyStub::MethodHandler ExchangeAVSControllerStubMethods[] = {
        // (0) virtual void Register(Exchange::IAVSController::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSController* implementation = reinterpret_cast<Exchange::IAVSController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IAVSController::INotification* _sink = nullptr;
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

        // (1) virtual void Unregister(const Exchange::IAVSController::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSController* implementation = reinterpret_cast<Exchange::IAVSController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IAVSController::INotification* _sink = nullptr;
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

        // (2) virtual uint32_t Mute(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSController* implementation = reinterpret_cast<Exchange::IAVSController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _muted = reader.Boolean();

            uint32_t result = implementation->Mute(_muted);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Record(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSController* implementation = reinterpret_cast<Exchange::IAVSController*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _started = reader.Boolean();

            uint32_t result = implementation->Record(_started);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeAVSControllerStubMethods

    //
    // Exchange::IAVSController::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void DialogueStateChange(const Exchange::IAVSController::INotification::dialoguestate) = 0
    //

    ProxyStub::MethodHandler ExchangeAVSControllerNotificationStubMethods[] = {
        // (0) virtual void DialogueStateChange(const Exchange::IAVSController::INotification::dialoguestate) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSController::INotification* implementation = reinterpret_cast<Exchange::IAVSController::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IAVSController::INotification::dialoguestate _state = reader.Number<Exchange::IAVSController::INotification::dialoguestate>();

            implementation->DialogueStateChange(_state);
        }
        , nullptr
    }; // ExchangeAVSControllerNotificationStubMethods

    //
    // Exchange::IAVSClient interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Initialize(PluginHost::IShell*, const string&) = 0
    //  (1) virtual bool Deinitialize() = 0
    //  (2) virtual Exchange::IAVSController* Controller() = 0
    //  (3) virtual void StateChange(PluginHost::IShell*) = 0
    //

    ProxyStub::MethodHandler ExchangeAVSClientStubMethods[] = {
        // (0) virtual bool Initialize(PluginHost::IShell*, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSClient* implementation = reinterpret_cast<Exchange::IAVSClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id serviceImplementation = reader.Number<Core::instance_id>();
            const string _configuration = reader.Text();

            PluginHost::IShell* _service = nullptr;
            ProxyStub::UnknownProxy* serviceProxy = nullptr;
            if (serviceImplementation != 0) {
                serviceProxy = RPC::Administrator::Instance().ProxyInstance(channel, serviceImplementation, false, _service);

                ASSERT((_service != nullptr) && (serviceProxy != nullptr));
            }

            bool result = implementation->Initialize(_service, static_cast<const string&>(_configuration));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);

            if (serviceProxy != nullptr) {
                RPC::Administrator::Instance().Release(serviceProxy, message->Response());
            }
        },

        // (1) virtual bool Deinitialize() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSClient* implementation = reinterpret_cast<Exchange::IAVSClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->Deinitialize();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (2) virtual Exchange::IAVSController* Controller() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSClient* implementation = reinterpret_cast<Exchange::IAVSClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IAVSController* result = implementation->Controller();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (3) virtual void StateChange(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVSClient* implementation = reinterpret_cast<Exchange::IAVSClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id audioSourceImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _audioSource = nullptr;
            ProxyStub::UnknownProxy* audioSourceProxy = nullptr;
            if (audioSourceImplementation != 0) {
                audioSourceProxy = RPC::Administrator::Instance().ProxyInstance(channel, audioSourceImplementation, false, _audioSource);

                ASSERT((_audioSource != nullptr) && (audioSourceProxy != nullptr));
            }

            implementation->StateChange(_audioSource);

            if (audioSourceProxy != nullptr) {
                RPC::Administrator::Instance().Release(audioSourceProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeAVSClientStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IAVSController interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IAVSController::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::IAVSController::INotification*) = 0
    //  (2) virtual uint32_t Mute(const bool) = 0
    //  (3) virtual uint32_t Record(const bool) = 0
    //

    class ExchangeAVSControllerProxy final : public ProxyStub::UnknownProxyType<Exchange::IAVSController> {
    public:
        ExchangeAVSControllerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IAVSController::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(const Exchange::IAVSController::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Mute(const bool _muted) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_muted);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Record(const bool _started) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_started);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeAVSControllerProxy

    //
    // Exchange::IAVSController::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void DialogueStateChange(const Exchange::IAVSController::INotification::dialoguestate) = 0
    //

    class ExchangeAVSControllerNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IAVSController::INotification> {
    public:
        ExchangeAVSControllerNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void DialogueStateChange(const Exchange::IAVSController::INotification::dialoguestate _state) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IAVSController::INotification::dialoguestate>(_state);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeAVSControllerNotificationProxy

    //
    // Exchange::IAVSClient interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Initialize(PluginHost::IShell*, const string&) = 0
    //  (1) virtual bool Deinitialize() = 0
    //  (2) virtual Exchange::IAVSController* Controller() = 0
    //  (3) virtual void StateChange(PluginHost::IShell*) = 0
    //

    class ExchangeAVSClientProxy final : public ProxyStub::UnknownProxyType<Exchange::IAVSClient> {
    public:
        ExchangeAVSClientProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool Initialize(PluginHost::IShell* _service, const string& _configuration) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));
            writer.Text(static_cast<const string&>(_configuration));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            Complete(reader);

            return (result);
        }

        bool Deinitialize() override
        {
            IPCMessage message(BaseClass::Message(1));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Exchange::IAVSController* Controller() override
        {
            IPCMessage message(BaseClass::Message(2));

            Exchange::IAVSController* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IAVSController*>(Interface(reader.Number<Core::instance_id>(), Exchange::IAVSController::ID));

            return (result);
        }

        void StateChange(PluginHost::IShell* _audioSource) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_audioSource));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeAVSClientProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IAVSController, ExchangeAVSControllerStubMethods> ExchangeAVSControllerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAVSController::INotification, ExchangeAVSControllerNotificationStubMethods> ExchangeAVSControllerNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAVSClient, ExchangeAVSClientStubMethods> ExchangeAVSClientStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IAVSController, ExchangeAVSControllerProxy, ExchangeAVSControllerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IAVSController::INotification, ExchangeAVSControllerNotificationProxy, ExchangeAVSControllerNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IAVSClient, ExchangeAVSClientProxy, ExchangeAVSClientStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IAVSController>();
                RPC::Administrator::Instance().Recall<Exchange::IAVSController::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IAVSClient>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
