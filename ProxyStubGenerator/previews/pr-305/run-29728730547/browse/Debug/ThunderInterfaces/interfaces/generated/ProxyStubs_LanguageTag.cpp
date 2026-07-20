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

namespace Thunder {

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

    static ProxyStub::MethodHandler ExchangeLanguageTagStubMethods[] = {
        // (0) virtual void Register(Exchange::ILanguageTag::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILanguageTag* implementation = reinterpret_cast<Exchange::ILanguageTag*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ILanguageTag::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(const Exchange::ILanguageTag::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILanguageTag* implementation = reinterpret_cast<Exchange::ILanguageTag*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::ILanguageTag::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
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

    static ProxyStub::MethodHandler ExchangeLanguageTagNotificationStubMethods[] = {
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

        void Register(Exchange::ILanguageTag::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(const Exchange::ILanguageTag::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Language(string& _language) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _language = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Language(const string& _language) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_language);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
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

        void LanguageChanged(const string& _language) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_language);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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
