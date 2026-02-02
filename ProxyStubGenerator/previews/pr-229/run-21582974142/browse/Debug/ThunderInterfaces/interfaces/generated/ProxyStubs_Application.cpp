//
// generated automatically from "IApplication.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IApplication
//   - class Exchange::IApplication::INotification
//

#include "Module.h"
#include "IApplication.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IApplication interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IApplication::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IApplication::INotification*) = 0
    //  (2) virtual uint32_t Reset(const Exchange::IApplication::resettype) = 0
    //  (3) virtual uint32_t Identifier(string&) const = 0
    //  (4) virtual uint32_t ContentLink(const string&) = 0
    //  (5) virtual uint32_t LaunchPoint(Exchange::IApplication::launchpointtype&) const = 0
    //  (6) virtual uint32_t LaunchPoint(const Exchange::IApplication::launchpointtype&) = 0
    //  (7) virtual uint32_t Visible(bool&) const = 0
    //  (8) virtual uint32_t Visible(const bool) = 0
    //  (9) virtual uint32_t Language(string&) const = 0
    //  (10) virtual uint32_t Language(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeApplicationStubMethods[] = {
        // (0) virtual void Register(Exchange::IApplication::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication* implementation = reinterpret_cast<Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IApplication::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IApplication::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication* implementation = reinterpret_cast<Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IApplication::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t Reset(const Exchange::IApplication::resettype) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication* implementation = reinterpret_cast<Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IApplication::resettype _type = reader.Number<Exchange::IApplication::resettype>();

            uint32_t result = implementation->Reset(_type);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (3) virtual uint32_t Identifier(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IApplication* implementation = reinterpret_cast<const Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _id{};

            uint32_t result = implementation->Identifier(_id);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_id);
        },

        // (4) virtual uint32_t ContentLink(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication* implementation = reinterpret_cast<Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _link = reader.Text();

            uint32_t result = implementation->ContentLink(static_cast<const string&>(_link));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual uint32_t LaunchPoint(Exchange::IApplication::launchpointtype&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IApplication* implementation = reinterpret_cast<const Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IApplication::launchpointtype _point{};

            uint32_t result = implementation->LaunchPoint(_point);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IApplication::launchpointtype>(_point);
        },

        // (6) virtual uint32_t LaunchPoint(const Exchange::IApplication::launchpointtype&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication* implementation = reinterpret_cast<Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IApplication::launchpointtype _parameter_fc4d00dd = reader.Number<Exchange::IApplication::launchpointtype>();

            uint32_t result = implementation->LaunchPoint(static_cast<const Exchange::IApplication::launchpointtype&>(_parameter_fc4d00dd));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (7) virtual uint32_t Visible(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IApplication* implementation = reinterpret_cast<const Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _visiblity{};

            uint32_t result = implementation->Visible(_visiblity);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_visiblity);
        },

        // (8) virtual uint32_t Visible(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication* implementation = reinterpret_cast<Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _parameter_09f85645 = reader.Boolean();

            uint32_t result = implementation->Visible(_parameter_09f85645);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (9) virtual uint32_t Language(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IApplication* implementation = reinterpret_cast<const Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _language{};

            uint32_t result = implementation->Language(_language);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_language);
        },

        // (10) virtual uint32_t Language(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication* implementation = reinterpret_cast<Exchange::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_06f02bd9 = reader.Text();

            uint32_t result = implementation->Language(static_cast<const string&>(_parameter_06f02bd9));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeApplicationStubMethods

    //
    // Exchange::IApplication::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void VisibilityChange(const bool) = 0
    //

    static ProxyStub::MethodHandler ExchangeApplicationNotificationStubMethods[] = {
        // (0) virtual void VisibilityChange(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IApplication::INotification* implementation = reinterpret_cast<Exchange::IApplication::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _hidden = reader.Boolean();

            implementation->VisibilityChange(_hidden);
        }
        , nullptr
    }; // ExchangeApplicationNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IApplication interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IApplication::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IApplication::INotification*) = 0
    //  (2) virtual uint32_t Reset(const Exchange::IApplication::resettype) = 0
    //  (3) virtual uint32_t Identifier(string&) const = 0
    //  (4) virtual uint32_t ContentLink(const string&) = 0
    //  (5) virtual uint32_t LaunchPoint(Exchange::IApplication::launchpointtype&) const = 0
    //  (6) virtual uint32_t LaunchPoint(const Exchange::IApplication::launchpointtype&) = 0
    //  (7) virtual uint32_t Visible(bool&) const = 0
    //  (8) virtual uint32_t Visible(const bool) = 0
    //  (9) virtual uint32_t Language(string&) const = 0
    //  (10) virtual uint32_t Language(const string&) = 0
    //

    class ExchangeApplicationProxy final : public ProxyStub::UnknownProxyType<Exchange::IApplication> {
    public:
        ExchangeApplicationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::IApplication::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::IApplication::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t Reset(const Exchange::IApplication::resettype _type) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IApplication::resettype>(_type);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Identifier(string& _id) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _id = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t ContentLink(const string& _link) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_link);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t LaunchPoint(Exchange::IApplication::launchpointtype& _point) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _point = reader.Number<Exchange::IApplication::launchpointtype>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t LaunchPoint(const Exchange::IApplication::launchpointtype& _parameter_fc4d00dd) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IApplication::launchpointtype>(_parameter_fc4d00dd);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Visible(bool& _visiblity) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _visiblity = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Visible(const bool _parameter_09f85645) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_parameter_09f85645);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Language(string& _language) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _language = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Language(const string& _parameter_06f02bd9) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_parameter_06f02bd9);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
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

    }; // class ExchangeApplicationProxy

    //
    // Exchange::IApplication::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void VisibilityChange(const bool) = 0
    //

    class ExchangeApplicationNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IApplication::INotification> {
    public:
        ExchangeApplicationNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void VisibilityChange(const bool _hidden) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_hidden);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeApplicationNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IApplication, ExchangeApplicationStubMethods> ExchangeApplicationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IApplication::INotification, ExchangeApplicationNotificationStubMethods> ExchangeApplicationNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IApplication, ExchangeApplicationProxy, ExchangeApplicationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IApplication::INotification, ExchangeApplicationNotificationProxy, ExchangeApplicationNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IApplication>();
                RPC::Administrator::Instance().Recall<Exchange::IApplication::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
