//
// generated automatically from "ITestPlugin.h"
//
// implements COM-RPC proxy stubs for:
//   - class QualityAssurance::ITestPlugin
//   - class QualityAssurance::ITestPlugin::INotification
//

#include "Module.h"
#include "ITestPlugin.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // QualityAssurance::ITestPlugin interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(QualityAssurance::ITestPlugin::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(QualityAssurance::ITestPlugin::INotification*) = 0
    //  (2) virtual Core::hresult Echo(const string&, string&) = 0
    //  (3) virtual Core::hresult Greet(const string&, string&) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestPluginStubMethods[] = {
        // (0) virtual Core::hresult Register(QualityAssurance::ITestPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestPlugin* implementation = reinterpret_cast<QualityAssurance::ITestPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            QualityAssurance::ITestPlugin::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(QualityAssurance::ITestPlugin::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestPlugin* implementation = reinterpret_cast<QualityAssurance::ITestPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            QualityAssurance::ITestPlugin::INotification* _notification{};
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

        // (2) virtual Core::hresult Echo(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestPlugin* implementation = reinterpret_cast<QualityAssurance::ITestPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _input = reader.Text();

            string _output{};

            Core::hresult result = implementation->Echo(static_cast<const string&>(_input), _output);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_output);
        },

        // (3) virtual Core::hresult Greet(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestPlugin* implementation = reinterpret_cast<QualityAssurance::ITestPlugin*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            string _message{};

            Core::hresult result = implementation->Greet(static_cast<const string&>(_name), _message);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_message);
        }
        , nullptr
    }; // QualityAssuranceTestPluginStubMethods

    //
    // QualityAssurance::ITestPlugin::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void OnGreeting(const string&) = 0
    //

    static ProxyStub::MethodHandler QualityAssuranceTestPluginNotificationStubMethods[] = {
        // (0) virtual void OnGreeting(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            QualityAssurance::ITestPlugin::INotification* implementation = reinterpret_cast<QualityAssurance::ITestPlugin::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _message = reader.Text();

            implementation->OnGreeting(static_cast<const string&>(_message));
        }
        , nullptr
    }; // QualityAssuranceTestPluginNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // QualityAssurance::ITestPlugin interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(QualityAssurance::ITestPlugin::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(QualityAssurance::ITestPlugin::INotification*) = 0
    //  (2) virtual Core::hresult Echo(const string&, string&) = 0
    //  (3) virtual Core::hresult Greet(const string&, string&) = 0
    //

    class QualityAssuranceTestPluginProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestPlugin> {
    public:
        QualityAssuranceTestPluginProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(QualityAssurance::ITestPlugin::INotification* _notification) override
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

        Core::hresult Unregister(QualityAssurance::ITestPlugin::INotification* _notification) override
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

        Core::hresult Echo(const string& _input, string& _output) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_input);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _output = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Greet(const string& _name, string& _message) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_name);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _message = reader.Text();
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

    }; // class QualityAssuranceTestPluginProxy

    //
    // QualityAssurance::ITestPlugin::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OnGreeting(const string&) = 0
    //

    class QualityAssuranceTestPluginNotificationProxy final : public ProxyStub::UnknownProxyType<QualityAssurance::ITestPlugin::INotification> {
    public:
        QualityAssuranceTestPluginNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void OnGreeting(const string& _message) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_message);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class QualityAssuranceTestPluginNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestPlugin, QualityAssuranceTestPluginStubMethods> QualityAssuranceTestPluginStub;
        typedef ProxyStub::UnknownStubType<QualityAssurance::ITestPlugin::INotification, QualityAssuranceTestPluginNotificationStubMethods> QualityAssuranceTestPluginNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestPlugin, QualityAssuranceTestPluginProxy, QualityAssuranceTestPluginStub>();
                RPC::Administrator::Instance().Announce<QualityAssurance::ITestPlugin::INotification, QualityAssuranceTestPluginNotificationProxy, QualityAssuranceTestPluginNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestPlugin>();
                RPC::Administrator::Instance().Recall<QualityAssurance::ITestPlugin::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
