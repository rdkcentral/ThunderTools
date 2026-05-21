//
// generated automatically from "IContentDecryption.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IContentDecryption
//   - class Exchange::IContentDecryption::INotification
//

#include "Module.h"
#include "IContentDecryption.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IContentDecryption interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Initialize(PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialize(PluginHost::IShell*) = 0
    //  (2) virtual uint32_t Reset() = 0
    //  (3) virtual RPC::IStringIterator* Systems() const = 0
    //  (4) virtual RPC::IStringIterator* Designators(const string&) const = 0
    //  (5) virtual RPC::IStringIterator* Sessions(const string&) const = 0
    //  (6) virtual uint32_t Register(Exchange::IContentDecryption::INotification*)
    //  (7) virtual uint32_t Unregister(Exchange::IContentDecryption::INotification*)
    //

    ProxyStub::MethodHandler ExchangeContentDecryptionStubMethods[] = {
        // (0) virtual uint32_t Initialize(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentDecryption* implementation = reinterpret_cast<Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id serviceImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _service = nullptr;
            ProxyStub::UnknownProxy* serviceProxy = nullptr;
            if (serviceImplementation != 0) {
                serviceProxy = RPC::Administrator::Instance().ProxyInstance(channel, serviceImplementation, false, _service);

                ASSERT((_service != nullptr) && (serviceProxy != nullptr));
            }

            uint32_t result = implementation->Initialize(_service);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (serviceProxy != nullptr) {
                RPC::Administrator::Instance().Release(serviceProxy, message->Response());
            }
        },

        // (1) virtual void Deinitialize(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentDecryption* implementation = reinterpret_cast<Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id serviceImplementation = reader.Number<Core::instance_id>();

            PluginHost::IShell* _service = nullptr;
            ProxyStub::UnknownProxy* serviceProxy = nullptr;
            if (serviceImplementation != 0) {
                serviceProxy = RPC::Administrator::Instance().ProxyInstance(channel, serviceImplementation, false, _service);

                ASSERT((_service != nullptr) && (serviceProxy != nullptr));
            }

            implementation->Deinitialize(_service);

            if (serviceProxy != nullptr) {
                RPC::Administrator::Instance().Release(serviceProxy, message->Response());
            }
        },

        // (2) virtual uint32_t Reset() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentDecryption* implementation = reinterpret_cast<Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Reset();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual RPC::IStringIterator* Systems() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IContentDecryption* implementation = reinterpret_cast<const Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::IStringIterator* result = implementation->Systems();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (4) virtual RPC::IStringIterator* Designators(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IContentDecryption* implementation = reinterpret_cast<const Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            RPC::IStringIterator* result = implementation->Designators(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (5) virtual RPC::IStringIterator* Sessions(const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IContentDecryption* implementation = reinterpret_cast<const Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();

            RPC::IStringIterator* result = implementation->Sessions(static_cast<const string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        },

        // (6) virtual uint32_t Register(Exchange::IContentDecryption::INotification*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentDecryption* implementation = reinterpret_cast<Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id VARIABLE_IS_NOT_USEDImplementation = reader.Number<Core::instance_id>();

            Exchange::IContentDecryption::INotification* _VARIABLE_IS_NOT_USED = nullptr;
            ProxyStub::UnknownProxy* VARIABLE_IS_NOT_USEDProxy = nullptr;
            if (VARIABLE_IS_NOT_USEDImplementation != 0) {
                VARIABLE_IS_NOT_USEDProxy = RPC::Administrator::Instance().ProxyInstance(channel, VARIABLE_IS_NOT_USEDImplementation, false, _VARIABLE_IS_NOT_USED);

                ASSERT((_VARIABLE_IS_NOT_USED != nullptr) && (VARIABLE_IS_NOT_USEDProxy != nullptr));
            }

            uint32_t result = implementation->Register(_VARIABLE_IS_NOT_USED);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (VARIABLE_IS_NOT_USEDProxy != nullptr) {
                RPC::Administrator::Instance().Release(VARIABLE_IS_NOT_USEDProxy, message->Response());
            }
        },

        // (7) virtual uint32_t Unregister(Exchange::IContentDecryption::INotification*)
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentDecryption* implementation = reinterpret_cast<Exchange::IContentDecryption*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id VARIABLE_IS_NOT_USEDImplementation = reader.Number<Core::instance_id>();

            Exchange::IContentDecryption::INotification* _VARIABLE_IS_NOT_USED = nullptr;
            ProxyStub::UnknownProxy* VARIABLE_IS_NOT_USEDProxy = nullptr;
            if (VARIABLE_IS_NOT_USEDImplementation != 0) {
                VARIABLE_IS_NOT_USEDProxy = RPC::Administrator::Instance().ProxyInstance(channel, VARIABLE_IS_NOT_USEDImplementation, false, _VARIABLE_IS_NOT_USED);

                ASSERT((_VARIABLE_IS_NOT_USED != nullptr) && (VARIABLE_IS_NOT_USEDProxy != nullptr));
            }

            uint32_t result = implementation->Unregister(_VARIABLE_IS_NOT_USED);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (VARIABLE_IS_NOT_USEDProxy != nullptr) {
                RPC::Administrator::Instance().Release(VARIABLE_IS_NOT_USEDProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeContentDecryptionStubMethods

    //
    // Exchange::IContentDecryption::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void initializationStatus(const std::string&, const Exchange::IContentDecryption::Status) = 0
    //

    ProxyStub::MethodHandler ExchangeContentDecryptionNotificationStubMethods[] = {
        // (0) virtual void initializationStatus(const std::string&, const Exchange::IContentDecryption::Status) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentDecryption::INotification* implementation = reinterpret_cast<Exchange::IContentDecryption::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _drm = reader.Text();
            const Exchange::IContentDecryption::Status _status = reader.Number<Exchange::IContentDecryption::Status>();

            implementation->initializationStatus(static_cast<const std::string&>(_drm), _status);
        }
        , nullptr
    }; // ExchangeContentDecryptionNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IContentDecryption interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Initialize(PluginHost::IShell*) = 0
    //  (1) virtual void Deinitialize(PluginHost::IShell*) = 0
    //  (2) virtual uint32_t Reset() = 0
    //  (3) virtual RPC::IStringIterator* Systems() const = 0
    //  (4) virtual RPC::IStringIterator* Designators(const string&) const = 0
    //  (5) virtual RPC::IStringIterator* Sessions(const string&) const = 0
    //  (6) virtual uint32_t Register(Exchange::IContentDecryption::INotification*)
    //  (7) virtual uint32_t Unregister(Exchange::IContentDecryption::INotification*)
    //

    class ExchangeContentDecryptionProxy final : public ProxyStub::UnknownProxyType<Exchange::IContentDecryption> {
    public:
        ExchangeContentDecryptionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Initialize(PluginHost::IShell* _service) override
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

        void Deinitialize(PluginHost::IShell* _service) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        uint32_t Reset() override
        {
            IPCMessage message(BaseClass::Message(2));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        RPC::IStringIterator* Systems() const override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::IStringIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<RPC::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));

            return (result);
        }

        RPC::IStringIterator* Designators(const string& _keySystem) const override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_keySystem));

            RPC::IStringIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<RPC::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));

            return (result);
        }

        RPC::IStringIterator* Sessions(const string& _keySystem) const override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_keySystem));

            RPC::IStringIterator* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<RPC::IStringIterator*>(Interface(reader.Number<Core::instance_id>(), RPC::IStringIterator::ID));

            return (result);
        }

        uint32_t Register(Exchange::IContentDecryption::INotification* _VARIABLE_IS_NOT_USED) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_VARIABLE_IS_NOT_USED));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

        uint32_t Unregister(Exchange::IContentDecryption::INotification* _VARIABLE_IS_NOT_USED) override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_VARIABLE_IS_NOT_USED));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            Complete(reader);

            return (result);
        }

    }; // class ExchangeContentDecryptionProxy

    //
    // Exchange::IContentDecryption::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void initializationStatus(const std::string&, const Exchange::IContentDecryption::Status) = 0
    //

    class ExchangeContentDecryptionNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IContentDecryption::INotification> {
    public:
        ExchangeContentDecryptionNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void initializationStatus(const std::string& _drm, const Exchange::IContentDecryption::Status _status) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_drm));
            writer.Number<Exchange::IContentDecryption::Status>(_status);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeContentDecryptionNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IContentDecryption, ExchangeContentDecryptionStubMethods> ExchangeContentDecryptionStub;
        typedef ProxyStub::UnknownStubType<Exchange::IContentDecryption::INotification, ExchangeContentDecryptionNotificationStubMethods> ExchangeContentDecryptionNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IContentDecryption, ExchangeContentDecryptionProxy, ExchangeContentDecryptionStub>();
                RPC::Administrator::Instance().Announce<Exchange::IContentDecryption::INotification, ExchangeContentDecryptionNotificationProxy, ExchangeContentDecryptionNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IContentDecryption>();
                RPC::Administrator::Instance().Recall<Exchange::IContentDecryption::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
