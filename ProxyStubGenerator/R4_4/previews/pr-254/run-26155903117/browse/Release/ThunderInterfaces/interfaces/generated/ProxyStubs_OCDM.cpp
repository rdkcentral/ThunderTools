//
// generated automatically from "IOCDM.h"
//
// implements COM-RPC proxy stubs for:
//   - class Exchange::ISession
//   - class Exchange::ISession::ICallback
//   - class Exchange::ISessionExt
//   - class Exchange::IAccessorOCDM
//

#include "Module.h"
#include "IOCDM.h"

#include <com/com.h>

namespace WPEFramework {

namespace ProxyStubs {

    PUSH_WARNING(DISABLE_WARNING_DEPRECATED_USE)
    PUSH_WARNING(DISABLE_WARNING_TYPE_LIMITS)

    // -----------------------------------------------------------------
    // STUBS
    // -----------------------------------------------------------------

    //
    // Exchange::ISession interface stub definitions
    //
    // Methods:
    //  (0) virtual Exchange::OCDM_RESULT Load() = 0
    //  (1) virtual void Update(const uint8_t*, const uint16_t) = 0
    //  (2) virtual Exchange::OCDM_RESULT Remove() = 0
    //  (3) virtual std::string Metadata() const = 0
    //  (4) virtual Exchange::OCDM_RESULT Metricdata(uint32_t&, uint8_t*) const = 0
    //  (5) virtual Exchange::ISession::KeyStatus Status() const = 0
    //  (6) virtual Exchange::ISession::KeyStatus Status(const uint8_t*, const uint8_t) const = 0
    //  (7) virtual Exchange::OCDM_RESULT CreateSessionBuffer(string&) = 0
    //  (8) virtual std::string BufferId() const = 0
    //  (9) virtual std::string SessionId() const = 0
    //  (10) virtual void Close() = 0
    //  (11) virtual void ResetOutputProtection() = 0
    //  (12) virtual void Revoke(Exchange::ISession::ICallback*) = 0
    //

    ProxyStub::MethodHandler ExchangeSessionStubMethods[] = {
        // (0) virtual Exchange::OCDM_RESULT Load() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->Load();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (1) virtual void Update(const uint8_t*, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyMessage{};
            const uint16_t keyMessageLen = reader.LockBuffer<uint16_t>(_keyMessage);
            reader.UnlockBuffer(keyMessageLen);

            implementation->Update(_keyMessage, keyMessageLen);
        },

        // (2) virtual Exchange::OCDM_RESULT Remove() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->Remove();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (3) virtual std::string Metadata() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string result = implementation->Metadata();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (4) virtual Exchange::OCDM_RESULT Metricdata(uint32_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint32_t _bufferSize = reader.Number<uint32_t>();

            uint8_t* _buffer{};

            if (_bufferSize != 0) {
                ASSERT(_bufferSize <= 0x1000000);
                _buffer = static_cast<uint8_t*>(ALLOCA(_bufferSize));
            }

            Exchange::OCDM_RESULT result = implementation->Metricdata(_bufferSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint32_t>((_buffer == nullptr? 0 : _bufferSize), _buffer);
            writer.Number<uint32_t>(_bufferSize);
        },

        // (5) virtual Exchange::ISession::KeyStatus Status() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::ISession::KeyStatus result = implementation->Status();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::ISession::KeyStatus>(result);
        },

        // (6) virtual Exchange::ISession::KeyStatus Status(const uint8_t*, const uint8_t) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyID{};
            const uint8_t keyIDLen = reader.LockBuffer<uint8_t>(_keyID);
            reader.UnlockBuffer(keyIDLen);

            Exchange::ISession::KeyStatus result = implementation->Status(_keyID, keyIDLen);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::ISession::KeyStatus>(result);
        },

        // (7) virtual Exchange::OCDM_RESULT CreateSessionBuffer(string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            string _bufferID{};

            Exchange::OCDM_RESULT result = implementation->CreateSessionBuffer(_bufferID);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Text(_bufferID);
        },

        // (8) virtual std::string BufferId() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string result = implementation->BufferId();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (9) virtual std::string SessionId() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession* implementation = reinterpret_cast<const Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string result = implementation->SessionId();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (10) virtual void Close() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->Close();
        },

        // (11) virtual void ResetOutputProtection() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->ResetOutputProtection();
        },

        // (12) virtual void Revoke(Exchange::ISession::ICallback*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession* implementation = reinterpret_cast<Exchange::ISession*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            Exchange::ISession::ICallback* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            implementation->Revoke(_callback);

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }
        }
        , nullptr
    }; // ExchangeSessionStubMethods

    //
    // Exchange::ISession::ICallback interface stub definitions
    //
    // Methods:
    //  (0) virtual void OnKeyMessage(const uint8_t*, const uint16_t, const std::string&) = 0
    //  (1) virtual void OnError(const int16_t, const Exchange::OCDM_RESULT, const std::string&) = 0
    //  (2) virtual void OnKeyStatusUpdate(const uint8_t*, const uint8_t, const Exchange::ISession::KeyStatus) = 0
    //  (3) virtual void OnKeyStatusesUpdated() const = 0
    //

    ProxyStub::MethodHandler ExchangeSessionCallbackStubMethods[] = {
        // (0) virtual void OnKeyMessage(const uint8_t*, const uint16_t, const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession::ICallback* implementation = reinterpret_cast<Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyMessage{};
            const uint16_t keyMessageLen = reader.LockBuffer<uint16_t>(_keyMessage);
            reader.UnlockBuffer(keyMessageLen);
            const std::string _URL = reader.Text();

            implementation->OnKeyMessage(_keyMessage, keyMessageLen, static_cast<const std::string&>(_URL));
        },

        // (1) virtual void OnError(const int16_t, const Exchange::OCDM_RESULT, const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession::ICallback* implementation = reinterpret_cast<Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const int16_t _error = reader.Number<int16_t>();
            const Exchange::OCDM_RESULT _sysError = reader.Number<Exchange::OCDM_RESULT>();
            const std::string _errorMessage = reader.Text();

            implementation->OnError(_error, _sysError, static_cast<const std::string&>(_errorMessage));
        },

        // (2) virtual void OnKeyStatusUpdate(const uint8_t*, const uint8_t, const Exchange::ISession::KeyStatus) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISession::ICallback* implementation = reinterpret_cast<Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyID{};
            const uint8_t keyIDLen = reader.LockBuffer<uint8_t>(_keyID);
            reader.UnlockBuffer(keyIDLen);
            const Exchange::ISession::KeyStatus _status = reader.Number<Exchange::ISession::KeyStatus>();

            implementation->OnKeyStatusUpdate(_keyID, keyIDLen, _status);
        },

        // (3) virtual void OnKeyStatusesUpdated() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISession::ICallback* implementation = reinterpret_cast<const Exchange::ISession::ICallback*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            implementation->OnKeyStatusesUpdated();
        }
        , nullptr
    }; // ExchangeSessionCallbackStubMethods

    //
    // Exchange::ISessionExt interface stub definitions
    //
    // Methods:
    //  (0) virtual uint32_t SessionIdExt() const = 0
    //  (1) virtual std::string BufferIdExt() const = 0
    //  (2) virtual Exchange::OCDM_RESULT SetDrmHeader(const uint8_t*, uint16_t) = 0
    //  (3) virtual Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t*, uint16_t&, uint32_t) = 0
    //  (4) virtual Exchange::OCDM_RESULT CancelChallengeDataExt() = 0
    //  (5) virtual Exchange::OCDM_RESULT StoreLicenseData(const uint8_t*, uint16_t, uint8_t*) = 0
    //  (6) virtual Exchange::OCDM_RESULT SelectKeyId(const uint8_t, const uint8_t*) = 0
    //  (7) virtual Exchange::OCDM_RESULT CleanDecryptContext() = 0
    //

    ProxyStub::MethodHandler ExchangeSessionExtStubMethods[] = {
        // (0) virtual uint32_t SessionIdExt() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISessionExt* implementation = reinterpret_cast<const Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            uint32_t result = implementation->SessionIdExt();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (1) virtual std::string BufferIdExt() const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::ISessionExt* implementation = reinterpret_cast<const Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            std::string result = implementation->BufferIdExt();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (2) virtual Exchange::OCDM_RESULT SetDrmHeader(const uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _drmHeader{};
            uint16_t drmHeaderLen = reader.LockBuffer<uint16_t>(_drmHeader);
            reader.UnlockBuffer(drmHeaderLen);

            Exchange::OCDM_RESULT result = implementation->SetDrmHeader(_drmHeader, drmHeaderLen);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (3) virtual Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t*, uint16_t&, uint32_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            uint16_t _challengeSize = reader.Number<uint16_t>();
            uint32_t _isLDL = reader.Number<uint32_t>();

            uint8_t* _challenge{};

            if (_challengeSize != 0) {
                _challenge = static_cast<uint8_t*>(ALLOCA(_challengeSize));
            }

            Exchange::OCDM_RESULT result = implementation->GetChallengeDataExt(_challenge, _challengeSize, _isLDL);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>((_challenge == nullptr? 0 : _challengeSize), _challenge);
            writer.Number<uint16_t>(_challengeSize);
        },

        // (4) virtual Exchange::OCDM_RESULT CancelChallengeDataExt() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->CancelChallengeDataExt();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (5) virtual Exchange::OCDM_RESULT StoreLicenseData(const uint8_t*, uint16_t, uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _licenseData{};
            uint16_t licenseDataLen = reader.LockBuffer<uint16_t>(_licenseData);
            reader.UnlockBuffer(licenseDataLen);

            uint8_t* _secureStopId{};

            if (16 != 0) {
                _secureStopId = static_cast<uint8_t*>(ALLOCA(16));
            }

            Exchange::OCDM_RESULT result = implementation->StoreLicenseData(_licenseData, licenseDataLen, _secureStopId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint8_t>(16, _secureStopId);
        },

        // (6) virtual Exchange::OCDM_RESULT SelectKeyId(const uint8_t, const uint8_t*) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const uint8_t* _keyId{};
            const uint8_t keyIdLen = reader.LockBuffer<uint8_t>(_keyId);
            reader.UnlockBuffer(keyIdLen);

            Exchange::OCDM_RESULT result = implementation->SelectKeyId(keyIdLen, _keyId);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (7) virtual Exchange::OCDM_RESULT CleanDecryptContext() = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::ISessionExt* implementation = reinterpret_cast<Exchange::ISessionExt*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            Exchange::OCDM_RESULT result = implementation->CleanDecryptContext();

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        }
        , nullptr
    }; // ExchangeSessionExtStubMethods

    //
    // Exchange::IAccessorOCDM interface stub definitions
    //
    // Methods:
    //  (0) virtual bool IsTypeSupported(const std::string&, const std::string&) const = 0
    //  (1) virtual Exchange::OCDM_RESULT Metadata(const std::string&, std::string&) const = 0
    //  (2) virtual Exchange::OCDM_RESULT Metricdata(const std::string&, uint32_t&, uint8_t*) const = 0
    //  (3) virtual Exchange::OCDM_RESULT CreateSession(const string&, const int32_t, const std::string&, const uint8_t*, const uint16_t, const uint8_t*, const uint16_t, Exchange::ISession::ICallback*, std::string&, Exchange::ISession*&) = 0
    //  (4) virtual Exchange::OCDM_RESULT SetServerCertificate(const string&, const uint8_t*, const uint16_t) = 0
    //  (5) virtual uint64_t GetDrmSystemTime(const std::string&) const = 0
    //  (6) virtual std::string GetVersionExt(const std::string&) const = 0
    //  (7) virtual uint32_t GetLdlSessionLimit(const std::string&) const = 0
    //  (8) virtual bool IsSecureStopEnabled(const std::string&) = 0
    //  (9) virtual Exchange::OCDM_RESULT EnableSecureStop(const std::string&, bool) = 0
    //  (10) virtual uint32_t ResetSecureStops(const std::string&) = 0
    //  (11) virtual Exchange::OCDM_RESULT GetSecureStopIds(const std::string&, uint8_t*, uint16_t, uint32_t&) = 0
    //  (12) virtual Exchange::OCDM_RESULT GetSecureStop(const std::string&, const uint8_t*, uint16_t, uint8_t*, uint16_t&) = 0
    //  (13) virtual Exchange::OCDM_RESULT CommitSecureStop(const std::string&, const uint8_t*, uint16_t, const uint8_t*, uint16_t) = 0
    //  (14) virtual Exchange::OCDM_RESULT DeleteKeyStore(const std::string&) = 0
    //  (15) virtual Exchange::OCDM_RESULT DeleteSecureStore(const std::string&) = 0
    //  (16) virtual Exchange::OCDM_RESULT GetKeyStoreHash(const std::string&, uint8_t*, uint16_t) = 0
    //  (17) virtual Exchange::OCDM_RESULT GetSecureStoreHash(const std::string&, uint8_t*, uint16_t) = 0
    //

    ProxyStub::MethodHandler ExchangeAccessorOCDMStubMethods[] = {
        // (0) virtual bool IsTypeSupported(const std::string&, const std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            const std::string _mimeType = reader.Text();

            bool result = implementation->IsTypeSupported(static_cast<const std::string&>(_keySystem), static_cast<const std::string&>(_mimeType));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (1) virtual Exchange::OCDM_RESULT Metadata(const std::string&, std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            std::string _metadata{};

            Exchange::OCDM_RESULT result = implementation->Metadata(static_cast<const std::string&>(_keySystem), _metadata);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Text(_metadata);
        },

        // (2) virtual Exchange::OCDM_RESULT Metricdata(const std::string&, uint32_t&, uint8_t*) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            uint32_t _bufferSize = reader.Number<uint32_t>();

            uint8_t* _buffer{};

            if (_bufferSize != 0) {
                ASSERT(_bufferSize <= 0x1000000);
                _buffer = static_cast<uint8_t*>(ALLOCA(_bufferSize));
            }

            Exchange::OCDM_RESULT result = implementation->Metricdata(static_cast<const std::string&>(_keySystem), _bufferSize, _buffer);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint32_t>((_buffer == nullptr? 0 : _bufferSize), _buffer);
            writer.Number<uint32_t>(_bufferSize);
        },

        // (3) virtual Exchange::OCDM_RESULT CreateSession(const string&, const int32_t, const std::string&, const uint8_t*, const uint16_t, const uint8_t*, const uint16_t, Exchange::ISession::ICallback*, std::string&, Exchange::ISession*&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& channel, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            const int32_t _licenseType = reader.Number<int32_t>();
            const std::string _initDataType = reader.Text();
            const uint8_t* _initData{};
            const uint16_t initDataLen = reader.LockBuffer<uint16_t>(_initData);
            reader.UnlockBuffer(initDataLen);
            const uint8_t* _CDMData{};
            const uint16_t CDMDataLen = reader.LockBuffer<uint16_t>(_CDMData);
            reader.UnlockBuffer(CDMDataLen);
            const Core::instance_id callbackImplementation = reader.Number<Core::instance_id>();

            std::string _sessionId{};
            Exchange::ISession* _session{};

            Exchange::ISession::ICallback* _callback = nullptr;
            ProxyStub::UnknownProxy* callbackProxy = nullptr;
            if (callbackImplementation != 0) {
                callbackProxy = RPC::Administrator::Instance().ProxyInstance(channel, callbackImplementation, false, _callback);

                ASSERT((_callback != nullptr) && (callbackProxy != nullptr));
            }

            Exchange::OCDM_RESULT result = implementation->CreateSession(static_cast<const string&>(_keySystem), _licenseType, static_cast<const std::string&>(_initDataType), _initData, initDataLen, _CDMData, CDMDataLen, _callback, _sessionId, _session);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Text(_sessionId);
            writer.Number<Core::instance_id>(RPC::instance_cast(_session));

            if (callbackProxy != nullptr) {
                RPC::Administrator::Instance().Release(callbackProxy, message->Response());
            }

            RPC::Administrator::Instance().RegisterInterface(channel, _session);
        },

        // (4) virtual Exchange::OCDM_RESULT SetServerCertificate(const string&, const uint8_t*, const uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const string _keySystem = reader.Text();
            const uint8_t* _serverCertificate{};
            const uint16_t serverCertificateLen = reader.LockBuffer<uint16_t>(_serverCertificate);
            reader.UnlockBuffer(serverCertificateLen);

            Exchange::OCDM_RESULT result = implementation->SetServerCertificate(static_cast<const string&>(_keySystem), _serverCertificate, serverCertificateLen);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (5) virtual uint64_t GetDrmSystemTime(const std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            uint64_t result = implementation->GetDrmSystemTime(static_cast<const std::string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint64_t>(result);
        },

        // (6) virtual std::string GetVersionExt(const std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            std::string result = implementation->GetVersionExt(static_cast<const std::string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Text(result);
        },

        // (7) virtual uint32_t GetLdlSessionLimit(const std::string&) const = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            const Exchange::IAccessorOCDM* implementation = reinterpret_cast<const Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            uint32_t result = implementation->GetLdlSessionLimit(static_cast<const std::string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (8) virtual bool IsSecureStopEnabled(const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            bool result = implementation->IsSecureStopEnabled(static_cast<const std::string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Boolean(result);
        },

        // (9) virtual Exchange::OCDM_RESULT EnableSecureStop(const std::string&, bool) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            bool _enable = reader.Boolean();

            Exchange::OCDM_RESULT result = implementation->EnableSecureStop(static_cast<const std::string&>(_keySystem), _enable);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (10) virtual uint32_t ResetSecureStops(const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            uint32_t result = implementation->ResetSecureStops(static_cast<const std::string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<uint32_t>(result);
        },

        // (11) virtual Exchange::OCDM_RESULT GetSecureStopIds(const std::string&, uint8_t*, uint16_t, uint32_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            uint16_t _idsLength = reader.Number<uint16_t>();
            uint32_t _count = reader.Number<uint32_t>();

            uint8_t* _ids{};

            if (_idsLength != 0) {
                _ids = static_cast<uint8_t*>(ALLOCA(_idsLength));
            }

            Exchange::OCDM_RESULT result = implementation->GetSecureStopIds(static_cast<const std::string&>(_keySystem), _ids, _idsLength, _count);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>(_idsLength, _ids);
            writer.Number<uint32_t>(_count);
        },

        // (12) virtual Exchange::OCDM_RESULT GetSecureStop(const std::string&, const uint8_t*, uint16_t, uint8_t*, uint16_t&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            const uint8_t* _sessionID{};
            uint16_t sessionIDLen = reader.LockBuffer<uint16_t>(_sessionID);
            reader.UnlockBuffer(sessionIDLen);
            uint16_t _rawSize = reader.Number<uint16_t>();

            uint8_t* _rawData{};

            if (_rawSize != 0) {
                _rawData = static_cast<uint8_t*>(ALLOCA(_rawSize));
            }

            Exchange::OCDM_RESULT result = implementation->GetSecureStop(static_cast<const std::string&>(_keySystem), _sessionID, sessionIDLen, _rawData, _rawSize);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>((_rawData == nullptr? 0 : _rawSize), _rawData);
            writer.Number<uint16_t>(_rawSize);
        },

        // (13) virtual Exchange::OCDM_RESULT CommitSecureStop(const std::string&, const uint8_t*, uint16_t, const uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            const uint8_t* _sessionID{};
            uint16_t sessionIDLen = reader.LockBuffer<uint16_t>(_sessionID);
            reader.UnlockBuffer(sessionIDLen);
            const uint8_t* _serverResponse{};
            uint16_t serverResponseLen = reader.LockBuffer<uint16_t>(_serverResponse);
            reader.UnlockBuffer(serverResponseLen);

            Exchange::OCDM_RESULT result = implementation->CommitSecureStop(static_cast<const std::string&>(_keySystem), _sessionID, sessionIDLen, _serverResponse, serverResponseLen);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (14) virtual Exchange::OCDM_RESULT DeleteKeyStore(const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            Exchange::OCDM_RESULT result = implementation->DeleteKeyStore(static_cast<const std::string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (15) virtual Exchange::OCDM_RESULT DeleteSecureStore(const std::string&) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();

            Exchange::OCDM_RESULT result = implementation->DeleteSecureStore(static_cast<const std::string&>(_keySystem));

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
        },

        // (16) virtual Exchange::OCDM_RESULT GetKeyStoreHash(const std::string&, uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            uint16_t _keyStoreHashLength = reader.Number<uint16_t>();

            uint8_t* _keyStoreHash{};

            if (_keyStoreHashLength != 0) {
                _keyStoreHash = static_cast<uint8_t*>(ALLOCA(_keyStoreHashLength));
            }

            Exchange::OCDM_RESULT result = implementation->GetKeyStoreHash(static_cast<const std::string&>(_keySystem), _keyStoreHash, _keyStoreHashLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>(_keyStoreHashLength, _keyStoreHash);
        },

        // (17) virtual Exchange::OCDM_RESULT GetSecureStoreHash(const std::string&, uint8_t*, uint16_t) = 0
        //
        [](Core::ProxyType<Core::IPCChannel>& /* channel */, Core::ProxyType<RPC::InvokeMessage>& message) {
            Exchange::IAccessorOCDM* implementation = reinterpret_cast<Exchange::IAccessorOCDM*>(message->Parameters().Implementation());
            ASSERT(implementation != nullptr);

            RPC::Data::Frame::Reader reader(message->Parameters().Reader());
            const std::string _keySystem = reader.Text();
            uint16_t _secureStoreHashLength = reader.Number<uint16_t>();

            uint8_t* _secureStoreHash{};

            if (_secureStoreHashLength != 0) {
                _secureStoreHash = static_cast<uint8_t*>(ALLOCA(_secureStoreHashLength));
            }

            Exchange::OCDM_RESULT result = implementation->GetSecureStoreHash(static_cast<const std::string&>(_keySystem), _secureStoreHash, _secureStoreHashLength);

            RPC::Data::Frame::Writer writer(message->Response().Writer());
            writer.Number<Exchange::OCDM_RESULT>(result);
            writer.Buffer<uint16_t>(_secureStoreHashLength, _secureStoreHash);
        }
        , nullptr
    }; // ExchangeAccessorOCDMStubMethods

    // -----------------------------------------------------------------
    // PROXIES
    // -----------------------------------------------------------------

    //
    // Exchange::ISession interface proxy definitions
    //
    // Methods:
    //  (0) virtual Exchange::OCDM_RESULT Load() = 0
    //  (1) virtual void Update(const uint8_t*, const uint16_t) = 0
    //  (2) virtual Exchange::OCDM_RESULT Remove() = 0
    //  (3) virtual std::string Metadata() const = 0
    //  (4) virtual Exchange::OCDM_RESULT Metricdata(uint32_t&, uint8_t*) const = 0
    //  (5) virtual Exchange::ISession::KeyStatus Status() const = 0
    //  (6) virtual Exchange::ISession::KeyStatus Status(const uint8_t*, const uint8_t) const = 0
    //  (7) virtual Exchange::OCDM_RESULT CreateSessionBuffer(string&) = 0
    //  (8) virtual std::string BufferId() const = 0
    //  (9) virtual std::string SessionId() const = 0
    //  (10) virtual void Close() = 0
    //  (11) virtual void ResetOutputProtection() = 0
    //  (12) virtual void Revoke(Exchange::ISession::ICallback*) = 0
    //

    class ExchangeSessionProxy final : public ProxyStub::UnknownProxyType<Exchange::ISession> {
    public:
        ExchangeSessionProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        Exchange::OCDM_RESULT Load() override
        {
            IPCMessage message(BaseClass::Message(0));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        void Update(const uint8_t* _keyMessage, const uint16_t keyMessageLen) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(keyMessageLen, _keyMessage);

            UnknownProxyType::Invoke(message);
        }

        Exchange::OCDM_RESULT Remove() override
        {
            IPCMessage message(BaseClass::Message(2));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        std::string Metadata() const override
        {
            IPCMessage message(BaseClass::Message(3));

            std::string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        Exchange::OCDM_RESULT Metricdata(uint32_t& _bufferSize, uint8_t* _buffer) const override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint32_t>(_bufferSize);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint32_t>(_bufferSize, _buffer);
            _bufferSize = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::ISession::KeyStatus Status() const override
        {
            IPCMessage message(BaseClass::Message(5));

            Exchange::ISession::KeyStatus result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::ISession::KeyStatus>();

            return (result);
        }

        Exchange::ISession::KeyStatus Status(const uint8_t* _keyID, const uint8_t keyIDLen) const override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(keyIDLen, _keyID);

            Exchange::ISession::KeyStatus result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::ISession::KeyStatus>();

            return (result);
        }

        Exchange::OCDM_RESULT CreateSessionBuffer(string& _bufferID) override
        {
            IPCMessage message(BaseClass::Message(7));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            _bufferID = reader.Text();

            return (result);
        }

        std::string BufferId() const override
        {
            IPCMessage message(BaseClass::Message(8));

            std::string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        std::string SessionId() const override
        {
            IPCMessage message(BaseClass::Message(9));

            std::string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        void Close() override
        {
            IPCMessage message(BaseClass::Message(10));

            UnknownProxyType::Invoke(message);
        }

        void ResetOutputProtection() override
        {
            IPCMessage message(BaseClass::Message(11));

            UnknownProxyType::Invoke(message);
        }

        void Revoke(Exchange::ISession::ICallback* _callback) override
        {
            IPCMessage message(BaseClass::Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());

            Complete(reader);
        }

    }; // class ExchangeSessionProxy

    //
    // Exchange::ISession::ICallback interface proxy definitions
    //
    // Methods:
    //  (0) virtual void OnKeyMessage(const uint8_t*, const uint16_t, const std::string&) = 0
    //  (1) virtual void OnError(const int16_t, const Exchange::OCDM_RESULT, const std::string&) = 0
    //  (2) virtual void OnKeyStatusUpdate(const uint8_t*, const uint8_t, const Exchange::ISession::KeyStatus) = 0
    //  (3) virtual void OnKeyStatusesUpdated() const = 0
    //

    class ExchangeSessionCallbackProxy final : public ProxyStub::UnknownProxyType<Exchange::ISession::ICallback> {
    public:
        ExchangeSessionCallbackProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        void OnKeyMessage(const uint8_t* _keyMessage, const uint16_t keyMessageLen, const std::string& _URL) override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(keyMessageLen, _keyMessage);
            writer.Text(static_cast<const std::string&>(_URL));

            UnknownProxyType::Invoke(message);
        }

        void OnError(const int16_t _error, const Exchange::OCDM_RESULT _sysError, const std::string& _errorMessage) override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<int16_t>(_error);
            writer.Number<Exchange::OCDM_RESULT>(_sysError);
            writer.Text(static_cast<const std::string&>(_errorMessage));

            UnknownProxyType::Invoke(message);
        }

        void OnKeyStatusUpdate(const uint8_t* _keyID, const uint8_t keyIDLen, const Exchange::ISession::KeyStatus _status) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(keyIDLen, _keyID);
            writer.Number<Exchange::ISession::KeyStatus>(_status);

            UnknownProxyType::Invoke(message);
        }

        void OnKeyStatusesUpdated() const override
        {
            IPCMessage message(BaseClass::Message(3));

            UnknownProxyType::Invoke(message);
        }

    }; // class ExchangeSessionCallbackProxy

    //
    // Exchange::ISessionExt interface proxy definitions
    //
    // Methods:
    //  (0) virtual uint32_t SessionIdExt() const = 0
    //  (1) virtual std::string BufferIdExt() const = 0
    //  (2) virtual Exchange::OCDM_RESULT SetDrmHeader(const uint8_t*, uint16_t) = 0
    //  (3) virtual Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t*, uint16_t&, uint32_t) = 0
    //  (4) virtual Exchange::OCDM_RESULT CancelChallengeDataExt() = 0
    //  (5) virtual Exchange::OCDM_RESULT StoreLicenseData(const uint8_t*, uint16_t, uint8_t*) = 0
    //  (6) virtual Exchange::OCDM_RESULT SelectKeyId(const uint8_t, const uint8_t*) = 0
    //  (7) virtual Exchange::OCDM_RESULT CleanDecryptContext() = 0
    //

    class ExchangeSessionExtProxy final : public ProxyStub::UnknownProxyType<Exchange::ISessionExt> {
    public:
        ExchangeSessionExtProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        uint32_t SessionIdExt() const override
        {
            IPCMessage message(BaseClass::Message(0));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        std::string BufferIdExt() const override
        {
            IPCMessage message(BaseClass::Message(1));

            std::string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        Exchange::OCDM_RESULT SetDrmHeader(const uint8_t* _drmHeader, uint16_t drmHeaderLen) override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(drmHeaderLen, _drmHeader);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        Exchange::OCDM_RESULT GetChallengeDataExt(uint8_t* _challenge, uint16_t& _challengeSize, uint32_t _isLDL) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Number<uint16_t>(_challengeSize);
            writer.Number<uint32_t>(_isLDL);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint16_t>(_challengeSize, _challenge);
            _challengeSize = reader.Number<uint16_t>();

            return (result);
        }

        Exchange::OCDM_RESULT CancelChallengeDataExt() override
        {
            IPCMessage message(BaseClass::Message(4));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        Exchange::OCDM_RESULT StoreLicenseData(const uint8_t* _licenseData, uint16_t licenseDataLen, uint8_t* _secureStopId) override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint16_t>(licenseDataLen, _licenseData);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint8_t>(16, _secureStopId);

            return (result);
        }

        Exchange::OCDM_RESULT SelectKeyId(const uint8_t keyIdLen, const uint8_t* _keyId) override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Buffer<uint8_t>(keyIdLen, _keyId);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        Exchange::OCDM_RESULT CleanDecryptContext() override
        {
            IPCMessage message(BaseClass::Message(7));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

    }; // class ExchangeSessionExtProxy

    //
    // Exchange::IAccessorOCDM interface proxy definitions
    //
    // Methods:
    //  (0) virtual bool IsTypeSupported(const std::string&, const std::string&) const = 0
    //  (1) virtual Exchange::OCDM_RESULT Metadata(const std::string&, std::string&) const = 0
    //  (2) virtual Exchange::OCDM_RESULT Metricdata(const std::string&, uint32_t&, uint8_t*) const = 0
    //  (3) virtual Exchange::OCDM_RESULT CreateSession(const string&, const int32_t, const std::string&, const uint8_t*, const uint16_t, const uint8_t*, const uint16_t, Exchange::ISession::ICallback*, std::string&, Exchange::ISession*&) = 0
    //  (4) virtual Exchange::OCDM_RESULT SetServerCertificate(const string&, const uint8_t*, const uint16_t) = 0
    //  (5) virtual uint64_t GetDrmSystemTime(const std::string&) const = 0
    //  (6) virtual std::string GetVersionExt(const std::string&) const = 0
    //  (7) virtual uint32_t GetLdlSessionLimit(const std::string&) const = 0
    //  (8) virtual bool IsSecureStopEnabled(const std::string&) = 0
    //  (9) virtual Exchange::OCDM_RESULT EnableSecureStop(const std::string&, bool) = 0
    //  (10) virtual uint32_t ResetSecureStops(const std::string&) = 0
    //  (11) virtual Exchange::OCDM_RESULT GetSecureStopIds(const std::string&, uint8_t*, uint16_t, uint32_t&) = 0
    //  (12) virtual Exchange::OCDM_RESULT GetSecureStop(const std::string&, const uint8_t*, uint16_t, uint8_t*, uint16_t&) = 0
    //  (13) virtual Exchange::OCDM_RESULT CommitSecureStop(const std::string&, const uint8_t*, uint16_t, const uint8_t*, uint16_t) = 0
    //  (14) virtual Exchange::OCDM_RESULT DeleteKeyStore(const std::string&) = 0
    //  (15) virtual Exchange::OCDM_RESULT DeleteSecureStore(const std::string&) = 0
    //  (16) virtual Exchange::OCDM_RESULT GetKeyStoreHash(const std::string&, uint8_t*, uint16_t) = 0
    //  (17) virtual Exchange::OCDM_RESULT GetSecureStoreHash(const std::string&, uint8_t*, uint16_t) = 0
    //

    class ExchangeAccessorOCDMProxy final : public ProxyStub::UnknownProxyType<Exchange::IAccessorOCDM> {
    public:
        ExchangeAccessorOCDMProxy(const Core::ProxyType<Core::IPCChannel>& channel, const Core::instance_id implementation, const bool otherSideInformed)
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

        bool IsTypeSupported(const std::string& _keySystem, const std::string& _mimeType) const override
        {
            IPCMessage message(BaseClass::Message(0));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Text(static_cast<const std::string&>(_mimeType));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Exchange::OCDM_RESULT Metadata(const std::string& _keySystem, std::string& _metadata) const override
        {
            IPCMessage message(BaseClass::Message(1));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            _metadata = reader.Text();

            return (result);
        }

        Exchange::OCDM_RESULT Metricdata(const std::string& _keySystem, uint32_t& _bufferSize, uint8_t* _buffer) const override
        {
            IPCMessage message(BaseClass::Message(2));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Number<uint32_t>(_bufferSize);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint32_t>(_bufferSize, _buffer);
            _bufferSize = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::OCDM_RESULT CreateSession(const string& _keySystem, const int32_t _licenseType, const std::string& _initDataType, const uint8_t* _initData, const uint16_t initDataLen, const uint8_t* _CDMData, const uint16_t CDMDataLen, Exchange::ISession::ICallback* _callback, std::string& _sessionId, Exchange::ISession*& _session) override
        {
            IPCMessage message(BaseClass::Message(3));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_keySystem));
            writer.Number<int32_t>(_licenseType);
            writer.Text(static_cast<const std::string&>(_initDataType));
            writer.Buffer<uint16_t>(initDataLen, _initData);
            writer.Buffer<uint16_t>(CDMDataLen, _CDMData);
            writer.Number<Core::instance_id>(RPC::instance_cast(_callback));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            _sessionId = reader.Text();
            _session = reinterpret_cast<Exchange::ISession*>(Interface(reader.Number<Core::instance_id>(), Exchange::ISession::ID));

            Complete(reader);

            return (result);
        }

        Exchange::OCDM_RESULT SetServerCertificate(const string& _keySystem, const uint8_t* _serverCertificate, const uint16_t serverCertificateLen) override
        {
            IPCMessage message(BaseClass::Message(4));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const string&>(_keySystem));
            writer.Buffer<uint16_t>(serverCertificateLen, _serverCertificate);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        uint64_t GetDrmSystemTime(const std::string& _keySystem) const override
        {
            IPCMessage message(BaseClass::Message(5));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            uint64_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint64_t>();

            return (result);
        }

        std::string GetVersionExt(const std::string& _keySystem) const override
        {
            IPCMessage message(BaseClass::Message(6));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            std::string result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Text();

            return (result);
        }

        uint32_t GetLdlSessionLimit(const std::string& _keySystem) const override
        {
            IPCMessage message(BaseClass::Message(7));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        bool IsSecureStopEnabled(const std::string& _keySystem) override
        {
            IPCMessage message(BaseClass::Message(8));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            bool result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Boolean();

            return (result);
        }

        Exchange::OCDM_RESULT EnableSecureStop(const std::string& _keySystem, bool _enable) override
        {
            IPCMessage message(BaseClass::Message(9));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Boolean(_enable);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        uint32_t ResetSecureStops(const std::string& _keySystem) override
        {
            IPCMessage message(BaseClass::Message(10));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            uint32_t result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::OCDM_RESULT GetSecureStopIds(const std::string& _keySystem, uint8_t* _ids, uint16_t _idsLength, uint32_t& _count) override
        {
            IPCMessage message(BaseClass::Message(11));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Number<uint16_t>(_idsLength);
            writer.Number<uint32_t>(_count);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint16_t>(_idsLength, _ids);
            _count = reader.Number<uint32_t>();

            return (result);
        }

        Exchange::OCDM_RESULT GetSecureStop(const std::string& _keySystem, const uint8_t* _sessionID, uint16_t sessionIDLen, uint8_t* _rawData, uint16_t& _rawSize) override
        {
            IPCMessage message(BaseClass::Message(12));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Buffer<uint16_t>(sessionIDLen, _sessionID);
            writer.Number<uint16_t>(_rawSize);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint16_t>(_rawSize, _rawData);
            _rawSize = reader.Number<uint16_t>();

            return (result);
        }

        Exchange::OCDM_RESULT CommitSecureStop(const std::string& _keySystem, const uint8_t* _sessionID, uint16_t sessionIDLen, const uint8_t* _serverResponse, uint16_t serverResponseLen) override
        {
            IPCMessage message(BaseClass::Message(13));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Buffer<uint16_t>(sessionIDLen, _sessionID);
            writer.Buffer<uint16_t>(serverResponseLen, _serverResponse);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        Exchange::OCDM_RESULT DeleteKeyStore(const std::string& _keySystem) override
        {
            IPCMessage message(BaseClass::Message(14));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        Exchange::OCDM_RESULT DeleteSecureStore(const std::string& _keySystem) override
        {
            IPCMessage message(BaseClass::Message(15));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();

            return (result);
        }

        Exchange::OCDM_RESULT GetKeyStoreHash(const std::string& _keySystem, uint8_t* _keyStoreHash, uint16_t _keyStoreHashLength) override
        {
            IPCMessage message(BaseClass::Message(16));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Number<uint16_t>(_keyStoreHashLength);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint16_t>(_keyStoreHashLength, _keyStoreHash);

            return (result);
        }

        Exchange::OCDM_RESULT GetSecureStoreHash(const std::string& _keySystem, uint8_t* _secureStoreHash, uint16_t _secureStoreHashLength) override
        {
            IPCMessage message(BaseClass::Message(17));

            RPC::Data::Frame::Writer writer(message->Parameters().Writer());
            writer.Text(static_cast<const std::string&>(_keySystem));
            writer.Number<uint16_t>(_secureStoreHashLength);

            Exchange::OCDM_RESULT result{};

            UnknownProxyType::Invoke(message);
            RPC::Data::Frame::Reader reader(message->Response().Reader());
            result = reader.Number<Exchange::OCDM_RESULT>();
            reader.Buffer<uint16_t>(_secureStoreHashLength, _secureStoreHash);

            return (result);
        }

    }; // class ExchangeAccessorOCDMProxy

    POP_WARNING()
    POP_WARNING()

    // -----------------------------------------------------------------
    // REGISTRATION
    // -----------------------------------------------------------------

    namespace {

        typedef ProxyStub::UnknownStubType<Exchange::ISession, ExchangeSessionStubMethods> ExchangeSessionStub;
        typedef ProxyStub::UnknownStubType<Exchange::ISession::ICallback, ExchangeSessionCallbackStubMethods> ExchangeSessionCallbackStub;
        typedef ProxyStub::UnknownStubType<Exchange::ISessionExt, ExchangeSessionExtStubMethods> ExchangeSessionExtStub;
        typedef ProxyStub::UnknownStubType<Exchange::IAccessorOCDM, ExchangeAccessorOCDMStubMethods> ExchangeAccessorOCDMStub;

        static class Instantiation {
        public:
            Instantiation()
            {
                RPC::Administrator::Instance().Announce<Exchange::ISession, ExchangeSessionProxy, ExchangeSessionStub>();
                RPC::Administrator::Instance().Announce<Exchange::ISession::ICallback, ExchangeSessionCallbackProxy, ExchangeSessionCallbackStub>();
                RPC::Administrator::Instance().Announce<Exchange::ISessionExt, ExchangeSessionExtProxy, ExchangeSessionExtStub>();
                RPC::Administrator::Instance().Announce<Exchange::IAccessorOCDM, ExchangeAccessorOCDMProxy, ExchangeAccessorOCDMStub>();
            }
            ~Instantiation()
            {
                RPC::Administrator::Instance().Recall<Exchange::ISession>();
                RPC::Administrator::Instance().Recall<Exchange::ISession::ICallback>();
                RPC::Administrator::Instance().Recall<Exchange::ISessionExt>();
                RPC::Administrator::Instance().Recall<Exchange::IAccessorOCDM>();
            }
        } ProxyStubRegistration;

    } // namespace

} // namespace ProxyStubs

}
