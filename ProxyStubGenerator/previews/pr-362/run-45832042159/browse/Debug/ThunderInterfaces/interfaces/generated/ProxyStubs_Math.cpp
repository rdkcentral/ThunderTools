//
// generated automatically from "IMath.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IMath
//   - class Exchange::IMathExtended
//   - class Exchange::IMathExtended::INotification
//

#include "Module.h"
#include "IMath.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IMath interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Add(const uint16_t, const uint16_t, uint16_t&) const = 0
    //  (1) virtual uint32_t Sub(const uint16_t, const uint16_t, uint16_t&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeMathStubMethods[] = {
        // (0) virtual uint32_t Add(const uint16_t, const uint16_t, uint16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IMath* implementation = reinterpret_cast<const Exchange::IMath*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _A = reader.Number<uint16_t>();
            const uint16_t _B = reader.Number<uint16_t>();

            uint16_t _sum{};

            uint32_t result = implementation->Add(_A, _B, _sum);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint16_t>(_sum);
        },

        // (1) virtual uint32_t Sub(const uint16_t, const uint16_t, uint16_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IMath* implementation = reinterpret_cast<const Exchange::IMath*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _A = reader.Number<uint16_t>();
            const uint16_t _B = reader.Number<uint16_t>();

            uint16_t _sum{};

            uint32_t result = implementation->Sub(_A, _B, _sum);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint16_t>(_sum);
        }
        , nullptr
    }; // ExchangeMathStubMethods

    //
    // Exchange::IMathExtended interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IMathExtended::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IMathExtended::INotification* const) = 0
    //  (2) virtual Core::hresult Multiply(const uint16_t, const uint16_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeMathExtendedStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IMathExtended::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMathExtended* implementation = reinterpret_cast<Exchange::IMathExtended*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IMathExtended::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(const Exchange::IMathExtended::INotification* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMathExtended* implementation = reinterpret_cast<Exchange::IMathExtended*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            const Exchange::IMathExtended::INotification* _notification{};
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

        // (2) virtual Core::hresult Multiply(const uint16_t, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMathExtended* implementation = reinterpret_cast<Exchange::IMathExtended*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint16_t _A = reader.Number<uint16_t>();
            const uint16_t _B = reader.Number<uint16_t>();

            Core::hresult result = implementation->Multiply(_A, _B);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeMathExtendedStubMethods

    //
    // Exchange::IMathExtended::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void MultiplyResult(const uint32_t) = 0
    //

    static ProxyStub::MethodHandler ExchangeMathExtendedNotificationStubMethods[] = {
        // (0) virtual void MultiplyResult(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMathExtended::INotification* implementation = reinterpret_cast<Exchange::IMathExtended::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _result = reader.Number<uint32_t>();

            implementation->MultiplyResult(_result);
        }
        , nullptr
    }; // ExchangeMathExtendedNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IMath interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Add(const uint16_t, const uint16_t, uint16_t&) const = 0
    //  (1) virtual uint32_t Sub(const uint16_t, const uint16_t, uint16_t&) const = 0
    //

    class ExchangeMathProxy final : public ProxyStub::UnknownProxyType<Exchange::IMath> {
    public:
        ExchangeMathProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Add(const uint16_t _A, const uint16_t _B, uint16_t& _sum) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_A);
            writer.Number<uint16_t>(_B);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _sum = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Sub(const uint16_t _A, const uint16_t _B, uint16_t& _sum) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_A);
            writer.Number<uint16_t>(_B);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _sum = reader.Number<uint16_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeMathProxy

    //
    // Exchange::IMathExtended interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IMathExtended::INotification* const) = 0
    //  (1) virtual Core::hresult Unregister(const Exchange::IMathExtended::INotification* const) = 0
    //  (2) virtual Core::hresult Multiply(const uint16_t, const uint16_t) = 0
    //

    class ExchangeMathExtendedProxy final : public ProxyStub::UnknownProxyType<Exchange::IMathExtended> {
    public:
        ExchangeMathExtendedProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::IMathExtended::INotification* const _notification) override
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

        Core::hresult Unregister(const Exchange::IMathExtended::INotification* const _notification) override
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

        Core::hresult Multiply(const uint16_t _A, const uint16_t _B) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_A);
            writer.Number<uint16_t>(_B);

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

    }; // class ExchangeMathExtendedProxy

    //
    // Exchange::IMathExtended::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void MultiplyResult(const uint32_t) = 0
    //

    class ExchangeMathExtendedNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IMathExtended::INotification> {
    public:
        ExchangeMathExtendedNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void MultiplyResult(const uint32_t _result) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_result);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeMathExtendedNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IMath, ExchangeMathStubMethods> ExchangeMathStub;
        typedef ProxyStub::UnknownStubType<Exchange::IMathExtended, ExchangeMathExtendedStubMethods> ExchangeMathExtendedStub;
        typedef ProxyStub::UnknownStubType<Exchange::IMathExtended::INotification, ExchangeMathExtendedNotificationStubMethods> ExchangeMathExtendedNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IMath, ExchangeMathProxy, ExchangeMathStub>();
                RPC::Administrator::Instance().Announce<Exchange::IMathExtended, ExchangeMathExtendedProxy, ExchangeMathExtendedStub>();
                RPC::Administrator::Instance().Announce<Exchange::IMathExtended::INotification, ExchangeMathExtendedNotificationProxy, ExchangeMathExtendedNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IMath>();
                RPC::Administrator::Instance().Recall<Exchange::IMathExtended>();
                RPC::Administrator::Instance().Recall<Exchange::IMathExtended::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
