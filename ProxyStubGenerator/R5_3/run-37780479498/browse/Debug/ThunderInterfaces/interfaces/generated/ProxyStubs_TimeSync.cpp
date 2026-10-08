//
// generated automatically from "ITimeSync.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ITimeSync
//   - class Exchange::ITimeSync::ISource
//   - class Exchange::ITimeSync::ISource::INotification
//   - class Exchange::ITimeSync::INotification
//

#include "Module.h"
#include "ITimeSync.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ITimeSync interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::ITimeSync::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::ITimeSync::INotification* const) = 0
    //  (2) virtual Core::hresult Synchronize() = 0
    //  (3) virtual Core::hresult SyncTime(Exchange::ITimeSync::TimeInfo&) const = 0
    //  (4) virtual Core::hresult Time(Core::Time&) const = 0
    //  (5) virtual Core::hresult Time(const Core::Time&) = 0
    //

    static ProxyStub::MethodHandler ExchangeTimeSyncStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::ITimeSync::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync* implementation = reinterpret_cast<Exchange::ITimeSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ITimeSync::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const Exchange::ITimeSync::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync* implementation = reinterpret_cast<Exchange::ITimeSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::ITimeSync::INotification* _notification{};
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

        // (2) virtual Core::hresult Synchronize() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync* implementation = reinterpret_cast<Exchange::ITimeSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::hresult result = implementation->Synchronize();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult SyncTime(Exchange::ITimeSync::TimeInfo&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITimeSync* implementation = reinterpret_cast<const Exchange::ITimeSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ITimeSync::TimeInfo _info{};

            Core::hresult result = implementation->SyncTime(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::Time::microsecondsfromepoch>(_info.time.Ticks());
            writer.Boolean(_info.source.IsSet());
            if (_info.source.IsSet() == true) {
                writer.Text(_info.source.Value());
            }
        },

        // (4) virtual Core::hresult Time(Core::Time&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITimeSync* implementation = reinterpret_cast<const Exchange::ITimeSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Core::Time _time{};

            Core::hresult result = implementation->Time(_time);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::Time::microsecondsfromepoch>(_time.Ticks());
        },

        // (5) virtual Core::hresult Time(const Core::Time&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync* implementation = reinterpret_cast<Exchange::ITimeSync*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::Time _time = reader.Number<Core::Time::microsecondsfromepoch>();

            Core::hresult result = implementation->Time(static_cast<const Core::Time&>(_time));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeTimeSyncStubMethods

    //
    // Exchange::ITimeSync::ISource interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::ITimeSync::ISource::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::ITimeSync::ISource::INotification*) = 0
    //  (2) virtual uint32_t Synchronize() = 0
    //  (3) virtual void Cancel() = 0
    //  (4) virtual string Source() const = 0
    //  (5) virtual uint64_t SyncTime() const = 0
    //

    static ProxyStub::MethodHandler ExchangeTimeSyncSourceStubMethods[] = {
        // (0) virtual void Register(Exchange::ITimeSync::ISource::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync::ISource* implementation = reinterpret_cast<Exchange::ITimeSync::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ITimeSync::ISource::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            implementation->Register(_notification);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::ITimeSync::ISource::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync::ISource* implementation = reinterpret_cast<Exchange::ITimeSync::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::ITimeSync::ISource::INotification* _notification{};
            ProxyStub::UnknownProxy* _notificationProxy__ = nullptr;
            if (_notificationInstanceId__ != 0) {
                _notificationProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _notificationInstanceId__, false, _notification);
                ASSERT((_notification != nullptr) && (_notificationProxy__ != nullptr));
            }

            implementation->Unregister(_notification);

            if (_notificationProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_notificationProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t Synchronize() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync::ISource* implementation = reinterpret_cast<Exchange::ITimeSync::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Synchronize();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual void Cancel() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync::ISource* implementation = reinterpret_cast<Exchange::ITimeSync::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Cancel();
        },

        // (4) virtual string Source() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITimeSync::ISource* implementation = reinterpret_cast<const Exchange::ITimeSync::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Source();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (5) virtual uint64_t SyncTime() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ITimeSync::ISource* implementation = reinterpret_cast<const Exchange::ITimeSync::ISource*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint64_t result = implementation->SyncTime();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(result);
        }
        , nullptr
    }; // ExchangeTimeSyncSourceStubMethods

    //
    // Exchange::ITimeSync::ISource::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void Completed() = 0
    //

    static ProxyStub::MethodHandler ExchangeTimeSyncSourceNotificationStubMethods[] = {
        // (0) virtual void Completed() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync::ISource::INotification* implementation = reinterpret_cast<Exchange::ITimeSync::ISource::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Completed();
        }
        , nullptr
    }; // ExchangeTimeSyncSourceNotificationStubMethods

    //
    // Exchange::ITimeSync::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void TimeChanged() = 0
    //

    static ProxyStub::MethodHandler ExchangeTimeSyncNotificationStubMethods[] = {
        // (0) virtual void TimeChanged() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ITimeSync::INotification* implementation = reinterpret_cast<Exchange::ITimeSync::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->TimeChanged();
        }
        , nullptr
    }; // ExchangeTimeSyncNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ITimeSync interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::ITimeSync::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::ITimeSync::INotification* const) = 0
    //  (2) virtual Core::hresult Synchronize() = 0
    //  (3) virtual Core::hresult SyncTime(Exchange::ITimeSync::TimeInfo&) const = 0
    //  (4) virtual Core::hresult Time(Core::Time&) const = 0
    //  (5) virtual Core::hresult Time(const Core::Time&) = 0
    //

    class ExchangeTimeSyncProxy final : public ProxyStub::UnknownProxyType<Exchange::ITimeSync> {
    public:
        ExchangeTimeSyncProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::ITimeSync::INotification* const _notification) override
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

        Core::hresult Unregister(const Exchange::ITimeSync::INotification* const _notification) override
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

        Core::hresult Synchronize() override
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

        Core::hresult SyncTime(Exchange::ITimeSync::TimeInfo& _info) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _info.time = reader.Number<Core::Time::microsecondsfromepoch>();
                if (reader.Boolean() == true) {
                    _info.source = reader.Text();
                }
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Time(Core::Time& _time) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _time = reader.Number<Core::Time::microsecondsfromepoch>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Time(const Core::Time& _time) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::Time::microsecondsfromepoch>(_time.Ticks());

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
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

    }; // class ExchangeTimeSyncProxy

    //
    // Exchange::ITimeSync::ISource interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::ITimeSync::ISource::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::ITimeSync::ISource::INotification*) = 0
    //  (2) virtual uint32_t Synchronize() = 0
    //  (3) virtual void Cancel() = 0
    //  (4) virtual string Source() const = 0
    //  (5) virtual uint64_t SyncTime() const = 0
    //

    class ExchangeTimeSyncSourceProxy final : public ProxyStub::UnknownProxyType<Exchange::ITimeSync::ISource> {
    public:
        ExchangeTimeSyncSourceProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::ITimeSync::ISource::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::ITimeSync::ISource::INotification* _notification) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_notification));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Synchronize() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Cancel() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        string Source() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint64_t SyncTime() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            uint64_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint64_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
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

    }; // class ExchangeTimeSyncSourceProxy

    //
    // Exchange::ITimeSync::ISource::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Completed() = 0
    //

    class ExchangeTimeSyncSourceNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::ITimeSync::ISource::INotification> {
    public:
        ExchangeTimeSyncSourceNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Completed() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeTimeSyncSourceNotificationProxy

    //
    // Exchange::ITimeSync::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void TimeChanged() = 0
    //

    class ExchangeTimeSyncNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::ITimeSync::INotification> {
    public:
        ExchangeTimeSyncNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void TimeChanged() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeTimeSyncNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ITimeSync, ExchangeTimeSyncStubMethods> ExchangeTimeSyncStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITimeSync::ISource, ExchangeTimeSyncSourceStubMethods> ExchangeTimeSyncSourceStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITimeSync::ISource::INotification, ExchangeTimeSyncSourceNotificationStubMethods> ExchangeTimeSyncSourceNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::ITimeSync::INotification, ExchangeTimeSyncNotificationStubMethods> ExchangeTimeSyncNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ITimeSync, ExchangeTimeSyncProxy, ExchangeTimeSyncStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITimeSync::ISource, ExchangeTimeSyncSourceProxy, ExchangeTimeSyncSourceStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITimeSync::ISource::INotification, ExchangeTimeSyncSourceNotificationProxy, ExchangeTimeSyncSourceNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::ITimeSync::INotification, ExchangeTimeSyncNotificationProxy, ExchangeTimeSyncNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ITimeSync>();
                RPC::Administrator::Instance().Recall<Exchange::ITimeSync::ISource>();
                RPC::Administrator::Instance().Recall<Exchange::ITimeSync::ISource::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::ITimeSync::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
