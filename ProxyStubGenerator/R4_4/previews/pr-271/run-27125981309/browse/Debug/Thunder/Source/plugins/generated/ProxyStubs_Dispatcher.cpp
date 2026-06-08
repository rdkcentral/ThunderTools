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
    // STUBS TEST
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

    static ProxyStub::MethodHandler DispatcherStubMethods[] = {
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
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();
            const uint32_t _channelId = reader.Number<uint32_t>();
            const uint32_t _id = reader.Number<uint32_t>();
            const string _token = reader.Text();
            const string _method = reader.Text();
            ASSERT((reader.PeekNumber<Core::Frame::UInt24>() >= 0) && (reader.PeekNumber<Core::Frame::UInt24>() <= 4194303));
            const string _parameters = reader.Text<Core::Frame::UInt24>();

            string _response{};

            IDispatcher::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            Core::hresult result = implementation->Invoke(_callback, _channelId, _id, static_cast<const string&>(_token), static_cast<const string&>(_method), static_cast<const string&>(_parameters), _response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text<Core::Frame::UInt24>(_response);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
            }
        },

        // (2) virtual Core::hresult Revoke(IDispatcher::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

            IDispatcher::ICallback* _callback{};
            ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
            if (_callbackInstanceId__ != 0) {
                _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
            }

            Core::hresult result = implementation->Revoke(_callback);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_callbackProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
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

    static ProxyStub::MethodHandler DispatcherCallbackStubMethods[] = {
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

        Core::hresult Validate(const string& _token, const string& _method, const string& _paramaters) const override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_token);
            writer.Text(_method);
            writer.Text<Core::Frame::UInt24>(_paramaters);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Invoke(IDispatcher::ICallback* _callback, const uint32_t _channelId, const uint32_t _id, const string& _token, const string& _method, const string& _parameters, string& _response) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));
            writer.Number<uint32_t>(_channelId);
            writer.Number<uint32_t>(_id);
            writer.Text(_token);
            writer.Text(_method);
            writer.Text<Core::Frame::UInt24>(_parameters);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                ASSERT((reader.PeekNumber<Core::Frame::UInt24>() >= 0) && (reader.PeekNumber<Core::Frame::UInt24>() <= 4194303));
                _response = reader.Text<Core::Frame::UInt24>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Revoke(IDispatcher::ICallback* _callback) override
        {
            IPCMessage message(UnknownProxyType::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        ILocalDispatcher* Local() override
        {
            // stubbed method, no implementation

            return {};
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

                result = UnknownProxyType::Complete(implementation, id, how);
                if (result != Core::ERROR_NONE) { return (COM_ERROR | result); }
            }

            return (result);
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

        Core::hresult Event(const string& _event, const string& _parameters) override
        {
            IPCMessage message(UnknownProxyType::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_event);
            writer.Text<Core::Frame::UInt24>(_parameters);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Error(const uint32_t _channel, const uint32_t _id, const uint32_t _code, const string& _message) override
        {
            IPCMessage message(UnknownProxyType::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Number<uint32_t>(_id);
            writer.Number<uint32_t>(_code);
            writer.Text(_message);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Response(const uint32_t _channel, const uint32_t _id, const string& _response) override
        {
            IPCMessage message(UnknownProxyType::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Number<uint32_t>(_id);
            writer.Text<Core::Frame::UInt24>(_response);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Subscribe(const uint32_t _channel, const string& _event, const string& _designator) override
        {
            IPCMessage message(UnknownProxyType::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Text(_event);
            writer.Text(_designator);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Unsubscribe(const uint32_t _channel, const string& _event, const string& _designator) override
        {
            IPCMessage message(UnknownProxyType::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channel);
            writer.Text(_event);
            writer.Text(_designator);

            Core::hresult hresult = UnknownProxyType::Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
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
