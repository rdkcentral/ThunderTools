//
// generated automatically from "ILocationSync.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ILocationSync
//   - class Exchange::ILocationSync::INotification
//

#include "Module.h"
#include "ILocationSync.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ILocationSync interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::ILocationSync::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::ILocationSync::INotification* const) = 0
    //  (2) virtual Core::hresult Sync() = 0
    //  (3) virtual Core::hresult Location(Exchange::ILocationSync::LocationInfo&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeLocationSyncStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::ILocationSync::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILocationSync* implementation = reinterpret_cast<Exchange::ILocationSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ILocationSync::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Register(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult Unregister(const Exchange::ILocationSync::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILocationSync* implementation = reinterpret_cast<Exchange::ILocationSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::ILocationSync::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            Core::hresult result = implementation->Unregister(_notification);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult Sync() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILocationSync* implementation = reinterpret_cast<Exchange::ILocationSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Sync();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult Location(Exchange::ILocationSync::LocationInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ILocationSync* implementation = reinterpret_cast<const Exchange::ILocationSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ILocationSync::LocationInfo _info{};

            Core::hresult result = implementation->Location(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Boolean(_info.city.IsSet());
            if (_info.city.IsSet() == true) {
                writer.Text(_info.city.Value());
            }
            writer.Boolean(_info.country.IsSet());
            if (_info.country.IsSet() == true) {
                writer.Text(_info.country.Value());
            }
            writer.Boolean(_info.region.IsSet());
            if (_info.region.IsSet() == true) {
                writer.Text(_info.region.Value());
            }
            writer.Boolean(_info.timeZone.IsSet());
            if (_info.timeZone.IsSet() == true) {
                writer.Text(_info.timeZone.Value());
            }
            writer.Boolean(_info.publicIP.IsSet());
            if (_info.publicIP.IsSet() == true) {
                writer.Text(_info.publicIP.Value());
            }
        }
        , nullptr
    }; // ExchangeLocationSyncStubMethods

    //
    // Exchange::ILocationSync::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Updated() = 0
    //

    static ProxyStub::MethodHandler ExchangeLocationSyncNotificationStubMethods[] = {
        // (0) virtual void Updated() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ILocationSync::INotification* implementation = reinterpret_cast<Exchange::ILocationSync::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Updated();
        }
        , nullptr
    }; // ExchangeLocationSyncNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ILocationSync interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::ILocationSync::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::ILocationSync::INotification* const) = 0
    //  (2) virtual Core::hresult Sync() = 0
    //  (3) virtual Core::hresult Location(Exchange::ILocationSync::LocationInfo&) const = 0
    //

    class ExchangeLocationSyncProxy final : public ProxyStub::UnknownProxyType<Exchange::ILocationSync> {
    public:
        ExchangeLocationSyncProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::ILocationSync::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
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

        Core::hresult Unregister(const Exchange::ILocationSync::INotification* const _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
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

        Core::hresult Sync() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Location(Exchange::ILocationSync::LocationInfo& _info) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if (reader.Boolean() == true) {
                    _info.city = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.country = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.region = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.timeZone = reader.Text();
                }
                if (reader.Boolean() == true) {
                    _info.publicIP = reader.Text();
                }
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

    }; // class ExchangeLocationSyncProxy

    //
    // Exchange::ILocationSync::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Updated() = 0
    //

    class ExchangeLocationSyncNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::ILocationSync::INotification> {
    public:
        ExchangeLocationSyncNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Updated() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeLocationSyncNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ILocationSync, ExchangeLocationSyncStubMethods> ExchangeLocationSyncStub;
        typedef ProxyStub::UnknownStubType<Exchange::ILocationSync::INotification, ExchangeLocationSyncNotificationStubMethods> ExchangeLocationSyncNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ILocationSync, ExchangeLocationSyncProxy, ExchangeLocationSyncStub>();
                RPC::Administrator::Instance().Announce<Exchange::ILocationSync::INotification, ExchangeLocationSyncNotificationProxy, ExchangeLocationSyncNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ILocationSync>();
                RPC::Administrator::Instance().Recall<Exchange::ILocationSync::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
