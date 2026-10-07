//
// generated automatically from "IContentProtection.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::IContentProtection
//   - class Exchange::IContentProtection::INotification
//   - class Exchange::IErrorToString
//

#include "Module.h"
#include "IContentProtection.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::IContentProtection interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IContentProtection::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Exchange::IContentProtection::INotification*) = 0
    //  (2) virtual Core::hresult OpenDrmSession(const string&, const string&, Exchange::IContentProtection::KeySystem, const string&, const string&, string&, string&) = 0
    //  (3) virtual Core::hresult SetDrmSessionState(const string&, Exchange::IContentProtection::State) = 0
    //  (4) virtual Core::hresult UpdateDrmSession(const string&, const string&, const string&, string&) = 0
    //  (5) virtual Core::hresult CloseDrmSession(const string&, string&) = 0
    //  (6) virtual Core::hresult ShowWatermark(const string&, bool, const uint8_t) = 0
    //  (7) virtual Core::hresult SetPlaybackPosition(const string&, int32_t, signed long) = 0
    //

    static ProxyStub::MethodHandler ExchangeContentProtectionStubMethods[] = {
        // (0) virtual Core::hresult Register(Exchange::IContentProtection::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IContentProtection::INotification* _notification{};
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

        // (1) virtual Core::hresult Unregister(Exchange::IContentProtection::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _notificationInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IContentProtection::INotification* _notification{};
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

        // (2) virtual Core::hresult OpenDrmSession(const string&, const string&, Exchange::IContentProtection::KeySystem, const string&, const string&, string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _clientId = reader.Text();
            const string _appId = reader.Text();
            Exchange::IContentProtection::KeySystem _keySystem = reader.Number<Exchange::IContentProtection::KeySystem>();
            const string _licenseRequest = reader.Text();
            const string _initData = reader.Text();

            string _sessionId{};
            string _response{};

            Core::hresult result = implementation->OpenDrmSession(static_cast<const string&>(_clientId), static_cast<const string&>(_appId), _keySystem, static_cast<const string&>(_licenseRequest), static_cast<const string&>(_initData), _sessionId, _response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_sessionId);
            writer.Text(_response);
        },

        // (3) virtual Core::hresult SetDrmSessionState(const string&, Exchange::IContentProtection::State) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _sessionId = reader.Text();
            Exchange::IContentProtection::State _sessionState = reader.Number<Exchange::IContentProtection::State>();

            Core::hresult result = implementation->SetDrmSessionState(static_cast<const string&>(_sessionId), _sessionState);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (4) virtual Core::hresult UpdateDrmSession(const string&, const string&, const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _sessionId = reader.Text();
            const string _licenseRequest = reader.Text();
            const string _initData = reader.Text();

            string _response{};

            Core::hresult result = implementation->UpdateDrmSession(static_cast<const string&>(_sessionId), static_cast<const string&>(_licenseRequest), static_cast<const string&>(_initData), _response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (5) virtual Core::hresult CloseDrmSession(const string&, string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _sessionId = reader.Text();

            string _response{};

            Core::hresult result = implementation->CloseDrmSession(static_cast<const string&>(_sessionId), _response);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_response);
        },

        // (6) virtual Core::hresult ShowWatermark(const string&, bool, const uint8_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _sessionId = reader.Text();
            bool _show = reader.Boolean();
            const uint8_t _opacityLevel = reader.Number<uint8_t>();
            ASSERT((_opacityLevel >= 0) && (_opacityLevel <= 100));

            Core::hresult result = implementation->ShowWatermark(static_cast<const string&>(_sessionId), _show, _opacityLevel);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (7) virtual Core::hresult SetPlaybackPosition(const string&, int32_t, signed long) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection* implementation = reinterpret_cast<Exchange::IContentProtection*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _sessionId = reader.Text();
            int32_t _speed = reader.Number<int32_t>();
            signed long _position = reader.Number<signed long>();

            Core::hresult result = implementation->SetPlaybackPosition(static_cast<const string&>(_sessionId), _speed, _position);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        }
        , nullptr
    }; // ExchangeContentProtectionStubMethods

    //
    // Exchange::IContentProtection::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void WatermarkStatusChanged(const string&, const string&, const Exchange::IContentProtection::INotification::Status&) = 0
    //

    static ProxyStub::MethodHandler ExchangeContentProtectionNotificationStubMethods[] = {
        // (0) virtual void WatermarkStatusChanged(const string&, const string&, const Exchange::IContentProtection::INotification::Status&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IContentProtection::INotification* implementation = reinterpret_cast<Exchange::IContentProtection::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _sessionId = reader.Text();
            const string _appId = reader.Text();
            Exchange::IContentProtection::INotification::Status _status{};
            _status.state = reader.Number<Exchange::IContentProtection::INotification::Status::State>();
            _status.failureReason = reader.Number<int32_t>();

            implementation->WatermarkStatusChanged(static_cast<const string&>(_sessionId), static_cast<const string&>(_appId), static_cast<const Exchange::IContentProtection::INotification::Status&>(_status));
        }
        , nullptr
    }; // ExchangeContentProtectionNotificationStubMethods

    //
    // Exchange::IErrorToString interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult ErrorToString(const int32_t, string&) const = 0
    //

    static ProxyStub::MethodHandler ExchangeErrorToStringStubMethods[] = {
        // (0) virtual Core::hresult ErrorToString(const int32_t, string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IErrorToString* implementation = reinterpret_cast<const Exchange::IErrorToString*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int32_t _code = reader.Number<int32_t>();

            string _result{};

            Core::hresult result = implementation->ErrorToString(_code, _result);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_result);
        }
        , nullptr
    }; // ExchangeErrorToStringStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::IContentProtection interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult Register(Exchange::IContentProtection::INotification*) = 0
    //  (1) virtual Core::hresult Unregister(Exchange::IContentProtection::INotification*) = 0
    //  (2) virtual Core::hresult OpenDrmSession(const string&, const string&, Exchange::IContentProtection::KeySystem, const string&, const string&, string&, string&) = 0
    //  (3) virtual Core::hresult SetDrmSessionState(const string&, Exchange::IContentProtection::State) = 0
    //  (4) virtual Core::hresult UpdateDrmSession(const string&, const string&, const string&, string&) = 0
    //  (5) virtual Core::hresult CloseDrmSession(const string&, string&) = 0
    //  (6) virtual Core::hresult ShowWatermark(const string&, bool, const uint8_t) = 0
    //  (7) virtual Core::hresult SetPlaybackPosition(const string&, int32_t, signed long) = 0
    //

    class ExchangeContentProtectionProxy final : public ProxyStub::UnknownProxyType<Exchange::IContentProtection> {
    public:
        ExchangeContentProtectionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult Register(Exchange::IContentProtection::INotification* _notification) override
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

        Core::hresult Unregister(Exchange::IContentProtection::INotification* _notification) override
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

        Core::hresult OpenDrmSession(const string& _clientId, const string& _appId, Exchange::IContentProtection::KeySystem _keySystem, const string& _licenseRequest, const string& _initData, string& _sessionId, string& _response) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_clientId);
            writer.Text(_appId);
            writer.Number<Exchange::IContentProtection::KeySystem>(_keySystem);
            writer.Text(_licenseRequest);
            writer.Text(_initData);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _sessionId = reader.Text();
                _response = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult SetDrmSessionState(const string& _sessionId, Exchange::IContentProtection::State _sessionState) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_sessionId);
            writer.Number<Exchange::IContentProtection::State>(_sessionState);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult UpdateDrmSession(const string& _sessionId, const string& _licenseRequest, const string& _initData, string& _response) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_sessionId);
            writer.Text(_licenseRequest);
            writer.Text(_initData);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _response = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult CloseDrmSession(const string& _sessionId, string& _response) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_sessionId);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _response = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult ShowWatermark(const string& _sessionId, bool _show, const uint8_t _opacityLevel) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_sessionId);
            writer.Boolean(_show);
            writer.Number<uint8_t>(_opacityLevel);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult SetPlaybackPosition(const string& _sessionId, int32_t _speed, signed long _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_sessionId);
            writer.Number<int32_t>(_speed);
            writer.Number<signed long>(_position);

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

    }; // class ExchangeContentProtectionProxy

    //
    // Exchange::IContentProtection::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void WatermarkStatusChanged(const string&, const string&, const Exchange::IContentProtection::INotification::Status&) = 0
    //

    class ExchangeContentProtectionNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IContentProtection::INotification> {
    public:
        ExchangeContentProtectionNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void WatermarkStatusChanged(const string& _sessionId, const string& _appId, const Exchange::IContentProtection::INotification::Status& _status) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_sessionId);
            writer.Text(_appId);
            writer.Number<Exchange::IContentProtection::INotification::Status::State>(_status.state);
            writer.Number<int32_t>(_status.failureReason);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeContentProtectionNotificationProxy

    //
    // Exchange::IErrorToString interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult ErrorToString(const int32_t, string&) const = 0
    //

    class ExchangeErrorToStringProxy final : public ProxyStub::UnknownProxyType<Exchange::IErrorToString> {
    public:
        ExchangeErrorToStringProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult ErrorToString(const int32_t _code, string& _result) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int32_t>(_code);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeErrorToStringProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::IContentProtection, ExchangeContentProtectionStubMethods> ExchangeContentProtectionStub;
        typedef ProxyStub::UnknownStubType<Exchange::IContentProtection::INotification, ExchangeContentProtectionNotificationStubMethods> ExchangeContentProtectionNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IErrorToString, ExchangeErrorToStringStubMethods> ExchangeErrorToStringStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::IContentProtection, ExchangeContentProtectionProxy, ExchangeContentProtectionStub>();
                RPC::Administrator::Instance().Announce<Exchange::IContentProtection::INotification, ExchangeContentProtectionNotificationProxy, ExchangeContentProtectionNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IErrorToString, ExchangeErrorToStringProxy, ExchangeErrorToStringStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::IContentProtection>();
                RPC::Administrator::Instance().Recall<Exchange::IContentProtection::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IErrorToString>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
