//
// generated automatically from "IBrowser.h"
//
// implements COM-RPC proxy stubs for:
//   - class RPC::IIteratorType<typename ELEMENT, const uint32_t INTERFACE_ID> [with ELEMENT = string, INTERFACE_ID = RPC::ID_STRINGITERATOR] [[iterator]]
//   - class Exchange::IBrowser
//   - class Exchange::IBrowser::INotification
//   - class Exchange::IWebBrowser
//   - class Exchange::IWebBrowser::INotification
//   - class Exchange::IWebBrowserExt
//   - class Exchange::IBrowserResources
//   - class Exchange::IBrowserSecurity
//   - class Exchange::IBrowserScripting
//   - class Exchange::IBrowserCookieJar
//   - class Exchange::IBrowserCookieJar::INotification
//

#include "Module.h"
#include "IBrowser.h"

#include <com/com.h>

namespace Thunder {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface stub definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    static ProxyStub::MethodHandler RPCIteratorTypeInstance_b3acff3685df4032StubMethods[] = {
        // (0) virtual bool Next(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Next(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (1) virtual bool Previous(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _info{};

            bool result = implementation->Previous(_info);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
            writer.Text(_info);
        },

        // (2) virtual void Reset(const uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            interface* implementation = reinterpret_cast<interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint32_t _position = reader.Number<uint32_t>();

            implementation->Reset(_position);
        },

        // (3) virtual bool IsValid() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool result = implementation->IsValid();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (4) virtual uint32_t Count() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->Count();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual string Current() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            using interface = RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>;

            const interface* implementation = reinterpret_cast<const interface*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->Current();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        }
        , nullptr
    }; // RPCIteratorTypeInstance_b3acff3685df4032StubMethods

    //
    // Exchange::IBrowser interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IBrowser::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IBrowser::INotification*) = 0
    //  (2) virtual void SetURL(const string&) = 0
    //  (3) virtual string GetURL() const = 0
    //  (4) virtual uint32_t GetFPS() const = 0
    //  (5) virtual void Hide(const bool) = 0
    //

    static ProxyStub::MethodHandler ExchangeBrowserStubMethods[] = {
        // (0) virtual void Register(Exchange::IBrowser::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser* implementation = reinterpret_cast<Exchange::IBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBrowser::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IBrowser::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser* implementation = reinterpret_cast<Exchange::IBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBrowser::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (2) virtual void SetURL(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser* implementation = reinterpret_cast<Exchange::IBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URL = reader.Text();

            implementation->SetURL(static_cast<const string&>(_URL));
        },

        // (3) virtual string GetURL() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowser* implementation = reinterpret_cast<const Exchange::IBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string result = implementation->GetURL();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual uint32_t GetFPS() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowser* implementation = reinterpret_cast<const Exchange::IBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->GetFPS();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (5) virtual void Hide(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser* implementation = reinterpret_cast<Exchange::IBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _hidden = reader.Boolean();

            implementation->Hide(_hidden);
        }
        , nullptr
    }; // ExchangeBrowserStubMethods

    //
    // Exchange::IBrowser::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void LoadFinished(const string&) = 0
    //  (1) virtual void URLChanged(const string&) = 0
    //  (2) virtual void Hidden(const bool) = 0
    //  (3) virtual void Closure() = 0
    //

    static ProxyStub::MethodHandler ExchangeBrowserNotificationStubMethods[] = {
        // (0) virtual void LoadFinished(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser::INotification* implementation = reinterpret_cast<Exchange::IBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URL = reader.Text();

            implementation->LoadFinished(static_cast<const string&>(_URL));
        },

        // (1) virtual void URLChanged(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser::INotification* implementation = reinterpret_cast<Exchange::IBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URL = reader.Text();

            implementation->URLChanged(static_cast<const string&>(_URL));
        },

        // (2) virtual void Hidden(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser::INotification* implementation = reinterpret_cast<Exchange::IBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _hidden = reader.Boolean();

            implementation->Hidden(_hidden);
        },

        // (3) virtual void Closure() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowser::INotification* implementation = reinterpret_cast<Exchange::IBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Closure();
        }
        , nullptr
    }; // ExchangeBrowserNotificationStubMethods

    //
    // Exchange::IWebBrowser interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IWebBrowser::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IWebBrowser::INotification*) = 0
    //  (2) virtual uint32_t URL(string&) const = 0
    //  (3) virtual uint32_t URL(const string&) = 0
    //  (4) virtual uint32_t Visibility(Exchange::IWebBrowser::VisibilityType&) const = 0
    //  (5) virtual uint32_t Visibility(const Exchange::IWebBrowser::VisibilityType) = 0
    //  (6) virtual uint32_t FPS(uint8_t&) const = 0
    //  (7) virtual Core::hresult HeaderList(string&) const = 0
    //  (8) virtual Core::hresult HeaderList(const string&) = 0
    //  (9) virtual uint32_t UserAgent(string&) const = 0
    //  (10) virtual uint32_t UserAgent(const string&) = 0
    //  (11) virtual uint32_t LocalStorageEnabled(bool&) const = 0
    //  (12) virtual uint32_t LocalStorageEnabled(const bool) = 0
    //  (13) virtual uint32_t HTTPCookieAcceptPolicy(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType&) const = 0
    //  (14) virtual uint32_t HTTPCookieAcceptPolicy(const Exchange::IWebBrowser::HTTPCookieAcceptPolicyType) = 0
    //  (15) virtual uint32_t BridgeReply(const string&) = 0
    //  (16) virtual uint32_t BridgeEvent(const string&) = 0
    //  (17) virtual uint32_t CollectGarbage() = 0
    //

    static ProxyStub::MethodHandler ExchangeWebBrowserStubMethods[] = {
        // (0) virtual void Register(Exchange::IWebBrowser::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IWebBrowser::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IWebBrowser::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IWebBrowser::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t URL(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowser* implementation = reinterpret_cast<const Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _url{};

            uint32_t result = implementation->URL(_url);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_url);
        },

        // (3) virtual uint32_t URL(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _url = reader.Text();

            uint32_t result = implementation->URL(static_cast<const string&>(_url));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (4) virtual uint32_t Visibility(Exchange::IWebBrowser::VisibilityType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowser* implementation = reinterpret_cast<const Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWebBrowser::VisibilityType _visible{};

            uint32_t result = implementation->Visibility(_visible);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IWebBrowser::VisibilityType>(_visible);
        },

        // (5) virtual uint32_t Visibility(const Exchange::IWebBrowser::VisibilityType) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IWebBrowser::VisibilityType _visible = reader.Number<Exchange::IWebBrowser::VisibilityType>();

            uint32_t result = implementation->Visibility(_visible);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (6) virtual uint32_t FPS(uint8_t&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowser* implementation = reinterpret_cast<const Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint8_t _fps{};

            uint32_t result = implementation->FPS(_fps);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint8_t>(_fps);
        },

        // (7) virtual Core::hresult HeaderList(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowser* implementation = reinterpret_cast<const Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _headerlist{};

            Core::hresult result = implementation->HeaderList(_headerlist);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Text(_headerlist);
        },

        // (8) virtual Core::hresult HeaderList(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _headerlist = reader.Text();

            Core::hresult result = implementation->HeaderList(static_cast<const string&>(_headerlist));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (9) virtual uint32_t UserAgent(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowser* implementation = reinterpret_cast<const Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _useragent{};

            uint32_t result = implementation->UserAgent(_useragent);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_useragent);
        },

        // (10) virtual uint32_t UserAgent(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _useragent = reader.Text();

            uint32_t result = implementation->UserAgent(static_cast<const string&>(_useragent));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (11) virtual uint32_t LocalStorageEnabled(bool&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowser* implementation = reinterpret_cast<const Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            bool _enabled{};

            uint32_t result = implementation->LocalStorageEnabled(_enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Boolean(_enabled);
        },

        // (12) virtual uint32_t LocalStorageEnabled(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _enabled = reader.Boolean();

            uint32_t result = implementation->LocalStorageEnabled(_enabled);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (13) virtual uint32_t HTTPCookieAcceptPolicy(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowser* implementation = reinterpret_cast<const Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWebBrowser::HTTPCookieAcceptPolicyType _policy{};

            uint32_t result = implementation->HTTPCookieAcceptPolicy(_policy);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>(_policy);
        },

        // (14) virtual uint32_t HTTPCookieAcceptPolicy(const Exchange::IWebBrowser::HTTPCookieAcceptPolicyType) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IWebBrowser::HTTPCookieAcceptPolicyType _policy = reader.Number<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>();

            uint32_t result = implementation->HTTPCookieAcceptPolicy(_policy);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (15) virtual uint32_t BridgeReply(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _payload = reader.Text();

            uint32_t result = implementation->BridgeReply(static_cast<const string&>(_payload));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (16) virtual uint32_t BridgeEvent(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _payload = reader.Text();

            uint32_t result = implementation->BridgeEvent(static_cast<const string&>(_payload));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (17) virtual uint32_t CollectGarbage() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser* implementation = reinterpret_cast<Exchange::IWebBrowser*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->CollectGarbage();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeWebBrowserStubMethods

    //
    // Exchange::IWebBrowser::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void LoadFinished(const string&, const int32_t) = 0
    //  (1) virtual void LoadFailed(const string&) = 0
    //  (2) virtual void URLChange(const string&, const bool) = 0
    //  (3) virtual void VisibilityChange(const bool) = 0
    //  (4) virtual void PageClosure() = 0
    //  (5) virtual void BridgeQuery(const string&) = 0
    //

    static ProxyStub::MethodHandler ExchangeWebBrowserNotificationStubMethods[] = {
        // (0) virtual void LoadFinished(const string&, const int32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser::INotification* implementation = reinterpret_cast<Exchange::IWebBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URL = reader.Text();
            const int32_t _httpstatus = reader.Number<int32_t>();

            implementation->LoadFinished(static_cast<const string&>(_URL), _httpstatus);
        },

        // (1) virtual void LoadFailed(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser::INotification* implementation = reinterpret_cast<Exchange::IWebBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URL = reader.Text();

            implementation->LoadFailed(static_cast<const string&>(_URL));
        },

        // (2) virtual void URLChange(const string&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser::INotification* implementation = reinterpret_cast<Exchange::IWebBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _URL = reader.Text();
            const bool _loaded = reader.Boolean();

            implementation->URLChange(static_cast<const string&>(_URL), _loaded);
        },

        // (3) virtual void VisibilityChange(const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser::INotification* implementation = reinterpret_cast<Exchange::IWebBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const bool _hidden = reader.Boolean();

            implementation->VisibilityChange(_hidden);
        },

        // (4) virtual void PageClosure() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser::INotification* implementation = reinterpret_cast<Exchange::IWebBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->PageClosure();
        },

        // (5) virtual void BridgeQuery(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowser::INotification* implementation = reinterpret_cast<Exchange::IWebBrowser::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _message = reader.Text();

            implementation->BridgeQuery(static_cast<const string&>(_message));
        }
        , nullptr
    }; // ExchangeWebBrowserNotificationStubMethods

    //
    // Exchange::IWebBrowserExt interface stub definitions
    //
    // Methods:
    //  (0) virtual Core::hresult DeleteDir(const string&) = 0
    //  (1) virtual Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator*&) const = 0
    //  (2) virtual Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator* const) = 0
    //

    static ProxyStub::MethodHandler ExchangeWebBrowserExtStubMethods[] = {
        // (0) virtual Core::hresult DeleteDir(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowserExt* implementation = reinterpret_cast<Exchange::IWebBrowserExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _path = reader.Text();

            Core::hresult result = implementation->DeleteDir(static_cast<const string&>(_path));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
        },

        // (1) virtual Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IWebBrowserExt* implementation = reinterpret_cast<const Exchange::IWebBrowserExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IWebBrowserExt::IStringIterator* _languages{};

            Core::hresult result = implementation->Languages(_languages);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_languages));

            RPC::Administrator::Instance().RegisterInterface(channel, _languages);
        },

        // (2) virtual Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IWebBrowserExt* implementation = reinterpret_cast<Exchange::IWebBrowserExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _languagesInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IWebBrowserExt::IStringIterator* _languages{};
            ProxyStub::UnknownProxy* _languagesProxy__ = nullptr;
            if (_languagesInstanceId__ != 0) {
                _languagesProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _languagesInstanceId__, false, _languages);
                ASSERT((_languages != nullptr) && (_languagesProxy__ != nullptr));
            }

            Core::hresult result = implementation->Languages(_languages);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Core::hresult>(result);

            if (_languagesProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_languagesProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExchangeWebBrowserExtStubMethods

    //
    // Exchange::IBrowserResources interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t Headers(Exchange::IBrowserResources::IStringIterator*&) const = 0
    //  (1) virtual uint32_t Headers(Exchange::IBrowserResources::IStringIterator* const) = 0
    //  (2) virtual uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator*&) const = 0
    //  (3) virtual uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator* const) = 0
    //  (4) virtual uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator*&) const = 0
    //  (5) virtual uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator* const) = 0
    //

    static ProxyStub::MethodHandler ExchangeBrowserResourcesStubMethods[] = {
        // (0) virtual uint32_t Headers(Exchange::IBrowserResources::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowserResources* implementation = reinterpret_cast<const Exchange::IBrowserResources*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBrowserResources::IStringIterator* _header{};

            uint32_t result = implementation->Headers(_header);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_header));

            RPC::Administrator::Instance().RegisterInterface(channel, _header);
        },

        // (1) virtual uint32_t Headers(Exchange::IBrowserResources::IStringIterator* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserResources* implementation = reinterpret_cast<Exchange::IBrowserResources*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _headerInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBrowserResources::IStringIterator* _header{};
            ProxyStub::UnknownProxy* _headerProxy__ = nullptr;
            if (_headerInstanceId__ != 0) {
                _headerProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _headerInstanceId__, false, _header);
                ASSERT((_header != nullptr) && (_headerProxy__ != nullptr));
            }

            uint32_t result = implementation->Headers(_header);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_headerProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_headerProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowserResources* implementation = reinterpret_cast<const Exchange::IBrowserResources*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBrowserResources::IStringIterator* _uris{};

            uint32_t result = implementation->UserScripts(_uris);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_uris));

            RPC::Administrator::Instance().RegisterInterface(channel, _uris);
        },

        // (3) virtual uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserResources* implementation = reinterpret_cast<Exchange::IBrowserResources*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _urisInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBrowserResources::IStringIterator* _uris{};
            ProxyStub::UnknownProxy* _urisProxy__ = nullptr;
            if (_urisInstanceId__ != 0) {
                _urisProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _urisInstanceId__, false, _uris);
                ASSERT((_uris != nullptr) && (_urisProxy__ != nullptr));
            }

            uint32_t result = implementation->UserScripts(_uris);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_urisProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_urisProxy__, message->Response());
            }
        },

        // (4) virtual uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator*&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowserResources* implementation = reinterpret_cast<const Exchange::IBrowserResources*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBrowserResources::IStringIterator* _uris{};

            uint32_t result = implementation->UserStyleSheets(_uris);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Core::instance_id>(RPC::instance_cast(_uris));

            RPC::Administrator::Instance().RegisterInterface(channel, _uris);
        },

        // (5) virtual uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator* const) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserResources* implementation = reinterpret_cast<Exchange::IBrowserResources*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _urisInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBrowserResources::IStringIterator* _uris{};
            ProxyStub::UnknownProxy* _urisProxy__ = nullptr;
            if (_urisInstanceId__ != 0) {
                _urisProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _urisInstanceId__, false, _uris);
                ASSERT((_uris != nullptr) && (_urisProxy__ != nullptr));
            }

            uint32_t result = implementation->UserStyleSheets(_uris);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);

            if (_urisProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_urisProxy__, message->Response());
            }
        }
        , nullptr
    }; // ExchangeBrowserResourcesStubMethods

    //
    // Exchange::IBrowserSecurity interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t SecurityProfile(string&) const = 0
    //  (1) virtual uint32_t SecurityProfile(const string&) = 0
    //  (2) virtual uint32_t MixedContentPolicy(Exchange::IBrowserSecurity::MixedContentPolicyType&) const = 0
    //  (3) virtual uint32_t MixedContentPolicy(const Exchange::IBrowserSecurity::MixedContentPolicyType) = 0
    //

    static ProxyStub::MethodHandler ExchangeBrowserSecurityStubMethods[] = {
        // (0) virtual uint32_t SecurityProfile(string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowserSecurity* implementation = reinterpret_cast<const Exchange::IBrowserSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _profile{};

            uint32_t result = implementation->SecurityProfile(_profile);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Text(_profile);
        },

        // (1) virtual uint32_t SecurityProfile(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserSecurity* implementation = reinterpret_cast<Exchange::IBrowserSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _profile = reader.Text();

            uint32_t result = implementation->SecurityProfile(static_cast<const string&>(_profile));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t MixedContentPolicy(Exchange::IBrowserSecurity::MixedContentPolicyType&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowserSecurity* implementation = reinterpret_cast<const Exchange::IBrowserSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBrowserSecurity::MixedContentPolicyType _policy{};

            uint32_t result = implementation->MixedContentPolicy(_policy);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<Exchange::IBrowserSecurity::MixedContentPolicyType>(_policy);
        },

        // (3) virtual uint32_t MixedContentPolicy(const Exchange::IBrowserSecurity::MixedContentPolicyType) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserSecurity* implementation = reinterpret_cast<Exchange::IBrowserSecurity*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Exchange::IBrowserSecurity::MixedContentPolicyType _policy = reader.Number<Exchange::IBrowserSecurity::MixedContentPolicyType>();

            uint32_t result = implementation->MixedContentPolicy(_policy);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeBrowserSecurityStubMethods

    //
    // Exchange::IBrowserScripting interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t RunJavaScript(const string&) = 0
    //  (1) virtual uint32_t AddUserScript(const string&, const bool) = 0
    //  (2) virtual uint32_t RemoveAllUserScripts() = 0
    //

    static ProxyStub::MethodHandler ExchangeBrowserScriptingStubMethods[] = {
        // (0) virtual uint32_t RunJavaScript(const string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserScripting* implementation = reinterpret_cast<Exchange::IBrowserScripting*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _script = reader.Text();

            uint32_t result = implementation->RunJavaScript(static_cast<const string&>(_script));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual uint32_t AddUserScript(const string&, const bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserScripting* implementation = reinterpret_cast<Exchange::IBrowserScripting*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _script = reader.Text();
            const bool _topFrameOnly = reader.Boolean();

            uint32_t result = implementation->AddUserScript(static_cast<const string&>(_script), _topFrameOnly);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (2) virtual uint32_t RemoveAllUserScripts() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserScripting* implementation = reinterpret_cast<Exchange::IBrowserScripting*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->RemoveAllUserScripts();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeBrowserScriptingStubMethods

    //
    // Exchange::IBrowserCookieJar interface stub definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IBrowserCookieJar::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IBrowserCookieJar::INotification*) = 0
    //  (2) virtual uint32_t CookieJar(Exchange::IBrowserCookieJar::Config&) const = 0
    //  (3) virtual uint32_t CookieJar(const Exchange::IBrowserCookieJar::Config&) = 0
    //

    static ProxyStub::MethodHandler ExchangeBrowserCookieJarStubMethods[] = {
        // (0) virtual void Register(Exchange::IBrowserCookieJar::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserCookieJar* implementation = reinterpret_cast<Exchange::IBrowserCookieJar*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBrowserCookieJar::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Register(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (1) virtual void Unregister(Exchange::IBrowserCookieJar::INotification*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserCookieJar* implementation = reinterpret_cast<Exchange::IBrowserCookieJar*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Core::instance_id _sinkInstanceId__ = reader.Number<Core::instance_id>();

            Exchange::IBrowserCookieJar::INotification* _sink{};
            ProxyStub::UnknownProxy* _sinkProxy__ = nullptr;
            if (_sinkInstanceId__ != 0) {
                _sinkProxy__ = RPC::Administrator::Instance().ProxyInstance(channel, _sinkInstanceId__, false, _sink);
                ASSERT((_sink != nullptr) && (_sinkProxy__ != nullptr));
            }

            implementation->Unregister(_sink);

            if (_sinkProxy__ != nullptr) {
                RPC::Administrator::Instance().Release(_sinkProxy__, message->Response());
            }
        },

        // (2) virtual uint32_t CookieJar(Exchange::IBrowserCookieJar::Config&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IBrowserCookieJar* implementation = reinterpret_cast<const Exchange::IBrowserCookieJar*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::IBrowserCookieJar::Config _cookieJarInfo{};

            uint32_t result = implementation->CookieJar(_cookieJarInfo);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
            writer.Number<uint32_t>(_cookieJarInfo.version);
            writer.Number<uint32_t>(_cookieJarInfo.checksum);
            writer.Text(_cookieJarInfo.payload);
        },

        // (3) virtual uint32_t CookieJar(const Exchange::IBrowserCookieJar::Config&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserCookieJar* implementation = reinterpret_cast<Exchange::IBrowserCookieJar*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            Exchange::IBrowserCookieJar::Config _cookieJarInfo{};
            _cookieJarInfo.version = reader.Number<uint32_t>();
            _cookieJarInfo.checksum = reader.Number<uint32_t>();
            _cookieJarInfo.payload = reader.Text();

            uint32_t result = implementation->CookieJar(static_cast<const Exchange::IBrowserCookieJar::Config&>(_cookieJarInfo));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        }
        , nullptr
    }; // ExchangeBrowserCookieJarStubMethods

    //
    // Exchange::IBrowserCookieJar::INotification interface stub definitions
    //
    // Methods:
    //  (0) virtual void CookieJarChanged() = 0
    //

    static ProxyStub::MethodHandler ExchangeBrowserCookieJarNotificationStubMethods[] = {
        // (0) virtual void CookieJarChanged() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IBrowserCookieJar::INotification* implementation = reinterpret_cast<Exchange::IBrowserCookieJar::INotification*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->CookieJarChanged();
        }
        , nullptr
    }; // ExchangeBrowserCookieJarNotificationStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // RPC::IIteratorTypeInstance_b3acff3685df4032 interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool Next(string&) = 0
    //  (1) virtual bool Previous(string&) = 0
    //  (2) virtual void Reset(const uint32_t) = 0
    //  (3) virtual bool IsValid() const = 0
    //  (4) virtual uint32_t Count() const = 0
    //  (5) virtual string Current() const = 0
    //

    class RPCIteratorTypeInstance_b3acff3685df4032Proxy final : public ProxyStub::UnknownProxyType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>> {
    public:
        RPCIteratorTypeInstance_b3acff3685df4032Proxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        bool Next(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        bool Previous(string& _info) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Boolean();
                _info = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Reset(const uint32_t _position) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_position);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        bool IsValid() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            bool result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
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
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        string Current() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

    }; // class RPCIteratorTypeInstance_b3acff3685df4032Proxy

    //
    // Exchange::IBrowser interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IBrowser::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IBrowser::INotification*) = 0
    //  (2) virtual void SetURL(const string&) = 0
    //  (3) virtual string GetURL() const = 0
    //  (4) virtual uint32_t GetFPS() const = 0
    //  (5) virtual void Hide(const bool) = 0
    //

    class ExchangeBrowserProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrowser> {
    public:
        ExchangeBrowserProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::IBrowser::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::IBrowser::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void SetURL(const string& _URL) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URL);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        string GetURL() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            string result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        uint32_t GetFPS() const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            uint32_t result{};

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                result = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (result);
        }

        void Hide(const bool _hidden) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_hidden);

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

    }; // class ExchangeBrowserProxy

    //
    // Exchange::IBrowser::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void LoadFinished(const string&) = 0
    //  (1) virtual void URLChanged(const string&) = 0
    //  (2) virtual void Hidden(const bool) = 0
    //  (3) virtual void Closure() = 0
    //

    class ExchangeBrowserNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrowser::INotification> {
    public:
        ExchangeBrowserNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void LoadFinished(const string& _URL) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URL);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void URLChanged(const string& _URL) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URL);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Hidden(const bool _hidden) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_hidden);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void Closure() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeBrowserNotificationProxy

    //
    // Exchange::IWebBrowser interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IWebBrowser::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IWebBrowser::INotification*) = 0
    //  (2) virtual uint32_t URL(string&) const = 0
    //  (3) virtual uint32_t URL(const string&) = 0
    //  (4) virtual uint32_t Visibility(Exchange::IWebBrowser::VisibilityType&) const = 0
    //  (5) virtual uint32_t Visibility(const Exchange::IWebBrowser::VisibilityType) = 0
    //  (6) virtual uint32_t FPS(uint8_t&) const = 0
    //  (7) virtual Core::hresult HeaderList(string&) const = 0
    //  (8) virtual Core::hresult HeaderList(const string&) = 0
    //  (9) virtual uint32_t UserAgent(string&) const = 0
    //  (10) virtual uint32_t UserAgent(const string&) = 0
    //  (11) virtual uint32_t LocalStorageEnabled(bool&) const = 0
    //  (12) virtual uint32_t LocalStorageEnabled(const bool) = 0
    //  (13) virtual uint32_t HTTPCookieAcceptPolicy(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType&) const = 0
    //  (14) virtual uint32_t HTTPCookieAcceptPolicy(const Exchange::IWebBrowser::HTTPCookieAcceptPolicyType) = 0
    //  (15) virtual uint32_t BridgeReply(const string&) = 0
    //  (16) virtual uint32_t BridgeEvent(const string&) = 0
    //  (17) virtual uint32_t CollectGarbage() = 0
    //

    class ExchangeWebBrowserProxy final : public ProxyStub::UnknownProxyType<Exchange::IWebBrowser> {
    public:
        ExchangeWebBrowserProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::IWebBrowser::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::IWebBrowser::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t URL(string& _url) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _url = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t URL(const string& _url) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_url);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Visibility(Exchange::IWebBrowser::VisibilityType& _visible) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _visible = reader.Number<Exchange::IWebBrowser::VisibilityType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Visibility(const Exchange::IWebBrowser::VisibilityType _visible) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IWebBrowser::VisibilityType>(_visible);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t FPS(uint8_t& _fps) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(6));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _fps = reader.Number<uint8_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult HeaderList(string& _headerlist) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(7));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _headerlist = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult HeaderList(const string& _headerlist) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_headerlist);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t UserAgent(string& _useragent) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(9));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _useragent = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t UserAgent(const string& _useragent) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_useragent);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t LocalStorageEnabled(bool& _enabled) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(11));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _enabled = reader.Boolean();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t LocalStorageEnabled(const bool _enabled) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_enabled);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t HTTPCookieAcceptPolicy(Exchange::IWebBrowser::HTTPCookieAcceptPolicyType& _policy) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(13));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _policy = reader.Number<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t HTTPCookieAcceptPolicy(const Exchange::IWebBrowser::HTTPCookieAcceptPolicyType _policy) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IWebBrowser::HTTPCookieAcceptPolicyType>(_policy);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t BridgeReply(const string& _payload) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_payload);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t BridgeEvent(const string& _payload) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(16));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_payload);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t CollectGarbage() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(17));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
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

    }; // class ExchangeWebBrowserProxy

    //
    // Exchange::IWebBrowser::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void LoadFinished(const string&, const int32_t) = 0
    //  (1) virtual void LoadFailed(const string&) = 0
    //  (2) virtual void URLChange(const string&, const bool) = 0
    //  (3) virtual void VisibilityChange(const bool) = 0
    //  (4) virtual void PageClosure() = 0
    //  (5) virtual void BridgeQuery(const string&) = 0
    //

    class ExchangeWebBrowserNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IWebBrowser::INotification> {
    public:
        ExchangeWebBrowserNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void LoadFinished(const string& _URL, const int32_t _httpstatus) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URL);
            writer.Number<int32_t>(_httpstatus);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void LoadFailed(const string& _URL) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URL);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void URLChange(const string& _URL, const bool _loaded) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_URL);
            writer.Boolean(_loaded);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void VisibilityChange(const bool _hidden) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Boolean(_hidden);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void PageClosure() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

        void BridgeQuery(const string& _message) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_message);

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeWebBrowserNotificationProxy

    //
    // Exchange::IWebBrowserExt interface proxy definitions
    //
    // Methods:
    //  (0) virtual Core::hresult DeleteDir(const string&) = 0
    //  (1) virtual Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator*&) const = 0
    //  (2) virtual Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator* const) = 0
    //

    class ExchangeWebBrowserExtProxy final : public ProxyStub::UnknownProxyType<Exchange::IWebBrowserExt> {
    public:
        ExchangeWebBrowserExtProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        Core::hresult DeleteDir(const string& _path) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_path);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator*& _languages) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<Core::hresult>();
                _languages = reinterpret_cast<Exchange::IWebBrowserExt::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IWebBrowserExt::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        Core::hresult Languages(Exchange::IWebBrowserExt::IStringIterator* const _languages) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_languages));

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

    }; // class ExchangeWebBrowserExtProxy

    //
    // Exchange::IBrowserResources interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t Headers(Exchange::IBrowserResources::IStringIterator*&) const = 0
    //  (1) virtual uint32_t Headers(Exchange::IBrowserResources::IStringIterator* const) = 0
    //  (2) virtual uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator*&) const = 0
    //  (3) virtual uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator* const) = 0
    //  (4) virtual uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator*&) const = 0
    //  (5) virtual uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator* const) = 0
    //

    class ExchangeBrowserResourcesProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrowserResources> {
    public:
        ExchangeBrowserResourcesProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t Headers(Exchange::IBrowserResources::IStringIterator*& _header) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _header = reinterpret_cast<Exchange::IBrowserResources::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IBrowserResources::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t Headers(Exchange::IBrowserResources::IStringIterator* const _header) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_header));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator*& _uris) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _uris = reinterpret_cast<Exchange::IBrowserResources::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IBrowserResources::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t UserScripts(Exchange::IBrowserResources::IStringIterator* const _uris) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_uris));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator*& _uris) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(4));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _uris = reinterpret_cast<Exchange::IBrowserResources::IStringIterator*>(static_cast<const ProxyStub::UnknownProxy&>(*this).Interface(reader.Number<Core::instance_id>(), Exchange::IBrowserResources::IStringIterator::ID));
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t UserStyleSheets(Exchange::IBrowserResources::IStringIterator* const _uris) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_uris));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();

                _Complete(reader);
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

    }; // class ExchangeBrowserResourcesProxy

    //
    // Exchange::IBrowserSecurity interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t SecurityProfile(string&) const = 0
    //  (1) virtual uint32_t SecurityProfile(const string&) = 0
    //  (2) virtual uint32_t MixedContentPolicy(Exchange::IBrowserSecurity::MixedContentPolicyType&) const = 0
    //  (3) virtual uint32_t MixedContentPolicy(const Exchange::IBrowserSecurity::MixedContentPolicyType) = 0
    //

    class ExchangeBrowserSecurityProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrowserSecurity> {
    public:
        ExchangeBrowserSecurityProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t SecurityProfile(string& _profile) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _profile = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t SecurityProfile(const string& _profile) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_profile);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t MixedContentPolicy(Exchange::IBrowserSecurity::MixedContentPolicyType& _policy) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _policy = reader.Number<Exchange::IBrowserSecurity::MixedContentPolicyType>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t MixedContentPolicy(const Exchange::IBrowserSecurity::MixedContentPolicyType _policy) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Exchange::IBrowserSecurity::MixedContentPolicyType>(_policy);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeBrowserSecurityProxy

    //
    // Exchange::IBrowserScripting interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t RunJavaScript(const string&) = 0
    //  (1) virtual uint32_t AddUserScript(const string&, const bool) = 0
    //  (2) virtual uint32_t RemoveAllUserScripts() = 0
    //

    class ExchangeBrowserScriptingProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrowserScripting> {
    public:
        ExchangeBrowserScriptingProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        uint32_t RunJavaScript(const string& _script) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_script);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t AddUserScript(const string& _script, const bool _topFrameOnly) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(_script);
            writer.Boolean(_topFrameOnly);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t RemoveAllUserScripts() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

    }; // class ExchangeBrowserScriptingProxy

    //
    // Exchange::IBrowserCookieJar interface proxy definitions
    //
    // Methods:
    //  (0) virtual void Register(Exchange::IBrowserCookieJar::INotification*) = 0
    //  (1) virtual void Unregister(Exchange::IBrowserCookieJar::INotification*) = 0
    //  (2) virtual uint32_t CookieJar(Exchange::IBrowserCookieJar::Config&) const = 0
    //  (3) virtual uint32_t CookieJar(const Exchange::IBrowserCookieJar::Config&) = 0
    //

    class ExchangeBrowserCookieJarProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrowserCookieJar> {
    public:
        ExchangeBrowserCookieJarProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void Register(Exchange::IBrowserCookieJar::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        void Unregister(Exchange::IBrowserCookieJar::INotification* _sink) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_sink));

            const Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());

                _Complete(reader);
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }
        }

        uint32_t CookieJar(Exchange::IBrowserCookieJar::Config& _cookieJarInfo) const override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(2));

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
                _cookieJarInfo.version = reader.Number<uint32_t>();
                _cookieJarInfo.checksum = reader.Number<uint32_t>();
                _cookieJarInfo.payload = reader.Text();
            } else {
                ASSERT((hresult & COM_ERROR) != 0);
            }

            return (hresult);
        }

        uint32_t CookieJar(const Exchange::IBrowserCookieJar::Config& _cookieJarInfo) override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_cookieJarInfo.version);
            writer.Number<uint32_t>(_cookieJarInfo.checksum);
            writer.Text(_cookieJarInfo.payload);

            Core::hresult hresult = static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
            if (hresult == Core::ERROR_NONE) {
                RPC::Data::Frame::Reader reader(message->Response().Reader());
                hresult = reader.Number<uint32_t>();
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

    }; // class ExchangeBrowserCookieJarProxy

    //
    // Exchange::IBrowserCookieJar::INotification interface proxy definitions
    //
    // Methods:
    //  (0) virtual void CookieJarChanged() = 0
    //

    class ExchangeBrowserCookieJarNotificationProxy final : public ProxyStub::UnknownProxyType<Exchange::IBrowserCookieJar::INotification> {
    public:
        ExchangeBrowserCookieJarNotificationProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
            : BaseClass(channel, implementation, otherSideInformed)
        {
        }

        void CookieJarChanged() override
        {
            IPCMessage message(static_cast<const ProxyStub::UnknownProxy&>(*this).Message(0));

            static_cast<const ProxyStub::UnknownProxy&>(*this).Invoke(message);
        }

    }; // class ExchangeBrowserCookieJarNotificationProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------
    namespace {

        typedef ProxyStub::UnknownStubType<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032StubMethods> RPCIteratorTypeInstance_b3acff3685df4032Stub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrowser, ExchangeBrowserStubMethods> ExchangeBrowserStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrowser::INotification, ExchangeBrowserNotificationStubMethods> ExchangeBrowserNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWebBrowser, ExchangeWebBrowserStubMethods> ExchangeWebBrowserStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWebBrowser::INotification, ExchangeWebBrowserNotificationStubMethods> ExchangeWebBrowserNotificationStub;
        typedef ProxyStub::UnknownStubType<Exchange::IWebBrowserExt, ExchangeWebBrowserExtStubMethods> ExchangeWebBrowserExtStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrowserResources, ExchangeBrowserResourcesStubMethods> ExchangeBrowserResourcesStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrowserSecurity, ExchangeBrowserSecurityStubMethods> ExchangeBrowserSecurityStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrowserScripting, ExchangeBrowserScriptingStubMethods> ExchangeBrowserScriptingStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrowserCookieJar, ExchangeBrowserCookieJarStubMethods> ExchangeBrowserCookieJarStub;
        typedef ProxyStub::UnknownStubType<Exchange::IBrowserCookieJar::INotification, ExchangeBrowserCookieJarNotificationStubMethods> ExchangeBrowserCookieJarNotificationStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>, RPCIteratorTypeInstance_b3acff3685df4032Proxy, RPCIteratorTypeInstance_b3acff3685df4032Stub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrowser, ExchangeBrowserProxy, ExchangeBrowserStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrowser::INotification, ExchangeBrowserNotificationProxy, ExchangeBrowserNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IWebBrowser, ExchangeWebBrowserProxy, ExchangeWebBrowserStub>();
                RPC::Administrator::Instance().Announce<Exchange::IWebBrowser::INotification, ExchangeWebBrowserNotificationProxy, ExchangeWebBrowserNotificationStub>();
                RPC::Administrator::Instance().Announce<Exchange::IWebBrowserExt, ExchangeWebBrowserExtProxy, ExchangeWebBrowserExtStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrowserResources, ExchangeBrowserResourcesProxy, ExchangeBrowserResourcesStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrowserSecurity, ExchangeBrowserSecurityProxy, ExchangeBrowserSecurityStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrowserScripting, ExchangeBrowserScriptingProxy, ExchangeBrowserScriptingStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrowserCookieJar, ExchangeBrowserCookieJarProxy, ExchangeBrowserCookieJarStub>();
                RPC::Administrator::Instance().Announce<Exchange::IBrowserCookieJar::INotification, ExchangeBrowserCookieJarNotificationProxy, ExchangeBrowserCookieJarNotificationStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<RPC::IIteratorType<string, RPC::ID_STRINGITERATOR>>();
                RPC::Administrator::Instance().Recall<Exchange::IBrowser>();
                RPC::Administrator::Instance().Recall<Exchange::IBrowser::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IWebBrowser>();
                RPC::Administrator::Instance().Recall<Exchange::IWebBrowser::INotification>();
                RPC::Administrator::Instance().Recall<Exchange::IWebBrowserExt>();
                RPC::Administrator::Instance().Recall<Exchange::IBrowserResources>();
                RPC::Administrator::Instance().Recall<Exchange::IBrowserSecurity>();
                RPC::Administrator::Instance().Recall<Exchange::IBrowserScripting>();
                RPC::Administrator::Instance().Recall<Exchange::IBrowserCookieJar>();
                RPC::Administrator::Instance().Recall<Exchange::IBrowserCookieJar::INotification>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
