//
// generated automatically from "IDispatcher.h"
//
// implements COM-RPC proxy stubs for:
//   - class IDispatcher
//   - class IDispatcher::ICallback
//

#include "Module.h"
#include "IDispatcher.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    using namespace PluginHost;

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // IDispatcher interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Validate(const string&, const string&, const string&) const = 0
    //  (1) virtual Core::hresult Invoke(IDispatcher::ICallback*, const uint32_t, const uint32_t, const string&, const string&, const string&, string&) = 0
    //  (2) virtual Core::hresult Revoke(IDispatcher::ICallback*) = 0
    //  (3) virtual ILocalDispatcher* Local() = 0
    //

    ProxyStub::MethodHandler DispatcherStubMethods[] = {
        // (0) virtual Core::hresult Validate(const string&, const string&, const string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const IDispatcher* implementation = reinterpret_cast<const IDispatcher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _token = reader.Text();
            const string _method = reader.Text();
            ASSERT((reader.PeekNumber<Core::Frame::UInt24>() >= 0) && (reader.PeekNumber<Core::Frame::UInt24>() <= 4194303));
            const string _paramaters = reader.Text<Core::Frame::UInt24>();

            Core::hresult result = implementation->Validate(static_cast<const string&>(_token), static_cast<const string&>(_method), static_cast<const string&>(_paramaters));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Invoke(IDispatcher::ICallback*, const uint32_t, const uint32_t, const string&, const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();
            const uint32_t _channelId = reader.Number<uint32_t>();
            const uint32_t _id = reader.Number<uint32_t>();
            const string _token = reader.Text();
            const string _method = reader.Text();
            ASSERT((reader.PeekNumber<Core::Frame::UInt24>() >= 0) && (reader.PeekNumber<Core::Frame::UInt24>() <= 4194303));
            const string _parameters = reader.Text<Core::Frame::UInt24>();

            string _response{};

            IDispatcher::ICallback* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            Core::hresult result = implementation->Invoke(_callback, _channelId, _id, static_cast<const string&>(_token), static_cast<const string&>(_method), static_cast<const string&>(_parameters), _response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text<Core::Frame::UInt24>(_response);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (2) virtual Core::hresult Revoke(IDispatcher::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            IDispatcher::ICallback* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            Core::hresult result = implementation->Revoke(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        },

        // (3) virtual ILocalDispatcher* Local() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& /* message */) {
            // stubbed method, no implementation
        }
        , nullptr
    }; // DispatcherStubMethods

    //
    // IDispatcher::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Event(const string&, const string&) = 0
    //  (1) virtual Core::hresult Error(const uint32_t, const uint32_t, const uint32_t, const string&) = 0
    //  (2) virtual Core::hresult Response(const uint32_t, const uint32_t, const string&) = 0
    //  (3) virtual Core::hresult Subscribe(const uint32_t, const string&, const string&) = 0
    //  (4) virtual Core::hresult Unsubscribe(const uint32_t, const string&, const string&) = 0
    //

    ProxyStub::MethodHandler DispatcherCallbackStubMethods[] = {
        // (0) virtual Core::hresult Event(const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher::ICallback* implementation = reinterpret_cast<IDispatcher::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _event = reader.Text();
            ASSERT((reader.PeekNumber<Core::Frame::UInt24>() >= 0) && (reader.PeekNumber<Core::Frame::UInt24>() <= 4194303));
            const string _parameters = reader.Text<Core::Frame::UInt24>();

            Core::hresult result = implementation->Event(static_cast<const string&>(_event), static_cast<const string&>(_parameters));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Error(const uint32_t, const uint32_t, const uint32_t, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher::ICallback* implementation = reinterpret_cast<IDispatcher::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _channel = reader.Number<uint32_t>();
            const uint32_t _id = reader.Number<uint32_t>();
            const uint32_t _code = reader.Number<uint32_t>();
            const string _message = reader.Text();

            Core::hresult result = implementation->Error(_channel, _id, _code, static_cast<const string&>(_message));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (2) virtual Core::hresult Response(const uint32_t, const uint32_t, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher::ICallback* implementation = reinterpret_cast<IDispatcher::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _channel = reader.Number<uint32_t>();
            const uint32_t _id = reader.Number<uint32_t>();
            ASSERT((reader.PeekNumber<Core::Frame::UInt24>() >= 0) && (reader.PeekNumber<Core::Frame::UInt24>() <= 4194303));
            const string _response = reader.Text<Core::Frame::UInt24>();

            Core::hresult result = implementation->Response(_channel, _id, static_cast<const string&>(_response));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (3) virtual Core::hresult Subscribe(const uint32_t, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher::ICallback* implementation = reinterpret_cast<IDispatcher::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _channel = reader.Number<uint32_t>();
            const string _event = reader.Text();
            const string _designator = reader.Text();

            Core::hresult result = implementation->Subscribe(_channel, static_cast<const string&>(_event), static_cast<const string&>(_designator));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult Unsubscribe(const uint32_t, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher::ICallback* implementation = reinterpret_cast<IDispatcher::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _channel = reader.Number<uint32_t>();
            const string _event = reader.Text();
            const string _designator = reader.Text();

            Core::hresult result = implementation->Unsubscribe(_channel, static_cast<const string&>(_event), static_cast<const string&>(_designator));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // DispatcherCallbackStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // IDispatcher interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Validate(const string&, const string&, const string&) const = 0
    //  (1) virtual Core::hresult Invoke(IDispatcher::ICallback*, const uint32_t, const uint32_t, const string&, const string&, const string&, string&) = 0
    //  (2) virtual Core::hresult Revoke(IDispatcher::ICallback*) = 0
    //  (3) virtual ILocalDispatcher* Local() = 0
    //

    class DispatcherProxy final : public ProxyStub::UnknownProxyType<IDispatcher> {
    public:
        DispatcherProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult Validate(const string& _token, const string& _method, const string& _paramaters) const override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_token));
            writer.Text(static_cast<const string&>(_method));
            writer.Text<Core::Frame::UInt24>(static_cast<const string&>(_paramaters));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Invoke(IDispatcher::ICallback* _callback, const uint32_t _channelId, const uint32_t _id, const string& _token, const string& _method, const string& _parameters, string& _response) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));
            writer.Number<uint32_t>(_channelId);
            writer.Number<uint32_t>(_id);
            writer.Text(static_cast<const string&>(_token));
            writer.Text(static_cast<const string&>(_method));
            writer.Text<Core::Frame::UInt24>(static_cast<const string&>(_parameters));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                if ((hresult & COM_ERROR) == 0) {
                    ASSERT((reader.PeekNumber<Core::Frame::UInt24>() >= 0) && (reader.PeekNumber<Core::Frame::UInt24>() <= 4194303));
                    _response = reader.Text<Core::Frame::UInt24>();
                }

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Revoke(IDispatcher::ICallback* _callback) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                Complete(reader);
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        ILocalDispatcher* Local() override
        {
            // stubbed method, no implementation

            return {};
        }

    }; // class DispatcherProxy

    //
    // IDispatcher::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Event(const string&, const string&) = 0
    //  (1) virtual Core::hresult Error(const uint32_t, const uint32_t, const uint32_t, const string&) = 0
    //  (2) virtual Core::hresult Response(const uint32_t, const uint32_t, const string&) = 0
    //  (3) virtual Core::hresult Subscribe(const uint32_t, const string&, const string&) = 0
    //  (4) virtual Core::hresult Unsubscribe(const uint32_t, const string&, const string&) = 0
    //

    class DispatcherCallbackProxy final : public ProxyStub::UnknownProxyType<IDispatcher::ICallback> {
    public:
        DispatcherCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Core::hresult Event(const string& _event, const string& _parameters) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_event));
            writer.Text<Core::Frame::UInt24>(static_cast<const string&>(_parameters));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Error(const uint32_t _channel, const uint32_t _id, const uint32_t _code, const string& _message) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Number<uint32_t>(_id);
            writer.Number<uint32_t>(_code);
            writer.Text(static_cast<const string&>(_message));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Response(const uint32_t _channel, const uint32_t _id, const string& _response) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Number<uint32_t>(_id);
            writer.Text<Core::Frame::UInt24>(static_cast<const string&>(_response));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Subscribe(const uint32_t _channel, const string& _event, const string& _designator) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Text(static_cast<const string&>(_event));
            writer.Text(static_cast<const string&>(_designator));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

        Core::hresult Unsubscribe(const uint32_t _channel, const string& _event, const string& _designator) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Text(static_cast<const string&>(_event));
            writer.Text(static_cast<const string&>(_designator));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                hresult |= COM_ERROR;
            }

            return (hresult);
        }

    }; // class DispatcherCallbackProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<IDispatcher, DispatcherStubMethods> DispatcherStub;
        typedef ProxyStub::UnknownStubType<IDispatcher::ICallback, DispatcherCallbackStubMethods> DispatcherCallbackStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<IDispatcher, DispatcherProxy, DispatcherStub>();
                RPC::Administrator::Instance().Announce<IDispatcher::ICallback, DispatcherCallbackProxy, DispatcherCallbackStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<IDispatcher>();
                RPC::Administrator::Instance().Recall<IDispatcher::ICallback>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
