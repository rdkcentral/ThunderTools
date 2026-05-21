//
// generated automatically from "IUserSettings.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IUserSettings
//   - class Exchange::IUserSettings::INotification
//

#include "Module.h"
#include "IUserSettings.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IUserSettings interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IUserSettings::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IUserSettings::INotification*) = 0
    //  (2) virtual uint32_t SetAudioDescription(const bool) = 0
    //  (3) virtual uint32_t GetAudioDescription(bool&) const = 0
    //  (4) virtual uint32_t SetPreferredAudioLanguages(const string&) = 0
    //  (5) virtual uint32_t GetPreferredAudioLanguages(string&) const = 0
    //  (6) virtual uint32_t SetPresentationLanguage(const string&) = 0
    //  (7) virtual uint32_t GetPresentationLanguage(string&) const = 0
    //  (8) virtual uint32_t SetCaptions(const bool) = 0
    //  (9) virtual uint32_t GetCaptions(bool&) const = 0
    //  (10) virtual uint32_t SetPreferredCaptionsLanguages(const string&) = 0
    //  (11) virtual uint32_t GetPreferredCaptionsLanguages(string&) const = 0
    //  (12) virtual uint32_t SetPreferredClosedCaptionService(const string&) = 0
    //  (13) virtual uint32_t GetPreferredClosedCaptionService(string&) const = 0
    //  (14) virtual uint32_t SetPrivacyMode(const string&) = 0
    //  (15) virtual uint32_t GetPrivacyMode(string&) const = 0
    //

    ProxyStub::MethodHandler ExchangeUserSettingsStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::IUserSettings::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IUserSettings::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            uint32_t result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::IUserSettings::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id notificationImplementation = reader.Number<Core::instance_id>();

            Exchange::IUserSettings::INotification* _notification = nullptr;
            ProxyStub::UnknownProxy* notificationProxy = nullptr;
            if (notificationImplementation != 0) {
                notificationProxy = RPC::Administrator::Instance().ProxyInstance(channel, notificationImplementation, false, _notification);

                ASSERT((_notification != nullptr) && (notificationProxy != nullptr));
            }

            uint32_t result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (notificationProxy != nullptr) {
                RPC::Administrator::Instance().Release(notificationProxy, message->Response());
            }
        },

        // (2) virtual uint32_t SetAudioDescription(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _enabled = reader.Boolean();

            uint32_t result = implementation->SetAudioDescription(_enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t GetAudioDescription(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUserSettings* implementation = reinterpret_cast<const Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _enabled{};

            uint32_t result = implementation->GetAudioDescription(_enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_enabled);
        },

        // (4) virtual uint32_t SetPreferredAudioLanguages(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _preferredLanguages = reader.Text();

            uint32_t result = implementation->SetPreferredAudioLanguages(static_cast<const string&>(_preferredLanguages));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t GetPreferredAudioLanguages(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUserSettings* implementation = reinterpret_cast<const Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _preferredLanguages{};

            uint32_t result = implementation->GetPreferredAudioLanguages(_preferredLanguages);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_preferredLanguages);
        },

        // (6) virtual uint32_t SetPresentationLanguage(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _presentationLanguages = reader.Text();

            uint32_t result = implementation->SetPresentationLanguage(static_cast<const string&>(_presentationLanguages));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t GetPresentationLanguage(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUserSettings* implementation = reinterpret_cast<const Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _presentationLanguages{};

            uint32_t result = implementation->GetPresentationLanguage(_presentationLanguages);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_presentationLanguages);
        },

        // (8) virtual uint32_t SetCaptions(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _enabled = reader.Boolean();

            uint32_t result = implementation->SetCaptions(_enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t GetCaptions(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUserSettings* implementation = reinterpret_cast<const Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _enabled{};

            uint32_t result = implementation->GetCaptions(_enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_enabled);
        },

        // (10) virtual uint32_t SetPreferredCaptionsLanguages(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _preferredLanguages = reader.Text();

            uint32_t result = implementation->SetPreferredCaptionsLanguages(static_cast<const string&>(_preferredLanguages));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (11) virtual uint32_t GetPreferredCaptionsLanguages(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUserSettings* implementation = reinterpret_cast<const Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _preferredLanguages{};

            uint32_t result = implementation->GetPreferredCaptionsLanguages(_preferredLanguages);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_preferredLanguages);
        },

        // (12) virtual uint32_t SetPreferredClosedCaptionService(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _service = reader.Text();

            uint32_t result = implementation->SetPreferredClosedCaptionService(static_cast<const string&>(_service));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (13) virtual uint32_t GetPreferredClosedCaptionService(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUserSettings* implementation = reinterpret_cast<const Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _service{};

            uint32_t result = implementation->GetPreferredClosedCaptionService(_service);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_service);
        },

        // (14) virtual uint32_t SetPrivacyMode(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings* implementation = reinterpret_cast<Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _privacyMode = reader.Text();

            uint32_t result = implementation->SetPrivacyMode(static_cast<const string&>(_privacyMode));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (15) virtual uint32_t GetPrivacyMode(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IUserSettings* implementation = reinterpret_cast<const Exchange::IUserSettings*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _privacyMode{};

            uint32_t result = implementation->GetPrivacyMode(_privacyMode);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_privacyMode);
        }
        , nullptr
    }; // ExchangeUserSettingsStubMethods

    //
    // Exchange::IUserSettings::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void OnAudioDescriptionChanged(const bool) = 0
    //  (1) virtual void OnPreferredAudioLanguagesChanged(const string&) = 0
    //  (2) virtual void OnPresentationLanguageChanged(const string&) = 0
    //  (3) virtual void OnCaptionsChanged(const bool) = 0
    //  (4) virtual void OnPreferredCaptionsLanguagesChanged(const string&) = 0
    //  (5) virtual void OnPreferredClosedCaptionServiceChanged(const string&) = 0
    //  (6) virtual void OnPrivacyModeChanged(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeUserSettingsNotificationStubMethods[] = {
        // (0) virtual void OnAudioDescriptionChanged(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings::INotification* implementation = reinterpret_cast<Exchange::IUserSettings::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _enabled = reader.Boolean();

            implementation->OnAudioDescriptionChanged(_enabled);
        },

        // (1) virtual void OnPreferredAudioLanguagesChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings::INotification* implementation = reinterpret_cast<Exchange::IUserSettings::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _preferredLanguages = reader.Text();

            implementation->OnPreferredAudioLanguagesChanged(static_cast<const string&>(_preferredLanguages));
        },

        // (2) virtual void OnPresentationLanguageChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings::INotification* implementation = reinterpret_cast<Exchange::IUserSettings::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _presentationLanguages = reader.Text();

            implementation->OnPresentationLanguageChanged(static_cast<const string&>(_presentationLanguages));
        },

        // (3) virtual void OnCaptionsChanged(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings::INotification* implementation = reinterpret_cast<Exchange::IUserSettings::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _enabled = reader.Boolean();

            implementation->OnCaptionsChanged(_enabled);
        },

        // (4) virtual void OnPreferredCaptionsLanguagesChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings::INotification* implementation = reinterpret_cast<Exchange::IUserSettings::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _preferredLanguages = reader.Text();

            implementation->OnPreferredCaptionsLanguagesChanged(static_cast<const string&>(_preferredLanguages));
        },

        // (5) virtual void OnPreferredClosedCaptionServiceChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings::INotification* implementation = reinterpret_cast<Exchange::IUserSettings::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _service = reader.Text();

            implementation->OnPreferredClosedCaptionServiceChanged(static_cast<const string&>(_service));
        },

        // (6) virtual void OnPrivacyModeChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IUserSettings::INotification* implementation = reinterpret_cast<Exchange::IUserSettings::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _privacyMode = reader.Text();

            implementation->OnPrivacyModeChanged(static_cast<const string&>(_privacyMode));
        }
        , nullptr
    }; // ExchangeUserSettingsNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IUserSettings interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::IUserSettings::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::IUserSettings::INotification*) = 0
    //  (2) virtual uint32_t SetAudioDescription(const bool) = 0
    //  (3) virtual uint32_t GetAudioDescription(bool&) const = 0
    //  (4) virtual uint32_t SetPreferredAudioLanguages(const string&) = 0
    //  (5) virtual uint32_t GetPreferredAudioLanguages(string&) const = 0
    //  (6) virtual uint32_t SetPresentationLanguage(const string&) = 0
    //  (7) virtual uint32_t GetPresentationLanguage(string&) const = 0
    //  (8) virtual uint32_t SetCaptions(const bool) = 0
    //  (9) virtual uint32_t GetCaptions(bool&) const = 0
    //  (10) virtual uint32_t SetPreferredCaptionsLanguages(const string&) = 0
    //  (11) virtual uint32_t GetPreferredCaptionsLanguages(string&) const = 0
    //  (12) virtual uint32_t SetPreferredClosedCaptionService(const string&) = 0
    //  (13) virtual uint32_t GetPreferredClosedCaptionService(string&) const = 0
    //  (14) virtual uint32_t SetPrivacyMode(const string&) = 0
    //  (15) virtual uint32_t GetPrivacyMode(string&) const = 0
    //

    class ExchangeUserSettingsProxy final : public ProxyStub::UnknownProxyType<Exchange::IUserSettings> {
    public:
        ExchangeUserSettingsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Register(Exchange::IUserSettings::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Unregister(Exchange::IUserSettings::INotification* _notification) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetAudioDescription(const bool _enabled) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enabled);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetAudioDescription(bool& _enabled) const override
        {
            IPCMessage message(BaseClass::Message(3));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _enabled = reader.Boolean();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetPreferredAudioLanguages(const string& _preferredLanguages) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_preferredLanguages));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetPreferredAudioLanguages(string& _preferredLanguages) const override
        {
            IPCMessage message(BaseClass::Message(5));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _preferredLanguages = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetPresentationLanguage(const string& _presentationLanguages) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_presentationLanguages));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetPresentationLanguage(string& _presentationLanguages) const override
        {
            IPCMessage message(BaseClass::Message(7));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _presentationLanguages = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetCaptions(const bool _enabled) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enabled);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetCaptions(bool& _enabled) const override
        {
            IPCMessage message(BaseClass::Message(9));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _enabled = reader.Boolean();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetPreferredCaptionsLanguages(const string& _preferredLanguages) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_preferredLanguages));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetPreferredCaptionsLanguages(string& _preferredLanguages) const override
        {
            IPCMessage message(BaseClass::Message(11));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _preferredLanguages = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetPreferredClosedCaptionService(const string& _service) override
        {
            IPCMessage message(BaseClass::Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_service));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetPreferredClosedCaptionService(string& _service) const override
        {
            IPCMessage message(BaseClass::Message(13));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _service = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t SetPrivacyMode(const string& _privacyMode) override
        {
            IPCMessage message(BaseClass::Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_privacyMode));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t GetPrivacyMode(string& _privacyMode) const override
        {
            IPCMessage message(BaseClass::Message(15));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                if ((hresult & COM_ERROR) == 0) {
                    _privacyMode = reader.Text();
                }
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeUserSettingsProxy

    //
    // Exchange::IUserSettings::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OnAudioDescriptionChanged(const bool) = 0
    //  (1) virtual void OnPreferredAudioLanguagesChanged(const string&) = 0
    //  (2) virtual void OnPresentationLanguageChanged(const string&) = 0
    //  (3) virtual void OnCaptionsChanged(const bool) = 0
    //  (4) virtual void OnPreferredCaptionsLanguagesChanged(const string&) = 0
    //  (5) virtual void OnPreferredClosedCaptionServiceChanged(const string&) = 0
    //  (6) virtual void OnPrivacyModeChanged(const string&) = 0
    //

    class ExchangeUserSettingsNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IUserSettings::INotification> {
    public:
        ExchangeUserSettingsNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void OnAudioDescriptionChanged(const bool _enabled) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enabled);

            UnknownProxyType::Invoke(message);
        }

        void OnPreferredAudioLanguagesChanged(const string& _preferredLanguages) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_preferredLanguages));

            UnknownProxyType::Invoke(message);
        }

        void OnPresentationLanguageChanged(const string& _presentationLanguages) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_presentationLanguages));

            UnknownProxyType::Invoke(message);
        }

        void OnCaptionsChanged(const bool _enabled) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enabled);

            UnknownProxyType::Invoke(message);
        }

        void OnPreferredCaptionsLanguagesChanged(const string& _preferredLanguages) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_preferredLanguages));

            UnknownProxyType::Invoke(message);
        }

        void OnPreferredClosedCaptionServiceChanged(const string& _service) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_service));

            UnknownProxyType::Invoke(message);
        }

        void OnPrivacyModeChanged(const string& _privacyMode) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_privacyMode));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeUserSettingsNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IUserSettings, ExchangeUserSettingsStubMethods> ExchangeUserSettingsStub;
        typedef ProxyStub::UnknownStubType<Exchange::IUserSettings::INotification, ExchangeUserSettingsNotificationStubMethods> ExchangeUserSettingsNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IUserSettings, ExchangeUserSettingsProxy, ExchangeUserSettingsStub>();
                RPC::Administrator::Instance().Announce<Exchange::IUserSettings::INotification, ExchangeUserSettingsNotificationProxy, ExchangeUserSettingsNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IUserSettings>();
                RPC::Administrator::Instance().Recall<Exchange::IUserSettings::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
