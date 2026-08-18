//
// generated automatically from "IDolby.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::Dolby::IOutput
//   - class Exchange::Dolby::IOutput::INotification
//

#include "Module.h"
#include "IDolby.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::Dolby::IOutput interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::Dolby::IOutput::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::Dolby::IOutput::INotification*) = 0
    //  (2) virtual uint32_t AtmosMetadata(bool&) const = 0
    //  (3) virtual uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes&) const = 0
    //  (4) virtual uint32_t EnableAtmosOutput(const bool) = 0
    //  (5) virtual uint32_t Mode(const Exchange::Dolby::IOutput::Type&) = 0
    //  (6) virtual uint32_t Mode(Exchange::Dolby::IOutput::Type&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeDolbyOutputStubMethods[] = {
        // (0) virtual uint32_t Register(Exchange::Dolby::IOutput::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            Exchange::Dolby::IOutput::INotification* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            uint32_t result = implementation->Register(_parameter_1);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
            }
        },

        // (1) virtual uint32_t Unregister(Exchange::Dolby::IOutput::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_1InstanceId__ = reader.Number<Core::instance_id>();

            Exchange::Dolby::IOutput::INotification* _parameter_1{};
            ProxyStub::UnknownProxy* _parameter_1Proxy__ = nullptr;
            if (_parameter_1InstanceId__ != 0) {
                _parameter_1Proxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_1InstanceId__, false, _parameter_1);
                ASSERT((_parameter_1 != nullptr) && (_parameter_1Proxy__ != nullptr));
            }

            uint32_t result = implementation->Unregister(_parameter_1);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_1Proxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_1Proxy__, message->Response());
            }
        },

        // (2) virtual uint32_t AtmosMetadata(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::Dolby::IOutput* implementation = reinterpret_cast<const Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _supported{};

            uint32_t result = implementation->AtmosMetadata(_supported);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_supported);
        },

        // (3) virtual uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::Dolby::IOutput* implementation = reinterpret_cast<const Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::Dolby::IOutput::SoundModes _mode{};

            uint32_t result = implementation->SoundMode(_mode);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::Dolby::IOutput::SoundModes>(_mode);
        },

        // (4) virtual uint32_t EnableAtmosOutput(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _enable = reader.Boolean();

            uint32_t result = implementation->EnableAtmosOutput(_enable);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t Mode(const Exchange::Dolby::IOutput::Type&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::Dolby::IOutput* implementation = reinterpret_cast<Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::Dolby::IOutput::Type _mode = reader.Number<Exchange::Dolby::IOutput::Type>();

            uint32_t result = implementation->Mode(static_cast<const Exchange::Dolby::IOutput::Type&>(_mode));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t Mode(Exchange::Dolby::IOutput::Type&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::Dolby::IOutput* implementation = reinterpret_cast<const Exchange::Dolby::IOutput*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::Dolby::IOutput::Type _mode{};

            uint32_t result = implementation->Mode(_mode);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::Dolby::IOutput::Type>(_mode);
        }
        , nullptr
    }; // ExchangeDolbyOutputStubMethods

    //
    // Exchange::Dolby::IOutput::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes, const bool) = 0
    //

    static ProxyStub::MethodHandler ExchangeDolbyOutputNotificationStubMethods[] = {
        // (0) virtual void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::Dolby::IOutput::INotification* implementation = reinterpret_cast<Exchange::Dolby::IOutput::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::Dolby::IOutput::SoundModes _mode = reader.Number<Exchange::Dolby::IOutput::SoundModes>();
            const bool _enabled = reader.Boolean();

            implementation->AudioModeChanged(_mode, _enabled);
        }
        , nullptr
    }; // ExchangeDolbyOutputNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::Dolby::IOutput interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Register(Exchange::Dolby::IOutput::INotification*) = 0
    //  (1) virtual uint32_t Unregister(Exchange::Dolby::IOutput::INotification*) = 0
    //  (2) virtual uint32_t AtmosMetadata(bool&) const = 0
    //  (3) virtual uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes&) const = 0
    //  (4) virtual uint32_t EnableAtmosOutput(const bool) = 0
    //  (5) virtual uint32_t Mode(const Exchange::Dolby::IOutput::Type&) = 0
    //  (6) virtual uint32_t Mode(Exchange::Dolby::IOutput::Type&) const = 0
    //

    class ExchangeDolbyOutputProxy final : public ProxyStub::UnknownProxyType<Exchange::Dolby::IOutput> {
    public:
        ExchangeDolbyOutputProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Register(Exchange::Dolby::IOutput::INotification* _parameter_1) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Unregister(Exchange::Dolby::IOutput::INotification* _parameter_1) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t AtmosMetadata(bool& _supported) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _supported = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t SoundMode(Exchange::Dolby::IOutput::SoundModes& _mode) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _mode = reader.Number<Exchange::Dolby::IOutput::SoundModes>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t EnableAtmosOutput(const bool _enable) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enable);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Mode(const Exchange::Dolby::IOutput::Type& _mode) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::Dolby::IOutput::Type>(_mode);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Mode(Exchange::Dolby::IOutput::Type& _mode) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _mode = reader.Number<Exchange::Dolby::IOutput::Type>();
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

    }; // class ExchangeDolbyOutputProxy

    //
    // Exchange::Dolby::IOutput::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes, const bool) = 0
    //

    class ExchangeDolbyOutputNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::Dolby::IOutput::INotification> {
    public:
        ExchangeDolbyOutputNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void AudioModeChanged(const Exchange::Dolby::IOutput::SoundModes _mode, const bool _enabled) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::Dolby::IOutput::SoundModes>(_mode);
            writer.Boolean(_enabled);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeDolbyOutputNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::Dolby::IOutput, ExchangeDolbyOutputStubMethods> ExchangeDolbyOutputStub;
        typedef ProxyStub::UnknownStubType<Exchange::Dolby::IOutput::INotification, ExchangeDolbyOutputNotificationStubMethods> ExchangeDolbyOutputNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::Dolby::IOutput, ExchangeDolbyOutputProxy, ExchangeDolbyOutputStub>();
                RPC::Administrator::Instance().Announce<Exchange::Dolby::IOutput::INotification, ExchangeDolbyOutputNotificationProxy, ExchangeDolbyOutputNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::Dolby::IOutput>();
                RPC::Administrator::Instance().Recall<Exchange::Dolby::IOutput::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
