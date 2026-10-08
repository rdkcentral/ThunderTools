//
// generated automatically from "IMemoryMonitor.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class Exchange::IMemoryMonitor
//   - class Exchange::IMemoryMonitor::INotification
//

#include "Module.h"
#include "IMemoryMonitor.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_b3acff3685df4032StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_b3acff3685df4032StubMethods

    //
    // Exchange::IMemoryMonitor interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IMemoryMonitor::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IMemoryMonitor::INotification* const) = 0
    //  (2) virtual Core::hresult RestartingLimits(const string&, const Exchange::IMemoryMonitor::Restart&) = 0
    //  (3) virtual Core::hresult RestartingLimits(const string&, Exchange::IMemoryMonitor::Restart&) const = 0
    //  (4) virtual Core::hresult Observables(Exchange::IMemoryMonitor::IStringIterator*&) const = 0
    //  (5) virtual Core::hresult MeasurementData(const string&, Exchange::IMemoryMonitor::Statistics&) const = 0
    //  (6) virtual Core::hresult ResetStatistics(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeMemoryMonitorStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IMemoryMonitor::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMemoryMonitor* implementation = reinterpret_cast<Exchange::IMemoryMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IMemoryMonitor::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const Exchange::IMemoryMonitor::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMemoryMonitor* implementation = reinterpret_cast<Exchange::IMemoryMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IMemoryMonitor::INotification* _notification{};
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

        // (2) virtual Core::hresult RestartingLimits(const string&, const Exchange::IMemoryMonitor::Restart&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMemoryMonitor* implementation = reinterpret_cast<Exchange::IMemoryMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Exchange::IMemoryMonitor::Restart _restart{};
            _restart.limit = reader.Number<uint8_t>();
            _restart.window = reader.Number<uint16_t>();

            Core::hresult result = implementation->RestartingLimits(static_cast<const string&>(_callsign), static_cast<const Exchange::IMemoryMonitor::Restart&>(_restart));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult RestartingLimits(const string&, Exchange::IMemoryMonitor::Restart&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IMemoryMonitor* implementation = reinterpret_cast<const Exchange::IMemoryMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Exchange::IMemoryMonitor::Restart _restart{};

            Core::hresult result = implementation->RestartingLimits(static_cast<const string&>(_callsign), _restart);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint8_t>(_restart.limit);
            writer.Number<uint16_t>(_restart.window);
        },

        // (4) virtual Core::hresult Observables(Exchange::IMemoryMonitor::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IMemoryMonitor* implementation = reinterpret_cast<const Exchange::IMemoryMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IMemoryMonitor::IStringIterator* _observables{};

            Core::hresult result = implementation->Observables(_observables);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_observables));

            RPC::Administrator::Instance().RegisterInterface(channel, _observables);
        },

        // (5) virtual Core::hresult MeasurementData(const string&, Exchange::IMemoryMonitor::Statistics&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IMemoryMonitor* implementation = reinterpret_cast<const Exchange::IMemoryMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Exchange::IMemoryMonitor::Statistics _statistics{};

            Core::hresult result = implementation->MeasurementData(static_cast<const string&>(_callsign), _statistics);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<uint64_t>(_statistics.resident.min);
            writer.Number<uint64_t>(_statistics.resident.max);
            writer.Number<uint64_t>(_statistics.resident.average);
            writer.Number<uint64_t>(_statistics.resident.last);
            writer.Number<uint64_t>(_statistics.allocated.min);
            writer.Number<uint64_t>(_statistics.allocated.max);
            writer.Number<uint64_t>(_statistics.allocated.average);
            writer.Number<uint64_t>(_statistics.allocated.last);
            writer.Number<uint64_t>(_statistics.shared.min);
            writer.Number<uint64_t>(_statistics.shared.max);
            writer.Number<uint64_t>(_statistics.shared.average);
            writer.Number<uint64_t>(_statistics.shared.last);
            writer.Number<uint64_t>(_statistics.process.min);
            writer.Number<uint64_t>(_statistics.process.max);
            writer.Number<uint64_t>(_statistics.process.average);
            writer.Number<uint64_t>(_statistics.process.last);
            writer.Boolean(_statistics.operational);
            writer.Number<uint32_t>(_statistics.count);
        },

        // (6) virtual Core::hresult ResetStatistics(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMemoryMonitor* implementation = reinterpret_cast<Exchange::IMemoryMonitor*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->ResetStatistics(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeMemoryMonitorStubMethods

    //
    // Exchange::IMemoryMonitor::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void StatusChanged(const string&, const Exchange::IMemoryMonitor::INotification::action, const Core::OptionalType<Exchange::IMemoryMonitor::INotification::reason>&) = 0
    //

    static ProxyStub::MethodHandler ExchangeMemoryMonitorNotificationStubMethods[] = {
        // (0) virtual void StatusChanged(const string&, const Exchange::IMemoryMonitor::INotification::action, const Core::OptionalType<Exchange::IMemoryMonitor::INotification::reason>&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMemoryMonitor::INotification* implementation = reinterpret_cast<Exchange::IMemoryMonitor::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Exchange::IMemoryMonitor::INotification::action _action = reader.Number<Exchange::IMemoryMonitor::INotification::action>();
            Core::OptionalType<Exchange::IMemoryMonitor::INotification::reason> _reason{};
            if (reader.Boolean() == true) {
                _reason = reader.Number<Exchange::IMemoryMonitor::INotification::reason>();
            }

            implementation->StatusChanged(static_cast<const string&>(_callsign), _action, static_cast<const Core::OptionalType<Exchange::IMemoryMonitor::INotification::reason>&>(_reason));
        }
        , nullptr
    }; // ExchangeMemoryMonitorNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_b3acff3685df4032Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_b3acff3685df4032Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t Count() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

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

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

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

    }; // class RPCIteratorTypeInstance_b3acff3685df4032Proxy

    //
    // Exchange::IMemoryMonitor interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IMemoryMonitor::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IMemoryMonitor::INotification* const) = 0
    //  (2) virtual Core::hresult RestartingLimits(const string&, const Exchange::IMemoryMonitor::Restart&) = 0
    //  (3) virtual Core::hresult RestartingLimits(const string&, Exchange::IMemoryMonitor::Restart&) const = 0
    //  (4) virtual Core::hresult Observables(Exchange::IMemoryMonitor::IStringIterator*&) const = 0
    //  (5) virtual Core::hresult MeasurementData(const string&, Exchange::IMemoryMonitor::Statistics&) const = 0
    //  (6) virtual Core::hresult ResetStatistics(const string&) = 0
    //

    class ExchangeMemoryMonitorProxy final : public ProxyStub::UnknownProxyType<Exchange::IMemoryMonitor> {
    public:
        ExchangeMemoryMonitorProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::IMemoryMonitor::INotification* const _notification) override
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

        Core::hresult Unregister(const Exchange::IMemoryMonitor::INotification* const _notification) override
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

        Core::hresult RestartingLimits(const string& _callsign, const Exchange::IMemoryMonitor::Restart& _restart) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<uint8_t>(_restart.limit);
            writer.Number<uint16_t>(_restart.window);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult RestartingLimits(const string& _callsign, Exchange::IMemoryMonitor::Restart& _restart) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _restart.limit = reader.Number<uint8_t>();
                _restart.window = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Observables(Exchange::IMemoryMonitor::IStringIterator*& _observables) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _observables = reinterpret_cast<Exchange::IMemoryMonitor::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IMemoryMonitor::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult MeasurementData(const string& _callsign, Exchange::IMemoryMonitor::Statistics& _statistics) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _statistics.resident.min = reader.Number<uint64_t>();
                _statistics.resident.max = reader.Number<uint64_t>();
                _statistics.resident.average = reader.Number<uint64_t>();
                _statistics.resident.last = reader.Number<uint64_t>();
                _statistics.allocated.min = reader.Number<uint64_t>();
                _statistics.allocated.max = reader.Number<uint64_t>();
                _statistics.allocated.average = reader.Number<uint64_t>();
                _statistics.allocated.last = reader.Number<uint64_t>();
                _statistics.shared.min = reader.Number<uint64_t>();
                _statistics.shared.max = reader.Number<uint64_t>();
                _statistics.shared.average = reader.Number<uint64_t>();
                _statistics.shared.last = reader.Number<uint64_t>();
                _statistics.process.min = reader.Number<uint64_t>();
                _statistics.process.max = reader.Number<uint64_t>();
                _statistics.process.average = reader.Number<uint64_t>();
                _statistics.process.last = reader.Number<uint64_t>();
                _statistics.operational = reader.Boolean();
                _statistics.count = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ResetStatistics(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

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

    }; // class ExchangeMemoryMonitorProxy

    //
    // Exchange::IMemoryMonitor::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void StatusChanged(const string&, const Exchange::IMemoryMonitor::INotification::action, const Core::OptionalType<Exchange::IMemoryMonitor::INotification::reason>&) = 0
    //

    class ExchangeMemoryMonitorNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IMemoryMonitor::INotification> {
    public:
        ExchangeMemoryMonitorNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void StatusChanged(const string& _callsign, const Exchange::IMemoryMonitor::INotification::action _action, const Core::OptionalType<Exchange::IMemoryMonitor::INotification::reason>& _reason) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Exchange::IMemoryMonitor::INotification::action>(_action);
            writer.Boolean(_reason.IsSet());
            if (_reason.IsSet() == true) {
                writer.Number<Exchange::IMemoryMonitor::INotification::reason>(_reason.Value());
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeMemoryMonitorNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IMemoryMonitor, ExchangeMemoryMonitorStubMethods> ExchangeMemoryMonitorStub;
        typedef ProxyStub::UnknownStubType<Exchange::IMemoryMonitor::INotification, ExchangeMemoryMonitorNotificationStubMethods> ExchangeMemoryMonitorNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IMemoryMonitor, ExchangeMemoryMonitorProxy, ExchangeMemoryMonitorStub>();
                RPC::Administrator::Instance().Announce<Exchange::IMemoryMonitor::INotification, ExchangeMemoryMonitorNotificationProxy, ExchangeMemoryMonitorNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IMemoryMonitor>();
                RPC::Administrator::Instance().Recall<Exchange::IMemoryMonitor::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
