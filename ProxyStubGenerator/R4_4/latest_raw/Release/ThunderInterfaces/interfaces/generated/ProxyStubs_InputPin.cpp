//
// generated automatically from "IInputPin.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IInputPin
//   - class Exchange::IInputPin::INotification
//   - class Exchange::IInputPin::ICatalog
//

#include "Module.h"
#include "IInputPin.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IInputPin interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IInputPin::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IInputPin::INotification*) = 0
    //  (2) virtual void AddMarker(const uint32_t) = 0
    //  (3) virtual void RemoveMarker(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeInputPinStubMethods[] = {
        // (0) virtual void Register(Exchange::IInputPin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IInputPin* implementation = reinterpret_cast<Exchange::IInputPin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IInputPin::INotification* _sink = nullptr;
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

        // (1) virtual void Unregister(Exchange::IInputPin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IInputPin* implementation = reinterpret_cast<Exchange::IInputPin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id sinkImplementation = reader.Number<Core::instance_id>();

            Exchange::IInputPin::INotification* _sink = nullptr;
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

        // (2) virtual void AddMarker(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IInputPin* implementation = reinterpret_cast<Exchange::IInputPin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _marker = reader.Number<uint32_t>();

            implementation->AddMarker(_marker);
        },

        // (3) virtual void RemoveMarker(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IInputPin* implementation = reinterpret_cast<Exchange::IInputPin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _marker = reader.Number<uint32_t>();

            implementation->RemoveMarker(_marker);
        }
        , nullptr
    }; // ExchangeInputPinStubMethods

    //
    // Exchange::IInputPin::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Marker(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeInputPinNotificationStubMethods[] = {
        // (0) virtual void Marker(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IInputPin::INotification* implementation = reinterpret_cast<Exchange::IInputPin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _marker = reader.Number<uint32_t>();

            implementation->Marker(_marker);
        }
        , nullptr
    }; // ExchangeInputPinNotificationStubMethods

    //
    // Exchange::IInputPin::ICatalog interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IInputPin* IInputPinResource(const uint32_t) = 0
    //

    ProxyStub::MethodHandler ExchangeInputPinCatalogStubMethods[] = {
        // (0) virtual Exchange::IInputPin* IInputPinResource(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IInputPin::ICatalog* implementation = reinterpret_cast<Exchange::IInputPin::ICatalog*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _id = reader.Number<uint32_t>();

            Exchange::IInputPin* result = implementation->IInputPinResource(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeInputPinCatalogStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IInputPin interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IInputPin::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IInputPin::INotification*) = 0
    //  (2) virtual void AddMarker(const uint32_t) = 0
    //  (3) virtual void RemoveMarker(const uint32_t) = 0
    //

    class ExchangeInputPinProxy final : public ProxyStub::UnknownProxyType<Exchange::IInputPin> {
    public:
        ExchangeInputPinProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Register(Exchange::IInputPin::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void Unregister(Exchange::IInputPin::INotification* _sink) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

        void AddMarker(const uint32_t _marker) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_marker);

            UnknownProxyType::Invoke(message);
        }

        void RemoveMarker(const uint32_t _marker) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_marker);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeInputPinProxy

    //
    // Exchange::IInputPin::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Marker(const uint32_t) = 0
    //

    class ExchangeInputPinNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IInputPin::INotification> {
    public:
        ExchangeInputPinNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Marker(const uint32_t _marker) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_marker);

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeInputPinNotificationProxy

    //
    // Exchange::IInputPin::ICatalog interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IInputPin* IInputPinResource(const uint32_t) = 0
    //

    class ExchangeInputPinCatalogProxy final : public ProxyStub::UnknownProxyType<Exchange::IInputPin::ICatalog> {
    public:
        ExchangeInputPinCatalogProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::IInputPin* IInputPinResource(const uint32_t _id) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_id);

            Exchange::IInputPin* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IInputPin*>(Interface(reader.Number<Core::instance_id>(), Exchange::IInputPin::ID));

            return (result);
        }

    }; // class ExchangeInputPinCatalogProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IInputPin, ExchangeInputPinStubMethods> ExchangeInputPinStub;
        typedef ProxyStub::UnknownStubType<Exchange::IInputPin::INotification, ExchangeInputPinNotificationStubMethods> ExchangeInputPinNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IInputPin::ICatalog, ExchangeInputPinCatalogStubMethods> ExchangeInputPinCatalogStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IInputPin, ExchangeInputPinProxy, ExchangeInputPinStub>();
                RPC::Administrator::Instance().Announce<Exchange::IInputPin::INotification, ExchangeInputPinNotificationProxy, ExchangeInputPinNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IInputPin::ICatalog, ExchangeInputPinCatalogProxy, ExchangeInputPinCatalogStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IInputPin>();
                RPC::Administrator::Instance().Recall<Exchange::IInputPin::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IInputPin::ICatalog>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
