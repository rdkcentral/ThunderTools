//
// generated automatically from "ILanguageTag.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ILanguageTag
//   - class Exchange::ILanguageTag::INotification
//

#include "Module.h"
#include "ILanguageTag.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ILanguageTag interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::ILanguageTag::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::ILanguageTag::INotification*) = 0
    //  (2) virtual uint32_t Language(string&) const = 0
    //  (3) virtual uint32_t Language(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeLanguageTagStubMethods[] = {
        // (0) virtual void Register(Exchange::ILanguageTag::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILanguageTag* implementation = reinterpret_cast<Exchange::ILanguageTag*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::ILanguageTag::INotification* _sink = nullptr;
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

        // (1) virtual void Unregister(const Exchange::ILanguageTag::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILanguageTag* implementation = reinterpret_cast<Exchange::ILanguageTag*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::ILanguageTag::INotification* _sink = nullptr;
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

        // (2) virtual uint32_t Language(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILanguageTag* implementation = reinterpret_cast<const Exchange::ILanguageTag*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _language{};

            uint32_t result = implementation->Language(_language);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_language);
        },

        // (3) virtual uint32_t Language(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILanguageTag* implementation = reinterpret_cast<Exchange::ILanguageTag*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _language = reader.Text();

            uint32_t result = implementation->Language(static_cast<const string&>(_language));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeLanguageTagStubMethods

    //
    // Exchange::ILanguageTag::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void LanguageChanged(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeLanguageTagNotificationStubMethods[] = {
        // (0) virtual void LanguageChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILanguageTag::INotification* implementation = reinterpret_cast<Exchange::ILanguageTag::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _language = reader.Text();

            implementation->LanguageChanged(static_cast<const string&>(_language));
        }
        , nullptr
    }; // ExchangeLanguageTagNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ILanguageTag interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::ILanguageTag::INotification*) = 0
    //  (1) virtual void Unregister(const Exchange::ILanguageTag::INotification*) = 0
    //  (2) virtual uint32_t Language(string&) const = 0
    //  (3) virtual uint32_t Language(const string&) = 0
    //

    class ExchangeLanguageTagProxy final : public ProxyStub::UnknownProxyType<Exchange::ILanguageTag> {
    public:
        ExchangeLanguageTagProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::ILanguageTag::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(const Exchange::ILanguageTag::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Language(string& _language) const override
        {
            IPCMessage message(BaseClass::Message(2));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _language = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Language(const string& _language) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_language));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeLanguageTagProxy

    //
    // Exchange::ILanguageTag::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void LanguageChanged(const string&) = 0
    //

    class ExchangeLanguageTagNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::ILanguageTag::INotification> {
    public:
        ExchangeLanguageTagNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void LanguageChanged(const string& _language) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_language));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeLanguageTagNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ILanguageTag, ExchangeLanguageTagStubMethods> ExchangeLanguageTagStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILanguageTag::INotification, ExchangeLanguageTagNotificationStubMethods> ExchangeLanguageTagNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ILanguageTag, ExchangeLanguageTagProxy, ExchangeLanguageTagStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILanguageTag::INotification, ExchangeLanguageTagNotificationProxy, ExchangeLanguageTagNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ILanguageTag>();
                RPC::Administrator::Instance().Recall<Exchange::ILanguageTag::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
