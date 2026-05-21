//
// generated automatically from "IMessageControl.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = Exchange::IMessageControl::Control, INTERFACE_ID = Exchange::ID_MESSAGE_CONTROL_ITERATOR] [[iterator]]
//   - class Exchange::IMessageControl
//

#include "Module.h"
#include "IMessageControl.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_675a6ff7e5671893 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IMessageControl::Control&) = 0
    //  (1) virtual bool Previous(Exchange::IMessageControl::Control&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IMessageControl::Control Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_675a6ff7e5671893StubMethods[] = {
        // (0) virtual bool Next(Exchange::IMessageControl::Control&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IMessageControl::Control _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IMessageControl::messagetype>(_info.type);
            writer.Text(_info.category);
            writer.Text(_info.module);
            writer.Boolean(_info.enabled);
        },

        // (1) virtual bool Previous(Exchange::IMessageControl::Control&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IMessageControl::Control _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Number<Exchange::IMessageControl::messagetype>(_info.type);
            writer.Text(_info.category);
            writer.Text(_info.module);
            writer.Boolean(_info.enabled);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual Exchange::IMessageControl::Control Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IMessageControl::Control result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::IMessageControl::messagetype>(result.type);
            writer.Text(result.category);
            writer.Text(result.module);
            writer.Boolean(result.enabled);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_675a6ff7e5671893StubMethods

    //
    // Exchange::IMessageControl interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Enable(const Exchange::IMessageControl::messagetype, const string&, const string&, const bool) = 0
    //  (1) virtual uint32_t Controls(Exchange::IMessageControl::IControlIterator*&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeMessageControlStubMethods[] = {
        // (0) virtual uint32_t Enable(const Exchange::IMessageControl::messagetype, const string&, const string&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IMessageControl* implementation = reinterpret_cast<Exchange::IMessageControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IMessageControl::messagetype _type = reader.Number<Exchange::IMessageControl::messagetype>();
            const string _category = reader.Text();
            const string _module = reader.Text();
            const bool _enabled = reader.Boolean();

            uint32_t result = implementation->Enable(_type, static_cast<const string&>(_category), static_cast<const string&>(_module), _enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t Controls(Exchange::IMessageControl::IControlIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IMessageControl* implementation = reinterpret_cast<const Exchange::IMessageControl*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IMessageControl::IControlIterator* _control{};

            uint32_t result = implementation->Controls(_control);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_control));

            RPC::Administrator::Instance().RegisterInterface(channel, _control);
        }
        , nullptr
    }; // ExchangeMessageControlStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_675a6ff7e5671893 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(Exchange::IMessageControl::Control&) = 0
    //  (1) virtual bool Previous(Exchange::IMessageControl::Control&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual Exchange::IMessageControl::Control Current() const = 0
    //

    class RPCIteratorTypeInstance_675a6ff7e5671893Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>> {
    public:
        RPCIteratorTypeInstance_675a6ff7e5671893Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(Exchange::IMessageControl::Control& _info) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            bool result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.type = reader.Number<Exchange::IMessageControl::messagetype>();
                _info.category = reader.Text();
                _info.module = reader.Text();
                _info.enabled = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(Exchange::IMessageControl::Control& _info) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            bool result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info.type = reader.Number<Exchange::IMessageControl::messagetype>();
                _info.category = reader.Text();
                _info.module = reader.Text();
                _info.enabled = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(UnknownProxyType::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            UnknownProxyType::Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(UnknownProxyType::Message(3));

            bool result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
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
            IPCMessage message(UnknownProxyType::Message(4));

            uint32_t result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        Exchange::IMessageControl::Control Current() const override
        {
            IPCMessage message(UnknownProxyType::Message(5));

            Exchange::IMessageControl::Control result{};

            const Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result.type = reader.Number<Exchange::IMessageControl::messagetype>();
                result.category = reader.Text();
                result.module = reader.Text();
                result.enabled = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_675a6ff7e5671893Proxy

    //
    // Exchange::IMessageControl interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Enable(const Exchange::IMessageControl::messagetype, const string&, const string&, const bool) = 0
    //  (1) virtual uint32_t Controls(Exchange::IMessageControl::IControlIterator*&) const = 0
    //

    class ExchangeMessageControlProxy final : public ProxyStub::UnknownProxyType<Exchange::IMessageControl> {
    public:
        ExchangeMessageControlProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Enable(const Exchange::IMessageControl::messagetype _type, const string& _category, const string& _module, const bool _enabled) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IMessageControl::messagetype>(_type);
            writer.Text(_category);
            writer.Text(_module);
            writer.Boolean(_enabled);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Controls(Exchange::IMessageControl::IControlIterator*& _control) const override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _control = reinterpret_cast<Exchange::IMessageControl::IControlIterator*>(UnknownProxyType::Interface(reader.Number<Core::instance_id>(), Exchange::IMessageControl::IControlIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeMessageControlProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>, RPCIteratorTypeInstance_675a6ff7e5671893StubMethods> RPCIteratorTypeInstance_675a6ff7e5671893Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IMessageControl, ExchangeMessageControlStubMethods> ExchangeMessageControlStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>, RPCIteratorTypeInstance_675a6ff7e5671893Proxy, RPCIteratorTypeInstance_675a6ff7e5671893Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IMessageControl, ExchangeMessageControlProxy, ExchangeMessageControlStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<Exchange::IMessageControl::Control, Exchange::ID_MESSAGE_CONTROL_ITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IMessageControl>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
