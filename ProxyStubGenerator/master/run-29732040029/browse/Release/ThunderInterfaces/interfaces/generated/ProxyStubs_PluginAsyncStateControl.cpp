//
// generated automatically from "IPluginAsyncStateControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IPluginAsyncStateControl
//   - class Exchange::IPluginAsyncStateControl::IActivationCallback
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
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
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IPluginAsyncStateControl* implementation = reinterpret_cast<Exchange::IPluginAsyncStateControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IPluginAsyncStateControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                Core::OptionalType<uint8_t> _maxnumberretries{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _maxnumberretries = reader.Number<uint8_t>();
                }
                Core::OptionalType<uint16_t> _delay{};
                if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                if (reader.Boolean() == true) {
                    if (reader.Length() < (1)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _delay = reader.Number<uint16_t>();
                }
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _cbInstanceId__ = reader.Number<Core::instance_id>();

                Exchange::IPluginAsyncStateControl::IActivationCallback* _cb{};
                ProxyStub::UnknownProxy* _cbProxy__ = nullptr;
                if (_cbInstanceId__ != 0) {
                    _cbProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _cbInstanceId__, false, _cb);
                    ASSERT((_cb != nullptr) && (_cbProxy__ != nullptr));
                    if ((_cb == nullptr) || (_cbProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Activate(static_cast<const string&>(_callsign), static_cast<const Core::OptionalType<uint8_t>&>(_maxnumberretries), static_cast<const Core::OptionalType<uint16_t>&>(_delay), _cb);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_cbProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_cbProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IPluginAsyncStateControl::ID, 0, hresult);
            }
        },

        // (1) virtual Core::hresult AbortActivate(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IPluginAsyncStateControl* implementation = reinterpret_cast<Exchange::IPluginAsyncStateControl*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IPluginAsyncStateControl::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();

                Core::hresult result = implementation->AbortActivate(static_cast<const string&>(_callsign));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IPluginAsyncStateControl::ID, 1, hresult);
            }
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
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                Exchange::IPluginAsyncStateControl::IActivationCallback* implementation = reinterpret_cast<Exchange::IPluginAsyncStateControl::IActivationCallback*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), Exchange::IPluginAsyncStateControl::IActivationCallback::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _callsignPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _callsignPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _callsign = reader.Text();
                if (reader.Length() < (Core::RealSize<Exchange::IPluginAsyncStateControl::IActivationCallback::state>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Exchange::IPluginAsyncStateControl::IActivationCallback::state _state = reader.Number<Exchange::IPluginAsyncStateControl::IActivationCallback::state>();
                if (reader.Length() < (Core::RealSize<uint8_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint8_t _numberofretries = reader.Number<uint8_t>();

                implementation->Finished(static_cast<const string&>(_callsign), _state, _numberofretries);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", Exchange::IPluginAsyncStateControl::IActivationCallback::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_cb), Exchange::IPluginAsyncStateControl::IActivationCallback::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IPluginAsyncStateControl::ID, 0, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult AbortActivate(const string& _callsign) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_callsign);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IPluginAsyncStateControl::ID, 1, hresult);
            }

            return (hresult);
        }

    private:
        uint32_t _Complete(RPC::Data::Frame::Reader& reader) const
        {
            uint32_t result = Core::ERROR_NONE;

            while (reader.HasData() == true) {
                const size_t entrySize = (sizeof(Core::instance_id) + sizeof(uint32_t) + sizeof(RPC::Data::Output::mode));
                if (reader.Length() < entrySize) { result = (COM_ERROR | Core::ERROR_READ_ERROR); break; }

                const Core::instance_id implementation = reader.Number<Core::instance_id>();
                ASSERT(implementation != 0);

                const uint32_t id = reader.Number<uint32_t>();
                const RPC::Data::Output::mode how = reader.Number<RPC::Data::Output::mode>();

                if (RPC::Administrator::Instance().IsValid(static_cast<const ProxyStub::UnknownProxy&>(*this).Channel(), implementation, id) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

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

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", Exchange::IPluginAsyncStateControl::IActivationCallback::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<Exchange::IPluginAsyncStateControl, ExchangePluginAsyncStateControlProxy, ExchangePluginAsyncStateControlStub>(security);
                RPC::Administrator::Instance().Announce<Exchange::IPluginAsyncStateControl::IActivationCallback, ExchangePluginAsyncStateControlActivationCallbackProxy, ExchangePluginAsyncStateControlActivationCallbackStub>(security);
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
