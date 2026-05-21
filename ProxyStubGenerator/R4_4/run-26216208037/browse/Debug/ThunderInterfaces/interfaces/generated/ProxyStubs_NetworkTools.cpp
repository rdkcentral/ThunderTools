//
// generated automatically from "INetworkTools.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::INetworkTools
//   - class Exchange::INetworkTools::ICallback
//

#include "Module.h"
#include "INetworkTools.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::INetworkTools interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Ping(const string&, const uint16_t, const uint16_t) = 0
    //  (1) virtual uint32_t TraceRoute(const string&, const uint16_t) = 0
    //  (2) virtual uint32_t Callback(Exchange::INetworkTools::ICallback*) = 0
    //

    ProxyStub::MethodHandler ExchangeNetworkToolsStubMethods[] = {
        // (0) virtual uint32_t Ping(const string&, const uint16_t, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkTools* implementation = reinterpret_cast<Exchange::INetworkTools*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _destination = reader.Text();
            const uint16_t _timeOutInSeconds = reader.Number<uint16_t>();
            const uint16_t _count = reader.Number<uint16_t>();

            uint32_t result = implementation->Ping(static_cast<const string&>(_destination), _timeOutInSeconds, _count);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t TraceRoute(const string&, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkTools* implementation = reinterpret_cast<Exchange::INetworkTools*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _destination = reader.Text();
            const uint16_t _timeOutInSeconds = reader.Number<uint16_t>();

            uint32_t result = implementation->TraceRoute(static_cast<const string&>(_destination), _timeOutInSeconds);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t Callback(Exchange::INetworkTools::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkTools* implementation = reinterpret_cast<Exchange::INetworkTools*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id reportOnImplementation = reader.Number<Core::instance_id>();

            Exchange::INetworkTools::ICallback* _reportOn = nullptr;
            ProxyStub::UnknownProxy* reportOnProxy = nullptr;
            if (reportOnImplementation != 0) {
                reportOnProxy = RPC::Administrator::Instance().ProxyInstance(channel, reportOnImplementation, false, _reportOn);

                ASSERT((_reportOn != nullptr) && (reportOnProxy != nullptr));
            }

            uint32_t result = implementation->Callback(_reportOn);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (reportOnProxy != nullptr) {
                RPC::Administrator::Instance().Release(reportOnProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeNetworkToolsStubMethods

    //
    // Exchange::INetworkTools::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Report(const string&, const string&) = 0
    //

    ProxyStub::MethodHandler ExchangeNetworkToolsCallbackStubMethods[] = {
        // (0) virtual void Report(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::INetworkTools::ICallback* implementation = reinterpret_cast<Exchange::INetworkTools::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _source = reader.Text();
            const string _metadata = reader.Text();

            implementation->Report(static_cast<const string&>(_source), static_cast<const string&>(_metadata));
        }
        , nullptr
    }; // ExchangeNetworkToolsCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::INetworkTools interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Ping(const string&, const uint16_t, const uint16_t) = 0
    //  (1) virtual uint32_t TraceRoute(const string&, const uint16_t) = 0
    //  (2) virtual uint32_t Callback(Exchange::INetworkTools::ICallback*) = 0
    //

    class ExchangeNetworkToolsProxy final : public ProxyStub::UnknownProxyType<Exchange::INetworkTools> {
    public:
        ExchangeNetworkToolsProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t Ping(const string& _destination, const uint16_t _timeOutInSeconds, const uint16_t _count) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_destination));
            writer.Number<uint16_t>(_timeOutInSeconds);
            writer.Number<uint16_t>(_count);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t TraceRoute(const string& _destination, const uint16_t _timeOutInSeconds) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_destination));
            writer.Number<uint16_t>(_timeOutInSeconds);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        uint32_t Callback(Exchange::INetworkTools::ICallback* _reportOn) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_reportOn));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class ExchangeNetworkToolsProxy

    //
    // Exchange::INetworkTools::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Report(const string&, const string&) = 0
    //

    class ExchangeNetworkToolsCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::INetworkTools::ICallback> {
    public:
        ExchangeNetworkToolsCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void Report(const string& _source, const string& _metadata) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_source));
            writer.Text(static_cast<const string&>(_metadata));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeNetworkToolsCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::INetworkTools, ExchangeNetworkToolsStubMethods> ExchangeNetworkToolsStub;
        typedef ProxyStub::UnknownStubType<Exchange::INetworkTools::ICallback, ExchangeNetworkToolsCallbackStubMethods> ExchangeNetworkToolsCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::INetworkTools, ExchangeNetworkToolsProxy, ExchangeNetworkToolsStub>();
                RPC::Administrator::Instance().Announce<Exchange::INetworkTools::ICallback, ExchangeNetworkToolsCallbackProxy, ExchangeNetworkToolsCallbackStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::INetworkTools>();
                RPC::Administrator::Instance().Recall<Exchange::INetworkTools::ICallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
