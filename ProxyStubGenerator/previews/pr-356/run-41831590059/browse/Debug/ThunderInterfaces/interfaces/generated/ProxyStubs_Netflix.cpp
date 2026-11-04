//
// generated automatically from "INetflix.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::INetflix
//   - class Exchange::INetflix::INotification
//

#include "Module.h"
#include "INetflix.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::INetflix interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::INetflix::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::INetflix::INotification*) = 0
    //  (2) virtual void SystemCommand(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeNetflixStubMethods[] = {
        // (0) virtual void Register(Exchange::INetflix::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetflix* implementation = reinterpret_cast<Exchange::INetflix*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _netflixInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::INetflix::INotification* _netflix{};
            ProxyStub::UnknownProxy* _netflixProxy__ = nullptr;
            if (_netflixInstanceId__ != 0) {
                _netflixProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _netflixInstanceId__, false, _netflix);
                ASSERT((_netflix != nullptr) && (_netflixProxy__ != nullptr));
            }

            implementation->Register(_netflix);

            if (_netflixProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_netflixProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::INetflix::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetflix* implementation = reinterpret_cast<Exchange::INetflix*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _netflixInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::INetflix::INotification* _netflix{};
            ProxyStub::UnknownProxy* _netflixProxy__ = nullptr;
            if (_netflixInstanceId__ != 0) {
                _netflixProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _netflixInstanceId__, false, _netflix);
                ASSERT((_netflix != nullptr) && (_netflixProxy__ != nullptr));
            }

            implementation->Unregister(_netflix);

            if (_netflixProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_netflixProxy__, message->Response());
            }
        },

        // (2) virtual void SystemCommand(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetflix* implementation = reinterpret_cast<Exchange::INetflix*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _command = reader.Text();

            implementation->SystemCommand(static_cast<const string&>(_command));
        }
        , nullptr
    }; // ExchangeNetflixStubMethods

    //
    // Exchange::INetflix::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const Exchange::INetflix::state) = 0
    //  (1) virtual void Exit(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeNetflixNotificationStubMethods[] = {
        // (0) virtual void StateChange(const Exchange::INetflix::state) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetflix::INotification* implementation = reinterpret_cast<Exchange::INetflix::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::INetflix::state _state = reader.Number<Exchange::INetflix::state>();

            implementation->StateChange(_state);
        },

        // (1) virtual void Exit(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetflix::INotification* implementation = reinterpret_cast<Exchange::INetflix::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _exitCode = reader.Number<uint32_t>();

            implementation->Exit(_exitCode);
        }
        , nullptr
    }; // ExchangeNetflixNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::INetflix interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::INetflix::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::INetflix::INotification*) = 0
    //  (2) virtual void SystemCommand(const string&) = 0
    //

    class ExchangeNetflixProxy final : public ProxyStub::UnknownProxyType<Exchange::INetflix> {
    public:
        ExchangeNetflixProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::INetflix::INotification* _netflix) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_netflix));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::INetflix::INotification* _netflix) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_netflix));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void SystemCommand(const string& _command) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_command);

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

    }; // class ExchangeNetflixProxy

    //
    // Exchange::INetflix::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StateChange(const Exchange::INetflix::state) = 0
    //  (1) virtual void Exit(const uint32_t) = 0
    //

    class ExchangeNetflixNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::INetflix::INotification> {
    public:
        ExchangeNetflixNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StateChange(const Exchange::INetflix::state _state) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::INetflix::state>(_state);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Exit(const uint32_t _exitCode) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_exitCode);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeNetflixNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::INetflix, ExchangeNetflixStubMethods> ExchangeNetflixStub;
        typedef ProxyStub::UnknownStubType<Exchange::INetflix::INotification, ExchangeNetflixNotificationStubMethods> ExchangeNetflixNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::INetflix, ExchangeNetflixProxy, ExchangeNetflixStub>();
                RPC::Administrator::Instance().Announce<Exchange::INetflix::INotification, ExchangeNetflixNotificationProxy, ExchangeNetflixNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::INetflix>();
                RPC::Administrator::Instance().Recall<Exchange::INetflix::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
