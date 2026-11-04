//
// generated automatically from "IDispatcher.h"
//
// implements COM-RPC proxy stubs for:
//   - class IDispatcher
//   - class IDispatcher::ICallback
//
// secure code enabled:
//   - instance verification enabled
//   - range verification enabled
//   - frame coherency verification enabled
//

#include "Module.h"
#include "IDispatcher.h"

#include <com/com.h>

namespace Thunder {

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
    //  (0) virtual uint32_t Invoke(const uint32_t, const uint32_t, const string&, const string&, const string&, string&) = 0
    //  (1) virtual Core::hresult Subscribe(IDispatcher::ICallback*, const string&, const string&, const string&) = 0
    //  (2) virtual Core::hresult Unsubscribe(IDispatcher::ICallback*, const string&, const string&, const string&) = 0
    //  (3) virtual Core::hresult Attach(IShell::IConnectionServer::INotification*&, IShell*) = 0
    //  (4) virtual Core::hresult Detach(IShell::IConnectionServer::INotification*&) = 0
    //  (5) virtual void Dropped(const IDispatcher::ICallback*) = 0
    //

    static ProxyStub::MethodHandler DispatcherStubMethods[] = {
        // (0) virtual uint32_t Invoke(const uint32_t, const uint32_t, const string&, const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IDispatcher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _channelid = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint32_t _id = reader.Number<uint32_t>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _tokenPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _tokenPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _token = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _methodPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _methodPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _method = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _parametersPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _parametersPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _parameters = reader.Text();

                string _response{};

                uint32_t result = implementation->Invoke(_channelid, _id, static_cast<const string&>(_token), static_cast<const string&>(_method), static_cast<const string&>(_parameters), _response);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(result);
                writer.Text(_response);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        },

        // (1) virtual Core::hresult Subscribe(IDispatcher::ICallback*, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IDispatcher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _eventPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _eventPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _event = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _designatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _designatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _designator = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _indexPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _indexPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _index = reader.Text();

                IDispatcher::ICallback* _callback{};
                ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
                if (_callbackInstanceId__ != 0) {
                    _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                    ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
                    if ((_callback == nullptr) || (_callbackProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Subscribe(_callback, static_cast<const string&>(_event), static_cast<const string&>(_designator), static_cast<const string&>(_index));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_callbackProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 1, hresult);
            }
        },

        // (2) virtual Core::hresult Unsubscribe(IDispatcher::ICallback*, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IDispatcher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _eventPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _eventPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _event = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _designatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _designatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _designator = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _indexPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _indexPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _index = reader.Text();

                IDispatcher::ICallback* _callback{};
                ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
                if (_callbackInstanceId__ != 0) {
                    _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                    ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
                    if ((_callback == nullptr) || (_callbackProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Unsubscribe(_callback, static_cast<const string&>(_event), static_cast<const string&>(_designator), static_cast<const string&>(_index));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                if (_callbackProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 2, hresult);
            }
        },

        // (3) virtual Core::hresult Attach(IShell::IConnectionServer::INotification*&, IShell*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IDispatcher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _serviceInstanceId__ = reader.Number<Core::instance_id>();

                IShell::IConnectionServer::INotification* _sink{};

                IShell* _service{};
                ProxyStub::UnknownProxy* _serviceProxy__ = nullptr;
                if (_serviceInstanceId__ != 0) {
                    _serviceProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _serviceInstanceId__, false, _service);
                    ASSERT((_service != nullptr) && (_serviceProxy__ != nullptr));
                    if ((_service == nullptr) || (_serviceProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                Core::hresult result = implementation->Attach(_sink, _service);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

                if (_serviceProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_serviceProxy__, message->Response());
                }

                RPC::Administrator::Instance().RegisterInterface(channel, _sink);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 3, hresult);
            }
        },

        // (4) virtual Core::hresult Detach(IShell::IConnectionServer::INotification*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IDispatcher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                IShell::IConnectionServer::INotification* _sink{};

                Core::hresult result = implementation->Detach(_sink);

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);
                writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

                RPC::Administrator::Instance().RegisterInterface(channel, _sink);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 4, hresult);
            }
        },

        // (5) virtual void Dropped(const IDispatcher::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                IDispatcher* implementation = reinterpret_cast<IDispatcher*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IDispatcher::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (sizeof(Core::instance_id))) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                Core::instance_id _callbackInstanceId__ = reader.Number<Core::instance_id>();

                const IDispatcher::ICallback* _callback{};
                ProxyStub::UnknownProxy* _callbackProxy__ = nullptr;
                if (_callbackInstanceId__ != 0) {
                    _callbackProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _callbackInstanceId__, false, _callback);
                    ASSERT((_callback != nullptr) && (_callbackProxy__ != nullptr));
                    if ((_callback == nullptr) || (_callbackProxy__ == nullptr)) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }
                }

                implementation->Dropped(_callback);

                if (_callbackProxy__ != nullptr) {
                    RPC::Administrator::Instance().Release(_callbackProxy__, message->Response());
                }

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }
        }
        , nullptr
    }; // DispatcherStubMethods

    //
    // IDispatcher::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Event(const string&, const string&, const string&, const string&) = 0
    //

    static ProxyStub::MethodHandler DispatcherCallbackStubMethods[] = {
        // (0) virtual Core::hresult Event(const string&, const string&, const string&, const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Core::hresult hresult = Core::ERROR_NONE;

            hresult = [&]() -> Core::hresult {
                if (message->Parameters().IsValid() == false) { return (COM_ERROR | Core::ERROR_READ_ERROR); }

                IDispatcher::ICallback* implementation = reinterpret_cast<IDispatcher::ICallback*>(message->Parameters().Implementation());
                ASSERT(implementation != nullptr);
                if (RPC::Administrator::Instance().IsValid(channel, RPC::instance_cast(implementation), IDispatcher::ICallback::ID) == false) { return (COM_ERROR | Core::ERROR_NOT_EXIST); }

                RPC::Data::Frame::Reader reader(message->Parameters().Reader());
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _eventPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _eventPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _event = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _designatorPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _designatorPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _designator = reader.Text();
                if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const uint16_t _indexPeekedLen__ = reader.PeekNumber<uint16_t>();
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _indexPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _index = reader.Text();
                if (reader.Length() < (Core::RealSize<Core::UInt24>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const Core::UInt24 _parametersPeekedLen__ = reader.PeekNumber<Core::UInt24>();
                ASSERT((_parametersPeekedLen__ >= 0) && (_parametersPeekedLen__ <= 4194303));
                if (!((_parametersPeekedLen__ >= 0) && (_parametersPeekedLen__ <= 4194303))) { return (COM_ERROR | Core::ERROR_INVALID_RANGE); }
                if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<Core::UInt24>()) + _parametersPeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                const string _parameters = reader.Text<Core::UInt24>();

                Core::hresult result = implementation->Event(static_cast<const string&>(_event), static_cast<const string&>(_designator), static_cast<const string&>(_index), static_cast<const string&>(_parameters));

                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<Core::hresult>(result);

                return (Core::ERROR_NONE);
            } ();

            if (hresult != Core::ERROR_NONE) {
                RPC::Data::Frame::Writer writer(message->Response().Writer());
                writer.Number<uint32_t>(hresult);
                fprintf(stderr, "COM-RPC stub 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ICallback::ID, 0, hresult);
            }
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
    //  (0) virtual uint32_t Invoke(const uint32_t, const uint32_t, const string&, const string&, const string&, string&) = 0
    //  (1) virtual Core::hresult Subscribe(IDispatcher::ICallback*, const string&, const string&, const string&) = 0
    //  (2) virtual Core::hresult Unsubscribe(IDispatcher::ICallback*, const string&, const string&, const string&) = 0
    //  (3) virtual Core::hresult Attach(IShell::IConnectionServer::INotification*&, IShell*) = 0
    //  (4) virtual Core::hresult Detach(IShell::IConnectionServer::INotification*&) = 0
    //  (5) virtual void Dropped(const IDispatcher::ICallback*) = 0
    //

    class DispatcherProxy final : public ProxyStub::UnknownProxyType<IDispatcher> {
    public:
        DispatcherProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Invoke(const uint32_t _channelid, const uint32_t _id, const string& _token, const string& _method, const string& _parameters, string& _response) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_channelid);
            writer.Number<uint32_t>(_id);
            writer.Text(_token);
            writer.Text(_method);
            writer.Text(_parameters);

            uint32_t result{};

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<uint32_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    result = reader.Number<uint32_t>();
                    if (reader.Length() < (Core::RealSize<uint16_t>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    const uint16_t _responsePeekedLen__ = reader.PeekNumber<uint16_t>();
                    if (reader.Length() < (static_cast<uint32_t>(Core::RealSize<uint16_t>()) + _responsePeekedLen__)) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    _response = reader.Text();

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 0, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            return (result);
        }

        Core::hresult Subscribe(IDispatcher::ICallback* _callback, const string& _event, const string& _designator, const string& _index) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));
            writer.Text(_event);
            writer.Text(_designator);
            writer.Text(_index);

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_callback), IDispatcher::ICallback::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 1, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Unsubscribe(IDispatcher::ICallback* _callback, const string& _event, const string& _designator, const string& _index) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));
            writer.Text(_event);
            writer.Text(_designator);
            writer.Text(_index);

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_callback), IDispatcher::ICallback::ID }, { 0, 0 } };
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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 2, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Attach(IShell::IConnectionServer::INotification*& _sink, IShell* _service) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_service));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_service), IShell::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _sink = reinterpret_cast<IShell::IConnectionServer::INotification*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), IShell::IConnectionServer::INotification::ID));
                    }

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 3, hresult);
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);

            return (hresult);
        }

        Core::hresult Detach(IShell::IConnectionServer::INotification*& _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());
                    if (reader.Length() < (Core::RealSize<Core::hresult>())) { return (COM_ERROR | Core::ERROR_READ_ERROR); }
                    hresult = reader.Number<Core::hresult>();
                    if ((hresult & COM_ERROR) == 0) {
                        _sink = reinterpret_cast<IShell::IConnectionServer::INotification*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), IShell::IConnectionServer::INotification::ID));
                    }

                    return (hresult);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 4, hresult);
            }

            return (hresult);
        }

        void Dropped(const IDispatcher::ICallback* _callback) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            const RPC::InstanceRecord passedInstances[] = { { RPC::instance_cast(_callback), IDispatcher::ICallback::ID }, { 0, 0 } };
            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(passedInstances);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                hresult = [&]() -> Core::hresult {
                    RPC::Data::Frame::Reader reader(message->Response().Reader());

                    const uint32_t completeResult__ = _Complete(reader);
                    if (completeResult__ != Core::ERROR_NONE) { return (completeResult__); }

                    return (Core::ERROR_NONE);
                } ();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            if ((hresult & COM_ERROR) != 0) {
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ID, 5, hresult);
                TRACE_L1("Warning: This COM-RPC failure will not propagate!");
            }

            static_cast<const ProxyStub::UnknownProxy&>(*this).Channel()->CustomData(nullptr);
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

    }; // class DispatcherProxy

    //
    // IDispatcher::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Event(const string&, const string&, const string&, const string&) = 0
    //

    class DispatcherCallbackProxy final : public ProxyStub::UnknownProxyType<IDispatcher::ICallback> {
    public:
        DispatcherCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Event(const string& _event, const string& _designator, const string& _index, const string& _parameters) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_event);
            writer.Text(_designator);
            writer.Text(_index);
            writer.Text<Core::UInt24>(_parameters);

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
                fprintf(stderr, "COM-RPC call 0x%08x(%u) failed: 0x%08x\n", IDispatcher::ICallback::ID, 0, hresult);
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
                const RPC::SecureProxyStubType security = static_cast<RPC::SecureProxyStubType>(static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_SECURE) | static_cast<std::underlying_type<RPC::SecureProxyStubType>::type>(RPC::SecureProxyStubType::PROXYSTUBS_SECURITY_COHERENT));

                RPC::Administrator::Instance().Announce<IDispatcher, DispatcherProxy, DispatcherStub>(security);
                RPC::Administrator::Instance().Announce<IDispatcher::ICallback, DispatcherCallbackProxy, DispatcherCallbackStub>(security);
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
