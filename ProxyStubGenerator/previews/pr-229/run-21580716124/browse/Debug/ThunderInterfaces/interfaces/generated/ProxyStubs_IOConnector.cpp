//
// generated automatically from "IIOConnector.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IIOConnector
//   - class Exchange::IIOConnector::INotification
//

#include "Module.h"
#include "IIOConnector.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IIOConnector interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(const uint16_t, Exchange::IIOConnector::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const uint16_t, const Exchange::IIOConnector::INotification* const) = 0
    //  (2) virtual Core::hresult Pin(const uint16_t, const int32_t) = 0
    //  (3) virtual Core::hresult Pin(const uint16_t, int32_t&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeIOConnectorStubMethods[] = {
        // (0) virtual Core::hresult Register(const uint16_t, Exchange::IIOConnector::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IIOConnector* implementation = reinterpret_cast<Exchange::IIOConnector*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _id = reader.Number<uint16_t>();
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IIOConnector::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_id, _notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(const uint16_t, const Exchange::IIOConnector::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IIOConnector* implementation = reinterpret_cast<Exchange::IIOConnector*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _id = reader.Number<uint16_t>();
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IIOConnector::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_id, _notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult Pin(const uint16_t, const int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IIOConnector* implementation = reinterpret_cast<Exchange::IIOConnector*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _id = reader.Number<uint16_t>();
            const int32_t _value = reader.Number<int32_t>();

            Core::hresult result = implementation->Pin(_id, _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult Pin(const uint16_t, int32_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IIOConnector* implementation = reinterpret_cast<const Exchange::IIOConnector*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _id = reader.Number<uint16_t>();

            int32_t _value{};

            Core::hresult result = implementation->Pin(_id, _value);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<int32_t>(_value);
        }
        , nullptr
    }; // ExchangeIOConnectorStubMethods

    //
    // Exchange::IIOConnector::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Activity(const uint16_t, const int32_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeIOConnectorNotificationStubMethods[] = {
        // (0) virtual void Activity(const uint16_t, const int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IIOConnector::INotification* implementation = reinterpret_cast<Exchange::IIOConnector::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _id = reader.Number<uint16_t>();
            const int32_t _value = reader.Number<int32_t>();

            implementation->Activity(_id, _value);
        }
        , nullptr
    }; // ExchangeIOConnectorNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IIOConnector interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(const uint16_t, Exchange::IIOConnector::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const uint16_t, const Exchange::IIOConnector::INotification* const) = 0
    //  (2) virtual Core::hresult Pin(const uint16_t, const int32_t) = 0
    //  (3) virtual Core::hresult Pin(const uint16_t, int32_t&) const = 0
    //

    class ExchangeIOConnectorProxy final : public ProxyStub::UnknownProxyType<Exchange::IIOConnector> {
    public:
        ExchangeIOConnectorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(const uint16_t _id, Exchange::IIOConnector::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_id);
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unregister(const uint16_t _id, const Exchange::IIOConnector::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_id);
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Pin(const uint16_t _id, const int32_t _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_id);
            writer.Number<int32_t>(_value);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Pin(const uint16_t _id, int32_t& _value) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_id);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _value = reader.Number<int32_t>();
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

    }; // class ExchangeIOConnectorProxy

    //
    // Exchange::IIOConnector::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Activity(const uint16_t, const int32_t) = 0
    //

    class ExchangeIOConnectorNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IIOConnector::INotification> {
    public:
        ExchangeIOConnectorNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Activity(const uint16_t _id, const int32_t _value) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_id);
            writer.Number<int32_t>(_value);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeIOConnectorNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IIOConnector, ExchangeIOConnectorStubMethods> ExchangeIOConnectorStub;
        typedef ProxyStub::UnknownStubType<Exchange::IIOConnector::INotification, ExchangeIOConnectorNotificationStubMethods> ExchangeIOConnectorNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IIOConnector, ExchangeIOConnectorProxy, ExchangeIOConnectorStub>();
                RPC::Administrator::Instance().Announce<Exchange::IIOConnector::INotification, ExchangeIOConnectorNotificationProxy, ExchangeIOConnectorNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IIOConnector>();
                RPC::Administrator::Instance().Recall<Exchange::IIOConnector::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
