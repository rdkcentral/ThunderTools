//
// generated automatically from "IDIALServer.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IDIALServer
//   - class Exchange::IDIALServer::IApplication
//

#include "Module.h"
#include "IDIALServer.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IDIALServer interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::IDIALServer::IApplication* Application(const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeDIALServerStubMethods[] = {
        // (0) virtual Exchange::IDIALServer::IApplication* Application(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IDIALServer* implementation = reinterpret_cast<Exchange::IDIALServer*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _name = reader.Text();

            Exchange::IDIALServer::IApplication* result = implementation->Application(static_cast<const string&>(_name));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(result));

            RPC::Administrator::Instance().RegisterInterface(channel, result);
        }
        , nullptr
    }; // ExchangeDIALServerStubMethods

    //
    // Exchange::IDIALServer::IApplication interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t AdditionalDataURL(string&) const = 0
    //

    ProxyStub::MethodHandler ExchangeDIALServerApplicationStubMethods[] = {
        // (0) virtual uint32_t AdditionalDataURL(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IDIALServer::IApplication* implementation = reinterpret_cast<const Exchange::IDIALServer::IApplication*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _url{};

            uint32_t result = implementation->AdditionalDataURL(_url);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_url);
        }
        , nullptr
    }; // ExchangeDIALServerApplicationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IDIALServer interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::IDIALServer::IApplication* Application(const string&) = 0
    //

    class ExchangeDIALServerProxy final : public ProxyStub::UnknownProxyType<Exchange::IDIALServer> {
    public:
        ExchangeDIALServerProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::IDIALServer::IApplication* Application(const string& _name) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_name));

            Exchange::IDIALServer::IApplication* result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reinterpret_cast<Exchange::IDIALServer::IApplication*>(Interface(reader.Number<Core::instance_id>(), Exchange::IDIALServer::IApplication::ID));

            return (result);
        }

    }; // class ExchangeDIALServerProxy

    //
    // Exchange::IDIALServer::IApplication interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t AdditionalDataURL(string&) const = 0
    //

    class ExchangeDIALServerApplicationProxy final : public ProxyStub::UnknownProxyType<Exchange::IDIALServer::IApplication> {
    public:
        ExchangeDIALServerApplicationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t AdditionalDataURL(string& _url) const override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();
            _url = reader.Text();

            return (result);
        }

    }; // class ExchangeDIALServerApplicationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IDIALServer, ExchangeDIALServerStubMethods> ExchangeDIALServerStub;
        typedef ProxyStub::UnknownStubType<Exchange::IDIALServer::IApplication, ExchangeDIALServerApplicationStubMethods> ExchangeDIALServerApplicationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IDIALServer, ExchangeDIALServerProxy, ExchangeDIALServerStub>();
                RPC::Administrator::Instance().Announce<Exchange::IDIALServer::IApplication, ExchangeDIALServerApplicationProxy, ExchangeDIALServerApplicationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IDIALServer>();
                RPC::Administrator::Instance().Recall<Exchange::IDIALServer::IApplication>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
