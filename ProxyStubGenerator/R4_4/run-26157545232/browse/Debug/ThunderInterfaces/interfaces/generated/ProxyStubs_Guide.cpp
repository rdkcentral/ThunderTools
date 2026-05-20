//
// generated automatically from "IGuide.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IGuide
//   - class Exchange::IGuide::INotification
//

#include "Module.h"
#include "IGuide.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IGuide interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t StartParser(PluginHost::IShell*) = 0
    //  (1) virtual const string GetChannels() = 0
    //  (2) virtual const string GetPrograms() = 0
    //  (3) virtual const string GetCurrentProgram(const string&) = 0
    //  (4) virtual const string GetAudioLanguages(const uint32_t) = 0
    //  (5) virtual const string GetSubtitleLanguages(const uint32_t) = 0
    //  (6) virtual bool SetParentalControlPin(const string&, const string&) = 0
    //  (7) virtual bool SetParentalControl(const string&, const bool) = 0
    //  (8) virtual bool IsParentalControlled() = 0
    //  (9) virtual bool SetParentalLock(const string&, const bool, const string&) = 0
    //  (10) virtual bool IsParentalLocked(const string&) = 0
    //  (11) virtual void Register(Exchange::IGuide::INotification*) = 0
    //  (12) virtual void Unregister(Exchange::IGuide::INotification*) = 0
    //

    ProxyStub::MethodHandler ExchangeGuideStubMethods[] = {
        // (0) virtual uint32_t StartParser(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_6d3c490aImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_6d3c490a = nullptr;
            ProxyStub::UnknownProxy* parameter_6d3c490aProxy = nullptr;
            if (parameter_6d3c490aImplementation != 0) {
                parameter_6d3c490aProxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_6d3c490aImplementation, false, _parameter_6d3c490a);

                ASSERT((_parameter_6d3c490a != nullptr) && (parameter_6d3c490aProxy != nullptr));
            }

            uint32_t result = implementation->StartParser(_parameter_6d3c490a);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (parameter_6d3c490aProxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_6d3c490aProxy, message->Response());
            }
        },

        // (1) virtual const string GetChannels() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            const string result = implementation->GetChannels();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual const string GetPrograms() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            const string result = implementation->GetPrograms();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (3) virtual const string GetCurrentProgram(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_4a43ea7f = reader.Text();

            const string result = implementation->GetCurrentProgram(static_cast<const string&>(_parameter_4a43ea7f));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual const string GetAudioLanguages(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _parameter_c3e8fb9f = reader.Number<uint32_t>();

            const string result = implementation->GetAudioLanguages(_parameter_c3e8fb9f);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (5) virtual const string GetSubtitleLanguages(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _parameter_26188763 = reader.Number<uint32_t>();

            const string result = implementation->GetSubtitleLanguages(_parameter_26188763);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (6) virtual bool SetParentalControlPin(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_6ff5414f = reader.Text();
            const string _parameter_ca57fe19 = reader.Text();

            bool result = implementation->SetParentalControlPin(static_cast<const string&>(_parameter_6ff5414f), static_cast<const string&>(_parameter_ca57fe19));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (7) virtual bool SetParentalControl(const string&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_b871a8da = reader.Text();
            const bool _parameter_8b80c645 = reader.Boolean();

            bool result = implementation->SetParentalControl(static_cast<const string&>(_parameter_b871a8da), _parameter_8b80c645);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (8) virtual bool IsParentalControlled() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsParentalControlled();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (9) virtual bool SetParentalLock(const string&, const bool, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_46ebe071 = reader.Text();
            const bool _parameter_ca620d0d = reader.Boolean();
            const string _parameter_949b58ed = reader.Text();

            bool result = implementation->SetParentalLock(static_cast<const string&>(_parameter_46ebe071), _parameter_ca620d0d, static_cast<const string&>(_parameter_949b58ed));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (10) virtual bool IsParentalLocked(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_4935ad4f = reader.Text();

            bool result = implementation->IsParentalLocked(static_cast<const string&>(_parameter_4935ad4f));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (11) virtual void Register(Exchange::IGuide::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_0b6040c7Implementation = reader.Number<Core::instance_id>();

            Exchange::IGuide::INotification* _parameter_0b6040c7 = nullptr;
            ProxyStub::UnknownProxy* parameter_0b6040c7Proxy = nullptr;
            if (parameter_0b6040c7Implementation != 0) {
                parameter_0b6040c7Proxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_0b6040c7Implementation, false, _parameter_0b6040c7);

                ASSERT((_parameter_0b6040c7 != nullptr) && (parameter_0b6040c7Proxy != nullptr));
            }

            implementation->Register(_parameter_0b6040c7);

            if (parameter_0b6040c7Proxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_0b6040c7Proxy, message->Response());
            }
        },

        // (12) virtual void Unregister(Exchange::IGuide::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide* implementation = reinterpret_cast<Exchange::IGuide*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id parameter_caff3c5fImplementation = reader.Number<Core::instance_id>();

            Exchange::IGuide::INotification* _parameter_caff3c5f = nullptr;
            ProxyStub::UnknownProxy* parameter_caff3c5fProxy = nullptr;
            if (parameter_caff3c5fImplementation != 0) {
                parameter_caff3c5fProxy = RPC::Administrator::Instance().ProxyInstance(channel, parameter_caff3c5fImplementation, false, _parameter_caff3c5f);

                ASSERT((_parameter_caff3c5f != nullptr) && (parameter_caff3c5fProxy != nullptr));
            }

            implementation->Unregister(_parameter_caff3c5f);

            if (parameter_caff3c5fProxy != nullptr) {
                RPC::Administrator::Instance().Release(parameter_caff3c5fProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeGuideStubMethods

    //
    // Exchange::IGuide::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void EITBroadcast() = 0
    //  (1) virtual void EmergencyAlert() = 0
    //  (2) virtual void ParentalControlChanged() = 0
    //  (3) virtual void ParentalLockChanged(const string&) = 0
    //  (4) virtual void TestNotification(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeGuideNotificationStubMethods[] = {
        // (0) virtual void EITBroadcast() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide::INotification* implementation = reinterpret_cast<Exchange::IGuide::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->EITBroadcast();
        },

        // (1) virtual void EmergencyAlert() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide::INotification* implementation = reinterpret_cast<Exchange::IGuide::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->EmergencyAlert();
        },

        // (2) virtual void ParentalControlChanged() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide::INotification* implementation = reinterpret_cast<Exchange::IGuide::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->ParentalControlChanged();
        },

        // (3) virtual void ParentalLockChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide::INotification* implementation = reinterpret_cast<Exchange::IGuide::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_33c9370a = reader.Text();

            implementation->ParentalLockChanged(static_cast<const string&>(_parameter_33c9370a));
        },

        // (4) virtual void TestNotification(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IGuide::INotification* implementation = reinterpret_cast<Exchange::IGuide::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_65b34c82 = reader.Text();

            implementation->TestNotification(static_cast<const string&>(_parameter_65b34c82));
        }
        , nullptr
    }; // ExchangeGuideNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IGuide interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t StartParser(PluginHost::IShell*) = 0
    //  (1) virtual const string GetChannels() = 0
    //  (2) virtual const string GetPrograms() = 0
    //  (3) virtual const string GetCurrentProgram(const string&) = 0
    //  (4) virtual const string GetAudioLanguages(const uint32_t) = 0
    //  (5) virtual const string GetSubtitleLanguages(const uint32_t) = 0
    //  (6) virtual bool SetParentalControlPin(const string&, const string&) = 0
    //  (7) virtual bool SetParentalControl(const string&, const bool) = 0
    //  (8) virtual bool IsParentalControlled() = 0
    //  (9) virtual bool SetParentalLock(const string&, const bool, const string&) = 0
    //  (10) virtual bool IsParentalLocked(const string&) = 0
    //  (11) virtual void Register(Exchange::IGuide::INotification*) = 0
    //  (12) virtual void Unregister(Exchange::IGuide::INotification*) = 0
    //

    class ExchangeGuideProxy final : public ProxyStub::UnknownProxyType<Exchange::IGuide> {
    public:
        ExchangeGuideProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t StartParser(PluginHost::IShell* _parameter_6d3c490a) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_6d3c490a));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        const string GetChannels() override
        {
            IPCMessage message(BaseClass::Message(1));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        const string GetPrograms() override
        {
            IPCMessage message(BaseClass::Message(2));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        const string GetCurrentProgram(const string& _parameter_4a43ea7f) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_4a43ea7f));

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        const string GetAudioLanguages(const uint32_t _parameter_c3e8fb9f) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_parameter_c3e8fb9f);

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        const string GetSubtitleLanguages(const uint32_t _parameter_26188763) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_parameter_26188763);

            string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        bool SetParentalControlPin(const string& _parameter_6ff5414f, const string& _parameter_ca57fe19) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_6ff5414f));
            writer.Text(static_cast<const string&>(_parameter_ca57fe19));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool SetParentalControl(const string& _parameter_b871a8da, const bool _parameter_8b80c645) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_b871a8da));
            writer.Boolean(_parameter_8b80c645);

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool IsParentalControlled() override
        {
            IPCMessage message(BaseClass::Message(8));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool SetParentalLock(const string& _parameter_46ebe071, const bool _parameter_ca620d0d, const string& _parameter_949b58ed) override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_46ebe071));
            writer.Boolean(_parameter_ca620d0d);
            writer.Text(static_cast<const string&>(_parameter_949b58ed));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        bool IsParentalLocked(const string& _parameter_4935ad4f) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_4935ad4f));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        void Register(Exchange::IGuide::INotification* _parameter_0b6040c7) override
        {
            IPCMessage message(BaseClass::Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_0b6040c7));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IGuide::INotification* _parameter_caff3c5f) override
        {
            IPCMessage message(BaseClass::Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_caff3c5f));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeGuideProxy

    //
    // Exchange::IGuide::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void EITBroadcast() = 0
    //  (1) virtual void EmergencyAlert() = 0
    //  (2) virtual void ParentalControlChanged() = 0
    //  (3) virtual void ParentalLockChanged(const string&) = 0
    //  (4) virtual void TestNotification(const string&) = 0
    //

    class ExchangeGuideNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IGuide::INotification> {
    public:
        ExchangeGuideNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void EITBroadcast() override
        {
            IPCMessage message(BaseClass::Message(0));

            UnknownProxyType::Invoke(message);
        }

        void EmergencyAlert() override
        {
            IPCMessage message(BaseClass::Message(1));

            UnknownProxyType::Invoke(message);
        }

        void ParentalControlChanged() override
        {
            IPCMessage message(BaseClass::Message(2));

            UnknownProxyType::Invoke(message);
        }

        void ParentalLockChanged(const string& _parameter_33c9370a) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_33c9370a));

            UnknownProxyType::Invoke(message);
        }

        void TestNotification(const string& _parameter_65b34c82) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_parameter_65b34c82));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeGuideNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IGuide, ExchangeGuideStubMethods> ExchangeGuideStub;
        typedef ProxyStub::UnknownStubType<Exchange::IGuide::INotification, ExchangeGuideNotificationStubMethods> ExchangeGuideNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IGuide, ExchangeGuideProxy, ExchangeGuideStub>();
                RPC::Administrator::Instance().Announce<Exchange::IGuide::INotification, ExchangeGuideNotificationProxy, ExchangeGuideNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IGuide>();
                RPC::Administrator::Instance().Recall<Exchange::IGuide::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
