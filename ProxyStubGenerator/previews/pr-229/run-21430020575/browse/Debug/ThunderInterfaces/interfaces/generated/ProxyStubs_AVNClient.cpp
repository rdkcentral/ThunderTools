//
// generated automatically from "IAVNClient.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IAVNClient
//

#include "Module.h"
#include "IAVNClient.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IAVNClient interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual void Launch(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeAVNClientStubMethods[] = {
        // (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVNClient* implementation = reinterpret_cast<Exchange::IAVNClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _parameter_95fdcf0eInstanceId__ = reader.Number<Core::instance_id>();

            PluginHost::IShell* _parameter_95fdcf0e{};
            ProxyStub::UnknownProxy* _parameter_95fdcf0eProxy__ = nullptr;
            if (_parameter_95fdcf0eInstanceId__ != 0) {
                _parameter_95fdcf0eProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _parameter_95fdcf0eInstanceId__, false, _parameter_95fdcf0e);
                ASSERT((_parameter_95fdcf0e != nullptr) && (_parameter_95fdcf0eProxy__ != nullptr));
            }

            uint32_t result = implementation->Configure(_parameter_95fdcf0e);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_parameter_95fdcf0eProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_parameter_95fdcf0eProxy__, message->Response());
            }
        },

        // (1) virtual void Launch(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAVNClient* implementation = reinterpret_cast<Exchange::IAVNClient*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _parameter_b7ff79a2 = reader.Text();

            implementation->Launch(static_cast<const string&>(_parameter_b7ff79a2));
        }
        , nullptr
    }; // ExchangeAVNClientStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IAVNClient interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Configure(PluginHost::IShell*) = 0
    //  (1) virtual void Launch(const string&) = 0
    //

    class ExchangeAVNClientProxy final : public ProxyStub::UnknownProxyType<Exchange::IAVNClient> {
    public:
        ExchangeAVNClientProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Configure(PluginHost::IShell* _parameter_95fdcf0e) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_parameter_95fdcf0e));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Launch(const string& _parameter_b7ff79a2) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_parameter_b7ff79a2);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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

    }; // class ExchangeAVNClientProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IAVNClient, ExchangeAVNClientStubMethods> ExchangeAVNClientStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IAVNClient, ExchangeAVNClientProxy, ExchangeAVNClientStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IAVNClient>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
