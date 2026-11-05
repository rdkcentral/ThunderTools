//
// generated automatically from "IPluginAsyncStateControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IPluginAsyncStateControl
//   - class Exchange::IPluginAsyncStateControl::IActivationCallback
//

#include "Module.h"
#include "IPluginAsyncStateControl.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IPluginAsyncStateControl interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Activate(const string&, const Core::OptionalType<uint8_t>&, const Core::OptionalType<uint16_t>&, Exchange::IPluginAsyncStateControl::IActivationCallback* const) = 0
    //  (1) virtual Core::hresult AbortActivate(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangePluginAsyncStateControlStubMethods[] = {
        // (0) virtual Core::hresult Activate(const string&, const Core::OptionalType<uint8_t>&, const Core::OptionalType<uint16_t>&, Exchange::IPluginAsyncStateControl::IActivationCallback* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPluginAsyncStateControl* implementation = reinterpret_cast<Exchange::IPluginAsyncStateControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            Core::OptionalType<uint8_t> _maxnumberretries{};
            if (reader.Boolean() == true) {
                _maxnumberretries = reader.Number<uint8_t>();
            }
            Core::OptionalType<uint16_t> _delay{};
            if (reader.Boolean() == true) {
                _delay = reader.Number<uint16_t>();
            }
            Core::instance_id _cbInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IPluginAsyncStateControl::IActivationCallback* _cb{};
            ProxyStub::UnknownProxy* _cbProxy__ = nullptr;
            if (_cbInstanceId__ != 0) {
                _cbProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _cbInstanceId__, false, _cb);
                ASSERT((_cb != nullptr) && (_cbProxy__ != nullptr));
            }

            Core::hresult result = implementation->Activate(static_cast<const string&>(_callsign), static_cast<const Core::OptionalType<uint8_t>&>(_maxnumberretries), static_cast<const Core::OptionalType<uint16_t>&>(_delay), _cb);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_cbProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_cbProxy__, message->Response());
            }
        },

        // (1) virtual Core::hresult AbortActivate(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPluginAsyncStateControl* implementation = reinterpret_cast<Exchange::IPluginAsyncStateControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();

            Core::hresult result = implementation->AbortActivate(static_cast<const string&>(_callsign));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangePluginAsyncStateControlStubMethods

    //
    // Exchange::IPluginAsyncStateControl::IActivationCallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void Finished(const string&, const Exchange::IPluginAsyncStateControl::IActivationCallback::state, const uint8_t) = 0
    //

    static ProxyStub::MethodHandler ExchangePluginAsyncStateControlActivationCallbackStubMethods[] = {
        // (0) virtual void Finished(const string&, const Exchange::IPluginAsyncStateControl::IActivationCallback::state, const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IPluginAsyncStateControl::IActivationCallback* implementation = reinterpret_cast<Exchange::IPluginAsyncStateControl::IActivationCallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _callsign = reader.Text();
            const Exchange::IPluginAsyncStateControl::IActivationCallback::state _state = reader.Number<Exchange::IPluginAsyncStateControl::IActivationCallback::state>();
            const uint8_t _numberofretries = reader.Number<uint8_t>();

            implementation->Finished(static_cast<const string&>(_callsign), _state, _numberofretries);
        }
        , nullptr
    }; // ExchangePluginAsyncStateControlActivationCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IPluginAsyncStateControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Activate(const string&, const Core::OptionalType<uint8_t>&, const Core::OptionalType<uint16_t>&, Exchange::IPluginAsyncStateControl::IActivationCallback* const) = 0
    //  (1) virtual Core::hresult AbortActivate(const string&) = 0
    //

    class ExchangePluginAsyncStateControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IPluginAsyncStateControl> {
    public:
        ExchangePluginAsyncStateControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Activate(const string& _callsign, const Core::OptionalType<uint8_t>& _maxnumberretries, const Core::OptionalType<uint16_t>& _delay, Exchange::IPluginAsyncStateControl::IActivationCallback* const _cb) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Boolean(_maxnumberretries.IsSet());
            if (_maxnumberretries.IsSet() == true) {
                writer.Number<uint8_t>(_maxnumberretries.Value());
            }
            writer.Boolean(_delay.IsSet());
            if (_delay.IsSet() == true) {
                writer.Number<uint16_t>(_delay.Value());
            }
            writer.Number<Core::instance_id>(RPC::instance_cast(_cb));

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

        Core::hresult AbortActivate(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

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

    }; // class ExchangePluginAsyncStateControlProxy

    //
    // Exchange::IPluginAsyncStateControl::IActivationCallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Finished(const string&, const Exchange::IPluginAsyncStateControl::IActivationCallback::state, const uint8_t) = 0
    //

    class ExchangePluginAsyncStateControlActivationCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::IPluginAsyncStateControl::IActivationCallback> {
    public:
        ExchangePluginAsyncStateControlActivationCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Finished(const string& _callsign, const Exchange::IPluginAsyncStateControl::IActivationCallback::state _state, const uint8_t _numberofretries) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);
            writer.Number<Exchange::IPluginAsyncStateControl::IActivationCallback::state>(_state);
            writer.Number<uint8_t>(_numberofretries);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangePluginAsyncStateControlActivationCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IPluginAsyncStateControl, ExchangePluginAsyncStateControlStubMethods> ExchangePluginAsyncStateControlStub;
        typedef ProxyStub::UnknownStubType<Exchange::IPluginAsyncStateControl::IActivationCallback, ExchangePluginAsyncStateControlActivationCallbackStubMethods> ExchangePluginAsyncStateControlActivationCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IPluginAsyncStateControl, ExchangePluginAsyncStateControlProxy, ExchangePluginAsyncStateControlStub>();
                RPC::Administrator::Instance().Announce<Exchange::IPluginAsyncStateControl::IActivationCallback, ExchangePluginAsyncStateControlActivationCallbackProxy, ExchangePluginAsyncStateControlActivationCallbackStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IPluginAsyncStateControl>();
                RPC::Administrator::Instance().Recall<Exchange::IPluginAsyncStateControl::IActivationCallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
